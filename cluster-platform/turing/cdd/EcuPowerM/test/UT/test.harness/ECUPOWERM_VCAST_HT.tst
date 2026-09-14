-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : ECUPOWERM_VCAST_HT
-- Unit(s) Under Test: CDD_EcuPowerM EcuPowerM EcuPowerM_ErrorHandler EcuPowerM_LowLevelDrv
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CDD_EcuPowerM

-- Subprogram: CCDD_EcuPowerM_Impl_MainFunction

-- Test Case: CCDD_EcuPowerM_Impl_MainFunction_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CCDD_EcuPowerM_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_EcuPowerM_Impl_MainFunction_Init
TEST.END

-- Subprogram: CCDD_EcuPowerM_Impl_OnCommand

-- Test Case: CCDD_EcuPowerM_Impl_OnCommand_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CCDD_EcuPowerM_Impl_OnCommand
TEST.NEW
TEST.NAME:CCDD_EcuPowerM_Impl_OnCommand_Init
TEST.EXPECTED:CDD_EcuPowerM.CCDD_EcuPowerM_Impl_OnCommand.return:0
TEST.END

-- Subprogram: CmpActivation

-- Test Case: CmpActivation_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CmpActivation
TEST.NEW
TEST.NAME:CmpActivation_Init
TEST.EXPECTED:CDD_EcuPowerM.CmpActivation.return:0
TEST.END

-- Subprogram: CmpActive

-- Test Case: CmpActive_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CmpActive
TEST.NEW
TEST.NAME:CmpActive_Init
TEST.EXPECTED:CDD_EcuPowerM.CmpActive.return:0
TEST.END

-- Subprogram: CmpDeActivation

-- Test Case: CmpDeActivation_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CmpDeActivation
TEST.NEW
TEST.NAME:CmpDeActivation_Init
TEST.EXPECTED:CDD_EcuPowerM.CmpDeActivation.return:0
TEST.END

-- Subprogram: CmpDeInit

-- Test Case: CmpDeInit_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CmpDeInit
TEST.NEW
TEST.NAME:CmpDeInit_Init
TEST.EXPECTED:CDD_EcuPowerM.CmpDeInit.return:0
TEST.END

-- Subprogram: CmpDiag

-- Test Case: CmpDiag_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CmpDiag
TEST.NEW
TEST.NAME:CmpDiag_Init
TEST.EXPECTED:CDD_EcuPowerM.CmpDiag.return:0
TEST.END

-- Subprogram: CmpDiagReturn

-- Test Case: CmpDiagReturn_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CmpDiagReturn
TEST.NEW
TEST.NAME:CmpDiagReturn_Init
TEST.EXPECTED:CDD_EcuPowerM.CmpDiagReturn.return:0
TEST.END

-- Subprogram: CmpInit

-- Test Case: CmpInit_Init
TEST.UNIT:CDD_EcuPowerM
TEST.SUBPROGRAM:CmpInit
TEST.NEW
TEST.NAME:CmpInit_Init
TEST.EXPECTED:CDD_EcuPowerM.CmpInit.return:0
TEST.END

-- Unit: EcuPowerM

-- Subprogram: EcuPowerM_DeInit

-- Test Case: EcuPowerM_DeInit.InitStatus=Uninitialized
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_DeInit
TEST.NEW
TEST.NAME:EcuPowerM_DeInit.InitStatus=Uninitialized
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuPowerM_DeInit.InitStatus=Uninitialized.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_DeInit
TEST.NEW
TEST.NAME:EcuPowerM_DeInit.InitStatus=Uninitialized.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.END

-- Subprogram: EcuPowerM_EvaluateChannelCriteria

-- Test Case: EcuPowerM_EvaluateChannelCriteria.G.value>currentValue
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.G.value>currentValue
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_GREATER
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].value:1
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:0
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.GTE.value<currentValue
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.GTE.value<currentValue
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_GREATER_THAN_EQUAL
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.currentValue:1
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.Init
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.Init
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.channelRef!=0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.channelRef!=0
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:0
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.criteria=Equal
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.criteria=Equal
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_EQUAL
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:0
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.criteria=Greater
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.criteria=Greater
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_GREATER
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.criteria=Greater_than_Equal
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.criteria=Greater_than_Equal
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_GREATER_THAN_EQUAL
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:0
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.criteria=Lesser
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.criteria=Lesser
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_LESSER
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.criteria=Lesser_than_Equal
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.criteria=Lesser_than_Equal
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_LESSER_THAN_EQUAL
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:0
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.def(Inv)
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.def(Inv)
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_TYPE_INVALID
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.value!=currentValue
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.value!=currentValue
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_EQUAL
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].value:1
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.value<currentValue
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.value<currentValue
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_LESSER
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.currentValue:2
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:0
TEST.END

