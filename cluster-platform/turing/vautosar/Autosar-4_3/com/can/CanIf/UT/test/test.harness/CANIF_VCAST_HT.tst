-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : CANIF_VCAST_HT
-- Unit(s) Under Test: CanIf
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CanIf

-- Subprogram: CanIf_AcceptanceFilter

-- Test Case: CanIf_AcceptanceFilter.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:255
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:FALSE
TEST.END

-- Test Case: CanIf_AcceptanceFilter.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_OFFLINE
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:FALSE
TEST.END

-- Test Case: CanIf_AcceptanceFilter.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_TRANSMIT
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId:<<malloc 1>>
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:FALSE
TEST.END

-- Test Case: CanIf_AcceptanceFilter.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:255
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId:<<malloc 1>>
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:FALSE
TEST.END

-- Test Case: CanIf_AcceptanceFilter.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:45
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId:<<malloc 1>>
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:FALSE
TEST.END

-- Test Case: CanIf_AcceptanceFilter.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:45
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:45
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:45
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:45
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:0
TEST.END

-- Test Case: CanIf_AcceptanceFilter.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[1].RxPduCanId:1
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:45
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[1].RxPduCanId:1
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:45
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:1
TEST.END

-- Test Case: CanIf_AcceptanceFilter.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:45
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[1].RxPduCanId:1
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:45
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId:<<malloc 1>>
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:TRUE
TEST.END

-- Test Case: CanIf_AcceptanceFilter.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:45
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:45
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:1
TEST.END

-- Test Case: CanIf_AcceptanceFilter.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_AcceptanceFilter
TEST.NEW
TEST.NAME:CanIf_AcceptanceFilter.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_RxMessageLinearSearch
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:45
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[1].RxPduCanId:1
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:45
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.return:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxPduCanId:45
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[1].RxPduCanId:1
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].CanId:45
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].Hoh:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.Mailbox[0].ControllerId:0
TEST.EXPECTED:CanIf.CanIf_AcceptanceFilter.return:0
TEST.END

-- Subprogram: CanIf_CancelTransmit

-- Test Case: CanIf_CancelTransmit.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CancelTransmit
TEST.NEW
TEST.NAME:CanIf_CancelTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:30
TEST.END

-- Test Case: CanIf_CancelTransmit.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CancelTransmit
TEST.NEW
TEST.NAME:CanIf_CancelTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_CancelTransmit.TxPduId:2
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:50
TEST.END

-- Test Case: CanIf_CancelTransmit.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CancelTransmit
TEST.NEW
TEST.NAME:CanIf_CancelTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_CancelTransmit.TxPduId:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_CancelTransmit.TxPduId:1
TEST.END

-- Subprogram: CanIf_CheckWakeup

-- Test Case: CanIf_CheckWakeup.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:30
TEST.END

-- Test Case: CanIf_CheckWakeup.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.END

-- Test Case: CanIf_CheckWakeup.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_ValidateCtrlId
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:10
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_CheckWakeup.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_ValidateCtrlId
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupSrcId:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:10
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupSrcId:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_CheckWakeup.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_ValidateCtrlId
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_SLEEP
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:10
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_CheckWakeup.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_ValidateCtrlId
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:2
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupTargetModuleConfig:CANIF_WAKEUPREQUEST_CAN
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_SLEEP
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:10
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:2
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_CheckWakeup.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_ValidateCtrlId
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupTargetModuleConfig:CANIF_WAKEUPREQUEST_CAN
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_SLEEP
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:10
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_CheckWakeup.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_ValidateCtrlId
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupTargetModuleConfig:CANIF_WAKEUPREQUEST_CAN
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_SLEEP
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:10
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_CheckWakeup.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_ValidateCtrlId
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:3
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[1].CanDrvFunctId:2
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupTargetModuleConfig:CANIF_WAKEUPREQUEST_CAN
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_SLEEP
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:10
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:1
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_CheckWakeup.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CheckWakeup
TEST.NEW
TEST.NAME:CanIf_CheckWakeup.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_ValidateCtrlId
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvWriteFunctPtr:test_CanTrcvWrite
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvCheckWakeupFunctPtr:CanDrvCheckWakeupFunct1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupTargetModuleConfig:CANIF_WAKEUPREQUEST_CAN
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_SLEEP
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:10
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_WakeUpConfig[0].WakeupCtrlId:10
TEST.END

-- Subprogram: CanIf_ControllerBusOff

-- Test Case: CanIf_ControllerBusOff.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerBusOff
TEST.NEW
TEST.NAME:CanIf_ControllerBusOff.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_ControllerBusOff.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_CONTROLLERBUSOFF_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.END

-- Test Case: CanIf_ControllerBusOff.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerBusOff
TEST.NEW
TEST.NAME:CanIf_ControllerBusOff.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_ControllerBusOff.ControllerId:255
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_CONTROLLERBUSOFF_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_CONTROLLERID
TEST.END

-- Test Case: CanIf_ControllerBusOff.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerBusOff
TEST.NEW
TEST.NAME:CanIf_ControllerBusOff.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerBusOff.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Test Case: CanIf_ControllerBusOff.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerBusOff
TEST.NEW
TEST.NAME:CanIf_ControllerBusOff.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_SetControllerMode
TEST.STUB:CanIf.CanIf_SetPduMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerBusOff.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_ControllerBusOff.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerBusOff
TEST.NEW
TEST.NAME:CanIf_ControllerBusOff.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_SetControllerMode
TEST.STUB:CanIf.CanIf_SetPduMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:CanIf_ControllerBusOff
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerBusOff.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_ControllerBusOff.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerBusOff
TEST.NEW
TEST.NAME:CanIf_ControllerBusOff.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_SetControllerMode
TEST.STUB:CanIf.CanIf_SetPduMode
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:CanIf_ControllerBusOff
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerBusOff.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_ControllerBusOff.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerBusOff
TEST.NEW
TEST.NAME:CanIf_ControllerBusOff.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_SetControllerMode
TEST.STUB:CanIf.CanIf_SetPduMode
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerBusOff.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: CanIf_ControllerModeIndication

