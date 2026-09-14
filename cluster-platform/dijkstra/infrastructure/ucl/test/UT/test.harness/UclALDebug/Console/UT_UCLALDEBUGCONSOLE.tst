-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLALDEBUGCONSOLE
-- Unit(s) Under Test: UclALDebugConsole_Impl
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

-- Unit: UclALDebugConsole_Impl

-- Subprogram: UclALDebugConsole_Impl_IUclALDebug_Initialize

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Initialize.true
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Initialize.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Initialize.pInst[0].logLevel:eUclALDebugLevel_Debug
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Debug
TEST.END

-- Subprogram: UclALDebugConsole_Impl_IUclALDebug_Log

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_Warn_true
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_Warn_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst[0].logLevel:eUclALDebugLevel_Error
TEST.END

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_else_true
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_else_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst[0].logLevel:eUclALDebugLevel_Warn
TEST.END

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_false
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst[0].logLevel:eUclALDebugLevel_Info
TEST.END

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_false_Level
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_false_Level
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst[0].logLevel:eUclALDebugLevel_Debug
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Info
TEST.END

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_true
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Log.Debug_level_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst[0].logLevel:eUclALDebugLevel_Debug
TEST.END

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Log.Level_Warn_true
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Log.Level_Warn_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst[0].logLevel:eUclALDebugLevel_Warn
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Warn
TEST.END

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Log.Level_error_false
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Log.Level_error_false
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst[0].logLevel:eUclALDebugLevel_Last
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.END

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Log.Level_error_true
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Log.Level_error_true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.pInst[0].logLevel:eUclALDebugLevel_Error
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.END

-- Subprogram: UclALDebugConsole_Impl_IUclALDebug_SetLevel

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_SetLevel.true
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_SetLevel.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugConsole_Impl.UclALDebugConsole_Impl_IUclALDebug_SetLevel.pInst:<<malloc 1>>
TEST.END

-- Subprogram: UclALDebugConsole_Impl_IUclALDebug_Shutdown

-- Test Case: UclALDebugConsole_Impl_IUclALDebug_Shutdown.true
TEST.UNIT:UclALDebugConsole_Impl
TEST.SUBPROGRAM:UclALDebugConsole_Impl_IUclALDebug_Shutdown
TEST.NEW
TEST.NAME:UclALDebugConsole_Impl_IUclALDebug_Shutdown.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END
