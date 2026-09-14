-- VectorCAST 20.sp7 (04/21/21)
-- Test Case Script
--
-- Environment    : SYSTEM_STATE_UT
-- Unit(s) Under Test: system_state system_state_component
--
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:REMOVED_CL_PREFIX
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STANDARD_SPACING_R2
TEST.SCRIPT_FEATURE:OVERLOADED_CONST_SUPPORT
TEST.SCRIPT_FEATURE:UNDERSCORE_NULLPTR
TEST.SCRIPT_FEATURE:FULL_PARAMETER_TYPES
TEST.SCRIPT_FEATURE:STRUCT_DTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STRUCT_FIELD_CTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Unit: system_state

-- Subprogram: SystemState::ShutdownFinalTimerListener::onTimeout

-- Test Case: l_return_S32_changed_for_false_case
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::ShutdownFinalTimerListener::onTimeout
TEST.NEW
TEST.NAME:l_return_S32_changed_for_false_case
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::SystemState
TEST.STUB:system_state.SystemState::onInit
TEST.STUB:system_state.SystemState::onExit
TEST.STUB:system_state.SystemState::onStart
TEST.STUB:system_state.SystemState::onStop
TEST.STUB:system_state.SystemState::worker
TEST.STUB:system_state.SystemState::requestStateChange
TEST.STUB:system_state.SystemState::requestWakeLock
TEST.STUB:system_state.SystemState::setCommLinkStatus
TEST.STUB:system_state.SystemState::setCompState
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::ShutdownFinalTimerListener::onTimeout.timer.dk::osal::Timer.<<constructor>>.Timer(const dk::osal::Timer&).<<call>>:0
TEST.VALUE:system_state.SystemState::onExit.return:true
TEST.VALUE:system_state.SystemState::onStop.return:true
TEST.VALUE:system_state.SystemState::requestStateChange.state:34,45,56
TEST.VALUE:system_state.SystemState::requestWakeLock.compId:23,45,67
TEST.VALUE:system_state.SystemState::requestWakeLock.enable:0
TEST.VALUE:system_state.SystemState::requestWakeLock.requestedLockTimeMs:567788
TEST.VALUE:system_state.SystemState::setCommLinkStatus.linkState:2147483641
TEST.VALUE:uut_prototype_stubs.dk_bspal_sys_shutdown.p_type_E:ESysShutdown_Shutdown
TEST.VALUE:uut_prototype_stubs.dk_bspal_sys_shutdown.return:0
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.mIsStarted:false
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.mSystemStateObj.SystemState.mSystemState:MACRO=ESystemState_Off
TEST.END

-- Test Case: l_return_S32_changed_for_true_case
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::ShutdownFinalTimerListener::onTimeout
TEST.NEW
TEST.NAME:l_return_S32_changed_for_true_case
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::SystemState
TEST.STUB:system_state.SystemState::onInit
TEST.STUB:system_state.SystemState::onExit
TEST.STUB:system_state.SystemState::onStart
TEST.STUB:system_state.SystemState::onStop
TEST.STUB:system_state.SystemState::worker
TEST.STUB:system_state.SystemState::requestStateChange
TEST.STUB:system_state.SystemState::requestWakeLock
TEST.STUB:system_state.SystemState::setCommLinkStatus
TEST.STUB:system_state.SystemState::setCompState
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::ShutdownFinalTimerListener::onTimeout.timer.dk::osal::Timer.<<constructor>>.Timer(const dk::osal::Timer&).<<call>>:0
TEST.VALUE:system_state.SystemState::onExit.return:true
TEST.VALUE:system_state.SystemState::onStop.return:true
TEST.VALUE:system_state.SystemState::requestStateChange.state:34,45,56
TEST.VALUE:system_state.SystemState::requestWakeLock.compId:23,45,67
TEST.VALUE:system_state.SystemState::requestWakeLock.enable:0
TEST.VALUE:system_state.SystemState::requestWakeLock.requestedLockTimeMs:567788
TEST.VALUE:system_state.SystemState::setCommLinkStatus.linkState:2147483641
TEST.VALUE:uut_prototype_stubs.dk_bspal_sys_shutdown.p_type_E:ESysShutdown_Shutdown
TEST.VALUE:uut_prototype_stubs.dk_bspal_sys_shutdown.return:-1
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.mIsStarted:false
TEST.END

-- Subprogram: SystemState::addWakeLock

