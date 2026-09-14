-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RAMTST_UT
-- Unit(s) Under Test: RamTst
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: RamTst

-- Subprogram: RamTst_Allow

-- Test Case: RamTst_Allow_AlreadyRun
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Allow
TEST.NEW
TEST.NAME:RamTst_Allow_AlreadyRun
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.END

-- Test Case: RamTst_Allow_Stop
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Allow
TEST.NEW
TEST.NAME:RamTst_Allow_Stop
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.END

-- Test Case: RamTst_Allow_Stp_Bgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Allow
TEST.NEW
TEST.NAME:RamTst_Allow_Stp_Bgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_WaitingState:RAMTST_EXECUTION_RUNNING
TEST.END

-- Subprogram: RamTst_CacheDisable

-- Test Case: RamTst_CacheDisable.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_CacheDisable
TEST.NEW
TEST.NAME:RamTst_CacheDisable.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.END

-- Subprogram: RamTst_CacheEnable

-- Test Case: RamTst_CacheEnable.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_CacheEnable
TEST.NEW
TEST.NAME:RamTst_CacheEnable.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.END

-- Subprogram: RamTst_ChangeNumberOfTestedCells

-- Test Case: RamTst_ChangeNumberOfTestedCells.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_ChangeNumberOfTestedCells
TEST.NEW
TEST.NAME:RamTst_ChangeNumberOfTestedCells.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:2
TEST.VALUE:RamTst.RamTst_ChangeNumberOfTestedCells.NewNumberOfTestedCells:1
TEST.EXPECTED:RamTst.RamTst_ChangeNumberOfTestedCells.NewNumberOfTestedCells:1
TEST.END

-- Test Case: RamTst_ChangeNumberOfTestedCells_changed
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_ChangeNumberOfTestedCells
TEST.NEW
TEST.NAME:RamTst_ChangeNumberOfTestedCells_changed
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.RamTst_ChangeNumberOfTestedCells.NewNumberOfTestedCells:512
TEST.END

-- Test Case: RamTst_ChangeNumberOfTestedCells_changed.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_ChangeNumberOfTestedCells
TEST.NEW
TEST.NAME:RamTst_ChangeNumberOfTestedCells_changed.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:3
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.RamTst_ChangeNumberOfTestedCells.NewNumberOfTestedCells:512
TEST.END

-- Test Case: RamTst_ChangeNumberOfTestedCells_invalid
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_ChangeNumberOfTestedCells
TEST.NEW
TEST.NAME:RamTst_ChangeNumberOfTestedCells_invalid
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.RamTst_ChangeNumberOfTestedCells.NewNumberOfTestedCells:1000051
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.END

-- Test Case: RamTst_ChangeNumberOfTestedCells_notchanged
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_ChangeNumberOfTestedCells
TEST.NEW
TEST.NAME:RamTst_ChangeNumberOfTestedCells_notchanged
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.RamTst_ChangeNumberOfTestedCells.NewNumberOfTestedCells:512
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.END

-- Test Case: RamTst_ChangeNumberOfTestedCells_overrun
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_ChangeNumberOfTestedCells
TEST.NEW
TEST.NAME:RamTst_ChangeNumberOfTestedCells_overrun
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.END

-- Test Case: RamTst_ChangeNumberOfTestedCells_overrun.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_ChangeNumberOfTestedCells
TEST.NEW
TEST.NAME:RamTst_ChangeNumberOfTestedCells_overrun.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.END

-- Subprogram: RamTst_DeInit

-- Test Case: RamTst_DeInit_Assert
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_DeInit
TEST.NEW
TEST.NAME:RamTst_DeInit_Assert
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:3
TEST.END

-- Test Case: RamTst_DeInit_Init
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_DeInit
TEST.NEW
TEST.NAME:RamTst_DeInit_Init
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.BlockResult[0][0]:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.Result:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.END

-- Subprogram: RamTst_GetAlgParams

-- Test Case: RamTst_GetAlgParams_Bgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetAlgParams
TEST.NEW
TEST.NAME:RamTst_GetAlgParams_Bgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.END

