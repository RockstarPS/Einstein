del commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW_C >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_63_C >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST VCAST_MAX_HEAP_SIZE=500000 TS_ARCH_FAMILY=TS_S6J3 TS_ARCH_DERIVATE=TS_S6J3200 TS_ARCH_SUBDERIVATE=TS_S6J324CLS DEBUG_ASSERT_ON >> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 60300 >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS asm s >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_DEPENDENCY_CACHE_DIR  >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_REPOSITORY C:\\workspace\\functional_safety\\sigunit_driver_tv2\\ui.core.infineon.traveo2.sig.unit.driver.test\\test_harness\\UT >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(4) >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\workspace\functional_safety\sigunit_driver_tv2\ui.core.infineon.traveo2.sig.unit.driver\src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\workspace\functional_safety\sigunit_driver_tv2\ui.core.infineon.traveo2.sig.unit.driver.test\test_harness\UT\Stubs\ >> commands.tmp
echo environment build SIG_DRV_TV2_VCAST_HT.env >> commands.tmp
echo /E:SIG_DRV_TV2_VCAST_HT  tools update mcdc >> commands.tmp
echo /E:SIG_DRV_TV2_VCAST_HT tools script run SIG_DRV_TV2_VCAST_HT.tst >> commands.tmp
echo /E:SIG_DRV_TV2_VCAST_HT execute batch >> commands.tmp
echo /E:SIG_DRV_TV2_VCAST_HT reports custom management SIG_DRV_TV2_VCAST_HT_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
