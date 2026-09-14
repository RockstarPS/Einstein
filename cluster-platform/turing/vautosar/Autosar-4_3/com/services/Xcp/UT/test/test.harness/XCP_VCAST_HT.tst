-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : XCP_VCAST_HT
-- Unit(s) Under Test: Xcp Xcp_CalibCmd Xcp_DaqCmd Xcp_PagCmd Xcp_PgmCmd Xcp_StdCmd
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: Xcp

-- Subprogram: Xcp_CalcSendQueueEntrySizeAndLimit

-- Test Case: Xcp_CalcSendQueueEntrySizeAndLimit.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_CalcSendQueueEntrySizeAndLimit
TEST.NEW
TEST.NAME:Xcp_CalcSendQueueEntrySizeAndLimit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_CmdProcessorReservedCmd

-- Test Case: Xcp_CmdProcessorReservedCmd.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_CmdProcessorReservedCmd
TEST.NEW
TEST.NAME:Xcp_CmdProcessorReservedCmd.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_DaqResumeProcess

-- Test Case: Xcp_DaqResumeProcess.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_DaqResumeProcess
TEST.NEW
TEST.NAME:Xcp_DaqResumeProcess.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_DaqResumeProcess.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_DaqResumeProcess
TEST.NEW
TEST.NAME:Xcp_DaqResumeProcess.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x4
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SessionStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_DaqResumeProcess.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_DaqResumeProcess
TEST.NEW
TEST.NAME:Xcp_DaqResumeProcess.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x2
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SessionStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_DaqResumeProcess.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_DaqResumeProcess
TEST.NEW
TEST.NAME:Xcp_DaqResumeProcess.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x8
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SessionStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_DaqResumeProcess.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_DaqResumeProcess
TEST.NEW
TEST.NAME:Xcp_DaqResumeProcess.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x1
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SessionStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_DaqResumeProcess.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_DaqResumeProcess
TEST.NEW
TEST.NAME:Xcp_DaqResumeProcess.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x1
TEST.VALUE:uut_prototype_stubs.Xcp_ApplResumeCalStore.return:1
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SessionStatus:EXPECTED_BASE=16
TEST.END

-- Subprogram: Xcp_Disconnect

-- Test Case: Xcp_Disconnect.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Disconnect
TEST.NEW
TEST.NAME:Xcp_Disconnect.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_Disconnect.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Disconnect
TEST.NEW
TEST.NAME:Xcp_Disconnect.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_Disconnect.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Disconnect
TEST.NEW
TEST.NAME:Xcp_Disconnect.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_SendCrm
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_Disconnect.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Disconnect
TEST.NEW
TEST.NAME:Xcp_Disconnect.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_Disconnect.XcpChannel:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_Disconnect.XcpChannel:2
TEST.END

-- Subprogram: Xcp_Event

-- Test Case: Xcp_Event.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Event
TEST.NEW
TEST.NAME:Xcp_Event.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_Event.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Event
TEST.NEW
TEST.NAME:Xcp_Event.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_Event.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Event
TEST.NEW
TEST.NAME:Xcp_Event.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_Event.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Event
TEST.NEW
TEST.NAME:Xcp_Event.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_Event.EventChannel:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_Event.EventChannel:2
TEST.END

-- Test Case: Xcp_Event.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Event
TEST.NEW
TEST.NAME:Xcp_Event.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x40
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x40
TEST.END

-- Subprogram: Xcp_GetActiveTl

-- Test Case: Xcp_GetActiveTl.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_GetActiveTl
TEST.NEW
TEST.NAME:Xcp_GetActiveTl.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_GetActiveTl.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_GetActiveTl
TEST.NEW
TEST.NAME:Xcp_GetActiveTl.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_GetActiveTl.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_GetActiveTl
TEST.NEW
TEST.NAME:Xcp_GetActiveTl.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_GetActiveTl.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_GetActiveTl
TEST.NEW
TEST.NAME:Xcp_GetActiveTl.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_GetActiveTl.XcpChannel:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_GetActiveTl.XcpChannel:2
TEST.END

-- Subprogram: Xcp_GetVersionInfo

-- Test Case: Xcp_GetVersionInfo.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_GetVersionInfo
TEST.NEW
TEST.NAME:Xcp_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_GetVersionInfo.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_GetVersionInfo
TEST.NEW
TEST.NAME:Xcp_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.Xcp_GetVersionInfo.versioninfo:<<malloc 1>>
TEST.END

-- Subprogram: Xcp_GetXcpChannelFromNetworkChannel

-- Test Case: Xcp_GetXcpChannelFromNetworkChannel.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_GetXcpChannelFromNetworkChannel
TEST.NEW
TEST.NAME:Xcp_GetXcpChannelFromNetworkChannel.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_GetXcpChannelFromNetworkChannel.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_GetXcpChannelFromNetworkChannel
TEST.NEW
TEST.NAME:Xcp_GetXcpChannelFromNetworkChannel.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.Xcp_GetXcpChannelFromNetworkChannel.Channel:1
TEST.EXPECTED:Xcp.Xcp_GetXcpChannelFromNetworkChannel.Channel:1
TEST.END

-- Subprogram: Xcp_Init

-- Test Case: Xcp_Init.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Init
TEST.NEW
TEST.NAME:Xcp_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_Init.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Init
TEST.NEW
TEST.NAME:Xcp_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_Init.Xcp_ConfigPtr:<<malloc 1>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_Init.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_Init
TEST.NEW
TEST.NAME:Xcp_Init.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_Init.Xcp_ConfigPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Xcp_ApplCheckDaqResume.return:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Subprogram: Xcp_MainFunction

-- Test Case: Xcp_MainFunction.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_MainFunction
TEST.NEW
TEST.NAME:Xcp_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_MainFunction.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_MainFunction
TEST.NEW
TEST.NAME:Xcp_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_MainFunction.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_MainFunction
TEST.NEW
TEST.NAME:Xcp_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Subprogram: Xcp_ModifyProtectionStatus

-- Test Case: Xcp_ModifyProtectionStatus.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ModifyProtectionStatus
TEST.NEW
TEST.NAME:Xcp_ModifyProtectionStatus.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_ModifyProtectionStatus.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ModifyProtectionStatus
TEST.NEW
TEST.NAME:Xcp_ModifyProtectionStatus.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_ModifyProtectionStatus.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ModifyProtectionStatus
TEST.NEW
TEST.NAME:Xcp_ModifyProtectionStatus.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_ModifyProtectionStatus.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ModifyProtectionStatus
TEST.NEW
TEST.NAME:Xcp_ModifyProtectionStatus.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_ModifyProtectionStatus.XcpChannel:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_ModifyProtectionStatus.XcpChannel:2
TEST.END

-- Test Case: Xcp_ModifyProtectionStatus.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ModifyProtectionStatus
TEST.NEW
TEST.NAME:Xcp_ModifyProtectionStatus.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_ModifyProtectionStatus.SetClear:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_ModifyProtectionStatus.SetClear:1
TEST.END

-- Subprogram: Xcp_ProcessChannelEvent

-- Test Case: Xcp_ProcessChannelEvent.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessChannelEvent
TEST.NEW
TEST.NAME:Xcp_ProcessChannelEvent.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_ProcessChannelEvent.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessChannelEvent
TEST.NEW
TEST.NAME:Xcp_ProcessChannelEvent.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.END

-- Test Case: Xcp_ProcessChannelEvent.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessChannelEvent
TEST.NEW
TEST.NAME:Xcp_ProcessChannelEvent.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x40
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x40
TEST.END

