-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UDS_CORE_UT
-- Unit(s) Under Test: dk_srvc_uds_core dk_srvc_uds_tp_doip uds_core_component
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STANDARD_SPACING_R2
TEST.SCRIPT_FEATURE:OVERLOADED_CONST_SUPPORT
TEST.SCRIPT_FEATURE:UNDERSCORE_NULLPTR
TEST.SCRIPT_FEATURE:FULL_PARAMETER_TYPES
TEST.SCRIPT_FEATURE:STRUCT_DTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: dk_srvc_uds_core

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::startSessionTimer
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mP2TimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mP2StarTimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mP4TimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mS3TimecountInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mUdsMainFunctionPeriodInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mUdsBusyResponseForMultiRequestSupport:true
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mDtoolAddress:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mRdiagAddress:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).udsCoreConfig.mFtoolAddress:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mP2TimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mP2StarTimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mP4TimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mS3TimecountInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mUdsMainFunctionPeriodInMs:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mUdsBusyResponseForMultiRequestSupport:true
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mDtoolAddress:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mRdiagAddress:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mFtoolAddress:1
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mpTpInstance.dk::srvc::udscore::vcast_concrete_CUdsTpIf.<<constructor>>.vcast_concrete_CUdsTpIf().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_RxProcessing,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceTimeout
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs.return:2
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_WaitForResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1},{0},{1,1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.003
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.003
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceTimeout
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs.return:0
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_WaitForResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1},{0},{1,1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.004
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.004
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceTimeout
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs.return:0
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_WaitForResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1},{0},{1,0}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.005
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.005
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceTimeout
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mP2StarTimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs.return:2
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_WaitForResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1},{0},{1,0}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.006
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.006
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceTimeout
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mP2StarTimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs.return:2
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,false,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_WaitForResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1},{0},{1,0}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.007
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.007
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceTimeout
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mUdsCoreConfig.mP2StarTimeCountInMs:1
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs.return:0
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_TransmitResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1},{0},{1,1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.008
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.008
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mpTpInstance.dk::srvc::udscore::vcast_concrete_CUdsTpIf.<<constructor>>.vcast_concrete_CUdsTpIf().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_TransmitResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1},{0},{1,1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.009
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.009
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mpTpInstance.dk::srvc::udscore::vcast_concrete_CUdsTpIf.<<constructor>>.vcast_concrete_CUdsTpIf().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_TransmitResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Negative,true,{1},{0},{1,1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.010
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.010
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mpTpInstance.dk::srvc::udscore::vcast_concrete_CUdsTpIf.<<constructor>>.vcast_concrete_CUdsTpIf().<<call>>:0
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_TransmitResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Negative,true,{1},{0},{1,1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.011
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.011
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mpTpInstance:<<null>>
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_ResponseConfirmation,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Positive,true,{1},{0},{1,1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.012
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.012
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mpTpInstance:<<null>>
TEST.VALUE_USER_CODE:<<dk::srvc::udscore::CUdsCore instance>>.dk::srvc::udscore::CUdsCore.mDiagnosticConnection
<<dk::srvc::udscore::CUdsCore instance>>->mDiagnosticConnection[1] = {0,true,dk::srvc::udscore::CUdsCore::EDiagnosticProcesingState_t::EDiagnosticProcesingState_TransmitResponse,dk::srvc::udscore::CUdsCoreIf::ERequestType_t::ERequestType_PhysicalRequest,dk::srvc::udscore::CUdsCore::EResponseType_t::EResponse_Negative,true,{1},{0},{1,1}};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.013
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::diagnosticMainFunction.013
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection[0][1]:5
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection[0]:<<function 1>>
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::getConnectionStatus

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.001
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection[0]:<<function 1>>
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.002
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.clientAddress:16#0#
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentServiceId:1
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentRequestState:EDiagnosticProcesingState_Idle
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation.clientAddress:16#0#
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<null>>
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::onExit

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::onExit.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::onExit
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::onExit.001
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::onInit

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::onInit.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::onInit
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::onInit.001
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::reStartSessionTimer

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::reStartSessionTimer.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::reStartSessionTimer
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::reStartSessionTimer.001
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::requestIndication

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::requestIndication.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::requestIndication.001
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.pDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.dataLength:1
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::requestIndication.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::requestIndication.002
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.pDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.dataLength:1
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:false
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::requestIndication.003
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::requestIndication.003
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.pDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.dataLength:7168
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::requestIndication.004
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::requestIndication.004
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mDiagnosticConnection[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.pDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.dataLength:1
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:false
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::sendResponsePending

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::sendResponsePending.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::sendResponsePending
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::sendResponsePending.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mpTpInstance.dk::srvc::udscore::vcast_concrete_CUdsTpIf.<<constructor>>.vcast_concrete_CUdsTpIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentServiceId:1
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::sendResponsePending.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::sendResponsePending
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::sendResponsePending.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<null>>
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::sendResponsePending.003
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::sendResponsePending
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::sendResponsePending.003
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mpTpInstance:<<null>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentServiceId:1
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::startSessionTimer
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<null>>
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::serviceTimeout

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::serviceTimeout.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::serviceTimeout
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::serviceTimeout.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentServiceId:1
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::serviceTimeout.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::serviceTimeout
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::serviceTimeout.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<null>>
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mSessionTimer:1
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs.return:2
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mSessionTimer:1
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs.return:1
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing.003
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::sessionTimerProcessing.003
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::nowTimeMs
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.mSessionTimer:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::setTimingParameters

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::setTimingParameters.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::setTimingParameters
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::setTimingParameters.001
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::setTimingParameters.p2TimeCountInMs:1000
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::setTimingParameters.p2StarTimeCountInMs:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::setTimingParameters.p4TimeCountInMs:1000
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::setTimingParameters.p2TimeCountInMs:1000
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::setTimingParameters.p2StarTimeCountInMs:0
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::setTimingParameters.p4TimeCountInMs:1000
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::setUdsTpIf

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::setUdsTpIf.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::setUdsTpIf
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::setUdsTpIf.001
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::stopSessionTimer

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::stopSessionTimer.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::stopSessionTimer
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::stopSessionTimer.001
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::transmitConfirmation

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.transmitStatus:true
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mResponsePendingTransmitStatus:false
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.transmitStatus:true
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.transmitStatus:false
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mResponsePendingTransmitStatus:false
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.transmitStatus:false
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.003
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.003
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mResponsePendingTransmitStatus:true
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.004
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.004
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::notifyTransmitConfirmation
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::serviceProcessingDone
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<null>>
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsCore::updateResponse

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::updateResponse.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::updateResponse
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::updateResponse.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Positive
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentRequestState:EDiagnosticProcesingState_WaitForResponse
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer[0]:<<function 1>>
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Positive
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::updateResponse.002
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::updateResponse
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::updateResponse.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Negative
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.pResponseData:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentRequestState:EDiagnosticProcesingState_WaitForResponse
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer[0]:<<function 1>>
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Negative
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::updateResponse.003
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::updateResponse
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::updateResponse.003
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_BusyNRC
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.pResponseData:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentRequestState:EDiagnosticProcesingState_WaitForResponse
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer[0]:<<function 1>>
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_BusyNRC
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::updateResponse.004
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::updateResponse
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::updateResponse.004
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Rcrrp
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.pResponseData:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentRequestState:EDiagnosticProcesingState_WaitForResponse
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentResponseType:EResponse_Last
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer[0]:<<function 1>>
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Rcrrp
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::updateResponse.005
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::updateResponse
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::updateResponse.005
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Rcrrp
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.pResponseData:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentRequestState:EDiagnosticProcesingState_WaitForResponse
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentResponseType:EResponse_Suppress
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer[0]:<<function 1>>
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Rcrrp
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsCore::updateResponse.006
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsCore::updateResponse
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsCore::updateResponse.006
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus
TEST.VALUE:dk_srvc_uds_core.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsCore.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Suppress
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.pResponseData:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentRequestState:EDiagnosticProcesingState_WaitForResponse
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mCurrentResponseType:EResponse_Suppress
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::getConnectionStatus.return[0].mDataBuffer[0]:<<function 1>>
TEST.EXPECTED:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::updateResponse.responseType:EResponse_Suppress
TEST.END

-- Subprogram: log

-- Test Case: BASIS-PATH-001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:log
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (!inst->getEnabled() || !inst->init(loglevel, context)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:dk_srvc_uds_core.log.context:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.log.loglevel:<<MIN>>
TEST.VALUE:dk_srvc_uds_core.log.value:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dk::Logger::init.return:false
TEST.VALUE:uut_prototype_stubs.dk::Logger::getEnabled.return:false
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:log
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 2
TEST.NOTES:
This is an automatically generated test case.
   Test Path 1
      (1) if (!inst->getEnabled() || !inst->init(loglevel, context)) ==> TRUE
   Test Case Generation Notes:
TEST.END_NOTES:
TEST.VALUE:dk_srvc_uds_core.log.context:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_core.log.loglevel:<<MIN>>
TEST.VALUE:dk_srvc_uds_core.log.value:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dk::Logger::init.return:false
TEST.VALUE:uut_prototype_stubs.dk::Logger::getEnabled.return:false
TEST.END

-- Subprogram: logError

-- Test Case: BASIS-PATH-001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:logError
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Test Case: BASIS-PATH-001.001
TEST.UNIT:dk_srvc_uds_core
TEST.SUBPROGRAM:logError
TEST.NEW
TEST.NAME:BASIS-PATH-001.001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
   No branches in subprogram
TEST.END_NOTES:
TEST.END

-- Unit: dk_srvc_uds_tp_doip

-- Subprogram: (cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.001
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.001
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.STUB:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::requestDataIndication.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpSA:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTA:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTAType:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[0]:16#6E#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[1]:16#80#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.length:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpResult:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:"10"
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.result:21
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.002
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.002
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.STUB:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::requestDataIndication.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpSA:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTA:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTAType:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[0]:16#6E#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[1]:16#80#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.length:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpResult:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:"10"
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.result:21
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.003
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.003
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.STUB:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::requestDataIndication.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpSA:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTA:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTAType:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[0]:16#6E#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[1]:16#80#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.length:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpResult:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:"10"
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.result:21
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.004
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.004
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.STUB:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::requestDataIndication.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpSA:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTA:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTAType:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[0]:16#3E#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[1]:16#80#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.length:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpResult:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:"10"
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.result:21
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.005
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.005
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.STUB:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::requestDataIndication.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf:<<null>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpSA:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTA:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTAType:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[0]:16#3E#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[1]:16#80#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.length:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpResult:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:"10"
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.result:21
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.006
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.006
TEST.STUB:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication
TEST.STUB:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication
TEST.VALUE:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::requestIndication.return:true
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::requestDataIndication.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf:<<null>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpSA:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTA:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpTAType:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[0]:16#6E#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.pMessageData[1]:16#80#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.length:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::requestDataIndication.doIpResult:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:"10"
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.result:21
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsTpDoip::setUdsCoreIf

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::setUdsCoreIf.001
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::setUdsCoreIf
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::setUdsCoreIf.001
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::setUdsCoreIf.pUdsCoreIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.001
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.001
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0].mAddress:111
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0].mAddressType:ERequestType_PhysicalRequest
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData[0]:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData[1]:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.length:3
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.clientAddress:16#6F#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.return:16#0#
TEST.EXPECTED:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.return:16#1#
TEST.ATTRIBUTES:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.clientAddress:INPUT_BASE=16
TEST.ATTRIBUTES:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig.mUdsTpReceiveAddressConfig[0].mAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.002
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.002
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0].mAddress:111
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0].mAddressType:ERequestType_Last
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData[0]:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData[1]:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.length:3
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.clientAddress:16#6F#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.return:16#0#
TEST.EXPECTED:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.return:16#0#
TEST.ATTRIBUTES:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.clientAddress:INPUT_BASE=16
TEST.ATTRIBUTES:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig.mUdsTpReceiveAddressConfig[0].mAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.003
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.003
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0].mAddress:110
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0].mAddressType:ERequestType_Last
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData:<<malloc 2>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData[0]:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.pMessageData[1]:2
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.length:3
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.clientAddress:16#6F#
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.return:16#0#
TEST.EXPECTED:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::transmitDataRequest.return:16#0#
TEST.ATTRIBUTES:dk_srvc_uds_core.(cl)dk::srvc::udscore::CUdsCore::transmitConfirmation.clientAddress:INPUT_BASE=16
TEST.ATTRIBUTES:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mUdsTpDoipConfig.mUdsTpReceiveAddressConfig.mUdsTpReceiveAddressConfig[0].mAddress:INPUT_BASE=16
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.001
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.001
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::trasmitDataConfirmation.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpSA:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpTA:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpTAType:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpResult:0
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.002
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.002
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::trasmitDataConfirmation.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf.dk::srvc::udscore::vcast_concrete_CUdsCoreIf.<<constructor>>.vcast_concrete_CUdsCoreIf().<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpSA:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpTA:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpTAType:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpResult:1
TEST.END

-- Test Case: (cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.003
TEST.UNIT:dk_srvc_uds_tp_doip
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.003
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:1
TEST.VALUE:uut_prototype_stubs.dk::srvc::udscore::vcast_concrete_CUdsTpIf::trasmitDataConfirmation.doIpResult:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig:<<malloc 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).udsTpDoipConfig.mUdsTpReceiveAddressConfig[0]:<<function 1>>
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.<<constructor>>.CUdsTpDoip(const dk::srvc::udscore::CUdsTpDoip::SUdsTpDoipConfig_t).<<call>>:0
TEST.VALUE:dk_srvc_uds_tp_doip.<<GLOBAL>>.(cl).dk::srvc::udscore::CUdsTpDoip.dk::srvc::udscore::CUdsTpDoip.mpUdsCoreTpIf:<<null>>
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpSA:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpTA:0
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpTAType:1
TEST.VALUE:dk_srvc_uds_tp_doip.(cl)dk::srvc::udscore::CUdsTpDoip::trasmitDataConfirmation.doIpResult:0
TEST.END

-- Unit: uds_core_component

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::onExit

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onExit.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onExit
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onExit.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsTpIfInst.dk::srvc::udscore::vcast_concrete_CUdsTpIf.<<constructor>>.vcast_concrete_CUdsTpIf().<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onExit.return:true
TEST.EXPECTED:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onExit.return:true
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onExit.002
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onExit
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onExit.002
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst:<<null>>
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsTpIfInst:<<null>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onExit.return:true
TEST.EXPECTED:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onExit.return:true
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::onInit

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onInit.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onInit
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onInit.001
TEST.STUB:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onInit.return:true
TEST.EXPECTED:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onInit.return:true
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onInit.002
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onInit
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onInit.002
TEST.STUB:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst:<<null>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onInit.return:true
TEST.EXPECTED:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onInit.return:true
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.result:21
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.002
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.002
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsTpIfInst.dk::srvc::udscore::vcast_concrete_CUdsTpIf.<<constructor>>.vcast_concrete_CUdsTpIf().<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.result:21
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsTpIfInst.dk::srvc::udscore::vcast_concrete_CUdsTpIf.<<constructor>>.vcast_concrete_CUdsTpIf().<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:"10"
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.result:21
TEST.ATTRIBUTES:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.sourceAddress:INPUT_BASE=16
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.002
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.002
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.sourceAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddress:11
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.targetAddressType:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.data:"10"
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataIndication.msg.result:21
TEST.ATTRIBUTES:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveDoipDiagDataConfirmation.msg.sourceAddress:INPUT_BASE=16
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.serviceId:34
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.responseType:4
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.clientAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.data:"10"
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.002
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.002
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.serviceId:34
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.responseType:4
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.clientAddress:16#6F#
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.dataLen:2
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.data:<<malloc 3>>
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceResponseTransmitRequest.msg.data:"10"
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.msg.p2TimeMs:50
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.msg.p2StarTimeMs:4000
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.msg.p4TimeMs:300000
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.002
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.002
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.msg.p2TimeMs:50
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.msg.p2StarTimeMs:4000
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onReceiveUdsServiceSetTimings.msg.p4TimeMs:300000
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::onStart

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onStart.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onStart
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onStart.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onStart.return:true
TEST.EXPECTED:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onStart.return:true
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::onStop

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::onStop.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::onStop
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::onStop.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onStop.return:true
TEST.EXPECTED:uds_core_component.(cl)dk::srvc::udscore::UdsCoreComponent::onStop.return:true
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler.001
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:100
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mUdsCoreParser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler.002
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler.002
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:false,true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:100
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mUdsCoreParser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler.003
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::udsCoreIniHandler.003
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getBoolValue.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getInt32Value.return:100
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst:<<null>>
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsTpIfInst:<<null>>
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mUdsCoreParser.dk::runtime::core::ParserIf.mIsConfigurationLoaded:false
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::udsPeriodicTask

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::udsPeriodicTask.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::udsPeriodicTask
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::udsPeriodicTask.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.END

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::udsPeriodicTask.002
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::udsPeriodicTask
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::udsPeriodicTask.002
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.mpUdsCoreInst.dk::srvc::udscore::CUdsCore.<<constructor>>.CUdsCore(const dk::srvc::udscore::CUdsCore::SUdsCoreConfig_t).<<call>>:0
TEST.END

-- Subprogram: (cl)dk::srvc::udscore::UdsCoreComponent::worker

-- Test Case: (cl)dk::srvc::udscore::UdsCoreComponent::worker.001
TEST.UNIT:uds_core_component
TEST.SUBPROGRAM:(cl)dk::srvc::udscore::UdsCoreComponent::worker
TEST.NEW
TEST.NAME:(cl)dk::srvc::udscore::UdsCoreComponent::worker.001
TEST.VALUE:uds_core_component.<<GLOBAL>>.(cl).dk::srvc::udscore::UdsCoreComponent.dk::srvc::udscore::UdsCoreComponent.<<constructor>>.UdsCoreComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*,const char*).<<call>>:0
TEST.END
