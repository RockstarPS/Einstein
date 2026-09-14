del commands.tmp
echo options C_ALT_COMPILE_CMD  >> commands.tmp
echo options C_ALT_EDG_FLAGS  >> commands.tmp
echo options C_ALT_PREPROCESS_CMD  >> commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW_C >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_63_C >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST  >> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 60300 >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_LINK_OPTIONS  >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options SOURCE_EXTENSION .c >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS asm s >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_COMPILER_SUPPORTS_CPP_CASTS FALSE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(5) >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo options VCAST_VCDB_FLAG_STRING -isystem=1 >> commands.tmp
echo options VCDB_FILENAME  >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\lib\public\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\lib\src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\stubs\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\stubs\include\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\stubs\include\sys\ >> commands.tmp
echo environment build UTP_SERILIZER_BSPAL.env >> commands.tmp
echo /E:UTP_SERILIZER_BSPAL tools script run UTP_SERILIZER_BSPAL.tst >> commands.tmp
echo /E:UTP_SERILIZER_BSPAL execute batch >> commands.tmp
echo /E:UTP_SERILIZER_BSPAL reports custom management UTP_SERILIZER_BSPAL_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
