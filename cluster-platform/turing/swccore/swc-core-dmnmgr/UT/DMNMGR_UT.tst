-- VectorCAST 20.sp6 (02/02/21)
-- Test Case Script
--
-- Environment    : DMNMGR_UT
-- Unit(s) Under Test: DmnMgr_ControlDmn DmnMgr_Main DmnMgr_MonitorDmn DmnMgr_PublishDmnStatus
--
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:REMOVED_CL_PREFIX
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Unit: DmnMgr_ControlDmn

-- Subprogram: DmnMgr_DmnCtrlResetDmn

-- Test Case: DmnMgr_DmnCtrlResetDmn.001
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnCtrlResetDmn
TEST.NEW
TEST.NAME:DmnMgr_DmnCtrlResetDmn.001
TEST.END

-- Subprogram: DmnMgr_DmnSystemStateChangeReq

-- Test Case: DmnMgr_DmnSystemStateChangeReq.001
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.001
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.002
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.003
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.003
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.004
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.004
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.005
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.005
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.006
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.006
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.007
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.007
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:3
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.008
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.008
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkUpbfrDownErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkDownbfrUpErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.invalidLinkStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstLinkUpExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstHBExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.RcvdInvalidSeqCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.009
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.009
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkUpbfrDownErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkDownbfrUpErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.invalidLinkStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstLinkUpExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstHBExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.RcvdInvalidSeqCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.010
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.010
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:0
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.011
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.011
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg:<<null>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:0
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.012
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.012
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkUpbfrDownErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkDownbfrUpErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.invalidLinkStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstLinkUpExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstHBExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.RcvdInvalidSeqCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.013
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.013
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:5
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkUpbfrDownErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkDownbfrUpErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.invalidLinkStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstLinkUpExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstHBExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.RcvdInvalidSeqCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeReq.014
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeReq
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeReq.014
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnId:3
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeReq.DmnState:6
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkUpbfrDownErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkDownbfrUpErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.invalidLinkStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstLinkUpExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstHBExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.RcvdInvalidSeqCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Subprogram: DmnMgr_DmnSystemStateChangeStatus

-- Test Case: DmnMgr_DmnSystemStateChangeStatus.001
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeStatus
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeStatus.001
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeStatus.002
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeStatus
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeStatus.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeStatus.003
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeStatus
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeStatus.003
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:<<malloc 2>>
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:"1"
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeStatus.004
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeStatus
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeStatus.004
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnId:2
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:<<malloc 2>>
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:"1"
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeStatus.005
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeStatus
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeStatus.005
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnId:1
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:<<malloc 2>>
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:"1"
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeStatus.006
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeStatus
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeStatus.006
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnId:3
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:<<malloc 2>>
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:"1"
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:3
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:3
TEST.END

-- Test Case: DmnMgr_DmnSystemStateChangeStatus.007
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_DmnSystemStateChangeStatus
TEST.NEW
TEST.NAME:DmnMgr_DmnSystemStateChangeStatus.007
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnId:0
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:<<malloc 2>>
TEST.VALUE:DmnMgr_ControlDmn.DmnMgr_DmnSystemStateChangeStatus.DmnStatus:"1"
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:0
TEST.END

-- Subprogram: DmnMgr_StartDomainMonitoring

-- Test Case: DmnMgr_StartDomainMonitoring.001
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_StartDomainMonitoring
TEST.NEW
TEST.NAME:DmnMgr_StartDomainMonitoring.001
TEST.END

-- Test Case: DmnMgr_StartDomainMonitoring.002
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_StartDomainMonitoring
TEST.NEW
TEST.NAME:DmnMgr_StartDomainMonitoring.002
TEST.VALUE:uut_prototype_stubs.CUclProxyCdd_Impl_Initialize.return:1
TEST.END

-- Test Case: DmnMgr_StartDomainMonitoring.003
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_StartDomainMonitoring
TEST.NEW
TEST.NAME:DmnMgr_StartDomainMonitoring.003
TEST.VALUE:uut_prototype_stubs.CUclProxyCdd_Impl_OnCommand.return:1
TEST.END

-- Subprogram: DmnMgr_StopDomainMonitoring

-- Test Case: DmnMgr_StopDomainMonitoring.001
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_StopDomainMonitoring
TEST.NEW
TEST.NAME:DmnMgr_StopDomainMonitoring.001
TEST.END

-- Test Case: DmnMgr_StopDomainMonitoring.002
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_StopDomainMonitoring
TEST.NEW
TEST.NAME:DmnMgr_StopDomainMonitoring.002
TEST.VALUE:uut_prototype_stubs.CUclProxyCdd_Impl_Shutdown.return:1
TEST.END

