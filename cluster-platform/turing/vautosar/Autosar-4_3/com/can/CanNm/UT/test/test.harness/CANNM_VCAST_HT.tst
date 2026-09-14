-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : CANNM_VCAST_HT
-- Unit(s) Under Test: CanNm
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CanNm

-- Subprogram: CanNm_CheckRemoteSleepIndication

-- Test Case: CanNm_CheckRemoteSleepIndication.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:CanNm_CheckRemoteSleepIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:1
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr[0]:0
TEST.EXPECTED:CanNm.CanNm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_CHECKREMOTESLEEPIND_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_CheckRemoteSleepIndication.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:CanNm_CheckRemoteSleepIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:1
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmChannelHandle:CANNM_NM_NUM_OF_CHANNELS
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr[0]:0
TEST.EXPECTED:CanNm.CanNm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_CHECKREMOTESLEEPIND_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_CheckRemoteSleepIndication.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:CanNm_CheckRemoteSleepIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:1
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmChannelHandle:CANNM_NM_NUM_OF_CHANNELS
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr[0]:0
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_CheckRemoteSleepIndication.return:E_OK
TEST.END

-- Test Case: CanNm_CheckRemoteSleepIndication.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:CanNm_CheckRemoteSleepIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:1
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmChannelHandle:CANNM_NM_NUM_OF_CHANNELS
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_CheckRemoteSleepIndication.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:CanNm_CheckRemoteSleepIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:1
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmChannelHandle:CANNM_NM_NUM_OF_CHANNELS
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr[0]:0
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.EXPECTED:CanNm.CanNm_CheckRemoteSleepIndication.return:E_OK
TEST.END

-- Test Case: CanNm_CheckRemoteSleepIndication.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_CheckRemoteSleepIndication
TEST.NEW
TEST.NAME:CanNm_CheckRemoteSleepIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:1
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmChannelHandle:CANNM_NM_NUM_OF_CHANNELS
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_CheckRemoteSleepIndication.nmRemoteSleepIndPtr[0]:0
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.EXPECTED:CanNm.CanNm_CheckRemoteSleepIndication.return:E_NOT_OK
TEST.END

-- Subprogram: CanNm_ComControlProcessing

-- Test Case: CanNm_ComControlProcessing.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_ComControlProcessing
TEST.NEW
TEST.NAME:CanNm_ComControlProcessing.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_ComControlProcessing.Channel:CANNM_NUM_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_ComControlProcessing.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_ComControlProcessing
TEST.NEW
TEST.NAME:CanNm_ComControlProcessing.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_ComControlProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.END

-- Test Case: CanNm_ComControlProcessing.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_ComControlProcessing
TEST.NEW
TEST.NAME:CanNm_ComControlProcessing.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_ComControlProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.END

-- Test Case: CanNm_ComControlProcessing.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_ComControlProcessing
TEST.NEW
TEST.NAME:CanNm_ComControlProcessing.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleOffset:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_ComControlProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.END

-- Test Case: CanNm_ComControlProcessing.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_ComControlProcessing
TEST.NEW
TEST.NAME:CanNm_ComControlProcessing.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleOffset:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_ComControlProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:11
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.END

-- Test Case: CanNm_ComControlProcessing.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_ComControlProcessing
TEST.NEW
TEST.NAME:CanNm_ComControlProcessing.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleOffset:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_ComControlProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:11
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:301
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.END

-- Subprogram: CanNm_Det_ReportError

-- Test Case: CanNm_Det_ReportError.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_Det_ReportError
TEST.NEW
TEST.NAME:CanNm_Det_ReportError.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_Det_ReportError.ApiId:CANNM_SID_PASSIVESTARTUP_API
TEST.VALUE:CanNm.CanNm_Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:CANNM_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:CANNM_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_PASSIVESTARTUP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Subprogram: CanNm_DisableCommunication

-- Test Case: CanNm_DisableCommunication.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_DisableCommunication
TEST.NEW
TEST.NAME:CanNm_DisableCommunication.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.CanNm_DisableCommunication.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_DisableCommunication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_DISABLECOMMUNICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_DisableCommunication.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_DisableCommunication
TEST.NEW
TEST.NAME:CanNm_DisableCommunication.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.CanNm_DisableCommunication.nmChannelHandle:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:0
TEST.EXPECTED:CanNm.CanNm_DisableCommunication.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_DisableCommunication.return:0
TEST.END

-- Test Case: CanNm_DisableCommunication.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_DisableCommunication
TEST.NEW
TEST.NAME:CanNm_DisableCommunication.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.CanNm_DisableCommunication.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_DisableCommunication.return:E_OK
TEST.END

