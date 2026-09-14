-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ETHSM_VCAST_HT
-- Unit(s) Under Test: EthSM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: EthSM

-- Subprogram: EthSM_ChangeNetworkModeState

-- Test Case: EthSM_ChangeNetworkModeState.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_ChangeNetworkModeState
TEST.NEW
TEST.NAME:EthSM_ChangeNetworkModeState.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CurrentMode:COMM_NO_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.EthSM_ChangeNetworkModeState.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_ChangeNetworkModeState.State:ETHSM_STATE_ONLINE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CurrentMode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_ChangeNetworkModeState.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_ChangeNetworkModeState
TEST.NEW
TEST.NAME:EthSM_ChangeNetworkModeState.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CurrentMode:COMM_NO_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.EthSM_ChangeNetworkModeState.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_ChangeNetworkModeState.State:ETHSM_STATE_ONHOLD
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CurrentMode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONHOLD
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_ChangeNetworkModeState.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_ChangeNetworkModeState
TEST.NEW
TEST.NAME:EthSM_ChangeNetworkModeState.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CurrentMode:COMM_NO_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.EthSM_ChangeNetworkModeState.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_ChangeNetworkModeState.State:6
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CurrentMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:6
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_CheckTrcvLink

-- Test Case: EthSM_CheckTrcvLink.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_CheckTrcvLink
TEST.NEW
TEST.NAME:EthSM_CheckTrcvLink.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:FALSE
TEST.VALUE:EthSM.EthSM_CheckTrcvLink.NetworkHandle:0
TEST.EXPECTED:EthSM.EthSM_CheckTrcvLink.return:FALSE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_CheckTrcvLink.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_CheckTrcvLink
TEST.NEW
TEST.NAME:EthSM_CheckTrcvLink.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:FALSE
TEST.VALUE:EthSM.EthSM_CheckTrcvLink.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_CheckTrcvLink.Active:TRUE
TEST.EXPECTED:EthSM.EthSM_CheckTrcvLink.return:TRUE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_CheckTrcvMode

-- Test Case: EthSM_CheckTrcvMode.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_CheckTrcvMode
TEST.NEW
TEST.NAME:EthSM_CheckTrcvMode.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:FALSE
TEST.EXPECTED:EthSM.EthSM_CheckTrcvMode.return:TRUE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_CtrlModeIndication

-- Test Case: EthSM_CtrlModeIndication.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_CtrlModeIndication
TEST.NEW
TEST.NAME:EthSM_CtrlModeIndication.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_UNINIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:1
TEST.VALUE:EthSM.EthSM_CtrlModeIndication.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_CTRLMODEINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_UNINIT
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_CtrlModeIndication.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_CtrlModeIndication
TEST.NEW
TEST.NAME:EthSM_CtrlModeIndication.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:1
TEST.VALUE:EthSM.EthSM_CtrlModeIndication.CtrlIdx:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_CTRLMODEINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_PARAM_CONTROLLER
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_CtrlModeIndication.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_CtrlModeIndication
TEST.NEW
TEST.NAME:EthSM_CtrlModeIndication.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.EthSM_CtrlModeIndication.CtrlIdx:0
TEST.VALUE:EthSM.EthSM_CtrlModeIndication.CtrlMode:ETH_MODE_ACTIVE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_FullComOnHoldSMStateHandler

-- Test Case: EthSM_FullComOnHoldSMStateHandler.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComOnHoldSMStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComOnHoldSMStateHandler.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComOnHoldSMStateHandler.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComOnHoldSMStateHandler.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComOnHoldSMStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComOnHoldSMStateHandler.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComOnHoldSMStateHandler.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComOnHoldSMStateHandler.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComOnHoldSMStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComOnHoldSMStateHandler.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComOnHoldSMStateHandler.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_FullComOnlineSMStateHandler

-- Test Case: EthSM_FullComOnlineSMStateHandler.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComOnlineSMStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComOnlineSMStateHandler.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONHOLD
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComOnlineSMStateHandler.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONHOLD
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComOnlineSMStateHandler.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComOnlineSMStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComOnlineSMStateHandler.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComOnlineSMStateHandler.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComOnlineSMStateHandler.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComOnlineSMStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComOnlineSMStateHandler.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComOnlineSMStateHandler.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_FullComStateHandler

