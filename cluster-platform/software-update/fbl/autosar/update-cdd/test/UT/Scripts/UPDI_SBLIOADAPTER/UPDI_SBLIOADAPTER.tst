-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_SBLIOADAPTER
-- Unit(s) Under Test: UPDi_SblIoAdapter
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Test Case: UPDSblIoAdapter_ProcessReq.001
TEST.UNIT:UPDi_SblIoAdapter
TEST.SUBPROGRAM:UPDSblIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDSblIoAdapter_ProcessReq.001
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.return:1
TEST.EXPECTED:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.return:1
TEST.END

-- Test Case: UPDSblIoAdapter_ProcessReq.002
TEST.UNIT:UPDi_SblIoAdapter
TEST.SUBPROGRAM:UPDSblIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDSblIoAdapter_ProcessReq.002
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.EXPECTED:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.END

-- Test Case: UPDSblIoAdapter_ProcessReq.003
TEST.UNIT:UPDi_SblIoAdapter
TEST.SUBPROGRAM:UPDSblIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDSblIoAdapter_ProcessReq.003
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDSblIoAdapter_ProcessReq.004
TEST.UNIT:UPDi_SblIoAdapter
TEST.SUBPROGRAM:UPDSblIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDSblIoAdapter_ProcessReq.004
TEST.STUB:uut_prototype_stubs.memcpy
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_SblIoAdapter.UPDSblIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.END