-- Test Case: set_requestLockTimeMs_and_return_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::addWakeLock
TEST.NEW
TEST.NAME:set_requestLockTimeMs_and_return_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.SystemState::addWakeLock.compId:1
TEST.VALUE:system_state.SystemState::addWakeLock.requestedLockTimeMs:1000
TEST.EXPECTED:system_state.SystemState::addWakeLock.return:1
TEST.END

-- Subprogram: SystemState::checkIfFullRunConditionSatified

-- Test Case: set_mFullRunCompList_size_and_values
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::checkIfFullRunConditionSatified
TEST.NEW
TEST.NAME:set_mFullRunCompList_size_and_values
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compState:MACRO=ESystemState_Up
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up
TEST.EXPECTED:system_state.SystemState::checkIfFullRunConditionSatified.return:true
TEST.END

-- Subprogram: SystemState::checkIfShutdownConditionSatified

-- Test Case: set_mActiveWakeLockList_size_to_non_zero
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::checkIfShutdownConditionSatified
TEST.NEW
TEST.NAME:set_mActiveWakeLockList_size_to_non_zero
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compState:MACRO=ECompState_Shutdown
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ECompState_Shutdown
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str:"static int index;"
TEST.EXPECTED:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: set_more_values_of_mFullRunCompList_and_return_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::checkIfShutdownConditionSatified
TEST.NEW
TEST.NAME:set_more_values_of_mFullRunCompList_and_return_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compState:MACRO=ECompState_Shutdown
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1].compId:2
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1].compState:MACRO=ECompState_Shutdown
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1]:<<function 1>>
TEST.EXPECTED:system_state.SystemState::checkIfShutdownConditionSatified.return:true
TEST.END

-- Test Case: set_size_of_FullRunComplist_and_return_false
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::checkIfShutdownConditionSatified
TEST.NEW
TEST.NAME:set_size_of_FullRunComplist_and_return_false
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.EXPECTED:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: set_values_of_FullRunCompList_and_return_false
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::checkIfShutdownConditionSatified
TEST.NEW
TEST.NAME:set_values_of_FullRunCompList_and_return_false
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compState:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.EXPECTED:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Subprogram: SystemState::enumToString

-- Test Case: SystemState::enumToString.001
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::enumToString
TEST.NEW
TEST.NAME:SystemState::enumToString.001
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::enumToString.return:<<malloc 3>>
TEST.VALUE:system_state.SystemState::enumToString.return:"15"
TEST.VALUE_USER_CODE:<<SystemState instance>>.SystemState.mEnumToStr
<<SystemState instance>>->mEnumToStr = {
    {0, "INIT"},
    {1, "STATE1"},
    {2, "STATE2"},
    {3, "STATE3"},
    {4, "STATE4"},
    {5, "STATE5"},
    {6, "STATE6"},
    {7, "STATE7"},
    {8, "STATE8"},
    {9, "STATE9"},
    {10, "STATE10"}
};
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: SystemState::getDomainId

-- Test Case: function_return_0
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::getDomainId
TEST.NEW
TEST.NAME:function_return_0
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.EXPECTED:system_state.SystemState::getDomainId.return:0
TEST.END

-- Subprogram: SystemState::getNumberOfActiveWakeLocks

-- Test Case: set_the_getNumberOfActiveWakeLocks_size_and_return
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::getNumberOfActiveWakeLocks
TEST.NEW
TEST.NAME:set_the_getNumberOfActiveWakeLocks_size_and_return
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].compId:10
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].expiresAt:10000
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.EXPECTED:system_state.SystemState::getNumberOfActiveWakeLocks.return:1
TEST.END

-- Subprogram: SystemState::loadConfiguration

-- Test Case: loadConfiguration_returns_false
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::loadConfiguration
TEST.NEW
TEST.NAME:loadConfiguration_returns_false
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mParserObj.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.EXPECTED:system_state.SystemState::loadConfiguration.return:false
TEST.END

-- Test Case: loadConfiguration_returns_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::loadConfiguration
TEST.NEW
TEST.NAME:loadConfiguration_returns_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mParserObj.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:system_state.SystemState::loadConfiguration.return:(2)false,true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:(2)false,true
TEST.EXPECTED:system_state.SystemState::loadConfiguration.return:true
TEST.END