-- Test Case: CanIf_ControllerModeIndication.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Test Case: CanIf_ControllerModeIndication.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_CONTROLLERMODEINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.END

-- Test Case: CanIf_ControllerModeIndication.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:255
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_CONTROLLERMODEINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_CONTROLLERID
TEST.END

-- Test Case: CanIf_ControllerModeIndication.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Test Case: CanIf_ControllerModeIndication.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerMode:255
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Test Case: CanIf_ControllerModeIndication.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Test Case: CanIf_ControllerModeIndication.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:CanIf_UpdateCurrentCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Test Case: CanIf_ControllerModeIndication.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:CanIf_UpdateCurrentCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_ControllerModeIndication.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_ControllerModeIndication.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_UpdateCurrentCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.VALUE:CanIf.CanIf_UpdateCurrentCtrlMode.CtrlMode:CAN_CS_STOPPED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_ControllerModeIndication.011
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ControllerModeIndication
TEST.NEW
TEST.NAME:CanIf_ControllerModeIndication.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_UpdateCurrentCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerModeIndicationFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserControllerBusOffFunctPtr:<<null>>
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserConfirmPnAvailabilityFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanIf.CanIf_ControllerModeIndication.ControllerMode:255
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.VALUE:CanIf.CanIf_UpdateCurrentCtrlMode.CtrlMode:CAN_CS_STOPPED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Subprogram: CanIf_CurrentIcomConfiguration

-- Test Case: CanIf_CurrentIcomConfiguration.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CurrentIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_CurrentIcomConfiguration.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:30
TEST.END

-- Test Case: CanIf_CurrentIcomConfiguration.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CurrentIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_CurrentIcomConfiguration.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_CurrentIcomConfiguration.ControllerId:3
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_CurrentIcomConfiguration.ControllerId:3
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:15
TEST.END

-- Test Case: CanIf_CurrentIcomConfiguration.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CurrentIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_CurrentIcomConfiguration.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_CurrentIcomConfiguration.ControllerId:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_CurrentIcomConfiguration.ControllerId:1
TEST.END

-- Test Case: CanIf_CurrentIcomConfiguration.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CurrentIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_CurrentIcomConfiguration.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_CurrentIcomConfiguration.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_CurrentIcomConfiguration.ControllerId:0
TEST.END

-- Test Case: CanIf_CurrentIcomConfiguration.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_CurrentIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_CurrentIcomConfiguration.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserCurrentIcomConfigurationFunctPtr:CanIf_CurrentIcomConfiguration_1
TEST.VALUE:CanIf.CanIf_CurrentIcomConfiguration.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_UserCallbackConfig.UserCurrentIcomConfigurationFunctPtr:CanIf_CurrentIcomConfiguration_1
TEST.EXPECTED:CanIf.CanIf_CurrentIcomConfiguration.ControllerId:0
TEST.END

-- Subprogram: CanIf_DeInit

-- Test Case: CanIf_DeInit.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_DeInit
TEST.NEW
TEST.NAME:CanIf_DeInit.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.END

-- Subprogram: CanIf_Det_ReportError

-- Test Case: CanIf_Det_ReportError.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Det_ReportError
TEST.NEW
TEST.NAME:CanIf_Det_ReportError.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.CanIf_Det_ReportError.ApiId:CANIF_RXINDICATION_API
TEST.VALUE:CanIf.CanIf_Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ModuleId:CANIF_MODULE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.InstanceId:CANIF_INSTANCE_ID
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.END

-- Subprogram: CanIf_GetCanIdentifier

-- Test Case: CanIf_GetCanIdentifier.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCanIdentifier
TEST.NEW
TEST.NAME:CanIf_GetCanIdentifier.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_GetCanIdentifier.CanIfTxSduId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_GetCanIdentifier.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCanIdentifier
TEST.NEW
TEST.NAME:CanIf_GetCanIdentifier.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN
TEST.VALUE:CanIf.CanIf_GetCanIdentifier.CanIfTxSduId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_GetCanIdentifier.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCanIdentifier
TEST.NEW
TEST.NAME:CanIf_GetCanIdentifier.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:1
TEST.VALUE:CanIf.CanIf_GetCanIdentifier.CanIfTxSduId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_GetCanIdentifier.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCanIdentifier
TEST.NEW
TEST.NAME:CanIf_GetCanIdentifier.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN
TEST.VALUE:CanIf.CanIf_GetCanIdentifier.CanIfTxSduId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_GetCanIdentifier.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCanIdentifier
TEST.NEW
TEST.NAME:CanIf_GetCanIdentifier.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN
TEST.VALUE:CanIf.CanIf_GetCanIdentifier.CanIfTxSduId:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_GetCanIdentifier.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCanIdentifier
TEST.NEW
TEST.NAME:CanIf_GetCanIdentifier.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN
TEST.VALUE:CanIf.CanIf_GetCanIdentifier.CanIfTxSduId:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_GetCanIdentifier.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCanIdentifier
TEST.NEW
TEST.NAME:CanIf_GetCanIdentifier.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_DynamicPduConfig[0].CanId:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_DynamicPduConfig[0].CanIfTxSduId:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_DynamicPduConfig[0].ReconfiguredSts:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_STANDARD_FD_CAN
TEST.VALUE:CanIf.CanIf_GetCanIdentifier.CanIfTxSduId:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_DynamicPduConfig[0].CanId:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_DynamicPduConfig[0].CanIfTxSduId:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_DynamicPduConfig[0].ReconfiguredSts:1
TEST.END

