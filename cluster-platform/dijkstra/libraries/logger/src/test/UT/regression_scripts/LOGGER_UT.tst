-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : LOGGER_UT
-- Unit(s) Under Test: dk_logger_impl
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

-- Subprogram: (cl)dk::Logger::Logger

-- Test Case: Console_Pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:Console_Pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: Console_Pass.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:Console_Pass.001
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pAppId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pAppId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pDescription:<<malloc 11>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pDescription:"loggertest"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.debugEnabled:true
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.logDest:eLogDestination_File
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.silent:false
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.filename:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.filename:""
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.logOnlyError:true
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mSilent = true;
<<dk::Logger instance>>->mFilename.close();
<<dk::Logger instance>>->mlogDestination=dk::Logger::eLogDestination::eLogDestination_File;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mSilent = true;
{{ <<dk::Logger instance>> != NULL }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: Console_Pass.002
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:Console_Pass.002
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pAppId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pAppId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pDescription:<<malloc 11>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pDescription:"loggertest"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.debugEnabled:true
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.logDest:eLogDestination_Console
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.silent:true
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.filename:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.filename:""
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.logOnlyError:true
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mSilent = true;
<<dk::Logger instance>>->mFilename.close();
<<dk::Logger instance>>->mlogDestination=dk::Logger::eLogDestination::eLogDestination_Console;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mSilent = true;
{{ <<dk::Logger instance>> != NULL }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: Console_Pass.003
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:Console_Pass.003
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pAppId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pAppId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pDescription:<<malloc 11>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.pDescription:"loggertest"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.debugEnabled:false
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.logDest:eLogDestination_File
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.silent:false
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.filename:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.filename:""
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::Logger.logOnlyError:true
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_File, false, "", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mSilent = true;
<<dk::Logger instance>>->mFilename.close();
<<dk::Logger instance>>->mDebugEnabled=true,false;
<<dk::Logger instance>>->mlogDestination=dk::Logger::eLogDestination::eLogDestination_File;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mSilent = true;
{{ <<dk::Logger instance>> != NULL }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_Pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:DLT_Pass
TEST.END

-- Test Case: Slog2_Pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:Slog2_Pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: Slog2_register_failed
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:Slog2_register_failed
TEST.VALUE:uut_prototype_stubs.slog2_register.return:-1
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: Slog2_register_pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:Slog2_register_pass
TEST.VALUE:uut_prototype_stubs.slog2_register.return:1
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: mfile_open
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::Logger
TEST.NEW
TEST.NAME:mfile_open
TEST.VALUE:uut_prototype_stubs.slog2_register.return:-1
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_File, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append()

-- Test Case: append()
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append()
TEST.NEW
TEST.NAME:append()
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const bool)

-- Test Case: append(constbool).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const bool)
TEST.NEW
TEST.NAME:append(constbool).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constbool).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const bool)
TEST.NEW
TEST.NAME:append(constbool).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const int16_t)

-- Test Case: append(constint16_t).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const int16_t)
TEST.NEW
TEST.NAME:append(constint16_t).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constint16_t).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const int16_t)
TEST.NEW
TEST.NAME:append(constint16_t).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const int32_t)

-- Test Case: append(constint32_t).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const int32_t)
TEST.NEW
TEST.NAME:append(constint32_t).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constint32_t).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const int32_t)
TEST.NEW
TEST.NAME:append(constint32_t).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const int64_t)

-- Test Case: append(constint64_t).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const int64_t)
TEST.NEW
TEST.NAME:append(constint64_t).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constint64_t).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const int64_t)
TEST.NEW
TEST.NAME:append(constint64_t).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC"; 
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const int8_t)

-- Test Case: append(constint8_t).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const int8_t)
TEST.NEW
TEST.NAME:append(constint8_t).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constint8_t).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const int8_t)
TEST.NEW
TEST.NAME:append(constint8_t).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>   != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const std::__cxx11::string&)

-- Test Case: append_pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const std::__cxx11::string&)
TEST.NEW
TEST.NAME:append_pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const std::vector<unsigned char, std::allocator<unsigned char>>&)