-- Test Case: DmnMgr_StopDomainMonitoring.003
TEST.UNIT:DmnMgr_ControlDmn
TEST.SUBPROGRAM:DmnMgr_StopDomainMonitoring
TEST.NEW
TEST.NAME:DmnMgr_StopDomainMonitoring.003
TEST.VALUE:uut_prototype_stubs.CUclProxyCdd_Impl_Shutdown.return:0
TEST.VALUE:uut_prototype_stubs.CUclProxyCdd_Impl_OnCommand.return:1
TEST.END

-- Unit: DmnMgr_Main

-- Subprogram: CDmnMgr_Impl_MainFunction

-- Test Case: CDmnMgr_Impl_MainFunction.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CDmnMgr_Impl_MainFunction
TEST.NEW
TEST.NAME:CDmnMgr_Impl_MainFunction.001
TEST.END

-- Subprogram: CDmnMgr_Impl_OnCommand

-- Test Case: CDmnMgr_Impl_OnCommand.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CDmnMgr_Impl_OnCommand
TEST.NEW
TEST.NAME:CDmnMgr_Impl_OnCommand.001
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.EXPECTED:DmnMgr_Main.CmpActivation.return:MACRO=E_OK
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.STUB:DmnMgr_Main.DmnMgrProcessEvents
TEST.EXPECTED:DmnMgr_Main.CmpActive.return:MACRO=E_OK
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.EXPECTED:DmnMgr_Main.CmpDeActivation.return:MACRO=E_OK
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.EXPECTED:DmnMgr_Main.CmpDeInit.return:MACRO=E_OK
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.002
TEST.EXPECTED:DmnMgr_Main.CmpInit.return:MACRO=E_OK
TEST.END

-- Subprogram: DmnMgrProcessEvents

-- Test Case: DmnMgrProcessEvents.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.001
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.END

-- Test Case: DmnMgrProcessEvents.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.002
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:0xFFFFFFFF
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.END

-- Test Case: DmnMgrProcessEvents.003
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:0xFFFFFFFF
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.END

-- Test Case: DmnMgrProcessEvents.004
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.004
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:0xFFFFFFFF
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.END

-- Test Case: DmnMgrProcessEvents.005
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.005
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:0xFFFFFFFF
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:1
TEST.END

-- Test Case: DmnMgrProcessEvents.006
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.006
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:0xFFFFFFFF
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:1
TEST.END

-- Test Case: DmnMgrProcessEvents.007
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.007
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:0xFFFFFFFF
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:1
TEST.END

-- Test Case: DmnMgrProcessEvents.008
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.008
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:0xFFFFFFFF
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:0xFFFFFFFF
TEST.END

-- Test Case: DmnMgrProcessEvents.009
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.009
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:0xFFFFFFFF
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:1
TEST.END

-- Test Case: DmnMgrProcessEvents.010
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgrProcessEvents
TEST.NEW
TEST.NAME:DmnMgrProcessEvents.010
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1999
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:1
TEST.END

-- Subprogram: DmnMgr_CmpMain

-- Test Case: DmnMgr_CmpMain.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_CmpMain
TEST.NEW
TEST.NAME:DmnMgr_CmpMain.001
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 864 TEST.VALUE:uut_prototype_stubs.ModeAppLib_Main.return:0
    >>>     >>> Could not find function ModeAppLib_Main
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 865 TEST.EXPECTED:uut_prototype_stubs.ModeAppLib_Main.pContext[0].RequestedMode:0
    >>>     >>> Could not find function ModeAppLib_Main
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 866 TEST.EXPECTED:uut_prototype_stubs.ModeAppLib_Main.pContext[0].ActualMode:0
    >>>     >>> Could not find function ModeAppLib_Main
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 867 TEST.EXPECTED:uut_prototype_stubs.ModeMgr_SWCStatus.feature:3
    >>>     >>> Could not find function ModeMgr_SWCStatus
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 868 TEST.EXPECTED:uut_prototype_stubs.ModeMgr_SWCStatus.actualmode:0
    >>>     >>> Could not find function ModeMgr_SWCStatus
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
    >>> (E) @LINE: 869 TEST.EXPECTED:uut_prototype_stubs.ModeMgr_SWCStatus.InhibitLocalSleep:0
    >>>     >>> Could not find function ModeMgr_SWCStatus
    >>>     >>>    in unit uut_prototype_stubs.
    >>>     >>> Value Line Error - Command Ignored
TEST.END_IMPORT_FAILURES:
TEST.END

-- Subprogram: DmnMgr_MainCheckForFirstHB

