-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : HT_UCLALPHYSERIALASR_IMPL
-- Unit(s) Under Test: UclALPhySerialASR_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALPhySerialASR_Impl

-- Subprogram: UclALPhySerialASR_Impl_IUclALHwCbk_GpioChanged

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_GpioChanged.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_GpioChanged
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_GpioChanged.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.InstId:0
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst>> = ( &TestSUclALPhySerialASRInst   );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.InstId:0
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Busy
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst>> = ( &TestSUclALPhySerialASRInst   );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.003
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.InstId:0
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.pLength[0]:10
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst>> = ( &TestSUclALPhySerialASRInst   );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.DMAMode
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.DMAMode
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.peerReadyState:eUclALPhyPeerReadyStatus_Ready
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.InstId:0
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.pLength[0]:10
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst>> = ( &TestSUclALPhySerialASRInst   );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.DMAMode.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.DMAMode.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].enableDMA:2
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.peerReadyState:eUclALPhyPeerReadyStatus_Ready
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.InstId:0
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.pLength[0]:10
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_ReceiveComplete.pInst>> = ( &TestSUclALPhySerialASRInst   );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.InstId:0
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.pInst>> = ( &TestSUclALPhySerialASRInst  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.InstId:0
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Busy
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.pInst>> = ( &TestSUclALPhySerialASRInst  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.003
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].periodicityMs:1
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.InstId:0
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALHwCbk_TransmitComplete.pInst>> = ( &TestSUclALPhySerialASRInst  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_IUclALPhy_Initialize

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_Ringbufferfailed.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_Ringbufferfailed.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Uninit
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_Ringbufferfailed.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_Ringbufferfailed.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].periodicityMs:1
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:0
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Uninit
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_SciChannelEnFailed.003
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_SciChannelEnFailed.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.VALUE:uut_prototype_stubs.SciDrv_EnableChn.return:1
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_SciModeSetFailed.004
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_SciModeSetFailed.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.VALUE:uut_prototype_stubs.SciDrv_EnableChn.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_SetAsyncMode.return:1
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_Scidriverfailed.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_Scidriverfailed.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_ScitReceiveModeSetFailed.005
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_ScitReceiveModeSetFailed.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.VALUE:uut_prototype_stubs.SciDrv_EnableChn.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:1
TEST.VALUE:uut_prototype_stubs.SciDrv_SetAsyncMode.return:0
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_Valid.006
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_Valid.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.VALUE:uut_prototype_stubs.SciDrv_EnableChn.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_SetAsyncMode.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_ValidDMAMode
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_ValidDMAMode
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.VALUE:uut_prototype_stubs.SciDrv_EnableChn.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_SetAsyncMode.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_ValidDMAMode.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_ValidDMAMode.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].channelId:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].enableDMA:1
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.VALUE:uut_prototype_stubs.SciDrv_EnableChn.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_SetAsyncMode.SciDrvMode:eSciDrvAsyncMode_Dma
TEST.VALUE:uut_prototype_stubs.SciDrv_SetAsyncMode.return:1
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_ValidDMAMode.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_ValidDMAMode.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.periodicityMs:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.return:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.VALUE:uut_prototype_stubs.SciDrv_EnableChn.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_SetAsyncMode.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Initialize_ValidInvalidMode
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Initialize
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Initialize_ValidInvalidMode
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:2
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.InstId:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetStatus.return:eSciDrvStatus_Ready
TEST.VALUE:uut_prototype_stubs.SciDrv_EnableChn.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_SetAsyncMode.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALPhyCbk_PeerReadyStatusChanged.Status:eUclALPhyPeerReadyStatus_NotReady
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Initialize.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_IUclALPhy_Read

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Read_InvalidDataptr.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Read_InvalidDataptr.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pData:<<malloc 9>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pData:<<null>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize[0]:25
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Read_InvalidRingbufferfunc.004
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Read_InvalidRingbufferfunc.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize[0]:25
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_ReadFrame.return:UCL_E_NOK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Read_Invalidsizeptr.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Read_Invalidsizeptr.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize:<<null>>
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Read_Invalidsizeval.003
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Read_Invalidsizeval.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize[0]:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Read_Valid.005
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Read
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Read_Valid.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pSize[0]:25
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_ReadFrame.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Read.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_IUclALPhy_Shutdown

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Shutdown_SCIDisable_Sucess.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Shutdown
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Shutdown_SCIDisable_Sucess.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Shutdown.InstId:0
TEST.VALUE:uut_prototype_stubs.SciDrv_DisableChn.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Shutdown.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Shutdown.pInst>> = ( &TestSUclALPhySerialASRInst); 
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_IUclALPhy_Write

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidInputPtr.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidInputPtr.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pData:<<null>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.Size:25
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidInputSize.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidInputSize.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.Size:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidRingBufferFunc.003
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidRingBufferFunc.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.Size:25
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_NOK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidRingBufferFunc.004
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidRingBufferFunc.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].periodicityMs:1
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.Size:25
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_NOK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidSetupTransmitFunc.004
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Write_InvalidSetupTransmitFunc.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.Size:25
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Write_ValidSetup.005
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Write_ValidSetup.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.Size:25
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Write_ValidSetup.006
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Write_ValidSetup.006
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.Size:25
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_OK
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_IUclALPhy_Write_ValidSetup.007
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_IUclALPhy_Write
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_IUclALPhy_Write_ValidSetup.007
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:0
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk[0]:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.InstId:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pData:<<malloc 25>>
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.Size:25
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Write.return:UCL_E_BUFFER_FULL
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.return:UCL_E_BUFFER_FULL
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_IUclALPhy_Write.pInst>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_ReadData

