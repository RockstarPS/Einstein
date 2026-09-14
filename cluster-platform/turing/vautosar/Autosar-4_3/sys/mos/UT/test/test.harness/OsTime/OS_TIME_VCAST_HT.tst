-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_TIME_VCAST_HT
-- Unit(s) Under Test: OsTime
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: OsTime

-- Subprogram: osInitAlarms

-- Test Case: osInitAlarms.001
TEST.UNIT:OsTime
TEST.SUBPROGRAM:osInitAlarms
TEST.NEW
TEST.NAME:osInitAlarms.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7609
TEST.END_NOTES:
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[1][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[4]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[4][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[5]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[5][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[6]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[6][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[7]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[7][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[8]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[8][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[9]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[9][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[10]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[10][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[11]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[11][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[12]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[12][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[13]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[13][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[14]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[14][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[15]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[15][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[16]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[16][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[17]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[17][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[18]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[18][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[19]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[19][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[20]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[20][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[21]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[21][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[22]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[22][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[23]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[23][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[24]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[24][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[25]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[25][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[26]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[26][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[27]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[27][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[28]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[28][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[29]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[29][0].OsAlarmParamRef:<<malloc 1>>
TEST.END

-- Subprogram: osInitTimer

-- Test Case: osInitTimer.001
TEST.UNIT:OsTime
TEST.SUBPROGRAM:osInitTimer
TEST.NEW
TEST.NAME:osInitTimer.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7609
TEST.END_NOTES:
TEST.END

-- Subprogram: osProcessAlarms

-- Test Case: osProcessAlarms.001
TEST.UNIT:OsTime
TEST.SUBPROGRAM:osProcessAlarms
TEST.NEW
TEST.NAME:osProcessAlarms.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7609
TEST.END_NOTES:
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmTime:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[0][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[1][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[1][0].OsAlarmParamRef[0].AlarmTime:0
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[1][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2][0].OsAlarmActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2][0].OsAlarmActivateTaskRef[0].TasksID:0
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2][0].OsAlarmParamRef[0].AlarmTime:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2][0].OsAlarmCallback:osSysErrAssert
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[2][0].OsAlarmAction:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmActivateTaskRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmActivateTaskRef[0].TasksID:0
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmParamRef[0].AlarmCyclicTime:10
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmParamRef[0].AlarmTime:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmTask:0
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[3][0].OsAlarmAction:2
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[4]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[4][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[4][0].OsAlarmParamRef[0].AlarmTime:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[4][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[4][0].OsAlarmTask:0
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[4][0].OsAlarmAction:3
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[5]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[5][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[5][0].OsAlarmParamRef[0].AlarmTime:10
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[5][0].OsAlarmParamRef[0].AlarmActivated:1
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[6]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[6][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[7]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[7][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[8]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[8][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[9]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[9][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[10]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[10][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[11]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[11][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[12]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[12][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[13]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[13][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[14]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[14][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[15]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[15][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[16]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[16][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[17]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[17][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[18]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[18][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[19]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[19][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[20]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[20][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[21]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[21][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[22]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[22][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[23]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[23][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[24]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[24][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[25]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[25][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[26]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[26][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[27]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[27][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[28]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[28][0].OsAlarmParamRef:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[29]:<<malloc 1>>
TEST.VALUE:OsTime.<<GLOBAL>>.AlarmRefConfig[29][0].OsAlarmParamRef:<<malloc 1>>
TEST.END

-- Subprogram: osTimerInterruptfunc

-- Test Case: osTimerInterruptfunc.001
TEST.UNIT:OsTime
TEST.SUBPROGRAM:osTimerInterruptfunc
TEST.NEW
TEST.NAME:osTimerInterruptfunc.001
TEST.STUB:OsTime.osProcessAlarms
TEST.END