-- Subprogram: CanIf_GetControllerErrorState

-- Test Case: CanIf_GetControllerErrorState.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerErrorState
TEST.NEW
TEST.NAME:CanIf_GetControllerErrorState.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:30
TEST.END

-- Test Case: CanIf_GetControllerErrorState.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerErrorState
TEST.NEW
TEST.NAME:CanIf_GetControllerErrorState.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ControllerId:2
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:15
TEST.END

-- Test Case: CanIf_GetControllerErrorState.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerErrorState
TEST.NEW
TEST.NAME:CanIf_GetControllerErrorState.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ErrorStatePtr:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.END

-- Test Case: CanIf_GetControllerErrorState.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerErrorState
TEST.NEW
TEST.NAME:CanIf_GetControllerErrorState.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ErrorStatePtr:<<null>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.END

-- Test Case: CanIf_GetControllerErrorState.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerErrorState
TEST.NEW
TEST.NAME:CanIf_GetControllerErrorState.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:2
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ErrorStatePtr:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:2
TEST.EXPECTED:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.END

-- Test Case: CanIf_GetControllerErrorState.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerErrorState
TEST.NEW
TEST.NAME:CanIf_GetControllerErrorState.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[1].CanDrvFunctId:2
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ErrorStatePtr:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[1].CanDrvFunctId:2
TEST.EXPECTED:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.END

-- Test Case: CanIf_GetControllerErrorState.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerErrorState
TEST.NEW
TEST.NAME:CanIf_GetControllerErrorState.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanGetCtrlErrorStateFunctPtr:CanIf_GetControllerErrorState_1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:2
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.VALUE:CanIf.CanIf_GetControllerErrorState.ErrorStatePtr:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:2
TEST.EXPECTED:CanIf.CanIf_GetControllerErrorState.ControllerId:1
TEST.END

-- Subprogram: CanIf_GetControllerMode

-- Test Case: CanIf_GetControllerMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerMode
TEST.NEW
TEST.NAME:CanIf_GetControllerMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_TX_OFFLINE
TEST.VALUE:CanIf.CanIf_GetControllerMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetControllerMode.ControllerModePtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_GetControllerMode.return:E_OK
TEST.END

-- Test Case: CanIf_GetControllerMode.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerMode
TEST.NEW
TEST.NAME:CanIf_GetControllerMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_TX_OFFLINE
TEST.VALUE:CanIf.CanIf_GetControllerMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetControllerMode.ControllerModePtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.EXPECTED:CanIf.CanIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_GETCONTROLLERMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.END

-- Test Case: CanIf_GetControllerMode.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerMode
TEST.NEW
TEST.NAME:CanIf_GetControllerMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_TX_OFFLINE
TEST.VALUE:CanIf.CanIf_GetControllerMode.ControllerId:255
TEST.VALUE:CanIf.CanIf_GetControllerMode.ControllerModePtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_GETCONTROLLERMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_CONTROLLERID
TEST.END

-- Test Case: CanIf_GetControllerMode.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetControllerMode
TEST.NEW
TEST.NAME:CanIf_GetControllerMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_TX_OFFLINE
TEST.VALUE:CanIf.CanIf_GetControllerMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetControllerMode.ControllerModePtr:<<null>>
TEST.VALUE:CanIf.CanIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_GetControllerMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_GETCONTROLLERMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_CTRLMODE
TEST.END

-- Subprogram: CanIf_GetCtrlId

-- Test Case: CanIf_GetCtrlId.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCtrlId
TEST.NEW
TEST.NAME:CanIf_GetCtrlId.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_GetCtrlId.CanTxPduId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_GetCtrlId.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCtrlId
TEST.NEW
TEST.NAME:CanIf_GetCtrlId.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:255
TEST.VALUE:CanIf.CanIf_GetCtrlId.CanTxPduId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanIf_GetCurrentCtrlMode

-- Test Case: CanIf_GetCurrentCtrlMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCurrentCtrlMode
TEST.NEW
TEST.NAME:CanIf_GetCurrentCtrlMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.CtrlId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanIf_GetCurrentPduMode

-- Test Case: CanIf_GetCurrentPduMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetCurrentPduMode
TEST.NEW
TEST.NAME:CanIf_GetCurrentPduMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.CtrlId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanIf_GetPduLength

-- Test Case: CanIf_GetPduLength.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetPduLength
TEST.NEW
TEST.NAME:CanIf_GetPduLength.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_GetPduLength.CanIfTxSduId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_GetPduLength.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetPduLength
TEST.NEW
TEST.NAME:CanIf_GetPduLength.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_GetPduLength.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_GetPduLength.CanIfTxInfoPtr:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanIf_GetPduMode

-- Test Case: CanIf_GetPduMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetPduMode
TEST.NEW
TEST.NAME:CanIf_GetPduMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_GetPduMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetPduMode.PduModePtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_GetPduMode.PduModePtr[0]:CANIF_OFFLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_GetPduMode.PduModePtr[0]:CANIF_ONLINE
TEST.END

-- Test Case: CanIf_GetPduMode.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetPduMode
TEST.NEW
TEST.NAME:CanIf_GetPduMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_GetPduMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetPduMode.PduModePtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_GetPduMode.PduModePtr[0]:CANIF_OFFLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_GETPDUMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.END