-- Test Case: EcuPowerM_EvaluateChannelCriteria.value>currentValue
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_EvaluateChannelCriteria
TEST.NEW
TEST.NAME:EcuPowerM_EvaluateChannelCriteria.value>currentValue
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].criteria:ECUPOWERM_CRITERIA_LESSER_THAN_EQUAL
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.channelRef[0].value:1
TEST.EXPECTED:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Subprogram: EcuPowerM_GetDeviceStatus

-- Test Case: EcuPowerM_GetDeviceStatus.Initstatus=Uninitialized
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_GetDeviceStatus
TEST.NEW
TEST.NAME:EcuPowerM_GetDeviceStatus.Initstatus=Uninitialized
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.EXPECTED:EcuPowerM.EcuPowerM_GetDeviceStatus.return:1
TEST.END

-- Test Case: EcuPowerM_GetDeviceStatus.device>=3
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_GetDeviceStatus
TEST.NEW
TEST.NAME:EcuPowerM_GetDeviceStatus.device>=3
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_GetDeviceStatus.deviceId:4
TEST.END

-- Test Case: EcuPowerM_GetDeviceStatus.else
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_GetDeviceStatus
TEST.NEW
TEST.NAME:EcuPowerM_GetDeviceStatus.else
TEST.VALUE:EcuPowerM.EcuPowerM_GetDeviceStatus.status:<<malloc 1>>
TEST.EXPECTED:EcuPowerM.EcuPowerM_GetDeviceStatus.return:0
TEST.END

-- Subprogram: EcuPowerM_Init

-- Test Case: EcuPowerM_Init.InitStatus=Initialized
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_Init
TEST.NEW
TEST.NAME:EcuPowerM_Init.InitStatus=Initialized
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.END

-- Subprogram: EcuPowerM_InitInternalMemory

-- Test Case: EcuPowerM_InitInternalMemory_Init
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_InitInternalMemory
TEST.NEW
TEST.NAME:EcuPowerM_InitInternalMemory_Init
TEST.END

-- Subprogram: EcuPowerM_MainFunction

-- Test Case: EcuPowerM_MainFunction.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_MainFunction
TEST.NEW
TEST.NAME:EcuPowerM_MainFunction.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.END

-- Test Case: EcuPowerM_MainFunction.002
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_MainFunction
TEST.NEW
TEST.NAME:EcuPowerM_MainFunction.002
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuPowerM_MainFunction.003
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_MainFunction
TEST.NEW
TEST.NAME:EcuPowerM_MainFunction.003
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWER_MAX
TEST.END

-- Subprogram: EcuPowerM_ProcessCommand

