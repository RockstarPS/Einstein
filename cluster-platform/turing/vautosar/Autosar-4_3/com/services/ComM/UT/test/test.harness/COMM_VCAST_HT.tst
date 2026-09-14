-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : COMM_VCAST_HT
-- Unit(s) Under Test: ComM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: ComM_BusSMSateChangeNotificationToUser

-- Test Case: ComM_BusSMSateChangeNotificationToUser.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSMSateChangeNotificationToUser
TEST.NEW
TEST.NAME:ComM_BusSMSateChangeNotificationToUser.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.END

-- Test Case: ComM_BusSMSateChangeNotificationToUser.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSMSateChangeNotificationToUser
TEST.NEW
TEST.NAME:ComM_BusSMSateChangeNotificationToUser.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_BusSMSateChangeNotificationToUser.Channel:3
TEST.EXPECTED:ComM.ComM_BusSMSateChangeNotificationToUser.Channel:3
TEST.END

-- Test Case: ComM_BusSMSateChangeNotificationToUser.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSMSateChangeNotificationToUser
TEST.NEW
TEST.NAME:ComM_BusSMSateChangeNotificationToUser.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.END

-- Test Case: ComM_BusSMSateChangeNotificationToUser.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSMSateChangeNotificationToUser
TEST.NEW
TEST.NAME:ComM_BusSMSateChangeNotificationToUser.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.END

-- Test Case: ComM_BusSMSateChangeNotificationToUser.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSMSateChangeNotificationToUser
TEST.NEW
TEST.NAME:ComM_BusSMSateChangeNotificationToUser.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.END

-- Test Case: ComM_BusSMSateChangeNotificationToUser.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSMSateChangeNotificationToUser
TEST.NEW
TEST.NAME:ComM_BusSMSateChangeNotificationToUser.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.END

-- Test Case: ComM_BusSMSateChangeNotificationToUser.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSMSateChangeNotificationToUser
TEST.NEW
TEST.NAME:ComM_BusSMSateChangeNotificationToUser.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:3
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:3
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.END

-- Test Case: ComM_BusSMSateChangeNotificationToUser.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSMSateChangeNotificationToUser
TEST.NEW
TEST.NAME:ComM_BusSMSateChangeNotificationToUser.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[1]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[2]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:4
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[1].ChannelsToUserMap[0]:4
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserConfig[2].ChannelsToUserMap[0]:4
TEST.VALUE:ComM.ComM_BusSMSateChangeNotificationToUser.Channel:2
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[1]:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[2]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:4
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_GetHighestRequestMode
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[1].ChannelsToUserMap[0]:4
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserConfig[2].ChannelsToUserMap[0]:4
TEST.EXPECTED:ComM.ComM_BusSMSateChangeNotificationToUser.Channel:2
TEST.END

-- Subprogram: ComM_BusSM_ModeIndication

-- Test Case: ComM_BusSM_ModeIndication.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_BUSSM_MODEINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_BUSSM_MODEINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 9>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<null>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_BUSSM_MODEINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_PARAM_POINTER
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:0xFF
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_BUSSM_MODEINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_FULL_COMMUNICATION
TEST.ATTRIBUTES:ComM.ComM_BusSM_ModeIndication.ComMode[0]:INPUT_BASE=16
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:COMM_SILENT_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_SILENT_COMMUNICATION
TEST.ATTRIBUTES:ComM.ComM_BusSM_ModeIndication.ComMode[0]:INPUT_BASE=16
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_SILENT_COMMUNICATION
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:COMM_NO_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_NO_COMMUNICATION
TEST.ATTRIBUTES:ComM.ComM_BusSM_ModeIndication.ComMode[0]:INPUT_BASE=16
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:0x0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_NO_COMMUNICATION
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_SILENT_COMMUNICATION
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:COMM_NO_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_NO_COMMUNICATION
TEST.ATTRIBUTES:ComM.ComM_BusSM_ModeIndication.ComMode[0]:INPUT_BASE=16
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.010
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_SILENT_COMMUNICATION
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:COMM_NO_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_NO_COMMUNICATION
TEST.ATTRIBUTES:ComM.ComM_BusSM_ModeIndication.ComMode[0]:INPUT_BASE=16
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.011
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[1]:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[2]:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:COMM_NO_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[1]:2
TEST.EXPECTED:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.EXPECTED:ComM.ComM_BusSM_ModeIndication.ComMode[0]:0
TEST.ATTRIBUTES:ComM.ComM_BusSM_ModeIndication.ComMode[0]:INPUT_BASE=16
TEST.END

-- Test Case: ComM_BusSM_ModeIndication.012
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_BusSM_ModeIndication
TEST.NEW
TEST.NAME:ComM_BusSM_ModeIndication.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[1]:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[2]:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_BusSM_ModeIndication.ComMode[0]:COMM_NO_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSmMode[1]:2
TEST.EXPECTED:ComM.ComM_BusSM_ModeIndication.Channel:0
TEST.EXPECTED:ComM.ComM_BusSM_ModeIndication.ComMode[0]:0
TEST.ATTRIBUTES:ComM.ComM_BusSM_ModeIndication.ComMode[0]:INPUT_BASE=16
TEST.END

-- Subprogram: ComM_CommunicationAllowed

-- Test Case: ComM_CommunicationAllowed.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_CommunicationAllowed
TEST.NEW
TEST.NAME:ComM_CommunicationAllowed.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_COMMUNICATIONALLOWED
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_CommunicationAllowed.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_CommunicationAllowed
TEST.NEW
TEST.NAME:ComM_CommunicationAllowed.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_CommunicationAllowed.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_COMMUNICATIONALLOWED
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_CommunicationAllowed.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_CommunicationAllowed
TEST.NEW
TEST.NAME:ComM_CommunicationAllowed.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CommunicationAllowedStatus[0]:FALSE
TEST.VALUE:ComM.ComM_CommunicationAllowed.Channel:0
TEST.VALUE:ComM.ComM_CommunicationAllowed.Allowed:TRUE
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_CommunicationAllowedStatus[0]:TRUE
TEST.END

-- Subprogram: ComM_DCM_ActiveDiagnostic

-- Test Case: ComM_DCM_ActiveDiagnostic.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DCM_ActiveDiagnostic
TEST.NEW
TEST.NAME:ComM_DCM_ActiveDiagnostic.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_DCM_ACTIVEDIAGNOSTIC
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_DCM_ActiveDiagnostic.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DCM_ActiveDiagnostic
TEST.NEW
TEST.NAME:ComM_DCM_ActiveDiagnostic.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_DCM_ActiveDiagnostic.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_DCM_ACTIVEDIAGNOSTIC
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_DCM_ActiveDiagnostic.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DCM_ActiveDiagnostic
TEST.NEW
TEST.NAME:ComM_DCM_ActiveDiagnostic.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:FALSE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.ComM_DCM_ActiveDiagnostic.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:TRUE
TEST.END

-- Test Case: ComM_DCM_ActiveDiagnostic.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DCM_ActiveDiagnostic
TEST.NEW
TEST.NAME:ComM_DCM_ActiveDiagnostic.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:FALSE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_PASSIVE
TEST.VALUE:ComM.ComM_DCM_ActiveDiagnostic.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:FALSE
TEST.END

-- Subprogram: ComM_DCM_InactiveDiagnostic

-- Test Case: ComM_DCM_InactiveDiagnostic.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DCM_InactiveDiagnostic
TEST.NEW
TEST.NAME:ComM_DCM_InactiveDiagnostic.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_DCM_INACTIVEDIAGNOSTIC
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_DCM_InactiveDiagnostic.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DCM_InactiveDiagnostic
TEST.NEW
TEST.NAME:ComM_DCM_InactiveDiagnostic.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_DCM_InactiveDiagnostic.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_DCM_INACTIVEDIAGNOSTIC
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_DCM_InactiveDiagnostic.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DCM_InactiveDiagnostic
TEST.NEW
TEST.NAME:ComM_DCM_InactiveDiagnostic.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:TRUE
TEST.VALUE:ComM.ComM_DCM_InactiveDiagnostic.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:FALSE
TEST.END

-- Subprogram: ComM_DeInit

-- Test Case: ComM_DeInit.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DeInit
TEST.NEW
TEST.NAME:ComM_DeInit.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_DEINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_INIT_FAILED
TEST.END

-- Test Case: ComM_DeInit.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DeInit
TEST.NEW
TEST.NAME:ComM_DeInit.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_NO_COM_NO_PENDING_REQUEST
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_NO_COM_NO_PENDING_REQUEST
TEST.END

-- Test Case: ComM_DeInit.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_DeInit
TEST.NEW
TEST.NAME:ComM_DeInit.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_NO_COM_REQUEST_PENDING
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_NO_COM_REQUEST_PENDING
TEST.END