-- Test Case: EthSM_FullComStateHandler.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.001
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.002
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.003
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.004
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.005
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.005
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.006
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.006
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.007
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.007
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.008
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.008
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_SHUTDOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.009
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.009
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_SHUTDOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONHOLD
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONHOLD
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComStateHandler.010
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComStateHandler.010
TEST.VALUE:<<OPTIONS>>.DISPLAY_FULL_STRING_DATA:FALSE
TEST.VALUE:<<OPTIONS>>.HEX_NOTATION_FOR_UNPRINTABLE_CHARS:FALSE
TEST.VALUE:<<OPTIONS>>.DO_COMBINATION:FALSE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_SHUTDOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_FullComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_FullComWaitOnlineStateHandler

-- Test Case: EthSM_FullComWaitOnlineStateHandler.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComWaitOnlineStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComWaitOnlineStateHandler.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComWaitOnlineStateHandler.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComWaitOnlineStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComWaitOnlineStateHandler.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_FullComWaitOnlineStateHandler.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_FullComWaitOnlineStateHandler
TEST.NEW
TEST.NAME:EthSM_FullComWaitOnlineStateHandler.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_GetCurrentComMode

-- Test Case: EthSM_GetCurrentComMode.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetCurrentComMode
TEST.NEW
TEST.NAME:EthSM_GetCurrentComMode.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_UNINIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentComMode.NetworkHandle:0
TEST.EXPECTED:EthSM.EthSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_UNINIT
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_GetCurrentComMode.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetCurrentComMode
TEST.NEW
TEST.NAME:EthSM_GetCurrentComMode.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:1
TEST.VALUE:EthSM.EthSM_GetCurrentComMode.NetworkHandle:0
TEST.EXPECTED:EthSM.EthSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_INVALID_NETWORK_HANDLE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_GetCurrentComMode.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetCurrentComMode
TEST.NEW
TEST.NAME:EthSM_GetCurrentComMode.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentComMode.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentComMode.ComM_ModePtr:<<malloc 9>>
TEST.VALUE:EthSM.EthSM_GetCurrentComMode.ComM_ModePtr:<<null>>
TEST.EXPECTED:EthSM.EthSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_GetCurrentComMode.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetCurrentComMode
TEST.NEW
TEST.NAME:EthSM_GetCurrentComMode.004
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CurrentMode:COMM_FULL_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentComMode.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentComMode.ComM_ModePtr:<<malloc 1>>
TEST.EXPECTED:EthSM.EthSM_GetCurrentComMode.ComM_ModePtr[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:EthSM.EthSM_GetCurrentComMode.return:E_OK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_GetCurrentInternalMode

-- Test Case: EthSM_GetCurrentInternalMode.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetCurrentInternalMode
TEST.NEW
TEST.NAME:EthSM_GetCurrentInternalMode.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_UNINIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.EXPECTED:EthSM.EthSM_GetCurrentInternalMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTINTERNALMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_UNINIT
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_GetCurrentInternalMode.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetCurrentInternalMode
TEST.NEW
TEST.NAME:EthSM_GetCurrentInternalMode.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:1
TEST.VALUE:EthSM.EthSM_GetCurrentInternalMode.NetworkHandle:0
TEST.EXPECTED:EthSM.EthSM_GetCurrentInternalMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTINTERNALMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_INVALID_NETWORK_HANDLE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_GetCurrentInternalMode.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetCurrentInternalMode
TEST.NEW
TEST.NAME:EthSM_GetCurrentInternalMode.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentInternalMode.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentInternalMode.EthSM_InternalMode:<<null>>
TEST.EXPECTED:EthSM.EthSM_GetCurrentInternalMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTINTERNALMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_PARAM_POINTER
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_GetCurrentInternalMode.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetCurrentInternalMode
TEST.NEW
TEST.NAME:EthSM_GetCurrentInternalMode.004
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentInternalMode.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_GetCurrentInternalMode.EthSM_InternalMode:<<malloc 1>>
TEST.EXPECTED:EthSM.EthSM_GetCurrentInternalMode.EthSM_InternalMode[0]:ETHSM_STATE_ONLINE
TEST.EXPECTED:EthSM.EthSM_GetCurrentInternalMode.return:E_OK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_GetNetworkHandleEth

-- Test Case: EthSM_GetNetworkHandleEth.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetNetworkHandleEth
TEST.NEW
TEST.NAME:EthSM_GetNetworkHandleEth.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:1
TEST.VALUE:EthSM.EthSM_GetNetworkHandleEth.CtrlIdx:0
TEST.EXPECTED:EthSM.EthSM_GetNetworkHandleEth.return:ETHSM_INVALID_CTRL
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_GetVersionInfo

-- Test Case: EthSM_GetVersionInfo.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetVersionInfo
TEST.NEW
TEST.NAME:EthSM_GetVersionInfo.001
TEST.VALUE:EthSM.EthSM_GetVersionInfo.versioninfo:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_PARAM_POINTER
TEST.END

-- Test Case: EthSM_GetVersionInfo.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_GetVersionInfo
TEST.NEW
TEST.NAME:EthSM_GetVersionInfo.002
TEST.VALUE:EthSM.EthSM_GetVersionInfo.versioninfo:<<malloc 1>>
TEST.EXPECTED:EthSM.EthSM_GetVersionInfo.versioninfo[0].vendorID:ETHSM_VENDOR_ID
TEST.EXPECTED:EthSM.EthSM_GetVersionInfo.versioninfo[0].moduleID:ETHSM_MODULE_ID
TEST.EXPECTED:EthSM.EthSM_GetVersionInfo.versioninfo[0].sw_major_version:ETHSM_SW_MAJOR_VERSION
TEST.EXPECTED:EthSM.EthSM_GetVersionInfo.versioninfo[0].sw_minor_version:ETHSM_SW_MINOR_VERSION
TEST.EXPECTED:EthSM.EthSM_GetVersionInfo.versioninfo[0].sw_patch_version:ETHSM_SW_PATCH_VERSION
TEST.END

-- Subprogram: EthSM_Init

-- Test Case: EthSM_Init.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_Init
TEST.NEW
TEST.NAME:EthSM_Init.001
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CurrentMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_DOWN
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_DOWN
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0
TEST.END

-- Subprogram: EthSM_MainFunction

-- Test Case: EthSM_MainFunction.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_MainFunction
TEST.NEW
TEST.NAME:EthSM_MainFunction.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_UNINIT
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_MainFunction.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_MainFunction
TEST.NEW
TEST.NAME:EthSM_MainFunction.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_FULL_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_FULL_COMMUNICATION
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_MainFunction.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_MainFunction
TEST.NEW
TEST.NAME:EthSM_MainFunction.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_NO_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_NO_COMMUNICATION
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_MainFunction.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_MainFunction
TEST.NEW
TEST.NAME:EthSM_MainFunction.004
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_SILENT_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_SILENT_COMMUNICATION
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_NoComStateHandler

-- Test Case: EthSM_NoComStateHandler.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_TRCVLINK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.004
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.005
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.005
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.006
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.006
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONHOLD
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.007
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.007
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONHOLD
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONHOLD
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONHOLD
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.008
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.008
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_ONHOLD
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.009
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.009
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.010
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.010
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.011
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.011
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.012
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.012
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.013
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.013
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:ETHSM_STATE_WAIT_OFFLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_NoComStateHandler.014
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_NoComStateHandler
TEST.NEW
TEST.NAME:EthSM_NoComStateHandler.014
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:6
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_NoComStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:(2)ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:(2)E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:(2)ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:(2)E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].NetworkMode:6
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_RequestComMode