-- Test Case: set_mIsConfigurationLoaded_to_false
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::loadConfiguration
TEST.NEW
TEST.NAME:set_mIsConfigurationLoaded_to_false
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mParserObj.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:false
TEST.EXPECTED:system_state.SystemState::loadConfiguration.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str
static int index;
bool ret = false;
if (index) {
ret = true;
}else {
ret = false;
index++;
}


<<uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return>> = ( ret );<<uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return>> = ( ret );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: set_mIsConfigurationLoaded_to_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::loadConfiguration
TEST.NEW
TEST.NAME:set_mIsConfigurationLoaded_to_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mParserObj.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.EXPECTED:system_state.SystemState::loadConfiguration.return:true
TEST.END

-- Test Case: set_str_in_loadConfiguration
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::loadConfiguration
TEST.NEW
TEST.NAME:set_str_in_loadConfiguration
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mParserObj.dk::runtime::core::ParserIf.mIsConfigurationLoaded:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:false
TEST.EXPECTED:system_state.SystemState::loadConfiguration.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.str
static int index;
bool ret = false;
if (index) {
ret = true;
}else {
ret = false;
index++;
}


<<uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return>> = ( ret );<<uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return>> = ( ret );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: SystemState::onExit

-- Test Case: return_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onExit
TEST.NEW
TEST.NAME:return_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.EXPECTED:system_state.SystemState::onExit.return:true
TEST.END

-- Subprogram: SystemState::onInit

-- Test Case: SystemState::onInit.001
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:SystemState::onInit.001
TEST.STUB:system_state.SystemState::loadConfiguration
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::onInit.return:true
TEST.VALUE:system_state.SystemState::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"States"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.END

-- Test Case: SystemState::onInit.002
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:SystemState::onInit.002
TEST.STUB:system_state.SystemState::loadConfiguration
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::onInit.return:true
TEST.VALUE:system_state.SystemState::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"States"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList:<<malloc 3>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:"1"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[1]:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[1]:"2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[2]:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[2]:"3"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[2]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getStringValue.return:"1"
TEST.END

-- Test Case: SystemState::onInit.003
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:SystemState::onInit.003
TEST.STUB:system_state.SystemState::loadConfiguration
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::onInit.return:true
TEST.VALUE:system_state.SystemState::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.section:"States"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList:<<malloc 3>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:"1"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[1]:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[1]:"2"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[2]:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[2]:"3"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.keyList[2]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllKeysFromSection.return:true
TEST.END

-- Test Case: getAllValuesForKey_returns_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:getAllValuesForKey_returns_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:false
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.section:"SystemStateConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.key:"FullRunComponentTransitionList"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.EXPECTED:system_state.SystemState::onInit.return:true
TEST.END

-- Test Case: loadConfiguration_returns_false
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:loadConfiguration_returns_false
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:false
TEST.EXPECTED:system_state.SystemState::onInit.return:true
TEST.END

-- Test Case: loadConfiguration_returns_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:loadConfiguration_returns_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.EXPECTED:system_state.SystemState::onInit.return:true
TEST.END

-- Test Case: while_loop
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:while_loop
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::setCompState
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compId:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compState:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1].compId:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1].compState:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1]:<<function 1>>
TEST.VALUE:system_state.SystemState::setCompState.compId:1
TEST.VALUE:system_state.SystemState::setCompState.compState:1
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.section:"SystemStateConfiguration"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.key:"FullRunComponentTransitionList"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 3>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"10"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.EXPECTED:system_state.SystemState::onInit.return:true
TEST.END

-- Test Case: while_loop_2
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:while_loop_2
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::requestWakeLock
TEST.STUB:system_state.SystemState::setCompState
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compId:2
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compState:2
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1].compState:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1]:<<function 1>>
TEST.VALUE:system_state.SystemState::setCompState.compId:0
TEST.VALUE:system_state.SystemState::setCompState.compState:MACRO=ECompState_Init
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.key:"FullRunComponentTransitionList"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 2>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"1"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[1]:<<malloc 3>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[1]:"10"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[1]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.EXPECTED:system_state.SystemState::onInit.return:true
TEST.END