-- Test Case: RamTst_GetAlgParams_Fgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetAlgParams
TEST.NEW
TEST.NAME:RamTst_GetAlgParams_Fgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.EXPECTED:RamTst.RamTst_GetAlgParams.return:1
TEST.END

-- Subprogram: RamTst_GetExecutionStatus

-- Test Case: RamTst_GetExecutionStatus_init
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetExecutionStatus
TEST.NEW
TEST.NAME:RamTst_GetExecutionStatus_init
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.EXPECTED:RamTst.RamTst_GetExecutionStatus.return:RAMTST_EXECUTION_RUNNING
TEST.END

-- Subprogram: RamTst_GetNumberOfTestedCells

-- Test Case: RamTst_GetNumberOfTestedCells_init
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetNumberOfTestedCells
TEST.NEW
TEST.NAME:RamTst_GetNumberOfTestedCells_init
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.EXPECTED:RamTst.RamTst_GetNumberOfTestedCells.return:1024
TEST.END

-- Subprogram: RamTst_GetTestAlgorithm

-- Test Case: RamTst_GetTestAlgorithm_Bgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestAlgorithm
TEST.NEW
TEST.NAME:RamTst_GetTestAlgorithm_Bgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.END

-- Test Case: RamTst_GetTestAlgorithm_Bgnd_overrun
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestAlgorithm
TEST.NEW
TEST.NAME:RamTst_GetTestAlgorithm_Bgnd_overrun
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.EXPECTED:RamTst.RamTst_GetTestAlgorithm.return:RAMTST_ALGORITHM_UNDEFINED
TEST.END

-- Test Case: RamTst_GetTestAlgorithm_Bgnd_overrun.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestAlgorithm
TEST.NEW
TEST.NAME:RamTst_GetTestAlgorithm_Bgnd_overrun.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:2
TEST.EXPECTED:RamTst.RamTst_GetTestAlgorithm.return:RAMTST_ALGORITHM_UNDEFINED
TEST.END

-- Test Case: RamTst_GetTestAlgorithm_Fgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestAlgorithm
TEST.NEW
TEST.NAME:RamTst_GetTestAlgorithm_Fgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.END

-- Test Case: RamTst_GetTestAlgorithm_Fgnd_overrun
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestAlgorithm
TEST.NEW
TEST.NAME:RamTst_GetTestAlgorithm_Fgnd_overrun
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:3
TEST.EXPECTED:RamTst.RamTst_GetTestAlgorithm.return:RAMTST_ALGORITHM_UNDEFINED
TEST.END

-- Subprogram: RamTst_GetTestResult

-- Test Case: RamTst_GetTestResult_Bgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestResult
TEST.NEW
TEST.NAME:RamTst_GetTestResult_Bgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.END

-- Test Case: RamTst_GetTestResult_Fgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestResult
TEST.NEW
TEST.NAME:RamTst_GetTestResult_Fgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.END

-- Subprogram: RamTst_GetTestResultPerBlock

-- Test Case: RamTst_GetTestResultPerBlock_Bgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestResultPerBlock
TEST.NEW
TEST.NAME:RamTst_GetTestResultPerBlock_Bgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.BlockID:1
TEST.END

-- Test Case: RamTst_GetTestResultPerBlock_Bgnd_invalidAlgmid
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestResultPerBlock
TEST.NEW
TEST.NAME:RamTst_GetTestResultPerBlock_Bgnd_invalidAlgmid
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:2
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.BlockID:1
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.return:RAMTST_RESULT_OK
TEST.END

-- Test Case: RamTst_GetTestResultPerBlock_Bgnd_invalidAlgmid.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestResultPerBlock
TEST.NEW
TEST.NAME:RamTst_GetTestResultPerBlock_Bgnd_invalidAlgmid.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:2
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.BlockID:1
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.return:RAMTST_RESULT_OK
TEST.END

