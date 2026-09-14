del commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW_C >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_63_C >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST const= >> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 60300 >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS asm s >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(5) >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\..\src\src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\dcc\v0\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\dcc\v0\soc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\dcc\v0\soc\am62px\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\dpl\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\ecc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\ecc\V0\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\ecc\soc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\ecc\soc\am62px\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\esm\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\esm\soc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\esm\soc\am62px\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\esm\v0\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\esm\v0\v0_0\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\include\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\include\am62px\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\pok\v1\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\pok\v1\soc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\pok\v1\soc\am62px\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\r5\v0\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\rti\v0\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\rti\v0\soc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR ..\test.harness\stubs\sdl\rti\v0\soc\am62px\ >> commands.tmp
echo environment build SAFENVM_VCAST_UT.env >> commands.tmp
echo /E:SAFENVM_VCAST_UT tools script run SAFENVM_VCAST_UT.tst >> commands.tmp
echo /E:SAFENVM_VCAST_UT execute batch >> commands.tmp
echo /E:SAFENVM_VCAST_UT reports custom management SafeNvM_TestCaseManagementReport.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
