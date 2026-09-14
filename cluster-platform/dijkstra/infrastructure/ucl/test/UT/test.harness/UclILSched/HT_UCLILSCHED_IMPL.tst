-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLILSCHED_IMPL
-- Unit(s) Under Test: UclILSched_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclILSched_Impl

-- Subprogram: UclILSched_Impl_FixedPrioSchedGetNextMessage

-- Test Case: UclILSched_Impl_FixedPrioSchedGetNextMessage_MutexLockfailed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_FixedPrioSchedGetNextMessage_MutexLockfailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_FixedPrioSchedGetNextMessage_WithnovalidMsgid
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_FixedPrioSchedGetNextMessage_WithnovalidMsgid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_FixedPrioSchedGetNextMessage_WithnovalidMsgid.MutexUnlock_fail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_FixedPrioSchedGetNextMessage_WithnovalidMsgid.MutexUnlock_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:2
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:(3)UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_FixedPrioSchedGetNextMessage_WithvalidMsgid
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_FixedPrioSchedGetNextMessage_WithvalidMsgid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:2
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_GetDLIdxForDestNode

-- Test Case: UclILSched_Impl_GetDLIdxForDestNode_for_loop_if_loop
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_GetDLIdxForDestNode
TEST.NEW
TEST.NAME:UclILSched_Impl_GetDLIdxForDestNode_for_loop_if_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.DestNode:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.pDLIdx:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.pDLIdx[0]:5
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.pInst
<<UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_GetDLIndex

-- Test Case: UclILSched_Impl_GetDLIndex_for_loop_if_loop
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_GetDLIndex
TEST.NEW
TEST.NAME:UclILSched_Impl_GetDLIndex_for_loop_if_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIndex.DLInstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIndex.DLIndex:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIndex.DLIndex[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_GetDLIndex.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_GetDLIndex.pInst
<<UclILSched_Impl.UclILSched_Impl_GetDLIndex.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_IUclDLCbk_FatalError

-- Test Case: UclILSched_Impl_IUclDLCbk_FatalError
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_FatalError
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_FatalError
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclILSched_Impl_IUclDLCbk_LinkStatusChanged

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusDown
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusDown
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Down
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Down
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:0
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusDown.001
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusDown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Down
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Down
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:0
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusUP_InvalidInstID
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusUP_InvalidInstID
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0_IUclDL[0]:5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Up
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusUP_InvalidInstID.001
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusUP_InvalidInstID.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0_IUclDL[0]:5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Up
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusUP_Timer_Already_running
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusUP_Timer_Already_running
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:10
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Up
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:10
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusUP_Timer_Already_running.001
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusUP_Timer_Already_running.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:10
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Up
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:10
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusUP_Timer_Not_running
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusUP_Timer_Not_running
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.timerTaskPeriodicityMs:5
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.schedulerPeriodicityMs:20
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.periodicMsgPeriodicityMs:40
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Up
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:8
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:4
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusUP_Timer_Not_running.001
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusUP_Timer_Not_running.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.timerTaskPeriodicityMs:5
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.schedulerPeriodicityMs:20
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.periodicMsgPeriodicityMs:40
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Up
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:8
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:4
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusUP_Whenanothers_instance_is_down
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusUP_Whenanothers_instance_is_down
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData1.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.numIUclDL:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:25
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Down
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:25
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_LinkStatusUP_Whenanothers_instance_is_down.001
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_LinkStatusUP_Whenanothers_instance_is_down.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData1.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.numIUclDL:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:25
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.Status:eUclDLLinkStatus_Down
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0..1]:25
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_IUclDLCbk_MsgReceived

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgReceived_DL_Send_Failed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgReceived_DL_Send_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].destNodeId:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.nodeId:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].numDestNodes:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].pDestNodeIds:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].pDestNodeIds[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.numIUclDL:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgHdr:0x1000
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].Size:5
TEST.VALUE:uut_prototype_stubs.UclDL_Send.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pMsgDbTx
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0>>.pMsgDbTx = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.pCfg
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0>>.pCfg = ( &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgReceived_DL_Send_Sucess
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgReceived_DL_Send_Sucess
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].destNodeId:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.nodeId:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].numDestNodes:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].pDestNodeIds:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].pDestNodeIds[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.numIUclDL:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgHdr:0x1000
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload:<<malloc 5>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].Size:5
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pMsgDbTx
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0>>.pMsgDbTx = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.pCfg
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0>>.pCfg = ( &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgReceived_GetDLIdx_Failed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgReceived_GetDLIdx_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].destNodeId:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.nodeId:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].numDestNodes:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].pDestNodeIds:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pDLCfg[0].pDestNodeIds[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.numIUclDL:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgHdr:0x7000
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload:<<malloc 9>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].pPayload:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].Size:5
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pMsgDbTx
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0>>.pMsgDbTx = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.pCfg
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0>>.pCfg = ( &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgReceived_NodeId_Matches
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgReceived_NodeId_Matches
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.nodeId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.Status:eUclDLRxStatus_Ok
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgHdr:0x100
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].MsgId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pMsg[0].Size:5
TEST.ATTRIBUTES:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.pCfg
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0>>.pCfg = ( &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusErr.Mutex_lock_return_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusErr.Mutex_lock_return_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_WaitForAck
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0x1001
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].notifyTxStatus:TRUE
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1001
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Error
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Retry
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusErr.Mutex_lock_true
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusErr.Mutex_lock_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_WaitForAck
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0x1001
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].notifyTxStatus:TRUE
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1001
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Error
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusOK
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_WaitForAck
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0x1001
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].notifyTxStatus:TRUE
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1001
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Ok
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusOK_InvalidAckstate
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusOK_InvalidAckstate
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_UpdateFlags
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0x1001
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].notifyTxStatus:TRUE
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1001
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Ok
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusOK_NotifyTxStatus_False
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusOK_NotifyTxStatus_False
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_UpdateFlags
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_WaitForAck
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0x1001
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].notifyTxStatus:FALSE
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1001
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Ok
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusOK_invalidMsgid
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusOK_invalidMsgid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_UpdateFlags
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_WaitForAck
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0x1003
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].notifyTxStatus:TRUE
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1001
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Ok
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusTimeout
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_AckstatusTimeout
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_WaitForAck
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0x1001
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].notifyTxStatus:TRUE
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1001
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Timeout
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Retry
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_InvalidAckstatus
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclDLCbk_MsgTransmitStatus_InvalidAckstatus
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_UpdateFlags
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_WaitForAck
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0x1001
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].notifyTxStatus:TRUE
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.MsgId:0x1001
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.Status:eUclDLAckStatus_Last
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_IUclILSched_Initialize

