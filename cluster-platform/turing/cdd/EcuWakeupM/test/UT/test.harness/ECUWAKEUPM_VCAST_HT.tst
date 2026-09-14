-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ECUWAKEUPM_VCAST_HT
-- Unit(s) Under Test: EcuWakeupM EcuWakeupM_ErrorHandler EcuWakeupM_LowlevelDrv_Gpt EcuWakeupM_LowlevelDrv_Icu EcuWakeupM_LowlevelDrv_Port
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: EcuWakeupM

-- Subprogram: EcuWakeupM_CheckWakeup

-- Test Case: EcuWakeupM_CheckWakeup.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_CheckWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_CheckWakeup.InitStatus!=Initialized
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_CheckWakeup.InitStatus!=Initialized.001
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_CheckWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_CheckWakeup.InitStatus!=Initialized.001
TEST.STUB:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_CheckWakeup.InitStatus=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_CheckWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_CheckWakeup.InitStatus=Initialized
TEST.END

-- Subprogram: EcuWakeupM_DisableAllWakeups

-- Test Case: EcuWakeupM_DisableAllWakeups.InitStatus!=Iniatialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableAllWakeups
TEST.NEW
TEST.NAME:EcuWakeupM_DisableAllWakeups.InitStatus!=Iniatialized
TEST.END

-- Test Case: EcuWakeupM_DisableAllWakeups.InitStatus!=Iniatialized.001
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableAllWakeups
TEST.NEW
TEST.NAME:EcuWakeupM_DisableAllWakeups.InitStatus!=Iniatialized.001
TEST.STUB:EcuWakeupM.EcuWakeupM_DisableWakeup
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.EcuWakeupM_DisableWakeup.Channel:6
TEST.END

-- Subprogram: EcuWakeupM_DisableWakeup

-- Test Case: EcuWakeupM_DisableWakeup.Channel>=2
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_DisableWakeup.Channel>=2
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.EcuWakeupM_DisableWakeup.Channel:2
TEST.END

-- Test Case: EcuWakeupM_DisableWakeup.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_DisableWakeup.InitStatus!=Initialized
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_UNINITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.END

-- Test Case: EcuWakeupM_DisableWakeup.NotifyStatus=1
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_DisableWakeup.NotifyStatus=1
TEST.STUB:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return[0].Port_SetPinModeFunc:<<null>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ChannelState[0].NotifyStatus:1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].WakeupPortAlternateMode:255
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_DisableWakeup.NotifyStatus=1.001
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_DisableWakeup.NotifyStatus=1.001
TEST.STUB:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return[0].Port_SetPinModeFunc:Port_SetPinMode
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ChannelState[0].NotifyStatus:1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 2>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[1].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 2>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].WakeupPortAlternateMode:255
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[1].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.EcuWakeupM_DisableWakeup.Channel:1
TEST.END

-- Test Case: EcuWakeupM_DisableWakeup.NotifyStatus=1.002
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_DisableWakeup.NotifyStatus=1.002
TEST.STUB:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return[0].Port_SetPinModeFunc:Port_SetPinMode
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ChannelState[0].NotifyStatus:1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].WakeupPortAlternateMode:255
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_DisableWakeup.WakeupTyp!=External
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_DisableWakeup.WakeupTyp!=External
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].WakeupType:ECUWAKEUPM_WAKEUP_INTERNAL
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_DisableWakeup.WakeupTyp=External
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_DisableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_DisableWakeup.WakeupTyp=External
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Subprogram: EcuWakeupM_EnableAllWakeups

-- Test Case: EcuWakeupM_EnableAllWakeups.InitSatus=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableAllWakeups
TEST.NEW
TEST.NAME:EcuWakeupM_EnableAllWakeups.InitSatus=Initialized
TEST.STUB:EcuWakeupM.EcuWakeupM_EnableWakeup
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.EcuWakeupM_EnableWakeup.Channel:6
TEST.END

-- Test Case: EcuWakeupM_EnableAllWakeups.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableAllWakeups
TEST.NEW
TEST.NAME:EcuWakeupM_EnableAllWakeups.InitStatus!=Initialized
TEST.END