-- Test Case: while_loop_3
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onInit
TEST.NEW
TEST.NAME:while_loop_3
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::requestWakeLock
TEST.STUB:system_state.SystemState::setCompState
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compId:2
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compState:2
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1].compState:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1]:<<function 1>>
TEST.VALUE:system_state.SystemState::setCompState.compId:0
TEST.VALUE:system_state.SystemState::setCompState.compState:MACRO=ECompState_Init
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.key:"FullRunComponentTransitionList"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<malloc 4>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:"10,"
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.valueList[0]:<<function 1>>
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::getAllValuesForKey.return:true
TEST.EXPECTED:system_state.SystemState::onInit.return:true
TEST.END

-- Subprogram: SystemState::onStart

-- Test Case: return_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onStart
TEST.NEW
TEST.NAME:return_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.EXPECTED:system_state.SystemState::onStart.return:true
TEST.END

-- Subprogram: SystemState::onStop

-- Test Case: return_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::onStop
TEST.NEW
TEST.NAME:return_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.EXPECTED:system_state.SystemState::onStop.return:true
TEST.END

-- Subprogram: SystemState::periodicTask

-- Test Case: change_removeExpiredWakeLocks
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::periodicTask
TEST.NEW
TEST.NAME:change_removeExpiredWakeLocks
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.STUB:system_state.SystemState::removeExpiredWakeLocks
TEST.STUB:system_state.SystemState::checkIfShutdownConditionSatified
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[1]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_PrepareShutdown
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemStateBroadcastTimer:1
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:1
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.timeNow:1
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.return:1
TEST.VALUE:system_state.SystemState::checkIfShutdownConditionSatified.return:true
TEST.END

-- Test Case: checkIfShutdownConditionSatisfied_to_false
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::periodicTask
TEST.NEW
TEST.NAME:checkIfShutdownConditionSatisfied_to_false
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.STUB:system_state.SystemState::removeExpiredWakeLocks
TEST.STUB:system_state.SystemState::checkIfShutdownConditionSatified
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[1]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_PrepareShutdown
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemStateBroadcastTimer:1
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:1
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.timeNow:1
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.return:1
TEST.VALUE:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: getNumberOfActiveWakeLocks_is_set_to_0
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::periodicTask
TEST.NEW
TEST.NAME:getNumberOfActiveWakeLocks_is_set_to_0
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.STUB:system_state.SystemState::removeExpiredWakeLocks
TEST.STUB:system_state.SystemState::checkIfShutdownConditionSatified
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[1]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_PrepareShutdown
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemStateShutdownTimer:1
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:1
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.timeNow:1
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.return:1
TEST.VALUE:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: getNumberOfActiveWakeLocks_is_set_to_1
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::periodicTask
TEST.NEW
TEST.NAME:getNumberOfActiveWakeLocks_is_set_to_1
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[1]:<<function 1>>
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:1
TEST.END

-- Test Case: set_num_wakeLocks_to_invalid
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::periodicTask
TEST.NEW
TEST.NAME:set_num_wakeLocks_to_invalid
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:0
TEST.END

-- Subprogram: SystemState::removeExpiredWakeLocks

-- Test Case: execting_the_false_condition
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::removeExpiredWakeLocks
TEST.NEW
TEST.NAME:execting_the_false_condition
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].expiresAt:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.timeNow:1
TEST.EXPECTED:system_state.SystemState::removeExpiredWakeLocks.return:1
TEST.END

-- Test Case: return_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::removeExpiredWakeLocks
TEST.NEW
TEST.NAME:return_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].expiresAt:5
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.timeNow:2
TEST.EXPECTED:system_state.SystemState::removeExpiredWakeLocks.return:1
TEST.END

-- Test Case: set_mActiveWakeLockList_sise_and_true_condition
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::removeExpiredWakeLocks
TEST.NEW
TEST.NAME:set_mActiveWakeLockList_sise_and_true_condition
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].expiresAt:100
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.SystemState::removeExpiredWakeLocks.timeNow:102
TEST.EXPECTED:system_state.SystemState::removeExpiredWakeLocks.return:0
TEST.END

-- Subprogram: SystemState::removeWakeLockByCompId

-- Test Case: set_enable_in_requestWakeLock
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::removeWakeLockByCompId
TEST.NEW
TEST.NAME:set_enable_in_requestWakeLock
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::requestWakeLock
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::requestWakeLock.compId:1
TEST.VALUE:system_state.SystemState::requestWakeLock.enable:0
TEST.VALUE:system_state.SystemState::requestWakeLock.requestedLockTimeMs:1
TEST.VALUE:system_state.SystemState::removeWakeLockByCompId.compId:2
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:system_state.SystemState::removeWakeLockByCompId.return:1
TEST.END

