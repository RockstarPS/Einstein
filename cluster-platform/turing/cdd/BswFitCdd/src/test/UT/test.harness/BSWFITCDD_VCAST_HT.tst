-- VectorCAST 18 (02/04/18)
-- Test Case Script
-- 
-- Environment    : BSWFITCDD_VCAST_HT
-- Unit(s) Under Test: CDD_BswFit CDD_BswFit_Cfg
-- 
-- Script Features
TEST.SCRIPT_FEATURE:C_DIRECT_ARRAY_INDEXING
TEST.SCRIPT_FEATURE:CPP_CLASS_OBJECT_REVISION
TEST.SCRIPT_FEATURE:MULTIPLE_UUT_SUPPORT
TEST.SCRIPT_FEATURE:MIXED_CASE_NAMES
TEST.SCRIPT_FEATURE:STATIC_HEADER_FUNCS_IN_UUTS
--

-- Unit: CDD_BswFit

-- Subprogram: BswFitCdd_DeInit

-- Test Case: BswFitCdd_DeInit=True
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:BswFitCdd_DeInit
TEST.NEW
TEST.NAME:BswFitCdd_DeInit=True
TEST.END

-- Subprogram: BswFitCdd_Init

-- Test Case: BswFitCdd_Init=True
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:BswFitCdd_Init
TEST.NEW
TEST.NAME:BswFitCdd_Init=True
TEST.END

-- Subprogram: CCDD_BswFit_Impl_MainFunction

-- Test Case: CCDD_BswFit_Impl_MainFunction.6.ReturnValue=1
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.6.ReturnValue=1
TEST.VALUE:uut_prototype_stubs.NvM_ReadBlock.return:1
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFitCdd_NvM_IntegrityFaultInjection_State:6
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.7.NvmBlockStatus=3
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.7.NvmBlockStatus=3
TEST.VALUE:uut_prototype_stubs.NvM_GetErrorStatus.RequestResultPtr[0]:3
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFitCdd_NvM_IntegrityFaultInjection_State:7
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=1
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=1
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFitCdd_NvM_IntegrityFaultInjection_State:1
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=3
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=3
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFitCdd_NvM_IntegrityFaultInjection_State:3
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=4
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=4
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFitCdd_NvM_IntegrityFaultInjection_State:4
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=5
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=5
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFitCdd_NvM_IntegrityFaultInjection_State:5
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=6
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=6
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFitCdd_NvM_IntegrityFaultInjection_State:6
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=7
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFitCdd_NvM_IntegrityFaultInjection_State=7
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFitCdd_NvM_IntegrityFaultInjection_State:7
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFit_NvMBlockID=64
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFit_NvMBlockID=64
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFit_NvMBlockID:64
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFit_Nv_Write_Triggered:1
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFit_Nv_Write_Triggered!=1
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFit_Nv_Write_Triggered!=1
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.BswFit_Nv_Write_Triggered=1
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.BswFit_Nv_Write_Triggered=1
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFit_Nv_Write_Triggered:1
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.NvmBlockManagementType=RedundantBlock
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.NvmBlockManagementType=RedundantBlock
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFit_Nv_Write_Triggered:1
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.NvM_BlockConfig[0].BlockManagementType:NVM_REDUNDANT_BLOCK
TEST.END

-- Test Case: CCDD_BswFit_Impl_MainFunction.NvmBlockManagementType=RedundantBlock.001
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CCDD_BswFit_Impl_MainFunction
TEST.NEW
TEST.NAME:CCDD_BswFit_Impl_MainFunction.NvmBlockManagementType=RedundantBlock.001
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.BswFit_Nv_Write_Triggered:1
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.NvM_BlockConfig[0].BlockManagementType:NVM_REDUNDANT_BLOCK
TEST.END

-- Subprogram: CDD_BswFit_FaultInjectionHandler

-- Test Case: CDD_BswFit_FaultInjectionHandler.1.SafeAlarmIndex>1
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CDD_BswFit_FaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_BswFit_FaultInjectionHandler.1.SafeAlarmIndex>1
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.TestListID:1
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data:<<malloc 1>>
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data[0]:1
TEST.EXPECTED:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.return:0
TEST.END