-- Test Case: Xcp_ProcessChannelEvent.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessChannelEvent
TEST.NEW
TEST.NAME:Xcp_ProcessChannelEvent.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x40
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListPrescalarCounter[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x40
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListPrescalarCounter[0]:0
TEST.END

-- Test Case: Xcp_ProcessChannelEvent.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessChannelEvent
TEST.NEW
TEST.NAME:Xcp_ProcessChannelEvent.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x40
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListPrescalarCounter[0]:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x40
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListPrescalarCounter[0]:1
TEST.END

-- Test Case: Xcp_ProcessChannelEvent.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessChannelEvent
TEST.NEW
TEST.NAME:Xcp_ProcessChannelEvent.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x42
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListPrescalarCounter[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x42
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListPrescalarCounter[0]:0
TEST.END

-- Subprogram: Xcp_ProcessEventDaq

-- Test Case: Xcp_ProcessEventDaq.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_ProcessEventDaq.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.END

-- Test Case: Xcp_ProcessEventDaq.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.END

-- Test Case: Xcp_ProcessEventDaq.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.END

-- Test Case: Xcp_ProcessEventDaq.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.END

-- Test Case: Xcp_ProcessEventDaq.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.END

-- Test Case: Xcp_ProcessEventDaq.007
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.END

-- Test Case: Xcp_ProcessEventDaq.008
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_UtilMemCopy
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:<<MAX>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:<<MAX>>
TEST.END

-- Test Case: Xcp_ProcessEventDaq.009
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_UtilMemCopy
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:<<MAX>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSize:10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueueRef[0]:1
TEST.VALUE:Xcp.Xcp_ProcessEventDaq.XcpChannel:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:<<MAX>>
TEST.END

-- Test Case: Xcp_ProcessEventDaq.010
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_UtilMemCopy
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:<<MAX>>
TEST.VALUE:Xcp_CalibCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtEntryIdxOfDaq[0]:2
TEST.VALUE:Xcp_CalibCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtEntryIdxOfDaq[1]:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:<<MAX>>
TEST.END

-- Test Case: Xcp_ProcessEventDaq.011
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventDaq
TEST.NEW
TEST.NAME:Xcp_ProcessEventDaq.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_UtilMemCopy
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:<<MAX>>
TEST.VALUE:Xcp_DaqCmd.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:100
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:7
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:100
TEST.EXPECTED:Xcp_DaqCmd.<<GLOBAL>>.Xcp_DaqSendQueue[0].EntrySize:100
TEST.END

-- Subprogram: Xcp_ProcessEventStim

-- Test Case: Xcp_ProcessEventStim.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_ProcessEventStim.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.END

-- Test Case: Xcp_ProcessEventStim.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.END

-- Test Case: Xcp_ProcessEventStim.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.END

-- Test Case: Xcp_ProcessEventStim.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0][0].Buffer[0]:0xFF
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0][0].Buffer[0]:0xFF
TEST.END

-- Test Case: Xcp_ProcessEventStim.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.END

-- Test Case: Xcp_ProcessEventStim.007
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.END

-- Test Case: Xcp_ProcessEventStim.008
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.END

-- Test Case: Xcp_ProcessEventStim.009
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_UtilMemCopy
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxDto:<<MAX>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[1]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[1]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxDto:<<MAX>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[1]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.END

-- Test Case: Xcp_ProcessEventStim.010
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessEventStim
TEST.NEW
TEST.NAME:Xcp_ProcessEventStim.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_UtilMemCopy
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxDto:<<MAX>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtEntryIdxOfDaq:<<malloc 2>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtEntryIdxOfDaq:"3"
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[1]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[1]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxDto:<<MAX>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntriesOfDaq[1]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x10
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_StimMode:1
TEST.END

-- Subprogram: Xcp_ProcessStimEventStatus

-- Test Case: Xcp_ProcessStimEventStatus.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessStimEventStatus
TEST.NEW
TEST.NAME:Xcp_ProcessStimEventStatus.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_ProcessStimEventStatus.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessStimEventStatus
TEST.NEW
TEST.NAME:Xcp_ProcessStimEventStatus.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.END

-- Test Case: Xcp_ProcessStimEventStatus.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessStimEventStatus
TEST.NEW
TEST.NAME:Xcp_ProcessStimEventStatus.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.END

-- Test Case: Xcp_ProcessStimEventStatus.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessStimEventStatus
TEST.NEW
TEST.NAME:Xcp_ProcessStimEventStatus.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.END

-- Test Case: Xcp_ProcessStimEventStatus.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessStimEventStatus
TEST.NEW
TEST.NAME:Xcp_ProcessStimEventStatus.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_ProcessStimEventStatus.Action:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.EXPECTED:Xcp.Xcp_ProcessStimEventStatus.Action:1
TEST.END

-- Test Case: Xcp_ProcessStimEventStatus.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessStimEventStatus
TEST.NEW
TEST.NAME:Xcp_ProcessStimEventStatus.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0][0].Buffer[0]:0xFF
TEST.VALUE:Xcp.Xcp_ProcessStimEventStatus.Action:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0][0].Buffer[0]:0xFF
TEST.EXPECTED:Xcp.Xcp_ProcessStimEventStatus.Action:1
TEST.END

-- Test Case: Xcp_ProcessStimEventStatus.007
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ProcessStimEventStatus
TEST.NEW
TEST.NAME:Xcp_ProcessStimEventStatus.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_ProcessStimEventStatus.Action:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.OdtEntriesSize[0]:1
TEST.EXPECTED:Xcp.Xcp_ProcessStimEventStatus.Action:2
TEST.END

-- Subprogram: Xcp_ResourceProtectionCheck

-- Test Case: Xcp_ResourceProtectionCheck.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ResourceProtectionCheck
TEST.NEW
TEST.NAME:Xcp_ResourceProtectionCheck.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_ResourceProtectionCheck.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_ResourceProtectionCheck
TEST.NEW
TEST.NAME:Xcp_ResourceProtectionCheck.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResourceProtectionStatus:1
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.Resource:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResourceProtectionStatus:1
TEST.EXPECTED:Xcp.Xcp_ResourceProtectionCheck.Resource:1
TEST.END

-- Subprogram: Xcp_SendAsyncEvent

-- Test Case: Xcp_SendAsyncEvent.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendAsyncEvent
TEST.NEW
TEST.NAME:Xcp_SendAsyncEvent.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_SendAsyncEvent.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendAsyncEvent
TEST.NEW
TEST.NAME:Xcp_SendAsyncEvent.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x70
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SendStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_SendAsyncEvent.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendAsyncEvent
TEST.NEW
TEST.NAME:Xcp_SendAsyncEvent.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x74
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SendStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_SendAsyncEvent.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendAsyncEvent
TEST.NEW
TEST.NAME:Xcp_SendAsyncEvent.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.END

-- Subprogram: Xcp_SendCrm

-- Test Case: Xcp_SendCrm.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendCrm
TEST.NEW
TEST.NAME:Xcp_SendCrm.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_SendCrm.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendCrm
TEST.NEW
TEST.NAME:Xcp_SendCrm.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_SendCrm.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendCrm
TEST.NEW
TEST.NAME:Xcp_SendCrm.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_SendCrm.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendCrm
TEST.NEW
TEST.NAME:Xcp_SendCrm.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_SendCrm.XcpChannel:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_SendCrm.XcpChannel:2
TEST.END

-- Test Case: Xcp_SendCrm.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendCrm
TEST.NEW
TEST.NAME:Xcp_SendCrm.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x70
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SendStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_SendCrm.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendCrm
TEST.NEW
TEST.NAME:Xcp_SendCrm.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xFF
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SendStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_SendCrm.007
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendCrm
TEST.NEW
TEST.NAME:Xcp_SendCrm.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFlushFunctPtrType:Xcp_ApplConnectionStateNotification
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFlushFunctPtrType:Xcp_ApplConnectionStateNotification
TEST.END

-- Test Case: Xcp_SendCrm.008
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendCrm
TEST.NEW
TEST.NAME:Xcp_SendCrm.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFlushFunctPtrType:Xcp_ApplConnectionStateNotification
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFlushFunctPtrType:Xcp_ApplConnectionStateNotification
TEST.END

