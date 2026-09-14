-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : DISPLAY_MGR_UT
-- Unit(s) Under Test: display_manager_component
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STANDARD_SPACING_R2
TEST.SCRIPT_FEATURE:OVERLOADED_CONST_SUPPORT
TEST.SCRIPT_FEATURE:UNDERSCORE_NULLPTR
TEST.SCRIPT_FEATURE:FULL_PARAMETER_TYPES
TEST.SCRIPT_FEATURE:STRUCT_DTOR_ADDS_POINTER
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: display_manager_component

-- Subprogram: (cl)DisplayManagerComponent::TftErrPollTimerListener::onTimeout

-- Test Case: T1_OnTimeout_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::TftErrPollTimerListener::onTimeout
TEST.NEW
TEST.NAME:T1_OnTimeout_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent::TftErrPollTimerListener.DisplayManagerComponent::TftErrPollTimerListener.<<constructor>>.TftErrPollTimerListener(DisplayManagerComponent&).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::TftErrPollTimerListener::onTimeout.timer.dk::osal::Timer.<<constructor>>.Timer(dk::osal::ITimerListener&).<<call>>:0
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::loadConfig

-- Test Case: T1_loadConfig_SystemConfigFile_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::loadConfig
TEST.NEW
TEST.NAME:T1_loadConfig_SystemConfigFile_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::loadConfig.return:true
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::loadConfig.return:true
TEST.STUB_VAL_USER_CODE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return
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

-- Test Case: T2_loadConfig_LocalConfigFile_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::loadConfig
TEST.NEW
TEST.NAME:T2_loadConfig_LocalConfigFile_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:true
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::loadConfig.return:true
TEST.END

-- Test Case: T3_loadConfig_NoConfigFileFound_Failure
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::loadConfig
TEST.NEW
TEST.NAME:T3_loadConfig_NoConfigFileFound_Failure
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::loadConfig.return:false
TEST.END

-- Test Case: T4_loadConfig_FallbackConfigFile_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::loadConfig
TEST.NEW
TEST.NAME:T4_loadConfig_FallbackConfigFile_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::loadConfig.return:true
TEST.VALUE:uut_prototype_stubs.dk::runtime::core::ParserIf::loadConfiguration.return:(2)false,true
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::loadConfig.return:true
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onExit

-- Test Case: T1_onExit_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onExit
TEST.NEW
TEST.NAME:T1_onExit_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onExit.return:false
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::onExit.return:false
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onInit

-- Test Case: T1_onInit_LoadConfig_Failure
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onInit
TEST.NEW
TEST.NAME:T1_onInit_LoadConfig_Failure
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onInit.return:false
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::onInit.return:false
TEST.END

-- Test Case: T2_onInit_LoadConfig_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onInit
TEST.NEW
TEST.NAME:T2_onInit_LoadConfig_Success
TEST.STUB:display_manager_component.(cl)DisplayManagerComponent::loadConfig
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onInit.return:false
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::loadConfig.return:true
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::onInit.return:false
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onReceiveDisplayGetGammaRGB

-- Test Case: T1_onReceiveDisplayGetGammaRGB_Failure
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplayGetGammaRGB
TEST.NEW
TEST.NAME:T1_onReceiveDisplayGetGammaRGB_Failure
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_gamma_rgb.return:1
TEST.END

-- Test Case: T1_onReceiveDisplayGetGammaRGB_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplayGetGammaRGB
TEST.NEW
TEST.NAME:T1_onReceiveDisplayGetGammaRGB_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_gamma_rgb.return:0
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onReceiveDisplayGetState

-- Test Case: T1_onReceiveDisplayGetState_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplayGetState
TEST.NEW
TEST.NAME:T1_onReceiveDisplayGetState_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onReceiveDisplayGetState.msg.displayId:0
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspalDisplayState_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T2_onReceiveDisplayGetState_Failure
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplayGetState
TEST.NEW
TEST.NAME:T2_onReceiveDisplayGetState_Failure
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspalDisplayState_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:1
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onReceiveDisplaySetGammaRGB

-- Test Case: T1_onReceiveDisplaySetGammaRGB_Failure
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplaySetGammaRGB
TEST.NEW
TEST.NAME:T1_onReceiveDisplaySetGammaRGB_Failure
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_gamma_rgb.return:1
TEST.END