-- Test Case: UclILSched_Impl_IUclILSched_Initialize
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.pMutexId[0]:23
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.pTimerId[0]:0xAA
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.msgStatusFlagsMutexId:23
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.timerTaskId:0xAA
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize.001
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.pMutexId[0]:23
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.pTimerId[0]:0xAA
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.msgStatusFlagsMutexId:23
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.timerTaskId:0xAA
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize.GetDLIdxForDestNode_true
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize.GetDLIdxForDestNode_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].destNodeId:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].sendOnInit:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.pDLIdx:"s"
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pWork
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pWork = ( &ppMsgDbTx_Work );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pMsgDbTx
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0>>.pMsgDbTx = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.pCfg
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0>>.pCfg = ( &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize.WriteMessageToPrioQueue_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize.WriteMessageToPrioQueue_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].msgId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].destNodeId:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].priorityLevel:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].sendOnInit:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].pWork:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.pDLIdx:"s"
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_NOK
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize.WriteMessageToPrioQueue_true
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize.WriteMessageToPrioQueue_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].msgId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].destNodeId:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].priorityLevel:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].sendOnInit:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].pWork:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.pDLIdx:"s"
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_OK
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize.pTxMsg->pWork_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize.pTxMsg->pWork_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].msgId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].pWork:<<null>>
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize.pTxMsg->sendOnInit_true
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize.pTxMsg->sendOnInit_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].msgId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].sendOnInit:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst[0].pCfg[0].pMsgDbTx[0].pWork:<<malloc 1>>
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize_MutexcreateFail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize_MutexcreateFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.pMutexId:<<null>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize_RingbuffLinitFail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize_RingbuffLinitFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.pMutexId:<<null>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize_TimercreateFail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize_TimercreateFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Initialize_UCLDLinitFail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Initialize
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Initialize_UCLDLinitFail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.pMutexId:<<null>>
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerCreate.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStart.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Initialize.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_IUclILSched_NotifyMessageUpdate

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate.UclALOs_MutexLock_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate.UclALOs_MutexLock_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].periodictyMs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.msgStatusFlagsMutexId:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_MutexLock.MutexId
<<uut_prototype_stubs.UclALOs_MutexLock.MutexId>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pWork
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pWork = ( &ppMsgDbTx_Work );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pMsgDbTx
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0>>.pMsgDbTx = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = ( &UclILSchedInst_0, &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate.UclALOs_MutexLock_true
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate.UclALOs_MutexLock_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].msgId:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].periodictyMs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.msgStatusFlagsMutexId:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:1
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:1
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pWork
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pWork = ( &ppMsgDbTx_Work );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pMsgDbTx
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0>>.pMsgDbTx = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.pCfg
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0>>.pCfg = ( &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = ( &UclILSchedInst_0, &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_GetDLIdx_Failed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_GetDLIdx_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:10
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_NOK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:80
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Loaded_WaitforPeriodictimeframe
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Loaded_WaitforPeriodictimeframe
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:50
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].periodictyMs:50
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:30
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Deferred
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_MsgTransfer_BufferBased_Periodic
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_MsgTransfer_BufferBased_Periodic
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:10
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:80
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_MsgTransfer_Improper_Inputs
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_MsgTransfer_Improper_Inputs
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:10
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].destNodeId:0xA5
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0,10
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:10,0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:80
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_MsgTransfer_timeNow>nextSchedTime
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_MsgTransfer_timeNow>nextSchedTime
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:10
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].periodictyMs:131
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:81
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Mutex_lock_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Mutex_lock_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:50
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].periodictyMs:50
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.msgStatusFlagsMutexId:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:30
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.UclALOs_MutexLock.MutexId
<<uut_prototype_stubs.UclALOs_MutexLock.MutexId>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_PeriodicMsgConfigured@ZeroMsPeriodicity
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_PeriodicMsgConfigured@ZeroMsPeriodicity
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:10
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:80
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_PriorQ_FULL
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_PriorQ_FULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:10
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_BUFFER_FULL
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:80
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Deferred
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Scheduler_Not_Initialized
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Scheduler_Not_Initialized
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 9>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.ATTRIBUTES:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList.ppUclTest_DataUnitList[0].pBuffer[5]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Write_To_PriorQ_Failed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Write_To_PriorQ_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:10
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:80
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Write_To_PriorQ_Failed.002
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_NotifyMessageUpdate
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_NotifyMessageUpdate_Write_To_PriorQ_Failed.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:10
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.InstId:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.MsgIdx:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.DuIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer:<<malloc 6>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[0]:0xA1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[1]:0xA2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[2]:0xA3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[3]:0xA4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[4]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pBuffer[5]:0xA6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.Size:6
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:80
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_NotifyMessageUpdate.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_IUclILSched_Shutdown