-- Subprogram: Xcp_SendDtoFromQueue

-- Test Case: Xcp_SendDtoFromQueue.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendDtoFromQueue
TEST.NEW
TEST.NAME:Xcp_SendDtoFromQueue.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_SendDtoFromQueue.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendDtoFromQueue
TEST.NEW
TEST.NAME:Xcp_SendDtoFromQueue.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xF
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xF
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.END

-- Test Case: Xcp_SendDtoFromQueue.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendDtoFromQueue
TEST.NEW
TEST.NAME:Xcp_SendDtoFromQueue.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xF
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x2F
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.END

-- Test Case: Xcp_SendDtoFromQueue.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendDtoFromQueue
TEST.NEW
TEST.NAME:Xcp_SendDtoFromQueue.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xF
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x2F
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.END

-- Test Case: Xcp_SendDtoFromQueue.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendDtoFromQueue
TEST.NEW
TEST.NAME:Xcp_SendDtoFromQueue.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xF
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x2F
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.END

-- Test Case: Xcp_SendDtoFromQueue.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendDtoFromQueue
TEST.NEW
TEST.NAME:Xcp_SendDtoFromQueue.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xF
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:11
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:11
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xF
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:11
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:11
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.END

-- Test Case: Xcp_SendDtoFromQueue.007
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SendDtoFromQueue
TEST.NEW
TEST.NAME:Xcp_SendDtoFromQueue.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0xF
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:11
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x2F
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].ReadIdx:11
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].WriteIdx:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_DaqSendQueue[0].QueueSizeLimit:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_TlConfig[0].TlSendFunctPtr:pTlSendFunct_test
TEST.END

-- Subprogram: Xcp_SetActiveTl

-- Test Case: Xcp_SetActiveTl.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetActiveTl
TEST.NEW
TEST.NAME:Xcp_SetActiveTl.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_SetActiveTl.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetActiveTl
TEST.NEW
TEST.NAME:Xcp_SetActiveTl.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_SetActiveTl.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetActiveTl
TEST.NEW
TEST.NAME:Xcp_SetActiveTl.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_SetActiveTl.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetActiveTl
TEST.NEW
TEST.NAME:Xcp_SetActiveTl.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_SetActiveTl.XcpChannel:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_SetActiveTl.XcpChannel:2
TEST.END

-- Test Case: Xcp_SetActiveTl.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetActiveTl
TEST.NEW
TEST.NAME:Xcp_SetActiveTl.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ActiveTl:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Subprogram: Xcp_SetNegativeResponse

-- Test Case: Xcp_SetNegativeResponse.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetNegativeResponse
TEST.NEW
TEST.NAME:Xcp_SetNegativeResponse.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_SetStimMode

-- Test Case: Xcp_SetStimMode.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetStimMode
TEST.NEW
TEST.NAME:Xcp_SetStimMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_SetStimMode.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetStimMode
TEST.NEW
TEST.NAME:Xcp_SetStimMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_SetStimMode.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetStimMode
TEST.NEW
TEST.NAME:Xcp_SetStimMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_SetStimMode.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetStimMode
TEST.NEW
TEST.NAME:Xcp_SetStimMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_SetStimMode.Mode:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_SetStimMode.Mode:2
TEST.END

-- Subprogram: Xcp_SetTransmissionMode

-- Test Case: Xcp_SetTransmissionMode.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetTransmissionMode
TEST.NEW
TEST.NAME:Xcp_SetTransmissionMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_SetTransmissionMode.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetTransmissionMode
TEST.NEW
TEST.NAME:Xcp_SetTransmissionMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_SetTransmissionMode.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetTransmissionMode
TEST.NEW
TEST.NAME:Xcp_SetTransmissionMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_SetTransmissionMode.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetTransmissionMode
TEST.NEW
TEST.NAME:Xcp_SetTransmissionMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_SetTransmissionMode.Mode:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_SetTransmissionMode.Mode:2
TEST.END

-- Test Case: Xcp_SetTransmissionMode.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_SetTransmissionMode
TEST.NEW
TEST.NAME:Xcp_SetTransmissionMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_GetXcpChannelFromNetworkChannel
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_GetXcpChannelFromNetworkChannel.return:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Subprogram: Xcp_StimEventStatus

-- Test Case: Xcp_StimEventStatus.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_StimEventStatus
TEST.NEW
TEST.NAME:Xcp_StimEventStatus.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_StimEventStatus.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_StimEventStatus
TEST.NEW
TEST.NAME:Xcp_StimEventStatus.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_StimEventStatus.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_StimEventStatus
TEST.NEW
TEST.NAME:Xcp_StimEventStatus.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_StimEventStatus.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_StimEventStatus
TEST.NEW
TEST.NAME:Xcp_StimEventStatus.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_StimEventStatus.EventChannel:1
TEST.VALUE:Xcp.Xcp_StimEventStatus.Action:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_StimEventStatus.EventChannel:1
TEST.EXPECTED:Xcp.Xcp_StimEventStatus.Action:2
TEST.END

-- Test Case: Xcp_StimEventStatus.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_StimEventStatus
TEST.NEW
TEST.NAME:Xcp_StimEventStatus.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x40
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x40
TEST.END

-- Test Case: Xcp_StimEventStatus.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_StimEventStatus
TEST.NEW
TEST.NAME:Xcp_StimEventStatus.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x40
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x40
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.END

-- Test Case: Xcp_StimEventStatus.007
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_StimEventStatus
TEST.NEW
TEST.NAME:Xcp_StimEventStatus.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x40
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqToEventChannelMap[0]:0
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x42
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x40
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqToEventChannelMap[0]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x42
TEST.END

-- Subprogram: Xcp_TlRxIndication

-- Test Case: Xcp_TlRxIndication.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_TlRxIndication.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_TlRxIndication.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_TlRxIndication.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_TlRxIndication.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_TlRxIndication.XcpChannel:2
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_TlRxIndication.XcpChannel:2
TEST.END

-- Test Case: Xcp_TlRxIndication.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.END

-- Test Case: Xcp_TlRxIndication.007
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr[0]:0xC0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.EXPECTED:Xcp.Xcp_TlRxIndication.CmdPtr[0]:0xC0
TEST.END

-- Test Case: Xcp_TlRxIndication.008
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x11
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr[0]:0xC0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x11
TEST.EXPECTED:Xcp.Xcp_TlRxIndication.CmdPtr[0]:0xC0
TEST.END

-- Test Case: Xcp_TlRxIndication.009
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResponsePending:1
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr[0]:0xC0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResponsePending:1
TEST.EXPECTED:Xcp.Xcp_TlRxIndication.CmdPtr[0]:0xC0
TEST.END

-- Test Case: Xcp_TlRxIndication.010
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.END

-- Test Case: Xcp_TlRxIndication.011
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:0xFF
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:0xFF
TEST.END

-- Test Case: Xcp_TlRxIndication.012
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_UtilMemCopy
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:0xFF
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.pStimBuffer[0]:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:0xFF
TEST.END

-- Test Case: Xcp_TlRxIndication.013
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlRxIndication
TEST.NEW
TEST.NAME:Xcp_TlRxIndication.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResponsePending:1
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_TlRxIndication.CmdPtr[0]:196
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ConnectionState:XCP_CONNECTION_STATE_TYPE_CONNECTED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResponsePending:1
TEST.EXPECTED:Xcp.Xcp_TlRxIndication.CmdPtr[0]:0xC4
TEST.END

-- Subprogram: Xcp_TlTxConfirmation

-- Test Case: Xcp_TlTxConfirmation.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlTxConfirmation
TEST.NEW
TEST.NAME:Xcp_TlTxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_TlTxConfirmation.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlTxConfirmation
TEST.NEW
TEST.NAME:Xcp_TlTxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_TlTxConfirmation.003
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlTxConfirmation
TEST.NEW
TEST.NAME:Xcp_TlTxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.END