-- Test Case: CanIf_GetPduMode.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetPduMode
TEST.NEW
TEST.NAME:CanIf_GetPduMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_GetPduMode.ControllerId:255
TEST.VALUE:CanIf.CanIf_GetPduMode.PduModePtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_GetPduMode.PduModePtr[0]:CANIF_OFFLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_GETPDUMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_CONTROLLERID
TEST.END

-- Test Case: CanIf_GetPduMode.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_GetPduMode
TEST.NEW
TEST.NAME:CanIf_GetPduMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_GetPduMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_GetPduMode.PduModePtr:<<null>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_GETPDUMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_POINTER
TEST.END

-- Subprogram: CanIf_Init

-- Test Case: CanIf_Init.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Init
TEST.NEW
TEST.NAME:CanIf_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_OFFLINE
TEST.VALUE:CanIf.CanIf_Init.ConfigPtr:<<null>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_OFFLINE
TEST.EXPECTED:CanIf.CanIf_Init.ConfigPtr:<<null>>
TEST.END

-- Test Case: CanIf_Init.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Init
TEST.NEW
TEST.NAME:CanIf_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.CanIf_Init.ConfigPtr:<<null>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_Init.ConfigPtr:<<null>>
TEST.END

-- Test Case: CanIf_Init.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Init
TEST.NEW
TEST.NAME:CanIf_Init.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:1
TEST.VALUE:CanIf.CanIf_Init.ConfigPtr:<<null>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:1
TEST.EXPECTED:CanIf.CanIf_Init.ConfigPtr:<<null>>
TEST.END

-- Subprogram: CanIf_InitiateTransfer

-- Test Case: CanIf_InitiateTransfer.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:255
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<null>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_InitiateTransfer.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<null>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_InitiateTransfer.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:255
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_InitiateTransfer.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_InitiateTransfer.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_InitiateTransfer.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_WritePdu
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduLength:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_InitiateTransfer.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_InitiateTransfer.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:2
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:2
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_InitiateTransfer.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:3
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_InitiateTransfer.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_InitiateTransfer
TEST.NEW
TEST.NAME:CanIf_InitiateTransfer.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:1
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 2>>
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduDataPtr:"1"
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanIf_RxGetCanIdMask

-- Test Case: CanIf_RxGetCanIdMask.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxGetCanIdMask
TEST.NEW
TEST.NAME:CanIf_RxGetCanIdMask.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.EXPECTED:CanIf.CanIf_RxGetCanIdMask.CanIf_RxCanIdMaskIdx:0
TEST.END

-- Test Case: CanIf_RxGetCanIdMask.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxGetCanIdMask
TEST.NEW
TEST.NAME:CanIf_RxGetCanIdMask.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.CanIf_RxGetCanIdMask.CanIf_RxCanIdMaskIdx:3
TEST.EXPECTED:CanIf.CanIf_RxGetCanIdMask.CanIf_RxCanIdMaskIdx:3
TEST.END

-- Subprogram: CanIf_RxIndication

-- Test Case: CanIf_RxIndication.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.END

-- Test Case: CanIf_RxIndication.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<null>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<null>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_POINTER
TEST.END

-- Test Case: CanIf_RxIndication.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[1].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x1E360000
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:35
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:1
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<null>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_RXINDICATION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_POINTER
TEST.END

-- Test Case: CanIf_RxIndication.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:CANIF_CANID_TYPE_STANDARD
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr[0]:22
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduLength:65
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Test Case: CanIf_RxIndication.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:CANIF_CANID_TYPE_STANDARD
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0x64
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr[0]:22
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduLength:4
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Test Case: CanIf_RxIndication.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_AcceptanceFilter
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:CANIF_CANID_TYPE_STANDARD
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr[0]:22
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduLength:4
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.return:2
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_RxIndication.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_AcceptanceFilter
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:CANIF_CANID_TYPE_STANDARD
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr[0]:22
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduLength:9
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.CtrlId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_RxIndication.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_AcceptanceFilter
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:CANIF_CANID_TYPE_STANDARD
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr[0]:22
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduLength:9
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.CtrlId:0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_SLEEP
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_RxIndication.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_AcceptanceFilter
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:CANIF_CANID_TYPE_STANDARD
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr[0]:22
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduLength:9
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.CtrlId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.CanIfRxPduId[0]:5
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_RxIndication.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_AcceptanceFilter
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:CANIF_CANID_TYPE_STANDARD
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxNotificationFunctId:4
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr[0]:22
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduLength:9
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.CtrlId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_RxPduIdConfig[0].RxNotificationFunctId:4
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_RxIndication.011
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxIndication
TEST.NEW
TEST.NAME:CanIf_RxIndication.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_AcceptanceFilter
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduStartId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].PduEndId:26
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:CANIF_CANID_TYPE_STANDARD
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanControllerId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanObjectType:CANIF_CAN_OBJECT_TYPE_RECEIVE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_RxNotificationFunctConfig[0]:pCanIfRxIndicationFunc1
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].CanId:0x5E2
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].Hoh:0
TEST.VALUE:CanIf.CanIf_RxIndication.Mailbox[0].ControllerId:0
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduDataPtr[0]:22
TEST.VALUE:CanIf.CanIf_RxIndication.PduInfoPtr[0].SduLength:9
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.CtrlId:0
TEST.VALUE:CanIf.CanIf_AcceptanceFilter.return:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.END

-- Subprogram: CanIf_RxMessageLinearSearch

-- Test Case: CanIf_RxMessageLinearSearch.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxMessageLinearSearch
TEST.NEW
TEST.NAME:CanIf_RxMessageLinearSearch.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxStartPduId:0
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxEndPduId:2
TEST.EXPECTED:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxStartPduId:0
TEST.EXPECTED:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxEndPduId:2
TEST.END

