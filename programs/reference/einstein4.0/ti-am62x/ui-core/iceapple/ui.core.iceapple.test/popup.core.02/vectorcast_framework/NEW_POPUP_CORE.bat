del commands.tmp
echo options WHITEBOX YES >> commands.tmp
echo options COVERAGE_IO_TYPE VCAST_COVERAGE_IO_ANIMATION >> commands.tmp
echo options VCAST_COLLAPSE_STD_HEADERS COLLAPSE_SYSTEM_HEADERS >> commands.tmp
echo options SBF_LOC_NONMEMBER_IN_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_MEMBER_IN_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_MEMBER_OUTSIDE_NSP DECL_NAMESPACE >> commands.tmp
echo options SBF_LOC_NONMEMBER_OUTSIDE_NSP DECL_NAMESPACE >> commands.tmp
echo options VCAST_INST_FILE_MAX_LINES 0 >> commands.tmp
echo options TARGET_VARIANT HOST >> commands.tmp
echo options C_COMPILER_TAG GNU_C_46 >> commands.tmp
echo options C_COMPILER_HIERARCHY_STRING GNU Native_4.6_C >> commands.tmp
echo options C_COMPILER_NAME GNU C 4.6 >> commands.tmp
echo options C_DEFINE_LIST  >> commands.tmp
echo options C_PREPROCESS_CMD gcc -E -C >> commands.tmp
echo options C_COMPILE_CMD gcc -c -g >> commands.tmp
echo options C_COMPILE_CMD_NAME gcc >> commands.tmp
echo options C_COMPILE_CMD_FLAG -c >> commands.tmp
echo options C_COMPILE_EXCLUDE_FLAGS -o** >> commands.tmp
echo options C_MAKE_ALL_CMD make -n -f {file} >> commands.tmp
echo options C_DEBUG_CMD gdb >> commands.tmp
echo options C_LINK_CMD gcc -g >> commands.tmp
echo options C_SYNTAX_CHECK_FLAG -S >> commands.tmp
echo options C_EDG_FLAGS -w --gcc --gnu_version 40600 >> commands.tmp
echo options EXECUTABLE_EXTENSION  >> commands.tmp
echo options VCAST_ENVIRONMENT_FILES  >> commands.tmp
echo options VCAST_RPTS_DEFAULT_FONT_FACE Arial(9) >> commands.tmp
echo options VCAST_ASSEMBLY_FILE_EXTENSIONS s >> commands.tmp
echo options SUBSTITUTE_CODE_FOR_C_FILE FALSE >> commands.tmp
echo options VCAST_AUTO_CLEAR_TEST_USER_CODE FALSE >> commands.tmp
echo options VCAST_COMMAND_LINE_DEBUGGER TRUE >> commands.tmp
echo options VCAST_COMPILER_SUPPORTS_CPP_CASTS FALSE >> commands.tmp
echo options VCAST_FORCE_ELAB_TYPE_SPEC TRUE >> commands.tmp
echo options VCAST_REMOVE_PREPROCESSOR_COMMENTS TRUE >> commands.tmp
echo options VCAST_TEST_ALL_NON_MEMBER_INLINES FALSE >> commands.tmp
echo options VCAST_TORNADO_CONSTRUCTOR_CALL_FILE FALSE >> commands.tmp
echo options VCAST_DISABLE_STD_WSTRING_DETECTION TRUE >> commands.tmp
echo options VCAST_HAS_LONGLONG TRUE >> commands.tmp
echo options VCAST_MICROSOFT_LONG_LONG FALSE >> commands.tmp
echo options VCAST_USE_STD_STRING TRUE >> commands.tmp
echo clear_default_source_dirs  >> commands.tmp
echo options TESTABLE_SOURCE_DIR .\inc\ >> commands.tmp
echo options TESTABLE_SOURCE_DIR .\src\ >> commands.tmp
echo environment build NEW_POPUP_CORE.env >> commands.tmp
echo /E:NEW_POPUP_CORE tools script run NEW_POPUP_CORE.tst >> commands.tmp
echo /E:NEW_POPUP_CORE execute batch >> commands.tmp
echo /E:NEW_POPUP_CORE reports custom management NEW_POPUP_CORE_management_report.html >> commands.tmp
"%VECTORCAST_DIR%\CLICAST"  /L:C tools execute commands.tmp false