-- Subprogram: EcuWakeupM_EnableWakeup

-- Test Case: EcuWakeupM_EnableWakeup.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_EnableWakeup.InitStatus!=Initialized
TEST.END

-- Test Case: EcuWakeupM_EnableWakeup.WakeupType!=External
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_EnableWakeup.WakeupType!=External
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].WakeupType:ECUWAKEUPM_WAKEUP_INTERNAL
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_EnableWakeup.WakeupType=External
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_EnableWakeup.WakeupType=External
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_EnableWakeup.WakeupType=External.001
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_EnableWakeup.WakeupType=External.001
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.<<GLOBAL>>.EcuWakeupM_PortDrvFuncTable.PortModeToGpioFunc:<<null>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.<<GLOBAL>>.EcuWakeupM_PortDrvFuncTable.Port_SetPinModeFunc:<<null>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_EnableWakeup.WakeupType=External.002
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_EnableWakeup.WakeupType=External.002
TEST.VALUE:EcuWakeupM_LowlevelDrv_Gpt.<<GLOBAL>>.EcuWakeupM_GptLowlevelDrvFuncTable.EnableWakeupIsrFunc:<<null>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.<<GLOBAL>>.EcuWakeupM_PortDrvFuncTable.PortModeToGpioFunc:<<null>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.<<GLOBAL>>.EcuWakeupM_PortDrvFuncTable.Port_SetPinModeFunc:Port_SetPinMode
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_EnableWakeup.WakeupType=External.003
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_EnableWakeup.WakeupType=External.003
TEST.STUB:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.<<GLOBAL>>.EcuWakeupM_PortDrvFuncTable.PortModeToGpioFunc:<<null>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.<<GLOBAL>>.EcuWakeupM_PortDrvFuncTable.Port_SetPinModeFunc:<<null>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 2>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[1].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 2>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[1].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.EcuWakeupM_EnableWakeup.Channel:1
TEST.END

-- Test Case: EcuWakeupM_EnableWakeup.channel>2
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_EnableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_EnableWakeup.channel>2
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.EcuWakeupM_EnableWakeup.Channel:6
TEST.END

-- Subprogram: EcuWakeupM_ExitCriticalSection

-- Test Case: EcuWakeupM_ExitCriticalSection_Init
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ExitCriticalSection
TEST.NEW
TEST.NAME:EcuWakeupM_ExitCriticalSection_Init
TEST.END

-- Subprogram: EcuWakeupM_GetWakeupChannel

-- Test Case: EcuWakeupM_GetWakeupChannel.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_GetWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_GetWakeupChannel.InitStatus!=Initialized
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuWakeupM_GetWakeupChannel.channeldata==0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_GetWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_GetWakeupChannel.channeldata==0
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.END

-- Test Case: EcuWakeupM_GetWakeupChannel.channeldata==0.001
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_GetWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_GetWakeupChannel.channeldata==0.001
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].EcuMWakeupSource:1
TEST.VALUE:EcuWakeupM.EcuWakeupM_GetWakeupChannel.WakeupSource:2
TEST.VALUE:EcuWakeupM.EcuWakeupM_GetWakeupChannel.ChannelData:<<malloc 1>>
TEST.END

-- Subprogram: EcuWakeupM_Init

-- Test Case: EcuWakeupM_Init.InitState=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_Init
TEST.NEW
TEST.NAME:EcuWakeupM_Init.InitState=Initialized
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.END

-- Test Case: EcuWakeupM_Init=true
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_Init
TEST.NEW
TEST.NAME:EcuWakeupM_Init=true
TEST.END

-- Subprogram: EcuWakeupM_ManageWakeup

-- Test Case: EcuWakeupM_ManageWakeup.EcuAppMCbk!=0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ManageWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_ManageWakeup.EcuAppMCbk!=0
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].EcuAppMCbk:Icu_CheckWakeup
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].UserCbk:EcuWakeupM_Init
TEST.END

