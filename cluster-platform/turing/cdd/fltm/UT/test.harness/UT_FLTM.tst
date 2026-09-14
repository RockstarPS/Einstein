-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_FLTM
-- Unit(s) Under Test: FltM FltM_Soc FltM_Soc_Dcc FltM_Soc_Ecc FltM_Soc_FlsIntegrity FltM_Soc_Pok FltM_Soc_Ppu
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: FltM

-- Subprogram: CFltM_Impl_MainFunction

-- Test Case: CFltM_Impl_MainFunction.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CFltM_Impl_MainFunction
TEST.NEW
TEST.NAME:CFltM_Impl_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: CFltM_Impl_OnCommand

-- Test Case: CFltM_Impl_OnCommand.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CFltM_Impl_OnCommand
TEST.NEW
TEST.NAME:CFltM_Impl_OnCommand.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.CmpLib_Command.Cmd:1
TEST.VALUE:uut_prototype_stubs.CmpLib_Command.return:1
TEST.EXPECTED:uut_prototype_stubs.CmpLib_Command.Cmd:0
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.EXPECTED:FltM.CmpActivation.return:0
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.EXPECTED:FltM.CmpActive.return:0
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.EXPECTED:FltM.CmpDeActivation.return:0
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.CmpDeInit.return:0
TEST.EXPECTED:FltM.CmpDeInit.return:0
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.EXPECTED:FltM.CmpDiag.return:0
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.EXPECTED:FltM.CmpDiagReturn.return:0
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_Init
TEST.VALUE:FltM.CmpInit.return:0
TEST.EXPECTED:FltM.CmpInit.return:0
TEST.END

-- Subprogram: FltM_EvaluateCounterDebounceFault

-- Test Case: FltM_EvaluateCounterDebounceFault.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF3
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FailDebounceCounter:2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FailDebounceCounter:2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FailDebounceCounter:2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.008
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].PassDebounceCounter:3
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.009
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_NG
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.010
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_NG
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].PassDebounceCounter:2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.011
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].PassDebounceCounter:2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.012
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.012
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].PassDebounceCounter:2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.013
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.013
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_GOOD
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.014
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.014
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].ActionCounter:0xFF
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.015
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.015
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FailDebounceCounter:0
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].FailCounterThreshold:4
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.016
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.016
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].PassCounterThreshold:4
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].PassDebounceCounter:0
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.017
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.017
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].PassCounterThreshold:4
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_NG
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].PassDebounceCounter:2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Test Case: FltM_EvaluateCounterDebounceFault.018
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_EvaluateCounterDebounceFault
TEST.NEW
TEST.NAME:FltM_EvaluateCounterDebounceFault.018
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].PassCounterThreshold:4
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.eFaultStatus:0xF1
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FltM_InternalPtr[0].PassDebounceCounter:2
TEST.VALUE:FltM.FltM_EvaluateCounterDebounceFault.FaultConfigPtr:<<malloc 1>>
TEST.END

-- Subprogram: FltM_ExecuteFatalPolicyAction

-- Test Case: FltM_ExecuteFatalPolicyAction.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ExecuteFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_ExecuteFatalPolicyAction.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFaultConfig:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:FLTM_FATAL_POLICY_REQUEST_RESET
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:0
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFormatLogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flTotalLogLength:1
TEST.VALUE:uut_prototype_stubs.FltM_ServiceRequestReset.return:0
TEST.EXPECTED:FltM.FltM_ExecuteFatalPolicyAction.return:0
TEST.END

-- Test Case: FltM_ExecuteFatalPolicyAction.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ExecuteFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_ExecuteFatalPolicyAction.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFaultConfig:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:FLTM_FATAL_POLICY_FINAL_SAFE_ACTION
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:0
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFormatLogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flTotalLogLength:1
TEST.VALUE:uut_prototype_stubs.FltM_ServiceLogFault.return:0
TEST.VALUE:uut_prototype_stubs.FltM_ServiceExecuteFinalSafeAction.return:0
TEST.EXPECTED:FltM.FltM_ExecuteFatalPolicyAction.return:0
TEST.END

-- Test Case: FltM_ExecuteFatalPolicyAction.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ExecuteFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_ExecuteFatalPolicyAction.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFaultConfig:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:FLTM_FATAL_POLICY_NO_ACTION
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:0
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFormatLogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flTotalLogLength:1
TEST.EXPECTED:FltM.FltM_ExecuteFatalPolicyAction.return:0
TEST.END

-- Test Case: FltM_ExecuteFatalPolicyAction.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ExecuteFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_ExecuteFatalPolicyAction.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFaultConfig:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:FLTM_FATAL_POLICY_REQUEST_RESET
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:0
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFormatLogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flTotalLogLength:1
TEST.VALUE:uut_prototype_stubs.FltM_ServiceRequestReset.return:1
TEST.EXPECTED:FltM.FltM_ExecuteFatalPolicyAction.return:1
TEST.END

-- Test Case: FltM_ExecuteFatalPolicyAction.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ExecuteFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_ExecuteFatalPolicyAction.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFaultConfig:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:FLTM_FATAL_POLICY_FINAL_SAFE_ACTION
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:0
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFormatLogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flTotalLogLength:1
TEST.VALUE:uut_prototype_stubs.FltM_ServiceExecuteFinalSafeAction.return:1
TEST.EXPECTED:FltM.FltM_ExecuteFatalPolicyAction.return:1
TEST.END

-- Test Case: FltM_ExecuteFatalPolicyAction.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ExecuteFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_ExecuteFatalPolicyAction.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFaultConfig:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:FLTM_FATAL_POLICY_FINAL_SAFE_ACTION
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:1
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFormatLogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flTotalLogLength:1
TEST.VALUE:uut_prototype_stubs.FltM_ServiceExecuteFinalSafeAction.return:1
TEST.EXPECTED:FltM.FltM_ExecuteFatalPolicyAction.return:1
TEST.END

-- Test Case: FltM_ExecuteFatalPolicyAction.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ExecuteFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_ExecuteFatalPolicyAction.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFaultConfig:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:9
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:0
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFormatLogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flTotalLogLength:1
TEST.EXPECTED:FltM.FltM_ExecuteFatalPolicyAction.return:0
TEST.END

-- Subprogram: FltM_FormatLogData

-- Test Case: FltM_FormatLogData.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_FormatLogData
TEST.NEW
TEST.NAME:FltM_FormatLogData.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_FormatLogData.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_FormatLogData.LogData[0]:1
TEST.VALUE:FltM.FltM_FormatLogData.LogLength:7
TEST.VALUE:FltM.FltM_FormatLogData.FormattedLogData:<<malloc 3>>
TEST.VALUE:FltM.FltM_FormatLogData.TotalLogLength:<<malloc 3>>
TEST.EXPECTED:FltM.FltM_FormatLogData.LogLength:7
TEST.END

-- Test Case: FltM_FormatLogData.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_FormatLogData
TEST.NEW
TEST.NAME:FltM_FormatLogData.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_FormatLogData.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_FormatLogData.LogLength:0
TEST.VALUE:FltM.FltM_FormatLogData.FormattedLogData:<<malloc 3>>
TEST.VALUE:FltM.FltM_FormatLogData.TotalLogLength:<<malloc 3>>
TEST.EXPECTED:FltM.FltM_FormatLogData.LogLength:0
TEST.END

-- Test Case: FltM_FormatLogData.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_FormatLogData
TEST.NEW
TEST.NAME:FltM_FormatLogData.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_FormatLogData.LogLength:5
TEST.VALUE:FltM.FltM_FormatLogData.FormattedLogData:<<malloc 3>>
TEST.VALUE:FltM.FltM_FormatLogData.TotalLogLength:<<malloc 3>>
TEST.EXPECTED:FltM.FltM_FormatLogData.LogLength:5
TEST.END

-- Test Case: FltM_FormatLogData.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_FormatLogData
TEST.NEW
TEST.NAME:FltM_FormatLogData.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_FormatLogData.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_FormatLogData.LogData[0]:1
TEST.VALUE:FltM.FltM_FormatLogData.LogLength:6
TEST.VALUE:FltM.FltM_FormatLogData.FormattedLogData:<<malloc 3>>
TEST.VALUE:FltM.FltM_FormatLogData.TotalLogLength:<<malloc 3>>
TEST.EXPECTED:FltM.FltM_FormatLogData.LogLength:6
TEST.END

-- Subprogram: FltM_GetConfigIndexById