-- Test Case: RamTst_GetTestResultPerBlock_Bgnd_invalidAlgmid.002
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestResultPerBlock
TEST.NEW
TEST.NAME:RamTst_GetTestResultPerBlock_Bgnd_invalidAlgmid.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:2
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.BlockID:1
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.return:RAMTST_RESULT_OK
TEST.END

-- Test Case: RamTst_GetTestResultPerBlock_Bgnd_invalidblockid
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestResultPerBlock
TEST.NEW
TEST.NAME:RamTst_GetTestResultPerBlock_Bgnd_invalidblockid
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.BlockResult[1][1]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.BlockID:12
TEST.EXPECTED:RamTst.RamTst_GetTestResultPerBlock.return:RAMTST_RESULT_UNDEFINED
TEST.END

-- Test Case: RamTst_GetTestResultPerBlock_Fgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetTestResultPerBlock
TEST.NEW
TEST.NAME:RamTst_GetTestResultPerBlock_Fgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.BlockID:1
TEST.VALUE:RamTst.RamTst_GetTestResultPerBlock.return:RAMTST_RESULT_OK
TEST.END

-- Subprogram: RamTst_GetVersionInfo

-- Test Case: RamTst_GetVersionInfo
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_GetVersionInfo
TEST.NEW
TEST.NAME:RamTst_GetVersionInfo
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_GetVersionInfo.versioninfo:<<malloc 1>>
TEST.END

-- Subprogram: RamTst_Init

-- Test Case: RamTst_Init_nullptr
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Init
TEST.NEW
TEST.NAME:RamTst_Init_nullptr
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_UNINIT
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr:<<null>>
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_UNINIT
TEST.END

-- Test Case: RamTst_Init_nullptr_alreadyinit
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Init
TEST.NEW
TEST.NAME:RamTst_Init_nullptr_alreadyinit
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstNumberOfAlgParamSets:1
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.END

-- Test Case: RamTst_Init_nullptr_validpter
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Init
TEST.NEW
TEST.NAME:RamTst_Init_nullptr_validpter
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstNumberOfAlgParamSets:1
TEST.END

-- Test Case: RamTst_Init_nullptr_validpter.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Init
TEST.NEW
TEST.NAME:RamTst_Init_nullptr_validpter.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.BlockResult[0][0]:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.Result:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6566
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:2
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstDefaultAlgParamsId:0
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:2
TEST.END

-- Test Case: RamTst_Init_nullptr_validpter.002
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Init
TEST.NEW
TEST.NAME:RamTst_Init_nullptr_validpter.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.BlockResult[0][0]:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.Result:RAMTST_RESULT_NOT_TESTED
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6566
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:2
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstDefaultAlgParamsId:0
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstNumberOfAlgParamSets:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:2
TEST.END

-- Test Case: RamTst_Init_overrun
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Init
TEST.NEW
TEST.NAME:RamTst_Init_overrun
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_ReportDetError
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_UNINIT
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstDefaultAlgParamsId:3
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.RamTst_Init.ConfigPtr[0].RamTstNumberOfAlgParamSets:1
TEST.EXPECTED:RamTst.RamTst_ReportDetError.APIID:0x0
TEST.END

-- Subprogram: RamTst_MainFunction

-- Test Case: RamTst_MainFunction.003
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.004
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.005
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFEE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.006
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:0
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.009
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.009
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFEE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.013
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.013
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.BlockResult[0][0]:RAMTST_RESULT_NOT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.014
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.014
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.015
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.015
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.016
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.016
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0xFFFFF
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:0xFFFFF
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFF
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.017
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.017
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:20
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0xFFFF
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:0x2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFEE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.018
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.018
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0x0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:0x1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.019
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.019
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_WaitingState:RAMTST_EXECUTION_SUSPENDED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0xFF
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:0xFF
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.ATTRIBUTES:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:INPUT_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.020
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.020
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0x0
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:0x2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Test Case: RamTst_MainFunction.021
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_MainFunction
TEST.NEW
TEST.NAME:RamTst_MainFunction.021
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:0x0
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.BgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:0x2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:0xFFFFFFFE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:RamTst_RunFullTest
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.ATTRIBUTES:RamTst.RamTst_ReportDetError.APIID:EXPECTED_BASE=16
TEST.END

