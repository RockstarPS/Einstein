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
 *   ECU-Project:  EcuInstance
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
#include "Rte_CBattMdl.h"
#include "Rte_CCDD_EcuPowerM.h"
#include "Rte_CDisplayCdd.h"
#include "Rte_CSleepManager.h"
#include "Rte_ComM.h"
#include "Rte_DemMaster_0.h"
#include "Rte_DemSatellite_0.h"
#include "Rte_Dlt.h"
#include "Rte_DltExt.h"
#include "Rte_DmnMgr.h"
#include "Rte_EcuAppM.h"
#include "Rte_EcuM.h"
#include "Rte_EcuMExt.h"
#include "Rte_IoHwAb.h"
#include "Rte_MemAbstractMdl.h"
#include "Rte_MemAbstractStub.h"
#include "Rte_NvM.h"
#include "Rte_NvMExt.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_RtcCdd.h"
#include "Rte_SciDrv.h"
#include "Rte_Test_Comp.h"
#include "Rte_TmExt.h"
#include "Rte_UclProxyCdd.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Ea.h"
#include "SchM_NvM.h"

#include "Rte_Hook.h"

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
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
CONST(Arr_u8_32, RTE_CONST) Rte_C_Arr_u8_32_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(Arr_u8_48, RTE_CONST) Rte_C_Arr_u8_48_0 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
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
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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
CONST(NV_Data_BsFuSa_Audio, RTE_CONST) Rte_C_NV_Data_BsFuSa_Audio_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsFuSa_Communication, RTE_CONST) Rte_C_NV_Data_BsFuSa_Communication_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsFuSa_Config, RTE_CONST) Rte_C_NV_Data_BsFuSa_Config_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsFuSa_Display, RTE_CONST) Rte_C_NV_Data_BsFuSa_Display_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsFuSa_Power, RTE_CONST) Rte_C_NV_Data_BsFuSa_Power_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsFuSa_Warning, RTE_CONST) Rte_C_NV_Data_BsFuSa_Warning_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(NV_Data_BsFusa_Fota, RTE_CONST) Rte_C_NV_Data_BsFusa_Fota_0 = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
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
CONST(NV_Data_BsReten_VisDlt, RTE_CONST) Rte_C_NV_Data_BsReten_VisDlt_0 = {
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
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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
CONST(SDisplayCurrentState, RTE_CONST) Rte_C_SDisplayCurrentState_0 = {
  0U, 4U
};
/* PRQA L:L1 */
/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
CONST(SDmnStatus, RTE_CONST) Rte_DmnMgrSDmnStatusValue0 = {
  0U, 0U, 0, 0U, 0U, 0U
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
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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
CONST(NV_Data_BsFuSa_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio_ROM_NVBlockDescriptor_BsFuSa_Audio = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsFuSa_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication_ROM_NVBlockDescriptor_BsFuSa_Communication = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsFuSa_Config, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config_ROM_NVBlockDescriptor_BsFuSa_Config = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsFuSa_Display, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display_ROM_NVBlockDescriptor_BsFuSa_Display = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsFuSa_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power_ROM_NVBlockDescriptor_BsFuSa_Power = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsFuSa_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning_ROM_NVBlockDescriptor_BsFuSa_Warning = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 0850, 3408 L1 */ /* MD_MSR_19.8, MD_Rte_3408 */
CONST(NV_Data_BsFusa_Fota, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota_ROM_NVBlockDescriptor_BsFusa_Fota = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
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
CONST(NV_Data_BsReten_VisDlt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt_ROM_NVBlockDescriptor_BsReten_VisDlt = {
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
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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

VAR(SHealthDomainFatalError, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData[2]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDomainHeartbeat, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData[5]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDumpData, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData[1]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDumpHdrInfo, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData[1]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SPowerExtendShutdownTime, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData[5]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SPowerKeepSystemAwake, RTE_VAR_NOINIT) Rte_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData[5]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDumpGetData, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData[1]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */
VAR(SHealthDumpGetHdr, RTE_VAR_NOINIT) Rte_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData[1]; /* PRQA S 0850, 1504, 3408 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Data structures for queue handling
 *********************************************************************************************************************/

#define RTE_Q_OK     ((Rte_QReturnType)0)
#define RTE_Q_EMPTY  ((Rte_QReturnType)1)
#define RTE_Q_FULL   ((Rte_QReturnType)2)

#define RTE_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData (0)
#define RTE_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData (1)
#define RTE_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData (2)
#define RTE_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData (3)
#define RTE_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData (4)
#define RTE_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData (5)
#define RTE_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData (6)
#define RTE_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData (7)

typedef uint8 Rte_QReturnType;
typedef uint8 Rte_QIndexType;

#define Rte_QInit() (Rte_MemClr(Rte_QRamInfo, 8 * sizeof(Rte_QRamInfoType)))

#define Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b0)
#define Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b1)
#define Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b2)
#define Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b3)
#define Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b4)
#define Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b5)
#define Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b6)
#define Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b7)

#define Rte_SystemApplication_OsCore0_QOverflowInit() (Rte_MemClr(&Rte_SystemApplication_OsCore0_QOverflow, sizeof(Rte_SystemApplication_OsCore0_QOverflow)))

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_QRamInfoType, RTE_VAR_NOINIT) Rte_QRamInfo[8]; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 0850, 1504 L1 */ /* MD_MSR_19.8, MD_MSR_8.10 */
CONST(Rte_QRomInfoType, RTE_CONST) Rte_QRomInfo[8] =
{
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
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData[0], /* Rte_BasePtr */
    sizeof(SHealthDumpGetData),  /* Rte_BytesPerElement */
    1 /* Rte_MaxElements */
  },
  {
    (P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT))&Rte_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData[0], /* Rte_BasePtr */
    sizeof(SHealthDumpGetHdr),  /* Rte_BytesPerElement */
    1 /* Rte_MaxElements */
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
#define RTE_CONST_MSEC_SystemTimer_130 (130UL)
#define RTE_CONST_MSEC_SystemTimer_20 (20UL)
#define RTE_CONST_MSEC_SystemTimer_30 (30UL)
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
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio = Rte_C_NV_Data_BsFuSa_Audio_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication = Rte_C_NV_Data_BsFuSa_Communication_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config = Rte_C_NV_Data_BsFuSa_Config_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display = Rte_C_NV_Data_BsFuSa_Display_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power = Rte_C_NV_Data_BsFuSa_Power_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning = Rte_C_NV_Data_BsFuSa_Warning_0;
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota = Rte_C_NV_Data_BsFusa_Fota_0;
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
  Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt = Rte_C_NV_Data_BsReten_VisDlt_0;
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
  (void)ActivateTask(OsTask_Diagnostics); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_MemSer); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_OsTask_Diagnostics_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_OsTask_MemSer_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Ea_Ea_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Std_ReturnType ret = RTE_E_OK;

  /* S/R queue initialization */
  Rte_QInit();
  Rte_SystemApplication_OsCore0_QOverflowInit();

  /* activate the tasks */
  (void)ActivateTask(OsTask_CddFun); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_Graphics); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_NvmSpeedup); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_Diagnostics_0_100ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_GraphicsTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(130)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_FotaTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(100)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_AppTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(50)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_TripTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(50)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_WarnTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(30)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_IndTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(30)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_AudioTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(30)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_LinTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_GaugeTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_TxRxIpcMessage, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_EthFun_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_Mcal_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_MemSer_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(4)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_WdgMgntTaskStubRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_CddFun_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_CddFun_0_5ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Test_Comp_IoExp_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_CANFun_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_INIT;

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_AppTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_AudioTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_CANFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_CddFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_CddFun_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_Diagnostics_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_EthFun_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_FotaTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_GaugeTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_GraphicsTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_IndTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_LinTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_Mcal_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_MemSer_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_UclProxyCdd_CUclProxyCdd_Impl_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_IoExp_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_NvMExt_NvMExt_SpeedupRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_TxRxIpcMessage); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_TripTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_WarnTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Test_Comp_WdgMgntTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_OsTask_Diagnostics_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_OsTask_MemSer_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Ea_Ea_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_UNINIT;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  Rte_InitState = RTE_STATE_UNINIT;

  Rte_InitMemory_SystemApplication_OsCore0();
}


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

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination, NVMBuffer, size);
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

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Audio);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Communication);

  if (size <= 16U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Config);

  if (size <= 16U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Display);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Power);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Warning);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning, NVMBuffer, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFusa_Fota);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota, NVMBuffer, size);
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

FUNC(Std_ReturnType, RTE_CODE) Rte_SetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt(P2CONST(void, AUTOMATIC, RTE_APPL_DATA) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_VisDlt);

  if (size <= 256U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(&Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt, NVMBuffer, size);
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

  if (size <= 128U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination, size);
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

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Audio);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Communication);

  if (size <= 16U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Config);

  if (size <= 16U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Display);

  if (size <= 64U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Power);

  if (size <= 48U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFuSa_Warning);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning, size);
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsFusa_Fota);

  if (size <= 32U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota, size);
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

FUNC(Std_ReturnType, RTE_CODE) Rte_GetMirror_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) NVMBuffer) /* PRQA S 0850, 3112 */ /* MD_MSR_19.8, MD_MSR_14.2 */
{
  Std_ReturnType ret = E_NOT_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */
  CONST(uint16_least, RTE_CONST) size = sizeof(NV_Data_BsReten_VisDlt);

  if (size <= 256U) /* PRQA S 3355, 3358 */ /* MD_Rte_3355, MD_Rte_3358 */ /* COV_RTE_NVMBUFFER_SIZE */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_MemCpy32(NVMBuffer, &Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt, size);
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