-- Test Case: Xcp_TlTxConfirmation.004
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlTxConfirmation
TEST.NEW
TEST.NAME:Xcp_TlTxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.Xcp_TlTxConfirmation.XcpChannel:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.Xcp_TlTxConfirmation.XcpChannel:2
TEST.END

-- Test Case: Xcp_TlTxConfirmation.005
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlTxConfirmation
TEST.NEW
TEST.NAME:Xcp_TlTxConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SendStatus:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.ATTRIBUTES:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus.Xcp_ChannelCtrlStatus[0].SendStatus:EXPECTED_BASE=16
TEST.END

-- Test Case: Xcp_TlTxConfirmation.006
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlTxConfirmation
TEST.NEW
TEST.NAME:Xcp_TlTxConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:64
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:64
TEST.END

-- Test Case: Xcp_TlTxConfirmation.007
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_TlTxConfirmation
TEST.NEW
TEST.NAME:Xcp_TlTxConfirmation.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x400
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_InitState:XCP_INIT_STATE_INTITIALIZED
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ControlState:XCP_CONTROL_STATE_ENABLE
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].SessionStatus:0x0
TEST.END

-- Subprogram: Xcp_UtilMemCopy

-- Test Case: Xcp_UtilMemCopy.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_UtilMemCopy
TEST.NEW
TEST.NAME:Xcp_UtilMemCopy.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_UtilMemCopy.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_UtilMemCopy
TEST.NEW
TEST.NAME:Xcp_UtilMemCopy.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.Xcp_UtilMemCopy.DestPtr:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_UtilMemCopy.SrcPtr:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_UtilMemCopy.Length:1
TEST.EXPECTED:Xcp.Xcp_UtilMemCopy.Length:1
TEST.END

-- Subprogram: Xcp_UtilMemSet

-- Test Case: Xcp_UtilMemSet.001
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_UtilMemSet
TEST.NEW
TEST.NAME:Xcp_UtilMemSet.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_UtilMemSet.002
TEST.UNIT:Xcp
TEST.SUBPROGRAM:Xcp_UtilMemSet
TEST.NEW
TEST.NAME:Xcp_UtilMemSet.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13849
TEST.END_NOTES:
TEST.VALUE:Xcp.Xcp_UtilMemSet.DestPtr:<<malloc 1>>
TEST.VALUE:Xcp.Xcp_UtilMemSet.Length:1
TEST.EXPECTED:Xcp.Xcp_UtilMemSet.Length:1
TEST.END

-- Unit: Xcp_CalibCmd

-- Subprogram: Xcp_CalibCmdProcessorDownload

-- Test Case: Xcp_CalibCmdProcessorDownload.001
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownload
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownload.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownload.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_CalibCmdProcessorDownload.002
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownload
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownload.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownload.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownload.CmdPtr[1]:0
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownload.CmdPtr[1]:0
TEST.END

-- Test Case: Xcp_CalibCmdProcessorDownload.003
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownload
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownload.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownload.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_CalibCmdProcessorDownload.004
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownload
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownload.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp_CalibCmd.Xcp_WriteMta
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelConfig[0].DownloadSizeMax:2
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownload.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownload.CmdPtr[1]:1
TEST.VALUE:Xcp_CalibCmd.Xcp_WriteMta.return:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelConfig[0].DownloadSizeMax:2
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownload.CmdPtr[1]:1
TEST.END

-- Subprogram: Xcp_CalibCmdProcessorDownloadMax

-- Test Case: Xcp_CalibCmdProcessorDownloadMax.001
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownloadMax
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownloadMax.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_CalibCmdProcessorDownloadMax.002
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownloadMax
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownloadMax.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.END

-- Test Case: Xcp_CalibCmdProcessorDownloadMax.003
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownloadMax
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownloadMax.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp_CalibCmd.Xcp_WriteMta
TEST.VALUE:Xcp_CalibCmd.Xcp_WriteMta.return:1
TEST.END

-- Subprogram: Xcp_CalibCmdProcessorDownloadNext

-- Test Case: Xcp_CalibCmdProcessorDownloadNext.001
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownloadNext
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownloadNext.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownloadNext.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_CalibCmdProcessorDownloadNext.002
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownloadNext
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownloadNext.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownloadNext.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownloadNext.CmdPtr[1]:<<MAX>>
TEST.VALUE:Xcp_DaqCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:2
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownloadNext.CmdPtr[1]:<<MAX>>
TEST.EXPECTED:Xcp_DaqCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:2
TEST.END

-- Test Case: Xcp_CalibCmdProcessorDownloadNext.003
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownloadNext
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownloadNext.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownloadNext.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownloadNext.CmdPtr[1]:<<MAX>>
TEST.VALUE:Xcp_DaqCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].NextDataBlockSize:<<MAX>>
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownloadNext.CmdPtr[1]:<<MAX>>
TEST.END

-- Test Case: Xcp_CalibCmdProcessorDownloadNext.004
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorDownloadNext
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorDownloadNext.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp_CalibCmd.Xcp_WriteMta
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorDownloadNext.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_WriteMta.return:1
TEST.VALUE:Xcp_DaqCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:2
TEST.EXPECTED:Xcp_DaqCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:2
TEST.END

-- Subprogram: Xcp_CalibCmdProcessorModifyBits

-- Test Case: Xcp_CalibCmdProcessorModifyBits.001
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorModifyBits
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorModifyBits.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_CalibCmdProcessorModifyBits.002
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorModifyBits
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorModifyBits.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_CalibCmdProcessorModifyBits.003
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorModifyBits
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorModifyBits.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr[1]:32
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr[1]:32
TEST.END

-- Test Case: Xcp_CalibCmdProcessorModifyBits.004
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorModifyBits
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorModifyBits.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp_StdCmd.Xcp_ReadMta
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr[1]:1
TEST.VALUE:Xcp_StdCmd.Xcp_ReadMta.return:1
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_CalibCmdProcessorModifyBits.005
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorModifyBits
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorModifyBits.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp_StdCmd.Xcp_ReadMta
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr[1]:1
TEST.VALUE:Xcp_StdCmd.Xcp_ReadMta.return:2
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_CalibCmdProcessorModifyBits.006
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorModifyBits
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorModifyBits.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp_StdCmd.Xcp_ReadMta
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr[1]:1
TEST.VALUE:Xcp_StdCmd.Xcp_ReadMta.return:0
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorModifyBits.CmdPtr[1]:1
TEST.END

-- Subprogram: Xcp_CalibCmdProcessorShortDownload

-- Test Case: Xcp_CalibCmdProcessorShortDownload.001
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorShortDownload
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorShortDownload.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorShortDownload.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_CalibCmdProcessorShortDownload.002
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorShortDownload
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorShortDownload.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorShortDownload.CmdPtr:<<malloc 1>>
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorShortDownload.CmdPtr[0]:1
TEST.VALUE:Xcp_DaqCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:8
TEST.EXPECTED:Xcp_CalibCmd.Xcp_CalibCmdProcessorShortDownload.CmdPtr[0]:1
TEST.EXPECTED:Xcp_DaqCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:8
TEST.END

-- Test Case: Xcp_CalibCmdProcessorShortDownload.003
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorShortDownload
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorShortDownload.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorShortDownload.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_CalibCmdProcessorShortDownload.004
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_CalibCmdProcessorShortDownload
TEST.NEW
TEST.NAME:Xcp_CalibCmdProcessorShortDownload.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.STUB:Xcp_CalibCmd.Xcp_WriteMta
TEST.VALUE:Xcp_CalibCmd.Xcp_CalibCmdProcessorShortDownload.CmdPtr:<<malloc 1>>
TEST.VALUE:Xcp_CalibCmd.Xcp_WriteMta.return:1
TEST.END

