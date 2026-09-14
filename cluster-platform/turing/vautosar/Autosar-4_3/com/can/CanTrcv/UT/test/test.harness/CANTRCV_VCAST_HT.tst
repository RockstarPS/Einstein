-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : CANTRCV_VCAST_HT
-- Unit(s) Under Test: CanTrcv CanTrcv_Tja1040
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CanTrcv

-- Subprogram: CanTrcv_CheckWakeup

-- Test Case: CanTrcv_CheckWakeup.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.002
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.003
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.CanTrcv_CheckWakeup.Transceiver:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.004
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.005
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:2
TEST.END

-- Test Case: CanTrcv_CheckWakeup.007
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.008
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_TrcvWakeupMode[0]:CANTRCV_WUMODE_DISABLE
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.009
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_TrcvWakeupReason[0]:CANTRCV_WU_BY_BUS
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.010
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.011
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.END

-- Test Case: CanTrcv_CheckWakeup.012
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_CheckWakeup
TEST.NEW
TEST.NAME:CanTrcv_CheckWakeup.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.END

-- Subprogram: CanTrcv_GetBusWuReason

-- Test Case: CanTrcv_GetBusWuReason.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetBusWuReason
TEST.NEW
TEST.NAME:CanTrcv_GetBusWuReason.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetBusWuReason.002
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetBusWuReason
TEST.NEW
TEST.NAME:CanTrcv_GetBusWuReason.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetBusWuReason.003
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetBusWuReason
TEST.NEW
TEST.NAME:CanTrcv_GetBusWuReason.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.CanTrcv_GetBusWuReason.Transceiver:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetBusWuReason.004
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetBusWuReason
TEST.NEW
TEST.NAME:CanTrcv_GetBusWuReason.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.CanTrcv_GetBusWuReason.Reason:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetBusWuReason.005
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetBusWuReason
TEST.NEW
TEST.NAME:CanTrcv_GetBusWuReason.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.CanTrcv_GetBusWuReason.Reason:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanTrcv_GetOpMode

-- Test Case: CanTrcv_GetOpMode.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_GetOpMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetOpMode.002
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_GetOpMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetOpMode.003
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_GetOpMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.Transceiver:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetOpMode.004
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_GetOpMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetOpMode.005
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_GetOpMode.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:3
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode:<<malloc 4>>
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:0x1
TEST.EXPECTED:CanTrcv.CanTrcv_GetOpMode.return:1
TEST.END

-- Test Case: CanTrcv_GetOpMode.006
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_GetOpMode.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode:<<malloc 4>>
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:0x1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.EXPECTED:CanTrcv.CanTrcv_GetOpMode.return:1
TEST.END

-- Test Case: CanTrcv_GetOpMode.007
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_GetOpMode.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode:<<malloc 4>>
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:0x1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_NORMAL
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.EXPECTED:CanTrcv.CanTrcv_GetOpMode.return:0
TEST.END

-- Subprogram: CanTrcv_GetVersionInfo

-- Test Case: CanTrcv_GetVersionInfo.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetVersionInfo
TEST.NEW
TEST.NAME:CanTrcv_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_GetVersionInfo.002
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_GetVersionInfo
TEST.NEW
TEST.NAME:CanTrcv_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.CanTrcv_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanTrcv_Init

-- Test Case: CanTrcv_Init.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_Init
TEST.NEW
TEST.NAME:CanTrcv_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_Init.002
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_Init
TEST.NEW
TEST.NAME:CanTrcv_Init.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_Init.003
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_Init
TEST.NEW
TEST.NAME:CanTrcv_Init.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_Init.004
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_Init
TEST.NEW
TEST.NAME:CanTrcv_Init.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_Init.005
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_Init
TEST.NEW
TEST.NAME:CanTrcv_Init.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_Init.006
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_Init
TEST.NEW
TEST.NAME:CanTrcv_Init.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_Init.007
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_Init
TEST.NEW
TEST.NAME:CanTrcv_Init.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanTrcv_InitMemory

-- Test Case: CanTrcv_InitMemory.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_InitMemory
TEST.NEW
TEST.NAME:CanTrcv_InitMemory.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanTrcv_MainFunction

-- Test Case: CanTrcv_MainFunction.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_MainFunction.003
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.END

-- Test Case: CanTrcv_MainFunction.004
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.END

-- Test Case: CanTrcv_MainFunction.005
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.END

-- Test Case: CanTrcv_MainFunction.006
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.END

-- Test Case: CanTrcv_MainFunction.007
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.END

-- Test Case: CanTrcv_MainFunction.008
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.END

-- Test Case: CanTrcv_MainFunction.009
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.009
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason1
TEST.END

-- Test Case: CanTrcv_MainFunction.010
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_TrcvWakeupMode[0]:CANTRCV_WUMODE_DISABLE
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.END

-- Test Case: CanTrcv_MainFunction.011
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunction
TEST.NEW
TEST.NAME:CanTrcv_MainFunction.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:0
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_TrcvChannelId:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_InitMode:CANTRCV_TRCVMODE_SLEEP
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupSource:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_InitFn:CanTrcv_MainFunctionDiagnostics
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetBusWuReasonFn:test_CanTrcv_GetBusWuReason2
TEST.END