-- Test Case: FltM_GetConfigIndexById.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetConfigIndexById
TEST.NEW
TEST.NAME:FltM_GetConfigIndexById.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultId:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr:<<malloc 1>>
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:1
TEST.EXPECTED:FltM.FltM_GetConfigIndexById.FaultId:0
TEST.END

-- Subprogram: FltM_GetFatalPolicyAction

-- Test Case: FltM_GetFatalPolicyAction.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_GetFatalPolicyAction.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.ResetPolicyMode:FLTM_RESET_POLICY_NONE
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.CurrentCount:0
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.FinalSafeActionThreshold:3
TEST.EXPECTED:FltM.FltM_GetFatalPolicyAction.return:FLTM_FATAL_POLICY_NO_ACTION
TEST.END

-- Test Case: FltM_GetFatalPolicyAction.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_GetFatalPolicyAction.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.ResetPolicyMode:FLTM_RESET_POLICY_RESET_ALWAYS
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.CurrentCount:3
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.FinalSafeActionThreshold:3
TEST.EXPECTED:FltM.FltM_GetFatalPolicyAction.return:FLTM_FATAL_POLICY_REQUEST_RESET
TEST.END

-- Test Case: FltM_GetFatalPolicyAction.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_GetFatalPolicyAction.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.ResetPolicyMode:FLTM_RESET_POLICY_FINAL_ACTION_ONLY
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.CurrentCount:0
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.FinalSafeActionThreshold:3
TEST.EXPECTED:FltM.FltM_GetFatalPolicyAction.return:FLTM_FATAL_POLICY_FINAL_SAFE_ACTION
TEST.END

-- Test Case: FltM_GetFatalPolicyAction.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_GetFatalPolicyAction.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.ResetPolicyMode:FLTM_RESET_POLICY_RESET_UNTIL_FINAL_ACTION
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.CurrentCount:2
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.FinalSafeActionThreshold:3
TEST.EXPECTED:FltM.FltM_GetFatalPolicyAction.return:FLTM_FATAL_POLICY_REQUEST_RESET
TEST.END

-- Test Case: FltM_GetFatalPolicyAction.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_GetFatalPolicyAction.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.ResetPolicyMode:FLTM_RESET_POLICY_RESET_UNTIL_FINAL_ACTION
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.CurrentCount:3
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.FinalSafeActionThreshold:3
TEST.EXPECTED:FltM.FltM_GetFatalPolicyAction.return:FLTM_FATAL_POLICY_FINAL_SAFE_ACTION
TEST.END

-- Test Case: FltM_GetFatalPolicyAction.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_GetFatalPolicyAction.006
TEST.NOTES:
PE4TI29141-12735: invalid policy preserves legacy threshold behavior below threshold.
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.ResetPolicyMode:99
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.CurrentCount:1
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.FinalSafeActionThreshold:3
TEST.EXPECTED:FltM.FltM_GetFatalPolicyAction.return:FLTM_FATAL_POLICY_REQUEST_RESET
TEST.END

-- Test Case: FltM_GetFatalPolicyAction.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFatalPolicyAction
TEST.NEW
TEST.NAME:FltM_GetFatalPolicyAction.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.ResetPolicyMode:99
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.CurrentCount:3
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.FinalSafeActionThreshold:3
TEST.EXPECTED:FltM.FltM_GetFatalPolicyAction.return:FLTM_FATAL_POLICY_FINAL_SAFE_ACTION
TEST.END

-- Subprogram: FltM_GetFaultStatus

-- Test Case: FltM_GetFaultStatus.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:DET_ERROR
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<null>>
TEST.EXPECTED:FltM.FltM_GetFaultStatus.return:1
TEST.END

-- Test Case: FltM_GetFaultStatus.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:0xFFFF
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_ACTIVE
TEST.EXPECTED:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_ACTIVE
TEST.EXPECTED:FltM.FltM_GetFaultStatus.return:1
TEST.END

-- Test Case: FltM_GetFaultStatus.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[85].FltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:DET_ERROR
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.EXPECTED:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_INACTIVE
TEST.END

-- Test Case: FltM_GetFaultStatus.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:0xFFFF
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_INACTIVE
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_GetFaultStatus.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:0xFFFF
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_INACTIVE
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:90
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_GetFaultStatus.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_NG
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:0xFFFF
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_INACTIVE
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_GetFaultStatus.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[85].FltMStatus:99
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:DET_ERROR
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.EXPECTED:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_INACTIVE
TEST.END

-- Test Case: FltM_GetFaultStatus.008
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:0xFFFF
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_INACTIVE
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_GetFaultStatus.009
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_GOOD
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:0xFFFF
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_INACTIVE
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_GetFaultStatus.010
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_GetFaultStatus
TEST.NEW
TEST.NAME:FltM_GetFaultStatus.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:10
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultId:0xFFFF
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus:<<malloc 1>>
TEST.VALUE:FltM.FltM_GetFaultStatus.FaultStatus[0]:FLTM_PUBLIC_STATUS_INACTIVE
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Subprogram: FltM_HandleEvaluatedFault

-- Test Case: FltM_HandleEvaluatedFault.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].ActionCounter:5
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:1
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:10
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:3
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[2].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[2].ActionCounter:4
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:2
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].PreviousFltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:1
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.008
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[5].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[5].ActionCounter:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:5
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.009
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_NG
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.010
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:10
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.011
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].PreviousFltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LogConfig[0].FltMLogLevel:DLT_LOG_FATAL
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceIsFatalFault.return:0
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.012
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.012
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].PreviousFltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:2
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.013
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.013
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].PreviousFltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:5
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:1
TEST.VALUE:uut_prototype_stubs.FltM_ServiceExecuteRecoveryAction.return:0
TEST.VALUE:uut_prototype_stubs.FltM_ServiceClearResetCount.return:0
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.014
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.014
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].PreviousFltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_GOOD
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:1
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.015
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.015
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].PreviousFltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LogConfig[0].FltMLogLevel:DLT_LOG_FATAL
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceIsFatalFault.return:1
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.016
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.016
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetFatalPolicyAction
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].PreviousFltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LogConfig[0].FltMLogLevel:DLT_LOG_FATAL
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.return:1
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceIsFatalFault.return:1
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.017
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.017
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetFatalPolicyAction
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].PreviousFltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LogConfig[0].FltMLogLevel:DLT_LOG_FATAL
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.return:1
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceIsFatalFault.return:1
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.018
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.018
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_GOOD
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandleEvaluatedFault.019
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandleEvaluatedFault
TEST.NEW
TEST.NAME:FltM_HandleEvaluatedFault.019
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_FormatLogData
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:6
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandleEvaluatedFault.FaultStatus:2
TEST.END

-- Subprogram: FltM_HandlePostReset

-- Test Case: FltM_HandlePostReset.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_HandlePostReset.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_HandlePostReset.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_HandlePostReset.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_HandlePostReset.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_HandlePostReset.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:77
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_HandlePostReset.008
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_HandlePostReset.009
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetResetCount.return:1
TEST.END

-- Test Case: FltM_HandlePostReset.010
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:90
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_HandlePostReset.011
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePostReset
TEST.NEW
TEST.NAME:FltM_HandlePostReset.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DemConfig[0].LogDtc:1
TEST.END

-- Subprogram: FltM_HandlePreInitFatalFault

-- Test Case: FltM_HandlePreInitFatalFault.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.FaultStatus:2
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetEarlyResetCount.return:1
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetFatalPolicyAction
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.return:1
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetEarlyResetCount.return:1
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetFatalPolicyAction
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.return:1
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetEarlyResetCount.return:1
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.008
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetFatalPolicyAction
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.return:1
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetEarlyResetCount.return:1
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.009
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetFatalPolicyAction
TEST.STUB:FltM.FltM_ExecuteFatalPolicyAction
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.return:2
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:2
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:0
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.return:1
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_Det_ReportError.ApiId:1
TEST.VALUE:uut_prototype_stubs.FltM_Det_ReportError.ErrorId:1
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetEarlyResetCount.return:1
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.010
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetFatalPolicyAction
TEST.STUB:FltM.FltM_ExecuteFatalPolicyAction
TEST.VALUE:FltM.FltM_GetFatalPolicyAction.return:2
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flFatalPolicyAction:2
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.flUseSameLogGate:0
TEST.VALUE:FltM.FltM_ExecuteFatalPolicyAction.return:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.FaultStatus:2
TEST.VALUE:uut_prototype_stubs.FltM_Det_ReportError.ApiId:1
TEST.VALUE:uut_prototype_stubs.FltM_Det_ReportError.ErrorId:1
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetEarlyResetCount.return:1
TEST.END