-- Subprogram: ComM_EcuM_PNCWakeUpIndication

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> FALSE
      (2) for (PncIndex < 1U) ==> FALSE
      (4) if (PncIndex < 1U) ==> FALSE
      (7) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set PncIndex due to assignment
      Cannot set ErrorId due to assignment
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002-PARTIAL
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-002-PARTIAL
TEST.BASIS_PATH:2 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> FALSE
      (2) for (PncIndex < 1U) ==> FALSE
      (4) if (PncIndex < 1U) ==> FALSE
      (7) if (0xffU != ErrorId) ==> TRUE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set PncIndex due to assignment
      Cannot set ErrorId due to assignment
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-003-PARTIAL
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-003-PARTIAL
TEST.BASIS_PATH:3 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> FALSE
      (2) for (PncIndex < 1U) ==> FALSE
      (4) if (PncIndex < 1U) ==> TRUE
      (5) if ((COMM_PNC_NO_COMMUNICATION) == (ComM_PncCurrentMode)[PncIndex]) ==> FALSE
      (6) for (ChannelId < 3U) ==> FALSE
      (7) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set PncIndex due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 6
      Cannot set local variable ErrorId in branch 7
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_REQUESTED
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-004-PARTIAL
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-004-PARTIAL
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> FALSE
      (2) for (PncIndex < 1U) ==> FALSE
      (4) if (PncIndex < 1U) ==> TRUE
      (5) if ((COMM_PNC_NO_COMMUNICATION) == (ComM_PncCurrentMode)[PncIndex]) ==> FALSE
      (6) for (ChannelId < 3U) ==> TRUE
      (7) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set PncIndex due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 6
      Cannot set local variable ErrorId in branch 7
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_REQUESTED
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> FALSE
      (2) for (PncIndex < 1U) ==> FALSE
      (4) if (PncIndex < 1U) ==> TRUE
      (5) if ((COMM_PNC_NO_COMMUNICATION) == (ComM_PncCurrentMode)[PncIndex]) ==> TRUE
      (6) for (ChannelId < 3U) ==> FALSE
      (7) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set PncIndex due to assignment
      Conflict: Unable to validate expression-to-expression comparison in branch 6
      Cannot set local variable ErrorId in branch 7
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_NO_COMMUNICATION
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> FALSE
      (2) for (PncIndex < 1U) ==> TRUE
      (3) if (PncId == pPncConfig->PncHandle) ==> TRUE
      (4) if (PncIndex < 1U) ==> FALSE
      (7) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set variable to unknown value in branch 3
      Cannot set pPncConfig due to assignment
      Cannot set local variable pPncConfig in branch 3
      Cannot set PncIndex due to assignment
      Cannot set ErrorId due to assignment
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> FALSE
      (2) for (PncIndex < 1U) ==> TRUE
      (3) if (PncId == pPncConfig->PncHandle) ==> FALSE
      (4) if (PncIndex < 1U) ==> FALSE
      (7) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set local variable pPncConfig in branch 3
      Cannot set PncIndex due to assignment
      Cannot set ErrorId due to assignment
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-007-PARTIAL.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-007-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> FALSE
      (2) for (PncIndex < 1U) ==> TRUE
      (3) if (PncId == pPncConfig->PncHandle) ==> FALSE
      (4) if (PncIndex < 1U) ==> FALSE
      (7) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Conflict: Unable to validate expression-to-expression comparison in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set local variable pPncConfig in branch 3
      Cannot set PncIndex due to assignment
      Cannot set ErrorId due to assignment
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncConfig[0].PncHandle:1
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:0
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_PNCWakeUpIndication
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((COMM_INIT) != ComM_InitStatus) ==> TRUE
      (7) if (0xffU != ErrorId) ==> FALSE
   Test Case Generation Notes:
      Cannot set ErrorId due to assignment
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.VALUE:ComM.ComM_EcuM_PNCWakeUpIndication.PncId:<<MIN>>
TEST.END

-- Subprogram: ComM_EcuM_WakeUpIndication

-- Test Case: ComM_EcuM_WakeUpIndication.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_WakeUpIndication
TEST.NEW
TEST.NAME:ComM_EcuM_WakeUpIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_ECUM_WAKEUPINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_EcuM_WakeUpIndication.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_WakeUpIndication
TEST.NEW
TEST.NAME:ComM_EcuM_WakeUpIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_EcuM_WakeUpIndication.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_ECUM_WAKEUPINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_EcuM_WakeUpIndication.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_EcuM_WakeUpIndication
TEST.NEW
TEST.NAME:ComM_EcuM_WakeUpIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[0]:FALSE
TEST.VALUE:ComM.ComM_EcuM_WakeUpIndication.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[0]:TRUE
TEST.END

-- Subprogram: ComM_FullComNetworkRequestOnEntry

-- Test Case: ComM_FullComNetworkRequestOnEntry.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestOnEntry.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_FullComNetworkRequestOnEntry.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_FullComNetworkRequestOnEntry.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:2
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_FullComNetworkRequestOnEntry.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComNetworkRequestOnEntry.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComNetworkRequestOnEntry.Channel:0x5
TEST.END

-- Test Case: ComM_FullComNetworkRequestOnEntry.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].BusSMFnConfigId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:2
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_FullComNetworkRequestOnEntry.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelUserRequestedMode[0]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelUserRequestedMode[1]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_FullComNetworkRequestOnEntry.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[1]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_FullComNetworkRequestOnEntry.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestOnEntry
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestOnEntry.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[1]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Subprogram: ComM_FullComNetworkRequestProcessor

