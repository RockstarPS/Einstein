-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_HYPERFLASHIOADAPTER
-- Unit(s) Under Test: UPDi_HyperFlashIoAdapter
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.001
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.001
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.return:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.return:0
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.002
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.002
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.003
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.003
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.004
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.004
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.005
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.005
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.006
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.006
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.HMemDrv_Erase.return:1
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.007
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.007
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.HMemDrv_Erase.return:3
TEST.VALUE:uut_prototype_stubs.HMemDrv_GetJobResult.return:EHMemDrvJobResult_OK
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.008
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.008
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 3>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.009
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.009
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:0x233
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.HMemDrv_Erase.return:3
TEST.VALUE:uut_prototype_stubs.HMemDrv_GetJobResult.return:EHMemDrvJobResult_OK
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:563
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.010
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.010
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.HMemDrv_Erase.return:1
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.011
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.011
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.HMemDrv_Erase.return:1
TEST.VALUE:uut_prototype_stubs.HMemDrv_GetJobResult.return:EHMemDrvJobResult_JobPending
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:1
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.012
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.012
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.HMemDrv_Erase.return:1
TEST.VALUE:uut_prototype_stubs.HMemDrv_GetJobResult.return:EHMemDrvJobResult_JobFailed
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.l_HmemDrvInitSts_U8:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.013
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.013
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 3>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.VALUE:uut_prototype_stubs.HMemDrv_Write.return:2
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.014
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.014
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 3>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.VALUE:uut_prototype_stubs.HMemDrv_Write.return:3
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.015
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.015
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 3>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.VALUE:uut_prototype_stubs.HMemDrv_Write.return:3
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.END

-- Test Case: UPDHyperFlashIoAdapter_ProcessReq.017
TEST.UNIT:UPDi_HyperFlashIoAdapter
TEST.SUBPROGRAM:UPDHyperFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDHyperFlashIoAdapter_ProcessReq.017
TEST.VALUE:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:1
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 3>>
TEST.VALUE:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.VALUE:uut_prototype_stubs.HMemDrv_Write.return:3
TEST.VALUE:uut_prototype_stubs.HMemDrv_GetJobResult.return:EHMemDrvJobResult_JobFailed
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.<<GLOBAL>>.HyperFlashReqStatus:0
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].Size:2
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_HyperFlashIoAdapter.UPDHyperFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"W'"
TEST.END