-- Test Case: FltM_HandlePreInitFatalFault.011
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFatalFault
TEST.NEW
TEST.NAME:FltM_HandlePreInitFatalFault.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_HandlePreInitFaults

-- Test Case: FltM_HandlePreInitFaults.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFaults
TEST.NEW
TEST.NAME:FltM_HandlePreInitFaults.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_HandlePreInitFaults.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_HandlePreInitFaults
TEST.NEW
TEST.NAME:FltM_HandlePreInitFaults.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_PreInitQueue[0].valid:1
TEST.END

-- Subprogram: FltM_Init

-- Test Case: FltM_Init.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_Init
TEST.NEW
TEST.NAME:FltM_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM_Soc.FltM_Soc_Init.return:1
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_GOOD
TEST.END

-- Test Case: FltM_Init.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_Init
TEST.NEW
TEST.NAME:FltM_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc.FltM_Soc_Init
TEST.VALUE:FltM_Soc.FltM_Soc_Init.return:0
TEST.END

-- Test Case: FltM_Init.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_Init
TEST.NEW
TEST.NAME:FltM_Init.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_LogFaultIfNeeded

-- Test Case: FltM_LogFaultIfNeeded.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_LogFaultIfNeeded
TEST.NEW
TEST.NAME:FltM_LogFaultIfNeeded.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_MainFunction

-- Test Case: FltM_MainFunction.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM_Soc.FltM_Soc_MainFunction.return:1
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:0
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:0
TEST.END

-- Test Case: FltM_MainFunction.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetFaultId:1
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:0
TEST.END

-- Test Case: FltM_MainFunction.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetResonReceived:1
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetResonReceived:1
TEST.END

-- Test Case: FltM_MainFunction.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_HandlePreInitFaults
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_HandlePreFaults:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetFaultId:63805
TEST.END

-- Test Case: FltM_MainFunction.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_MainFunction.008
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.END

-- Test Case: FltM_MainFunction.009
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.END

-- Test Case: FltM_MainFunction.010
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.END

-- Test Case: FltM_MainFunction.011
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FailTimerMs:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.END

-- Test Case: FltM_MainFunction.012
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.012
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.END

-- Test Case: FltM_MainFunction.013
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.013
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_TRANSITION_TO_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.END

-- Test Case: FltM_MainFunction.014
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.014
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.END

-- Test Case: FltM_MainFunction.015
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.015
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:5
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.END

-- Test Case: FltM_MainFunction.016
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.016
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].PassTimerMs:0xFFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.END

-- Test Case: FltM_MainFunction.017
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.017
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FailTimerMs:0xFFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.END

-- Test Case: FltM_MainFunction.018
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.018
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FailTimerMs:0xFFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].ActionCounter:0xFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.END

-- Test Case: FltM_MainFunction.019
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.019
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FailTimerMs:0xFFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].ActionCounter:0xFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.END

-- Test Case: FltM_MainFunction.020
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.020
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.END

-- Test Case: FltM_MainFunction.021
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.021
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetLastResetReason.return:1
TEST.END

-- Test Case: FltM_MainFunction.022
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.022
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetFaultId:63805
TEST.VALUE:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetResonReceived:0
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetLastResetReason.FaultId[0]:63805
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetLastResetReason.return:0
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetFaultId:63805
TEST.END

-- Test Case: FltM_MainFunction.023
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.023
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetFaultId:64513
TEST.VALUE:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetResonReceived:0
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetLastResetReason.FaultId[0]:64513
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetLastResetReason.return:0
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_ResetState.FltM_ResetFaultId:64513
TEST.END

-- Test Case: FltM_MainFunction.024
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.024
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.025
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.025
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.026
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.026
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.027
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.027
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FailTimerMs:0xFFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.028
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.028
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FailTimerMs:0xFFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.029
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.029
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FailTimerMs:0xFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceFailTimeMs:0xFFFF
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.030
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.030
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FailTimerMs:0xFFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].ActionCounter:0xFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.031
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.031
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.032
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.032
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.033
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.033
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].PassTimerMs:0xFFFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Test Case: FltM_MainFunction.034
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_MainFunction
TEST.NEW
TEST.NAME:FltM_MainFunction.034
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.<<GLOBAL>>.CmpState:1
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_TimeDebounceCache[1].valid:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].PassTimerMs:0xFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[1].TimeDebounceActive:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[1]:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebouncePassTimeMs:0xFFFF
TEST.EXPECTED:FltM.<<GLOBAL>>.CmpState:1
TEST.END

-- Subprogram: FltM_ReportFault

-- Test Case: FltM_ReportFault.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultId:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:1
TEST.EXPECTED:FltM.FltM_ReportFault.return:1
TEST.END

-- Test Case: FltM_ReportFault.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:90
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_ReportFault.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.STUB:FltM.FltM_EvaluateCounterDebounceFault
TEST.STUB:FltM.FltM_HandleEvaluatedFault
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:2
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:2
TEST.EXPECTED:FltM.FltM_ReportFault.FaultStatus:2
TEST.END

-- Test Case: FltM_ReportFault.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogData[0]:0xAB
TEST.VALUE:FltM.FltM_ReportFault.LogLength:3
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetResetCount.return:1
TEST.END

-- Test Case: FltM_ReportFault.007
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 9>>
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<null>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:3
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.FltM_ServiceGetResetCount.Count[0]:5
TEST.END

-- Test Case: FltM_ReportFault.008
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_ReportFault.009
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:3
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_ReportFault.010
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].TimeDebounceActive:1
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 9>>
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<null>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:3
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.FltM_Det_ReportError.ApiId:4
TEST.VALUE:uut_prototype_stubs.FltM_Det_ReportError.ErrorId:2
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_Internal[0].TimeDebounceActive:1
TEST.END

-- Test Case: FltM_ReportFault.011
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.STUB:FltM.FltM_HandlePreInitFatalFault
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:0
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:FltM.FltM_HandlePreInitFatalFault.return:0
TEST.EXPECTED:FltM.FltM_ReportFault.return:0
TEST.END

-- Test Case: FltM_ReportFault.012
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.012
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.STUB:FltM.FltM_StorePreInitFault
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:0
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.EXPECTED:FltM.FltM_ReportFault.return:0
TEST.END

-- Test Case: FltM_ReportFault.013
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.013
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.STUB:FltM.FltM_StorePreInitFault
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:0
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:1
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.EXPECTED:FltM.FltM_ReportFault.return:0
TEST.END

-- Test Case: FltM_ReportFault.014
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.014
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.STUB:FltM.FltM_EvaluateCounterDebounceFault
TEST.STUB:FltM.FltM_HandleEvaluatedFault
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_LastReportedStatus[0]:0
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.EXPECTED:FltM.<<GLOBAL>>.FltM_LastReportedStatus[0]:2
TEST.END

-- Test Case: FltM_ReportFault.015
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.015
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceFailTimeMs:1
TEST.END

-- Test Case: FltM_ReportFault.016
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.016
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].FltMStatus:FLTM_FAULT_STATUS_NG
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_ReportFault.017
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.017
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0xFF
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.END

-- Test Case: FltM_ReportFault.018
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.018
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:1
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceFailTimeMs:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebouncePassTimeMs:0
TEST.END

-- Test Case: FltM_ReportFault.019
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.019
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:1
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceFailTimeMs:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebouncePassTimeMs:1
TEST.END

-- Test Case: FltM_ReportFault.020
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.020
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:1
TEST.VALUE:FltM.<<GLOBAL>>.FltM_Internal[0].ActionCounter:0
TEST.VALUE:FltM.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:FLTM_DEBOUNCE_TYPE_TIME
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:1
TEST.VALUE:FltM.FltM_ReportFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_ReportFault.LogLength:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceType:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebounceFailTimeMs:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.FltM_DebounceConfig[0].DebouncePassTimeMs:1
TEST.END

-- Test Case: FltM_ReportFault.021
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_ReportFault
TEST.NEW
TEST.NAME:FltM_ReportFault.021
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM.FltM_GetConfigIndexById
TEST.STUB:FltM.FltM_StorePreInitFault
TEST.VALUE:FltM.<<GLOBAL>>.gFltM_Initialized:0
TEST.VALUE:FltM.FltM_ReportFault.FaultStatus:2
TEST.VALUE:FltM.FltM_GetConfigIndexById.FaultConfigIndexPtr[0]:0
TEST.VALUE:FltM.FltM_GetConfigIndexById.return:0
TEST.VALUE:uut_prototype_stubs.FltM_ServiceIsFatalFault.return:1
TEST.EXPECTED:FltM.FltM_ReportFault.return:0
TEST.END