-- Test Case: UclALPhySerialASR_Impl_ReadData.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_ReadData
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_ReadData.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.rxDmaBufferSize:20
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.Count:21
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.pInst>> = ( &TestSUclALPhySerialASRInst  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_ReadData.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_ReadData
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_ReadData.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.rxDmaBufferSize:20
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.Count:19
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.pInst>> = ( &TestSUclALPhySerialASRInst  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_ReadData.003
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_ReadData
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_ReadData.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.rxDmaBufferSize:20
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.Count:19
TEST.VALUE:uut_prototype_stubs.SciDrv_ReadIB.return:1
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_ReadData.pInst>> = ( &TestSUclALPhySerialASRInst  );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_SetupReceive

-- Test Case: UclALPhySerialASR_Impl_SetupReceive_InvalidMode
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupReceive
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupReceive_InvalidMode
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:2
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupReceive_SCI_Busy.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupReceive
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupReceive_SCI_Busy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:0
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Busy
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupReceive_SCI_Busy_AsyncRx_Sucess.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupReceive
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupReceive_SCI_Busy_AsyncRx_Sucess.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Busy
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupReceive_SCI_Idle_AsyncRx_Sucess.003
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupReceive
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupReceive_SCI_Idle_AsyncRx_Sucess.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SciDrv_ASyncReceive.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupReceive.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_SetupTransmit

-- Test Case: UclALPhySerialASR_Impl_SetupTransmit_SCI_AllValid.005
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupTransmit
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupTransmit_SCI_AllValid.005
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:4
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupTransmit_SCI_AllValid_DMA
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupTransmit
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupTransmit_SCI_AllValid_DMA
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:4
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupTransmit_SCI_AllValid_DMA.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupTransmit
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupTransmit_SCI_AllValid_DMA.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].enableDMA:0
TEST.VALUE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:1
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:4
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_SetupEB.return:1
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupTransmit_SCI_AllValid_DMA.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupTransmit
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupTransmit_SCI_AllValid_DMA.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRCfg.enableDMA:2
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:4
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupTransmit_SCI_Busy.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupTransmit
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupTransmit_SCI_Busy.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Busy
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupTransmit_SCI_Idle_Ringbuffer_fail.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupTransmit
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupTransmit_SCI_Idle_Ringbuffer_fail.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.numIUclALPhyCbk:1
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:<<malloc 5>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pIUclALPhyCbk:"NULL"
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:4
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupTransmit_SCI_Idle_Ringbuffer_fail.003
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupTransmit
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupTransmit_SCI_Idle_Ringbuffer_fail.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:0
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_SetupTransmit_SCI_Idle_Ringbuffer_pass_EB_fail.004
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_SetupTransmit
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_SetupTransmit_SCI_Idle_Ringbuffer_pass_EB_fail.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.pSize[0]:4
TEST.VALUE:uut_prototype_stubs.UclCmnRingBuffer_Read.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.SciDrv_GetChnResult.return:eSciDrvChnResult_Ok
TEST.EXPECTED:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit.pInst>> = ( &TestSUclALPhySerialASRInst);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALPhySerialASR_Impl_TimerTask

-- Test Case: UclALPhySerialASR_Impl_TimerTask.001
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_TimerTask.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].periodicityMs:1
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_TimerTask.pData
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_TimerTask.pData>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALPhySerialASR_Impl_TimerTask.002
TEST.UNIT:UclALPhySerialASR_Impl
TEST.SUBPROGRAM:UclALPhySerialASR_Impl_TimerTask
TEST.NEW
TEST.NAME:UclALPhySerialASR_Impl_TimerTask.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_SetupTransmit
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg:<<malloc 1>>
TEST.VALUE:UclALPhySerialASR_Impl.<<GLOBAL>>.TestSUclALPhySerialASRInst.pCfg[0].periodicityMs:0
TEST.VALUE_USER_CODE:UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_TimerTask.pData
<<UclALPhySerialASR_Impl.UclALPhySerialASR_Impl_TimerTask.pData>> = ( &TestSUclALPhySerialASRInst );
TEST.END_VALUE_USER_CODE:
TEST.END