-- Test Case: T1_onReceiveDisplaySetGammaRGB_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplaySetGammaRGB
TEST.NEW
TEST.NAME:T1_onReceiveDisplaySetGammaRGB_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_gamma_rgb.return:0
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onReceiveDisplaySetPower

-- Test Case: T1_onReceiveDisplaySetPower_Display_off
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplaySetPower
TEST.NEW
TEST.NAME:T1_onReceiveDisplaySetPower_Display_off
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onReceiveDisplaySetPower.msg.state:EDisplayPower_Off
TEST.END

-- Test Case: T2_onReceiveDisplaySetPower_Display_on
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplaySetPower
TEST.NEW
TEST.NAME:T2_onReceiveDisplaySetPower_Display_on
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onReceiveDisplaySetPower.msg.state:EDisplayPower_On
TEST.END

-- Test Case: T3_onReceiveDisplaySetPower_Display_default
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceiveDisplaySetPower
TEST.NEW
TEST.NAME:T3_onReceiveDisplaySetPower_Display_default
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onReceiveDisplaySetPower.msg.state:EDisplayState_Error
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onReceivePowerSystemState

-- Test Case: T1_onReceivePowerSystemState_Up
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceivePowerSystemState
TEST.NEW
TEST.NAME:T1_onReceivePowerSystemState_Up
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onReceivePowerSystemState.msg.domainId:ESystemState_Up
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onReceivePowerSystemState.msg.state:ESystemState_Up
TEST.END

-- Test Case: T2_onReceivePowerSystemState_Down
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onReceivePowerSystemState
TEST.NEW
TEST.NAME:T2_onReceivePowerSystemState_Down
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onReceivePowerSystemState.msg.domainId:0
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onStart

-- Test Case: T1_onStart_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onStart
TEST.NEW
TEST.NAME:T1_onStart_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onStart.return:false
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::onStart.return:false
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::onStop

-- Test Case: T1_onStop_Success
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::onStop
TEST.NEW
TEST.NAME:T1_onStop_Success
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::onStop.return:false
TEST.EXPECTED:display_manager_component.(cl)DisplayManagerComponent::onStop.return:false
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::sendDisplayCurrentState

-- Test Case: T1_sendDisplayCurrentState_default
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::sendDisplayCurrentState
TEST.NEW
TEST.NAME:T1_sendDisplayCurrentState_default
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::sendDisplayCurrentState.p_stat_E:-1
TEST.END

-- Test Case: T2_sendDisplayCurrentState_disconnected
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::sendDisplayCurrentState
TEST.NEW
TEST.NAME:T2_sendDisplayCurrentState_disconnected
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::sendDisplayCurrentState.p_stat_E:EBspalDisplayState_Disconnected
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::seqncrFsm

-- Test Case: T10_seqncrFsm_off_up_03
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T10_seqncrFsm_off_up_03
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_OFF
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_UP_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:1
TEST.END

-- Test Case: T11_seqncrFsm_off_up_04
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T11_seqncrFsm_off_up_04
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_OFF
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_UP_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_Error
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T12_seqncrFsm_off_up_05
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T12_seqncrFsm_off_up_05
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_OFF
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_UP_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T13_seqncrFsm_off_up_06
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T13_seqncrFsm_off_up_06
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_OFF
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_UP_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_Error
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:1
TEST.END

-- Test Case: T14_seqncrFsm_on_down_05
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T14_seqncrFsm_on_down_05
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_DOWN_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspalDisplayState_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T15_seqncrFsm_on_down_06
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T15_seqncrFsm_on_down_06
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:-1
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspalDisplayState_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:1
TEST.END

-- Test Case: T16_seqncrFsm_on_down_07
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T16_seqncrFsm_on_down_07
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_DOWN_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspalDisplayState_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:1
TEST.END

-- Test Case: T17_seqncrFsm_on_down_08
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T17_seqncrFsm_on_down_08
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_DOWN_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:1
TEST.END

-- Test Case: T18_seqncrFsm_on_error_01
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T18_seqncrFsm_on_error_01
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_TFT_ERROR_POLL
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_Error
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T19_seqncrFsm_on_error_02
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T19_seqncrFsm_on_error_02
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_TFT_ERROR_POLL
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T1_seqncrFsm_error_default
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T1_seqncrFsm_error_default
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ERROR
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:-1
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:1
TEST.END