-- Subprogram: FltM_StorePreInitFault

-- Test Case: FltM_StorePreInitFault.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_StorePreInitFault
TEST.NEW
TEST.NAME:FltM_StorePreInitFault.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_StorePreInitFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_StorePreInitFault.FaultStatus:2
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData:<<malloc 9>>
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData:<<null>>
TEST.VALUE:FltM.FltM_StorePreInitFault.LogLength:0
TEST.END

-- Test Case: FltM_StorePreInitFault.002
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_StorePreInitFault
TEST.NEW
TEST.NAME:FltM_StorePreInitFault.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_StorePreInitFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_StorePreInitFault.FaultStatus:1
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData[0]:0xAB
TEST.VALUE:FltM.FltM_StorePreInitFault.LogLength:3
TEST.END

-- Test Case: FltM_StorePreInitFault.003
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_StorePreInitFault
TEST.NEW
TEST.NAME:FltM_StorePreInitFault.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_StorePreInitFault.flConfigIndex:1
TEST.VALUE:FltM.FltM_StorePreInitFault.FaultStatus:2
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData[0]:0x55
TEST.VALUE:FltM.FltM_StorePreInitFault.LogLength:10
TEST.END

-- Test Case: FltM_StorePreInitFault.004
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_StorePreInitFault
TEST.NEW
TEST.NAME:FltM_StorePreInitFault.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_StorePreInitFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_StorePreInitFault.FaultStatus:2
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData:<<malloc 9>>
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData:<<null>>
TEST.VALUE:FltM.FltM_StorePreInitFault.LogLength:7
TEST.END

-- Test Case: FltM_StorePreInitFault.005
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_StorePreInitFault
TEST.NEW
TEST.NAME:FltM_StorePreInitFault.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_StorePreInitFault.flConfigIndex:3
TEST.VALUE:FltM.FltM_StorePreInitFault.FaultStatus:1
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData:<<malloc 1>>
TEST.VALUE:FltM.FltM_StorePreInitFault.LogLength:0
TEST.END

-- Test Case: FltM_StorePreInitFault.006
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_StorePreInitFault
TEST.NEW
TEST.NAME:FltM_StorePreInitFault.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM.FltM_StorePreInitFault.flConfigIndex:0
TEST.VALUE:FltM.FltM_StorePreInitFault.FaultStatus:2
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData:<<malloc 5>>
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData[0]:0x11
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData[1]:0x22
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData[2]:0x33
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData[3]:0x44
TEST.VALUE:FltM.FltM_StorePreInitFault.LogData[4]:0x55
TEST.VALUE:FltM.FltM_StorePreInitFault.LogLength:5
TEST.END

-- Subprogram: FltM_UpdateLogCache

-- Test Case: FltM_UpdateLogCache.001
TEST.UNIT:FltM
TEST.SUBPROGRAM:FltM_UpdateLogCache
TEST.NEW
TEST.NAME:FltM_UpdateLogCache.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Detailed_Design::FltM_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Unit: FltM_Soc

-- Subprogram: FLTM_Clocksleep

-- Test Case: FLTM_Clocksleep.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_Clocksleep
TEST.NEW
TEST.NAME:FLTM_Clocksleep.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FLTM_DisableInterrupt

-- Test Case: FLTM_DisableInterrupt.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_DisableInterrupt
TEST.NEW
TEST.NAME:FLTM_DisableInterrupt.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc.FLTM_DisableInterrupt.intNum:244
TEST.END

-- Test Case: FLTM_DisableInterrupt.002
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_DisableInterrupt
TEST.NEW
TEST.NAME:FLTM_DisableInterrupt.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc.FLTM_deregisterInterrupt
TEST.VALUE:FltM_Soc.FLTM_deregisterInterrupt.handle:VECTORCAST_INT1
TEST.END

-- Subprogram: FLTM_EnableInterrupt

-- Test Case: FLTM_EnableInterrupt.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_EnableInterrupt
TEST.NEW
TEST.NAME:FLTM_EnableInterrupt.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FLTM_EnableInterrupt.002
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_EnableInterrupt
TEST.NEW
TEST.NAME:FLTM_EnableInterrupt.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc.FLTM_EnableInterrupt.intNum:244
TEST.END

-- Subprogram: FLTM_deregisterInterrupt

-- Test Case: FLTM_deregisterInterrupt.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_deregisterInterrupt
TEST.NEW
TEST.NAME:FLTM_deregisterInterrupt.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FLTM_deregisterInterrupt.002
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_deregisterInterrupt
TEST.NEW
TEST.NAME:FLTM_deregisterInterrupt.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc.FLTM_deregisterInterrupt.handle:VECTORCAST_INT1
TEST.END

-- Subprogram: FLTM_registerInterrupt

-- Test Case: FLTM_registerInterrupt.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_registerInterrupt
TEST.NEW
TEST.NAME:FLTM_registerInterrupt.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FLTM_registerInterrupt.002
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_registerInterrupt
TEST.NEW
TEST.NAME:FLTM_registerInterrupt.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams:<<malloc 1>>
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams[0].intNum:1
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams[0].callback:SDL_ESM_hiInterruptHandler
TEST.END

-- Test Case: FLTM_registerInterrupt.003
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_registerInterrupt
TEST.NEW
TEST.NAME:FLTM_registerInterrupt.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams:<<malloc 1>>
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams[0].intNum:1
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams[0].callback:SDL_ESM_loInterruptHandler
TEST.END

-- Test Case: FLTM_registerInterrupt.004
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FLTM_registerInterrupt
TEST.NEW
TEST.NAME:FLTM_registerInterrupt.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams:<<malloc 1>>
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams[0].intNum:1
TEST.VALUE:FltM_Soc.FLTM_registerInterrupt.pParams[0].callback:SDL_ESM_configInterruptHandler
TEST.END

-- Subprogram: FltM_CfgInterruptHandler

-- Test Case: FltM_CfgInterruptHandler.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_CfgInterruptHandler
TEST.NEW
TEST.NAME:FltM_CfgInterruptHandler.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_HiInterruptHandler

-- Test Case: FltM_HiInterruptHandler.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_HiInterruptHandler
TEST.NEW
TEST.NAME:FltM_HiInterruptHandler.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_LowInterruptHandler

-- Test Case: FltM_LowInterruptHandler.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_LowInterruptHandler
TEST.NEW
TEST.NAME:FltM_LowInterruptHandler.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_Soc_Init

-- Test Case: FltM_Soc_Init.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_Init
TEST.NEW
TEST.NAME:FltM_Soc_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.SDL_ESM_init.return:1
TEST.END

-- Test Case: FltM_Soc_Init.002
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_Init
TEST.NEW
TEST.NAME:FltM_Soc_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_FlsIntegrity.FltM_FlashIntegrity
TEST.VALUE:uut_prototype_stubs.SDL_ESM_init.return:0
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.return:1
TEST.VALUE:FltM_Soc_FlsIntegrity.FltM_FlashIntegrity.return:1
TEST.END

-- Test Case: FltM_Soc_Init.003
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_Init
TEST.NEW
TEST.NAME:FltM_Soc_Init.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_FlsIntegrity.FltM_FlashIntegrity
TEST.VALUE:uut_prototype_stubs.SDL_ESM_init.return:0
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.return:0
TEST.VALUE:FltM_Soc_FlsIntegrity.FltM_FlashIntegrity.return:1
TEST.END

-- Test Case: FltM_Soc_Init.004
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_Init
TEST.NEW
TEST.NAME:FltM_Soc_Init.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_Init
TEST.STUB:FltM_Soc_FlsIntegrity.FltM_FlashIntegrity_Init
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.SDL_ESM_init.return:0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_Init.return:0
TEST.VALUE:FltM_Soc_FlsIntegrity.FltM_FlashIntegrity_Init.return:0
TEST.END

-- Subprogram: FltM_Soc_MainFunction

-- Test Case: FltM_Soc_MainFunction.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_Soc_MainFunction.002
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_Soc_MainFunction.003
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_Soc_MainFunction.004
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_Soc_MainFunction.005
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Ecc.FltM_ECC_ReadBack
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_ReadBack.return:1
TEST.END