-- Subprogram: RamTst_ReportDetError

-- Test Case: RamTst_ReportDetError.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_ReportDetError
TEST.NEW
TEST.NAME:RamTst_ReportDetError.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.END

-- Subprogram: RamTst_RestoreSPCacheData

-- Test Case: RamTst_RestoreSPCacheData.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RestoreSPCacheData
TEST.NEW
TEST.NAME:RamTst_RestoreSPCacheData.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.END

-- Subprogram: RamTst_Resume

-- Test Case: RamTst_Resume_stop
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Resume
TEST.NEW
TEST.NAME:RamTst_Resume_stop
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.END

-- Test Case: RamTst_Resume_suspend
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Resume
TEST.NEW
TEST.NAME:RamTst_Resume_suspend
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.END

-- Test Case: RamTst_Resume_uninit
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Resume
TEST.NEW
TEST.NAME:RamTst_Resume_uninit
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_UNINIT
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_UNINIT
TEST.END

-- Subprogram: RamTst_RunFullTest

-- Test Case: RamTst_RunFullTest.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:3
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.END

-- Test Case: RamTst_RunFullTest.002
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.END

-- Test Case: RamTst_RunFullTest_Run
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.END

-- Test Case: RamTst_RunFullTest_Run.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.END

-- Test Case: RamTst_RunFullTest_Run.002
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:2
TEST.END

-- Test Case: RamTst_RunFullTest_Run.003
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_WALK_PATH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_WALK_PATH_TEST
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.END

-- Test Case: RamTst_RunFullTest_Run.004
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.END

-- Test Case: RamTst_RunFullTest_Run.005
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.return:1
TEST.END

-- Test Case: RamTst_RunFullTest_Run.006
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.return:0
TEST.END

-- Test Case: RamTst_RunFullTest_Run.007
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.return:0
TEST.END

-- Test Case: RamTst_RunFullTest_Run.008
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunFullTest
TEST.NEW
TEST.NAME:RamTst_RunFullTest_Run.008
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.return:1
TEST.END

-- Subprogram: RamTst_RunPartialTest

-- Test Case: RamTst_RunPartialTest.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6555
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_RunPartialTest.BlockId:1
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.RamTst_preprocess.return:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:1111
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:RAMTST_EXITCRITICALSECTION
TEST.VALUE:uut_prototype_stubs.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:RAMTST_EXITCRITICALSECTION
TEST.END

-- Test Case: RamTst_RunPartialTest.002
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1
TEST.END

-- Test Case: RamTst_RunPartialTest.003
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.END

-- Test Case: RamTst_RunPartialTest.004
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.END

-- Test Case: RamTst_RunPartialTest_overrun
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest_overrun
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.RamTst_RunPartialTest.BlockId:5
TEST.END

-- Test Case: RamTst_RunPartialTest_overrun.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest_overrun.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.RamTst_RunPartialTest.BlockId:5
TEST.END

-- Test Case: RamTst_RunPartialTest_overrun.002
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest_overrun.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_RunPartialTest.BlockId:0
TEST.END

-- Test Case: RamTst_RunPartialTest_overrun.003
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest_overrun.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.RamTst_RunPartialTest.BlockId:0
TEST.VALUE:RamTst.RamTst_preprocess.return:1
TEST.END

-- Test Case: RamTst_RunPartialTest_overrun.004
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest_overrun.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndBlockID:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndstartadress:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.BlockResult[0][0]:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.FgndResult.Result:RAMTST_RESULT_OK
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_WALK_PATH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.END

-- Test Case: RamTst_RunPartialTest_overrun.005
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest_overrun.005
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_CHECKERBOARD_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_RunPartialTest.BlockId:0
TEST.END

-- Test Case: RamTst_RunPartialTest_overrun.006
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest_overrun.006
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_RunPartialTest.BlockId:0
TEST.VALUE:RamTst.RamTst_preprocess.return:1
TEST.END

