-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : CORTST_VCAST_HT
-- Unit(s) Under Test: CorTst
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CorTst

-- Subprogram: CorTst_Abort

-- Test Case: CorTst_Abort.bgnd_init_invalid_atomic
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Abort
TEST.NEW
TEST.NAME:CorTst_Abort.bgnd_init_invalid_atomic
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:0
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.END

-- Test Case: CorTst_Abort.bgndstate_valid_automic
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Abort
TEST.NEW
TEST.NAME:CorTst_Abort.bgndstate_valid_automic
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_OK
TEST.END

-- Test Case: CorTst_Abort.invalid_state_atomic
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Abort
TEST.NEW
TEST.NAME:CorTst_Abort.invalid_state_atomic
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_OK
TEST.END

-- Test Case: CorTst_Abort.valid.inputs
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Abort
TEST.NEW
TEST.NAME:CorTst_Abort.valid.inputs
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.END

-- Test Case: CorTst_Abort_init
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Abort
TEST.NEW
TEST.NAME:CorTst_Abort_init
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_OK
TEST.END

-- Test Case: CorTst_Abort_init_bgndrun
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Abort
TEST.NEW
TEST.NAME:CorTst_Abort_init_bgndrun
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.END

-- Test Case: CorTst_Abort_init_bgndrun_atomic
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Abort
TEST.NEW
TEST.NAME:CorTst_Abort_init_bgndrun_atomic
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.END

-- Test Case: CorTst_Abort_init_invalid_atomic
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Abort
TEST.NEW
TEST.NAME:CorTst_Abort_init_invalid_atomic
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:0
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.END

-- Subprogram: CorTst_DeInit

-- Test Case: CorTst_DeInit_init
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_DeInit
TEST.NEW
TEST.NAME:CorTst_DeInit_init
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:0
TEST.END

-- Test Case: CorTst_DeInit_init.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_DeInit
TEST.NEW
TEST.NAME:CorTst_DeInit_init.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:0
TEST.END

-- Test Case: CorTst_DeInit_init.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_DeInit
TEST.NEW
TEST.NAME:CorTst_DeInit_init.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:0
TEST.END

-- Test Case: CorTst_DeInit_init_bnginit
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_DeInit
TEST.NEW
TEST.NAME:CorTst_DeInit_init_bnginit
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.END

-- Subprogram: CorTst_GetCurrentStatus

-- Test Case: CorTst_GetCurrentStatus_ini
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetCurrentStatus
TEST.NEW
TEST.NAME:CorTst_GetCurrentStatus_ini
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_OKAY
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_OKAY
TEST.VALUE:CorTst.CorTst_GetCurrentStatus.ErrOk:<<malloc 1>>
TEST.END

-- Test Case: CorTst_GetCurrentStatus_ini.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetCurrentStatus
TEST.NEW
TEST.NAME:CorTst_GetCurrentStatus_ini.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_OKAY
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_OKAY
TEST.VALUE:CorTst.CorTst_GetCurrentStatus.ErrOk:<<malloc 1>>
TEST.END

-- Test Case: CorTst_GetCurrentStatus_ini.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetCurrentStatus
TEST.NEW
TEST.NAME:CorTst_GetCurrentStatus_ini.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_OKAY
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_OKAY
TEST.VALUE:CorTst.CorTst_GetCurrentStatus.ErrOk:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_GetCurrentStatus.ErrOk[0].returnvalue:CORTST_E_NOT_TESTED
TEST.END

-- Subprogram: CorTst_GetFgndSignature

-- Test Case: CorTst_GetFgndSignature.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetFgndSignature
TEST.NEW
TEST.NAME:CorTst_GetFgndSignature.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.EXPECTED:CorTst.CorTst_GetFgndSignature.return:<<ZERO>>
TEST.END

-- Test Case: CorTst_GetFgndSignature.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetFgndSignature
TEST.NEW
TEST.NAME:CorTst_GetFgndSignature.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.CorTst_GetFgndSignature.return:<<ZERO>>
TEST.END

-- Subprogram: CorTst_GetSignature

-- Test Case: CorTst_GetSignature_ini
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetSignature
TEST.NEW
TEST.NAME:CorTst_GetSignature_ini
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.EXPECTED:CorTst.CorTst_GetSignature.return.SignatureValue:0
TEST.EXPECTED:CorTst.CorTst_GetSignature.return.CorTstTestIntervalId:0
TEST.END

