-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : CANSM_VCAST_HT
-- Unit(s) Under Test: CanSM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CanSM

-- Subprogram: CanSM_BusoffRecoveryL1Check

-- Test Case: CanSM_BusoffRecoveryL1Check.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1Check.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1Check.Network:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL1Check.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1Check.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1Check.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL1Check.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1Check.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1Check.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL1Check.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1Check.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetBusOffConfigId
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:0
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.return:1
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1Check.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL1Check.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1Check.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetBusOffConfigId
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:0
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.return:1
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1Check.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL1Check.006
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1Check.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetBusOffConfigId
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:0
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.return:0
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1Check.Network:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:2
TEST.VALUE:uut_prototype_stubs.BswM_CanSM_CurrentState.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanSM_BusoffRecoveryL1TxOff

-- Test Case: CanSM_BusoffRecoveryL1TxOff.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1TxOff.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1TxOff.Network:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL1TxOff.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1TxOff.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1TxOff.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL1TxOff.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1TxOff.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1TxOff.Network:0
TEST.VALUE:uut_prototype_stubs.BswM_CanSM_CurrentState.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL1TxOff.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL1TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL1TxOff.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].L1ToL2Counter:0
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL1TxOff.Network:1
TEST.VALUE:uut_prototype_stubs.BswM_CanSM_CurrentState.Network:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanSM_BusoffRecoveryL2Check

-- Test Case: CanSM_BusoffRecoveryL2Check.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2Check.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2Check.Network:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL2Check.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2Check.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2Check.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL2Check.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2Check.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2Check.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL2Check.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2Check.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetBusOffConfigId
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:0
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.return:1
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2Check.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL2Check.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2Check
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2Check.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetBusOffConfigId
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:0
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.return:1
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2Check.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanSM_BusoffRecoveryL2TxOff

-- Test Case: CanSM_BusoffRecoveryL2TxOff.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2TxOff.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2TxOff.Network:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL2TxOff.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2TxOff.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:255
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2TxOff.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL2TxOff.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2TxOff.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:3500
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:4000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2TxOff.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL2TxOff.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2TxOff.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0xFFFFFFFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:4000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2TxOff.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_BusoffRecoveryL2TxOff.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryL2TxOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryL2TxOff.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetBusOffConfigId
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0x0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:0
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.return:0
TEST.VALUE:CanSM.CanSM_BusoffRecoveryL2TxOff.Network:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:0
TEST.VALUE:uut_prototype_stubs.BswM_CanSM_CurrentState.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanSM_BusoffRecoveryNoBusOff

-- Test Case: CanSM_BusoffRecoveryNoBusOff.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_BusoffRecoveryNoBusOff
TEST.NEW
TEST.NAME:CanSM_BusoffRecoveryNoBusOff.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_BusoffRecoveryNoBusOff.Network:255
TEST.EXPECTED:CanSM.CanSM_BusoffRecoveryNoBusOff.Network:255
TEST.ATTRIBUTES:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:INPUT_BASE=16
TEST.END

-- Subprogram: CanSM_CheckCtrlConfigStatus

-- Test Case: CanSM_CheckCtrlConfigStatus.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_CheckCtrlConfigStatus
TEST.NEW
TEST.NAME:CanSM_CheckCtrlConfigStatus.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.CtrlId:CANSM_NUM_OF_NETWORKS
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.Network:<<malloc 1>>
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:CANSM_NUM_OF_NETWORKS
TEST.EXPECTED:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:CANSM_NUM_OF_NETWORKS
TEST.EXPECTED:CanSM.CanSM_CheckCtrlConfigStatus.return:FALSE
TEST.END

-- Test Case: CanSM_CheckCtrlConfigStatus.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_CheckCtrlConfigStatus
TEST.NEW
TEST.NAME:CanSM_CheckCtrlConfigStatus.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:CANSM_NUM_OF_NETWORKS
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[1].ControllerId:CANSM_NUM_OF_NETWORKS
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.CtrlId:0
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.Network:<<malloc 1>>
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:CANSM_NUM_OF_NETWORKS
TEST.EXPECTED:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:CANSM_NUM_OF_NETWORKS
TEST.EXPECTED:CanSM.CanSM_CheckCtrlConfigStatus.return:FALSE
TEST.END