-- Test Case: RamTst_RunPartialTest_overrun.007
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_RunPartialTest
TEST.NEW
TEST.NAME:RamTst_RunPartialTest_overrun.007
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_preprocess
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentBgndAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:0
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.RamTst_NumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstAlgorithm:RAMTST_MARCH_TEST
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstExtNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstMaxNumberOfTestedCells:6565
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfBlocks:1
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstNumberOfTestedCells:1024
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstBlockId:0
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstStartAddress:2
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstEndAddress:3
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstFillPattern:1111
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].BlockPtr[0].RamTstDataBackUpAreaStart:4
TEST.VALUE:RamTst.<<GLOBAL>>.Algconfig[0].RamTstDataBackUpAreaEnd:5
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstDefaultAlgParamsId:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstMinNumberOfTestedCells:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstNumberOfAlgParamSets:1
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_RunPartialTest.BlockId:0
TEST.VALUE:RamTst.RamTst_preprocess.return:0
TEST.END

-- Subprogram: RamTst_SaveSPCacheData

-- Test Case: RamTst_SaveSPCacheData.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_SaveSPCacheData
TEST.NEW
TEST.NAME:RamTst_SaveSPCacheData.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.END

-- Subprogram: RamTst_SelectAlgParams

-- Test Case: RamTst_SelectAlgParams_changed
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_SelectAlgParams
TEST.NEW
TEST.NAME:RamTst_SelectAlgParams_changed
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.VALUE:RamTst.RamTst_SelectAlgParams.NewAlgParamsId:2
TEST.END

-- Test Case: RamTst_SelectAlgParams_invalidid
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_SelectAlgParams
TEST.NEW
TEST.NAME:RamTst_SelectAlgParams_invalidid
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.VALUE:RamTst.RamTst_SelectAlgParams.NewAlgParamsId:12
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.END

-- Test Case: RamTst_SelectAlgParams_invalidid.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_SelectAlgParams
TEST.NEW
TEST.NAME:RamTst_SelectAlgParams_invalidid.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_UNINIT
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.END

-- Test Case: RamTst_SelectAlgParams_invalidid.002
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_SelectAlgParams
TEST.NEW
TEST.NAME:RamTst_SelectAlgParams_invalidid.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.END

-- Test Case: RamTst_SelectAlgParams_notchanged
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_SelectAlgParams
TEST.NEW
TEST.NAME:RamTst_SelectAlgParams_notchanged
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_BACKGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.VALUE:RamTst.RamTst_SelectAlgParams.NewAlgParamsId:2
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_Infoptr.CurrentFgndAlgParamsId:1
TEST.END

-- Subprogram: RamTst_Stop

-- Test Case: RamTst_Stop_BgndRunning
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Stop
TEST.NEW
TEST.NAME:RamTst_Stop_BgndRunning
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.END

-- Test Case: RamTst_Stop_Bgndstop
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Stop
TEST.NEW
TEST.NAME:RamTst_Stop_Bgndstop
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_STOPPED
TEST.END

-- Test Case: RamTst_Stop_init
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Stop
TEST.NEW
TEST.NAME:RamTst_Stop_init
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_UNINIT
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_UNINIT
TEST.END

-- Test Case: RamTst_Stop_suspend
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Stop
TEST.NEW
TEST.NAME:RamTst_Stop_suspend
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.END

-- Subprogram: RamTst_Suspend

-- Test Case: RamTst_Suspend_Bgndruning
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Suspend
TEST.NEW
TEST.NAME:RamTst_Suspend_Bgndruning
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_WaitingState:RAMTST_EXECUTION_SUSPENDED
TEST.END

-- Test Case: RamTst_Suspend_Bgndstop
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Suspend
TEST.NEW
TEST.NAME:RamTst_Suspend_Bgndstop
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.END

-- Test Case: RamTst_Suspend_Fgnd
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Suspend
TEST.NEW
TEST.NAME:RamTst_Suspend_Fgnd
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_RUNNING
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:0
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.END