-- Subprogram: CanTrcv_MainFunctionDiagnostics

-- Test Case: CanTrcv_MainFunctionDiagnostics.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_MainFunctionDiagnostics
TEST.NEW
TEST.NAME:CanTrcv_MainFunctionDiagnostics.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanTrcv_ReportWakeup

-- Test Case: CanTrcv_ReportWakeup.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_ReportWakeup
TEST.NEW
TEST.NAME:CanTrcv_ReportWakeup.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:CanTrcv.CanTrcv_ReportWakeup.Transceiver:0
TEST.EXPECTED:CanTrcv.CanTrcv_ReportWakeup.Transceiver:0
TEST.END

-- Test Case: CanTrcv_ReportWakeup.002
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_ReportWakeup
TEST.NEW
TEST.NAME:CanTrcv_ReportWakeup.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:CanTrcv.CanTrcv_ReportWakeup.Transceiver:1
TEST.EXPECTED:CanTrcv.CanTrcv_ReportWakeup.Transceiver:1
TEST.END

-- Test Case: CanTrcv_ReportWakeup.003
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_ReportWakeup
TEST.NEW
TEST.NAME:CanTrcv_ReportWakeup.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_TrcvWakeupReason[0]:CANTRCV_WU_BY_BUS
TEST.VALUE:CanTrcv.CanTrcv_ReportWakeup.Transceiver:0
TEST.EXPECTED:CanTrcv.CanTrcv_ReportWakeup.Transceiver:0
TEST.END

-- Test Case: CanTrcv_ReportWakeup.004
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_ReportWakeup
TEST.NEW
TEST.NAME:CanTrcv_ReportWakeup.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_TrcvWakeupReason[0]:CANTRCV_WU_BY_BUS
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.CanTrcv_ReportWakeup.Transceiver:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.EXPECTED:CanTrcv.CanTrcv_ReportWakeup.Transceiver:0
TEST.END

-- Test Case: CanTrcv_ReportWakeup.005
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_ReportWakeup
TEST.NEW
TEST.NAME:CanTrcv_ReportWakeup.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_TrcvWakeupReason[0]:CANTRCV_WU_BY_BUS
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsWakeupSourceSupported:1
TEST.VALUE:CanTrcv.CanTrcv_ReportWakeup.Transceiver:0
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_WakeupByBusUsed:1
TEST.EXPECTED:CanTrcv.CanTrcv_ReportWakeup.Transceiver:0
TEST.END

-- Subprogram: CanTrcv_SetOpMode

-- Test Case: CanTrcv_SetOpMode.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.002
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.003
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.Transceiver:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.004
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.005
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_HwFunctCfgId:2
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.006
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.007
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.008
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.008
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.010
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.010
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:CANTRCV_TRCVMODE_STANDBY
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.011
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.011
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:CANTRCV_TRCVMODE_STANDBY
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.012
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.012
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:CANTRCV_TRCVMODE_STANDBY
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.013
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.013
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.014
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.014
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:CANTRCV_TRCVMODE_SLEEP
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.015
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.015
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.016
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.016
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:CanTrcv_GetOpMode
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:4
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.CanTrcv_SetOpMode.OpMode:4
TEST.END

-- Test Case: CanTrcv_SetOpMode.017
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.017
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:CanTrcv_SetOpMode
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.Transceiver:1
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.return:1
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_STANDBY
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetOpMode.018
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_SetOpMode.018
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.STUB:CanTrcv.CanTrcv_GetOpMode
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_SetOpModeFn:test_CanTrcv_SetOpModeFn3
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_HWFunctCfg[0].CanTrcv_GetOpModeFn:test_CanTrcv_GetOpModeFn2
TEST.VALUE:CanTrcv.CanTrcv_SetOpMode.OpMode:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.VALUE:CanTrcv.CanTrcv_GetOpMode.return:2
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CanTrcv_SetWakeupMode

-- Test Case: CanTrcv_SetWakeupMode.001
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetWakeupMode
TEST.NEW
TEST.NAME:CanTrcv_SetWakeupMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetWakeupMode.002
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetWakeupMode
TEST.NEW
TEST.NAME:CanTrcv_SetWakeupMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetWakeupMode.003
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetWakeupMode
TEST.NEW
TEST.NAME:CanTrcv_SetWakeupMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.CanTrcv_SetWakeupMode.Transceiver:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CanTrcv_SetWakeupMode.004
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetWakeupMode
TEST.NEW
TEST.NAME:CanTrcv_SetWakeupMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.END

-- Test Case: CanTrcv_SetWakeupMode.005
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetWakeupMode
TEST.NEW
TEST.NAME:CanTrcv_SetWakeupMode.005
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.CanTrcv_SetWakeupMode.TrcvWakeupMode:CANTRCV_WUMODE_DISABLE
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.CanTrcv_SetWakeupMode.TrcvWakeupMode:CANTRCV_WUMODE_DISABLE
TEST.END

