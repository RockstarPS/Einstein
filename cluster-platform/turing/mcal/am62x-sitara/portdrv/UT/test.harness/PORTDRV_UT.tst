-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : PORTDRV_UT
-- Unit(s) Under Test: Port
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: Port_GetVersionInfo

-- Test Case: BASIS-PATH-001
TEST.UNIT:Port
TEST.SUBPROGRAM:Port_GetVersionInfo
TEST.NEW
TEST.NAME:BASIS-PATH-001
TEST.BASIS_PATH:1 of 1
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Portdrv::Portdrv_Detailed_Design::portdrv_Class_Diagram
Requirement_PE4TI29141-2376
TEST.END_NOTES:
TEST.END

-- Subprogram: Port_Init

-- Test Case: Port_Init.001
TEST.UNIT:Port
TEST.SUBPROGRAM:Port_Init
TEST.NEW
TEST.NAME:Port_Init.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Portdrv::Portdrv_Detailed_Design::portdrv_Class_Diagram
Requirement_PE4TI29141-2376
TEST.END_NOTES:
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig:<<malloc 1>>
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig[0].NumOfPins:5
TEST.VALUE:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE:Port.Port_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Instance:0
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Pin:0
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Direction:PORT_PIN_OUT
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_DefaultValue:1
TEST.VALUE:Port.Port_Init.ConfigPtr[0].NumOfPins:1
TEST.EXPECTED:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE_USER_CODE:<<testcase>>
Dio_GPIOBaseAddr[0] = (unsigned int)&Mock_GPIO_Regs;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Port_Init.002
TEST.UNIT:Port
TEST.SUBPROGRAM:Port_Init
TEST.NEW
TEST.NAME:Port_Init.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Portdrv::Portdrv_Detailed_Design::portdrv_Class_Diagram
Requirement_PE4TI29141-2376
TEST.END_NOTES:
TEST.VALUE:Port.Port_Init.ConfigPtr:<<null>>
TEST.END

-- Test Case: Port_Init.003
TEST.UNIT:Port
TEST.SUBPROGRAM:Port_Init
TEST.NEW
TEST.NAME:Port_Init.003
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Portdrv::Portdrv_Detailed_Design::portdrv_Class_Diagram
Requirement_PE4TI29141-2376
TEST.END_NOTES:
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig:<<malloc 1>>
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig[0].NumOfPins:5
TEST.VALUE:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE:Port.Port_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Instance:0
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Pin:0
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Direction:PORT_PIN_IN
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_DefaultValue:1
TEST.VALUE:Port.Port_Init.ConfigPtr[0].NumOfPins:1
TEST.EXPECTED:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE_USER_CODE:<<testcase>>
Dio_GPIOBaseAddr[0] = (unsigned int)&Mock_GPIO_Regs;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Port_Init.004
TEST.UNIT:Port
TEST.SUBPROGRAM:Port_Init
TEST.NEW
TEST.NAME:Port_Init.004
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Portdrv::Portdrv_Detailed_Design::portdrv_Class_Diagram
Requirement_PE4TI29141-2376
TEST.END_NOTES:
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig:<<malloc 1>>
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig[0].NumOfPins:5
TEST.VALUE:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE:Port.Port_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Instance:0
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Pin:0
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_Direction:PORT_PIN_OUT
TEST.VALUE:Port.Port_Init.ConfigPtr[0].Pins[0].Port_DefaultValue:0
TEST.VALUE:Port.Port_Init.ConfigPtr[0].NumOfPins:1
TEST.EXPECTED:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE_USER_CODE:<<testcase>>
Dio_GPIOBaseAddr[0] = (unsigned int)&Mock_GPIO_Regs;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: Port_RefreshPortDirection

-- Test Case: Port_RefreshPortDirection.001
TEST.UNIT:Port
TEST.SUBPROGRAM:Port_RefreshPortDirection
TEST.NEW
TEST.NAME:Port_RefreshPortDirection.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Portdrv::Portdrv_Detailed_Design::portdrv_Class_Diagram
Requirement_PE4TI29141-2376
TEST.END_NOTES:
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig:<<malloc 1>>
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig[0].Pins[0].Port_Instance:0
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig[0].Pins[0].Port_Pin:0
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig[0].Pins[0].Port_Direction:PORT_PIN_OUT
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig[0].Pins[0].Port_DefaultValue:0
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig[0].NumOfPins:1
TEST.VALUE:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.EXPECTED:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE_USER_CODE:<<testcase>>
Dio_GPIOBaseAddr[0] = (unsigned int)&Mock_GPIO_Regs;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: Port_RefreshPortDirection.002
TEST.UNIT:Port
TEST.SUBPROGRAM:Port_RefreshPortDirection
TEST.NEW
TEST.NAME:Port_RefreshPortDirection.002
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Portdrv::Portdrv_Detailed_Design::portdrv_Class_Diagram
Requirement_PE4TI29141-2376
TEST.END_NOTES:
TEST.VALUE:Port.<<GLOBAL>>.Port_currentconfig:<<null>>
TEST.VALUE:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.EXPECTED:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE_USER_CODE:<<testcase>>
Dio_GPIOBaseAddr[0] = (unsigned int)&Mock_GPIO_Regs;
TEST.END_VALUE_USER_CODE:
TEST.END

-- Subprogram: Port_SetPinDirection

-- Test Case: Port_SetPinDirection.001
TEST.UNIT:Port
TEST.SUBPROGRAM:Port_SetPinDirection
TEST.NEW
TEST.NAME:Port_SetPinDirection.001
TEST.NOTES:
SoftwareArchitecture::TI::MCAL::Portdrv::Portdrv_Detailed_Design::portdrv_Class_Diagram
Requirement_PE4TI29141-2376
TEST.END_NOTES:
TEST.VALUE:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE:Port.Port_SetPinDirection.Pin:0
TEST.VALUE:Port.Port_SetPinDirection.Direction:PORT_PIN_OUT
TEST.EXPECTED:Port.<<GLOBAL>>.Mock_GPIO_Regs.BANK_REGISTERS[0].SET_DATA:1
TEST.VALUE_USER_CODE:<<testcase>>
Dio_GPIOBaseAddr[0] = (unsigned int)&Mock_GPIO_Regs;
TEST.END_VALUE_USER_CODE:
TEST.END