-- Subprogram: Xcp_WriteMta

-- Test Case: Xcp_WriteMta.001
TEST.UNIT:Xcp_CalibCmd
TEST.SUBPROGRAM:Xcp_WriteMta
TEST.NEW
TEST.NAME:Xcp_WriteMta.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-13860
TEST.END_NOTES:
TEST.END

-- Unit: Xcp_DaqCmd

-- Subprogram: Xcp_DaqAllocStimMemory

-- Test Case: Xcp_DaqAllocStimMemory.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqAllocStimMemory
TEST.NEW
TEST.NAME:Xcp_DaqAllocStimMemory.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_DaqAllocStimMemory.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqAllocStimMemory
TEST.NEW
TEST.NAME:Xcp_DaqAllocStimMemory.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.END

-- Test Case: Xcp_DaqAllocStimMemory.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqAllocStimMemory
TEST.NEW
TEST.NAME:Xcp_DaqAllocStimMemory.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.END

-- Test Case: Xcp_DaqAllocStimMemory.004
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqAllocStimMemory
TEST.NEW
TEST.NAME:Xcp_DaqAllocStimMemory.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x2
TEST.END

-- Test Case: Xcp_DaqAllocStimMemory.005
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqAllocStimMemory
TEST.NEW
TEST.NAME:Xcp_DaqAllocStimMemory.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x2
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorAllocDaq

-- Test Case: Xcp_DaqCmdProcessorAllocDaq.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocDaq.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocDaq.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocDaq.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocDaq.CmdPtr:<<malloc 4>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocDaq.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocDaq.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocDaq.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocDaq.CmdPtr[2]:10
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocDaq.CmdPtr[3]:0
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocDaq.CmdPtr[2]:10
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocDaq.CmdPtr[3]:0
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorAllocOdt

-- Test Case: Xcp_DaqCmdProcessorAllocOdt.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdt
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdt.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdt.CmdPtr:<<malloc 5>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocOdt.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdt
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdt.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdt.CmdPtr:<<malloc 5>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocOdt.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdt
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdt.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdt.CmdPtr:<<malloc 5>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdt.CmdPtr[2]:9
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdt.CmdPtr[3]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdt.CmdPtr[2]:9
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdt.CmdPtr[3]:0
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocOdt.004
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdt
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdt.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:3
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdt.CmdPtr:<<malloc 5>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:0
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorAllocOdtEntry

-- Test Case: Xcp_DaqCmdProcessorAllocOdtEntry.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdtEntry
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdtEntry.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr:<<malloc 6>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocOdtEntry.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdtEntry
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdtEntry.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr:<<malloc 6>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocOdtEntry.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdtEntry
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdtEntry.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr:<<malloc 6>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr[2]:9
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr[3]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr[2]:9
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr[3]:0
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocOdtEntry.004
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdtEntry
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdtEntry.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr:<<malloc 6>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocOdtEntry.005
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdtEntry
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdtEntry.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:3
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr:<<malloc 6>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0]:3
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorAllocOdtEntry.006
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorAllocOdtEntry
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorAllocOdtEntry.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:3
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorAllocOdtEntry.CmdPtr:<<malloc 6>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtsOfDaq[0]:0
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorFreeDaq

-- Test Case: Xcp_DaqCmdProcessorFreeDaq.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorFreeDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorFreeDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_DaqCmdProcessorFreeDaq.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorFreeDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorFreeDaq.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorGetDaqClock

-- Test Case: Xcp_DaqCmdProcessorGetDaqClock.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorGetDaqClock
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorGetDaqClock.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorGetDaqEventInfo

-- Test Case: Xcp_DaqCmdProcessorGetDaqEventInfo.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorGetDaqEventInfo
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorGetDaqEventInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorGetDaqEventInfo.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorGetDaqEventInfo.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorGetDaqEventInfo
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorGetDaqEventInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorGetDaqEventInfo.CmdPtr:<<malloc 1>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorGetDaqEventInfo.CmdPtr[0]:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorGetDaqEventInfo.CmdPtr[0]:1
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorGetDaqListMode

-- Test Case: Xcp_DaqCmdProcessorGetDaqListMode.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorGetDaqListMode
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorGetDaqListMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorGetDaqListMode.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorGetDaqListMode.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorGetDaqListMode
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorGetDaqListMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorGetDaqListMode.CmdPtr:<<malloc 4>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorGetDaqProcessorInfo

-- Test Case: Xcp_DaqCmdProcessorGetDaqProcessorInfo.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorGetDaqProcessorInfo
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorGetDaqProcessorInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorGetDaqResolutionInfo

-- Test Case: Xcp_DaqCmdProcessorGetDaqResolutionInfo.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorGetDaqResolutionInfo
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorGetDaqResolutionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorSetDaqListMode

-- Test Case: Xcp_DaqCmdProcessorSetDaqListMode.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorSetDaqListMode
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorSetDaqListMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr:<<malloc 8>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorSetDaqListMode.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorSetDaqListMode
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorSetDaqListMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr:<<malloc 8>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[2]:9
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[3]:0
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[4]:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[5]:0
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[7]:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[2]:9
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[3]:0
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[4]:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[5]:0
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[7]:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorSetDaqListMode.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorSetDaqListMode
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorSetDaqListMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr:<<malloc 8>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[6]:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr[6]:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorSetDaqListMode.004
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorSetDaqListMode
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorSetDaqListMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.STUB:Xcp_DaqCmd.Xcp_DaqAllocStimMemory
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqListMode.CmdPtr:<<malloc 8>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqAllocStimMemory.return:1
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorSetDaqPtr

-- Test Case: Xcp_DaqCmdProcessorSetDaqPtr.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorSetDaqPtr
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorSetDaqPtr.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqPtr.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorSetDaqPtr.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorSetDaqPtr
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorSetDaqPtr.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqPtr.CmdPtr:<<malloc 5>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorSetDaqPtr.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorSetDaqPtr
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorSetDaqPtr.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorSetDaqPtr.CmdPtr:<<malloc 5>>
TEST.VALUE:Xcp_PgmCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.FirstOdtIdxOfDaq[0..2]:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorStartStopDaqList

-- Test Case: Xcp_DaqCmdProcessorStartStopDaqList.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopDaqList
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopDaqList.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopDaqList.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopDaqList
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopDaqList.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopDaqList.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopDaqList
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopDaqList.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr[1]:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr[1]:2
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopDaqList.004
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopDaqList
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopDaqList.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:<<MAX>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr[1]:0
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:<<MAX>>
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr[1]:0
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopDaqList.005
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopDaqList
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopDaqList.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr[1]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopDaqList.CmdPtr[1]:1
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorStartStopSynch

-- Test Case: Xcp_DaqCmdProcessorStartStopSynch.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopSynch
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopSynch.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopSynch.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopSynch
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopSynch.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr:<<malloc 2>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopSynch.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopSynch
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopSynch.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopSynch.004
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopSynch
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopSynch.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr[1]:3
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr[1]:3
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopSynch.005
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopSynch
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopSynch.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr[1]:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorStartStopSynch.006
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorStartStopSynch
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorStartStopSynch.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr[1]:2
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorStartStopSynch.CmdPtr[1]:2
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorWriteDaq

-- Test Case: Xcp_DaqCmdProcessorWriteDaq.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr:<<malloc 6>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaq.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaq.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr:<<malloc 6>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaq.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaq.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr:<<malloc 6>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaq.004
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaq.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr:<<malloc 6>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr[1]:0xFF
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr[2]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr[1]:0xFF
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr[2]:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaq.005
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaq.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram 
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.ActiveOdtEntryIdx:3
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr:<<malloc 6>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr[1]:0xFF
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr[2]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.ActiveOdtEntryIdx:3
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr[1]:0xFF
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaq.CmdPtr[2]:1
TEST.END

