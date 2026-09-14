del commands.tmp
echo options C_COMPILER_CFG_SOURCE CONFIG_FILE_63 >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING GNU Native_4.8_C >> commands.tmp
echo options C_COMPILER_TAG GNU_C_48 >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_COMPILE_CMD_FLAG -c >> commands.tmp
echo options C_COMPILE_EXCLUDE_FLAGS -o** >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST UTEST CHECKER VCAST ALTIA_INTERFACE QT_INTERFACE __interrupt= const= func= >> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 40800 >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options EXECUTABLE_EXTENSION  >> commands.tmp
echo options SBF_LOC_MEMBER_IN_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_MEMBER_OUTSIDE_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_NONMEMBER_IN_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_NONMEMBER_OUTSIDE_NSP DECL_NAMESPACE >> commands.tmp
echo options SUBSTITUTE_CODE_FOR_C_FILE FALSE >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS s >> commands.tmp
echo options VCAST_AUTO_CLEAR_TEST_USER_CODE FALSE >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_COMPILER_SUPPORTS_CPP_CASTS FALSE >> commands.tmp
echo options VCAST_COVERAGE_FOR_AGGREGATE_INIT TRUE >> commands.tmp
echo options VCAST_CUSTOM_REPORT_FORMAT HTML >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_FORCE_ELAB_TYPE_SPEC TRUE >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_INST_FILE_MAX_LINES 0 >> commands.tmp
echo options VCAST_MICROSOFT_LONG_LONG FALSE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE FALSE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS  >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(8) >> commands.tmp
echo options VCAST_TEST_ALL_NON_MEMBER_INLINES FALSE >> commands.tmp
echo options VCAST_TORNADO_CONSTRUCTOR_CALL_FILE FALSE >> commands.tmp
echo options VCAST_USE_STD_STRING TRUE >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\EcuWakeupM\src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\EcuWakeupM\include\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\EcuWakeupM\lib_src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\EcuWakeupM\lib_include\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\stubs\ >> commands.tmp
echo environment build ECUWAKEUPM_VCAST_HT.env >> commands.tmp
echo /E:ECUWAKEUPM_VCAST_HT tools script run ECUWAKEUPM_VCAST_HT.tst >> commands.tmp
echo /E:ECUWAKEUPM_VCAST_HT execute batch >> commands.tmp
echo /E:ECUWAKEUPM_VCAST_HT reports custom management ECUWAKEUPM_VCAST_HT_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
