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
 *          File:  Rte.c
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

#if defined(osDisableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalUM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelUM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelUM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelUM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u16_7, RTE_CONST) Rte_C_Arr_u16_7_0 = {
  700U, 710U, 720U, 730U, 740U, 750U, 760U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u16_7, RTE_CONST) Rte_C_Arr_u16_7_1 = {
  8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_10, RTE_CONST) Rte_C_Arr_u8_10_0 = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_100, RTE_CONST) Rte_C_Arr_u8_100_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_1024, RTE_CONST) Rte_C_Arr_u8_1024_0 = {
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
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_128, RTE_CONST) Rte_C_Arr_u8_128_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_16, RTE_CONST) Rte_C_Arr_u8_16_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_17, RTE_CONST) Rte_C_Arr_u8_17_0 = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_2048, RTE_CONST) Rte_C_Arr_u8_2048_0 = {
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
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_256, RTE_CONST) Rte_C_Arr_u8_256_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_28, RTE_CONST) Rte_C_Arr_u8_28_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_3, RTE_CONST) Rte_C_Arr_u8_3_0 = {
  1U, 1U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_3, RTE_CONST) Rte_C_Arr_u8_3_1 = {
  255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_32, RTE_CONST) Rte_C_Arr_u8_32_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_46, RTE_CONST) Rte_C_Arr_u8_46_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_48, RTE_CONST) Rte_C_Arr_u8_48_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_61, RTE_CONST) Rte_C_Arr_u8_61_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_64, RTE_CONST) Rte_C_Arr_u8_64_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_8, RTE_CONST) Rte_C_Arr_u8_8_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_9, RTE_CONST) Rte_C_Arr_u8_9_0 = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Diag_Buffer_Tx_USDT, RTE_CONST) Rte_C_Diag_Buffer_Tx_USDT_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Diag_Buffer_Tx_UUDT, RTE_CONST) Rte_C_Diag_Buffer_Tx_UUDT_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TTBlinkArray, RTE_CONST) Rte_CCtrl_TelltaleTTBlinkStatusArrayValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TTBlinkArray, RTE_CONST) Rte_CView_TelltaleTTBlinkStatusArrayValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TTBlinkArray, RTE_CONST) Rte_Ctrl_WSSTTBlinkStatusArrayValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TT_OP_Type, RTE_CONST) Rte_CCtrl_TelltaleTelltaleFunctionalOpStatusValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TT_OP_Type, RTE_CONST) Rte_CCtrl_TelltaleTelltaleOpArrayValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TT_OP_Type, RTE_CONST) Rte_CView_TelltaleTelltaleOpArrayValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(TT_OP_Type, RTE_CONST) Rte_Ctrl_WSSTelltaleOpArrayValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(T_NV_Temperature_Conversion, RTE_CONST) Rte_C_T_NV_Temperature_Conversion_0 = {
  4095U, 4095U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Tpms_Arr_u8_5, RTE_CONST) Rte_CWarnMsg_Core_ObserverTpms_PayloadValue0 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(IllumCtrl_Ip, RTE_CONST) Rte_Ctrl_IlluminationIllumCtrl_Ip_DataValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(IllumCtrl_Ip, RTE_CONST) Rte_Mdl_DimIllumCtrl_Ip_DataValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(IllumCtrl_Op, RTE_CONST) Rte_Ctrl_IlluminationIllumCtrl_Op_DataValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(IllumCtrl_Op, RTE_CONST) Rte_View_IlluminationIllumCtrl_Op_DataValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_Audio, RTE_CONST) Rte_C_NV_Data_BsConst_Audio_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_Communication, RTE_CONST) Rte_C_NV_Data_BsConst_Communication_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_EngOffTimer, RTE_CONST) Rte_C_NV_Data_BsConst_EngOffTimer_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_FuelGauge, RTE_CONST) Rte_C_NV_Data_BsConst_FuelGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_Illumination, RTE_CONST) Rte_C_NV_Data_BsConst_Illumination_0 = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_Illumination_Copy1, RTE_CONST) Rte_C_NV_Data_BsConst_Illumination_Copy1_0 = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_Illumination_Copy2, RTE_CONST) Rte_C_NV_Data_BsConst_Illumination_Copy2_0 = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_OilGauge, RTE_CONST) Rte_C_NV_Data_BsConst_OilGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_Power, RTE_CONST) Rte_C_NV_Data_BsConst_Power_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_PowerGauge, RTE_CONST) Rte_C_NV_Data_BsConst_PowerGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_RealTimeClock, RTE_CONST) Rte_C_NV_Data_BsConst_RealTimeClock_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_ServiceReminder, RTE_CONST) Rte_C_NV_Data_BsConst_ServiceReminder_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_SpeedoGauge, RTE_CONST) Rte_C_NV_Data_BsConst_SpeedoGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_TachoGauge, RTE_CONST) Rte_C_NV_Data_BsConst_TachoGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_TempGauge, RTE_CONST) Rte_C_NV_Data_BsConst_TempGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_TripComputer, RTE_CONST) Rte_C_NV_Data_BsConst_TripComputer_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsConst_Warning, RTE_CONST) Rte_C_NV_Data_BsConst_Warning_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsCys_Certicificate, RTE_CONST) Rte_C_NV_Data_BsCys_Certicificate_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsDiag_Dtc, RTE_CONST) Rte_C_NV_Data_BsDiag_Dtc_0 = {
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
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsDiag_ErrorRecord, RTE_CONST) Rte_C_NV_Data_BsDiag_ErrorRecord_0 = {
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
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Audio, RTE_CONST) Rte_C_NV_Data_BsReten_Audio_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Communication, RTE_CONST) Rte_C_NV_Data_BsReten_Communication_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Display, RTE_CONST) Rte_C_NV_Data_BsReten_Display_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Gauges, RTE_CONST) Rte_C_NV_Data_BsReten_Gauges_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Illumination, RTE_CONST) Rte_C_NV_Data_BsReten_Illumination_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Odometer, RTE_CONST) Rte_C_NV_Data_BsReten_Odometer_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Personalization, RTE_CONST) Rte_C_NV_Data_BsReten_Personalization_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Power, RTE_CONST) Rte_C_NV_Data_BsReten_Power_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_RealTimeClock, RTE_CONST) Rte_C_NV_Data_BsReten_RealTimeClock_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Tripcomputer, RTE_CONST) Rte_C_NV_Data_BsReten_Tripcomputer_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsReten_Warning, RTE_CONST) Rte_C_NV_Data_BsReten_Warning_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_CusDlt, RTE_CONST) Rte_C_NV_Data_BsRt_CusDlt_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_FuelGauge, RTE_CONST) Rte_C_NV_Data_BsRt_FuelGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_Illumination, RTE_CONST) Rte_C_NV_Data_BsRt_Illumination_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_Odometer, RTE_CONST) Rte_C_NV_Data_BsRt_Odometer_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_OilGauge, RTE_CONST) Rte_C_NV_Data_BsRt_OilGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_Personalization, RTE_CONST) Rte_C_NV_Data_BsRt_Personalization_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_PowerGauge, RTE_CONST) Rte_C_NV_Data_BsRt_PowerGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_RealTimeClock, RTE_CONST) Rte_C_NV_Data_BsRt_RealTimeClock_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_SpeedoGauge, RTE_CONST) Rte_C_NV_Data_BsRt_SpeedoGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_TachoGauge, RTE_CONST) Rte_C_NV_Data_BsRt_TachoGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_TempGauge, RTE_CONST) Rte_C_NV_Data_BsRt_TempGauge_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_TripComputer, RTE_CONST) Rte_C_NV_Data_BsRt_TripComputer_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsRt_Warning, RTE_CONST) Rte_C_NV_Data_BsRt_Warning_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsShare_EcuPartNumber, RTE_CONST) Rte_C_NV_Data_BsShare_EcuPartNumber_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {1U, 1U, 0U
  }, {1U, 1U, 0U}, {255U, 255U, 255U}, {255U, 255U, 255U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdFotaFinPrint_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsShare_SwUpdFotaMode, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdFotaMode_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsShare_SwUpdFotaStatus, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdFotaStatus_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsShare_SwUpdFotadecrypt, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdFotadecrypt_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsShare_SwUpdReflash, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdReflash_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsShare_VehicleConfig, RTE_CONST) Rte_C_NV_Data_BsShare_VehicleConfig_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsShare_VisMeet, RTE_CONST) Rte_C_NV_Data_BsShare_VisMeet_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 65535U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_RefCys_Certicificate, RTE_CONST) Rte_C_NV_Data_RefCys_Certicificate_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_RefCys_Certicificate1, RTE_CONST) Rte_C_NV_Data_RefCys_Certicificate1_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDLTControlMessageReponse, RTE_CONST) Rte_DltExtDLTControlMessageReponseDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDLTControlMessageReponse, RTE_CONST) Rte_UclProxyCddDLTControlMessageReponseDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDLTControlMessageRequest, RTE_CONST) Rte_DltExtDLTControlMessageRequestDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDLTControlMessageRequest, RTE_CONST) Rte_UclProxyCddDLTControlMessageRequestDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDLTMessageReadAck, RTE_CONST) Rte_DltExtDLTMessageReadAckDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDLTMessageReadAck, RTE_CONST) Rte_UclProxyCddDLTMessageReadAckDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDLTMessageReadRequest, RTE_CONST) Rte_DltExtDLTMessageReadRequestDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDLTMessageReadRequest, RTE_CONST) Rte_UclProxyCddDLTMessageReadRequestDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDisplayCurrentState, RTE_CONST) Rte_CDisplayCddDisplayCurrentStateDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDisplayCurrentState, RTE_CONST) Rte_C_SDisplayCurrentState_0 = {
  0U, 4U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDisplayCurrentState, RTE_CONST) Rte_UclProxyCddDisplayCurrentStateDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDisplaySetPower, RTE_CONST) Rte_CDisplayCddDisplaySetPowerDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDisplaySetPower, RTE_CONST) Rte_UclProxyCddDisplaySetPowerDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDmnStatus, RTE_CONST) Rte_DmnMgrSDmnStatusValue0 = {
  0U, 0U, 0, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SEmmcErrorNotifier, RTE_CONST) Rte_UclProxyCddEmmcErrorNotifierDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SEnetRegReq, RTE_CONST) Rte_C_SEnetRegReq_0 = {
  9U, 2U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SEnetRegResp, RTE_CONST) Rte_C_SEnetRegResp_0 = {
  9U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SFRTT_Status, RTE_CONST) Rte_UclProxyCddFRTT_StatusDataValue0 = {
  {0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SFastGaugeInfo, RTE_CONST) Rte_SFastGaugeInfo_InitValue = {
  {{0U, 0U, 0U, 0U, 0U}, {0U, 0U, 0U, 0U, 0U}}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SG_ABS, RTE_CONST) Rte_C_SG_ABS_0 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SG_COM_HS, RTE_CONST) Rte_C_SG_COM_HS_0 = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SHudWarningDisplay, RTE_CONST) Rte_CWarnMsg_Core_ObserverHudWarningDisplayDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SHudWarningDisplay, RTE_CONST) Rte_UclProxyCddHudWarningDisplayDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SHudWarningStatus, RTE_CONST) Rte_CWarnMsg_Core_ObserverHudWarningStatusDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SHudWarningStatus, RTE_CONST) Rte_UclProxyCddHudWarningStatusDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_CSigCddsig0_portValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_CSwcDispMonSfsig0_portValue0 = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SIlluminationData, RTE_CONST) Rte_Ctrl_DimIlluminationDataDataValue0 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SIlluminationData, RTE_CONST) Rte_UclProxyCddIlluminationDataDataValue0 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SIlluminationData, RTE_CONST) Rte_View_IlluminationIlluminationDataDataValue0 = {
  0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SPowerSystemState, RTE_CONST) Rte_C_SPowerSystemState_0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SPowerSystemState, RTE_CONST) Rte_DmnMgrPowerSystemStateDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SPowerSystemState, RTE_CONST) Rte_UclProxyCddPowerSystemStateDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SPowerSystemStateReqChange, RTE_CONST) Rte_DmnMgrPowerSystemStateReqChangeDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SPowerSystemStateReqChange, RTE_CONST) Rte_UclProxyCddPowerSystemStateReqChangeDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SRTT_Icon, RTE_CONST) Rte_UclProxyCddRTT_IconDataValue0 = {
  {0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SRTT_Status, RTE_CONST) Rte_UclProxyCddRTT_StatusDataValue0 = {
  {0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SRTT_Toggle, RTE_CONST) Rte_UclProxyCddRTT_ToggleDataValue0 = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SShiftPosIndStatus, RTE_CONST) Rte_Mdl_GearShiftPosIndStatusDataValue0 = {
  {0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SShiftPosIndStatus, RTE_CONST) Rte_UclProxyCddShiftPosIndStatusDataValue0 = {
  {0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SSlowGuageInfo, RTE_CONST) Rte_SlowGaugeAdapterSlowGaugeInfoDataValue0 = {
  {0U, 0U, 0, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SSlowGuageInfo, RTE_CONST) Rte_UclProxyCddSlowGaugeInfoDataValue0 = {
  {0U, 0U, 0, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(STT_Status, RTE_CONST) Rte_CView_TelltaleTT_StatusDataValue0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(STT_Status, RTE_CONST) Rte_UclProxyCddTT_StatusDataValue0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(STpmsWarningData, RTE_CONST) Rte_CWarnMsg_Core_ObserverTpmsWarningDataDataValue0 = {
  {0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(STpmsWarningData, RTE_CONST) Rte_UclProxyCddTpmsWarningDataDataValue0 = {
  {0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SWarningDisplay, RTE_CONST) Rte_CWarnMsg_Core_ObserverWarningDisplayDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SWarningDisplay, RTE_CONST) Rte_UclProxyCddWarningDisplayDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SWarningDisplayAvailable, RTE_CONST) Rte_UclProxyCddWarningDisplayAvailableDataValue0 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SWarningExtDisplay, RTE_CONST) Rte_UclProxyCddWarningExtDisplayDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SWarningStatus, RTE_CONST) Rte_CWarnMsg_Core_ObserverWarningStatusDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SWarningStatus, RTE_CONST) Rte_UclProxyCddWarningStatusDataValue0 = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(ShiftposData_Type, RTE_CONST) Rte_Mdl_GearShiftPos_DataValue0 = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio_ROM_NVBlockDescriptor_BsConst_Audio = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication_ROM_NVBlockDescriptor_BsConst_Communication = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_EngOffTimer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer_ROM_NVBlockDescriptor_BsConst_EngOffTimer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_FuelGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge_ROM_NVBlockDescriptor_BsConst_FuelGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_Illumination_Copy1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1 = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_Illumination_Copy2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2 = {
  44433U, 11U, {700U, 710U, 720U, 730U, 740U, 750U, 760U}, {8600U, 7700U, 6700U, 5800U, 4800U, 3900U, 3000U}, 68U, 0U, {
  4095U, 4095U}, {4095U, 4095U}, 670U, 100U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_OilGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge_ROM_NVBlockDescriptor_BsConst_OilGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power_ROM_NVBlockDescriptor_BsConst_Power = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_PowerGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge_ROM_NVBlockDescriptor_BsConst_PowerGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock_ROM_NVBlockDescriptor_BsConst_RealTimeClock = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_ServiceReminder, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder_ROM_NVBlockDescriptor_BsConst_ServiceReminder = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_SpeedoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge_ROM_NVBlockDescriptor_BsConst_SpeedoGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_TachoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge_ROM_NVBlockDescriptor_BsConst_TachoGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_TempGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge_ROM_NVBlockDescriptor_BsConst_TempGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer_ROM_NVBlockDescriptor_BsConst_TripComputer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsConst_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning_ROM_NVBlockDescriptor_BsConst_Warning = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsCys_Certicificate, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate_ROM_NVBlockDescriptor_BsCys_Certicificate = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsDiag_Dtc, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc_ROM_NVBlockDescriptor_BsDiag_Dtc = {
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
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsDiag_ErrorRecord, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord_ROM_NVBlockDescriptor_BsDiag_ErrorRecord = {
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
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio_ROM_NVBlockDescriptor_BsReten_Audio = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication_ROM_NVBlockDescriptor_BsReten_Communication = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Display, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display_ROM_NVBlockDescriptor_BsReten_Display = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Gauges, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges_ROM_NVBlockDescriptor_BsReten_Gauges = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination_ROM_NVBlockDescriptor_BsReten_Illumination = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Odometer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer_ROM_NVBlockDescriptor_BsReten_Odometer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Personalization, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization_ROM_NVBlockDescriptor_BsReten_Personalization = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power_ROM_NVBlockDescriptor_BsReten_Power = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock_ROM_NVBlockDescriptor_BsReten_RealTimeClock = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Tripcomputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer_ROM_NVBlockDescriptor_BsReten_Tripcomputer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsReten_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning_ROM_NVBlockDescriptor_BsReten_Warning = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_CusDlt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt_ROM_NVBlockDescriptor_BsRt_CusDlt = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_FuelGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge_ROM_NVBlockDescriptor_BsRt_FuelGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination_ROM_NVBlockDescriptor_BsRt_Illumination = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_Odometer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer_ROM_NVBlockDescriptor_BsRt_Odometer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_OilGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge_ROM_NVBlockDescriptor_BsRt_OilGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_Personalization, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization_ROM_NVBlockDescriptor_BsRt_Personalization = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_PowerGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge_ROM_NVBlockDescriptor_BsRt_PowerGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock_ROM_NVBlockDescriptor_BsRt_RealTimeClock = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_SpeedoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge_ROM_NVBlockDescriptor_BsRt_SpeedoGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_TachoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge_ROM_NVBlockDescriptor_BsRt_TachoGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_TempGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge_ROM_NVBlockDescriptor_BsRt_TempGauge = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer_ROM_NVBlockDescriptor_BsRt_TripComputer = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsRt_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning_ROM_NVBlockDescriptor_BsRt_Warning = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsShare_EcuPartNumber, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U}, {1U, 1U, 0U
  }, {1U, 1U, 0U}, {255U, 255U, 255U}, {255U, 255U, 255U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint_ROM_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsShare_SwUpdFotaMode, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode_ROM_NVBlockDescriptor_BsShare_SwUpdFotaMode = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsShare_SwUpdFotaStatus, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus_ROM_NVBlockDescriptor_BsShare_SwUpdFotaStatus = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsShare_SwUpdFotadecrypt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt_ROM_NVBlockDescriptor_BsShare_SwUpdFotadecrypt = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsShare_SwUpdReflash, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash_ROM_NVBlockDescriptor_BsShare_SwUpdReflash = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsShare_VehicleConfig, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig_ROM_NVBlockDescriptor_BsShare_VehicleConfig = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsShare_VisMeet, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet_ROM_NVBlockDescriptor_BsShare_VisMeet = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}, 65535U
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_RefCys_Certicificate1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1_ROM_NVBlockDescriptor_RefCys_Certicificate1 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_RefCys_Certicificate, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate_ROM_NVBlockDescriptor_RefCys_Certicificate = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/
#define RTE_FBK_COM_STOPPED                (0U)
#define RTE_FBK_TIMEOUT                    (1U)
#define RTE_FBK_TRANSMIT_ACK               (2U)
#define RTE_FBK_NO_DATA                    (3U)

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
 * Queues for each Rte_Receive function
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(SDiagResponse, RTE_VAR_NOINIT) Rte_Q_CMeetCdd_rSR_DiagResponse_DiagResponseData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SUpdateShortServiceResp, RTE_VAR_NOINIT) Rte_Q_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SMainHMIReadyStatus, RTE_VAR_NOINIT) Rte_Q_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData[5]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDomainFatalError, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDomainHeartbeat, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData[5]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDumpData, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData[1]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDumpHdrInfo, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData[1]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SPowerExtendShutdownTime, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData[5]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SPowerKeepSystemAwake, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData[5]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SDiagDIDRequest, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SDiagIOCtrlRequest, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SDiagRoutineRequest, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDumpGetData, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData[1]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDumpGetHdr, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData[1]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SUpdateLongServiceReq, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SUpdateShortServiceReq, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
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

#define Rte_QInit() (Rte_MemClr(Rte_QRamInfo, 16 * sizeof(Rte_QRamInfoType)))

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

#define Rte_OsApplication_NonTrusted_QOverflowInit() (Rte_MemClr(&Rte_OsApplication_NonTrusted_QOverflow, sizeof(Rte_OsApplication_NonTrusted_QOverflow)))

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_QRamInfoType, RTE_VAR_NOINIT) Rte_QRamInfo[16]; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 0850, 1504 L1 */ /* MD_MSR_19.8, MD_MSR_8.10 */
CONST(Rte_QRomInfoType, RTE_CONST) Rte_QRomInfo[16] =
{
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_CMeetCdd_rSR_DiagResponse_DiagResponseData[0], /* Rte_BasePtr */
    sizeof(SDiagResponse),  /* Rte_BytesPerElement */
    2 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_CUpdateCdd_rp_SR_UpdateShortServiceResponse_UpdateShortServiceRespData[0], /* Rte_BasePtr */
    sizeof(SUpdateShortServiceResp),  /* Rte_BytesPerElement */
    2 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_Ctrl_WSS_rpUclHMIReadySts_MainHMIReadyStatusData[0], /* Rte_BasePtr */
    sizeof(SMainHMIReadyStatus),  /* Rte_BytesPerElement */
    5 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData[0], /* Rte_BasePtr */
    sizeof(SHealthDomainFatalError),  /* Rte_BytesPerElement */
    2 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData[0], /* Rte_BasePtr */
    sizeof(SHealthDomainHeartbeat),  /* Rte_BytesPerElement */
    5 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData[0], /* Rte_BasePtr */
    sizeof(SHealthDumpData),  /* Rte_BytesPerElement */
    1 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData[0], /* Rte_BasePtr */
    sizeof(SHealthDumpHdrInfo),  /* Rte_BytesPerElement */
    1 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData[0], /* Rte_BasePtr */
    sizeof(SPowerExtendShutdownTime),  /* Rte_BytesPerElement */
    5 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData[0], /* Rte_BasePtr */
    sizeof(SPowerKeepSystemAwake),  /* Rte_BytesPerElement */
    5 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData[0], /* Rte_BasePtr */
    sizeof(SDiagDIDRequest),  /* Rte_BytesPerElement */
    2 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData[0], /* Rte_BasePtr */
    sizeof(SDiagIOCtrlRequest),  /* Rte_BytesPerElement */
    2 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData[0], /* Rte_BasePtr */
    sizeof(SDiagRoutineRequest),  /* Rte_BytesPerElement */
    2 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData[0], /* Rte_BasePtr */
    sizeof(SHealthDumpGetData),  /* Rte_BytesPerElement */
    1 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData[0], /* Rte_BasePtr */
    sizeof(SHealthDumpGetHdr),  /* Rte_BytesPerElement */
    1 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData[0], /* Rte_BasePtr */
    sizeof(SUpdateLongServiceReq),  /* Rte_BytesPerElement */
    2 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData[0], /* Rte_BasePtr */
    sizeof(SUpdateShortServiceReq),  /* Rte_BytesPerElement */
    2 /* Rte_MaxElements */
  }
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
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

FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num) /* PRQA S 3408, 1505 */ /* MD_Rte_3408, MD_MSR_8.10 */
{
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source;
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination;
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = src[i];
  }
}

#define RTE_MEMCPY32ALIGN (sizeof(uint32) - 1)

FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num)
{
  P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA) asrc = (P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA)) source;
  P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR) adst = (P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR)) destination;
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source;
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination;
  uint32_least i = 0;

  if (num >= 16)
  {
    if (((((uint32)src) & RTE_MEMCPY32ALIGN) == 0) && ((((uint32)dst) & RTE_MEMCPY32ALIGN) == 0)) /* PRQA S 0306 */ /* MD_Rte_0306 */
    {
      uint32_least asize = num / sizeof(uint32);
      uint32_least rem = num & RTE_MEMCPY32ALIGN;
      for (i = 0; i < (asize - 3); i += 4)
      {
        adst[i] = asrc[i];
        adst[i+1] = asrc[i+1];
        adst[i+2] = asrc[i+2];
        adst[i+3] = asrc[i+3];
      }

      while (i < asize)
      {
        adst[i] = asrc[i];
        ++i;
      }
      i = num - rem;
    }
    else
    {
      for (i = 0; (i + 15) < num; i += 16)
      {
        dst[i] = src[i];
        dst[i+1] = src[i+1];
        dst[i+2] = src[i+2];
        dst[i+3] = src[i+3];
        dst[i+4] = src[i+4];
        dst[i+5] = src[i+5];
        dst[i+6] = src[i+6];
        dst[i+7] = src[i+7];
        dst[i+8] = src[i+8];
        dst[i+9] = src[i+9];
        dst[i+10] = src[i+10];
        dst[i+11] = src[i+11];
        dst[i+12] = src[i+12];
        dst[i+13] = src[i+13];
        dst[i+14] = src[i+14];
        dst[i+15] = src[i+15];
      }
    }

  }
  while (i < num)
  {
    dst[i] = src[i];
    ++i;
  }
}

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))ptr;
  uint32_least i;
  for (i = 0; i < num; i++)
  {
    dst[i] = 0;
  }
}

