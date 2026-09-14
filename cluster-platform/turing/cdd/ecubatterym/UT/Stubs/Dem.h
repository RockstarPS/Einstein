/*****************************************************************************
 *                                                                            *
 *              CONFIDENTIAL VISTEON CORPORATION                              *
 *                                                                            *
 * This is an unpublished work of authorship, which contains trade            *
 * secrets, created in 2017. Visteon Corporation owns all rights to           *
 * this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right,           *
 * under the copyright laws of the United States or those of any              *
 * other country that may have jurisdiction, to protect this work             *
 * as an unpublished work, in the event of an inadvertent or                  *
 * deliberate unauthorized publication. Visteon Corporation also              *
 * reserves its rights under all copyright laws to protect this               *
 * work as a published work, when appropriate. Those having access            *
 * to this work may not copy it, use it, modify it or disclose the            *
 * information contained in it without the written authorization              *
 * of Visteon Corporation.                                                    *
 *                                                                            *
 ******************************************************************************/
/*****************************************************************************
 *  File Name         :  Dem.h                                                *
 *  Module Short Name :  ErrMgr                                               *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionlities.                    *
 *                                                                            *
 * Organization     :  Driver Information Software Section,                   *
 *                     Visteon Software Operation                             *
 *                     Visteon Corporation                                    *
 *                                                                            *
 * ---------------------------------------------------------------------------*
 * Compiler Name    :  GHS                                                    *
 * Target Hardware  :                                                         *
 *                                                                            *
 ******************************************************************************/
#ifndef DEM_H
#define DEM_H

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Dem_Types.h"
#include "Dem_Cfg.h"
#include "Dem_Private.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/
#ifndef DEM_C
#define EXTERN extern
#else
#define EXTERN
#endif

#define DEM_MODULE_ID                            (54U)
#define DEM_MAINFUNCTION_APIID                   (0x55U)              /*< Service ID: Dem_MainFunction() */
#define DEM_SETOPERATIONCYCLESTATE_APIID         (0x08U)
#define DEM_INIT_APIID                           (0x02U)
#define DEM_E_UNINIT                             (0x20U)
#define DEM_E_WRONG_CONDITION                    (0x40U)

/***	DEM DET Error Code	***/
#define DEM_DET_NO_ERROR            0U
#define DEM_DET_WRONG_CONDITION	    1U
#define DEM_DET_UNINITIALIZED       2U
#define DEM_DET_INVALID_PARAMETER   3U

#define DEM_DTC_GROUP_ALL_DTCS      0x00FFFFFFU
#define DEM_NVM_MAGIC_VALUE         0x3F

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/

/*****************************************************************************
 *                                Globally  accessed Variable Declarations    *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                                 Locally used Variable Declarations         *
 *----------------------------------------------------------------------------*
 * Declaration shall be followed by a comment that gives the following info.  *
 * about the variable.                                                        *
 * purpose, critical section, unit, and resolution                            *
 ******************************************************************************/

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/

/**************************************************************************
 Function name   : Dem_GetVersionInfo
 Arguments       : Std_VersionInfoType* versioninfo
 Return type     : void
 Sync/Async		: Synchronous
 Reentrancy		: Reentrant
 Description     : Returns the version information of this module..
 **************************************************************************/
EXTERN void Dem_GetVersionInfo(Std_VersionInfoType* versioninfo);

/* ECU State Manager <=> Dem */

/**************************************************************************
 Function name   : Dem_PreInit
 Arguments       : void
 Return type     : void
 Sync/Async		: Synchronous
 Reentrancy		: Non Reentrant
 Description     : Initializes the internal states necessary to process
 events reported by BSW-modules.
 **************************************************************************/
EXTERN void Dem_PreInit(void);

/**************************************************************************
 Function name   :  Dem_Init
 Arguments       :  const Dem_ConfigType* ConfigPtr
 Return type     :  void
 Sync/Async		:  Synchronous
 Reentrancy		:  Non Reentrant
 Description     :  Initializes or reinitializes this module.
 **************************************************************************/
EXTERN void Dem_Init(const Dem_ConfigType* ConfigPtr);

