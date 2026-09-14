-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : VIEW-IILUMINATION-UTP
-- Unit(s) Under Test: View_Illumination
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: Brightness_Mode_Process

-- Test Case: Brightness_Mode_Process.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:Brightness_Mode_Process
TEST.NEW
TEST.NAME:Brightness_Mode_Process.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1345
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1346
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1347
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1341
TEST.VALUE:View_Illumination.Brightness_Mode_Process.l_PWMData[0]:1
TEST.EXPECTED:View_Illumination.Brightness_Mode_Process.l_PWMData[0]:1
TEST.END

-- Subprogram: Bulb_Mode_Process

-- Test Case: Bulb_Mode_Process.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:Bulb_Mode_Process
TEST.NEW
TEST.NAME:Bulb_Mode_Process.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1345
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1346
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1347
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1341
TEST.VALUE:View_Illumination.Bulb_Mode_Process.l_PWMData[0]:1
TEST.EXPECTED:View_Illumination.Bulb_Mode_Process.l_PWMData[0]:1
TEST.END

-- Subprogram: CView_Illumination_Impl_MainFunction

-- Test Case: CView_Illumination_Impl_MainFunction.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CView_Illumination_Impl_MainFunction
TEST.NEW
TEST.NAME:CView_Illumination_Impl_MainFunction.001
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.END

-- Subprogram: CView_Illumination_Impl_OnCommand

-- Test Case: CView_Illumination_Impl_OnCommand.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CView_Illumination_Impl_OnCommand
TEST.NEW
TEST.NAME:CView_Illumination_Impl_OnCommand.001
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.EXPECTED:View_Illumination.CView_Illumination_Impl_OnCommand.Cmd:0
TEST.EXPECTED:View_Illumination.CView_Illumination_Impl_OnCommand.return:0
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation.001
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.EXPECTED:View_Illumination.CmpActivation.return:0
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive.001
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.EXPECTED:View_Illumination.CmpDeActivation.return:0
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit.001
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.EXPECTED:View_Illumination.CmpDeInit.return:0
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag.001
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.EXPECTED:View_Illumination.CmpDiag.return:0
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn.001
TEST.VALUE:View_Illumination.<<GLOBAL>>.fl_View_Ip.Duty_Out[0]:1
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.fl_View_Ip.Duty_Out[0]:1
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit.001
TEST.END

-- Subprogram: Dial_Mode_Process

-- Test Case: Dial_Mode_Process.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:Dial_Mode_Process
TEST.NEW
TEST.NAME:Dial_Mode_Process.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1345
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1346
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1347
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1341
TEST.VALUE:View_Illumination.Dial_Mode_Process.l_PWMData[0]:2
TEST.EXPECTED:View_Illumination.Dial_Mode_Process.l_PWMData[0]:2
TEST.END

-- Subprogram: Display_Mode_Process

-- Test Case: Display_Mode_Process.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:Display_Mode_Process
TEST.NEW
TEST.NAME:Display_Mode_Process.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1341
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1345
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1346
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1347
TEST.VALUE:View_Illumination.Display_Mode_Process.l_PWMData[0]:1
TEST.EXPECTED:View_Illumination.Display_Mode_Process.l_PWMData[0]:1
TEST.END

-- Subprogram: Duty_Mode_Process

-- Test Case: Duty_Mode_Process.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:Duty_Mode_Process
TEST.NEW
TEST.NAME:Duty_Mode_Process.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1345
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1346
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1347
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1341
TEST.VALUE:View_Illumination.Duty_Mode_Process.l_PWMData[0]:0
TEST.EXPECTED:View_Illumination.Duty_Mode_Process.l_PWMData[0]:0
TEST.END

-- Subprogram: Input_Processing

-- Test Case: Input_Processing.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:Input_Processing
TEST.NEW
TEST.NAME:Input_Processing.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1340
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.END

-- Subprogram: LED_Mode_Process

-- Test Case: LED_Mode_Process.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:LED_Mode_Process
TEST.NEW
TEST.NAME:LED_Mode_Process.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1341
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1345
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1346
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1347
TEST.VALUE:View_Illumination.LED_Mode_Process.l_PWMData[0]:1
TEST.EXPECTED:View_Illumination.LED_Mode_Process.l_PWMData[0]:1
TEST.END

-- Subprogram: Process_View_Illumination

-- Test Case: Process_View_Illumination.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:Process_View_Illumination
TEST.NEW
TEST.NAME:Process_View_Illumination.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.EXPECTED:View_Illumination.<<GLOBAL>>.CmpState:8
TEST.END

-- Subprogram: RGB_Mode_Process

-- Test Case: RGB_Mode_Process.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:RGB_Mode_Process
TEST.NEW
TEST.NAME:RGB_Mode_Process.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1341
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1345
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1346
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1347
TEST.VALUE:View_Illumination.RGB_Mode_Process.l_PWMData[0]:1
TEST.EXPECTED:View_Illumination.RGB_Mode_Process.l_PWMData[0]:1
TEST.END

-- Subprogram: Telltale_Mode_Process

-- Test Case: Telltale_Mode_Process.001
TEST.UNIT:View_Illumination
TEST.SUBPROGRAM:Telltale_Mode_Process
TEST.NEW
TEST.NAME:Telltale_Mode_Process.001
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1341
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1343
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1345
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1346
TEST.REQUIREMENT_KEY:https://visteon.atlassian.net/browse/DICMBD-1347
TEST.VALUE:View_Illumination.Telltale_Mode_Process.l_PWMData[0]:2
TEST.EXPECTED:View_Illumination.Telltale_Mode_Process.l_PWMData[0]:2
TEST.END