-- Test Case: CanTrcv_SetWakeupMode.006
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetWakeupMode
TEST.NEW
TEST.NAME:CanTrcv_SetWakeupMode.006
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.CanTrcv_SetWakeupMode.TrcvWakeupMode:CANTRCV_WUMODE_CLEAR
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.CanTrcv_SetWakeupMode.TrcvWakeupMode:CANTRCV_WUMODE_CLEAR
TEST.END

-- Test Case: CanTrcv_SetWakeupMode.007
TEST.UNIT:CanTrcv
TEST.SUBPROGRAM:CanTrcv_SetWakeupMode
TEST.NEW
TEST.NAME:CanTrcv_SetWakeupMode.007
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13725
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_InitStatus:1
TEST.VALUE:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.VALUE:CanTrcv.CanTrcv_SetWakeupMode.TrcvWakeupMode:4
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:CanTrcv.<<GLOBAL>>.CanTrcv_ChannelCfg[0].CanTrcv_IsChannelUsed:1
TEST.EXPECTED:CanTrcv.CanTrcv_SetWakeupMode.TrcvWakeupMode:4
TEST.END

-- Unit: CanTrcv_Tja1040

-- Subprogram: CanTrcv_Tja1040_GetBusWuReason

-- Test Case: CanTrcv_Tja1040_GetBusWuReason.001
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1040_GetBusWuReason
TEST.NEW
TEST.NAME:CanTrcv_Tja1040_GetBusWuReason.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1040_GetBusWuReason.Channel:0
TEST.END

-- Subprogram: CanTrcv_Tja1040_Init

-- Test Case: CanTrcv_Tja1040_Init.001
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1040_Init
TEST.NEW
TEST.NAME:CanTrcv_Tja1040_Init.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.END

-- Subprogram: CanTrcv_Tja1040_InitMemory

-- Test Case: CanTrcv_Tja1040_InitMemory.001
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1040_InitMemory
TEST.NEW
TEST.NAME:CanTrcv_Tja1040_InitMemory.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.END

-- Subprogram: CanTrcv_Tja1040_SetOpMode

-- Test Case: CanTrcv_Tja1040_SetOpMode.001
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1040_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_Tja1040_SetOpMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.Channel:0
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.Channel:0
TEST.END

-- Test Case: CanTrcv_Tja1040_SetOpMode.002
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1040_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_Tja1040_SetOpMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.Channel:0
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.OpMode:CANTRCV_TRCVMODE_STANDBY
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.Channel:0
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.OpMode:CANTRCV_TRCVMODE_STANDBY
TEST.END

-- Test Case: CanTrcv_Tja1040_SetOpMode.003
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1040_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_Tja1040_SetOpMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.Channel:0
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.OpMode:CANTRCV_TRCVMODE_SLEEP
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.Channel:0
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.OpMode:CANTRCV_TRCVMODE_SLEEP
TEST.END

-- Test Case: CanTrcv_Tja1040_SetOpMode.004
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1040_SetOpMode
TEST.NEW
TEST.NAME:CanTrcv_Tja1040_SetOpMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.Channel:2
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.OpMode:CANTRCV_TRCVMODE_SLEEP
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.Channel:2
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1040_SetOpMode.OpMode:CANTRCV_TRCVMODE_SLEEP
TEST.END

-- Subprogram: CanTrcv_Tja1443_GetOpMode

-- Test Case: CanTrcv_Tja1443_GetOpMode.001
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1443_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_Tja1443_GetOpMode.001
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.Channel:0
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.OpMode:<<malloc 1>>
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.Channel:0
TEST.END

-- Test Case: CanTrcv_Tja1443_GetOpMode.002
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1443_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_Tja1443_GetOpMode.002
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:1
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.Channel:0
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.OpMode:<<null>>
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.Channel:0
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.OpMode:<<null>>
TEST.END

-- Test Case: CanTrcv_Tja1443_GetOpMode.003
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1443_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_Tja1443_GetOpMode.003
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:1
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.Channel:2
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.OpMode:<<null>>
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.Channel:2
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.OpMode:<<null>>
TEST.END

-- Test Case: CanTrcv_Tja1443_GetOpMode.004
TEST.UNIT:CanTrcv_Tja1040
TEST.SUBPROGRAM:CanTrcv_Tja1443_GetOpMode
TEST.NEW
TEST.NAME:CanTrcv_Tja1443_GetOpMode.004
TEST.NOTES:
SoftwareArchitecture::COM::CAN::CanTrcv::CANTRCV_DETAILED_DESIGN::CanTrcv_ClassDiagram 
Requirement_DICVA-13726
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.ChannelId:1
TEST.VALUE:uut_prototype_stubs.Dio_ReadChannel.return:1
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.Channel:0
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.OpMode:<<malloc 1>>
TEST.VALUE:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.OpMode[0]:CANTRCV_TRCVMODE_NORMAL
TEST.EXPECTED:CanTrcv_Tja1040.CanTrcv_Tja1443_GetOpMode.Channel:0
TEST.END