-- Test Case: DmnMgr_MainCheckForFirstHB.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForFirstHB
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForFirstHB.001
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.pCfg[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckForFirstHB.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForFirstHB
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForFirstHB.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.pCfg[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckForFirstHB.003
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForFirstHB
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForFirstHB.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.pCfg[0].dmnTimeForFirstHBMs:2
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckForFirstHB.004
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForFirstHB
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForFirstHB.004
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.pCfg[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForFirstHB.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Subprogram: DmnMgr_MainCheckForFirstLinkUp

-- Test Case: DmnMgr_MainCheckForFirstLinkUp_MIN.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForFirstLinkUp
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForFirstLinkUp_MIN.001
TEST.VALUE:<<ALL_MIN>>
TEST.END

-- Test Case: DmnMgr_MainCheckForFirstLinkUp_MIN.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForFirstLinkUp
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForFirstLinkUp_MIN.002
TEST.VALUE:<<ALL_MIN>>
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.END

-- Test Case: DmnMgr_MainCheckForFirstLinkUp_MIN.003
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForFirstLinkUp
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForFirstLinkUp_MIN.003
TEST.VALUE:<<ALL_MIN>>
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Test Case: DmnMgr_MainCheckForFirstLinkUp_MIN.004
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForFirstLinkUp
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForFirstLinkUp_MIN.004
TEST.VALUE:<<ALL_MIN>>
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForFirstLinkUp.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUpWaitTime:0xFFFFFFFF
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUpWaitTime:0xFFFFFFFF
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:MACRO=UINT32_MAX_VALUE
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkUpbfrDownErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkDownbfrUpErrCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.invalidLinkStatus:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstLinkUpExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstHBExpiry:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.RcvdInvalidSeqCnt:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.ATTRIBUTES:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:INPUT_BASE=16
TEST.END

-- Subprogram: DmnMgr_MainCheckForHBMiss

-- Test Case: DmnMgr_MainCheckForHBMiss.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForHBMiss
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForHBMiss.001
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_MainCheckForHBMiss.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForHBMiss
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForHBMiss.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckForHBMiss.003
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForHBMiss
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForHBMiss.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBRcvPeriodicityMs:2
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:2
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckForHBMiss.004
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForHBMiss
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForHBMiss.004
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBMissCount:3
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckForHBMiss.005
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForHBMiss
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForHBMiss.005
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBMissCount:3
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.EXPECTED:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckForHBMiss.006
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForHBMiss
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForHBMiss.006
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBMissCount:3
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:0xFF
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckForHBMiss.007
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckForHBMiss
TEST.NEW
TEST.NAME:DmnMgr_MainCheckForHBMiss.007
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.systemUpTime:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.systemUpNow:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.pCfg[0].dmnHBMissCount:3
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:0x2
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:5
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainCheckForHBMiss.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.END

-- Subprogram: DmnMgr_MainCheckIfDmnShutRequested

-- Test Case: DmnMgr_MainCheckIfDmnShutRequested.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnShutRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnShutRequested.001
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:MACRO=ESystemState_Shutdown
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnShutRequested.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnShutRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnShutRequested.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:MACRO=ESystemState_Shutdown
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:5
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnShutRequested.003
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnShutRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnShutRequested.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnShutRequested.dmnId:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnShutRequested.004
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnShutRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnShutRequested.004
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:MACRO=ESystemState_Shutdown
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnShutRequested.005
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnShutRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnShutRequested.005
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:MACRO=ESystemState_Shutdown
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnShutRequested.006
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnShutRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnShutRequested.006
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:MACRO=ESystemState_Shutdown
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnShutRequested.007
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnShutRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnShutRequested.007
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:MACRO=ESystemState_Shutdown
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:6
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnShutRequested.008
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnShutRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnShutRequested.008
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:5
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.END

-- Subprogram: DmnMgr_MainCheckIfDmnWakeUpRequested

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.001
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:11
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:11
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.003
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:11
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.004
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.004
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.005
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.005
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:11
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:6
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.006
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.006
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:11
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.007
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.007
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:11
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.008
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.008
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:11
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:2
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.END

-- Test Case: DmnMgr_MainCheckIfDmnWakeUpRequested.009
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainCheckIfDmnWakeUpRequested
TEST.NEW
TEST.NAME:DmnMgr_MainCheckIfDmnWakeUpRequested.009
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:11
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainCheckIfDmnWakeUpRequested.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:2
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:1
TEST.END

-- Subprogram: DmnMgr_MainGetDmnUsrCfg

-- Test Case: DmnMgr_MainGetDmnUsrCfg.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainGetDmnUsrCfg
TEST.NEW
TEST.NAME:DmnMgr_MainGetDmnUsrCfg.002
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg:<<malloc 1>>
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_NOK
TEST.END

-- Test Case: DmnMgr_MainGetDmnUsrCfg.003
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainGetDmnUsrCfg
TEST.NEW
TEST.NAME:DmnMgr_MainGetDmnUsrCfg.003
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:0
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:0
TEST.END

-- Test Case: DmnMgr_MainGetDmnUsrCfg.004
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainGetDmnUsrCfg
TEST.NEW
TEST.NAME:DmnMgr_MainGetDmnUsrCfg.004
TEST.STUB:DmnMgr_Main.Domain_initconfigurations
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg:<<null>>
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:1
TEST.END

-- Test Case: DmnMgr_MainGetDmnUsrCfg.005
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainGetDmnUsrCfg
TEST.NEW
TEST.NAME:DmnMgr_MainGetDmnUsrCfg.005
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:0
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:0
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForShutdown:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:1
TEST.END

-- Test Case: DmnMgr_MainGetDmnUsrCfg.006
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainGetDmnUsrCfg
TEST.NEW
TEST.NAME:DmnMgr_MainGetDmnUsrCfg.006
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].dmnCnt:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnId:2
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:2
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnHBMissCount:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFirstHBMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForFullRunMs:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForUclLinkUp:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnTimeForShutdown:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:1
TEST.END

-- Subprogram: DmnMgr_MainGetDomainIdPostIdxCheck

-- Test Case: DmnMgr_MainGetDomainIdPostIdxCheck.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainGetDomainIdPostIdxCheck
TEST.NEW
TEST.NAME:DmnMgr_MainGetDomainIdPostIdxCheck.001
TEST.END

-- Test Case: DmnMgr_MainGetDomainIdPostIdxCheck.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainGetDomainIdPostIdxCheck
TEST.NEW
TEST.NAME:DmnMgr_MainGetDomainIdPostIdxCheck.002
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDomainIdPostIdxCheck.dmnId:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainGetDomainIdPostIdxCheck.return:0
TEST.END

-- Subprogram: DmnMgr_MainGetElapsedTicks

-- Test Case: DmnMgr_MainGetElapsedTicks.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:DmnMgr_MainGetElapsedTicks
TEST.NEW
TEST.NAME:DmnMgr_MainGetElapsedTicks.001
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.cmnDmnStatus.elapsedTicks:1
TEST.EXPECTED:DmnMgr_Main.DmnMgr_MainGetElapsedTicks.return:1
TEST.END

-- Subprogram: Domain_initconfigurations

-- Test Case: Domain_initconfigurations.001
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:Domain_initconfigurations
TEST.NEW
TEST.NAME:Domain_initconfigurations.001
TEST.END

-- Test Case: Domain_initconfigurations.002
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:Domain_initconfigurations
TEST.NEW
TEST.NAME:Domain_initconfigurations.002
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].dmnCnt:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:1
TEST.END

-- Test Case: Domain_initconfigurations.004
TEST.UNIT:DmnMgr_Main
TEST.SUBPROGRAM:Domain_initconfigurations
TEST.NEW
TEST.NAME:Domain_initconfigurations.004
TEST.VALUE:DmnMgr_ControlDmn.<<GLOBAL>>.b_DmnMgr_StopVarReset:0
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].dmnCnt:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnId:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnHBRcvPeriodicityMs:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnHBMissCount:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnTimeForFirstHBMs:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnTimeForFullRunMs:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnSeqCntrDeviation:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnTimeForUclLinkUp:1
TEST.VALUE:uut_prototype_stubs.DmnMgr_UserConfigurations.return[0].pDmnMgrCfgList[0].dmnTimeForShutdown:1
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.pDmnUsrCfg:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.<<GLOBAL>>.b_DmnMgr_StopVarReset:0
TEST.END