FUNC(void, RTE_CODE) SchM_Init(void)
{
  /* initialize the NvBlock mirror buffers */
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio = Rte_C_NV_Data_BsConst_Audio_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication = Rte_C_NV_Data_BsConst_Communication_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer = Rte_C_NV_Data_BsConst_EngOffTimer_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge = Rte_C_NV_Data_BsConst_FuelGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = Rte_C_NV_Data_BsConst_Illumination_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 = Rte_C_NV_Data_BsConst_Illumination_Copy1_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 = Rte_C_NV_Data_BsConst_Illumination_Copy2_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge = Rte_C_NV_Data_BsConst_OilGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power = Rte_C_NV_Data_BsConst_Power_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge = Rte_C_NV_Data_BsConst_PowerGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock = Rte_C_NV_Data_BsConst_RealTimeClock_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder = Rte_C_NV_Data_BsConst_ServiceReminder_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge = Rte_C_NV_Data_BsConst_SpeedoGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge = Rte_C_NV_Data_BsConst_TachoGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge = Rte_C_NV_Data_BsConst_TempGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer = Rte_C_NV_Data_BsConst_TripComputer_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning = Rte_C_NV_Data_BsConst_Warning_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate = Rte_C_NV_Data_BsCys_Certicificate_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc = Rte_C_NV_Data_BsDiag_Dtc_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord = Rte_C_NV_Data_BsDiag_ErrorRecord_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio = Rte_C_NV_Data_BsReten_Audio_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication = Rte_C_NV_Data_BsReten_Communication_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display = Rte_C_NV_Data_BsReten_Display_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges = Rte_C_NV_Data_BsReten_Gauges_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination = Rte_C_NV_Data_BsReten_Illumination_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer = Rte_C_NV_Data_BsReten_Odometer_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization = Rte_C_NV_Data_BsReten_Personalization_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power = Rte_C_NV_Data_BsReten_Power_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock = Rte_C_NV_Data_BsReten_RealTimeClock_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer = Rte_C_NV_Data_BsReten_Tripcomputer_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning = Rte_C_NV_Data_BsReten_Warning_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt = Rte_C_NV_Data_BsRt_CusDlt_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge = Rte_C_NV_Data_BsRt_FuelGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination = Rte_C_NV_Data_BsRt_Illumination_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer = Rte_C_NV_Data_BsRt_Odometer_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge = Rte_C_NV_Data_BsRt_OilGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization = Rte_C_NV_Data_BsRt_Personalization_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge = Rte_C_NV_Data_BsRt_PowerGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock = Rte_C_NV_Data_BsRt_RealTimeClock_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge = Rte_C_NV_Data_BsRt_SpeedoGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge = Rte_C_NV_Data_BsRt_TachoGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge = Rte_C_NV_Data_BsRt_TempGauge_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer = Rte_C_NV_Data_BsRt_TripComputer_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning = Rte_C_NV_Data_BsRt_Warning_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = Rte_C_NV_Data_BsShare_EcuPartNumber_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint = Rte_C_NV_Data_BsShare_SwUpdFotaFinPrint_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode = Rte_C_NV_Data_BsShare_SwUpdFotaMode_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus = Rte_C_NV_Data_BsShare_SwUpdFotaStatus_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt = Rte_C_NV_Data_BsShare_SwUpdFotadecrypt_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash = Rte_C_NV_Data_BsShare_SwUpdReflash_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig = Rte_C_NV_Data_BsShare_VehicleConfig_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet = Rte_C_NV_Data_BsShare_VisMeet_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate = Rte_C_NV_Data_RefCys_Certicificate_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 = Rte_C_NV_Data_RefCys_Certicificate1_0;

  /* activate the tasks */
  (void)ActivateTask(OsTask_CANFun); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_Diagnostics); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_MemSer); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_ModeMgt); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_SafeBsw); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_OsTask_ModeMgt_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_OsTask_MemSer_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Ea_Ea_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_OsTask_SafeBsw_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_OsTask_Diagnostics_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_OsTask_CANFun_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Std_ReturnType ret = RTE_E_OK;

  /* S/R queue initialization */
  Rte_QInit();
  Rte_OsApplication_NonTrusted_QOverflowInit();

  /* activate the tasks */
  (void)ActivateTask(OsTask_DispFun); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_IpcUclEv); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_LSH_16ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_NvmSpeedup); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_ModeMgt_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_DispFun_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_DispFun_0_5ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_SlowGaugeAdapter_SlowGaugeAdapter_Task, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_WdgMngt_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_MemSer_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_Mcal_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_LSH_16ms_0_16ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(16)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_EthFun_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_SafeBsw_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_SafeApp_0_30ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(30)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_GaugeFun_0_20ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_LinTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_Diagnostics_0_100ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_Diagnostics_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_Diagnostics_0_20ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_AudioTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(30)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_IndFun_0_30ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(30)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_WarnFun_0_32ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(32)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_DmnMgr_CDmnMgr_Impl_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(4)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_TripFun_0_50ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(50)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_AppFun_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_FotaTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_CANFun_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_INIT;

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_OsTask_AppFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_AudioTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_CANFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_Diagnostics_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_Diagnostics_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_Diagnostics_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_DispFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_DispFun_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SlowGaugeAdapter_SlowGaugeAdapter_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_EthFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_FotaTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_GaugeFun_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_IndFun_0_30ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_DmnMgr_CDmnMgr_Impl_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_LSH_16ms_0_16ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_LinTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_Mcal_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_MemSer_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_ModeMgt_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_SafeApp_0_30ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_IoHwAb_IoHwAb_OsTask_SafeBsw_WdgM_CheckPoint_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_SafeBsw_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_TripFun_0_50ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_WarnFun_0_32ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_WdgMngt_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_OsTask_CANFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_OsTask_Diagnostics_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_OsTask_MemSer_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Ea_Ea_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_OsTask_ModeMgt_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_OsTask_SafeBsw_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_UNINIT;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_InitState = RTE_STATE_UNINIT;

  Rte_InitMemory_OsApplication_NonTrusted();
  Rte_InitMemory_OsApplication_Trusted();
}