-- Test Case: set_removeWakeLockByCompId
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::removeWakeLockByCompId
TEST.NEW
TEST.NAME:set_removeWakeLockByCompId
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::removeWakeLockByCompId.compId:1
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:system_state.SystemState::removeWakeLockByCompId.return:0
TEST.END

-- Test Case: set_size_of_mActiveWakeLockList
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::removeWakeLockByCompId
TEST.NEW
TEST.NAME:set_size_of_mActiveWakeLockList
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].expiresAt:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.SystemState::removeWakeLockByCompId.compId:1
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:system_state.SystemState::removeWakeLockByCompId.return:0
TEST.END

-- Subprogram: SystemState::requestStateChange

-- Test Case: state_0_mSystemState_ESystemState_Shutdown
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_0_mSystemState_ESystemState_Shutdown
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Shutdown
TEST.VALUE:system_state.SystemState::requestStateChange.state:0
TEST.END

-- Test Case: state_6_mSystemState_5
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_6_mSystemState_5
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:5
TEST.VALUE:system_state.SystemState::requestStateChange.state:6
TEST.END

-- Test Case: state_6_mSystemState_7
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_6_mSystemState_7
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:7
TEST.VALUE:system_state.SystemState::requestStateChange.state:6
TEST.END

-- Test Case: state_ESystemState_Startup_mSystemState_ESystemState_Shutdown
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_ESystemState_Startup_mSystemState_ESystemState_Shutdown
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Shutdown
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Startup
TEST.END

-- Test Case: state_ESystemState_Startup_mSystemState_ESystemState_Up
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_ESystemState_Startup_mSystemState_ESystemState_Up
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Startup
TEST.END

-- Test Case: state_FullRun_mSystemState_FullRun
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_FullRun_mSystemState_FullRun
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_FullRun
TEST.END

-- Test Case: state_FullRun_mSystemState_Up
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_FullRun_mSystemState_Up
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_FullRun
TEST.END

-- Test Case: state_Meet_mSystemState_Meet
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Meet_mSystemState_Meet
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::checkIfShutdownConditionSatified
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Meet
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Meet
TEST.VALUE:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: state_Meet_mSystemState_Up_FullRun
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Meet_mSystemState_Up_FullRun
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::checkIfShutdownConditionSatified
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Meet
TEST.VALUE:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: state_Minimal_mSystemState_Up_FullRun
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Minimal_mSystemState_Up_FullRun
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:7
TEST.VALUE:system_state.SystemState::requestStateChange.state:2
TEST.END

-- Test Case: state_Minimal_mSystemState_Up_Startup
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Minimal_mSystemState_Up_Startup
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_Startup
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Minimal
TEST.END

-- Test Case: state_Off_mSystemState_Off
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Off_mSystemState_Off
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::checkIfShutdownConditionSatified
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Off
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Off
TEST.VALUE:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: state_Shutdown_mSystemState_FullRun_Minimal
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Shutdown_mSystemState_FullRun_Minimal
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:3
TEST.VALUE:system_state.SystemState::requestStateChange.state:5
TEST.END

-- Test Case: state_Shutdown_mSystemState_Shutdown_PrepareShutdown
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Shutdown_mSystemState_Shutdown_PrepareShutdown
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::checkIfShutdownConditionSatified
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Shutdown,MACRO=ESystemState_PrepareShutdown
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Shutdown
TEST.VALUE:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: state_Shutdown_mSystemState_Up_FullRun
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Shutdown_mSystemState_Up_FullRun
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Shutdown
TEST.END

-- Test Case: state_Shutdown_mSystemState_Up_FullRun_and_shutdown_condition_satisfied_false
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Shutdown_mSystemState_Up_FullRun_and_shutdown_condition_satisfied_false
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::checkIfShutdownConditionSatified
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Shutdown
TEST.VALUE:system_state.SystemState::checkIfShutdownConditionSatified.return:false
TEST.END

-- Test Case: state_Up_mSystemState_StartUp_Mininmal_Meet
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Up_mSystemState_StartUp_Mininmal_Meet
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:5
TEST.VALUE:system_state.SystemState::requestStateChange.state:2
TEST.END

-- Test Case: state_Up_mSystemState_Startup_Shutdown
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:state_Up_mSystemState_Startup_Shutdown
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Startup,MACRO=ESystemState_Shutdown
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_Up
TEST.END