/**************************************************************************
 Function name   : Dem_Shutdown
 Arguments       : void
 Return type     : void
 Sync/Async		: Synchronous
 Reentrancy		: Non Reentrant
 Description     : Shuts down this module.
 **************************************************************************/
EXTERN void Dem_Shutdown(void);

/**************************************************************************
 Function name   : Dem_MainFunction
 Arguments       : void
 Return type     : void
 Sync/Async		:
 Reentrancy		:
 Description     : Processes all not event based Dem internal functions..
 **************************************************************************/
EXTERN void Dem_MainFunction(void);

/*** nterface BSW modules / SW-Components <=> Dem  ***/

/**************************************************************************
 Function name   : Dem_ReportErrorStatus
 Arguments       : Dem_EventIdType EventId, Dem_EventStatusType EventStatus
 Return type     : void
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Queues the reported events from the BSW modules (API is
 only used by BSW modules). The interface has an asynchronous
 behavior, because the processing of the event is
 done within the Dem main function.
 OBD Events Suppression shall be ignored for this computation.
 **************************************************************************/
EXTERN void Dem_ReportErrorStatus(Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus);

/**************************************************************************
 Function name   : Dem_SetEventAvailable
 Arguments       : Dem_EventIdType EventId, boolean AvailableStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant.
 Description     : Set the available status of a specific Event.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetEventAvailable(Dem_EventIdType EventId,
    boolean AvailableStatus);

/**************************************************************************
 Function name   : Dem_SetEventStatus
 Arguments       : Dem_EventIdType EventId, Dem_EventStatusType EventStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous/Asynchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Processes the events reported by SW-Cs via RTE. This API
 can only be used through the RTE, and therefore no declaration
 is exported via Dem.h. Some bits of the UDS DTC
 status byte changes synchronously or asynchronously (refer
 to Dem036 and Dem379).
 OBD Events Suppression shall be ignored for this computation.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus);

/**************************************************************************
 Function name   : Dem_ResetEventDebounceStatus
 Arguments       : Dem_EventIdType EventId,
 Dem_DebounceResetStatusType DebounceResetStatus)
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Control the internal debounce counter/timer by BSW modules
 and SW-Cs. The event qualification will not be affected
 by these debounce state changes. This API is available for
 BSW modules as soon as Dem_PreInit has been completed
 **************************************************************************/
EXTERN Std_ReturnType Dem_ResetEventDebounceStatus(Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus);