-- Test Case: EthSM_RequestComMode.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestComMode
TEST.NEW
TEST.NAME:EthSM_RequestComMode.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_UNINIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.EXPECTED:EthSM.EthSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_UNINIT
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_RequestComMode.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestComMode
TEST.NEW
TEST.NAME:EthSM_RequestComMode.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:1
TEST.VALUE:EthSM.EthSM_RequestComMode.NetworkHandle:0
TEST.EXPECTED:EthSM.EthSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_INVALID_NETWORK_HANDLE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_RequestComMode.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestComMode
TEST.NEW
TEST.NAME:EthSM_RequestComMode.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.EthSM_RequestComMode.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_RequestComMode.ComM_Mode:3
TEST.EXPECTED:EthSM.EthSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_INVALID_NETWORK_MODE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_RequestComMode.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestComMode
TEST.NEW
TEST.NAME:EthSM_RequestComMode.004
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.EthSM_RequestComMode.NetworkHandle:0
TEST.VALUE:EthSM.EthSM_RequestComMode.ComM_Mode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:EthSM.EthSM_RequestComMode.return:E_OK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_RequestEthIfModeChg

-- Test Case: EthSM_RequestEthIfModeChg.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestEthIfModeChg
TEST.NEW
TEST.NAME:EthSM_RequestEthIfModeChg.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x2
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_RequestEthIfModeChg.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x2
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_RequestEthIfModeChg.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestEthIfModeChg
TEST.NEW
TEST.NAME:EthSM_RequestEthIfModeChg.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x4
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_RequestEthIfModeChg.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x4
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_RequestEthIfModeChg.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestEthIfModeChg
TEST.NEW
TEST.NAME:EthSM_RequestEthIfModeChg.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:FALSE
TEST.VALUE:EthSM.EthSM_RequestEthIfModeChg.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x2
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_RequestEthIfModeChg.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestEthIfModeChg
TEST.NEW
TEST.NAME:EthSM_RequestEthIfModeChg.004
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_SILENT_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_RequestEthIfModeChg.NetworkHandle:0
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x6
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_RequestEthIfModeChg.005
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestEthIfModeChg
TEST.NEW
TEST.NAME:EthSM_RequestEthIfModeChg.005
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestedMode:COMM_NO_COMMUNICATION
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_RequestEthIfModeChg.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_SetControllerMode.return:E_NOT_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0x6
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_RequestTcpIpModeChg