-- Test Case: EcuWakeupM_ManageWakeup.EcuAppMCbk=0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ManageWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_ManageWakeup.EcuAppMCbk=0
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_ManageWakeup.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ManageWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_ManageWakeup.InitStatus!=Initialized
TEST.END

-- Test Case: EcuWakeupM_ManageWakeup.channel>=2
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ManageWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_ManageWakeup.channel>=2
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.EcuWakeupM_ManageWakeup.Channel:6
TEST.END

-- Subprogram: EcuWakeupM_ReportAllWakeupSources

-- Test Case: EcuWakeupM_ReportAllWakeupSources.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportAllWakeupSources
TEST.NEW
TEST.NAME:EcuWakeupM_ReportAllWakeupSources.InitStatus!=Initialized
TEST.END

-- Test Case: EcuWakeupM_ReportAllWakeupSources.InitStatus=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportAllWakeupSources
TEST.NEW
TEST.NAME:EcuWakeupM_ReportAllWakeupSources.InitStatus=Initialized
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.END

-- Test Case: EcuWakeupM_ReportAllWakeupSources.NotifyWakeupToServiceLayer!=0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportAllWakeupSources
TEST.NEW
TEST.NAME:EcuWakeupM_ReportAllWakeupSources.NotifyWakeupToServiceLayer!=0
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].EcuAppMCbk:Icu_CheckWakeup
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].NotifyWakeupToServiceLayer:Icu_CheckWakeup
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.END

-- Test Case: EcuWakeupM_ReportAllWakeupSources.Status!=0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportAllWakeupSources
TEST.NEW
TEST.NAME:EcuWakeupM_ReportAllWakeupSources.Status!=0
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ChannelState[0].WakeupStatus:1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].EcuAppMCbk:<<null>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].NotifyWakeupToServiceLayer:<<null>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.END

-- Subprogram: EcuWakeupM_ReportWakeupSource

-- Test Case: EcuWakeupM_ReportWakeupSource.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportWakeupSource
TEST.NEW
TEST.NAME:EcuWakeupM_ReportWakeupSource.InitStatus!=Initialized
TEST.EXPECTED:EcuWakeupM.EcuWakeupM_ReportWakeupSource.return:0
TEST.END

-- Test Case: EcuWakeupM_ReportWakeupSource.NotifyWakeupToServiceLayer!=0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportWakeupSource
TEST.NEW
TEST.NAME:EcuWakeupM_ReportWakeupSource.NotifyWakeupToServiceLayer!=0
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ChannelState[0].WakeupStatus:1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].EcuAppMCbk:Icu_CheckWakeup
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].NotifyWakeupToServiceLayer:Icu_CheckWakeup
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.EXPECTED:EcuWakeupM.EcuWakeupM_ReportWakeupSource.return:1
TEST.END

-- Test Case: EcuWakeupM_ReportWakeupSource.NotifyWakeupToServiceLayer=0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportWakeupSource
TEST.NEW
TEST.NAME:EcuWakeupM_ReportWakeupSource.NotifyWakeupToServiceLayer=0
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ChannelState[0].WakeupStatus:1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.EXPECTED:EcuWakeupM.EcuWakeupM_ReportWakeupSource.return:1
TEST.END

-- Test Case: EcuWakeupM_ReportWakeupSource.WakeupStatus=0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportWakeupSource
TEST.NEW
TEST.NAME:EcuWakeupM_ReportWakeupSource.WakeupStatus=0
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.EXPECTED:EcuWakeupM.EcuWakeupM_ReportWakeupSource.return:0
TEST.END

-- Test Case: EcuWakeupM_ReportWakeupSource.channel>2
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ReportWakeupSource
TEST.NEW
TEST.NAME:EcuWakeupM_ReportWakeupSource.channel>2
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.EcuWakeupM_ReportWakeupSource.Channel:6
TEST.EXPECTED:EcuWakeupM.EcuWakeupM_ReportWakeupSource.return:0
TEST.END

-- Subprogram: EcuWakeupM_ScanAllWakeupChannels

