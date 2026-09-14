-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_GIPIOADAPTER
-- Unit(s) Under Test: UPDi_GipIoAdapter
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UPDi_GipIoAdapter

-- Subprogram: UPDGipIoAdapter_ProcessReq

-- Test Case: UPDGipIoAdapter_ProcessReq.001
TEST.UNIT:UPDi_GipIoAdapter
TEST.SUBPROGRAM:UPDGipIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDGipIoAdapter_ProcessReq.001
TEST.VALUE:UPDi_GipIoAdapter.UPDGipIoAdapter_ProcessReq.return:0
TEST.EXPECTED:UPDi_GipIoAdapter.UPDGipIoAdapter_ProcessReq.return:0
TEST.END
