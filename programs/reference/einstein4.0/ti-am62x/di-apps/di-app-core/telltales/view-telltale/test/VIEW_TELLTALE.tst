-- VectorCAST 20.sp7 (04/21/21)
-- Test Case Script
--
-- Environment    : VIEW_TELLTALE
-- Unit(s) Under Test: View_Telltale
--
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:REMOVED_CL_PREFIX
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
TEST.SCRIPT_FEATURE:VCAST_MAIN_NOT_RENAMED
--

-- Subprogram: CView_Telltale_Impl_MainFunction

-- Test Case: CView_Telltale_Impl_MainFunction.001
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CView_Telltale_Impl_MainFunction
TEST.NEW
TEST.NAME:CView_Telltale_Impl_MainFunction.001
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[2]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[0]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[1]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[2]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[3]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[4]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[5]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[6]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[7]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[8]:1
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[9]:1
TEST.END

-- Test Case: CView_Telltale_Impl_MainFunction.002
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CView_Telltale_Impl_MainFunction
TEST.NEW
TEST.NAME:CView_Telltale_Impl_MainFunction.002
TEST.END

-- Subprogram: CView_Telltale_Impl_OnCommand

-- Test Case: CView_Telltale_Impl_OnCommand.001
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CView_Telltale_Impl_OnCommand
TEST.NEW
TEST.NAME:CView_Telltale_Impl_OnCommand.001
TEST.VALUE:View_Telltale.CView_Telltale_Impl_OnCommand.Cmd:1
TEST.VALUE:View_Telltale.CView_Telltale_Impl_OnCommand.return:0
TEST.END

-- Subprogram: CmpActivation

-- Test Case: Return_value_Testcase
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:Return_value_Testcase
TEST.VALUE:View_Telltale.CmpActivation.return:MACRO=TT_TURN_OFF
TEST.END

-- Subprogram: CmpActive

-- Test Case: Telltale_Input_status_On_Off_testcase
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:Telltale_Input_status_On_Off_testcase
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[0]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[1]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[2]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[3]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[4]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[5]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[6]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[7]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[8]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[9]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[10]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[11]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[12]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[13]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[14]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[15]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[16]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[17]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[18]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[19]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[20]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[21]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[22]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.CmpActive.return:MACRO=TT_TURN_OFF
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation.001
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation.001
TEST.VALUE:View_Telltale.CmpDeActivation.return:MACRO=TT_TURN_OFF
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: Return_Value_Testcase
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:Return_Value_Testcase
TEST.VALUE:View_Telltale.CmpDeInit.return:MACRO=TT_TURN_OFF
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag_Return_value
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag_Return_value
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn_return_value
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn_return_value
TEST.VALUE:View_Telltale.CmpDiagReturn.return:MACRO=TT_TURN_OFF
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit_Return_value
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit_Return_value
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[0]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[1]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[2]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[3]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[4]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[5]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[6]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[7]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[8]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[9]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[10]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[11]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[12]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[13]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[14]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[15]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[16]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[17]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[18]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[19]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[20]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[21]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[22]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.CmpInit.return:MACRO=TT_TURN_OFF
TEST.END

-- Subprogram: ViewTelltale_SendTelltaleStatus

-- Test Case: ALL_ITELLTALE_NDEX_OFF_STATE
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:ViewTelltale_SendTelltaleStatus
TEST.NEW
TEST.NAME:ALL_ITELLTALE_NDEX_OFF_STATE
TEST.VALUE:View_Telltale.ViewTelltale_SendTelltaleStatus.index:MACRO=TT_ABS_INDEX,MACRO=TT_ADAS_INDEX,MACRO=TT_AIRBAG_INDEX,MACRO=TT_AUTO_HIGH_BEAM_INDEX,MACRO=TT_BRAKE_RED_INDEX,MACRO=TT_BRAKE_HOLD_INDEX,MACRO=TT_BRAKE_HOLD_STANDBY_INDEX,MACRO=TT_BRAKE_YELLOW_INDEX,MACRO=TT_PARKING_BRAKE_INDEX,MACRO=TT_FUEL_INDEX,MACRO=TT_FFOG_INDEX,MACRO=TT_HEAD_INDEX,MACRO=TT_HIGH_BEAM_INDEX,MACRO=TT_PCS_OFF_INDEX,MACRO=TT_READY_INDEX,MACRO=TT_RFOG_INDEX,MACRO=TT_SEAT_BELT_INDEX,MACRO=TT_TAIL_LIGHT_INDEX,MACRO=TT_TRACTION_CTRL_INDEX,MACRO=TT_TURN_HAZARD_RIGHT_INDEX,MACRO=TT_TURN_HAZARD_LEFT_INDEX,MACRO=TT_VCS_OFF_INDEX,MACRO=TT_EWT_INDEX
TEST.VALUE:View_Telltale.ViewTelltale_SendTelltaleStatus.TT_status:(23)MACRO=TT_TURN_OFF
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[0]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[1]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[2]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[3]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[4]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[5]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[6]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[7]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[8]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[9]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[10]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[11]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[12]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[13]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[14]:0
TEST.END