-- Test Case: CanSM_CheckCtrlConfigStatus.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_CheckCtrlConfigStatus
TEST.NEW
TEST.NAME:CanSM_CheckCtrlConfigStatus.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.CtrlId:0
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.Network:<<malloc 1>>
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:CANSM_NUM_OF_NETWORKS
TEST.EXPECTED:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:0
TEST.EXPECTED:CanSM.CanSM_CheckCtrlConfigStatus.return:TRUE
TEST.END

-- Subprogram: CanSM_CheckModeChangeIndication

-- Test Case: CanSM_CheckModeChangeIndication.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_CheckModeChangeIndication
TEST.NEW
TEST.NAME:CanSM_CheckModeChangeIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_CheckModeChangeIndication.Network:255
TEST.EXPECTED:CanSM.CanSM_CheckModeChangeIndication.Network:255
TEST.END

-- Test Case: CanSM_CheckModeChangeIndication.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_CheckModeChangeIndication
TEST.NEW
TEST.NAME:CanSM_CheckModeChangeIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:4
TEST.VALUE:CanSM.CanSM_CheckModeChangeIndication.Network:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:4
TEST.EXPECTED:CanSM.CanSM_CheckModeChangeIndication.Network:0
TEST.END

-- Subprogram: CanSM_ControllerBusOff

-- Test Case: CanSM_ControllerBusOff.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerBusOff
TEST.NEW
TEST.NAME:CanSM_ControllerBusOff.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerBusOff.ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:TRUE
TEST.END

-- Test Case: CanSM_ControllerBusOff.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerBusOff
TEST.NEW
TEST.NAME:CanSM_ControllerBusOff.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerBusOff.ControllerId:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_CONTROLLERBUSOFF_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_UNINIT
TEST.END

-- Test Case: CanSM_ControllerBusOff.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerBusOff
TEST.NEW
TEST.NAME:CanSM_ControllerBusOff.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[1].ControllerId:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[1].TransceiverId:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[1].BusOffId:5
TEST.VALUE:CanSM.CanSM_ControllerBusOff.ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_CONTROLLERBUSOFF_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_PARAM_CONTROLLER
TEST.END

-- Test Case: CanSM_ControllerBusOff.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerBusOff
TEST.NEW
TEST.NAME:CanSM_ControllerBusOff.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_CheckCtrlConfigStatus
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerBusOff.ControllerId:0
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:3
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.return:1
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerBusOff.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:0
TEST.END

-- Subprogram: CanSM_ControllerModeIndication

-- Test Case: CanSM_ControllerModeIndication.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STOPPED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.END

-- Test Case: CanSM_ControllerModeIndication.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SD_CC_STOPPED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:34
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.END

-- Test Case: CanSM_ControllerModeIndication.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SD_CC_SLEEP
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:35
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.END

-- Test Case: CanSM_ControllerModeIndication.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STARTED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:3
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.END

-- Test Case: CanSM_ControllerModeIndication.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STARTED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_UNINIT
TEST.END

-- Test Case: CanSM_ControllerModeIndication.006
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STOPPED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:3
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_PARAM_CONTROLLER
TEST.END

-- Test Case: CanSM_ControllerModeIndication.007
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_CheckCtrlConfigStatus
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STARTED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.Network[0]:3
TEST.VALUE:CanSM.CanSM_CheckCtrlConfigStatus.return:1
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:3
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.END

-- Test Case: CanSM_ControllerModeIndication.008
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetUpdatedMode
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STARTED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STOPPED
TEST.VALUE:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STOPPED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:3
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.END

-- Test Case: CanSM_ControllerModeIndication.009
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetUpdatedMode
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STOPPED
TEST.VALUE:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STOPPED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x3
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STOPPED
TEST.EXPECTED:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STOPPED
TEST.END

-- Test Case: CanSM_ControllerModeIndication.010
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetUpdatedMode
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x22
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STOPPED
TEST.VALUE:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STOPPED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x23
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STOPPED
TEST.EXPECTED:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STOPPED
TEST.END

-- Test Case: CanSM_ControllerModeIndication.011
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STARTED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_SLEEP
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:1
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:3
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_SLEEP
TEST.END

-- Test Case: CanSM_ControllerModeIndication.012
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x23
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_SLEEP
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x40
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_SLEEP
TEST.END

-- Test Case: CanSM_ControllerModeIndication.013
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.013
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STARTED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STARTED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:80
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STARTED
TEST.END

-- Test Case: CanSM_ControllerModeIndication.014
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.014
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x3
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STARTED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x50
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STARTED
TEST.END

-- Test Case: CanSM_ControllerModeIndication.015
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.015
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STARTED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STARTED
TEST.END

