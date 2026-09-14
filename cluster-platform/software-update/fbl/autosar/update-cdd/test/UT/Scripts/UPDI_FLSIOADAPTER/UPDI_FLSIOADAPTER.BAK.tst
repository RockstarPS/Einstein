-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_FLSIOADAPTER.BAK
-- Unit(s) Under Test: UPDi_FlsIoAdapter
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Test Case: UPDFlsIoAdapter_ProcessReq.001
TEST.UNIT:UPDi_FlsIoAdapter
TEST.SUBPROGRAM:UPDFlsIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDFlsIoAdapter_ProcessReq.001
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Hash
TEST.EXPECTED:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Hash
TEST.END

-- Test Case: UPDFlsIoAdapter_ProcessReq.002
TEST.UNIT:UPDi_FlsIoAdapter
TEST.SUBPROGRAM:UPDFlsIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDFlsIoAdapter_ProcessReq.002
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.EXPECTED:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.END

-- Test Case: UPDFlsIoAdapter_ProcessReq.003
TEST.UNIT:UPDi_FlsIoAdapter
TEST.SUBPROGRAM:UPDFlsIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDFlsIoAdapter_ProcessReq.003
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDFlsIoAdapter_ProcessReq.004
TEST.UNIT:UPDi_FlsIoAdapter
TEST.SUBPROGRAM:UPDFlsIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDFlsIoAdapter_ProcessReq.004
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].Address:291
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.FblFlashDrv_Write.addr:291
TEST.EXPECTED:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:uut_prototype_stubs.FblFlashDrv_Write.addr:291
TEST.END

-- Test Case: UPDFlsIoAdapter_ProcessReq.005
TEST.UNIT:UPDi_FlsIoAdapter
TEST.SUBPROGRAM:UPDFlsIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDFlsIoAdapter_ProcessReq.005
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Idle
TEST.EXPECTED:UPDi_FlsIoAdapter.UPDFlsIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Idle
TEST.END