-- Test Case: switch_case_for_default_case
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestStateChange
TEST.NEW
TEST.NAME:switch_case_for_default_case
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::requestStateChange.state:10
TEST.END

-- Subprogram: SystemState::requestWakeLock

-- Test Case: requestWakeLock_disable_1
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestWakeLock
TEST.NEW
TEST.NAME:requestWakeLock_disable_1
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].compId:2
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_Startup
TEST.VALUE:system_state.SystemState::requestWakeLock.compId:1
TEST.VALUE:system_state.SystemState::requestWakeLock.enable:0
TEST.VALUE:system_state.SystemState::requestWakeLock.requestedLockTimeMs:2
TEST.END

-- Test Case: requestWakeLock_disable_2
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestWakeLock
TEST.NEW
TEST.NAME:requestWakeLock_disable_2
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::removeWakeLockByCompId
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_Startup
TEST.VALUE:system_state.SystemState::requestWakeLock.compId:1
TEST.VALUE:system_state.SystemState::requestWakeLock.enable:0
TEST.VALUE:system_state.SystemState::requestWakeLock.requestedLockTimeMs:1
TEST.END

-- Test Case: requestWakeLock_enable_1
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestWakeLock
TEST.NEW
TEST.NAME:requestWakeLock_enable_1
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::requestWakeLock.compId:1
TEST.VALUE:system_state.SystemState::requestWakeLock.enable:1
TEST.END

-- Test Case: requestWakeLock_enable_2
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::requestWakeLock
TEST.NEW
TEST.NAME:requestWakeLock_enable_2
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up,MACRO=ESystemState_Startup
TEST.VALUE:system_state.SystemState::requestWakeLock.compId:1
TEST.VALUE:system_state.SystemState::requestWakeLock.enable:1
TEST.VALUE:system_state.SystemState::requestWakeLock.requestedLockTimeMs:2
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:0
TEST.END

-- Subprogram: SystemState::sendCurrentSystemState

-- Test Case: return_nothing
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::sendCurrentSystemState
TEST.NEW
TEST.NAME:return_nothing
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.END

-- Subprogram: SystemState::sendExtendShutdownTime

-- Test Case: return_nothing
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::sendExtendShutdownTime
TEST.NEW
TEST.NAME:return_nothing
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.END

-- Subprogram: SystemState::sendKeepSystemAwake

-- Test Case: set_compId_and_return
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::sendKeepSystemAwake
TEST.NEW
TEST.NAME:set_compId_and_return
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::addWakeLock
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0].expiresAt:1000
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[1].compId:2
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[1].expiresAt:1000
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[1]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.SystemState::addWakeLock.compId:1
TEST.VALUE:system_state.SystemState::addWakeLock.requestedLockTimeMs:1
TEST.VALUE:system_state.SystemState::addWakeLock.return:1
TEST.END

-- Test Case: set_linkState
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::sendKeepSystemAwake
TEST.NEW
TEST.NAME:set_linkState
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::setCommLinkStatus
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::setCommLinkStatus.linkState:-50
TEST.END

-- Subprogram: SystemState::sendStatusReport

-- Test Case: getNumberOfActiveWakeLocks_return_0
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::sendStatusReport
TEST.NEW
TEST.NAME:getNumberOfActiveWakeLocks_return_0
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:0
TEST.END

-- Test Case: getNumberOfActiveWakeLocks_return_1
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::sendStatusReport
TEST.NEW
TEST.NAME:getNumberOfActiveWakeLocks_return_1
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:1
TEST.END

-- Test Case: set_mActiveWakeLockList_size
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::sendStatusReport
TEST.NEW
TEST.NAME:set_mActiveWakeLockList_size
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::getNumberOfActiveWakeLocks
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList:<<malloc 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mActiveWakeLockList[0]:<<function 1>>
TEST.VALUE:system_state.SystemState::getNumberOfActiveWakeLocks.return:1
TEST.END

-- Subprogram: SystemState::setCommLinkStatus

-- Test Case: linkState_set_to_(sint32)_-50
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::setCommLinkStatus
TEST.NEW
TEST.NAME:linkState_set_to_(sint32)_-50
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::requestStateChange
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::setCommLinkStatus.linkState:-2147483648
TEST.END

