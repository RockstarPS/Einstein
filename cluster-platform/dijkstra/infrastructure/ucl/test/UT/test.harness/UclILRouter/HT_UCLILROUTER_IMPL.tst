-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLILROUTER_IMPL
-- Unit(s) Under Test: UclILRouter_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclILRouter_Impl

-- Subprogram: UclILRouter_Impl_IUclDLCbk_FatalError

-- Test Case: UclILRouter_Impl_IUclDLCbk_FatalError.0x01
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_FatalError
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_FatalError.0x01
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.Status:eUclDLError_SecurityTSCError
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_FatalError.0x02
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_FatalError
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_FatalError.0x02
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.Status:eUclDLError_SecurityNegoError
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_FatalError.0x03
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_FatalError
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_FatalError.0x03
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.Status:eUclDLError_SecurityCMACError
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_FatalError.invalid_state_errstatus=-7
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_FatalError
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_FatalError.invalid_state_errstatus=-7
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.InstId:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.Status:0x56
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_FatalError_true
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_FatalError
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_FatalError_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.Status:eUclDLError_FatalError
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_FatalError.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILRouter_Impl_IUclDLCbk_LinkStatusChanged

-- Test Case: UclILRouter_Impl_IUclDLCbk_LinkStatusChanged_Invalidstatus
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_LinkStatusChanged_Invalidstatus
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Last
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_LinkStatusChanged_Linkdown
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_LinkStatusChanged_Linkdown
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Down
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_LinkStatusChanged_Linkdown.005
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_LinkStatusChanged_Linkdown.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Down
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_LinkStatusChanged_Linkup
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_LinkStatusChanged_Linkup
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Up
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILRouter_Impl_IUclDLCbk_MsgReceived