-- Test Case: EcuWakeupM_ScanAllWakeupChannels.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanAllWakeupChannels
TEST.NEW
TEST.NAME:EcuWakeupM_ScanAllWakeupChannels.InitStatus!=Initialized
TEST.END

-- Test Case: EcuWakeupM_ScanAllWakeupChannels.InitStatus!=Initialized.001
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanAllWakeupChannels
TEST.NEW
TEST.NAME:EcuWakeupM_ScanAllWakeupChannels.InitStatus!=Initialized.001
TEST.STUB:EcuWakeupM.EcuWakeupM_ScanWakeupChannel
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.EcuWakeupM_ScanWakeupChannel.Channel:6
TEST.END

-- Subprogram: EcuWakeupM_ScanWakeupChannel

-- Test Case: EcuWakeupM_ScanWakeupChannel.InitiStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.InitiStatus!=Initialized
TEST.END

-- Test Case: EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0
TEST.STUB:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable
TEST.STUB:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.001
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.001
TEST.STUB:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_GetGptDrvFctTable
TEST.STUB:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_Gpt_SetMode
TEST.STUB:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_Gpt_EnableWakeup
TEST.STUB:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_Gpt_DisableWakeup
TEST.STUB:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_Gpt_EnableNotification
TEST.STUB:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_Gpt_DisableNotification
TEST.STUB:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_Gpt_CheckWakeup
TEST.STUB:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable
TEST.STUB:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable
TEST.STUB:EcuWakeupM.EcuWakeupM_Init
TEST.STUB:EcuWakeupM.EcuWakeupM_EnableWakeup
TEST.STUB:EcuWakeupM.EcuWakeupM_DisableWakeup
TEST.STUB:EcuWakeupM.EcuWakeupM_EnableAllWakeups
TEST.STUB:EcuWakeupM.EcuWakeupM_DisableAllWakeups
TEST.STUB:EcuWakeupM.EcuWakeupM_SetNotification
TEST.STUB:EcuWakeupM.EcuWakeupM_ManageWakeup
TEST.STUB:EcuWakeupM.EcuWakeupM_CheckWakeup
TEST.STUB:EcuWakeupM.EcuWakeupM_GetWakeupChannel
TEST.STUB:EcuWakeupM.EcuWakeupM_ScanAllWakeupChannels
TEST.STUB:EcuWakeupM.EcuWakeupM_ReportWakeupSource
TEST.STUB:EcuWakeupM.EcuWakeupM_ReportAllWakeupSources
TEST.STUB:EcuWakeupM.EcuWakeupM_EnterCriticalSection
TEST.STUB:EcuWakeupM.EcuWakeupM_ExitCriticalSection
TEST.STUB:EcuWakeupM_ErrorHandler.EcuWakeupM_ReportError
TEST.VALUE:EcuWakeupM_LowlevelDrv_Gpt.<<GLOBAL>>.EcuWakeupM_GptDrvFuncTable.LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_Gpt_EnableWakeup.channel:1
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.<<GLOBAL>>.EcuWakeupM_IcuDrvFuncTable.LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.<<GLOBAL>>.EcuWakeupM_IcuDrvFuncTable.LowlevelDrvFunc[0].SetModeFunc:Icu_EnableWakeup
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.EcuWakeupM_EnableAllWakeups.NotifyStatus:1
TEST.END

-- Test Case: EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.002
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.002
TEST.STUB:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.END