-- Test Case: ComM_FullComNetworkRequestProcessor.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComNetworkRequestProcessor.Channel:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_GetUserModeWithInhibitionCheck
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:4
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:4
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Timer[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Timer[0]:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.010
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Timer[0]:2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.011
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_GetUserModeWithInhibitionCheck
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Timer[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Timer[0]:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComNetworkRequestProcessor.012
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComNetworkRequestProcessor
TEST.NEW
TEST.NAME:ComM_FullComNetworkRequestProcessor.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSmMode[0]:2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Subprogram: ComM_FullComReadySleepOnEntry

-- Test Case: ComM_FullComReadySleepOnEntry.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:4
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:4
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepOnEntry.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepOnEntry.Channel:0x5
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].BusSMFnConfigId:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[1]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepOnEntry.Channel:1
TEST.VALUE:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[1].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.END

-- Test Case: ComM_FullComReadySleepOnEntry.010
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_FullComReadySleepOnEntry.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[1].NmVariantType:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepOnEntry.CurrentComMState:1
TEST.END

-- Subprogram: ComM_FullComReadySleepProcessor

-- Test Case: ComM_FullComReadySleepProcessor.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepProcessor.Channel:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepProcessor.Channel:2
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_GetUserModeWithInhibitionCheck
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].BusType:4
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].BusType:4
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:4
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.010
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:2
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.011
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Timer[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Timer[0]:0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.012
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.012
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Timer[0]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Timer[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_FullComReadySleepProcessor.013
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_FullComReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_FullComReadySleepProcessor.013
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_FullComReadySleepProcessor.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_FullComReadySleepProcessor.Channel:0x5
TEST.END

-- Subprogram: ComM_GetCurrentComMode

-- Test Case: ComM_GetCurrentComMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetCurrentComMode
TEST.NEW
TEST.NAME:ComM_GetCurrentComMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETCURRENTCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_GetCurrentComMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetCurrentComMode
TEST.NEW
TEST.NAME:ComM_GetCurrentComMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetCurrentComMode.User:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETCURRENTCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_GetCurrentComMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetCurrentComMode
TEST.NEW
TEST.NAME:ComM_GetCurrentComMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetCurrentComMode.User:0
TEST.VALUE:ComM.ComM_GetCurrentComMode.ComMode:<<malloc 9>>
TEST.VALUE:ComM.ComM_GetCurrentComMode.ComMode:<<null>>
TEST.VALUE:ComM.ComM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETCURRENTCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_PARAM_POINTER
TEST.END

-- Test Case: ComM_GetCurrentComMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetCurrentComMode
TEST.NEW
TEST.NAME:ComM_GetCurrentComMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].BusSMFnConfigId:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_GetCurrentComMode.User:0
TEST.VALUE:ComM.ComM_GetCurrentComMode.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_GetCurrentComMode.ComMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.ComM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetCurrentComMode.ComMode[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.ComM_GetCurrentComMode.return:E_OK
TEST.END

-- Test Case: ComM_GetCurrentComMode.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetCurrentComMode
TEST.NEW
TEST.NAME:ComM_GetCurrentComMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].BusSMFnConfigId:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[1].BusSMFnConfigId:2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[1].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_GetCurrentComMode.User:0
TEST.VALUE:ComM.ComM_GetCurrentComMode.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetCurrentComMode.return:E_OK
TEST.END

-- Test Case: ComM_GetCurrentComMode.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetCurrentComMode
TEST.NEW
TEST.NAME:ComM_GetCurrentComMode.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetRequestedComMode
TEST.VALUE:ComM.ComM_GetCurrentComMode.ComMode:<<malloc 1>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.END

-- Test Case: ComM_GetCurrentComMode.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetCurrentComMode
TEST.NEW
TEST.NAME:ComM_GetCurrentComMode.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:BusSMGetCurrentComModeFn_test
TEST.VALUE:ComM.ComM_GetCurrentComMode.ComMode:<<malloc 1>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:BusSMGetCurrentComModeFn_test
TEST.END

-- Subprogram: ComM_GetHighestRequestMode

-- Test Case: ComM_GetHighestRequestMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetHighestRequestMode
TEST.NEW
TEST.NAME:ComM_GetHighestRequestMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.END

-- Test Case: ComM_GetHighestRequestMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetHighestRequestMode
TEST.NEW
TEST.NAME:ComM_GetHighestRequestMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsFullComRequestByUser
TEST.VALUE:ComM.ComM_IsFullComRequestByUser.return:1
TEST.END

-- Test Case: ComM_GetHighestRequestMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetHighestRequestMode
TEST.NEW
TEST.NAME:ComM_GetHighestRequestMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.END

-- Test Case: ComM_GetHighestRequestMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetHighestRequestMode
TEST.NEW
TEST.NAME:ComM_GetHighestRequestMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusComModeReq[0]:2
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusComModeReq[0]:2
TEST.END

-- Test Case: ComM_GetHighestRequestMode.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetHighestRequestMode
TEST.NEW
TEST.NAME:ComM_GetHighestRequestMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusComModeReq[0]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap:"5"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[1].ChannelsToUserMap:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[1].ChannelsToUserMap:"5"
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusComModeReq[0]:2
TEST.END

-- Test Case: ComM_GetHighestRequestMode.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetHighestRequestMode
TEST.NEW
TEST.NAME:ComM_GetHighestRequestMode.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelInhibitionEnabled
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusComModeReq[0]:2
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap:"5"
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[1].ChannelsToUserMap:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[1].ChannelsToUserMap:"5"
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusComModeReq[0]:2
TEST.END

-- Test Case: ComM_GetHighestRequestMode.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetHighestRequestMode
TEST.NEW
TEST.NAME:ComM_GetHighestRequestMode.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_PncGetHighestRequestedMode
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.return:COMM_PNC_REQUESTED
TEST.END

-- Test Case: ComM_GetHighestRequestMode.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetHighestRequestMode
TEST.NEW
TEST.NAME:ComM_GetHighestRequestMode.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_PncGetHighestRequestedMode
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.return:COMM_PNC_REQUESTED
TEST.END

-- Subprogram: ComM_GetInhibitionStatus

-- Test Case: ComM_GetInhibitionStatus.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetInhibitionStatus
TEST.NEW
TEST.NAME:ComM_GetInhibitionStatus.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.VALUE:ComM.ComM_GetInhibitionStatus.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETINHIBITIONSTATUS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_GetInhibitionStatus.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetInhibitionStatus
TEST.NEW
TEST.NAME:ComM_GetInhibitionStatus.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetInhibitionStatus.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETINHIBITIONSTATUS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_GetInhibitionStatus.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetInhibitionStatus
TEST.NEW
TEST.NAME:ComM_GetInhibitionStatus.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetInhibitionStatus.Channel:0
TEST.VALUE:ComM.ComM_GetInhibitionStatus.Status:<<malloc 9>>
TEST.VALUE:ComM.ComM_GetInhibitionStatus.Status:<<null>>
TEST.VALUE:ComM.ComM_GetInhibitionStatus.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetInhibitionStatus.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETINHIBITIONSTATUS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_PARAM_POINTER
TEST.END

-- Test Case: ComM_GetInhibitionStatus.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetInhibitionStatus
TEST.NEW
TEST.NAME:ComM_GetInhibitionStatus.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetInhibitionStatus.Channel:0
TEST.VALUE:ComM.ComM_GetInhibitionStatus.Status:<<malloc 1>>
TEST.VALUE:ComM.ComM_GetInhibitionStatus.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetInhibitionStatus.return:E_OK
TEST.END

-- Subprogram: ComM_GetMaxComMode

-- Test Case: ComM_GetMaxComMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetMaxComMode
TEST.NEW
TEST.NAME:ComM_GetMaxComMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.VALUE:ComM.ComM_GetMaxComMode.User:0
TEST.VALUE:ComM.ComM_GetMaxComMode.ComMode:<<malloc 1>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETMAXCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_GetMaxComMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetMaxComMode
TEST.NEW
TEST.NAME:ComM_GetMaxComMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetMaxComMode.User:255
TEST.VALUE:ComM.ComM_GetMaxComMode.ComMode:<<malloc 1>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETMAXCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_GetMaxComMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetMaxComMode
TEST.NEW
TEST.NAME:ComM_GetMaxComMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetMaxComMode.User:0
TEST.VALUE:ComM.ComM_GetMaxComMode.ComMode:<<malloc 9>>
TEST.VALUE:ComM.ComM_GetMaxComMode.ComMode:<<null>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETMAXCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_PARAM_POINTER
TEST.END

-- Test Case: ComM_GetMaxComMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetMaxComMode
TEST.NEW
TEST.NAME:ComM_GetMaxComMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:FALSE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:FALSE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:FALSE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap:<<malloc 5>>
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap:"0x01"
TEST.VALUE:ComM.ComM_GetMaxComMode.User:0
TEST.VALUE:ComM.ComM_GetMaxComMode.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_GetMaxComMode.ComMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.ComM_GetMaxComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetMaxComMode.ComMode[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.ComM_GetMaxComMode.return:E_OK
TEST.END

-- Test Case: ComM_GetMaxComMode.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetMaxComMode
TEST.NEW
TEST.NAME:ComM_GetMaxComMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:455
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_GetMaxComMode.User:0
TEST.VALUE:ComM.ComM_GetMaxComMode.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_GetMaxComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetMaxComMode.return:E_OK
TEST.END

-- Test Case: ComM_GetMaxComMode.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetMaxComMode
TEST.NEW
TEST.NAME:ComM_GetMaxComMode.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelInhibitionEnabled
TEST.VALUE:<<OPTIONS>>.REFERENCED_GLOBALS:TRUE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:455
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_GetMaxComMode.User:0
TEST.VALUE:ComM.ComM_GetMaxComMode.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_GetMaxComMode.return:E_NOT_OK
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.return:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetMaxComMode.return:E_OK
TEST.END

-- Subprogram: ComM_GetRequestedComMode

-- Test Case: ComM_GetRequestedComMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetRequestedComMode
TEST.NEW
TEST.NAME:ComM_GetRequestedComMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETREQUESTEDCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_GetRequestedComMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetRequestedComMode
TEST.NEW
TEST.NAME:ComM_GetRequestedComMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetRequestedComMode.User:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETREQUESTEDCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_GetRequestedComMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetRequestedComMode
TEST.NEW
TEST.NAME:ComM_GetRequestedComMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetRequestedComMode.User:0
TEST.VALUE:ComM.ComM_GetRequestedComMode.ComMode:<<malloc 9>>
TEST.VALUE:ComM.ComM_GetRequestedComMode.ComMode:<<null>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETREQUESTEDCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_PARAM_POINTER
TEST.END

-- Test Case: ComM_GetRequestedComMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetRequestedComMode
TEST.NEW
TEST.NAME:ComM_GetRequestedComMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.ComM_GetRequestedComMode.User:0
TEST.VALUE:ComM.ComM_GetRequestedComMode.ComMode:<<malloc 1>>
TEST.VALUE:ComM.ComM_GetRequestedComMode.ComMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.ComM_GetRequestedComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetRequestedComMode.ComMode[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.ComM_GetRequestedComMode.return:E_OK
TEST.END

-- Subprogram: ComM_GetState

-- Test Case: ComM_GetState.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetState.Channel:3
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"0"
TEST.VALUE:ComM.ComM_GetState.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"1"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:1
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"1"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:1
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"1"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:5
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"1"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:5
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"1"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_GetUserModeWithInhibitionCheck
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:5
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"1"
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.010
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:5
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"1"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetState.011
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetState
TEST.NEW
TEST.NAME:ComM_GetState.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:5
TEST.VALUE:ComM.ComM_GetState.Channel:0x4
TEST.VALUE:ComM.ComM_GetState.State:<<malloc 2>>
TEST.VALUE:ComM.ComM_GetState.State:"1"
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_GetState.Channel:0x4
TEST.END

-- Subprogram: ComM_GetStatus

-- Test Case: ComM_GetStatus.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetStatus
TEST.NEW
TEST.NAME:ComM_GetStatus.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetStatus.Status:<<null>>
TEST.VALUE:ComM.ComM_GetStatus.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetStatus.Status:<<null>>
TEST.EXPECTED:ComM.ComM_GetStatus.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETSTATUS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_PARAM_POINTER
TEST.END

-- Test Case: ComM_GetStatus.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetStatus
TEST.NEW
TEST.NAME:ComM_GetStatus.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.VALUE:ComM.ComM_GetStatus.Status:<<null>>
TEST.VALUE:ComM.ComM_GetStatus.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.ComM_GetStatus.Status:<<null>>
TEST.EXPECTED:ComM.ComM_GetStatus.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETSTATUS
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_GetStatus.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetStatus
TEST.NEW
TEST.NAME:ComM_GetStatus.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_GetStatus.Status:<<malloc 1>>
TEST.VALUE:ComM.ComM_GetStatus.Status[0]:COMM_UNINIT
TEST.VALUE:ComM.ComM_GetStatus.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetStatus.Status[0]:COMM_INIT
TEST.EXPECTED:ComM.ComM_GetStatus.return:E_OK
TEST.END

-- Subprogram: ComM_GetUserModeWithInhibitionCheck

-- Test Case: ComM_GetUserModeWithInhibitionCheck.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetUserModeWithInhibitionCheck
TEST.NEW
TEST.NAME:ComM_GetUserModeWithInhibitionCheck.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_GetUserModeWithInhibitionCheck.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetUserModeWithInhibitionCheck
TEST.NEW
TEST.NAME:ComM_GetUserModeWithInhibitionCheck.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_GetUserModeWithInhibitionCheck.Channel:0x5
TEST.END

-- Subprogram: ComM_GetVersionInfo

-- Test Case: ComM_GetVersionInfo.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetVersionInfo
TEST.NEW
TEST.NAME:ComM_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_GetVersionInfo.Versioninfo:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_GETVERSIONINFO
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_PARAM_POINTER
TEST.END

-- Test Case: ComM_GetVersionInfo.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_GetVersionInfo
TEST.NEW
TEST.NAME:ComM_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_GetVersionInfo.Versioninfo:<<malloc 1>>
TEST.EXPECTED:ComM.ComM_GetVersionInfo.Versioninfo[0].vendorID:51
TEST.EXPECTED:ComM.ComM_GetVersionInfo.Versioninfo[0].moduleID:12
TEST.EXPECTED:ComM.ComM_GetVersionInfo.Versioninfo[0].sw_major_version:1
TEST.EXPECTED:ComM.ComM_GetVersionInfo.Versioninfo[0].sw_minor_version:0
TEST.EXPECTED:ComM.ComM_GetVersionInfo.Versioninfo[0].sw_patch_version:0
TEST.END

-- Subprogram: ComM_Init

-- Test Case: ComM_Init.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Init
TEST.NEW
TEST.NAME:ComM_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_Init.ConfigPtr:<<null>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_INIT_FAILED
TEST.END

-- Test Case: ComM_Init.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Init
TEST.NEW
TEST.NAME:ComM_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.END

-- Subprogram: ComM_InitMemory

-- Test Case: ComM_InitMemory.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_InitMemory
TEST.NEW
TEST.NAME:ComM_InitMemory.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: ComM_IsChannelInhibitionEnabled

-- Test Case: ComM_IsChannelInhibitionEnabled_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelInhibitionEnabled_001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_IsChannelInhibitionEnabled_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelInhibitionEnabled_002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelNoComLimitationEnabled
TEST.STUB:ComM.ComM_IsChannelWakeupInhibitionEnabled
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.Channel:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelNoComLimitationEnabled.return:0
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.return:0
TEST.END

-- Test Case: ComM_IsChannelInhibitionEnabled_002.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelInhibitionEnabled_002.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelNoComLimitationEnabled
TEST.STUB:ComM.ComM_IsChannelWakeupInhibitionEnabled
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.Channel:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelNoComLimitationEnabled.return:0
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.return:1
TEST.END

-- Test Case: ComM_IsChannelInhibitionEnabled_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelInhibitionEnabled_003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelNoComLimitationEnabled
TEST.STUB:ComM.ComM_IsChannelWakeupInhibitionEnabled
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.Channel:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelNoComLimitationEnabled.return:1
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.return:1
TEST.END

-- Subprogram: ComM_IsChannelNoComLimitationEnabled

-- Test Case: ComM_IsChannelNoComLimitationEnable_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelNoComLimitationEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelNoComLimitationEnable_001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_IsChannelNoComLimitationEnabled.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_IsChannelNoComLimitationEnable_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelNoComLimitationEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelNoComLimitationEnable_002
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_IsChannelNoComLimitationEnabled.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_IsChannelNoComLimitationEnable_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelNoComLimitationEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelNoComLimitationEnable_003
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_IsChannelNoComLimitationEnabled.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_IsChannelNoComLimitationEnable_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelNoComLimitationEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelNoComLimitationEnable_004
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_IsChannelNoComLimitationEnabled.Channel:<<MIN>>
TEST.END

-- Subprogram: ComM_IsChannelWakeupInhibitionEnabled

-- Test Case: ComM_IsChannelWakeupInhibitionEnabled_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelWakeupInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelWakeupInhibitionEnabled_001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_IsChannelWakeupInhibitionEnabled_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelWakeupInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelWakeupInhibitionEnabled_002
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_IsChannelWakeupInhibitionEnabled_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelWakeupInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelWakeupInhibitionEnabled_003
TEST.BASIS_PATH:3 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:2
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_IsChannelWakeupInhibitionEnabled_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelWakeupInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelWakeupInhibitionEnabled_004
TEST.BASIS_PATH:4 of 4 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_IsChannelWakeupInhibitionEnabled_004.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelWakeupInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelWakeupInhibitionEnabled_004.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.Channel:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus:"1"
TEST.END

-- Test Case: ComM_IsChannelWakeupInhibitionEnabled_004.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelWakeupInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelWakeupInhibitionEnabled_004.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.Channel:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus:"0"
TEST.END

-- Test Case: ComM_IsChannelWakeupInhibitionEnabled_004.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelWakeupInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelWakeupInhibitionEnabled_004.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.Channel:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_CurrentState[0]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus:"1"
TEST.END

-- Test Case: ComM_IsChannelWakeupInhibitionEnabled_004.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsChannelWakeupInhibitionEnabled
TEST.NEW
TEST.NAME:ComM_IsChannelWakeupInhibitionEnabled_004.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:3
TEST.VALUE:ComM.ComM_IsChannelWakeupInhibitionEnabled.Channel:<<MIN>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus:"1"
TEST.END

-- Subprogram: ComM_IsFullComRequestByUser

-- Test Case: ComM_IsFullComRequestByUser.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsFullComRequestByUser
TEST.NEW
TEST.NAME:ComM_IsFullComRequestByUser.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_IsFullComRequestByUser.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsFullComRequestByUser
TEST.NEW
TEST.NAME:ComM_IsFullComRequestByUser.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_IsFullComRequestByUser.Channel:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_IsFullComRequestByUser.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsFullComRequestByUser
TEST.NEW
TEST.NAME:ComM_IsFullComRequestByUser.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_IsFullComRequestByUser.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsFullComRequestByUser
TEST.NEW
TEST.NAME:ComM_IsFullComRequestByUser.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].ChannelsToUserMap[0]:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_IsFullComRequestByUser.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_IsFullComRequestByUser
TEST.NEW
TEST.NAME:ComM_IsFullComRequestByUser.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_IsFullComRequestByUser.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_IsFullComRequestByUser.Channel:0x5
TEST.END

-- Subprogram: ComM_LimitChannelToNoComMode

-- Test Case: ComM_LimitChannelToNoComMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitChannelToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitChannelToNoComMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Channel:0
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_LimitChannelToNoComMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitChannelToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitChannelToNoComMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Channel:255
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_LimitChannelToNoComMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitChannelToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitChannelToNoComMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_FULL_COM_NETWORK_REQUESTED
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_FULL
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Channel:0
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Status:TRUE
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x2
TEST.EXPECTED:ComM.ComM_LimitChannelToNoComMode.return:E_OK
TEST.END

-- Test Case: ComM_LimitChannelToNoComMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitChannelToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitChannelToNoComMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_FULL_COM_NETWORK_REQUESTED
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Channel:0
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Status:TRUE
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x0
TEST.EXPECTED:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.END

-- Test Case: ComM_LimitChannelToNoComMode.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitChannelToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitChannelToNoComMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_FULL_COM_NETWORK_REQUESTED
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Channel:0
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Status:TRUE
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x0
TEST.EXPECTED:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.END

-- Test Case: ComM_LimitChannelToNoComMode.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitChannelToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitChannelToNoComMode.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_SILENT_COM
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Channel:0
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Status:TRUE
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x0
TEST.EXPECTED:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.END

-- Test Case: ComM_LimitChannelToNoComMode.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitChannelToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitChannelToNoComMode.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_SILENT_COM
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_FULL
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Channel:0
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Status:FALSE
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x0
TEST.EXPECTED:ComM.ComM_LimitChannelToNoComMode.return:E_OK
TEST.END

-- Test Case: ComM_LimitChannelToNoComMode.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitChannelToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitChannelToNoComMode.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:COMM_SILENT_COM
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_PASSIVE
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Channel:0
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.Status:FALSE
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x2
TEST.EXPECTED:ComM.ComM_LimitChannelToNoComMode.return:E_NOT_OK
TEST.END

-- Subprogram: ComM_LimitECUToNoComMode

-- Test Case: ComM_LimitECUToNoComMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitECUToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitECUToNoComMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.END

-- Test Case: ComM_LimitECUToNoComMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitECUToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitECUToNoComMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.END

-- Test Case: ComM_LimitECUToNoComMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_LimitECUToNoComMode
TEST.NEW
TEST.NAME:ComM_LimitECUToNoComMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_LimitChannelToNoComMode
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_LimitChannelToNoComMode.return:1
TEST.END

-- Subprogram: ComM_MainFunction

-- Test Case: ComM_MainFunction.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.001
TEST.END

-- Test Case: ComM_MainFunction.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.002
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.END

-- Test Case: ComM_MainFunction.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.003
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_MainFunction.Channel:4
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_MainFunction.Channel:4
TEST.END

-- Test Case: ComM_MainFunction.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.004
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CurrentState[0]:5
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_CurrentState[0]:5
TEST.END

-- Test Case: ComM_MainFunction.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.005
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[0].StateProcessorFn:<<null>>
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[0].StateProcessorFn:<<null>>
TEST.END

-- Test Case: ComM_MainFunction.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.006
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[0].StateProcessorFn:StateProcessorFn_test2
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[0].StateProcessorFn:StateProcessorFn_test2
TEST.END

-- Test Case: ComM_MainFunction.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.007
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[0].StateProcessorFn:StateProcessorFn_test1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[0].StateProcessorFn:StateProcessorFn_test1
TEST.END

-- Test Case: ComM_MainFunction.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.008
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[0].StateProcessorFn:StateProcessorFn_test2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[1].StateOnEntryActionFn:StateOnEntryActionFn_test1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[0].StateProcessorFn:StateProcessorFn_test2
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_StateFunctionListConfig[1].StateOnEntryActionFn:StateOnEntryActionFn_test1
TEST.END

-- Test Case: ComM_MainFunction.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_MainFunction
TEST.NEW
TEST.NAME:ComM_MainFunction.009
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_IsBusSmModeChanged[0]:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_IsBusSmModeChanged[0]:0
TEST.END

-- Subprogram: ComM_Nm_BusSleepMode

-- Test Case: ComM_Nm_BusSleepMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_BusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_BusSleepMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_BUSSLEEPMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_Nm_BusSleepMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_BusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_BusSleepMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_Nm_BusSleepMode.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_BUSSLEEPMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_BusSleepMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_BusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_BusSleepMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.ComM_Nm_BusSleepMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_BUSSLEEPMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_BusSleepMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_BusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_BusSleepMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_FULL
TEST.VALUE:ComM.ComM_Nm_BusSleepMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:COMM_NO_COM_NO_PENDING_REQUEST
TEST.END

-- Test Case: ComM_Nm_BusSleepMode.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_BusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_BusSleepMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_PASSIVE
TEST.VALUE:ComM.ComM_Nm_BusSleepMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:COMM_NO_COM_NO_PENDING_REQUEST
TEST.END

-- Subprogram: ComM_Nm_NetworkMode

-- Test Case: ComM_Nm_NetworkMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkMode
TEST.NEW
TEST.NAME:ComM_Nm_NetworkMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_NETWORKMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_Nm_NetworkMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkMode
TEST.NEW
TEST.NAME:ComM_Nm_NetworkMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_Nm_NetworkMode.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_NETWORKMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_NetworkMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkMode
TEST.NEW
TEST.NAME:ComM_Nm_NetworkMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.ComM_Nm_NetworkMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_NETWORKMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_NetworkMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkMode
TEST.NEW
TEST.NAME:ComM_Nm_NetworkMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_FULL
TEST.VALUE:ComM.ComM_Nm_NetworkMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:COMM_FULL_COM_NETWORK_REQUESTED
TEST.END

-- Test Case: ComM_Nm_NetworkMode.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkMode
TEST.NEW
TEST.NAME:ComM_Nm_NetworkMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_PASSIVE
TEST.VALUE:ComM.ComM_Nm_NetworkMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:COMM_FULL_COM_NETWORK_REQUESTED
TEST.END

-- Subprogram: ComM_Nm_NetworkStartIndication

-- Test Case: ComM_Nm_NetworkStartIndication.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkStartIndication
TEST.NEW
TEST.NAME:ComM_Nm_NetworkStartIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_NETWORKSTARTINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_Nm_NetworkStartIndication.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkStartIndication
TEST.NEW
TEST.NAME:ComM_Nm_NetworkStartIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_Nm_NetworkStartIndication.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_NETWORKSTARTINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_NetworkStartIndication.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkStartIndication
TEST.NEW
TEST.NAME:ComM_Nm_NetworkStartIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.ComM_Nm_NetworkStartIndication.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_NETWORKSTARTINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_NetworkStartIndication.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkStartIndication
TEST.NEW
TEST.NAME:ComM_Nm_NetworkStartIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_FULL
TEST.VALUE:ComM.ComM_Nm_NetworkStartIndication.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:COMM_FULL_COM_NETWORK_REQUESTED
TEST.END

-- Test Case: ComM_Nm_NetworkStartIndication.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_NetworkStartIndication
TEST.NEW
TEST.NAME:ComM_Nm_NetworkStartIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_PASSIVE
TEST.VALUE:ComM.ComM_Nm_NetworkStartIndication.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:COMM_FULL_COM_NETWORK_REQUESTED
TEST.END

-- Subprogram: ComM_Nm_PrepareBusSleepMode

-- Test Case: ComM_Nm_PrepareBusSleepMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_PrepareBusSleepMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_PREPAREBUSSLEEPMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_Nm_PrepareBusSleepMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_PrepareBusSleepMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_Nm_PrepareBusSleepMode.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_PREPAREBUSSLEEPMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_PrepareBusSleepMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_PrepareBusSleepMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.ComM_Nm_PrepareBusSleepMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_PREPAREBUSSLEEPMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_PrepareBusSleepMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_PrepareBusSleepMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_FULL
TEST.VALUE:ComM.ComM_Nm_PrepareBusSleepMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:COMM_SILENT_COM
TEST.END

-- Test Case: ComM_Nm_PrepareBusSleepMode.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_PrepareBusSleepMode
TEST.NEW
TEST.NAME:ComM_Nm_PrepareBusSleepMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_PASSIVE
TEST.VALUE:ComM.ComM_Nm_PrepareBusSleepMode.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:COMM_SILENT_COM
TEST.END

-- Subprogram: ComM_Nm_RestartIndication

-- Test Case: ComM_Nm_RestartIndication.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_RestartIndication
TEST.NEW
TEST.NAME:ComM_Nm_RestartIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_RESTARTINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_Nm_RestartIndication.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_RestartIndication
TEST.NEW
TEST.NAME:ComM_Nm_RestartIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_Nm_RestartIndication.Channel:255
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_RESTARTINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_RestartIndication.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_RestartIndication
TEST.NEW
TEST.NAME:ComM_Nm_RestartIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_NONE
TEST.VALUE:ComM.ComM_Nm_RestartIndication.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_NM_RESTARTINDICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_Nm_RestartIndication.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_RestartIndication
TEST.NEW
TEST.NAME:ComM_Nm_RestartIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_FULL
TEST.VALUE:ComM.ComM_Nm_RestartIndication.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.END

-- Test Case: ComM_Nm_RestartIndication.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_Nm_RestartIndication
TEST.NEW
TEST.NAME:ComM_Nm_RestartIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:COMM_NM_VARIANT_TYPE_PASSIVE
TEST.VALUE:ComM.ComM_Nm_RestartIndication.Channel:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.END

-- Subprogram: ComM_NoComNoPendingRequestOnEntry

-- Test Case: ComM_NoComNoPendingRequestOnEntry.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestOnEntry
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestOnEntry.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestOnEntry.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestOnEntry
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestOnEntry.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetMaxComMode
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetMaxComMode
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_NoComNoPendingRequestOnEntry.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestOnEntry
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestOnEntry.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_NoComNoPendingRequestOnEntry.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_NoComNoPendingRequestOnEntry.Channel:0x5
TEST.END

-- Test Case: ComM_NoComNoPendingRequestOnEntry.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestOnEntry
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestOnEntry.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].BusSMFnConfigId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetMaxComMode
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetMaxComMode
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_NoComNoPendingRequestOnEntry.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestOnEntry
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestOnEntry.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[1].NmVariantType:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetMaxComMode
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetMaxComMode
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_NoComNoPendingRequestOnEntry.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestOnEntry
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestOnEntry.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelNoComLimitationEnabled
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[1].NmVariantType:1
TEST.VALUE:ComM.ComM_IsChannelNoComLimitationEnabled.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetMaxComMode
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].BusSMGetCurrentComModeFn:ComM_GetMaxComMode
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Subprogram: ComM_NoComNoPendingRequestProcessor

