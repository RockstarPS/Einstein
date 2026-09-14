-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : CTRL-ILLUMINATION
-- Unit(s) Under Test: Ctrl_Illumination
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: BrightnessMode_Control

-- Test Case: BrightnessMode_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:BrightnessMode_Control
TEST.NEW
TEST.NAME:BrightnessMode_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.fl_Input_Data.Brightness_Control[0].Status:1
TEST.END

-- Subprogram: BulbMode_Control

-- Test Case: BulbMode_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:BulbMode_Control
TEST.NEW
TEST.NAME:BulbMode_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.fl_Input_Data.Bulb_Control[0].Status:1
TEST.END

-- Subprogram: CCtrl_Illumination_Impl_MainFunction

-- Test Case: CCtrl_Illumination_Impl_MainFunction.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CCtrl_Illumination_Impl_MainFunction
TEST.NEW
TEST.NAME:CCtrl_Illumination_Impl_MainFunction.001
TEST.END

-- Subprogram: CCtrl_Illumination_Impl_OnCommand

-- Test Case: CCtrl_Illumination_Impl_OnCommand.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CCtrl_Illumination_Impl_OnCommand
TEST.NEW
TEST.NAME:CCtrl_Illumination_Impl_OnCommand.001
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.EXPECTED:Ctrl_Illumination.CmpDeActivation.return:0
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.EXPECTED:Ctrl_Illumination.CmpDeInit.return:0
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.EXPECTED:Ctrl_Illumination.CmpDiag.return:0
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.EXPECTED:Ctrl_Illumination.CmpDiagReturn.return:0
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.EXPECTED:Ctrl_Illumination.CmpInit.return:0
TEST.END

-- Subprogram: Default_control

-- Test Case: Default_control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Default_control
TEST.NEW
TEST.NAME:Default_control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1337
TEST.END

-- Subprogram: DialMode_Control

-- Test Case: DialMode_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:DialMode_Control
TEST.NEW
TEST.NAME:DialMode_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.fl_Input_Data.Dial_Control[0].Status:1
TEST.END

-- Subprogram: DisplayMode_Control

-- Test Case: DisplayMode_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:DisplayMode_Control
TEST.NEW
TEST.NAME:DisplayMode_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.fl_Input_Data.Display_Control[0].Status:1
TEST.END

-- Subprogram: DutyMode_Control

-- Test Case: DutyMode_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:DutyMode_Control
TEST.NEW
TEST.NAME:DutyMode_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Prev_Duty_Mode:<<malloc 2>>
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Prev_Duty_Mode:"2"
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.fl_Input_Data.Duty_Control[0].Status:1
TEST.END

-- Subprogram: Illumination_Data_handle

-- Test Case: Illumination_Data_handle.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Illumination_Data_handle
TEST.NEW
TEST.NAME:Illumination_Data_handle.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Switching_Control_logic[1]:Set_PWM_to_Off
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Switching_Control_logic[3]:Timing_control
TEST.END

-- Subprogram: Input_Processing

-- Test Case: Input_Processing.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Input_Processing
TEST.NEW
TEST.NAME:Input_Processing.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1340
TEST.END

-- Subprogram: LEDMode_Control

-- Test Case: LEDMode_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:LEDMode_Control
TEST.NEW
TEST.NAME:LEDMode_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.fl_Input_Data.LED_Control[0].Status:1
TEST.END

-- Subprogram: Mode_Timer_Control

-- Test Case: Mode_Timer_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Mode_Timer_Control
TEST.NEW
TEST.NAME:Mode_Timer_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.Curr_val:2
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.TimerVal:1
TEST.END

-- Test Case: Mode_Timer_Control.002
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Mode_Timer_Control
TEST.NEW
TEST.NAME:Mode_Timer_Control.002
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.Curr_val:2
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.TimerVal:1
TEST.END

-- Test Case: Mode_Timer_Control.003
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Mode_Timer_Control
TEST.NEW
TEST.NAME:Mode_Timer_Control.003
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.STUB:Ctrl_Illumination.handle_timer
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Mode_Timer_Control.l_ModeCtrl_Ip.Curr_val:2
TEST.VALUE:Ctrl_Illumination.handle_timer.return:1
TEST.END

