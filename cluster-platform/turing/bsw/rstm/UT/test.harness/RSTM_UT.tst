-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : RSTM_UT
-- Unit(s) Under Test: RstM
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: RstM_ClearResetHistory

-- Test Case: RstM_ClearResetHistory.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_ClearResetHistory
TEST.NEW
TEST.NAME:RstM_ClearResetHistory.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_ClearResetHistory.return:0
TEST.EXPECTED:RstM.RstM_ClearResetHistory.return:0
TEST.END

-- Subprogram: RstM_CopyResetHistoryData

-- Test Case: RstM_CopyResetHistoryData.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_CopyResetHistoryData
TEST.NEW
TEST.NAME:RstM_CopyResetHistoryData.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.END

-- Subprogram: RstM_EnableResetIsolation

-- Test Case: RstM_EnableResetIsolation.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_EnableResetIsolation
TEST.NEW
TEST.NAME:RstM_EnableResetIsolation.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SOC_enableResetIsolation.return:1
TEST.ATTRIBUTES:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]::INPUT_BASE=16
TEST.ATTRIBUTES:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][1]::INPUT_BASE=16
TEST.END

-- Test Case: RstM_EnableResetIsolation.002
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_EnableResetIsolation
TEST.NEW
TEST.NAME:RstM_EnableResetIsolation.002
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SOC_enableResetIsolation.return:0
TEST.END

-- Subprogram: RstM_GetLastResetReason

-- Test Case: RstM_GetLastResetReason.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetLastResetReason
TEST.NEW
TEST.NAME:RstM_GetLastResetReason.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_GetLastResetReason.lastResetInfo:<<malloc 1>>
TEST.VALUE:RstM.RstM_GetLastResetReason.lastResetInfo[0]:1
TEST.VALUE:RstM.RstM_GetLastResetReason.return:0
TEST.EXPECTED:RstM.RstM_GetLastResetReason.return:1
TEST.END

-- Test Case: RstM_GetLastResetReason.002
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetLastResetReason
TEST.NEW
TEST.NAME:RstM_GetLastResetReason.002
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_GetLastResetReason.lastResetInfo:<<null>>
TEST.EXPECTED:RstM.RstM_GetLastResetReason.lastResetInfo:<<null>>
TEST.END

-- Test Case: RstM_GetLastResetReason.003
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetLastResetReason
TEST.NEW
TEST.NAME:RstM_GetLastResetReason.003
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.VALUE:RstM.RstM_GetLastResetReason.lastResetInfo:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PmicCdd_GetResetReason.return:PmicCdd_PowerOn_Reset
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.ATTRIBUTES:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.END

-- Test Case: RstM_GetLastResetReason.004
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetLastResetReason
TEST.NEW
TEST.NAME:RstM_GetLastResetReason.004
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.VALUE:RstM.RstM_GetLastResetReason.lastResetInfo:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PmicCdd_GetResetReason.return:PmicCdd_PmicWdg_Reset
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.END

-- Test Case: RstM_GetLastResetReason.005
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetLastResetReason
TEST.NEW
TEST.NAME:RstM_GetLastResetReason.005
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]:0xFF
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.VALUE:RstM.RstM_GetLastResetReason.lastResetInfo:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.PmicCdd_GetResetReason.return:PmicCdd_PmicWdg_Reset
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]:0xFF
TEST.END

-- Subprogram: RstM_GetResetCount

-- Test Case: RstM_GetResetCount.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetCount
TEST.NEW
TEST.NAME:RstM_GetResetCount.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_GetResetCount.FaultId:4
TEST.VALUE:RstM.RstM_GetResetCount.Count:<<malloc 2>>
TEST.VALUE:RstM.RstM_GetResetCount.Count[0]:1
TEST.VALUE:RstM.RstM_GetResetCount.Count[1]:1
TEST.VALUE:RstM.RstM_GetResetCount.return:1
TEST.EXPECTED:RstM.RstM_GetResetCount.FaultId:4
TEST.END

-- Test Case: RstM_GetResetCount.002
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetCount
TEST.NEW
TEST.NAME:RstM_GetResetCount.002
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_GetResetCount.FaultId:4
TEST.VALUE:RstM.RstM_GetResetCount.Count:<<malloc 9>>
TEST.VALUE:RstM.RstM_GetResetCount.Count:<<null>>
TEST.VALUE:RstM.RstM_GetResetCount.return:1
TEST.EXPECTED:RstM.RstM_GetResetCount.FaultId:4
TEST.END

-- Test Case: RstM_GetResetCount.003
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetCount
TEST.NEW
TEST.NAME:RstM_GetResetCount.003
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_GetResetCount.Count:<<malloc 2>>
TEST.VALUE:RstM.RstM_GetResetCount.Count[0]:1
TEST.VALUE:RstM.RstM_GetResetCount.Count[1]:1
TEST.VALUE:RstM.RstM_GetResetCount.return:1
TEST.EXPECTED:RstM.RstM_GetResetCount.FaultId:0
TEST.END

