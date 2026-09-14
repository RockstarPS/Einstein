/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_OsApplication_NonTrusted.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_Rte_0781, MD_MSR_1.1_857 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_CBacklightCdd.h"
#include "Rte_CCDD_BswFit.h"
#include "Rte_CCDD_EcuBatteryM.h"
#include "Rte_CCDD_EcuPowerM.h"
#include "Rte_CCDD_FitManager.h"
#include "Rte_CCDD_McuFit.h"
#include "Rte_CComAbsCtrl.h"
#include "Rte_CComAbsMdl.h"
#include "Rte_CComAbsMdlSafe.h"
#include "Rte_CComAbsMdl_stubs.h"
#include "Rte_CCtrl_Telltale.h"
#include "Rte_CDisplayCdd.h"
#include "Rte_CFltM.h"
#include "Rte_CFltMExt.h"
#include "Rte_CIoExp.h"
#include "Rte_CMeetCdd.h"
#include "Rte_CPmicCdd.h"
#include "Rte_CRstM.h"
#include "Rte_CSigCdd.h"
#include "Rte_CSwcDispMonSf.h"
#include "Rte_CUpdateCdd.h"
#include "Rte_CView_Telltale.h"
#include "Rte_CWarnMsg_Core_Observer.h"
#include "Rte_ComCallout.h"
#include "Rte_ComMExt.h"
#include "Rte_CorTst.h"
#include "Rte_Ctrl_Dim.h"
#include "Rte_Ctrl_Illumination.h"
#include "Rte_Ctrl_WSS.h"
#include "Rte_Ctrl_warning.h"
#include "Rte_DcmApp.h"
#include "Rte_DcmExt.h"
#include "Rte_DemApp.h"
#include "Rte_DemExt.h"
#include "Rte_DemMaster_0.h"
#include "Rte_DemSatellite_0.h"
#include "Rte_Det.h"
#include "Rte_Dlt.h"
#include "Rte_DltExt.h"
#include "Rte_DmnMgr.h"
#include "Rte_EcuAppM.h"
#include "Rte_EcuM.h"
#include "Rte_EcuMExt.h"
#include "Rte_FastGaugeAdapter.h"
#include "Rte_FlsTst.h"
#include "Rte_GdtCdd.h"
#include "Rte_IoHwAb.h"
#include "Rte_Mdl_Airbag.h"
#include "Rte_Mdl_Dim.h"
#include "Rte_Mdl_Gear.h"
#include "Rte_Mdl_Linear_Interpolation.h"
#include "Rte_Mdl_SafetyAdapter.h"
#include "Rte_Mdl_Speed.h"
#include "Rte_Mdl_Tacho.h"
#include "Rte_Mdl_TurnHazard.h"
#include "Rte_Mdl_wAirbag.h"
#include "Rte_Mdl_wFuelLidOpen.h"
#include "Rte_MemAbstractMdl.h"
#include "Rte_MemAbstractStub.h"
#include "Rte_MemAbstract_Stub_Safe.h"
#include "Rte_NvM.h" /* PRQA S 3451 */ /* MD_Rte_3451_NvM */
#include "Rte_NvMExt.h"
#include "Rte_NvMExtSf.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_RamTst.h"
#include "Rte_RtcCdd.h"
#include "Rte_SafeBsw.h"
#include "Rte_SafeNvM.h"
#include "Rte_SciDrv.h"
#include "Rte_SlowGaugeAdapter.h"
#include "Rte_SysTst.h"
#include "Rte_Test_Comp.h"
#include "Rte_TmExt.h"
#include "Rte_TrustecSWC.h"
#include "Rte_UclProxyCdd.h"
#include "Rte_View_Illumination.h"
#include "Rte_View_Speed.h"
#include "Rte_WarnMsg_Core_TmrSupport.h"
#include "Rte_WdgM.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanSM.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Ea.h"
#include "SchM_EcuM.h"
#include "SchM_Nm.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

#include "NvM.h" /* PRQA S 3451 */ /* MD_Rte_3451_NvM */