/**************************************************************************
 Function name   : Dem_ResetEventStatus
 Arguments       : Dem_EventIdType EventId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Resets the event failed status. This API can only be used
 through the RTE and therefore no declaration is exported via
 Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_ResetEventStatus(Dem_EventIdType EventId);

/**************************************************************************
 Function name   : Dem_PrestoreFreezeFrame
 Arguments       : Dem_EventIdType EventId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Captures the freeze frame data for a specific event. This
 API can only be used through the RTE and therefore no
 declaration is exported via Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_PrestoreFreezeFrame(Dem_EventIdType EventId);

/**************************************************************************
 Function name   : Dem_ClearPrestoredFreezeFrame
 Arguments       : Dem_EventIdType EventId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.
 Description     : Clears a prestored freeze frame of a specific event. This
 API can only be used through the RTE and therefore no
 declaration is exported via Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId);

/**************************************************************************
 Function name   : Dem_SetOperationCycleState
 Arguments       : uint8 OperationCycleId,
 Dem_OperationCycleStateType CycleState
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant.
 Description     : Sets an operation cycle state. This API can only be used
 through the RTE and therefore no declaration is exported via
 Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetOperationCycleState(uint8 OperationCycleId,
    Dem_OperationCycleStateType CycleState);

/**************************************************************************
 Function name   : Dem_GetOperationCycleState
 Arguments       : uint8 OperationCycleId,
 Dem_OperationCycleStateType* CycleState
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant.
 Description     : Gets information about the status of a specific operation cycle.
 This API can only be used through the RTE and therefore
 no declaration is exported via Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetOperationCycleState(uint8 OperationCycleId,
    Dem_OperationCycleStateType* CycleState);

#if (DEM_PROCESS_AGING_CTR_EXTERN == TRUE)
/**************************************************************************
 Function name   : Dem_SetAgingCycleState
 Arguments       : uint8 OperationCycleId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant.
 Description     : Triggers the next aging cycle state. This API can only be
 used through the RTE, and therefore no declaration is exported
 via Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetAgingCycleState(uint8 OperationCycleId);

/**************************************************************************
 Function name   : Dem_SetAgingCycleCounterValue
 Arguments       : uint8 CounterValue
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant.
 Description     : Provides the value of the external aging counter. This API
 can only be used through the RTE, and therefore no declaration
 is exported via Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetAgingCycleCounterValue(uint8 CounterValue);

#endif

/**************************************************************************
 Function name   : Dem_SetWIRStatus
 Arguments       : Dem_EventIdType EventId, boolean WIRStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant for different EventIds. Non reentrant for the same
 EventId.Non Reentrant.
 Description     : Sets the WIR status bit via failsafe SW-Cs.
 This API can only be used through the RTE and therefore no
 declaration is exported via Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetWIRStatus(Dem_EventIdType EventId, boolean WIRStatus);

/**************************************************************************
 Function name   : Dem_GetComponentFailed
 Arguments       : Dem_ComponentIdType ComponentId, boolean* ComponentFailed
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant.
 Description     : Gets the failed status of a DemComponent.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetComponentFailed(Dem_ComponentIdType ComponentId,
    boolean* ComponentFailed);

/**************************************************************************
 Function name   : Dem_GetEventStatus
 Arguments       : Dem_EventIdType EventId,
 Dem_UdsStatusByteType* EventStatusByte
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the current extended event status of an event.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetEventStatus(Dem_EventIdType EventId,
    Dem_UdsStatusByteType* EventStatusByte);

/**************************************************************************
 Function name   : Dem_GetEventFailed
 Arguments       : Dem_EventIdType EventId, boolean* EventFailed
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event failed status of an event.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetEventFailed(Dem_EventIdType EventId, boolean* EventFailed);

/**************************************************************************
 Function name   : Dem_GetEventTested
 Arguments       : Dem_EventIdType EventId, boolean* EventTested
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event tested status of an event.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetEventTested(Dem_EventIdType EventId, boolean* EventTested);

/**************************************************************************
 Function name   : Dem_GetDebouncingOfEvent
 Arguments       : Dem_EventIdType EventId,
 Dem_DebouncingStateType* DebouncingState
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event tested status of an event.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetDebouncingOfEvent(Dem_EventIdType EventId,
    Dem_DebouncingStateType* DebouncingState);

/**************************************************************************
 Function name   : Dem_GetDTCOfEvent
 Arguments       : Dem_EventIdType EventId,
 Dem_DTCFormatType DTCFormat, uint32* DTCOfEvent
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the DTC of an event.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetDTCOfEvent(Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat, uint32* DTCOfEvent);

/**************************************************************************
 Function name   : Dem_SetEnableCondition
 Arguments       : uint8 EnableConditionID, boolean ConditionFulfilled
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     : Std_ReturnType
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetEnableCondition(uint8 EnableConditionID,
    boolean ConditionFulfilled);

/**************************************************************************
 Function name   : Dem_SetStorageCondition
 Arguments       : uint8 StorageConditionID, boolean ConditionFulfilled
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Sets a storage condition.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetStorageCondition(uint8 StorageConditionID,
    boolean ConditionFulfilled);

/**************************************************************************
 Function name   : Dem_GetFaultDetectionCounter
 Arguments       : Dem_EventIdType EventId, sint8* FaultDetectionCounter
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the fault detection counter of an event. This API can
 only be used through the RTE, and therefore no declaration
 is exported via Dem.h.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetFaultDetectionCounter(Dem_EventIdType EventId,
    sint8* FaultDetectionCounter);

/**************************************************************************
 Function name   : Dem_GetIndicatorStatus
 Arguments       : uint8 IndicatorId, Dem_IndicatorStatusType* IndicatorStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the indicator status derived from the event status.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetIndicatorStatus(uint8 IndicatorId,
    Dem_IndicatorStatusType* IndicatorStatus);

/**************************************************************************
 Function name   : Dem_SetIndicatorStatus
 Arguments       : uint8 IndicatorId, Dem_IndicatorStatusType* IndicatorStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Sets the indicator status included in the event status.
 API will only exist in a Master ECU a software component if
 the MIL Master functionality is solved within the Dem of the
 Master ECU.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetIndicatorStatus(uint8 IndicatorId,
    Dem_IndicatorStatusType* IndicatorStatus);

/**************************************************************************
 Function name   : Dem_GetEventFreezeFrameData
 Arguments       : Dem_EventIdType EventId, uint8 RecordNumber,
 boolean ReportTotalRecord, uint16 DataId,uint8* DestBuffer
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the data of a freeze frame by event.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetEventFreezeFrameData(Dem_EventIdType EventId,
    uint8 RecordNumber, boolean ReportTotalRecord, uint16 DataId, uint8* DestBuffer);

/**************************************************************************
 Function name   : Dem_GetEventExtendedDataRecord
 Arguments       : Dem_EventIdType EventId, uint8 RecordNumber, uint8* DestBuffer
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the data of an extended data record by event.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetEventExtendedDataRecord(Dem_EventIdType EventId,
    uint8 RecordNumber, uint8* DestBuffer);

/**************************************************************************
 Function name   : Dem_GetEventMemoryOverflow
 Arguments       : Dem_DTCOriginType DTCOrigin, boolean* OverflowIndication
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event memory overflow indication status.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetEventMemoryOverflow(Dem_DTCOriginType DTCOrigin,
    boolean* OverflowIndication);

/**************************************************************************
 Function name   : Dem_GetNumberOfEventMemoryEntries
 Arguments       : Dem_DTCOriginType DTCOrigin, uint8* NumberOfEventMemoryEntries
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Returns the number of entries currently stored in the
 requested event memory.
 **************************************************************************/