-- Test Case: CanIf_RxMessageLinearSearch.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxMessageLinearSearch
TEST.NEW
TEST.NAME:CanIf_RxMessageLinearSearch.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxStartPduId:0
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxEndPduId:0
TEST.EXPECTED:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxStartPduId:0
TEST.EXPECTED:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxEndPduId:0
TEST.END

-- Test Case: CanIf_RxMessageLinearSearch.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_RxMessageLinearSearch
TEST.NEW
TEST.NAME:CanIf_RxMessageLinearSearch.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_RxGetCanIdMask
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxStartPduId:0
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxEndPduId:0
TEST.VALUE:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RcvdCanId:3
TEST.VALUE:CanIf.CanIf_RxGetCanIdMask.return:1
TEST.EXPECTED:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxStartPduId:0
TEST.EXPECTED:CanIf.CanIf_RxMessageLinearSearch.pRxSearchParam[0].RxEndPduId:0
TEST.END

-- Subprogram: CanIf_SetBaudrate

-- Test Case: CanIf_SetBaudrate.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetBaudrate
TEST.NEW
TEST.NAME:CanIf_SetBaudrate.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:30
TEST.END

-- Test Case: CanIf_SetBaudrate.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetBaudrate
TEST.NEW
TEST.NAME:CanIf_SetBaudrate.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_SetBaudrate.ControllerId:2
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:15
TEST.END

-- Test Case: CanIf_SetBaudrate.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetBaudrate
TEST.NEW
TEST.NAME:CanIf_SetBaudrate.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_SetBaudrate.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.END

-- Test Case: CanIf_SetBaudrate.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetBaudrate
TEST.NEW
TEST.NAME:CanIf_SetBaudrate.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:2
TEST.VALUE:CanIf.CanIf_SetBaudrate.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:2
TEST.END

-- Test Case: CanIf_SetBaudrate.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetBaudrate
TEST.NEW
TEST.NAME:CanIf_SetBaudrate.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram 
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetBaudrateFunctPtr:CanIf_SetBaudrate_1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetIcomConfigurationFunctPtr:CanIf_SetIcomConfiguration
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanGetCtrlErrorStateFunctPtr:CanIf_GetControllerErrorState
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanGetControllerModeFunctPtr:CanIf_GetControllerMode
TEST.VALUE:CanIf.CanIf_SetBaudrate.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetBaudrateFunctPtr:CanIf_SetBaudrate_1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetIcomConfigurationFunctPtr:CanIf_SetIcomConfiguration
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanGetCtrlErrorStateFunctPtr:CanIf_GetControllerErrorState
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanGetControllerModeFunctPtr:CanIf_GetControllerMode
TEST.EXPECTED:CanIf.CanIf_SetBaudrate.ControllerId:0
TEST.END

-- Subprogram: CanIf_SetCanCtrlMode

-- Test Case: CanIf_SetCanCtrlMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetCanCtrlMode
TEST.NEW
TEST.NAME:CanIf_SetCanCtrlMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_SetCanCtrlMode.ControllerId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_SetCanCtrlMode.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetCanCtrlMode
TEST.NEW
TEST.NAME:CanIf_SetCanCtrlMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:255
TEST.VALUE:CanIf.CanIf_SetCanCtrlMode.ControllerId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_SetCanCtrlMode.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetCanCtrlMode
TEST.NEW
TEST.NAME:CanIf_SetCanCtrlMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:0
TEST.VALUE:CanIf.CanIf_SetCanCtrlMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_SetCanCtrlMode.ControllerMode:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_SetCanCtrlMode.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetCanCtrlMode
TEST.NEW
TEST.NAME:CanIf_SetCanCtrlMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetControllerModeFunctPtr:test_CanDrvSetControllerModeFunctPtr1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanGetControllerModeFunctPtr:CanIf_GetControllerMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:0
TEST.VALUE:CanIf.CanIf_SetCanCtrlMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_SetCanCtrlMode.ControllerMode:CAN_CS_STOPPED
TEST.VALUE:CanIf.CanIf_SetCanCtrlMode.return:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanIf_SetControllerMode

-- Test Case: CanIf_SetControllerMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x0
TEST.END

-- Test Case: CanIf_SetControllerMode.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.END

-- Test Case: CanIf_SetControllerMode.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.CanIf_SetControllerMode.ControllerId:0x3
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.CanIf_SetControllerMode.ControllerId:0x3
TEST.END

-- Test Case: CanIf_SetControllerMode.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.END

-- Test Case: CanIf_SetControllerMode.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.END

-- Test Case: CanIf_SetControllerMode.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.END

-- Test Case: CanIf_SetControllerMode.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_SetCanCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_RxIndication.Mailbox[0].CanId:INPUT_BASE=16
TEST.END

-- Test Case: CanIf_SetControllerMode.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_SetCanCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.CanIf_SetControllerMode.ControllerMode:CAN_CS_STOPPED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_RxIndication.Mailbox[0].CanId:INPUT_BASE=16
TEST.END

-- Test Case: CanIf_SetControllerMode.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_SetCanCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.CanIf_SetControllerMode.ControllerMode:CAN_CS_SLEEP
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_RxIndication.Mailbox[0].CanId:INPUT_BASE=16
TEST.END

-- Test Case: CanIf_SetControllerMode.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_SetCanCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.CanIf_SetControllerMode.ControllerMode:CAN_CS_STARTED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_RxIndication.Mailbox[0].CanId:INPUT_BASE=16
TEST.END

