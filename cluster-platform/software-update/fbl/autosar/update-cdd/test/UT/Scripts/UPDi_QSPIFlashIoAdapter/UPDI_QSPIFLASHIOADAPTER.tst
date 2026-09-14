-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UPDI_QSPIFLASHIOADAPTER
-- Unit(s) Under Test: UPDi_QSPIFlashIoAdapter
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.001
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.001
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Hash
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Hash
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.002
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.002
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Init
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.003
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.003
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.004
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.004
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.005
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.005
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.006
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.006
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitTimeoutCounter_U16:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitTimeoutCounter_U16:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.007
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.007
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.008
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.008
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Erase.return:1
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.009
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.009
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Erase.return:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.010
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.010
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Erase.return:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.011
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.011
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Erase.return:3
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_GetJobResult.return:EExtMemMgrJobResult_OK
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.012
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.012
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Erase.return:3
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_GetJobResult.return:EExtMemMgrJobResult_JobPending
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.013
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.013
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Write.return:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.014
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.014
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Write.return:2
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.015
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.015
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Write.return:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.016
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.016
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Write.return:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.017
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.017
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Write.return:3
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_GetJobResult.return:EExtMemMgrJobResult_OK
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.018
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.018
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Write.return:3
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_GetJobResult.return:EExtMemMgrJobResult_OK
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.019
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.019
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Write.return:3
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_GetJobResult.return:EExtMemMgrJobResult_JobPending
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.020
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.020
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:0x123
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:<<malloc 2>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Write.return:3
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_GetJobResult.return:EExtMemMgrJobResult_JobFailed
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Write
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].pIoAdapter[0].Ram[0].AdapterBuffer:"w"
TEST.END

-- Test Case: UPDQspiFlashIoAdapter_ProcessReq.021
TEST.UNIT:UPDi_QSPIFlashIoAdapter
TEST.SUBPROGRAM:UPDQspiFlashIoAdapter_ProcessReq
TEST.NEW
TEST.NAME:UPDQspiFlashIoAdapter_ProcessReq.021
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:1
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req:<<malloc 1>>
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.VALUE:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_Erase.return:3
TEST.VALUE:uut_prototype_stubs.ExtMemMgr_GetJobResult.return:EExtMemMgrJobResult_JobFailed
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.QSPIFlashReqStatus:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.<<GLOBAL>>.l_ExtMemMgrInitSts_U8:0
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Address:291
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].Size:3
TEST.EXPECTED:UPDi_QSPIFlashIoAdapter.UPDQspiFlashIoAdapter_ProcessReq.Req[0].ReqType:eUPDiIoReq_Erase
TEST.END