-- Test Case: linkState_set_to_-1
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::setCommLinkStatus
TEST.NEW
TEST.NAME:linkState_set_to_-1
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::requestStateChange
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::setCommLinkStatus.linkState:-1
TEST.END

-- Test Case: linkState_set_to_-50
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::setCommLinkStatus
TEST.NEW
TEST.NAME:linkState_set_to_-50
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::requestStateChange
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.SystemState::requestStateChange.state:MACRO=ESystemState_FullRun
TEST.VALUE:system_state.SystemState::setCommLinkStatus.linkState:-50
TEST.END

-- Subprogram: SystemState::setCompState

-- Test Case: FullRunComList_vector_size_is_set
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::setCompState
TEST.NEW
TEST.NAME:FullRunComList_vector_size_is_set
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1]:<<function 1>>
TEST.VALUE:system_state.SystemState::setCompState.compId:1
TEST.VALUE:system_state.SystemState::setCompState.compState:1
TEST.END

-- Test Case: mFullRunCompList_vector_filled_with_values
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::setCompState
TEST.NEW
TEST.NAME:mFullRunCompList_vector_filled_with_values
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList:<<malloc 2>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compId:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0].compState:1
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[0]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mFullRunCompList[1]:<<function 1>>
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.mSystemState:MACRO=ESystemState_Up
TEST.VALUE:system_state.SystemState::setCompState.compId:1
TEST.VALUE:system_state.SystemState::setCompState.compState:1
TEST.END

-- Subprogram: SystemState::worker

-- Test Case: return_true
TEST.UNIT:system_state
TEST.SUBPROGRAM:SystemState::worker
TEST.NEW
TEST.NAME:return_true
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState.SystemState.<<constructor>>.SystemState().<<call>>:0
TEST.END

-- Unit: system_state_component

-- Subprogram: SystemStateComponent::onExit

-- Test Case: SystemStateComponent::onExit
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onExit
TEST.NEW
TEST.NAME:SystemStateComponent::onExit
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:system_state_component.SystemStateComponent::onExit.return:true
TEST.END

-- Subprogram: SystemStateComponent::onInit

-- Test Case: SystemStateComponent::onInit
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onInit
TEST.NEW
TEST.NAME:SystemStateComponent::onInit
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state.SystemState::onInit
TEST.STUB:system_state_component.SystemStateComponent::periodicTask_100ms
TEST.VALUE:system_state.<<GLOBAL>>.(cl).SystemState::ShutdownFinalTimerListener.SystemState::ShutdownFinalTimerListener.<<constructor>>.ShutdownFinalTimerListener().<<call>>:0
TEST.VALUE:system_state.SystemState::onInit.return:true
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:system_state_component.SystemStateComponent::onInit.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::Component::registerTask.taskCbk
// Begin user code for dk::runtime::core::Component::registerTask
if ( <<uut_prototype_stubs.dk::runtime::core::Component::registerTask.taskCbk>> ) {
    // Invoke the callback immediately to simulate scheduling
    <<uut_prototype_stubs.dk::runtime::core::Component::registerTask.taskCbk>>();
}
 
// Return success (0 = OK)
return 0;
// End user code
 
 
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Subprogram: SystemStateComponent::onReceiveHealthGetStatus

-- Test Case: SystemStateComponent::onReceiveHealthGetStatus
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onReceiveHealthGetStatus
TEST.NEW
TEST.NAME:SystemStateComponent::onReceiveHealthGetStatus
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state_component.SystemStateComponent::onReceiveRTC
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveHealthGetStatus.msg.base.compId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveHealthGetStatus.msg.base.msgCnt:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveHealthGetStatus.msg.compIdx:1
TEST.END

-- Subprogram: SystemStateComponent::onReceivePowerReportCompState

-- Test Case: SystemStateComponent::onReceivePowerReportCompState
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onReceivePowerReportCompState
TEST.NEW
TEST.NAME:SystemStateComponent::onReceivePowerReportCompState
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerReportCompState.msg.base.compId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerReportCompState.msg.base.msgCnt:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerReportCompState.msg.state:1
TEST.END

-- Subprogram: SystemStateComponent::onReceivePowerSystemStateReqChange

-- Test Case: SystemStateComponent::onReceivePowerSystemStateReqChange
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onReceivePowerSystemStateReqChange
TEST.NEW
TEST.NAME:SystemStateComponent::onReceivePowerSystemStateReqChange
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state_component.SystemStateComponent::onReceivePowerReportCompState
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.base.compId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.base.msgCnt:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.domainId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.state:1
TEST.END