-- Subprogram: Xcp_DaqCmdProcessorWriteDaqMultiple

-- Test Case: Xcp_DaqCmdProcessorWriteDaqMultiple.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaqMultiple
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaqMultiple.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaqMultiple.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaqMultiple
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaqMultiple.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaqMultiple.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaqMultiple
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaqMultiple.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr:<<malloc 2>>
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaqMultiple.004
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaqMultiple
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaqMultiple.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[1]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaqMultiple.005
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaqMultiple
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaqMultiple.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:uut_prototype_stubs.Xcp_ApplGetAddrPointer.return:<<MAX>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[1]:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[2]:0xFF
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[3]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[1]:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[2]:0xFF
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[3]:1
TEST.END

-- Test Case: Xcp_DaqCmdProcessorWriteDaqMultiple.006
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdProcessorWriteDaqMultiple
TEST.NEW
TEST.NAME:Xcp_DaqCmdProcessorWriteDaqMultiple.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.ActiveOdtEntryIdx:2
TEST.VALUE:uut_prototype_stubs.Xcp_ApplGetAddrPointer.return:<<MAX>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[1]:1
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[2]:0xFF
TEST.VALUE:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[3]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdts:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfOdtEntries:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.ActiveOdtEntryIdx:2
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[1]:1
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[2]:0xFF
TEST.EXPECTED:Xcp_DaqCmd.Xcp_DaqCmdProcessorWriteDaqMultiple.CmdPtr[3]:1
TEST.END

-- Subprogram: Xcp_DaqCmdQueueInit

-- Test Case: Xcp_DaqCmdQueueInit.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdQueueInit
TEST.NEW
TEST.NAME:Xcp_DaqCmdQueueInit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_DaqCmdStartAllSelectedDaq

-- Test Case: Xcp_DaqCmdStartAllSelectedDaq.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStartAllSelectedDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStartAllSelectedDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_DaqCmdStartAllSelectedDaq.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStartAllSelectedDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStartAllSelectedDaq.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.END

-- Test Case: Xcp_DaqCmdStartAllSelectedDaq.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStartAllSelectedDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStartAllSelectedDaq.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:64
TEST.END

-- Subprogram: Xcp_DaqCmdStartDaq

-- Test Case: Xcp_DaqCmdStartDaq.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStartDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStartDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_DaqCmdStopAllDaq

-- Test Case: Xcp_DaqCmdStopAllDaq.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStopAllDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStopAllDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_DaqCmdStopAllSelectedDaq

-- Test Case: Xcp_DaqCmdStopAllSelectedDaq.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStopAllSelectedDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStopAllSelectedDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_DaqCmdStopAllSelectedDaq.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStopAllSelectedDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStopAllSelectedDaq.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.END

-- Test Case: Xcp_DaqCmdStopAllSelectedDaq.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStopAllSelectedDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStopAllSelectedDaq.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[0]:0x0
TEST.END

-- Subprogram: Xcp_DaqCmdStopDaq

-- Test Case: Xcp_DaqCmdStopDaq.001
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStopDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStopDaq.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_DaqCmdStopDaq.002
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStopDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStopDaq.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:1
TEST.END

-- Test Case: Xcp_DaqCmdStopDaq.003
TEST.UNIT:Xcp_DaqCmd
TEST.SUBPROGRAM:Xcp_DaqCmdStopDaq
TEST.NEW
TEST.NAME:Xcp_DaqCmdStopDaq.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14085
TEST.END_NOTES:
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:2
TEST.VALUE:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[1]:0x40
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.NumOfDaqLists:2
TEST.EXPECTED:Xcp.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].Xcp_DaqListStatus.DaqListMode[1]:0x40
TEST.END

-- Unit: Xcp_PagCmd

-- Subprogram: Xcp_PagCmdProcessorCopyCalPage

-- Test Case: Xcp_PagCmdProcessorCopyCalPage.001
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorCopyCalPage
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorCopyCalPage.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorCopyCalPage.CmdPtr:<<malloc 5>>
TEST.END

-- Test Case: Xcp_PagCmdProcessorCopyCalPage.002
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorCopyCalPage
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorCopyCalPage.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorCopyCalPage.CmdPtr:<<malloc 5>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorCopyCalPage.CmdPtr[1]:10
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorCopyCalPage.CmdPtr[1]:10
TEST.END

-- Test Case: Xcp_PagCmdProcessorCopyCalPage.003
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorCopyCalPage
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorCopyCalPage.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplCopyCalPage.return:1
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorCopyCalPage.CmdPtr:<<malloc 5>>
TEST.END

-- Subprogram: Xcp_PagCmdProcessorGetCalPage

-- Test Case: Xcp_PagCmdProcessorGetCalPage.001
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetCalPage
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetCalPage.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetCalPage.CmdPtr:<<malloc 3>>
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetCalPage.002
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetCalPage
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetCalPage.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetCalPage.CmdPtr:<<malloc 3>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetCalPage.CmdPtr[1]:1
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetCalPage.CmdPtr[1]:1
TEST.END

-- Subprogram: Xcp_PagCmdProcessorGetPageInfo

-- Test Case: Xcp_PagCmdProcessorGetPageInfo.001
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetPageInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetPageInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetPageInfo.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetPageInfo.002
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetPageInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetPageInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetPageInfo.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetPageInfo.CmdPtr[2]:10
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetPageInfo.CmdPtr[3]:10
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetPageInfo.CmdPtr[2]:10
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetPageInfo.CmdPtr[3]:10
TEST.END

-- Subprogram: Xcp_PagCmdProcessorGetPageProcessorInfo

-- Test Case: Xcp_PagCmdProcessorGetPageProcessorInfo.001
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetPageProcessorInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetPageProcessorInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_PagCmdProcessorGetSegmentInfo

-- Test Case: Xcp_PagCmdProcessorGetSegmentInfo.001
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetSegmentInfo.002
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:3
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[2]:10
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:3
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[2]:10
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetSegmentInfo.003
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentInfo.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[3]:2
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[3]:2
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetSegmentInfo.004
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentInfo.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:1
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetSegmentInfo.005
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentInfo.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[3]:1
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[3]:1
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetSegmentInfo.006
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentInfo.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:2
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:2
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetSegmentInfo.007
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentInfo.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:2
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[3]:1
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:2
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[3]:1
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetSegmentInfo.008
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentInfo
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentInfo.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr:<<malloc 4>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:2
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[3]:2
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[1]:2
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentInfo.CmdPtr[3]:2
TEST.END

-- Subprogram: Xcp_PagCmdProcessorGetSegmentMode

-- Test Case: Xcp_PagCmdProcessorGetSegmentMode.001
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentMode
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentMode.CmdPtr:<<malloc 3>>
TEST.END

-- Test Case: Xcp_PagCmdProcessorGetSegmentMode.002
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorGetSegmentMode
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorGetSegmentMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentMode.CmdPtr:<<malloc 3>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentMode.CmdPtr[2]:10
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorGetSegmentMode.CmdPtr[2]:10
TEST.END

-- Subprogram: Xcp_PagCmdProcessorSetCalPage

-- Test Case: Xcp_PagCmdProcessorSetCalPage.001
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorSetCalPage
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorSetCalPage.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorSetCalPage.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_PagCmdProcessorSetCalPage.002
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorSetCalPage
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorSetCalPage.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplSetCalPage.return:1
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorSetCalPage.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_PagCmdProcessorSetCalPage.003
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorSetCalPage
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorSetCalPage.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplSetCalPage.return:2
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorSetCalPage.CmdPtr:<<malloc 4>>
TEST.END

-- Subprogram: Xcp_PagCmdProcessorSetSegmentMode