/**********************************************************************************************************************
 * COM-Callbacks for DataReceivedEvent triggered runnables, inter-ECU client/server communication, for queued com. and for Rx timeout / Rx inv. flag (reset)
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_SG_ABS_oABS_oCAN00_6681ad27_Rx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_OsApplication_NonTrusted_RxNeverReceivedFlags.Rte_RxNeverReceived_SG_ABS_oABS_oCAN00_6681ad27_Rx = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    (void)Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SG_ABS_oABS_oCAN00_6681ad27_Rx, &Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx[0]);
    Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx_Length = 6;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */


/**********************************************************************************************************************
 * COM-Callbacks for DataSendCompletedEvent triggered runnables for transmission acknowledgement and error handling
 *********************************************************************************************************************/


FUNC(void, RTE_CODE) Rte_COMCbkTAck_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx(void) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    if (Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS == RTE_FBK_NO_DATA)
    {
      Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = RTE_FBK_TRANSMIT_ACK;
      Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkTErr_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    if (Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS == RTE_FBK_NO_DATA)
    {
      Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = RTE_FBK_COM_STOPPED;
      Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkTxTOut_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    if (Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS == RTE_FBK_NO_DATA)
    {
      Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = RTE_FBK_TIMEOUT;
      Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }
}



/**********************************************************************************************************************
 * RTE Schedulable entity for COM-Access from different partitions
 *********************************************************************************************************************/
FUNC(void, RTE_CODE) Rte_ComSendSignalProxyPeriodic(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  uint8 updateAction;
  updateAction = RTE_COM_SENDSIGNALPROXY_NOCHANGE;
  if (Rte_OsApplication_Trusted_TxUpdateFlags.Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS != Rte_OsApplication_NonTrusted_TxUpdateFlags.Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS)
  {
    updateAction = Rte_OsApplication_Trusted_TxUpdateFlags.Rte_TxUpdate_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS;
  }
  if (updateAction == RTE_COM_SENDSIGNALPROXY_SEND)
  {
    Std_ReturnType ret = RTE_E_OK;
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret |= Com_SendSignalGroupArray(ComConf_ComSignalGroup_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx, &Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx[0]);
    if (ret == RTE_E_COM_STOPPED)
    {
      Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = RTE_FBK_COM_STOPPED;
    }
    else
    {
      Rte_OsApplication_NonTrusted_AckFlags.Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = RTE_FBK_NO_DATA;
    }
    Rte_OsApplication_NonTrusted_TxUpdateFlags.Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS = Rte_OsApplication_Trusted_TxUpdateFlags.Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * NvM-Callback for synchronous copying of the mirror buffer from the NvM
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Audio);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Communication);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_EngOffTimer);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_FuelGauge);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Illumination);

  if (size <= 88U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Illumination_Copy1);

  if (size <= 88U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Illumination_Copy2);

  if (size <= 88U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_OilGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Power);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_PowerGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_RealTimeClock);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_ServiceReminder);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_SpeedoGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_TachoGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_TempGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_TripComputer);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Warning);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsCys_Certicificate);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsDiag_Dtc);

  if (size <= 2048U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsDiag_ErrorRecord);

  if (size <= 1024U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Audio);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Communication);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Display);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Gauges);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Illumination);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Odometer);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Personalization);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Power);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_RealTimeClock);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Tripcomputer);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Warning);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_CusDlt);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_FuelGauge);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_Illumination);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_Odometer);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_OilGauge);

  if (size <= 8U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_Personalization);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_PowerGauge);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_RealTimeClock);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_SpeedoGauge);

  if (size <= 8U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_TachoGauge);

  if (size <= 16U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_TempGauge);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_TripComputer);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_Warning);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_EcuPartNumber);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdFotaFinPrint);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdFotaMode);

  if (size <= 16U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdFotaStatus);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdFotadecrypt);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdReflash);

  if (size <= 8U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_VehicleConfig);

  if (size <= 256U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_VisMeet);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_RefCys_Certicificate);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_RefCys_Certicificate1);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}


