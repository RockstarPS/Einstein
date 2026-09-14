-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : UT_SYSLOG
-- Unit(s) Under Test: UclALDebugSyslog_Impl
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: UclALDebugSyslog_Impl

-- Subprogram: UclALDebugSyslog_Impl_IUclALDebug_Initialize

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Initialize.001
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Initialize.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Debug
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Debug
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Initialize.002
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Initialize.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Info
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Info
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Initialize.003
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Initialize.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Warn
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Warn
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Initialize.004
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Initialize
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Initialize.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Error
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Initialize.pInst[0].pCfg[0].logLevel:eUclALDebugLevel_Error
TEST.END

-- Subprogram: UclALDebugSyslog_Impl_IUclALDebug_Log

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Log.001
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Log.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Debug
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Debug
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Log.002
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Log.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Info
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Info
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Log.003
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Log.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Warn
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Warn
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Log.004
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Log
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Log.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Log.Level:eUclALDebugLevel_Error
TEST.END

-- Subprogram: UclALDebugSyslog_Impl_IUclALDebug_SetLevel

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_SetLevel.001
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_SetLevel.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Info
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Info
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_SetLevel.002
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_SetLevel.002
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Warn
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Warn
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_SetLevel.003
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_SetLevel.003
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Error
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Error
TEST.END

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_SetLevel.004
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_SetLevel
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_SetLevel.004
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.pInst:<<malloc 1>>
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Last
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_SetLevel.Level:eUclALDebugLevel_Last
TEST.END

-- Subprogram: UclALDebugSyslog_Impl_IUclALDebug_Shutdown

-- Test Case: UclALDebugSyslog_Impl_IUclALDebug_Shutdown.001
TEST.UNIT:UclALDebugSyslog_Impl
TEST.SUBPROGRAM:UclALDebugSyslog_Impl_IUclALDebug_Shutdown
TEST.NEW
TEST.NAME:UclALDebugSyslog_Impl_IUclALDebug_Shutdown.001
TEST.NOTES:
Detailed_Design in GIP_Infra::ucl 
Ucl in GIP_INFRA::Library::ucl
TEST.END_NOTES:
TEST.VALUE:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Shutdown.pInst:<<null>>
TEST.EXPECTED:UclALDebugSyslog_Impl.UclALDebugSyslog_Impl_IUclALDebug_Shutdown.pInst:<<null>>
TEST.END
