-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ICUDRV_VCAST_UT
-- Unit(s) Under Test: Icu
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Subprogram: Icu_CheckConfigPtr

-- Test Case: Icu_CheckConfigPtr.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_CheckConfigPtr
TEST.NEW
TEST.NAME:Icu_CheckConfigPtr.001
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:0
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_RISING_EDGE
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].NumberOfChannels:1
TEST.END

-- Subprogram: Icu_DeInit

-- Test Case: Icu_DeInit.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_DeInit
TEST.NEW
TEST.NAME:Icu_DeInit.001
TEST.STUB:Icu.Icu_GPIO_setTrigType
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_GPIO_setTrigType.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_setTrigType.pinNum:42
TEST.VALUE:Icu.Icu_GPIO_setTrigType.trigType:2
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: Icu_DeInit.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_DeInit
TEST.NEW
TEST.NAME:Icu_DeInit.002
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_UNINITIALIZED
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.END

-- Test Case: Icu_DeInit.003
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_DeInit
TEST.NEW
TEST.NAME:Icu_DeInit.003
TEST.STUB:Icu.Icu_GPIO_setTrigType
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_GPIO_setTrigType.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_setTrigType.pinNum:42
TEST.VALUE:Icu.Icu_GPIO_setTrigType.trigType:2
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Subprogram: Icu_DisableNotification

-- Test Case: Icu_DisableNotification.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_DisableNotification
TEST.NEW
TEST.NAME:Icu_DisableNotification.001
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_UNINITIALIZED
TEST.END

-- Test Case: Icu_DisableNotification.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_DisableNotification
TEST.NEW
TEST.NAME:Icu_DisableNotification.002
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.END

-- Test Case: Icu_DisableNotification.003
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_DisableNotification
TEST.NEW
TEST.NAME:Icu_DisableNotification.003
TEST.STUB:Icu.Icu_GPIO_bankIntrDisable
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_DisableNotification.Channel:0
TEST.VALUE:Icu.Icu_GPIO_bankIntrDisable.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_bankIntrDisable.bankNum:2
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: Icu_DisableNotification.004
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_DisableNotification
TEST.NEW
TEST.NAME:Icu_DisableNotification.004
TEST.STUB:Icu.Icu_GPIO_bankIntrDisable
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_DisableNotification.Channel:1
TEST.VALUE:Icu.Icu_GPIO_bankIntrDisable.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_bankIntrDisable.bankNum:2
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: Icu_DisableNotification.005
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_DisableNotification
TEST.NEW
TEST.NAME:Icu_DisableNotification.005
TEST.STUB:Icu.Icu_GPIO_bankIntrDisable
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_DisableNotification.Channel:0
TEST.VALUE:Icu.Icu_GPIO_bankIntrDisable.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_bankIntrDisable.bankNum:2
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_MEASUREMENT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Subprogram: Icu_EnableNotification

-- Test Case: Icu_EnableNotification.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_EnableNotification
TEST.NEW
TEST.NAME:Icu_EnableNotification.001
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_EnableNotification.Channel:0
TEST.VALUE:uut_prototype_stubs.Icu_ReportError.ApiId:7
TEST.VALUE:uut_prototype_stubs.Icu_ReportError.ErrorId:14
TEST.END

-- Test Case: Icu_EnableNotification.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_EnableNotification
TEST.NEW
TEST.NAME:Icu_EnableNotification.002
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_UNINITIALIZED
TEST.VALUE:Icu.Icu_EnableNotification.Channel:0
TEST.VALUE:uut_prototype_stubs.Icu_ReportError.ApiId:7
TEST.VALUE:uut_prototype_stubs.Icu_ReportError.ErrorId:14
TEST.END

-- Test Case: Icu_EnableNotification.003
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_EnableNotification
TEST.NEW
TEST.NAME:Icu_EnableNotification.003
TEST.STUB:Icu.Icu_GPIO_bankIntrEnable
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_EnableNotification.Channel:0
TEST.VALUE:Icu.Icu_GPIO_bankIntrEnable.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_bankIntrEnable.bankNum:2
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: Icu_EnableNotification.004
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_EnableNotification
TEST.NEW
TEST.NAME:Icu_EnableNotification.004
TEST.STUB:Icu.Icu_GPIO_bankIntrEnable
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_EnableNotification.Channel:1
TEST.VALUE:Icu.Icu_GPIO_bankIntrEnable.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_bankIntrEnable.bankNum:2
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: Icu_EnableNotification.005
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_EnableNotification
TEST.NEW
TEST.NAME:Icu_EnableNotification.005
TEST.STUB:Icu.Icu_GPIO_bankIntrEnable
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_EnableNotification.Channel:0
TEST.VALUE:Icu.Icu_GPIO_bankIntrEnable.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_bankIntrEnable.bankNum:2
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_MEASUREMENT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Subprogram: Icu_GPIO_setTrigType

-- Test Case: Icu_GPIO_setTrigType.004
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_GPIO_setTrigType
TEST.NEW
TEST.NAME:Icu_GPIO_setTrigType.004
TEST.VALUE:Icu.Icu_GPIO_setTrigType.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_setTrigType.pinNum:42
TEST.VALUE:Icu.Icu_GPIO_setTrigType.trigType:4
TEST.END

-- Subprogram: Icu_Init

-- Test Case: Icu_Init.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_Init
TEST.NEW
TEST.NAME:Icu_Init.001
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_UNINITIALIZED
TEST.END

-- Test Case: Icu_Init.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_Init
TEST.NEW
TEST.NAME:Icu_Init.002
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.END