-- Test Case: CanSM_ControllerModeIndication.016
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ControllerModeIndication
TEST.NEW
TEST.NAME:CanSM_ControllerModeIndication.016
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x3
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.VALUE:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STARTED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:1
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x3
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerId:0
TEST.EXPECTED:CanSM.CanSM_ControllerModeIndication.ControllerMode:CAN_CS_STARTED
TEST.END

-- Subprogram: CanSM_DeInit

-- Test Case: CanSM_DeInit.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_DeInit
TEST.NEW
TEST.NAME:CanSM_DeInit.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:1
TEST.END

-- Test Case: CanSM_DeInit.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_DeInit
TEST.NEW
TEST.NAME:CanSM_DeInit.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:10
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:10
TEST.END

-- Subprogram: CanSM_Det_ReportError

-- Test Case: CanSM_Det_ReportError.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Det_ReportError
TEST.NEW
TEST.NAME:CanSM_Det_ReportError.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_Det_ReportError.ApiId:CANSM_TXTIMEOUTEXCEPTION_API
TEST.VALUE:CanSM.CanSM_Det_ReportError.ErrorId:CANSM_E_INVALID_NETWORK_HANDLE
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_TXTIMEOUTEXCEPTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_INVALID_NETWORK_HANDLE
TEST.END

-- Subprogram: CanSM_EvaluateMaxModeReq

-- Test Case: CanSM_EvaluateMaxModeReq.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_EvaluateMaxModeReq
TEST.NEW
TEST.NAME:CanSM_EvaluateMaxModeReq.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_EvaluateMaxModeReq.Network:255
TEST.EXPECTED:CanSM.CanSM_EvaluateMaxModeReq.Network:255
TEST.END

-- Subprogram: CanSM_GetBusOffConfigId

-- Test Case: CanSM_GetBusOffConfigId.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetBusOffConfigId
TEST.NEW
TEST.NAME:CanSM_GetBusOffConfigId.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:255
TEST.EXPECTED:CanSM.CanSM_GetBusOffConfigId.Network:255
TEST.END

-- Subprogram: CanSM_GetChIndexFromComMIndex

-- Test Case: CanSM_GetChIndexFromComMIndex.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetChIndexFromComMIndex
TEST.NEW
TEST.NAME:CanSM_GetChIndexFromComMIndex.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_GetChIndexFromComMIndex.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetChIndexFromComMIndex
TEST.NEW
TEST.NAME:CanSM_GetChIndexFromComMIndex.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_GetChIndexFromComMIndex.nmChannelHandle:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanSM.CanSM_GetChIndexFromComMIndex.nmChannelHandle:1
TEST.END

-- Subprogram: CanSM_GetCurrentComMode

-- Test Case: CanSM_GetCurrentComMode.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetCurrentComMode
TEST.NEW
TEST.NAME:CanSM_GetCurrentComMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.ComM_ModePtr:<<malloc 1>>
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.ComM_ModePtr[0]:COMM_SILENT_COMMUNICATION
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.CanSM_GetCurrentComMode.ComM_ModePtr[0]:COMM_FULL_COMMUNICATION
TEST.EXPECTED:CanSM.CanSM_GetCurrentComMode.return:E_OK
TEST.END

-- Test Case: CanSM_GetCurrentComMode.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetCurrentComMode
TEST.NEW
TEST.NAME:CanSM_GetCurrentComMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:CanSM.CanSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_GETCURRENTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_UNINIT
TEST.END

-- Test Case: CanSM_GetCurrentComMode.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetCurrentComMode
TEST.NEW
TEST.NAME:CanSM_GetCurrentComMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.CanSM_GetCurrentComMode.return:1
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:3
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:2
TEST.END

-- Test Case: CanSM_GetCurrentComMode.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetCurrentComMode
TEST.NEW
TEST.NAME:CanSM_GetCurrentComMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.ComM_ModePtr:<<malloc 9>>
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.ComM_ModePtr:<<null>>
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:CanSM.CanSM_GetCurrentComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_GETCURRENTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_PARAM_POINTER
TEST.END