-- Test Case: DLT_Pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const std::vector<unsigned char, std::allocator<unsigned char>>&)
TEST.NEW
TEST.NAME:DLT_Pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_Pass.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const std::vector<unsigned char, std::allocator<unsigned char>>&)
TEST.NEW
TEST.NAME:DLT_Pass.001
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::append(const std::vector<unsigned char, std::allocator<unsigned char>>&).data:<<malloc 3>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::append(const std::vector<unsigned char, std::allocator<unsigned char>>&).data[0]:<<function 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::append(const std::vector<unsigned char, std::allocator<unsigned char>>&).data[1]:<<function 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::append(const std::vector<unsigned char, std::allocator<unsigned char>>&).data[2]:<<function 1>>
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
std::vector<uint8_t> data;
data.push_back(244);

TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const std::vector<unsigned char, std::allocator<unsigned char>>&)
TEST.NEW
TEST.NAME:DLT_fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const uint16_t)

-- Test Case: append(constuint16_t).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const uint16_t)
TEST.NEW
TEST.NAME:append(constuint16_t).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constuint16_t).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const uint16_t)
TEST.NEW
TEST.NAME:append(constuint16_t).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const uint32_t)

-- Test Case: append(constuint32_t).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const uint32_t)
TEST.NEW
TEST.NAME:append(constuint32_t).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constuint32_t).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const uint32_t)
TEST.NEW
TEST.NAME:append(constuint32_t).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const uint64_t)

-- Test Case: append(constuint64_t).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const uint64_t)
TEST.NEW
TEST.NAME:append(constuint64_t).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constuint64_t).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const uint64_t)
TEST.NEW
TEST.NAME:append(constuint64_t).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::append(const uint8_t)

-- Test Case: append(constuint8_t).fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const uint8_t)
TEST.NEW
TEST.NAME:append(constuint8_t).fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: append(constuint8_t).pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::append(const uint8_t)
TEST.NEW
TEST.NAME:append(constuint8_t).pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::createInstance

-- Test Case: DLTwrapper_!=NULL
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::createInstance
TEST.NEW
TEST.NAME:DLTwrapper_!=NULL
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
<<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> = ( new Logger("logger test", "logger test") );
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_USER_CODE:dk_logger_impl.(cl)dk::Logger::createInstance.return
{{ <<dk_logger_impl.(cl)dk::Logger::createInstance.return>> != ( NULL ) }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Test Case: DLTwrapper_=_NULL
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::createInstance
TEST.NEW
TEST.NAME:DLTwrapper_=_NULL
TEST.VALUE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper:<<null>>
TEST.VALUE:dk_logger_impl.<<GLOBAL>>.(cl).dk::Logger:<<null>>
TEST.EXPECTED_USER_CODE:dk_logger_impl.(cl)dk::Logger::createInstance.return
{{ <<dk_logger_impl.(cl)dk::Logger::createInstance.return>> != (NULL) }}
TEST.END_EXPECTED_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::deInit

-- Test Case: deInit_Pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::deInit
TEST.NEW
TEST.NAME:deInit_Pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: deinit_Fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::deInit
TEST.NEW
TEST.NAME:deinit_Fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::getEnabled

-- Test Case: LogLevel_Disabled
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::getEnabled
TEST.NEW
TEST.NAME:LogLevel_Disabled
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description);
logger_ptr->getEnabled();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::getFileName

