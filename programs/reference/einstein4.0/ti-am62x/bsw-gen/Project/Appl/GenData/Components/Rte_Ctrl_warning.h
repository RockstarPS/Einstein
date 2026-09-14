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
 *          File:  Rte_Ctrl_warning.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Ctrl_warning>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTRL_WARNING_H
# define _RTE_CTRL_WARNING_H

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

# include "Rte_Ctrl_warning_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_rpIgnSubstate_IgnitionSubstate (0U)
#  define Rte_InitValue_rp_ClusterMode_WSSCurrentClusterMode (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rpIgnSubstate_IgnitionSubstate Rte_Read_Ctrl_warning_rpIgnSubstate_IgnitionSubstate
#  define Rte_Read_Ctrl_warning_rpIgnSubstate_IgnitionSubstate(data) (*(data) = Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ClusterMode_WSSCurrentClusterMode Rte_Read_Ctrl_warning_rp_ClusterMode_WSSCurrentClusterMode
#  define Rte_Read_Ctrl_warning_rp_ClusterMode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define Ctrl_warning_START_SEC_CODE
# include "Ctrl_warning_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Ctrl_warning_GetActiveWarningStatus Ctrl_warning_GetActiveWarningStatus
#  define RTE_RUNNABLE_Ctrl_warning_GetWarningActiveStatus Ctrl_warning_GetWarningActiveStatus
#  define RTE_RUNNABLE_Ctrl_warning_GetWarningDisplayedPayload Ctrl_warning_GetWarningDisplayedPayload
#  define RTE_RUNNABLE_Ctrl_warning_GetWarningDisplayedStatus Ctrl_warning_GetWarningDisplayedStatus
#  define RTE_RUNNABLE_Ctrl_warning_Get_Red_MasterLamp_Status Ctrl_warning_Get_Red_MasterLamp_Status
#  define RTE_RUNNABLE_Ctrl_warning_Get_Yellow_MasterLamp_Status Ctrl_warning_Get_Yellow_MasterLamp_Status
#  define RTE_RUNNABLE_Ctrl_warning_Init Ctrl_warning_Init
#  define RTE_RUNNABLE_Ctrl_warning_SetWarningDisplayedPayload Ctrl_warning_SetWarningDisplayedPayload
#  define RTE_RUNNABLE_Ctrl_warning_SetWarningDisplayedStatus Ctrl_warning_SetWarningDisplayedStatus
#  define RTE_RUNNABLE_Ctrl_warning_Task Ctrl_warning_Task
#  define RTE_RUNNABLE_Ctrl_warning_UpdateExtdPayload Ctrl_warning_UpdateExtdPayload
#  define RTE_RUNNABLE_Ctrl_warning_UpdateWarningStatus Ctrl_warning_UpdateWarningStatus
#  define RTE_RUNNABLE_Ctrl_warning_Warning_Group_update Ctrl_warning_Warning_Group_update
# endif

FUNC(void, Ctrl_warning_CODE) Ctrl_warning_GetActiveWarningStatus(WarningId CurrentWarning, P2VAR(ExtWarningData, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) CurrentWarningStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_GetWarningActiveStatus(WarningId CurrentWarning, P2VAR(WarningDataS, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) CurrentWarningStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_GetWarningDisplayedPayload(WarningId CurWarningId, P2VAR(Rte_DT_PayloadArr_u8_8_0, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) DisplayedPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_GetWarningDisplayedPayload(WarningId CurWarningId, P2VAR(PayloadArr_u8_8, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) DisplayedPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_GetWarningDisplayedStatus(WarningId CurWarningId, P2VAR(WarningDisplayedStatus, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) DisplayedStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Get_Red_MasterLamp_Status(P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) LampStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Get_Yellow_MasterLamp_Status(P2VAR(UInt8, AUTOMATIC, RTE_CTRL_WARNING_APPL_VAR) LampStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_SetWarningDisplayedPayload(WarningId CurWarningId, P2CONST(Rte_DT_PayloadArr_u8_8_0, AUTOMATIC, RTE_CTRL_WARNING_APPL_DATA) CurWarningDispPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_SetWarningDisplayedPayload(WarningId CurWarningId, P2CONST(PayloadArr_u8_8, AUTOMATIC, RTE_CTRL_WARNING_APPL_DATA) CurWarningDispPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_SetWarningDisplayedStatus(WarningId CurWarningId, WarningDisplayedStatus CurWarningDispStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_UpdateExtdPayload(WarningId WarningCurId, P2CONST(Rte_DT_PayloadArr_u8_8_0, AUTOMATIC, RTE_CTRL_WARNING_APPL_DATA) WarningPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# else
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_UpdateExtdPayload(WarningId WarningCurId, P2CONST(PayloadArr_u8_8, AUTOMATIC, RTE_CTRL_WARNING_APPL_DATA) WarningPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
# endif
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_UpdateWarningStatus(WarningId WarningCurId, WarningStatus WarningCurStatus, WarningEvent WarningCurEvent, UInt32 WarningPayload); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Ctrl_warning_CODE) Ctrl_warning_Warning_Group_update(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define Ctrl_warning_STOP_SEC_CODE
# include "Ctrl_warning_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTRL_WARNING_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