-- Test Case: SystemStateComponent::onReceivePowerSystemStateReqChange_false
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onReceivePowerSystemStateReqChange
TEST.NEW
TEST.NAME:SystemStateComponent::onReceivePowerSystemStateReqChange_false
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state_component.SystemStateComponent::onReceivePowerReportCompState
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.base.compId:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.base.msgCnt:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.domainId:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.state:0
TEST.END

-- Subprogram: SystemStateComponent::onReceivePowerSystemStateReqWakeLock

-- Test Case: SystemStateComponent::onReceivePowerSystemStateReqWakeLock
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onReceivePowerSystemStateReqWakeLock
TEST.NEW
TEST.NAME:SystemStateComponent::onReceivePowerSystemStateReqWakeLock
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqWakeLock.msg.base.compId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqWakeLock.msg.base.msgCnt:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqWakeLock.msg.enable:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqWakeLock.msg.requiredTimeMs:1
TEST.END

-- Subprogram: SystemStateComponent::onReceiveRTC

-- Test Case: SystemStateComponent::onReceiveRTC
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onReceiveRTC
TEST.NEW
TEST.NAME:SystemStateComponent::onReceiveRTC
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveRTC.msg.base.compId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveRTC.msg.base.msgCnt:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveRTC.msg.dateTime.year:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveRTC.msg.dateTime.month:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveRTC.msg.dateTime.day:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveRTC.msg.dateTime.hour:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveRTC.msg.dateTime.min:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveRTC.msg.dateTime.sec:1
TEST.END

-- Subprogram: SystemStateComponent::onReceiveUclErrorNotify

-- Test Case: SystemStateComponent::onReceiveUclErrorNotify
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onReceiveUclErrorNotify
TEST.NEW
TEST.NAME:SystemStateComponent::onReceiveUclErrorNotify
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveUclErrorNotify.msg.base.compId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveUclErrorNotify.msg.base.msgCnt:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveUclErrorNotify.msg.errorCode:1
TEST.END

-- Subprogram: SystemStateComponent::onReceiveUclLinkStatus

-- Test Case: SystemStateComponent::onReceiveUclLinkStatus
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onReceiveUclLinkStatus
TEST.NEW
TEST.NAME:SystemStateComponent::onReceiveUclLinkStatus
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state_component.SystemStateComponent::onReceiveUclErrorNotify
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveUclErrorNotify.msg.errorCode:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveUclLinkStatus.msg.base.compId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveUclLinkStatus.msg.base.msgCnt:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceiveUclLinkStatus.msg.status:1
TEST.END

-- Subprogram: SystemStateComponent::onStart

-- Test Case: SystemStateComponent::onStart
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onStart
TEST.NEW
TEST.NAME:SystemStateComponent::onStart
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:system_state_component.SystemStateComponent::onStart.return:true
TEST.END

-- Subprogram: SystemStateComponent::onStop

-- Test Case: SystemStateComponent::onStop
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::onStop
TEST.NEW
TEST.NAME:SystemStateComponent::onStop
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:system_state_component.SystemStateComponent::onStop.return:true
TEST.END

-- Subprogram: SystemStateComponent::periodicTask_100ms

-- Test Case: SystemStateComponent::periodicTask_100ms
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::periodicTask_100ms
TEST.NEW
TEST.NAME:SystemStateComponent::periodicTask_100ms
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END

-- Subprogram: SystemStateComponent::worker

-- Test Case: SystemStateComponent::worker
TEST.UNIT:system_state_component
TEST.SUBPROGRAM:SystemStateComponent::worker
TEST.NEW
TEST.NAME:SystemStateComponent::worker
TEST.NOTES:
PowerMgr in GIP_INFRA::PlatformServices::PowerMgr (This is applicable for BMW Program)
TEST.END_NOTES:
TEST.STUB:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange
TEST.STUB:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqWakeLock
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.<<constructor>>.SystemStateComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:system_state_component.<<GLOBAL>>.(cl).SystemStateComponent.SystemStateComponent.mSystemStateObj.SystemState.mDomainId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.base.compId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.base.msgCnt:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.domainId:1
TEST.VALUE:system_state_component.SystemStateComponent::onReceivePowerSystemStateReqChange.msg.state:1
TEST.END
