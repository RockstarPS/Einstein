del commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW (C) >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_63_C >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST SOC_AM62PX SOC_AM62P >> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 60300 >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS asm s >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_DISPLAY_UNINST_EXPR FALSE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(7) >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo options VCAST_VCDB_FLAG_STRING -isystem=1 >> commands.tmp
echo options VCDB_FILENAME  >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\ui.core.gdt\hmi.gfx.manager.02\src\ >> commands.tmp
echo environment build SWLIB_TIDSS_UT_ENV.env >> commands.tmp
echo /E:SWLIB_TIDSS_UT_ENV tools script run SWLIB_TIDSS_UT_ENV.tst >> commands.tmp
echo /E:SWLIB_TIDSS_UT_ENV execute batch >> commands.tmp
echo /E:SWLIB_TIDSS_UT_ENV reports custom management SWLIB_TIDSS_UT_ENV_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
