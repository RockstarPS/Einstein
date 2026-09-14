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
 *          File:  Rte_SystemApplication_OsCore0.c
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
#include "Rte_NvM.h" /* PRQA S 3451 */ /* MD_Rte_3451_NvM */
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

#include "NvM.h" /* PRQA S 3451 */ /* MD_Rte_3451_NvM */

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
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(UInt8, RTE_VAR_INIT) Rte_CSleepManager_ppSR_SleepStatus_SleepManager_SleepStatus = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SPowerSystemStateReqChange, RTE_VAR_INIT) Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData = {
  0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(SDmnStatus, RTE_VAR_INIT) Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus = {
  0U, 0U, 0, 0U, 0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsConst_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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
VAR(NV_Data_BsConst_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = {
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
VAR(NV_Data_BsFuSa_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsFuSa_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsFuSa_Config, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsFuSa_Display, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsFuSa_Power, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsFuSa_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(NV_Data_BsFusa_Fota, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}
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
VAR(NV_Data_BsReten_VisDlt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt = {
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
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
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
VAR(SPowerSystemState, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData = {
  0U, 0U
}; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 * Defines for Rte_ComSendSignalProxy
 *********************************************************************************************************************/
#define RTE_COM_SENDSIGNALPROXY_NOCHANGE       (0U)
#define RTE_COM_SENDSIGNALPROXY_SEND           (1U)
#define RTE_COM_SENDSIGNALPROXY_INVALIDATE     (2U)



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

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QAddElementSystemApplication_OsCore0(Rte_QIndexType q, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) pData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QUnqueueElementSystemApplication_OsCore0(Rte_QIndexType q, P2VAR(void, AUTOMATIC, RTE_APPL_VAR) pData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b0)
#define Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b1)
#define Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b2)
#define Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b3)
#define Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b4)
#define Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b5)
#define Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b6)
#define Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData (Rte_SystemApplication_OsCore0_QOverflow.Rte_b7)

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_SystemApplication_OsCore0_QOverflowType, RTE_VAR_NOINIT) Rte_SystemApplication_OsCore0_QOverflow; /* PRQA S 0850, 1504 */ /* MD_MSR_19.8, MD_MSR_8.10 */

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


FUNC(void, RTE_CODE) Rte_InitMemory_SystemApplication_OsCore0(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* reset Dirty Flags */
  Rte_DirtyFlagsInit();

  /* set default values for internal data */
  Rte_CSleepManager_ppSR_SleepStatus_SleepManager_SleepStatus = 0U;
  Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData = Rte_UclProxyCddPowerSystemStateReqChangeDataValue0;
  Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus = Rte_DmnMgrSDmnStatusValue0;
  Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData = Rte_DmnMgrPowerSystemStateDataValue0;

}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_DmnMgr_pSR_HealthDumpGetData_HealthDumpGetDataData(P2CONST(SHealthDumpGetData, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementSystemApplication_OsCore0(RTE_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_HealthDumpGetData */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_DmnMgr_pSR_HealthDumpGetHdr_HealthDumpGetHdrData(P2CONST(SHealthDumpGetHdr, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementSystemApplication_OsCore0(RTE_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: OnDre_HealthDumpGetHdr */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(P2CONST(SPowerSystemStateReqChange, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData = *(data);
  /* scheduled trigger for runnables: OnDre_PowerSystemStateReqChange */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DmnMgr_ppSR_DmnInfo_SDmnStatus(P2CONST(SDmnStatus, AUTOMATIC, RTE_DMNMGR_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus = *(data);

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Audio_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio.BsConst_Audio_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Communication_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication.BsConst_Communication_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_EngOffTimer_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer.BsConst_EngOffTimer_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_FuelGauge_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge.BsConst_FuelGauge_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Illumination_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Illumination_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_OilGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge.BsConst_OilGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_PowerGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge.BsConst_PowerGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Power_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power.BsConst_Power_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_RealTimeClock_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock.BsConst_RealTimeClock_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_ServiceReminder_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder.BsConst_ServiceReminder_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_SpeedoGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge.BsConst_SpeedoGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TachoGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge.BsConst_TachoGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TempGauge_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge.BsConst_TempGauge_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_TripComputer_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer.BsConst_TripComputer_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsConst_Warning_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning.BsConst_Warning_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsCys_Certicificate_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate.BsCys_Certicificate_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsDiag_Dtc_Element_Value(P2CONST(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc.BsDiag_Dtc_Element, *(data), sizeof(Arr_u8_2048));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsDiag_ErrorRecord_Element_Value(P2CONST(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord.BsDiag_ErrorRecord_Element, *(data), sizeof(Arr_u8_1024));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsFuSa_Audio_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio.BsFuSa_Audio_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsFuSa_Communication_Element_Value(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication.BsFuSa_Communication_Element, *(data), sizeof(Arr_u8_16));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsFuSa_Config_Element_Value(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config.BsFuSa_Config_Element, *(data), sizeof(Arr_u8_16));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsFuSa_Display_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display.BsFuSa_Display_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsFuSa_Power_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power.BsFuSa_Power_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsFuSa_Warning_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning.BsFuSa_Warning_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsFusa_Fota_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota.BsFusa_Fota_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Audio_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio.BsReten_Audio_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Communication_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication.BsReten_Communication_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Display_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display.BsReten_Display_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Gauges_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges.BsReten_Gauges_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Illumination_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination.BsReten_Illumination_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Odometer_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer.BsReten_Odometer_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Personalization_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization.BsReten_Personalization_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Power_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power.BsReten_Power_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_RealTimeClock_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock.BsReten_RealTimeClock_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Tripcomputer_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer.BsReten_Tripcomputer_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_VisDlt_Element_Value(P2CONST(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt.BsReten_VisDlt_Element, *(data), sizeof(Arr_u8_256));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsReten_Warning_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning.BsReten_Warning_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_CusDlt_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt.BsRt_CusDlt_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_FuelGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge.BsRt_FuelGauge_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Illumination_Element_Value(P2CONST(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination.BsRt_Illumination_Element, *(data), sizeof(Arr_u8_100));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Odometer_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer.BsRt_Odometer_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_OilGauge_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge.BsRt_OilGauge_Element, *(data), sizeof(Arr_u8_8));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Personalization_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization.BsRt_Personalization_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_PowerGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge.BsRt_PowerGauge_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_RealTimeClock_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock.BsRt_RealTimeClock_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_SpeedoGauge_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge.BsRt_SpeedoGauge_Element, *(data), sizeof(Arr_u8_8));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TachoGauge_Element_Value(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge.BsRt_TachoGauge_Element, *(data), sizeof(Arr_u8_16));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TempGauge_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge.BsRt_TempGauge_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_TripComputer_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer.BsRt_TripComputer_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsRt_Warning_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning.BsRt_Warning_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_EcuPartNumber_Element_Value(P2CONST(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_EcuPartNumber_Element, *(data), sizeof(Arr_u8_128));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value(P2CONST(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint.BsShare_SwUpdFotaFinPrint_Element, *(data), sizeof(Arr_u8_32));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value(P2CONST(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode.BsShare_SwUpdFotaMode_Element, *(data), sizeof(Arr_u8_16));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus.BsShare_SwUpdFotaStatus_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt.BsShare_SwUpdFotadecrypt_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_SwUpdReflash_Element_Value(P2CONST(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash.BsShare_SwUpdReflash_Element, *(data), sizeof(Arr_u8_8));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VehicleConfig_Element_Value(P2CONST(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig.BsShare_VehicleConfig_Element, *(data), sizeof(Arr_u8_256));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_BsShare_VisMeet_Element_Value(P2CONST(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_Element, *(data), sizeof(Arr_u8_48));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_RefCys_Certicificate1_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1.RefCys_Certicificate1_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MemAbstractStub_RefCys_Certicificate_Element_Value(P2CONST(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate.RefCys_Certicificate_Element, *(data), sizeof(Arr_u8_64));
  Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate = 1;
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  /* scheduled trigger for runnables: NvBlockSwComponentTypeRunnable */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(P2CONST(SHealthDomainFatalError, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnHealthFatalError */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(P2CONST(SHealthDomainHeartbeat, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnHeartBeat */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDumpData_HealthDumpDataData(P2CONST(SHealthDumpData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnHealthDumpData */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(P2CONST(SHealthDumpHdrInfo, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnHealthDumpHdrInfo */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(P2CONST(SPowerExtendShutdownTime, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnExtendShutdownTime */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(P2CONST(SPowerKeepSystemAwake, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (Rte_QAddElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData, (P2CONST(void, AUTOMATIC, RTE_APPL_DATA))(data)) == RTE_Q_FULL) /* PRQA S 0850 */ /* MD_MSR_19.8 */
  {
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = 1;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnKeepSystemAwake */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData(P2CONST(SPowerSystemState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData = *(data);
  /* scheduled trigger for runnables: DmnMgr_MonitorDmnPowerSystemState */
  (void)SetEvent(OsTask_MemSer, Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(P2VAR(SHealthDomainFatalError, AUTOMATIC, RTE_DMNMGR_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_HealthDomainFatalError_HealthDomainFatalErrorData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
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
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
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
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_HealthDumpData_HealthDumpDataData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_HealthDumpData_HealthDumpDataData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
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
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
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
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
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
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementSystemApplication_OsCore0(RTE_Q_DmnMgr_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
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

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio.BsConst_Audio_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Communication_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication.BsConst_Communication_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_EngOffTimer_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer.BsConst_EngOffTimer_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_FuelGauge_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge.BsConst_FuelGauge_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Illumination_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination.BsConst_Illumination_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_OilGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge.BsConst_OilGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_PowerGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge.BsConst_PowerGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Power_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power.BsConst_Power_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_RealTimeClock_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock.BsConst_RealTimeClock_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_ServiceReminder_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder.BsConst_ServiceReminder_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_SpeedoGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge.BsConst_SpeedoGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TachoGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge.BsConst_TachoGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TempGauge_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge.BsConst_TempGauge_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_TripComputer_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer.BsConst_TripComputer_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsConst_Warning_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning.BsConst_Warning_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsCys_Certicificate_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate.BsCys_Certicificate_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsDiag_Dtc_Element_Value(P2VAR(Arr_u8_2048, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc.BsDiag_Dtc_Element, sizeof(Arr_u8_2048));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsDiag_ErrorRecord_Element_Value(P2VAR(Arr_u8_1024, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord.BsDiag_ErrorRecord_Element, sizeof(Arr_u8_1024));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsFuSa_Audio_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio.BsFuSa_Audio_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsFuSa_Communication_Element_Value(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication.BsFuSa_Communication_Element, sizeof(Arr_u8_16));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsFuSa_Config_Element_Value(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config.BsFuSa_Config_Element, sizeof(Arr_u8_16));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsFuSa_Display_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display.BsFuSa_Display_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsFuSa_Power_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power.BsFuSa_Power_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsFuSa_Warning_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning.BsFuSa_Warning_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsFusa_Fota_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota.BsFusa_Fota_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Audio_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio.BsReten_Audio_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Communication_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication.BsReten_Communication_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Display_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display.BsReten_Display_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Gauges_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges.BsReten_Gauges_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Illumination_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination.BsReten_Illumination_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Odometer_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer.BsReten_Odometer_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Personalization_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization.BsReten_Personalization_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Power_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power.BsReten_Power_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_RealTimeClock_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock.BsReten_RealTimeClock_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Tripcomputer_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer.BsReten_Tripcomputer_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_VisDlt_Element_Value(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt.BsReten_VisDlt_Element, sizeof(Arr_u8_256));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsReten_Warning_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning.BsReten_Warning_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_CusDlt_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt.BsRt_CusDlt_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_FuelGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge.BsRt_FuelGauge_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Illumination_Element_Value(P2VAR(Arr_u8_100, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination.BsRt_Illumination_Element, sizeof(Arr_u8_100));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Odometer_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer.BsRt_Odometer_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_OilGauge_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge.BsRt_OilGauge_Element, sizeof(Arr_u8_8));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Personalization_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization.BsRt_Personalization_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_PowerGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge.BsRt_PowerGauge_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_RealTimeClock_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock.BsRt_RealTimeClock_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_SpeedoGauge_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge.BsRt_SpeedoGauge_Element, sizeof(Arr_u8_8));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TachoGauge_Element_Value(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge.BsRt_TachoGauge_Element, sizeof(Arr_u8_16));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TempGauge_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge.BsRt_TempGauge_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_TripComputer_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer.BsRt_TripComputer_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsRt_Warning_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning.BsRt_Warning_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_EcuPartNumber_Element_Value(P2VAR(Arr_u8_128, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber.BsShare_EcuPartNumber_Element, sizeof(Arr_u8_128));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaFinPrint_Element_Value(P2VAR(Arr_u8_32, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint.BsShare_SwUpdFotaFinPrint_Element, sizeof(Arr_u8_32));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaMode_Element_Value(P2VAR(Arr_u8_16, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode.BsShare_SwUpdFotaMode_Element, sizeof(Arr_u8_16));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotaStatus_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus.BsShare_SwUpdFotaStatus_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdFotadecrypt_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt.BsShare_SwUpdFotadecrypt_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_SwUpdReflash_Element_Value(P2VAR(Arr_u8_8, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash.BsShare_SwUpdReflash_Element, sizeof(Arr_u8_8));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VehicleConfig_Element_Value(P2VAR(Arr_u8_256, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig.BsShare_VehicleConfig_Element, sizeof(Arr_u8_256));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_BsShare_VisMeet_Element_Value(P2VAR(Arr_u8_48, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet.BsShare_VisMeet_Element, sizeof(Arr_u8_48));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_RefCys_Certicificate1_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1.RefCys_Certicificate1_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MemAbstractStub_RefCys_Certicificate_Element_Value(P2VAR(Arr_u8_64, AUTOMATIC, RTE_MEMABSTRACTSTUB_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  Rte_MemCpy32(*(data), Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate.RefCys_Certicificate_Element, sizeof(Arr_u8_64));
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Test_Comp_pSR_PowerSystemState_PowerSystemStateData(P2VAR(SPowerSystemState, AUTOMATIC, RTE_TEST_COMP_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData;

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData(P2VAR(SDiagDIDRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  data = data;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(P2VAR(SDiagIOCtrlRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  data = data;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData(P2VAR(SDiagRoutineRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505, 3206 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10, MD_Rte_3206 */
{
  data = data;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData(P2VAR(SHealthDumpGetData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  {
    Std_ReturnType lost_data = RTE_E_OK;
    Rte_QReturnType retQueue;
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementSystemApplication_OsCore0(RTE_Q_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
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
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    if (Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData == 1)
    {
      /* reset errorflag */
      Rte_QOverflow_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData = 0;
      lost_data = RTE_E_LOST_DATA;
    }
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retQueue = Rte_QUnqueueElementSystemApplication_OsCore0(RTE_Q_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData, (P2VAR(void, AUTOMATIC, RTE_APPL_VAR))(data));
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

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(P2VAR(SPowerSystemStateReqChange, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  *(data) = Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;

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

  MemAbstractMdl_NotifyJobEnd_BsConst_Illumination(ServiceId, JobResult);

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

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Audio_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsFuSa_Audio(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Communication_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsFuSa_Communication(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Config_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsFuSa_Config(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Display_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsFuSa_Display(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Power_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsFuSa_Power(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Warning_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsFuSa_Warning(ServiceId, JobResult);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsFusa_Fota_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsFusa_Fota(ServiceId, JobResult);

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

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_NvM_RpNotifyJobEnd_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_VisDlt_JobFinished(NvM_ServiceIdType ServiceId, NvM_RequestResultType JobResult) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */

  MemAbstractMdl_NotifyJobEnd_BsReten_VisDlt(ServiceId, JobResult);

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
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QAddElementSystemApplication_OsCore0(Rte_QIndexType q, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) pData)
{
  Rte_QReturnType ret = RTE_Q_FULL;
  P2VAR(Rte_QRamInfoType, AUTOMATIC, RTE_VAR_NOINIT) pRamI = &(Rte_QRamInfo[q]);
  P2CONST(Rte_QRomInfoType, AUTOMATIC, RTE_CONST) pRomI = &(Rte_QRomInfo[q]);

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
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
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return(ret);
}
/* PRQA L:L1 */

/* PRQA S 0850 L1 */ /* MD_MSR_19.8 */
RTE_LOCAL FUNC(Rte_QReturnType, RTE_CODE) Rte_QUnqueueElementSystemApplication_OsCore0(Rte_QIndexType q, P2VAR(void, AUTOMATIC, RTE_APPL_VAR) pData)
{
  Rte_QReturnType ret = RTE_Q_EMPTY;
  P2VAR(Rte_QRamInfoType, AUTOMATIC, RTE_VAR_NOINIT) pRamI = &(Rte_QRamInfo[q]); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  P2CONST(Rte_QRomInfoType, AUTOMATIC, RTE_CONST) pRomI = &(Rte_QRomInfo[q]); /* PRQA S 0850 */ /* MD_MSR_19.8 */

  Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
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
  Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

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
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Communication_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_EngOffTimer_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_FuelGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Illumination_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_OilGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_PowerGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Power_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_RealTimeClock_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_ServiceReminder_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_SpeedoGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_TachoGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_TempGauge_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_TripComputer_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsConst_Warning_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsCys_Certicificate_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsDiag_Dtc_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsDiag_ErrorRecord_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsFuSa_Audio_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsFuSa_Communication_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsFuSa_Config_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsFuSa_Display_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsFuSa_Power_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsFuSa_Warning_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsFusa_Fota_Element>
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
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsReten_VisDlt_Element>
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
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_EcuPartNumber_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdFotaFinPrint_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdFotaMode_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdFotaStatus_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdFotadecrypt_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_SwUpdReflash_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_VehicleConfig_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <BsShare_VisMeet_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <RefCys_Certicificate1_Element>
 *   - triggered on DataReceivedEvent for DataElementPrototype <Value> of PortPrototype <RefCys_Certicificate_Element>
 *
 *********************************************************************************************************************/

RTE_LOCAL FUNC(void, RTE_CODE) NvBlockSwComponentTypeRunnable(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Audio, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Communication, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_EngOffTimer, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_FuelGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Illumination, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_OilGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Power, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_PowerGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_RealTimeClock, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_ServiceReminder, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_SpeedoGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TachoGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TempGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_TripComputer, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsConst_Warning, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsCys_Certicificate, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_Dtc, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsDiag_ErrorRecord, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Audio, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Communication, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Config, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Display, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Power, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFuSa_Warning, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsFusa_Fota, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Audio, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Communication, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Display, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Gauges, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Illumination, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Odometer, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Personalization, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Power, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_RealTimeClock, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Tripcomputer, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_VisDlt, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsReten_Warning, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_CusDlt, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_FuelGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Illumination, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Odometer, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_OilGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Personalization, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_PowerGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_RealTimeClock, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_SpeedoGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TachoGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TempGauge, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_TripComputer, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsRt_Warning, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_EcuPartNumber, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaFinPrint, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaMode, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotaStatus, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdFotadecrypt, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_SwUpdReflash, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VehicleConfig, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_BsShare_VisMeet, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  if (Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 == 1)
  {
    (void)NvM_WriteBlock(NvMConf_NvMBlockDescriptor_NvBlockSwComponentTypeNVBlockDescriptor_RefCys_Certicificate1, NULL_PTR);
    Rte_DisableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_DirtyFlags.Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 = 0;
    Rte_EnableOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

}



/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     OsTask_AppFun
 * Priority: 15
 * Schedule: NON
 * Alarm:    Cycle Time 0.05 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_AppFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  AppTaskStubRunnable();

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
 * Priority: 0
 * Schedule: NON
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_CANFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  Com_MainFunctionRx();

  /* call runnable */
  Com_MainFunctionTx();

  /* call runnable */
  ComM_MainFunction_0();

  /* call runnable */
  CanSM_MainFunction();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_CddFun
 * Priority: 2
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_CddFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_OsTask_CddFun_0_10ms | Rte_Ev_Cyclic_OsTask_CddFun_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_CddFun, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_OsTask_CddFun_0_10ms | Rte_Ev_Cyclic_OsTask_CddFun_0_5ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_OsTask_CddFun_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      CddTaskStubRunnable();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_CddFun_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CBacklightCdd_Impl_MainFunction();

      /* call runnable */
      CDisplayCdd_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_CddFun_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      CBattMdl_Impl_MainFunction();

      /* call runnable */
      CCDD_EcuPowerM_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_CddFun_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CRtcCdd_Impl_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_Diagnostics
 * Priority: 18
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_Diagnostics) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms | Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_Diagnostics, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms | Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_OsTask_Diagnostics_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Dcm_MainFunction();

      /* call runnable */
      Dem_MasterMainFunction();

      /* call runnable */
      Dem_SatelliteMainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_Diagnostics_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      DltExt_MainFunction();

      /* call runnable */
      Dlt_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_EthFun
 * Priority: 7
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
 * Priority: 16
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
 * Priority: 9
 * Schedule: NON
 * Alarm:    Cycle Time 0.02 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_GaugeFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  GaugeTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_Graphics
 * Priority: 17
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(OsTask_Graphics) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_Test_Comp_GraphicsTaskStubRunnable); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_Graphics, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_Test_Comp_GraphicsTaskStubRunnable)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_Test_Comp_GraphicsTaskStubRunnable) != (EventMaskType)0)
    {
      /* call runnable */
      GraphicsTaskStubRunnable();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_IndFun
 * Priority: 12
 * Schedule: NON
 * Alarm:    Cycle Time 0.03 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_IndFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  IndTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_LinFun
 * Priority: 10
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
 * Priority: 5
 * Schedule: NON
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_Mcal) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  EcuM_MainFunction();

  /* call runnable */
  EcuMExt_MainFunction();

  /* call runnable */
  EcuAppM_MainFunction();

  /* call runnable */
  I2c_MainFunction();

  /* call runnable */
  IoHwAb_MainFunction();

  /* call runnable */
  SciDrv_MainFunction();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_MemSer
 * Priority: 4
 * Schedule: NON
 *********************************************************************************************************************/
TASK(OsTask_MemSer) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;
  EventMaskType evRun;

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms | Rte_Ev_Cyclic_OsTask_MemSer_0_10ms | Rte_Ev_Run_Ea_Ea_MainFunction | Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable | Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction | Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData | Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr | Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_MemSer, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_OsTask_MemSer_0_10ms | Rte_Ev_Cyclic_OsTask_MemSer_0_10ms | Rte_Ev_Run_Ea_Ea_MainFunction | Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable | Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction | Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData | Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr | Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange)); /* PRQA S 3417 */ /* MD_Rte_Os */

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
      Spi_MainFunction_Handling();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_CUclProxyCdd_Impl_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      CUclProxyCdd_Impl_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_MemSer_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      MemAbstract_MainFunction();

      /* call runnable */
      NvMExt_MainFunction();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetData) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_HealthDumpGetData();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_HealthDumpGetHdr) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_HealthDumpGetHdr();
    }

    if ((ev & Rte_Ev_Run_UclProxyCdd_OnDre_PowerSystemStateReqChange) != (EventMaskType)0)
    {
      /* call runnable */
      OnDre_PowerSystemStateReqChange();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_MemSer_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Test_Comp_MainFunction();

      /* call runnable */
      TmExt_MainFunction();

      /* call runnable */
      MemAbstractMdl_MainFunction();
    }

    if ((ev & Rte_Ev_Run_NvBlockSwComponentType_NvBlockSwComponentTypeRunnable) != (EventMaskType)0)
    {
      /* call runnable */
      NvBlockSwComponentTypeRunnable();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_MemSer_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CDmnMgr_Impl_MainFunction();
    }

    (void)GetEvent(OsTask_MemSer, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnExtendShutdownTime); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnExtendShutdownTime();
    }

    (void)GetEvent(OsTask_MemSer, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpData); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnHealthDumpData();
    }

    (void)GetEvent(OsTask_MemSer, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthDumpHdrInfo); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnHealthDumpHdrInfo();
    }

    (void)GetEvent(OsTask_MemSer, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHealthFatalError); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnHealthFatalError();
    }

    (void)GetEvent(OsTask_MemSer, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnHeartBeat); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnHeartBeat();
    }

    (void)GetEvent(OsTask_MemSer, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnKeepSystemAwake); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnKeepSystemAwake();
    }

    (void)GetEvent(OsTask_MemSer, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DmnMgr_DmnMgr_MonitorDmnPowerSystemState); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      DmnMgr_MonitorDmnPowerSystemState();
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_MemSer_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CSleepManager_Impl_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_ModeMgt
 * Priority: 1
 * Schedule: NON
 * Alarm:    Cycle Time 0.005 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_ModeMgt) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  IoExp_MainFunction();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_NvmSpeedup
 * Priority: 0
 * Schedule: NON
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
 * Task:     OsTask_SafeFun
 * Priority: 8
 * Schedule: NON
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_SafeFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  TxRxIpcMessage();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_TripFun
 * Priority: 14
 * Schedule: NON
 * Alarm:    Cycle Time 0.05 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_TripFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  TripTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_WarnFun
 * Priority: 13
 * Schedule: NON
 * Alarm:    Cycle Time 0.03 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_WarnFun) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  WarnTaskStubRunnable();

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     OsTask_WdgMngt
 * Priority: 3
 * Schedule: NON
 * Alarm:    Cycle Time 0.01 s Alarm Offset 0 s
 *********************************************************************************************************************/
TASK(OsTask_WdgMngt) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{

  /* call runnable */
  WdgMgntTaskStubRunnable();

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