EXTERN Std_ReturnType Dem_GetNumberOfEventMemoryEntries(Dem_DTCOriginType DTCOrigin,
    uint8* NumberOfEventMemoryEntries);

/**************************************************************************
 Function name   : Dem_SetComponentAvailable
 Arguments       : Dem_ComponentIdType ComponentId, boolean AvailableStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Set the availability of a specific DemComponent.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetComponentAvailable(Dem_ComponentIdType ComponentId,
    boolean AvailableStatus);

/**************************************************************************
 Function name   : Dem_SetDTCSuppression
 Arguments       : uint32 DTC, Dem_DTCFormatType DTCFormat,
 boolean SuppressionStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Set the suppression status of a specific DTC.
 **************************************************************************/
EXTERN Std_ReturnType Dem_SetDTCSuppression(uint32 DTC, Dem_DTCFormatType DTCFormat,
    boolean SuppressionStatus);

/**************************************************************************
 Function name   : Dem_ClearDTC
 Arguments       : uint32 DTC, Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin
 Return type     : Dem_ReturnClearDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     : Clears single DTCs, as well as groups of DTCs. This
 API is intended for complex device driver. It can only be
 used through the RTE (due to work-around described below
 SWS_Dem_00659), and therefore no declaration is exported
 via Dem.h.
 **************************************************************************/
EXTERN Dem_ReturnClearDTCType Dem_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin);

/*** Interface Dcm <=> Dem ***/

/**************************************************************************
 Function name   : Dem_DcmGetTranslationType
 Arguments       : void
 Return type     : Dem_DTCTranslationFormatType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the supported DTC formats of the ECU.
 The supported formats are configured via DemTypeOfDTCSupported.
 **************************************************************************/
EXTERN Dem_DTCTranslationFormatType Dem_DcmGetTranslationType(void);

/**************************************************************************
 Function name   : Dem_DcmGetDTCStatusAvailabilityMask
 Arguments       : Dem_UdsStatusByteType* DTCStatusMask
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the DTC Status availability mask.
 **************************************************************************/
EXTERN Std_ReturnType Dem_DcmGetDTCStatusAvailabilityMask(
    Dem_UdsStatusByteType* DTCStatusMask);

/**************************************************************************
 Function name   : Dem_DcmGetStatusOfDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8* DTCStatus
 Return type     : Dem_ReturnGetStatusOfDTCType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the status of a DTC.
 For large configurations and DTC-calibration, the interface
 behavior can be asynchronous
 **************************************************************************/
EXTERN Dem_ReturnGetStatusOfDTCType Dem_DcmGetStatusOfDTC(uint32 DTC,
    Dem_DTCOriginType DTCOrigin, uint8* DTCStatus);

