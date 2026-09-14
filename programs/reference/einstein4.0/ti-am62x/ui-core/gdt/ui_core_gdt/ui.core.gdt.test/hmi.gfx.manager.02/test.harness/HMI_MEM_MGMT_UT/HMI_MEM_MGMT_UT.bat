del commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW (C) >> commands.tmp
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
echo options TESTABLE_SOURCE_DIR ..\..\..\..\ui.core.gdt\hmi.gfx.manager.02\hmi_memory_manager\ >> commands.tmp
echo environment build HMI_MEM_MGMT_UT.env >> commands.tmp
echo /E:HMI_MEM_MGMT_UT tools script run HMI_MEM_MGMT_UT.tst >> commands.tmp
echo /E:HMI_MEM_MGMT_UT execute batch >> commands.tmp
echo /E:HMI_MEM_MGMT_UT reports custom management HMI_MEM_MGMT_UT_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
