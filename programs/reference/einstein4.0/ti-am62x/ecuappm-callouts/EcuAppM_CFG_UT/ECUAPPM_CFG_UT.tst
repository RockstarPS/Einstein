-- VectorCAST 20.sp6 (02/02/21)
-- Test Case Script
--
-- Environment    : ECUAPPM_CFG_UT
-- Unit(s) Under Test: EcuAppM_Callouts EcuAppM_Cfg
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

-- Unit: EcuAppM_Callouts

-- Subprogram: EcuAppM_BackupData

-- Test Case: EcuAppM_BackupData.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_BackupData
TEST.NEW
TEST.NAME:EcuAppM_BackupData.001
TEST.END

-- Subprogram: EcuAppM_CheckApplicationSleepStatus

-- Test Case: EcuAppM_CheckApplicationSleepStatus.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_CheckApplicationSleepStatus
TEST.NEW
TEST.NAME:EcuAppM_CheckApplicationSleepStatus.001
TEST.END

-- Subprogram: EcuAppM_FailSafeMechanism

-- Test Case: EcuAppM_FailSafeMechanism.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_FailSafeMechanism
TEST.NEW
TEST.NAME:EcuAppM_FailSafeMechanism.001
TEST.END

-- Subprogram: EcuAppM_GroupActivationAllowed

-- Test Case: EcuAppM_GroupActivationAllowed.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_GroupActivationAllowed
TEST.NEW
TEST.NAME:EcuAppM_GroupActivationAllowed.001
TEST.END

-- Subprogram: EcuAppM_GroupStatusChangeCbk

-- Test Case: EcuAppM_GroupStatusChangeCbk.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_GroupStatusChangeCbk
TEST.NEW
TEST.NAME:EcuAppM_GroupStatusChangeCbk.001
TEST.END

-- Subprogram: EcuAppM_OnNVMReadAll

-- Test Case: EcuAppM_OnNVMReadAll.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_OnNVMReadAll
TEST.NEW
TEST.NAME:EcuAppM_OnNVMReadAll.001
TEST.END

-- Subprogram: EcuAppM_OnPowerSeqStart

-- Test Case: EcuAppM_OnPowerSeqStart.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_OnPowerSeqStart
TEST.NEW
TEST.NAME:EcuAppM_OnPowerSeqStart.001
TEST.END

-- Test Case: EcuAppM_OnPowerSeqStart.002
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_OnPowerSeqStart
TEST.NEW
TEST.NAME:EcuAppM_OnPowerSeqStart.002
TEST.VALUE:EcuAppM_Callouts.EcuAppM_OnPowerSeqStart.State:4
TEST.END

-- Test Case: EcuAppM_OnPowerSeqStart.003
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_OnPowerSeqStart
TEST.NEW
TEST.NAME:EcuAppM_OnPowerSeqStart.003
TEST.VALUE:EcuAppM_Callouts.EcuAppM_OnPowerSeqStart.State:9
TEST.END

-- Subprogram: EcuAppM_OnWakeupValidation

-- Test Case: EcuAppM_OnWakeupValidation.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_OnWakeupValidation
TEST.NEW
TEST.NAME:EcuAppM_OnWakeupValidation.001
TEST.END

-- Subprogram: EcuAppM_PowerUpWakeupSources

-- Test Case: EcuAppM_PowerUpWakeupSources.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_PowerUpWakeupSources
TEST.NEW
TEST.NAME:EcuAppM_PowerUpWakeupSources.001
TEST.END

-- Subprogram: EcuAppM_ProcessJobStatus

-- Test Case: EcuAppM_ProcessJobStatus.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_ProcessJobStatus
TEST.NEW
TEST.NAME:EcuAppM_ProcessJobStatus.001
TEST.END

-- Test Case: EcuAppM_ProcessJobStatus.002
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_ProcessJobStatus
TEST.NEW
TEST.NAME:EcuAppM_ProcessJobStatus.002
TEST.VALUE:EcuAppM_Callouts.EcuAppM_ProcessJobStatus.Current_State:VARY FROM:00 TO:016 BY: 1
TEST.END

-- Subprogram: EcuAppM_StartOfGroupsDeactivation

-- Test Case: EcuAppM_StartOfGroupsDeactivation.001
TEST.UNIT:EcuAppM_Callouts
TEST.SUBPROGRAM:EcuAppM_StartOfGroupsDeactivation
TEST.NEW
TEST.NAME:EcuAppM_StartOfGroupsDeactivation.001
TEST.END

-- Unit: EcuAppM_Cfg

-- Subprogram: CBacklightCdd_Impl_OnCommand

-- Test Case: CBacklightCdd_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:CBacklightCdd_Impl_OnCommand
TEST.NEW
TEST.NAME:CBacklightCdd_Impl_OnCommand.001
TEST.END

-- Subprogram: CCDD_EcuPowerM_Impl_OnCommand

-- Test Case: CCDD_EcuPowerM_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:CCDD_EcuPowerM_Impl_OnCommand
TEST.NEW
TEST.NAME:CCDD_EcuPowerM_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAbsTT_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAbsTT_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAbsTT_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CAbsTT_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBAC_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBAC_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBAC_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBAC_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightDerating_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightDerating_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightDerating_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBacklightDerating_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBattMdl_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBattMdl_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBattMdl_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CBattMdl_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCddIpc_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCddIpc_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCddIpc_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CCddIpc_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCddExt_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCddExt_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCddExt_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDisplayCddExt_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDwaTT_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDwaTT_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDwaTT_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CDwaTT_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEsmCdd_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEsmCdd_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEsmCdd_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CEsmCdd_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrv_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrv_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrv_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CFaldDrv_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CPmicCdd_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CPmicCdd_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CPmicCdd_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CPmicCdd_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRstMgr_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRstMgr_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRstMgr_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CRstMgr_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmiApp_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmiApp_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmiApp_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmiApp_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmi_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmi_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmi_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSafeHmi_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepMgr_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepMgr_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepMgr_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSleepMgr_Impl_OnCommand.001
TEST.END

-- Subprogram: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDiag_Impl_OnCommand

-- Test Case: Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDiag_Impl_OnCommand.001
TEST.UNIT:EcuAppM_Cfg
TEST.SUBPROGRAM:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDiag_Impl_OnCommand
TEST.NEW
TEST.NAME:Rte_Call_rp_CmpLibCmd_rp_CmpLibCmd_CSwcDiag_Impl_OnCommand.001
TEST.END