-- Test Case: CorTst_GetSignature_ini.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetSignature
TEST.NEW
TEST.NAME:CorTst_GetSignature_ini.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.CorTst_GetSignature.return.SignatureValue:0
TEST.EXPECTED:CorTst.CorTst_GetSignature.return.CorTstTestIntervalId:0
TEST.END

-- Subprogram: CorTst_GetState

-- Test Case: CorTst_GetState_ini
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetState
TEST.NEW
TEST.NAME:CorTst_GetState_ini
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.CorTst_GetState.return:CORTST_INIT
TEST.END

-- Subprogram: CorTst_GetVersionInfo

-- Test Case: CorTst_GetVersionInfo.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetVersionInfo
TEST.NEW
TEST.NAME:CorTst_GetVersionInfo.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_GetVersionInfo.versioninfo:<<null>>
TEST.EXPECTED:CorTst.CorTst_GetVersionInfo.versioninfo:<<null>>
TEST.END

-- Test Case: CorTst_GetVersionInfo.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_GetVersionInfo
TEST.NEW
TEST.NAME:CorTst_GetVersionInfo.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_GetVersionInfo.versioninfo:<<malloc 1>>
TEST.END

-- Subprogram: CorTst_Init

-- Test Case: CorTst_Init_Invalidinput
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Init
TEST.NEW
TEST.NAME:CorTst_Init_Invalidinput
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_UNINIT
TEST.VALUE:CorTst.CorTst_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Init.ConfigPtr[0].CorTstBlockFgnd:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Init.ConfigPtr[0].CorTstBlockFgnd[0].testId:0
TEST.VALUE:CorTst.CorTst_Init.ConfigPtr[0].CorTstBlockBgnd:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Init.ConfigPtr[0].CorTstBlockBgnd[0].testId:0
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.END

-- Test Case: CorTst_Init_init
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Init
TEST.NEW
TEST.NAME:CorTst_Init_init
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_UNINIT
TEST.VALUE:CorTst.CorTst_Init.ConfigPtr:<<null>>
TEST.EXPECTED:CorTst.CorTst_Init.ConfigPtr:<<null>>
TEST.END

-- Test Case: CorTst_Init_uninit
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Init
TEST.NEW
TEST.NAME:CorTst_Init_uninit
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.CorTst_Init.ConfigPtr:<<null>>
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.END

-- Subprogram: CorTst_MainFunction

-- Test Case: CorTst_MainFunction.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:0
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockFgnd:<<null>>
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockBgnd:<<null>>
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.END

-- Test Case: CorTst_MainFunction.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockFgnd:<<null>>
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockBgnd:<<null>>
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_OK
TEST.END

-- Test Case: CorTst_MainFunction.003
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_UNINIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:0
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockFgnd:<<null>>
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockBgnd:<<null>>
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.END

-- Test Case: CorTst_MainFunction.004
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:0
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockFgnd:<<null>>
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockBgnd:<<null>>
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.END

-- Test Case: CorTst_MainFunction.005
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction.005
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_UNINIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:0
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockFgnd:<<null>>
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockBgnd:<<null>>
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_UNINIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.END

-- Test Case: CorTst_MainFunction.006
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction.006
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:0
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentTestIntervalId:4
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockFgnd:<<null>>
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlock.CorTstBlockBgnd:<<null>>
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.END

-- Test Case: CorTst_MainFunction.run_bgnd
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction.run_bgnd
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:3
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CorTst_MainFunction_abortreq
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_abortreq
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:0
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_MainFunction_init
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_init
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_MainFunction_rejectabortreq
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_rejectabortreq
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:2
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_OK
TEST.END

-- Test Case: CorTst_MainFunction_rejectabortreq.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_rejectabortreq.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_CpuTestStatus:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:2
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_OK
TEST.END

-- Test Case: CorTst_MainFunction_testcount
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_testcount
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentTestIntervalId:4
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.END

-- Test Case: CorTst_MainFunction_testcount.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_testcount.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:2
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentTestIntervalId:4
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_OKAY
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_OKAY
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_MainFunction_testcount.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_testcount.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.STUB:CorTst.CorTst_Process
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_CpuTestStatus:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:2
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentTestIntervalId:4
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.CorTst_Process.return:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.END

-- Test Case: CorTst_MainFunction_testcount.003
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_testcount.003
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.STUB:CorTst.CorTst_Process
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_CpuTestStatus:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:2
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentTestIntervalId:4
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.CorTst_Process.return:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.END