-- Test Case: FltM_Soc_MainFunction.006
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_DCC_ReadBack
TEST.VALUE:FltM_Soc_Dcc.FltM_DCC_ReadBack.return:1
TEST.END

-- Test Case: FltM_Soc_MainFunction.007
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_DCC_ReadBack
TEST.VALUE:FltM_Soc_Dcc.FltM_DCC_ReadBack.return:0
TEST.END

-- Test Case: FltM_Soc_MainFunction.008
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Ppu.FltM_PPU_ReadBack
TEST.VALUE:FltM_Soc_Ppu.FltM_PPU_ReadBack.return:1
TEST.END

-- Test Case: FltM_Soc_MainFunction.009
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_Soc_MainFunction.010
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_Soc_MainFunction
TEST.NEW
TEST.NAME:FltM_Soc_MainFunction.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_addrTranslate

-- Test Case: FltM_addrTranslate.001
TEST.UNIT:FltM_Soc
TEST.SUBPROGRAM:FltM_addrTranslate
TEST.NEW
TEST.NAME:FltM_addrTranslate.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Unit: FltM_Soc_Dcc

-- Subprogram: FltM_DCC_ReadBack

-- Test Case: FltM_DCC_ReadBack.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_DCC_ReadBack
TEST.NEW
TEST.NAME:FltM_DCC_ReadBack.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_DCC_ReadBack.002
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_DCC_ReadBack
TEST.NEW
TEST.NAME:FltM_DCC_ReadBack.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC0
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC0
TEST.END

-- Test Case: FltM_DCC_ReadBack.003
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_DCC_ReadBack
TEST.NEW
TEST.NAME:FltM_DCC_ReadBack.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC1
TEST.EXPECTED:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC1
TEST.END

-- Test Case: FltM_DCC_ReadBack.004
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_DCC_ReadBack
TEST.NEW
TEST.NAME:FltM_DCC_ReadBack.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:0
TEST.END

-- Subprogram: FltM_Dcc_CallBackFunc

-- Test Case: FltM_Dcc_CallBackFunc.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_CallBackFunc
TEST.NEW
TEST.NAME:FltM_Dcc_CallBackFunc.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_IsValidInstance
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_IsValidInstance.return:1
TEST.END

-- Test Case: FltM_Dcc_CallBackFunc.002
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_CallBackFunc
TEST.NEW
TEST.NAME:FltM_Dcc_CallBackFunc.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_IsValidInstance
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_IsValidInstance.return:0
TEST.END

-- Subprogram: FltM_Dcc_Disable

-- Test Case: FltM_Dcc_Disable.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_Disable
TEST.NEW
TEST.NAME:FltM_Dcc_Disable.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_Dcc_GetTriggeredDccInstance

-- Test Case: FltM_Dcc_GetTriggeredDccInstance.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_GetTriggeredDccInstance
TEST.NEW
TEST.NAME:FltM_Dcc_GetTriggeredDccInstance.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_GetTriggeredDccInstance.esmInst:SDL_ESM_INST_WKUP_ESM0
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_GetTriggeredDccInstance.esmInst:SDL_ESM_INST_WKUP_ESM0
TEST.END

-- Test Case: FltM_Dcc_GetTriggeredDccInstance.002
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_GetTriggeredDccInstance
TEST.NEW
TEST.NAME:FltM_Dcc_GetTriggeredDccInstance.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_GetTriggeredDccInstance.esmInst:SDL_ESM_INST_MAIN_ESM0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_GetTriggeredDccInstance.intSrc:1
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_GetTriggeredDccInstance.esmInst:SDL_ESM_INST_MAIN_ESM0
TEST.END

-- Test Case: FltM_Dcc_GetTriggeredDccInstance.003
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_GetTriggeredDccInstance
TEST.NEW
TEST.NAME:FltM_Dcc_GetTriggeredDccInstance.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.<<GLOBAL>>.FltM_DCC_mainDccMap[0].intSrc:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_GetTriggeredDccInstance.esmInst:SDL_ESM_INST_MAIN_ESM0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_GetTriggeredDccInstance.intSrc:1
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_GetTriggeredDccInstance.esmInst:SDL_ESM_INST_MAIN_ESM0
TEST.END

-- Subprogram: FltM_Dcc_Init

-- Test Case: FltM_Dcc_Init.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_Init
TEST.NEW
TEST.NAME:FltM_Dcc_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_Init.return:1
TEST.END

-- Test Case: FltM_Dcc_Init.002
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_Init
TEST.NEW
TEST.NAME:FltM_Dcc_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_Dcc_Init.003
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_Init
TEST.NEW
TEST.NAME:FltM_Dcc_Init.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC0
TEST.END

-- Test Case: FltM_Dcc_Init.004
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_Init
TEST.NEW
TEST.NAME:FltM_Dcc_Init.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC1
TEST.EXPECTED:FltM_Soc_Dcc.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC1
TEST.END

-- Test Case: FltM_Dcc_Init.005
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_Init
TEST.NEW
TEST.NAME:FltM_Dcc_Init.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:0
TEST.END

-- Test Case: FltM_Dcc_Init.006
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_Init
TEST.NEW
TEST.NAME:FltM_Dcc_Init.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.<<GLOBAL>>.Dcc_Config[0].mode:1
TEST.END

-- Test Case: FltM_Dcc_Init.007
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_Init
TEST.NEW
TEST.NAME:FltM_Dcc_Init.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].mode:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:0
TEST.END

-- Subprogram: FltM_Dcc_InjectFault

-- Test Case: FltM_Dcc_InjectFault.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_InjectFault
TEST.NEW
TEST.NAME:FltM_Dcc_InjectFault.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_InjectFault.InjectIndex:99
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_InjectFault.return:0
TEST.END

-- Test Case: FltM_Dcc_InjectFault.002
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_InjectFault
TEST.NEW
TEST.NAME:FltM_Dcc_InjectFault.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_InjectFault.InjectIndex:7
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_InjectFault.return:0
TEST.END

-- Test Case: FltM_Dcc_InjectFault.003
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_InjectFault
TEST.NEW
TEST.NAME:FltM_Dcc_InjectFault.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_Disable
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].refclkFreq:1000000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].monclkFreq:2000000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].DriftVal:100
TEST.VALUE:uut_prototype_stubs.SDL_DCC_configure.return:0
TEST.VALUE:uut_prototype_stubs.SDL_DCC_verifyConfig.return:0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_InjectFault.InjectIndex:0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:0
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_InjectFault.return:0
TEST.END

-- Test Case: FltM_Dcc_InjectFault.004
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_InjectFault
TEST.NEW
TEST.NAME:FltM_Dcc_InjectFault.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_Disable
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_InjectFault.InjectIndex:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_InjectFault.return:1
TEST.END

-- Test Case: FltM_Dcc_InjectFault.005
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_InjectFault
TEST.NEW
TEST.NAME:FltM_Dcc_InjectFault.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_Disable
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:uut_prototype_stubs.SDL_DCC_configure.return:-1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_InjectFault.InjectIndex:2
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:0
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_InjectFault.return:1
TEST.END

-- Test Case: FltM_Dcc_InjectFault.006
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_InjectFault
TEST.NEW
TEST.NAME:FltM_Dcc_InjectFault.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_Disable
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:uut_prototype_stubs.SDL_DCC_configure.return:0
TEST.VALUE:uut_prototype_stubs.SDL_DCC_verifyConfig.return:-1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_InjectFault.InjectIndex:3
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:0
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_InjectFault.return:1
TEST.END

-- Test Case: FltM_Dcc_InjectFault.007
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_InjectFault
TEST.NEW
TEST.NAME:FltM_Dcc_InjectFault.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_Disable
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:uut_prototype_stubs.SDL_DCC_configure.return:0
TEST.VALUE:uut_prototype_stubs.SDL_DCC_verifyConfig.return:0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_InjectFault.InjectIndex:4
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:0
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_InjectFault.return:0
TEST.END

-- Test Case: FltM_Dcc_InjectFault.008
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_InjectFault
TEST.NEW
TEST.NAME:FltM_Dcc_InjectFault.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_Disable
TEST.STUB:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].dccInst:SDL_DCC_INST_MCU_DCC1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].refclkFreq:1000000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].monclkFreq:2000000
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Dcc_Config[0].DriftVal:100
TEST.VALUE:uut_prototype_stubs.SDL_DCC_configure.return:0
TEST.VALUE:uut_prototype_stubs.SDL_DCC_verifyConfig.return:0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_InjectFault.InjectIndex:0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:0
TEST.EXPECTED:FltM_Soc_Dcc.FltM_Dcc_InjectFault.return:0
TEST.END