-- Test Case: CDD_BswFit_FaultInjectionHandler.TestListID.def
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CDD_BswFit_FaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_BswFit_FaultInjectionHandler.TestListID.def
TEST.EXPECTED:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.return:1
TEST.END

-- Test Case: CDD_BswFit_FaultInjectionHandler.TestListID=1
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CDD_BswFit_FaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_BswFit_FaultInjectionHandler.TestListID=1
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.TestListID:1
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data:<<malloc 1>>
TEST.EXPECTED:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.return:0
TEST.END

-- Test Case: CDD_BswFit_FaultInjectionHandler.TestListID=2
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CDD_BswFit_FaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_BswFit_FaultInjectionHandler.TestListID=2
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.TestListID:2
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data:<<malloc 1>>
TEST.EXPECTED:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.return:0
TEST.END

-- Test Case: CDD_BswFit_FaultInjectionHandler.TestListID=3
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CDD_BswFit_FaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_BswFit_FaultInjectionHandler.TestListID=3
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.NvM_BlockConfig[0].RamBlockDataAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.NvM_BlockConfig[0].RomBlockDataAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[0].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[0].TaskStackStartAddress[0]:0x1234
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[1].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[2].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[3].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[4].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[5].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[6].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[7].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[8].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[9].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[10].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[11].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[12].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[13].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[14].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[15].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[16].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[17].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[18].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[19].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[20].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[21].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[22].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[23].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[24].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[25].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[26].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[27].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[28].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[29].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[30].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[31].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.TestListID:3
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data:<<malloc 1>>
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data[0]:32
TEST.EXPECTED:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.return:1
TEST.END

-- Test Case: CDD_BswFit_FaultInjectionHandler.TestListID=4
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CDD_BswFit_FaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_BswFit_FaultInjectionHandler.TestListID=4
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.NvM_BlockConfig[0].RamBlockDataAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.NvM_BlockConfig[0].RomBlockDataAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[0].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[0].TaskStackStartAddress[0]:0x1234
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[1].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[2].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[3].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[4].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[5].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[6].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[7].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[8].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[9].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[10].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[11].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[12].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[13].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[14].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[15].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[16].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[17].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[18].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[19].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[20].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[21].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[22].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[23].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[24].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[25].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[26].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[27].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[28].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[29].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[30].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[31].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.TestListID:4
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data:<<malloc 1>>
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data[0]:32
TEST.EXPECTED:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.return:1
TEST.END

-- Test Case: CDD_BswFit_FaultInjectionHandler.TestListID=5
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CDD_BswFit_FaultInjectionHandler
TEST.NEW
TEST.NAME:CDD_BswFit_FaultInjectionHandler.TestListID=5
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.NvM_BlockConfig[0].RamBlockDataAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.NvM_BlockConfig[0].RomBlockDataAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[0].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[0].TaskStackStartAddress[0]:0x1234
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[1].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[2].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[3].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[4].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[5].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[6].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[7].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[8].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[9].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[10].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[11].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[12].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[13].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[14].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[15].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[16].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[17].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[18].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[19].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[20].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[21].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[22].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[23].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[24].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[25].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[26].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[27].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[28].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[29].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[30].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.<<GLOBAL>>.TcbTaskConfig[31].TaskStackStartAddress:<<malloc 1>>
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.TestListID:5
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data:<<malloc 1>>
TEST.VALUE:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.Data[0]:32
TEST.EXPECTED:CDD_BswFit.CDD_BswFit_FaultInjectionHandler.return:0
TEST.END

-- Subprogram: CDD_BswFit_SafeMemUpdate

-- Test Case: CDD_BswFit_SafeMemUpdate=True
TEST.UNIT:CDD_BswFit
TEST.SUBPROGRAM:CDD_BswFit_SafeMemUpdate
TEST.NEW
TEST.NAME:CDD_BswFit_SafeMemUpdate=True
TEST.END