-- Test Case: ComM_NoComNoPendingRequestProcessor.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_NoComNoPendingRequestProcessor.Channel:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_NoComNoPendingRequestProcessor.Channel:3
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_GetUserModeWithInhibitionCheck
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.Channel:0
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMWakeupIndicationStatus[0]:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_CommunicationAllowedStatus[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_NoComNoPendingRequestProcessor.010
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_NoComNoPendingRequestProcessor
TEST.NEW
TEST.NAME:ComM_NoComNoPendingRequestProcessor.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_NoComNoPendingRequestProcessor.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_NoComNoPendingRequestProcessor.Channel:0x5
TEST.END

-- Subprogram: ComM_PncGetHighestRequestedMode

-- Test Case: ComM_PncGetHighestRequestMode_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_001
TEST.BASIS_PATH:1 of 9
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MAX>>
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_001.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_001.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.BswM_ComM_CurrentPNCMode.PncId:5
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_002
TEST.BASIS_PATH:2 of 9 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncBusRequestedMode[0]:<<MIN>>
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MIN>>
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_003
TEST.BASIS_PATH:3 of 9 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncBusRequestedMode[0]:<<MAX>>
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MIN>>
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_004
TEST.BASIS_PATH:4 of 9 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncBusRequestedMode[0]:<<MIN>>
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MIN>>
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_005
TEST.BASIS_PATH:5 of 9 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelInhibitionEnabled
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncBusRequestedMode[0]:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.return:1
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MIN>>
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_006
TEST.BASIS_PATH:6 of 9 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelInhibitionEnabled
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncBusRequestedMode[0]:<<MIN>>
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.return:0
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MIN>>
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_007
TEST.BASIS_PATH:7 of 9 (template)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncBusRequestedMode[0]:<<MIN>>
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MIN>>
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_008
TEST.BASIS_PATH:8 of 9 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncBusRequestedMode[0]:<<MIN>>
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncUserRequestComMode[0]:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncToUserMapConfig[0]:0
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MIN>>
TEST.END

-- Test Case: ComM_PncGetHighestRequestMode_009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncGetHighestRequestedMode
TEST.NEW
TEST.NAME:ComM_PncGetHighestRequestMode_009
TEST.BASIS_PATH:9 of 9 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncBusRequestedMode[0]:<<MIN>>
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncUserRequestComMode[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncToUserMapConfig[0]:0
TEST.VALUE:ComM.ComM_PncGetHighestRequestedMode.PncId:<<MIN>>
TEST.END

-- Subprogram: ComM_PncModeSendSignal

-- Test Case: ComM_PncModeSendSignal_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_001
TEST.BASIS_PATH:1 of 8
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U > PncId) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MAX>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:<<MIN>>
TEST.END

-- Test Case: ComM_PncModeSendSignal_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_002
TEST.BASIS_PATH:2 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:<<MIN>>
TEST.END

-- Test Case: ComM_PncModeSendSignal_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_003
TEST.BASIS_PATH:3 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> FALSE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:<<MIN>>
TEST.END

-- Test Case: ComM_PncModeSendSignal_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_004
TEST.BASIS_PATH:4 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> FALSE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> TRUE
      (7) if (0U == pChannelConfig->NmVariantType) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 6
      Cannot set pChannelConfig due to assignment
      Cannot set local variable pChannelConfig in branch 7
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:<<MIN>>
TEST.END

-- Test Case: ComM_PncModeSendSignal_005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_005
TEST.BASIS_PATH:5 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> FALSE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> TRUE
      (7) if (0U == pChannelConfig->NmVariantType) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 6
      Cannot set pChannelConfig due to assignment
      Cannot set local variable pChannelConfig in branch 7
      Cannot set local variable pPncComSignalConfig in branch 8
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:<<MIN>>
TEST.END

-- Test Case: ComM_PncModeSendSignal_006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_006
TEST.BASIS_PATH:6 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> FALSE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:<<MIN>>
TEST.END

-- Test Case: ComM_PncModeSendSignal_007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_007
TEST.BASIS_PATH:7 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> FALSE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:<<MIN>>
TEST.END

-- Test Case: ComM_PncModeSendSignal_008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_008
TEST.BASIS_PATH:8 of 8 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> TRUE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:1
TEST.END

-- Test Case: ComM_PncModeSendSignal_008.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_008.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> TRUE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_PncConfig[0].PncComSignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_PncConfig[0].PncComSignalEndId:1
TEST.END

-- Test Case: ComM_PncModeSendSignal_008.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_008.002
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> TRUE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncConfig[0].PncComSignalStartId:0
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_PncConfig[0].PncComSignalStartId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_PncConfig[0].PncComSignalEndId:1
TEST.END

-- Test Case: ComM_PncModeSendSignal_008.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_008.003
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> TRUE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncConfig[0].PncComSignalStartId:4
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncConfig[0].PncComSignalEndId:4
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:1
TEST.END

-- Test Case: ComM_PncModeSendSignal_008.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_008.004
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> TRUE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncComSignalConfig[0].PncComSignalDirectionType:1
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:1
TEST.END

-- Test Case: ComM_PncModeSendSignal_008.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_008.005
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> TRUE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncComSignalConfig[0].PncComSignalBufferStartId:4
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:1
TEST.END

-- Test Case: ComM_PncModeSendSignal_008.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_008.006
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> TRUE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncComSignalConfig[0].PncComSignalChanneId:4
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:1
TEST.END

-- Test Case: ComM_PncModeSendSignal_008.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncModeSendSignal
TEST.NEW
TEST.NAME:ComM_PncModeSendSignal_008.007
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if (1U > PncId) ==> TRUE
      (2) for ((PncToComSignalMapId = pPncConfig->PncComSignalEndId) && 1U > PncToComSignalMapId) ==> TRUE
      (3) if (0U == pPncComSignalConfig->PncComSignalDirectionType) ==> TRUE
      (4) if (2U > PncComSignalBufferId) ==> TRUE
      (5) if (IsSet == (unsigned char)1U) ==> TRUE
      (6) if (3U > pPncComSignalConfig->PncComSignalChanneId) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable pPncConfig in branch 2
      Cannot set pPncConfig due to assignment
      Cannot set pPncComSignalConfig due to assignment
      Cannot set local variable pPncComSignalConfig in branch 3
      Cannot set local variable pPncComSignalConfig in branch 4
      Cannot set local variable pPncConfig in branch 4
      Cannot set PncComSignalBufferId due to assignment
      Cannot set local variable pPncConfig in branch 6
      Cannot set local variable pPncComSignalConfig in branch 6
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.VALUE:ComM.ComM_PncModeSendSignal.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncModeSendSignal.IsSet:1
TEST.END

-- Subprogram: ComM_PncNoCommunicationOnEntry

-- Test Case: ComM_PncNoCommunicationOnEntry_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncNoCommunicationOnEntry
TEST.NEW
TEST.NAME:ComM_PncNoCommunicationOnEntry_001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U > PncId) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncNoCommunicationOnEntry.PncId:<<MAX>>
TEST.VALUE:ComM.ComM_PncNoCommunicationOnEntry.CurrentPncMode:<<MIN>>
TEST.END