-- Subprogram: FltM_Dcc_IsValidInstance

-- Test Case: BASIS-PATH-001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_IsValidInstance
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (dccInstance != (SDL_DCC_INVALID_INSTANCE) && dccInstance != (SDL_DCC_Inst)99U) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_IsValidInstance.dccInstance:SDL_DCC_INVALID_INSTANCE
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_IsValidInstance
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (dccInstance != (SDL_DCC_INVALID_INSTANCE) && dccInstance != (SDL_DCC_Inst)99U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_IsValidInstance.dccInstance:SDL_DCC_INST_DCC2
TEST.END

-- Test Case: BASIS-PATH-002.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_IsValidInstance
TEST.NEW
TEST.NAME:BASIS-PATH-002.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (dccInstance != (SDL_DCC_INVALID_INSTANCE) && dccInstance != (SDL_DCC_Inst)99U) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_IsValidInstance.dccInstance:99
TEST.END

-- Subprogram: FltM_Dcc_SetSeedVals

-- Test Case: FltM_Dcc_SetSeedVals.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.002
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<null>>
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.003
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.004
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:8
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:9
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.005
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:10
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.006
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:10
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:5
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams[0].clk0Seed:1061059
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.007
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:10
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:101
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams[0].clk0Seed:1061059
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.008
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:500
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:200
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.009
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:10
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.010
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.011
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:0xFFFFFFFF
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.012
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.012
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:0xFFFFFFFF
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:0x0
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.013
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.013
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:100000000
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:1000000
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:100000000
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:1000000000
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.014
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.014
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:0xFFFFFFFF
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:0xFFFFFFFF
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:0x1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.016
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.016
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:10000
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:10000
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Test Case: FltM_Dcc_SetSeedVals.017
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_Dcc_SetSeedVals
TEST.NEW
TEST.NAME:FltM_Dcc_SetSeedVals.017
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.refClkFreq:1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.testClkFreq:0xFFFFFFFF
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.fsysclk:0x1
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.driftPer:100
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.configParams:<<malloc 1>>
TEST.VALUE:FltM_Soc_Dcc.FltM_Dcc_SetSeedVals.return:1
TEST.END

-- Subprogram: FltM_OscClkLossDetection_Enable

-- Test Case: FltM_OscClkLossDetection_Enable.001
TEST.UNIT:FltM_Soc_Dcc
TEST.SUBPROGRAM:FltM_OscClkLossDetection_Enable
TEST.NEW
TEST.NAME:FltM_OscClkLossDetection_Enable.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Unit: FltM_Soc_Ecc

-- Subprogram: FltM_ECC_CallBackFunc

-- Test Case: FltM_ECC_CallBackFunc.001
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.002
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.EXPECTED:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.003
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.pErrorInfo[0].injectBitErrCnt:1
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.return:1
TEST.VALUE:uut_prototype_stubs.SDL_ECC_clearNIntrPending.return:1
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.004
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.pErrorInfo[0].injectBitErrCnt:0
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.return:1
TEST.VALUE:uut_prototype_stubs.SDL_ECC_clearNIntrPending.return:1
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.005
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Ecc.SDL_REG32_RD_RAW
TEST.STUB:FltM_Soc_Ecc.SDL_REG32_WR_RAW
TEST.VALUE:FltM_Soc_Ecc.SDL_REG32_RD_RAW.return:0
TEST.VALUE:FltM_Soc_Ecc.SDL_REG32_WR_RAW.v:1
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:28
TEST.EXPECTED:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:28
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.006
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Ecc.SDL_REG32_RD_RAW
TEST.STUB:FltM_Soc_Ecc.SDL_REG32_WR_RAW
TEST.VALUE:FltM_Soc_Ecc.SDL_REG32_RD_RAW.return:0
TEST.VALUE:FltM_Soc_Ecc.SDL_REG32_WR_RAW.v:1
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:29
TEST.EXPECTED:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:29
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.007
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.pErrorInfo[0].injectBitErrCnt:0
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.return:1
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getESMErrorInfo.return:1
TEST.VALUE:uut_prototype_stubs.SDL_ECC_clearNIntrPending.return:1
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.008
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.pErrorInfo[0].injectBitErrCnt:1
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.return:0
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.EXPECTED:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.009
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.pErrorInfo[0].injectBitErrCnt:0
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.return:0
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.EXPECTED:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.010
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.pErrorInfo[0].injectBitErrCnt:0
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.return:0
TEST.VALUE:uut_prototype_stubs.SDL_ECC_clearNIntrPending.return:1
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.EXPECTED:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.END

-- Test Case: FltM_ECC_CallBackFunc.011
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_CallBackFunc
TEST.NEW
TEST.NAME:FltM_ECC_CallBackFunc.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.pErrorInfo[0].injectBitErrCnt:0
TEST.VALUE:uut_prototype_stubs.SDL_ECC_getErrorInfo.return:0
TEST.VALUE:uut_prototype_stubs.SDL_ECC_ackIntr.return:1
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.EXPECTED:FltM_Soc_Ecc.FltM_ECC_CallBackFunc.intSrc:27
TEST.END

-- Subprogram: FltM_ECC_Init_All

-- Test Case: FltM_ECC_Init_All.001
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_Init_All
TEST.NEW
TEST.NAME:FltM_ECC_Init_All.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_init.return:1
TEST.END

-- Test Case: FltM_ECC_Init_All.002
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_Init_All
TEST.NEW
TEST.NAME:FltM_ECC_Init_All.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_ECC_Init_All.003
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_Init_All
TEST.NEW
TEST.NAME:FltM_ECC_Init_All.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_configECCRam.return:1
TEST.END

-- Subprogram: FltM_ECC_IsInjectParamValid

-- Test Case: FltM_ECC_IsInjectParamValid.001
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.001
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_ONCE
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.002
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.002
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:10
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.003
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.003
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_ONCE
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.004
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.004
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_N_ROW_ONCE
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.005
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.005
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_ONCE
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.006
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.006
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_2BIT_N_ROW_ONCE
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.007
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.007
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_REPEAT
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.008
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.008
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_2BIT_REPEAT
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.009
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.009
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_N_ROW_REPEAT
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.010
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.010
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_2BIT_N_ROW_REPEAT
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.011
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.011
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_2BIT_ONCE
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.012
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.012
TEST.VALUE:FltM.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.aggregatorInstance:1
TEST.VALUE:FltM.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.numRams:1
TEST.VALUE:FltM.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.pMemSubTypes:<<malloc 1>>
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0]:<<malloc 1>>
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0][0].aggregatorInstance:1
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0][0].numRams:3
TEST.VALUE:FltM_Soc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.aggregatorInstance:1
TEST.VALUE:FltM_Soc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.numRams:3
TEST.VALUE:FltM_Soc_Dcc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.aggregatorInstance:1
TEST.VALUE:FltM_Soc_Dcc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.numRams:1
TEST.VALUE:FltM_Soc_Dcc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.pMemSubTypes:<<malloc 1>>
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.aggregator:1
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.ramid:1
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_ONCE
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.SDL_ECC_aggrBaseAddressTable[1]:<<malloc 1>>
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.globalECCConfigs[0]:<<malloc 2>>
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.globalECCConfigs[0][0].aggregatorInstance:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.globalECCConfigs[0][0].numRams:3
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.013
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.013
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0]:<<malloc 1>>
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0][0].aggregatorInstance:10
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0][0].numRams:5
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0][0].pMemSubTypes:<<malloc 1>>
TEST.VALUE:FltM_Soc_Ecc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.aggregatorInstance:10
TEST.VALUE:FltM_Soc_Ecc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.numRams:5
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.aggregator:10
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.ramid:2
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_ONCE
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.return:1
TEST.END

-- Test Case: FltM_ECC_IsInjectParamValid.014
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_IsInjectParamValid
TEST.NEW
TEST.NAME:FltM_ECC_IsInjectParamValid.014
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0]:<<malloc 1>>
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0][0].aggregatorInstance:10
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0][0].numRams:5
TEST.VALUE:FltM.<<GLOBAL>>.globalECCConfigs[0][0].pMemSubTypes:<<malloc 1>>
TEST.VALUE:FltM_Soc_Ecc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.aggregatorInstance:10
TEST.VALUE:FltM_Soc_Ecc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.numRams:5
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.aggregator:10
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.ramid:7
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.errortype:SDL_INJECT_ECC_ERROR_FORCING_1BIT_ONCE
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.return:1
TEST.END