-- Test Case: CanIf_SetControllerMode.011
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetControllerMode
TEST.NEW
TEST.NAME:CanIf_SetControllerMode.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_SetCanCtrlMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.CanIf_SetControllerMode.ControllerMode:CAN_CS_STARTED
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.END

-- Subprogram: CanIf_SetDynamicTxId

-- Test Case: CanIf_SetDynamicTxId.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:30
TEST.END

-- Test Case: CanIf_SetDynamicTxId.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:2
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:2
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:50
TEST.END

-- Test Case: CanIf_SetDynamicTxId.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.END

-- Test Case: CanIf_SetDynamicTxId.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:1
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:1
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.END

-- Test Case: CanIf_SetDynamicTxId.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:2
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:2
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.END

-- Test Case: CanIf_SetDynamicTxId.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxCanIdMaskIdx:2
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxCanIdMaskIdx:2
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.END

-- Test Case: CanIf_SetDynamicTxId.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:1
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:1
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.END

-- Test Case: CanIf_SetDynamicTxId.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:0
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanId:0x8FF
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:0
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.END

-- Test Case: CanIf_SetDynamicTxId.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:1
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanId:0x3FFFFFFF
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:1
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.END

-- Test Case: CanIf_SetDynamicTxId.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetDynamicTxId
TEST.NEW
TEST.NAME:CanIf_SetDynamicTxId.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_DynamicPduConfig[0].CanIfTxSduId:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:1
TEST.VALUE:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_DynamicPduConfig[0].CanIfTxSduId:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanIdType:1
TEST.EXPECTED:CanIf.CanIf_SetDynamicTxId.CanIfTxSduId:0
TEST.END

-- Subprogram: CanIf_SetIcomConfiguration

-- Test Case: CanIf_SetIcomConfiguration.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_SetIcomConfiguration.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:30
TEST.END

-- Test Case: CanIf_SetIcomConfiguration.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_SetIcomConfiguration.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_SetIcomConfiguration.ControllerId:2
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_SetIcomConfiguration.ControllerId:2
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:15
TEST.END

-- Test Case: CanIf_SetIcomConfiguration.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_SetIcomConfiguration.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_SetIcomConfiguration.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_SetIcomConfiguration.ControllerId:0
TEST.END

-- Test Case: CanIf_SetIcomConfiguration.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_SetIcomConfiguration.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:1
TEST.VALUE:CanIf.CanIf_SetIcomConfiguration.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:1
TEST.EXPECTED:CanIf.CanIf_SetIcomConfiguration.ControllerId:0
TEST.END

-- Test Case: CanIf_SetIcomConfiguration.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_SetIcomConfiguration.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetIcomConfigurationFunctPtr:CanIf_SetIcomConfiguration_1
TEST.VALUE:CanIf.CanIf_SetIcomConfiguration.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetIcomConfigurationFunctPtr:CanIf_SetIcomConfiguration_1
TEST.EXPECTED:CanIf.CanIf_SetIcomConfiguration.ControllerId:0
TEST.END

-- Test Case: CanIf_SetIcomConfiguration.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetIcomConfiguration
TEST.NEW
TEST.NAME:CanIf_SetIcomConfiguration.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetIcomConfigurationFunctPtr:<<null>>
TEST.VALUE:CanIf.CanIf_SetIcomConfiguration.ControllerId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvSetIcomConfigurationFunctPtr:<<null>>
TEST.EXPECTED:CanIf.CanIf_SetIcomConfiguration.ControllerId:0
TEST.END

-- Subprogram: CanIf_SetPduMode

-- Test Case: CanIf_SetPduMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetPduMode
TEST.NEW
TEST.NAME:CanIf_SetPduMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_OFFLINE
TEST.VALUE:CanIf.CanIf_SetPduMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_SetPduMode.PduModeRequest:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_SetPduMode.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_SetPduMode.PduModeRequest:CANIF_ONLINE
TEST.EXPECTED:CanIf.CanIf_SetPduMode.return:E_OK
TEST.END

-- Test Case: CanIf_SetPduMode.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetPduMode
TEST.NEW
TEST.NAME:CanIf_SetPduMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_OFFLINE
TEST.VALUE:CanIf.CanIf_SetPduMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_SetPduMode.PduModeRequest:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_SetPduMode.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.EXPECTED:CanIf.CanIf_SetPduMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_SETPDUMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.END

-- Test Case: CanIf_SetPduMode.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetPduMode
TEST.NEW
TEST.NAME:CanIf_SetPduMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_OFFLINE
TEST.VALUE:CanIf.CanIf_SetPduMode.ControllerId:255
TEST.VALUE:CanIf.CanIf_SetPduMode.PduModeRequest:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_SetPduMode.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_SetPduMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_SETPDUMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_CONTROLLERID
TEST.END

-- Test Case: CanIf_SetPduMode.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_SetPduMode
TEST.NEW
TEST.NAME:CanIf_SetPduMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_OFFLINE
TEST.VALUE:CanIf.CanIf_SetPduMode.ControllerId:0
TEST.VALUE:CanIf.CanIf_SetPduMode.PduModeRequest:255
TEST.VALUE:CanIf.CanIf_SetPduMode.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_SetPduMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_SETPDUMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_PDU_MODE
TEST.END

-- Subprogram: CanIf_Transmit

-- Test Case: CanIf_Transmit.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722

TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:1
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:FALSE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_TRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_UNINIT
TEST.END

-- Test Case: CanIf_Transmit.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:255
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_TRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_INVALID_TXPDUID
TEST.END

-- Test Case: CanIf_Transmit.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:1
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<null>>
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANIF_TRANSMIT_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANIF_E_PARAM_POINTER
TEST.END