#include "ComXf.h"
#include "E2EXf.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#define Rte_DisableAllInterrupts(Mode) Rte_DisableAllInterrupts##Mode() /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterruptsKM() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterruptsKM() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osDisableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterruptsUM() osDisableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterruptsUM() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osDisableGlobalAM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterruptsAM() osDisableGlobalAM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterruptsAM() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#define Rte_EnableAllInterrupts(Mode) Rte_EnableAllInterrupts##Mode() /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterruptsKM() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterruptsKM() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterruptsUM() osEnableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterruptsUM() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalAM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterruptsAM() osEnableGlobalAM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterruptsAM() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#define Rte_DisableOSInterrupts(Mode) Rte_DisableOSInterrupts##Mode() /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterruptsKM() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterruptsKM() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osDisableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterruptsUM() osDisableLevelUM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterruptsUM() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osDisableLevelAM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterruptsAM() osDisableLevelAM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterruptsAM() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#define Rte_EnableOSInterrupts(Mode) Rte_EnableOSInterrupts##Mode() /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterruptsKM() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterruptsKM() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterruptsUM() osEnableLevelUM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterruptsUM() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelAM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterruptsAM() osEnableLevelAM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterruptsAM() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(UInt8, RTE_VAR_INIT) Rte_CSigCdd_pp_SigCddSts_win_violation_output = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SHudWarningDisplay, RTE_VAR_INIT) Rte_CWarnMsg_Core_Observer_pp_HUDWarningDisplay_HudWarningDisplayData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(STpmsWarningData, RTE_VAR_INIT) Rte_CWarnMsg_Core_Observer_pp_TPMSWarnPayload_TpmsWarningDataData = {
  {0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SWarningDisplay, RTE_VAR_INIT) Rte_CWarnMsg_Core_Observer_pp_WarningDisplay_WarningDisplayData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SIlluminationData, RTE_VAR_INIT) Rte_Ctrl_Dim_pSR_IlluminationData_IlluminationDataData = {
  0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Boolean, RTE_VAR_INIT) Rte_Ctrl_Dim_pp_Ctrl_Ready_to_Sleep_Ready_to_Sleep = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Ctrl_Dim_pp_IlumDayNightRequired_IlumDayNightRequired = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Ctrl_Dim_pp_IlumDayNightStatus_Day_Night_Status = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Ctrl_Dim_pp_StopPwmUpdate_channel_id = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IllumCtrl_Op, RTE_VAR_INIT) Rte_Ctrl_Illumination_pp_IllumCtrl_Op_IllumCtrl_Op_Data = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(HMIReadySts_Type, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(DisplayStatus, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_TFTDisplayOn_TFTDisplayOn = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(VehicleActiveModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SDLTControlMessageReponse, RTE_VAR_INIT) Rte_DltExt_pSR_DLTControlMessageReponse_DLTControlMessageReponseData = {
  0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SDLTMessageReadRequest, RTE_VAR_INIT) Rte_DltExt_pSR_DLTMessageReadRequest_DLTMessageReadRequestData = {
  0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SPowerSystemStateReqChange, RTE_VAR_INIT) Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData = {
  0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SDmnStatus, RTE_VAR_INIT) Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus = {
  0U, 0U, 0, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SFastGaugeInfo, RTE_VAR_INIT) Rte_FastGaugeAdapter_pp_FastGaugeInfo_FastGaugeInfoData = {
  {{0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IllumCtrl_Ip, RTE_VAR_INIT) Rte_Mdl_Dim_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_IlumDayNightStatus_illumDNStatus = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_IlumStep_IllumStepValue = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_RheostatDayStep_RheostatDayStep = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_RheostatNightStep_RheostatNightStep = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_illumStarterstatus_StarterStatus_Out = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_illum_rheostat_change_RheoUpdateVal = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SShiftPosIndStatus, RTE_VAR_INIT) Rte_Mdl_Gear_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData = {
  {0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Selection_Table_Speed_Selection_Table = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Target2_Status_Spd_Target2_Status = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Target_Status_Spd_Target_Status = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Trim2_Status_Spd_Trim2_Status = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Trim_Status_Spd_Trim_Status = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Needle_Transparent_Needle_TR = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Boolean, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(TurnStates, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(TurnStates, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_TurnR_Sts_RightIndicatorSts = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2 = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_Illumination_Copy1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_Illumination_Copy2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_EngOffTimer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_FuelGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_OilGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_PowerGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_Power, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_ServiceReminder, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_SpeedoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_TachoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_TempGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_TripComputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsCys_Certicificate, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsDiag_Dtc, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsDiag_ErrorRecord, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Display, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Gauges, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Odometer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Personalization, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Power, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Tripcomputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsReten_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_CusDlt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_FuelGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_Odometer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_OilGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_Personalization, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_PowerGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_SpeedoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_TachoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_TempGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_TripComputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsRt_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsShare_EcuPartNumber, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {1U, 1U, 0U
  }, {1U, 1U, 0U}, {255U, 255U, 255U}, {255U, 255U, 255U}, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsShare_SwUpdFotaMode, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsShare_SwUpdFotaStatus, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsShare_SwUpdFotadecrypt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsShare_SwUpdReflash, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsShare_VehicleConfig, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsShare_VisMeet, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 65535U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_RefCys_Certicificate1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_RefCys_Certicificate, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted = FALSE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SSlowGuageInfo, RTE_VAR_INIT) Rte_SlowGaugeAdapter_pp_SlowGaugeInfo_SlowGaugeInfoData = {
  {0U, 0U, 0, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SDLTControlMessageRequest, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_DLTControlMessageRequest_DLTControlMessageRequestData = {
  0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SDLTMessageReadAck, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_DLTMessageReadAck_DLTMessageReadAckData = {
  0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SDisplayCurrentState, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData = {
  0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SHudWarningStatus, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_HudWarningStatus_HudWarningStatusData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SPowerSystemState, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData = {
  0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SWarningStatus, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_WarningStatus_WarningStatusData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_View_Speed_pp_Display_speed_Value_Digital_Speed_Value = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(UInt16, RTE_VAR_INIT) Rte_View_Speed_pp_SubDisplaySpeed_Value_SubDispSpeedVal = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/
#define RTE_FBK_COM_STOPPED                (0U)
#define RTE_FBK_TIMEOUT                    (1U)
#define RTE_FBK_TRANSMIT_ACK               (2U)
#define RTE_FBK_NO_DATA                    (3U)


#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_OsApplication_NonTrusted_AckFlagsType, RTE_VAR_INIT) Rte_OsApplication_NonTrusted_AckFlags = { /* PRQA S 0850 */ /* MD_MSR_19.8 */
  RTE_FBK_TRANSMIT_ACK,
};

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define Rte_OsApplication_NonTrusted_AckFlagsInit() (Rte_MemClr(&Rte_OsApplication_NonTrusted_AckFlags, sizeof(Rte_OsApplication_NonTrusted_AckFlagsType)))

/**********************************************************************************************************************
 * TxUpdate Flags for each external Tx Signal over Rte_ComSendSignalProxy without IOCs
 *********************************************************************************************************************/
#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_OsApplication_NonTrusted_TxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrusted_TxUpdateFlags = {
  0
}; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define Rte_OsApplication_NonTrusted_TxUpdateFlagsInit() (Rte_MemClr(&Rte_OsApplication_NonTrusted_TxUpdateFlags, sizeof(Rte_OsApplication_NonTrusted_TxUpdateFlagsType)))

/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



/**********************************************************************************************************************
 * Never Received Flags for each external Rx Signal with handleNeverReceived != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_OsApplication_NonTrusted_RxNeverReceivedFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrusted_RxNeverReceivedFlags = {
  0
}; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define Rte_OsApplication_NonTrusted_RxNeverReceivedFlagsInit() (Rte_MemClr(&Rte_OsApplication_NonTrusted_RxNeverReceivedFlags, sizeof(Rte_OsApplication_NonTrusted_RxNeverReceivedFlagsType)))


/**********************************************************************************************************************
 * Dirty Flags for NVBlockDescriptors
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_DirtyFlagsType, RTE_VAR_ZERO_INIT) Rte_DirtyFlags = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
}; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define Rte_DirtyFlagsInit() (Rte_MemClr(&Rte_DirtyFlags, sizeof(Rte_DirtyFlagsType)))


/**********************************************************************************************************************
 * Prototypes for Runnable Entities of Nv Block Components
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

RTE_LOCAL FUNC(void, RTE_CODE) NvBlockSwComponentTypeRunnable(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num); /* PRQA S 0850, 3447, 3408 */ /* MD_MSR_19.8, MD_Rte_3447, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 0850, 1505, 3447, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3447, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 0850, 1505, 3447, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3447, MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Buffers for data transformation
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint8, RTE_VAR_NOINIT) Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx[6]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint32, RTE_VAR_INIT) Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx_Length = 0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Data structures for queue handling
 *********************************************************************************************************************/

#define RTE_Q_OK     ((Rte_QReturnType)0)
#define RTE_Q_EMPTY  ((Rte_QReturnType)1)
#define RTE_Q_FULL   ((Rte_QReturnType)2)

#define RTE_Q_CMeetCdd_rSR_DiagResponse_DiagResponseData (0)
#define RTE_Q_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData (1)
#define RTE_Q_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData (2)
#define RTE_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData (3)
#define RTE_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData (4)
#define RTE_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData (5)
#define RTE_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData (6)
#define RTE_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData (7)
#define RTE_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData (8)
#define RTE_Q_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData (9)
#define RTE_Q_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData (10)
#define RTE_Q_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData (11)
#define RTE_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData (12)
#define RTE_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData (13)
#define RTE_Q_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData (14)
#define RTE_Q_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData (15)

typedef uint8 Rte_QReturnType;
typedef uint8 Rte_QIndexType;

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QAddElementOsApplication_NonTrusted(Rte_QIndexType q, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) pData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QUnqueueElementOsApplication_NonTrusted(Rte_QIndexType q, P2VAR(void, AUTOMATIC, RTE_APPL_VAR) pData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define Rte_QOverflow_CMeetCdd_rSR_DiagResponse_DiagResponseData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b0)
#define Rte_QOverflow_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b1)
#define Rte_QOverflow_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b2)
#define Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b3)
#define Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b4)
#define Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b5)
#define Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b6)
#define Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b7)
#define Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b8)
#define Rte_QOverflow_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b9)
#define Rte_QOverflow_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b10)
#define Rte_QOverflow_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b11)
#define Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b12)
#define Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b13)
#define Rte_QOverflow_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b14)
#define Rte_QOverflow_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData (Rte_OsApplication_NonTrusted_QOverflow.Rte_b15)

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_OsApplication_NonTrusted_QOverflowType, RTE_VAR_NOINIT) Rte_OsApplication_NonTrusted_QOverflow; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer
# define RTE_USEC_SystemTimer OS_US2TICKS_SystemTimer
#else
# define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer
# define RTE_MSEC_SystemTimer OS_MS2TICKS_SystemTimer
#else
# define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer
# define RTE_SEC_SystemTimer OS_SEC2TICKS_SystemTimer
#else
# define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_19.13_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_0 (0UL)
#define RTE_CONST_MSEC_SystemTimer_10 (10UL)
#define RTE_CONST_MSEC_SystemTimer_100 (100UL)
#define RTE_CONST_MSEC_SystemTimer_16 (16UL)
#define RTE_CONST_MSEC_SystemTimer_20 (20UL)
#define RTE_CONST_MSEC_SystemTimer_30 (30UL)
#define RTE_CONST_MSEC_SystemTimer_32 (32UL)
#define RTE_CONST_MSEC_SystemTimer_4 (4UL)
#define RTE_CONST_MSEC_SystemTimer_5 (5UL)
#define RTE_CONST_MSEC_SystemTimer_50 (50UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


FUNC(void, RTE_CODE) Rte_InitMemory_OsApplication_NonTrusted(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* reset Tx Update Flags */
  Rte_OsApplication_NonTrusted_TxUpdateFlagsInit();

  /* reset Rx Never Received Flags */
  Rte_OsApplication_NonTrusted_RxNeverReceivedFlagsInit();

  /* reset Dirty Flags */
  Rte_DirtyFlagsInit();

  /* set default values for internal data */
  Rte_CSigCdd_pp_SigCddSts_win_violation_output = 0U;
  Rte_CWarnMsg_Core_Observer_pp_HUDWarningDisplay_HudWarningDisplayData = Rte_UclProxyCddHudWarningDisplayDataValue0;
  Rte_CWarnMsg_Core_Observer_pp_TPMSWarnPayload_TpmsWarningDataData = Rte_UclProxyCddTpmsWarningDataDataValue0;
  Rte_CWarnMsg_Core_Observer_pp_WarningDisplay_WarningDisplayData = Rte_UclProxyCddWarningDisplayDataValue0;
  Rte_Ctrl_Dim_pSR_IlluminationData_IlluminationDataData = Rte_UclProxyCddIlluminationDataDataValue0;
  Rte_Ctrl_Dim_pp_Ctrl_Ready_to_Sleep_Ready_to_Sleep = FALSE;
  Rte_Ctrl_Dim_pp_IlumDayNightRequired_IlumDayNightRequired = 0U;
  Rte_Ctrl_Dim_pp_IlumDayNightStatus_Day_Night_Status = 0U;
  Rte_Ctrl_Dim_pp_StopPwmUpdate_channel_id = 0U;
  Rte_Ctrl_Illumination_pp_IllumCtrl_Op_IllumCtrl_Op_Data = Rte_View_IlluminationIllumCtrl_Op_DataValue0;
  Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate = 0U;
  Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode = 0U;
  Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus = 0U;
  Rte_Ctrl_WSS_pp_TFTDisplayOn_TFTDisplayOn = 0U;
  Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState = 0U;
  Rte_DltExt_pSR_DLTControlMessageReponse_DLTControlMessageReponseData = Rte_UclProxyCddDLTControlMessageReponseDataValue0;
  Rte_DltExt_pSR_DLTMessageReadRequest_DLTMessageReadRequestData = Rte_UclProxyCddDLTMessageReadRequestDataValue0;
  Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData = Rte_UclProxyCddPowerSystemStateReqChangeDataValue0;
  Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus = Rte_DmnMgrSDmnStatusValue0;
  Rte_FastGaugeAdapter_pp_FastGaugeInfo_FastGaugeInfoData = Rte_SFastGaugeInfo_InitValue;
  Rte_Mdl_Dim_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data = Rte_Ctrl_IlluminationIllumCtrl_Ip_DataValue0;
  Rte_Mdl_Dim_pp_IlumDayNightStatus_illumDNStatus = 0U;
  Rte_Mdl_Dim_pp_IlumStep_IllumStepValue = 0U;
  Rte_Mdl_Dim_pp_RheostatDayStep_RheostatDayStep = 0U;
  Rte_Mdl_Dim_pp_RheostatNightStep_RheostatNightStep = 0U;
  Rte_Mdl_Dim_pp_illumStarterstatus_StarterStatus_Out = 0U;
  Rte_Mdl_Dim_pp_illum_rheostat_change_RheoUpdateVal = 0U;
  Rte_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay = 0U;
  Rte_Mdl_Gear_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData = Rte_UclProxyCddShiftPosIndStatusDataValue0;
  Rte_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status = 0U;
  Rte_Mdl_Speed_pp_SPD_Selection_Table_Speed_Selection_Table = 0U;
  Rte_Mdl_Speed_pp_SPD_Target2_Status_Spd_Target2_Status = 0U;
  Rte_Mdl_Speed_pp_SPD_Target_Status_Spd_Target_Status = 0U;
  Rte_Mdl_Speed_pp_SPD_Trim2_Status_Spd_Trim2_Status = 0U;
  Rte_Mdl_Speed_pp_SPD_Trim_Status_Spd_Trim_Status = 0U;
  Rte_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho = 0U;
  Rte_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho = 0U;
  Rte_Mdl_Tacho_pp_Needle_Transparent_Needle_TR = 0U;
  Rte_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit = FALSE;
  Rte_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM = 0U;
  Rte_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX = 0U;
  Rte_Mdl_TurnHazard_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus = 0U;
  Rte_Mdl_TurnHazard_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus = 0U;
  Rte_Mdl_TurnHazard_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts = 0U;
  Rte_Mdl_TurnHazard_pp_TurnHazard_TurnR_Sts_RightIndicatorSts = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2 = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element = 0U;
  Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element = 0U;
  Rte_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted = FALSE;
  Rte_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted = FALSE;
  Rte_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted = FALSE;
  Rte_SlowGaugeAdapter_pp_SlowGaugeInfo_SlowGaugeInfoData = Rte_UclProxyCddSlowGaugeInfoDataValue0;
  Rte_UclProxyCdd_pSR_DLTControlMessageRequest_DLTControlMessageRequestData = Rte_DltExtDLTControlMessageRequestDataValue0;
  Rte_UclProxyCdd_pSR_DLTMessageReadAck_DLTMessageReadAckData = Rte_DltExtDLTMessageReadAckDataValue0;
  Rte_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData = Rte_CDisplayCddDisplayCurrentStateDataValue0;
  Rte_UclProxyCdd_pSR_HudWarningStatus_HudWarningStatusData = Rte_CWarnMsg_Core_ObserverHudWarningStatusDataValue0;
  Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData = Rte_DmnMgrPowerSystemStateDataValue0;
  Rte_UclProxyCdd_pSR_WarningStatus_WarningStatusData = Rte_CWarnMsg_Core_ObserverWarningStatusDataValue0;
  Rte_View_Speed_pp_Display_speed_Value_Digital_Speed_Value = 0U;
  Rte_View_Speed_pp_SubDisplaySpeed_Value_SubDispSpeedVal = 0U;

  /* reset Tx Ack Flags */
  Rte_OsApplication_NonTrusted_AckFlagsInit();
  Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = RTE_FBK_TRANSMIT_ACK;

  /* initialize transformation buffers */
  Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx_Length = 0;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxCurrentStateIC_CurrentStateIC(CurrentStateIC data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_CurrentStateIC_oIC_NMPDU_oCAN00_ffb15989_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte0_Debug1_Byte0(Debug1_Byte0 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug1_Byte0_oDebug_Frame1_oCAN00_7a3e08ee_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte1_Debug1_Byte1(Debug1_Byte1 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug1_Byte1_oDebug_Frame1_oCAN00_6d166c2e_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte2_Debug1_Byte2(Debug1_Byte2 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug1_Byte2_oDebug_Frame1_oCAN00_546ec16e_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte3_Debug1_Byte3(Debug1_Byte3 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug1_Byte3_oDebug_Frame1_oCAN00_4346a5ae_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte4_Debug1_Byte4(Debug1_Byte4 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug1_Byte4_oDebug_Frame1_oCAN00_269f9bee_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte5_Debug1_Byte5(Debug1_Byte5 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug1_Byte5_oDebug_Frame1_oCAN00_31b7ff2e_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte6_Debug1_Byte6(Debug1_Byte6 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug1_Byte6_oDebug_Frame1_oCAN00_08cf526e_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug1_Byte7_Debug1_Byte7(Debug1_Byte7 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug1_Byte7_oDebug_Frame1_oCAN00_1fe736ae_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte0_Debug2_Byte0(Debug2_Byte0 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug2_Byte0_oDebug_Frame2_oCAN00_f66f082a_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte1_Debug2_Byte1(Debug2_Byte1 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug2_Byte1_oDebug_Frame2_oCAN00_e1476cea_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte2_Debug2_Byte2(Debug2_Byte2 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug2_Byte2_oDebug_Frame2_oCAN00_d83fc1aa_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte3_Debug2_Byte3(Debug2_Byte3 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug2_Byte3_oDebug_Frame2_oCAN00_cf17a56a_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte4_Debug2_Byte4(Debug2_Byte4 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug2_Byte4_oDebug_Frame2_oCAN00_aace9b2a_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte5_Debug2_Byte5(Debug2_Byte5 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug2_Byte5_oDebug_Frame2_oCAN00_bde6ffea_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte6_Debug2_Byte6(Debug2_Byte6 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug2_Byte6_oDebug_Frame2_oCAN00_849e52aa_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug2_Byte7_Debug2_Byte7(Debug2_Byte7 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug2_Byte7_oDebug_Frame2_oCAN00_93b6366a_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte0_Debug3_Byte0(Debug3_Byte0 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug3_Byte0_oDebug_Frame3_oCAN00_3b70f5a9_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte1_Debug3_Byte1(Debug3_Byte1 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug3_Byte1_oDebug_Frame3_oCAN00_2c589169_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte2_Debug3_Byte2(Debug3_Byte2 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug3_Byte2_oDebug_Frame3_oCAN00_15203c29_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte3_Debug3_Byte3(Debug3_Byte3 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug3_Byte3_oDebug_Frame3_oCAN00_020858e9_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte4_Debug3_Byte4(Debug3_Byte4 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug3_Byte4_oDebug_Frame3_oCAN00_67d166a9_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte5_Debug3_Byte5(Debug3_Byte5 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug3_Byte5_oDebug_Frame3_oCAN00_70f90269_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte6_Debug3_Byte6(Debug3_Byte6 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug3_Byte6_oDebug_Frame3_oCAN00_4981af29_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug3_Byte7_Debug3_Byte7(Debug3_Byte7 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug3_Byte7_oDebug_Frame3_oCAN00_5ea9cbe9_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte0_Debug4_Byte0(Debug4_Byte0 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug4_Byte0_oDebug_Frame4_oCAN00_35bc0fe3_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte1_Debug4_Byte1(Debug4_Byte1 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug4_Byte1_oDebug_Frame4_oCAN00_22946b23_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte2_Debug4_Byte2(Debug4_Byte2 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug4_Byte2_oDebug_Frame4_oCAN00_1becc663_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte3_Debug4_Byte3(Debug4_Byte3 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug4_Byte3_oDebug_Frame4_oCAN00_0cc4a2a3_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte4_Debug4_Byte4(Debug4_Byte4 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug4_Byte4_oDebug_Frame4_oCAN00_691d9ce3_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte5_Debug4_Byte5(Debug4_Byte5 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug4_Byte5_oDebug_Frame4_oCAN00_7e35f823_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte6_Debug4_Byte6(Debug4_Byte6 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug4_Byte6_oDebug_Frame4_oCAN00_474d5563_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug4_Byte7_Debug4_Byte7(Debug4_Byte7 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug4_Byte7_oDebug_Frame4_oCAN00_506531a3_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte0_Debug5_Byte0(Debug5_Byte0 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug5_Byte0_oDebug_Frame5_oCAN00_f8a3f260_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte1_Debug5_Byte1(Debug5_Byte1 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug5_Byte1_oDebug_Frame5_oCAN00_ef8b96a0_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte2_Debug5_Byte2(Debug5_Byte2 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug5_Byte2_oDebug_Frame5_oCAN00_d6f33be0_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte3_Debug5_Byte3(Debug5_Byte3 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug5_Byte3_oDebug_Frame5_oCAN00_c1db5f20_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte4_Debug5_Byte4(Debug5_Byte4 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug5_Byte4_oDebug_Frame5_oCAN00_a4026160_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte5_Debug5_Byte5(Debug5_Byte5 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug5_Byte5_oDebug_Frame5_oCAN00_b32a05a0_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte6_Debug5_Byte6(Debug5_Byte6 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug5_Byte6_oDebug_Frame5_oCAN00_8a52a8e0_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDebug5_Byte7_Debug5_Byte7(Debug5_Byte7 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Debug5_Byte7_oDebug_Frame5_oCAN00_9d7acc20_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT(P2CONST(Diag_Buffer_Tx_USDT, AUTOMATIC, RTE_CCOMABSMDL_STUBS_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Diag_Buffer_Tx_USDT_oDiag_Resp_USDT_oCAN00_3c21528d_Tx, *(data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT(P2CONST(Diag_Buffer_Tx_UUDT, AUTOMATIC, RTE_CCOMABSMDL_STUBS_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Diag_Buffer_Tx_UUDT_oDiag_Resp_UUDT_oCAN00_0ee1ff7b_Tx, *(data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxFV_Tx_FV_Tx(FV_Tx data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_FV_Tx_oCluster_Secure_Tx_oCAN00_f077ac5c_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxIllumination_PWM_Illumination_PWM(Illumination_PWM data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Illumination_PWM_oCluster_Tx_Reduced_Com_oCAN00_0a670875_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxMAC_Tx_MAC_Tx(MAC_Tx data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_MAC_Tx_oCluster_Secure_Tx_oCAN00_b83a6da7_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxOdometer_Odometer(Odometer data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_Odometer_oCluster_Tx_Normal_COM_LS_oCAN00_3e00d027_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxPreviousStateIC_PreviousStateIC(PreviousStateIC data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_PreviousStateIC_oIC_NMPDU_oCAN00_54068aa2_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte0_SecureTxByte0(SecureTxByte0 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_SecureTxByte0_oCluster_Secure_Tx_oCAN00_659a0722_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte1_SecureTxByte1(SecureTxByte1 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_SecureTxByte1_oCluster_Secure_Tx_oCAN00_0b161c63_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte2_SecureTxByte2(SecureTxByte2 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_SecureTxByte2_oCluster_Secure_Tx_oCAN00_b88231a0_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxSecureTxByte3_SecureTxByte3(SecureTxByte3 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_SecureTxByte3_oCluster_Secure_Tx_oCAN00_d60e2ae1_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData1_IC_UserData1_IC(UserData1_IC data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_UserData1_IC_oIC_NMPDU_oCAN00_7de7a39d_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData2_IC_UserData2_IC(UserData2_IC data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_UserData2_IC_oIC_NMPDU_oCAN00_06f9217e_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData3_IC_UserData3_IC(UserData3_IC data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_UserData3_IC_oIC_NMPDU_oCAN00_9923a2e0_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData4_IC_UserData4_IC(UserData4_IC data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_UserData4_IC_oIC_NMPDU_oCAN00_f0c424b8_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxUserData5_IC_UserData5_IC(UserData5_IC data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_UserData5_IC_oIC_NMPDU_oCAN00_6f1ea726_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CComAbsMdl_stubs_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC(VehicleSpeedIC data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_VehicleSpeedIC_oCluster_Tx_Normal_COM_MS_oCAN00_1b17fdcc_Tx, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_CMeetCdd_pSR_DiagDIDRequest_DiagDIDRequestData(P2CONST(SDiagDIDRequest, AUTOMATIC, RTE_CMEETCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_DiagDIDRequest */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_DiagDIDRequest); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_CMeetCdd_pSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(P2CONST(SDiagIOCtrlRequest, AUTOMATIC, RTE_CMEETCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_DiagIOCtrlRequest */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_DiagIOCtrlRequest); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_CMeetCdd_pSR_DiagRoutineRequest_DiagRoutineRequestData(P2CONST(SDiagRoutineRequest, AUTOMATIC, RTE_CMEETCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_DiagRoutineRequest */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_DiagRoutineRequest); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_CUpdateCdd_pp_SR_UpdateLongServiceRequest_UpdateLongServiceReqData(P2CONST(SUpdateLongServiceReq, AUTOMATIC, RTE_CUPDATECDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData = 1;
    Rte_EnableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_UpdateLongServiceReq */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_UpdateLongServiceReq); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_CUpdateCdd_pp_SR_UpdateShortServiceRequest_UpdateShortServiceReqData(P2CONST(SUpdateShortServiceReq, AUTOMATIC, RTE_CUPDATECDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData = 1;
    Rte_EnableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_UpdateShortServiceReq */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_UpdateShortServiceReq); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CWarnMsg_Core_Observer_pp_HUDWarningDisplay_HudWarningDisplayData(P2CONST(SHudWarningDisplay, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CWarnMsg_Core_Observer_pp_HUDWarningDisplay_HudWarningDisplayData = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CWarnMsg_Core_Observer_pp_TPMSWarnPayload_TpmsWarningDataData(P2CONST(STpmsWarningData, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CWarnMsg_Core_Observer_pp_TPMSWarnPayload_TpmsWarningDataData = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CWarnMsg_Core_Observer_pp_WarningDisplay_WarningDisplayData(P2CONST(SWarningDisplay, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CWarnMsg_Core_Observer_pp_WarningDisplay_WarningDisplayData = *(data);
  /* scheduled trigger for runnables: OnDre_WarningDisplay */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ctrl_Dim_pSR_IlluminationData_IlluminationDataData(P2CONST(SIlluminationData, AUTOMATIC, RTE_CTRL_DIM_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_Ctrl_Dim_pSR_IlluminationData_IlluminationDataData = *(data);
  /* scheduled trigger for runnables: OnDre_IlluminationData */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_IlluminationData); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ctrl_Illumination_pp_IllumCtrl_Op_IllumCtrl_Op_Data(P2CONST(IllumCtrl_Op, AUTOMATIC, RTE_CTRL_ILLUMINATION_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_Ctrl_Illumination_pp_IllumCtrl_Op_IllumCtrl_Op_Data = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DltExt_pSR_DLTControlMessageReponse_DLTControlMessageReponseData(P2CONST(SDLTControlMessageReponse, AUTOMATIC, RTE_DLTEXT_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DltExt_pSR_DLTControlMessageReponse_DLTControlMessageReponseData = *(data);
  /* scheduled trigger for runnables: OnDre_DLTControlMessageReponse */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_DLTControlMessageReponse); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DltExt_pSR_DLTMessageReadRequest_DLTMessageReadRequestData(P2CONST(SDLTMessageReadRequest, AUTOMATIC, RTE_DLTEXT_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DltExt_pSR_DLTMessageReadRequest_DLTMessageReadRequestData = *(data);
  /* scheduled trigger for runnables: OnDre_DLTMessageReadRequest */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_DLTMessageReadRequest); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_DmnMgr_pSR_HealthDumpGetData_HealthDumpGetDataData(P2CONST(SHealthDumpGetData, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_HealthDumpGetData */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_DmnMgr_pSR_HealthDumpGetHdr_HealthDumpGetHdrData(P2CONST(SHealthDumpGetHdr, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_HealthDumpGetHdr */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(P2CONST(SPowerSystemStateReqChange, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData = *(data);
  /* scheduled trigger for runnables: OnDre_PowerSystemStateReqChange */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DmnMgr_ppSR_DmnInfo_SDmnStatus(P2CONST(SDmnStatus, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_FastGaugeAdapter_pp_FastGaugeInfo_FastGaugeInfoData(P2CONST(SFastGaugeInfo, AUTOMATIC, RTE_FASTGAUGEADAPTER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_FastGaugeAdapter_pp_FastGaugeInfo_FastGaugeInfoData = *(data);
  /* scheduled trigger for runnables: OnDre_FastGaugeInfo */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_FastGaugeInfo); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Mdl_Dim_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data(P2CONST(IllumCtrl_Ip, AUTOMATIC, RTE_MDL_DIM_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_Mdl_Dim_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Mdl_Gear_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData(P2CONST(SShiftPosIndStatus, AUTOMATIC, RTE_MDL_GEAR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_Mdl_Gear_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData = *(data);
  /* scheduled trigger for runnables: OnDre_ShiftPosIndStatus */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_ShiftPosIndStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Audio_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio.BsConst_Audio_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_Value(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_BsConst_Illumination_ReservedByte, *(data), sizeof(Arr_u8_28));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_BsConst_Illumination_ReservedByte_SafeCopy1, *(data), sizeof(Arr_u8_28));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_BsConst_Illumination_ReservedByte_SafeCopy2, *(data), sizeof(Arr_u8_28));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Communication_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication.BsConst_Communication_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_Value(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Compensation_Line_Shift_b = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy1_Value(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Compensation_Line_Shift_b_SafeCopy1 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Shift_b_SafeCopy2_Value(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Compensation_Line_Shift_b_SafeCopy2 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_Value(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Compensation_Line_Slope_m = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy1_Value(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Compensation_Line_Slope_m_SafeCopy1 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Compensation_Line_Slope_m_SafeCopy2_Value(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Compensation_Line_Slope_m_SafeCopy2 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Derating_Backlight_Disable = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy1_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Derating_Backlight_Disable_SafeCopy1 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Derating_Backlight_Disable_SafeCopy2_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Derating_Backlight_Disable_SafeCopy2 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_Value(uint16 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Display_Illum_Max_Level = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy1_Value(uint16 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Display_Illum_Max_Level_SafeCopy1 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Display_Illum_Max_Level_SafeCopy2_Value(uint16 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Display_Illum_Max_Level_SafeCopy2 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_EngOffTimer_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer.BsConst_EngOffTimer_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_FuelGauge_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge.BsConst_FuelGauge_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Lookup_Curve_HotSpot_Coef_X, *(data), sizeof(Arr_u16_7));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1, *(data), sizeof(Arr_u16_7));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2, *(data), sizeof(Arr_u16_7));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Lookup_Curve_HotSpot_Coef_Y, *(data), sizeof(Arr_u16_7));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1, *(data), sizeof(Arr_u16_7));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2, *(data), sizeof(Arr_u16_7));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_OilGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge.BsConst_OilGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_PCB_Temperature_Sensor_Conv, *(data), sizeof(T_NV_Temperature_Conversion));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1, *(data), sizeof(T_NV_Temperature_Conversion));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2, *(data), sizeof(T_NV_Temperature_Conversion));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_PWM_boost_bypass_duty = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy1_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_PWM_boost_bypass_duty_SafeCopy1 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PWM_boost_bypass_duty_SafeCopy2_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_PWM_boost_bypass_duty_SafeCopy2 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PowerGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge.BsConst_PowerGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Power_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power.BsConst_Power_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_RealTimeClock_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock.BsConst_RealTimeClock_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_ServiceReminder_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder.BsConst_ServiceReminder_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_SpeedoGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge.BsConst_SpeedoGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TachoGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge.BsConst_TachoGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TempGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge.BsConst_TempGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Temp_Threshold_Hysteresis_Derating = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Temperature_Sensor_Conv, *(data), sizeof(T_NV_Temperature_Conversion));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Temperature_Sensor_Conv_SafeCopy1, *(data), sizeof(T_NV_Temperature_Conversion));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Temperature_Sensor_Conv_SafeCopy2, *(data), sizeof(T_NV_Temperature_Conversion));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TripComputer_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer.BsConst_TripComputer_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Warning_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning.BsConst_Warning_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsCys_Certicificate_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate.BsCys_Certicificate_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsDiag_Dtc_Element_Value(P2CONST(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc.BsDiag_Dtc_Element, *(data), sizeof(Arr_u8_2048));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsDiag_ErrorRecord_Element_Value(P2CONST(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord.BsDiag_ErrorRecord_Element, *(data), sizeof(Arr_u8_1024));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Audio_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio.BsReten_Audio_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Communication_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication.BsReten_Communication_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Display_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display.BsReten_Display_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Gauges_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges.BsReten_Gauges_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Illumination_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination.BsReten_Illumination_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Odometer_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer.BsReten_Odometer_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Personalization_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization.BsReten_Personalization_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Power_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power.BsReten_Power_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_RealTimeClock_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock.BsReten_RealTimeClock_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Tripcomputer_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer.BsReten_Tripcomputer_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Warning_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning.BsReten_Warning_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_CusDlt_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt.BsRt_CusDlt_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_FuelGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge.BsRt_FuelGauge_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Illumination_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination.BsRt_Illumination_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Odometer_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer.BsRt_Odometer_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_OilGauge_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge.BsRt_OilGauge_Element, *(data), sizeof(Arr_u8_8));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Personalization_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization.BsRt_Personalization_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_PowerGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge.BsRt_PowerGauge_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_RealTimeClock_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock.BsRt_RealTimeClock_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_SpeedoGauge_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge.BsRt_SpeedoGauge_Element, *(data), sizeof(Arr_u8_8));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TachoGauge_Element_Value(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge.BsRt_TachoGauge_Element, *(data), sizeof(Arr_u8_16));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TempGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge.BsRt_TempGauge_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TripComputer_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer.BsRt_TripComputer_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Warning_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning.BsRt_Warning_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_AssemblyManufacturingDate_Value(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_AssemblyManufacturingDate, *(data), sizeof(Arr_u8_3));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_AssemblyPlantNumber_Value(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_AssemblyPlantNumber, *(data), sizeof(Arr_u8_3));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_EcuPartNumber_Element_Value(P2CONST(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_EcuPartNumber_Element, *(data), sizeof(Arr_u8_61));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_HWModification_Value(uint16 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_HWModification = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_PCBSerialNumber_Value(P2CONST(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_PCBSerialNumber, *(data), sizeof(Arr_u8_9));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_ProductSerialNumber_Value(P2CONST(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_ProductSerialNumber, *(data), sizeof(Arr_u8_10));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SMTManufacturingDate_Value(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_SMTManufacturingDate, *(data), sizeof(Arr_u8_3));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SMTPlantNumber_Value(P2CONST(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_SMTPlantNumber, *(data), sizeof(Arr_u8_3));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint.BsShare_SwUpdFotaFinPrint_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode.BsShare_SwUpdFotaMode_Element, *(data), sizeof(Arr_u8_16));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus.BsShare_SwUpdFotaStatus_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt.BsShare_SwUpdFotadecrypt_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdReflash_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash.BsShare_SwUpdReflash_Element, *(data), sizeof(Arr_u8_8));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VehicleConfig_Element_Value(P2CONST(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig.BsShare_VehicleConfig_Element, *(data), sizeof(Arr_u8_256));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisMeet_EOLEntry_Element_Value(uint16 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_EOLEntry_Element = *(&data);
  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisMeet_Element_Value(P2CONST(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_Element, *(data), sizeof(Arr_u8_46));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisteonPCBPartNumber_Value(P2CONST(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_VisteonPCBPartNumber, *(data), sizeof(Arr_u8_17));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisteonPartNumber_Value(P2CONST(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_VisteonPartNumber, *(data), sizeof(Arr_u8_17));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_RefCys_Certicificate1_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1.RefCys_Certicificate1_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_RefCys_Certicificate_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate.RefCys_Certicificate_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate = 1;
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SlowGaugeAdapter_pp_SlowGaugeInfo_SlowGaugeInfoData(P2CONST(SSlowGuageInfo, AUTOMATIC, RTE_SLOWGAUGEADAPTER_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_SlowGaugeAdapter_pp_SlowGaugeInfo_SlowGaugeInfoData = *(data);
  /* scheduled trigger for runnables: OnDre_SlowGaugeInfo */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_SlowGaugeInfo); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_DiagResponse_DiagResponseData(P2CONST(SDiagResponse, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_CMeetCdd_rSR_DiagResponse_DiagResponseData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_CMeetCdd_rSR_DiagResponse_DiagResponseData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(P2CONST(SHealthDomainFatalError, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnHealthFatalError */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(P2CONST(SHealthDomainHeartbeat, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnHeartBeat */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDumpData_HealthDumpDataData(P2CONST(SHealthDumpData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnHealthDumpData */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(P2CONST(SHealthDumpHdrInfo, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnHealthDumpHdrInfo */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(P2CONST(SMainHMIReadyStatus, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(P2CONST(SPowerExtendShutdownTime, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnExtendShutdownTime */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(P2CONST(SPowerKeepSystemAwake, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnKeepSystemAwake */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(P2CONST(SUpdateShortServiceResp, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementOsApplication_NonTrusted(RTE_Q_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData = 1;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: CUpdateCdd_OnDre_UpdateResponse */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_CUpdateCdd_CUpdateCdd_OnDre_UpdateResponse); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(P2CONST(SDLTControlMessageRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_UclProxyCdd_pSR_DLTControlMessageRequest_DLTControlMessageRequestData = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_DLTMessageReadAck_DLTMessageReadAckData(P2CONST(SDLTMessageReadAck, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_UclProxyCdd_pSR_DLTMessageReadAck_DLTMessageReadAckData = *(data);
  /* scheduled trigger for runnables: DltExt_OnDreDLTMessageReadAckData */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_DltExt_DltExt_OnDreDLTMessageReadAckData); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData(P2CONST(SDisplayCurrentState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_HudWarningStatus_HudWarningStatusData(P2CONST(SHudWarningStatus, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_UclProxyCdd_pSR_HudWarningStatus_HudWarningStatusData = *(data);
  /* scheduled trigger for runnables: OnDre_UCL_HudWarnStatus */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_HudWarnStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData(P2CONST(SPowerSystemState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData = *(data);
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnPowerSystemState */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_WarningStatus_WarningStatusData(P2CONST(SWarningStatus, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_UclProxyCdd_pSR_WarningStatus_WarningStatusData = *(data);
  /* scheduled trigger for runnables: OnDre_UCL_WarnStatus */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_WarnStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_CMeetCdd_rSR_DiagResponse_DiagResponseData(P2VAR(SDiagResponse, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_CMeetCdd_rSR_DiagResponse_DiagResponseData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_CMeetCdd_rSR_DiagResponse_DiagResponseData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_CMeetCdd_rSR_DiagResponse_DiagResponseData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CSigCdd_rp_SigData_sig0_port(P2VAR(SIG_WIN_SETUP_T, AUTOMATIC, RTE_CSIGCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CSwcDispMonSf_pp_SigData_sig0_port;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData(P2VAR(SUpdateShortServiceResp, AUTOMATIC, RTE_CUPDATECDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CWarnMsg_Core_Observer_rp_HUDWarningStatus_HudWarningStatusData(P2VAR(SHudWarningStatus, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_UclProxyCdd_pSR_HudWarningStatus_HudWarningStatusData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CWarnMsg_Core_Observer_rp_WarningStatus_WarningStatusData(P2VAR(SWarningStatus, AUTOMATIC, RTE_CWARNMSG_CORE_OBSERVER_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_UclProxyCdd_pSR_WarningStatus_WarningStatusData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ctrl_Illumination_rp_IllumCtrl_Ip_IllumCtrl_Ip_Data(P2VAR(IllumCtrl_Ip, AUTOMATIC, RTE_CTRL_ILLUMINATION_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_Mdl_Dim_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_Ctrl_WSS_rpCS_EcuMExt_FuelLidStatus_FuelLidStatus(P2VAR(BOOL_TYPE, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  data = data;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_Ctrl_WSS_rpCS_EcuMExt_HazardStatus_HazardStatus(P2VAR(BOOL_TYPE, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  data = data;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData(P2VAR(SMainHMIReadyStatus, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ctrl_WSS_rpTelltaleStatusOP_TelltaleOpArray(P2VAR(TT_OP_Type, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_MemCpy32(*(data), Rte_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray, sizeof(TT_OP_Type));

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ctrl_WSS_rp_BlinkStsArray_TTBlinkStatusArray(P2VAR(TTBlinkArray, AUTOMATIC, RTE_CTRL_WSS_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_MemCpy32(*(data), Rte_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray, sizeof(TTBlinkArray));

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DltExt_rSR_DLTControlMessageRequest_DLTControlMessageRequestData(P2VAR(SDLTControlMessageRequest, AUTOMATIC, RTE_DLTEXT_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_UclProxyCdd_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DltExt_rSR_DLTMessageReadAck_DLTMessageReadAckData(P2VAR(SDLTMessageReadAck, AUTOMATIC, RTE_DLTEXT_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_UclProxyCdd_pSR_DLTMessageReadAck_DLTMessageReadAckData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(P2VAR(SHealthDomainFatalError, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(P2VAR(SHealthDomainHeartbeat, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDumpData_HealthDumpDataData(P2VAR(SHealthDumpData, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(P2VAR(SHealthDumpHdrInfo, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(P2VAR(SPowerExtendShutdownTime, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(P2VAR(SPowerKeepSystemAwake, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DmnMgr_rSR_PowerSystemState_PowerSystemStateData(P2VAR(SPowerSystemState, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DmnMgr_rpSR_DmnInfo_SDmnStatus(P2VAR(SDmnStatus, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Audio_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio.BsConst_Audio_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_Value(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_BsConst_Illumination_ReservedByte, sizeof(Arr_u8_28));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Value(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_BsConst_Illumination_ReservedByte_SafeCopy1, sizeof(Arr_u8_28));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Value(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_BsConst_Illumination_ReservedByte_SafeCopy2, sizeof(Arr_u8_28));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Communication_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication.BsConst_Communication_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_EngOffTimer_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer.BsConst_EngOffTimer_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_FuelGauge_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge.BsConst_FuelGauge_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Lookup_Curve_HotSpot_Coef_X, sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1, sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2, sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Lookup_Curve_HotSpot_Coef_Y, sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1, sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2, sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_OilGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge.BsConst_OilGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_PCB_Temperature_Sensor_Conv, sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1, sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2, sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PowerGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge.BsConst_PowerGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Power_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power.BsConst_Power_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_RealTimeClock_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock.BsConst_RealTimeClock_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_ServiceReminder_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder.BsConst_ServiceReminder_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_SpeedoGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge.BsConst_SpeedoGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TachoGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge.BsConst_TachoGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TempGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge.BsConst_TempGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Temperature_Sensor_Conv, sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy1_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1.BsConst_Temperature_Sensor_Conv_SafeCopy1, sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Temperature_Sensor_Conv_SafeCopy2_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2.BsConst_Temperature_Sensor_Conv_SafeCopy2, sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TripComputer_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer.BsConst_TripComputer_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Warning_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning.BsConst_Warning_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsCys_Certicificate_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate.BsCys_Certicificate_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsDiag_Dtc_Element_Value(P2VAR(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc.BsDiag_Dtc_Element, sizeof(Arr_u8_2048));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsDiag_ErrorRecord_Element_Value(P2VAR(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord.BsDiag_ErrorRecord_Element, sizeof(Arr_u8_1024));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Audio_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio.BsReten_Audio_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Communication_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication.BsReten_Communication_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Display_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display.BsReten_Display_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Gauges_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges.BsReten_Gauges_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Illumination_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination.BsReten_Illumination_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Odometer_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer.BsReten_Odometer_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Personalization_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization.BsReten_Personalization_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Power_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power.BsReten_Power_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_RealTimeClock_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock.BsReten_RealTimeClock_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Tripcomputer_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer.BsReten_Tripcomputer_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Warning_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning.BsReten_Warning_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_CusDlt_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt.BsRt_CusDlt_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_FuelGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge.BsRt_FuelGauge_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Illumination_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination.BsRt_Illumination_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Odometer_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer.BsRt_Odometer_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_OilGauge_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge.BsRt_OilGauge_Element, sizeof(Arr_u8_8));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Personalization_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization.BsRt_Personalization_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_PowerGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge.BsRt_PowerGauge_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_RealTimeClock_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock.BsRt_RealTimeClock_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_SpeedoGauge_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge.BsRt_SpeedoGauge_Element, sizeof(Arr_u8_8));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TachoGauge_Element_Value(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge.BsRt_TachoGauge_Element, sizeof(Arr_u8_16));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TempGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge.BsRt_TempGauge_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TripComputer_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer.BsRt_TripComputer_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Warning_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning.BsRt_Warning_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_AssemblyManufacturingDate_Value(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_AssemblyManufacturingDate, sizeof(Arr_u8_3));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_AssemblyPlantNumber_Value(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_AssemblyPlantNumber, sizeof(Arr_u8_3));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_EcuPartNumber_Element_Value(P2VAR(Arr_u8_61, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_EcuPartNumber_Element, sizeof(Arr_u8_61));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_PCBSerialNumber_Value(P2VAR(Arr_u8_9, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_PCBSerialNumber, sizeof(Arr_u8_9));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_ProductSerialNumber_Value(P2VAR(Arr_u8_10, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_ProductSerialNumber, sizeof(Arr_u8_10));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SMTManufacturingDate_Value(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_SMTManufacturingDate, sizeof(Arr_u8_3));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SMTPlantNumber_Value(P2VAR(Arr_u8_3, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_SMTPlantNumber, sizeof(Arr_u8_3));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint.BsShare_SwUpdFotaFinPrint_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode.BsShare_SwUpdFotaMode_Element, sizeof(Arr_u8_16));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus.BsShare_SwUpdFotaStatus_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt.BsShare_SwUpdFotadecrypt_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdReflash_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash.BsShare_SwUpdReflash_Element, sizeof(Arr_u8_8));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VehicleConfig_Element_Value(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig.BsShare_VehicleConfig_Element, sizeof(Arr_u8_256));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisMeet_Element_Value(P2VAR(Arr_u8_46, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_Element, sizeof(Arr_u8_46));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisteonPCBPartNumber_Value(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_VisteonPCBPartNumber, sizeof(Arr_u8_17));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisteonPartNumber_Value(P2VAR(Arr_u8_17, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_VisteonPartNumber, sizeof(Arr_u8_17));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_RefCys_Certicificate1_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1.RefCys_Certicificate1_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_RefCys_Certicificate_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate.RefCys_Certicificate_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Test_Comp_pSR_DisplayCurrentState_DisplayCurrentStateData(P2VAR(SDisplayCurrentState, AUTOMATIC, RTE_TEST_COMP_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Test_Comp_pSR_PowerSystemState_PowerSystemStateData(P2VAR(SPowerSystemState, AUTOMATIC, RTE_TEST_COMP_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData(P2VAR(SDiagDIDRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(P2VAR(SDiagIOCtrlRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData(P2VAR(SDiagRoutineRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData(P2VAR(SHealthDumpGetData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(P2VAR(SHealthDumpGetHdr, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_IgnState_IgnStateData(P2VAR(SIgnState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  data = data;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(P2VAR(SUpdateLongServiceReq, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(P2VAR(SUpdateShortServiceReq, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementOsApplication_NonTrusted(RTE_Q_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
    if (retQueue == RTE_Q_EMPTY)
    {
      ret = RTE_E_NO_DATA;
    }
    ret |= lost_data;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(P2VAR(SDLTControlMessageReponse, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_DltExt_pSR_DLTControlMessageReponse_DLTControlMessageReponseData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(P2VAR(SDLTMessageReadRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_DltExt_pSR_DLTMessageReadRequest_DLTMessageReadRequestData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_DisplaySetPower_DisplaySetPowerData(P2VAR(SDisplaySetPower, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_FastGaugeInfo_FastGaugeInfoData(P2VAR(SFastGaugeInfo, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_FastGaugeAdapter_pp_FastGaugeInfo_FastGaugeInfoData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_HudWarningDisplay_HudWarningDisplayData(P2VAR(SHudWarningDisplay, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CWarnMsg_Core_Observer_pp_HUDWarningDisplay_HudWarningDisplayData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_IlluminationData_IlluminationDataData(P2VAR(SIlluminationData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_Ctrl_Dim_pSR_IlluminationData_IlluminationDataData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(P2VAR(SPowerSystemStateReqChange, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(P2VAR(SShiftPosIndStatus, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_Mdl_Gear_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_SlowGaugeInfo_SlowGaugeInfoData(P2VAR(SSlowGuageInfo, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_SlowGaugeAdapter_pp_SlowGaugeInfo_SlowGaugeInfoData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_TT_Status_TT_StatusData(P2VAR(STT_Status, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CView_Telltale_ppTelltaleSts_TT_StatusData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_TpmsWarningData_TpmsWarningDataData(P2VAR(STpmsWarningData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CWarnMsg_Core_Observer_pp_TPMSWarnPayload_TpmsWarningDataData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_WarningDisplay_WarningDisplayData(P2VAR(SWarningDisplay, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_CWarnMsg_Core_Observer_pp_WarningDisplay_WarningDisplayData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_View_Illumination_rp_IllumCtrl_Op_IllumCtrl_Op_Data(P2VAR(IllumCtrl_Op, AUTOMATIC, RTE_VIEW_ILLUMINATION_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_Ctrl_Illumination_pp_IllumCtrl_Op_IllumCtrl_Op_Data;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_Audio(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_Communication(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_EngOffTimer(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_FuelGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy1(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_Safe_NotifyJobEnd_BsConst_Illumination_Copy2(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_OilGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_Power(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_PowerGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_RealTimeClock(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_ServiceReminder(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_SpeedoGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_TachoGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_TempGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_TripComputer(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsConst_Warning(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsCys_Certicificate(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsDiag_Dtc(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsDiag_ErrorRecord(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Audio(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Communication(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Display(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Gauges(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Illumination(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Odometer(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Personalization(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Power(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_RealTimeClock(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Tripcomputer(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_Warning(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_CusDlt(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_FuelGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_Illumination(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_Odometer(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_OilGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_Personalization(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_PowerGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_RealTimeClock(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_SpeedoGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_TachoGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_TempGauge(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_TripComputer(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsRt_Warning(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsShare_EcuPartNumber(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaFinPrint(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaMode(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotaStatus(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdFotadecrypt(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsShare_SwUpdReflash(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsShare_VehicleConfig(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsShare_VisMeet(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_RefCys_Certicificate1(ServiceId, JobResult);

  return ret;
}


/**********************************************************************************************************************
 * Queue handling functions
 *********************************************************************************************************************/
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QAddElementOsApplication_NonTrusted(Rte_QIndexType q, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) pData)
{
  Rte_QReturnType ret = RTE_Q_FULL;
  P2VAR(Rte_QRamInfoType, AUTOMATIC, RTE_VAR_NOINIT) pRamI = &(Rte_QRamInfo[q]);
  P2CONST(Rte_QRomInfoType, AUTOMATIC, RTE_CONST) pRomI = &(Rte_QRomInfo[q]);

  Rte_DisableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if (pRamI->Rte_ElementCtr < pRomI->Rte_MaxElements)
  {
    uint8 writeCtr = pRamI->Rte_WriteCtr;
    if (writeCtr < (pRomI->Rte_MaxElements - 1U))
    {
      ++writeCtr;
    }
    else
    {
      writeCtr = 0U;
    }
    pRamI->Rte_WriteCtr = writeCtr;
    pRamI->Rte_ElementCtr++;
    Rte_MemCpy((void *)&((uint8 *)pRomI->Rte_BasePtr)[writeCtr * pRomI->Rte_BytesPerElement], pData, pRomI->Rte_BytesPerElement);
    ret = RTE_Q_OK;
  }
  Rte_EnableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return(ret);
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QUnqueueElementOsApplication_NonTrusted(Rte_QIndexType q, P2VAR(void, AUTOMATIC, RTE_APPL_VAR) pData)
{
  Rte_QReturnType ret = RTE_Q_EMPTY;
  P2VAR(Rte_QRamInfoType, AUTOMATIC, RTE_VAR_NOINIT) pRamI = &(Rte_QRamInfo[q]); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2CONST(Rte_QRomInfoType, AUTOMATIC, RTE_CONST) pRomI = &(Rte_QRomInfo[q]); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  Rte_DisableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if (0 < pRamI->Rte_ElementCtr)
  {
    uint8 readCtr = pRamI->Rte_ReadCtr;
    if (readCtr < (pRomI->Rte_MaxElements - 1U))
    {
      ++readCtr;
    }
    else
    {
      readCtr = 0U;
    }
    pRamI->Rte_ReadCtr = readCtr;
    pRamI->Rte_ElementCtr--;
    Rte_MemCpy(pData, (void *)&((uint8 *)pRomI->Rte_BasePtr)[readCtr * pRomI->Rte_BytesPerElement], pRomI->Rte_BytesPerElement);
    ret = RTE_Q_OK;
  }
  Rte_EnableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return(ret);
}
/* PRQA L:L1 */


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_EcuM_currentMode_currentMode(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_currentMode_currentMode(EcuM_StateType nextMode) /* PRQA S 0850, 1505, 3206 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK;

  nextMode = nextMode;

  return ret;
}

/**********************************************************************************************************************
 * Runnable Entities for Nv Block Components
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * Runnable Entity Name: NvBlockSwComponentTypeRunnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Audio_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_BsConst_Illumination_ReservedByte>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_BsConst_Illumination_ReservedByte_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_BsConst_Illumination_ReservedByte_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Communication_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Compensation_Line_Shift_b>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Compensation_Line_Shift_b_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Compensation_Line_Shift_b_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Compensation_Line_Slope_m>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Compensation_Line_Slope_m_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Compensation_Line_Slope_m_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Derating_Backlight_Disable>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Derating_Backlight_Disable_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Derating_Backlight_Disable_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Display_Illum_Max_Level>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Display_Illum_Max_Level_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Display_Illum_Max_Level_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_EngOffTimer_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_FuelGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Lookup_Curve_HotSpot_Coef_X>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Lookup_Curve_HotSpot_Coef_Y>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_OilGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_PCB_Temperature_Sensor_Conv>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_PWM_boost_bypass_duty>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_PWM_boost_bypass_duty_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_PWM_boost_bypass_duty_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_PowerGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Power_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_RealTimeClock_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_ServiceReminder_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_SpeedoGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_TachoGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_TempGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Temp_Threshold_Hysteresis_Derating>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Temperature_Sensor_Conv>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Temperature_Sensor_Conv_SafeCopy1>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Temperature_Sensor_Conv_SafeCopy2>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_TripComputer_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Warning_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsCys_Certicificate_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsDiag_Dtc_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsDiag_ErrorRecord_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Audio_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Communication_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Display_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Gauges_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Illumination_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Odometer_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Personalization_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Power_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_RealTimeClock_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Tripcomputer_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_Warning_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_CusDlt_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_FuelGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_Illumination_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_Odometer_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_OilGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_Personalization_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_PowerGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_RealTimeClock_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_SpeedoGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_TachoGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_TempGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_TripComputer_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsRt_Warning_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_AssemblyManufacturingDate>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_AssemblyPlantNumber>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_EcuPartNumber_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_HWModification>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_PCBSerialNumber>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_ProductSerialNumber>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SMTManufacturingDate>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SMTPlantNumber>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdFotaFinPrint_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdFotaMode_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdFotaStatus_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdFotadecrypt_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdReflash_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_VehicleConfig_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_VisMeet_EOLEntry_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_VisMeet_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_VisteonPCBPartNumber>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_VisteonPartNumber>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <RefCys_Certicificate1_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <RefCys_Certicificate_Element>
 *
 *********************************************************************************************************************/

RTE_LOCAL FUNC(void, RTE_CODE) NvBlockSwComponentTypeRunnable(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy1, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination_Copy2, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1, NULL_PTR);
    Rte_DisableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 = 0;
    Rte_EnableOSInterrupts(UM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

}



/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     OsTask_AppFun
 * Priority: 5
 * Schedule: NON
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_AppFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  CDcmApp_Impl_MainFunction();

  /* call runnable */
  CDemApp_Impl_MainFunction();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_AudioFun
 * Priority: 11
 * Schedule: NON
 * Alarm:    Cycle Time 0.03 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_AudioFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  AudioTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_CANFun
 * Priority: 2
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_CANFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms | Rte_Ev_Cyclic_OsTask_CANFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_CANFun, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms | Rte_Ev_Cyclic_OsTask_CANFun_0_10ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      ComM_MainFunction_0();

      /* call schedulable entity */
      CanSM_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_CANFun_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CComAbsCtrl_CmpMain();

      /* call runnable */
      CComAbsCtrl_Impl_MainFunction();

      /* call runnable */
      CComAbsMdl_Impl_RxCanMdlMainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Rte_ComSendSignalProxyPeriodic();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_CANFun_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CComAbsMdl_Impl_TxCanMdlMainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_OsTask_CANFun_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Com_MainFunctionRx();

      /* call schedulable entity */
      Com_MainFunctionTx();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_CANFun_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComCallout_Impl_MainFunction();

      /* call runnable */
      CComAbsMdl_stubs_MainFunction();

      /* call runnable */
      ComMExt_Impl_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_Diagnostics
 * Priority: 12
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_Diagnostics) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms | Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms | Rte_Ev_Cyclic_OsTask_Diagnostics_0_10ms | Rte_Ev_Cyclic_OsTask_Diagnostics_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_Diagnostics, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms | Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms | Rte_Ev_Cyclic_OsTask_Diagnostics_0_10ms | Rte_Ev_Cyclic_OsTask_Diagnostics_0_20ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Dcm_MainFunction();

      /* call runnable */
      Dem_MasterMainFunction();

      /* call runnable */
      Dem_SatelliteMainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_Diagnostics_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Det_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      DltExt_MainFunction();

      /* call runnable */
      Dlt_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_Diagnostics_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      DcmExt_MainFunction();

      /* call runnable */
      DemExt_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_Diagnostics_0_20ms) != (EventMaskType)0)
    {
      /* call runnable */
      CCDD_BswFit_Impl_MainFunction();

      /* call runnable */
      CCDD_FitManager_Impl_MainFunction();

      /* call runnable */
      CCDD_McuFit_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_Diagnostics_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Test_Comp_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_DispFun
 * Priority: 24
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_DispFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_OsTask_DispFun_0_10ms | Rte_Ev_Cyclic_OsTask_DispFun_0_5ms | Rte_Ev_Run_SlowGaugeAdapter_SlowGaugeAdapter_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_DispFun, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_OsTask_DispFun_0_10ms | Rte_Ev_Cyclic_OsTask_DispFun_0_5ms | Rte_Ev_Run_SlowGaugeAdapter_SlowGaugeAdapter_Task)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_OsTask_DispFun_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CBacklightCdd_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_DispFun_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      CddTaskStubRunnable();
    }

    if ((ev & Rte_Ev_Run_SlowGaugeAdapter_SlowGaugeAdapter_Task) != (EventMaskType)0)
    {
      /* call runnable */
      SlowGaugeAdapter_Task();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_DispFun_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CRtcCdd_Impl_MainFunction();

      /* call runnable */
      Mdl_Dim_Task();

      /* call runnable */
      Ctrl_Dim_Task();

      /* call runnable */
      CUpdateCdd_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_DispFun_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      CCDD_EcuPowerM_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_DispFun_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Ctrl_Illumination_Task();

      /* call runnable */
      CMeetCdd_Impl_MainFunction();

      /* call runnable */
      View_Illumination_Task();

      /* call runnable */
      CCtrl_Illumination_Impl_MainFunction();

      /* call runnable */
      CView_Illumination_Impl_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_EthFun
 * Priority: 17
 * Schedule: NON
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_EthFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  EthIf_MainFunctionState();

  /* call runnable */
  EthSM_MainFunction();

  /* call runnable */
  TcpIp_MainFunction();

  /* call runnable */
  SoAd_MainFunction();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_FotaFun
 * Priority: 4
 * Schedule: FULL
 * Alarm:    Cycle Time 0.1 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_FotaFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  FotaTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_GaugeFun
 * Priority: 14
 * Schedule: NON
 * Alarm:    Cycle Time 0.02 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_GaugeFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  Mdl_Linear_Interpolation_Task();

  /* call runnable */
  Mdl_Speed_Task();

  /* call runnable */
  View_Speed_Task();

  /* call runnable */
  Mdl_Tacho_Task();

  /* call runnable */
  FastGaugeAdapter_Task();

  /* call runnable */
  GaugeTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_IndFun
 * Priority: 10
 * Schedule: NON
 * Alarm:    Cycle Time 0.03 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_IndFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  IndTaskStubRunnable();

  /* call runnable */
  Mdl_TurnHazard_Task();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_IpcUclEv
 * Priority: 8
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_IpcUclEv) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;
  EventMaskType evRun;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_CUpdateCdd_CUpdateCdd_OnDre_UpdateResponse | Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_HudWarnStatus | Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_WarnStatus | Rte_Ev_Run_DmnMgr_CDmnMgr_Impl_MainFunction | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState | Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction | Rte_Ev_Run_UclProxyCdd_OnDre_DLTControlMessageReponse | Rte_Ev_Run_UclProxyCdd_OnDre_DLTMessageReadRequest | Rte_Ev_Run_UclProxyCdd_OnDre_DiagDIDRequest | Rte_Ev_Run_UclProxyCdd_OnDre_DiagIOCtrlRequest | Rte_Ev_Run_UclProxyCdd_OnDre_DiagRoutineRequest | Rte_Ev_Run_UclProxyCdd_OnDre_DisplaySetPower | Rte_Ev_Run_UclProxyCdd_OnDre_FRTT_Status | Rte_Ev_Run_UclProxyCdd_OnDre_FastGaugeInfo | Rte_Ev_Run_UclProxyCdd_OnDre_IlluminationData | Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Icon | Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Status | Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Toggle | Rte_Ev_Run_UclProxyCdd_OnDre_ShiftPosIndStatus | Rte_Ev_Run_UclProxyCdd_OnDre_SlowGaugeInfo | Rte_Ev_Run_UclProxyCdd_OnDre_TT_Status | Rte_Ev_Run_UclProxyCdd_OnDre_UpdateLongServiceReq | Rte_Ev_Run_UclProxyCdd_OnDre_UpdateShortServiceReq | Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay | Rte_Ev_Run_UclProxyCdd_OnDre_WarningExtDisplay); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_IpcUclEv, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_CUpdateCdd_CUpdateCdd_OnDre_UpdateResponse | Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_HudWarnStatus | Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_WarnStatus | Rte_Ev_Run_DmnMgr_CDmnMgr_Impl_MainFunction | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake | Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState | Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction | Rte_Ev_Run_UclProxyCdd_OnDre_DLTControlMessageReponse | Rte_Ev_Run_UclProxyCdd_OnDre_DLTMessageReadRequest | Rte_Ev_Run_UclProxyCdd_OnDre_DiagDIDRequest | Rte_Ev_Run_UclProxyCdd_OnDre_DiagIOCtrlRequest | Rte_Ev_Run_UclProxyCdd_OnDre_DiagRoutineRequest | Rte_Ev_Run_UclProxyCdd_OnDre_DisplaySetPower | Rte_Ev_Run_UclProxyCdd_OnDre_FRTT_Status | Rte_Ev_Run_UclProxyCdd_OnDre_FastGaugeInfo | Rte_Ev_Run_UclProxyCdd_OnDre_IlluminationData | Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Icon | Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Status | Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Toggle | Rte_Ev_Run_UclProxyCdd_OnDre_ShiftPosIndStatus | Rte_Ev_Run_UclProxyCdd_OnDre_SlowGaugeInfo | Rte_Ev_Run_UclProxyCdd_OnDre_TT_Status | Rte_Ev_Run_UclProxyCdd_OnDre_UpdateLongServiceReq | Rte_Ev_Run_UclProxyCdd_OnDre_UpdateShortServiceReq | Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay | Rte_Ev_Run_UclProxyCdd_OnDre_WarningExtDisplay)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime) != (EventMaskType)0)
    {
      /* call runnable */
      DmnMgr_MonitorDmnExtendShutdownTime();
    }

    if ((ev & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData) != (EventMaskType)0)
    {
      /* call runnable */
      DmnMgr_MonitorDmnHealthDumpData();
    }

    if ((ev & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo) != (EventMaskType)0)
    {
      /* call runnable */
      DmnMgr_MonitorDmnHealthDumpHdrInfo();
    }

    if ((ev & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError) != (EventMaskType)0)
    {
      /* call runnable */
      DmnMgr_MonitorDmnHealthFatalError();
    }

    if ((ev & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat) != (EventMaskType)0)
    {
      /* call runnable */
      DmnMgr_MonitorDmnHeartBeat();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      CUclProxyCdd_Impl_MainFunction();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnKeepSystemAwake();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnPowerSystemState();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_CUpdateCdd_CUpdateCdd_OnDre_UpdateResponse) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_CUpdateCdd_CUpdateCdd_OnDre_UpdateResponse) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_CUpdateCdd_CUpdateCdd_OnDre_UpdateResponse); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      CUpdateCdd_OnDre_UpdateResponse();
    }

    if ((ev & Rte_Ev_Run_DmnMgr_CDmnMgr_Impl_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      CDmnMgr_Impl_MainFunction();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      OnDre_HealthDumpGetData();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      OnDre_HealthDumpGetHdr();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      OnDre_PowerSystemStateReqChange();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_DisplaySetPower) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_DisplaySetPower();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_FRTT_Status) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_FRTT_Status();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_FastGaugeInfo) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_FastGaugeInfo();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Icon) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_RTT_Icon();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Status) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_RTT_Status();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_RTT_Toggle) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_RTT_Toggle();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_ShiftPosIndStatus) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_ShiftPosIndStatus();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_SlowGaugeInfo) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_SlowGaugeInfo();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_DiagDIDRequest) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_DiagDIDRequest();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_DiagIOCtrlRequest) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_DiagIOCtrlRequest();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_DiagRoutineRequest) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_DiagRoutineRequest();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_IlluminationData) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_IlluminationData();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_HudWarnStatus) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_HudWarnStatus) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_HudWarnStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      OnDre_UCL_HudWarnStatus();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_WarnStatus) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_WarnStatus) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_CWarnMsg_Core_Observer_OnDre_UCL_WarnStatus); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      OnDre_UCL_WarnStatus();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_TT_Status) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_TT_Status();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_UclProxyCdd_OnDre_WarningDisplay); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      OnDre_WarningDisplay();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_UclProxyCdd_OnDre_UpdateLongServiceReq) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_UclProxyCdd_OnDre_UpdateLongServiceReq) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_UclProxyCdd_OnDre_UpdateLongServiceReq); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      OnDre_UpdateLongServiceReq();
    }

    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_UclProxyCdd_OnDre_UpdateShortServiceReq) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_UclProxyCdd_OnDre_UpdateShortServiceReq) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_UclProxyCdd_OnDre_UpdateShortServiceReq); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      OnDre_UpdateShortServiceReq();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_WarningExtDisplay) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_WarningExtDisplay();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_DLTControlMessageReponse) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_DLTControlMessageReponse();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_DLTMessageReadRequest) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_DLTMessageReadRequest();
    }
    (void)GetEvent(OsTask_IpcUclEv, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DltExt_DltExt_OnDreDLTMessageReadAckData) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DltExt_DltExt_OnDreDLTMessageReadAckData); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DltExt_OnDreDLTMessageReadAckData();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_LSH_16ms
 * Priority: 20
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_LSH_16ms) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_OsTask_LSH_16ms_0_16ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_LSH_16ms, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_OsTask_LSH_16ms_0_16ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_OsTask_LSH_16ms_0_16ms) != (EventMaskType)0)
    {
      /* call runnable */
      CGdtCdd_Impl_MainFunction();

      /* call runnable */
      CSigCdd_Impl_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_LinFun
 * Priority: 13
 * Schedule: NON
 * Alarm:    Cycle Time 0.02 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_LinFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  LinTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_Mcal
 * Priority: 21
 * Schedule: NON
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_Mcal) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  EcuMExt_MainFunction();

  /* call runnable */
  I2c_MainFunction();

  /* call runnable */
  SciDrv_MainFunction();

  /* call runnable */
  IoExp_MainFunction();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_MemSer
 * Priority: 22
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_MemSer) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms | Rte_Ev_Cyclic_OsTask_MemSer_0_10ms | Rte_Ev_Run_Ea_Ea_MainFunction | Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_MemSer, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms | Rte_Ev_Cyclic_OsTask_MemSer_0_10ms | Rte_Ev_Run_Ea_Ea_MainFunction | Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      NvM_MainFunction();
    }

    if ((ev & Rte_Ev_Run_Ea_Ea_MainFunction) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Ea_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_MemSer_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      EepDrv_MainFunction();

      /* call runnable */
      MemAbstract_MainFunction();

      /* call runnable */
      NvMExt_MainFunction();
    }

    if ((ev & Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable) != (EventMaskType)0)
    {
      /* call runnable */
      NvBlockSwComponentTypeRunnable();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_MemSer_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CMemAbstractMdl_Impl_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_ModeMgt
 * Priority: 25
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_ModeMgt) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_OsTask_ModeMgt_0_10ms | Rte_Ev_Cyclic_OsTask_ModeMgt_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_ModeMgt, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_OsTask_ModeMgt_0_10ms | Rte_Ev_Cyclic_OsTask_ModeMgt_0_10ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_OsTask_ModeMgt_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Ctrl_WSS_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_OsTask_ModeMgt_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      EcuM_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_ModeMgt_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      TmExt_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_NvmSpeedup
 * Priority: 7
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(OsTask_NvmSpeedup) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_NvmSpeedup, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_NvMExt_NvMExt_SpeedupRunnable) != (EventMaskType)0)
    {
      /* call runnable */
      NvMExt_SpeedupRunnable();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_TripFun
 * Priority: 6
 * Schedule: NON
 * Alarm:    Cycle Time 0.05 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_TripFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  TripTaskStubRunnable();

  /* call runnable */
  AppTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_WarnFun
 * Priority: 9
 * Schedule: NON
 * Alarm:    Cycle Time 0.032 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_WarnFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  Mdl_wAirbag_Task();

  /* call runnable */
  Mdl_wFuelLidOpen_Task();

  /* call runnable */
  Ctrl_warning_Task();

  /* call runnable */
  WarnMsg_Core_TmrSupport_Task();

  /* call runnable */
  CWarnMsg_Core_Observer_Impl_MainFunction();

  /* call runnable */
  Mdl_Gear_Task();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_3197:  MISRA rule: -
     Reason:     The variable is not written by the code in all possible code variants. Due to this, the variable is initialized.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: -
     Reason:     The parameter's are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3447:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451_NvM:  MISRA rule: 8.8
     Reason:     NvM functions are declared by the RTE and also by the NvM.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