-- Subprogram: FltM_ECC_ReadBack

-- Test Case: FltM_ECC_ReadBack.001
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_ReadBack
TEST.NEW
TEST.NAME:FltM_ECC_ReadBack.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:FltM_Soc_Ecc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.numRams:0
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_ReadBack.return:1
TEST.END

-- Test Case: FltM_ECC_ReadBack.002
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_ReadBack
TEST.NEW
TEST.NAME:FltM_ECC_ReadBack.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ecc_aggrVerifyConfigEccRam.return:1
TEST.VALUE:FltM_Soc_Ecc.<<GLOBAL>>.FLTM_MCU_MCAN1_Config.numRams:1
TEST.END

-- Test Case: FltM_ECC_ReadBack.003
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_ReadBack
TEST.NEW
TEST.NAME:FltM_ECC_ReadBack.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ecc_aggrVerifyConfigEccRam.return:-1
TEST.END

-- Test Case: FltM_ECC_ReadBack.004
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_ECC_ReadBack
TEST.NEW
TEST.NAME:FltM_ECC_ReadBack.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ecc_aggrVerifyConfigEccRam.return:0
TEST.END

-- Subprogram: FltM_runECC_InjectTest

-- Test Case: FltM_runECC_InjectTest.001
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_runECC_InjectTest
TEST.NEW
TEST.NAME:FltM_runECC_InjectTest.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_injectError.return:1
TEST.END

-- Test Case: FltM_runECC_InjectTest.002
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_runECC_InjectTest
TEST.NEW
TEST.NAME:FltM_runECC_InjectTest.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ECC_injectError.pECCErrorConfig[0].pErrMem:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.SDL_ECC_injectError.return:0
TEST.END

-- Test Case: FltM_runECC_InjectTest.003
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_runECC_InjectTest
TEST.NEW
TEST.NAME:FltM_runECC_InjectTest.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid
TEST.VALUE:uut_prototype_stubs.SDL_ECC_injectError.pECCErrorConfig[0].pErrMem:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.SDL_ECC_injectError.return:0
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.return:1
TEST.END

-- Test Case: FltM_runECC_InjectTest.004
TEST.UNIT:FltM_Soc_Ecc
TEST.SUBPROGRAM:FltM_runECC_InjectTest
TEST.NEW
TEST.NAME:FltM_runECC_InjectTest.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid
TEST.VALUE:uut_prototype_stubs.SDL_ECC_injectError.pECCErrorConfig[0].pErrMem:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.SDL_ECC_injectError.return:1
TEST.VALUE:FltM_Soc_Ecc.FltM_ECC_IsInjectParamValid.return:1
TEST.END

-- Unit: FltM_Soc_FlsIntegrity

-- Subprogram: FltM_FlashIntegrity

-- Test Case: FltM_FlashIntegrity.001
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.002
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.003
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_FlashIntegrity.004
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFFFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.005
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:7
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.006
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.007
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:512
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_TextRegionIdx:7
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.008
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:512
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_TextRegionIdx:7
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Result:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.009
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:1024
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_TextRegionIdx:7
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Result:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.010
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:0xFFFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_TextRegionIdx:7
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Result:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.011
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:0xFFFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionHalfBlock_Length:0x100000
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_TextRegionIdx:7
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Result:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.012
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.012
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Result:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.END

-- Test Case: FltM_FlashIntegrity.013
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.013
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFFFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Test Case: FltM_FlashIntegrity.014
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity
TEST.NEW
TEST.NAME:FltM_FlashIntegrity.014
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.g_checksum[0]:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Address_Processed:0xFFFF
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.RegionBlock_Length:512
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_TextRegionIdx:7
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Result:1
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.CheckSum_Process:0
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.VALUE:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].StartAddress:30
TEST.EXPECTED:FltM_Soc_FlsIntegrity.<<GLOBAL>>.FltM_FlsIntegrityConfig[0].EndAddress:10
TEST.END

-- Subprogram: FltM_FlashIntegrity_Init

-- Test Case: FltM_FlashIntegrity_Init.001
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlashIntegrity_Init
TEST.NEW
TEST.NAME:FltM_FlashIntegrity_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.FltM_FlashIntegrity_Init.return:1
TEST.END

-- Subprogram: FltM_FlsIntegrity_GetStatus

-- Test Case: FltM_FlsIntegrity_GetStatus.001
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlsIntegrity_GetStatus
TEST.NEW
TEST.NAME:FltM_FlsIntegrity_GetStatus.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.FltM_FlsIntegrity_GetStatus.Status:<<malloc 9>>
TEST.VALUE:FltM_Soc_FlsIntegrity.FltM_FlsIntegrity_GetStatus.Status:<<null>>
TEST.END

-- Test Case: FltM_FlsIntegrity_GetStatus.002
TEST.UNIT:FltM_Soc_FlsIntegrity
TEST.SUBPROGRAM:FltM_FlsIntegrity_GetStatus
TEST.NEW
TEST.NAME:FltM_FlsIntegrity_GetStatus.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_FlsIntegrity.FltM_FlsIntegrity_GetStatus.Status:<<malloc 1>>
TEST.END

-- Unit: FltM_Soc_Pok

-- Subprogram: FltM_POK_CallBackFunc

-- Test Case: FltM_POK_CallBackFunc.001
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.sdlGetInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_getBaseaddr.return:true
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].hystCtrl:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].hystCtrlOV:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].trim:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].trimOV:0
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].detectionStatus:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].pokEnSelSrcCtrl:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].deglitch:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.instance:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.return:0
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.return:1
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.return:0
TEST.END

-- Test Case: FltM_POK_CallBackFunc.002
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_ESM_clrNError.return:1
TEST.END

-- Test Case: FltM_POK_CallBackFunc.003
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:1
TEST.END

-- Test Case: FltM_POK_CallBackFunc.004
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:0
TEST.END

-- Test Case: FltM_POK_CallBackFunc.005
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:5
TEST.END

-- Test Case: FltM_POK_CallBackFunc.006
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.sdlGetInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_getBaseaddr.return:true
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.return:1
TEST.END

-- Test Case: FltM_POK_CallBackFunc.007
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.sdlGetInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_getBaseaddr.return:true
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:0
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.return:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.return:0
TEST.END

-- Test Case: FltM_POK_CallBackFunc.008
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.sdlGetInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_getBaseaddr.return:true
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.return:0
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.pConfig:<<null>>
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.return:1
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.return:0
TEST.END

-- Test Case: FltM_POK_CallBackFunc.009
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.sdlGetInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_getBaseaddr.return:true
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:0
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.return:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.return:0
TEST.END

-- Test Case: FltM_POK_CallBackFunc.010
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.sdlGetInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_getBaseaddr.return:true
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].hystCtrl:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].hystCtrlOV:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:2
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].trim:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].trimOV:0
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].detectionStatus:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].pokEnSelSrcCtrl:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].deglitch:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.instance:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.return:0
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.return:1
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.return:0
TEST.END

-- Test Case: FltM_POK_CallBackFunc.011
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_CallBackFunc
TEST.NEW
TEST.NAME:FltM_POK_CallBackFunc.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.sdlGetInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_getBaseaddr.return:true
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].hystCtrl:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].hystCtrlOV:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:2
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].trim:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].trimOV:0
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].detectionStatus:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].pokEnSelSrcCtrl:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].deglitch:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.instance:1
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.return:1
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.return:1
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.return:0
TEST.END

-- Subprogram: FltM_POK_Init

-- Test Case: FltM_POK_Init.001
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_Init
TEST.NEW
TEST.NAME:FltM_POK_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.FltM_POK_setConfig
TEST.STUB:FltM_Soc_Pok.FltM_POK_IsValidPrgInstance
TEST.VALUE:FltM_Soc_Pok.FltM_POK_setConfig.return:1
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidPrgInstance.return:0
TEST.END

-- Test Case: FltM_POK_Init.002
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_Init
TEST.NEW
TEST.NAME:FltM_POK_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.FltM_POK_IsValidInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_enablePP.return:1
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidInstance.return:0
TEST.END

-- Test Case: FltM_POK_Init.003
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_Init
TEST.NEW
TEST.NAME:FltM_POK_Init.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.FltM_POK_IsValidInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_enablePP.return:0
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidInstance.return:1
TEST.END