-- Test Case: CanIf_Transmit.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0x18DDF285
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduLength:64
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:11
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:53
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:CANIF_TX_PDU_TYPE_STATIC
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:1
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanIf_Transmit.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_OFFLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0x18DDF285
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduLength:64
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:11
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:53
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:CANIF_TX_PDU_TYPE_STATIC
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:1
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanIf_Transmit.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0x1E340032
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduLength:2
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:49
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:3
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:CANIF_TX_PDU_TYPE_STATIC
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:1
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanIf_Transmit.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:4
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanIf_Transmit.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_FULL_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:4
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanIf_Transmit.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:4
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.END

-- Test Case: CanIf_Transmit.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentPduMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0x18DDF285
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduLength:64
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0xB
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:53
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanIdType:CANIF_TX_PDU_CAN_ID_TYPE_EXTENDED_FD_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduType:CANIF_TX_PDU_TYPE_STATIC
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:1
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.return:CANIF_TX_OFFLINE_ACTIVE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.EXPECTED:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_Transmit.011
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_InitiateTransfer
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0x0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x4
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x4
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:CanIf.CanIf_Transmit.return:1
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_Transmit.012
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_InitiateTransfer
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0x0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x4
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x4
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:8
TEST.EXPECTED:CanIf.CanIf_Transmit.return:0
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_Transmit.013
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.013
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_InitiateTransfer
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0x0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduLength:6
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x4
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:0
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:2
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduLength:6
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x4
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:0
TEST.EXPECTED:CanIf.CanIf_Transmit.return:0
TEST.EXPECTED:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_Transmit.014
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_Transmit
TEST.NEW
TEST.NAME:CanIf_Transmit.014
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_InitiateTransfer
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:TRUE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:CANIF_CAN_HANDLE_TYPE_BASIC_CAN
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0x0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduLength:6
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x4
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr:<<malloc 1>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:<<malloc 3>>
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.VALUE:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:0
TEST.VALUE:CanIf.CanIf_Transmit.return:E_NOT_OK
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.VALUE:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:2
TEST.VALUE:CanIf.CanIf_InitiateTransfer.return:CAN_BUSY
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_CtrlInfo[0].CurrentPduMode:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_MailBoxConfig[0].CanHandleType:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduLength:6
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x4
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduHTHId:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxSduId:0
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduDataPtr:"01"
TEST.EXPECTED:CanIf.CanIf_Transmit.CanIfTxInfoPtr[0].SduLength:0
TEST.EXPECTED:CanIf.CanIf_Transmit.return:1
TEST.EXPECTED:CanIf.CanIf_InitiateTransfer.CanIfTxSduId:0
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: CanIf_TriggerTransmit

-- Test Case: CanIf_TriggerTransmit.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TriggerTransmit
TEST.NEW
TEST.NAME:CanIf_TriggerTransmit.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:30
TEST.END

-- Test Case: CanIf_TriggerTransmit.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TriggerTransmit
TEST.NEW
TEST.NAME:CanIf_TriggerTransmit.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_TriggerTransmit.TxPduId:2
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_TriggerTransmit.TxPduId:2
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:50
TEST.END

-- Test Case: CanIf_TriggerTransmit.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TriggerTransmit
TEST.NEW
TEST.NAME:CanIf_TriggerTransmit.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_TriggerTransmit.TxPduId:0
TEST.VALUE:CanIf.CanIf_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_TriggerTransmit.TxPduId:0
TEST.END

-- Test Case: CanIf_TriggerTransmit.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TriggerTransmit
TEST.NEW
TEST.NAME:CanIf_TriggerTransmit.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxTriggerTransmitFunctId:1
TEST.VALUE:CanIf.CanIf_TriggerTransmit.TxPduId:0
TEST.VALUE:CanIf.CanIf_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxTriggerTransmitFunctId:1
TEST.EXPECTED:CanIf.CanIf_TriggerTransmit.TxPduId:0
TEST.END

-- Test Case: CanIf_TriggerTransmit.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TriggerTransmit
TEST.NEW
TEST.NAME:CanIf_TriggerTransmit.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxTriggerTransmitFunctConfig[0]:CanIf_TriggerTransmit_1
TEST.VALUE:CanIf.CanIf_TriggerTransmit.TxPduId:0
TEST.VALUE:CanIf.CanIf_TriggerTransmit.PduInfoPtr:<<malloc 1>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxTriggerTransmitFunctConfig[0]:CanIf_TriggerTransmit_1
TEST.EXPECTED:CanIf.CanIf_TriggerTransmit.TxPduId:0
TEST.END

-- Test Case: CanIf_TriggerTransmit.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TriggerTransmit
TEST.NEW
TEST.NAME:CanIf_TriggerTransmit.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.VALUE:CanIf.CanIf_TriggerTransmit.TxPduId:0
TEST.VALUE:CanIf.CanIf_TriggerTransmit.PduInfoPtr:<<null>>
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:1
TEST.EXPECTED:CanIf.CanIf_TriggerTransmit.TxPduId:0
TEST.EXPECTED:CanIf.CanIf_TriggerTransmit.PduInfoPtr:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:20
TEST.END

-- Subprogram: CanIf_TxConfirmation

-- Test Case: CanIf_TxConfirmation.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0
TEST.END

-- Test Case: CanIf_TxConfirmation.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.END

-- Test Case: CanIf_TxConfirmation.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.CanIf_TxConfirmation.CanTxPduId:0x45
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0x45
TEST.END