-- Test Case: CanSM_GetCurrentComMode.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetCurrentComMode
TEST.NEW
TEST.NAME:CanSM_GetCurrentComMode.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetChIndexFromComMIndex
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.ComM_ModePtr:<<malloc 9>>
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.ComM_ModePtr:<<null>>
TEST.VALUE:CanSM.CanSM_GetCurrentComMode.return:E_NOT_OK
TEST.VALUE:CanSM.CanSM_GetChIndexFromComMIndex.nmChannelHandle:2
TEST.VALUE:CanSM.CanSM_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.CanSM_GetCurrentComMode.ComM_ModePtr:<<null>>
TEST.EXPECTED:CanSM.CanSM_GetCurrentComMode.return:1
TEST.EXPECTED:CanSM.CanSM_GetChIndexFromComMIndex.nmChannelHandle:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:3
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:3
TEST.END

-- Subprogram: CanSM_GetUpdatedMode

-- Test Case: CanSM_GetUpdatedMode.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetUpdatedMode
TEST.NEW
TEST.NAME:CanSM_GetUpdatedMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_UNINIT
TEST.EXPECTED:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_UNINIT
TEST.END

-- Test Case: CanSM_GetUpdatedMode.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetUpdatedMode
TEST.NEW
TEST.NAME:CanSM_GetUpdatedMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STARTED
TEST.EXPECTED:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STARTED
TEST.END

-- Test Case: CanSM_GetUpdatedMode.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetUpdatedMode
TEST.NEW
TEST.NAME:CanSM_GetUpdatedMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STOPPED
TEST.EXPECTED:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_STOPPED
TEST.END

-- Test Case: CanSM_GetUpdatedMode.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetUpdatedMode
TEST.NEW
TEST.NAME:CanSM_GetUpdatedMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_SLEEP
TEST.EXPECTED:CanSM.CanSM_GetUpdatedMode.ControllerMode:CAN_CS_SLEEP
TEST.END

-- Subprogram: CanSM_GetVersionInfo

-- Test Case: CanSM_GetVersionInfo.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetVersionInfo
TEST.NEW
TEST.NAME:CanSM_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.VALUE:CanSM.CanSM_GetVersionInfo.VersionInfo[0].vendorID:0
TEST.VALUE:CanSM.CanSM_GetVersionInfo.VersionInfo[0].moduleID:0
TEST.VALUE:CanSM.CanSM_GetVersionInfo.VersionInfo[0].sw_major_version:0
TEST.VALUE:CanSM.CanSM_GetVersionInfo.VersionInfo[0].sw_minor_version:0
TEST.VALUE:CanSM.CanSM_GetVersionInfo.VersionInfo[0].sw_patch_version:0
TEST.EXPECTED:CanSM.CanSM_GetVersionInfo.VersionInfo[0].vendorID:51
TEST.EXPECTED:CanSM.CanSM_GetVersionInfo.VersionInfo[0].moduleID:140
TEST.EXPECTED:CanSM.CanSM_GetVersionInfo.VersionInfo[0].sw_major_version:1
TEST.EXPECTED:CanSM.CanSM_GetVersionInfo.VersionInfo[0].sw_minor_version:0
TEST.EXPECTED:CanSM.CanSM_GetVersionInfo.VersionInfo[0].sw_patch_version:0
TEST.END

-- Test Case: CanSM_GetVersionInfo.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_GetVersionInfo
TEST.NEW
TEST.NAME:CanSM_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_GetVersionInfo.VersionInfo:<<null>>
TEST.EXPECTED:CanSM.CanSM_GetVersionInfo.VersionInfo:<<null>>
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_GETVERSIONINFO_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_PARAM_POINTER
TEST.END

-- Subprogram: CanSM_HandleBusOffRecovery

-- Test Case: CanSM_HandleBusOffRecovery.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_HandleBusOffRecovery
TEST.NEW
TEST.NAME:CanSM_HandleBusOffRecovery.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_HandleBusOffRecovery.Network:255
TEST.EXPECTED:CanSM.CanSM_HandleBusOffRecovery.Network:255
TEST.END

-- Subprogram: CanSM_Init

-- Test Case: CanSM_Init.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Init
TEST.NEW
TEST.NAME:CanSM_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.VALUE:CanSM.CanSM_Init.ConfigPtr:<<null>>
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.END

-- Test Case: CanSM_Init.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Init
TEST.NEW
TEST.NAME:CanSM_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.CanSM_Init.ConfigPtr:<<null>>
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.END

-- Subprogram: CanSM_InitiateShutdownProcess

-- Test Case: CanSM_InitiateShutdownProcess.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_InitiateShutdownProcess
TEST.NEW
TEST.NAME:CanSM_InitiateShutdownProcess.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_InitiateShutdownProcess.Network:255
TEST.EXPECTED:CanSM.CanSM_InitiateShutdownProcess.Network:255
TEST.END