-- Test Case: T21_seqncrFsm_on_error_05
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T21_seqncrFsm_on_error_05
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_TFT_ERROR_POLL
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:1
TEST.END

-- Test Case: T22_seqncrFsm_on_error_04
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T22_seqncrFsm_on_error_04
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_TFT_ERROR_POLL
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspalDisplayState_Disconnected
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T23_seqncrFsm_ucl_default
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T23_seqncrFsm_ucl_default
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_WAIT_FOR_UCL
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:-1
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_Error
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T24_seqncrFsm_ucl_error_01
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T24_seqncrFsm_ucl_error_01
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_WAIT_FOR_UCL
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_SYS_STATE_UP
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_Error
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T25_seqncrFsm_ucl_error_02
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T25_seqncrFsm_ucl_error_02
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_WAIT_FOR_UCL
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_SYS_STATE_UP
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_Error
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:1
TEST.END

-- Test Case: T26_seqncrFsm_ucl_on_01
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T26_seqncrFsm_ucl_on_01
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_WAIT_FOR_UCL
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_SYS_STATE_UP
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspaDisplayState_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T27_seqncrFsm_ucl_up_02
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T27_seqncrFsm_ucl_up_02
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_WAIT_FOR_UCL
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_SYS_STATE_UP
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:1
TEST.END

-- Test Case: T28_seqncrFsm_ucl_up_03
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T28_seqncrFsm_ucl_up_03
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_WAIT_FOR_UCL
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_SYS_STATE_UP
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspalDisplayState_Disconnected
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Test Case: T2_seqncrFsm_error_down_01
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T2_seqncrFsm_error_down_01
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ERROR
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_DOWN_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:0
TEST.END

-- Test Case: T3_seqncrFsm_error_down_02
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T3_seqncrFsm_error_down_02
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ERROR
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_DOWN_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:1
TEST.END

-- Test Case: T4_seqncrFsm_final_deafult
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T4_seqncrFsm_final_deafult
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:-1
TEST.END

-- Test Case: T5_seqncrFsm_init_default
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T5_seqncrFsm_init_default
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_INIT
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:-1
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:1
TEST.END

-- Test Case: T6_seqncrFsm_init_start_01
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T6_seqncrFsm_init_start_01
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_INIT
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_START
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:0
TEST.END

-- Test Case: T7_seqncrFsm_init_start_02
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T7_seqncrFsm_init_start_02
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_INIT
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_START
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:1
TEST.END

-- Test Case: T8_seqncrFsm_off_up_01
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T8_seqncrFsm_off_up_01
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_OFF
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:-1
TEST.END

-- Test Case: T9_seqncrFsm_off_up_02
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:T9_seqncrFsm_off_up_02
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_OFF
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_DISP_PWR_UP_REQ
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.p_value_E:EBspalDisplayPower_On
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_set_power.return:0
TEST.END

-- Test Case: _T20_seqncrFsmon_error_03
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::seqncrFsm
TEST.NEW
TEST.NAME:_T20_seqncrFsmon_error_03
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.mSeqncrState:STATE_DISP_ON
TEST.VALUE:display_manager_component.(cl)DisplayManagerComponent::seqncrFsm.p_evt_E:EVT_TFT_ERROR_POLL
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.p_value_EP[0]:EBspalDisplayState_Off
TEST.VALUE:uut_prototype_stubs.dk_bspal_display_get_state.return:0
TEST.END

-- Subprogram: (cl)DisplayManagerComponent::worker

-- Test Case: T1_worker_Execution_ValidConditions
TEST.UNIT:display_manager_component
TEST.SUBPROGRAM:(cl)DisplayManagerComponent::worker
TEST.NEW
TEST.NAME:T1_worker_Execution_ValidConditions
TEST.VALUE:display_manager_component.<<GLOBAL>>.(cl).DisplayManagerComponent.DisplayManagerComponent.<<constructor>>.DisplayManagerComponent(std::map<unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>, std::less<unsigned short>, std::allocator<std::pair<const unsigned short, std::function<void (dk::runtime::core::MsgDeserializer&msgDeserializer)>>>>*const,const char*const).<<call>>:0
TEST.END