-- Test Case: UclILSched_Impl_IUclILSched_Shutdown
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Shutdown
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Shutdown
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexDestroy.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Shutdown_MutexDestroyfail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Shutdown
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Shutdown_MutexDestroyfail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexDestroy.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Shutdown_TimerDestroyfail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Shutdown
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Shutdown_TimerDestroyfail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexDestroy.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclDL_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Shutdown_Timerstopfail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Shutdown
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Shutdown_Timerstopfail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexDestroy.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_IUclILSched_Shutdown_UCLDLshutdownFaill
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_IUclILSched_Shutdown
TEST.NEW
TEST.NAME:UclILSched_Impl_IUclILSched_Shutdown_UCLDLshutdownFaill
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexDestroy.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerStop.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_TimerDestroy.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Shutdown.return:UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst
<<UclILSched_Impl.UclILSched_Impl_IUclILSched_Shutdown.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_PrepareTransmitMessage

-- Test Case: UclILSched_Impl_PrepareTransmitMessage.msgLen<BuffLen_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage.msgLen<BuffLen_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pWork:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].numDataUnits:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].dataUnitId:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].numSignals:2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].pSignalList:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].pSignalList[0].pAdapterFunc:UclGen_Read_Signal3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 5>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:"abcd"
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:1
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage.msgLen<BuffLen_false_line_704
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage.msgLen<BuffLen_false_line_704
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pWork:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].numDataUnits:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].dataUnitId:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].numSignals:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].pSignalList:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].pSignalList[0].pAdapterFunc:UclGen_Read_Signal3
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].msgSize:2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg[0].pDataUnitList[0].pMsgAdapterFunc:UclGen_Read_Signal2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 5>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:"abcd"
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:1
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_Attribute_always_InvalidSignalID
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_Attribute_always_InvalidSignalID
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:INPUT_BASE=16,EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList.ppUclTest_DataUnitList[0].pSignalList
<<UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList>>[0].pSignalList = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList.ppUclTest_DataUnitList[1].pSignalList
<<UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList>>[1].pSignalList = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_Attribute_always_Messagebased_CallbackInvalid
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_Attribute_always_Messagebased_CallbackInvalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.RetAdapterFunc:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].msgSize:6
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].pMsgAdapterFunc:UclGen_Read_Signal2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].msgSize:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].pMsgAdapterFunc:UclGen_Read_Signal3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:4
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:4
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_Attribute_always_Messagebased_Invalid
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_Attribute_always_Messagebased_Invalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].msgSize:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].pMsgAdapterFunc:UclGen_Read_Signal1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].msgSize:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].pMsgAdapterFunc:UclGen_Read_Signal3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_Attribute_always_SignalBased
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_Attribute_always_SignalBased
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:16
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0xA2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0xA3
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0xA4
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0xA5
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0xA6
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0x1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0x2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0xA2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:16
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_Attribute_always_SignalBased_CallbackInvalid
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_Attribute_always_SignalBased_CallbackInvalid
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.RetAdapterFunc:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:14
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0xA2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0xA3
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0xA4
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0xA5
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0xA6
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0x2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:14
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_Attribute_onchange
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_Attribute_onchange
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_OnChange
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:16
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0xA2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0xA3
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0xA4
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0xA5
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0xA6
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0x1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0x2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0xA2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:16
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_DuSize_Zero
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_DuSize_Zero
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Retry
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].msgSize:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].pMsgAdapterFunc:UclGen_Read_Signal1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].msgSize:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].pMsgAdapterFunc:UclGen_Read_Signal3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:12
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pDataUnitList
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pDataUnitList = ( &ppUclTest_DataUnitList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_MsgAdapterFunc_NULL
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_MsgAdapterFunc_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Retry
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].msgSize:6
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].pMsgAdapterFunc:<<null>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].msgSize:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].pMsgAdapterFunc:UclGen_Read_Signal1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pDataUnitList
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pDataUnitList = ( &ppUclTest_DataUnitList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_MsgSignalAdapterFunc_NULL
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_MsgSignalAdapterFunc_NULL
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Retry
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].numSignals:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].msgSize:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].pMsgAdapterFunc:<<null>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].numSignals:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].msgSize:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].pMsgAdapterFunc:<<null>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:12
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.ppUclTestdataunit_2.ppUclTestdataunit_2[0].pAdapterFunc
<<UclILSched_Impl.<<GLOBAL>>.ppUclTestdataunit_2>>[0].pAdapterFunc = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList.ppUclTest_DataUnitList[0].pSignalList
<<UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList>>[0].pSignalList = ( &ppUclTestdataunit_2 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList.ppUclTest_DataUnitList[1].pSignalList
<<UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList>>[1].pSignalList = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pDataUnitList
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pDataUnitList = ( &ppUclTest_DataUnitList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_Msg_Retry
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_Msg_Retry
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Retry
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].msgSize:6
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].pMsgAdapterFunc:UclGen_Read_Signal1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].msgSize:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].pMsgAdapterFunc:UclGen_Read_Signal3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:12
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0xA2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0xA3
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0xA4
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0xA5
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0xA6
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0x0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0x2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0xA1
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:12
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pDataUnitList
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pDataUnitList = ( &ppUclTest_DataUnitList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_No_DUs_Present
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_No_DUs_Present
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Retry
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].msgSize:6
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].pMsgAdapterFunc:UclGen_Read_Signal1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].msgSize:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].pMsgAdapterFunc:UclGen_Read_Signal3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:12
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_NOK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pDataUnitList
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pDataUnitList = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_PrepareTransmitMessage_flag_eUclILMsgDbTxMsgStatus_SendOnInit
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_PrepareTransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_PrepareTransmitMessage_flag_eUclILMsgDbTxMsgStatus_SendOnInit
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_SendOnInit
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].msgSize:6
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[0].pMsgAdapterFunc:<<null>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].numSignals:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].msgSize:2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppUclTest_DataUnitList[1].pMsgAdapterFunc:UclGen_Read_Signal1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].numDataUnits:2
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[1]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[2]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[3]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[4]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[5]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[6]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[7]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[8]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[9]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[10]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[11]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[12]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[13]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[14]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pMsgBuff[15]:EXPECTED_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pDataUnitList
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pDataUnitList = ( &ppUclTest_DataUnitList );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_ProcessTransmitPeriodicMessages

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages.flag_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages.flag_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:5
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_OnChange
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.msgStatusFlagsMutexId:5
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.MutexId:5
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.MutexId:5
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx.UclILMsgDbTx[0].pWork
<<UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx>>[0].pWork = ( &ppMsgDbTx_Work );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pMsgDbTx
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0>>.pMsgDbTx = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedCfg_0, &UclILSchedInst_0
 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages.mutex_lock_return_true
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages.mutex_lock_return_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:100
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages.nextSchedTime>timenow
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages.nextSchedTime>timenow
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:35
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:80
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages.schedAttrib_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages.schedAttrib_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Deferred
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_OnWrite
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:100
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages_GetDLIdx_Failed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages_GetDLIdx_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:100
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages_Invalidstatus
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages_Invalidstatus
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_OnWrite
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:100
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages_MsgPeriodicityGTtimenow
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages_MsgPeriodicityGTtimenow
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:10
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages_PriorityQueueFAiled
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages_PriorityQueueFAiled
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:100
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages_WriteToPrioQueue_Failed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages_WriteToPrioQueue_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:100
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages_Wrngdestnode
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages_Wrngdestnode
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_GetDLIdxForDestNode.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:100
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_ProcessTransmitPeriodicMessages_numMsgDbTxMsgs_for_loop
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.NEW
TEST.NAME:UclILSched_Impl_ProcessTransmitPeriodicMessages_numMsgDbTxMsgs_for_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:30
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].schedAttrib:eUclILMsgDbSchedAttrib_Periodic
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:uut_prototype_stubs.UclALOs_GetSystemTimeMs.return:100
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.timeStampMs:150
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst
<<UclILSched_Impl.UclILSched_Impl_ProcessTransmitPeriodicMessages.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_RunFixedPrioScheduler