-- Test Case: getFileName.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::getFileName
TEST.NEW
TEST.NAME:getFileName.001
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance ("logger","TESTDESC", true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: getFileName.002
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::getFileName
TEST.NEW
TEST.NAME:getFileName.002
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getFileName.filePath:<<malloc 5>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getFileName.filePath:"/tmp"
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: getFileName.003
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::getFileName
TEST.NEW
TEST.NAME:getFileName.003
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getFileName.filePath:<<malloc 5>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getFileName.filePath:"/tmp"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getFileName.withExtension:false
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: getFileName.004
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::getFileName
TEST.NEW
TEST.NAME:getFileName.004
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getFileName.filePath:<<malloc 13>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getFileName.filePath:"tmp/file.txt"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getFileName.seperator:'/'
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "file.txt";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::getInstance

-- Test Case: getInstance.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::getInstance
TEST.NEW
TEST.NAME:getInstance.001
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
Logger *logger_ptr = dk::Logger::getInstance ();
logger_ptr = NULL;
logger_ptr = dk::Logger::getInstance ();

TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: getInstance.002
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::getInstance
TEST.NEW
TEST.NAME:getInstance.002
TEST.VALUE:uut_prototype_stubs.getenv.return:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.getenv.return[0]:'a'
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
Logger *logger_ptr = dk::Logger::getInstance ();
logger_ptr = NULL;
logger_ptr = dk::Logger::getInstance ();

TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::init

-- Test Case: DLT_Fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::init
TEST.NEW
TEST.NAME:DLT_Fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_Pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::init
TEST.NEW
TEST.NAME:DLT_Pass
TEST.VALUE:uut_prototype_stubs.dlt_user_is_logLevel_enabled.return:DLT_RETURN_TRUE
TEST.VALUE:uut_prototype_stubs.dlt_user_log_write_start.return:DLT_RETURN_ERROR
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: LogLevel_Disabled
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::init
TEST.NEW
TEST.NAME:LogLevel_Disabled
TEST.VALUE:uut_prototype_stubs.dlt_user_is_logLevel_enabled.return:DLT_RETURN_ERROR
TEST.VALUE:uut_prototype_stubs.dlt_user_log_write_start.return:DLT_RETURN_ERROR
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: pContext!=Null
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::init
TEST.NEW
TEST.NAME:pContext!=Null
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::init.pContext:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.dlt_user_is_logLevel_enabled.return:DLT_RETURN_TRUE
TEST.VALUE:uut_prototype_stubs.dlt_user_log_write_start.return:DLT_RETURN_ERROR
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: write_start_Pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::init
TEST.NEW
TEST.NAME:write_start_Pass
TEST.VALUE:uut_prototype_stubs.dlt_user_is_logLevel_enabled.return:DLT_RETURN_TRUE
TEST.VALUE:uut_prototype_stubs.dlt_user_log_write_start.return:DLT_RETURN_TRUE
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::initNoDlt

-- Test Case: initNoDlt.0001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0001
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
logger_ptr ->initNoDlt(DLT_LOG_WARN,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0002
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0002
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,NULL);
<<dk::Logger instance>>=(logger_ptr);
  
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0003
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0003
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
logger_ptr ->initNoDlt(DLT_LOG_FATAL,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0004
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0004
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char * filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
logger_ptr ->initNoDlt(DLT_LOG_ERROR,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0005
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0005
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
logger_ptr ->initNoDlt(DLT_LOG_INFO,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0006
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0006
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
logger_ptr ->initNoDlt(DLT_LOG_INFO,NULL);
<<dk::Logger instance>>=(logger_ptr);
  
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0007
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0007
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0008
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0008
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::initNoDlt.loglevel:DLT_LOG_VERBOSE
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,NULL);
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mLogOnlyError = false;
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
  
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0009
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0009
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
             char *l_description = "TESTDESC";
             char *filename = "testlogger.log";
             Logger *logger_ptr = NULL;
              DltContext ptr;
             //ptr.log_level_pos = 1;
             //ptr.log_level_user = 1;
             strcpy(ptr.contextID,"abc");
             logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
             dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
             logger_ptr ->initNoDlt(DLT_LOG_INFO,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0010
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0010
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_FATAL,&ptr);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0011
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0011
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_ERROR,&ptr);
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mLogOnlyError = false;
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0012
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0012
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_WARN,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0013
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0013
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_WARN,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0014
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0014
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
 char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_FATAL,NULL);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0015
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0015
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_INFO,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0017
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0017
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_OFF,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0018
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0018
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_INFO,NULL);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0019
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0019
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_ERROR,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0020
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0020
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
logger_ptr ->initNoDlt(DLT_LOG_WARN,NULL);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0021
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0021
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_WARN,NULL);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0022
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0022
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
 char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_WARN,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0023
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0023
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_INFO,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0024
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0024
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, true, filename, true);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);
             logger_ptr ->init(DLT_LOG_VERBOSE,NULL);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0025
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0025
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);
             logger_ptr ->init(DLT_LOG_VERBOSE,NULL);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0026
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0026
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_DEBUG,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0027
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0027
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,NULL);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0028
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0028
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_VERBOSE,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0029
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0029
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::initNoDlt.loglevel:DLT_LOG_VERBOSE
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_VERBOSE,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_VERBOSE,&ptr);
<<dk::Logger instance>> = logger_ptr;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_Console;
<<dk::Logger instance>>->mLogOnlyError = false;
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0030
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0030
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_VERBOSE,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0031
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0031
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
<<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
<<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
<<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
<<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
<<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
<<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
<<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
<<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
<<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);
logger_ptr ->init(DLT_LOG_VERBOSE,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0032
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0032
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_WARN,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0033
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0033
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, false);
logger_ptr ->initNoDlt(DLT_LOG_WARN,NULL);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0034
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0034
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
 logger_ptr ->initNoDlt(DLT_LOG_OFF,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0035
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0035
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Console, true, filename, true);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
<<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
<<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
<<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
<<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
<<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
<<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
<<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
<<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
<<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);
logger_ptr ->init(DLT_LOG_VERBOSE,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0036
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0036
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_DEBUG,&ptr);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0037
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0037
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
 char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_FATAL,&ptr);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0038
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0038
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
 char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,&ptr);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0039
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0039
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_INFO,&ptr);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0040
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0040
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_WARN,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0041
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0041
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_INFO,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0042
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0042
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::initNoDlt.loglevel:DLT_LOG_ERROR
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_OFF, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_ERROR,&ptr);
<<dk::Logger instance>>=(logger_ptr);
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination::eLogDestination_File;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_OFF));
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_OFF, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_ERROR,&ptr);
<<dk::Logger instance>>=(logger_ptr);
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination::eLogDestination_File;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_OFF));
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0043
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0043
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_ERROR,NULL);
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0044
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0044
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::initNoDlt.loglevel:DLT_LOG_VERBOSE
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,NULL);
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mLogOnlyError = true;
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
  
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0045
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0045
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::initNoDlt.loglevel:DLT_LOG_VERBOSE
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_VERBOSE,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_VERBOSE,&ptr);
<<dk::Logger instance>> = logger_ptr;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_Console;
<<dk::Logger instance>>->mLogOnlyError = true;
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0046
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0046
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::initNoDlt.loglevel:DLT_LOG_VERBOSE
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_INFO,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_INFO,&ptr);
             