-- Subprogram: CanSM_MainFunction

-- Test Case: CanSM_MainFunction.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:255
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.END

-- Test Case: CanSM_MainFunction.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:TRUE
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_SILENT_COMMUNICATION
TEST.END

-- Test Case: CanSM_MainFunction.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_MAINFUNCTION_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_UNINIT
TEST.END

-- Test Case: CanSM_MainFunction.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_TXOFF_L1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:TRUE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_SILENT_COMMUNICATION
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_CHECK_L1
TEST.END

-- Test Case: CanSM_MainFunction.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_CHECK_L1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:4
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:TRUE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_SILENT_COMMUNICATION
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_TXOFF_L1
TEST.END

-- Test Case: CanSM_MainFunction.006
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_CHECK_L1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:6
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:TRUE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_SILENT_COMMUNICATION
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_TXOFF_L2
TEST.END

-- Test Case: CanSM_MainFunction.007
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_CHECK_L1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:4999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:6
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.END

-- Test Case: CanSM_MainFunction.008
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_TXOFF_L2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:2999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:6
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_CHECK_L2
TEST.END

-- Test Case: CanSM_MainFunction.009
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_CHECK_L2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:2999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:6
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:TRUE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_TXOFF_L2
TEST.END

-- Test Case: CanSM_MainFunction.010
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_CHECK_L2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:4999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:6
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.END

-- Test Case: CanSM_MainFunction.011
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:4999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:6
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.END

-- Test Case: CanSM_MainFunction.012
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_SILENT_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:4999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:6
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_SILENT_COMMUNICATION
TEST.END

-- Test Case: CanSM_MainFunction.013
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.013
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_SILENT_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_SILENT_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_TRCV_NORMAL
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:4999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:6
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:12
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_SILENT_COMMUNICATION
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.END

-- Test Case: CanSM_MainFunction.014
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.014
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SU_CC_STARTED
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<CanSM.<<GLOBAL>>.CanSM_NetworkInfo>>[0].CurrentState = CANSM_SU_CC_STARTED;

<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_OK );

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: CanSM_MainFunction.015
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.015
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:<<OPTIONS>>.GLOBAL_DATA_DISPLAY:RANGE_ITERATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_SILENTCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].IndicatedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].ModeReqRepetitionTimer:2
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[1].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_SD_CC_SLEEP
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<CanSM.<<GLOBAL>>.CanSM_NetworkInfo>>[0].CurrentState = CANSM_SD_CC_SLEEP;

<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_OK );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: CanSM_MainFunction.016
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.016
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_NO_BUS_OFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_NOT_OK );

TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: CanSM_MainFunction.017
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_MainFunction
TEST.NEW
TEST.NAME:CanSM_MainFunction.017
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_TXOFF_L1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:999
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].L1ToL2Counter:0xFF
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionTimer:CANSM_RESET_TIMER
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusOffEventReported:TRUE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorCounterL1ToL2:5
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL1:1000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeL2:3000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTimeTxEnsured:5000
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_BusOffConfig[0].BorTxConfirmationPolling:FALSE
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_SILENT_COMMUNICATION
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].BusoffRecoveryState:CANSM_BOR_CHECK_L1
TEST.END

-- Subprogram: CanSM_ProcessBusoffEvent

-- Test Case: CanSM_ProcessBusoffEvent.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ProcessBusoffEvent
TEST.NEW
TEST.NAME:CanSM_ProcessBusoffEvent.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_ProcessBusoffEvent.Network:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ProcessBusoffEvent.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ProcessBusoffEvent
TEST.NEW
TEST.NAME:CanSM_ProcessBusoffEvent.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_ProcessBusoffEvent.Network:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ProcessBusoffEvent.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ProcessBusoffEvent
TEST.NEW
TEST.NAME:CanSM_ProcessBusoffEvent.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetBusOffConfigId
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_ProcessBusoffEvent.Network:1
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:1
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.return:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ProcessBusoffEvent.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ProcessBusoffEvent
TEST.NEW
TEST.NAME:CanSM_ProcessBusoffEvent.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_ProcessBusoffEvent.Network:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ProcessBusoffEvent.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ProcessBusoffEvent
TEST.NEW
TEST.NAME:CanSM_ProcessBusoffEvent.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_ProcessBusoffEvent.Network:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanSM_ProcessComModeRequest

