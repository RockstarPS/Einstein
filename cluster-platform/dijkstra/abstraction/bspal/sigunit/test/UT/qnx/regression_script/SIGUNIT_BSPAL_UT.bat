del commands.tmp
echo options ASSEMBLER_CMD  >> commands.tmp
echo options C_ALT_COMPILE_CMD  >> commands.tmp
echo options C_ALT_EDG_FLAGS  >> commands.tmp
echo options C_ALT_PREPROCESS_CMD  >> commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_FAMILY_NAME  >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW_C >> commands.tmp
echo options C_COMPILER_PY_ARGS  >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_63_C >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST QNX_PLATFORM>> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 60300 >> commands.tmp
echo options C_EXECUTE_CMD  >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options SOURCE_EXTENSION .c >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS asm s >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_COMPILER_SUPPORTS_CPP_CASTS FALSE >> commands.tmp
echo options VCAST_DEPENDENCY_CACHE_DIR  >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_DISPLAY_UNINST_EXPR FALSE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_EXECUTE_WITH_STDOUT FALSE >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_NO_STDIN FALSE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_PREPROCESS_PREINCLUDE  >> commands.tmp
echo options VCAST_REPOSITORY  >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(4) >> commands.tmp
echo options VCAST_STDIO FALSE >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo options VCAST_USE_VCPP FALSE >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\lib\src >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\lib\public\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\stubs\include\ >> commands.tmp
echo environment build SIGUNIT_BSPAL_UT.env >> commands.tmp
echo /E:SIGUNIT_BSPAL_UT tools script run SIGUNIT_BSPAL_UT.tst >> commands.tmp
echo /E:SIGUNIT_BSPAL_UT execute batch >> commands.tmp
echo /E:SIGUNIT_BSPAL_UT reports custom management SIGUNIT_BSPAL_UT_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