-- Test Case: FltM_POK_Init.004
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_Init
TEST.NEW
TEST.NAME:FltM_POK_Init.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.FltM_POK_IsValidInstance
TEST.VALUE:uut_prototype_stubs.SDL_POK_enablePP.return:0
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.return:1
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidInstance.return:1
TEST.END

-- Subprogram: FltM_POK_IsValidInstance

-- Test Case: BASIS-PATH-001
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_IsValidInstance
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (instance >= (SDL_POK_Inst)0 && instance <= (SDL_POK_Inst)9) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidInstance.instance:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_IsValidInstance
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (instance >= (SDL_POK_Inst)0 && instance <= (SDL_POK_Inst)9) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidInstance.instance:10
TEST.END

-- Subprogram: FltM_POK_IsValidPrgInstance

-- Test Case: BASIS-PATH-001
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_IsValidPrgInstance
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (instance >= (SDL_PRG_Inst)0 && instance <= (SDL_PRG_Inst)2) ==> FALSE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidPrgInstance.instance:<<MIN>>
TEST.END

-- Test Case: BASIS-PATH-002
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_IsValidPrgInstance
TEST.NEW
TEST.NAME:BASIS-PATH-002
TEST.BASIS_PATH:2 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 2
      (1) if (instance >= (SDL_PRG_Inst)0 && instance <= (SDL_PRG_Inst)2) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidPrgInstance.instance:3
TEST.END

-- Subprogram: FltM_POK_setConfig

-- Test Case: FltM_POK_setConfig.001
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:FltM_POK_setConfig
TEST.NEW
TEST.NAME:FltM_POK_setConfig.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SDL_POK_init.return:1
TEST.END

-- Subprogram: deactivate_trigger

-- Test Case: deactivate_trigger.001
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:deactivate_trigger
TEST.NEW
TEST.NAME:deactivate_trigger.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.sdlGetInstance
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].voltDetMode:11
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].trim:45
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.pPokVal[0].trimOV:128
TEST.VALUE:uut_prototype_stubs.SDL_pokGetControl.return:1
TEST.END

-- Subprogram: sdlGetInstance

-- Test Case: sdlGetInstance.001
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 9>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<null>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:81
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:81
TEST.END

-- Test Case: sdlGetInstance.002
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<null>>
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<null>>
TEST.END

-- Test Case: sdlGetInstance.003
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<null>>
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<null>>
TEST.END

-- Test Case: sdlGetInstance.004
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Pok.FltM_POK_IsValidInstance
TEST.VALUE:FltM_Soc_Pok.FltM_POK_IsValidInstance.return:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:77
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:77
TEST.END

-- Test Case: sdlGetInstance.005
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:70
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:70
TEST.END

-- Test Case: sdlGetInstance.006
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:76
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:76
TEST.END

-- Test Case: sdlGetInstance.007
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.007
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:69
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:69
TEST.END

-- Test Case: sdlGetInstance.008
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.008
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:73
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:73
TEST.END

-- Test Case: sdlGetInstance.009
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.009
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:66
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:66
TEST.END

-- Test Case: sdlGetInstance.010
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.010
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:72
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:72
TEST.END

-- Test Case: sdlGetInstance.011
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:71
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:71
TEST.END

-- Test Case: sdlGetInstance.012
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.012
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:64
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:64
TEST.END

-- Test Case: sdlGetInstance.013
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.013
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:65
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:65
TEST.END

-- Test Case: sdlGetInstance.014
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.014
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:80
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:80
TEST.END

-- Test Case: sdlGetInstance.015
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.015
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:79
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:79
TEST.END

-- Test Case: sdlGetInstance.016
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.016
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:78
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:78
TEST.END

-- Test Case: sdlGetInstance.017
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.017
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:81
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:81
TEST.END

-- Test Case: sdlGetInstance.018
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.018
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:6
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:82
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.instance[0]:6
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:82
TEST.END

-- Test Case: sdlGetInstance.019
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.019
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 9>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<null>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.instance:<<null>>
TEST.END

-- Test Case: sdlGetInstance.020
TEST.UNIT:FltM_Soc_Pok
TEST.SUBPROGRAM:sdlGetInstance
TEST.NEW
TEST.NAME:sdlGetInstance.020
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.instance[0]:0
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig:<<malloc 1>>
TEST.VALUE:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:100
TEST.EXPECTED:FltM_Soc_Pok.sdlGetInstance.esm_err_sig[0]:100
TEST.END

-- Unit: FltM_Soc_Ppu

-- Subprogram: FltM_FwlExceptionHandler

-- Test Case: FltM_FwlExceptionHandler.001
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_FwlExceptionHandler
TEST.NEW
TEST.NAME:FltM_FwlExceptionHandler.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Subprogram: FltM_PPU_ReadBack

-- Test Case: FltM_PPU_ReadBack.001
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_PPU_ReadBack
TEST.NEW
TEST.NAME:FltM_PPU_ReadBack.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_PPU_ReadBack.002
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_PPU_ReadBack
TEST.NEW
TEST.NAME:FltM_PPU_ReadBack.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Sciclient_firewallGetRegion.return:1
TEST.END

-- Test Case: FltM_PPU_ReadBack.003
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_PPU_ReadBack
TEST.NEW
TEST.NAME:FltM_PPU_ReadBack.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Sciclient_firewallGetRegion.resp[0].control:1
TEST.END

-- Test Case: FltM_PPU_ReadBack.004
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_PPU_ReadBack
TEST.NEW
TEST.NAME:FltM_PPU_ReadBack.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].control:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_1:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_2:0
TEST.VALUE:uut_prototype_stubs.Sciclient_firewallGetRegion.resp[0].permissions[0]:1
TEST.END

-- Test Case: FltM_PPU_ReadBack.005
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_PPU_ReadBack
TEST.NEW
TEST.NAME:FltM_PPU_ReadBack.005
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].control:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_1:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_2:0
TEST.VALUE:uut_prototype_stubs.Sciclient_firewallGetRegion.resp[0].permissions[1]:1
TEST.END

-- Test Case: FltM_PPU_ReadBack.006
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_PPU_ReadBack
TEST.NEW
TEST.NAME:FltM_PPU_ReadBack.006
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].control:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_0:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_1:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Ppu_Config[0].permissions_2:0
TEST.VALUE:uut_prototype_stubs.Sciclient_firewallGetRegion.resp[0].permissions[2]:1
TEST.END

-- Subprogram: FltM_Ppu_FireWallConfigure

-- Test Case: FltM_Ppu_FireWallConfigure.001
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_Ppu_FireWallConfigure
TEST.NEW
TEST.NAME:FltM_Ppu_FireWallConfigure.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_Ppu_FireWallConfigure.002
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_Ppu_FireWallConfigure
TEST.NEW
TEST.NAME:FltM_Ppu_FireWallConfigure.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:FltM_Soc_Ppu.<<GLOBAL>>.Ppu_Config[0].control:0xA
TEST.END

-- Test Case: FltM_Ppu_FireWallConfigure.003
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_Ppu_FireWallConfigure
TEST.NEW
TEST.NAME:FltM_Ppu_FireWallConfigure.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Sciclient_firewallSetRegion.return:1
TEST.VALUE:FltM_Soc_Ppu.<<GLOBAL>>.Ppu_Config[0].control:0xA
TEST.END

-- Test Case: FltM_Ppu_FireWallConfigure.004
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_Ppu_FireWallConfigure
TEST.NEW
TEST.NAME:FltM_Ppu_FireWallConfigure.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.Sciclient_firewallChangeOwnerInfo.return:1
TEST.VALUE:uut_prototype_stubs.Sciclient_firewallSetRegion.return:1
TEST.VALUE:FltM_Soc_Ppu.<<GLOBAL>>.Ppu_Config[0].control:0xA
TEST.END

-- Subprogram: FltM_Ppu_Init

-- Test Case: FltM_Ppu_Init.001
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_Ppu_Init
TEST.NEW
TEST.NAME:FltM_Ppu_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.END

-- Test Case: FltM_Ppu_Init.002
TEST.UNIT:FltM_Soc_Ppu
TEST.SUBPROGRAM:FltM_Ppu_Init
TEST.NEW
TEST.NAME:FltM_Ppu_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::FltM::FltM_Soc_Detailed_Design::FltM_Soc_ClassDiagram
Requirement_PE4TI29141-9274
TEST.END_NOTES:
TEST.STUB:FltM_Soc_Ppu.FltM_Ppu_FireWallConfigure
TEST.VALUE:FltM_Soc_Ppu.FltM_Ppu_FireWallConfigure.return:1
TEST.END