-- Test Case: EcuPowerM_ProcessCommand.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.002
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.002
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.003
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.003
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_INVALID
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.004
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.004
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAIT_TIME
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.005
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.005
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<null>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.006
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.006
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_READ_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.007
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.007
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.008
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.008
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.009
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.009
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<null>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.010
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.010
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_ANALOG
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.011
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.011
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.DioWriteChannel:<<null>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.012
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.012
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.DioWriteChannel:<<null>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.013
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.013
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.DioWriteChannel:<<null>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.014
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.014
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.015
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.015
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:8
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.016
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.016
TEST.VALUE:uut_prototype_stubs.dummy.return:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE_USER_CODE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr.commandptr[0].channelRef.channelRef[0].channelRef[0][0].apiName
<<EcuPowerM.EcuPowerM_ProcessCommand.commandptr>>[0].channelRef[0][0].apiName = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.017
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.017
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<null>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.018
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.018
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.019
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.019
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE_USER_CODE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr.commandptr[0].channelRef.channelRef[0].channelRef[0][0].apiName
<<EcuPowerM.EcuPowerM_ProcessCommand.commandptr>>[0].channelRef[0][0].apiName = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.020
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.020
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE_USER_CODE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr.commandptr[0].channelRef.channelRef[0].channelRef[0][0].apiName
<<EcuPowerM.EcuPowerM_ProcessCommand.commandptr>>[0].channelRef[0][0].apiName = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.021
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.021
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.022
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.022
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.023
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.023
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.IohwAbsAdcReadChannel:<<null>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.024
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.024
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.025
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.025
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_INVALID
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.026
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.026
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiName:<<null>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.027
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.027
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE_USER_CODE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr.commandptr[0].channelRef.channelRef[0].channelRef[0][0].apiName
<<EcuPowerM.EcuPowerM_ProcessCommand.commandptr>>[0].channelRef[0][0].apiName = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.028
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.028
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE_USER_CODE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr.commandptr[0].channelRef.channelRef[0].channelRef[0][0].apiName
<<EcuPowerM.EcuPowerM_ProcessCommand.commandptr>>[0].channelRef[0][0].apiName = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.029
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.029
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_ANALOG
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.030
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.030
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_ANALOG
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.031
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.031
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.032
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.032
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.033
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.033
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandState:ECUPOWERM_COMMAND_STATE_IN_EXECUTION
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAIT_TIME
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:4
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.034
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.034
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandState:ECUPOWERM_COMMAND_STATE_IN_WAIT
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAIT_TIME
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:0
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.035
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.035
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandState:ECUPOWERM_COMMAND_STATE_IN_WAIT
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].waitTimer:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAIT_TIME
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:4
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.036
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.036
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.037
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.037
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.038
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.038
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<null>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.039
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.039
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_INVALID
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.040
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.040
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_ANALOG
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.041
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.041
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiName:<<null>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.042
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.042
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE_USER_CODE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr.commandptr[0].channelRef.channelRef[0].channelRef[0][0].apiName
<<EcuPowerM.EcuPowerM_ProcessCommand.commandptr>>[0].channelRef[0][0].apiName = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.043
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.043
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE_USER_CODE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr.commandptr[0].channelRef.channelRef[0].channelRef[0][0].apiName
<<EcuPowerM.EcuPowerM_ProcessCommand.commandptr>>[0].channelRef[0][0].apiName = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.044
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.044
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.PwmSetDuty:<<null>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.045
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.045
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.046
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.046
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_PERIOD_AND_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.047
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.047
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_CUSTOM
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.048
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.048
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:2
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_CUSTOM
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.049
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.049
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:3
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_CUSTOM
TEST.VALUE_USER_CODE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr.commandptr[0].channelRef.channelRef[0].channelRef[0][0].apiName
<<EcuPowerM.EcuPowerM_ProcessCommand.commandptr>>[0].channelRef[0][0].apiName = ( &dummy );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.050
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.050
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:2
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.051
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.051
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.PwmSetDuty:<<null>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.052
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.052
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WRITE_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:2
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE_USER_CODE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.IohwAbsWriteChannel
<<EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable>>.IohwAbsWriteChannel = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.053
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.053
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE_USER_CODE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.AdcReadChannel
<<EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable>>.AdcReadChannel = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.054
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.054
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_SET_DUTY
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE_USER_CODE:EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable.IohwAbsSetDuty
<<EcuPowerM.<<GLOBAL>>.EcuPowerM_LowLevelDrvFuncTable>>.IohwAbsSetDuty = ( NULL );
TEST.END_VALUE_USER_CODE:
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.055
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.055
TEST.STUB:EcuPowerM.EcuPowerM_EvaluateChannelCriteria
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.056
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.056
TEST.STUB:EcuPowerM.EcuPowerM_EvaluateChannelCriteria
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.057
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.057
TEST.STUB:EcuPowerM.EcuPowerM_EvaluateChannelCriteria
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandState:ECUPOWERM_COMMAND_STATE_IN_EXECUTION
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.058
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.058
TEST.STUB:EcuPowerM.EcuPowerM_EvaluateChannelCriteria
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandState:ECUPOWERM_COMMAND_STATE_IN_EXECUTION
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.059
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.059
TEST.STUB:EcuPowerM.EcuPowerM_EvaluateChannelCriteria
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].waitTimer:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.060
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.060
TEST.STUB:EcuPowerM.EcuPowerM_EvaluateChannelCriteria
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Test Case: EcuPowerM_ProcessCommand.061
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessCommand
TEST.NEW
TEST.NAME:EcuPowerM_ProcessCommand.061
TEST.STUB:EcuPowerM.EcuPowerM_EvaluateChannelCriteria
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.deviceId:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].timeout:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].channelptr[0].channelType:ECUPOWERM_CHANNEL_TYPE_DIGITAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].value:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessCommand.commandptr[0].channelRef[0][0].apiType:ECUPOWERM_DRIVER_API_TYPE_DIO
TEST.VALUE:EcuPowerM.EcuPowerM_EvaluateChannelCriteria.return:1
TEST.END