-- Test Case: CanNm_DisableCommunication.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_DisableCommunication
TEST.NEW
TEST.NAME:CanNm_DisableCommunication.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.CanNm_DisableCommunication.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.EXPECTED:CanNm.CanNm_DisableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_DisableCommunication.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_DisableCommunication
TEST.NEW
TEST.NAME:CanNm_DisableCommunication.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.CanNm_DisableCommunication.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:2
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.EXPECTED:CanNm.CanNm_DisableCommunication.return:E_NOT_OK
TEST.END

-- Subprogram: CanNm_EnableCommunication

-- Test Case: CanNm_EnableCommunication.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_EnableCommunication
TEST.NEW
TEST.NAME:CanNm_EnableCommunication.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_EnableCommunication.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_EnableCommunication.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_ENABLECOMMUNICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_EnableCommunication.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_EnableCommunication
TEST.NEW
TEST.NAME:CanNm_EnableCommunication.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_EnableCommunication.nmChannelHandle:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:1
TEST.EXPECTED:CanNm.CanNm_EnableCommunication.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_EnableCommunication.return:0
TEST.END

-- Test Case: CanNm_EnableCommunication.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_EnableCommunication
TEST.NEW
TEST.NAME:CanNm_EnableCommunication.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_EnableCommunication.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_EnableCommunication.return:E_OK
TEST.END

-- Test Case: CanNm_EnableCommunication.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_EnableCommunication
TEST.NEW
TEST.NAME:CanNm_EnableCommunication.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_EnableCommunication.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.EXPECTED:CanNm.CanNm_EnableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_EnableCommunication.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_EnableCommunication
TEST.NEW
TEST.NAME:CanNm_EnableCommunication.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_EnableCommunication.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.EXPECTED:CanNm.CanNm_EnableCommunication.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_EnableCommunication.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_EnableCommunication
TEST.NEW
TEST.NAME:CanNm_EnableCommunication.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.CanNm_EnableCommunication.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.EXPECTED:CanNm.CanNm_EnableCommunication.return:E_NOT_OK
TEST.END

-- Subprogram: CanNm_GetChIndexFromNmIndex

-- Test Case: CanNm_GetChIndexFromNmIndex.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetChIndexFromNmIndex
TEST.NEW
TEST.NAME:CanNm_GetChIndexFromNmIndex.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:CANNM_NM_NUM_OF_CHANNELS
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromNmIndex.return:CANNM_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_GetChIndexFromNmIndex.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetChIndexFromNmIndex
TEST.NEW
TEST.NAME:CanNm_GetChIndexFromNmIndex.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_NmToCanNmChannelMapping[0]:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:0
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.END

-- Subprogram: CanNm_GetChIndexFromRxPduId

-- Test Case: CanNm_GetChIndexFromRxPduId.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetChIndexFromRxPduId
TEST.NEW
TEST.NAME:CanNm_GetChIndexFromRxPduId.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:4
TEST.VALUE:CanNm.CanNm_GetChIndexFromRxPduId.RxPduId:1
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromRxPduId.return:CANNM_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_GetChIndexFromRxPduId.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetChIndexFromRxPduId
TEST.NEW
TEST.NAME:CanNm_GetChIndexFromRxPduId.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:4
TEST.VALUE:CanNm.CanNm_GetChIndexFromRxPduId.RxPduId:2
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromRxPduId.return:0
TEST.END

-- Test Case: CanNm_GetChIndexFromRxPduId.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetChIndexFromRxPduId
TEST.NEW
TEST.NAME:CanNm_GetChIndexFromRxPduId.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:4
TEST.VALUE:CanNm.CanNm_GetChIndexFromRxPduId.RxPduId:5
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromRxPduId.RxPduId:5
TEST.END

-- Subprogram: CanNm_GetChIndexFromTxPduId

-- Test Case: CanNm_GetChIndexFromTxPduId.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetChIndexFromTxPduId
TEST.NEW
TEST.NAME:CanNm_GetChIndexFromTxPduId.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgId:5
TEST.VALUE:CanNm.CanNm_GetChIndexFromTxPduId.TxPduId:0
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromTxPduId.return:CANNM_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_GetChIndexFromTxPduId.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetChIndexFromTxPduId
TEST.NEW
TEST.NAME:CanNm_GetChIndexFromTxPduId.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgId:5
TEST.VALUE:CanNm.CanNm_GetChIndexFromTxPduId.TxPduId:5
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromTxPduId.return:0
TEST.END

-- Subprogram: CanNm_GetLocalNodeIdentifier