-- Test Case: CanIf_TxConfirmation.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCtrlId
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_GetCurrentPduMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.return:CANIF_ONLINE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:INPUT_BASE=16
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_TxConfirmation.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCtrlId
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_GetCurrentPduMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.return:CANIF_TX_OFFLINE_ACTIVE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxPduCanId:INPUT_BASE=16
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_TxConfirmation.006
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCtrlId
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_GetCurrentPduMode
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0x2
TEST.VALUE:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.return:CANIF_TX_OFFLINE_ACTIVE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:0x2
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.END

-- Test Case: CanIf_TxConfirmation.007
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCtrlId
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_GetCurrentPduMode
TEST.STUB:CanIf.CanIf_Det_ReportError
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x0
TEST.VALUE:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.return:CANIF_TX_OFFLINE_ACTIVE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x0
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.END

-- Test Case: CanIf_TxConfirmation.008
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCtrlId
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_GetCurrentPduMode
TEST.STUB:CanIf.CanIf_Det_ReportError
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x0
TEST.VALUE:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STOPPED
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.return:CANIF_TX_OFFLINE_ACTIVE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x0
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.END

-- Test Case: CanIf_TxConfirmation.009
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCtrlId
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_GetCurrentPduMode
TEST.STUB:CanIf.CanIf_Det_ReportError
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x0
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:4
TEST.VALUE:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STOPPED
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.return:CANIF_TX_OFFLINE_ACTIVE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x0
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].TxConfirmationFunctId:4
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.END

-- Test Case: CanIf_TxConfirmation.010
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_TxConfirmation
TEST.NEW
TEST.NAME:CanIf_TxConfirmation.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCtrlId
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.STUB:CanIf.CanIf_GetCurrentPduMode
TEST.STUB:CanIf.CanIf_Det_ReportError
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxConfirmationFunctConfig[0]:test_CanIf_TxConfirmationFunctConfig1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x0
TEST.VALUE:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STOPPED
TEST.VALUE:CanIf.CanIf_GetCurrentPduMode.return:CANIF_TX_OFFLINE_ACTIVE
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_InitStatus:0x1
TEST.EXPECTED:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:0x0
TEST.EXPECTED:CanIf.CanIf_TxConfirmation.CanTxPduId:0x0
TEST.END

-- Subprogram: CanIf_UpdateCurrentCtrlMode

-- Test Case: CanIf_UpdateCurrentCtrlMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_UpdateCurrentCtrlMode
TEST.NEW
TEST.NAME:CanIf_UpdateCurrentCtrlMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_UpdateCurrentCtrlMode.CtrlId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_UpdateCurrentCtrlMode.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_UpdateCurrentCtrlMode
TEST.NEW
TEST.NAME:CanIf_UpdateCurrentCtrlMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_UpdateCurrentCtrlMode.CtrlId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanIf.CanIf_UpdateCurrentCtrlMode.CtrlId:0
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: CanIf_UpdateCurrentPduMode

-- Test Case: CanIf_UpdateCurrentPduMode.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_UpdateCurrentPduMode
TEST.NEW
TEST.NAME:CanIf_UpdateCurrentPduMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_UpdateCurrentPduMode.CtrlId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanIf_ValidateCtrlId

-- Test Case: CanIf_ValidateCtrlId.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ValidateCtrlId
TEST.NEW
TEST.NAME:CanIf_ValidateCtrlId.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_ValidateCtrlId.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ValidateCtrlId
TEST.NEW
TEST.NAME:CanIf_ValidateCtrlId.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_ValidateCtrlId.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ValidateCtrlId
TEST.NEW
TEST.NAME:CanIf_ValidateCtrlId.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.CtrlId:2
TEST.VALUE:CanIf.CanIf_ValidateCtrlId.CtrlId:2
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ErrorId:0xFF
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_ValidateCtrlId.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ValidateCtrlId
TEST.NEW
TEST.NAME:CanIf_ValidateCtrlId.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: CanIf_ValidateCtrlId.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_ValidateCtrlId
TEST.NEW
TEST.NAME:CanIf_ValidateCtrlId.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.STUB:CanIf.CanIf_GetCurrentCtrlMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_GetCurrentCtrlMode.return:CAN_CS_STARTED
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: CanIf_WritePdu

-- Test Case: CanIf_WritePdu.001
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_WritePdu
TEST.NEW
TEST.NAME:CanIf_WritePdu.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.CanIf_WritePdu.CtrlId:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_WritePdu.002
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_WritePdu
TEST.NEW
TEST.NAME:CanIf_WritePdu.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:255
TEST.VALUE:CanIf.CanIf_WritePdu.CtrlId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_WritePdu.003
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_WritePdu
TEST.NEW
TEST.NAME:CanIf_WritePdu.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:0
TEST.VALUE:CanIf.CanIf_WritePdu.CtrlId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_WritePdu.004
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_WritePdu
TEST.NEW
TEST.NAME:CanIf_WritePdu.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:0
TEST.VALUE:CanIf.CanIf_WritePdu.CtrlId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanIf_WritePdu.005
TEST.UNIT:CanIf
TEST.SUBPROGRAM:CanIf_WritePdu
TEST.NEW
TEST.NAME:CanIf_WritePdu.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanIf::CANIF_DETAILED_DESIGN::CanIf_ClassDiagram
Requirement_DICVA-13722
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CanDrvFunctConfig[0].CanDrvWriteFunctPtr:CanDrvWriteFunctPtr1
TEST.VALUE:CanIf.<<GLOBAL>>.CanIf_CtrlIdtoCanDrvFunctMapConfig[0].CanDrvFunctId:0
TEST.VALUE:CanIf.CanIf_WritePdu.CtrlId:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.ATTRIBUTES:CanIf.<<GLOBAL>>.CanIf_TxPduIdConfig[0].UpperPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:CanIf.CanIf_TxConfirmation.CanTxPduId:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END