-- Unit: DmnMgr_MonitorDmn

-- Subprogram: DmnMgr_ConsolidatedDmnStatus

-- Test Case: DmnMgr_ConsolidatedDmnStatus.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.001
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:0
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:0
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.002
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.003
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.003
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:MACRO=EUclLinkState_Up
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:MACRO=EUclLinkState_Up
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.004
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.004
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.005
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.005
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:-7
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclFatalErrorRcvd:-7
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnCurSystemState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.006
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.006
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclLinkState:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclFatalErrorRcvd:-7
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHealthState:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.007
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.007
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:2
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnId:2
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:2
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.008
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.008
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:-7
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnId:2
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.009
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.009
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:4
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnId:2
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.010
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.010
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:6
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnId:2
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Test Case: DmnMgr_ConsolidatedDmnStatus.011
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ConsolidatedDmnStatus
TEST.NEW
TEST.NAME:DmnMgr_ConsolidatedDmnStatus.011
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:9
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnId:2
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].isFirstLinkUpRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclLinkState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnCurSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnReqSystemState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStateChangeReqStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnLastRstReason:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnHealthState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnThermalState:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[1].ErrStatus.RcvdInvalidSeqCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ConsolidatedDmnStatus.dmnId:1
TEST.END

-- Subprogram: DmnMgr_ErrorNotification