-- Test Case: CanNm_GetLocalNodeIdentifier.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetLocalNodeIdentifier.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NodeId:77
TEST.VALUE:CanNm.CanNm_GetLocalNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:CanNm.CanNm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_GETLOCALNODEIDENTIFIER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_GetLocalNodeIdentifier.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetLocalNodeIdentifier.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NodeId:77
TEST.VALUE:CanNm.CanNm_GetLocalNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NodeId:77
TEST.EXPECTED:CanNm.CanNm_GetLocalNodeIdentifier.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_GetLocalNodeIdentifier.return:0
TEST.END

-- Test Case: CanNm_GetLocalNodeIdentifier.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetLocalNodeIdentifier.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NodeId:77
TEST.VALUE:CanNm.CanNm_GetLocalNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetLocalNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetLocalNodeIdentifier.return:E_OK
TEST.END

-- Test Case: CanNm_GetLocalNodeIdentifier.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetLocalNodeIdentifier.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NodeId:77
TEST.VALUE:CanNm.CanNm_GetLocalNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_GetLocalNodeIdentifier.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetLocalNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetLocalNodeIdentifier.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NodeId:77
TEST.VALUE:CanNm.CanNm_GetLocalNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.CanNm_GetLocalNodeIdentifier.return:E_NOT_OK
TEST.END

-- Subprogram: CanNm_GetNodeIdentifier

-- Test Case: CanNm_GetNodeIdentifier.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetNodeIdentifier.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:77
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:CanNm.CanNm_GetNodeIdentifier.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_GETNODEIDENTIFIER_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_GetNodeIdentifier.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetNodeIdentifier.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:77
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:77
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0
TEST.EXPECTED:CanNm.CanNm_GetNodeIdentifier.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_GetNodeIdentifier.return:0
TEST.END

-- Test Case: CanNm_GetNodeIdentifier.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetNodeIdentifier.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:77
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetNodeIdentifier.return:E_OK
TEST.END

-- Test Case: CanNm_GetNodeIdentifier.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetNodeIdentifier.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:77
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_GetNodeIdentifier.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetNodeIdentifier.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:77
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0xFF
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0xFF
TEST.EXPECTED:CanNm.CanNm_GetNodeIdentifier.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_GetNodeIdentifier.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetNodeIdentifier.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:77
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0x0
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetNodeIdentifier.return:E_NOT_OK
TEST.ATTRIBUTES:CanNm.<<GLOBAL>>.CanNm_ChannelConfig.CanNm_ChannelConfig[0].PduNidPosition:EXPECTED_BASE=16
TEST.END

-- Test Case: CanNm_GetNodeIdentifier.007
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetNodeIdentifier
TEST.NEW
TEST.NAME:CanNm_GetNodeIdentifier.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:77
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetNodeIdentifier.nmNodeIdPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.CanNm_GetNodeIdentifier.return:E_NOT_OK
TEST.END

-- Subprogram: CanNm_GetPduData

-- Test Case: CanNm_GetPduData.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetPduData
TEST.NEW
TEST.NAME:CanNm_GetPduData.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.CanNm_GetPduData.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[0]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[1]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[2]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[3]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[4]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[5]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[6]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[7]:0
TEST.EXPECTED:CanNm.CanNm_GetPduData.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_GETPDUDATA_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_GetPduData.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetPduData
TEST.NEW
TEST.NAME:CanNm_GetPduData.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.CanNm_GetPduData.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[0]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[1]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[2]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[3]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[4]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[5]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[6]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[7]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmPduDataPtr[0]:1
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmPduDataPtr[1]:2
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmPduDataPtr[2]:3
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmPduDataPtr[3]:4
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmPduDataPtr[4]:5
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmPduDataPtr[5]:6
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmPduDataPtr[6]:7
TEST.EXPECTED:CanNm.CanNm_GetPduData.nmPduDataPtr[7]:8
TEST.EXPECTED:CanNm.CanNm_GetPduData.return:0
TEST.END

-- Test Case: CanNm_GetPduData.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetPduData
TEST.NEW
TEST.NAME:CanNm_GetPduData.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.CanNm_GetPduData.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[0]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[1]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[2]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[3]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[4]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[5]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[6]:0
TEST.VALUE:CanNm.CanNm_GetPduData.nmPduDataPtr[7]:0
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetPduData.return:E_OK
TEST.END

-- Test Case: CanNm_GetPduData.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetPduData
TEST.NEW
TEST.NAME:CanNm_GetPduData.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.CanNm_GetPduData.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetPduData.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_GetPduData.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetPduData
TEST.NEW
TEST.NAME:CanNm_GetPduData.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.CanNm_GetPduData.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.CanNm_GetPduData.return:E_NOT_OK
TEST.END

-- Subprogram: CanNm_GetState

