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

/* AUTOSAR Software specification version information */
# define DEM_AR_RELEASE_MAJOR_VERSION           (4u)
# define DEM_AR_RELEASE_MINOR_VERSION           (2u)
# define DEM_AR_RELEASE_REVISION_VERSION        (2u)

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

#define DEM_MODULE_ID                            (54U)
#define DEM_MAINFUNCTION_APIID                   (0x55U)              /*< Service ID: Dem_MainFunction() */
#define DEM_SETOPERATIONCYCLESTATE_APIID         (0x08U)
#define DEM_INIT_APIID                           (0x02U)
#define DEM_E_UNINIT                             (0x20U)
#define DEM_E_WRONG_CONDITION                    (0x40U)

/***  DEM DET Error Code  ***/
#define DEM_DET_NO_ERROR            0U
#define DEM_DET_WRONG_CONDITION     1U
#define DEM_DET_UNINITIALIZED       2U
#define DEM_DET_INVALID_PARAMETER   3U
#define DEM_WRONG_DTC       4U
#define DEM_WRONG_DTCORIGIN       5U

#define DEM_DTC_GROUP_ALL_DTCS      0x00FFFFFFU
#define DEM_NVM_MAGIC_VALUE         0x3F

/* Det and port interfaces Error Code */
#define DEM_E_NO_ERROR                           (0x00U)
#define DEM_E_NO_DTC_AVAILABLE                   (0x02U)
#define DEM_E_NO_FDC_AVAILABLE                   (0x03U)
#define DEM_E_PARAM_CONFIG                       (0x10U)
#define DEM_E_PARAM_POINTER                      (0x11U)
#define DEM_E_PARAM_DATA                         (0x12U)
#define DEM_E_PARAM_LENGTH                       (0x13U)
#define DEM_E_UNINIT                             (0x20U)
#define DEM_E_NODATAAVAILABLE                    (0x30U)
#define DEM_E_WRONG_RECORDNUMBER                 (0x31U)
#define DEM_E_WRONG_DIDNUMBER                    (0x32U)
#define DEM_E_WRONG_CONDITION                    (0x40U)
#define DEM_E_INCONSISTENT_STATE                 (0xf0U)
#define DEM_UINT_8_MAX                           (0xFFU)

#define DEM_DCM_CLIENT             0u
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
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Returns the version information of this module..
 **************************************************************************/
extern void Dem_GetVersionInfo(Std_VersionInfoType* versioninfo);

/* ECU State Manager <=> Dem */

/**************************************************************************
 Function name   : Dem_PreInit
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Initializes the internal states necessary to process
 events reported by BSW-modules.
 **************************************************************************/
extern void Dem_PreInit(void);

/**************************************************************************
 Function name   :  Dem_Init
 Arguments       :  const Dem_ConfigType* ConfigPtr
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :  Non Reentrant
 Description     :  Initializes or reinitializes this module.
 **************************************************************************/
extern void Dem_Init(const Dem_ConfigType* ConfigPtr);

/**************************************************************************
 Function name   : Dem_Shutdown
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Shuts down this module.
 **************************************************************************/
extern void Dem_Shutdown(void);

/**************************************************************************
 Function name   : Dem_MainFunction
 Arguments       : void
 Return type     : void
 Sync/Async		:
 Reentrancy		:
 Description     : Processes all not event based Dem internal functions..
 **************************************************************************/
extern void Dem_MainFunction(void);

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
extern void Dem_ReportErrorStatus(Dem_EventIdType EventId,
                                  Dem_EventStatusType EventStatus);

/**************************************************************************
 Function name   : Dem_SetEventAvailable
 Arguments       : Dem_EventIdType EventId, boolean AvailableStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant.
 Description     : Set the available status of a specific Event.
 **************************************************************************/
