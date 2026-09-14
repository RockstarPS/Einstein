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
 *          File:  Rte_NvMExt.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <NvMExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_NVMEXT_H
# define _RTE_NVMEXT_H

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

# include "Rte_NvMExt_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted (FALSE)
#  define Rte_InitValue_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted (FALSE)
#  define Rte_InitValue_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted (FALSE)
#  define Rte_InitValue_pp_SR_NvMExt_WakeupStatus_WakeupFlag (FALSE)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted Rte_Write_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted
#  define Rte_Write_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted(data) (Rte_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted Rte_Write_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted
#  define Rte_Write_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted(data) (Rte_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted Rte_Write_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted
#  define Rte_Write_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted(data) (Rte_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted = (data), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SR_NvMExt_WakeupStatus_WakeupFlag Rte_Write_NvMExt_pp_SR_NvMExt_WakeupStatus_WakeupFlag
#  define Rte_Write_NvMExt_pp_SR_NvMExt_WakeupStatus_WakeupFlag(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define NvMExt_START_SEC_CODE
# include "NvMExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_NvMExt_CancelSleep NvMExt_CancelSleep
#  define RTE_RUNNABLE_NvMExt_GetErrorStatus NvMExt_GetErrorStatus
#  define RTE_RUNNABLE_NvMExt_GetPendingStatus NvMExt_GetPendingStatus
#  define RTE_RUNNABLE_NvMExt_MainFunction NvMExt_MainFunction
#  define RTE_RUNNABLE_NvMExt_ReadAll NvMExt_ReadAll
#  define RTE_RUNNABLE_NvMExt_ReadBlock NvMExt_ReadBlock
#  define RTE_RUNNABLE_NvMExt_ReadytoSleep NvMExt_ReadytoSleep
#  define RTE_RUNNABLE_NvMExt_RequestSleep NvMExt_RequestSleep
#  define RTE_RUNNABLE_NvMExt_RestoreBlockDefaults NvMExt_RestoreBlockDefaults
#  define RTE_RUNNABLE_NvMExt_SpeedupRunnable NvMExt_SpeedupRunnable
#  define RTE_RUNNABLE_NvMExt_WriteBlock NvMExt_WriteBlock
#  define RTE_RUNNABLE_NvmExt_GetNvMReadAllStatus NvmExt_GetNvMReadAllStatus
# endif

FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_CancelSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_GetErrorStatus(NvM_BlockIdType NvmBlockId, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVMEXT_APPL_VAR) RequestResultPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_GetPendingStatus(UInt8 NvmBlockID, P2VAR(UInt8, AUTOMATIC, RTE_NVMEXT_APPL_VAR) Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NvMExt_CODE) NvMExt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, NvMExt_CODE) NvMExt_ReadAll(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_ReadBlock(NvM_BlockIdType NvmBlockId, P2VAR(UInt8, AUTOMATIC, RTE_NVMEXT_APPL_VAR) NvMDstPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_ReadytoSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_RequestSleep(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_RestoreBlockDefaults(NvM_BlockIdType NvmBlockId, P2VAR(UInt8, AUTOMATIC, RTE_NVMEXT_APPL_VAR) NvMDstPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NvMExt_CODE) NvMExt_SpeedupRunnable(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, NvMExt_CODE) NvMExt_WriteBlock(NvM_BlockIdType NvmBlockId, P2VAR(UInt8, AUTOMATIC, RTE_NVMEXT_APPL_VAR) NvM_SrcPtr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, NvMExt_CODE) NvmExt_GetNvMReadAllStatus(P2VAR(Boolean, AUTOMATIC, RTE_NVMEXT_APPL_VAR) Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define NvMExt_STOP_SEC_CODE
# include "NvMExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_NvMExt_GetErrorStatus_E_NOT_OK (1U)

#  define RTE_E_TI_NvMExt_ReadBlock_E_NOT_OK (1U)

#  define RTE_E_TI_NvMExt_RestoreBlockDefaults_E_NOT_OK (1U)

#  define RTE_E_TI_NvMExt_SleepOperations_E_NOT_OK (1U)

#  define RTE_E_TI_NvMExt_WriteBlock_E_NOT_OK (1U)

#  define RTE_E_TI_NvmExt_GetPendingStatus_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_NVMEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