-- Subprogram: Output_Processing

-- Test Case: Output_Processing.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Output_Processing
TEST.NEW
TEST.NAME:Output_Processing.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1332
TEST.END

-- Subprogram: RGBMode_Control

-- Test Case: RGBMode_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:RGBMode_Control
TEST.NEW
TEST.NAME:RGBMode_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.fl_Input_Data.RGB_Control[0].Status:1
TEST.END

-- Subprogram: Slicing_control

-- Test Case: Slicing_control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Slicing_control
TEST.NEW
TEST.NAME:Slicing_control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Output_Table[1]:<<malloc 7>>
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Output_Table[1][0][3][5]:30
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Index_Ip.table_index:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Index_Ip.Illum_index:0
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode:3
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm:30
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode:3
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Level:5
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Status:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.switching_control:0
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.Ill_Pwm_Data:<<malloc 1>>
TEST.END

-- Test Case: Slicing_control.002
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Slicing_control
TEST.NEW
TEST.NAME:Slicing_control.002
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Output_Table[1]:<<malloc 7>>
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Output_Table[1][0][3][5]:30
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Index_Ip.table_index:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Index_Ip.Illum_index:0
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode:3
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm:30
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode:4
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Level:5
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Status:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.switching_control:0
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal:1
TEST.VALUE:Ctrl_Illumination.Slicing_control.Ill_Pwm_Data:<<malloc 1>>
TEST.END

-- Subprogram: Step_Timer_Control

-- Test Case: Step_Timer_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Step_Timer_Control
TEST.NEW
TEST.NAME:Step_Timer_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.Curr_val:2
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.TimerVal:1
TEST.END

-- Test Case: Step_Timer_Control.002
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Step_Timer_Control
TEST.NEW
TEST.NAME:Step_Timer_Control.002
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.Curr_val:2
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.TimerVal:1
TEST.END

-- Test Case: Step_Timer_Control.003
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Step_Timer_Control
TEST.NEW
TEST.NAME:Step_Timer_Control.003
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.STUB:Ctrl_Illumination.handle_timer
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Step_Timer_Control.l_StepCtrl_Ip.Curr_val:2
TEST.VALUE:Ctrl_Illumination.handle_timer.return:1
TEST.END

-- Subprogram: TelltaleMode_Control

-- Test Case: TelltaleMode_Control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:TelltaleMode_Control
TEST.NEW
TEST.NAME:TelltaleMode_Control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1334
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.fl_Input_Data.Telltale_Control[0].Status:1
TEST.END

-- Subprogram: Timing_control

-- Test Case: Timing_control.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Timing_control
TEST.NEW
TEST.NAME:Timing_control.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.STUB:Ctrl_Illumination.CCtrl_Illumination_Impl_MainFunction
TEST.STUB:Ctrl_Illumination.CCtrl_Illumination_Impl_OnCommand
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Switching_Control_logic[0]:Slicing_control
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Switching_Control_logic[1]:Timing_control
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Switching_Control_logic[2]:Default_control
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Switching_Control_logic[3]:Off_mode
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Index_Ip.table_index:8
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Index_Ip.Illum_index:0
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Mode:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Curr_Ip.Curr_Pwm:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Mode:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Level:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.Status:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Ctrl_Ip.switching_control:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.Curr_val:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_ModeCtrl_Ip.TimerVal:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerID:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.Prev_val:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.Curr_val:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_StepCtrl_Ip.TimerVal:1
TEST.VALUE:Ctrl_Illumination.Timing_control.Ill_Pwm_Data:<<malloc 1>>
TEST.VALUE:Ctrl_Illumination.Timing_control.Ill_Pwm_Data[0]:0
TEST.EXPECTED:Ctrl_Illumination.Timing_control.Ill_Pwm_Data[0]:0
TEST.END