-- Test Case: DmnMgr_ErrorNotification.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ErrorNotification
TEST.NEW
TEST.NAME:DmnMgr_ErrorNotification.001
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ErrorNotification.ErrorCode:1
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclFatalErrorRcvd:1
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHealthState:MACRO=EDmnHealth_UCL_Fatal_Error
TEST.END

-- Test Case: DmnMgr_ErrorNotification.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ErrorNotification
TEST.NEW
TEST.NAME:DmnMgr_ErrorNotification.002
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ErrorNotification.ErrorCode:-52
TEST.END

-- Subprogram: DmnMgr_GetDmnRunTimeStatus

-- Test Case: DmnMgr_GetDmnRunTimeStatus.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_GetDmnRunTimeStatus
TEST.NEW
TEST.NAME:DmnMgr_GetDmnRunTimeStatus.001
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_MonitorGetDomainIdPostIdxCheck
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_MonitorGetDomainIdPostIdxCheck.return:2
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.END

-- Test Case: DmnMgr_GetDmnRunTimeStatus.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_GetDmnRunTimeStatus
TEST.NEW
TEST.NAME:DmnMgr_GetDmnRunTimeStatus.002
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_NOK
TEST.ATTRIBUTES:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:INPUT_BASE=8
TEST.END

-- Test Case: DmnMgr_GetDmnRunTimeStatus.003
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_GetDmnRunTimeStatus
TEST.NEW
TEST.NAME:DmnMgr_GetDmnRunTimeStatus.003
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:MACRO=FALSE
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:MACRO=EUclLinkState_Not_Rcvd
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:MACRO=EDmnChangeReqStatus_NoReq
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:MACRO=DMN_NOT_READY
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.RcvdInvalidSeqCnt:0
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.END

-- Test Case: DmnMgr_GetDmnRunTimeStatus.004
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_GetDmnRunTimeStatus
TEST.NEW
TEST.NAME:DmnMgr_GetDmnRunTimeStatus.004
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].isFirstLinkUpRcvd:MACRO=FALSE
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclLinkState:MACRO=EUclLinkState_Not_Rcvd
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUclFatalErrorRcvd:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnCurSystemState:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnReqSystemState:MACRO=EDmnChangeReqStatus_NoReq
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStateChangeReqStatus:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBMissCount:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastSeqCount:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHBLastRcvTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnLastRstReason:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnHealthState:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnThermalState:MACRO=UNKNOWN
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnStatus:MACRO=DMN_NOT_READY
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnExtendShutDownTimeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnShutDownWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnSystemAwakeWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnUpWaitTime:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkUpbfrDownErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.linkDownbfrUpErrCnt:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.invalidLinkStatus:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstLinkUpExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.dmnFirstHBExpiry:0
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].ErrStatus.RcvdInvalidSeqCnt:0
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.END

-- Subprogram: DmnMgr_LinkStatusChanged

-- Test Case: DmnMgr_LinkStatusChanged.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_LinkStatusChanged
TEST.NEW
TEST.NAME:DmnMgr_LinkStatusChanged.001
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-50
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-50
TEST.END

-- Test Case: DmnMgr_LinkStatusChanged.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_LinkStatusChanged
TEST.NEW
TEST.NAME:DmnMgr_LinkStatusChanged.002
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-51
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-51
TEST.END

-- Test Case: DmnMgr_LinkStatusChanged.003
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_LinkStatusChanged
TEST.NEW
TEST.NAME:DmnMgr_LinkStatusChanged.003
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:0
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:0
TEST.END

-- Test Case: DmnMgr_LinkStatusChanged.004
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_LinkStatusChanged
TEST.NEW
TEST.NAME:DmnMgr_LinkStatusChanged.004
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:MACRO=EUclLinkState_Down
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-50
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-50
TEST.END

-- Test Case: DmnMgr_LinkStatusChanged.005
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_LinkStatusChanged
TEST.NEW
TEST.NAME:DmnMgr_LinkStatusChanged.005
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].isFirstLinkUpRcvd:MACRO=TRUE
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-50
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-50
TEST.END

-- Test Case: DmnMgr_LinkStatusChanged.006
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_LinkStatusChanged
TEST.NEW
TEST.NAME:DmnMgr_LinkStatusChanged.006
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:MACRO=EUclLinkState_Up
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-51
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-51
TEST.END