/**************************************************************************
 Function name   : Dem_DcmGetSeverityOfDTC
 Arguments       : uint32 DTC, Dem_DTCSeverityType* DTCSeverity
 Return type     : Dem_ReturnGetSeverityOfDTCType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the severity of the requested DTC.
 For large configurations and DTC-calibration, the interface
 behavior can be asynchronous.
 **************************************************************************/
EXTERN Dem_ReturnGetSeverityOfDTCType Dem_DcmGetSeverityOfDTC(uint32 DTC,
    Dem_DTCSeverityType* DTCSeverity);

/**************************************************************************
 Function name   : Dem_DcmGetFunctionalUnitOfDTC
 Arguments       : uint32 DTC, uint8* DTCFunctionalUnit
 Return type     : Dem_ReturnGetFunctionalUnitOfDTCType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the functional unit of the requested DTC.
 **************************************************************************/
EXTERN Dem_ReturnGetFunctionalUnitOfDTCType Dem_DcmGetFunctionalUnitOfDTC(uint32 DTC,
    uint8* DTCFunctionalUnit);

/**************************************************************************
 Function name   : Dem_DcmSetDTCFilter
 Arguments       : Dem_UdsStatusByteType DTCStatusMask, Dem_DTCKindType DTCKind,
 Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin,
 boolean FilterWithSeverity,
 Dem_DTCSeverityType DTCSeverityMask,
 boolean FilterForFaultDetectionCounter
 Return type     : Dem_ReturnSetFilterType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Sets the DTC Filter.
 The server shall perform a bit-wise logical AND-ing operation
 between the parameter DTCStatusMask and the current DTC status in the
 server. In addition to the DTCStatusAvailabilityMask, the server
 shall return all DTCs for which the result of the AND-ing
 operation is non-zero [i.e. (statusOfDTC & DTCStatusMask)
 != 0]. The server shall process only the DTC Status bits that
 it is supporting.
 OBD Events Suppression shall be ignored for this computation.
 If no DTCs within the server match the masking criteria
 specified in the client?s request, no DTC or status
 information shall be provided following the DTCStatusAvailabilityMask
 byte in the positive response message
 (((statusOfDTC & DTCStatusMask) != 0) && ((severity
 & DTCSeverityMask) != 0)) == TRUE
 **************************************************************************/
EXTERN Dem_ReturnSetFilterType Dem_DcmSetDTCFilter(Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCKindType DTCKind, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity, Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter);

/**************************************************************************
 Function name   : Dem_DcmGetNumberOfFilteredDTC
 Arguments       : uint16* NumberOfFilteredDTC
 Return type     : Dem_ReturnGetNumberOfFilteredDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the number of a filtered DTC.
 **************************************************************************/
EXTERN Dem_ReturnGetNumberOfFilteredDTCType
Dem_DcmGetNumberOfFilteredDTC(uint16* NumberOfFilteredDTC);

/**************************************************************************
 Function name   : Dem_DcmGetNextFilteredDTC
 Arguments       : uint32* DTC, Dem_UdsStatusByteType* DTCStatus
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC matching the filter criteria. For
 UDS services, the interface has an asynchronous behavior,
 because a large number of DTCs has to be processed.
 **************************************************************************/
EXTERN Dem_ReturnGetNextFilteredElementType
Dem_DcmGetNextFilteredDTC(uint32* DTC, Dem_UdsStatusByteType* DTCStatus);

/**************************************************************************
 Function name   : Dem_DcmGetNextFilteredDTCAndFDC
 Arguments       : uint32* DTC, sint8* DTCFaultDetectionCounter
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC and its associated Fault Detection
 Counter (FDC) matching the filter criteria. The interface
 has an asynchronous behavior, because a large number of
 DTCs has to be processed and the FDC might be received
 asynchronously from a SW-C, too.
 **************************************************************************/
EXTERN Dem_ReturnGetNextFilteredElementType
Dem_DcmGetNextFilteredDTCAndFDC(uint32* DTC, sint8* DTCFaultDetectionCounter);