-- Test Case: Xcp_PagCmdProcessorSetSegmentMode.001
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorSetSegmentMode
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorSetSegmentMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorSetSegmentMode.CmdPtr:<<malloc 3>>
TEST.END

-- Test Case: Xcp_PagCmdProcessorSetSegmentMode.002
TEST.UNIT:Xcp_PagCmd
TEST.SUBPROGRAM:Xcp_PagCmdProcessorSetSegmentMode
TEST.NEW
TEST.NAME:Xcp_PagCmdProcessorSetSegmentMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14086
TEST.END_NOTES:
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorSetSegmentMode.CmdPtr:<<malloc 3>>
TEST.VALUE:Xcp_PagCmd.Xcp_PagCmdProcessorSetSegmentMode.CmdPtr[1]:10
TEST.EXPECTED:Xcp_PagCmd.Xcp_PagCmdProcessorSetSegmentMode.CmdPtr[1]:10
TEST.END

-- Unit: Xcp_PgmCmd

-- Subprogram: Xcp_PgmCmdProcessorGetPgmProcessorInfo

-- Test Case: Xcp_PgmCmdProcessorGetPgmProcessorInfo.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorGetPgmProcessorInfo
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorGetPgmProcessorInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_PgmCmdProcessorGetSectorInfo

-- Test Case: Xcp_PgmCmdProcessorGetSectorInfo.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorGetSectorInfo
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorGetSectorInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr:<<malloc 3>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorGetSectorInfo.002
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorGetSectorInfo
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorGetSectorInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr:<<malloc 3>>
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr[2]:1
TEST.EXPECTED:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr[2]:1
TEST.END

-- Test Case: Xcp_PgmCmdProcessorGetSectorInfo.003
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorGetSectorInfo
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorGetSectorInfo.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr:<<malloc 3>>
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr[1]:2
TEST.EXPECTED:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr[1]:2
TEST.END

-- Test Case: Xcp_PgmCmdProcessorGetSectorInfo.004
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorGetSectorInfo
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorGetSectorInfo.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr:<<malloc 3>>
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr[1]:1
TEST.EXPECTED:Xcp_PgmCmd.Xcp_PgmCmdProcessorGetSectorInfo.CmdPtr[1]:1
TEST.END

-- Subprogram: Xcp_PgmCmdProcessorProgram

-- Test Case: Xcp_PgmCmdProcessorProgram.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgram
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgram.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgram.CmdPtr:<<malloc 3>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgram.002
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgram
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgram.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgram.CmdPtr:<<malloc 3>>
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgram.CmdPtr[1]:<<MAX>>
TEST.EXPECTED:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgram.CmdPtr[1]:<<MAX>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgram.003
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgram
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgram.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgram.CmdPtr:<<malloc 3>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgram.004
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgram
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgram.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplProgram.return:1
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgram.CmdPtr:<<malloc 3>>
TEST.END

-- Subprogram: Xcp_PgmCmdProcessorProgramClear

-- Test Case: Xcp_PgmCmdProcessorProgramClear.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramClear
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramClear.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramClear.CmdPtr:<<malloc 8>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramClear.002
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramClear
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramClear.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramClear.CmdPtr:<<malloc 8>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramClear.003
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramClear
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramClear.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramClear.CmdPtr:<<malloc 8>>
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramClear.CmdPtr[1]:1
TEST.EXPECTED:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramClear.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramClear.004
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramClear
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramClear.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplProgramClear.return:1
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramClear.CmdPtr:<<malloc 8>>
TEST.END

-- Subprogram: Xcp_PgmCmdProcessorProgramMax

-- Test Case: Xcp_PgmCmdProcessorProgramMax.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramMax
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramMax.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramMax.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramMax.002
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramMax
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramMax.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.STUB:Xcp.Xcp_ResourceProtectionCheck
TEST.VALUE:Xcp.Xcp_ResourceProtectionCheck.return:1
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramMax.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramMax.003
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramMax
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramMax.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplProgram.return:1
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramMax.CmdPtr:<<malloc 2>>
TEST.END

-- Subprogram: Xcp_PgmCmdProcessorProgramNext

-- Test Case: Xcp_PgmCmdProcessorProgramNext.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramNext
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramNext.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramNext.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramNext.002
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramNext
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramNext.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramNext.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramNext.CmdPtr[1]:1
TEST.EXPECTED:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramNext.CmdPtr[1]:1
TEST.END

-- Subprogram: Xcp_PgmCmdProcessorProgramPrepare

-- Test Case: Xcp_PgmCmdProcessorProgramPrepare.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramPrepare
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramPrepare.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramPrepare.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramPrepare.002
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramPrepare
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramPrepare.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplProgramPrepare.return:1
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramPrepare.CmdPtr:<<malloc 4>>
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramPrepare.003
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramPrepare
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramPrepare.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplProgramPrepare.return:2
TEST.VALUE:Xcp_PgmCmd.Xcp_PgmCmdProcessorProgramPrepare.CmdPtr:<<malloc 4>>
TEST.END

-- Subprogram: Xcp_PgmCmdProcessorProgramReset

-- Test Case: Xcp_PgmCmdProcessorProgramReset.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramReset
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramReset.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_PgmCmdProcessorProgramStart

-- Test Case: Xcp_PgmCmdProcessorProgramStart.001
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramStart
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramStart.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramStart.002
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramStart
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramStart.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplProgramStart.return:1
TEST.END

-- Test Case: Xcp_PgmCmdProcessorProgramStart.003
TEST.UNIT:Xcp_PgmCmd
TEST.SUBPROGRAM:Xcp_PgmCmdProcessorProgramStart
TEST.NEW
TEST.NAME:Xcp_PgmCmdProcessorProgramStart.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14087
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplProgramStart.return:2
TEST.END

-- Unit: Xcp_StdCmd

-- Subprogram: Xcp_ReadMta

-- Test Case: Xcp_ReadMta.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_ReadMta
TEST.NEW
TEST.NAME:Xcp_ReadMta.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_SetMta

-- Test Case: Xcp_SetMta.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_SetMta
TEST.NEW
TEST.NAME:Xcp_SetMta.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_StdCmdProcessorBuildChecksum

-- Test Case: Xcp_StdCmdProcessorBuildChecksum.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorBuildChecksum
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorBuildChecksum.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorBuildChecksum.CmdPtr:<<malloc 8>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorBuildChecksum.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorBuildChecksum
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorBuildChecksum.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorBuildChecksum.CmdPtr:<<malloc 8>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorBuildChecksum.CmdPtr[4]:2
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorBuildChecksum.CmdPtr[4]:2
TEST.END

-- Test Case: Xcp_StdCmdProcessorBuildChecksum.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorBuildChecksum
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorBuildChecksum.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplCalculateChecksum.return:1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorBuildChecksum.CmdPtr:<<malloc 8>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorBuildChecksum.004
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorBuildChecksum
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorBuildChecksum.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplCalculateChecksum.return:2
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorBuildChecksum.CmdPtr:<<malloc 8>>
TEST.END

-- Subprogram: Xcp_StdCmdProcessorConnect

-- Test Case: Xcp_StdCmdProcessorConnect.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorConnect
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorConnect.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_StdCmdProcessorDisconnect

-- Test Case: Xcp_StdCmdProcessorDisconnect.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorDisconnect
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorDisconnect.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_StdCmdProcessorGetCommModeInfo

-- Test Case: Xcp_StdCmdProcessorGetCommModeInfo.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetCommModeInfo
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetCommModeInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_StdCmdProcessorGetId

-- Test Case: Xcp_StdCmdProcessorGetId.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetId
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetId.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetId.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorGetId.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetId
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetId.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetId.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetId.CmdPtr[1]:1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorGetId.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_StdCmdProcessorGetId.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetId
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetId.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplGetIdData.return:1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetId.CmdPtr:<<malloc 2>>
TEST.END