-- Test Case: DmnMgr_LinkStatusChanged.007
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_LinkStatusChanged
TEST.NEW
TEST.NAME:DmnMgr_LinkStatusChanged.007
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnUclLinkState:MACRO=EUclLinkState_Down
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHealthState:0xFF
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-50
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_LinkStatusChanged.Status:-50
TEST.END

-- Subprogram: DmnMgr_MonitorDmnExtendShutdownTime

-- Test Case: DmnMgr_MonitorDmnExtendShutdownTime.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnExtendShutdownTime
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnExtendShutdownTime.001
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnExtendShutdownTime.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnExtendShutdownTime
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnExtendShutdownTime.002
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.return:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnExtendShutdownTime.003
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnExtendShutdownTime
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnExtendShutdownTime.003
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.data[0].timeoutMs:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.return:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnExtendShutdownTime.004
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnExtendShutdownTime
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnExtendShutdownTime.004
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.data[0].domainId:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.data[0].timeoutMs:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.return:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnExtendShutdownTime.005
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnExtendShutdownTime
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnExtendShutdownTime.005
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.data[0].domainId:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.data[0].timeoutMs:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData.return:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.EXPECTED:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnSystemAwakeWaitTime:0
TEST.END

-- Subprogram: DmnMgr_MonitorDmnHealthDumpData

-- Test Case: DmnMgr_MonitorDmnHealthDumpData.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHealthDumpData
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHealthDumpData.001
TEST.END

-- Subprogram: DmnMgr_MonitorDmnHealthDumpHdrInfo

-- Test Case: DmnMgr_MonitorDmnHealthDumpHdrInfo.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHealthDumpHdrInfo
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHealthDumpHdrInfo.001
TEST.END

-- Subprogram: DmnMgr_MonitorDmnHealthFatalError

-- Test Case: DmnMgr_MonitorDmnHealthFatalError.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHealthFatalError
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHealthFatalError.001
TEST.END

-- Test Case: DmnMgr_MonitorDmnHealthFatalError.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHealthFatalError
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHealthFatalError.002
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.data[0].compldx:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.return:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnHealthFatalError.003
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHealthFatalError
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHealthFatalError.003
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.data[0].domainId:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.data[0].compldx:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.return:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnHealthFatalError.004
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHealthFatalError
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHealthFatalError.004
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.data[0].domainId:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.data[0].compldx:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.return:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnHealthFatalError.005
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHealthFatalError
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHealthFatalError.005
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.data[0].domainId:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.data[0].compldx:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData.return:1
TEST.END

-- Subprogram: DmnMgr_MonitorDmnHeartBeat

-- Test Case: DmnMgr_MonitorDmnHeartBeat.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.001
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.002
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.003
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.003
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<null>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.004
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.004
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.005
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.005
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.006
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.006
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.007
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.007
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.008
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.008
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:0xFFFF
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.009
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.009
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:0xFFFF
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.010
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.010
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:0xFFFFFFFF
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnSeqCntrDeviation:0xFFFF
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnHBLastRcvTime:1
TEST.END

-- Test Case: DmnMgr_MonitorDmnHeartBeat.011
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnHeartBeat
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnHeartBeat.011
TEST.STUB:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.data[0].seqCnt:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData.return:0
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.pCfg[0][0].dmnId:1
TEST.VALUE:DmnMgr_Main.DmnMgr_MainGetDmnUsrCfg.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.END

-- Subprogram: DmnMgr_MonitorDmnKeepSystemAwake

-- Test Case: DmnMgr_MonitorDmnKeepSystemAwake.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnKeepSystemAwake
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnKeepSystemAwake.001
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.data[0].domainId:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.data[0].timeoutMs:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.return:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnKeepSystemAwake.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnKeepSystemAwake
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnKeepSystemAwake.002
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.return:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnKeepSystemAwake.003
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnKeepSystemAwake
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnKeepSystemAwake.003
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.data[0].domainId:1
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.data[0].timeoutMs:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.return:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.END

-- Test Case: DmnMgr_MonitorDmnKeepSystemAwake.004
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnKeepSystemAwake
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnKeepSystemAwake.004
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.data[0].domainId:3
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.data[0].timeoutMs:0
TEST.VALUE:uut_prototype_stubs.Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData.return:0
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnKeepSystemAwakeMs:0
TEST.END

-- Subprogram: DmnMgr_MonitorDmnPowerSystemState

-- Test Case: DmnMgr_MonitorDmnPowerSystemState.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnPowerSystemState
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnPowerSystemState.001
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:3
TEST.ATTRIBUTES:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:INPUT_BASE=8
TEST.END