-- Test Case: EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.003
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.003
TEST.STUB:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:uut_prototype_stubs.dummy.channel:1
TEST.VALUE:uut_prototype_stubs.dummy.return:1
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:<<null>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.STUB_VAL_USER_CODE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return.return[0].LowlevelDrvFunc.LowlevelDrvFunc[0].CheckWakeupIsrFunc
<<EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return>>[0].LowlevelDrvFunc[0].CheckWakeupIsrFunc = ( &dummy );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.004
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.004
TEST.STUB:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:uut_prototype_stubs.dummy.channel:1
TEST.VALUE:uut_prototype_stubs.dummy.return:1
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:<<null>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.STUB_VAL_USER_CODE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return.return[0].LowlevelDrvFunc.LowlevelDrvFunc[0].CheckWakeupIsrFunc
<<EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return>>[0].LowlevelDrvFunc[0].CheckWakeupIsrFunc = ( &dummy );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr.GenericPtr[0].ReadWakeupFromServiceLayer
<<EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData>>.GenericPtr[0].ReadWakeupFromServiceLayer = ( &dummy_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.005
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.005
TEST.STUB:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:uut_prototype_stubs.dummy.channel:1
TEST.VALUE:uut_prototype_stubs.dummy.return:0
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:<<null>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.STUB_VAL_USER_CODE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return.return[0].LowlevelDrvFunc.LowlevelDrvFunc[0].CheckWakeupIsrFunc
<<EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return>>[0].LowlevelDrvFunc[0].CheckWakeupIsrFunc = ( &dummy );
TEST.END_STUB_VAL_USER_CODE:
TEST.END

-- Test Case: EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.006
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.LowlevelDrvFuncPtr!=0.006
TEST.STUB:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:uut_prototype_stubs.dummy.channel:1
TEST.VALUE:uut_prototype_stubs.dummy.return:1
TEST.VALUE:uut_prototype_stubs.dummy_1.return:0
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].LowlevelDrvFunc:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:<<null>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].EcuMWakeupSource:1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.STUB_VAL_USER_CODE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return.return[0].LowlevelDrvFunc.LowlevelDrvFunc[0].CheckWakeupIsrFunc
<<EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return>>[0].LowlevelDrvFunc[0].CheckWakeupIsrFunc = ( &dummy );
TEST.END_STUB_VAL_USER_CODE:
TEST.VALUE_USER_CODE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr.GenericPtr[0].ReadWakeupFromServiceLayer
<<EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData>>.GenericPtr[0].ReadWakeupFromServiceLayer = ( &dummy_1 );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuWakeupM_ScanWakeupChannel.channel>2
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_ScanWakeupChannel
TEST.NEW
TEST.NAME:EcuWakeupM_ScanWakeupChannel.channel>2
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.EcuWakeupM_ScanWakeupChannel.Channel:6
TEST.END

-- Subprogram: EcuWakeupM_SetNotification

-- Test Case: EcuWakeupM_SetNotification.InitStatus!=Initialized
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_SetNotification
TEST.NEW
TEST.NAME:EcuWakeupM_SetNotification.InitStatus!=Initialized
TEST.END

-- Test Case: EcuWakeupM_SetNotification.NotifyStatus=1
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_SetNotification
TEST.NEW
TEST.NAME:EcuWakeupM_SetNotification.NotifyStatus=1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ChannelState[0].NotifyStatus:1
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.GenericPtr[0].GetPortDrvFuncTable:EcuWakeupM_GetPortDrvFuncTable
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr:<<malloc 1>>
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_ConfigData.ChannelPtr[0].GetDrvFuncTable:EcuWakeupM_GetIcuDrvFuncTable
TEST.VALUE:EcuWakeupM.EcuWakeupM_SetNotification.NotifyStatus:1
TEST.END

-- Test Case: EcuWakeupM_SetNotification.channel>2
TEST.UNIT:EcuWakeupM
TEST.SUBPROGRAM:EcuWakeupM_SetNotification
TEST.NEW
TEST.NAME:EcuWakeupM_SetNotification.channel>2
TEST.VALUE:EcuWakeupM.<<GLOBAL>>.EcuWakeupM_InitStatus:ECUWAKEUPM_S_INITIALIZED
TEST.VALUE:EcuWakeupM.EcuWakeupM_SetNotification.Channel:6
TEST.END

-- Unit: EcuWakeupM_ErrorHandler

-- Subprogram: EcuWakeupM_ReportError

-- Test Case: EcuWakeupM_ReportError_Init
TEST.UNIT:EcuWakeupM_ErrorHandler
TEST.SUBPROGRAM:EcuWakeupM_ReportError
TEST.NEW
TEST.NAME:EcuWakeupM_ReportError_Init
TEST.END

-- Unit: EcuWakeupM_LowlevelDrv_Gpt