-- Subprogram: EcuPowerM_ProcessDevice

-- Test Case: EcuPowerM_ProcessDevice.B.NoOfSequence<Sequence
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.NoOfSequence<Sequence
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:4
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.NoOfSequence>0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.NoOfSequence>0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:4
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERUP
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERUP
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<null>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.002
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.002
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERUP
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERDOWN
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.003
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.003
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERDOWN
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.004
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.004
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.005
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.005
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_BUSY
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.006
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.006
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_BUSY
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].deviceId:4
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.007
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.007
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_BUSY
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.008
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.008
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_BUSY
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].sequence:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.009
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.009
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_BUSY
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<null>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.010
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.010
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_COMPLETED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<null>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.011
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.011
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_COMPLETED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<null>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:2
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.012
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.012
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.Sequenceptr=0.013
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.Sequenceptr=0.013
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWER_MAX
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessDevice.deviceId:0
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.B.stateInfoptr->device>3
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.B.stateInfoptr->device>3
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.InitStatus=Uninitialized
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.InitStatus=Uninitialized
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.devCurrRqst!=PowerUp
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.devCurrRqst!=PowerUp
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERDOWN
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.devPendingRqst!=idle
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.devPendingRqst!=idle
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.devState=Busy
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.devState=Busy
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.devState=Invalid
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.devState=Invalid
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.devState=completed
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.devState=completed
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.deviceptr.noOfSequence>0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.deviceptr.noOfSequence>0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.sequenceType!=PowerDown
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.sequenceType!=PowerDown
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERUP
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.sequenceType!=PowerUp
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.sequenceType!=PowerUp
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr[0][0].sequenceType:ECUPOWERM_SEQ_POWERDOWN
TEST.END

-- Test Case: EcuPowerM_ProcessDevice.sequenceptr=0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessDevice
TEST.NEW
TEST.NAME:EcuPowerM_ProcessDevice.sequenceptr=0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].numOfSequences:1
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_DeviceConfigTable[0].sequenceptr:<<malloc 1>>
TEST.END

-- Subprogram: EcuPowerM_ProcessJob

-- Test Case: EcuPowerM_ProcessJob.jobptr.commandState=State_In_Wait
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.commandState=State_In_Wait
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].timeout:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].criteria:ECUPOWERM_CRITERIA_TYPE_INVALID
TEST.END

-- Test Case: EcuPowerM_ProcessJob.jobptr.commandState=State_In_Wait.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.commandState=State_In_Wait.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].timeout:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].criteria:ECUPOWERM_CRITERIA_TYPE_INVALID
TEST.END

-- Test Case: EcuPowerM_ProcessJob.jobptr.commandState=State_In_Wait.002
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.commandState=State_In_Wait.002
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandState:ECUPOWERM_COMMAND_STATE_IN_EXECUTION
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].timeout:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].criteria:ECUPOWERM_CRITERIA_TYPE_INVALID
TEST.END

-- Test Case: EcuPowerM_ProcessJob.jobptr.commandState=State_In_Wait.003
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.commandState=State_In_Wait.003
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].waitTimer:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].numOfChannels:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].commandType:ECUPOWERM_COMMAND_WAITON_CHANNEL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].timeout:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].criteria:ECUPOWERM_CRITERIA_TYPE_INVALID
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0][0].value:4
TEST.END

