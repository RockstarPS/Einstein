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
 *          File:  Rte_SlowGaugeAdapter.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <SlowGaugeAdapter>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_SLOWGAUGEADAPTER_H
# define _RTE_SLOWGAUGEADAPTER_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_SlowGaugeAdapter_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(HMIReadySts_Type, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
#  define Rte_InitValue_rp_Dcm_appStop_AppId (0U)
#  define Rte_InitValue_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value (0U)
#  define Rte_InitValue_rp_DispDistanceUnit_DisplayUnit (0U)
#  define Rte_InitValue_rp_HMIReadyState_HMI_ReadyStatus (0U)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SlowGaugeAdapter_pp_SlowGaugeInfo_SlowGaugeInfoData(P2CONST(SSlowGuageInfo, AUTOMATIC, RTE_SLOWGAUGEADAPTER_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_SlowGaugeAdapter_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_SlowGaugeAdapter_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_SlowGaugeAdapter_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_SlowGaugeAdapter_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Dcm_appStop_AppId Rte_Read_SlowGaugeAdapter_rp_Dcm_appStop_AppId
#  define Rte_Read_SlowGaugeAdapter_rp_Dcm_appStop_AppId(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value Rte_Read_SlowGaugeAdapter_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value
#  define Rte_Read_SlowGaugeAdapter_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_DispDistanceUnit_DisplayUnit Rte_Read_SlowGaugeAdapter_rp_DispDistanceUnit_DisplayUnit
#  define Rte_Read_SlowGaugeAdapter_rp_DispDistanceUnit_DisplayUnit(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_HMIReadyState_HMI_ReadyStatus Rte_Read_SlowGaugeAdapter_rp_HMIReadyState_HMI_ReadyStatus
#  define Rte_Read_SlowGaugeAdapter_rp_HMIReadyState_HMI_ReadyStatus(data) (*(data) = Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_SlowGaugeInfo_SlowGaugeInfoData Rte_Write_SlowGaugeAdapter_pp_SlowGaugeInfo_SlowGaugeInfoData


# endif /* !defined(RTE_CORE) */


# define SlowGaugeAdapter_START_SEC_CODE
# include "SlowGaugeAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_SlowGaugeAdapter_Init SlowGaugeAdapter_Init
#  define RTE_RUNNABLE_SlowGaugeAdapter_Task SlowGaugeAdapter_Task
# endif

FUNC(void, SlowGaugeAdapter_CODE) SlowGaugeAdapter_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, SlowGaugeAdapter_CODE) SlowGaugeAdapter_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define SlowGaugeAdapter_STOP_SEC_CODE
# include "SlowGaugeAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_SLOWGAUGEADAPTER_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