extern Std_ReturnType Dem_SetEventAvailable(Dem_EventIdType EventId,
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
extern Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId,
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
extern Std_ReturnType Dem_ResetEventDebounceStatus(Dem_EventIdType EventId,
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
extern Std_ReturnType Dem_ResetEventStatus(Dem_EventIdType EventId);

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
extern Std_ReturnType Dem_PrestoreFreezeFrame(Dem_EventIdType EventId);

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
extern Std_ReturnType Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId);

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
extern Std_ReturnType Dem_SetOperationCycleState(uint8 OperationCycleId,
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
extern Std_ReturnType Dem_GetOperationCycleState(uint8 OperationCycleId,
    Dem_OperationCycleStateType* CycleState);

#if(DEM_PROCESS_AGING_CTR_EXTERN == TRUE)
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
extern Std_ReturnType Dem_SetAgingCycleState(uint8 OperationCycleId);

#else

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
extern Std_ReturnType Dem_SetWIRStatus(Dem_EventIdType EventId, boolean WIRStatus);

#endif

/**************************************************************************
 Function name   : Dem_GetComponentFailed
 Arguments       : Dem_ComponentIdType ComponentId, boolean* ComponentFailed
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant.
 Description     : Gets the failed status of a DemComponent.
 **************************************************************************/
extern Std_ReturnType Dem_GetComponentFailed(Dem_ComponentIdType ComponentId,
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
extern Std_ReturnType Dem_GetEventStatus(Dem_EventIdType EventId,
    Dem_UdsStatusByteType* EventStatusByte);

/**************************************************************************
 Function name   : Dem_GetEventFailed
 Arguments       : Dem_EventIdType EventId, boolean* EventFailed
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event failed status of an event.
 **************************************************************************/
extern Std_ReturnType Dem_GetEventFailed(Dem_EventIdType EventId, boolean* EventFailed);

/**************************************************************************
 Function name   : Dem_GetEventTested
 Arguments       : Dem_EventIdType EventId, boolean* EventTested
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event tested status of an event.
 **************************************************************************/
extern Std_ReturnType Dem_GetEventTested(Dem_EventIdType EventId, boolean* EventTested);

/**************************************************************************
 Function name   : Dem_GetDebouncingOfEvent
 Arguments       : Dem_EventIdType EventId,
 Dem_DebouncingStateType* DebouncingState
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event tested status of an event.
 **************************************************************************/
extern Std_ReturnType Dem_GetDebouncingOfEvent(Dem_EventIdType EventId,
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
extern Std_ReturnType Dem_GetDTCOfEvent(Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat, uint32* DTCOfEvent);

/**************************************************************************
 Function name   : Dem_SetEnableCondition
 Arguments       : uint8 EnableConditionID, boolean ConditionFulfilled
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     : Std_ReturnType
 **************************************************************************/
extern Std_ReturnType Dem_SetEnableCondition(uint8 EnableConditionID,
    boolean ConditionFulfilled);

/**************************************************************************
 Function name   : Dem_SetStorageCondition
 Arguments       : uint8 StorageConditionID, boolean ConditionFulfilled
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Sets a storage condition.
 **************************************************************************/
extern Std_ReturnType Dem_SetStorageCondition(uint8 StorageConditionID,
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
extern Std_ReturnType Dem_GetFaultDetectionCounter(Dem_EventIdType EventId,
    sint8* FaultDetectionCounter);

/**************************************************************************
 Function name   : Dem_GetIndicatorStatus
 Arguments       : uint8 IndicatorId, Dem_IndicatorStatusType* IndicatorStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the indicator status derived from the event status.
 **************************************************************************/
extern Std_ReturnType Dem_GetIndicatorStatus(uint8 IndicatorId,
    Dem_IndicatorStatusType* IndicatorStatus);

/**************************************************************************
 Function name   : Dem_GetEventFreezeFrameDataEx
 Arguments       : Dem_EventIdType EventId, uint8 RecordNumber,
                   uint16 DataId, uint8* DestBuffer, uint16* BufSize
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the data of a freeze frame by event.
 **************************************************************************/
extern Std_ReturnType Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, 
                                                    uint8 RecordNumber, 
                                                    uint16 DataId, 
                                                    uint8* DestBuffer, 
                                                    uint16* BufSize);

#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
/**************************************************************************
 Function name   : Dem_GetEventExtendedDataRecordEx
 Arguments       : Dem_EventIdType EventId, uint8 RecordNumber, uint8* DestBuffer,
                   uint16* BufSize
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the data of an extended data record by event.
 **************************************************************************/
extern Std_ReturnType Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId,
                                                       uint8 RecordNumber,
                                                       uint8* DestBuffer,
                                                       uint16* BufSize);
#endif

/**************************************************************************
 Function name   : Dem_GetEventMemoryOverflow
 Arguments       : Dem_DTCOriginType DTCOrigin, boolean* OverflowIndication
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event memory overflow indication status.
 **************************************************************************/
extern Std_ReturnType Dem_GetEventMemoryOverflow(uint8 ClientId, Dem_DTCOriginType DTCOrigin, boolean* OverflowIndication);

/**************************************************************************
 Function name   : Dem_GetNumberOfEventMemoryEntries
 Arguments       : Dem_DTCOriginType DTCOrigin, uint8* NumberOfEventMemoryEntries
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Returns the number of entries currently stored in the
 requested event memory.
 **************************************************************************/
extern Std_ReturnType Dem_GetNumberOfEventMemoryEntries(uint8 ClientId, Dem_DTCOriginType DTCOrigin, uint8* NumberOfEventMemoryEntries);

/**************************************************************************
 Function name   : Dem_SetComponentAvailable
 Arguments       : Dem_ComponentIdType ComponentId, boolean AvailableStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Set the availability of a specific DemComponent.
 **************************************************************************/
extern Std_ReturnType Dem_SetComponentAvailable(Dem_ComponentIdType ComponentId,
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
extern Std_ReturnType Dem_SetDTCSuppression(uint8 ClientId,boolean SuppressionStatus);

/**************************************************************************
 Function name   : Dem_DcmGetTranslationType
 Arguments       : ClientId
 Return type     : Dem_DTCTranslationFormatType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the supported DTC formats of the ECU.
 The supported formats are configured via DemTypeOfDTCSupported.
 **************************************************************************/
extern Dem_DTCTranslationFormatType Dem_GetTranslationType(uint8 ClientId);

/**************************************************************************
 Function name   : Dem_GetDTCStatusAvailabilityMask
 Arguments       : uint8 ClientId, Dem_UdsStatusByteType* DTCStatusMask
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the DTC Status availability mask.
 **************************************************************************/
extern Std_ReturnType Dem_GetDTCStatusAvailabilityMask(uint8 ClientId, Dem_UdsStatusByteType* DTCStatusMask);
/**************************************************************************
 Function name   : Dem_GetStatusOfDTC
 Arguments       : uint8 ClientId, uint8* DTCStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the status of a DTC.
 For large configurations and DTC-calibration, the interface
 behavior can be asynchronous
 **************************************************************************/
extern Std_ReturnType Dem_GetStatusOfDTC(uint8 ClientId, uint8* DTCStatus);

#if (SeveritySuppotEnabled == STD_ON)
/**************************************************************************
 Function name   : Dem_GetSeverityOfDTC
 Arguments       : uint8 ClientId, Dem_DTCSeverityType* DTCSeverity
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the severity of the requested DTC.
 For large configurations and DTC-calibration, the interface
 behavior can be asynchronous.
 **************************************************************************/
extern Std_ReturnType Dem_GetSeverityOfDTC(uint8 ClientId, Dem_DTCSeverityType* DTCSeverity);
#endif

#if (SeveritySuppotEnabled == STD_ON)
/**************************************************************************
 Function name   : Dem_GetFunctionalUnitOfDTC
 Arguments       : uint8 ClientId, uint8* DTCFunctionalUnit
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the functional unit of the requested DTC.
 **************************************************************************/
extern Std_ReturnType Dem_GetFunctionalUnitOfDTC(uint8 ClientId, uint8* DTCFunctionalUnit);
#endif

/**************************************************************************
 Function name   : Dem_SetDTCFilter
 Arguments       : uint8 ClientId, uint8 DTCStatusMask, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin, boolean FilterWithSeverity,
  Dem_DTCSeverityType DTCSeverityMask, boolean FilterForFaultDetectionCounter
 Return type     : Std_ReturnType
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
extern Std_ReturnType Dem_SetDTCFilter(uint8 ClientId, uint8 DTCStatusMask, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin, boolean FilterWithSeverity, Dem_DTCSeverityType DTCSeverityMask, boolean FilterForFaultDetectionCounter);

/**************************************************************************
 Function name   : Dem_DcmGetNumberOfFilteredDTC
 Arguments       : uint8 ClientId, uint16* NumberOfFilteredDTC
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the number of a filtered DTC.
 **************************************************************************/
extern Std_ReturnType Dem_GetNumberOfFilteredDTC(uint8 ClientId, uint16* NumberOfFilteredDTC);

/**************************************************************************
 Function name   : Dem_GetNextFilteredDTC
 Arguments       : uint8 ClientId, uint32* DTC, uint8* DTCStatus
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Synchronous or Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC matching the filter criteria. For
 UDS services, the interface has an asynchronous behavior,
 because a large number of DTCs has to be processed.
 **************************************************************************/
extern Std_ReturnType Dem_GetNextFilteredDTC(uint8 ClientId, uint32* DTC, uint8* DTCStatus);

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
extern Dem_ReturnGetNextFilteredElementType
Dem_DcmGetNextFilteredDTC(uint32* DTC, Dem_UdsStatusByteType* DTCStatus);

/**************************************************************************
 Function name   : Dem_GetNextFilteredDTCAndFDC
 Arguments       : uint8 ClientId, uint32* DTC, sint8* DTCFaultDetectionCounter
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC and its associated Fault Detection
 Counter (FDC) matching the filter criteria. The interface
 has an asynchronous behavior, because a large number of
 DTCs has to be processed and the FDC might be received
 asynchronously from a SW-C, too.
 **************************************************************************/
extern Std_ReturnType Dem_GetNextFilteredDTCAndFDC(uint8 ClientId, uint32* DTC, sint8* DTCFaultDetectionCounter);

/**************************************************************************
 Function name   : Dem_GetNextFilteredDTCAndSeverity
 Arguments       : uint8 ClientId, uint32* DTC, uint8* DTCStatus, Dem_DTCSeverityType* DTCSeverity, uint8* DTCFunctionalUnit
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next filtered DTC and its associated Severity
 matching the filter criteria. The interface has an asynchronous
 behavior, because a large number of DTCs has to be processed.
 **************************************************************************/
extern Std_ReturnType Dem_GetNextFilteredDTCAndSeverity(uint8 ClientId, uint32* DTC, uint8* DTCStatus, Dem_DTCSeverityType* DTCSeverity, uint8* DTCFunctionalUnit);

/**************************************************************************
 Function name   : Dem_SetFreezeFrameRecordFilter
 Arguments       : uint8 ClientId,Dem_DTCFormatType DTCFormat,uint16* NumberOfFilteredRecords
 Return type     : Dem_ReturnSetFilterType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Sets a freeze frame record filter.
 **************************************************************************/
extern Std_ReturnType Dem_SetFreezeFrameRecordFilter(uint8 ClientId,Dem_DTCFormatType DTCFormat,uint16* NumberOfFilteredRecords);

/**************************************************************************
 Function name   : Dem_GetNextFilteredRecord
 Arguments       : uint8 ClientId, uint32* DTC, uint8* RecordNumber
 Return type     : Dem_ReturnGetNextFilteredElementType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the next freeze frame record number and its associated
 DTC stored in the event memory. The interface has an
 asynchronous behavior, because NvRAM access might be
 required.
 **************************************************************************/
extern Std_ReturnType Dem_GetNextFilteredRecord(uint8 ClientId, uint32* DTC, uint8* RecordNumber);

/**************************************************************************
 Function name   : Dem_GetDTCByOccurrenceTime
 Arguments       : uint8 ClientId, Dem_DTCRequestType DTCRequest, uint32* DTC
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the DTC by occurrence time. There is no explicit
 parameter for the DTC-origin as the origin always is
 DEM_DTC_ORIGIN_PRIMARY_MEMORY.
 **************************************************************************/
extern Std_ReturnType Dem_GetDTCByOccurrenceTime(uint8 ClientId, Dem_DTCRequestType DTCRequest, uint32* DTC);

/**************************************************************************
 Function name   : Dem_DcmControlDTCStatusChangedNotification
 Arguments       : boolean TriggerNotification
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Controls the triggering of Dcm_DemTriggerOnDTCStatus.
 **************************************************************************/
extern void
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
extern Dem_ReturnDisableDTCRecordUpdateType
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
extern Dem_ReturnDisableDTCRecordUpdateType
Dem_DcmEnableDTCRecordUpdate(void);

#if (DemMaxNumberFreezeFrameRecords > 0)
/**************************************************************************
 Function name   : Dem_SelectFreezeFrameData
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 RecordNumber,
 uint8* DestBuffer, uint16* BufSize
 Return type     : Dem_ReturnGetFreezeFrameDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets freeze frame data by DTC. The function stores the data
 in the provided DestBuffer.
 **************************************************************************/
extern Std_ReturnType Dem_SelectFreezeFrameData(uint8 ClientId, uint8 RecordNumber);
/**************************************************************************
 Function name   : Dem_GetNextFreezeFrameData
 Arguments       : uint8 ClientId, uint8* DestBuffer, uint16* BufSize
 Return type     : Dem_ReturnGetFreezeFrameDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets freeze frame data by DTC. The function stores the data
 in the provided DestBuffer.
 **************************************************************************/
extern Std_ReturnType Dem_GetNextFreezeFrameData(uint8 ClientId, uint8* DestBuffer, uint16* BufSize);

/**************************************************************************
 Function name   : Dem_GetSizeOfFreezeFrameByDTC
 Arguments       : uint8 ClientId, uint16* SizeOfFreezeFrame
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the size of freeze frame data by DTC.
 **************************************************************************/
extern Std_ReturnType Dem_GetSizeOfFreezeFrameSelection(uint8 ClientId,
                                    uint16* SizeOfFreezeFrame);
#endif
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
/**************************************************************************
 Function name   : Dem_SelectFreezeFrameData
 Arguments       : uint32 DTC, Dem_DTCOriginType DTCOrigin, uint8 RecordNumber,
 uint8* DestBuffer, uint16* BufSize
 Return type     : Dem_ReturnGetFreezeFrameDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets freeze frame data by DTC. The function stores the data
 in the provided DestBuffer.
 **************************************************************************/
extern Std_ReturnType Dem_SelectExtendedDataRecord(uint8 ClientId, uint8 RecordNumber);
/**************************************************************************
 Function name   : Dem_DcmGetExtendedDataRecordByDTC
 Arguments       : uint8 ClientId, uint8* DestBuffer, uint16* BufSize
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :  Gets extended data by DTC. The function stores the data in
 the provided DestBuffer.
 **************************************************************************/
extern Std_ReturnType Dem_GetNextExtendedDataRecord(uint8 ClientId, uint8* DestBuffer, uint16* BufSize);

/**************************************************************************
 Function name   : Dem_GetSizeOfExtendedDataRecordSelection
 Arguments       : uint8 ClientId, uint16* SizeOfExtendedDataRecord
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the size of extended data by DTC.
 **************************************************************************/
extern Std_ReturnType Dem_GetSizeOfExtendedDataRecordSelection(uint8 ClientId, uint16* SizeOfExtendedDataRecord);
#endif //#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
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
extern Std_ReturnType Dem_ClearDTC(uint8 ClientId);

/**************************************************************************
 Function name   : Dem_DisableDTCSetting
 Arguments       : uint8 ClinetId

 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Disables the DTC setting for a DTC group.
 **************************************************************************/
extern Std_ReturnType Dem_DisableDTCSetting(uint8 ClinetId);

/**************************************************************************
 Function name   : Dem_EnableDTCSetting
 Arguments       : uint8 ClientId

 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Enables the DTC setting for a DTC group.
 This API is intended for the Dcm. It can only be used
 through the RTE (due to work-around described below
 SWS_Dem_00035), and therefore no declaration is exported
 via Dem_Dcm.h.
 **************************************************************************/
extern Std_ReturnType Dem_EnableDTCSetting(uint8 ClientId);

/**************************************************************************
 Function name   : Dem_SelectDTC
 Arguments       : uint8 ClientId, uint32 DTC, Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : 
 **************************************************************************/
extern Std_ReturnType Dem_SelectDTC(uint8 ClientId, uint32 DTC, Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin);
 
/**************************************************************************
 Function name   : Dem_GetDTCSelectionResult
 Arguments       : uint8 ClientId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : 
 **************************************************************************/
extern Std_ReturnType Dem_GetDTCSelectionResult(uint8 ClientId);



/*** OBD-specific Dcm <=> Dem Interfaces *** Not Supported ***/
/*** Interface J1939Dcm <=> Dem *** Not Supported ***/
/*** OBD-specific Interfaces *** Not Supported ***/
/*** Interface Dlt <=> Dem *** Not Supported ***/

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
/**-------------------------------------------------------------------------*/
/*Date              : 29-Aug-2020                                           */
/*Version           :                                                       */
/*By                : bbaskara                                              */
/*Traceability      : Rtc#1029668                                           */
/*Change Description: 0x19 0x06 service design changes                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-Feb-2021                                           */
/*Version           :                                                       */
/*By                : pmanoj2                                               */
/*Traceability      : 1177550: 1152813: [hondabev]cert-c - turing.bsw.errmgr*/
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 18-Jan-2022                                           */
/*Version           :                                                       */
/*By                : iiliev1                                               */
/*Traceability      : Rtc#1560389                                           */
/*Change Description: DCM and DEM Autosar 4.2.2 Migration                   */
/*--------------------------------------------------------------------------*/