-- Test Case: EthSM_RequestTcpIpModeChg.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_RequestTcpIpModeChg
TEST.NEW
TEST.NAME:EthSM_RequestTcpIpModeChg.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].RequestStream:0xFF
TEST.VALUE:EthSM.EthSM_RequestTcpIpModeChg.State:TCPIP_STATE_ONLINE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_TcpIpModeIndication

-- Test Case: EthSM_TcpIpModeIndication.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TcpIpModeIndication
TEST.NEW
TEST.NAME:EthSM_TcpIpModeIndication.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_UNINIT
TEST.EXPECTED:EthSM.EthSM_TcpIpModeIndication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTINTERNALMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_UNINIT
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TcpIpModeIndication.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TcpIpModeIndication
TEST.NEW
TEST.NAME:EthSM_TcpIpModeIndication.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:1
TEST.VALUE:EthSM.EthSM_TcpIpModeIndication.CtrlIdx:0
TEST.EXPECTED:EthSM.EthSM_TcpIpModeIndication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTINTERNALMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_PARAM_CONTROLLER
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TcpIpModeIndication.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TcpIpModeIndication
TEST.NEW
TEST.NAME:EthSM_TcpIpModeIndication.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.EthSM_TcpIpModeIndication.CtrlIdx:0
TEST.VALUE:EthSM.EthSM_TcpIpModeIndication.TcpIpState:6
TEST.EXPECTED:EthSM.EthSM_TcpIpModeIndication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_GETCURRENTINTERNALMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_INVALID_TCP_IP_MODE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TcpIpModeIndication.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TcpIpModeIndication
TEST.NEW
TEST.NAME:EthSM_TcpIpModeIndication.004
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.EthSM_TcpIpModeIndication.CtrlIdx:0
TEST.VALUE:EthSM.EthSM_TcpIpModeIndication.TcpIpState:TCPIP_STATE_ONLINE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_ONLINE
TEST.EXPECTED:EthSM.EthSM_TcpIpModeIndication.return:E_OK
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_TransferOfflineStateHandler

-- Test Case: EthSM_TransferOfflineStateHandler.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TransferOfflineStateHandler
TEST.NEW
TEST.NAME:EthSM_TransferOfflineStateHandler.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_TransferOfflineStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TransferOfflineStateHandler.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TransferOfflineStateHandler
TEST.NEW
TEST.NAME:EthSM_TransferOfflineStateHandler.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TcpIpState:TCPIP_STATE_OFFLINE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.NumOfNetworks:1
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:EthSM.EthSM_TransferOfflineStateHandler.NetworkHandle:0
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:ETH_MODE_DOWN
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.TrcvModePtr[0]:ETHTRCV_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_DOWN
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_TrcvLinkStateChg