-- Test Case: CorTst_MainFunction_testcount.004
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_testcount.004
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.AtomicIntervalCount:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.CurrentTestIntervalId:4
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.END

-- Test Case: CorTst_MainFunction_uninit
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_uninit
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_UNINIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.END

-- Test Case: CorTst_MainFunction_uninit.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_MainFunction
TEST.NEW
TEST.NAME:CorTst_MainFunction_uninit.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_UNINIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_TESTED
TEST.END

-- Subprogram: CorTst_Process

-- Test Case: CorTst_Process.CORTST_E_OKAY
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.CORTST_E_OKAY
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_Process.CORTST_E_OKAY.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.CORTST_E_OKAY.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Process.return:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_Process.CORTST_E_OKAY.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.CORTST_E_OKAY.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Process.return:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_Process.CORTST_E_OKAY.003
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.CORTST_E_OKAY.003
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.STUB:CorTst.CorTst_TestALU
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.VALUE:CorTst.CorTst_TestALU.return:CORTST_E_NOT_OK
TEST.END

-- Test Case: CorTst_Process.TESTED
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.TESTED
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_Process.TESTED.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.TESTED.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstAlu:NOT_SELECTED
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_Process.TESTED.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.TESTED.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstAlu:NOT_SELECTED
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstMemoryIf:NOT_SELECTED
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_Process.TESTED.003
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.TESTED.003
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstAddress:NOT_SELECTED
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstAlu:NOT_SELECTED
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstMemoryIf:NOT_SELECTED
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_Process.TESTED.004
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.TESTED.004
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstAddress:NOT_SELECTED
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstAlu:NOT_SELECTED
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstMemoryIf:NOT_SELECTED
TEST.VALUE:CorTst.CorTst_Process.TestPtr[0].CorTstRegister:NOT_SELECTED
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Test Case: CorTst_Process.TESTED_NOT_OKAY
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Process
TEST.NEW
TEST.NAME:CorTst_Process.TESTED_NOT_OKAY
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_Process.TestPtr:<<malloc 1>>
TEST.EXPECTED:CorTst.CorTst_Process.return:CORTST_E_OKAY
TEST.END

-- Subprogram: CorTst_ReportDetError

-- Test Case: CorTst_ReportDetError.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_ReportDetError
TEST.NEW
TEST.NAME:CorTst_ReportDetError.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.CorTst_ReportDetError.APIID:1
TEST.VALUE:CorTst.CorTst_ReportDetError.ErrorID:1
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_State:CORTST_UNINIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_WaitingState:CORTST_UNINIT
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.CorTst_ReportDetError.APIID:1
TEST.EXPECTED:CorTst.CorTst_ReportDetError.ErrorID:1
TEST.END

-- Subprogram: CorTst_Start

-- Test Case: CorTst_Start.invalid_cortst_state
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Start
TEST.NEW
TEST.NAME:CorTst_Start.invalid_cortst_state
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_ABORT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlockFgnd[0].testId:0
TEST.VALUE:CorTst.CorTst_Start.TestId:1
TEST.END

-- Test Case: CorTst_Start_invalidtestid
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Start
TEST.NEW
TEST.NAME:CorTst_Start_invalidtestid
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlockFgnd[0].testId:0
TEST.VALUE:CorTst.CorTst_Start.TestId:0
TEST.EXPECTED:CorTst.CorTst_Start.return:0
TEST.END

-- Test Case: CorTst_Start_invalidtestid.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Start
TEST.NEW
TEST.NAME:CorTst_Start_invalidtestid.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlockFgnd[0].testId:2
TEST.VALUE:CorTst.CorTst_Start.TestId:2
TEST.END

-- Test Case: CorTst_Start_invalidtestid.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Start
TEST.NEW
TEST.NAME:CorTst_Start_invalidtestid.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_INIT
TEST.VALUE:CorTst.<<GLOBAL>>.CorTstBlockFgnd[0].testId:1
TEST.VALUE:CorTst.CorTst_Start.TestId:0
TEST.EXPECTED:CorTst.CorTst_Start.return:0
TEST.END

-- Test Case: CorTst_Start_validinput_state_bgndrun
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Start
TEST.NEW
TEST.NAME:CorTst_Start_validinput_state_bgndrun
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.CorTst_Start.TestId:0
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.CorTst_Start.return:0
TEST.END