-- Test Case: CanSM_ProcessComModeRequest.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ProcessComModeRequest
TEST.NEW
TEST.NAME:CanSM_ProcessComModeRequest.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_ProcessComModeRequest.Network:255
TEST.EXPECTED:CanSM.CanSM_ProcessComModeRequest.Network:255
TEST.END

-- Test Case: CanSM_ProcessComModeRequest.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ProcessComModeRequest
TEST.NEW
TEST.NAME:CanSM_ProcessComModeRequest.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_BO_TX_OFFLINE
TEST.VALUE:CanSM.CanSM_ProcessComModeRequest.Network:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:20
TEST.EXPECTED:CanSM.CanSM_ProcessComModeRequest.Network:0
TEST.END

-- Subprogram: CanSM_RequestComMode

-- Test Case: CanSM_RequestComMode.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_RequestComMode
TEST.NEW
TEST.NAME:CanSM_RequestComMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.ComM_Mode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.EXPECTED:CanSM.CanSM_RequestComMode.return:E_OK
TEST.END

-- Test Case: CanSM_RequestComMode.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_RequestComMode
TEST.NEW
TEST.NAME:CanSM_RequestComMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.ComM_Mode:COMM_SILENT_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_SILENT_COMMUNICATION
TEST.EXPECTED:CanSM.CanSM_RequestComMode.return:E_OK
TEST.END

-- Test Case: CanSM_RequestComMode.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_RequestComMode
TEST.NEW
TEST.NAME:CanSM_RequestComMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.ComM_Mode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:CanSM.CanSM_RequestComMode.return:E_OK
TEST.END

-- Test Case: CanSM_RequestComMode.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_RequestComMode
TEST.NEW
TEST.NAME:CanSM_RequestComMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.ComM_Mode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_UNINIT
TEST.END

-- Test Case: CanSM_RequestComMode.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_RequestComMode
TEST.NEW
TEST.NAME:CanSM_RequestComMode.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.ComM_Mode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:2
TEST.EXPECTED:CanSM.CanSM_RequestComMode.ComM_Mode:2
TEST.EXPECTED:CanSM.CanSM_RequestComMode.return:0
TEST.END

-- Test Case: CanSM_RequestComMode.006
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_RequestComMode
TEST.NEW
TEST.NAME:CanSM_RequestComMode.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.ComM_Mode:255
TEST.VALUE:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.EXPECTED:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_REQUESTCOMMODE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_INVALID_COMM_REQUEST
TEST.END

-- Test Case: CanSM_RequestComMode.007
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_RequestComMode
TEST.NEW
TEST.NAME:CanSM_RequestComMode.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetChIndexFromComMIndex
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.CanSM_RequestComMode.ComM_Mode:255
TEST.VALUE:CanSM.CanSM_RequestComMode.return:E_NOT_OK
TEST.VALUE:CanSM.CanSM_GetChIndexFromComMIndex.nmChannelHandle:2
TEST.VALUE:CanSM.CanSM_GetChIndexFromComMIndex.return:2
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.CanSM_RequestComMode.ComM_Mode:255
TEST.EXPECTED:CanSM.CanSM_RequestComMode.return:1
TEST.EXPECTED:CanSM.CanSM_GetChIndexFromComMIndex.nmChannelHandle:0
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:2
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:3
TEST.END

-- Subprogram: CanSM_StartWakeupSource

-- Test Case: CanSM_StartWakeupSource.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StartWakeupSource
TEST.NEW
TEST.NAME:CanSM_StartWakeupSource.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_StartWakeupSource.Network:0
TEST.VALUE:CanSM.CanSM_StartWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:64
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_StartWakeupSource.Network:0
TEST.EXPECTED:CanSM.CanSM_StartWakeupSource.return:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<CanSM.<<GLOBAL>>.CanSM_NetworkInfo>>[0].CurrentState =CANSM_STARTWAKEUPSOURCES_OK;
<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_OK );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: CanSM_StartWakeupSource.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StartWakeupSource
TEST.NEW
TEST.NAME:CanSM_StartWakeupSource.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_STARTWAKEUPSOURCES_OK
TEST.VALUE:CanSM.CanSM_StartWakeupSource.Network:0
TEST.VALUE:CanSM.CanSM_StartWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.EXPECTED:CanSM.CanSM_StartWakeupSource.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_STARTWAKEUPSOURCE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_UNINIT
TEST.END

