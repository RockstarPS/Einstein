-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OSAL_CONFIG_UT
-- Unit(s) Under Test: DKOsalConfig
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

-- Unit: DKOsalConfig

-- Subprogram: (cl)dk::osal::OsalConfig::OsalConfig

-- Test Case: Init
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::OsalConfig
TEST.NEW
TEST.NAME:Init
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::OsalConfig::getInstance

-- Test Case: Get_instance
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::getInstance
TEST.NEW
TEST.NAME:Get_instance
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getInstance.return.dk::osal::OsalConfig.<<constructor>>.OsalConfig().<<call>>:0
TEST.END

-- Subprogram: (cl)dk::osal::OsalConfig::getThreadConfig

-- Test Case: Config_table_no_needed_data
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::getThreadConfig
TEST.NEW
TEST.NAME:Config_table_no_needed_data
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTblSize:1
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.id:<<malloc 4>>
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.id:"1"
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.return:false
TEST.VALUE_USER_CODE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl
<<DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl>> = ( &dk::osal::s_DefaultConfig[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Id_null_error
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::getThreadConfig
TEST.NEW
TEST.NAME:Id_null_error
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.return:false
TEST.END

-- Test Case: Success_case_custom_values
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::getThreadConfig
TEST.NEW
TEST.NAME:Success_case_custom_values
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTblSize:1
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.id:<<malloc 1>>
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.id:""
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.return:true
TEST.VALUE_USER_CODE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl
dk::osal::OSAL_THREAD_CONFIG g_TempConfig [] = {
   {"", 0xFF, 0},
};
<<DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl>> = ( &dk::osal::s_DefaultConfig[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Success_case_default_values
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::getThreadConfig
TEST.NEW
TEST.NAME:Success_case_default_values
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTblSize:0
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.id:<<malloc 1>>
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.id:""
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.return:true
TEST.END

-- Test Case: Wrong_custom_table_size
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::getThreadConfig
TEST.NEW
TEST.NAME:Wrong_custom_table_size
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTblSize:0
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.id:<<malloc 1>>
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.id:""
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::getThreadConfig.return:true
TEST.VALUE_USER_CODE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl
<<DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl>> = ( &dk::osal::s_DefaultConfig[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::OsalConfig::isPrioReserved

-- Test Case: Default_priority_value
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::isPrioReserved
TEST.NEW
TEST.NAME:Default_priority_value
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.return:false
TEST.END

-- Test Case: Same_prio_value
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::isPrioReserved
TEST.NEW
TEST.NAME:Same_prio_value
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1:-1
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTblSize:1
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.return:false
TEST.VALUE_USER_CODE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl
dk::osal::OSAL_THREAD_CONFIG g_TempConfig [] = {
   {"", 0x1, 0},
};
<<DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl>> = ( &g_TempConfig[0] );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.prio
<<DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.prio>> = ( <<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Success_case
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::isPrioReserved
TEST.NEW
TEST.NAME:Success_case
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTblSize:1
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.prio:16#0#
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.return:true
TEST.VALUE_USER_CODE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl
dk::osal::OSAL_THREAD_CONFIG g_TempConfig [] = {
   {"", 0xFF, 0},
};
<<DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl>> = ( &g_TempConfig[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Wrong_prio_value
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::isPrioReserved
TEST.NEW
TEST.NAME:Wrong_prio_value
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTblSize:1
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.prio:16#2#
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.return:false
TEST.VALUE_USER_CODE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl
dk::osal::OSAL_THREAD_CONFIG g_TempConfig [] = {
   {"", 0x1, 0},
};
<<DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl>> = ( &g_TempConfig[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Wrong_prio_value.001
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::isPrioReserved
TEST.NEW
TEST.NAME:Wrong_prio_value.001
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTblSize:1
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.prio:16#2#
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::isPrioReserved.return:true
TEST.VALUE_USER_CODE:DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl
dk::osal::OSAL_THREAD_CONFIG g_TempConfig [] = {
   {"", 0x1, 0},
};
<<DKOsalConfig.<<GLOBAL>>.dk::osal::s_ThreadConfigTbl>> = ( &g_TempConfig[0] );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::osal::OsalConfig::setDefaultThreadConfigTable

-- Test Case: Configure_to_default
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::setDefaultThreadConfigTable
TEST.NEW
TEST.NAME:Configure_to_default
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.END

-- Subprogram: (cl)dk::osal::OsalConfig::setThreadConfigTable

-- Test Case: Config_table_failed_case
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::setThreadConfigTable
TEST.NEW
TEST.NAME:Config_table_failed_case
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::setThreadConfigTable.size:1
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::setThreadConfigTable.return:false
TEST.END

-- Test Case: Size_failed_case
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::setThreadConfigTable
TEST.NEW
TEST.NAME:Size_failed_case
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::setThreadConfigTable.size:0
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::setThreadConfigTable.return:false
TEST.END

-- Test Case: Success_case
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::setThreadConfigTable
TEST.NEW
TEST.NAME:Success_case
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::setThreadConfigTable.configTbl:<<malloc 1>>
TEST.VALUE:DKOsalConfig.(cl)dk::osal::OsalConfig::setThreadConfigTable.size:1
TEST.EXPECTED:DKOsalConfig.(cl)dk::osal::OsalConfig::setThreadConfigTable.return:true
TEST.END

-- Subprogram: (cl)dk::osal::OsalConfig::~OsalConfig

-- Test Case: DeInit
TEST.UNIT:DKOsalConfig
TEST.SUBPROGRAM:(cl)dk::osal::OsalConfig::~OsalConfig
TEST.NEW
TEST.NAME:DeInit
TEST.NOTES:
Requirement_AU29610-146973
TEST.END_NOTES:
TEST.VALUE:DKOsalConfig.<<GLOBAL>>.(cl).dk::osal::OsalConfig.dk::osal::OsalConfig.<<constructor>>.OsalConfig().<<call>>:0
TEST.END