-- Subprogram: Xcp_StdCmdProcessorGetSeed

-- Test Case: Xcp_StdCmdProcessorGetSeed.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetSeed
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetSeed.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorGetSeed.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetSeed
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetSeed.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[0]:1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[0]:1
TEST.END

-- Test Case: Xcp_StdCmdProcessorGetSeed.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetSeed
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetSeed.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[1]:0x2
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[1]:0x2
TEST.END

-- Test Case: Xcp_StdCmdProcessorGetSeed.004
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetSeed
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetSeed.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResourceProtectionStatus:0x1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[1]:0x1
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResourceProtectionStatus:0x1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[1]:0x1
TEST.END

-- Test Case: Xcp_StdCmdProcessorGetSeed.005
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetSeed
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetSeed.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplGetSeed.Resource:0
TEST.VALUE:uut_prototype_stubs.Xcp_ApplGetSeed.SeedPtr[0]:0
TEST.VALUE:uut_prototype_stubs.Xcp_ApplGetSeed.return:<<MAX>>
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:2
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResourceProtectionStatus:0x1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[0]:0
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[1]:0x1
TEST.EXPECTED:uut_prototype_stubs.Xcp_ApplGetSeed.Resource:0
TEST.EXPECTED:uut_prototype_stubs.Xcp_ApplGetSeed.SeedPtr[0]:0
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:2
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ResourceProtectionStatus:0x1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[0]:0
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorGetSeed.CmdPtr[1]:0x1
TEST.END

-- Subprogram: Xcp_StdCmdProcessorGetStatus

-- Test Case: Xcp_StdCmdProcessorGetStatus.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorGetStatus
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorGetStatus.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_StdCmdProcessorSetMta

-- Test Case: Xcp_StdCmdProcessorSetMta.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorSetMta
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorSetMta.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetMta.CmdPtr:<<malloc 4>>
TEST.END

-- Subprogram: Xcp_StdCmdProcessorSetRequest

-- Test Case: Xcp_StdCmdProcessorSetRequest.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorSetRequest
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorSetRequest.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorSetRequest.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorSetRequest
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorSetRequest.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr[1]:0x1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr[1]:0x1
TEST.END

-- Test Case: Xcp_StdCmdProcessorSetRequest.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorSetRequest
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorSetRequest.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr[1]:0x2
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr[1]:0x2
TEST.END

-- Test Case: Xcp_StdCmdProcessorSetRequest.004
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorSetRequest
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorSetRequest.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr[1]:0x4
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr[1]:0x4
TEST.END

-- Test Case: Xcp_StdCmdProcessorSetRequest.005
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorSetRequest
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorSetRequest.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr[1]:0x8
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorSetRequest.CmdPtr[1]:0x8
TEST.END

-- Subprogram: Xcp_StdCmdProcessorShortUpload

-- Test Case: Xcp_StdCmdProcessorShortUpload.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorShortUpload
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorShortUpload.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorShortUpload.CmdPtr:<<malloc 5>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorShortUpload.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorShortUpload
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorShortUpload.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelConfig[0].UploadSizeMax:1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorShortUpload.CmdPtr:<<malloc 5>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorShortUpload.CmdPtr[1]:1
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelConfig[0].UploadSizeMax:1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorShortUpload.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_StdCmdProcessorShortUpload.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorShortUpload
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorShortUpload.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.STUB:Xcp_StdCmd.Xcp_ReadMta
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelConfig[0].UploadSizeMax:1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorShortUpload.CmdPtr:<<malloc 5>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorShortUpload.CmdPtr[1]:1
TEST.VALUE:Xcp_StdCmd.Xcp_ReadMta.return:1
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelConfig[0].UploadSizeMax:1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorShortUpload.CmdPtr[1]:1
TEST.END

-- Subprogram: Xcp_StdCmdProcessorSynch

-- Test Case: Xcp_StdCmdProcessorSynch.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorSynch
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorSynch.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.END

-- Subprogram: Xcp_StdCmdProcessorTlCmd

-- Test Case: Xcp_StdCmdProcessorTlCmd.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorTlCmd
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorTlCmd.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorTlCmd.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorTlCmd.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorTlCmd
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorTlCmd.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ActiveTl:2
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorTlCmd.CmdPtr:<<malloc 1>>
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].ActiveTl:2
TEST.END

-- Test Case: Xcp_StdCmdProcessorTlCmd.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorTlCmd
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorTlCmd.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_TlConfig[0].TlServiceFunctPtr:Xcp_ApplGetSeed
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorTlCmd.CmdPtr:<<malloc 1>>
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_TlConfig[0].TlServiceFunctPtr:Xcp_ApplGetSeed
TEST.END

-- Test Case: Xcp_StdCmdProcessorTlCmd.004
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorTlCmd
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorTlCmd.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_TlConfig[0].TlServiceFunctPtr:pTlServiceFunct_test
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorTlCmd.CmdPtr:<<malloc 1>>
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_TlConfig[0].TlServiceFunctPtr:pTlServiceFunct_test
TEST.END

-- Subprogram: Xcp_StdCmdProcessorUnlock

-- Test Case: Xcp_StdCmdProcessorUnlock.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUnlock
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUnlock.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUnlock.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorUnlock.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUnlock
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUnlock.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:2
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUnlock.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUnlock.CmdPtr[1]:1
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelCtrlStatus[0].MaxCto:2
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorUnlock.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_StdCmdProcessorUnlock.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUnlock
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUnlock.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplUnlock.return:1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUnlock.CmdPtr:<<malloc 2>>
TEST.END

-- Subprogram: Xcp_StdCmdProcessorUpload

-- Test Case: Xcp_StdCmdProcessorUpload.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUpload
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUpload.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr:<<malloc 2>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorUpload.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUpload
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUpload.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr[1]:1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_StdCmdProcessorUpload.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUpload
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUpload.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelConfig[0].UploadSizeMax:1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr[1]:1
TEST.EXPECTED:Xcp_StdCmd.<<GLOBAL>>.Xcp_ChannelConfig[0].UploadSizeMax:1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_StdCmdProcessorUpload.004
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUpload
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUpload.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.STUB:Xcp_StdCmd.Xcp_ReadMta
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr[1]:1
TEST.VALUE:Xcp_StdCmd.Xcp_ReadMta.return:2
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr[1]:1
TEST.END

-- Test Case: Xcp_StdCmdProcessorUpload.005
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUpload
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUpload.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.STUB:Xcp_StdCmd.Xcp_ReadMta
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr:<<malloc 2>>
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr[1]:1
TEST.VALUE:Xcp_StdCmd.Xcp_ReadMta.return:1
TEST.EXPECTED:Xcp_StdCmd.Xcp_StdCmdProcessorUpload.CmdPtr[1]:1
TEST.END

-- Subprogram: Xcp_StdCmdProcessorUserCmd

-- Test Case: Xcp_StdCmdProcessorUserCmd.001
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUserCmd
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUserCmd.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUserCmd.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorUserCmd.002
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUserCmd
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUserCmd.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplUserCmdProcessor.return:1
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUserCmd.CmdPtr:<<malloc 1>>
TEST.END

-- Test Case: Xcp_StdCmdProcessorUserCmd.003
TEST.UNIT:Xcp_StdCmd
TEST.SUBPROGRAM:Xcp_StdCmdProcessorUserCmd
TEST.NEW
TEST.NAME:Xcp_StdCmdProcessorUserCmd.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::Xcp::Xcp_Detailed_Design::Xcp_Class_Diagram
Requirement_DICVA-14088
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Xcp_ApplUserCmdProcessor.return:2
TEST.VALUE:Xcp_StdCmd.Xcp_StdCmdProcessorUserCmd.CmdPtr:<<malloc 1>>
TEST.END