-- Test Case: UclILSched_Impl_RunFixedPrioSchedule_TransmitMessageFailed_mutex_lock_return_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioSchedule_TransmitMessageFailed_mutex_lock_return_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_NOK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:1
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioSchedule_TransmitMessageFailed_set_flag
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioSchedule_TransmitMessageFailed_set_flag
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_NOK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Retry
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioSchedule_ZeroLenPayload
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioSchedule_ZeroLenPayload
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.pLength[0]:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg:<<null>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Idle
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioScheduler.numMsgDbTxMsgs>MsgIdx_false
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioScheduler.numMsgDbTxMsgs>MsgIdx_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0xA
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.InstId:0
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_OK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]::INPUT_BASE=16
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioScheduler_In_otherstate
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioScheduler_In_otherstate
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Error
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Error
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioScheduler_SubFunc_failed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioScheduler_SubFunc_failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.isInitialized:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_PrepareTransmitMessage.return:UCL_E_NOK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_Error
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:INPUT_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioScheduler_Sucessfu_Mutiplestates
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioScheduler_Sucessfu_Mutiplestates
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags
<<UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work>>.flags = ( 0x5 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioScheduler_Sucessfu_Mutiplestates.ret==NOK
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioScheduler_Sucessfu_Mutiplestates.ret==NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.schedMsgRetryScratchBufferSize:20
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[0]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[1]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[2]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[3]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[4]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[5]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[6]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[7]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[8]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[9]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[10]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[11]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[12]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[13]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[14]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[15]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[16]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[17]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[18]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[19]:0xFF
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_NOK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags
<<UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work>>.flags = ( 0x5 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.pCfg
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0>>.pCfg = ( &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioScheduler_Sucessfu_Mutiplestates_mutex_unlock
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioScheduler_Sucessfu_Mutiplestates_mutex_unlock
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.numMsgDbTxMsgs:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.schedMsgRetryScratchBufferSize:20
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer:<<malloc 20>>
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[0]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[1]:0xFF
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[2]:0x3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[3]:0x4
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[4]:0x5
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[5]:0x5
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[6]:0x6
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[7]:0x5
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[8]:0x4
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[9]:0x3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[10]:0x2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[11]:0x3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[12]:0x4
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[13]:0x5
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[14]:0x3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[15]:0x3
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[16]:0x2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[17]:0x2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[18]:0x2
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedCfg_0.pSchedMsgRetryScratchBuffer[19]:0x5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexUnlock.return:UCL_E_NOK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags
<<UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work>>.flags = ( 0x5 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.pCfg
<<UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0>>.pCfg = ( &UclILSchedCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioScheduler_Sucessful_update_flag_-4
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioScheduler_Sucessful_update_flag_-4
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:-4
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunFixedPrioScheduler_TransmitMsg_Sucessful
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunFixedPrioScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunFixedPrioScheduler_TransmitMsg_Sucessful
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_TransmitMessage
TEST.STUB:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:20
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.DLIdx:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:0x0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[1]:0x1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.return:UCL_E_OK,UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.ppMsgDbTx_Work.flags:eUclILMsgDbTxMsgStatus_WaitForAck
TEST.ATTRIBUTES:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pMsgIdx[0]:EXPECTED_BASE=16
TEST.STUB_VAL_USER_CODE:UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_FixedPrioSchedGetNextMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_RunMessageScheduler

-- Test Case: UclILSched_Impl_RunMessageScheduler_numIUclDl_for_loop
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunMessageScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunMessageScheduler_numIUclDl_for_loop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_RunMessageScheduler_trylock_Failed
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_RunMessageScheduler
TEST.NEW
TEST.NAME:UclILSched_Impl_RunMessageScheduler_trylock_Failed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclILSched_Impl.UclILSched_Impl_RunFixedPrioScheduler
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexTryLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst
<<UclILSched_Impl.UclILSched_Impl_RunMessageScheduler.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_TimerTask

-- Test Case: UclILSched_Impl_TimerTask.001_localtimers_false_ifloop
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TimerTask
TEST.NEW
TEST.NAME:UclILSched_Impl_TimerTask.001_localtimers_false_ifloop
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:45
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TimerTask.return:<<null>>
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:44
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TimerTask.pData
<<UclILSched_Impl.UclILSched_Impl_TimerTask.pData>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_TimerTask.localtimers_localtimercbk
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TimerTask
TEST.NEW
TEST.NAME:UclILSched_Impl_TimerTask.localtimers_localtimercbk
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:45
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:1
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[0]:UclILSched_Impl_ProcessTransmitPeriodicMessages
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimersCbk[1]:UclILSched_Impl_RunMessageScheduler
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TimerTask.return:<<null>>
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[0]:44
TEST.EXPECTED:UclILSched_Impl.<<GLOBAL>>.UclILSchedInst_0.localTimers[1]:0
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TimerTask.pData
<<UclILSched_Impl.UclILSched_Impl_TimerTask.pData>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_TransmitMessage

-- Test Case: UclILSched_Impl_TransmitMessage_Authenticated_linkStatus_Up
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_TransmitMessage_Authenticated_linkStatus_Up
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].securityLevel:eUclILMsgDbSecurityLevel_Authenticated
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff:<<malloc 2>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[0]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[1]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_TransmitMessage_Encrypted
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_TransmitMessage_Encrypted
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].securityLevel:eUclILMsgDbSecurityLevel_Encrypted
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff:<<malloc 2>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[0]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[1]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_TransmitMessage_NormalMessage_Criticalpriority
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_TransmitMessage_NormalMessage_Criticalpriority
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].securityLevel:eUclILMsgDbSecurityLevel_Unsecure
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].priorityLevel:eUclILMsgDbPriorityLevel_Critical
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff:<<malloc 2>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[0]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[1]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_TransmitMessage_NormalMessage_Highpriority
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_TransmitMessage_NormalMessage_Highpriority
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].securityLevel:eUclILMsgDbSecurityLevel_Unsecure
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].priorityLevel:eUclILMsgDbPriorityLevel_High
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff:<<malloc 2>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[0]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[1]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_TransmitMessage_NormalMessage_InvalidState
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_TransmitMessage_NormalMessage_InvalidState
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Last
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].securityLevel:eUclILMsgDbSecurityLevel_Unsecure
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].priorityLevel:eUclILMsgDbPriorityLevel_Critical
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff:<<malloc 2>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[0]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[1]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_TransmitMessage_NormalMessage_Invalidpriority
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_TransmitMessage_NormalMessage_Invalidpriority
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].securityLevel:eUclILMsgDbSecurityLevel_Unsecure
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].priorityLevel:eUclILMsgDbPriorityLevel_Last
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff:<<malloc 2>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[0]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[1]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_TransmitMessage_NormalMessage_Medpriority
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_TransmitMessage_NormalMessage_Medpriority
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].securityLevel:eUclILMsgDbSecurityLevel_Unsecure
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UclILMsgDbTx[0].priorityLevel:eUclILMsgDbPriorityLevel_Medium
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff:<<malloc 2>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[0]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[1]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_TransmitMessage_NormalMessage_lowpriority
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_TransmitMessage
TEST.NEW
TEST.NAME:UclILSched_Impl_TransmitMessage_NormalMessage_lowpriority
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.<<GLOBAL>>.UCLILSCHEDCFG_0_DL0_SUclILSchedDLData.linkStatus:eUclDLLinkStatus_Up
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff:<<malloc 2>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[0]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pMsgBuff[1]:0xA5
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.Length:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_TransmitMessage.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg
<<UclILSched_Impl.UclILSched_Impl_TransmitMessage.pTxMsg>> = ( &UclILMsgDbTx );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_UpdateFlags

