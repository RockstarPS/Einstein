del commands.tmp
echo options C_ALT_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_ALT_EDG_FLAGS -w --gcc --gnu_version 60300 >> commands.tmp
echo options C_ALT_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW_C++ >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_63_CPP >> commands.tmp
echo options C_COMPILER_VERSION_CMD g++ --version >> commands.tmp
echo options C_COMPILE_CMD g++ -c -g >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST VCAST_NO_PTR_TO_UNCON_ARRAY_SUPPORT >> commands.tmp
echo options C_EDG_FLAGS -w --g++ --gnu_version 60300 --type_info_in_std --type_traits_helpers >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD g++ -g >> commands.tmp
echo options C_PREPROCESS_CMD g++ -E -C >> commands.tmp
echo options SOURCE_EXTENSION .cpp >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS asm s >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_COMPILER_SUPPORTS_CPP_CASTS TRUE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(5) >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\stubs\ >> commands.tmp
echo environment build DOIP_UT.env >> commands.tmp
echo /E:DOIP_UT tools script run DOIP_UT.tst >> commands.tmp
echo /E:DOIP_UT execute batch >> commands.tmp
echo /E:DOIP_UT reports custom management DOIP_UT_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:CPLUSPLUS tools execute commands.tmp false