-- Test Case: EcuPowerM_ProcessJob.jobptr.noOfCommands=0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.noOfCommands=0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessJob.jobptr.noOfCommands>0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.noOfCommands>0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessJob.jobptr.noOfCommands>20
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.noOfCommands>20
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].numOfCommands:24
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr:<<malloc 23>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessJob.jobptr.noOfCommands>20.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.noOfCommands>20.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].numOfCommands:24
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr:<<malloc 23>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessJob.jobptr.noOfCommands>20.002
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob.jobptr.noOfCommands>20.002
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.deviceId:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].numOfCommands:24
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr:<<malloc 23>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessJob.jobptr[0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessJob_Init
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob_Init
TEST.END

-- Test Case: EcuPowerM_ProcessJob_InitStatus=Uninitialized
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessJob
TEST.NEW
TEST.NAME:EcuPowerM_ProcessJob_InitStatus=Uninitialized
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.END

-- Subprogram: EcuPowerM_ProcessSequence

-- Test Case: EcuPowerM_ProcessSequence.InitStatus=uninitialized
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.InitStatus=uninitialized
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.devPendingRqst!=idle
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.devPendingRqst!=idle
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].interruptible:ECUPOWERM_SEQ_INTERRUPTIBLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.devPendingRqst=devCurrentRqst
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.devPendingRqst=devCurrentRqst
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].interruptible:ECUPOWERM_SEQ_INTERRUPTIBLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.devState=invalid
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.devState=invalid
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.jobCnt>numofjobs
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.jobCnt>numofjobs
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr->interruptible!=interruptible
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr->interruptible!=interruptible
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:5
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].interruptible:ECUPOWERM_SEQ_NOT_INTERRUPTIBLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[1].devState:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.002
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.002
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].jobCnt:5
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.003
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.003
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_IDLE
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].jobCnt:2
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandCnt:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].sequenceType:ECUPOWERM_SEQ_POWERDOWN
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 3>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 2>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0][0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][1].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][1].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][1].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][1].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][1].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][1].commandptr[0][0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[1]:<<malloc 2>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[1][0].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[1][1].numOfCommands:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[2]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[2][0].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[2][0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[2][0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[2][0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.004
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.004
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_IDLE
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_IDLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].interruptible:ECUPOWERM_SEQ_NOT_INTERRUPTIBLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.005
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.005
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_IDLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].interruptible:ECUPOWERM_SEQ_INTERRUPTIBLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.006
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.006
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERUP
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_POWERUP
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].interruptible:ECUPOWERM_SEQ_INTERRUPTIBLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.007
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.007
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_ILLEGAL
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_IDLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].interruptible:ECUPOWERM_SEQ_NOT_INTERRUPTIBLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.008
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr.numOfJobs>0.008
TEST.STUB:EcuPowerM.EcuPowerM_ProcessCommand
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_IDLE
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].jobCnt:0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandCnt:0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].commandState:ECUPOWERM_COMMAND_STATE_IN_WAIT
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[1].jobCnt:0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[1].commandCnt:0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[1].commandState:ECUPOWERM_COMMAND_STATE_IN_WAIT
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].numOfJobs:1
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].interruptible:ECUPOWERM_SEQ_NOT_INTERRUPTIBLE
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].numOfCommands:2
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0][0].channelRef:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0][0].channelRef[0]:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0][0].channelRef[0][0].channelptr:<<malloc 1>>
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr[0].jobptr[0][0].commandptr[0][0].channelRef[0][0].apiName:<<null>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr=0
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr=0
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<malloc 1>>
TEST.END

-- Test Case: EcuPowerM_ProcessSequence.sequenceptr=0.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessSequence
TEST.NEW
TEST.NAME:EcuPowerM_ProcessSequence.sequenceptr=0.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.deviceId:4
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessSequence.sequenceptr:<<null>>
TEST.END

-- Subprogram: EcuPowerM_ProcessWaitTime

-- Test Case: EcuPowerM_ProcessWaitTime.InitStatus=Uninitialized
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessWaitTime
TEST.NEW
TEST.NAME:EcuPowerM_ProcessWaitTime.InitStatus=Uninitialized
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.END

-- Test Case: EcuPowerM_ProcessWaitTime.InitStatus=Uninitialized.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessWaitTime
TEST.NEW
TEST.NAME:EcuPowerM_ProcessWaitTime.InitStatus=Uninitialized.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessWaitTime.deviceId:4
TEST.END

-- Test Case: EcuPowerM_ProcessWaitTime.waitTimer>=10
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessWaitTime
TEST.NEW
TEST.NAME:EcuPowerM_ProcessWaitTime.waitTimer>=10
TEST.END

-- Test Case: EcuPowerM_ProcessWaitTime.waitTimer>=10.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_ProcessWaitTime
TEST.NEW
TEST.NAME:EcuPowerM_ProcessWaitTime.waitTimer>=10.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_INITIALIZED
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].waitTimer:12
TEST.VALUE:EcuPowerM.EcuPowerM_ProcessWaitTime.deviceId:0
TEST.END

-- Subprogram: EcuPowerM_RequestPower

-- Test Case: EcuPowerM_RequestPower.InitStatus=Uinitialized
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.InitStatus=Uinitialized
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_InitStatus:ECUPOWERM_S_UNINITIALIZED
TEST.EXPECTED:EcuPowerM.EcuPowerM_RequestPower.return:1
TEST.END