/**************************************************************************
 Function name   : Dem_DcmGetNextFilteredDTCAndSeverity
 Arguments       : uint32* DTC, Dem_UdsStatusByteType* DTCStatus,
 Dem_DTCSeverityType* DTCSeverity, uint8* DTCFunctionalUnit
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC and its associated Severity
 matching the filter criteria. The interface has an asynchronous
 behavior, because a large number of DTCs has to be processed.
 **************************************************************************/
EXTERN Dem_ReturnGetNextFilteredElementType
Dem_DcmGetNextFilteredDTCAndSeverity(uint32* DTC, Dem_UdsStatusByteType* DTCStatus,
    Dem_DTCSeverityType* DTCSeverity, uint8* DTCFunctionalUnit);

/**************************************************************************
 Function name   : Dem_DcmSetFreezeFrameRecordFilter
 Arguments       : Dem_DTCFormatType DTCFormat, uint16* NumberOfFilteredRecords
 Return type     : Dem_ReturnSetFilterType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Sets a freeze frame record filter.
 **************************************************************************/
EXTERN Dem_ReturnSetFilterType Dem_DcmSetFreezeFrameRecordFilter(
    Dem_DTCFormatType DTCFormat, uint16* NumberOfFilteredRecords);

/**************************************************************************
 Function name   : Dem_DcmGetNextFilteredRecord
 Arguments       : uint32* DTC, uint8* RecordNumber
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next freeze frame record number and its associated
 DTC stored in the event memory. The interface has an
 asynchronous behavior, because NvRAM access might be
 required.
 **************************************************************************/
EXTERN Dem_ReturnGetNextFilteredElementType Dem_DcmGetNextFilteredRecord(uint32* DTC,
    uint8* RecordNumber);

/**************************************************************************
 Function name   : Dem_DcmGetDTCByOccurrenceTime
 Arguments       : Dem_DTCRequestType DTCRequest, uint32* DTC
 Return type     : Dem_ReturnGetDTCByOccurrenceTimeType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the DTC by occurrence time. There is no explicit
 parameter for the DTC-origin as the origin always is
 DEM_DTC_ORIGIN_PRIMARY_MEMORY.
 **************************************************************************/
EXTERN Dem_ReturnGetDTCByOccurrenceTimeType Dem_DcmGetDTCByOccurrenceTime(
    Dem_DTCRequestType DTCRequest, uint32* DTC);

/**************************************************************************
 Function name   : Dem_DcmControlDTCStatusChangedNotification
 Arguments       : boolean TriggerNotification
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Controls the triggering of Dcm_DemTriggerOnDTCStatus.
 **************************************************************************/
EXTERN void
Dem_DcmControlDTCStatusChangedNotification(boolean TriggerNotification);

/**************************************************************************
 Function name   : Dem_DcmDisableDTCRecordUpdate
 Arguments       : uint32 DTC,
 Dem_DTCOriginType DTCOrigin
 Return type     : Dem_ReturnDisableDTCRecordUpdateType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Disables the event memory update of a specific DTC.
 **************************************************************************/
EXTERN Dem_ReturnDisableDTCRecordUpdateType
Dem_DcmDisableDTCRecordUpdate(uint32 DTC, Dem_DTCOriginType DTCOrigin);

/**************************************************************************
 Function name   : Dem_DcmEnableDTCRecordUpdate
 Arguments       : void
 Return type     : Dem_ReturnDisableDTCRecordUpdateType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Enables the event memory update of the DTC disabled by
 Dem_DcmDisableDTCRecordUpdate() before.
 **************************************************************************/
EXTERN Dem_ReturnDisableDTCRecordUpdateType
Dem_DcmEnableDTCRecordUpdate(void);

/**************************************************************************
 Function name   : Dem_DcmGetFreezeFrameDataByDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 RecordNumber,
 uint8* DestBuffer, uint16* BufSize
 Return type     : Dem_ReturnGetFreezeFrameDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets freeze frame data by DTC. The function stores the data
 in the provided DestBuffer.
 **************************************************************************/
EXTERN Dem_ReturnGetFreezeFrameDataByDTCType Dem_DcmGetFreezeFrameDataByDTC(uint32 DTC,
    Dem_DTCOriginType DTCOrigin, uint8 RecordNumber, uint8* DestBuffer, uint16* BufSize);