-- Test Case: ComM_PncNoCommunicationOnEntry_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncNoCommunicationOnEntry
TEST.NEW
TEST.NAME:ComM_PncNoCommunicationOnEntry_002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U > PncId) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncNoCommunicationOnEntry.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncNoCommunicationOnEntry.CurrentPncMode:<<MIN>>
TEST.END

-- Subprogram: ComM_PncNoCommunicationProcessor

-- Test Case: ComM_PnNoCommunicationProcessor_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncNoCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_PnNoCommunicationProcessor_001
TEST.BASIS_PATH:1 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMPncWakeupIndicationStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:0
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.ChannelId:<<MIN>>
TEST.END

-- Test Case: ComM_PnNoCommunicationProcessor_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncNoCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_PnNoCommunicationProcessor_002
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMPncWakeupIndicationStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:0
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PnNoCommunicationProcessor_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncNoCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_PnNoCommunicationProcessor_003
TEST.BASIS_PATH:3 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U != (ComM_EcuMPncWakeupIndicationStatus)[PncId]) ==> FALSE
      (3) if ((unsigned char)0U != (ComM_PncEiraRequestStatus)[PncId]) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMPncWakeupIndicationStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:1
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PnNoCommunicationProcessor_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncNoCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_PnNoCommunicationProcessor_004
TEST.BASIS_PATH:4 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U != (ComM_EcuMPncWakeupIndicationStatus)[PncId]) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_EcuMPncWakeupIndicationStatus[0]:1
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PnNoCommunicationProcessor_005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncNoCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_PnNoCommunicationProcessor_005
TEST.BASIS_PATH:5 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncNoCommunicationProcessor.HighestRequestedPncMode:COMM_PNC_REQUESTED
TEST.END