-- Test Case: Timing_control.003
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:Timing_control
TEST.NEW
TEST.NAME:Timing_control.003
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.STUB:Ctrl_Illumination.handle_timer
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Prev_Mode[7].array:<<malloc 1>>
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Prev_Mode[7].array[0]:1
TEST.VALUE:Ctrl_Illumination.<<GLOBAL>>.Prev_Mode[7].size:1
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Index_Ip.table_index:7
TEST.VALUE:Ctrl_Illumination.Timing_control.l_SwitchCtrl_Ip.l_Index_Ip.Illum_index:1
TEST.VALUE:Ctrl_Illumination.Timing_control.Ill_Pwm_Data:<<malloc 1>>
TEST.VALUE:Ctrl_Illumination.handle_timer.return:1
TEST.END

-- Subprogram: handle_slew

-- Test Case: handle_slew.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:1
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:2
TEST.END

-- Test Case: handle_slew.002
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.002
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:1
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:3
TEST.VALUE:Ctrl_Illumination.handle_slew.slewrate:2
TEST.END

-- Test Case: handle_slew.003
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.003
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:3
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:1
TEST.VALUE:Ctrl_Illumination.handle_slew.slewrate:2
TEST.END

-- Test Case: handle_slew.004
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.004
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:3
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:1
TEST.VALUE:Ctrl_Illumination.handle_slew.slewrate:4
TEST.END

-- Test Case: handle_slew.005
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.005
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:10
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:5
TEST.VALUE:Ctrl_Illumination.handle_slew.slewrate:4
TEST.END

-- Test Case: handle_slew.006
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.006
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:1001
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:1001
TEST.VALUE:Ctrl_Illumination.handle_slew.slewrate:1001
TEST.END

-- Test Case: handle_slew.007
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.007
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:1000
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:1001
TEST.VALUE:Ctrl_Illumination.handle_slew.slewrate:1001
TEST.END

-- Test Case: handle_slew.008
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.008
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:1000
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:1000
TEST.VALUE:Ctrl_Illumination.handle_slew.slewrate:1001
TEST.EXPECTED:Ctrl_Illumination.handle_slew.return:1000
TEST.END

-- Test Case: handle_slew.009
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_slew
TEST.NEW
TEST.NAME:handle_slew.009
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1336
TEST.VALUE:Ctrl_Illumination.handle_slew.current_val:990
TEST.VALUE:Ctrl_Illumination.handle_slew.target_val:990
TEST.VALUE:Ctrl_Illumination.handle_slew.slewrate:1
TEST.EXPECTED:Ctrl_Illumination.handle_slew.return:990
TEST.END

-- Subprogram: handle_timer

-- Test Case: handle_timer.001
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_timer
TEST.NEW
TEST.NAME:handle_timer.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.VALUE:Ctrl_Illumination.handle_timer.timerId:2
TEST.VALUE:Ctrl_Illumination.handle_timer.loadtime:2
TEST.VALUE:Ctrl_Illumination.handle_timer.return:0
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsStarted.IsStarted:"1"
TEST.END

-- Test Case: handle_timer.002
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_timer
TEST.NEW
TEST.NAME:handle_timer.002
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.VALUE:Ctrl_Illumination.handle_timer.timerId:2
TEST.VALUE:Ctrl_Illumination.handle_timer.loadtime:2
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.hTimer:2
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.Timeout:2
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.IsElapsed[0]:0
TEST.EXPECTED:uut_prototype_stubs.TmExt_Timer_IsElapsed.hTimer:2
TEST.EXPECTED:uut_prototype_stubs.TmExt_Timer_IsElapsed.Timeout:2
TEST.EXPECTED:uut_prototype_stubs.TmExt_Timer_IsElapsed.IsElapsed[0]:0
TEST.END

-- Test Case: handle_timer.003
TEST.UNIT:Ctrl_Illumination
TEST.SUBPROGRAM:handle_timer
TEST.NEW
TEST.NAME:handle_timer.003
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1335
TEST.VALUE:Ctrl_Illumination.handle_timer.timerId:2
TEST.VALUE:Ctrl_Illumination.handle_timer.loadtime:0
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.hTimer:2
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.Timeout:0
TEST.VALUE:uut_prototype_stubs.TmExt_Timer_IsElapsed.IsElapsed[0]:1
TEST.EXPECTED:uut_prototype_stubs.TmExt_Timer_IsElapsed.hTimer:2
TEST.EXPECTED:uut_prototype_stubs.TmExt_Timer_IsElapsed.Timeout:0
TEST.END