-- Test Case: UclILRouter_Impl_IUclDLCbk_MsgReceived_Msg_Not_Bound_To_Current_Node
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_MsgReceived_Msg_Not_Bound_To_Current_Node
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Idle
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].msgId:0x1234
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.nodeId:0x1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId:0x1234
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload:<<malloc 10>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]:0x15
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]:0xA1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]:0xA2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]:0xA3
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]:0x16
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]:0xA4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].Size:8
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx.UclILMsgDbRx[0].pWork
<<UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx>>[0].pWork = ( &rpUclTest_Work );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_MsgReceived_Process_Rcv_Fail
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_MsgReceived_Process_Rcv_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTestDataUnits1[0].dataUnitId:0x15
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTestDataUnits1[0].numSignals:0
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTestDataUnits1[0].msgSize:8
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTestDataUnits1[0].pMsgAdapterFunc:UclGen_Write_TestMsgAdapter
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Idle
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].msgId:0x123
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].numDataUnits:1
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.nodeId:0x0
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.numMsgDbRxMsgs:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId:0x1234
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload:<<malloc 10>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]:0x15
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]:0xA1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]:0xA2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]:0xA3
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]:0x16
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]:0xA4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].Size:8
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Error
TEST.VALUE_USER_CODE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx.UclILMsgDbRx[0].pWork
<<UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx>>[0].pWork = ( &rpUclTest_Work );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx.UclILMsgDbRx[0].pDataUnitList
<<UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx>>[0].pDataUnitList = ( &rpUclTestDataUnits1 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.pMsgDbRx
<<UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0>>.pMsgDbRx = ( &UclILMsgDbRx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclDLCbk_MsgReceived_Process_Rcv_Success
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_MsgReceived_Process_Rcv_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTestDataUnits1[0].dataUnitId:0x15
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTestDataUnits1[0].numSignals:0
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTestDataUnits1[0].msgSize:8
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTestDataUnits1[0].pMsgAdapterFunc:UclGen_Write_TestMsgAdapter
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Idle
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].msgId:0x1234
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].numDataUnits:1
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.nodeId:0x0
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.numMsgDbRxMsgs:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgHdr:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId:0x1234
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload:<<malloc 10>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]:0x15
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]:0xA1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]:0xA2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]:0xA3
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]:0x16
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]:0xA4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].Size:8
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Recvd
TEST.VALUE_USER_CODE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx.UclILMsgDbRx[0].pWork
<<UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx>>[0].pWork = ( &rpUclTest_Work );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx.UclILMsgDbRx[0].pDataUnitList
<<UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx>>[0].pDataUnitList = ( &rpUclTestDataUnits1 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.pMsgDbRx
<<UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0>>.pMsgDbRx = ( &UclILMsgDbRx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus

-- Test Case: UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1234
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Ok
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILRouter_Impl_IUclILRouter_Initialize

-- Test Case: UclILRouter_Impl_IUclILRouter_Initialize.create_mutex_timertask
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclILRouter_Initialize
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclILRouter_Initialize.create_mutex_timertask
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.periodicMsgCheckPeriodicityMs:60
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterCfg_0.timerTaskPeriodicityMs:4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.pMutexId[0]:0xAA
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.pTimerId[0]:0xBB
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.msgStatusFlagsMutexId:0xAA
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.timerTaskId:0xBB
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:15
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimersCbk[0]:UclILRouter_Impl_ProcessPeriodicMessage
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Initialize.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Initialize.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclILRouter_Initialize_TimercreateFail
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclILRouter_Initialize
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclILRouter_Initialize_TimercreateFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_NOK
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Initialize.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Initialize.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILRouter_Impl_IUclILRouter_Shutdown

-- Test Case: UclILRouter_Impl_IUclILRouter_Shutdown.TimerStop_true
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclILRouter_Shutdown
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclILRouter_Shutdown.TimerStop_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:20
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Shutdown.InstId:0
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:0
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Shutdown.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Shutdown.pInst>> = (& UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_IUclILRouter_Shutdown_Timerstopfail
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_IUclILRouter_Shutdown
TEST.NEW
TEST.NAME:UclILRouter_Impl_IUclILRouter_Shutdown_Timerstopfail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:20
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:UCL_E_NOK
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:0
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Shutdown.pInst
<<UclILRouter_Impl.UclILRouter_Impl_IUclILRouter_Shutdown.pInst>> = (& UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILRouter_Impl_ProcessPeriodicMessage

-- Test Case: UclILRouter_Impl_ProcessPeriodicMessage_RxMsg
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessPeriodicMessage
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessPeriodicMessage_RxMsg
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Recvd
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.timeStampMs:80
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].periodictyMs:50
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:90
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Recvd
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessPeriodicMessage.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessPeriodicMessage.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessPeriodicMessage_RxMsgTimeout
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessPeriodicMessage
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessPeriodicMessage_RxMsgTimeout
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Recvd
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.timeStampMs:0
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].periodictyMs:50
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:90
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Missing
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessPeriodicMessage.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessPeriodicMessage.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessPeriodicMessage_RxMsgTimeout_MissingNotifyEnabled
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessPeriodicMessage
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessPeriodicMessage_RxMsgTimeout_MissingNotifyEnabled
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Recvd
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.timeStampMs:0
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].periodictyMs:50
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx[0].notifyRxMissingStatus:TRUE
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:90
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Missing
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessPeriodicMessage.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessPeriodicMessage.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILRouter_Impl_ProcessReceivedDataUnits

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.DULIst_NULL
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.DULIst_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgId:0x7
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 15>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[0]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[1]:0x17
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:15
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_OK
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx.UclILMsgDbRx[2].pDataUnitList
<<UclILRouter_Impl.<<GLOBAL>>.UclILMsgDbRx>>[2].pDataUnitList = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg>> = ( &UclILMsgDbRx[2] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.DURcv
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.DURcv
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgId:0x7
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 15>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[0]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[1]:0x17
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:15
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_OK
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg>> = ( &UclILMsgDbRx[2] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.MsgLen>pMsg->Size
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.MsgLen>pMsg->Size
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].numDataUnits:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].dataUnitId:24930
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].numSignals:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].signalId:99
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].size:2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].pAdapterFunc:UclGen_Write_TestRouterCbk4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pMsgAdapterFunc:UclGen_Write_TestRouterCbk2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 5>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:"abcd"
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:1
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.NoSignalCBAssociated
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.NoSignalCBAssociated
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgId:0x9
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 15>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[0]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[1]:0x17
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[2]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[3]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:7
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_OK
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg>> = ( &UclILMsgDbRx[1] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.Rcvd_Msg_Size_LT_2
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.Rcvd_Msg_Size_LT_2
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgId:0x9
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 15>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[0]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[1]:0x17
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[2]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[3]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:1
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_OK
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg>> = ( &UclILMsgDbRx[1] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.SignalRcv_InvalidSignalID
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.SignalRcv_InvalidSignalID
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgId:0x8
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 15>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[0]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[1]:0x15
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[2]:4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[3]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[4]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[5]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[6]:2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[7]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[8]:0x16
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[9]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[10]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:15
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_OK
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg>> = ( &UclILMsgDbRx[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.SignalRcv_Success
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.SignalRcv_Success
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].MsgId:0x8
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 15>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[0]:0x0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[1]:0x15
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[2]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[3]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[4]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[5]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[6]:2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[7]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[8]:0x16
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[9]:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload[10]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:15
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_OK
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg>> = ( &UclILMsgDbRx[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.pAdapterFunc_false
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.pAdapterFunc_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].numDataUnits:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].dataUnitId:24930
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].numSignals:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].signalId:99
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].size:2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].pAdapterFunc:UclGen_Write_TestRouterCbk4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 5>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:"abcd"
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:3
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedDataUnits.pAdapterFunc_true
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedDataUnits
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedDataUnits.pAdapterFunc_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].numDataUnits:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].dataUnitId:24930
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].numSignals:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].signalId:99
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].size:2
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pSignalList[0].pAdapterFunc:UclGen_Write_TestRouterCbk4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pRxMsg[0].pDataUnitList[0].pMsgAdapterFunc:UclGen_Write_TestRouterCbk4
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:<<malloc 5>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].pPayload:"abcd"
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.pMsg[0].Size:3
TEST.END

