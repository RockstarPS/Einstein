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
 *          File:  Rte_CFltM.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CFltM>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CFLTM_H
# define _RTE_CFLTM_H

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

# include "Rte_CFltM_Type.h"
# include "Rte_DataHandleType.h"


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DEMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DEMEXT_APPL_CODE) DemExt_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DEMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus DemExt_SetEventStatus
#  define RTE_START_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRSTM_APPL_CODE) RstM_ClearResetHistory(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RstM_ClearResetHistory_RstM_ClearResetHistory RstM_ClearResetHistory
#  define RTE_START_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRSTM_APPL_CODE) RstM_GetLastResetReason(P2VAR(eFltM_FaultIdType, AUTOMATIC, RTE_CRSTM_APPL_VAR) pFaultId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RstM_GetLastResetReason_RstM_GetLastResetReason RstM_GetLastResetReason
#  define RTE_START_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRSTM_APPL_CODE) RstM_GetResetCount(eFltM_FaultIdType FaultId, P2VAR(UInt8, AUTOMATIC, RTE_CRSTM_APPL_VAR) count); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RstM_GetResetCount_RstM_GetResetCount RstM_GetResetCount
#  define RTE_START_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRSTM_APPL_CODE) RstM_GetResetHistory(P2VAR(UInt8, AUTOMATIC, RTE_CRSTM_APPL_VAR) ResetHistory); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RstM_GetResetHistory_RstM_GetResetHistory RstM_GetResetHistory
#  define RTE_START_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRSTM_APPL_CODE) RstM_RequestSwReset(eFltM_FaultIdType FaultId, P2VAR(UInt8, AUTOMATIC, RTE_CRSTM_APPL_VAR) LogData, UInt16 LogLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRSTM_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RstM_RequestSwReset_RstM_RequestSwReset RstM_RequestSwReset


# endif /* !defined(RTE_CORE) */


# define CFltM_START_SEC_CODE
# include "CFltM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CFltM_Impl_MainFunction CFltM_Impl_MainFunction
#  define RTE_RUNNABLE_CFltM_Impl_OnCommand CFltM_Impl_OnCommand
#  define RTE_RUNNABLE_FltM_FlsIntegrity_GetStatus FltM_FlsIntegrity_GetStatus
#  define RTE_RUNNABLE_FltM_HandlePostReset FltM_HandlePostReset
#  define RTE_RUNNABLE_FltM_ReportFault FltM_ReportFault
# endif

FUNC(void, CFltM_CODE) CFltM_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, CFltM_CODE) CFltM_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CFltM_CODE) FltM_FlsIntegrity_GetStatus(P2VAR(eFltM_FlsIntegrityStatusType, AUTOMATIC, RTE_CFLTM_APPL_VAR) Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, CFltM_CODE) FltM_HandlePostReset(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, CFltM_CODE) FltM_ReportFault(eFltM_FaultIdType FaultId, eFltM_FaultStatusType FaultStatus, P2VAR(UInt8, AUTOMATIC, RTE_CFLTM_APPL_VAR) LogData, UInt16 LogLength); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CFltM_STOP_SEC_CODE
# include "CFltM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_DemExt_SetEventStatus_E_NOT_OK (1U)

#  define RTE_E_TI_FltM_ReportFault_E_NOT_OK (1U)

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

#endif /* _RTE_CFLTM_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
