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
 *          File:  Rte_OsApplication_Trusted.c
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
#include "Rte_NvM.h"
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

#define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(TTBlinkArray, RTE_VAR_INIT) Rte_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(TTFlashMask, RTE_VAR_INIT) Rte_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(TT_OP_Type, RTE_VAR_INIT) Rte_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SDisplaySetPower, RTE_VAR_INIT) Rte_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData = {
  0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SIG_WIN_SETUP_T, RTE_VAR_INIT) Rte_CSwcDispMonSf_pp_SigData_sig0_port = {
  0U, 0U, 0U, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(STT_Status, RTE_VAR_INIT) Rte_CView_Telltale_ppTelltaleSts_TT_StatusData = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Arr_u8_28, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint16, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Arr_u16_7, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(Arr_u16_7, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(T_NV_Temperature_Conversion, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(T_NV_Temperature_Conversion, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/
#define RTE_FBK_COM_STOPPED                (0U)
#define RTE_FBK_TIMEOUT                    (1U)
#define RTE_FBK_TRANSMIT_ACK               (2U)
#define RTE_FBK_NO_DATA                    (3U)


/**********************************************************************************************************************
 * TxUpdate Flags for each external Tx Signal over Rte_ComSendSignalProxy without IOCs
 *********************************************************************************************************************/
#define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_OsApplication_Trusted_TxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Trusted_TxUpdateFlags = {
  0,
  0
}; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define Rte_OsApplication_Trusted_TxUpdateFlagsInit() (Rte_MemClr(&Rte_OsApplication_Trusted_TxUpdateFlags, sizeof(Rte_OsApplication_Trusted_TxUpdateFlagsType)))

/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)


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

#define RTE_START_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint8, RTE_VAR_NOINIT) Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx[3]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(uint32, RTE_VAR_INIT) Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx_Length = 0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
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


FUNC(void, RTE_CODE) Rte_InitMemory_OsApplication_Trusted(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* reset Tx Update Flags */
  Rte_OsApplication_Trusted_TxUpdateFlagsInit();

  /* set default values for internal data */
  Rte_MemCpy32(Rte_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray, Rte_CView_TelltaleTTBlinkStatusArrayValue0, sizeof(TTBlinkArray));
  Rte_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes = 0U;
  Rte_MemCpy32(Rte_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray, Rte_CView_TelltaleTelltaleOpArrayValue0, sizeof(TT_OP_Type));
  Rte_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData = Rte_UclProxyCddDisplaySetPowerDataValue0;
  Rte_CSwcDispMonSf_pp_SigData_sig0_port = Rte_CSigCddsig0_portValue0;
  Rte_CView_Telltale_ppTelltaleSts_TT_StatusData = Rte_UclProxyCddTT_StatusDataValue0;
  Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus = 0U;

  /* initialize transformation buffers */
  Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx_Length = 0;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray(P2CONST(TTBlinkArray, AUTOMATIC, RTE_CCTRL_TELLTALE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray, *(data), sizeof(TTBlinkArray));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray(P2CONST(TT_OP_Type, AUTOMATIC, RTE_CCTRL_TELLTALE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray, *(data), sizeof(TT_OP_Type));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData(P2CONST(SDisplaySetPower, AUTOMATIC, RTE_CDISPLAYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData = *(data);
  Rte_EnableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: OnDre_DisplaySetPower */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_DisplaySetPower); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CSwcDispMonSf_pp_SigData_sig0_port(P2CONST(SIG_WIN_SETUP_T, AUTOMATIC, RTE_CSWCDISPMONSF_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CSwcDispMonSf_pp_SigData_sig0_port = *(data);
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CView_Telltale_ppTelltaleSts_TT_StatusData(P2CONST(STT_Status, AUTOMATIC, RTE_CVIEW_TELLTALE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_CView_Telltale_ppTelltaleSts_TT_StatusData = *(data);
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: OnDre_TT_Status */
  (void)SetEvent(OsTask_IpcUclEv, Rte_Ev_Run_UclProxyCdd_OnDre_TT_Status); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value(P2CONST(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value, *(data), sizeof(Arr_u8_28));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value = *(&data);
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value = *(&data);
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value = *(&data);
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value(uint16 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value = *(&data);
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value, *(data), sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2CONST(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value, *(data), sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value, *(data), sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value = *(&data);
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value(uint8 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value = *(&data);
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value(P2CONST(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value, *(data), sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: OnDre_SafeNvM_Illumination */
  (void)SetEvent(OsTask_SafeBsw, Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS(P2CONST(SG_COM_HS, AUTOMATIC, RTE_TRUSTECSWC_APPL_DATA) data, P2VAR(Rte_TransformerError, AUTOMATIC, RTE_TRUSTECSWC_APPL_VAR) transformerError) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret;
  uint32 lengthBuffer;
  uint32 lengthSendBuffer;
  uint8 transformationBuffer_0[3];
  transformerError->errorCode = RTE_E_OK;
  transformerError->transformerClass = RTE_TRANSFORMER_UNSPECIFIED;

  ret = ComXf_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS(&(transformationBuffer_0[0]), &lengthBuffer, data);
  if (ret != RTE_E_OK)
  {
    transformerError->errorCode = ret;
    transformerError->transformerClass = RTE_TRANSFORMER_SERIALIZER;
  }
  if (!Rte_IsHardTransformerError(ret))
  {
    Std_ReturnType currentTransformerError;
    lengthBuffer = sizeof(Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx);
    currentTransformerError = E2EXf_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    ret |= currentTransformerError;
    if (((transformerError->errorCode == RTE_E_OK) && (currentTransformerError != RTE_E_OK)) || Rte_IsHardTransformerError(currentTransformerError))
    {
      transformerError->errorCode = currentTransformerError;
      transformerError->transformerClass = RTE_TRANSFORMER_SAFETY;
    }
  }
  lengthSendBuffer = lengthBuffer;
  if ((lengthSendBuffer <= 3U) && (!Rte_IsHardTransformerError(ret)))
  {
    Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx_Length = lengthSendBuffer;
    Rte_MemCpy(Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx, transformationBuffer_0, lengthSendBuffer);
    Rte_OsApplication_Trusted_TxUpdateFlags.Rte_TxUpdate_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = RTE_COM_SENDSIGNALPROXY_SEND;
    Rte_OsApplication_Trusted_TxUpdateFlags.Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = !Rte_OsApplication_NonTrusted_TxUpdateFlags.Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS;
    Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (ret != RTE_E_OK)
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }
  else
  {
    ret = RTE_E_HARD_TRANSFORMER_ERROR;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CDisplayCdd_rpSRDisplayCurrentState_DisplayCurrentStateData(P2VAR(SDisplayCurrentState, AUTOMATIC, RTE_CDISPLAYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  *(data) = Rte_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData;
  Rte_EnableOSInterrupts(AM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CView_Telltale_rpBlinkStatusArray_TTBlinkStatusArray(P2VAR(TTBlinkArray, AUTOMATIC, RTE_CVIEW_TELLTALE_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray, sizeof(TTBlinkArray));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CView_Telltale_rpTelltaleStatusOP_TelltaleOpArray(P2VAR(TT_OP_Type, AUTOMATIC, RTE_CVIEW_TELLTALE_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray, sizeof(TT_OP_Type));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value(P2VAR(Arr_u8_28, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value, sizeof(Arr_u8_28));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value, sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value(P2VAR(Arr_u16_7, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value, sizeof(Arr_u16_7));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value, sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value(P2VAR(T_NV_Temperature_Conversion, AUTOMATIC, RTE_MEMABSTRACT_STUB_SAFE_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value, sizeof(T_NV_Temperature_Conversion));
  Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(P2VAR(SG_ABS, AUTOMATIC, RTE_TRUSTECSWC_APPL_VAR) data, P2VAR(Rte_TransformerError, AUTOMATIC, RTE_TRUSTECSWC_APPL_VAR) transformerError) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[6];
  transformerError->errorCode = RTE_E_OK;
  transformerError->transformerClass = RTE_TRANSFORMER_UNSPECIFIED;

  if (Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx_Length == 0)
  {
    *data = Rte_C_SG_ABS_0;
  }
  else
  {
    Rte_DisableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    lengthBuffer = Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx_Length;
    if (lengthBuffer > 6U)
    {
      lengthBuffer = 6U;
    }
    Rte_MemCpy(transformationBuffer_0, Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx, lengthBuffer);
    Rte_EnableOSInterrupts(KM); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E2EXf_Inv_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (ret != RTE_E_OK)
    {
      transformerError->errorCode = ret;
      transformerError->transformerClass = RTE_TRANSFORMER_SAFETY;
    }
    if (!Rte_IsHardTransformerError(ret))
    {
      Std_ReturnType currentTransformerError;
      currentTransformerError = ComXf_Inv_TrustecSWC_RP_RX_SG_ABS_RP_SR_TX_SG_ABS(&(transformationBuffer_0[0]), lengthBuffer, data);
      ret |= currentTransformerError;
      if (((transformerError->errorCode == RTE_E_OK) && (currentTransformerError != RTE_E_OK)) || Rte_IsHardTransformerError(currentTransformerError))
      {
        transformerError->errorCode = currentTransformerError;
        transformerError->transformerClass = RTE_TRANSFORMER_SERIALIZER;
      }
    }
    if (Rte_IsHardTransformerError(ret))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (ret != RTE_E_OK) /* PRQA S 2004 */ /* MD_Rte_2004 */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }
  if (Rte_OsApplication_NonTrusted_RxNeverReceivedFlags.Rte_RxNeverReceived_SG_ABS_oABS_oCAN00_6681ad27_Rx == 0)
  {
    ret = RTE_E_NEVER_RECEIVED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Feedback_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Std_ReturnType ret = RTE_E_TRANSMIT_ACK;


  if (Rte_OsApplication_Trusted_TxUpdateFlags.Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS == Rte_OsApplication_NonTrusted_TxUpdateFlags.Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS)
  {
    if (Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS != RTE_FBK_TRANSMIT_ACK)
    {
      ret = (Std_ReturnType)(Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS + 128U);
    }
  }
  else
  {
    ret = RTE_E_NO_DATA;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     OsTask_SafeApp
 * Priority: 15
 * Schedule: NON
 * Alarm:    Cycle Time 0.03 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_SafeApp) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  Mdl_Airbag_Task();

  /* call runnable */
  CCtrl_Telltale_Impl_MainFunction();

  /* call runnable */
  CCtrl_Telltale_Adapter_Task();

  /* call runnable */
  CView_Telltale_Impl_MainFunction();

  /* call runnable */
  TxRxIpcMessage();

  /* call runnable */
  GraphicsTaskStubRunnable();

  /* call runnable */
  IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_30ms();

  /* call runnable */
  TrustedSwc_MainFunction();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_SafeBsw
 * Priority: 16
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_SafeBsw) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_OsTask_SafeBsw_0_10ms | Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms | Rte_Ev_Run_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms | Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_EBW2 | Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_PKBLP | Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_SCSBZR | Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_VSCOFF | Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_SafeBsw, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_OsTask_SafeBsw_0_10ms | Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms | Rte_Ev_Run_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms | Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_EBW2 | Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_PKBLP | Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_SCSBZR | Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_VSCOFF | Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      IoHwAb_MainFunction();
    }

    if ((ev & Rte_Ev_Run_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms) != (EventMaskType)0)
    {
      /* call runnable */
      IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Mdl_SafetyAdapter_Task();
    }

    if ((ev & Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_EBW2) != (EventMaskType)0)
    {
      /* call runnable */
      Mdl_SafetyAdapter_OnDataRx_B_EBW2();
    }

    if ((ev & Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_B_PKBLP) != (EventMaskType)0)
    {
      /* call runnable */
      Mdl_SafetyAdapter_OnDataRx_B_PKBLP();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CDisplayCdd_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_SCSBZR) != (EventMaskType)0)
    {
      /* call runnable */
      Mdl_SafetyAdapter_OnDataRx_SCSBZR();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      EcuAppM_MainFunction();
    }

    if ((ev & Rte_Ev_Run_Mdl_SafetyAdapter_Mdl_SafetyAdapter_OnDataRx_VSCOFF) != (EventMaskType)0)
    {
      /* call runnable */
      Mdl_SafetyAdapter_OnDataRx_VSCOFF();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CNvMExtSf_MainFunction();

      /* call runnable */
      CorTst_MainFunction();

      /* call runnable */
      FlsTst_MainFunction();

      /* call runnable */
      CCDD_EcuBatteryM_Impl_MainFunction();
      RamTst_MainFunction();

      /* call runnable */
      SysTst_MainFunction();

      /* call runnable */
      IoHwAb_OsTask_SafeBsw_Task_10ms();
    }

    if ((ev & Rte_Ev_Cyclic2_OsTask_SafeBsw_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Can_MainFunction_BusOff();

      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call schedulable entity */
      Can_MainFunction_Wakeup();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_SafeBsw_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Spi_MainFunction_Handling();

      /* call runnable */
      MemAbstract_Stub_Safe();

      /* call runnable */
      CComAbsMdlSafe_Impl_RxCanMdlSafeMainFunction();

      /* call runnable */
      CComAbsMdlSafe_Impl_TxCanMdlSafeMainFunction();

      /* call runnable */
      CFltM_Impl_MainFunction();

      /* call runnable */
      CSafeNvM_Impl_MainFunction();

      /* call runnable */
      CFltMExt_MainFunction();

      /* call runnable */
      CRstM_Impl_MainFunction();

      /* call runnable */
      CSwcDispMonSf_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Run_SafeNvM_OnDre_SafeNvM_Illumination) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_SafeNvM_Illumination();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_WdgMngt
 * Priority: 23
 * Schedule: NON
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_WdgMngt) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  WdgM_MainFunction();

  /* call runnable */
  IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_10ms();

  /* call runnable */
  CPmicCdd_Impl_MainFunction();

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

   MD_Rte_2004:  MISRA rule: 14.10
     Reason:     The concluding else is not needed and an empty else makes the code more difficult to understand.
     Risk:       Wrong implementations could remain undetected.
     Prevention: Code inspection and test of different source code variants by the component test suites.

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