/**************************************************************************
 Function name   : Dem_DcmGetSizeOfFreezeFrameByDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin,
 uint8 RecordNumber, uint16* SizeOfFreezeFrame
 Return type     : Dem_ReturnGetSizeOfDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the size of freeze frame data by DTC.
 **************************************************************************/
EXTERN Dem_ReturnGetSizeOfDataByDTCType Dem_DcmGetSizeOfFreezeFrameByDTC(uint32 DTC,
    Dem_DTCOriginType DTCOrigin, uint8 RecordNumber, uint16* SizeOfFreezeFrame);

/**************************************************************************
 Function name   : Dem_DcmGetExtendedDataRecordByDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin,
 uint8 ExtendedDataNumber, uint8* DestBuffer, uint16* BufSize
 Return type     : Dem_ReturnGetExtendedDataRecordByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :  Gets extended data by DTC. The function stores the data in
 the provided DestBuffer.
 **************************************************************************/
EXTERN Dem_ReturnGetExtendedDataRecordByDTCType
Dem_DcmGetExtendedDataRecordByDTC(uint32 DTC, Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber, uint8* DestBuffer, uint16* BufSize);

/**************************************************************************
 Function name   : Dem_DcmGetSizeOfExtendedDataRecordByDTC
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin,
 uint8 ExtendedDataNumber, uint16* SizeOfExtendedDataRecord
 Return type     : Dem_ReturnGetSizeOfDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the size of extended data by DTC.
 **************************************************************************/
EXTERN Dem_ReturnGetSizeOfDataByDTCType
Dem_DcmGetSizeOfExtendedDataRecordByDTC(uint32 DTC, Dem_DTCOriginType DTCOrigin,
    uint8 ExtendedDataNumber, uint16* SizeOfExtendedDataRecord);

/**************************************************************************
 Function name   : Dem_ClearDTC
 Arguments       : uint32 DTC, Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin
 Return type     : Dem_ReturnClearDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     : Clears single DTCs, as well as groups of DTCs. This
 API is intended for complex device driver. It can only be
 used through the RTE (due to work-around described below
 SWS_Dem_00659), and therefore no declaration is exported
 via Dem.h.
 **************************************************************************/
EXTERN Dem_ReturnClearDTCType Dem_DcmClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin);

/**************************************************************************
 Function name   : Dem_DcmDisableDTCSetting
 Arguments       : uint32 DTCGroup, Dem_DTCKindType DTCKind

 Return type     : Dem_ReturnControlDTCSettingType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Disables the DTC setting for a DTC group.
 **************************************************************************/
EXTERN Dem_ReturnControlDTCSettingType Dem_DcmDisableDTCSetting(uint32 DTCGroup,
    Dem_DTCKindType DTCKind);

/**************************************************************************
 Function name   : Dem_DcmEnableDTCSetting
 Arguments       : uint32 DTCGroup, Dem_DTCKindType DTCKind

 Return type     : Dem_ReturnControlDTCSettingType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Enables the DTC setting for a DTC group.
 This API is intended for the Dcm. It can only be used
 through the RTE (due to work-around described below
 SWS_Dem_00035), and therefore no declaration is exported
 via Dem_Dcm.h..
 **************************************************************************/
EXTERN Dem_ReturnControlDTCSettingType Dem_DcmEnableDTCSetting(uint32 DTCGroup,
    Dem_DTCKindType DTCKind);

/*** OBD-specific Dcm <=> Dem Interfaces *** Not Supported ***/
/*** Interface J1939Dcm <=> Dem *** Not Supported ***/
/*** OBD-specific Interfaces *** Not Supported ***/
/*** Interface Dlt <=> Dem *** Not Supported ***/

#undef EXTERN

#endif
/*****************************************************************************
 *     End of File
 *
 *******************************************************************************/
/****************************************************************************
 *   for each change to this file, be sure to record:                        *
 *      1.  who made the change and when the change was made                 *
 *      2.  why the change was made and the intended result                  *
 *   Following block needs to be repeated for each change                    *
 *****************************************************************************/
/**-------------------------------------------------------------------------*/
/*Date              : 07-Mar-2017                                            */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      :                                                       */
/*Change Description: Data design And Framework , Initial Version */
/*--------------------------------------------------------------------------*/