-- Subprogram: ComM_PncPrepareSleepOnEntry

-- Test Case: ComM_PncPrepareSleepOnEntry_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepOnEntry
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepOnEntry_001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U > PncId) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncPrepareSleepOnEntry.PncId:<<MAX>>
TEST.VALUE:ComM.ComM_PncPrepareSleepOnEntry.CurrentPncMode:<<MIN>>
TEST.END

-- Test Case: ComM_PncPrepareSleepOnEntry_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepOnEntry
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepOnEntry_002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U > PncId) ==> TRUE
      (2) if ((COMM_PNC_NO_COMMUNICATION) == CurrentPncMode) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncPrepareSleepOnEntry.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepOnEntry.CurrentPncMode:COMM_PNC_REQUESTED
TEST.END

-- Test Case: ComM_PncPrepareSleepOnEntry_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepOnEntry
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepOnEntry_003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U > PncId) ==> TRUE
      (2) if ((COMM_PNC_NO_COMMUNICATION) == CurrentPncMode) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncPrepareSleepOnEntry.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepOnEntry.CurrentPncMode:COMM_PNC_NO_COMMUNICATION
TEST.END

-- Subprogram: ComM_PncPrepareSleepProcessor

-- Test Case: ComM_PncPrepareSleepProcessor_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepProcessor
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepProcessor_001
TEST.BASIS_PATH:1 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U != (ComM_PncEiraRequestStatus)[PncId]) ==> FALSE
      (3) if ((ComM_PncPrepareSleepTimer)[PncId] > 0U) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncPrepareSleepTimer[0]:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PncPrepareSleepProcessor_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepProcessor
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepProcessor_002
TEST.BASIS_PATH:2 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U != (ComM_PncEiraRequestStatus)[PncId]) ==> FALSE
      (3) if ((ComM_PncPrepareSleepTimer)[PncId] > 0U) ==> TRUE
      (4) if ((ComM_PncPrepareSleepTimer)[PncId] == 0U) ==> FALSE
   Test Case Generation Notes:
      Cannot set (ComM_PncPrepareSleepTimer)[PncId] due to assignment
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncPrepareSleepTimer[0]:<<MAX>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PncPrepareSleepProcessor_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepProcessor
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepProcessor_003
TEST.BASIS_PATH:3 of 5 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U != (ComM_PncEiraRequestStatus)[PncId]) ==> FALSE
      (3) if ((ComM_PncPrepareSleepTimer)[PncId] > 0U) ==> TRUE
      (4) if ((ComM_PncPrepareSleepTimer)[PncId] == 0U) ==> TRUE
   Test Case Generation Notes:
      Cannot set (ComM_PncPrepareSleepTimer)[PncId] due to assignment
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncPrepareSleepTimer[0]:<<MAX>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PncPrepareSleepProcessor_003.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepProcessor
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepProcessor_003.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U != (ComM_PncEiraRequestStatus)[PncId]) ==> FALSE
      (3) if ((ComM_PncPrepareSleepTimer)[PncId] > 0U) ==> TRUE
      (4) if ((ComM_PncPrepareSleepTimer)[PncId] == 0U) ==> TRUE
   Test Case Generation Notes:
      Cannot set (ComM_PncPrepareSleepTimer)[PncId] due to assignment
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncPrepareSleepTimer[0]:1
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_PncPrepareSleepTimer[0]:1
TEST.END

-- Test Case: ComM_PncPrepareSleepProcessor_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepProcessor
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepProcessor_004
TEST.BASIS_PATH:4 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U != (ComM_PncEiraRequestStatus)[PncId]) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:1
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PncPrepareSleepProcessor_005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncPrepareSleepProcessor
TEST.NEW
TEST.NAME:ComM_PncPrepareSleepProcessor_005
TEST.BASIS_PATH:5 of 5
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncPrepareSleepProcessor.HighestRequestedPncMode:COMM_PNC_REQUESTED
TEST.END