-- Test Case: CanNm_GetState.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetState
TEST.NEW
TEST.NAME:CanNm_GetState.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetState.nmModePtr:<<malloc 1>>
TEST.EXPECTED:CanNm.CanNm_GetState.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_GETSTATE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_GetState.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetState
TEST.NEW
TEST.NAME:CanNm_GetState.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetState.nmModePtr:<<malloc 1>>
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_GetState.return:0
TEST.END

-- Test Case: CanNm_GetState.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetState
TEST.NEW
TEST.NAME:CanNm_GetState.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetState.nmModePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetState.return:E_OK
TEST.END

-- Test Case: CanNm_GetState.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetState
TEST.NEW
TEST.NAME:CanNm_GetState.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_GetState.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_GetState.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetState
TEST.NEW
TEST.NAME:CanNm_GetState.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_GetState.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_GetState.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetState
TEST.NEW
TEST.NAME:CanNm_GetState.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetState.nmModePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.EXPECTED:CanNm.CanNm_GetState.return:E_OK
TEST.END

-- Test Case: CanNm_GetState.007
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetState
TEST.NEW
TEST.NAME:CanNm_GetState.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetState.nmModePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:CanNm.CanNm_GetState.return:E_OK
TEST.END

-- Test Case: CanNm_GetState.008
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetState
TEST.NEW
TEST.NAME:CanNm_GetState.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetState.nmStatePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetState.nmModePtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:CanNm.CanNm_GetState.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_GetState.return:1
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.END

-- Subprogram: CanNm_GetVersionInfo

-- Test Case: CanNm_GetVersionInfo.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetVersionInfo
TEST.NEW
TEST.NAME:CanNm_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_GetVersionInfo.versioninfo:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_PARAM_POINTER
TEST.END

-- Test Case: CanNm_GetVersionInfo.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_GetVersionInfo
TEST.NEW
TEST.NAME:CanNm_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_GetVersionInfo.versioninfo:<<malloc 1>>
TEST.EXPECTED:CanNm.CanNm_GetVersionInfo.versioninfo[0].vendorID:CANNM_VENDOR_ID
TEST.EXPECTED:CanNm.CanNm_GetVersionInfo.versioninfo[0].moduleID:CANNM_MODULE_ID
TEST.EXPECTED:CanNm.CanNm_GetVersionInfo.versioninfo[0].sw_major_version:CANNM_SW_MAJOR_VERSION
TEST.EXPECTED:CanNm.CanNm_GetVersionInfo.versioninfo[0].sw_minor_version:CANNM_SW_MINOR_VERSION
TEST.EXPECTED:CanNm.CanNm_GetVersionInfo.versioninfo[0].sw_patch_version:CANNM_SW_PATCH_VERSION
TEST.END

-- Subprogram: CanNm_Init

-- Test Case: CanNm_Init.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_Init
TEST.NEW
TEST.NAME:CanNm_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_Init.CannmConfigPtr:<<null>>
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.END

-- Subprogram: CanNm_InitMemory

-- Test Case: CanNm_InitMemory.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_InitMemory
TEST.NEW
TEST.NAME:CanNm_InitMemory.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_UNINIT
TEST.END

-- Subprogram: CanNm_LocalInit

-- Test Case: CanNm_LocalInit.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalInit
TEST.NEW
TEST.NAME:CanNm_LocalInit.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_LocalInit.Channel:CANNM_NUM_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_INIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_LocalInit.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalInit
TEST.NEW
TEST.NAME:CanNm_LocalInit.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:CANNM_PDU_OFF
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:CANNM_PDU_OFF
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].UnusedDataByteVal:0xAA
TEST.VALUE:CanNm.CanNm_LocalInit.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_READY_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][0]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][2]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][3]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][4]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][5]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][6]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][7]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.END

-- Test Case: CanNm_LocalInit.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalInit
TEST.NEW
TEST.NAME:CanNm_LocalInit.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].UnusedDataByteVal:0xAA
TEST.VALUE:CanNm.CanNm_LocalInit.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_READY_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][0]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][2]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][3]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][4]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][5]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][6]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][7]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.END

-- Test Case: CanNm_LocalInit.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalInit
TEST.NEW
TEST.NAME:CanNm_LocalInit.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].UnusedDataByteVal:0xAA
TEST.VALUE:CanNm.CanNm_LocalInit.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_READY_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][0]:0x0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0x0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][2]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][3]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][4]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][5]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][6]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][7]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.END

-- Test Case: CanNm_LocalInit.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalInit
TEST.NEW
TEST.NAME:CanNm_LocalInit.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduNidPosition:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].UnusedDataByteVal:0xAA
TEST.VALUE:CanNm.CanNm_LocalInit.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_READY_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][0]:0x0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0x0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][2]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][3]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][4]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][5]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][6]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][7]:0xAA
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.END

