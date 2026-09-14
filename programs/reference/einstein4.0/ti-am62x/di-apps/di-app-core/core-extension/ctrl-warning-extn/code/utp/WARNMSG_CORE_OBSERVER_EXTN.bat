del commands.tmp
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
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS asm s >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_COVERAGE_SOURCE_FILE_PERSPECTIVE FALSE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_DISPLAY_UNINST_EXPR FALSE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(5) >> commands.tmp
echo options VCAST_TEST_VALUES_DICTIONARY  >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo options VCAST_USE_DIR_LIST_FOR_INCLUDES TRUE >> commands.tmp
echo options VCDB_CMD_VERB  >> commands.tmp
echo options VCDB_FILENAME  >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Work\Tasks\X-Carline\Vectorcast_Workspace\cluster-platform\turing\lib\memlib\src\src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Work\Tasks\X-Carline\Vectorcast_Workspace\programs\toyota\my2026\7xxd\bsw-gen\Appl\GenData\Components\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Work\Tasks\X-Carline\Vectorcast_Workspace\programs\toyota\my2026\7xxd\bsw-gen\Appl\GenData\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Work\Tasks\X-Carline\Vectorcast_Workspace\programs\toyota\my2026\7xxd\vp-build\stubs\include\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Work\Tasks\X-Carline\Vectorcast_Workspace\programs\toyota\my2026\7xxd\vp-build\Tools\MOT_Generator\inc\Dummy_includes\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Work\Tasks\X-Carline\Vectorcast_Workspace\programs\toyota\my2026\7xxd\vp-build\stubs\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Work\Tasks\X-Carline\Vectorcast_Workspace\apps\toyota\di-apps\a-telltale\Mdl_CSeat_Belt\Mdl_SeatBelt_Config\CodeGen\ >> commands.tmp
echo environment build WARNMSG_CORE_OBSERVER_EXTN.env >> commands.tmp
echo /E:WARNMSG_CORE_OBSERVER_EXTN tools script run WARNMSG_CORE_OBSERVER_EXTN.tst >> commands.tmp
echo /E:WARNMSG_CORE_OBSERVER_EXTN execute batch >> commands.tmp
echo /E:WARNMSG_CORE_OBSERVER_EXTN reports custom management WARNMSG_CORE_OBSERVER_EXTN_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp true
