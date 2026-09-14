del commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW_C >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_63_C >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST MK_HWWORDLENGTH=32 MK_HWMAXCORES=1 OS_TOOL_INLINE_KEYWORD= mk_hwexceptioninfo_t= UPDd_MAX_SLOT=2 UPDd_MAX_PACKAGE_NAME_SIZE=64 UPDd_LOAD_BUFFER_SIZE=256 UPDd_REQ_FIFO_SIZE=8 UPDd_COMPOSE_BUFFER_SIZE=1 UPDd_HASH_BUFFER_SIZE=32 E_PENDING=0x02 UPDd_HOLD_TIMEOUT_MS=60000 UPDd_TASK_PERIOD_MS=100 false=0 true=1 UPDd_MAX_HASHING_CYCLE=5 UPDd_MAX_ERASE_CYCLE=2 VCAST_UT=1 >> commands.tmp
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
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(3) >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\src >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\..\..\cfg >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\stubs >> commands.tmp
echo environment build UPDI_TARGET.env >> commands.tmp
echo /E:UPDI_TARGET tools script run UPDI_TARGET.tst >> commands.tmp
echo /E:UPDI_TARGET execute batch >> commands.tmp
echo /E:UPDI_TARGET reports custom management UPDI_TARGET_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