-- Test Case: ALL_TELLTALE_INDEX_ON_STATE
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:ViewTelltale_SendTelltaleStatus
TEST.NEW
TEST.NAME:ALL_TELLTALE_INDEX_ON_STATE
TEST.VALUE:View_Telltale.ViewTelltale_SendTelltaleStatus.index:MACRO=TT_ABS_INDEX,MACRO=TT_ADAS_INDEX,MACRO=TT_AIRBAG_INDEX,MACRO=TT_AUTO_HIGH_BEAM_INDEX,MACRO=TT_BRAKE_RED_INDEX,MACRO=TT_BRAKE_HOLD_INDEX,MACRO=TT_BRAKE_HOLD_STANDBY_INDEX,MACRO=TT_BRAKE_YELLOW_INDEX,MACRO=TT_PARKING_BRAKE_INDEX,MACRO=TT_FUEL_INDEX,MACRO=TT_FFOG_INDEX,MACRO=TT_HEAD_INDEX,MACRO=TT_HIGH_BEAM_INDEX,MACRO=TT_PCS_OFF_INDEX,MACRO=TT_READY_INDEX,MACRO=TT_RFOG_INDEX,MACRO=TT_SEAT_BELT_INDEX,MACRO=TT_TAIL_LIGHT_INDEX,MACRO=TT_TRACTION_CTRL_INDEX,MACRO=TT_TURN_HAZARD_RIGHT_INDEX,MACRO=TT_TURN_HAZARD_LEFT_INDEX,MACRO=TT_VCS_OFF_INDEX,MACRO=TT_EWT_INDEX
TEST.VALUE:View_Telltale.ViewTelltale_SendTelltaleStatus.TT_status:(23)MACRO=TT_TURN_ON
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[0]:255
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[1]:255
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[2]:127
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[3]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[4]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[5]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[6]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[7]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[8]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[9]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[10]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[11]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[12]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[13]:0
TEST.EXPECTED:View_Telltale.<<GLOBAL>>.TelltaleStatusData.mask[14]:0
TEST.END

-- Test Case: Telltale_Index_Exceeded_testcase
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:ViewTelltale_SendTelltaleStatus
TEST.NEW
TEST.NAME:Telltale_Index_Exceeded_testcase
TEST.VALUE:View_Telltale.ViewTelltale_SendTelltaleStatus.index:24
TEST.VALUE:View_Telltale.ViewTelltale_SendTelltaleStatus.TT_status:MACRO=TT_TURN_ON
TEST.END

-- Subprogram: WriteTTStatus

-- Test Case: All_index_Telltale_driven_type_Testcase
TEST.UNIT:View_Telltale
TEST.SUBPROGRAM:WriteTTStatus
TEST.NEW
TEST.NAME:All_index_Telltale_driven_type_Testcase
TEST.IMPORT_FAILURES:
(E) Errors from previous script import(s)
    >>> (E) @LINE: 100 TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[23]:TT_TURN_OFF
    >>>     >>> Array Index Value(s) out of range 0 to 22
    >>>     >>> Input Index was: 23
    >>> (E) @LINE: 101 TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[24]:TT_TURN_OFF
    >>>     >>> Array Index Value(s) out of range 0 to 22
    >>>     >>> Input Index was: 24
    >>> (E) @LINE: 102 TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[25]:TT_TURN_OFF
    >>>     >>> Array Index Value(s) out of range 0 to 22
    >>>     >>> Input Index was: 25
    >>> (E) @LINE: 103 TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[26]:TT_TURN_OFF
    >>>     >>> Array Index Value(s) out of range 0 to 22
    >>>     >>> Input Index was: 26
    >>> (E) @LINE: 104 TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[27]:TT_TURN_OFF
    >>>     >>> Array Index Value(s) out of range 0 to 22
    >>>     >>> Input Index was: 27
    >>> (E) @LINE: 105 TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[28]:TT_TURN_OFF
    >>>     >>> Array Index Value(s) out of range 0 to 22
    >>>     >>> Input Index was: 28
    >>> (E) @LINE: 106 TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[29]:TT_TURN_OFF
    >>>     >>> Array Index Value(s) out of range 0 to 22
    >>>     >>> Input Index was: 29
    >>> (E) @LINE: 107 TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[30]:TT_TURN_OFF
    >>>     >>> Array Index Value(s) out of range 0 to 22
    >>>     >>> Input Index was: 30
TEST.END_IMPORT_FAILURES:
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[0]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[1]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[2]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[3]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[4]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[5]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[6]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[7]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[8]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[9]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[10]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[11]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[12]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[13]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[14]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[15]:MACRO=TT_TURN_ON
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[16]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[17]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[18]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[19]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[20]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[21]:MACRO=TT_TURN_OFF
TEST.VALUE:View_Telltale.<<GLOBAL>>.TelltaleInputStatus[22]:MACRO=TT_TURN_OFF
TEST.END