<<dk::Logger instance>> = logger_ptr;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_File;
<<dk::Logger instance>>->mLogOnlyError = false;
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0047
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0047
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::initNoDlt.loglevel:DLT_LOG_VERBOSE
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_INFO,&ptr);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_INFO,&ptr);
             
<<dk::Logger instance>> = logger_ptr;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_File;
<<dk::Logger instance>>->mLogOnlyError = true;
<<dk::Logger instance>>->mNoDltContextData.logLevel = 7;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0048
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0048
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,NULL);
             <<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mLogOnlyError = true;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,NULL);
             
<<dk::Logger instance>>->mLogOnlyError = true;
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0049
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0049
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
 char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,&ptr);
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mLogOnlyError = true;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
 char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"NULL");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, true, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_OFF );
logger_ptr ->initNoDlt(DLT_LOG_DEFAULT,&ptr);
<<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mLogOnlyError = true;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: initNoDlt.0050
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::initNoDlt
TEST.NEW
TEST.NAME:initNoDlt.0050
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::initNoDlt.loglevel:DLT_LOG_DEBUG
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_OFF, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_ERROR,&ptr);
<<dk::Logger instance>>=(logger_ptr);
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_OFF));
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, filename, true);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_DEBUG, DLT_TRACE_STATUS_ON );
logger_ptr ->initNoDlt(DLT_LOG_DEBUG,&ptr);
<<dk::Logger instance>>=(logger_ptr);
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_DEBUG));
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::now