-- Test Case: CanSM_StartWakeupSource.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StartWakeupSource
TEST.NEW
TEST.NAME:CanSM_StartWakeupSource.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_STARTWAKEUPSOURCES_OK
TEST.VALUE:CanSM.CanSM_StartWakeupSource.Network:255
TEST.VALUE:CanSM.CanSM_StartWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.CanSM_StartWakeupSource.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_STARTWAKEUPSOURCE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_INVALID_NETWORK_HANDLE
TEST.END

-- Test Case: CanSM_StartWakeupSource.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StartWakeupSource
TEST.NEW
TEST.NAME:CanSM_StartWakeupSource.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_StartWakeupSource.Network:0
TEST.VALUE:CanSM.CanSM_StartWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.CanSM_StartWakeupSource.return:E_NOT_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<CanSM.<<GLOBAL>>.CanSM_NetworkInfo>>[0].CurrentState =CANSM_STARTWAKEUPSOURCES_OK;
<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_OK );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: CanSM_StartWakeupSource.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StartWakeupSource
TEST.NEW
TEST.NAME:CanSM_StartWakeupSource.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_Statemachine
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:50
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.VALUE:CanSM.CanSM_StartWakeupSource.Network:0
TEST.VALUE:CanSM.CanSM_StartWakeupSource.return:E_NOT_OK
TEST.VALUE:CanSM.CanSM_Statemachine.Network:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:64
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].ControllerId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].BusOffId:0
TEST.EXPECTED:CanSM.CanSM_StartWakeupSource.Network:0
TEST.EXPECTED:CanSM.CanSM_StartWakeupSource.return:1
TEST.EXPECTED:CanSM.CanSM_Statemachine.Network:0
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<CanSM.<<GLOBAL>>.CanSM_NetworkInfo>>[0].CurrentState =CANSM_STARTWAKEUPSOURCES_OK;
<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_OK );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: CanSM_Statemachine

-- Test Case: CanSM_Statemachine.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Statemachine
TEST.NEW
TEST.NAME:CanSM_Statemachine.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_Statemachine.Network:255
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_Statemachine.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Statemachine
TEST.NEW
TEST.NAME:CanSM_Statemachine.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].ModeReqRepetitionCounter:11
TEST.VALUE:CanSM.CanSM_Statemachine.Network:0
TEST.VALUE:uut_prototype_stubs.BswM_CanSM_CurrentState.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_Statemachine.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Statemachine
TEST.NEW
TEST.NAME:CanSM_Statemachine.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0xFF
TEST.VALUE:CanSM.CanSM_Statemachine.Network:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x1
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0xFF
TEST.EXPECTED:CanSM.CanSM_Statemachine.Network:0
TEST.END

-- Test Case: CanSM_Statemachine.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Statemachine
TEST.NEW
TEST.NAME:CanSM_Statemachine.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x24
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0xFF
TEST.VALUE:CanSM.CanSM_Statemachine.Network:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x24
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0xFF
TEST.EXPECTED:CanSM.CanSM_Statemachine.Network:0
TEST.END

-- Test Case: CanSM_Statemachine.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Statemachine
TEST.NEW
TEST.NAME:CanSM_Statemachine.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x25
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0xFF
TEST.VALUE:CanSM.CanSM_Statemachine.Network:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x25
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0xFF
TEST.EXPECTED:CanSM.CanSM_Statemachine.Network:0
TEST.END

-- Test Case: CanSM_Statemachine.006
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_Statemachine
TEST.NEW
TEST.NAME:CanSM_Statemachine.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x3
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0xFF
TEST.VALUE:CanSM.CanSM_Statemachine.Network:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x3
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkConfig[0].TransceiverId:0xFF
TEST.EXPECTED:CanSM.CanSM_Statemachine.Network:0
TEST.END

-- Subprogram: CanSM_StopWakeupSource

-- Test Case: CanSM_StopWakeupSource.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StopWakeupSource
TEST.NEW
TEST.NAME:CanSM_StopWakeupSource.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.CanSM_StopWakeupSource.Network:0
TEST.VALUE:CanSM.CanSM_StopWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.CanSM_StopWakeupSource.return:E_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<CanSM.<<GLOBAL>>.CanSM_NetworkInfo>>[0].CurrentState =CANSM_S_NOCOM;
<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_OK );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: CanSM_StopWakeupSource.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StopWakeupSource
TEST.NEW
TEST.NAME:CanSM_StopWakeupSource.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.CanSM_StopWakeupSource.Network:0
TEST.VALUE:CanSM.CanSM_StopWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_UNINITED
TEST.EXPECTED:CanSM.CanSM_StopWakeupSource.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_STOPWAKEUPSOURCE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_UNINIT
TEST.END

