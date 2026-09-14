del commands.tmp
echo options ASM_FUNCS_BEHAVE_AS_INLINES FALSE >> commands.tmp
echo options C_COMPILER_CFG_SOURCE BUILT_IN_TAG >> commands.tmp
echo options C_COMPILER_FAMILY_NAME  >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING VectorCAST MinGW_C >> commands.tmp
echo options C_COMPILER_PY_ARGS  >> commands.tmp
echo options C_COMPILER_TAG BUILTIN_MINGW_63_C >> commands.tmp
echo options C_COMPILER_VERSION_CMD gcc --version >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_COMPILE_EXCLUDE_FLAGS -o** >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_DEFINE_LIST  >> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 60300 >> commands.tmp
echo options C_EXECUTE_CMD  >> commands.tmp
echo options C_LINKER_VERSION_CMD ld --version >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_OUTPUT_FLAG -o >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS asm s >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_COMPILER_SUPPORTS_CPP_CASTS FALSE >> commands.tmp
echo options VCAST_COVERAGE_FOR_AGGREGATE_INIT TRUE >> commands.tmp
echo options VCAST_DISABLE_CPP_EXCEPTIONS FALSE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_DISPLAY_FUNCTION_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENABLE_FUNCTION_CALL_COVERAGE TRUE >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_NO_LONG_DOUBLE TRUE >> commands.tmp
echo options VCAST_NO_SETJMP FALSE >> commands.tmp
echo options VCAST_PREPEND_TO_PATH_DIRS $(VECTORCAST_DIR)/MinGW/bin >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(5) >> commands.tmp
echo options VCAST_TYPEOF_OPERATOR TRUE >> commands.tmp
echo options VCAST_USE_STD_STRING TRUE >> commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\Dependencies\bsw-gen\Appl\GenData\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\Dependencies\di-apps\app-lib\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\Dependencies\di-apps-cfg\cfg\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\Dependencies\di-apps-cfg\inc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\Dependencies\vp-build\stubs\include\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\Dependencies\vp-build\stubs\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\Dependencies\vp-build\stubs\apm\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\code\src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\code\inc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core_observer\code\WarnMsg_Core_Observer\src\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Git\mahindra\Message_Core_UT\message_core\Dependencies\vp-build\Tools\MOT_Generator\inc\Dummy_includes\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core\Dependencies\bsw-gen\Appl\GenData\Components\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR C:\Users\ashenoy1\Downloads\Message_Core_UT\message_core_observer\code\WarnMsg_Core_TmrSupport\src\ >> commands.tmp
echo environment build MESSAGE_CORE.env >> commands.tmp
echo /E:MESSAGE_CORE  tools update mcdc >> commands.tmp
echo /E:MESSAGE_CORE tools script run MESSAGE_CORE.tst >> commands.tmp
echo /E:MESSAGE_CORE execute batch >> commands.tmp
echo /E:MESSAGE_CORE tools import_coverage MESSAGE_CORE.cvr >> commands.tmp
echo /E:MESSAGE_CORE reports custom management MESSAGE_CORE_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