-- Test Case: EthSM_TrcvLinkStateChg.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TrcvLinkStateChg
TEST.NEW
TEST.NAME:EthSM_TrcvLinkStateChg.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_TRCVLINKSTATECHG_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_UNINIT
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TrcvLinkStateChg.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TrcvLinkStateChg
TEST.NEW
TEST.NAME:EthSM_TrcvLinkStateChg.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:1
TEST.VALUE:EthSM.EthSM_TrcvLinkStateChg.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_TRCVLINKSTATECHG_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_PARAM_CONTROLLER
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TrcvLinkStateChg.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TrcvLinkStateChg
TEST.NEW
TEST.NAME:EthSM_TrcvLinkStateChg.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.EthSM_TrcvLinkStateChg.CtrlIdx:0
TEST.VALUE:EthSM.EthSM_TrcvLinkStateChg.TransceiverLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_ACTIVE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TrcvLinkStateChg.004
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TrcvLinkStateChg
TEST.NEW
TEST.NAME:EthSM_TrcvLinkStateChg.004
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.EthSM_TrcvLinkStateChg.CtrlIdx:0
TEST.VALUE:EthSM.EthSM_TrcvLinkStateChg.TransceiverLinkState:3
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvLinkState:ETHTRCV_LINK_STATE_DOWN
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_TrcvModeIndication

-- Test Case: EthSM_TrcvModeIndication.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TrcvModeIndication
TEST.NEW
TEST.NAME:EthSM_TrcvModeIndication.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_TRCVMODEINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_UNINIT
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TrcvModeIndication.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TrcvModeIndication
TEST.NEW
TEST.NAME:EthSM_TrcvModeIndication.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:1
TEST.VALUE:EthSM.EthSM_TrcvModeIndication.CtrlIdx:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:ETHSM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:ETHSM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:ETHSM_TRCVMODEINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:ETHSM_E_PARAM_CONTROLLER
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_TrcvModeIndication.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_TrcvModeIndication
TEST.NEW
TEST.NAME:EthSM_TrcvModeIndication.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_InitStatus:ETHSM_STATUS_INIT
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.EthSM_TrcvModeIndication.CtrlIdx:0
TEST.VALUE:EthSM.EthSM_TrcvModeIndication.TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_ACTIVE
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: EthSM_UpdateControllerMode

-- Test Case: EthSM_UpdateControllerMode.001
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_UpdateControllerMode
TEST.NEW
TEST.NAME:EthSM_UpdateControllerMode.001
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_DOWN
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_UpdateControllerMode.002
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_UpdateControllerMode
TEST.NEW
TEST.NAME:EthSM_UpdateControllerMode.002
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:FALSE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:E_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_DOWN
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EthSM_UpdateControllerMode.003
TEST.UNIT:EthSM
TEST.SUBPROGRAM:EthSM_UpdateControllerMode
TEST.NEW
TEST.NAME:EthSM_UpdateControllerMode.003
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_DOWN
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig:<<malloc 1>>
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMEthIfControllerId:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMComMNetworkHandle:0
TEST.VALUE:EthSM.<<GLOBAL>>.EthSM_Config.pNetworkConfig[0].EthSMIsEthTrcvAvailable:TRUE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.CtrlModePtr[0]:ETH_MODE_ACTIVE
TEST.VALUE:uut_prototype_stubs.EthIf_GetControllerMode.return:E_OK
TEST.VALUE:uut_prototype_stubs.EthIf_GetTransceiverMode.return:E_NOT_OK
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].CtrlMode:ETH_MODE_ACTIVE
TEST.EXPECTED:EthSM.<<GLOBAL>>.EthSM_NetworkStatus[0].TrcvMode:ETHTRCV_MODE_DOWN
TEST.VALUE_USER_CODE:EthSM.<<GLOBAL>>.pEthSMConfig
<<EthSM.<<GLOBAL>>.pEthSMConfig>> = ( &EthSM_Config );
TEST.END_VALUE_USER_CODE:
TEST.END