-- Test Case: RstM_GetResetCount.004
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetCount
TEST.NEW
TEST.NAME:RstM_GetResetCount.004
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].faultId:4
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.VALUE:RstM.RstM_GetResetCount.FaultId:4
TEST.VALUE:RstM.RstM_GetResetCount.Count:<<malloc 2>>
TEST.VALUE:RstM.RstM_GetResetCount.Count[0]:1
TEST.VALUE:RstM.RstM_GetResetCount.Count[1]:1
TEST.VALUE:RstM.RstM_GetResetCount.return:1
TEST.EXPECTED:RstM.RstM_GetResetCount.FaultId:4
TEST.END

-- Test Case: RstM_GetResetCount.005
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetCount
TEST.NEW
TEST.NAME:RstM_GetResetCount.005
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].faultId:3
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.VALUE:RstM.RstM_GetResetCount.FaultId:4
TEST.VALUE:RstM.RstM_GetResetCount.Count:<<malloc 2>>
TEST.VALUE:RstM.RstM_GetResetCount.Count[0]:1
TEST.VALUE:RstM.RstM_GetResetCount.Count[1]:1
TEST.VALUE:RstM.RstM_GetResetCount.return:1
TEST.EXPECTED:RstM.RstM_GetResetCount.FaultId:4
TEST.END

-- Test Case: RstM_GetResetCount.006
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetCount
TEST.NEW
TEST.NAME:RstM_GetResetCount.006
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].faultId:3
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.VALUE:RstM.RstM_GetResetCount.FaultId:4
TEST.VALUE:RstM.RstM_GetResetCount.Count:<<malloc 2>>
TEST.VALUE:RstM.RstM_GetResetCount.Count[0]:1
TEST.VALUE:RstM.RstM_GetResetCount.Count[1]:1
TEST.VALUE:RstM.RstM_GetResetCount.return:1
TEST.EXPECTED:RstM.RstM_GetResetCount.FaultId:4
TEST.END

-- Test Case: RstM_GetResetCount.007
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetCount
TEST.NEW
TEST.NAME:RstM_GetResetCount.007
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].faultId:4
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.VALUE:RstM.RstM_GetResetCount.FaultId:4
TEST.VALUE:RstM.RstM_GetResetCount.Count:<<malloc 2>>
TEST.VALUE:RstM.RstM_GetResetCount.Count[0]:1
TEST.VALUE:RstM.RstM_GetResetCount.Count[1]:1
TEST.VALUE:RstM.RstM_GetResetCount.return:1
TEST.EXPECTED:RstM.RstM_GetResetCount.FaultId:4
TEST.END

-- Subprogram: RstM_GetResetHistory

-- Test Case: RstM_GetResetHistory.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetHistory
TEST.NEW
TEST.NAME:RstM_GetResetHistory.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_GetResetHistory.return:1
TEST.EXPECTED:RstM.RstM_GetResetHistory.return:1
TEST.END

-- Test Case: RstM_GetResetHistory.002
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_GetResetHistory
TEST.NEW
TEST.NAME:RstM_GetResetHistory.002
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_GetResetHistory.ResetHistory:<<malloc 1>>
TEST.VALUE:RstM.RstM_GetResetHistory.return:0
TEST.EXPECTED:RstM.RstM_GetResetHistory.return:0
TEST.END

-- Subprogram: RstM_Init

-- Test Case: RstM_Init.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_Init
TEST.NEW
TEST.NAME:RstM_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_RetreivedLogData.code[4][0]:0
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_RetreivedLogData.code[4][0]:0
TEST.END

-- Test Case: RstM_Init.002
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_Init
TEST.NEW
TEST.NAME:RstM_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.STUB:RstM.RstM_UpdateResetCounts
TEST.VALUE:RstM.<<GLOBAL>>.RstM_RetreivedLogData.code[4]:<<malloc 2>>
TEST.VALUE:RstM.<<GLOBAL>>.RstM_RetreivedLogData.code[4]:"1"
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_RetreivedLogData.code[4]:"1"
TEST.ATTRIBUTES:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]:INPUT_BASE=16
TEST.ATTRIBUTES:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][1]:INPUT_BASE=16
TEST.ATTRIBUTES:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].faultId:INPUT_BASE=16
TEST.END

-- Subprogram: RstM_MainFunction

-- Test Case: RstM_MainFunction.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_MainFunction
TEST.NEW
TEST.NAME:RstM_MainFunction.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.END

-- Test Case: RstM_MainFunction.002
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_MainFunction
TEST.NEW
TEST.NAME:RstM_MainFunction.002
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:0
TEST.VALUE:uut_prototype_stubs.EcuMExt_GetNvmReadAllStatus.return:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:1
TEST.END