-- Test Case: Logger_now_pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::now
TEST.NEW
TEST.NAME:Logger_now_pass
TEST.VALUE:uut_prototype_stubs.localtime.VCAST_PARAM_1[0]:1
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
<<dk::Logger instance>> = logger_ptr;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Logger_now_pass.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::now
TEST.NEW
TEST.NAME:Logger_now_pass.001
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::now.return:<<malloc 4>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::now.return:"abc"
TEST.VALUE:uut_prototype_stubs.localtime.VCAST_PARAM_1[0]:1
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.localtime.return
struct tm timeinfo;
<<uut_prototype_stubs.localtime.return>>=&timeinfo;
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
<<dk::Logger instance>> = logger_ptr;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const)

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).001
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> = logger_ptr;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).003
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).003
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> = logger_ptr;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_DLT;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).004
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).004
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.contextID:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.contextID:"a"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.log_level_pos:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.log_level_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.trace_status_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.mcnt:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pContextId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pContextId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pDescription:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pDescription:"1"
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> = logger_ptr;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
//<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_VERBOSE));


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).005
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).005
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.contextID:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.contextID:"a"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.log_level_pos:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.log_level_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.trace_status_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.mcnt:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pContextId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pContextId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pDescription:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pDescription:"1"
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> = logger_ptr;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_Console;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
//<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_VERBOSE));


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).006
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const).006
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.contextID:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.contextID:"a"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.log_level_pos:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.log_level_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.trace_status_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).handle.mcnt:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pContextId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pContextId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pDescription:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const).pDescription:"1"
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> = logger_ptr;
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;

int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_Console;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
<<dk::Logger instance>>->mSilent = true;
//<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_VERBOSE));


TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType)

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const,constDltLogLevelType,constDltTraceStatusType).001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const,constDltLogLevelType,constDltTraceStatusType).001
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_DLT;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const,constDltLogLevelType,constDltTraceStatusType).002
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const,constDltLogLevelType,constDltTraceStatusType).002
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.contextID:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.contextID:"a"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_pos:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_ptr[0]:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.trace_status_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.trace_status_ptr[0]:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.mcnt:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pContextId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pContextId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pDescription:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pDescription:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).level:DLT_LOG_FATAL
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).status:DLT_TRACE_STATUS_ON
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
//<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_VERBOSE));


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const,constDltLogLevelType,constDltTraceStatusType).003
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const,constDltLogLevelType,constDltTraceStatusType).003
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.contextID:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.contextID:"a"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_pos:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_ptr[0]:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.trace_status_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.trace_status_ptr[0]:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.mcnt:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pContextId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pContextId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pDescription:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pDescription:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).level:DLT_LOG_FATAL
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).status:DLT_TRACE_STATUS_ON
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_Console;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
<<dk::Logger instance>>->mSilent = true;
//<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_VERBOSE));


TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: (cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const,constDltLogLevelType,constDltTraceStatusType).004
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType)
TEST.NEW
TEST.NAME:(cl)dk::Logger::registerContext(DltContext&,constchar*const,constchar*const,constDltLogLevelType,constDltTraceStatusType).004
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.contextID:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.contextID:"a"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_pos:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.log_level_ptr[0]:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.trace_status_ptr:<<malloc 1>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.trace_status_ptr[0]:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).handle.mcnt:1
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pContextId:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pContextId:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pDescription:<<malloc 2>>
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).pDescription:"1"
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).level:DLT_LOG_FATAL
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::registerContext(DltContext&,const char*const,const char*const,const DltLogLevelType,const DltTraceStatusType).status:DLT_TRACE_STATUS_ON
TEST.VALUE_USER_CODE:<<dk::Logger instance>>
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);

<<dk::Logger instance>> = logger_ptr;
int8_t log_ptr = 1;
int8_t trace_ptr = 1;
DltContext handle = {{'a'},1,&log_ptr,&trace_ptr,1};
std::string str= "abc";
const char * const pContextId = "ab";
<<dk::Logger instance>>->mDebugEnabled = true;
<<dk::Logger instance>>->mlogDestination = dk::Logger::eLogDestination_t::eLogDestination_Console;
<<dk::Logger instance>>->mMapContext.insert ( std::make_pair (&handle,std::string(pContextId)));
<<dk::Logger instance>>->mSilent = false;
//<<dk::Logger instance>>->mMapContextLevel.insert( std::make_pair (&handle,DltLogLevelType::DLT_LOG_VERBOSE));


TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::send

