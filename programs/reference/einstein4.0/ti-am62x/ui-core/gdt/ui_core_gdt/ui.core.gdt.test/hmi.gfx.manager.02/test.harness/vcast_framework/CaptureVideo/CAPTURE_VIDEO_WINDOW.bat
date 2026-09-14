del commands.tmp
echo options ASM_FUNCS_BEHAVE_AS_INLINES FALSE >> commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_FAMILY_NAME  >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW_C >> commands.tmp
echo options C_COMPILER_PY_ARGS  >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_45_C >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_COMPILE_CMD_FLAG -c >> commands.tmp
echo options C_COMPILE_EXCLUDE_FLAGS -o** >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST  >> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 40500 >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_OUTPUT_FLAG -o >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options EXECUTABLE_EXTENSION  >> commands.tmp
echo options GLOBALS_DISPLAY GDD_RANGE_ITERATION >> commands.tmp
echo options SBF_LOC_MEMBER_IN_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_MEMBER_OUTSIDE_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_NONMEMBER_IN_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_NONMEMBER_OUTSIDE_NSP DECL_NAMESPACE >> commands.tmp
echo options STANDARD_OUTPUT REDIRECT >> commands.tmp
echo options SUBSTITUTE_CODE_FOR_C_FILE FALSE >> commands.tmp
echo options TARGET_VARIANT HOST >> commands.tmp
echo options TI_CC_TCF_FILENAME  >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS s >> commands.tmp
echo options VCAST_AUTO_CLEAR_TEST_USER_CODE FALSE >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_COMPILER_SUPPORTS_CPP_CASTS FALSE >> commands.tmp
echo options VCAST_COMPILER_TEMPLATE_SECTION TRUE >> commands.tmp
echo options VCAST_COVERAGE_FOR_AGGREGATE_INIT TRUE >> commands.tmp
echo options VCAST_DISABLE_CPP_EXCEPTIONS FALSE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_EMPTY_TESTCASE_FAIL TRUE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_FILE_VERSION_COMMAND  >> commands.tmp
echo options VCAST_FORCE_ELAB_TYPE_SPEC TRUE >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_INST_FILE_MAX_LINES 0 >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_NO_STDIN FALSE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_PREPROCESS_PREINCLUDE  >> commands.tmp
echo options VCAST_REMOVE_PREPROCESSOR_COMMENTS TRUE >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(10) >> commands.tmp
echo options VCAST_RPTS_SHOW_VERSION TRUE >> commands.tmp
echo options VCAST_STDIO FALSE >> commands.tmp
echo options VCAST_TESTCASE_FAIL_ON_NO_EXPECTED TRUE >> commands.tmp
echo options VCAST_TEST_ALL_NON_MEMBER_INLINES FALSE >> commands.tmp
echo options VCAST_TORNADO_CONSTRUCTOR_CALL_FILE FALSE >> commands.tmp
echo options VCAST_UNCOVERED_LINE_INDICATOR '#' >> commands.tmp
echo options VCAST_UNIT_TYPE UUT >> commands.tmp
echo options VCAST_USE_RELATIVE_PATHS TRUE >> commands.tmp
echo options VCAST_USE_VCPP FALSE >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\ADEVI\RTC_NEW_WORKSPACE\UI_CORE_GDT\ui.core.gdt\hmi.gfx.manager.02\src\ >> commands.tmp
echo environment build CAPTURE_VIDEO_WINDOW.env >> commands.tmp
echo /E:CAPTURE_VIDEO_WINDOW tools script run CAPTURE_VIDEO_WINDOW.tst >> commands.tmp
echo /E:CAPTURE_VIDEO_WINDOW execute batch >> commands.tmp
echo /E:CAPTURE_VIDEO_WINDOW reports custom management CAPTURE_VIDEO_WINDOW_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