/**********************************************************************************************************************
 * NvM-Callback for synchronous copying of the mirror buffer to the NvM
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Audio);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Communication);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_EngOffTimer);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_FuelGauge);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Illumination);

  if (size <= 88U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Illumination_Copy1);

  if (size <= 88U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Illumination_Copy2);

  if (size <= 88U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_OilGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Power);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_PowerGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_RealTimeClock);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_ServiceReminder);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_SpeedoGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_TachoGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_TempGauge);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_TripComputer);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsConst_Warning);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsCys_Certicificate);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsDiag_Dtc);

  if (size <= 2048U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsDiag_ErrorRecord);

  if (size <= 1024U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Audio);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Communication);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Display);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Gauges);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Illumination);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Odometer);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Personalization);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Power);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_RealTimeClock);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Tripcomputer);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_Warning);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_CusDlt);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_FuelGauge);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_Illumination);

  if (size <= 100U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_Odometer);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_OilGauge);

  if (size <= 8U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_Personalization);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_PowerGauge);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_RealTimeClock);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_SpeedoGauge);

  if (size <= 8U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_TachoGauge);

  if (size <= 16U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_TempGauge);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_TripComputer);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsRt_Warning);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_EcuPartNumber);

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdFotaFinPrint);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdFotaMode);

  if (size <= 16U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdFotaStatus);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdFotadecrypt);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_SwUpdReflash);

  if (size <= 8U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_VehicleConfig);

  if (size <= 256U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsShare_VisMeet);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_RefCys_Certicificate);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_RefCys_Certicificate1);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0306:  MISRA rule: 11.3
     Reason:     An optimized copy algorithm can be used for aligned data. To check if pointers are aligned, pointers need to be casted to an integer type.
     Risk:       No functional risk. Only the lower 8 bits of the address are checked, therefore all integer types are sufficient.
     Prevention: Not required.

   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_3197:  MISRA rule: -
     Reason:     The variable is not written by the code in all possible code variants. Due to this, the variable is initialized.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3355:  MISRA rule: 13.7
     Reason:     The result of the evaluation depends on the compiler specific alignment.
                 This control expression has been added for safety reasons.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3358:  MISRA rule: 13.7
     Reason:     The result of the evaluation depends on the compiler specific alignment.
                 This control expression has been added for safety reasons.
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

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/

/**********************************************************************************************************************
 Code coverage justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN
   \ID COV_RTE_NVMBUFFER_SIZE
     \ACCEPT TX
     \REASON The condition checks that the NVMBuffer is large enough to store the data. The size of the NVMBuffer is
             generated as magic number and is compared to the result of the sizeof()-Expression. Additionally, RTE Analyzer
             verifies that the NVMBuffer is at least "size"-elements long.
             As the sizeof()-Expression returns the expected (calculated) size, the condition cannot be false unless a
             wrong configuration is used. In case of a wrong configuration RTE Analyzer would detect the difference between
             the expected value and the actual size of the NVMBuffer.

COV_JUSTIFICATION_END */