-- Test Case: RstM_MainFunction.003
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_MainFunction
TEST.NEW
TEST.NAME:RstM_MainFunction.003
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:0
TEST.VALUE:uut_prototype_stubs.EcuMExt_GetNvmReadAllStatus.return:0
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:0
TEST.END

-- Test Case: RstM_MainFunction.004
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_MainFunction
TEST.NEW
TEST.NAME:RstM_MainFunction.004
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:0
TEST.VALUE:uut_prototype_stubs.EcuMExt_GetNvmReadAllStatus.return:1
TEST.VALUE:uut_prototype_stubs.DltExt_GetResetInfo.return:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_ResetHistoryDataValid:0
TEST.END

-- Subprogram: RstM_ProcessResetIsolationReq

-- Test Case: RstM_ProcessResetIsolationReq.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_ProcessResetIsolationReq
TEST.NEW
TEST.NAME:RstM_ProcessResetIsolationReq.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.END

-- Subprogram: RstM_RequestSwReset

-- Test Case: RstM_RequestSwReset.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_RequestSwReset
TEST.NEW
TEST.NAME:RstM_RequestSwReset.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_RequestSwReset.LogData:<<malloc 1>>
TEST.VALUE:RstM.RstM_RequestSwReset.return:1
TEST.EXPECTED:RstM.RstM_RequestSwReset.return:1
TEST.END

-- Test Case: RstM_RequestSwReset.002
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_RequestSwReset
TEST.NEW
TEST.NAME:RstM_RequestSwReset.002
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_RequestSwReset.LogData:<<malloc 9>>
TEST.VALUE:RstM.RstM_RequestSwReset.LogData:<<null>>
TEST.VALUE:RstM.RstM_RequestSwReset.return:1
TEST.EXPECTED:RstM.RstM_RequestSwReset.return:1
TEST.END

-- Test Case: RstM_RequestSwReset.003
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_RequestSwReset
TEST.NEW
TEST.NAME:RstM_RequestSwReset.003
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_RequestSwReset.FaultId:1
TEST.VALUE:RstM.RstM_RequestSwReset.ResetType:3
TEST.VALUE:RstM.RstM_RequestSwReset.LogData:<<malloc 1>>
TEST.VALUE:RstM.RstM_RequestSwReset.return:0
TEST.EXPECTED:RstM.RstM_RequestSwReset.ResetType:3
TEST.EXPECTED:RstM.RstM_RequestSwReset.return:0
TEST.END

-- Test Case: RstM_RequestSwReset.004
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_RequestSwReset
TEST.NEW
TEST.NAME:RstM_RequestSwReset.004
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.RstM_RequestSwReset.FaultId:1
TEST.VALUE:RstM.RstM_RequestSwReset.ResetType:1
TEST.VALUE:RstM.RstM_RequestSwReset.LogData:<<malloc 1>>
TEST.VALUE:RstM.RstM_RequestSwReset.return:0
TEST.EXPECTED:RstM.RstM_RequestSwReset.ResetType:1
TEST.EXPECTED:RstM.RstM_RequestSwReset.return:0
TEST.END

-- Subprogram: RstM_UpdateResetCounts

-- Test Case: RstM_UpdateResetCounts.001
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_UpdateResetCounts
TEST.NEW
TEST.NAME:RstM_UpdateResetCounts.001
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.END

-- Test Case: RstM_UpdateResetCounts.002
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_UpdateResetCounts
TEST.NEW
TEST.NAME:RstM_UpdateResetCounts.002
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.STUB:RstM.RstM_Init
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.ATTRIBUTES:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]:INPUT_BASE=16
TEST.ATTRIBUTES:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][1]:INPUT_BASE=16
TEST.END

-- Test Case: RstM_UpdateResetCounts.003
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_UpdateResetCounts
TEST.NEW
TEST.NAME:RstM_UpdateResetCounts.003
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.STUB:RstM.RstM_Init
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]:0xFF
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][1]:0xFF
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.END

-- Test Case: RstM_UpdateResetCounts.004
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_UpdateResetCounts
TEST.NEW
TEST.NAME:RstM_UpdateResetCounts.004
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.STUB:RstM.RstM_Init
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]:0xFF
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][1]:0xFF
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].faultId:0xFFFF
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.END

-- Test Case: RstM_UpdateResetCounts.005
TEST.UNIT:RstM
TEST.SUBPROGRAM:RstM_UpdateResetCounts
TEST.NEW
TEST.NAME:RstM_UpdateResetCounts.005
TEST.NOTES:
SoftwareArchitecture::TI::BSW::RstM::RstM_Detailed_Design::RstM_ClassDiagram
Requirement_PE4TI29141-9277
TEST.END_NOTES:
TEST.STUB:RstM.RstM_Init
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][0]:0xFF
TEST.VALUE:RstM.<<GLOBAL>>.RstM_ResetHistoryCode[0][1]:0xFF
TEST.VALUE:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.EXPECTED:RstM.<<GLOBAL>>.RstM_FaultResetCount[0].isValid:1
TEST.END