-- Test Case: CanSM_StopWakeupSource.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StopWakeupSource
TEST.NEW
TEST.NAME:CanSM_StopWakeupSource.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.CanSM_StopWakeupSource.Network:255
TEST.VALUE:CanSM.CanSM_StopWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.CanSM_StopWakeupSource.return:E_NOT_OK
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ApiId:CANSM_STOPWAKEUPSOURCE_API
TEST.EXPECTED:uut_prototype_stubs.Det_ReportError.ErrorId:CANSM_E_INVALID_NETWORK_HANDLE
TEST.END

-- Test Case: CanSM_StopWakeupSource.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StopWakeupSource
TEST.NEW
TEST.NAME:CanSM_StopWakeupSource.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_FULL_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:CANSM_S_NOCOM
TEST.VALUE:CanSM.CanSM_StopWakeupSource.Network:0
TEST.VALUE:CanSM.CanSM_StopWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.CanSM_StopWakeupSource.return:E_OK
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<CanSM.<<GLOBAL>>.CanSM_NetworkInfo>>[0].CurrentState =CANSM_S_NOCOM;
<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_OK );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: CanSM_StopWakeupSource.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_StopWakeupSource
TEST.NEW
TEST.NAME:CanSM_StopWakeupSource.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_Statemachine
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:COMM_NO_COMMUNICATION
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x0
TEST.VALUE:CanSM.CanSM_StopWakeupSource.Network:0
TEST.VALUE:CanSM.CanSM_StopWakeupSource.return:E_NOT_OK
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_InitStatus:CANSM_INITED
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].RequestedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].IndicatedComMode:0
TEST.EXPECTED:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:0x22
TEST.EXPECTED:CanSM.CanSM_StopWakeupSource.Network:0
TEST.EXPECTED:CanSM.CanSM_StopWakeupSource.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.CanIf_SetControllerMode.return
<<CanSM.<<GLOBAL>>.CanSM_NetworkInfo>>[0].CurrentState =CANSM_S_NOCOM;
<<uut_prototype_stubs.CanIf_SetControllerMode.return>> = ( E_OK );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: CanSM_TimerHandling

-- Test Case: CanSM_TimerHandling.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_TimerHandling
TEST.NEW
TEST.NAME:CanSM_TimerHandling.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:CanSM.CanSM_TimerHandling.Network:255
TEST.EXPECTED:CanSM.CanSM_TimerHandling.Network:255
TEST.ATTRIBUTES:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].CurrentState:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Subprogram: CanSM_ValidateBusoffRecovery

-- Test Case: CanSM_ValidateBusoffRecovery.001
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ValidateBusoffRecovery
TEST.NEW
TEST.NAME:CanSM_ValidateBusoffRecovery.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ValidateBusoffRecovery.002
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ValidateBusoffRecovery
TEST.NEW
TEST.NAME:CanSM_ValidateBusoffRecovery.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_ValidateBusoffRecovery.Network:3
TEST.VALUE:uut_prototype_stubs.BswM_CanSM_CurrentState.Network:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ValidateBusoffRecovery.003
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ValidateBusoffRecovery
TEST.NEW
TEST.NAME:CanSM_ValidateBusoffRecovery.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.<<GLOBAL>>.CanSM_NetworkInfo[0].NetworkTimer:1
TEST.VALUE:CanSM.CanSM_ValidateBusoffRecovery.Network:0
TEST.VALUE:CanSM.CanSM_ValidateBusoffRecovery.BusoffRecoveryPassCount:0
TEST.VALUE:uut_prototype_stubs.BswM_CanSM_CurrentState.Network:0
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ValidateBusoffRecovery.004
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ValidateBusoffRecovery
TEST.NEW
TEST.NAME:CanSM_ValidateBusoffRecovery.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.STUB:CanSM.CanSM_GetBusOffConfigId
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.Network:0
TEST.VALUE:CanSM.CanSM_GetBusOffConfigId.return:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ValidateBusoffRecovery.005
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ValidateBusoffRecovery
TEST.NEW
TEST.NAME:CanSM_ValidateBusoffRecovery.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanSM_ValidateBusoffRecovery.006
TEST.UNIT:CanSM
TEST.SUBPROGRAM:CanSM_ValidateBusoffRecovery
TEST.NEW
TEST.NAME:CanSM_ValidateBusoffRecovery.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanSm:CANSM_DETAILED_DESIGN::CanSM_ClassDiagram 
Requirement_DICVA-13845
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END
