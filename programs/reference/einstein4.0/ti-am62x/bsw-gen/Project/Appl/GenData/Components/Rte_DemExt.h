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
 *          File:  Rte_DemExt.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <DemExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DEMEXT_H
# define _RTE_DEMEXT_H

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

# include "Rte_DemExt_Type.h"
# include "Rte_DataHandleType.h"


# define DemExt_START_SEC_CODE
# include "DemExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DemExt_ClearDTC DemExt_ClearDTC
#  define RTE_RUNNABLE_DemExt_GetDTCOfEvent DemExt_GetDTCOfEvent
#  define RTE_RUNNABLE_DemExt_GetDTCSelectionResult DemExt_GetDTCSelectionResult
#  define RTE_RUNNABLE_DemExt_GetDTCSelectionResultForClearDTC DemExt_GetDTCSelectionResultForClearDTC
#  define RTE_RUNNABLE_DemExt_GetDebouncingOfEvent DemExt_GetDebouncingOfEvent
#  define RTE_RUNNABLE_DemExt_GetEventExtendedDataRecordEx DemExt_GetEventExtendedDataRecordEx
#  define RTE_RUNNABLE_DemExt_GetEventFreezeFrameDataEx DemExt_GetEventFreezeFrameDataEx
#  define RTE_RUNNABLE_DemExt_GetEventUdsStatus DemExt_GetEventUdsStatus
#  define RTE_RUNNABLE_DemExt_GetFaultDetectionCounter DemExt_GetFaultDetectionCounter
#  define RTE_RUNNABLE_DemExt_GetNumberOfEventMemoryEntries DemExt_GetNumberOfEventMemoryEntries
#  define RTE_RUNNABLE_DemExt_GetOperationCycleState DemExt_GetOperationCycleState
#  define RTE_RUNNABLE_DemExt_MainFunction DemExt_MainFunction
#  define RTE_RUNNABLE_DemExt_SelectDTC DemExt_SelectDTC
#  define RTE_RUNNABLE_DemExt_SetEnableCondition DemExt_SetEnableCondition
#  define RTE_RUNNABLE_DemExt_SetEventAvailable DemExt_SetEventAvailable
#  define RTE_RUNNABLE_DemExt_SetEventStatus DemExt_SetEventStatus
#  define RTE_RUNNABLE_DemExt_SetOperationCycleState DemExt_SetOperationCycleState
#  define RTE_RUNNABLE_DemExt_SetStorageCondition DemExt_SetStorageCondition
# endif

FUNC(Std_ReturnType, DemExt_CODE) DemExt_ClearDTC(UInt8 ClientId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat, P2VAR(UInt32, AUTOMATIC, RTE_DEMEXT_APPL_VAR) DTCOfEvent); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetDTCSelectionResult(UInt8 ClientId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetDTCSelectionResultForClearDTC(UInt8 ClientId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetDebouncingOfEvent(Dem_EventIdType EventId, P2VAR(Dem_DebouncingStateType, AUTOMATIC, RTE_DEMEXT_APPL_VAR) DebouncingState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetEventExtendedDataRecordEx(Dem_EventIdType EventId, UInt8 RecordNumber, P2VAR(UInt8, AUTOMATIC, RTE_DEMEXT_APPL_VAR) DestBuffer, P2VAR(UInt16, AUTOMATIC, RTE_DEMEXT_APPL_VAR) BufSize); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, UInt8 RecordNumber, UInt16 DataId, P2VAR(UInt8, AUTOMATIC, RTE_DEMEXT_APPL_VAR) DestBuffer, P2VAR(UInt16, AUTOMATIC, RTE_DEMEXT_APPL_VAR) BufSize); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetEventUdsStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, RTE_DEMEXT_APPL_VAR) UDSStatusByte); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(SInt8, AUTOMATIC, RTE_DEMEXT_APPL_VAR) FaultDetectionCounter); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetNumberOfEventMemoryEntries(UInt8 ClientId, Dem_DTCOriginType DTCOrigin, P2VAR(UInt8, AUTOMATIC, RTE_DEMEXT_APPL_VAR) NumberOfEventMemoryEntries); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_GetOperationCycleState(UInt8 OperationCycleId, P2VAR(Dem_OperationCycleStateType, AUTOMATIC, RTE_DEMEXT_APPL_VAR) CycleState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, DemExt_CODE) DemExt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_SelectDTC(UInt8 ClientId, UInt32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_SetEnableCondition(UInt8 EnableConditionID, Boolean ConditionFulfilled); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_SetEventAvailable(Dem_EventIdType EventId, Boolean AvailableStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_SetOperationCycleState(UInt8 OperationCycleId, Dem_OperationCycleStateType CycleState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DemExt_CODE) DemExt_SetStorageCondition(UInt8 StorageConditionID, Boolean ConditionFulfilled); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DemExt_STOP_SEC_CODE
# include "DemExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_DemExt_ClearDTC_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetDTCOfEvent_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetDTCSelectionResult_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetDTCSelectionResultForClearDTC_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetDebouncingOfEvent_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetEventExtendedDataRecordEx_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetEventFreezeFrameDataEx_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetEventUdsStatus_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetFaultDetectionCounter_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetNumberOfEventMemoryEntries_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_GetOperationCycleState_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_SelectDTC_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_SetEnableCondition_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_SetEventAvailable_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_SetEventStatus_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_SetOperationCycleState_E_NOT_OK (1U)

#  define RTE_E_TI_DemExt_SetStorageCondition_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DEMEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