-- Test Case: (cl)dk::Logger::send.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:(cl)dk::Logger::send.001
TEST.VALUE:dk_logger_impl.<<GLOBAL>>.(cl).dk::Logger.dk::Logger.<<constructor>>.Logger(const char*const,const char*const,const bool,const dk::Logger::eLogDestination_t,const bool,const std::__cxx11::string,const bool).<<call>>:0
TEST.END

-- Test Case: DLT_LOG_DEBUG
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:DLT_LOG_DEBUG
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
 char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->init(DLT_LOG_DEBUG,&ptr);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
             
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_LOG_ERROR
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:DLT_LOG_ERROR
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
logger_ptr ->init(DLT_LOG_ERROR,NULL);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_LOG_FATAL
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:DLT_LOG_FATAL
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
logger_ptr ->init(DLT_LOG_FATAL,NULL);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>!= ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_LOG_INFO
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:DLT_LOG_INFO
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
 
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>!= ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_LOG_VERBOSE
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:DLT_LOG_VERBOSE
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->init(DLT_LOG_VERBOSE,&ptr);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);

TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_LOG_WARN
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:DLT_LOG_WARN
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
  
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: default
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:default
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
DltContext ptr;
strcpy(ptr.contextID,"abc");
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
dk_Logger_registerContext ( &ptr, l_appid, l_description, DLT_LOG_VERBOSE, DLT_TRACE_STATUS_ON );
logger_ptr ->init(DLT_LOG_OFF,&ptr);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
             
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: eLogDestination_Console
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:eLogDestination_Console
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: eLogDestination_Console.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:eLogDestination_Console.001
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mLogOn =false;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: eLogDestination_DLT
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:eLogDestination_DLT
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
           
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: eLogDestination_Slog2
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:eLogDestination_Slog2
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: eLogDestination_Slog2.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:eLogDestination_Slog2.001
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
<<dk::Logger instance>>->mLogOn = false;
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: mLogOn_True
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::send
TEST.NEW
TEST.NAME:mLogOn_True
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_File, false, "testlogger.log", false);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
            
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::unregisterContext

-- Test Case: DLT_Fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::unregisterContext
TEST.NEW
TEST.NAME:DLT_Fail
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
             <<dk::Logger instance>>=(logger_ptr);
             
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: DLT_Pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::unregisterContext
TEST.NEW
TEST.NAME:DLT_Pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description);
             <<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: (cl)dk::Logger::~Logger

-- Test Case: (cl)dk::Logger::~Logger.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::~Logger
TEST.NEW
TEST.NAME:(cl)dk::Logger::~Logger.001
TEST.END

-- Test Case: DebugEnabled
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::~Logger
TEST.NEW
TEST.NAME:DebugEnabled
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: Logger.Console
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::~Logger
TEST.NEW
TEST.NAME:Logger.Console
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Console, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: Logger.Dlt
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::~Logger
TEST.NEW
TEST.NAME:Logger.Dlt
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_DLT, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Logger.File
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::~Logger
TEST.NEW
TEST.NAME:Logger.File
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_File, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: Logger.Slog2
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:(cl)dk::Logger::~Logger
TEST.NEW
TEST.NAME:Logger.Slog2
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, "testlogger.log", false);
logger_ptr ->init(DLT_LOG_WARN,NULL);
logger_ptr->send();
<<dk::Logger instance>>=(logger_ptr);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: dk_Logger_createInstance

-- Test Case: pFile_!=_NULL
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:dk_Logger_createInstance
TEST.NEW
TEST.NAME:pFile_!=_NULL
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pName:<<malloc 9>>
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pName:"testName"
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pDesc:<<malloc 9>>
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pDesc:"testDesc"
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.bEnable:1
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.dest:eLogDestination_DLT
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.bSilent:1
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pFile:<<malloc 10>>
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pFile:"testPfile"
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.bOnlyError:1
TEST.EXPECTED:dk_logger_impl.dk_Logger_createInstance.bEnable:1
TEST.EXPECTED:dk_logger_impl.dk_Logger_createInstance.dest:eLogDestination_DLT
TEST.EXPECTED:dk_logger_impl.dk_Logger_createInstance.bSilent:1
TEST.EXPECTED:dk_logger_impl.dk_Logger_createInstance.bOnlyError:1
TEST.END