-- Subprogram: CanNm_LocalMainFunction

-- Test Case: CanNm_LocalMainFunction.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:CANNM_NUM_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_LocalMainFunction.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:20
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:10
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:19
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:9
TEST.END

-- Test Case: CanNm_LocalMainFunction.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:20
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:10
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:19
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:9
TEST.END

-- Test Case: CanNm_LocalMainFunction.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:20
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:10
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlStateRequest[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:200
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:0
TEST.END

-- Test Case: CanNm_LocalMainFunction.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:CANNM_PDU_OFF
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.END

-- Test Case: CanNm_LocalMainFunction.009
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.END

-- Test Case: CanNm_LocalMainFunction.010
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_ACTIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.END

-- Test Case: CanNm_LocalMainFunction.011
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.END

-- Test Case: CanNm_LocalMainFunction.012
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.END

-- Test Case: CanNm_LocalMainFunction.013
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.013
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.END

-- Test Case: CanNm_LocalMainFunction.014
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.014
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.END

-- Test Case: CanNm_LocalMainFunction.015
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.015
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:0
TEST.END

-- Test Case: CanNm_LocalMainFunction.016
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.016
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:4
TEST.END

-- Test Case: CanNm_LocalMainFunction.017
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.017
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].WaitBusSleepTime:5000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:200
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.END

-- Test Case: CanNm_LocalMainFunction.018
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.018
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].WaitBusSleepTime:5000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.END

-- Test Case: CanNm_LocalMainFunction.019
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.019
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:0
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:0
TEST.END

-- Test Case: CanNm_LocalMainFunction.020
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.020
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:5
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:4
TEST.END

-- Test Case: CanNm_LocalMainFunction.021
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.021
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.END

-- Test Case: CanNm_LocalMainFunction.022
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.022
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:CANNM_COMM_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.END

-- Test Case: CanNm_LocalMainFunction.023
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.023
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.END

-- Test Case: CanNm_LocalMainFunction.024
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.024
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:5
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:4
TEST.END

-- Test Case: CanNm_LocalMainFunction.025
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.025
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.END

-- Test Case: CanNm_LocalMainFunction.026
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.026
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.END

-- Test Case: CanNm_LocalMainFunction.027
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.027
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:4
TEST.END

-- Test Case: CanNm_LocalMainFunction.028
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.028
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:TRUE
TEST.EXPECTED:uut_prototype_stubs.Nm_RemoteSleepIndication.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_LocalMainFunction.029
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.029
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ImmediateNmCycleTime:500
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleTime:1000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:0
TEST.END

-- Test Case: CanNm_LocalMainFunction.030
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.030
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ImmediateNmCycleTime:500
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleTime:1000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:4
TEST.END

-- Test Case: CanNm_LocalMainFunction.031
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.031
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ImmediateNmCycleTime:500
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleTime:1000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:100
TEST.END

-- Test Case: CanNm_LocalMainFunction.032
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.032
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ImmediateNmCycleTime:500
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleTime:1000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:50
TEST.END

-- Test Case: CanNm_LocalMainFunction.033
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.033
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ImmediateNmCycleTime:500
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleTime:1000
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:50
TEST.END

-- Test Case: CanNm_LocalMainFunction.035
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.035
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:0
TEST.END

-- Test Case: CanNm_LocalMainFunction.036
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.036
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:4
TEST.END

-- Test Case: CanNm_LocalMainFunction.037
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_LocalMainFunction
TEST.NEW
TEST.NAME:CanNm_LocalMainFunction.037
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_LocalMainFunction.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimeoutTimer[0]:0
TEST.EXPECTED:uut_prototype_stubs.Nm_TxTimeoutException.nmNetworkHandle:1
TEST.END

-- Subprogram: CanNm_MainFunction

-- Test Case: CanNm_MainFunction.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_MainFunction
TEST.NEW
TEST.NAME:CanNm_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:TRUE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:TRUE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_MainFunction.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_MainFunction
TEST.NEW
TEST.NAME:CanNm_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:TRUE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.END

-- Subprogram: CanNm_NetworkRelease

-- Test Case: CanNm_NetworkRelease.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRelease
TEST.NEW
TEST.NAME:CanNm_NetworkRelease.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_NetworkRelease.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_NetworkRelease.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_NETWORKRELEASE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_NetworkRelease.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRelease
TEST.NEW
TEST.NAME:CanNm_NetworkRelease.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.CanNm_NetworkRelease.nmChannelHandle:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.CanNm_NetworkRelease.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_NetworkRelease.return:0
TEST.END

