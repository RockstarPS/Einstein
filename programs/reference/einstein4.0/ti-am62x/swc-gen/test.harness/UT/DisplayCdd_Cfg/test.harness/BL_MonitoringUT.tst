-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : BL_UT
-- Unit(s) Under Test: DisplayCdd_Cfg
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: DisplayCdd_Cfg_DeInit

-- Test Case: DisplayCdd_Cfg_DeInit.001
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_Cfg_DeInit
TEST.NEW
TEST.NAME:DisplayCdd_Cfg_DeInit.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.END

-- Subprogram: DisplayCdd_Cfg_Init

-- Test Case: DisplayCdd_Cfg_Init.001
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_Cfg_Init
TEST.NEW
TEST.NAME:DisplayCdd_Cfg_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.END

-- Subprogram: DisplayCdd_Cfg_PreInitCheck

-- Test Case: DisplayCdd_Cfg_PreInitCheck.001
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_Cfg_PreInitCheck
TEST.NEW
TEST.NAME:DisplayCdd_Cfg_PreInitCheck.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.END

-- Subprogram: DisplayCdd_TIMainFunction

-- Test Case: DisplayCdd_TIMainFunction.001
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_On_Debounce:5
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_Off_Debounce:5
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.002
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayInitCheck: User code needed
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].RequesterPowerState:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvCdd_Waittime:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].FaultStatus:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.displayId:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.PwmErrorStatus:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_On_Debounce:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_Off_Debounce:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_FaultHandled:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_Cfg_PreInitCheck.return:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarInit.DeviceIndex:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarDeInit.DeviceIndex:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ModuleId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.InstanceId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ApiId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ErrorId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data[0].displayId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data[0].state:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data[0].displayId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data[0].state:<<MAX>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.OutputId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.OutputSignal:<<MAX>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.ErrorStatus:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.PwmId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.Pwm_Duty:<<MAX>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.ErrorStatus:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.device:<<MAX>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.request:<<MAX>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.device:<<MAX>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.status:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.return:<<MAX>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.faultId:<<MAX>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.FaultStatus:<<MAX>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.LogData:"<<MAX>>"
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.LogLength:<<MAX>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.return:<<MAX>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.003
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.003
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayInitCheck: User code needed
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].RequesterPowerState:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvCdd_Waittime:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].FaultStatus:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.displayId:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.PwmErrorStatus:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_On_Debounce:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_Off_Debounce:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_FaultHandled:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_Cfg_PreInitCheck.return:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarInit.DeviceIndex:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarDeInit.DeviceIndex:<<MID>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MID>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ModuleId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.InstanceId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ApiId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ErrorId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data[0].displayId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data[0].state:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data[0].displayId:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data[0].state:<<MID>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.OutputId:<<MID>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.OutputSignal:<<MID>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.ErrorStatus:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputId:<<MID>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.PwmId:<<MID>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.Pwm_Duty:<<MID>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.ErrorStatus:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.device:<<MID>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.request:<<MID>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.device:<<MID>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.status:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.return:<<MID>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.faultId:<<MID>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.FaultStatus:<<MID>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.LogData:"<<MID>>"
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.LogLength:<<MID>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.return:<<MID>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.004
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.004
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayInitCheck: User code needed
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].RequesterPowerState:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvCdd_Waittime:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].FaultStatus:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.displayId:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.PwmErrorStatus:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_On_Debounce:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_Off_Debounce:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_FaultHandled:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_Cfg_PreInitCheck.return:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarInit.DeviceIndex:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarDeInit.DeviceIndex:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ModuleId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.InstanceId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ApiId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.ErrorId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Det_ReportError.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data[0].displayId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.data[0].state:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data:<<malloc 1>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data[0].displayId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.data[0].state:<<MIN>>
TEST.VALUE:uut_prototype_stubs.Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.OutputId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.OutputSignal:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.ErrorStatus:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.PwmId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.Pwm_Duty:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.ErrorStatus:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.IoHwAb_Pwm_SetDuty.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.device:<<MIN>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.request:<<MIN>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_RequestPower.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.device:<<MIN>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.status:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.return:<<MIN>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.faultId:<<MIN>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.FaultStatus:<<MIN>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.LogData:"<<MIN>>"
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.LogLength:<<MIN>>
TEST.VALUE:uut_prototype_stubs.FltM_ReportFault.return:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.005
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.005
TEST.BASIS_PATH:1 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:7
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.006
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.006
TEST.BASIS_PATH:2 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayIdleState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.007
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.007
TEST.BASIS_PATH:3 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayEnableState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.status[0]:2
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.008
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.008
TEST.BASIS_PATH:4 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayEnableState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.009
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.009
TEST.BASIS_PATH:5 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayPowerWaitState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.010
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.010
TEST.BASIS_PATH:6 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayPowerWaitState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal[0]:1
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.011
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.011
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayPowerWaitState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal[0]:0
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.012
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.012
TEST.BASIS_PATH:7 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayPowerWaitState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.013
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.013
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayPowerWaitState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal[0]:1
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.014
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.014
TEST.BASIS_PATH:8 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eDisplayPowerWaitState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Displaystatus.state:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.015
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.015
TEST.BASIS_PATH:9 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightEnableState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.016
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.016
TEST.BASIS_PATH:10 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightEnableState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.EcuPowerM_GetDeviceStatus.status[0]:2
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.017
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.017
TEST.BASIS_PATH:11 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightFaultState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.return:1
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.018
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.018
TEST.BASIS_PATH:12 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightFaultState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.019
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.019
TEST.BASIS_PATH:13 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightRecoveryState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.return:1
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.020
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.020
TEST.BASIS_PATH:14 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightRecoveryState
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_DOut_SetOutputPin.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.021
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.021
TEST.BASIS_PATH:15 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MIN>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.022
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.022
TEST.BASIS_PATH:16 of 21
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:1
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.023
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.023
TEST.BASIS_PATH:17 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.024
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.024
TEST.BASIS_PATH:18 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.025
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.025
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_Off_Debounce:5
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal[0]:1
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.026
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.026
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_On_Debounce:5
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal[0]:1
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.027
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.027
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_Off_Debounce:5
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.028
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.028
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_On_Debounce:5
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_FaultHandled:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal[0]:1
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.029
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.029
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_Off_Debounce:5
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_FaultHandled:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.030
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.030
TEST.BASIS_PATH:19 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.031
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.031
TEST.BASIS_PATH:20 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.032
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.032
TEST.BASIS_PATH:21 of 21 (partial)
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightMonitorState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.033
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.033
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightFaultState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_On_Debounce:5
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_FaultHandled:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.InputSignal[0]:1
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Test Case: DisplayCdd_TIMainFunction.034
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayCdd_TIMainFunction
TEST.NEW
TEST.NAME:DisplayCdd_TIMainFunction.034
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.DisplayDrvInfo[0].DisplayDrvStateMachine:eBackLightRecoveryState
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.debounce_Interval_Check:<<MAX>>
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_Off_Debounce:5
TEST.VALUE:DisplayCdd_Cfg.<<GLOBAL>>.Bl_FaultHandled:1
TEST.VALUE:DisplayCdd_Cfg.DisplayCdd_TIMainFunction.DeviceIndex:<<MIN>>
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.ErrorStatus[0]:12
TEST.VALUE:uut_prototype_stubs.IoHwAb_GetProcessedInput.return:0
TEST.END