-- Test Case: CorTst_Start_validinput_state_bgndrun.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_Start
TEST.NEW
TEST.NAME:CorTst_Start_validinput_state_bgndrun.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.STUB:CorTst.CorTst_Process
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.CorTst_Start.TestId:0
TEST.VALUE:CorTst.CorTst_Process.return:CORTST_E_NOT_OK
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.ResultBuffer:CORTST_E_NOT_TESTED
TEST.EXPECTED:CorTst.CorTst_Start.return:0
TEST.END

-- Subprogram: CorTst_TestALU

-- Test Case: testALU.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestALU
TEST.NEW
TEST.NAME:testALU.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.EXPECTED:CorTst.CorTst_TestALU.return:CORTST_E_OKAY
TEST.END

-- Test Case: testALU.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestALU
TEST.NEW
TEST.NAME:testALU.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.EXPECTED:CorTst.CorTst_TestALU.return:CORTST_E_OKAY
TEST.END

-- Test Case: testALU.003
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestALU
TEST.NEW
TEST.NAME:testALU.003
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.EXPECTED:CorTst.CorTst_TestALU.return:CORTST_E_OKAY
TEST.END

-- Subprogram: CorTst_TestAddressGeneration

-- Test Case: CorTst_TestAddressGeneration.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestAddressGeneration
TEST.NEW
TEST.NAME:CorTst_TestAddressGeneration.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CorTst_TestAddressGeneration.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestAddressGeneration
TEST.NEW
TEST.NAME:CorTst_TestAddressGeneration.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Test Case: CorTst_TestAddressGeneration.003
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestAddressGeneration
TEST.NEW
TEST.NAME:CorTst_TestAddressGeneration.003
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_AddressGenerationStatus:1
TEST.EXPECTED:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.END

-- Subprogram: CorTst_TestCoreRegister

-- Test Case: testCoreRegister.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestCoreRegister
TEST.NEW
TEST.NAME:testCoreRegister.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.EXPECTED:CorTst.CorTst_TestCoreRegister.return:CORTST_E_OKAY
TEST.END

-- Test Case: testCoreRegister.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestCoreRegister
TEST.NEW
TEST.NAME:testCoreRegister.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_CpuTestStatus:1
TEST.VALUE:CorTst.CorTst_TestCoreRegister.return:CORTST_E_OKAY
TEST.EXPECTED:CorTst.CorTst_TestCoreRegister.return:CORTST_E_NOT_OK
TEST.END

-- Subprogram: CorTst_TestMemoryInterface

-- Test Case: CorTst_TestMemoryInterface.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestMemoryInterface
TEST.NEW
TEST.NAME:CorTst_TestMemoryInterface.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.END

-- Test Case: CorTst_TestMemoryInterface.002
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestMemoryInterface
TEST.NEW
TEST.NAME:CorTst_TestMemoryInterface.002
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_MemoryInterfaceTestStatus:1
TEST.END

-- Test Case: CorTst_TestMemoryInterface.003
TEST.UNIT:CorTst
TEST.SUBPROGRAM:CorTst_TestMemoryInterface
TEST.NEW
TEST.NAME:CorTst_TestMemoryInterface.003
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.VALUE:CorTst.<<GLOBAL>>.CorTst_State:CORTST_RUNNING_BGND
TEST.END

-- Subprogram: Cortst_AddressGenerationFail

-- Test Case: Cortst_AddressGenerationFail.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:Cortst_AddressGenerationFail
TEST.NEW
TEST.NAME:Cortst_AddressGenerationFail.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.END

-- Subprogram: Cortst_CpuTestFail

-- Test Case: cortst_cputestfail.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:Cortst_CpuTestFail
TEST.NEW
TEST.NAME:cortst_cputestfail.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.EXPECTED:CorTst.<<GLOBAL>>.CorTst_Infoptr.OverallBngResultBuffer:CORTST_E_NOT_OK
TEST.END

-- Subprogram: Cortst_MemoryInterfaceFail

-- Test Case: Cortst_MemoryInterfaceFail.001
TEST.UNIT:CorTst
TEST.SUBPROGRAM:Cortst_MemoryInterfaceFail
TEST.NEW
TEST.NAME:Cortst_MemoryInterfaceFail.001
TEST.NOTES:
SoftwareArchitecture::MCAL::CorTst::CorTst_Detailed_Design::CorTst_Class_Diagram
Requirement_PE4TI29141-6449
TEST.END_NOTES:
TEST.END