-- Test Case: CanNm_NetworkRelease.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRelease
TEST.NEW
TEST.NAME:CanNm_NetworkRelease.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.CanNm_NetworkRelease.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.CanNm_NetworkRelease.return:E_OK
TEST.END

-- Test Case: CanNm_NetworkRelease.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRelease
TEST.NEW
TEST.NAME:CanNm_NetworkRelease.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.CanNm_NetworkRelease.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.CanNm_NetworkRelease.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_NetworkRelease.return:1
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.END

-- Subprogram: CanNm_NetworkRequest

-- Test Case: CanNm_NetworkRequest.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRequest
TEST.NEW
TEST.NAME:CanNm_NetworkRequest.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_NetworkRequest.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_NetworkRequest.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_NETWORKREQUEST_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_NetworkRequest.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRequest
TEST.NEW
TEST.NAME:CanNm_NetworkRequest.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_NetworkRequest.nmChannelHandle:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.CanNm_NetworkRequest.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_NetworkRequest.return:0
TEST.END

-- Test Case: CanNm_NetworkRequest.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRequest
TEST.NEW
TEST.NAME:CanNm_NetworkRequest.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_NetworkRequest.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_CommState[0]:1
TEST.EXPECTED:CanNm.CanNm_NetworkRequest.return:E_OK
TEST.END

-- Test Case: CanNm_NetworkRequest.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRequest
TEST.NEW
TEST.NAME:CanNm_NetworkRequest.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_NetworkRequest.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_CommState[0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:1
TEST.EXPECTED:CanNm.CanNm_NetworkRequest.return:E_OK
TEST.END

-- Test Case: CanNm_NetworkRequest.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRequest
TEST.NEW
TEST.NAME:CanNm_NetworkRequest.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.CanNm_NetworkRequest.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_CommState[0]:1
TEST.EXPECTED:CanNm.CanNm_NetworkRequest.return:E_OK
TEST.END

-- Test Case: CanNm_NetworkRequest.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_NetworkRequest
TEST.NEW
TEST.NAME:CanNm_NetworkRequest.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_CommState[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.CanNm_NetworkRequest.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_CommState[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.EXPECTED:CanNm.CanNm_NetworkRequest.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_NetworkRequest.return:1
TEST.EXPECTED:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.END

-- Subprogram: CanNm_PassiveStartUp

-- Test Case: CanNm_PassiveStartUp.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_PassiveStartUp
TEST.NEW
TEST.NAME:CanNm_PassiveStartUp.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_PassiveStartUp.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_PASSIVESTARTUP_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_PassiveStartUp.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_PassiveStartUp
TEST.NEW
TEST.NAME:CanNm_PassiveStartUp.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.END

-- Test Case: CanNm_PassiveStartUp.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_PassiveStartUp
TEST.NEW
TEST.NAME:CanNm_PassiveStartUp.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.VALUE:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.EXPECTED:CanNm.CanNm_PassiveStartUp.return:E_NOT_OK
TEST.END

-- Test Case: CanNm_PassiveStartUp.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_PassiveStartUp
TEST.NEW
TEST.NAME:CanNm_PassiveStartUp.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.END

-- Test Case: CanNm_PassiveStartUp.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_PassiveStartUp
TEST.NEW
TEST.NAME:CanNm_PassiveStartUp.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.EXPECTED:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.END

-- Test Case: CanNm_PassiveStartUp.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_PassiveStartUp
TEST.NEW
TEST.NAME:CanNm_PassiveStartUp.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.END

-- Test Case: CanNm_PassiveStartUp.007
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_PassiveStartUp
TEST.NEW
TEST.NAME:CanNm_PassiveStartUp.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.STUB:CanNm.CanNm_GetChIndexFromNmIndex
TEST.STUB:CanNm.CanNm_Det_ReportError
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.nmChannelHandle:1
TEST.VALUE:CanNm.CanNm_GetChIndexFromNmIndex.return:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_InitStatus:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.EXPECTED:CanNm.CanNm_PassiveStartUp.nmChannelHandle:1
TEST.END

-- Subprogram: CanNm_RxIndication

-- Test Case: CanNm_RxIndication.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[4]:5
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[5]:6
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[7]:8
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_RxIndication.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:0
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[4]:5
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[5]:6
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[7]:8
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_PDUID
TEST.END

-- Test Case: CanNm_RxIndication.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_PARAM_POINTER
TEST.END

-- Test Case: CanNm_RxIndication.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 9>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<null>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_PARAM_POINTER
TEST.END

-- Test Case: CanNm_RxIndication.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[4]:5
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[5]:6
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[7]:8
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.EXPECTED:uut_prototype_stubs.Nm_PduRxIndication.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_RxIndication.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:CANNM_PDU_OFF
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[4]:5
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[5]:6
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[7]:8
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.EXPECTED:uut_prototype_stubs.Nm_PduRxIndication.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_RxIndication.007
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:8
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[4]:5
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[5]:6
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[7]:8
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.EXPECTED:uut_prototype_stubs.Nm_PduRxIndication.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_RxIndication.008
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:0
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[4]:5
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[5]:6
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[7]:8
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.EXPECTED:uut_prototype_stubs.Nm_PduRxIndication.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_RxIndication.009
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:0
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[4]:5
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[5]:6
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[7]:8
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.EXPECTED:uut_prototype_stubs.Nm_PduRxIndication.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_RxIndication.010
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxIndication
TEST.NEW
TEST.NAME:CanNm_RxIndication.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgStartId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmReceiveMsgEndId:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:0
TEST.VALUE:CanNm.CanNm_RxIndication.RxPduId:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 8>>
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[0]:1
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[1]:2
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[2]:3
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[3]:4
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[4]:5
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[5]:6
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[6]:7
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduDataPtr[7]:8
TEST.VALUE:CanNm.CanNm_RxIndication.PduInfoPtr[0].SduLength:8
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][1]:2
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][2]:3
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][3]:4
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][4]:5
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][5]:6
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][6]:7
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RxMessageData[0][7]:8
TEST.EXPECTED:uut_prototype_stubs.Nm_PduRxIndication.nmNetworkHandle:1
TEST.END

