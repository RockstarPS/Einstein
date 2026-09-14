-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : VIEW_ILLUMINATION_EXTN
-- Unit(s) Under Test: View_Illumination_Extn
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: CAN_Data_Out

-- Test Case: CAN_Data_Out.001
TEST.UNIT:View_Illumination_Extn
TEST.SUBPROGRAM:CAN_Data_Out
TEST.NEW
TEST.NAME:CAN_Data_Out.001
TEST.VALUE:View_Illumination_Extn.CAN_Data_Out.data:1
TEST.VALUE:View_Illumination_Extn.CAN_Data_Out.type:1
TEST.EXPECTED:View_Illumination_Extn.CAN_Data_Out.data:1
TEST.EXPECTED:View_Illumination_Extn.CAN_Data_Out.type:1
TEST.END

-- Test Case: CAN_Data_Out.002
TEST.UNIT:View_Illumination_Extn
TEST.SUBPROGRAM:CAN_Data_Out
TEST.NEW
TEST.NAME:CAN_Data_Out.002
TEST.VALUE:View_Illumination_Extn.CAN_Data_Out.data:256
TEST.VALUE:View_Illumination_Extn.CAN_Data_Out.type:1
TEST.EXPECTED:View_Illumination_Extn.CAN_Data_Out.data:256
TEST.EXPECTED:View_Illumination_Extn.CAN_Data_Out.type:1
TEST.END

-- Subprogram: IoHwAb_Data_Out

-- Test Case: IoHwAb_Data_Out.001
TEST.UNIT:View_Illumination_Extn
TEST.SUBPROGRAM:IoHwAb_Data_Out
TEST.NEW
TEST.NAME:IoHwAb_Data_Out.001
TEST.VALUE:View_Illumination_Extn.IoHwAb_Data_Out.data:1
TEST.VALUE:View_Illumination_Extn.IoHwAb_Data_Out.type:1
TEST.EXPECTED:View_Illumination_Extn.IoHwAb_Data_Out.data:1
TEST.EXPECTED:View_Illumination_Extn.IoHwAb_Data_Out.type:1
TEST.END

-- Subprogram: UCL_Data_Out

-- Test Case: UCL_Data_Out.001
TEST.UNIT:View_Illumination_Extn
TEST.SUBPROGRAM:UCL_Data_Out
TEST.NEW
TEST.NAME:UCL_Data_Out.001
TEST.VALUE:View_Illumination_Extn.UCL_Data_Out.data:1
TEST.VALUE:View_Illumination_Extn.UCL_Data_Out.type:1
TEST.EXPECTED:View_Illumination_Extn.UCL_Data_Out.data:1
TEST.EXPECTED:View_Illumination_Extn.UCL_Data_Out.type:1
TEST.END

-- Subprogram: ViewIllumination_InputAdapter

-- Test Case: ViewIllumination_InputAdapter.001
TEST.UNIT:View_Illumination_Extn
TEST.SUBPROGRAM:ViewIllumination_InputAdapter
TEST.NEW
TEST.NAME:ViewIllumination_InputAdapter.001
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip:<<malloc 1>>
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip[0].Duty_Out[0]:1
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip[0].Brightness_Out[0]:1
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip[0].RGB_Out[0]:1
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip[0].Bulb_Out[0]:1
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip[0].LED_Out[0]:1
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip[0].Dial_Out[0]:1
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip[0].Display_Out[0]:1
TEST.VALUE:View_Illumination_Extn.ViewIllumination_InputAdapter.l_View_Ip[0].Telltale_Out[0]:1
TEST.END