-- Test Case: DmnMgr_MonitorDmnPowerSystemState.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnPowerSystemState
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnPowerSystemState.002
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:3
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:3
TEST.ATTRIBUTES:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:INPUT_BASE=8
TEST.END

-- Test Case: DmnMgr_MonitorDmnPowerSystemState.003
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorDmnPowerSystemState
TEST.NEW
TEST.NAME:DmnMgr_MonitorDmnPowerSystemState.003
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnCurSystemState:6
TEST.VALUE:DmnMgr_MonitorDmn.<<GLOBAL>>.DmnMgrStatus[0].dmnReqSystemState:6
TEST.ATTRIBUTES:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0][0].dmnKeepSystemAwakeMs:INPUT_BASE=8
TEST.END

-- Subprogram: DmnMgr_MonitorGetDomainIdPostIdxCheck

-- Test Case: DmnMgr_MonitorGetDomainIdPostIdxCheck.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_MonitorGetDomainIdPostIdxCheck
TEST.NEW
TEST.NAME:DmnMgr_MonitorGetDomainIdPostIdxCheck.001
TEST.END

-- Subprogram: DmnMgr_ResetDmnRunTimeStatus

-- Test Case: DmnMgr_ResetDmnRunTimeStatus.001
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ResetDmnRunTimeStatus
TEST.NEW
TEST.NAME:DmnMgr_ResetDmnRunTimeStatus.001
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ResetDmnRunTimeStatus.dmnId:0
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_ResetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.END

-- Test Case: DmnMgr_ResetDmnRunTimeStatus.002
TEST.UNIT:DmnMgr_MonitorDmn
TEST.SUBPROGRAM:DmnMgr_ResetDmnRunTimeStatus
TEST.NEW
TEST.NAME:DmnMgr_ResetDmnRunTimeStatus.002
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_ResetDmnRunTimeStatus.dmnId:3
TEST.EXPECTED:DmnMgr_MonitorDmn.DmnMgr_ResetDmnRunTimeStatus.return:1
TEST.END

-- Unit: DmnMgr_PublishDmnStatus

-- Subprogram: DmnMgr_PublishDmnHealthStaus

-- Test Case: DmnMgr_PublishDmnHealthStaus.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishDmnHealthStaus
TEST.NEW
TEST.NAME:DmnMgr_PublishDmnHealthStaus.001
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnHealthStaus.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnHealthStaus.return:MACRO=DMNMGR_E_OK
TEST.END

-- Test Case: DmnMgr_PublishDmnHealthStaus.002
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishDmnHealthStaus
TEST.NEW
TEST.NAME:DmnMgr_PublishDmnHealthStaus.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnHealthStaus.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnHealthStaus.return:MACRO=DMNMGR_E_NOK
TEST.END

-- Test Case: DmnMgr_PublishDmnHealthStaus.003
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishDmnHealthStaus
TEST.NEW
TEST.NAME:DmnMgr_PublishDmnHealthStaus.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:1
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnHealthStaus.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnHealthStaus.return:1
TEST.END

-- Subprogram: DmnMgr_PublishDmnSystemState

-- Test Case: DmnMgr_PublishDmnSystemState.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishDmnSystemState
TEST.NEW
TEST.NAME:DmnMgr_PublishDmnSystemState.001
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnSystemState.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnSystemState.return:MACRO=DMNMGR_E_OK
TEST.END

-- Test Case: DmnMgr_PublishDmnSystemState.002
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishDmnSystemState
TEST.NEW
TEST.NAME:DmnMgr_PublishDmnSystemState.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_NOK
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnSystemState.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnSystemState.return:MACRO=DMNMGR_E_NOK
TEST.END

-- Test Case: DmnMgr_PublishDmnSystemState.003
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishDmnSystemState
TEST.NEW
TEST.NAME:DmnMgr_PublishDmnSystemState.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnSystemState.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnSystemState.return:1
TEST.END

-- Subprogram: DmnMgr_PublishDmnThermalState

-- Test Case: DmnMgr_PublishDmnThermalState.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishDmnThermalState
TEST.NEW
TEST.NAME:DmnMgr_PublishDmnThermalState.001
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnThermalState.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishDmnThermalState.return:MACRO=DMNMGR_E_NOK
TEST.END

-- Subprogram: DmnMgr_PublishUclFatatError

-- Test Case: DmnMgr_PublishUclFatatError.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishUclFatatError
TEST.NEW
TEST.NAME:DmnMgr_PublishUclFatatError.001
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclFatatError.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclFatatError.return:MACRO=DMNMGR_E_OK
TEST.END

-- Test Case: DmnMgr_PublishUclFatatError.002
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishUclFatatError
TEST.NEW
TEST.NAME:DmnMgr_PublishUclFatatError.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_NOK
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclFatatError.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclFatatError.return:MACRO=DMNMGR_E_NOK
TEST.END