-- Subprogram: DisplayDrvCdd_HannstarDeInit

-- Test Case: DisplayDrvCdd_HannstarDeInit.001
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayDrvCdd_HannstarDeInit
TEST.NEW
TEST.NAME:DisplayDrvCdd_HannstarDeInit.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarDeInit.DeviceIndex:2
TEST.END

-- Test Case: DisplayDrvCdd_HannstarDeInit.002
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayDrvCdd_HannstarDeInit
TEST.NEW
TEST.NAME:DisplayDrvCdd_HannstarDeInit.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarDeInit.DeviceIndex:0
TEST.END

-- Subprogram: DisplayDrvCdd_HannstarInit

-- Test Case: DisplayDrvCdd_HannstarInit.001
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayDrvCdd_HannstarInit
TEST.NEW
TEST.NAME:DisplayDrvCdd_HannstarInit.001
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.END

-- Test Case: DisplayDrvCdd_HannstarInit.002
TEST.UNIT:DisplayCdd_Cfg
TEST.SUBPROGRAM:DisplayDrvCdd_HannstarInit
TEST.NEW
TEST.NAME:DisplayDrvCdd_HannstarInit.002
TEST.NOTES:
SoftwareArchitecture::TI::CDD::DisplayCdd_Cfg::BL_Monitoring_Class_Diagram
Requirement ID: Requirement_PE4TI29141-9340
TEST.END_NOTES:
TEST.VALUE:DisplayCdd_Cfg.DisplayDrvCdd_HannstarInit.DeviceIndex:2
TEST.END
