-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLALDEBUGSLOGGER
-- Unit(s) Under Test: UclALDebugSlogger_Impl
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

-- Unit: UclALDebugSlogger_Impl

-- Subprogram: UclALDebugSlogger_Impl_IUclALDebug_Initialize

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Initialize.debug_level_default
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Initialize.debug_level_default
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Last
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Initialize.debug_level_error
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Initialize.debug_level_error
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Error
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Initialize.debug_level_info
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Initialize.debug_level_info
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Info
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Initialize.debug_level_warn
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Initialize.debug_level_warn
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Warn
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Initialize.slog2regester_true
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Initialize.slog2regester_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:uut_prototype_stubs.slog2_register.return:-1
TEST.VALUE_USER_CODE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst
<<UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Initialize.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: UclALDebugSlogger_Impl_IUclALDebug_Log

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Log.Debug_level_default
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Log.Debug_level_default
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Last
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Log.Debug_level_error
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Log.Debug_level_error
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Log.Debug_level_info
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Log.Debug_level_info
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Info
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Log.Debug_level_warn
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Log.Debug_level_warn
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Warn
TEST.END

-- Subprogram: UclALDebugSlogger_Impl_IUclALDebug_SetLevel

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_SetLevel.DebugLevel_Error
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_SetLevel.DebugLevel_Error
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Error
TEST.VALUE_USER_CODE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.pInst
<<UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_SetLevel.DebugLevel_info
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_SetLevel.DebugLevel_info
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Info
TEST.VALUE_USER_CODE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.pInst
<<UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_SetLevel.DebugLevel_warn
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_SetLevel.DebugLevel_warn
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Warn
TEST.VALUE_USER_CODE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.pInst
<<UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.pInst>> = ( &UclALDebugInst_0 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_SetLevel.default_case
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_SetLevel.default_case
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSlogger_Impl.UclALDebugSlogger_Impl_IUclALDebug_SetLevel.pInst[0].logLevel:eUclALDebugLevel_Warn
TEST.END

-- Subprogram: UclALDebugSlogger_Impl_IUclALDebug_Shutdown

-- Test Case: UclALDebugSlogger_Impl_IUclALDebug_Shutdown.true
TEST.UNIT:UclALDebugSlogger_Impl
TEST.SUBPROGRAM:UclALDebugSlogger_Impl_IUclALDebug_Shutdown
TEST.NEW
TEST.NAME:UclALDebugSlogger_Impl_IUclALDebug_Shutdown.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END