-- Test Case: DmnMgr_PublishUclFatatError.003
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishUclFatatError
TEST.NEW
TEST.NAME:DmnMgr_PublishUclFatatError.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:0
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclFatatError.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclFatatError.return:1
TEST.END

-- Subprogram: DmnMgr_PublishUclLinkStatus

-- Test Case: DmnMgr_PublishUclLinkStatus.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishUclLinkStatus
TEST.NEW
TEST.NAME:DmnMgr_PublishUclLinkStatus.001
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts[0]:<<malloc 1>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclLinkStatus.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclLinkStatus.return:MACRO=DMNMGR_E_OK
TEST.END

-- Test Case: DmnMgr_PublishUclLinkStatus.002
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishUclLinkStatus
TEST.NEW
TEST.NAME:DmnMgr_PublishUclLinkStatus.002
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_NOK
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclLinkStatus.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclLinkStatus.return:MACRO=DMNMGR_E_NOK
TEST.END

-- Test Case: DmnMgr_PublishUclLinkStatus.003
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_PublishUclLinkStatus
TEST.NEW
TEST.NAME:DmnMgr_PublishUclLinkStatus.003
TEST.STUB:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.dmnId:1
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.pDmnSts:<<null>>
TEST.VALUE:DmnMgr_MonitorDmn.DmnMgr_GetDmnRunTimeStatus.return:MACRO=DMNMGR_E_OK
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclLinkStatus.dmnId:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.DmnMgr_PublishUclLinkStatus.return:1
TEST.END

-- Subprogram: DmnMgr_SetDmnInfo_dmnHealthState

-- Test Case: DmnMgr_SetDmnInfo_dmnHealthState.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_SetDmnInfo_dmnHealthState
TEST.NEW
TEST.NAME:DmnMgr_SetDmnInfo_dmnHealthState.001
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_dmnHealthState.pData:<<malloc 1>>
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_dmnHealthState.pData[0]:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.<<GLOBAL>>.oDmnStatus.dmnHealthState:1
TEST.END

-- Subprogram: DmnMgr_SetDmnInfo_dmnId

-- Test Case: DmnMgr_SetDmnInfo_dmnId.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_SetDmnInfo_dmnId
TEST.NEW
TEST.NAME:DmnMgr_SetDmnInfo_dmnId.001
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_dmnId.pData:<<malloc 1>>
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_dmnId.pData[0]:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.<<GLOBAL>>.oDmnStatus.dmnId:1
TEST.END

-- Subprogram: DmnMgr_SetDmnInfo_dmnStatus

-- Test Case: DmnMgr_SetDmnInfo_dmnStatus.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_SetDmnInfo_dmnStatus
TEST.NEW
TEST.NAME:DmnMgr_SetDmnInfo_dmnStatus.001
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_dmnStatus.pData:<<malloc 1>>
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_dmnStatus.pData[0]:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.<<GLOBAL>>.oDmnStatus.dmnStatus:1
TEST.END

-- Subprogram: DmnMgr_SetDmnInfo_linkStatus

-- Test Case: DmnMgr_SetDmnInfo_linkStatus.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_SetDmnInfo_linkStatus
TEST.NEW
TEST.NAME:DmnMgr_SetDmnInfo_linkStatus.001
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_linkStatus.pData:<<malloc 1>>
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_linkStatus.pData[0]:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.<<GLOBAL>>.oDmnStatus.linkStatus:1
TEST.END

-- Subprogram: DmnMgr_SetDmnInfo_state

-- Test Case: DmnMgr_SetDmnInfo_state.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_SetDmnInfo_state
TEST.NEW
TEST.NAME:DmnMgr_SetDmnInfo_state.001
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_state.pData:<<malloc 1>>
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_state.pData[0]:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.<<GLOBAL>>.oDmnStatus.state:1
TEST.END

-- Subprogram: DmnMgr_SetDmnInfo_uclErrCode

-- Test Case: DmnMgr_SetDmnInfo_uclErrCode.001
TEST.UNIT:DmnMgr_PublishDmnStatus
TEST.SUBPROGRAM:DmnMgr_SetDmnInfo_uclErrCode
TEST.NEW
TEST.NAME:DmnMgr_SetDmnInfo_uclErrCode.001
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_uclErrCode.pData:<<malloc 1>>
TEST.VALUE:DmnMgr_PublishDmnStatus.DmnMgr_SetDmnInfo_uclErrCode.pData[0]:1
TEST.EXPECTED:DmnMgr_PublishDmnStatus.<<GLOBAL>>.oDmnStatus.uclErrCode:1
TEST.END