-- Test Case: RamTst_Suspend_suspend
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_Suspend
TEST.NEW
TEST.NAME:RamTst_Suspend_suspend
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.VALUE:RamTst.<<GLOBAL>>.Mode:RAMTST_MODE_FOREGROUND
TEST.VALUE:RamTst.<<GLOBAL>>.RamTst_Infoptr.BgndExeStatus:1
TEST.EXPECTED:RamTst.<<GLOBAL>>.RamTst_State:RAMTST_EXECUTION_SUSPENDED
TEST.END

-- Subprogram: RamTst_preprocess

-- Test Case: BASIS-PATH-001-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-001-PARTIAL
TEST.BASIS_PATH:1 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-005-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-005-PARTIAL
TEST.BASIS_PATH:5 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      (11) while ((0 == status && RamTstEndAddr > cur_addr) && RamTstBlockPtr->RamTstStartAddress <= cur_addr) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
      Cannot set local variable status in branch 11
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-006-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-006-PARTIAL
TEST.BASIS_PATH:6 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      (11) while ((0 == status && RamTstEndAddr > cur_addr) && RamTstBlockPtr->RamTstStartAddress <= cur_addr) ==> TRUE
      (12) if ((uint32)0UL != *((volatile uint32 *)((uintptr_t)cur_addr))) ==> FALSE
      (13) if (cur_addr <= (0xffffffffU) - (uint32)sizeof(uint32)) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
      Cannot set local variable status in branch 11
      Cannot set dereferenced value of type unsigned long in branch 12
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-008-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-008-PARTIAL
TEST.BASIS_PATH:8 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      (11) while ((0 == status && RamTstEndAddr > cur_addr) && RamTstBlockPtr->RamTstStartAddress <= cur_addr) ==> TRUE
      (12) if ((uint32)0UL != *((volatile uint32 *)((uintptr_t)cur_addr))) ==> TRUE
      (13) if (cur_addr <= (0xffffffffU) - (uint32)sizeof(uint32)) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
      Cannot set local variable status in branch 11
      Cannot set dereferenced value of type unsigned long in branch 12
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-009-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-009-PARTIAL
TEST.BASIS_PATH:9 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> TRUE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-011-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-011-PARTIAL
TEST.BASIS_PATH:11 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> TRUE
      (6) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      (7) if ((uint32)0xffffffffUL != *((volatile uint32 *)((uintptr_t)cur_addr))) ==> FALSE
      (8) if (cur_addr <= (0xffffffffU) - (uint32)sizeof(uint32)) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable RamTst_ReadNMIStatus in branch 6
      Cannot set dereferenced value of type unsigned long in branch 7
      Cannot set status due to assignment
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:4294967292
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL
TEST.BASIS_PATH:12 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> TRUE
      (6) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      (7) if ((uint32)0xffffffffUL != *((volatile uint32 *)((uintptr_t)cur_addr))) ==> FALSE
      (8) if (cur_addr <= (0xffffffffU) - (uint32)sizeof(uint32)) ==> TRUE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable RamTst_ReadNMIStatus in branch 6
      Cannot set dereferenced value of type unsigned long in branch 7
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:1
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-012-PARTIAL.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-012-PARTIAL.001
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> TRUE
      (2) while (RamTstAddress <= RamTstBlockPtr->RamTstEndAddress) ==> FALSE
      (4) while ((Std_ReturnType)0 == status && RamTstBlockPtr->RamTstEndAddress > cur_addr) ==> FALSE
      (7) if (status == (Std_ReturnType)0) ==> FALSE
      (8) if ((uint8)0 == RamTst_ReadNMIStatus) ==> FALSE
      (11) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (13) while (RamTstBlockPtr->RamTstEndAddress >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 4
      Cannot set local variable status in branch 7
      Conflict: Trying to set variable RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstTestPolicy 'equal to' and 'not equal to' same value in branches 1/11
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-013-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-013-PARTIAL
TEST.BASIS_PATH:13 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 13
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> TRUE
      (6) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      (7) if ((uint32)0xffffffffUL != *((volatile uint32 *)((uintptr_t)cur_addr))) ==> TRUE
      (8) if (cur_addr <= (0xffffffffU) - (uint32)sizeof(uint32)) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable RamTst_ReadNMIStatus in branch 6
      Cannot set dereferenced value of type unsigned long in branch 7
      Cannot set status due to assignment
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:4294967292
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: BASIS-PATH-014-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:BASIS-PATH-014-PARTIAL
TEST.BASIS_PATH:14 of 17 (partial)
TEST.NOTES:
This is an automatically generated test case.
   Test Path 14
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> TRUE
      (2) while (RamTstAddress <= RamTstEndAddr) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (14) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
      Conflict: Trying to set variable RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstTestPolicy 'equal to' and 'not equal to' same value in branches 1/14
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.END

-- Test Case: COND_10_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_10_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:9 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 9
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #10, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_10_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_10_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:8 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 8
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #10, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_11_ROW_2_PAIR_c_TTF-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_11_ROW_2_PAIR_c_TTF-PARTIAL
TEST.MCDC_BASIS_PATH:19 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 19
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      (11) while ((0 == status && RamTstEndAddr > cur_addr) && RamTstBlockPtr->RamTstStartAddress <= cur_addr) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #11, subcondition "c".
         Condition a ==> TRUE
         Condition b ==> TRUE
         Condition c ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 11
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:4294967294
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_11_ROW_3_PAIR_b_TFT-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_11_ROW_3_PAIR_b_TFT-PARTIAL
TEST.MCDC_BASIS_PATH:18 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 18
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> TRUE
      (11) while ((0 == status && RamTstEndAddr > cur_addr) && RamTstBlockPtr->RamTstStartAddress <= cur_addr) ==> FALSE
      Row number 3 forms a pair with Row 1 for Condition #11, subcondition "b".
         Condition a ==> TRUE
         Condition b ==> FALSE
         Condition c ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable status in branch 11
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_14_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_14_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:11 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 11
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (14) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #14, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
      Conflict: Trying to set variable RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstTestPolicy 'equal to' and 'not equal to' same value in branches 1/14
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.END

-- Test Case: COND_14_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_14_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:10 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 10
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #14, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_15_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_15_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:14 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 14
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (14) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> TRUE
      (15) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #15, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
      Conflict: Trying to set variable RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstTestPolicy 'equal to' and 'not equal to' same value in branches 1/14
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_16_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_16_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:12 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 12
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      (10) if (0 == RamTst_ReadNMIStatus) ==> FALSE
      (16) while (RamTstEndAddr >= RamTstAddress) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #16, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
      Cannot set local variable status in branch 9
      Cannot set local variable RamTst_ReadNMIStatus in branch 10
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_2_ROW_2_PAIR_a_F
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_2_ROW_2_PAIR_a_F
TEST.MCDC_BASIS_PATH:30 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 30
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> TRUE
      (2) while (RamTstAddress <= RamTstEndAddr) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #2, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.END

-- Test Case: COND_3_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_3_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:32 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 32
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> TRUE
      (2) while (RamTstAddress <= RamTstEndAddr) ==> TRUE
      (3) if (RamTstAddress <= (0xffffffffU) - (uint32)sizeof(uint32)) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #3, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Conflict: Cannot resolve multiple comparisons ( RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstStartAddress ) in branches 2/3
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_NON_DESTRUCTIVE
TEST.END

-- Test Case: COND_5_ROW_2_PAIR_b_TF-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_5_ROW_2_PAIR_b_TF-PARTIAL
TEST.MCDC_BASIS_PATH:5 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 5
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #5, subcondition "b".
         Condition a ==> TRUE
         Condition b ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 5
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_9_ROW_1_PAIR_a_T-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_9_ROW_1_PAIR_a_T-PARTIAL
TEST.MCDC_BASIS_PATH:7 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 7
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> TRUE
      Row number 1 forms a pair with Row 2 for Condition #9, subcondition "a".
         Condition a ==> TRUE
   Test Case Generation Notes:
      Cannot set local variable status in branch 9
      Cannot set local variable status in branch 5
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: COND_9_ROW_2_PAIR_a_F-PARTIAL
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:COND_9_ROW_2_PAIR_a_F-PARTIAL
TEST.MCDC_BASIS_PATH:6 of 35
TEST.NOTES:
This is an automatically generated test case.
   Test Path 6
      (1) if ((RAMTEST_NON_DESTRUCTIVE) == RamTstBlockPtr->RamTstTestPolicy) ==> FALSE
      (5) while (0 == status && RamTstEndAddr > cur_addr) ==> FALSE
      (9) if (status == 0) ==> FALSE
      Row number 2 forms a pair with Row 1 for Condition #9, subcondition "a".
         Condition a ==> FALSE
   Test Case Generation Notes:
      Cannot set local variable status in branch 9
      Cannot set local variable status in branch 5
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstStartAddress:<<MAX>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstEndAddress:<<MIN>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.END

-- Test Case: RamTst_preprocess
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:RamTst_preprocess
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_CacheDisable
TEST.STUB:RamTst.RamTst_RestoreSPCacheData
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.VALUE_USER_CODE:RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstBlockPtr[0].RamTstStartAddress
<<RamTst.RamTst_preprocess.RamTstBlockPtr>>[0].RamTstStartAddress = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstBlockPtr[0].RamTstEndAddress
<<RamTst.RamTst_preprocess.RamTstBlockPtr>>[0].RamTstEndAddress = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: RamTst_preprocess.001
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:RamTst_preprocess.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_CacheDisable
TEST.STUB:RamTst.RamTst_RestoreSPCacheData
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0xFFFFFF
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.VALUE_USER_CODE:RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstBlockPtr[0].RamTstStartAddress
<<RamTst.RamTst_preprocess.RamTstBlockPtr>>[0].RamTstStartAddress = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstBlockPtr[0].RamTstEndAddress
<<RamTst.RamTst_preprocess.RamTstBlockPtr>>[0].RamTstEndAddress = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: RamTst_preprocess.002
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:RamTst_preprocess.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_CacheDisable
TEST.STUB:RamTst.RamTst_RestoreSPCacheData
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0x1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.VALUE_USER_CODE:RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstBlockPtr[0].RamTstStartAddress
<<RamTst.RamTst_preprocess.RamTstBlockPtr>>[0].RamTstStartAddress = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstBlockPtr[0].RamTstEndAddress
<<RamTst.RamTst_preprocess.RamTstBlockPtr>>[0].RamTstEndAddress = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: RamTst_preprocess_NMI_ON
TEST.UNIT:RamTst
TEST.SUBPROGRAM:RamTst_preprocess
TEST.NEW
TEST.NAME:RamTst_preprocess_NMI_ON
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::ramtst::ramtst_Detailed_Design::Class_Diagram
Requirement_PE4TI29141-6477
TEST.END_NOTES:
TEST.STUB:RamTst.RamTst_SaveSPCacheData
TEST.STUB:RamTst.RamTst_CacheEnable
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:0x1
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2:2
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestCompletedNotification:<<null>>
TEST.VALUE:RamTst.<<GLOBAL>>.RamTstConfig.RamTstTestErrorNotification:<<null>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr:<<malloc 1>>
TEST.VALUE:RamTst.RamTst_preprocess.RamTstBlockPtr[0].RamTstTestPolicy:RAMTEST_DESTRUCTIVE
TEST.VALUE:RamTst.RamTst_preprocess.return:12
TEST.VALUE_USER_CODE:RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstBlockPtr[0].RamTstStartAddress
<<RamTst.RamTst_preprocess.RamTstBlockPtr>>[0].RamTstStartAddress = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:RamTst.RamTst_preprocess.RamTstBlockPtr.RamTstBlockPtr[0].RamTstEndAddress
<<RamTst.RamTst_preprocess.RamTstBlockPtr>>[0].RamTstEndAddress = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> );
TEST.END_VALUE_USER_CODE:
TEST.END
