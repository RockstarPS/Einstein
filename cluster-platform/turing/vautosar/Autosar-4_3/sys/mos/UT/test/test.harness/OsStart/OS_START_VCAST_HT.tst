-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : OS_START_VCAST_HT
-- Unit(s) Under Test: OsStart
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: OsInitMemory

-- Test Case: OsInitMemory.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:OsInitMemory
TEST.NEW
TEST.NAME:OsInitMemory.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.<<GLOBAL>>.OsCoreRefConfig[0]:<<malloc 1>>
TEST.END

-- Subprogram: osFillISRStacks

-- Test Case: osFillISRStacks.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillISRStacks
TEST.NEW
TEST.NAME:osFillISRStacks.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.END

-- Test Case: osFillISRStacks.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillISRStacks
TEST.NEW
TEST.NAME:osFillISRStacks.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.END

-- Test Case: osFillISRStacks.001.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillISRStacks
TEST.NEW
TEST.NAME:osFillISRStacks.001.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.END

-- Test Case: osFillISRStacks.001.002
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillISRStacks
TEST.NEW
TEST.NAME:osFillISRStacks.001.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.END

-- Test Case: osFillISRStacks.002
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillISRStacks
TEST.NEW
TEST.NAME:osFillISRStacks.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillISRStacks.ISRId:30
TEST.END

-- Test Case: osFillISRStacks.002.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillISRStacks
TEST.NEW
TEST.NAME:osFillISRStacks.002.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillISRStacks.ISRId:30
TEST.END

-- Test Case: osFillISRStacks.002.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillISRStacks
TEST.NEW
TEST.NAME:osFillISRStacks.002.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillISRStacks.ISRId:30
TEST.END

-- Test Case: osFillISRStacks.002.002
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillISRStacks
TEST.NEW
TEST.NAME:osFillISRStacks.002.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillISRStacks.ISRId:30
TEST.END

-- Subprogram: osFillStack

-- Test Case: osFillStack.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillStack
TEST.NEW
TEST.NAME:osFillStack.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE_USER_CODE:OsStart.osFillStack.stackTop
<<OsStart.osFillStack.stackTop>> = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:OsStart.osFillStack.stackBot
<<OsStart.osFillStack.stackBot>> = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: osFillStack.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillStack
TEST.NEW
TEST.NAME:osFillStack.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE_USER_CODE:OsStart.osFillStack.stackTop
<<OsStart.osFillStack.stackTop>> = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:OsStart.osFillStack.stackBot
<<OsStart.osFillStack.stackBot>> = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: osFillStack.001.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillStack
TEST.NEW
TEST.NAME:osFillStack.001.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE_USER_CODE:OsStart.osFillStack.stackTop
<<OsStart.osFillStack.stackTop>> = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:OsStart.osFillStack.stackBot
<<OsStart.osFillStack.stackBot>> = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: osFillStack.001.002
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillStack
TEST.NEW
TEST.NAME:osFillStack.001.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE_USER_CODE:OsStart.osFillStack.stackTop
<<OsStart.osFillStack.stackTop>> = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT2>> );
TEST.END_VALUE_USER_CODE:
TEST.VALUE_USER_CODE:OsStart.osFillStack.stackBot
<<OsStart.osFillStack.stackBot>> = ( &<<USER_GLOBALS_VCAST.<<GLOBAL>>.VECTORCAST_INT1>> );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: osFillTaskStack

-- Test Case: osFillTaskStack.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillTaskStack
TEST.NEW
TEST.NAME:osFillTaskStack.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillTaskStack.TaskId:55
TEST.END

-- Test Case: osFillTaskStack.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillTaskStack
TEST.NEW
TEST.NAME:osFillTaskStack.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskStackStartAddress[0]:0x200
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskStackSize:4
TEST.VALUE:OsStart.osFillTaskStack.TaskId:0
TEST.END