-- Test Case: EcuPowerM_RequestPower.devCurrentRqst=request
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.devCurrentRqst=request
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.request:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.EXPECTED:EcuPowerM.EcuPowerM_RequestPower.return:0
TEST.END

-- Test Case: EcuPowerM_RequestPower.devPendingRqst!=request
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.devPendingRqst!=request
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.request:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.EXPECTED:EcuPowerM.EcuPowerM_RequestPower.return:0
TEST.END

-- Test Case: EcuPowerM_RequestPower.device>3
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.device>3
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].deviceId:1
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.deviceId:4
TEST.END

-- Test Case: EcuPowerM_RequestPower.device>3.001
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.device>3.001
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_POWER_MAX
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].deviceId:1
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.request:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.END

-- Test Case: EcuPowerM_RequestPower.device>3.002
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.device>3.002
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_IDLE
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWER_MAX
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.request:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.END

-- Test Case: EcuPowerM_RequestPower.device>3.003
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.device>3.003
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_IDLE
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_POWER_MAX
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].deviceId:1
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.request:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.END

-- Test Case: EcuPowerM_RequestPower.device>3.004
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.device>3.004
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devState:ECUPOWERM_DEVICE_STATE_BUSY
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devPendingRqst:ECUPOWERM_RQST_DEVICE_IDLE
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].devCurrentRqst:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.VALUE:EcuPowerM.<<GLOBAL>>.EcuPowerM_CurrentStateInfo[0].deviceId:1
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.deviceId:0
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.request:ECUPOWERM_RQST_DEVICE_POWERDOWN
TEST.END

-- Test Case: EcuPowerM_RequestPower.request=Power_Max
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.request=Power_Max
TEST.VALUE:EcuPowerM.EcuPowerM_RequestPower.request:ECUPOWERM_RQST_DEVICE_POWER_MAX
TEST.EXPECTED:EcuPowerM.EcuPowerM_RequestPower.return:1
TEST.END

-- Test Case: EcuPowerM_RequestPower.stateInfoptr.devCurrentRqst!=idle
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.stateInfoptr.devCurrentRqst!=idle
TEST.EXPECTED:EcuPowerM.EcuPowerM_RequestPower.return:1
TEST.END

-- Test Case: EcuPowerM_RequestPower.stateInfoptr.devPendingRqst!=idle
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.stateInfoptr.devPendingRqst!=idle
TEST.EXPECTED:EcuPowerM.EcuPowerM_RequestPower.return:1
TEST.END

-- Test Case: EcuPowerM_RequestPower.stateInfoptr.device!=device
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower.stateInfoptr.device!=device
TEST.END

-- Test Case: EcuPowerM_RequestPower_Init
TEST.UNIT:EcuPowerM
TEST.SUBPROGRAM:EcuPowerM_RequestPower
TEST.NEW
TEST.NAME:EcuPowerM_RequestPower_Init
TEST.EXPECTED:EcuPowerM.EcuPowerM_RequestPower.return:1
TEST.END

-- Unit: EcuPowerM_ErrorHandler

-- Subprogram: EcuPowerM_ReportError

-- Test Case: EcuPowerM_ReportError.True
TEST.UNIT:EcuPowerM_ErrorHandler
TEST.SUBPROGRAM:EcuPowerM_ReportError
TEST.NEW
TEST.NAME:EcuPowerM_ReportError.True
TEST.END

-- Unit: EcuPowerM_LowLevelDrv

-- Subprogram: AnalogChannelRead

-- Test Case: AnalogChannelRead.buffer!=0
TEST.UNIT:EcuPowerM_LowLevelDrv
TEST.SUBPROGRAM:AnalogChannelRead
TEST.NEW
TEST.NAME:AnalogChannelRead.buffer!=0
TEST.VALUE:EcuPowerM_LowLevelDrv.AnalogChannelRead.channel:1
TEST.VALUE:EcuPowerM_LowLevelDrv.AnalogChannelRead.buffer:<<malloc 1>>
TEST.VALUE:EcuPowerM_LowLevelDrv.AnalogChannelRead.buffer[0]:1
TEST.END

-- Test Case: AnalogChannelRead.buffer=0
TEST.UNIT:EcuPowerM_LowLevelDrv
TEST.SUBPROGRAM:AnalogChannelRead
TEST.NEW
TEST.NAME:AnalogChannelRead.buffer=0
TEST.END
