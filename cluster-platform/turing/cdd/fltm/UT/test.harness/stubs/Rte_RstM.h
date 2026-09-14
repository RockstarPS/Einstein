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
 *          File:  Rte_RstM.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <RstM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_RSTM_H
# define _RTE_RSTM_H

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

# include "Rte_RstM_Type.h"
# include "Rte_DataHandleType.h"


# define RstM_START_SEC_CODE
# include "RstM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_RstM_ClearResetHistory RstM_ClearResetHistory
#  define RTE_RUNNABLE_RstM_GetLastResetReason RstM_GetLastResetReason
#  define RTE_RUNNABLE_RstM_GetResetCount RstM_GetResetCount
#  define RTE_RUNNABLE_RstM_GetResetHistory RstM_GetResetHistory
#  define RTE_RUNNABLE_CRstM_Impl_MainFunction CRstM_Impl_MainFunction
#  define RTE_RUNNABLE_CRstM_Impl_OnCommand CRstM_Impl_OnCommand
#  define RTE_RUNNABLE_RstM_RequestSwReset RstM_RequestSwReset
# endif

FUNC(Std_ReturnType, RstM_CODE) RstM_ClearResetHistory(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RstM_CODE) RstM_GetLastResetReason(P2VAR(eFltM_FaultIdType, AUTOMATIC, RTE_RSTM_APPL_VAR) pFaultId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RstM_CODE) RstM_GetResetCount(eFltM_FaultIdType FaultId, P2VAR(UInt8, AUTOMATIC, RTE_RSTM_APPL_VAR) count); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RstM_CODE) RstM_GetResetHistory(P2VAR(UInt8, AUTOMATIC, RTE_RSTM_APPL_VAR) ResetHistory); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, RstM_CODE) CRstM_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, RstM_CODE) CRstM_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RstM_CODE) RstM_RequestSwReset(eFltM_FaultIdType FaultId, P2VAR(UInt8, AUTOMATIC, RTE_RSTM_APPL_VAR) LogData, UInt16 LogLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RstM_STOP_SEC_CODE
# include "RstM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_RstM_ClearResetHistory_E_NOT_OK (1U)

#  define RTE_E_TI_RstM_GetLastResetReason_E_NOT_OK (1U)

#  define RTE_E_TI_RstM_GetResetCount_E_NOT_OK (1U)

#  define RTE_E_TI_RstM_GetResetHistory_E_NOT_OK (1U)

#  define RTE_E_TI_RstM_RequestSwReset_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_RSTM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