-- Test Case: Icu_Init.003
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_Init
TEST.NEW
TEST.NAME:Icu_Init.003
TEST.STUB:Icu.Icu_GPIO_setTrigType
TEST.STUB:Icu.Icu_CheckConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_UNINITIALIZED
TEST.VALUE:Icu.Icu_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_RISING_EDGE
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].NumberOfChannels:1
TEST.VALUE:Icu.Icu_GPIO_setTrigType.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_setTrigType.pinNum:42
TEST.VALUE:Icu.Icu_GPIO_setTrigType.trigType:1
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_RISING_EDGE
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].NumberOfChannels:1
TEST.VALUE:Icu.Icu_CheckConfigPtr.return:1
TEST.END

-- Test Case: Icu_Init.004
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_Init
TEST.NEW
TEST.NAME:Icu_Init.004
TEST.STUB:Icu.Icu_SciClient
TEST.STUB:Icu.Icu_GPIO_setTrigType
TEST.STUB:Icu.Icu_CheckConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_UNINITIALIZED
TEST.VALUE:Icu.Icu_Init.ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_RISING_EDGE
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_Init.ConfigPtr[0].NumberOfChannels:1
TEST.VALUE:Icu.Icu_SciClient.return:1
TEST.VALUE:Icu.Icu_GPIO_setTrigType.baseAddr:69210112
TEST.VALUE:Icu.Icu_GPIO_setTrigType.pinNum:42
TEST.VALUE:Icu.Icu_GPIO_setTrigType.trigType:1
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_RISING_EDGE
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_CheckConfigPtr.ConfigPtr[0].NumberOfChannels:1
TEST.VALUE:Icu.Icu_CheckConfigPtr.return:1
TEST.END

-- Subprogram: Icu_SciClient

-- Test Case: Icu_SciClient.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_SciClient
TEST.NEW
TEST.NAME:Icu_SciClient.001
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].NumberOfChannels:1
TEST.END

-- Test Case: Icu_SciClient.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_SciClient
TEST.NEW
TEST.NAME:Icu_SciClient.002
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].NumberOfChannels:1
TEST.END

-- Test Case: Icu_SciClient.003
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_SciClient
TEST.NEW
TEST.NAME:Icu_SciClient.003
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:6291456
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].NumberOfChannels:1
TEST.VALUE:Icu.Icu_SciClient.Channel:0
TEST.VALUE:Icu.Icu_SciClient.return:1
TEST.END

-- Test Case: Icu_SciClient.004
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_SciClient
TEST.NEW
TEST.NAME:Icu_SciClient.004
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:6295552
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].NumberOfChannels:1
TEST.VALUE:uut_prototype_stubs.Sciclient_rmIrqSetRaw.return:1
TEST.END

-- Test Case: Icu_SciClient.005
TEST.UNIT:Icu
TEST.SUBPROGRAM:Icu_SciClient
TEST.NEW
TEST.NAME:Icu_SciClient.005
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_SciClient.ConfigPtr[0].NumberOfChannels:1
TEST.END

-- Subprogram: MAIN_ISR_34func

-- Test Case: MAIN_ISR_34func.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:MAIN_ISR_34func
TEST.NEW
TEST.NAME:MAIN_ISR_34func.001
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].NumberOfChannels:1
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: MAIN_ISR_34func.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:MAIN_ISR_34func
TEST.NEW
TEST.NAME:MAIN_ISR_34func.002
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.STUB:Icu.ICU_IrqHandler
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].GpioBaseAddress:6291456
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.<<GLOBAL>>.Icu_ConfigPtr[0].NumberOfChannels:1
TEST.VALUE:Icu.<<GLOBAL>>.Icu_DriverStatus:ICU_S_INITIALIZED
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:6291456
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Subprogram: MAIN_ISR_35func

-- Test Case: MAIN_ISR_35func.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:MAIN_ISR_35func
TEST.NEW
TEST.NAME:MAIN_ISR_35func.001
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:6291456
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: MAIN_ISR_35func.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:MAIN_ISR_35func
TEST.NEW
TEST.NAME:MAIN_ISR_35func.002
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.STUB:Icu.ICU_IrqHandler
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:6295552
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Subprogram: MCU_ISR_6func

-- Test Case: MCU_ISR_6func.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:MCU_ISR_6func
TEST.NEW
TEST.NAME:MCU_ISR_6func.001
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.STUB:Icu.ICU_IrqHandler
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:32
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_RISING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: MCU_ISR_6func.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:MCU_ISR_6func
TEST.NEW
TEST.NAME:MCU_ISR_6func.002
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.STUB:Icu.ICU_IrqHandler
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:32
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:4
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_RISING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Subprogram: MCU_ISR_7func

-- Test Case: MCU_ISR_7func.001
TEST.UNIT:Icu
TEST.SUBPROGRAM:MCU_ISR_7func
TEST.NEW
TEST.NAME:MCU_ISR_7func.001
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.STUB:Icu.ICU_IrqHandler
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:69210112
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END

-- Test Case: MCU_ISR_7func.002
TEST.UNIT:Icu
TEST.SUBPROGRAM:MCU_ISR_7func
TEST.NEW
TEST.NAME:MCU_ISR_7func.002
TEST.STUB:Icu.Icu_GetConfigPtr
TEST.STUB:Icu.ICU_IrqHandler
TEST.VALUE:Icu.Icu_GetConfigPtr.return:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr:<<malloc 1>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].ChannelId:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioPinNumber:42
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioBaseAddress:0
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].GpioTriggerType:ICU_FALLING_EDGE
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].MeasurementMode:ICU_MODE_SIGNAL_EDGE_DETECT
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].ChannelPtr[0].NotificationCallback:<<null>>
TEST.VALUE:Icu.Icu_GetConfigPtr.return[0].NumberOfChannels:1
TEST.END