-- Subprogram: CanNm_RxMsgProcessing

-- Test Case: CanNm_RxMsgProcessing.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:CANNM_NUM_OF_CHANNELS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_RxMsgProcessing.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.END

-- Test Case: CanNm_RxMsgProcessing.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.EXPECTED:uut_prototype_stubs.Nm_NetworkStartIndication.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_RxMsgProcessing.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.EXPECTED:uut_prototype_stubs.Nm_NetworkMode.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_RxMsgProcessing.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_DISABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:FALSE
TEST.END

-- Test Case: CanNm_RxMsgProcessing.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgReducedTime:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].BusLoadReductionActive:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:301
TEST.END

-- Test Case: CanNm_RxMsgProcessing.007
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgReducedTime:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].BusLoadReductionActive:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:301
TEST.END

-- Test Case: CanNm_RxMsgProcessing.008
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgReducedTime:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].BusLoadReductionActive:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:11
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:301
TEST.END

-- Test Case: CanNm_RxMsgProcessing.009
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgReducedTime:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].BusLoadReductionActive:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:11
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:301
TEST.END

-- Test Case: CanNm_RxMsgProcessing.010
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgReducedTime:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].BusLoadReductionActive:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:11
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:301
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:uut_prototype_stubs.Nm_RemoteSleepCancellation.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_RxMsgProcessing.011
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_RxMsgProcessing
TEST.NEW
TEST.NAME:CanNm_RxMsgProcessing.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgIndicationFlag[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgReducedTime:100
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].BusLoadReductionActive:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_RxMsgProcessing.Channel:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:uut_prototype_stubs.Nm_RemoteSleepCancellation.nmNetworkHandle:1
TEST.END

-- Subprogram: CanNm_StateTransition

-- Test Case: CanNm_StateTransition.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:CANNM_NUM_OF_CHANNELS
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_BUS_SLEEP
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_CHANNEL
TEST.END

-- Test Case: CanNm_StateTransition.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0xFF
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].WaitBusSleepTime:5000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:FALSE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:501
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:uut_prototype_stubs.Nm_PrepareBusSleepMode.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_StateTransition.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0xFF
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].WaitBusSleepTime:5000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:CANNM_PDU_OFF
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:TRUE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:501
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:uut_prototype_stubs.Nm_PrepareBusSleepMode.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_StateTransition.005
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0xFF
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].WaitBusSleepTime:5000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:TRUE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:501
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:uut_prototype_stubs.Nm_PrepareBusSleepMode.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_StateTransition.006
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0xFF
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].WaitBusSleepTime:5000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:TRUE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:501
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_PREPARE_BUS_SLEEP
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0xEF
TEST.EXPECTED:uut_prototype_stubs.Nm_PrepareBusSleepMode.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_StateTransition.011
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RemoteSleepIndTime:3000
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_NORMAL_OPERATION
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:301
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.END

-- Test Case: CanNm_StateTransition.016
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.016
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleOffset:100
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_NORMAL_OPERATION
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_NORMAL_OPERATION
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:11
TEST.END

-- Test Case: CanNm_StateTransition.020
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.020
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_ACTIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ImmediateNmTransmissionsCount:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleOffset:100
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:101
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:11
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.END

