-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLALDEBUGDLT
-- Unit(s) Under Test: UclALDebugDLT_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALDebugDLT_Impl

-- Subprogram: UclALDebugDLT_Impl_IUclALDebug_Initialize

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Initialize.DbgLvl_Debug
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Initialize.DbgLvl_Debug
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugCfg_0.logLevel:eUclALDebugLevel_Debug
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.InstId:DLT_LOG_OFF
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Initialize.DbgLvl_Error
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Initialize.DbgLvl_Error
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugCfg_0.logLevel:eUclALDebugLevel_Error
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.InstId:0
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Initialize.DbgLvl_Info
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Initialize.DbgLvl_Info
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugCfg_0.logLevel:eUclALDebugLevel_Info
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.InstId:0
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Initialize.DbgLvl_Warn
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Initialize.DbgLvl_Warn
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugCfg_0.logLevel:eUclALDebugLevel_Warn
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.InstId:0
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Initialize.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALDebugDLT_Impl_IUclALDebug_Log

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Log.DbgLvl_Debug
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Log.DbgLvl_Debug
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Debug
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Log.DbgLvl_Error
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Log.DbgLvl_Error
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Log.DbgLvl_Info
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Log.DbgLvl_Info
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Info
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Log.DbgLvl_Warn
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Log.DbgLvl_Warn
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Warn
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Log.MutexFailed
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Log.MutexFailed
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALDebugDLT_Impl.dlt_user_is_logLevel_enabled
TEST.VALUE:UclALDebugDLT_Impl.dlt_user_is_logLevel_enabled.return:DLT_RETURN_TRUE
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.VALUE:uut_prototype_stubs.dlt_user_log_write_start.return:DLT_RETURN_TRUE
TEST.VALUE:uut_prototype_stubs.UclALOs_MutexLock.return:UCL_E_NOK
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Log.logLvl_enabled_TRUE
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Log.logLvl_enabled_TRUE
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALDebugDLT_Impl.dlt_user_is_logLevel_enabled
TEST.VALUE:UclALDebugDLT_Impl.dlt_user_is_logLevel_enabled.return:DLT_RETURN_TRUE
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Log.log_write_TRUE
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Log.log_write_TRUE
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.STUB:UclALDebugDLT_Impl.dlt_user_is_logLevel_enabled
TEST.VALUE:UclALDebugDLT_Impl.dlt_user_is_logLevel_enabled.return:DLT_RETURN_TRUE
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.VALUE:uut_prototype_stubs.dlt_user_log_write_start.return:DLT_RETURN_TRUE
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Log.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALDebugDLT_Impl_IUclALDebug_SetLevel

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_SetLevel.DbgLvl_Debug
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_SetLevel.DbgLvl_Debug
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugCfg_0.logLevel:eUclALDebugLevel_Debug
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugInst_0.DltContext.log_level_ptr:<<malloc 1>>
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Debug
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_SetLevel.DbgLvl_Error
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_SetLevel.DbgLvl_Error
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugCfg_0.logLevel:eUclALDebugLevel_Debug
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugInst_0.DltContext.log_level_ptr:<<malloc 1>>
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Error
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_SetLevel.DbgLvl_Info
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_SetLevel.DbgLvl_Info
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugCfg_0.logLevel:eUclALDebugLevel_Debug
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugInst_0.DltContext.log_level_ptr:<<malloc 1>>
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Info
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_SetLevel.DbgLvl_Warn
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_SetLevel.DbgLvl_Warn
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugCfg_0.logLevel:eUclALDebugLevel_Debug
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugInst_0.DltContext.log_level_ptr:<<malloc 1>>
TEST.VALUE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Warn
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_SetLevel.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALDebugDLT_Impl_IUclALDebug_Shutdown

-- Test Case: UclALDebugDLT_Impl_IUclALDebug_Shutdown.001
TEST.UNIT:UclALDebugDLT_Impl
TEST.SUBPROGRAM:UclALDebugDLT_Impl_IUclALDebug_Shutdown
TEST.NEW
TEST.NAME:UclALDebugDLT_Impl_IUclALDebug_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugDLT_Impl.<<GLOBAL>>.UclALDebugInst_0.wrMutexId:1
TEST.VALUE_USER_CODE:UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Shutdown.pInst
<<UclALDebugDLT_Impl.UclALDebugDLT_Impl_IUclALDebug_Shutdown.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END