-- Subprogram: ComM_PncReadySleepOnEntry

-- Test Case: ComM_PncReadySleepOnEntry_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_PncReadySleepOnEntry_001
TEST.BASIS_PATH:1 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U > PncId) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncReadySleepOnEntry.PncId:<<MAX>>
TEST.VALUE:ComM.ComM_PncReadySleepOnEntry.CurrentPncMode:<<MIN>>
TEST.END

-- Test Case: ComM_PncReadySleepOnEntry_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_PncReadySleepOnEntry_002
TEST.BASIS_PATH:2 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U > PncId) ==> TRUE
      (2) if ((COMM_PNC_REQUESTED) == CurrentPncMode) ==> FALSE
      (3) if ((COMM_PNC_NO_COMMUNICATION) == CurrentPncMode) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncReadySleepOnEntry.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepOnEntry.CurrentPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PncReadySleepOnEntry_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_PncReadySleepOnEntry_003
TEST.BASIS_PATH:3 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U > PncId) ==> TRUE
      (2) if ((COMM_PNC_REQUESTED) == CurrentPncMode) ==> FALSE
      (3) if ((COMM_PNC_NO_COMMUNICATION) == CurrentPncMode) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncReadySleepOnEntry.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepOnEntry.CurrentPncMode:COMM_PNC_NO_COMMUNICATION
TEST.END

-- Test Case: ComM_PncReadySleepOnEntry_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepOnEntry
TEST.NEW
TEST.NAME:ComM_PncReadySleepOnEntry_004
TEST.BASIS_PATH:4 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if (1U > PncId) ==> TRUE
      (2) if ((COMM_PNC_REQUESTED) == CurrentPncMode) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncReadySleepOnEntry.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepOnEntry.CurrentPncMode:COMM_PNC_REQUESTED
TEST.END

-- Subprogram: ComM_PncReadySleepProcessor

-- Test Case: ComM_PncReadySleepProcessor_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_PncReadySleepProcessor_001
TEST.BASIS_PATH:1 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U == (ComM_PncEiraRequestStatus)[PncId]) ==> FALSE
      (3) if (PncMode != (COMM_PNC_READY_SLEEP)) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable PncMode in branch 3
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:1
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PncReadySleepProcessor_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_PncReadySleepProcessor_002
TEST.BASIS_PATH:2 of 4 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U == (ComM_PncEiraRequestStatus)[PncId]) ==> FALSE
      (3) if (PncMode != (COMM_PNC_READY_SLEEP)) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable PncMode in branch 3
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:1
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PncReadySleepProcessor_002.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_PncReadySleepProcessor_002.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U == (ComM_PncEiraRequestStatus)[PncId]) ==> FALSE
      (3) if (PncMode != (COMM_PNC_READY_SLEEP)) ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable PncMode in branch 3
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:1
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.HighestRequestedPncMode:COMM_PNC_NO_COMMUNICATION
TEST.END

-- Test Case: ComM_PncReadySleepProcessor_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_PncReadySleepProcessor_003
TEST.BASIS_PATH:3 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> FALSE
      (2) if ((unsigned char)0U == (ComM_PncEiraRequestStatus)[PncId]) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncEiraRequestStatus[0]:0
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.PncId:0
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Test Case: ComM_PncReadySleepProcessor_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncReadySleepProcessor
TEST.NEW
TEST.NAME:ComM_PncReadySleepProcessor_004
TEST.BASIS_PATH:4 of 4
TEST.NOTES:
This is an automatically generated test case.
   Test Path 4
      (1) if ((COMM_PNC_REQUESTED) == HighestRequestedPncMode) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncReadySleepProcessor.HighestRequestedPncMode:COMM_PNC_REQUESTED
TEST.END

-- Subprogram: ComM_PncRequestOnEntry

-- Test Case: ComM_PncRequestonEntry_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncRequestOnEntry
TEST.NEW
TEST.NAME:ComM_PncRequestonEntry_001
TEST.BASIS_PATH:1 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (1U > PncId) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncRequestOnEntry.PncId:<<MAX>>
TEST.VALUE:ComM.ComM_PncRequestOnEntry.CurrentPncMode:<<MIN>>
TEST.END

-- Test Case: ComM_PncRequestonEntry_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncRequestOnEntry
TEST.NEW
TEST.NAME:ComM_PncRequestonEntry_002
TEST.BASIS_PATH:2 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (1U > PncId) ==> TRUE
      (2) if ((COMM_PNC_NO_COMMUNICATION) == CurrentPncMode) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncRequestOnEntry.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncRequestOnEntry.CurrentPncMode:COMM_PNC_REQUESTED
TEST.END

-- Test Case: ComM_PncRequestonEntry_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncRequestOnEntry
TEST.NEW
TEST.NAME:ComM_PncRequestonEntry_003
TEST.BASIS_PATH:3 of 3
TEST.NOTES:
This is an automatically generated test case.
   Test Path 3
      (1) if (1U > PncId) ==> TRUE
      (2) if ((COMM_PNC_NO_COMMUNICATION) == CurrentPncMode) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncRequestOnEntry.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncRequestOnEntry.CurrentPncMode:COMM_PNC_NO_COMMUNICATION
TEST.END

-- Subprogram: ComM_PncRequestProcessor

-- Test Case: ComM_PncRequestProcess_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncRequestProcessor
TEST.NEW
TEST.NAME:ComM_PncRequestProcess_001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (HighestRequestedPncMode != (COMM_PNC_REQUESTED)) ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncRequestProcessor.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncRequestProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncRequestProcessor.HighestRequestedPncMode:COMM_PNC_REQUESTED
TEST.END

-- Test Case: ComM_PncRequestProcess_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncRequestProcessor
TEST.NEW
TEST.NAME:ComM_PncRequestProcess_002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (HighestRequestedPncMode != (COMM_PNC_REQUESTED)) ==> TRUE
   Test Case Generation Notes:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.ComM_PncRequestProcessor.PncId:<<MIN>>
TEST.VALUE:ComM.ComM_PncRequestProcessor.ChannelId:<<MIN>>
TEST.VALUE:ComM.ComM_PncRequestProcessor.HighestRequestedPncMode:COMM_PNC_READY_SLEEP
TEST.END

-- Subprogram: ComM_PncStateProcessing

-- Test Case: ComM_PncStateProcessing_001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_001
TEST.BASIS_PATH:1 of 14
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_PncStateProcessing_002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_002
TEST.BASIS_PATH:2 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_PncStateProcessing_003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_003
TEST.BASIS_PATH:3 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_PncStateProcessing_004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_004
TEST.BASIS_PATH:4 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_PncStateProcessing_005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_005
TEST.BASIS_PATH:5 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_PncStateProcessing_006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_006
TEST.BASIS_PATH:6 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_PncStateProcessing_007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_007
TEST.BASIS_PATH:7 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_NO_COMMUNICATION
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_PncStateProcessing_008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_008
TEST.BASIS_PATH:8 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_REQUESTED
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.END

-- Test Case: ComM_PncStateProcessing_008.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_008.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_REQUESTED
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:Nm_PassiveStartUp
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[1].UserNotificationFn:Nm_PassiveStartUp
TEST.END

-- Test Case: ComM_PncStateProcessing_008.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_008.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_REQUESTED
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_NO_COMMUNICATION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:Nm_PassiveStartUp
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[1].UserNotificationFn:Nm_PassiveStartUp
TEST.END

-- Test Case: ComM_PncStateProcessing_008.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_008.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_REQUESTED
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:Nm_PassiveStartUp
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[1].UserNotificationFn:Nm_PassiveStartUp
TEST.END

-- Test Case: ComM_PncStateProcessing_008.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_008.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:COMM_PNC_REQUESTED
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MAX>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[0].UserNotificationFn:ComM_LimitECUToNoComMode
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[1].UserNotificationFn:Nm_NetworkRelease
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_UserConfig[2].UserNotificationFn:ComM_LimitECUToNoComMode
TEST.END

-- Test Case: ComM_PncStateProcessing_009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_009
TEST.BASIS_PATH:9 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_PncStateProcessing_010
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_010
TEST.BASIS_PATH:10 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:<<MAX>>
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_PncStateProcessing_011
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_011
TEST.BASIS_PATH:11 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:<<MIN>>
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_PncStateProcessing_012
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_012
TEST.BASIS_PATH:12 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_PncStateProcessing_012.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_012.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncStateFunctionListConfig[0].PncStateOnEntryActionFn:<<null>>
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncStateFunctionListConfig[1].PncStateOnEntryActionFn:<<null>>
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_PncStateProcessing_012.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_012.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncStateFunctionListConfig[0].PncStateOnEntryActionFn:<<null>>
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncStateFunctionListConfig[1].PncStateProcessorFn:ComM_PncNoCommunicationProcessor
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncStateFunctionListConfig[1].PncStateOnEntryActionFn:<<null>>
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_PncStateProcessing_013
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_013
TEST.BASIS_PATH:13 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:4
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_PncStateProcessing_014
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_014
TEST.BASIS_PATH:14 of 14 (partial)
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:4
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Test Case: ComM_PncStateProcessing_014.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PncStateProcessing
TEST.NEW
TEST.NAME:ComM_PncStateProcessing_014.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncNotifyStateChange:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_PncCurrentMode[0]:6
TEST.VALUE:ComM.ComM_PncStateProcessing.Channel:<<MIN>>
TEST.END

-- Subprogram: ComM_PreventWakeUp

