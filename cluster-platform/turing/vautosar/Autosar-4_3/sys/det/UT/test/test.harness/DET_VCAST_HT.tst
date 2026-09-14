-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : DET_VCAST_HT
-- Unit(s) Under Test: Det
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: Det

-- Subprogram: Det_GetVersionInfo

-- Test Case: Det_GetVersionInfo.001
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_GetVersionInfo
TEST.NEW
TEST.NAME:Det_GetVersionInfo.001
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.END

-- Test Case: Det_GetVersionInfo.002
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_GetVersionInfo
TEST.NEW
TEST.NAME:Det_GetVersionInfo.002
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.VALUE:Det.Det_GetVersionInfo.VersionInfo:<<malloc 1>>
TEST.END

-- Subprogram: Det_Init

-- Test Case: Det_Init.001
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_Init
TEST.NEW
TEST.NAME:Det_Init.001
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.END

-- Test Case: Det_Init.002
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_Init
TEST.NEW
TEST.NAME:Det_Init.002
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.VALUE:Det.Det_Init.ConfigPtr:<<malloc 1>>
TEST.END

-- Subprogram: Det_InitMemory

-- Test Case: Det_InitMemory.001
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_InitMemory
TEST.NEW
TEST.NAME:Det_InitMemory.001
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.END

-- Subprogram: Det_ReportError

-- Test Case: Det_ReportError.001
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_ReportError
TEST.NEW
TEST.NAME:Det_ReportError.001
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.END

-- Test Case: Det_ReportError.002
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_ReportError
TEST.NEW
TEST.NAME:Det_ReportError.002
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.VALUE:Det.<<GLOBAL>>.Det_InitStatus:1
TEST.END

-- Subprogram: Det_ReportRuntimeError

-- Test Case: Det_ReportRuntimeError.001
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_ReportRuntimeError
TEST.NEW
TEST.NAME:Det_ReportRuntimeError.001
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.END

-- Subprogram: Det_ReportTransientFault

-- Test Case: Det_ReportTransientFault.001
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_ReportTransientFault
TEST.NEW
TEST.NAME:Det_ReportTransientFault.001
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.END

-- Subprogram: Det_Start

-- Test Case: Det_Start.001
TEST.UNIT:Det
TEST.SUBPROGRAM:Det_Start
TEST.NEW
TEST.NAME:Det_Start.001
TEST.NOTES:
Requirement_DICVA-7445
TEST.END_NOTES:
TEST.END