-- Test Case: UclILSched_Impl_UpdateFlags_Clear.001_bset_false_idle
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_UpdateFlags
TEST.NEW
TEST.NAME:UclILSched_Impl_UpdateFlags_Clear.001_bset_false_idle
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_UpdateFlags.pFlags:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_UpdateFlags.bSet:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_UpdateFlags.Bits:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_UpdateFlags.pFlags[0]:eUclILMsgDbTxMsgStatus_Idle
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_UpdateFlags.pInst
<<UclILSched_Impl.UclILSched_Impl_UpdateFlags.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_UpdateFlags_bSet_true_ready_to_send
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_UpdateFlags
TEST.NEW
TEST.NAME:UclILSched_Impl_UpdateFlags_bSet_true_ready_to_send
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_UpdateFlags.pFlags:<<malloc 1>>
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_UpdateFlags.bSet:1
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_UpdateFlags.Bits:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_UpdateFlags.pFlags[0]:eUclILMsgDbTxMsgStatus_ReadyToSend
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_UpdateFlags.pInst
<<UclILSched_Impl.UclILSched_Impl_UpdateFlags.pInst>> = (& UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclILSched_Impl_WriteMessageToPrioQueue

-- Test Case: UclILSched_Impl_WriteMessageToPrioQueue.FillCnt>0_ret_-5
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_WriteMessageToPrioQueue
TEST.NEW
TEST.NAME:UclILSched_Impl_WriteMessageToPrioQueue.FillCnt>0_ret_-5
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.Prio:eUclILMsgDbPriorityLevel_Critical
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:0x1000
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:-5
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_GetFillCnt.pSize[0]:30
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.pInst
<<UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_WriteMessageToPrioQueue.FillCnt>1
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_WriteMessageToPrioQueue
TEST.NEW
TEST.NAME:UclILSched_Impl_WriteMessageToPrioQueue.FillCnt>1
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.Prio:eUclILMsgDbPriorityLevel_Critical
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:0x1000
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_GetFillCnt.pSize[0]:2
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.pInst
<<UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx=PrioMsgIdx
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_WriteMessageToPrioQueue
TEST.NEW
TEST.NAME:UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx=PrioMsgIdx
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.Prio:eUclILMsgDbPriorityLevel_Critical
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:0x0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:-5
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_GetFillCnt.pSize[0]:2
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.pInst
<<UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclILSched_Impl_WriteMessageToPrioQueue.Mutex_lock_fail
TEST.UNIT:UclILSched_Impl
TEST.SUBPROGRAM:UclILSched_Impl_WriteMessageToPrioQueue
TEST.NEW
TEST.NAME:UclILSched_Impl_WriteMessageToPrioQueue.Mutex_lock_fail
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.DLIdx:0
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.Prio:eUclILMsgDbPriorityLevel_Critical
TEST.VALUE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.MsgIdx:0x1000
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.EXPECTED:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.pInst
<<UclILSched_Impl.UclILSched_Impl_WriteMessageToPrioQueue.pInst>> = ( &UclILSchedInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