-- Test Case: ComM_PreventWakeUp.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PreventWakeUp
TEST.NEW
TEST.NAME:ComM_PreventWakeUp.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.VALUE:ComM.ComM_PreventWakeUp.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.ComM_PreventWakeUp.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_PREVENTWAKEUP
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_PreventWakeUp.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PreventWakeUp
TEST.NEW
TEST.NAME:ComM_PreventWakeUp.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_PreventWakeUp.Channel:255
TEST.VALUE:ComM.ComM_PreventWakeUp.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_PreventWakeUp.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_PREVENTWAKEUP
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_PreventWakeUp.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PreventWakeUp
TEST.NEW
TEST.NAME:ComM_PreventWakeUp.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0
TEST.VALUE:ComM.ComM_PreventWakeUp.Channel:0
TEST.VALUE:ComM.ComM_PreventWakeUp.Status:TRUE
TEST.VALUE:ComM.ComM_PreventWakeUp.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:1
TEST.EXPECTED:ComM.ComM_PreventWakeUp.return:E_OK
TEST.END

-- Test Case: ComM_PreventWakeUp.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PreventWakeUp
TEST.NEW
TEST.NAME:ComM_PreventWakeUp.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0
TEST.VALUE:ComM.ComM_PreventWakeUp.Channel:0
TEST.VALUE:ComM.ComM_PreventWakeUp.Status:TRUE
TEST.VALUE:ComM.ComM_PreventWakeUp.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0
TEST.EXPECTED:ComM.ComM_PreventWakeUp.return:E_NOT_OK
TEST.END

-- Test Case: ComM_PreventWakeUp.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_PreventWakeUp
TEST.NEW
TEST.NAME:ComM_PreventWakeUp.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:1
TEST.VALUE:ComM.ComM_PreventWakeUp.Channel:0
TEST.VALUE:ComM.ComM_PreventWakeUp.Status:FALSE
TEST.VALUE:ComM.ComM_PreventWakeUp.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0
TEST.EXPECTED:ComM.ComM_PreventWakeUp.return:E_OK
TEST.END

-- Subprogram: ComM_ReadInhibitCounter

-- Test Case: ComM_ReadInhibitCounter.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_ReadInhibitCounter
TEST.NEW
TEST.NAME:ComM_ReadInhibitCounter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.VALUE:ComM.ComM_ReadInhibitCounter.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.ComM_ReadInhibitCounter.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_READINHIBITCOUNTER
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_ReadInhibitCounter.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_ReadInhibitCounter
TEST.NEW
TEST.NAME:ComM_ReadInhibitCounter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_ReadInhibitCounter.CounterValue:<<null>>
TEST.VALUE:ComM.ComM_ReadInhibitCounter.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_ReadInhibitCounter.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_READINHIBITCOUNTER
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_ReadInhibitCounter.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_ReadInhibitCounter
TEST.NEW
TEST.NAME:ComM_ReadInhibitCounter.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:10
TEST.VALUE:ComM.ComM_ReadInhibitCounter.CounterValue:<<malloc 1>>
TEST.VALUE:ComM.ComM_ReadInhibitCounter.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_ReadInhibitCounter.CounterValue[0]:10
TEST.EXPECTED:ComM.ComM_ReadInhibitCounter.return:E_OK
TEST.END

-- Subprogram: ComM_RequestComMode

-- Test Case: ComM_RequestComMode.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_REQUESTCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_RequestComMode.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_RequestComMode.User:0
TEST.VALUE:ComM.ComM_RequestComMode.ComMode:COMM_SILENT_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_REQUESTCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_RequestComMode.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_RequestComMode.User:255
TEST.VALUE:ComM.ComM_RequestComMode.ComMode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_REQUESTCOMMODE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_RequestComMode.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_RequestComMode.User:0
TEST.VALUE:ComM.ComM_RequestComMode.ComMode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_FULL_COMMUNICATION
TEST.END

-- Test Case: ComM_RequestComMode.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x0
TEST.VALUE:ComM.ComM_RequestComMode.User:0
TEST.VALUE:ComM.ComM_RequestComMode.ComMode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_FULL_COMMUNICATION
TEST.END

-- Test Case: ComM_RequestComMode.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:5
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_RequestComMode.User:0
TEST.VALUE:ComM.ComM_RequestComMode.ComMode:0
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_NO_COMMUNICATION
TEST.END

-- Test Case: ComM_RequestComMode.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:0xFFFF
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_RequestComMode.User:0
TEST.VALUE:ComM.ComM_RequestComMode.ComMode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x1
TEST.END

-- Test Case: ComM_RequestComMode.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelInhibitionEnabled
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:0xFFFF
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_RequestComMode.User:0
TEST.VALUE:ComM.ComM_RequestComMode.ComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.return:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x1
TEST.END

-- Test Case: ComM_RequestComMode.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_RequestComMode
TEST.NEW
TEST.NAME:ComM_RequestComMode.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_IsChannelInhibitionEnabled
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_NO_COMMUNICATION
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:0xFFF
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0x2
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].UsersToChannelMap[0]:0x1
TEST.VALUE:ComM.ComM_RequestComMode.User:0
TEST.VALUE:ComM.ComM_RequestComMode.ComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:ComM.ComM_IsChannelInhibitionEnabled.return:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_UserRequestedMode[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[0]:0x1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.ChannelInhibitionStatus[1]:0x1
TEST.END

-- Subprogram: ComM_ResetInhibitCounter

-- Test Case: ComM_ResetInhibitCounter.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_ResetInhibitCounter
TEST.NEW
TEST.NAME:ComM_ResetInhibitCounter.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_RESETINHIBITCOUNTER
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_ResetInhibitCounter.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_ResetInhibitCounter
TEST.NEW
TEST.NAME:ComM_ResetInhibitCounter.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:10
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.InhibitionCount:0
TEST.END

-- Subprogram: ComM_SetECUGroupClassification

-- Test Case: ComM_SetECUGroupClassification.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SetECUGroupClassification
TEST.NEW
TEST.NAME:ComM_SetECUGroupClassification.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_SETECUGROUPCLASSIFICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_NOT_INITED
TEST.END

-- Test Case: ComM_SetECUGroupClassification.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SetECUGroupClassification
TEST.NEW
TEST.NAME:ComM_SetECUGroupClassification.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.ComM_SetECUGroupClassification.Status:255
TEST.VALUE:ComM.ComM_SetECUGroupClassification.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.ComM_SetECUGroupClassification.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:COMM_SID_SETECUGROUPCLASSIFICATION
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:COMM_E_WRONG_PARAMETERS
TEST.END

-- Test Case: ComM_SetECUGroupClassification.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SetECUGroupClassification
TEST.NEW
TEST.NAME:ComM_SetECUGroupClassification.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.VALUE:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:0
TEST.VALUE:ComM.ComM_SetECUGroupClassification.Status:1
TEST.VALUE:ComM.ComM_SetECUGroupClassification.return:E_NOT_OK
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_InitStatus:COMM_INIT
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_Inhibition.EcuInhibitionStatus:1
TEST.EXPECTED:ComM.ComM_SetECUGroupClassification.return:E_OK
TEST.END

-- Subprogram: ComM_SilentCommunicationOnEntry

-- Test Case: ComM_SilentCommunicationOnEntry.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationOnEntry
TEST.NEW
TEST.NAME:ComM_SilentCommunicationOnEntry.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_SilentCommunicationOnEntry.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationOnEntry
TEST.NEW
TEST.NAME:ComM_SilentCommunicationOnEntry.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Test Case: ComM_SilentCommunicationOnEntry.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationOnEntry
TEST.NEW
TEST.NAME:ComM_SilentCommunicationOnEntry.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_SilentCommunicationOnEntry.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_SilentCommunicationOnEntry.Channel:0x5
TEST.END

-- Test Case: ComM_SilentCommunicationOnEntry.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationOnEntry
TEST.NEW
TEST.NAME:ComM_SilentCommunicationOnEntry.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_ChannelConfig[0].BusSMFnConfigId:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_BusSMComMModeFnConfig[0].CanSM_RequestComModeFn:ComM_RequestComMode
TEST.END

-- Subprogram: ComM_SilentCommunicationProcessor

-- Test Case: ComM_SilentCommunicationProcessor.001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.001
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.002
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.002
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_SilentCommunicationProcessor.Channel:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_SilentCommunicationProcessor.Channel:2
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.003
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.003
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.STUB:ComM.ComM_GetUserModeWithInhibitionCheck
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.Channel:0
TEST.VALUE:ComM.ComM_GetUserModeWithInhibitionCheck.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.004
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.004
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_DcmFullComRequest[0]:1
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.005
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.005
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:1
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.006
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.006
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.007
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.007
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.008
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.008
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:5
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.009
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.009
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:3
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.010
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.010
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.<<GLOBAL>>.ComM_BusNmRequestedState[0]:2
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.ComM_ChannelConfig[0].NmVariantType:3
TEST.END

-- Test Case: ComM_SilentCommunicationProcessor.011
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_SilentCommunicationProcessor
TEST.NEW
TEST.NAME:ComM_SilentCommunicationProcessor.011
TEST.NOTES:
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:ComM.ComM_SilentCommunicationProcessor.Channel:0x5
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:ComM.ComM_SilentCommunicationProcessor.Channel:0x5
TEST.END

-- Subprogram: ComM_UpdateEiraEraData

-- Test Case: BASIS-PATH-001
TEST.UNIT:ComM
TEST.SUBPROGRAM:ComM_UpdateEiraEraData
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
SoftwareArchitecture::COM::SERVICES::ComM::ComM_Detailed_Design::ComM_Class_Diagram
Requirement_DICVA-13785
TEST.END_NOTES:
TEST.END
