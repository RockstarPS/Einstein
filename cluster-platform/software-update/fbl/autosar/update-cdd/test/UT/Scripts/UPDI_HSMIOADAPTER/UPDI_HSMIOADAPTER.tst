-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_HSMIOADAPTER
-- Unit(s) Under Test: UPDi_HsmIoAdapter
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Test Case: UPDHsmIoAdapter_ProcessReq.001
TEST.UNIT:UPDi_HsmIoAdapter
TEST.SUBPROGRAM:UPDHsmIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHsmIoAdapter_ProcessReq.001
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.return:0
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.return:0
TEST.END

-- Test Case: UPDHsmIoAdapter_ProcessReq.002
TEST.UNIT:UPDi_HsmIoAdapter
TEST.SUBPROGRAM:UPDHsmIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHsmIoAdapter_ProcessReq.002
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.END

-- Test Case: UPDHsmIoAdapter_ProcessReq.003
TEST.UNIT:UPDi_HsmIoAdapter
TEST.SUBPROGRAM:UPDHsmIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHsmIoAdapter_ProcessReq.003
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Idle
TEST.END

-- Test Case: UPDHsmIoAdapter_ProcessReq.004
TEST.UNIT:UPDi_HsmIoAdapter
TEST.SUBPROGRAM:UPDHsmIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHsmIoAdapter_ProcessReq.004
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.END

-- Test Case: UPDHsmIoAdapter_ProcessReq.005
TEST.UNIT:UPDi_HsmIoAdapter
TEST.SUBPROGRAM:UPDHsmIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHsmIoAdapter_ProcessReq.005
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].Size:2
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.FblHsmFlashDrv_Write.addr:0x123
TEST.VALUE:uut_prototype_stubs.FblHsmFlashDrv_Write.pLen[0]:1
TEST.VALUE:uut_prototype_stubs.FblHsmFlashDrv_Write.pBuffer:"W'"
TEST.VALUE:uut_prototype_stubs.FblHsmFlashDrv_Write.return:1
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].Size:1
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.EXPECTED:uut_prototype_stubs.FblHsmFlashDrv_Write.addr:291
TEST.EXPECTED:uut_prototype_stubs.FblHsmFlashDrv_Write.pLen[0]:2
TEST.EXPECTED:uut_prototype_stubs.FblHsmFlashDrv_Write.pBuffer:"w"
TEST.END

-- Test Case: UPDHsmIoAdapter_ProcessReq.006
TEST.UNIT:UPDi_HsmIoAdapter
TEST.SUBPROGRAM:UPDHsmIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHsmIoAdapter_ProcessReq.006
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.FblHsmFlashGetResp_erase.return:1
TEST.EXPECTED:UPDi_HsmIoAdapter.UPDHsmIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Idle
TEST.END