-- Test Case: CanNm_StateTransition.021
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.021
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_PASSIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ImmediateNmTransmissionsCount:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleOffset:100
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:101
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:11
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.END

-- Test Case: CanNm_StateTransition.022
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.022
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_ACTIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxControlState[0]:CANNM_MSG_TX_ENABLED
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ImmediateNmTransmissionsCount:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgCycleOffset:100
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:101
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_ImmediateNmMsgCount[0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgTimer[0]:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.END

-- Test Case: CanNm_StateTransition.023
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.023
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_ACTIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_READY_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:TRUE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:101
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.END

-- Test Case: CanNm_StateTransition.025
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.025
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_PASSIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:TRUE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:101
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:uut_prototype_stubs.Nm_NetworkMode.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_StateTransition.026
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.026
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_ACTIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:CANNM_PDU_OFF
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:TRUE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:101
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:uut_prototype_stubs.Nm_NetworkMode.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_StateTransition.027
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.027
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_ACTIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:TRUE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:101
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:uut_prototype_stubs.Nm_NetworkMode.nmNetworkHandle:1
TEST.END

-- Test Case: CanNm_StateTransition.028
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_StateTransition
TEST.NEW
TEST.NAME:CanNm_StateTransition.028
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_ACTIVE_RESTART
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_BUS_SLEEP
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].NmChannelRef:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].RepeatMessageTime:1000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].TimeoutTime:2000
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].PduCbvPosition:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].ActiveWakeupBitEnabled:TRUE
TEST.VALUE:CanNm.CanNm_StateTransition.Channel:0
TEST.VALUE:CanNm.CanNm_StateTransition.NextNmState:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NetworkRestartFlag[0]:CANNM_NO_RESTART
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TimeoutTimer[0]:201
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_WaitBusSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RepeatMsgTimer[0]:101
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_NmState[0]:NM_STATE_REPEAT_MESSAGE
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:0x10
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepTimer[0]:0
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_RemoteSleepIndState[0]:FALSE
TEST.EXPECTED:uut_prototype_stubs.Nm_NetworkMode.nmNetworkHandle:1
TEST.END

-- Subprogram: CanNm_TriggerTransmission

-- Test Case: CanNm_TriggerTransmission.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_TriggerTransmission
TEST.NEW
TEST.NAME:CanNm_TriggerTransmission.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][0]:1
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][1]:2
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][2]:3
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][3]:4
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][4]:5
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][5]:6
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][6]:7
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_TxMessageData[0][7]:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgLength:8
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_ChannelConfig[0].MsgTimeoutTime:2000
TEST.VALUE:CanNm.CanNm_TriggerTransmission.Channel:CANNM_NUM_OF_CHANNELS
TEST.VALUE:uut_prototype_stubs.CanIf_Transmit.return:E_OK
TEST.EXPECTED:CanNm.CanNm_TriggerTransmission.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_CHANNEL
TEST.END

-- Subprogram: CanNm_TxConfirmation

-- Test Case: CanNm_TxConfirmation.001
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_TxConfirmation
TEST.NEW
TEST.NAME:CanNm_TxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgId:1
TEST.VALUE:CanNm.CanNm_TxConfirmation.TxPduId:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_TXCONFIRMATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_NO_INIT
TEST.END

-- Test Case: CanNm_TxConfirmation.002
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_TxConfirmation
TEST.NEW
TEST.NAME:CanNm_TxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgId:0
TEST.VALUE:CanNm.CanNm_TxConfirmation.TxPduId:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANNM_SID_TXCONFIRMATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANNM_E_INVALID_PDUID
TEST.END

-- Test Case: CanNm_TxConfirmation.003
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_TxConfirmation
TEST.NEW
TEST.NAME:CanNm_TxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgId:1
TEST.VALUE:CanNm.CanNm_TxConfirmation.TxPduId:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:TRUE
TEST.END

-- Test Case: CanNm_TxConfirmation.004
TEST.UNIT:CanNm
TEST.SUBPROGRAM:CanNm_TxConfirmation
TEST.NEW
TEST.NAME:CanNm_TxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanNm::CanNm_Detailed_Design::CanNm_ClassDiagram
Requirement_DICVA-13813
TEST.END_NOTES:
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_InitStatus:TRUE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:FALSE
TEST.VALUE:CanNm.<<GLOBAL>>.CanNM_ChannelPduConfig[0].CanNmTransmitMsgId:1
TEST.VALUE:CanNm.CanNm_TxConfirmation.TxPduId:1
TEST.EXPECTED:CanNm.<<GLOBAL>>.CanNm_MsgConfirmationFlag[0]:TRUE
TEST.END
