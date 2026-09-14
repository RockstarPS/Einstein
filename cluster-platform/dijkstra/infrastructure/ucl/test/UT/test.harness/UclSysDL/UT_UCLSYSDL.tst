-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLSYSDL
-- Unit(s) Under Test: UclSysDL_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclSysDL_Impl

-- Subprogram: UclSysDL_Impl_IUclDLCbk_FatalError

-- Test Case: UclSysDL_Impl_IUclDLCbk_FatalError
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclDLCbk_FatalError
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclDLCbk_FatalError
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.<<GLOBAL>>.UclSysCfg_0.pFatalErrorFunc:App_UclFatalError
TEST.VALUE_USER_CODE:UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0.pCfg
<<UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0>>.pCfg = ( &UclSysCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_FatalError.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_FatalError.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSysDL_Impl_IUclDLCbk_FatalError.callback_null
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclDLCbk_FatalError
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclDLCbk_FatalError.callback_null
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.<<GLOBAL>>.UclSysCfg_0.pFatalErrorFunc:<<null>>
TEST.VALUE_USER_CODE:UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0.pCfg
<<UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0>>.pCfg = ( &UclSysCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_FatalError.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_FatalError.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSysDL_Impl_IUclDLCbk_LinkStatusChanged

-- Test Case: UclSysDL_Impl_IUclDLCbk_LinkStatusChanged.callback_null
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclDLCbk_LinkStatusChanged.callback_null
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.<<GLOBAL>>.UclSysCfg_0.pLinkStatusChangedFunc:<<null>>
TEST.VALUE_USER_CODE:UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0.pCfg
<<UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0>>.pCfg = ( &UclSysCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSysDL_Impl_IUclDLCbk_LinkStatusChanged.true
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclDLCbk_LinkStatusChanged
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclDLCbk_LinkStatusChanged.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.<<GLOBAL>>.UclSysCfg_0.pLinkStatusChangedFunc:App_UclLinkStatusChangedFunc
TEST.VALUE_USER_CODE:UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0.pCfg
<<UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0>>.pCfg = ( &UclSysCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_LinkStatusChanged.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_LinkStatusChanged.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSysDL_Impl_IUclDLCbk_MsgReceived

-- Test Case: UclSysDL_Impl_IUclDLCbk_MsgReceived.callback_null
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclDLCbk_MsgReceived.callback_null
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.<<GLOBAL>>.UclSysCfg_0.pMsgReceivedFunc:<<null>>
TEST.VALUE_USER_CODE:UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0.pCfg
<<UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0>>.pCfg = ( &UclSysCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_MsgReceived.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSysDL_Impl_IUclDLCbk_MsgReceived.true
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclDLCbk_MsgReceived
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclDLCbk_MsgReceived.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.<<GLOBAL>>.UclSysCfg_0.pMsgReceivedFunc:App_UclMsgReceivedFunc
TEST.VALUE_USER_CODE:UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0.pCfg
<<UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0>>.pCfg = ( &UclSysCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_MsgReceived.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_MsgReceived.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus

-- Test Case: UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus.callback_null
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus.callback_null
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.<<GLOBAL>>.UclSysCfg_0.pMsgTransmitStatusFunc:<<null>>
TEST.VALUE_USER_CODE:UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0.pCfg
<<UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0>>.pCfg = ( &UclSysCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus.true
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.<<GLOBAL>>.UclSysCfg_0.pMsgTransmitStatusFunc:App_UclMsgTransmitStatusFunc
TEST.VALUE_USER_CODE:UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0.pCfg
<<UclSysDL_Impl.<<GLOBAL>>.UclSysInst_0>>.pCfg = ( &UclSysCfg_0 );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclDLCbk_MsgTransmitStatus.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSysDL_Impl_IUclSys_Initialize

-- Test Case: UclSysDL_Impl_IUclSys_Initialize.DLInit_fail_UCL_E_NOK
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclSys_Initialize
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclSys_Initialize.DLInit_fail_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclALOs_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSysDL_Impl_IUclSys_Initialize.OsInit_fail_UCL_E_NOK
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclSys_Initialize
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclSys_Initialize.OsInit_fail_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_Initialize.return:UCL_E_NOK
TEST.EXPECTED:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSysDL_Impl_IUclSys_Initialize.initialize_UCL_E_OK
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclSys_Initialize
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclSys_Initialize.initialize_UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Initialize.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclALOs_Initialize.return:UCL_E_OK
TEST.EXPECTED:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclSys_Initialize.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSysDL_Impl_IUclSys_Send

-- Test Case: UclSysDL_Impl_IUclSys_Send.return_UCL_E_NOK
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclSys_Send
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclSys_Send.return_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Send.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclDL_Send.return:UCL_E_NOK
TEST.EXPECTED:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Send.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Send.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclSys_Send.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSysDL_Impl_IUclSys_Send.return_UCL_E_OK
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclSys_Send
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclSys_Send.return_UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Send.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Send.return:UCL_E_OK
TEST.EXPECTED:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Send.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Send.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclSys_Send.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSysDL_Impl_IUclSys_Shutdown

-- Test Case: UclSysDL_Impl_IUclSys_Shutdown.shutdown_UCL_E_NOK
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclSys_Shutdown
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclSys_Shutdown.shutdown_UCL_E_NOK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE:uut_prototype_stubs.UclDL_Shutdown.return:UCL_E_NOK
TEST.EXPECTED:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Shutdown.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Shutdown.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclSys_Shutdown.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclSysDL_Impl_IUclSys_Shutdown.shutdown_UCL_E_OK
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclSys_Shutdown
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclSys_Shutdown.shutdown_UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Shutdown.return:UCL_E_OK
TEST.VALUE:uut_prototype_stubs.UclDL_Shutdown.return:UCL_E_OK
TEST.EXPECTED:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Shutdown.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Shutdown.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclSys_Shutdown.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclSysDL_Impl_IUclSys_Task

-- Test Case: UclSysDL_Impl_IUclSys_Task.return_UCL_E_OK
TEST.UNIT:UclSysDL_Impl
TEST.SUBPROGRAM:UclSysDL_Impl_IUclSys_Task
TEST.NEW
TEST.NAME:UclSysDL_Impl_IUclSys_Task.return_UCL_E_OK
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Task.return:UCL_E_OK
TEST.VALUE_USER_CODE:UclSysDL_Impl.UclSysDL_Impl_IUclSys_Task.pInst
<<UclSysDL_Impl.UclSysDL_Impl_IUclSys_Task.pInst>> = ( &UclSysInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