-- Test Case: osFillTaskStack.001.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillTaskStack
TEST.NEW
TEST.NAME:osFillTaskStack.001.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillTaskStack.TaskId:55
TEST.END

-- Test Case: osFillTaskStack.001.002
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillTaskStack
TEST.NEW
TEST.NAME:osFillTaskStack.001.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillTaskStack.TaskId:55
TEST.END

-- Test Case: osFillTaskStack.002
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillTaskStack
TEST.NEW
TEST.NAME:osFillTaskStack.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillTaskStack.TaskId:25
TEST.END

-- Test Case: osFillTaskStack.002.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillTaskStack
TEST.NEW
TEST.NAME:osFillTaskStack.002.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillTaskStack.TaskId:25
TEST.END

-- Test Case: osFillTaskStack.002.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillTaskStack
TEST.NEW
TEST.NAME:osFillTaskStack.002.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillTaskStack.TaskId:25
TEST.END

-- Test Case: osFillTaskStack.002.002
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osFillTaskStack
TEST.NEW
TEST.NAME:osFillTaskStack.002.002
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.VALUE:OsStart.osFillTaskStack.TaskId:25
TEST.END

-- Subprogram: osInitialize

-- Test Case: osInitialize.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osInitialize
TEST.NEW
TEST.NAME:osInitialize.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.STUB:OsStart.osFillTaskStack
TEST.STUB:OsStart.osFillISRStacks
TEST.STUB:OsStart.OsInitMemory
TEST.VALUE:OsStart.<<GLOBAL>>.CounterRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.CounterRefConfig[0][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.CounterRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.CounterRefConfig[1][0].OsCounterParam:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[1]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[1][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[2]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[2][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[3]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[3][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[4]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[4][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[5]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[5][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[6]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[6][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[7]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[7][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[8]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[8][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[9]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[9][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[10]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[10][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[11]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[11][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[12]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[12][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[13]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[13][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[14]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[14][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[15]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[15][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[16]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[16][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[17]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[17][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[18]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[18][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[19]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[19][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[20]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[20][0].TaskParamRef:<<malloc 1>>
TEST.END

-- Subprogram: osStartOS

-- Test Case: osStartOS.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osStartOS
TEST.NEW
TEST.NAME:osStartOS.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.STUB:OsStart.osInitialize
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].AutoStartRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].AutoStartRef[0].AutoStartType:SCHEDULETABLE_ABSOLUTE
TEST.END

-- Test Case: osStartOS.001.001
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osStartOS
TEST.NEW
TEST.NAME:osStartOS.001.001
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.STUB:OsStart.osInitialize
TEST.VALUE:OsStart.<<GLOBAL>>.AutoStartTaskList:<<malloc 4>>
TEST.VALUE:OsStart.<<GLOBAL>>.AutoStartTaskList:"256"
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].AutoStartRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].AutoStartRef[0].AutoStartType:SCHEDULETABLE_RELATIVE
TEST.END

-- Test Case: osStartOS.001.003
TEST.UNIT:OsStart
TEST.SUBPROGRAM:osStartOS
TEST.NEW
TEST.NAME:osStartOS.001.003
TEST.NOTES:
SoftwareArchitecture::SYS::mos::mos_Detailed_Design::mos Class Diagram
Requirement_DICVA-7604
TEST.END_NOTES:
TEST.STUB:OsStart.osInitialize
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.TcbTaskRefConfig[0][0].TaskParamRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0]:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].AutoStartRef:<<malloc 1>>
TEST.VALUE:OsStart.<<GLOBAL>>.OsScheduleTableRefConfig[0][0].AutoStartRef[0].AutoStartType:SCHEDULETABLE_SYNCHRON
TEST.VALUE_USER_CODE:OsStart.<<GLOBAL>>.AutoStartTaskList
<<OsStart.<<GLOBAL>>.AutoStartTaskList[0]>> = ( 255 );
TEST.END_VALUE_USER_CODE:
TEST.END