-- Subprogram: EcuWakeupM_GetGptDrvFctTable

-- Test Case: EcuWakeupM_GetGptDrvFctTable_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Gpt
TEST.SUBPROGRAM:EcuWakeupM_GetGptDrvFctTable
TEST.NEW
TEST.NAME:EcuWakeupM_GetGptDrvFctTable_Init
TEST.VALUE:EcuWakeupM_LowlevelDrv_Gpt.EcuWakeupM_GetGptDrvFctTable.return:<<malloc 1>>
TEST.END

-- Subprogram: EcuWakeupM_Gpt_CheckWakeup

-- Test Case: EcuWakeupM_Gpt_CheckWakeup_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Gpt
TEST.SUBPROGRAM:EcuWakeupM_Gpt_CheckWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_Gpt_CheckWakeup_Init
TEST.END

-- Subprogram: EcuWakeupM_Gpt_DisableNotification

-- Test Case: EcuWakeupM_Gpt_DisableNotification_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Gpt
TEST.SUBPROGRAM:EcuWakeupM_Gpt_DisableNotification
TEST.NEW
TEST.NAME:EcuWakeupM_Gpt_DisableNotification_Init
TEST.END

-- Subprogram: EcuWakeupM_Gpt_DisableWakeup

-- Test Case: EcuWakeupM_Gpt_DisableWakeup_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Gpt
TEST.SUBPROGRAM:EcuWakeupM_Gpt_DisableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_Gpt_DisableWakeup_Init
TEST.END

-- Subprogram: EcuWakeupM_Gpt_EnableNotification

-- Test Case: EcuWakeupM_Gpt_EnableNotification_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Gpt
TEST.SUBPROGRAM:EcuWakeupM_Gpt_EnableNotification
TEST.NEW
TEST.NAME:EcuWakeupM_Gpt_EnableNotification_Init
TEST.END

-- Subprogram: EcuWakeupM_Gpt_EnableWakeup

-- Test Case: EcuWakeupM_Gpt_EnableWakeup_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Gpt
TEST.SUBPROGRAM:EcuWakeupM_Gpt_EnableWakeup
TEST.NEW
TEST.NAME:EcuWakeupM_Gpt_EnableWakeup_Init
TEST.END

-- Subprogram: EcuWakeupM_Gpt_SetMode

-- Test Case: EcuWakeupM_Gpt_SetMode_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Gpt
TEST.SUBPROGRAM:EcuWakeupM_Gpt_SetMode
TEST.NEW
TEST.NAME:EcuWakeupM_Gpt_SetMode_Init
TEST.END

-- Unit: EcuWakeupM_LowlevelDrv_Icu

-- Subprogram: EcuWakeupM_GetIcuDrvFuncTable

-- Test Case: EcuWakeupM_GetIcuDrvFuncTable_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Icu
TEST.SUBPROGRAM:EcuWakeupM_GetIcuDrvFuncTable
TEST.NEW
TEST.NAME:EcuWakeupM_GetIcuDrvFuncTable_Init
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].NormalMode:1
TEST.VALUE:EcuWakeupM_LowlevelDrv_Icu.EcuWakeupM_GetIcuDrvFuncTable.return[0].SleepMode:2
TEST.END

-- Unit: EcuWakeupM_LowlevelDrv_Port

-- Subprogram: EcuWakeupM_GetPortDrvFuncTable

-- Test Case: EcuWakeupM_GetPortDrvFuncTable_Init
TEST.UNIT:EcuWakeupM_LowlevelDrv_Port
TEST.SUBPROGRAM:EcuWakeupM_GetPortDrvFuncTable
TEST.NEW
TEST.NAME:EcuWakeupM_GetPortDrvFuncTable_Init
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return:<<malloc 1>>
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return[0].PortModeToGpioFunc:Port_SetToDioMode
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return[0].PortModeToAlternateFunc:Port_SetToAlternateMode
TEST.VALUE:EcuWakeupM_LowlevelDrv_Port.EcuWakeupM_GetPortDrvFuncTable.return[0].Port_SetPinModeFunc:Port_SetPinMode
TEST.END
