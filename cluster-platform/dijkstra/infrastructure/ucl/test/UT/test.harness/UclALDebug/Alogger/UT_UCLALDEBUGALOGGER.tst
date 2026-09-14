-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_UCLALDEBUGALOGGER
-- Unit(s) Under Test: UclALDebugAlogger_Impl
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

-- Unit: UclALDebugAlogger_Impl

-- Subprogram: UclALDebugAlogger_Impl_IUclALDebug_Initialize

-- Test Case: UclALDebugAlogger_Impl_IUclALDebug_Initialize.001
TEST.UNIT:UclALDebugAlogger_Impl
TEST.SUBPROGRAM:UclALDebugAlogger_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugAlogger_Impl_IUclALDebug_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.END

-- Subprogram: UclALDebugAlogger_Impl_IUclALDebug_Log

-- Test Case: UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_Debug
TEST.UNIT:UclALDebugAlogger_Impl
TEST.SUBPROGRAM:UclALDebugAlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_Debug
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Debug
TEST.END

-- Test Case: UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_default
TEST.UNIT:UclALDebugAlogger_Impl
TEST.SUBPROGRAM:UclALDebugAlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_default
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Last
TEST.END

-- Test Case: UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_error
TEST.UNIT:UclALDebugAlogger_Impl
TEST.SUBPROGRAM:UclALDebugAlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_error
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.END

-- Test Case: UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_info
TEST.UNIT:UclALDebugAlogger_Impl
TEST.SUBPROGRAM:UclALDebugAlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_info
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Info
TEST.END

-- Test Case: UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_warn
TEST.UNIT:UclALDebugAlogger_Impl
TEST.SUBPROGRAM:UclALDebugAlogger_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugAlogger_Impl_IUclALDebug_Log.DebugLevel_warn
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Warn
TEST.END

-- Subprogram: UclALDebugAlogger_Impl_IUclALDebug_SetLevel

-- Test Case: UclALDebugAlogger_Impl_IUclALDebug_SetLevel.true
TEST.UNIT:UclALDebugAlogger_Impl
TEST.SUBPROGRAM:UclALDebugAlogger_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugAlogger_Impl_IUclALDebug_SetLevel.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugAlogger_Impl.UclALDebugAlogger_Impl_IUclALDebug_SetLevel.pInst:<<malloc 1>>
TEST.END

-- Subprogram: UclALDebugAlogger_Impl_IUclALDebug_Shutdown

-- Test Case: UclALDebugAlogger_Impl_IUclALDebug_Shutdown.true
TEST.UNIT:UclALDebugAlogger_Impl
TEST.SUBPROGRAM:UclALDebugAlogger_Impl_IUclALDebug_Shutdown
TEST.NEW
TEST.NAME:UclALDebugAlogger_Impl_IUclALDebug_Shutdown.true
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.END