-- Subprogram: UclILRouter_Impl_ProcessReceivedMessage

-- Test Case: UclILRouter_Impl_ProcessReceivedMessage.Invalid_Msg_Rx_Status
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedMessage
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedMessage.Invalid_Msg_Rx_Status
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.Status:eUclDLRxStatus_Error
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgId:8
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].Size:5
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_OK
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Error
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedMessage.ProcessReceiveDu_Fail
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedMessage
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedMessage.ProcessReceiveDu_Fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgId:8
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].Size:5
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_NOK
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Recvd
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:2
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedMessage.ProcessReceiveDu_Fail.002.003
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedMessage
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedMessage.ProcessReceiveDu_Fail.002.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgId:8
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].Size:5
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_NOK
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Recvd
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:2
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedMessage.Success.
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedMessage
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedMessage.Success.
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgHdr:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgId:8
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].Size:5
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedDataUnits.return:UCL_E_OK
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.rpUclTest_Work.flags:eUclILMsgDbRxMsgStatus_Recvd
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:2
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[0]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[1]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[2]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[3]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[4]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[5]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[6]::INPUT_BASE=16
TEST.ATTRIBUTES:UclILRouter_Impl.UclILRouter_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload[7]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst
<<UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_ProcessReceivedMessage.status_ok
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_ProcessReceivedMessage
TEST.NEW
TEST.NAME:UclILRouter_Impl_ProcessReceivedMessage.status_ok
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst[0].pCfg[0].numMsgDbRxMsgs:0
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst[0].pCfg[0].pMsgDbRx:<<null>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst[0].pCfg[0].periodicMsgCheckPeriodicityMs:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst[0].pCfg[0].timerTaskPeriodicityMs:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pInst[0].localTimers[0]:1
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_ProcessReceivedMessage.pMsg[0].MsgId:2
TEST.END

-- Subprogram: UclILRouter_Impl_TimerTask

-- Test Case: UclILRouter_Impl_TimerTask.for_loop
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_TimerTask
TEST.NEW
TEST.NAME:UclILRouter_Impl_TimerTask.for_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:0
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimersCbk[0]:<<null>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_TimerTask.return:<<null>>
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:0
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_TimerTask.pData
<<UclILRouter_Impl.UclILRouter_Impl_TimerTask.pData>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_TimerTask_Not_Expired
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_TimerTask
TEST.NEW
TEST.NAME:UclILRouter_Impl_TimerTask_Not_Expired
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:3
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimersCbk[0]:UclILRouter_Impl_ProcessPeriodicMessage
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_TimerTask.return:<<null>>
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:2
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_TimerTask.pData
<<UclILRouter_Impl.UclILRouter_Impl_TimerTask.pData>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILRouter_Impl_TimerTask_Timer_Expired.001.003
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_TimerTask
TEST.NEW
TEST.NAME:UclILRouter_Impl_TimerTask_Timer_Expired.001.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:1
TEST.VALUE:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimersCbk[0]:UclILRouter_Impl_ProcessPeriodicMessage
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_TimerTask.return:<<null>>
TEST.EXPECTED:UclILRouter_Impl.<<GLOBAL>>.UclILRouterInst_0.localTimers[0]:0
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_TimerTask.pData
<<UclILRouter_Impl.UclILRouter_Impl_TimerTask.pData>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILRouter_Impl_UpdateFlags

-- Test Case: UclILRouter_Impl_UpdateFlags_ReSet_MutexLockfailed
TEST.UNIT:UclILRouter_Impl
TEST.SUBPROGRAM:UclILRouter_Impl_UpdateFlags
TEST.NEW
TEST.NAME:UclILRouter_Impl_UpdateFlags_ReSet_MutexLockfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_UpdateFlags.pFlags:<<malloc 1>>
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_UpdateFlags.pFlags[0]:eUclILMsgDbRxMsgStatus_Missing
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_UpdateFlags.bSet:FALSE
TEST.VALUE:UclILRouter_Impl.UclILRouter_Impl_UpdateFlags.Bits:eUclILMsgDbRxMsgStatus_Missing
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclILRouter_Impl.UclILRouter_Impl_UpdateFlags.pFlags[0]:eUclILMsgDbRxMsgStatus_Missing
TEST.VALUE_USER_CODE:UclILRouter_Impl.UclILRouter_Impl_UpdateFlags.pInst
<<UclILRouter_Impl.UclILRouter_Impl_UpdateFlags.pInst>> = ( &UclILRouterInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