-- Test Case: pFile_==_NULL
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:dk_Logger_createInstance
TEST.NEW
TEST.NAME:pFile_==_NULL
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pName:<<malloc 9>>
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pName:"testName"
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pDesc:<<malloc 9>>
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.pDesc:"testDesc"
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.bEnable:1
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.dest:eLogDestination_DLT
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.bSilent:1
TEST.VALUE:dk_logger_impl.dk_Logger_createInstance.bOnlyError:1
TEST.EXPECTED:dk_logger_impl.dk_Logger_createInstance.bEnable:1
TEST.EXPECTED:dk_logger_impl.dk_Logger_createInstance.dest:eLogDestination_DLT
TEST.EXPECTED:dk_logger_impl.dk_Logger_createInstance.bSilent:1
TEST.EXPECTED:dk_logger_impl.dk_Logger_createInstance.bOnlyError:1
TEST.END

-- Subprogram: dk_Logger_log

-- Test Case: dk_Logger_log.fail
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:dk_Logger_log
TEST.NEW
TEST.NAME:dk_Logger_log.fail
TEST.STUB:dk_logger_impl.(cl)dk::Logger::init
TEST.STUB:dk_logger_impl.(cl)dk::Logger::getEnabled
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::init.return:false
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::getEnabled.return:true
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, true, filename, true);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
 char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_WARN);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: dk_Logger_log.fail.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:dk_Logger_log
TEST.NEW
TEST.NAME:dk_Logger_log.fail.001
TEST.STUB:dk_logger_impl.(cl)dk::Logger::init
TEST.VALUE:dk_logger_impl.(cl)dk::Logger::init.return:true
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, true, filename, true);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
 char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_WARN);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Test Case: dk_Logger_log.pass
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:dk_Logger_log
TEST.NEW
TEST.NAME:dk_Logger_log.pass
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, true, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
 char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: dk_Logger_registerContext

-- Test Case: dk_Logger_registerContext.002
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:dk_Logger_registerContext
TEST.NEW
TEST.NAME:dk_Logger_registerContext.002
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
char *pFileName = "log";     
char *pDelim1 = "test";
uint32_t lineNo = 10;            
char *pDelim2 = "test";
char *pFuncName ="test2";
char *pDelim3= "test4";
char *fmt = "%s";
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
             <<dk_logger_impl.dk_Logger_log.logLevel>>=(DLT_LOG_VERBOSE);
             <<dk_logger_impl.dk_Logger_log.pFileName>>=(pFileName);
             <<dk_logger_impl.dk_Logger_log.pDelim1>>=(pDelim1);
             <<dk_logger_impl.dk_Logger_log.lineNo>>=(lineNo);
             <<dk_logger_impl.dk_Logger_log.pDelim2>>=(pDelim2);
             <<dk_logger_impl.dk_Logger_log.pFuncName>>=(pFuncName);
             <<dk_logger_impl.dk_Logger_log.pDelim3>>=(pDelim3);
             <<dk_logger_impl.dk_Logger_log.fmt>>=(fmt);
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>> != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END

-- Subprogram: dk_Logger_unregisterContext

-- Test Case: dk_Logger_unregisterContext.001
TEST.UNIT:dk_logger_impl
TEST.SUBPROGRAM:dk_Logger_unregisterContext
TEST.NEW
TEST.NAME:dk_Logger_unregisterContext.001
TEST.VALUE_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
char *l_appid = "logger";
char *l_description = "TESTDESC";
char *filename = "testlogger.log";
Logger *logger_ptr = NULL;
logger_ptr = dk::Logger::createInstance (l_appid,l_description, false, dk::Logger::eLogDestination_t::eLogDestination_Slog2, false, filename, false);
DltContext *pHandle = {0};
             <<dk_logger_impl.dk_Logger_log.pHandle>>=(pHandle);
         
TEST.END_VALUE_USER_CODE:
TEST.EXPECTED_GLOBALS_USER_CODE:dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper
{{ <<dk_logger_impl.<<GLOBAL>>.dk::Logger::mpDLTWrapper>>  != ( NULL ) }}
TEST.END_EXPECTED_GLOBALS_USER_CODE:
TEST.END
