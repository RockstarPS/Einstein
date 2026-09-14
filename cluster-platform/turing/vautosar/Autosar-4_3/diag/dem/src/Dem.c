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
 *  File Name         :  Dem.c                                                *
 *  Module Short Name :  ErrMgr                                               *
 *  VOBName           :                                                       *
 *  Author            : msavariy                                              *
 *  Description       : This file contains the Diagnostics request and        *
 *                       response handling functionalities.                   *
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
#ifndef DEM_C
#define DEM_C

/*****************************************************************************
 *                            Include files                                   *
 ******************************************************************************/
#include "Dem.h"
#include "Dem_Cbk.h"
#include "Dem_Dcm.h"
#include "NvM.h"
#include "Dcm_Internal.h"

/* Schedule Manager, for critical sections */
#include "SchM_Dem.h"

/* Development error tracer, for Det_ReportError */
# include "Det.h"

/*****************************************************************************
 *                                 Macro Definitions                          *
 *----------------------------------------------------------------------------*
 * Definition of macro shall be followed by a comment that explains the       *
 * purpose of the macro.                                                      *
 ******************************************************************************/


/*** utilities ***/

#define DEM_CALCULATE_SIZE(Value)         (((Value) + 7) /8)
#define DEM_CALCULATE_INDEX(Value)        ((Value) / 8)
#define DEM_CALCULATE_MASK_BIT(Value)     (uint8)(0x01 << ((uint8)((Value) % 8)))

#define DEM_GET_BIT_STATE(Value, Mask)    (uint8)(((Value) & (Mask)) != FALSE)
#define DEM_SET_BIT_STATE(Value, Mask)    (uint8)((Value) |= (Mask))
#define DEM_RESET_BIT_STATE(Value, Mask)  (uint8)((Value) &= ~(Mask))


/****  Dem Initialization States  ***/

#define DEM_UNINITIALIZED     0U
#define DEM_PREINITIALIZED    1U
#define DEM_INITIALIZED       2U
#define DEM_SHUTDOWN          3U
#define DEM_ONE                  0x01U
#define DEM_0xFF                 0xFFU
#define DEM_0xFFFF               0xFFFFU
#define DEM_TWO                  0x02U
/*** DTC  ***/
#define DEM_DTC_STORAGE_SETTING_ENABLED   1U
#define DEM_DTC_STORAGE_SETTING_DISABLED  0U

#define DEM_INITIAL          0U
#define DEM_DTC_SELECTED     1U

/*** Enable and Storage Condition ***/

#define DEM_EVENT_ENABLE_CONDITION_FAILED          0U
#define DEM_EVENT_ENABLE_CONDITION_FULFILLED       1U
#define DEM_EVENT_STORAGE_CONDITION_FAILED         0U
#define DEM_EVENT_STORAGE_CONDITION_FULFILLED      1U

#define DEM_EVENT_ENABLE_CONDITION_REQUESTED        0x01U
#define DEM_EVENT_STORAGE_CONDITION_REQUESTED       0x02U

/*** Invalid Status ***/

#define DEM_DTC_INVALID                         0x00FFFFFFu
#define DEM_DTC_AGING_INVALID                   0x00u
#define DEM_EVENT_INVALID                       0x00u
#define DEM_FAILED_COUNT_INVALID                0xFFu
#define DEM_EVENT_TMSTMP_INVALID                0x00u
#define DEM_EVENT_OCCNTR_INVALID                0x00u
#define DEM_EVENT_STATUS_INVALID                0x04u
#define DEM_DTC_FORMAT_INVALID                  0xFFu
#define DEM_DTC_ORIGIN_INVALID                  0x00u
#define DEM_DTC_KIND_INVALID                    0x03u
#define DEM_DTC_VALID_START                     0x01u
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
#define DEM_EXT_REC_DATA_INVALID                0x00u
#endif
#if (DemMaxNumberFreezeFrameRecords > 0)
#define DEM_FREEZE_FRAME_INVALID                0x00u
#endif
/*** DEM Clear DTC ***/
#define DEM_DCM_CLEAR_DTC_IDLE                  0x00u
#define DEM_DCM_CLEAR_DTC_REQUESTED             0x01u
#define DEM_DCM_CLEAR_DTC_REQUEST_COMPLETED     0x02u

#define DEM_DCM_CLEAR_DTC_QUEUE_PENDING         0x01u
#define DEM_DCM_CLEAR_DTC_QUEUE_FAILED          0x02u
#define DEM_DCM_CLEAR_DTC_QUEUE_DONE            0x03u
#define DEM_DCM_CLEAR_DTC_QUEUE_CANCEL          0x04u

/*** Event Internal Status  ***/

#define DEM_EVENT_VALID_ID_START                0x01u

#define DEM_EVENT_STATUS_BIT_POS                0x00u
#define DEM_EVENT_STATUS_BIT_MASK               0x03u

#define DEM_EVENT_STATUS_NONE                   0x00u
#define DEM_EVENT_STATUS_TRIGGERED              0x01u
#define DEM_EVENT_STATUS_STORED                 0x02u
#define DEM_EVENT_STATUS_AGING                  0x03u

#define DEM_EVENT_DEBOUNCE_STATUS_BIT_POS       0x02u
#define DEM_EVENT_DEBOUNCE_STATUS_BIT_MASK      0x0Fu

#define DEM_EVENT_DEBOUNCE_STATUS_RESET         0x00u
#define DEM_EVENT_DEBOUNCE_STATUS_NONE          0x00u
#define DEM_EVENT_DEBOUNCE_STATUS_PASSED        0x01u
#define DEM_EVENT_DEBOUNCE_STATUS_FAILED        0x02u
#define DEM_EVENT_DEBOUNCE_STATUS_HEALING       0x03u
#define DEM_EVENT_DEBOUNCE_STATUS_FAILING       0x04u
#define DEM_EVENT_DEBOUNCE_STATUS_HEAL_RESET    0x05u
#define DEM_EVENT_DEBOUNCE_STATUS_FAIL_RESET    0x06u
#define DEM_EVENT_DEBOUNCE_FREEZE_HEAL_STATUS   0x07u
#define DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL   0x08u

/*** Operation cycle status ***/
#define DEM_OPCYCLE_STATE_INVALID               0x02u

#define DEM_OPERATION_QUEUE_CYCLE_STOPED        0x01u
#define DEM_OPERATION_QUEUE_CYCLE_STARTED       0x02u
#define DEM_OPERATION_QUEUE_CYCLE_RESTARTED     0x03u

#define DEM_GET_OPERATION_CYCLE_STATUS(Status, CycleId)    (boolean)((uint16)((Status) & (uint16)(1 << (CycleId))) != 0)
#define DEM_SET_OPERATION_CYCLE_STATUS(Status, CycleId)    (uint16)((Status) |= (uint16)(1 << (CycleId)))
#define DEM_RESET_OPERATION_CYCLE_STATUS(Status, CycleId)  (uint16)((Status) &= (uint16)(~((uint16)(1 << (CycleId)))))

/***    UDS Status bit update   ***/

/***  TF  ***/
#define DEM_UDS_STATUS_MASK_TF            0x01u /* test failed */
#define DEM_UDS_STATUS_MASK_TFTMC         0x02u /* test failed this monitoring cycle */
#define DEM_UDS_STATUS_MASK_PDTC          0x04u /* pending DTC */
#define DEM_UDS_STATUS_MASK_CDTC          0x08u /* confirmed DTC */
#define DEM_UDS_STATUS_MASK_TNCSLC        0x10u /* test not completed since last clear */
#define DEM_UDS_STATUS_MASK_TFSLC         0x20u /* test failed since last clear */
#define DEM_UDS_STATUS_MASK_TNCTMC        0x40u /* test not completed this monitoring cycle */
#define DEM_UDS_STATUS_MASK_WIR           0x80u /* warning indicator requested */
#define DEM_UDS_STATUS_DEFAULT            0x50U

#define DEM_SET_UDS_STATUS_BYTE_TF(status)        (uint8)((status) |= (DEM_UDS_STATUS_MASK_TF))
#define DEM_SET_UDS_STATUS_BYTE_TFTMC(status)     (uint8)((status) |= (DEM_UDS_STATUS_MASK_TFTMC))
#define DEM_SET_UDS_STATUS_BYTE_PDTC(status)      (uint8)((status) |= (DEM_UDS_STATUS_MASK_PDTC))
#define DEM_SET_UDS_STATUS_BYTE_CDTC(status)      (uint8)((status) |= (DEM_UDS_STATUS_MASK_CDTC))
#define DEM_SET_UDS_STATUS_BYTE_TNCSLC(status)    (uint8)((status) |= (DEM_UDS_STATUS_MASK_TNCSLC))
#define DEM_SET_UDS_STATUS_BYTE_TFSLC(status)     (uint8)((status) |= (DEM_UDS_STATUS_MASK_TFSLC))
#define DEM_SET_UDS_STATUS_BYTE_TNCTMC(status)    (uint8)((status) |= (DEM_UDS_STATUS_MASK_TNCTMC))
#define DEM_SET_UDS_STATUS_BYTE_WIR(status)       (uint8)((status) |= (DEM_UDS_STATUS_MASK_WIR))

#define DEM_RESET_UDS_STATUS_BYTE_TF(status)      (uint8)((status) &= ~(DEM_UDS_STATUS_MASK_TF))
#define DEM_RESET_UDS_STATUS_BYTE_TFTMC(status)   (uint8)((status) &= ~(DEM_UDS_STATUS_MASK_TFTMC))
#define DEM_RESET_UDS_STATUS_BYTE_PDTC(status)    (uint8)((status) &= ~(DEM_UDS_STATUS_MASK_PDTC))
#define DEM_RESET_UDS_STATUS_BYTE_CDTC(status)    (uint8)((status) &= ~(DEM_UDS_STATUS_MASK_CDTC))
#define DEM_RESET_UDS_STATUS_BYTE_TNCSLC(status)  (uint8)((status) &= ~(DEM_UDS_STATUS_MASK_TNCSLC))
#define DEM_RESET_UDS_STATUS_BYTE_TFSLC(status)   (uint8)((status) &= ~(DEM_UDS_STATUS_MASK_TFSLC))
#define DEM_RESET_UDS_STATUS_BYTE_TNCTMC(status)  (uint8)((status) &= ~(DEM_UDS_STATUS_MASK_TNCTMC))
#define DEM_RESET_UDS_STATUS_BYTE_WIR(status)     (uint8)((status) &= ~(DEM_UDS_STATUS_MASK_WIR))

#define DEM_GET_UDS_STATUS_BYTE_TF(status)        (boolean)((uint8)((status) & (DEM_UDS_STATUS_MASK_TF)) != 0)
#define DEM_GET_UDS_STATUS_BYTE_TFTMC(status)     (boolean)((uint8)((status) & (DEM_UDS_STATUS_MASK_TFTMC)) != 0)
#define DEM_GET_UDS_STATUS_BYTE_CDTC(status)      (boolean)((uint8)((status) & (DEM_UDS_STATUS_MASK_CDTC)) != 0)
#define DEM_GET_UDS_STATUS_BYTE_TNCTMC(status)    (boolean)((uint8)((status) & (DEM_UDS_STATUS_MASK_TNCTMC)) != 0)

// To get the event tested status
#define DEM_GET_UDS_EVENT_TESTED_TNCTMC(status)    (boolean)((uint8)((status) & (DEM_UDS_STATUS_MASK_TNCTMC)) != DEM_UDS_STATUS_MASK_TNCTMC)

/***  DEM Event Queue Status  ***/
#define DEM_EVENT_QUEUE_PENDING         0x80u
#define DEM_EVENT_QUEUE_PASSED          0x01u
#define DEM_EVENT_QUEUE_FAILED          0x02u
#define DEM_EVENT_QUEUE_IS_PASSED       0x40u

#define DEM_EVENT_GET_QUEUE_STATUS_PENDING(Status)    (boolean)((uint8)((Status) & (DEM_EVENT_QUEUE_PENDING)) != 0)
#define DEM_EVENT_SET_QUEUE_STATUS_PENDING(Status)    (uint8)((Status) |= (DEM_EVENT_QUEUE_PENDING))
#define DEM_EVENT_RESET_QUEUE_STATUS_PENDING(Status)  (uint8)((Status) &= ~(DEM_EVENT_QUEUE_PENDING))

#define DEM_EVENT_GET_QUEUE_STATUS_FAILED(Status)     (boolean)((uint8)((Status) & (DEM_EVENT_QUEUE_FAILED)) != 0)
#define DEM_EVENT_SET_QUEUE_STATUS_FAILED(Status)     (uint8)((Status) |= (DEM_EVENT_QUEUE_FAILED))
#define DEM_EVENT_RESET_QUEUE_STATUS_FAILED(Status)   (uint8)((Status) &= ~(DEM_EVENT_QUEUE_FAILED))

#define DEM_EVENT_GET_QUEUE_STATUS_PASSED(Status)     (boolean)((uint8)((Status) & (DEM_EVENT_QUEUE_PASSED)) != 0)
#define DEM_EVENT_SET_QUEUE_STATUS_PASSED(Status)     (uint8)((Status) |= (DEM_EVENT_QUEUE_PASSED))
#define DEM_EVENT_RESET_QUEUE_STATUS_PASSED(Status)   (uint8)((Status) &= ~(DEM_EVENT_QUEUE_PASSED))

#define DEM_EVENT_GET_QUEUE_STATUS_ISPASSED(Status)   (boolean)((uint8)((Status) & (DEM_EVENT_QUEUE_IS_PASSED)) != 0)
#define DEM_EVENT_SET_QUEUE_STATUS_ISPASSED(Status)   (uint8)((Status) |= (DEM_EVENT_QUEUE_IS_PASSED))
#define DEM_EVENT_RESET_QUEUE_STATUS_ISPASSED(Status) (uint8)((Status) &= ~(DEM_EVENT_QUEUE_IS_PASSED))

/*** NVM Status ***/

#define DEM_NVM_IDLE           0x00U
#define DEM_NVM_WRITING        0x01U
#define DEM_NVM_FINISHED       0x02U
#define DEM_NVM_FAILED         0x03U
/* Mem Status */
#define DEM_MEM_IDLE           0x00U
#define DEM_MEM_DIRTY          0x01U

/***  Dem Internal Mem Status  ***/
#define DEM_MEM_STATUS_NONE                      0x00U
#define DEM_MEM_STATUS_TRIGGER_STORAGE           0x01U
#define DEM_MEM_STATUS_TRIGGER_CLEAR             0x02U


#define DEM_TRIGGER_ON_TEST_FAILED    0x00u
#define DEM_TRIGGER_ON_FDC_THRESHOLD  0x01u
#define DEM_TRIGGER_ON_PENDING        0x02u
#define DEM_TRIGGER_ON_CONFIRMED      0x03u
#define DEM_TRIGGER_ON_PASSED         0x04u
#define DEM_TRIGGER_ON_MIRROR         0x05u

#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT  0x00u
#define DEM_STATUS_BIT_NORMAL                  0x01u

#define DEM_FF_RECNUM_CALCULATED               0x00u
#define DEM_FF_RECNUM_CONFIGURED               0x01u


/*** Dem Dcm interface ***/
#define DEM_DCM_FILTER_USESTATUSMASK             0x01U
#define DEM_DCM_FILTER_USEFDC                    0x02U
#define DEM_DCM_FILTER_USESEVERITYSTATUSMASK     0x04U

#define DEM_DCM_FILTER_USEFREEZEFRAMERECORDMASK  0x01U

#define DEM_DCM_GET_USESTATUSMASK_FLAG(filter)               (boolean)((uint8)((filter) & (DEM_DCM_FILTER_USESTATUSMASK)) != 0)
#define DEM_DCM_SET_USESTATUSMASK_FLAG(filter)               (uint8)((filter) |= (DEM_DCM_FILTER_USESTATUSMASK))
#define DEM_DCM_RESET_USESTATUSMASK_FLAG(filter)             (uint8)((filter) &= ~(DEM_DCM_FILTER_USESTATUSMASK))

#define DEM_DCM_GET_USESEVERITYSTATUSMASK_FLAG(filter)       (boolean)((uint8)((filter) & (DEM_DCM_FILTER_USESEVERITYSTATUSMASK)) != 0)
#define DEM_DCM_SET_USESEVERITYSTATUSMASK_FLAG(filter)       (uint8)((filter) |= (DEM_DCM_FILTER_USESEVERITYSTATUSMASK))
#define DEM_DCM_RESET_USESEVERITYSTATUSMASK_FLAG(filter)     (uint8)((filter) &= ~(DEM_DCM_FILTER_USESEVERITYSTATUSMASK))

#define DEM_DCM_GET_USEFREEZEFRAMERECORDMASK_FLAG(filter)    (boolean)((uint8)((filter) & (DEM_DCM_FILTER_USEFREEZEFRAMERECORDMASK)) != 0)
#define DEM_DCM_SET_USEFREEZEFRAMERECORDMASK_FLAG(filter)    (uint8)((filter) |= (DEM_DCM_FILTER_USEFREEZEFRAMERECORDMASK))
#define DEM_DCM_RESET_USEFREEZEFRAMERECORDMASK_FLAG(filter)  (uint8)((filter) &= ~(DEM_DCM_FILTER_USEFREEZEFRAMERECORDMASK))

#define DEM_DCM_GET_USEFDC_FLAG(filter)                      (boolean)((uint8)((filter) & (DEM_DCM_FILTER_USEFDC)) != 0)
#define DEM_DCM_SET_USEFDC_FLAG(filter)                      (uint8)((filter) |= (DEM_DCM_FILTER_USEFDC))
#define DEM_DCM_RESET_USEFDC_FLAG(filter)                    (uint8)((filter) &= ~(DEM_DCM_FILTER_USEFDC))

#define DEM_MAX_PRIODTC          0xFu

#define DEM_PRIMARY_MEMORY_INDEX 0x00u
#define DEM_SECONDARY_MEMORY_INDEX 0x01u
#define DEM_INVALID_MEMORY_INDEX 0xFFu

/*****************************************************************************
 *                                 Type Declarations                          *
 ******************************************************************************/
typedef struct
{
  uint32 TimeStampCounter;
  uint8 InitState;
  boolean DtcSettingEnCondition;
  boolean DtcSettingEnConditionQueue;
  boolean DtcSettingConditionRequestedFlag;
} Dem_InternalType;

typedef struct
{
  sint16 DebounceValue[Dem_Cfg_Num_Of_Event];
  uint16 EnableConditionGroupMask;
  uint16 StorageConditionGroupMask;
  uint8 InternalStatus[Dem_Cfg_Num_Of_Event];
  uint8 InternalMemStatus[Dem_Cfg_Mem_Total_Entry];
  uint8 QueueStatus[Dem_Cfg_Num_Of_Event];
  uint8 AvailableStatus[DEM_CALCULATE_SIZE(Dem_Cfg_Num_Of_Event)];
  uint8 EnableCondition[Dem_Cfg_Num_Of_EnCon];
  uint8 StorageCondition[Dem_Cfg_Num_Of_StrCon];
  uint8 EnableConditionQueue[Dem_Cfg_Num_Of_EnCon];
  uint8 StorageConditionQueue[Dem_Cfg_Num_Of_StrCon];
  uint8 EnStrConditionFlag;
  uint8 QueueCount;
  #if(DEM_SUPPRESSION_SUPPORT == STD_ON)
  uint8 SuppressionState[DEM_CALCULATE_SIZE(Dem_Cfg_Num_Of_Event)];
  #endif
} Dem_EventType;

typedef struct
{
  uint32 DTC;
  uint16 EventId;
  Dem_DTCFormatType Format;
  Dem_DTCOriginType Origin;
  uint8 QueueState;
  uint8 Req_Status;
} Dem_ClearDtcType;

typedef struct
{
  uint32 DTC;
  uint16 EventId;
  Dem_DTCFormatType Format;
  Dem_DTCOriginType Origin;
  uint8 Req_Status;
  uint8 ClientId;
  uint8 ActiveOps;
  Dem_DTCKindType DTCKind;
  uint8 SnapshotRecordNumber;
  uint8 ExtendedDataNumber;
} Dem_DTCSelectorType;

typedef struct
{
  uint8 MemIndex;
  uint8 PendingCount;
  uint8 MemStatus;
  uint8 WriteStatus;
} Dem_NvmWriteDataType;

typedef struct
{
  uint16 EventIndex;
  uint8 MemIndex;
  uint8 Dtc_StatusMask;
  uint8 Req_Status;
  uint8 Dtc_SeverityMask;
  uint8 Req_SeverityStatus;
  uint8 FFRecIndex;
  uint8 FFStatus;
  uint8 Origin;
} Dem_FilterInfoType;

typedef struct
{
  uint16 State;
  uint16 QueueState;
  uint16 Flag;
} Dem_InternalOpCycleType;

typedef struct
{
  uint16 IndexofLowprioDTC;
  uint16 NoofstoredDTC;
  uint16 LowprioEventId;
  Dem_DTCOriginType EventOrigin;
  uint8 ValueofLowprioDTC;
  uint8 MemoryIndex;
  boolean TestFailedDTC;
  boolean OverflowIndication;
} Dem_MemStatusType;



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
#define DIAGMGR_DATA_SEC_START
#include "MemMap.h"

Dem_InternalType Dem_Internal;
Dem_EventType Dem_Event;
Dem_ClearDtcType Dem_ClearDtc[Dem_Cfg_Num_Of_Clients];
Dem_DTCSelectorType Dem_DTCSelector[Dem_Cfg_Num_Of_Clients];
Dem_NvmWriteDataType Dem_NvmWriteData;
boolean DTCStatusChangeNotification;

Dem_FilterInfoType Dem_FilterInfo[Dem_Cfg_Num_Of_Clients];
Dem_InternalOpCycleType Dem_InternalOpCycle;
Dem_MemStatusType Dem_MemStatus[Dem_Cfg_Num_Of_EventMemorySet];
#define DIAGMGR_DATA_SEC_END
#include "MemMap.h"

#define DIAGMGR_CODE_SEC_START
#include "MemMap.h"

static void Dem_InitInternalEventAvailabeStatus(void);
static void Dem_InitInternalEventEnableCondition(void);
static void Dem_InitInternalEventStorageCondition(void);
static void Dem_InitInternalOperationCycleAutoStart(void);
static void Dem_InternalStatusRestoreFromNvm(void);
static void Dem_InternalMemStatusRestoreFromNvM(Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry, uint8 Index);
static Dem_EventIdType Dem_InternalGetEventIdByDTCValue(uint32 DTC);
static void Dem_InternalSetEventStatus(Dem_EventIdType EventId, uint8 Value);
static uint8 Dem_InternalGetEventStatus(Dem_EventIdType EventId);
static void Dem_InternalSetDebounceStatus(Dem_EventIdType EventId, uint8 Value);
static uint8 Dem_InternalGetDebounceStatus(Dem_EventIdType EventId);
static void Dem_InitCfgUdsStatusData(void);
static void Dem_InitInternalEventStatusData(void);
static void Dem_InitCfgOperationCycleCounter(void);
static void Dem_InitCfgMemEntry(void);
static void Dem_ProcessEventAging(Dem_EventIdType flEventId, uint8 CycleId);
static void Dem_ProcessOperationCycleStateChange(uint8 CycleId, uint8 CycleStatus);
static void Dem_ProcessOperationCycleQueue(void);
static void Dem_MainFunctionProcessQueue(uint8 Client);
static void Dem_MainFunctionProcessTimerBasedEvent(uint8 Client);
static void Dem_MainFunctionProcessNvm(uint8 Client);
static Std_ReturnType Dem_AssessTimerBasedEvent(Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus);
static Std_ReturnType Dem_AssessInstantEvent(Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus);
static Std_ReturnType Dem_InternalCheckEventQualification(Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus);
static void Dem_ProcessQueuedEvents(uint8 Client);
static void Dem_ProcessTimerEvents(Dem_EventIdType EventId,
    Dem_Cfg_DebounceTableType DebounceTable);
static void Dem_ProcessQualifiedQueuedEvents(void);
static void Dem_InternalFreezeOrResetDebounceStatus(Dem_EventIdType flEventId);
static void Dem_ProcessDtcEnableCondition(void);
static void Dem_ProcessInitMForEventAll(Dem_InitMonitorReasonType flInitMReason);
static void Dem_ProcessNvmPendingWrite(void);
static Std_ReturnType Dem_ProcessCreateMemEntry(Dem_EventIdType EventId, uint8 *flMemIndex);
static Std_ReturnType Dem_ProcessUpdateMemEntry(Dem_EventIdType EventId, boolean IsPassed, uint8 *flMemIndex);
static void Dem_ProcessDeleteMemEntry(uint8 flMemIndex, uint8 flMemIterIndex);
static Std_ReturnType Dem_InternalClearDTC(uint8 Client);
static void Dem_ProcessClearDtcQueue(uint8 Client);
static Std_ReturnType Dem_ClearEventAllowed(Dem_EventIdType EventId);
#if (DemMaxNumberFreezeFrameRecords > 0)
static Dem_ReturnGetFreezeFrameDataByDTCType Dem_InternalGetMemoryIndex(uint16 *MemIndex, uint32 DtcId);
static void Dem_InternalUpdateFreezeFrameData(Dem_EventIdType EventId, Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry, uint8 flFreezeFrameRecNumClassRef);
static void Dem_InternalUpdateCalculatedFreezeFrameData(Dem_EventIdType EventId, Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry, uint8 flFreezeFrameRecNumClassRef);
static void Dem_InternalUpdateConfiguredFreezeFrameData(Dem_EventIdType EventId, Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry, uint8 flFreezeFrameRecNumClassRef);
#endif
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
static void Dem_InternalUpdateExtRecordData(Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry, uint8 ExtRecordTableRef,
        Dem_EventIdType EventId);
static void Dem_UpdateExtendedRecord(Dem_EventIdType Event, Dem_Cfg_PrimaryMemEntryType *MemoryPointer,uint8 * DestBuffer, DemIntDataElementType ExtendedData,uint8 DataSize);
static Dem_ReturnGetSizeOfDataByDTCType Dem_InternalGetExtDataRecMemoryIndex(Dem_EventIdType EventId, uint8 ExtendedDataNumber, uint16* indexOfExtendedDataRecord);
#endif
static sint8 Dem_InternalCalculateFDCCounterBased(Dem_EventIdType EventId, sint16 flDebounceValue);
static sint8 Dem_InternalCalculateFDCTimerBased(Dem_EventIdType EventId, sint16 flDebounceValue, uint8 flDebounceStatus);
static Std_ReturnType Dem_InternalFilterMatchEvent(uint8 ClientId, Dem_EventIdType flEventId);
static uint8 Dem_FindMemoryIndex(Dem_DTCOriginType Origin);

/*****************************************************************************
 *                   Functions                                                *
 ******************************************************************************/
#if(DEM_VERSION_INFO_AVAILABLE == TRUE)
/**************************************************************************
 Function name   : Dem_GetVersionInfo
 Arguments       : Std_VersionInfoType* versioninfo
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Returns the version information of this module..
 **************************************************************************/
void Dem_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
  if (versioninfo != NULL_PTR)
  {
    versioninfo->vendorID = DEM_VENDOR_ID;
    versioninfo->moduleID = DEM_MODULE_ID;
    versioninfo->sw_major_version = DEM_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = DEM_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = DEM_SW_PATCH_VERSION;
  }
}
#endif

/**************************************************************************
 Function name   : Dem_GetStatusAvailabilityMask
 Arguments       : void
 Return type     : Dem_UdsStatusByteType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Returns the version information of this module..
 **************************************************************************/
Dem_UdsStatusByteType Dem_GetStatusAvailabilityMask(void)
{
  Dem_UdsStatusByteType mask = DemDtcStatusAvailabilityMask_Def;
  Dcm_SesCtrlType sesCtrlType = 0u;
  (void) Dcm_GetSesCtrlType (&sesCtrlType);

  if(DIAG_SESSION_FOTA == sesCtrlType)
  {
    mask = DemDtcStatusAvailabilityMask_Fota;
  }
  return mask;
}

/**************************************************************************
 Function name   :  Dem_InternalSetEventStatus
 Arguments       :  Dem_EventIdType EventId, uint8 Value
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Set the status of the internal event status.
 **************************************************************************/
static void Dem_InternalSetEventStatus(Dem_EventIdType EventId, uint8 Value)
{
#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Value &= (DEM_EVENT_STATUS_BIT_MASK);
    Dem_Event.InternalStatus[EventId] &=
           ~(DEM_EVENT_STATUS_BIT_MASK << DEM_EVENT_STATUS_BIT_POS);
    Dem_Event.InternalStatus[EventId] |= (Value << DEM_EVENT_STATUS_BIT_POS);
  }
}

/**************************************************************************
 Function name   :  Dem_InternalGetEventStatus
 Arguments       :  Dem_EventIdType EventId
 Return type     :  uint8
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Get the status of the internal event status.
 **************************************************************************/
static uint8 Dem_InternalGetEventStatus(Dem_EventIdType EventId)
{
  uint8 fl_RetVal = 0u;
#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    fl_RetVal = (Dem_Event.InternalStatus[EventId]
        & (DEM_EVENT_STATUS_BIT_MASK << DEM_EVENT_STATUS_BIT_POS));
    fl_RetVal = (uint8)(fl_RetVal >> DEM_EVENT_STATUS_BIT_POS);
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   :  Dem_InternalSetDebounceStatus
 Arguments       :  Dem_EventIdType EventId, uint8 Value
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Set the status of the internal debounce status.
 **************************************************************************/
static void Dem_InternalSetDebounceStatus(Dem_EventIdType EventId, uint8 Value)
{
#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Value &= (DEM_EVENT_DEBOUNCE_STATUS_BIT_MASK);
    Dem_Event.InternalStatus[EventId] &= ~(DEM_EVENT_DEBOUNCE_STATUS_BIT_MASK
        << DEM_EVENT_DEBOUNCE_STATUS_BIT_POS);
    Dem_Event.InternalStatus[EventId] |= (Value << DEM_EVENT_DEBOUNCE_STATUS_BIT_POS);
  }
}

/**************************************************************************
 Function name   :  Dem_InternalGetDebounceStatus
 Arguments       :  Dem_EventIdType EventId
 Return type     :  uint8
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Get the status of the internal debounce status.
 **************************************************************************/
static uint8 Dem_InternalGetDebounceStatus(Dem_EventIdType EventId)
{
  uint8 fl_RetVal = 0u;
#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    fl_RetVal = (Dem_Event.InternalStatus[EventId]
        & (DEM_EVENT_DEBOUNCE_STATUS_BIT_MASK << DEM_EVENT_DEBOUNCE_STATUS_BIT_POS));
    fl_RetVal = (uint8)(fl_RetVal >> DEM_EVENT_DEBOUNCE_STATUS_BIT_POS);
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   :  Dem_InitCfgUdsStatusData
 Arguments       :  void
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Used to initialize the UDS event status and related data
 to default values upon init.
 **************************************************************************/
static void Dem_InitCfgUdsStatusData(void)
{
  Dem_EventIdType flIter;
  Dem_Cfg_StatusData.FirstConfirmedEvent = DEM_EVENT_INVALID;
  Dem_Cfg_StatusData.FirstFailedEvent = DEM_EVENT_INVALID;
  Dem_Cfg_StatusData.RecentConfirmedEvent = DEM_EVENT_INVALID;
  Dem_Cfg_StatusData.RecentFailedEvent = DEM_EVENT_INVALID;
 
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_EventMemorySet; flIter++)
  {
    Dem_Cfg_StatusData.MemoryOverflow [flIter] = FALSE;
  }
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_Event; flIter++)
  {
    Dem_Cfg_StatusData.EventStatus[flIter] = DEM_UDS_STATUS_DEFAULT;
  }
  if ((Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] == DEM_MEM_STATUS_NONE) && (Dem_NvmWriteData.PendingCount < DEM_UINT_8_MAX))
  {
    Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + DEM_ONE;
  }
  Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] = DEM_MEM_STATUS_TRIGGER_CLEAR;
}

/**************************************************************************
 Function name   :  Dem_InitInternalEventStatusData
 Arguments       :  void
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Used to initialize the UDS event status and related data
 to default values upon init.
 **************************************************************************/
static void Dem_InitInternalEventStatusData(void)
{
  Dem_EventIdType flIter;

  for (flIter = 0; flIter < Dem_Cfg_Num_Of_Event; flIter++)
  {
    Dem_InternalSetEventStatus(flIter, DEM_EVENT_STATUS_NONE);
  }
}

/**************************************************************************
 Function name   :  Dem_InitCfgOperationCycleCounter
 Arguments       :  void
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Used to initialize the Operation cycle counter and magic flag
 to default values upon init.
 **************************************************************************/
static void Dem_InitCfgOperationCycleCounter(void)
{
  uint8 flIter;
  Dem_Cfg_OpCycle.MagicFlag = DEM_NVM_MAGIC_VALUE;
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_OpCycle; flIter++)
  {
    Dem_Cfg_OpCycle.Counter[flIter] = 0x0U;
  }
  if ((Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Admin_Index] == DEM_MEM_STATUS_NONE) && (Dem_NvmWriteData.PendingCount < DEM_UINT_8_MAX))
  {
    Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + DEM_ONE;
  }
  Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Admin_Index] = DEM_MEM_STATUS_TRIGGER_CLEAR;
}

/**************************************************************************
 Function name   :  Dem_InitCfgMemEntry
 Arguments       :  void
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :
 Description     :  Used to initialize the primary memory entry init structures
 to default values upon init.
 **************************************************************************/
static void Dem_InitCfgMemEntry(void)
{
  uint8 flIter;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
    uint8 ExtRecordRowIndex = 0;
    uint8 ExtRecordSizeIndex = 0;
#endif
#if (DemMaxNumberFreezeFrameRecords > 0)
    uint8 FFRecordRowIndex = 0;
    uint8 FFRecordSizeIndex = 0;
#endif

  for (flIter = Dem_Cfg_Mem_Primary_Entry_Start; flIter < Dem_Cfg_Mem_Total_Entry; flIter++)
  {
    flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flIter];
    flEntry->AgingCounter = DEM_DTC_AGING_INVALID;
    flEntry->EventId = DEM_EVENT_INVALID;
    flEntry->OccurrenceCounter = DEM_EVENT_OCCNTR_INVALID;
    flEntry->TimeStamp = DEM_EVENT_TMSTMP_INVALID;
    flEntry->EventMemoryOrigin = DEM_DTC_ORIGIN_INVALID_MEMORY;

    if ((Dem_Event.InternalMemStatus[flIter] == DEM_MEM_STATUS_NONE) && (Dem_NvmWriteData.PendingCount < DEM_UINT_8_MAX))
    {
      Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + DEM_ONE;
    }
    Dem_Event.InternalMemStatus[flIter] = DEM_MEM_STATUS_TRIGGER_CLEAR;
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
    /*Init ExtRecordData*/
    for (ExtRecordRowIndex = 0;  ExtRecordRowIndex < DEM_NUM_OF_EXTENDEDRECORD; ExtRecordRowIndex++)
    {
      for (ExtRecordSizeIndex = 0; ExtRecordSizeIndex < DEM_MAX_LENGTH_OF_EXTENDEDRECORD; ExtRecordSizeIndex++)
      {
        flEntry->ExtendedDataRecord[ExtRecordRowIndex][ExtRecordSizeIndex] = DEM_EXT_REC_DATA_INVALID;
      }
    }
#endif
#if (DemMaxNumberFreezeFrameRecords > 0)
    /*Init FFRecordData*/
    flEntry->SnahpshotHeader = 0x0U;
    for (FFRecordRowIndex = 0;  FFRecordRowIndex < DemMaxNumberFreezeFrameRecords; FFRecordRowIndex++)
    {
      for (FFRecordSizeIndex = 0; FFRecordSizeIndex < DemMaxLengthFreezeFrameData; FFRecordSizeIndex++)
      {
        flEntry->SnapshotData[FFRecordRowIndex][FFRecordSizeIndex] = DEM_FREEZE_FRAME_INVALID;
      }
    }
#endif
  }
}

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
void Dem_PreInit(void)
{
  Dem_EventIdType flIter = 0;

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_UNINITIALIZED)
  {
    flError = DEM_DET_WRONG_CONDITION;
  }

  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dem_Internal.DtcSettingEnCondition = DEM_DTC_STORAGE_SETTING_ENABLED;
    Dem_Internal.DtcSettingEnConditionQueue = DEM_DTC_STORAGE_SETTING_ENABLED;
    Dem_Internal.DtcSettingConditionRequestedFlag = FALSE;

    Dem_Internal.TimeStampCounter = 0U;

    for (flIter = 0; flIter < Dem_Cfg_Num_Of_Clients; flIter++)
    {
      Dem_ClearDtc[flIter].DTC = 0U;
      Dem_ClearDtc[flIter].EventId = 0U;
      Dem_ClearDtc[flIter].Format = 0U;
      Dem_ClearDtc[flIter].Origin = 0U;
      Dem_ClearDtc[flIter].Req_Status = 0U;
      Dem_ClearDtc[flIter].QueueState = 0U;

      Dem_DTCSelector[flIter].DTC = 0U;
      Dem_DTCSelector[flIter].EventId = 0U;
      Dem_DTCSelector[flIter].Format = 0U;
      Dem_DTCSelector[flIter].Origin = 0U;
      Dem_DTCSelector[flIter].Req_Status = 0U;
      Dem_DTCSelector[flIter].ClientId = 0U;
      Dem_DTCSelector[flIter].DTCKind = 0U;
      Dem_DTCSelector[flIter].ActiveOps = 0U;
      Dem_DTCSelector[flIter].SnapshotRecordNumber = 0U;
      Dem_DTCSelector[flIter].ExtendedDataNumber = 0U;

      Dem_FilterInfo[flIter].Dtc_StatusMask = 0U;
      Dem_FilterInfo[flIter].EventIndex = 0U;
      Dem_FilterInfo[flIter].Req_Status = 0U;
      Dem_FilterInfo[flIter].Dtc_StatusMask = 0u;
      Dem_FilterInfo[flIter].Dtc_SeverityMask = 0u;
      Dem_FilterInfo[flIter].FFRecIndex = 0u;
      Dem_FilterInfo[flIter].FFStatus = 0u;
      Dem_FilterInfo[flIter].MemIndex = 0u;
      Dem_FilterInfo[flIter].Req_SeverityStatus = 0u;
      Dem_FilterInfo[flIter].Origin = DEM_DTC_ORIGIN_INVALID_MEMORY;
    }

    Dem_NvmWriteData.MemIndex = 0U;
    Dem_NvmWriteData.PendingCount = 0U;
    Dem_NvmWriteData.WriteStatus = DEM_NVM_IDLE;

    for (flIter = 0; flIter < Dem_Cfg_Num_Of_EventMemorySet; flIter++)
    {
      Dem_MemStatus[flIter].IndexofLowprioDTC = 0U;
      Dem_MemStatus[flIter].NoofstoredDTC = 0U;
      Dem_MemStatus[flIter].LowprioEventId = 0U;
      Dem_MemStatus[flIter].ValueofLowprioDTC = 0U;
      Dem_MemStatus[flIter].TestFailedDTC = 0U;
      Dem_MemStatus[flIter].EventOrigin = DEM_DTC_ORIGIN_INVALID_MEMORY;
      Dem_MemStatus[flIter].MemoryIndex = DEM_INVALID_MEMORY_INDEX;
      Dem_MemStatus[flIter].OverflowIndication = FALSE;
    }

    Dem_InternalOpCycle.Flag = 0U;
    Dem_InternalOpCycle.QueueState = 0U;
    Dem_InternalOpCycle.State = 0U;

    Dem_Event.QueueCount = 0U;

    DTCStatusChangeNotification = 0U;

    for (flIter = 0; flIter < Dem_Cfg_Num_Of_Event; flIter++)
    {
      Dem_Event.DebounceValue[flIter] = 0U;
      Dem_Event.InternalStatus[flIter] = 0U;
      Dem_Event.QueueStatus[flIter] = 0U;
    }

    for (flIter = 0; flIter < Dem_Cfg_Mem_Total_Entry; flIter++)
    {
      Dem_Event.InternalMemStatus[flIter] = 0U;
    }

    Dem_InitInternalEventAvailabeStatus();
    Dem_InitInternalEventEnableCondition();
    Dem_InitInternalEventStorageCondition();
    Dem_InitInternalOperationCycleAutoStart();
    Dem_Internal.InitState = DEM_PREINITIALIZED;
  }
}

/**************************************************************************
 Function name   : Dem_InitInternalOperationCycleAutoStart
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to initialize the operation cycle auto-start functionality
 upon pre-init.
 **************************************************************************/
static void Dem_InitInternalOperationCycleAutoStart(void)
{
  uint8 flIter;
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_OpCycle; flIter++)
  {
    if (FALSE != (Dem_Cfg_OpCycleState[flIter].AutoStart))
    {
      DEM_SET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.State, flIter);
    }
    else
    {
      DEM_RESET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.State, flIter);
    }
  }
}

/**************************************************************************
 Function name   : Dem_InitInternalEventAvailabeStatus
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to initialize the event available status upon pre-init.
 **************************************************************************/
static void Dem_InitInternalEventAvailabeStatus(void)
{
  Dem_EventIdType flIter;
  uint8 flIndex;
  uint8 flMask;

  for (flIter = 0; flIter < Dem_Cfg_Num_Of_Event; flIter++)
  {
    flIndex = DEM_CALCULATE_INDEX(flIter);
    flMask = DEM_CALCULATE_MASK_BIT(flIter);
    /* Setting the Default bit wise status from  configuration*/
    if (FALSE != (Dem_Cfg_EventParameter[flIter].AvailableStatus))
    {
      DEM_SET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    }
    else
    {
      DEM_RESET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    }
  }
}

/**************************************************************************
 Function name   : Dem_InitInternalEventEnableCondition
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to initialize the event enable condition upon pre-init.
 **************************************************************************/
static void Dem_InitInternalEventEnableCondition(void)
{
  uint8 flIter;
  Dem_Event.EnableConditionGroupMask = 0x00U;
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_EnCon; flIter++)
  {
    Dem_Event.EnableCondition[flIter] = Dem_Cfg_EnableCondition[flIter].Status;
    Dem_Event.EnableConditionQueue[flIter] = Dem_Cfg_EnableCondition[flIter].Status;
    if(Dem_Event.EnableCondition[flIter] != 0x0U)
    {
      Dem_Event.EnableConditionGroupMask |= (0x01U << flIter);
    }
  }
  DEM_RESET_BIT_STATE(Dem_Event.EnStrConditionFlag, DEM_EVENT_ENABLE_CONDITION_REQUESTED);

}

/**************************************************************************
 Function name   : Dem_InitInternalEventStorageCondition
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to initialize the event storage condition upon pre-init.
 **************************************************************************/
static void Dem_InitInternalEventStorageCondition(void)
{
  uint8 flIter;
  Dem_Event.StorageConditionGroupMask = 0x00U;
  for (flIter = 0; flIter < Dem_Cfg_Num_Of_StrCon; flIter++)
  {
    Dem_Event.StorageCondition[flIter] = Dem_Cfg_StorageCondition[flIter].Status;
    Dem_Event.StorageConditionQueue[flIter] = Dem_Cfg_StorageCondition[flIter].Status;
    if(Dem_Event.StorageCondition[flIter] != 0x0U)
    {
      Dem_Event.StorageConditionGroupMask |= (0x01U << flIter);
    }
  }
  DEM_RESET_BIT_STATE(Dem_Event.EnStrConditionFlag,
      DEM_EVENT_STORAGE_CONDITION_REQUESTED);
}

/**************************************************************************
 Function name   : Dem_InternalStatusRestoreFromNvm
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to restore the UDS event status from retained event volatile
 Entry if exists. Else restore the default values to all PRAM.
 **************************************************************************/
static void Dem_InternalStatusRestoreFromNvm(void)
{
  uint8 flIter;
  Dem_EventIdType flEventId = 0;
  uint32 flTimeStamp = 0;

  Dem_Cfg_PrimaryMemEntryType *flEntry;

  /* If Magic Number is not intact, then load default values */
  if (Dem_Cfg_OpCycle.MagicFlag == DEM_NVM_MAGIC_VALUE)
  {
    /* Restore status data */
    for (flIter = Dem_Cfg_Mem_Primary_Entry_Start;
        flIter < Dem_Cfg_Mem_Total_Entry; flIter++)
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flIter];
      flEventId = flEntry->EventId;
      /* Checks already entry is there are not in PRAM */
      if (flEventId != DEM_EVENT_INVALID)
      {
        if (flEntry->TimeStamp != DEM_EVENT_TMSTMP_INVALID)
        {
          if (flTimeStamp < flEntry->TimeStamp)
          {
            flTimeStamp = flEntry->TimeStamp;
          }
        }
        if (flEntry->AgingCounter != DEM_DTC_AGING_INVALID)
        {
          Dem_InternalSetEventStatus(flEventId, DEM_EVENT_STATUS_AGING);
        }
        else
        {
          Dem_InternalSetEventStatus(flEventId, DEM_EVENT_STATUS_STORED);
        }
        Dem_InternalMemStatusRestoreFromNvM(flEntry,flIter);
      }
    }
    /* Loads highest time stamp value */
    Dem_Internal.TimeStampCounter = flTimeStamp + DEM_ONE;
  }
  else
  {
    Dem_NvmWriteData.PendingCount = 0x00U;
    Dem_InitCfgUdsStatusData();
    Dem_InitCfgOperationCycleCounter();
    Dem_InitCfgMemEntry();
    Dem_InitInternalEventStatusData();
    Dem_Internal.TimeStampCounter = DEM_ONE;
  }
}

/**************************************************************************
 Function name   : Dem_InternalMemStatusRestoreFromNvM
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to restore the UDS event status from retained event volatile
 Entry if exists. Else restore the default values to all PRAM.
 **************************************************************************/
static void Dem_InternalMemStatusRestoreFromNvM(Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry, uint8 Index)
{
  uint8 flIndex = 0u ;

  flIndex = Dem_FindMemoryIndex(Dem_Cfg_EventParameter[fl_MemoryEntry->EventId].DemOrigin);

  Dem_MemStatus[flIndex].ValueofLowprioDTC = 0U;
  Dem_MemStatus[flIndex].IndexofLowprioDTC = Dem_Cfg_Mem_Total_Entry + DEM_ONE;
  Dem_MemStatus[flIndex].LowprioEventId = DEM_EVENT_INVALID;
  Dem_MemStatus[flIndex].NoofstoredDTC = 0U;
  Dem_MemStatus[flIndex].TestFailedDTC = DEM_EVENT_INVALID;
  Dem_MemStatus[flIndex].OverflowIndication = FALSE;
  Dem_MemStatus[flIndex].MemoryIndex = flIndex;
  if (Dem_MemStatus[flIndex].ValueofLowprioDTC < Dem_Cfg_EventParameter[fl_MemoryEntry->EventId].Priority)
  {
    Dem_MemStatus[flIndex].ValueofLowprioDTC = Dem_Cfg_EventParameter[fl_MemoryEntry->EventId].Priority;
    Dem_MemStatus[flIndex].IndexofLowprioDTC = Index;
    Dem_MemStatus[flIndex].LowprioEventId = fl_MemoryEntry->EventId;
    Dem_MemStatus[flIndex].TestFailedDTC = DEM_GET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[fl_MemoryEntry->EventId]);
    Dem_MemStatus[flIndex].EventOrigin = Dem_Cfg_EventParameter[fl_MemoryEntry->EventId].DemOrigin;
  }
  Dem_MemStatus[flIndex].NoofstoredDTC += DEM_ONE;

}

/**************************************************************************
 Function name   : Dem_FindMemoryIndex
 Arguments       : Dem_DTCOriginType Origin
 Return type     : uint8
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to find memory index.
**************************************************************************/
static uint8 Dem_FindMemoryIndex(Dem_DTCOriginType Origin)
{
  uint8 index;

  if(Origin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
  {
    index = DEM_PRIMARY_MEMORY_INDEX;
  }
  else if(Origin == DEM_DTC_ORIGIN_USER_MEMORY)
  {
    index = DEM_SECONDARY_MEMORY_INDEX;
  }
  else
  {
    index = DEM_INVALID_MEMORY_INDEX;
  }

  return index;
}

/**************************************************************************
 Function name   :  Dem_Init
 Arguments       :  const Dem_ConfigType* ConfigPtr
 Return type     :  void
 Sync/Async      :  Synchronous
 Reentrancy      :  Non Reentrant
 Description     :  Initializes or reinitializes this module.
 **************************************************************************/
void Dem_Init(const Dem_ConfigType* ConfigPtr)
{
  DEM_IGNORE_UNREF_PARAM(ConfigPtr);

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if ((Dem_Internal.InitState != DEM_PREINITIALIZED)
      && (Dem_Internal.InitState != DEM_SHUTDOWN))
  {
    flError = DEM_DET_WRONG_CONDITION;
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    uint8 flIter = 0U;
    /*** NVM Init ***/

    Dem_NvmWriteData.MemIndex = 0U;
    Dem_NvmWriteData.PendingCount = 0U;
    Dem_NvmWriteData.WriteStatus = DEM_NVM_IDLE;

    for (flIter = 0; flIter < Dem_Cfg_Num_Of_Clients; flIter++)
    {
      Dem_DTCSelector[flIter].DTC = DEM_DTC_INVALID;
      Dem_DTCSelector[flIter].EventId = DEM_EVENT_INVALID;
      Dem_DTCSelector[flIter].Format = DEM_DTC_FORMAT_INVALID;
      Dem_DTCSelector[flIter].Origin = DEM_DTC_ORIGIN_INVALID;
      Dem_DTCSelector[flIter].Req_Status = 0U;
      Dem_DTCSelector[flIter].ClientId = 0U;
      Dem_DTCSelector[flIter].ActiveOps = 0U;
      Dem_DTCSelector[flIter].DTCKind = DEM_DTC_KIND_INVALID;
      Dem_DTCSelector[flIter].SnapshotRecordNumber = 0U;
      Dem_DTCSelector[flIter].ExtendedDataNumber = 0U;
      
      Dem_ClearDtc[flIter].DTC = DEM_DTC_INVALID;
      Dem_ClearDtc[flIter].EventId = DEM_EVENT_INVALID;
      Dem_ClearDtc[flIter].Format = DEM_DTC_FORMAT_INVALID;
      Dem_ClearDtc[flIter].Origin = DEM_DTC_ORIGIN_INVALID;
      Dem_ClearDtc[flIter].Req_Status = 0U;
    }

    DTCStatusChangeNotification = 0x0U;

    Dem_InternalStatusRestoreFromNvm();

    Dem_Internal.InitState = DEM_INITIALIZED;
  }
}

/**************************************************************************
 Function name   : Dem_Shutdown
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Shuts down this module.
 **************************************************************************/
void Dem_Shutdown(void)
{
  uint8 flIndex;
#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dem_Internal.InitState = DEM_SHUTDOWN;

    for (flIndex = 0; flIndex < Dem_Cfg_Num_Of_OpCycle; flIndex++)
    {
      DEM_RESET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState, flIndex);
      DEM_RESET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, flIndex);
      if(FALSE != Dem_Cfg_OpCycleState[flIndex].AutoStop)
      {
        (void)Dem_SetOperationCycleState(flIndex, DEM_CYCLE_STATE_END);
        (void)Dem_SetOperationCycleState(flIndex, DEM_CYCLE_STATE_START);
        (void)Dem_SetOperationCycleState(flIndex, DEM_CYCLE_STATE_END);
      }
    }
    /* Process The Operation Cycle Queue */
    Dem_ProcessOperationCycleQueue();

    #if (DEM_USE_NVM == STD_ON)
    for (flIndex = Dem_Cfg_Mem_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry;
        flIndex++)
    {
      if (Dem_Event.InternalMemStatus[flIndex] != DEM_MEM_STATUS_NONE)
      {
        (void) NvM_SetRamBlockStatus((NvM_BlockIdType) Dem_Cfg_Memory_BlockId[flIndex], TRUE);
      }
    }
    #endif
  }
}

/**************************************************************************
 Function name   : IsDemReady
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
boolean IsDemReady(void)
{
  return (Dem_Internal.InitState == DEM_INITIALIZED);
}

/**************************************************************************
 Function name   : Dem_ProcessTimerEvents
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does process of qualifying reported events which are configured for
 time debouncing algorithm.
 **************************************************************************/
static void Dem_ProcessTimerEvents(Dem_EventIdType EventId,
                      Dem_Cfg_DebounceTableType DebounceTable)
{
  Dem_EventStatusType flEventStatus;
  sint16 flOldDebounceValue;
  sint16 flNewDebounceValue;
  uint8 flInternalDebounceStatus;
  uint8 flOldUdsEventStatus;
  uint8 flNewUdsEventStatus;
#if(DemTriggerDcmReports == STD_ON)
  uint8 flDTCTableRef;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flOldDebounceValue = Dem_Event.DebounceValue[EventId];
    flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[EventId];
    flNewDebounceValue = flOldDebounceValue;
    flNewUdsEventStatus = flOldUdsEventStatus;
    flEventStatus = DEM_EVENT_STATUS_INVALID;

    flInternalDebounceStatus = Dem_InternalGetDebounceStatus(EventId);
    switch (flInternalDebounceStatus)
    {
      case DEM_EVENT_DEBOUNCE_STATUS_PASSED:
        flNewDebounceValue = 0x0U;
        flEventStatus = DEM_EVENT_STATUS_PASSED;
        break;
      
      case DEM_EVENT_DEBOUNCE_STATUS_FAILED:
        flNewDebounceValue = 0x0U;
        flEventStatus = DEM_EVENT_STATUS_FAILED;
        break;
      
      case DEM_EVENT_DEBOUNCE_STATUS_HEALING:
        if (flNewDebounceValue > DEM_ONE)
        {
          flNewDebounceValue = flNewDebounceValue - DEM_ONE;
          flEventStatus = DEM_EVENT_STATUS_PREPASSED;
        }
        else
        {
          flNewDebounceValue = 0x0U;
          Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_PASSED);
          flEventStatus = DEM_EVENT_STATUS_PASSED;
        }
        break;
      
      case DEM_EVENT_DEBOUNCE_STATUS_FAILING:
        if (flNewDebounceValue > DEM_ONE)
        {
          flNewDebounceValue = flNewDebounceValue - DEM_ONE;
          flEventStatus = DEM_EVENT_STATUS_PREFAILED;
        }
        else
        {
          flNewDebounceValue = 0x0U;
          Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FAILED);
          flEventStatus = DEM_EVENT_STATUS_FAILED;
        }
        break;
      
      case DEM_EVENT_DEBOUNCE_STATUS_HEAL_RESET:
        flNewDebounceValue = DebounceTable.PassedTimeThershold;
        flEventStatus = DEM_EVENT_STATUS_PREPASSED;
        Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_HEALING);
        break;
      
      case DEM_EVENT_DEBOUNCE_STATUS_FAIL_RESET:
        flNewDebounceValue = DebounceTable.FailedTimeThershold;
        flEventStatus = DEM_EVENT_STATUS_PREFAILED;
        Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FAILING);
        break;
      
      default:
           /*DoNothing*/
        break;
    }

    if (flNewDebounceValue != flOldDebounceValue)
    {
      if (flEventStatus == DEM_EVENT_STATUS_PASSED)
      {
        DEM_RESET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_WIR(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else if (flEventStatus == DEM_EVENT_STATUS_FAILED)
      {
        DEM_SET_UDS_STATUS_BYTE_TFTMC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TFSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else
      {
        /* Do nothing */
      }
      if (DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition)
      {

        /***  Queue Event Status ***/
        (void)Dem_InternalCheckEventQualification(EventId, flEventStatus);

        /*** Update New event status  ***/
        if (flNewUdsEventStatus != flOldUdsEventStatus)
        {
          flDTCTableRef = Dem_Cfg_EventParameter[EventId].DTCTableRef;
          DCMEXT_NOTIFICATIONONDTCSTATUSCHANGE(Dem_Cfg_DTC[flDTCTableRef].Value,
                                      flOldUdsEventStatus, flNewUdsEventStatus);
#if(DemTriggerDcmReports == STD_ON)
          if(DTCStatusChangeNotification != FALSE)
          {
            flDTCTableRef = Dem_Cfg_EventParameter[EventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
            if(flDTCTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
            {
              (void)Dcm_DemTriggerOnDTCStatus(Dem_Cfg_DTC[flDTCTableRef].Value,
                                        flOldUdsEventStatus, flNewUdsEventStatus); /*MISRA FIX*/
            }
          }
#endif
          Dem_Cfg_StatusData.EventStatus[EventId] = flNewUdsEventStatus;
        }
        Dem_Event.DebounceValue[EventId] = flNewDebounceValue;
      }
    }
  }
}



#if (DemMaxNumberFreezeFrameRecords > 0)
/**************************************************************************
 Function name   : Dem_InternalUpdateFreezeFrameData
 Arguments       :
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
static void Dem_InternalUpdateFreezeFrameData(Dem_EventIdType EventId,
                                  Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry,
                                  uint8 flFreezeFrameRecNumClassRef)
{

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (fl_MemoryEntry == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    #if(DemTypeOfFreezeFrameRecordNumeration != DEM_FF_RECNUM_CONFIGURED)
      Dem_InternalUpdateCalculatedFreezeFrameData(EventId, fl_MemoryEntry, flFreezeFrameRecNumClassRef);
    #else
      Dem_InternalUpdateConfiguredFreezeFrameData(EventId, fl_MemoryEntry, flFreezeFrameRecNumClassRef);
    #endif
  }
}

#if(DemTypeOfFreezeFrameRecordNumeration != DEM_FF_RECNUM_CONFIGURED)
/**************************************************************************
 Function name   : Dem_InternalUpdateCalculatedFreezeFrameData
 Arguments       :
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
static void Dem_InternalUpdateCalculatedFreezeFrameData(Dem_EventIdType EventId,
                                  Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry,
                                  uint8 flFreezeFrameRecNumClassRef)
{
  uint8 flFreezeFrameClassRef;
  uint8 flDidClassRef;
  uint8 flExternalDataElementClassRef;
  uint8 flDIDIndex;
  uint8 flNoOfDid;
  uint8 flMemIndex;
  uint8 flElementSize;
  uint8 flElementIndex;
  Std_ReturnType flRetVal;

  flMemIndex = 0;
  if(fl_MemoryEntry->SnahpshotHeader <= DemMaxNumberFreezeFrameRecords)
  {
    flFreezeFrameClassRef = flFreezeFrameRecNumClassRef;
    if(flFreezeFrameClassRef < Dem_Cfg_Num_Of_DTC)
    {
      if(fl_MemoryEntry->SnahpshotHeader >= DemMaxNumberFreezeFrameRecords - 1u)
      {
        fl_MemoryEntry->SnahpshotHeader = DemMaxNumberFreezeFrameRecords;
      }
      else
      {
        //SnahpshotHeader will have the count of how many records stored - msavariy
        fl_MemoryEntry->SnahpshotHeader += DEM_ONE;
      }
      flNoOfDid = DemFreezeFrameClass[flFreezeFrameClassRef].NoOfDid;
      for(flDIDIndex = 0U; flDIDIndex < flNoOfDid; flDIDIndex++)
      {
        flDidClassRef = DemFreezeFrameClass[flFreezeFrameClassRef].DidClassRef[flDIDIndex];
        if(DemMaxNumberFreezeFrameDID > flDidClassRef)
        {
          flExternalDataElementClassRef = DemDidClass[flDidClassRef].ExternalDataElementClassRef;
          if(DEM_NUM_OF_EXTERNALRECORDDATA > flExternalDataElementClassRef)
          {
            if((flMemIndex < DemMaxLengthFreezeFrameData)
                    && (NULL != Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementReadFnc))
            {
              flRetVal = Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementReadFnc(EventId, (uint8*) &fl_MemoryEntry->SnapshotData[fl_MemoryEntry->SnahpshotHeader - 1u][flMemIndex]);
              if(flRetVal != E_OK)
              {
                /* If return values of external data record read function is other than E_OK, then load 0xFF to elements */
                flElementSize = Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                for(flElementIndex = 0; flElementIndex < flElementSize; flElementIndex++)
                {
                  #if(DemDevAdditionalCoverityChecks == TRUE)
                  if((flMemIndex + flElementIndex) < DemMaxLengthFreezeFrameData)
                  #endif
                  {
                    fl_MemoryEntry->SnapshotData[fl_MemoryEntry->SnahpshotHeader - 1u][flMemIndex + flElementIndex] = DEM_0xFF;
                  }
                }
              }
            }
          }
        }
        flMemIndex += Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
      }
    }
  }
}
#endif

#if(DemTypeOfFreezeFrameRecordNumeration != DEM_FF_RECNUM_CALCULATED)
/**************************************************************************
 Function name   : Dem_InternalUpdateConfiguredFreezeFrameData
 Arguments       :
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
static void Dem_InternalUpdateConfiguredFreezeFrameData(Dem_EventIdType EventId,
                                  Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry,
                                  uint8 flFreezeFrameRecNumClassRef)
{
  uint8 flFreezeFrameRecordClassRef;
  uint8 flFreezeFrameRecordNumClassRef;
  uint8 flFreezeFrameClassRef;
  uint8 flDidClassRef;
  uint8 flExternalDataElementClassRef;
  uint8 flNoOFFF;
  uint8 flFFIndex;
  uint8 flDIDIndex;
  uint8 flNoOfDid;
  uint8 flMemIndex;
  uint8 flElementSize;
  uint8 flElementIndex;
  uint8 flFFClassIndex;
  uint8 flIndex;
  Std_ReturnType flRetVal;
  boolean flUpdate = FALSE;

  if(DemMaxNumberFreezeFrameRecords > flFreezeFrameRecNumClassRef)
  {
    flNoOFFF = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].MaxNumberFreezeFrameRecords;
    for(flFFIndex = 0U; flFFIndex < flNoOFFF; flFFIndex++)
    {
      flMemIndex = 0;
      flFreezeFrameRecordClassRef = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].FreezeFrameRecordClassRef[flFFIndex];
      if(DemMaxNumberFreezeFrameRecords > flFreezeFrameRecordClassRef)
      {
        if(   (DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].Update == DEM_UPDATE_RECORD_NO)
             && (fl_MemoryEntry->SnahpshotHeader > 0))
        {
          /* empty */
        }
        else
        {
          /* Check whether there is a memory entry available for the request DTC */
          flFreezeFrameRecordNumClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].NoofFFClass;
          for(flFFClassIndex = 0U; flFFClassIndex < flFreezeFrameRecordNumClassRef; flFFClassIndex++)
          {
            flFreezeFrameClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].FreezeFrameClassRef[flFFClassIndex];
            flNoOfDid = DemFreezeFrameClass[flFreezeFrameClassRef].NoOfDid;
            for(flDIDIndex = 0U; flDIDIndex < flNoOfDid; flDIDIndex++)
            {
              flDidClassRef = DemFreezeFrameClass[flFreezeFrameClassRef].DidClassRef[flDIDIndex];
              if(DemMaxNumberFreezeFrameDID > flDidClassRef)
              {
                flExternalDataElementClassRef = DemDidClass[flDidClassRef].ExternalDataElementClassRef;
                #if(DemDevAdditionalCoverityChecks == TRUE)
                if((flFFIndex < DemMaxNumberFreezeFrameRecords) &&
                    (DEM_NUM_OF_EXTERNALRECORDDATA > flExternalDataElementClassRef))
                #else
                if(DEM_NUM_OF_EXTERNALRECORDDATA > flExternalDataElementClassRef)
                #endif
                {
                  #if(DemDevAdditionalCoverityChecks == TRUE)
                  if(   (flMemIndex < DemMaxLengthFreezeFrameData)
                      && (NULL != Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementReadFnc))
                  #endif
                  {
                    flRetVal = Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementReadFnc(EventId, (uint8*) &fl_MemoryEntry->SnapshotData[flFFIndex][flMemIndex]);
                    if(flRetVal != E_OK)
                    {
                      /* If return values of external data record read function is other than E_OK, then load 0xFF to elements */
                      flElementSize = Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                      for(flElementIndex = 0; flElementIndex < flElementSize; flElementIndex++)
                      {
                        #if(DemDevAdditionalCoverityChecks == TRUE)
                        if((flMemIndex + flElementIndex) < DemMaxLengthFreezeFrameData)
                        #endif
                        {
                          fl_MemoryEntry->SnapshotData[flFFIndex][flMemIndex + flElementIndex] = DEM_0xFF;
                        }
                      }
                    }
                    //SnahpshotHeader will have the count of how many records stored - msavariy
                    fl_MemoryEntry->SnahpshotHeader = flFFIndex + DEM_ONE;
                    flMemIndex += Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
#endif
#endif /* (DemMaxNumberFreezeFrameRecords > 0)*/

/**************************************************************************
 Function name   : Dem_ProcessCreateMemEntry
 Arguments       : Dem_EventIdType EventId,     uint8 *flMemIndex
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to find the free PRAM entry and create new entry into that.
 **************************************************************************/
static Std_ReturnType Dem_CreateMemEntry(Dem_EventIdType EventId, uint8 flIndex, uint8 flMemIterIndex, uint8 *flMemIndex)
{

  Std_ReturnType flReturnVal = E_NOT_OK;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
#if (DemMaxNumberFreezeFrameRecords > 0) || (DEM_NUM_OF_EXTENDEDRECORD > 0)
  uint8 ref;
#endif
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
  uint8 AttributeTableRef;
  uint8 ExtRecordTableRef;
#endif
#if (DemMaxNumberFreezeFrameRecords > 0)
  uint8 flFFAttributeTableRef;
  uint8 flFreezeFrameRecNumClassRef;
#endif
  flEntry = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[flIndex];
  if ((flEntry->EventId == DEM_EVENT_INVALID) && (flEntry->TimeStamp == DEM_EVENT_TMSTMP_INVALID))
  {
    flEntry->EventId = EventId;
    flEntry->AgingCounter = DEM_DTC_AGING_INVALID;
    flEntry->OccurrenceCounter = DEM_ONE;
    flEntry->TimeStamp = Dem_Internal.TimeStampCounter;
    Dem_Internal.TimeStampCounter += DEM_ONE;
    flEntry->FirstFailedCount = 0x0U;
    flEntry->LastFailedCount = 0x0U;
    flEntry->EventMemoryOrigin = Dem_Cfg_EventParameter[EventId].DemOrigin;
    flEntry->EventMemoryEntryCounter = flMemIterIndex;
    if (Dem_MemStatus[flMemIterIndex].ValueofLowprioDTC < Dem_Cfg_EventParameter[EventId].Priority)
    {
      Dem_MemStatus[flMemIterIndex].ValueofLowprioDTC = Dem_Cfg_EventParameter[EventId].Priority;
      Dem_MemStatus[flMemIterIndex].LowprioEventId = EventId;
      Dem_MemStatus[flMemIterIndex].IndexofLowprioDTC = flIndex;
      Dem_MemStatus[flMemIterIndex].TestFailedDTC = DEM_GET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[EventId]);
    }
    Dem_MemStatus[flMemIterIndex].NoofstoredDTC += DEM_ONE;
    #if (DemMaxNumberFreezeFrameRecords > 0)
    ref = Dem_Cfg_EventParameter[EventId].DTCTableRef;
    #if (DemDevAdditionalCoverityChecks == TRUE)
    if (ref <= Dem_Cfg_Num_Of_DTC)
    #endif
    {
      flFFAttributeTableRef = Dem_Cfg_DTC[ref].AttrbsRef;
      if ((flFFAttributeTableRef <= Dem_Cfg_Num_Of_DTC) && (FALSE != Dem_Cfg_DTCAttributes[flFFAttributeTableRef].FreezeFrameRecordSupported))
      {
        #if(DemTypeofFreezeFrameRecordNumeration == DEM_FF_RECNUM_CONFIGURED)
        flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flFFAttributeTableRef].FreezeFrameRecNumClassRef;
        #else
        flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flFFAttributeTableRef].FreezeFrameClassRef;
        #endif
        Dem_InternalUpdateFreezeFrameData(EventId, flEntry, flFreezeFrameRecNumClassRef);
      }
    }
    #endif
    #if (DEM_NUM_OF_EXTENDEDRECORD > 0)
    ref = Dem_Cfg_EventParameter[EventId].DTCTableRef;
    #if (DemDevAdditionalCoverityChecks == TRUE)
    if (ref <= Dem_Cfg_Num_Of_DTC)
    #endif
    {
      AttributeTableRef = Dem_Cfg_DTC[ref].AttrbsRef;
      #if (DemDevAdditionalCoverityChecks == TRUE)
      if ((AttributeTableRef <= Dem_Cfg_Num_Of_DTC) && (FALSE != Dem_Cfg_DTCAttributes[AttributeTableRef].ExtDataRecordSupported))
      #else
      if (FALSE != Dem_Cfg_DTCAttributes[AttributeTableRef].ExtDataRecordSupported)
      #endif
      {
        ExtRecordTableRef = Dem_Cfg_DTCAttributes[AttributeTableRef].ExtDataRecordContainerRef;
        Dem_InternalUpdateExtRecordData(flEntry, ExtRecordTableRef, EventId);
      }
    }
    #endif
    *flMemIndex = flIndex;
    flReturnVal = E_OK;
    flIndex = Dem_Cfg_Mem_Total_Entry;
  }
  return flReturnVal;
}

/**************************************************************************
 Function name   : Dem_ProcessCreateMemEntry
 Arguments       : Dem_EventIdType EventId,     uint8 *flMemIndex
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to find the free PRAM entry and create new entry into that.
 **************************************************************************/
static Std_ReturnType Dem_ProcessCreateMemEntry(Dem_EventIdType EventId,
                                                uint8 *flMemIndex)
{
  uint8 flIndex;
  uint16 flLowPrioIndex = 0U;
  Std_ReturnType flReturnVal = E_NOT_OK;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint8 flFTstatus;
  boolean flupdateCount = FALSE;


#if (DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
  else
#endif
  {
    switch(Dem_Cfg_EventParameter[EventId].DemOrigin)
    {
      case DEM_DTC_ORIGIN_PRIMARY_MEMORY:
      {
        if (Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].NoofstoredDTC < (Dem_Cfg_Mem_Total_Primary_Entry))
        {
          for (flIndex = Dem_Cfg_Mem_Primary_Entry_Start; flIndex < Dem_Cfg_Mem_Primary_Entry_Stop;
               flIndex++)
          {
            flEntry = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[flIndex];
            flEntry->EventMemoryEntryCounter = DEM_PRIMARY_MEMORY_INDEX;
            if ((flEntry->EventId == DEM_EVENT_INVALID) && (flEntry->TimeStamp == DEM_EVENT_TMSTMP_INVALID))
            {
              flReturnVal = Dem_CreateMemEntry(EventId, flIndex, DEM_PRIMARY_MEMORY_INDEX, flMemIndex);
              flIndex = Dem_Cfg_Mem_Total_Entry;
            }
            else
            {
              if ((Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].NoofstoredDTC == 0U) || (flupdateCount == TRUE))
              {
                flupdateCount = TRUE;
                Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].NoofstoredDTC += DEM_ONE;
              }
            }
          }
        } // if (Dem_MemStatus.NoofstoredDTC < Dem_Cfg_Mem_Total_Entry )
        else
        {
          Dem_Cfg_StatusData.MemoryOverflow[DEM_PRIMARY_MEMORY_INDEX] = TRUE;
          if ( (Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].ValueofLowprioDTC >= Dem_Cfg_EventParameter[EventId].Priority) && (Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].TestFailedDTC != 0U))
          {
            for (flIndex = Dem_Cfg_Mem_Primary_Entry_Start; flIndex < Dem_Cfg_Mem_Primary_Entry_Stop;
                 flIndex++)
            {
              flEntry = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[flIndex];
              flEntry->EventMemoryEntryCounter = DEM_PRIMARY_MEMORY_INDEX;
              if (Dem_Cfg_EventParameter[flEntry->EventId].Priority == Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].ValueofLowprioDTC)
              {

                flFTstatus = DEM_GET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[flEntry->EventId]);
                if (DEM_ONE != flFTstatus)
                {
                  Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].TestFailedDTC = 0U;
                  Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].IndexofLowprioDTC = flIndex;
                  Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].LowprioEventId  = flEntry->EventId;
                }
              }
            }
          }
          if (Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].ValueofLowprioDTC > Dem_Cfg_EventParameter[EventId].Priority)
          {
            flLowPrioIndex = Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].IndexofLowprioDTC;
            Dem_ProcessDeleteMemEntry(Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].IndexofLowprioDTC, DEM_PRIMARY_MEMORY_INDEX);
            flReturnVal = Dem_CreateMemEntry(EventId,flLowPrioIndex,DEM_PRIMARY_MEMORY_INDEX,flMemIndex);
          }
          else if (Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].ValueofLowprioDTC == Dem_Cfg_EventParameter[EventId].Priority)
          {
            if (Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].TestFailedDTC == 0)
            {
              flLowPrioIndex = Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].IndexofLowprioDTC;
              Dem_ProcessDeleteMemEntry(Dem_MemStatus[DEM_PRIMARY_MEMORY_INDEX].IndexofLowprioDTC, DEM_PRIMARY_MEMORY_INDEX);
              flReturnVal = Dem_CreateMemEntry(EventId,flLowPrioIndex,DEM_PRIMARY_MEMORY_INDEX,flMemIndex);
            }
          }
          else
          {
            /*do nothing*/
          }
        }
      }
      break;

      case DEM_DTC_ORIGIN_USER_MEMORY:
      {
        if (Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].NoofstoredDTC < (Dem_Cfg_Mem_Total_Entry))
        {
          for (flIndex = Dem_Cfg_Mem_UserDefined_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry;
               flIndex++)
          {
            flEntry = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[flIndex];
            flEntry->EventMemoryEntryCounter = DEM_SECONDARY_MEMORY_INDEX;
            if ((flEntry->EventId == DEM_EVENT_INVALID) && (flEntry->TimeStamp == DEM_EVENT_TMSTMP_INVALID))
            {
              flReturnVal = Dem_CreateMemEntry(EventId,flIndex, DEM_SECONDARY_MEMORY_INDEX, flMemIndex);
              flIndex = Dem_Cfg_Mem_Total_Entry;
            }
            else
            {
              if ((Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].NoofstoredDTC == 0U) || (flupdateCount == TRUE))
              {
                flupdateCount = TRUE;
                Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].NoofstoredDTC += DEM_ONE;
              }
            }
          }
        } // if (Dem_MemStatus.NoofstoredDTC < Dem_Cfg_Mem_Total_Entry )
        else
        {
          Dem_Cfg_StatusData.MemoryOverflow[DEM_SECONDARY_MEMORY_INDEX] = TRUE;
          if ( (Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].ValueofLowprioDTC >= Dem_Cfg_EventParameter[EventId].Priority) && (Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].TestFailedDTC != 0U))
          {
            for (flIndex = Dem_Cfg_Mem_UserDefined_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry;
                 flIndex++)
            {
              flEntry = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[flIndex];
              flEntry->EventMemoryEntryCounter = DEM_SECONDARY_MEMORY_INDEX;
              if (Dem_Cfg_EventParameter[flEntry->EventId].Priority == Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].ValueofLowprioDTC)
              {
                flFTstatus = DEM_GET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[flEntry->EventId]);
                if (DEM_ONE != flFTstatus)
                {
                  Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].TestFailedDTC = 0U;
                  Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].IndexofLowprioDTC = flIndex;
                  Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].LowprioEventId  = flEntry->EventId;
                }
              }
            }
          }
          if (Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].ValueofLowprioDTC > Dem_Cfg_EventParameter[EventId].Priority)
          {
            flLowPrioIndex = Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].IndexofLowprioDTC;
            Dem_ProcessDeleteMemEntry(Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].IndexofLowprioDTC, DEM_SECONDARY_MEMORY_INDEX);
            flReturnVal = Dem_CreateMemEntry(EventId,flLowPrioIndex,DEM_SECONDARY_MEMORY_INDEX,flMemIndex);
          }
          else if (Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].ValueofLowprioDTC == Dem_Cfg_EventParameter[EventId].Priority)
          {
            if (Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].TestFailedDTC == 0)
            {
               flLowPrioIndex = Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].IndexofLowprioDTC;
               Dem_ProcessDeleteMemEntry(Dem_MemStatus[DEM_SECONDARY_MEMORY_INDEX].IndexofLowprioDTC, DEM_SECONDARY_MEMORY_INDEX);
               flReturnVal = Dem_CreateMemEntry(EventId,flLowPrioIndex,DEM_SECONDARY_MEMORY_INDEX, flMemIndex);
            }
          }
          else
          {
               /*do nothing*/
          }
        }
      }
      break;

      default:
      break;
    }
  }
  return flReturnVal;
}

/**************************************************************************
 Function name   : Dem_ProcessUpdateMemEntry
 Arguments       : Dem_EventIdType EventId, boolean IsPassed, uint8 *flMemIndex
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to find the existing entry from reported EventId and
                   update that entry with latest time stamp value.
 **************************************************************************/
static Std_ReturnType Dem_ProcessUpdateMemEntry(Dem_EventIdType EventId, boolean IsPassed,
                                                uint8 *flMemIndex)
{
  uint8 flIndex;
  uint8 flMemIterIndex;
  Std_ReturnType flReturnVal = E_NOT_OK;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
#if (DemMaxNumberFreezeFrameRecords > 0) || (DEM_NUM_OF_EXTENDEDRECORD > 0)
  uint8 ref;
#endif
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
  uint8 AttributeTableRef;
  uint8 ExtRecordTableRef;
#endif
#if (DemMaxNumberFreezeFrameRecords > 0)
  uint8 flFFAttributeTableRef;
  uint8 flFreezeFrameRecNumClassRef;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    /* Find New Free index */
    for (flIndex = Dem_Cfg_Mem_Primary_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry;
        flIndex++)
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flIndex];
      flMemIterIndex = flEntry -> EventMemoryEntryCounter;
      if (flEntry->EventId == EventId)
      {
        if ((Dem_MemStatus[flMemIterIndex].LowprioEventId == EventId) && (Dem_MemStatus[flMemIterIndex].IndexofLowprioDTC == flIndex))
        {
          Dem_MemStatus[flMemIterIndex].TestFailedDTC = DEM_GET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[EventId]);
        }
        flEntry->AgingCounter = DEM_DTC_AGING_INVALID;
        /* If occurrence counter reached threshold, No need to put NVM entry */
        if((flEntry->OccurrenceCounter < DEM_OCCURRENCE_COUNTER_THRESHOLD) && (FALSE != IsPassed))
        {
          flEntry->OccurrenceCounter = flEntry->OccurrenceCounter + DEM_ONE;
          flEntry->TimeStamp = Dem_Internal.TimeStampCounter;
          /* CERT C fix 17224939 */
          if(Dem_Internal.TimeStampCounter < DEM_0xFFFF)
          {
            Dem_Internal.TimeStampCounter = Dem_Internal.TimeStampCounter + DEM_ONE;
          }

          flEntry->LastFailedCount = 0x00U;
#if (DemMaxNumberFreezeFrameRecords > 0)
          ref = Dem_Cfg_EventParameter[EventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
          if(ref <= Dem_Cfg_Num_Of_DTC)
#endif
          {
            flFFAttributeTableRef = Dem_Cfg_DTC[ref].AttrbsRef;
            if((flFFAttributeTableRef <= Dem_Cfg_Num_Of_DTC) && (FALSE != Dem_Cfg_DTCAttributes[flFFAttributeTableRef].FreezeFrameRecordSupported))
            {
              #if(DemTypeofFreezeFrameRecordNumeration == DEM_FF_RECNUM_CONFIGURED)
              flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flFFAttributeTableRef].FreezeFrameRecNumClassRef;
              #else
              flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flFFAttributeTableRef].FreezeFrameClassRef;
              #endif
              Dem_InternalUpdateFreezeFrameData(EventId, flEntry, flFreezeFrameRecNumClassRef);
            }
          }
#endif
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
          ref = Dem_Cfg_EventParameter[EventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
          if(ref <= Dem_Cfg_Num_Of_DTC)
#endif
          {
            AttributeTableRef = Dem_Cfg_DTC[ref].AttrbsRef;
            if((AttributeTableRef <= Dem_Cfg_Num_Of_DTC) && (FALSE != Dem_Cfg_DTCAttributes[AttributeTableRef].ExtDataRecordSupported))
            {
              ExtRecordTableRef = Dem_Cfg_DTCAttributes[AttributeTableRef].ExtDataRecordContainerRef;
              Dem_InternalUpdateExtRecordData(flEntry, ExtRecordTableRef, EventId);
            }
          }
#endif
          *flMemIndex = flIndex;
          flReturnVal = E_OK;
        }
        flIndex = Dem_Cfg_Mem_Total_Entry;
      }
    }
  }
  return flReturnVal;
}

/**************************************************************************
 Function name   : Dem_ProcessDeleteMemEntry
 Arguments       : uint8 *flMemIndex
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Used to delete the reported entry from PRAM and trigger the NV storage.
 **************************************************************************/
static void Dem_ProcessDeleteMemEntry(uint8 flMemIndex, uint8 flMemIterIndex)
{
  boolean flprioCheckNeed = FALSE;
  uint16 flIndex = 0U;
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
  uint8 AttributeTableRef;
  uint8 ExtRecordRowIndex;
  uint8 ExtRecordSizeIndex;
#endif
#if (DemMaxNumberFreezeFrameRecords > 0)
  uint8 FFRecordRowIndex;
  uint8 FFRecordSizeIndex;
#endif
  Dem_Cfg_PrimaryMemEntryType *flEntry;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (flMemIndex >= Dem_Cfg_Mem_Total_Entry)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dem_EnterCriticalSection();
    flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
#if(DemDevAdditionalCoverityChecks == TRUE)
    if(flEntry->EventId < Dem_Cfg_Num_Of_Event)
#endif
    {
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(Dem_Cfg_EventParameter[flEntry->EventId].DTCTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
      {
        if (Dem_MemStatus[flMemIterIndex].ValueofLowprioDTC == Dem_Cfg_EventParameter[flEntry->EventId].Priority)
        {
          if (Dem_MemStatus[flMemIterIndex].IndexofLowprioDTC == flMemIndex)
          {
            Dem_MemStatus[flMemIterIndex].ValueofLowprioDTC = 0u;
            Dem_MemStatus[flMemIterIndex].IndexofLowprioDTC = Dem_Cfg_Mem_Total_Entry + DEM_ONE;
            flprioCheckNeed = TRUE;
          }
        }

        if (Dem_MemStatus[flMemIterIndex].NoofstoredDTC > 0)
        {
          Dem_MemStatus[flMemIterIndex].NoofstoredDTC -= DEM_ONE;
        }
#if (DEM_NUM_OF_EXTENDEDRECORD > 0)
        AttributeTableRef = Dem_Cfg_DTC[Dem_Cfg_EventParameter[flEntry->EventId].DTCTableRef].AttrbsRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
        if(AttributeTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
        {
          if (FALSE != Dem_Cfg_DTCAttributes[AttributeTableRef].ExtDataRecordSupported)
          {
            for (ExtRecordRowIndex = 0;  ExtRecordRowIndex < DEM_NUM_OF_EXTENDEDRECORD; ExtRecordRowIndex++)
            {
              for (ExtRecordSizeIndex = 0; ExtRecordSizeIndex < DEM_MAX_LENGTH_OF_EXTENDEDRECORD; ExtRecordSizeIndex++)
              {
                flEntry->ExtendedDataRecord[ExtRecordRowIndex][ExtRecordSizeIndex] = DEM_EXT_REC_DATA_INVALID;
              }
            }
          }
        }
#endif
      }
#if (DemMaxNumberFreezeFrameRecords > 0)
      /*Init FFRecordData*/
      for (FFRecordRowIndex = 0;  FFRecordRowIndex < DemMaxNumberFreezeFrameRecords; FFRecordRowIndex++)
      {
        for (FFRecordSizeIndex = 0; FFRecordSizeIndex < DemMaxLengthFreezeFrameData; FFRecordSizeIndex++)
        {
          flEntry->SnapshotData[FFRecordRowIndex][FFRecordSizeIndex] = DEM_FREEZE_FRAME_INVALID;
        }
      }
      flEntry->SnahpshotHeader = 0x0U;
#endif
      Dem_Event.DebounceValue[flEntry->EventId] = 0x00U;

      Dem_InternalSetEventStatus(flEntry->EventId, DEM_EVENT_STATUS_NONE);
      Dem_InternalSetDebounceStatus(flEntry->EventId, DEM_EVENT_DEBOUNCE_STATUS_NONE);

      if(FALSE != DEM_EVENT_GET_QUEUE_STATUS_PENDING(Dem_Event.QueueStatus[flEntry->EventId]))
      {
        DEM_EVENT_RESET_QUEUE_STATUS_PENDING(Dem_Event.QueueStatus[flEntry->EventId]);
        /*CERT C fix 17225336*/
        if(Dem_Event.QueueCount > 0u)
        {
          Dem_Event.QueueCount = Dem_Event.QueueCount - DEM_ONE;
        }
      }

      flEntry->EventId = DEM_EVENT_INVALID;
      flEntry->AgingCounter = DEM_DTC_AGING_INVALID;
      flEntry->OccurrenceCounter = DEM_EVENT_OCCNTR_INVALID;
      flEntry->TimeStamp = DEM_EVENT_TMSTMP_INVALID;
      flEntry->FirstFailedCount = 0x0U;
      flEntry->LastFailedCount = 0x0U;
      flEntry->EventMemoryOrigin = DEM_DTC_ORIGIN_INVALID;
      flEntry->EventMemoryEntryCounter = 0x0u;

      if (Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] == DEM_MEM_STATUS_NONE)
      {
        /* CERT C fix 17224940 */
        if(Dem_NvmWriteData.PendingCount < DEM_0xFF)
        {
          Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + DEM_ONE;
        }
      }
      Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] = DEM_MEM_STATUS_TRIGGER_CLEAR;

      if (Dem_Event.InternalMemStatus[flMemIndex] == DEM_MEM_STATUS_NONE)
      {
        Dem_NvmWriteData.PendingCount += DEM_ONE;
      }
      Dem_Event.InternalMemStatus[flMemIndex] = DEM_MEM_STATUS_TRIGGER_CLEAR;
    }
    Dem_ExitCriticalSection();

    if (TRUE == flprioCheckNeed)
    {
      for (flIndex = Dem_Cfg_Mem_Primary_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry;
           flIndex++)
      {
        flEntry = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[flIndex];
        if ((flEntry->EventId != DEM_EVENT_INVALID) && (flEntry->TimeStamp != DEM_EVENT_TMSTMP_INVALID))
        {
          if (Dem_MemStatus[flMemIterIndex].ValueofLowprioDTC < Dem_Cfg_EventParameter[flEntry->EventId].Priority)
          {
            Dem_MemStatus[flMemIterIndex].ValueofLowprioDTC = Dem_Cfg_EventParameter[flEntry->EventId].Priority;
            Dem_MemStatus[flMemIterIndex].IndexofLowprioDTC = flIndex;
            Dem_MemStatus[flMemIterIndex].LowprioEventId = flEntry->EventId;
            Dem_MemStatus[flMemIterIndex].TestFailedDTC = DEM_GET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[flEntry->EventId]);
            Dem_MemStatus[flMemIterIndex].EventOrigin = Dem_Cfg_EventParameter[flEntry->EventId].DemOrigin;
            Dem_MemStatus[flMemIterIndex].MemoryIndex = flMemIterIndex;
            Dem_MemStatus[flMemIterIndex].OverflowIndication = FALSE;
          }
        }
      }
    }
  }
}

/**************************************************************************
 Function name   : Dem_ProcessOperationCycleQueue
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing of Operation Cycle state change requested queue.
 **************************************************************************/
static void Dem_ProcessOperationCycleQueue(void)
{
  uint8 flIter;
  boolean flOldStatus;
  boolean flNewStatus;

  for (flIter = 0; flIter < Dem_Cfg_Num_Of_OpCycle; flIter++)
  {
    if (FALSE != DEM_GET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, flIter))
    {
      DEM_RESET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, flIter);
      flOldStatus = DEM_GET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.State, flIter);
      flNewStatus = DEM_GET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState, flIter);

      if (FALSE != flNewStatus)
      {
        if (flOldStatus == flNewStatus)
        {
          /* Trigger the operations for Operation cycle Re-Starting */
          Dem_ProcessOperationCycleStateChange(flIter, DEM_OPERATION_QUEUE_CYCLE_RESTARTED);
        }
        else
        {
          /* Trigger the operations for Operation cycle Starting */
          Dem_ProcessOperationCycleStateChange(flIter, DEM_OPERATION_QUEUE_CYCLE_STARTED);
        }

      }
      else
      {
        if (flOldStatus != flNewStatus)
        {
          /* Trigger the operations for Operation cycle Stops */
          Dem_ProcessOperationCycleStateChange(flIter, DEM_OPERATION_QUEUE_CYCLE_STOPED);
        }
      }
    }
  }
}

/**************************************************************************
 Function name   : Dem_ProcessOperationCycleStateChange
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the action item for operation cycle state changes.
 **************************************************************************/
static void Dem_ProcessOperationCycleStateChange(uint8 CycleId, uint8 CycleStatus)
{
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  Dem_EventIdType flEventId;
  Dem_UdsStatusByteType flNewUdsEventStatus;
  Dem_UdsStatusByteType flOldUdsEventStatus;
  uint8 flDtcAttributeTableRef;
  uint8 flMemIndex;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if(CycleId >= Dem_Cfg_Num_Of_OpCycle)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    DEM_RESET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.State, CycleId);
    if (DEM_OPERATION_QUEUE_CYCLE_STOPED != CycleStatus)
    {
      /* CERT C fix 17226063 0521 */
      if(Dem_Cfg_OpCycle.Counter[CycleId] < DEM_0xFFFF )
      {
        Dem_Cfg_OpCycle.Counter[CycleId] = Dem_Cfg_OpCycle.Counter[CycleId] + DEM_ONE;
      }
      else
      {
        /* Handle Error */
      }
      /* Trigger Operation Cycle counter storage */
      if ((Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Admin_Index] == DEM_MEM_STATUS_NONE) && (Dem_NvmWriteData.PendingCount < DEM_UINT_8_MAX)) /*Cert-c 17224123*/
      {
        Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + DEM_ONE;
      }
      Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Admin_Index] = DEM_MEM_STATUS_TRIGGER_STORAGE;
    }

    for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
    {
      flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[flEventId];
      flNewUdsEventStatus = flOldUdsEventStatus;

      flDtcAttributeTableRef = Dem_Cfg_DTC[Dem_Cfg_EventParameter[flEventId].DTCTableRef].AttrbsRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(flDtcAttributeTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
      {
        if (CycleId == Dem_Cfg_EventParameter[flEventId].OpCycleRef)
        {
          Dem_EnterCriticalSection();
          Dem_Event.DebounceValue[flEventId] = 0x0U;
          Dem_InternalSetDebounceStatus(flEventId, DEM_EVENT_DEBOUNCE_STATUS_NONE);
          Dem_ExitCriticalSection();
          /* Do The Stop Cycle Activity */
          if (DEM_OPERATION_QUEUE_CYCLE_STARTED != CycleStatus)
          {
            for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start; flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
            {
              flEntry = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[flMemIndex];
              if (flEntry->EventId == flEventId)
              {
                /* SWS_Dem_00777 */
                if (flEntry->FirstFailedCount < DEM_0xFF)
                {
                  flEntry->FirstFailedCount += DEM_ONE;
                }
                /* SWS_Dem_00773 */
                if (flEntry->LastFailedCount < DEM_0xFF)
                {
                  flEntry->LastFailedCount += DEM_ONE;
                }
                break;
              }
            }
            if(   (FALSE == DEM_GET_UDS_STATUS_BYTE_TFTMC(flOldUdsEventStatus))
               && (FALSE == DEM_GET_UDS_STATUS_BYTE_TNCTMC(flOldUdsEventStatus)))
            {
              DEM_RESET_UDS_STATUS_BYTE_PDTC(flNewUdsEventStatus);
              if (DEM_EVENT_STATUS_NONE != Dem_InternalGetEventStatus(flEventId))
              {
                Dem_ProcessEventAging(flEventId, CycleId);
              }
            }
          }
          /* If event deleted due to aging then re-store status again */
          if(Dem_Cfg_StatusData.EventStatus[flEventId] == DEM_UDS_STATUS_DEFAULT)
          {
            flNewUdsEventStatus = Dem_Cfg_StatusData.EventStatus[flEventId];
          }
          /* Do The Start Cycle Activity */
          if (DEM_OPERATION_QUEUE_CYCLE_STOPED != CycleStatus)
          {
            /* New operation cycle started, Restore the UDS status for new OpCycle*/
            DEM_RESET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
            DEM_RESET_UDS_STATUS_BYTE_WIR(flNewUdsEventStatus);
            DEM_RESET_UDS_STATUS_BYTE_TFTMC(flNewUdsEventStatus);
            DEM_SET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);

            if (NULL != Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE)
            {
              (void)Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE(DEM_INIT_MONITOR_RESTART); /*MISRA FIX*/
            }
          }
          if(flOldUdsEventStatus != flNewUdsEventStatus)
          {
            Dem_Cfg_StatusData.EventStatus[flEventId] = flNewUdsEventStatus;
            if(   (Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] == DEM_MEM_STATUS_NONE)
               && (Dem_NvmWriteData.PendingCount < DEM_UINT_8_MAX)) /*Cert-c 17224123*/
            {
              Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + DEM_ONE;
            }
            Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] = DEM_MEM_STATUS_TRIGGER_STORAGE;
          }
        }
        else if (CycleId == Dem_Cfg_DTCAttributes[flDtcAttributeTableRef].AgingOpCycleRef)
        {
          /* Do The Stop Cycle Activity */
          if (DEM_OPERATION_QUEUE_CYCLE_STARTED != CycleStatus)
          {
            if(   (FALSE == DEM_GET_UDS_STATUS_BYTE_TFTMC(flOldUdsEventStatus))
               && (FALSE == DEM_GET_UDS_STATUS_BYTE_TNCTMC(flOldUdsEventStatus)))
            {
              if (DEM_EVENT_STATUS_NONE != Dem_InternalGetEventStatus(flEventId))
              {
                Dem_ProcessEventAging(flEventId, CycleId);
              }
            }
          }
        }
        else
        {
          // do nothing
        }
      }
    }
    if (CycleStatus != DEM_OPERATION_QUEUE_CYCLE_STOPED)
    {
      DEM_SET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.State, CycleId);
    }
  }
}

/**************************************************************************
 Function name   : Dem_ProcessEventAging
 Arguments       : Dem_EventIdType flEventId, uint8 CycleId
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does qualifying process on stored event entry for event aging.
 **************************************************************************/
static void Dem_ProcessEventAging(Dem_EventIdType flEventId, uint8 CycleId)
{
  uint8 flMemIndex;
  uint8 flMemIterIndex;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint8 flDtcAttributeTableRef;
  uint8 flOldUdsEventStatus;
  uint8 flNewUdsEventStatus;

#if(DemDevAdditionalCoverityChecks == TRUE)
  if((flEventId < Dem_Cfg_Num_Of_Event) && (Dem_Cfg_EventParameter[flEventId].DTCTableRef <= Dem_Cfg_Num_Of_DTC))
#endif
  {
    flDtcAttributeTableRef = Dem_Cfg_DTC[Dem_Cfg_EventParameter[flEventId].DTCTableRef].AttrbsRef;

#if(DemDevAdditionalCoverityChecks == TRUE)
    if(flDtcAttributeTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
    {
      if ((FALSE != Dem_Cfg_DTCAttributes[flDtcAttributeTableRef].AgingAllowed)
          && (CycleId == Dem_Cfg_DTCAttributes[flDtcAttributeTableRef].AgingOpCycleRef))
      {
        for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start;
            flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
        {
          flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
          flMemIterIndex = flEntry->EventMemoryEntryCounter;
          if (flEntry->EventId == flEventId)
          {
            /* Aging can be started with test pass result */
            flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[flEventId];
            flNewUdsEventStatus = flOldUdsEventStatus;
            if(FALSE == DEM_GET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus))
            {
              if (DEM_EVENT_STATUS_AGING != Dem_InternalGetEventStatus(flEventId))
              {
                Dem_InternalSetEventStatus(flEventId, DEM_EVENT_STATUS_AGING);
              }

              if (DEM_EVENT_STATUS_AGING == Dem_InternalGetEventStatus(flEventId))
              {
                flEntry->AgingCounter += DEM_ONE;
                if(flEntry->AgingCounter >= Dem_Cfg_DTCAttributes[flDtcAttributeTableRef].AgingThershold)
                {
                  DEM_RESET_UDS_STATUS_BYTE_CDTC(flNewUdsEventStatus);
                  if(DemStatusBitHandlingTestFailedSinceLastClear != DEM_STATUS_BIT_NORMAL)
                  {
                    DEM_RESET_UDS_STATUS_BYTE_TFSLC(flNewUdsEventStatus);
                  }
                  Dem_ProcessDeleteMemEntry(flMemIndex, flMemIterIndex);
                }
              }
            }
            if(flOldUdsEventStatus != flNewUdsEventStatus)
            {
              Dem_Cfg_StatusData.EventStatus[flEventId] = flNewUdsEventStatus;
            }
            if (Dem_Event.InternalMemStatus[flMemIndex] == DEM_MEM_STATUS_NONE)
            {
              Dem_NvmWriteData.PendingCount += DEM_ONE;
            }
            Dem_Event.InternalMemStatus[flMemIndex] = DEM_MEM_STATUS_TRIGGER_STORAGE;
            flMemIndex = Dem_Cfg_Mem_Total_Entry;
          }
        }
      }
    }
  }
}

/**************************************************************************
 Function name   : Dem_ProcessInitMForEventAll
 Arguments       : Dem_InitMonitorReasonType flInitMReason
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does Callback the all configured monitor components for event enable or
 re-enable condition.
 **************************************************************************/
static void Dem_ProcessInitMForEventAll(Dem_InitMonitorReasonType flInitMReason)
{
  Dem_EventIdType flEventId;

  for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event;
      flEventId++)
  {
    if (NULL != Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE)
    {
      (void) Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE(flInitMReason);
    }
  }
}

/**************************************************************************
 Function name   : Dem_InternalFreezeOrResetDebounceStatus
 Arguments       : Dem_EventIdType flEventId
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Reset or Freeze the internal event debounce status.
 **************************************************************************/
static void Dem_InternalFreezeOrResetDebounceStatus(Dem_EventIdType flEventId)
{
  uint8 flDebounceTableRef;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (flEventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flDebounceTableRef = Dem_Cfg_EventParameter[flEventId].DebounceTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
    if(flDebounceTableRef < Dem_Cfg_Num_Of_DebounceTable)
#endif
    {
      Dem_EnterCriticalSection();
      if (DEM_CFG_DEBOUNCETYPE_TIMER == Dem_Cfg_DebounceTable[flDebounceTableRef].AlgoClass)
      {
        if (Dem_Cfg_DebounceTable[flDebounceTableRef].behavior == DEM_DEBOUNCE_RESET)
        {
          Dem_Event.DebounceValue[flEventId] = 0U;
          Dem_InternalSetDebounceStatus(flEventId, DEM_EVENT_DEBOUNCE_STATUS_NONE);
        }
        else
        {
          switch (Dem_InternalGetDebounceStatus(flEventId))
          {
            case DEM_EVENT_DEBOUNCE_STATUS_PASSED:
            case DEM_EVENT_DEBOUNCE_STATUS_HEAL_RESET:
            case DEM_EVENT_DEBOUNCE_STATUS_HEALING:
              Dem_InternalSetDebounceStatus(flEventId, DEM_EVENT_DEBOUNCE_FREEZE_HEAL_STATUS);
              break;
            case DEM_EVENT_DEBOUNCE_STATUS_FAILED:
            case DEM_EVENT_DEBOUNCE_STATUS_FAILING:
            case DEM_EVENT_DEBOUNCE_STATUS_FAIL_RESET:
              Dem_InternalSetDebounceStatus(flEventId, DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL);
              break;
            default:
              break;
          }
        }
      }
      else
      { /* No Freeze for counter based algo */
        Dem_Event.DebounceValue[flEventId] = 0U;
      }
      Dem_ExitCriticalSection();
    }
  }
}

/**************************************************************************
 Function name   : Dem_ProcessDtcEnableCondition
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does processing of action item has to taken for DTC storage setting
 enabled / disabled condition.
 **************************************************************************/
static void Dem_ProcessDtcEnableCondition(void)
{
  Dem_EventIdType flEventId;
  uint8 flMemInex;
  if ((Dem_Internal.DtcSettingEnCondition == DEM_DTC_STORAGE_SETTING_ENABLED)
      || (Dem_Internal.DtcSettingEnConditionQueue == DEM_DTC_STORAGE_SETTING_ENABLED))
  {
    if (Dem_Internal.DtcSettingEnConditionQueue == DEM_DTC_STORAGE_SETTING_DISABLED)
    {
      /* Reset De-bounce and internal status */
      for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
      {
        Dem_InternalFreezeOrResetDebounceStatus(flEventId);
        DEM_EVENT_RESET_QUEUE_STATUS_PENDING(Dem_Event.QueueStatus[flEventId]);
        DEM_EVENT_RESET_QUEUE_STATUS_FAILED(Dem_Event.QueueStatus[flEventId]);
        DEM_EVENT_RESET_QUEUE_STATUS_PASSED(Dem_Event.QueueStatus[flEventId]);
      }
      Dem_Event.QueueCount = 0x00U;

      for (flMemInex = Dem_Cfg_Mem_Entry_Start;
          flMemInex < Dem_Cfg_Mem_Primary_Entry_Stop; flMemInex++)
      {
        if (Dem_Event.InternalMemStatus[flMemInex] != DEM_MEM_STATUS_NONE)
        {
          Dem_Event.InternalMemStatus[flMemInex] = DEM_MEM_STATUS_NONE;
          if (0U != Dem_NvmWriteData.PendingCount) /*Cert-c 17224244*/
          {
            Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount - DEM_ONE;
          }
        }
      }
    }
    else if (Dem_Internal.DtcSettingEnCondition == DEM_DTC_STORAGE_SETTING_ENABLED)
    {
            /*SWS_Dem_00682*/
            Dem_ProcessInitMForEventAll (DEM_INIT_MONITOR_REENABLED);
    }
    else
    {
      /*DoNothing*/
    }
    Dem_EnterCriticalSection();
    Dem_Internal.DtcSettingEnCondition = Dem_Internal.DtcSettingEnConditionQueue;
    Dem_ExitCriticalSection();
  }
}

/**************************************************************************
 Function name   : Dem_ProcessQualifiedQueuedEvents
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does processing of checking queued qualified result and takes necessary
 action
 **************************************************************************/
static void Dem_ProcessQualifiedQueuedEvents(void)
{
  Dem_EventIdType EventId;
  uint8 flReturnVal;
  uint8 flMemIndex = 0;
  uint8 lQueueStatus;
  uint8 lQueueCount;
  boolean IsPassed = FALSE;
  uint8 flNewUdsEventStatus;
  uint8 flOldUdsEventStatus;
  uint8 flDTCTableRef;
  flReturnVal = E_NOT_OK;
  lQueueCount = Dem_Event.QueueCount;
  for (EventId = DEM_EVENT_VALID_ID_START; EventId < Dem_Cfg_Num_Of_Event; EventId++)
  {
    lQueueStatus = Dem_Event.QueueStatus[EventId];
    if (FALSE != DEM_EVENT_GET_QUEUE_STATUS_PENDING(lQueueStatus))
    {
      if(FALSE != DEM_EVENT_GET_QUEUE_STATUS_FAILED(lQueueStatus))
      {
        if((DEM_ONE << DemEventMemoryEntryStorageTrigger) & Dem_Cfg_StatusData.EventStatus[EventId])
        {
          if (DEM_EVENT_STATUS_NONE == Dem_InternalGetEventStatus(EventId))
          {
            flReturnVal = Dem_ProcessCreateMemEntry(EventId, &flMemIndex);
          }
          else
          {
            if ((FALSE != DEM_EVENT_GET_QUEUE_STATUS_ISPASSED(lQueueStatus)) || (Dem_Cfg_StatusData.EventStatus[EventId] & DEM_UDS_STATUS_MASK_CDTC))
            {
              IsPassed = TRUE;
            }
            flReturnVal = Dem_ProcessUpdateMemEntry(EventId, IsPassed, &flMemIndex);
          }

#if(DemDevAdditionalCoverityChecks == TRUE)
          if((flReturnVal == E_OK) && (flMemIndex < Dem_Cfg_Mem_Total_Entry))
#else
          if(flReturnVal == E_OK)
#endif
          {
            if (Dem_Event.InternalMemStatus[flMemIndex] == DEM_MEM_STATUS_NONE)
            {
              Dem_NvmWriteData.PendingCount += DEM_ONE;
            }
            Dem_Event.InternalMemStatus[flMemIndex] = DEM_MEM_STATUS_TRIGGER_STORAGE;
            Dem_InternalSetEventStatus(EventId, DEM_EVENT_STATUS_TRIGGERED);
          }
          DEM_EVENT_RESET_QUEUE_STATUS_FAILED(lQueueStatus);
          DEM_EVENT_RESET_QUEUE_STATUS_ISPASSED(lQueueStatus);
        }
        if(   (Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] == DEM_MEM_STATUS_NONE)
           && (Dem_NvmWriteData.PendingCount < DEM_UINT_8_MAX))
        {
          Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + DEM_ONE;
        }
        Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] = DEM_MEM_STATUS_TRIGGER_STORAGE;
        flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[EventId];
        flNewUdsEventStatus = flOldUdsEventStatus;
        DEM_SET_UDS_STATUS_BYTE_PDTC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_CDTC(flNewUdsEventStatus);
        if((FALSE != DEM_GET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus)) && (FALSE != Dem_Cfg_DTCAttributes[EventId].WIR_Supported))
        {
            DEM_SET_UDS_STATUS_BYTE_WIR(flNewUdsEventStatus);
        }
        if(flNewUdsEventStatus != flOldUdsEventStatus)
        {
          Dem_Cfg_StatusData.EventStatus[EventId] = flNewUdsEventStatus;
        }

#if(DemTriggerDcmReports == STD_ON)
        flDTCTableRef = Dem_Cfg_EventParameter[EventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
        if(flDTCTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
        {
          if(DTCStatusChangeNotification != FALSE)
          {
            (void)Dcm_DemTriggerOnDTCStatus(Dem_Cfg_DTC[flDTCTableRef].Value,
                                      flOldUdsEventStatus, flNewUdsEventStatus); /*MISRA FIX*/
          }
        }
#endif
      }
      else if (FALSE != DEM_EVENT_GET_QUEUE_STATUS_PASSED(lQueueStatus))
      {
        if (DEM_EVENT_STATUS_NONE != Dem_InternalGetEventStatus(EventId))
        {
          /* Aging related activities ? */
          DEM_EVENT_RESET_QUEUE_STATUS_PASSED(lQueueStatus);
          DEM_EVENT_SET_QUEUE_STATUS_ISPASSED(lQueueStatus);
        }
        if (Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] == DEM_MEM_STATUS_NONE && Dem_NvmWriteData.PendingCount < DEM_UINT_8_MAX)
        {
          Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount + 1U;
        }
        Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] = DEM_MEM_STATUS_TRIGGER_STORAGE;
      }
      else
      {
         /*DoNothing*/
      }
      DEM_EVENT_RESET_QUEUE_STATUS_PENDING(lQueueStatus);
      Dem_Event.QueueStatus[EventId] = lQueueStatus;
      if (lQueueCount > 0U)
      {
        lQueueCount--;
      }
    }
  }
  Dem_Event.QueueCount = lQueueCount;
}

/**************************************************************************
 Function name   : Dem_ProcessQueuedEvents
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Checks condition prior to process the queues event status
 **************************************************************************/
static void Dem_ProcessQueuedEvents(uint8 Client)
{
  if ((DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition)
      && (Dem_ClearDtc[Client].Req_Status == DEM_DCM_CLEAR_DTC_IDLE))
  {
    Dem_ProcessQualifiedQueuedEvents();
  }
}

/**************************************************************************
 Function name   : Dem_ClearEventAllowed
 Arguments       : Dem_EventIdType EventId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous/Asynchronous
 Reentrancy      :
 EventId.
 Description     :
 **************************************************************************/
static Std_ReturnType Dem_ClearEventAllowed(Dem_EventIdType EventId)
{
  Std_ReturnType RetVal = E_OK;
  boolean ClearAllowed = 0u;
  if((EventId != DEM_EVENT_INVALID) && (EventId < Dem_Cfg_Num_Of_Event))
  {
    uint8 ref = Dem_Cfg_EventParameter[EventId].CBClearEventAllowed;

    if((ref < Dem_Cfg_Num_Of_CBClrEvtAlwd) && (NULL != Dem_Cfg_CBClearEvent[ref].CBClearEventAllowedFunc))
    {
      RetVal = Dem_Cfg_CBClearEvent[ref].CBClearEventAllowedFunc(&ClearAllowed);

      if(ClearAllowed != TRUE)
      {
        RetVal = E_NOT_OK;
      }
    }
  }
  return RetVal;
}

/**************************************************************************
 Function name   : Dem_ProcessClearDtcQueue
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing of clearing event/s entry from PRAM and triggers
 the clearing of entry from NVM upon requested
 **************************************************************************/
static void Dem_ProcessClearDtcQueue(uint8 Client)
{
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint8 flMemIndex;
  uint8 flMemIterIndex;
  uint8 flIndex = 0u;
  boolean conditionclearDtc = TRUE;

  if (Dem_ClearDtc[Client].EventId != DEM_EVENT_INVALID)
  {
    if (DEM_EVENT_STATUS_NONE != Dem_InternalGetEventStatus(Dem_ClearDtc[Client].EventId))
    {
      for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start;
       flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
      {
        flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
        flMemIterIndex = flEntry->EventMemoryEntryCounter;
        #if(DemDevAdditionalCoverityChecks == TRUE)
        if((flEntry->EventId < Dem_Cfg_Num_Of_Event) && (flEntry->EventId == Dem_ClearDtc[Client].EventId))
        #else
        if(flEntry->EventId == Dem_ClearDtc[Client].EventId)
        #endif
        {
          if (NULL != Dem_Cfg_EventParameter[flEntry->EventId].DemCallbackInitMForE)
          {
            /*SWS_Dem_00680*/
            (void)Dem_Cfg_EventParameter[flEntry->EventId].DemCallbackInitMForE(DEM_INIT_MONITOR_CLEAR);
          }
          Dem_Cfg_StatusData.EventStatus[flEntry->EventId] = DEM_UDS_STATUS_DEFAULT;
          Dem_ProcessDeleteMemEntry(flMemIndex, flMemIterIndex);
          flMemIndex = Dem_Cfg_Mem_Primary_Entry_Stop;
        }
      }
    }
    /* Cover DTCs which are not stored in NVM */
    Dem_EventIdType flEventId = Dem_ClearDtc[Client].EventId;
    #if(DemDevAdditionalCoverityChecks == TRUE)
    if(flEventId < Dem_Cfg_Num_Of_Event)
    #endif
    {
      if (DEM_UDS_STATUS_DEFAULT != Dem_Cfg_StatusData.EventStatus[flEventId])
      {
        Dem_EnterCriticalSection();
        Dem_Event.DebounceValue[flEventId] = 0U;
        Dem_Event.InternalStatus[flEventId] = 0U;
        if (FALSE != DEM_EVENT_GET_QUEUE_STATUS_PENDING(Dem_Event.QueueStatus[flEventId]))
        {
          Dem_Event.QueueStatus[flEventId] = 0U;
          if (Dem_Event.QueueCount > 0U)
          {
            Dem_Event.QueueCount--;
          }
        }
        Dem_Cfg_StatusData.EventStatus[flEventId] = DEM_UDS_STATUS_DEFAULT;
        if (Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] == DEM_MEM_STATUS_NONE)
        {
          Dem_NvmWriteData.PendingCount++;
        }
        Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] = DEM_MEM_STATUS_TRIGGER_CLEAR;
        Dem_ExitCriticalSection();
      }
    }  /* END: Cover DTCs which are not stored in NVM */
  }
  else
  {
    for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start;
       flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
      flMemIterIndex = flEntry->EventMemoryEntryCounter;
      #if(DemDevAdditionalCoverityChecks == TRUE)
      if((flEntry->EventId < Dem_Cfg_Num_Of_Event) && (flEntry->EventId != DEM_EVENT_INVALID))
      #else
      if(flEntry->EventId != DEM_EVENT_INVALID)
      #endif
      {
        /*SWS_Dem_00680*/
        Dem_ProcessInitMForEventAll(DEM_INIT_MONITOR_CLEAR);
        if (Dem_ClearEventAllowed(flEntry->EventId) != E_OK)
        {
          conditionclearDtc = FALSE;
        }
        if (conditionclearDtc == TRUE)
        {
          Dem_ProcessDeleteMemEntry(flMemIndex,flMemIterIndex);
          Dem_Cfg_StatusData.EventStatus[flEntry->EventId] = DEM_UDS_STATUS_DEFAULT;
        }
        conditionclearDtc = TRUE;
      }
    }
    Dem_Internal.TimeStampCounter = 0x00U;
    /* Cover DTCs which are not stored in NVM */
    Dem_EventIdType flEventId;
    Dem_EnterCriticalSection();
    for (flEventId = 0; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
    {
      if(Dem_ClearEventAllowed(flEventId) != E_OK)
      {
        conditionclearDtc = FALSE;
      }
      if ((flEventId != DEM_EVENT_INVALID) && (conditionclearDtc == TRUE))
      {
        Dem_Event.DebounceValue[flEventId] = 0U;
        Dem_Event.InternalStatus[flEventId] = 0U;
        Dem_Event.QueueStatus[flEventId] = 0U;
        Dem_Cfg_StatusData.EventStatus[flEventId] = DEM_UDS_STATUS_DEFAULT;
      }
      conditionclearDtc = TRUE;
    }
    Dem_Event.QueueCount = 0U;
    Dem_Cfg_StatusData.FirstConfirmedEvent = DEM_EVENT_INVALID;
    Dem_Cfg_StatusData.FirstFailedEvent = DEM_EVENT_INVALID;
    Dem_Cfg_StatusData.RecentConfirmedEvent = DEM_EVENT_INVALID;
    Dem_Cfg_StatusData.RecentFailedEvent = DEM_EVENT_INVALID;
    for(flIndex = 0u; flIndex < Dem_Cfg_Num_Of_EventMemorySet; flIndex++)
    {
       Dem_Cfg_StatusData.MemoryOverflow[flIndex] = FALSE;
    }
    if (Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] == DEM_MEM_STATUS_NONE)
    {
      Dem_NvmWriteData.PendingCount++;
    }
    Dem_Event.InternalMemStatus[Dem_Cfg_Mem_Status_Index] = DEM_MEM_STATUS_TRIGGER_CLEAR;
    Dem_ExitCriticalSection();
    /* END: Cover DTCs which are not stored in NVM */
  }
  Dem_ClearDtc[Client].Req_Status = DEM_DCM_CLEAR_DTC_REQUEST_COMPLETED;

#if((TRUE == DEM_CLRRESP_VOLATILE) || (TRUE == DEM_CLRRESP_NONVOLATILE_TRIGGER))
  Dem_ClearDtc[Client].QueueState = DEM_DCM_CLEAR_DTC_QUEUE_DONE;
  /*Zeroth index should always be Dcm*/
  if(Client == Dem_Cfg_Client[0].DemClientId)
  {
    DCM_14S_END_NOTIFICATION();
  }
#endif
}

/**************************************************************************
 Function name   : Dem_ProcessEnableStorageCondition
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing on queued enable condition status.
 **************************************************************************/
static void Dem_ProcessEnableStorageCondition(void)
{
  uint16 flEnableConditionCfgGroupMask = 0U;
  uint16 flStorageConditionCfgGroupMask = 0U;
  uint8 flEnableConditionCfgGroupRef = 0U;
  uint8 flStorageConditionCfgGroupRef = 0U;
  Dem_EventIdType flEventId;
  uint8 flConditionId;
  uint8 flOldEnableCondition;
  uint8 flNewEnableCondition;
  uint8 flNewStorageCondition;

  if (Dem_Event.EnStrConditionFlag & DEM_EVENT_ENABLE_CONDITION_REQUESTED)
  {
    for (flConditionId = 0; flConditionId < Dem_Cfg_Num_Of_EnCon; flConditionId++)
    {
      flOldEnableCondition = Dem_Event.EnableCondition[flConditionId];
      flNewEnableCondition = Dem_Event.EnableConditionQueue[flConditionId];
      Dem_Event.EnableCondition[flConditionId] = flNewEnableCondition;

      if(flNewEnableCondition == DEM_EVENT_ENABLE_CONDITION_FAILED)
      {
        Dem_Event.EnableConditionGroupMask &= ~((uint16)0x01U << flConditionId);
      }
      else
      {
        Dem_Event.EnableConditionGroupMask |= ((uint16)0x01U << flConditionId);
      }

      /* Reset De-bounce and internal status */
      for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
      {
        flEnableConditionCfgGroupRef = Dem_Cfg_EventParameter[flEventId].EnableConditionGroupRef;
        flEnableConditionCfgGroupMask = Dem_Cfg_EnableConditionGroup[flEnableConditionCfgGroupRef].Mask;
        if(flEnableConditionCfgGroupMask & (uint16)0x01U << flConditionId)
        {
          if(   (flNewEnableCondition == DEM_EVENT_ENABLE_CONDITION_FAILED)
             && (flOldEnableCondition == DEM_EVENT_ENABLE_CONDITION_FULFILLED))
          {
            Dem_InternalFreezeOrResetDebounceStatus(flEventId);
          }
          else if(flNewEnableCondition == DEM_EVENT_ENABLE_CONDITION_FULFILLED)
          {
            if(NULL != Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE)
            {
              if((Dem_Event.EnableConditionGroupMask & flEnableConditionCfgGroupMask) == flEnableConditionCfgGroupMask)
              {
                (void) Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE(DEM_INIT_MONITOR_REENABLED);
              }
            }
          }
          else
          {
            /*DO NOTHING - MISRA FIX*/
          }
        }
      }
    }
    DEM_RESET_BIT_STATE(Dem_Event.EnStrConditionFlag,
        DEM_EVENT_ENABLE_CONDITION_REQUESTED);
  }

  if (Dem_Event.EnStrConditionFlag & DEM_EVENT_STORAGE_CONDITION_REQUESTED)
  {
    for (flConditionId = 0; flConditionId < Dem_Cfg_Num_Of_StrCon; flConditionId++)
    {
      flNewStorageCondition = Dem_Event.StorageConditionQueue[flConditionId];
      Dem_Event.StorageCondition[flConditionId] = flNewStorageCondition;

      if(flNewStorageCondition == DEM_EVENT_STORAGE_CONDITION_FAILED)
      {
        Dem_Event.StorageConditionGroupMask &= ~((uint16)0x01U << flConditionId);
      }
      else
      {
        Dem_Event.StorageConditionGroupMask |= ((uint16)0x01U << flConditionId);
      }

      for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
      {
        flStorageConditionCfgGroupRef = Dem_Cfg_EventParameter[flEventId].StorageConditionGroupRef;
        flStorageConditionCfgGroupMask = Dem_Cfg_StorageConditionGroup[flStorageConditionCfgGroupRef].Mask;

        if(flStorageConditionCfgGroupMask & (uint16)0x01U << flConditionId)
        {
          if(flNewStorageCondition == DEM_EVENT_STORAGE_CONDITION_FULFILLED)
          {
            if(NULL != Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE)
            {
              if((Dem_Event.StorageConditionGroupMask & flStorageConditionCfgGroupMask) == flStorageConditionCfgGroupMask)
              {
                (void) Dem_Cfg_EventParameter[flEventId].DemCallbackInitMForE(DEM_INIT_MONITOR_REENABLED);
              }
            }
          }
        }
      }
    }
    DEM_RESET_BIT_STATE(Dem_Event.EnStrConditionFlag, DEM_EVENT_STORAGE_CONDITION_REQUESTED);
  }
}

/**************************************************************************
 Function name   : Dem_MainFunctionProcessQueue
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     : Does the processing of main function queues.
 **************************************************************************/
static void Dem_MainFunctionProcessQueue(uint8 Client)
{
  if (Dem_Event.QueueCount != 0U)
  {
    Dem_ProcessQueuedEvents(Client);
  }

  if (Dem_Internal.DtcSettingConditionRequestedFlag != FALSE)
  {
    Dem_ProcessDtcEnableCondition();
    Dem_Internal.DtcSettingConditionRequestedFlag = FALSE;
  }

  if (Dem_ClearDtc[Client].Req_Status == DEM_DCM_CLEAR_DTC_REQUESTED)
  {
    Dem_ProcessClearDtcQueue(Client);
  }


  if (Dem_Event.EnStrConditionFlag != 0U)
  {
    Dem_ProcessEnableStorageCondition();
  }

  /* OpCycle state change should be called last ? */

  if (Dem_InternalOpCycle.Flag != 0U)
  {
    Dem_ProcessOperationCycleQueue();
  }

}

/**************************************************************************
 Function name   : Dem_ProcessNvmPendingWrite
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
static void Dem_ProcessNvmPendingWrite(void)
{
  Std_ReturnType flReturnVal = E_NOT_OK;
  uint8 flMemIndex;
#if (DEM_USE_NVM == STD_ON)
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint16 flBlockId;
#endif

  for (flMemIndex = Dem_Cfg_Mem_Entry_Start; flMemIndex < Dem_Cfg_Mem_Total_Entry;
      flMemIndex++)
  {
    if(   (DEM_MEM_STATUS_TRIGGER_STORAGE == Dem_Event.InternalMemStatus[flMemIndex])
       || (DEM_MEM_STATUS_TRIGGER_CLEAR   == Dem_Event.InternalMemStatus[flMemIndex]))
    {
#if (DEM_USE_NVM == STD_ON)
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
      flBlockId = Dem_Cfg_Memory_BlockId[flMemIndex];
      flReturnVal = NvM_WriteBlock(flBlockId, flEntry);
#else
      flReturnVal = E_OK;
#endif
      if (E_OK == flReturnVal)
      {
        Dem_NvmWriteData.MemIndex = flMemIndex;
        Dem_NvmWriteData.WriteStatus = DEM_NVM_WRITING;
      }
      flMemIndex = Dem_Cfg_Mem_Total_Entry;
    }
    else
    {
        /*Do Nothing*/
    }
    /* No more fresh write available...Try for ??? */
  }
}

/**************************************************************************
 Function name   : Dem_MainFunctionProcessNvm
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
static void Dem_MainFunctionProcessNvm(uint8 Client)
{
  uint8 flOldUdsEventStatus;
  uint8 flNewUdsEventStatus;

  Dem_Cfg_PrimaryMemEntryType *flEntry = NULL_PTR; /*Cert-c 19703302*/

  if(Client < Dem_Cfg_Num_Of_Clients)
  {
    if (Dem_NvmWriteData.WriteStatus == DEM_NVM_FINISHED)
    {
      if (Dem_NvmWriteData.PendingCount > 0x00U)
      {
        Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount - DEM_ONE;
      }
      if((Dem_NvmWriteData.MemIndex >= Dem_Cfg_Mem_Primary_Entry_Start) && (Dem_NvmWriteData.MemIndex < Dem_Cfg_Mem_Total_Entry))
      {
         flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[Dem_NvmWriteData.MemIndex];
      }
      else
      {
        flEntry = NULL_PTR;
      }

      if(Dem_NvmWriteData.MemIndex < Dem_Cfg_Mem_Total_Entry)
      {
        switch (Dem_Event.InternalMemStatus[Dem_NvmWriteData.MemIndex])
        {
          case DEM_MEM_STATUS_TRIGGER_STORAGE:
            Dem_Event.InternalMemStatus[Dem_NvmWriteData.MemIndex] = DEM_MEM_STATUS_NONE;
            if((NULL_PTR != flEntry))
            {
              #if(DemDevAdditionalCoverityChecks == TRUE)
              if(flEntry->EventId < Dem_Cfg_Num_Of_Event)
              #endif
              {
                Dem_InternalSetEventStatus(flEntry->EventId, DEM_EVENT_STATUS_STORED);
              }
            }
          break;

          case DEM_MEM_STATUS_TRIGGER_CLEAR:
            Dem_Event.InternalMemStatus[Dem_NvmWriteData.MemIndex] = DEM_MEM_STATUS_NONE;
            if((NULL_PTR != flEntry))
            {
              #if(DemDevAdditionalCoverityChecks == TRUE)
              if(flEntry->EventId < Dem_Cfg_Num_Of_Event)
              #endif
              {
                Dem_InternalSetEventStatus(flEntry->EventId, DEM_EVENT_STATUS_NONE);
                Dem_EnterCriticalSection();
                flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[flEntry->EventId];
                flNewUdsEventStatus = flOldUdsEventStatus;
                DEM_RESET_UDS_STATUS_BYTE_CDTC(flNewUdsEventStatus);
                DEM_RESET_UDS_STATUS_BYTE_PDTC(flNewUdsEventStatus);
                if(flNewUdsEventStatus != flOldUdsEventStatus)
                {
                  Dem_Cfg_StatusData.EventStatus[flEntry->EventId] = flNewUdsEventStatus;
                }
                Dem_ExitCriticalSection();
              }
            }
            /* Clear confirmed DTC */
            #if(TRUE == DEM_CLRRESP_NONVOLATILE_FINISH)
            if ((Dem_ClearDtc[Client].Req_Status == DEM_DCM_CLEAR_DTC_REQUEST_COMPLETED)
              && (Dem_NvmWriteData.PendingCount == 0x00U))
            {
              Dem_ClearDtc[Client].QueueState = DEM_DCM_CLEAR_DTC_QUEUE_DONE;
            }
            #endif
          break;

          default:
            /*DoNothing*/
          break;
        }
        Dem_NvmWriteData.WriteStatus = DEM_NVM_IDLE;
      }
    }
    else if(Dem_NvmWriteData.WriteStatus== DEM_NVM_FAILED)
    {
      if (Dem_NvmWriteData.PendingCount > 0x00U)
      {
        Dem_NvmWriteData.PendingCount = Dem_NvmWriteData.PendingCount - DEM_ONE;
      }
    
      if((Dem_NvmWriteData.MemIndex >= Dem_Cfg_Mem_Primary_Entry_Start) && (Dem_NvmWriteData.MemIndex < Dem_Cfg_Mem_Total_Entry))
      {
         flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[Dem_NvmWriteData.MemIndex];
      }
      else
      {
        flEntry = NULL_PTR;
      }
    
      if(Dem_NvmWriteData.MemIndex < Dem_Cfg_Mem_Total_Entry)
      {
        switch (Dem_Event.InternalMemStatus[Dem_NvmWriteData.MemIndex])
        {
          case DEM_MEM_STATUS_TRIGGER_STORAGE:
            Dem_Event.InternalMemStatus[Dem_NvmWriteData.MemIndex] = DEM_MEM_STATUS_NONE;
            if((NULL_PTR != flEntry))
            {
              #if(DemDevAdditionalCoverityChecks == TRUE)
              if(flEntry->EventId < Dem_Cfg_Num_Of_Event)
              #endif
              {
                Dem_InternalSetEventStatus(flEntry->EventId, DEM_EVENT_STATUS_NONE);
              }
            }
          break;

          case DEM_MEM_STATUS_TRIGGER_CLEAR:
            #if(TRUE == DEM_CLRRESP_NONVOLATILE_FINISH)
            if ((Dem_ClearDtc[Client].Req_Status == DEM_DCM_CLEAR_DTC_REQUEST_COMPLETED)
                && (Dem_NvmWriteData.PendingCount == 0x00U))
            {
              Dem_ClearDtc[Client].QueueState = DEM_DCM_CLEAR_DTC_QUEUE_FAILED;
            }
            #endif
            Dem_Event.InternalMemStatus[Dem_NvmWriteData.MemIndex] = DEM_MEM_STATUS_NONE;
            
            if((NULL_PTR != flEntry))
            {
              #if(DemDevAdditionalCoverityChecks == TRUE)
              if(flEntry->EventId < Dem_Cfg_Num_Of_Event)
              #endif
              {
                Dem_InternalSetEventStatus(flEntry->EventId, DEM_EVENT_STATUS_NONE);
                Dem_EnterCriticalSection();
                flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[flEntry->EventId];
                flNewUdsEventStatus = flOldUdsEventStatus;
                DEM_RESET_UDS_STATUS_BYTE_CDTC(flNewUdsEventStatus);
                DEM_RESET_UDS_STATUS_BYTE_PDTC(flNewUdsEventStatus);
                if(flNewUdsEventStatus != flOldUdsEventStatus)
                {
                  Dem_Cfg_StatusData.EventStatus[flEntry->EventId] = flNewUdsEventStatus;
                }
                Dem_ExitCriticalSection();
              }
            }
          break;

          default:
            /*DoNothing*/
          break;
        }
        Dem_NvmWriteData.WriteStatus = DEM_NVM_IDLE;
      }
    } 
    else
    {
      /*Do Nothing*/
    }

    if ((Dem_NvmWriteData.PendingCount != 0x0U)
        && (Dem_NvmWriteData.WriteStatus == DEM_NVM_IDLE))
    {
      if (Dem_NvmWriteData.PendingCount > Dem_Cfg_Mem_Total_Entry)
      {
        Dem_NvmWriteData.PendingCount = Dem_Cfg_Mem_Total_Entry;
      }
      Dem_ProcessNvmPendingWrite();
    }
  }
}

/**************************************************************************
 Function name   : Dem_MainFunctionProcessTimerBasedEvent
 Arguments       : void
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
static void Dem_MainFunctionProcessTimerBasedEvent(uint8 Client)
{
  Dem_EventIdType EventId;
  uint8 flDebounceInfoTableRef;

  for (EventId = DEM_EVENT_VALID_ID_START; EventId < Dem_Cfg_Num_Of_Event; EventId++)
  {
    flDebounceInfoTableRef = Dem_Cfg_EventParameter[EventId].DebounceTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
    if(flDebounceInfoTableRef < Dem_Cfg_Num_Of_DebounceTable)
#endif
    {
      if(Dem_Cfg_DebounceTable[flDebounceInfoTableRef].AlgoClass == DEM_CFG_DEBOUNCETYPE_TIMER)
      {
        Dem_EnterCriticalSection();
        Dem_ProcessTimerEvents(EventId, Dem_Cfg_DebounceTable[flDebounceInfoTableRef]);
        Dem_ExitCriticalSection();
      }
    }
  }

}

/**************************************************************************
 Function name   : Dem_InternalCalculateFDCCounterBased
 Arguments       : Dem_EventIdType EventId, sint16 flDebounceValue
 Return type     : sint8
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
static sint8 Dem_InternalCalculateFDCCounterBased(Dem_EventIdType EventId, sint16 flDebounceValue)
{
  sint8 flReturnFdc = 0;
  sint16 flFailedThershold;
  sint16 flPassedThershold;
  uint8 flDebounceTableRef;

  if (flDebounceValue == 0)
  {
    flReturnFdc = 0;
  }
  else
  {
#if(DemDevAdditionalCoverityChecks == TRUE)
    if(EventId < Dem_Cfg_Num_Of_Event)
#endif
    {
      flDebounceTableRef = Dem_Cfg_EventParameter[EventId].DebounceTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(flDebounceTableRef < Dem_Cfg_Num_Of_DebounceTable)
#endif
      {
        flFailedThershold = Dem_Cfg_DebounceTable[flDebounceTableRef].FailedThershold;
        flPassedThershold = Dem_Cfg_DebounceTable[flDebounceTableRef].PassedThershold;

        if (flFailedThershold == flDebounceValue)
        {
          flReturnFdc = 127;
        }
        else if (flPassedThershold == flDebounceValue)
        {
          flReturnFdc = -128;
        }
        else
        {
          if(flDebounceValue > 0)
          {
            flReturnFdc = (sint8)(((sint32)flDebounceValue * 127 ) / flFailedThershold);
            if(flReturnFdc == 0)
            {
              flReturnFdc = (sint8)DEM_ONE;/*Cert-c 17225617*/
            }
          }
          else
          {
            flReturnFdc = (sint8)(((sint32)flDebounceValue * -128 ) / flPassedThershold);
            if(flReturnFdc == 0)
            {
              flReturnFdc = (sint8)-DEM_ONE;
            }
          }
        }
      }
    }
  }
  return flReturnFdc;
}


/**************************************************************************
 Function name   : Dem_InternalCalculateFDCTimerBased
 Arguments       : Dem_EventIdType EventId, sint16 flDebounceValue, uint8 flDebounceStatus
 Return type     : sint8
 Sync/Async      : Synchronous
 Reentrancy      :
 Description     :
 **************************************************************************/
static sint8 Dem_InternalCalculateFDCTimerBased(Dem_EventIdType EventId, sint16 flDebounceValue, uint8 flDebounceStatus)
{
  sint8 flReturnFdc = 0;
  sint16 flFailedTimerThershold;
  sint16 flPassedTimerThershold;
  uint8 flDebounceTableRef;

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flDebounceTableRef = Dem_Cfg_EventParameter[EventId].DebounceTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
    if(flDebounceTableRef < Dem_Cfg_Num_Of_DebounceTable)
#endif
    {
      switch(flDebounceStatus)
      {
      case DEM_EVENT_DEBOUNCE_STATUS_NONE:
        flReturnFdc = 0;
        break;
      case DEM_EVENT_DEBOUNCE_STATUS_FAILED:
        flReturnFdc = 127;
        break;
      case DEM_EVENT_DEBOUNCE_STATUS_PASSED:
        flReturnFdc = -128;
        break;
      case DEM_EVENT_DEBOUNCE_STATUS_FAIL_RESET:
        flReturnFdc = DEM_ONE;
        break;
      case DEM_EVENT_DEBOUNCE_STATUS_HEAL_RESET:
        flReturnFdc = (sint8)-DEM_ONE;
        break;
      case DEM_EVENT_DEBOUNCE_STATUS_HEALING:
        flPassedTimerThershold = Dem_Cfg_DebounceTable[flDebounceTableRef].PassedTimeThershold;
        flReturnFdc = (sint8)((sint32)((sint32)(flPassedTimerThershold - flDebounceValue) * -128) \
                                  / flPassedTimerThershold);
        if (flReturnFdc == 0)
        {
          flReturnFdc = (sint8)-DEM_ONE; /*Cert-c 17224374*/
        }
        break;
      case DEM_EVENT_DEBOUNCE_FREEZE_HEAL_STATUS:
        flPassedTimerThershold = Dem_Cfg_DebounceTable[flDebounceTableRef].PassedTimeThershold;
        flReturnFdc = (sint8)((sint32)((sint32)(flPassedTimerThershold - flDebounceValue) * -128) \
                                  / flPassedTimerThershold);
        if (flReturnFdc == 0)
        {
          flReturnFdc = (sint8)-DEM_ONE;
        }
        break;
      case DEM_EVENT_DEBOUNCE_STATUS_FAILING:
        flFailedTimerThershold = Dem_Cfg_DebounceTable[flDebounceTableRef].FailedTimeThershold;
        flReturnFdc = (sint8)((sint32)((sint32)(flFailedTimerThershold - flDebounceValue) * 127) \
                                  / flFailedTimerThershold);
        if (flReturnFdc == 0)
        {
          flReturnFdc = (sint8)DEM_ONE;
        }
        break;
      case DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL:
        flFailedTimerThershold = Dem_Cfg_DebounceTable[flDebounceTableRef].FailedTimeThershold;
        flReturnFdc = (sint8)((sint32)((sint32)(flFailedTimerThershold - flDebounceValue) * 127) \
                                  / flFailedTimerThershold);
        if (flReturnFdc == 0)
        {
          flReturnFdc = (sint8)DEM_ONE;
        }
        break;
      default:
        flReturnFdc = (sint8)0;
        break;
      }
    }
  }
  return flReturnFdc;
}

/**************************************************************************
 Function name   : Dem_MainFunction
 Arguments       : void
 Return type     : void
 Sync/Async      :
 Reentrancy      :
 Description     : Processes all not event based Dem internal functions..
 **************************************************************************/
void Dem_MainFunction(void)
{
  uint8 index;

  if (Dem_Internal.InitState == DEM_INITIALIZED)
  {
    for(index = 0; index < Dem_Cfg_Num_Of_Clients; index++)
    {
      Dem_MainFunctionProcessTimerBasedEvent(index);
      Dem_MainFunctionProcessQueue(index);
      Dem_MainFunctionProcessNvm(index);
    }/*optimisation tbd phase-2*/
  }
}

/*** Interface BSW modules / SW-Components <=> Dem  ***/

/**************************************************************************
 Function name   : Dem_SetEventAvailable
 Arguments       : Dem_EventIdType EventId, boolean AvailableStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant.
 Description     : Set the available status of a specific Event.
 **************************************************************************/
Std_ReturnType Dem_SetEventAvailable(Dem_EventIdType EventId, boolean AvailableStatus)
{
  Std_ReturnType fl_RetVal;
  uint8 flIndex;
  uint8 flMask;
  fl_RetVal = E_OK;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((EventId >= Dem_Cfg_Num_Of_Event) || (EventId == DEM_EVENT_INVALID))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flIndex = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    Dem_EnterCriticalSection();
    if (AvailableStatus != FALSE)
    {
      DEM_SET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    }
    else
    {
      DEM_RESET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    }
    Dem_ExitCriticalSection();
  }
  return fl_RetVal;
}


/**************************************************************************
 Function name   : Dem_AssessTimerBasedEvent
 Arguments       :
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous/Asynchronous
 Reentrancy      :
 EventId.
 Description     :
 **************************************************************************/
static Std_ReturnType Dem_AssessTimerBasedEvent(Dem_EventIdType EventId,
                                          Dem_EventStatusType EventStatus)
{
  Std_ReturnType flReturnVal = E_NOT_OK;
  uint8 flOldInternalStatus;
  uint8 flNewInternalStatus;
  uint8 flNewUdsEventStatus;
  uint8 flOldUdsEventStatus;
#if(DemTriggerDcmReports == STD_ON)
  uint8 flDTCTableRef;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flReturnVal = E_OK;
    flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[EventId];
    flNewUdsEventStatus = flOldUdsEventStatus;
    flOldInternalStatus = Dem_InternalGetDebounceStatus(EventId);
    flNewInternalStatus = flOldInternalStatus;
    if (DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition)
    {
      switch (EventStatus)
      {
      case DEM_EVENT_STATUS_PREPASSED:
        if ((flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_NONE)
            || (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_FAILING)
            || (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_FAILED))
        {
          flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_HEAL_RESET;
        }
        else if (flOldInternalStatus == DEM_EVENT_DEBOUNCE_FREEZE_HEAL_STATUS)
        {
          flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_HEALING;
        }
        else
        {
          /*DO NOTHING - MISRA FIX*/
        }
        break;

      case DEM_EVENT_STATUS_PREFAILED:
        if ((flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_NONE)
            || (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_HEALING)
            || (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_PASSED))
        {
          flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_FAIL_RESET;
        }
        else if (flOldInternalStatus == DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL)
        {
          flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_FAILING;
        }
        else
        {
          /*DO NOTHING - MISRA FIX*/
        }
        break;

      case DEM_EVENT_STATUS_PASSED:
        flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_PASSED;
        break;

      case DEM_EVENT_STATUS_FAILED:
        flNewInternalStatus = DEM_EVENT_DEBOUNCE_STATUS_FAILED;
        break;
      default:
            /*DoNothing*/
        break;
      }
    }
    else
    {
      flReturnVal = E_NOT_OK;
    }

    if (flOldInternalStatus != flNewInternalStatus)
    {
      if (EventStatus == DEM_EVENT_STATUS_PASSED)
      {
        DEM_RESET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_WIR(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);

      }
      else if (EventStatus == DEM_EVENT_STATUS_FAILED)
      {
        DEM_SET_UDS_STATUS_BYTE_TFTMC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TFSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else
      {
        /* Do nothing */
      }
        /***  Queue Event Status ***/
      flReturnVal = Dem_InternalCheckEventQualification(EventId, EventStatus);
      if(flNewUdsEventStatus != flOldUdsEventStatus)
      {
        flDTCTableRef = Dem_Cfg_EventParameter[EventId].DTCTableRef;
        DCMEXT_NOTIFICATIONONDTCSTATUSCHANGE(Dem_Cfg_DTC[flDTCTableRef].Value,
                                      flOldUdsEventStatus, flNewUdsEventStatus);
#if(DemTriggerDcmReports == STD_ON)
        if(DTCStatusChangeNotification != FALSE)
        {
          flDTCTableRef = Dem_Cfg_EventParameter[EventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
          if(flDTCTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
          {
            (void)Dcm_DemTriggerOnDTCStatus(Dem_Cfg_DTC[flDTCTableRef].Value,
                                      flOldUdsEventStatus, flNewUdsEventStatus); /*MISRA FIX*/
          }
        }
#endif
        Dem_Cfg_StatusData.EventStatus[EventId] = flNewUdsEventStatus;
      }
      Dem_InternalSetDebounceStatus(EventId, flNewInternalStatus);
    }
  }
  return flReturnVal;
}

/**************************************************************************
 Function name   : Dem_InternalCheckEventQualification
 Arguments       :
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous/Asynchronous
 Reentrancy      :
 EventId.
 Description     :
 **************************************************************************/
static Std_ReturnType Dem_InternalCheckEventQualification(Dem_EventIdType EventId,
                                                  Dem_EventStatusType EventStatus)
{
  Std_ReturnType flReturnVal = E_NOT_OK;
  uint16 flStorageConditionGroupMask;
  uint8 lQueueStatus;
  uint8 lQueueCount;
  uint8 flStorageCondition = 0U;
  uint8 flStorageConditionGroupRef;

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flReturnVal = E_OK;
    lQueueStatus = Dem_Event.QueueStatus[EventId];
    lQueueCount = Dem_Event.QueueCount;

    if (EventStatus == DEM_EVENT_STATUS_PASSED)
    {
      if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_PENDING(lQueueStatus))
      {
        DEM_EVENT_SET_QUEUE_STATUS_PENDING(lQueueStatus);
        lQueueCount++;
      }

      if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_PASSED(lQueueStatus))
      {
        DEM_EVENT_SET_QUEUE_STATUS_PASSED(lQueueStatus);
      }
    }
    else if (EventStatus == DEM_EVENT_STATUS_FAILED)
    {
      flStorageConditionGroupRef = Dem_Cfg_EventParameter[EventId].StorageConditionGroupRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(Dem_Cfg_Num_Of_StrConGroup > flStorageConditionGroupRef)
#endif
      {
        flStorageConditionGroupMask = Dem_Cfg_StorageConditionGroup[flStorageConditionGroupRef].Mask;
        if((flStorageConditionGroupMask & Dem_Event.StorageConditionGroupMask) == flStorageConditionGroupMask)
        {
          flStorageCondition = TRUE;
        }
        if(FALSE != flStorageCondition)
        {
          if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_PENDING(lQueueStatus))
          {
            DEM_EVENT_SET_QUEUE_STATUS_PENDING(lQueueStatus);
            lQueueCount++;
          }
          if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_FAILED(lQueueStatus))
          {
            DEM_EVENT_SET_QUEUE_STATUS_FAILED(lQueueStatus);
          }
        }
        if (Dem_Cfg_StatusData.FirstFailedEvent != DEM_EVENT_INVALID)
        {
          Dem_Cfg_StatusData.RecentFailedEvent = EventId;
          Dem_Cfg_StatusData.RecentConfirmedEvent = EventId;
        }
        else
        {
          Dem_Cfg_StatusData.FirstConfirmedEvent = EventId;
          Dem_Cfg_StatusData.FirstFailedEvent = EventId;
          Dem_Cfg_StatusData.RecentFailedEvent = EventId;
          Dem_Cfg_StatusData.RecentConfirmedEvent = EventId;
        }
      }
    }
    else
    {
      /*DO NOTHING - MISRA FIX*/
    }

    if (lQueueStatus != Dem_Event.QueueStatus[EventId])
    {
      Dem_Event.QueueStatus[EventId] = lQueueStatus;
    }
    if (lQueueCount != Dem_Event.QueueCount)
    {
      Dem_Event.QueueCount = lQueueCount;
    }
  }
  return flReturnVal;
}

/**************************************************************************
 Function name   : Dem_AssessInstantEvent
 Arguments       :
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous/Asynchronous
 Reentrancy      :
 EventId.
 Description     :
 **************************************************************************/
static Std_ReturnType Dem_AssessInstantEvent(Dem_EventIdType EventId,
                                      Dem_EventStatusType EventStatus)
{
  Std_ReturnType flReturnVal = E_NOT_OK;
  sint16 flOldDebounceValue;
  sint16 flNewDebounceValue;
  sint16 flJumpToValue;
  uint8 flOldUdsEventStatus;
  uint8 flNewUdsEventStatus;
  uint8 flCfgDebounceTableRef;
#if(DemTriggerDcmReports == STD_ON)
  uint8 flDTCTableRef;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if(EventId >= Dem_Cfg_Num_Of_Event)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flReturnVal = E_OK;
    flOldUdsEventStatus = Dem_Cfg_StatusData.EventStatus[EventId];
    flNewUdsEventStatus = flOldUdsEventStatus;
    flOldDebounceValue = Dem_Event.DebounceValue[EventId];
    flNewDebounceValue = flOldDebounceValue;

    if (DEM_DTC_STORAGE_SETTING_ENABLED == Dem_Internal.DtcSettingEnCondition)
    {
      flCfgDebounceTableRef = Dem_Cfg_EventParameter[EventId].DebounceTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(flCfgDebounceTableRef < Dem_Cfg_Num_Of_DebounceTable)
#endif
      {
        switch (EventStatus)
        {
        case DEM_EVENT_STATUS_PREPASSED:
          if (FALSE != (Dem_Cfg_DebounceTable[flCfgDebounceTableRef].JumpDown))
          {
            flJumpToValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef].JumpDownValue;
            if (flOldDebounceValue > flJumpToValue)
            {
              flNewDebounceValue = flJumpToValue;
            }
            else
            {
              flNewDebounceValue = flOldDebounceValue;
            }
          }

          if (Dem_Cfg_DebounceTable[flCfgDebounceTableRef].PassedThershold
              >= (flNewDebounceValue
                  + Dem_Cfg_DebounceTable[flCfgDebounceTableRef].DecStepSize))
          {
            flNewDebounceValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef]
                .PassedThershold;
            EventStatus = DEM_EVENT_STATUS_PASSED;
          }
          else
          {
            flNewDebounceValue += Dem_Cfg_DebounceTable[flCfgDebounceTableRef].DecStepSize;
          }
          break;

        case DEM_EVENT_STATUS_PREFAILED:
          if (FALSE != (Dem_Cfg_DebounceTable[flCfgDebounceTableRef].JumpUp))
          {
            flJumpToValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef].JumpUpValue;
            if (flOldDebounceValue < flJumpToValue)
            {
              flNewDebounceValue = flJumpToValue;
            }
            else
            {
              flNewDebounceValue = flOldDebounceValue;
            }
          }

          if (Dem_Cfg_DebounceTable[flCfgDebounceTableRef].FailedThershold
              <= (flNewDebounceValue
                  + Dem_Cfg_DebounceTable[flCfgDebounceTableRef].IncStepSize))
          {
            flNewDebounceValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef]
                .FailedThershold;
            EventStatus = DEM_EVENT_STATUS_FAILED;
          }
          else
          {
            flNewDebounceValue += Dem_Cfg_DebounceTable[flCfgDebounceTableRef].IncStepSize;
          }
          break;

        case DEM_EVENT_STATUS_PASSED:
          flNewDebounceValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef].PassedThershold;
          EventStatus = DEM_EVENT_STATUS_PASSED;
          break;

        case DEM_EVENT_STATUS_FAILED:
          flNewDebounceValue = Dem_Cfg_DebounceTable[flCfgDebounceTableRef].FailedThershold;
          EventStatus = DEM_EVENT_STATUS_FAILED;
          break;
        default:
               /*DoNothing*/
          break;
        }
      }
    }
    else
    {
      flReturnVal = E_NOT_OK;
    }

    if (flNewDebounceValue != flOldDebounceValue)
    {
      if (EventStatus == DEM_EVENT_STATUS_PASSED)
      {
        DEM_RESET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_WIR(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else if (EventStatus == DEM_EVENT_STATUS_FAILED)
      {
        DEM_SET_UDS_STATUS_BYTE_TFTMC(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TF(flNewUdsEventStatus);
        DEM_SET_UDS_STATUS_BYTE_TFSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCSLC(flNewUdsEventStatus);
        DEM_RESET_UDS_STATUS_BYTE_TNCTMC(flNewUdsEventStatus);
      }
      else
      {
        /* Do nothing */
      }
      /***  Queue Event Status ***/
      flReturnVal = Dem_InternalCheckEventQualification(EventId, EventStatus);

      /*** Update New event status  ***/
      if (flReturnVal == E_OK)
      {
        if(flNewUdsEventStatus != flOldUdsEventStatus)
        {
          flDTCTableRef = Dem_Cfg_EventParameter[EventId].DTCTableRef;
          DCMEXT_NOTIFICATIONONDTCSTATUSCHANGE(Dem_Cfg_DTC[flDTCTableRef].Value,
                                      flOldUdsEventStatus, flNewUdsEventStatus);
#if(DemTriggerDcmReports == STD_ON)
          if(DTCStatusChangeNotification != FALSE)
          {
            flDTCTableRef = Dem_Cfg_EventParameter[EventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
            if(flDTCTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
            {
              (void)Dcm_DemTriggerOnDTCStatus(Dem_Cfg_DTC[flDTCTableRef].Value,
                                        flOldUdsEventStatus, flNewUdsEventStatus); /*MISRA FIX*/
            }
          }
#endif
          Dem_Cfg_StatusData.EventStatus[EventId] = flNewUdsEventStatus;
        }
        Dem_Event.DebounceValue[EventId] = flNewDebounceValue;
      }
    }
  }
  return flReturnVal;
}

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
Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId,
                                  Dem_EventStatusType EventStatus)
{

  uint16 flEnableConditionGroupMask = 0U;
  Std_ReturnType fl_RetVal;
  uint8 flOpCycleId;
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
  uint8 flEnableConditionGroupRef;
  uint8 flEnableCondition = 0U;

  fl_RetVal = E_NOT_OK;
#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((EventId >= Dem_Cfg_Num_Of_Event) || (EventId == DEM_EVENT_INVALID)
              || (EventStatus >= DEM_EVENT_STATUS_INVALID))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flOpCycleId = Dem_Cfg_EventParameter[EventId].OpCycleRef;
    if (FALSE != DEM_GET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.State, flOpCycleId))
    {
      flIndex = DEM_CALCULATE_INDEX(EventId);
      flMask = DEM_CALCULATE_MASK_BIT(EventId);
      flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
      flEnableConditionGroupRef = Dem_Cfg_EventParameter[EventId].EnableConditionGroupRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(flEnableConditionGroupRef < Dem_Cfg_Num_Of_EnConGroup)
#endif
      {
        flEnableConditionGroupMask = Dem_Cfg_EnableConditionGroup[flEnableConditionGroupRef].Mask;
        if((flEnableConditionGroupMask & Dem_Event.EnableConditionGroupMask) == flEnableConditionGroupMask)
        {
          flEnableCondition = TRUE;
        }
        if ((0x00uL != flAvailableCondition) && (0x00uL != flEnableCondition))
        {
          uint8 ref;
          Dem_EnterCriticalSection();
          ref = Dem_Cfg_EventParameter[EventId].DebounceTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
          if(ref < Dem_Cfg_Num_Of_DebounceTable)
#endif
          {
            if (DEM_CFG_DEBOUNCETYPE_TIMER == Dem_Cfg_DebounceTable[ref].AlgoClass)
            {
              fl_RetVal = Dem_AssessTimerBasedEvent(EventId, EventStatus);
            }
            else
            {
              fl_RetVal = Dem_AssessInstantEvent(EventId, EventStatus);
            }
          }
          Dem_ExitCriticalSection();
        }
      }
    }
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_ResetEventDebounceStatus(Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((EventId >= Dem_Cfg_Num_Of_Event) || (EventId == DEM_EVENT_INVALID)
            || (DebounceResetStatus > DEM_DEBOUNCE_STATUS_RESET))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);

    if(FALSE != flAvailableCondition)
#endif
    {
      Dem_EnterCriticalSection();
      if (DebounceResetStatus == DEM_DEBOUNCE_STATUS_RESET)
      {
        Dem_Event.DebounceValue[EventId] = 0U;
        Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_RESET);
      }
      else
      {
        switch (Dem_InternalGetDebounceStatus(EventId))
        {
        case DEM_EVENT_DEBOUNCE_STATUS_PASSED:
          Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_FREEZE_HEAL_STATUS);
          break;
        case DEM_EVENT_DEBOUNCE_STATUS_HEAL_RESET:
          Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_FREEZE_HEAL_STATUS);
          break;
        case DEM_EVENT_DEBOUNCE_STATUS_HEALING:
          Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_FREEZE_HEAL_STATUS);
          break;
        case DEM_EVENT_DEBOUNCE_STATUS_FAILED:
          Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL);
          break;
        case DEM_EVENT_DEBOUNCE_STATUS_FAILING:
          Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL);
          break;
        case DEM_EVENT_DEBOUNCE_STATUS_FAIL_RESET:
          Dem_InternalSetDebounceStatus(EventId, DEM_EVENT_DEBOUNCE_STATUS_FREEZE_FAIL);
          break;
        default:
        /* do nothing */
        break;
        }
        fl_RetVal = E_OK;
      }
      Dem_ExitCriticalSection();
    }
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_ResetEventStatus(Dem_EventIdType EventId)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((EventId >= Dem_Cfg_Num_Of_Event) || (EventId == DEM_EVENT_INVALID))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);

    if(FALSE != flAvailableCondition)
#endif
    {
      if (FALSE != DEM_GET_UDS_STATUS_BYTE_TNCTMC(Dem_Cfg_StatusData.EventStatus[EventId]))
      {
        Dem_EnterCriticalSection();
        DEM_RESET_UDS_STATUS_BYTE_TF(Dem_Cfg_StatusData.EventStatus[EventId]);
        DEM_RESET_UDS_STATUS_BYTE_WIR(Dem_Cfg_StatusData.EventStatus[EventId]);
        Dem_InternalFreezeOrResetDebounceStatus(EventId);
        Dem_ExitCriticalSection();
        fl_RetVal = E_OK;
      }
    }
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_PrestoreFreezeFrame(Dem_EventIdType EventId)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

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
Std_ReturnType Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId)
{
  Std_ReturnType fl_RetVal = E_OK;
  return fl_RetVal;
}

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
Std_ReturnType Dem_SetOperationCycleState(uint8 OperationCycleId,
                            Dem_OperationCycleStateType CycleState)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
  uint8 flOpCycleStatus;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((OperationCycleId >= Dem_Cfg_Num_Of_OpCycle) || (CycleState >= DEM_OPCYCLE_STATE_INVALID))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /* MISRA Fix Do nothing */
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    /* !!! check for critical section code - later */
    flOpCycleStatus = DEM_OPERATION_QUEUE_CYCLE_STOPED;
    if (FALSE != DEM_GET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.State, OperationCycleId))
    {
      flOpCycleStatus = DEM_OPERATION_QUEUE_CYCLE_STARTED;
    }
    /* Check Current operation cycle state and requested state are for STOP.
     * If yes, no need to proceed further */
    if(   (flOpCycleStatus != DEM_OPERATION_QUEUE_CYCLE_STOPED)
       || (CycleState != DEM_CYCLE_STATE_END))
    {
      /* Check if already queued cycle request is there ? */
      if(FALSE != DEM_GET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, OperationCycleId))
      {
        /* Check Pending state is for STOP */
        if(FALSE == DEM_GET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState, OperationCycleId))
        {
          /* If pending state is for STOP, take new start request alone */
          if (CycleState == DEM_CYCLE_STATE_START)
          {
            DEM_SET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState, OperationCycleId);
          }
        }
      }
      else
      {
        DEM_SET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.Flag, OperationCycleId);
        if (CycleState == DEM_CYCLE_STATE_START)
        {
          DEM_SET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState, OperationCycleId);
        }
        else
        {
          DEM_RESET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.QueueState, OperationCycleId);
        }
      }
    }
    fl_RetVal = E_OK;
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_GetOperationCycleState(uint8 OperationCycleId,
    Dem_OperationCycleStateType* CycleState)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((OperationCycleId >= Dem_Cfg_Num_Of_OpCycle) || (CycleState == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /* MISRA Fix Do nothing */
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    if (DEM_GET_OPERATION_CYCLE_STATUS(Dem_InternalOpCycle.State, OperationCycleId)!= FALSE)
    {
      *CycleState = DEM_CYCLE_STATE_START;
    }
    else
    {
      *CycleState = DEM_CYCLE_STATE_END;
    }
    fl_RetVal = E_OK;
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_SetAgingCycleState(uint8 OperationCycleId)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

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
Std_ReturnType Dem_SetWIRStatus(Dem_EventIdType EventId, boolean WIRStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

#endif /*(DEM_PROCESS_AGING_CTR_EXTERN == TRUE)*/

/**************************************************************************
 Function name   : Dem_GetComponentFailed
 Arguments       : Dem_ComponentIdType ComponentId, boolean* ComponentFailed
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant.
 Description     : Gets the failed status of a DemComponent.
 **************************************************************************/
Std_ReturnType Dem_GetComponentFailed(Dem_ComponentIdType ComponentId,
    boolean* ComponentFailed)
{
  Std_ReturnType fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetEventStatus
 Arguments       : Dem_EventIdType EventId,
 Dem_UdsStatusByteType* EventStatusByte
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the current extended event status of an event.
 **************************************************************************/
Std_ReturnType Dem_GetEventStatus(Dem_EventIdType EventId,
                      Dem_UdsStatusByteType* EventStatusByte)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((EventId >= Dem_Cfg_Num_Of_Event) || (EventId == DEM_EVENT_INVALID)
                || (EventStatusByte == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    if(FALSE != flAvailableCondition)
#endif
    {
      *EventStatusByte = Dem_Cfg_StatusData.EventStatus[EventId];
      fl_RetVal = E_OK;
    }
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetDebouncingOfEvent
 Arguments       : Dem_EventIdType EventId,
 Dem_DebouncingStateType* DebouncingState
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event tested status of an event.
 **************************************************************************/
Std_ReturnType Dem_GetDebouncingOfEvent(Dem_EventIdType EventId,
    Dem_DebouncingStateType* DebouncingState)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetDTCOfEvent
 Arguments       : Dem_EventIdType EventId,
 Dem_DTCFormatType DTCFormat, uint32* DTCOfEvent
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the DTC of an event.
 **************************************************************************/
Std_ReturnType Dem_GetDTCOfEvent(Dem_EventIdType EventId, Dem_DTCFormatType DTCFormat,
                                 uint32* DTCOfEvent)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((EventId >= Dem_Cfg_Num_Of_Event) || (EventId == DEM_EVENT_INVALID)
            || (DTCFormat >= DEM_DTC_FORMAT_INVALID) || (DTCOfEvent == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);

    if(FALSE != flAvailableCondition)
#endif
    {
      if (DTCFormat == DEM_DTC_FORMAT_UDS)
      {
        *DTCOfEvent = Dem_Cfg_DTC[EventId].Value;
        fl_RetVal = E_OK;
      }
    }
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetEnableCondition
 Arguments       : uint8 EnableConditionID, boolean ConditionFulfilled
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     : Std_ReturnType
 **************************************************************************/
Std_ReturnType Dem_SetEnableCondition(uint8 EnableConditionID, boolean ConditionFulfilled)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (EnableConditionID >= Dem_Cfg_Num_Of_EnCon)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dem_Event.EnableConditionQueue[EnableConditionID] = ConditionFulfilled;
    DEM_SET_BIT_STATE(Dem_Event.EnStrConditionFlag, DEM_EVENT_ENABLE_CONDITION_REQUESTED);
    fl_RetVal = E_OK;
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetStorageCondition
 Arguments       : uint8 StorageConditionID, boolean ConditionFulfilled
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Sets a storage condition.
 **************************************************************************/
Std_ReturnType Dem_SetStorageCondition(uint8 StorageConditionID,
                                      boolean ConditionFulfilled)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (StorageConditionID >= Dem_Cfg_Num_Of_StrCon)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dem_Event.StorageConditionQueue[StorageConditionID] = ConditionFulfilled;
    DEM_SET_BIT_STATE(Dem_Event.EnStrConditionFlag,
            DEM_EVENT_STORAGE_CONDITION_REQUESTED);
    fl_RetVal = E_OK;
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_GetFaultDetectionCounter(Dem_EventIdType EventId,
                                            sint8* FaultDetectionCounter)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
  uint8 flDebounceTableRef;
  sint8 fdc_external = 0u;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((EventId >= Dem_Cfg_Num_Of_Event) || (EventId == DEM_EVENT_INVALID) || (FaultDetectionCounter == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);

    if(FALSE != flAvailableCondition)
#endif
    {
      flDebounceTableRef = Dem_Cfg_EventParameter[EventId].DebounceTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(flDebounceTableRef < Dem_Cfg_Num_Of_DebounceTable)
#endif
      {
        switch(Dem_Cfg_DebounceTable[flDebounceTableRef].AlgoClass)
        {
        case DEM_CFG_DEBOUNCETYPE_COUNTER:
          *FaultDetectionCounter = Dem_InternalCalculateFDCCounterBased(EventId, Dem_Event.DebounceValue[EventId]);
          fl_RetVal = E_OK;
          break;

        case DEM_CFG_DEBOUNCETYPE_TIMER:
          *FaultDetectionCounter = Dem_InternalCalculateFDCTimerBased(EventId, Dem_Event.DebounceValue[EventId],
                                        Dem_InternalGetDebounceStatus(EventId));
          fl_RetVal = E_OK;
          break;

        case DEM_CFG_DEBOUNCETYPE_EXTERNAL: /* External Monitor Debounce */
          {
            uint8 ref = Dem_Cfg_EventParameter[EventId].CallBackGetFdcRef;
            if((ref < Dem_Cfg_Num_Of_CBGetFdc) && (NULL != Dem_Cfg_CallBackGetFdc[ref].DemCallbackGetFdc))
            {
              fl_RetVal = Dem_Cfg_CallBackGetFdc[ref].DemCallbackGetFdc(&fdc_external);
              if(fl_RetVal == E_OK)
              {
                *FaultDetectionCounter = fdc_external;
              }
            }
            else
            {
              fl_RetVal = DEM_E_NO_FDC_AVAILABLE;
            }
          }
          break;

        case DEM_CFG_DEBOUNCETYPE_INVALID:
          fl_RetVal = DEM_E_NO_FDC_AVAILABLE;
          break;

        default:
          /* MISRA Fix Do Nothing */
          break;
        }
      }
    }
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetIndicatorStatus
 Arguments       : uint8 IndicatorId, Dem_IndicatorStatusType* IndicatorStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the indicator status derived from the event status.
 **************************************************************************/
Std_ReturnType Dem_GetIndicatorStatus(uint8 IndicatorId,
    Dem_IndicatorStatusType* IndicatorStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

#if ((DemMaxNumberFreezeFrameRecords > 0) && (DemTypeofFreezeFrameRecordNumeration == DEM_FF_RECNUM_CONFIGURED))
/**************************************************************************
 Function name   : Dem_GetEventFreezeFrameDataEx
 Arguments       : Dem_EventIdType EventId, uint8 RecordNumber,
                   uint16 DataId, uint8* DestBuffer, uint16* BufSize
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the data of a freeze frame by event.
 **************************************************************************/
Std_ReturnType Dem_GetEventFreezeFrameDataEx(Dem_EventIdType EventId, uint8 RecordNumber,
                                             uint16 DataId, uint8* DestBuffer, uint16* BufSize)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint16 flDestBufferIndex;
  uint8  flMemIndex = 0u;
  uint8  lQueueStatus;
  uint8  flDataPointer = 0u;
  uint8 flFreezeFrameRecordNumClassRef;
  uint8 flDTCTableRef;
  uint8 flFreezeFrameRecNumClassRef;
  uint8 flNoOFFF;
  uint8 flFFIndex;
  uint8 flFreezeFrameRecordClassRef;
  uint8 flRecordNumber;
  uint8 flFreezeFrameClassRef;
  uint8 flFFClassIndex;
  uint8 flNoOfDid;
  uint8 flDIDIndex;
  uint8 flDemDidClassRef;
  uint8 flExternalDataElementClassRef;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if ((Dem_Internal.InitState == DEM_UNINITIALIZED) || (Dem_Internal.InitState == DEM_SHUTDOWN)) /*Cert-c 17224522*/
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((EventId >= Dem_Cfg_Num_Of_Event) || (EventId == DEM_EVENT_INVALID))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);

    if(FALSE != flAvailableCondition)
#endif
    {
      if((EventId != DEM_EVENT_INVALID) && (EventId < Dem_Cfg_Num_Of_Event))
      {
        if((Dem_Cfg_EventParameter[EventId].AvailableStatus != FALSE) && (Dem_Cfg_EventParameter[EventId].DTCTableRef != FALSE))
        {
          if((RecordNumber != DEM_0xFF) && (RecordNumber != 0x00))
          {
            for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start; flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
            {
              flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
              if(flEntry->EventId == EventId)
              {
                if(flMemIndex < Dem_Cfg_Mem_Total_Entry)
                {
                  /* Check for Data being updated while reading */
                  lQueueStatus = Dem_Event.QueueStatus[EventId];
                  if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_PENDING(lQueueStatus))
                  {
                    if (FALSE == DEM_EVENT_GET_QUEUE_STATUS_FAILED(lQueueStatus))
                    {
                      flDTCTableRef = Dem_Cfg_EventParameter[EventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
                      if(Dem_Cfg_Num_Of_DTC > flDTCTableRef)
#endif
                      {
                        if(Dem_Cfg_DTCAttributes[flDTCTableRef].FreezeFrameRecordSupported != FALSE)
                        {
                          flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flDTCTableRef].FreezeFrameRecNumClassRef;
                          if(DemMaxNumberFreezeFrameRecords > flFreezeFrameRecNumClassRef)
                          {
                            flNoOFFF = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].MaxNumberFreezeFrameRecords;
                            for(flFFIndex = 0U; flFFIndex < flNoOFFF; flFFIndex++)
                            {
                              flFreezeFrameRecordClassRef = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].FreezeFrameRecordClassRef[flFFIndex];
                              /* Check for record number match */
#if(DemDevAdditionalCoverityChecks == TRUE)
                              if(DemMaxNumberFreezeFrameRecords > flFreezeFrameRecordClassRef)
#endif
                              {
                                flFreezeFrameRecordNumClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].NoofFFClass;
                                for(flFFClassIndex = 0U; flFFClassIndex < flFreezeFrameRecordNumClassRef; flFFClassIndex++)
                                {
                                  flRecordNumber = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].Number;
                                  fl_RetVal = DEM_E_WRONG_RECORDNUMBER;
                                  if(RecordNumber == flRecordNumber)
                                  {
                                    flFreezeFrameClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].FreezeFrameClassRef[flFFClassIndex];
                                    flNoOfDid = DemFreezeFrameClass[flFreezeFrameClassRef].NoOfDid;
                                    for(flDIDIndex = 0U; flDIDIndex < flNoOfDid; flDIDIndex++)
                                    {
                                      flDemDidClassRef = DemFreezeFrameClass[flFreezeFrameClassRef].DidClassRef[flDIDIndex];
                                      #if(DemDevAdditionalCoverityChecks == TRUE)
                                      if(DemMaxNumberFreezeFrameDID > flDemDidClassRef)
                                      #endif
                                      {
                                        flExternalDataElementClassRef = DemDidClass[flDemDidClassRef].ExternalDataElementClassRef;
                                        fl_RetVal = DEM_E_WRONG_DIDNUMBER;
                                        if(DemDidClass[flDemDidClassRef].Did == DataId)
                                        {
                                          #if(DemDevAdditionalCoverityChecks == TRUE)
                                          if(DEM_NUM_OF_EXTERNALRECORDDATA > flExternalDataElementClassRef)
                                          #endif
                                          {
                                            if((*BufSize) < Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize)
                                            {
                                              *BufSize = Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                                            }
                                          }
                                          for(flDestBufferIndex = 0u; flDestBufferIndex < (*BufSize); flDestBufferIndex++)
                                          {
                                            #if(DemDevAdditionalCoverityChecks == TRUE)
                                            if(flDataPointer < DemMaxLengthFreezeFrameData)
                                            #endif
                                            {
                                              DestBuffer[flDestBufferIndex] = flEntry->SnapshotData[flFFIndex][flDataPointer];
                                              flDataPointer++;
                                            }
                                          }
                                          flDIDIndex = flNoOfDid;
                                          fl_RetVal = E_OK;
                                        }
                                        #if(DemDevAdditionalCoverityChecks == TRUE)
                                        if(DEM_NUM_OF_EXTERNALRECORDDATA > flExternalDataElementClassRef)
                                        #endif
                                        {
                                          flDataPointer += Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                                        }
                                      }
                                    }
                                    flFFIndex = flNoOFFF;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else
          {
            if(RecordNumber == 0x00)
            {
              fl_RetVal = DEM_E_WRONG_RECORDNUMBER;
            }
          }
        }
      }
    }
  }
  return fl_RetVal;
}
#endif

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
Std_ReturnType Dem_GetEventExtendedDataRecordEx(Dem_EventIdType EventId,
                                                uint8 RecordNumber,
                                                uint8* DestBuffer,
                                                uint16* BufSize)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
  uint8 SizeofExtendedData = 0U;
  uint16 MemIndex = 0U;
  Dem_Cfg_PrimaryMemEntryType *MemoryPointer;
  uint16 Dataindex = 0U;
  uint8 RecordIndex = 0U;
  uint16 arrayindex = 0UL;
  uint8 ExtRecNumber = 0U;
  uint8 flRecNumber = 0U;
  uint8 flNo_of_Rec = 0U;
  uint8 ExtDataRecContainerindex = 0U;
  uint8 DataTableindex = 0U;
  uint8 loopcount = 0U;
  uint8 index = 0U;
  uint8 flrecindex = 0U;
  uint8 DataRecTypeIndex = 0U;
  uint16 flIndex = 0U;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint16 flIndex_1 = 0U;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif
  DemIntDataElementType fldataElement = DEM_EXTENDED_DATA_INIT;
  Dem_Cfg_PrimaryMemEntryType *flEntry;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if(EventId > Dem_Cfg_Num_Of_DTC)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex_1 = DEM_CALCULATE_INDEX(EventId);
    flMask = DEM_CALCULATE_MASK_BIT(EventId);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex_1], flMask);

    if(FALSE != flAvailableCondition)
#endif
    {
      uint8 ref = Dem_Cfg_DTC[EventId].AttrbsRef;
      if(ref <= Dem_Cfg_Num_Of_DTC)
      {
        if (FALSE != Dem_Cfg_DTCAttributes[ref].ExtDataRecordSupported)
        {
          ExtDataRecContainerindex = Dem_Cfg_DTCAttributes[ref].ExtDataRecordContainerRef;
  #if(DemDevAdditionalCoverityChecks == TRUE)
          if(ExtDataRecContainerindex < DEM_NUM_OF_EXTENDEDRECORD_COMBINATION)
  #endif
          {
            flNo_of_Rec = Dem_Cfg_ExtDataRecordContainer[ExtDataRecContainerindex].NoOfExtdataRecord;
            for (index = 0; ((index < flNo_of_Rec) && (DEM_ONE != loopcount)); index++)
            {
              if (DEM_0xFF == RecordNumber)
              {
                DataTableindex = Dem_Cfg_ExtDataRecordContainer[ExtDataRecContainerindex].DemExtendedDataRecordClassTypeRef[index];
  #if(DemDevAdditionalCoverityChecks == TRUE)
                if(DataTableindex < DEM_NUM_OF_EXTENDEDRECORD)
  #endif
                {
                  ExtRecNumber = Dem_Cfg_ExtRecordParameter[DataTableindex].DemExtendedDataRecordNumber;
                }
              }
              else
              {
                ExtRecNumber = RecordNumber;
                for (flrecindex = 0U; ((flrecindex < flNo_of_Rec) && (DEM_ONE != loopcount)); flrecindex++)
                {
                  DataTableindex = Dem_Cfg_ExtDataRecordContainer[ExtDataRecContainerindex].DemExtendedDataRecordClassTypeRef[flrecindex];
  #if(DemDevAdditionalCoverityChecks == TRUE)
                  if(DataTableindex < DEM_NUM_OF_EXTENDEDRECORD)
  #endif
                  {
                    flRecNumber = Dem_Cfg_ExtRecordParameter[DataTableindex].DemExtendedDataRecordNumber;
                    if (RecordNumber == flRecNumber)
                    {
                      loopcount = DEM_ONE;
                    }
                  }
  #if(DemDevAdditionalCoverityChecks == TRUE)
                  else
                  {
                    loopcount = DEM_ONE; // safety
                  }
  #endif
                }
              }
              if((loopcount != FALSE) || (RecordNumber == DEM_0xFF))
              {
                /*GET the size of ExtendedRecordData*/
  #if(DemDevAdditionalCoverityChecks == TRUE)
                if(DataTableindex < DEM_NUM_OF_EXTENDEDRECORD)
  #endif
                {
                  DataRecTypeIndex = Dem_Cfg_ExtRecordParameter[DataTableindex].DemExtendedDataClassRef;
  #if(DemDevAdditionalCoverityChecks == TRUE)
                  if(DataRecTypeIndex < DEM_NUM_OF_EXTENDEDRECORD)
  #endif
                  {
                    uint8 Ref = Dem_Cfg_ExtDataClass[DataRecTypeIndex].DemDataElementRef;
                    if (InternalDataElementClass == Dem_Cfg_ExtDataClass[DataRecTypeIndex].DemDataElementType)
                    {
  #if(DemDevAdditionalCoverityChecks == TRUE)
                    if(Ref < DEM_NUM_OF_INTERNALRECORDDATA)
  #endif
                      {
                        SizeofExtendedData = Dem_Cfg_InternalExtDataElement[Ref].DemIntDataElementDataSize;
                        fldataElement = Dem_Cfg_InternalExtDataElement[Ref].DemInternalDataElement;
                      }
  #if(DemDevAdditionalCoverityChecks == TRUE)
                      else
                      {
                        SizeofExtendedData = 0u;
                      }
  #endif
                    }
                    else
                    {
  #if(DemDevAdditionalCoverityChecks == TRUE)
                    if(Ref < DEM_NUM_OF_EXTERNALRECORDDATA)
  #endif
                      {
                        SizeofExtendedData = Dem_Cfg_ExternalExtDataElement[Ref].DemDataElementDataSize;
                      }
  #if(DemDevAdditionalCoverityChecks == TRUE)
                      else
                      {
                        SizeofExtendedData = 0u;
                      }
  #endif
                    }
                  }
  #if(DemDevAdditionalCoverityChecks == TRUE)
                  else
                  {
                    SizeofExtendedData = 0u;
                  }
  #endif
                  if (0u != SizeofExtendedData)
                  {
                    /*Loop to memory index using EventID */
                    for (flIndex = Dem_Cfg_Mem_Primary_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry; flIndex++)
                    {
                      flEntry = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[flIndex];
                      if (flEntry->EventId == EventId)
                      {
                        MemIndex = (uint16)flIndex;
                        fl_RetVal = E_OK;
                        break;
                      }
                      else
                      {
                        /*No Event*/
                        fl_RetVal = DEM_E_NODATAAVAILABLE;
                      }
                    }
                    if (E_OK == fl_RetVal)
                    {
                      MemoryPointer = (Dem_Cfg_PrimaryMemEntryType *)Dem_Cfg_MemPtr[MemIndex];
                      if (MemoryPointer != NULL)
                      {
                        Dataindex = 0U;
                        DestBuffer[RecordIndex] = ExtRecNumber;
                        RecordIndex++;
                        *BufSize = *BufSize + DEM_ONE;
                        Dataindex++;
                        if (InternalDataElementClass == Dem_Cfg_ExtDataClass[DataRecTypeIndex].DemDataElementType)
                        {
                          Dem_UpdateExtendedRecord(EventId, MemoryPointer, &DestBuffer[RecordIndex], fldataElement, SizeofExtendedData);
                          RecordIndex += SizeofExtendedData;
                          *BufSize = *BufSize + SizeofExtendedData;
                        }
                        else
                        {
                          fl_RetVal = Dem_InternalGetExtDataRecMemoryIndex(EventId, ExtRecNumber, &arrayindex);
                          if (E_OK == fl_RetVal)
                          {
                            for ( ; RecordIndex < SizeofExtendedData + DEM_ONE; RecordIndex++)
                            {
  #if(DemDevAdditionalCoverityChecks == TRUE)
                              if((Dataindex <= DEM_MAX_LENGTH_OF_EXTENDEDRECORD) && (arrayindex < DEM_NUM_OF_EXTENDEDRECORD))
  #endif
                              {
                                DestBuffer[RecordIndex] = MemoryPointer->ExtendedDataRecord[arrayindex][Dataindex];
                              }
                              *BufSize = *BufSize + DEM_ONE;
                              Dataindex++;
                            }
                          }
                        }
                      }
                      else
                      {
                        /* code */
                        fl_RetVal = DEM_E_NODATAAVAILABLE;
                      }
                    }
                  } // END of if (0!= SizeofExtendedData)
                }
              }
            } //for (uint8 index = 0; ((index < flNo_of_Rec) && (1 != loopcount )); index++)
          }
        }
        else
        {
          /* NO Ext Data Record */
          fl_RetVal = DEM_E_WRONG_RECORDNUMBER;
        }
      }
    }
  }
  return fl_RetVal;
}
#endif //#if (DEM_NUM_OF_EXTENDEDRECORD > 0)

/**************************************************************************
 Function name   : Dem_GetEventMemoryOverflow
 Arguments       : Dem_DTCOriginType DTCOrigin, boolean* OverflowIndication
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Gets the event memory overflow indication status.
 **************************************************************************/
Std_ReturnType Dem_GetEventMemoryOverflow(uint8 ClientId, Dem_DTCOriginType DTCOrigin, boolean* OverflowIndication)
{
  Std_ReturnType fl_RetVal;
  uint8 flIndex;
  fl_RetVal = E_NOT_OK;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients)||(DEM_DTC_ORIGIN_INVALID == DTCOrigin))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    fl_RetVal = E_OK;
    for(flIndex = 0u; flIndex < Dem_Cfg_Num_Of_EventMemorySet; flIndex++)
    {
      if(Dem_MemStatus[flIndex].EventOrigin == DTCOrigin)
      {
        *OverflowIndication = Dem_Cfg_StatusData.MemoryOverflow[flIndex];
        break;
      }
    }
  }
  return fl_RetVal;
}


/**************************************************************************
 Function name   : Dem_GetNumberOfEventMemoryEntries
 Arguments       : Dem_DTCOriginType DTCOrigin, uint8* NumberOfEventMemoryEntries
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : Returns the number of entries currently stored in the
 requested event memory.
 **************************************************************************/
Std_ReturnType Dem_GetNumberOfEventMemoryEntries(uint8 ClientId, Dem_DTCOriginType DTCOrigin, uint8* NumberOfEventMemoryEntries)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SetComponentAvailable
 Arguments       : Dem_ComponentIdType ComponentId, boolean AvailableStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Set the availability of a specific DemComponent.
 **************************************************************************/
Std_ReturnType Dem_SetComponentAvailable(Dem_ComponentIdType ComponentId,
    boolean AvailableStatus)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_OK;
  return fl_RetVal;
}

#if(DEM_SUPPRESSION_SUPPORT == STD_ON)
/**************************************************************************
 Function name   : Dem_SetDTCSuppression
 Arguments       : uint32 DTC, Dem_DTCFormatType DTCFormat,
 boolean SuppressionStatus
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Set the suppression status of a specific DTC.
 **************************************************************************/
Std_ReturnType Dem_SetDTCSuppression(uint8 ClientId,boolean SuppressionStatus)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
  uint8 flIndex;
  uint8 flMask;
  Dem_EventIdType flEventId = 0;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    if(Dem_GetDTCSelectionResult(ClientId) == E_OK)
    {
      flEventId = Dem_InternalGetEventIdByDTCValue(Dem_DTCSelector[ClientId].DTC); 
      if((flEventId != DEM_EVENT_INVALID) && (flEventId < Dem_Cfg_Num_Of_Event))
      {
        flIndex = DEM_CALCULATE_INDEX(flEventId);
        flMask = DEM_CALCULATE_MASK_BIT(flEventId);
         if(SuppressionStatus == TRUE)
         {
           DEM_SET_BIT_STATE(Dem_Event.SuppressionState[flIndex], flMask);
         }
         else
         {
           DEM_RESET_BIT_STATE(Dem_Event.SuppressionState[flIndex], flMask);
         }  
      }
    }
  }
  return fl_RetVal;
}
#endif

/**************************************************************************
 Function name   : Dem_GetTranslationType
 Arguments       : uint8 ClientId
 Return type     : Dem_DTCTranslationFormatType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the supported DTC formats of the ECU.
 The supported formats are configured via DemTypeOfDTCSupported.
 **************************************************************************/
Dem_DTCTranslationFormatType Dem_GetTranslationType(uint8 ClientId)
{
  Dem_DTCTranslationFormatType fl_RetVal;
  fl_RetVal = DEM_DTC_TRANSLATION_ISO14229_1;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetDTCStatusAvailabilityMask
 Arguments       : Dem_UdsStatusByteType* DTCStatusMask
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the DTC Status availability mask.
 **************************************************************************/
Std_ReturnType Dem_GetDTCStatusAvailabilityMask(uint8 ClientId, Dem_UdsStatusByteType* DTCStatusMask)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = E_NOT_OK;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((DTCStatusMask == NULL_PTR) || (ClientId >= Dem_Cfg_Num_Of_Clients))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    *DTCStatusMask = Dem_GetStatusAvailabilityMask();
    fl_RetVal = E_OK;
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_InternalGetEventIdByDTCValue
 Arguments       :
 Return type     : Dem_EventIdType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     :
 **************************************************************************/
static Dem_EventIdType Dem_InternalGetEventIdByDTCValue(uint32 DTC)
{
  Dem_EventIdType flEventId;
  uint8 flMatch;
  uint16 flDtcRef;

  flMatch = E_NOT_OK;
  flEventId = DEM_EVENT_INVALID;

  if (DTC != DEM_DTC_INVALID)
  {
    for (flDtcRef = DEM_DTC_VALID_START; flDtcRef <= Dem_Cfg_Num_Of_DTC; flDtcRef++)
    {
      if (Dem_Cfg_DTC[flDtcRef].Value == DTC)
      {
        flMatch = E_OK;
        break;
      }
    }
    if(flMatch == E_OK)
    {
      for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event;
          flEventId++)
      {
        if (flDtcRef == Dem_Cfg_EventParameter[flEventId].DTCTableRef)
        {
          flMatch = E_OK;
          break;
        }
      }
    }
  }
  if(flMatch == E_NOT_OK)
  {
    flEventId = DEM_EVENT_INVALID;
  }
  return flEventId;
}

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
Std_ReturnType Dem_GetStatusOfDTC(uint8 ClientId, uint8* DTCStatus)
{
  Std_ReturnType fl_RetVal = DEM_STATUS_WRONG_DTCORIGIN;
  Dem_EventIdType flEventId = 0;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = DEM_STATUS_FAILED;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (DTCStatus == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_STATUS_FAILED;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0, flError);
  }
  else
#endif
  {
    flEventId = Dem_InternalGetEventIdByDTCValue(Dem_DTCSelector[ClientId].DTC);
    fl_RetVal = DEM_STATUS_WRONG_DTC;
    *DTCStatus = 0x0;
    if((flEventId != DEM_EVENT_INVALID) && (flEventId < Dem_Cfg_Num_Of_Event))
    {
      *DTCStatus = (Dem_Cfg_StatusData.EventStatus[flEventId]
                  & Dem_GetStatusAvailabilityMask());
      fl_RetVal = DEM_STATUS_OK;
    }
    Dem_DTCSelector[ClientId].ActiveOps = 0;
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_GetSeverityOfDTC(uint8 ClientId, Dem_DTCSeverityType* DTCSeverity)

{
  Std_ReturnType fl_RetVal;
  Dem_EventIdType flEventId;

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
  }
  else if ((Dem_DTCSelector[ClientId].DTC == DEM_DTC_INVALID)||(DTCSeverity == NULL))
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flEventId = Dem_InternalGetEventIdByDTCValue(Dem_DTCSelector[ClientId].DTC);
    fl_RetVal = DEM_GET_SEVERITYOFDTC_WRONG_DTC;
    *DTCSeverity = 0x0;
    if((flEventId != DEM_EVENT_INVALID) && (flEventId <= Dem_Cfg_Num_Of_DTC))
    {
      *DTCSeverity = Dem_Cfg_DTC[flEventId].Severity;
      fl_RetVal = DEM_GET_SEVERITYOFDTC_OK;
      Dem_DTCSelector[ClientId].ActiveOps = 0;
    }
  }
  return fl_RetVal;
}
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
Std_ReturnType Dem_GetFunctionalUnitOfDTC(uint8 ClientId, uint8* DTCFunctionalUnit)
{
  Std_ReturnType fl_RetVal;
  Dem_EventIdType flEventId;

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
  }
  else if (Dem_DTCSelector[ClientId].DTC == DEM_DTC_INVALID)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    fl_RetVal = DEM_GET_FUNCTIONALUNITOFDTC_WRONG_DTC;
    flEventId = Dem_InternalGetEventIdByDTCValue(Dem_DTCSelector[ClientId].DTC);
    *DTCFunctionalUnit = 0x0;
    if((flEventId != DEM_EVENT_INVALID) && (flEventId <= Dem_Cfg_Num_Of_DTC))
    {
      *DTCFunctionalUnit = Dem_Cfg_DTC[flEventId].DTCFunctionalUnit;
      fl_RetVal = DEM_GET_FUNCTIONALUNITOFDTC_OK;
    }
    Dem_DTCSelector[ClientId].ActiveOps = 0;
  }
  return fl_RetVal;
}
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
Std_ReturnType Dem_SetDTCFilter(uint8 ClientId, uint8 DTCStatusMask, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin, boolean FilterWithSeverity, Dem_DTCSeverityType DTCSeverityMask, boolean FilterForFaultDetectionCounter)
{
  Std_ReturnType fl_RetVal;
  fl_RetVal = DEM_WRONG_FILTER;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if ((DTCFormat == DEM_DTC_FORMAT_INVALID)||(DEM_DTC_ORIGIN_INVALID == DTCOrigin))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    if (DTCFormat == DEM_DTC_FORMAT_UDS)
    {
      fl_RetVal = DEM_FILTER_ACCEPTED;
      Dem_FilterInfo[ClientId].Origin = DTCOrigin;
      Dem_FilterInfo[ClientId].Req_Status = 0x00U;
      Dem_FilterInfo[ClientId].EventIndex = DEM_EVENT_VALID_ID_START;

      if (DTCStatusMask == 0x00U)
      {
        DEM_DCM_RESET_USESTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_Status);
        Dem_FilterInfo[ClientId].Dtc_StatusMask = 0x00u; // No filter
      }
      else
      {
        Dem_FilterInfo[ClientId].Dtc_StatusMask = (DTCStatusMask & Dem_GetStatusAvailabilityMask());
        DEM_DCM_SET_USESTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_Status);
      }
#if (SeveritySuppotEnabled == STD_ON)
      if (FilterWithSeverity == DEM_FILTER_WITH_SEVERITY_YES)
      {
        if((DTCSeverityMask & DemDTCSeverityMask) != FALSE)
        {
            Dem_FilterInfo[ClientId].Dtc_SeverityMask = (DTCSeverityMask & DemDTCSeverityMask);
            DEM_DCM_SET_USESEVERITYSTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_SeverityStatus);
            DEM_DCM_RESET_USESTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_Status);
        }
        else
        {
          Dem_FilterInfo[ClientId].Dtc_SeverityMask = 0x00u; //No Severity Filter
        }
      }
#endif
      if(DEM_FILTER_FOR_FDC_YES == FilterForFaultDetectionCounter)
      {
        DEM_DCM_SET_USEFDC_FLAG(Dem_FilterInfo[ClientId].Req_Status);
      }
      else
      {
        DEM_DCM_RESET_USEFDC_FLAG(Dem_FilterInfo[ClientId].Req_Status);
      }
    }
  }
  return fl_RetVal;
}


/**************************************************************************
 Function name   : Dem_InternalFilterMatchEvent
 Arguments       :
 Return type     :
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :
 **************************************************************************/
static Std_ReturnType Dem_InternalFilterMatchEvent(uint8 ClientId, Dem_EventIdType flEventId)
{
  Std_ReturnType fl_ReturnVal = E_NOT_OK;
  uint8 flOrigin = 0;
  sint8 flFdc = 0;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if((flEventId >= Dem_Cfg_Num_Of_Event))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flOrigin = Dem_FilterInfo[ClientId].Origin;
    if(flOrigin == Dem_Cfg_EventParameter[flEventId].DemOrigin)
    {
      if(DEM_DCM_GET_USESTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_Status) != FALSE)
      {
        if(   (Dem_Cfg_StatusData.EventStatus[flEventId] & Dem_FilterInfo[ClientId].Dtc_StatusMask)
           && DEM_DCM_GET_USESTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_Status))
        {
          fl_ReturnVal = E_OK;
        }
      }
      #if (SeveritySuppotEnabled == STD_ON)
      else if(DEM_DCM_GET_USESEVERITYSTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_SeverityStatus) != FALSE)
      {
        if((Dem_FilterInfo[ClientId].Dtc_SeverityMask != FALSE) && (Dem_FilterInfo[ClientId].Dtc_StatusMask != FALSE))
        {
          /* Implements ISO 14229:13 chapter 11.3.1.8 */
          if(   (Dem_Cfg_DTC[flEventId].Severity & Dem_FilterInfo[ClientId].Dtc_SeverityMask)
             && (Dem_Cfg_StatusData.EventStatus[flEventId] & Dem_FilterInfo[ClientId].Dtc_StatusMask))
          {
            fl_ReturnVal = E_OK;
          }
        }
      }
      else
      {
        /*DO NOTHING - MISRA FIX*/
      }
      #endif
      if(DEM_DCM_GET_USEFDC_FLAG(Dem_FilterInfo[ClientId].Req_Status))
      {
        if(E_OK == Dem_GetFaultDetectionCounter(flEventId, &flFdc))
        {
          if((flFdc > 0U) && (flFdc <= 0x7E))
          {
            fl_ReturnVal = E_OK;
          }
        }
      }
    }
  }
  return fl_ReturnVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetNumberOfFilteredDTC
 Arguments       : uint8 ClientId, uint16* NumberOfFilteredDTC
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the number of a filtered DTC.
 **************************************************************************/
Std_ReturnType Dem_GetNumberOfFilteredDTC(uint8 ClientId, uint16* NumberOfFilteredDTC)
{
  Std_ReturnType fl_RetVal = DEM_NUMBER_FAILED;
  uint16 flNumberofFilteredDtc = 0x00U;
  Dem_EventIdType flEventId;
  uint8 flDtcTableRef;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else if (NumberOfFilteredDTC == NULL_PTR)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dcm_SesCtrlType flSessionIndex = 0u;
    (void) Dcm_GetSesCtrlTypeIndex (&flSessionIndex);

    for (flEventId = DEM_EVENT_VALID_ID_START; flEventId < Dem_Cfg_Num_Of_Event; flEventId++)
    {
      if((Dem_Cfg_EventParameter[flEventId].AvailableStatus != FALSE)
         && (Dem_Cfg_EventParameter[flEventId].DTCTableRef != 0))
      {
        flDtcTableRef = Dem_Cfg_EventParameter[flEventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
        if(flDtcTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
        {
          if((Dem_Cfg_DTC[flDtcTableRef].Sess_Ref & (DEM_ONE << flSessionIndex)) != 0)
          {
            if(E_NOT_OK != Dem_InternalFilterMatchEvent(ClientId, flEventId))
            {
              flNumberofFilteredDtc++;
            }
          }
        }
      }
    }
    *NumberOfFilteredDTC = flNumberofFilteredDtc;
    fl_RetVal = DEM_NUMBER_OK;
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_GetNextFilteredDTC(uint8 ClientId, uint32* DTC, uint8* DTCStatus)
{
  Std_ReturnType fl_RetVal = DEM_NO_SUCH_ELEMENT;
  uint8 flDtcTableRef;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((DTC == NULL_PTR) || (DTCStatus == NULL_PTR) || (ClientId >= Dem_Cfg_Num_Of_Clients))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dcm_SesCtrlType flSessionIndex = 0u;
    (void) Dcm_GetSesCtrlTypeIndex (&flSessionIndex);
    while(   (fl_RetVal == DEM_NO_SUCH_ELEMENT)
          && (Dem_FilterInfo[ClientId].EventIndex < Dem_Cfg_Num_Of_Event))
    {
      if(   (Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].AvailableStatus != FALSE)
         && (Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].DTCTableRef != 0)
         &&    (Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].DemOrigin == Dem_FilterInfo[ClientId].Origin))
      {
        flDtcTableRef = Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
        if(flDtcTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
        {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
          flIndex = DEM_CALCULATE_INDEX(Dem_FilterInfo[ClientId].EventIndex);
          flMask = DEM_CALCULATE_MASK_BIT(Dem_FilterInfo[ClientId].EventIndex);
          flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);

          if(FALSE != flAvailableCondition)
#endif
          {
            if((Dem_Cfg_DTC[flDtcTableRef].Sess_Ref &  (DEM_ONE << flSessionIndex)) != 0)
            {
              if (DEM_DCM_GET_USESTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_Status))
              {
                /* DTC uses filter */
                if (FALSE != (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo[ClientId].EventIndex]
                        & Dem_FilterInfo[ClientId].Dtc_StatusMask))
                {
                  *DTC = Dem_Cfg_DTC[flDtcTableRef].Value;
                  *DTCStatus = (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo[ClientId].EventIndex]
                      & Dem_GetStatusAvailabilityMask());
                  fl_RetVal = DEM_FILTERED_OK;
                }
              }
              else
              {
                *DTC = Dem_Cfg_DTC[flDtcTableRef].Value;
                *DTCStatus = (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo[ClientId].EventIndex]
                    & Dem_GetStatusAvailabilityMask());
                fl_RetVal = DEM_FILTERED_OK;
              }
            }
          }
        }
      }
      Dem_FilterInfo[ClientId].EventIndex++;
    }
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_GetNextFilteredDTCAndFDC(uint8 ClientId, uint32* DTC, sint8* DTCFaultDetectionCounter)
{
  uint8 flDtcTableRef;
  Std_ReturnType fl_RetVal = DEM_NO_SUCH_ELEMENT;
  uint8 flEventIndex;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((DTC == NULL_PTR) || (DTCFaultDetectionCounter == NULL_PTR) || (ClientId >= Dem_Cfg_Num_Of_Clients))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dcm_SesCtrlType flSessionIndex = 0u;
    (void) Dcm_GetSesCtrlTypeIndex (&flSessionIndex);

    while(   (fl_RetVal == DEM_NO_SUCH_ELEMENT)
          && (Dem_FilterInfo[ClientId].EventIndex < Dem_Cfg_Num_Of_Event)
          &&    (Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].DemOrigin == Dem_FilterInfo[ClientId].Origin))
    {
      flEventIndex = Dem_FilterInfo[ClientId].EventIndex;
        if(E_OK == Dem_GetFaultDetectionCounter((Dem_EventIdType)flEventIndex, DTCFaultDetectionCounter))
        {
          flDtcTableRef = Dem_Cfg_EventParameter[flEventIndex].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
          if(flDtcTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
          {
            if((Dem_Cfg_DTC[flDtcTableRef].Sess_Ref &  (DEM_ONE << flSessionIndex)) != 0)
            {
              *DTC = Dem_Cfg_DTC[flDtcTableRef].Value;
              fl_RetVal = DEM_FILTERED_OK;
            }
          }
        }
      Dem_FilterInfo[ClientId].EventIndex++;
    }
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_GetNextFilteredDTCAndSeverity(uint8 ClientId, uint32* DTC, uint8* DTCStatus, Dem_DTCSeverityType* DTCSeverity, uint8* DTCFunctionalUnit)
{
  Std_ReturnType fl_RetVal;
  uint8 flDtcTableRef;
  fl_RetVal = DEM_NO_SUCH_ELEMENT;

#if(DemDevErrorDetect == TRUE)
  uint8 flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (DTC == NULL_PTR) || (DTCStatus == NULL_PTR) ||
                                                    (DTCSeverity == NULL_PTR) || (DTCFunctionalUnit == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dcm_SesCtrlType flSessionIndex = 0u;
    (void) Dcm_GetSesCtrlTypeIndex (&flSessionIndex);

    while(   (fl_RetVal == DEM_NO_SUCH_ELEMENT)
          && (Dem_FilterInfo[ClientId].EventIndex < Dem_Cfg_Num_Of_Event)
          &&    (Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].DemOrigin == Dem_FilterInfo[ClientId].Origin))
    {
      if(   (Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].AvailableStatus != FALSE)
         && (Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].DTCTableRef != FALSE))
      {
        flDtcTableRef = Dem_Cfg_EventParameter[Dem_FilterInfo[ClientId].EventIndex].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
        if(flDtcTableRef <= Dem_Cfg_Num_Of_DTC)
#endif
        {
          if((Dem_Cfg_DTC[flDtcTableRef].Sess_Ref & (DEM_ONE << flSessionIndex)) != 0)
          {
            if (DEM_DCM_GET_USESEVERITYSTATUSMASK_FLAG(Dem_FilterInfo[ClientId].Req_SeverityStatus))
            {
    #if (SeveritySuppotEnabled == STD_ON)
              /* DTC uses filter */
              if(FALSE != (   (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo[ClientId].EventIndex] & Dem_FilterInfo[ClientId].Dtc_StatusMask)
                          && (Dem_Cfg_DTC[Dem_FilterInfo[ClientId].EventIndex].Severity & Dem_FilterInfo[ClientId].Dtc_SeverityMask)))
                {
                  *DTC = Dem_Cfg_DTC[flDtcTableRef].Value;
                  *DTCStatus = (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo[ClientId].EventIndex]
                              & Dem_GetStatusAvailabilityMask());
                  *DTCSeverity = Dem_Cfg_DTC[flDtcTableRef].Severity;
                  *DTCFunctionalUnit = Dem_Cfg_DTC[flDtcTableRef].DTCFunctionalUnit;
                  fl_RetVal = DEM_FILTERED_OK;
                }
    #endif
            }
            else
            {
              *DTC = Dem_Cfg_DTC[flDtcTableRef].Value;
              *DTCStatus = (Dem_Cfg_StatusData.EventStatus[Dem_FilterInfo[ClientId].EventIndex]
                          & Dem_GetStatusAvailabilityMask());
              fl_RetVal = DEM_FILTERED_OK;
            }
          }
        }
      }
      Dem_FilterInfo[ClientId].EventIndex++;
    }
  }
  return fl_RetVal;
}

#if (DemMaxNumberFreezeFrameRecords > 0)
/**************************************************************************
 Function name   : Dem_SetFreezeFrameRecordFilter
 Arguments       : uint8 ClientId,Dem_DTCFormatType DTCFormat,uint16* NumberOfFilteredRecords
 Return type     : Dem_ReturnSetFilterType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Sets a freeze frame record filter.
 **************************************************************************/
Std_ReturnType Dem_SetFreezeFrameRecordFilter(uint8 ClientId,Dem_DTCFormatType DTCFormat,uint16* NumberOfFilteredRecords)
{
  Std_ReturnType fl_RetVal= DEM_WRONG_FILTER;
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  uint8 flMemIndex = 0u;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (DTCFormat >= DEM_DTC_FORMAT_INVALID) || (NumberOfFilteredRecords == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    if(DTCFormat == DEM_DTC_FORMAT_UDS)
    {
      for (flMemIndex = Dem_Cfg_Mem_Primary_Entry_Start; flMemIndex < Dem_Cfg_Mem_Total_Entry; flMemIndex++)
      {
         flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
         if((flEntry->EventId != DEM_EVENT_INVALID) && (flEntry->EventId < Dem_Cfg_Num_Of_Event))
         {
           //SnahpshotHeader will have the Number of Records stored
           if(flEntry->SnahpshotHeader <= DemMaxNumberFreezeFrameRecords)
           {
              *NumberOfFilteredRecords += flEntry->SnahpshotHeader;
           }
         }
      }
      fl_RetVal = DEM_FILTER_ACCEPTED;
      Dem_FilterInfo[ClientId].EventIndex = DEM_EVENT_VALID_ID_START;
      Dem_FilterInfo[ClientId].FFRecIndex = 0u;
      Dem_FilterInfo[ClientId].FFStatus = 0u;
      Dem_FilterInfo[ClientId].MemIndex = Dem_Cfg_Mem_Primary_Entry_Start;
      DEM_DCM_SET_USEFREEZEFRAMERECORDMASK_FLAG(Dem_FilterInfo[ClientId].FFStatus);
    }
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_GetNextFilteredRecord(uint8 ClientId, uint32* DTC, uint8* RecordNumber)
{
  Std_ReturnType fl_RetVal = DEM_NO_SUCH_ELEMENT;
  #if(DemTypeOfFreezeFrameRecordNumeration != DEM_FF_RECNUM_CALCULATED)
  Dem_Cfg_PrimaryMemEntryType *flEntry;
  Dem_EventIdType flEventId = 0u;
  uint8 flError = DEM_DET_NO_ERROR;
  uint8 flMemIndex = 0u;
  uint8 flFFIndex = 0u;
  uint8 flDTCAttributesRef = 0u;
  uint8 flFreezeFrameRecNumClassRef = 0u;
  uint8 flFreezeFrameRecordClassRef = 0;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
  uint8 flIndex;
  uint8 flMask;
  uint8 flAvailableCondition;
#endif

#if(DemDevErrorDetect == TRUE)
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (DTC == NULL_PTR) || (RecordNumber == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flMemIndex = Dem_FilterInfo[ClientId].MemIndex;
    flFFIndex = Dem_FilterInfo[ClientId].FFRecIndex;
    while(flMemIndex < Dem_Cfg_Mem_Total_Entry)
    {
      flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flMemIndex];
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(NULL != flEntry)
#endif
      {
        flEventId = flEntry->EventId;
        if((flEventId != DEM_EVENT_INVALID) && (flEventId < Dem_Cfg_Num_Of_Event))
        {
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
          flIndex = DEM_CALCULATE_INDEX(flEventId);
          flMask = DEM_CALCULATE_MASK_BIT(flEventId);
          flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);

          if(FALSE != flAvailableCondition)
#endif
          {
            if(flFFIndex < flEntry->SnahpshotHeader)
            {
              *DTC = Dem_Cfg_DTC[flEventId].Value;
              flDTCAttributesRef = Dem_Cfg_DTC[flEventId].AttrbsRef;
              if((flDTCAttributesRef <= Dem_Cfg_Num_Of_DTC) && (FALSE != Dem_Cfg_DTCAttributes[flDTCAttributesRef].FreezeFrameRecordSupported))
              {
                flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flDTCAttributesRef].FreezeFrameRecNumClassRef;
                if(DemMaxNumberFreezeFrameRecords > flFreezeFrameRecNumClassRef)
                {
                  flFreezeFrameRecordClassRef = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].FreezeFrameRecordClassRef[flFFIndex];
#if(DemDevAdditionalCoverityChecks == TRUE)
                  if(DemMaxNumberFreezeFrameRecords > flFreezeFrameRecordClassRef)
#endif
                  {
                    *RecordNumber = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].Number;
                    flFFIndex++;
                    fl_RetVal = DEM_FILTERED_OK;
                    break;
                  }
                }
              }
            }
            else
            {
              flFFIndex = 0u;
              flMemIndex++;
            }
          }
        }
        else
        {
          flMemIndex++;
        }
      }
    }
    Dem_FilterInfo[ClientId].FFRecIndex = flFFIndex;
    Dem_FilterInfo[ClientId].MemIndex = flMemIndex;
  }
  #endif
 return fl_RetVal;
}
#endif /*(DemMaxNumberFreezeFrameRecords > 0)*/

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
Std_ReturnType Dem_GetDTCByOccurrenceTime(uint8 ClientId, Dem_DTCRequestType DTCRequest, uint32* DTC)
{
  Std_ReturnType fl_RetVal = DEM_OCCURR_NOT_AVAILABLE;
  Dem_EventIdType flEventId;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (DTCRequest > DEM_MOST_REC_DET_CONFIRMED_DTC) || (NULL_PTR == DTC))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    flEventId = DEM_EVENT_INVALID;
    switch (DTCRequest)
    {
    case DEM_FIRST_FAILED_DTC:
      flEventId = Dem_Cfg_StatusData.FirstFailedEvent;
      break;
    case DEM_MOST_RECENT_FAILED_DTC:
      flEventId = Dem_Cfg_StatusData.RecentFailedEvent;
      break;
    case DEM_FIRST_DET_CONFIRMED_DTC:
      flEventId = Dem_Cfg_StatusData.FirstConfirmedEvent;
      break;
    case DEM_MOST_REC_DET_CONFIRMED_DTC:
      flEventId = Dem_Cfg_StatusData.RecentConfirmedEvent;
      break;
    default:
       /*DoNothing*/
      break;
    }
    if((flEventId != DEM_EVENT_INVALID) && (flEventId < Dem_Cfg_Num_Of_Event))
    {
      Dcm_SesCtrlType flSessionIndex = 0u;
      (void) Dcm_GetSesCtrlTypeIndex (&flSessionIndex);

      uint8 ref = Dem_Cfg_EventParameter[flEventId].DTCTableRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(ref <= Dem_Cfg_Num_Of_DTC)
#endif
      {
        if((Dem_Cfg_DTC[ref].Sess_Ref & (DEM_ONE << flSessionIndex)) != 0)
        {
          *DTC = Dem_Cfg_DTC[ref].Value;
          if(E_OK == Dem_SelectDTC(ClientId, *DTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY))
          {
            fl_RetVal = DEM_OCCURR_OK;
          }
        }
      }
    }
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_ControlDTCStatusChangedNotification
 Arguments       : boolean TriggerNotification
 Return type     : void
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Controls the triggering of Dcm_DemTriggerOnDTCStatus.
 **************************************************************************/
void Dem_DcmControlDTCStatusChangedNotification(boolean TriggerNotification)
{
  DTCStatusChangeNotification = TriggerNotification;
}

/**************************************************************************
 Function name   : Dem_DisableDTCRecordUpdate
 Arguments       : uint8 ClientId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Disables the event memory update of a specific DTC.
 **************************************************************************/
Std_ReturnType Dem_DisableDTCRecordUpdate(uint8 ClientId)
{
  Dem_ReturnDisableDTCRecordUpdateType fl_RetVal;
  fl_RetVal = DEM_DISABLE_DTCRECUP_OK;
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_EnableDTCRecordUpdate
 Arguments       : uint8 ClientId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Enables the event memory update of the DTC disabled by
 Dem_DcmDisableDTCRecordUpdate() before.
 **************************************************************************/
Std_ReturnType Dem_EnableDTCRecordUpdate(uint8 ClientId)
{
  Dem_ReturnDisableDTCRecordUpdateType fl_RetVal;
  fl_RetVal = DEM_DISABLE_DTCRECUP_OK;
  return fl_RetVal;
}

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
Std_ReturnType Dem_SelectFreezeFrameData(uint8 ClientId, uint8 RecordNumber)
{
  Std_ReturnType fl_RetVal= E_NOT_OK;
  #if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = E_NOT_OK;
  }
  else if ((Dem_DTCSelector[ClientId].Format >= DEM_DTC_FORMAT_INVALID) || (ClientId >= Dem_Cfg_Num_Of_Clients))
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_WRONG_DTC;
  }
  else
  {
    /*Do Nothing*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
  #endif
  {
    Dem_DTCSelector[ClientId].SnapshotRecordNumber= RecordNumber;
    fl_RetVal = E_OK;
  }
  return fl_RetVal;
}
/**************************************************************************
 Function name   : Dem_GetNextFreezeFrameData
 Arguments       : uint8 ClientId, uint8* DestBuffer, uint16* BufSize
 Return type     : Dem_ReturnGetFreezeFrameDataByDTCType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets freeze frame data by DTC. The function stores the data
 in the provided DestBuffer.
 **************************************************************************/
Std_ReturnType Dem_GetNextFreezeFrameData(uint8 ClientId, uint8* DestBuffer, uint16* BufSize)
{
  Std_ReturnType fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_DTC;
#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (0x00U == Dem_DTCSelector[ClientId].Origin) || (DEM_DTC_ORIGIN_INVALID == Dem_DTCSelector[ClientId].Origin) || (BufSize == NULL_PTR) || (DestBuffer == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    uint16 MemIndex = 0U;
    uint8 flDtcAttri = 0u;
    uint8 flMatch;
    uint16 flDtcRef = 0U;
    uint8 flFFIndex = 0U;
    #if(DemTypeofFreezeFrameRecordNumeration != DEM_FF_RECNUM_CALCULATED)
    uint8 flFreezeFrameRecNumClassRef = 0U;
    uint8 flFreezeFrameRecordClassRef = 0U;
    uint8 flFreezeFrameRecordNumClassRef = 0U;
    uint8 flFFClassIndex;
    uint8 flMemEntryIndex = 0U;
    uint8 flRecordNumber = 0U;
    #endif
    uint8 flFreezeFrameClassRef = 0U;
    uint8 flDidClassRef = 0U;
    uint8 flExternalDataElementClassRef = 0U;
    uint8 flNoOFFF;
    uint8 flNoOfDid;
    uint8 flDIDIndex;
    Dem_Cfg_PrimaryMemEntryType *flMemEntry;
    uint8 flDataElementSize;
    uint8 flDataElementIndex = 0U;
    uint16 flBufferIndex = 0U;
    uint8 flIterIndex = 0u;
#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    uint8 flIndex;
    uint8 flMask;
    uint8 flAvailableCondition;
#endif

#if(DemTypeofFreezeFrameRecordNumeration != DEM_FF_RECNUM_CALCULATED)
    flMatch = E_NOT_OK;
    *BufSize = 0x0U;
    fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_DTC;
    if (Dem_DTCSelector[ClientId].DTC != DEM_DTC_INVALID)
    {
      for (flDtcRef = DEM_DTC_VALID_START; flDtcRef <= Dem_Cfg_Num_Of_DTC; flDtcRef++)
      {
        if (Dem_Cfg_DTC[flDtcRef].Value == Dem_DTCSelector[ClientId].DTC)
        {
          flDtcAttri = Dem_Cfg_DTC[flDtcRef].AttrbsRef;
          flMatch = E_OK;
          break;
        }
      }
    }

#if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex = DEM_CALCULATE_INDEX(flDtcAttri);
    flMask = DEM_CALCULATE_MASK_BIT(flDtcAttri);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);

    if(FALSE != flAvailableCondition)
#endif
    {
      if((E_OK == flMatch) && (flDtcAttri <= Dem_Cfg_Num_Of_DTC))
      {
        fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
        if((Dem_Cfg_DTCAttributes[flDtcAttri].FreezeFrameRecordSupported != FALSE) && (Dem_DTCSelector[ClientId].SnapshotRecordNumber != 0U))
        {
          if(Dem_DTCSelector[ClientId].SnapshotRecordNumber != DEM_0xFF)
          {
            flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flDtcAttri].FreezeFrameRecNumClassRef;
            if(DemMaxNumberFreezeFrameRecords > flFreezeFrameRecNumClassRef)
            {
              flNoOFFF = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].MaxNumberFreezeFrameRecords;
              flMatch = E_NOT_OK;
              for(flFFIndex = 0U; flFFIndex < flNoOFFF; flFFIndex++)
              {
                flMemEntryIndex = 0;
                flFreezeFrameRecordClassRef = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].FreezeFrameRecordClassRef[flFFIndex];
                /* Check for record number match */
                if(DemMaxNumberFreezeFrameRecords > flFreezeFrameRecordClassRef)
                {
                  flRecordNumber = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].Number;
                  if(Dem_DTCSelector[ClientId].SnapshotRecordNumber == flRecordNumber)
                  {
                    flMatch = E_OK;
                    /* Check whether there is a memory entry available for the request DTC */
                    if(DEM_GET_FFDATABYDTC_OK == Dem_InternalGetMemoryIndex(&MemIndex, Dem_DTCSelector[ClientId].DTC))
                    {
                      flFreezeFrameRecordNumClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].NoofFFClass;
                      for(flFFClassIndex = 0U; flFFClassIndex < flFreezeFrameRecordNumClassRef; flFFClassIndex++)
                      {
                        flFreezeFrameClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].FreezeFrameClassRef[flFFClassIndex];
                        flNoOfDid = DemFreezeFrameClass[flFreezeFrameClassRef].NoOfDid;
                        #if(DemDevAdditionalCoverityChecks == TRUE)
                        if(DcmDslBufferSize > flBufferIndex)
                        #endif
                        {
                          /* Record Number */
                          DestBuffer[flBufferIndex] = Dem_DTCSelector[ClientId].SnapshotRecordNumber;
                          flBufferIndex++;
                          #if(DemDevAdditionalCoverityChecks == TRUE)
                          if(DcmDslBufferSize > flBufferIndex)
                          #endif
                          {
                            /* Number Of IDdentifier */
                            DestBuffer[flBufferIndex] = flNoOfDid;
                            flBufferIndex++;
                            *BufSize += DEM_TWO;
                            for(flDIDIndex = 0U; flDIDIndex < flNoOfDid; flDIDIndex++)
                            {
                              flDidClassRef = DemFreezeFrameClass[flFreezeFrameClassRef].DidClassRef[flDIDIndex];
                              #if(DemDevAdditionalCoverityChecks == TRUE)
                              if(DcmDslBufferSize > flBufferIndex)
                              #endif
                              {
                                if((DemMaxNumberFreezeFrameDID > flDidClassRef) && (Dem_Cfg_Mem_Total_Entry > MemIndex))
                                {
                                  flExternalDataElementClassRef = DemDidClass[flDidClassRef].ExternalDataElementClassRef;
                                  flMemEntry = (Dem_Cfg_PrimaryMemEntryType*)Dem_Cfg_MemPtr[MemIndex];
                                  if(DEM_NUM_OF_EXTERNALRECORDDATA > flExternalDataElementClassRef)
                                  {
                                    flDataElementSize = Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                                    /* Data IDdentifier */
                                    DestBuffer[flBufferIndex] = (uint8)(DEM_0xFF & (DemDidClass[flDidClassRef].Did >> 0x08));
                                    flBufferIndex++;
                                    #if(DemDevAdditionalCoverityChecks == TRUE)
                                    if(DcmDslBufferSize > flBufferIndex)
                                    #endif
                                    {
                                      DestBuffer[flBufferIndex] = (uint8)(DEM_0xFF & DemDidClass[flDidClassRef].Did);
                                      flBufferIndex++;
                                      *BufSize += DEM_TWO;
                                      for(flDataElementIndex = 0; flDataElementIndex < flDataElementSize; flDataElementIndex++)
                                      {
                                        #if(DemDevAdditionalCoverityChecks == TRUE)
                                        if(DcmDslBufferSize > flBufferIndex)
                                        #endif
                                        {
                                          /* Data Elements */
                                          #if(DemDevAdditionalCoverityChecks == TRUE)
                                          if((flMemEntryIndex < DemMaxLengthFreezeFrameData) && (NULL != flMemEntry))
                                          #endif
                                          {
                                            DestBuffer[flBufferIndex] = flMemEntry->SnapshotData[flFFIndex][flMemEntryIndex];
                                          }
                                          flBufferIndex++;
                                          flMemEntryIndex++;
                                        }
                                      }
                                      /* Data Element size + DID Size */
                                      *BufSize += flDataElementSize;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    else
                    {
                      /* If memory entry not available set size as zero and return DEM_GET_FFDATABYDTC_OK*/
                      *BufSize = 0x0U;
                      break;
                    }
                    break;
                  }
                }
              }
            }
            if(flMatch == E_OK)
            {
              fl_RetVal = DEM_GET_FFDATABYDTC_OK;
            }
          }
        }
      }
    }
  #else
  flMatch = E_NOT_OK;
  *BufSize = 0x0U;
  fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_DTC;
  if (Dem_DTCSelector[ClientId].DTC != DEM_DTC_INVALID)
  {
    for (flDtcRef = DEM_DTC_VALID_START; flDtcRef <= Dem_Cfg_Num_Of_DTC; flDtcRef++)
    {
      if (Dem_Cfg_DTC[flDtcRef].Value == Dem_DTCSelector[ClientId].DTC)
      {
        flDtcAttri = Dem_Cfg_DTC[flDtcRef].AttrbsRef;
        flMatch = E_OK;
        break;
      }
    }
  }

    #if (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    flIndex = DEM_CALCULATE_INDEX(flDtcAttri);
    flMask = DEM_CALCULATE_MASK_BIT(flDtcAttri);
    flAvailableCondition = DEM_GET_BIT_STATE(Dem_Event.AvailableStatus[flIndex], flMask);
    
    if(FALSE != flAvailableCondition)
    #endif
    {
      if((E_OK == flMatch) && (flDtcAttri <= Dem_Cfg_Num_Of_DTC))
      {
        fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
        if((Dem_Cfg_DTCAttributes[flDtcAttri].FreezeFrameRecordSupported != FALSE) && (Dem_DTCSelector[ClientId].SnapshotRecordNumber != 0U))
        {
          if((Dem_DTCSelector[ClientId].SnapshotRecordNumber != DEM_0xFF) && (Dem_DTCSelector[ClientId].SnapshotRecordNumber <= DemMaxNumberFreezeFrameRecords))
          {
            /*Instead of DemMaxNumberFreezeFrameRecords try to fetch the Memory Entry and iterated based on the entries*/
            /* Check whether there is a memory entry available for the request DTC */
            if(DEM_GET_FFDATABYDTC_OK == Dem_InternalGetMemoryIndex(&MemIndex, Dem_DTCSelector[ClientId].DTC))
            {
              flMemEntry = (Dem_Cfg_PrimaryMemEntryType*)Dem_Cfg_MemPtr[MemIndex];
              flNoOFFF = flMemEntry->SnahpshotHeader;
              if(Dem_DTCSelector[ClientId].SnapshotRecordNumber <= flMemEntry->SnahpshotHeader)
              {
                fl_RetVal = DEM_GET_FFDATABYDTC_OK;
                flFreezeFrameClassRef = Dem_Cfg_DTCAttributes[flDtcAttri].FreezeFrameClassRef;
                flNoOfDid = DemFreezeFrameClass[flFreezeFrameClassRef].NoOfDid;
                /* Record Number */
                DestBuffer[flBufferIndex] = Dem_DTCSelector[ClientId].SnapshotRecordNumber;
                flBufferIndex++;
                /* Number Of IDdentifier */
                DestBuffer[flBufferIndex] = flNoOfDid;
                flBufferIndex++;
                *BufSize += DEM_TWO;
                for(flDIDIndex = 0U; flDIDIndex < flNoOfDid; flDIDIndex++)
                {
                  flDidClassRef = DemFreezeFrameClass[flFreezeFrameClassRef].DidClassRef[flDIDIndex];
                  flExternalDataElementClassRef = DemDidClass[flDidClassRef].ExternalDataElementClassRef;
                  if(DEM_NUM_OF_EXTERNALRECORDDATA > flExternalDataElementClassRef)
                  {
                    flDataElementSize = Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                    /* Data IDdentifier */
                    DestBuffer[flBufferIndex] = (uint8)(DEM_0xFF & (DemDidClass[flDidClassRef].Did >> 0x08));
                    flBufferIndex++;
                    DestBuffer[flBufferIndex] = (uint8)(DEM_0xFF & DemDidClass[flDidClassRef].Did);
                    flBufferIndex++;
                    *BufSize += DEM_TWO;
                    for(flDataElementIndex = flIterIndex ; flDataElementIndex < (flIterIndex + flDataElementSize); flDataElementIndex++)
                    {
                      DestBuffer[flBufferIndex] = flMemEntry->SnapshotData[Dem_DTCSelector[ClientId].SnapshotRecordNumber - 1u][flDataElementIndex];
                      flBufferIndex++;
                    }
                  }
                  /* Data Element size + DID Size */
                  *BufSize += flDataElementSize;
                  flIterIndex += flDataElementSize;
                }
              }
              else
              {
                fl_RetVal = DEM_GET_FFDATABYDTC_OK;
                /* If memory entry not available set size as zero and return DEM_GET_FFDATABYDTC_OK*/
                *BufSize = 0x0U;
              }
            }
            else
            {
            fl_RetVal = DEM_GET_FFDATABYDTC_OK;
            /* If memory entry not available set size as zero and return DEM_GET_FFDATABYDTC_OK*/
            *BufSize = 0x0U;
            }
          }
          else if(Dem_DTCSelector[ClientId].SnapshotRecordNumber == DEM_0xFF)
          {
            flMatch = E_NOT_OK;
            /*Instead of DemMaxNumberFreezeFrameRecords try to fetch the Memory Entry and iterated based on the entries*/
            /* Check whether there is a memory entry available for the request DTC */
            if(DEM_GET_FFDATABYDTC_OK == Dem_InternalGetMemoryIndex(&MemIndex, Dem_DTCSelector[ClientId].DTC))
            {
              fl_RetVal = DEM_GET_FFDATABYDTC_OK;
              flMatch = E_OK;
              flMemEntry = (Dem_Cfg_PrimaryMemEntryType*)Dem_Cfg_MemPtr[MemIndex];
              flNoOFFF = flMemEntry->SnahpshotHeader;
              flFreezeFrameClassRef = Dem_Cfg_DTCAttributes[flDtcAttri].FreezeFrameClassRef;
              flNoOfDid = DemFreezeFrameClass[flFreezeFrameClassRef].NoOfDid;
              for(flFFIndex = 0u; flFFIndex < flNoOFFF; flFFIndex++)
              {
                /* Record Number */
                DestBuffer[flBufferIndex] = flFFIndex + 1u;
                flBufferIndex++;
                /* Number Of IDdentifier */
                DestBuffer[flBufferIndex] = flNoOfDid;
                flBufferIndex++;
                *BufSize += DEM_TWO;
                for(flDIDIndex = 0U; flDIDIndex < flNoOfDid; flDIDIndex++)
                {
                  flDidClassRef = DemFreezeFrameClass[flFreezeFrameClassRef].DidClassRef[flDIDIndex];
                  flExternalDataElementClassRef = DemDidClass[flDidClassRef].ExternalDataElementClassRef;
                  if(DEM_NUM_OF_EXTERNALRECORDDATA > flExternalDataElementClassRef)
                  {
                    flDataElementSize = Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                    /* Data IDdentifier */
                    DestBuffer[flBufferIndex] = (uint8)(DEM_0xFF & (DemDidClass[flDidClassRef].Did >> 0x08));
                    flBufferIndex++;
                    DestBuffer[flBufferIndex] = (uint8)(DEM_0xFF & DemDidClass[flDidClassRef].Did);
                    flBufferIndex++;
                    *BufSize += DEM_TWO;
                    for(flDataElementIndex = 0; flDataElementIndex < flDataElementSize; flDataElementIndex++)
                    {
                      DestBuffer[flBufferIndex] = flMemEntry->SnapshotData[flFFIndex][flDataElementIndex];
                      flBufferIndex++;
                    }
                  }
                  /* Data Element size + DID Size */
                  *BufSize += flDataElementSize;
                }
              }
            }
            else
            {
            fl_RetVal = DEM_GET_FFDATABYDTC_OK;
            /* If memory entry not available set size as zero and return DEM_GET_FFDATABYDTC_OK*/
            *BufSize = 0x0U;
            }
          }
          else
          {
            fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
          }
        }
      }
    }
    #endif
  }
  return fl_RetVal;
}


/**************************************************************************
 Function name   : Dem_GetSizeOfFreezeFrameByDTC
 Arguments       : uint8 ClientId, uint16* SizeOfFreezeFrame
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the size of freeze frame data by DTC.
 **************************************************************************/
Std_ReturnType Dem_GetSizeOfFreezeFrameSelection(uint8 ClientId,
                                    uint16* SizeOfFreezeFrame)
{
  Std_ReturnType fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_DTC;
 #if(DemTypeofFreezeFrameRecordNumeration == DEM_FF_RECNUM_CONFIGURED)
#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (0x00U == Dem_DTCSelector[ClientId].Origin) || (DEM_DTC_ORIGIN_INVALID <= Dem_DTCSelector[ClientId].Origin) || (SizeOfFreezeFrame == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    uint16 MemIndex = 0U;
    uint8 flDtcAttri = 0U;
    uint8 flMatch = 0U;
    uint16 flDtcRef = 0U;
    uint8 flFFIndex = 0U;
    uint8 flFreezeFrameRecNumClassRef = 0U;
    uint8 flFreezeFrameRecordNumClassRef = 0U;
    uint8 flFreezeFrameRecordClassRef = 0U;
    uint8 flFreezeFrameClassRef = 0U;
    uint8 flDidClassRef = 0U;
    uint8 flExternalDataElementClassRef = 0U;
    uint8 flNoOFFF = 0U;
    uint8 flNoOfDid = 0U;
    uint8 flDIDIndex = 0U;
    uint8 flFFClassIndex = 0U;
    uint8 flRecordNumber = 0U;

    flMatch = E_NOT_OK;
    *SizeOfFreezeFrame = 0x0;

    fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN;
    if(Dem_DTCSelector[ClientId].Origin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
    {
      fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_DTC;
      if (Dem_DTCSelector[ClientId].DTC != DEM_DTC_INVALID)
      {
        for (flDtcRef = DEM_DTC_VALID_START; flDtcRef <= Dem_Cfg_Num_Of_DTC; flDtcRef++)
        {
          if (Dem_Cfg_DTC[flDtcRef].Value == Dem_DTCSelector[ClientId].DTC)
          {
            flDtcAttri = Dem_Cfg_DTC[flDtcRef].AttrbsRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
            if(flDtcAttri <= Dem_Cfg_Num_Of_DTC)
#endif
            {
              flMatch = E_OK;
            }
            break;
          }
        }
      }
    }
    if(E_OK == flMatch)
    {
      fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER;
      if((Dem_Cfg_DTCAttributes[flDtcAttri].FreezeFrameRecordSupported != FALSE) && (Dem_DTCSelector[ClientId].SnapshotRecordNumber != 0U))
      {
        if(Dem_DTCSelector[ClientId].SnapshotRecordNumber != DEM_0xFF)
        {
          flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flDtcAttri].FreezeFrameRecNumClassRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
          if(flFreezeFrameRecNumClassRef < DemMaxNumberFreezeFrameRecords)
#endif
          {
            flNoOFFF = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].MaxNumberFreezeFrameRecords;
            flMatch = E_NOT_OK;
            for(flFFIndex = 0U; flFFIndex < flNoOFFF; flFFIndex++)
            {
              flFreezeFrameRecordClassRef = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].FreezeFrameRecordClassRef[flFFIndex];
#if(DemDevAdditionalCoverityChecks == TRUE)
              if(flFreezeFrameRecordClassRef < DemMaxNumberFreezeFrameRecords)
#endif
              {
                /* Check for record number match */
                flRecordNumber = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].Number;
                if(Dem_DTCSelector[ClientId].SnapshotRecordNumber == flRecordNumber)
                {
                  flMatch = E_OK;
                  /* Check whether there is a memory entry available for the request DTC */
                  if(DEM_GET_FFDATABYDTC_OK == Dem_InternalGetMemoryIndex(&MemIndex, Dem_DTCSelector[ClientId].DTC))
                  {
                    flFreezeFrameRecordNumClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].NoofFFClass;
                    for(flFFClassIndex = 0U; flFFClassIndex < flFreezeFrameRecordNumClassRef; flFFClassIndex++)
                    {
                      flFreezeFrameClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].FreezeFrameClassRef[flFFClassIndex];
                      flNoOfDid = DemFreezeFrameClass[flFreezeFrameClassRef].NoOfDid;
                      #if(DemDevAdditionalCoverityChecks == TRUE)
                      if(flNoOfDid < DemMaxNumberFreezeFrameDIDPerFF)
                      #endif
                      {
                        for(flDIDIndex = 0U; flDIDIndex < flNoOfDid; flDIDIndex++)
                        {
                          flDidClassRef = DemFreezeFrameClass[flFreezeFrameClassRef].DidClassRef[flDIDIndex];
                          #if(DemDevAdditionalCoverityChecks == TRUE)
                          if(flDidClassRef < DemMaxNumberFreezeFrameDID)
                          #endif
                          {
                            flExternalDataElementClassRef = DemDidClass[flDidClassRef].ExternalDataElementClassRef;
                            #if(DemDevAdditionalCoverityChecks == TRUE)
                            if(flExternalDataElementClassRef < DEM_NUM_OF_EXTERNALRECORDDATA)
                            #endif
                            {
                              *SizeOfFreezeFrame += Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                            }
                          }
                        }
                        fl_RetVal = DEM_GET_FFDATABYDTC_OK;
                      }
                    }
                  }
                  else
                  {
                    /* If memory entry not available set size as zero and return DEM_GET_FFDATABYDTC_OK*/
                    *SizeOfFreezeFrame = 0x0U;
                    fl_RetVal = DEM_GET_FFDATABYDTC_OK;
                    break;
                  }
                  break;
                }
              }
            }
          }
          if(flMatch == E_OK)
          {
            /* Record Number + Num Of Did's + DID#1 + pay load data+ DID#n + pay load data*/
            *SizeOfFreezeFrame += flNoOFFF + DEM_ONE + (flNoOfDid * DEM_TWO);
          }
        }
        else
        {
          flFreezeFrameRecNumClassRef = Dem_Cfg_DTCAttributes[flDtcAttri].FreezeFrameRecNumClassRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
          if(flFreezeFrameRecNumClassRef < DemMaxNumberFreezeFrameRecords)
#endif
          {
            flNoOFFF = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].MaxNumberFreezeFrameRecords;
            flMatch = E_NOT_OK;
            for(flFFIndex = 0U; flFFIndex < flNoOFFF; flFFIndex++)
            {
              flFreezeFrameRecordClassRef = DemFreezeFrameRecNumClass[flFreezeFrameRecNumClassRef].FreezeFrameRecordClassRef[flFFIndex];
#if(DemDevAdditionalCoverityChecks == TRUE)
              if(flFreezeFrameRecordClassRef < DemMaxNumberFreezeFrameRecords)
#endif
              {
                /* Check whether there is a memory entry available for the request DTC */
                if(DEM_GET_FFDATABYDTC_OK == Dem_InternalGetMemoryIndex(&MemIndex, Dem_DTCSelector[ClientId].DTC))
                {
                  flMatch = E_OK;
                  flFreezeFrameRecordNumClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].NoofFFClass;
                  for(flFFClassIndex = 0U; flFFClassIndex < flFreezeFrameRecordNumClassRef; flFFClassIndex++)
                  {
                    flFreezeFrameClassRef = DemFreezeFrameRecordClass[flFreezeFrameRecordClassRef].FreezeFrameClassRef[flFFClassIndex];
                    flNoOfDid = DemFreezeFrameClass[flFreezeFrameClassRef].NoOfDid;
                    #if(DemDevAdditionalCoverityChecks == TRUE)
                    if(flNoOfDid < DemMaxNumberFreezeFrameDIDPerFF)
                    #endif
                    {
                      for(flDIDIndex = 0U; flDIDIndex < flNoOfDid; flDIDIndex++)
                      {
                        flDidClassRef = DemFreezeFrameClass[flFreezeFrameClassRef].DidClassRef[flDIDIndex];
                        #if(DemDevAdditionalCoverityChecks == TRUE)
                        if(flDidClassRef < DemMaxNumberFreezeFrameDID)
                        #endif
                        {
                          flExternalDataElementClassRef = DemDidClass[flDidClassRef].ExternalDataElementClassRef;
                          #if(DemDevAdditionalCoverityChecks == TRUE)
                          if(flExternalDataElementClassRef < DEM_NUM_OF_EXTERNALRECORDDATA)
                          #endif
                          {
                            *SizeOfFreezeFrame += Dem_Cfg_ExternalExtDataElement[flExternalDataElementClassRef].DemDataElementDataSize;
                          }
                        }
                      }
                      /* Record Number + Num Of Did's + DID#1 + pay load data+ DID#n + pay load data*/
                      *SizeOfFreezeFrame += DEM_ONE + DEM_ONE + (flNoOfDid * DEM_TWO) ;
                    }
                  }
                }
                else
                {
                  /* If memory entry not available set size as zero and return DEM_GET_FFDATABYDTC_OK*/
                  *SizeOfFreezeFrame = 0x0U;
                  fl_RetVal = DEM_GET_FFDATABYDTC_OK;
                  flMatch = E_OK;
                  break;
                }
              }
            }
          }
          if(flMatch == E_OK)
          {
            /* Record Number + Num Of Did's + DID#1 + pay load data+ DID#n + pay load data*/
            fl_RetVal = DEM_GET_FFDATABYDTC_OK;
          }
        }
      }
    }
  }
  #endif
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_InternalGetMemoryIndex
 Arguments       :
 Return type     :
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :
 **************************************************************************/
static Dem_ReturnGetFreezeFrameDataByDTCType Dem_InternalGetMemoryIndex(uint16 *MemIndex, uint32 DtcId)
{
  Dem_ReturnGetFreezeFrameDataByDTCType fl_RetVal;
  Dem_EventIdType Event;
  uint8 flIndex;
  Dem_Cfg_PrimaryMemEntryType *flEntry;

  fl_RetVal = DEM_GET_FFDATABYDTC_WRONG_DTC;
  Event = Dem_InternalGetEventIdByDTCValue(DtcId);
  for(flIndex = Dem_Cfg_Mem_Primary_Entry_Start; flIndex < Dem_Cfg_Mem_Total_Entry; flIndex++)
  {
    flEntry = (Dem_Cfg_PrimaryMemEntryType*) Dem_Cfg_MemPtr[flIndex];
    if (flEntry->EventId == Event)
    {
      *MemIndex = (uint16)flIndex;
      fl_RetVal = DEM_GET_FFDATABYDTC_OK;
    }
  }
  return fl_RetVal;
}

#endif /*(DemMaxNumberFreezeFrameRecords > 0)*/



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
Std_ReturnType Dem_SelectExtendedDataRecord(uint8 ClientId, uint8 RecordNumber)
{
  Std_ReturnType fl_RetVal= E_NOT_OK;
  #if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = E_NOT_OK;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (Dem_DTCSelector[ClientId].Format >= DEM_DTC_FORMAT_INVALID) || (ClientId >= Dem_Cfg_Num_Of_Clients))
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_WRONG_DTC;
  }
  else
  {
    /*Do Nothing*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    Dem_DTCSelector[ClientId].ExtendedDataNumber= RecordNumber;
    fl_RetVal = E_OK;
  }
  return fl_RetVal;

}
/**************************************************************************
 Function name   : Dem_InternalUpdateExtRecordData
 Arguments       :
 Return type     :
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :
 **************************************************************************/
static void Dem_InternalUpdateExtRecordData( Dem_Cfg_PrimaryMemEntryType *fl_MemoryEntry,
                                      uint8 ExtRecordTableRef,  Dem_EventIdType EventId)
{
  uint8 ExtRecord;
  uint8 ExtRecordParameterRef;

  uint8 DemExtDataClassRef;
  uint8 Dataindex = DEM_ONE;

  DemExtendedDataRecordUpdateType Update;
#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if(ExtRecordTableRef >= DEM_NUM_OF_EXTENDEDRECORD_COMBINATION)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    for (ExtRecord = 0; ExtRecord < Dem_Cfg_ExtDataRecordContainer[ExtRecordTableRef].NoOfExtdataRecord;
            ExtRecord++)
    {
      ExtRecordParameterRef =
                Dem_Cfg_ExtDataRecordContainer[ExtRecordTableRef].DemExtendedDataRecordClassTypeRef[ExtRecord];
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(ExtRecordParameterRef < DEM_NUM_OF_EXTENDEDRECORD)
#endif
      {
        DemExtDataClassRef =
                  Dem_Cfg_ExtRecordParameter[ExtRecordParameterRef].DemExtendedDataClassRef;

        Update = Dem_Cfg_ExtRecordParameter[ExtRecordParameterRef].DemExtendedDataRecordUpdate;
#if(DemDevAdditionalCoverityChecks == TRUE)
        if((DemExtDataClassRef < DEM_NUM_OF_EXTENDEDRECORD) &&
           ((DEM_ONE != fl_MemoryEntry->ExtendedDataRecord[ExtRecord][0U]) || (DEM_UPDATE_RECORD_YES == Update)))
#else
        if((DEM_ONE != fl_MemoryEntry->ExtendedDataRecord[ExtRecord][0U]) || (DEM_UPDATE_RECORD_YES == Update))
#endif
        {
          /*when to check Trigger*/
          /* Data update bit */
          fl_MemoryEntry->ExtendedDataRecord[ExtRecord][0U] = DEM_ONE;
          if (InternalDataElementClass
                  == Dem_Cfg_ExtDataClass[DemExtDataClassRef].DemDataElementType)
          {
            /*Do nothing*/
          }
          else
          {
            uint8 ref = Dem_Cfg_ExtDataClass[DemExtDataClassRef].DemDataElementRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
            if(ref < DEM_NUM_OF_EXTERNALRECORDDATA)
#endif
            {
              (void)Dem_Cfg_ExternalExtDataElement[ref].DemDataElementReadFnc(
                EventId, (uint8*) (&fl_MemoryEntry->ExtendedDataRecord[ExtRecord][Dataindex]));
            }
          }
        }
      }
    }
  }
}

/**************************************************************************
 Function name   : Dem_UpdateExtendedRecord
 Arguments       :
 Return type     :
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :
 **************************************************************************/
static void Dem_UpdateExtendedRecord(Dem_EventIdType Event, Dem_Cfg_PrimaryMemEntryType *MemoryPointer,uint8 * DestBuffer, DemIntDataElementType ExtendedData,uint8 DataSize)
{
  uint8 elementId =0U;
  uint8 DataLength =0U;
  uint8 index=0U;
  uint8 flMask= DEM_ONE;
  uint16 flElement= 0U;
  uint8 flcounter = 0U;
  uint16 flIndex = 0U;
  uint8 flMemIndex = 0U;
  Dem_DTCOriginType EventOrigin = 0u;
#if (STD_OFF == DEM_CFG_EXTRECDATA_COUNTER_2BYTES)
  uint8 flAgeCount = 0U;
  uint8 flDtcAttributeTableRef = 0U;
#endif
  for (elementId = 0; ((DataLength < DataSize)&&(9 > flcounter)); elementId++)
  {
    flElement = (ExtendedData & (flMask << elementId));
    if(FALSE != flElement)
    {
      switch(flElement)
      {
        case DEM_EXTENDED_DTC_PRIORITY:
          for (flIndex = 0; flIndex < Dem_Cfg_Num_Of_Event; flIndex++)
          {
            if (Dem_Cfg_EventParameter[flIndex].Id == Event)
            {
              DestBuffer[DataLength] = (uint8)(Dem_Cfg_EventParameter[flIndex].Priority);
              DataLength += DEM_ONE;
            }
          }
          break;

        case DEM_EXTENDED_MEM_OVERFLOW:
          EventOrigin = Dem_Cfg_EventParameter[Event].DemOrigin;
          flMemIndex = Dem_FindMemoryIndex(EventOrigin);
          if (flMemIndex != DEM_INVALID_MEMORY_INDEX)
          {
            #if (STD_ON == DEM_CFG_EXTRECDATA_COUNTER_2BYTES)
            DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.MemoryOverflow[flMemIndex] >> 8) & DEM_0xFF;
            DestBuffer[DataLength + DEM_ONE] = (uint8)(Dem_Cfg_StatusData.MemoryOverflow[flMemIndex]) & DEM_0xFF;
            DataLength += DEM_TWO;
            #else
            DestBuffer[DataLength] = Dem_Cfg_StatusData.MemoryOverflow[flMemIndex];
            DataLength += DEM_ONE;
            #endif
          }
          break;

        case DEM_EXTENDED_DATA_OCCCNTR:
#if (STD_ON == DEM_CFG_EXTRECDATA_COUNTER_2BYTES)
          DestBuffer[DataLength] = (uint8)(MemoryPointer->OccurrenceCounter >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(MemoryPointer->OccurrenceCounter) & DEM_0xFF;
          DataLength += DEM_TWO;
#else
          DestBuffer[DataLength] = (uint8)(MemoryPointer->OccurrenceCounter);
          DataLength += DEM_ONE;
#endif
          break;
        case DEM_EXTENDED_DATA_AGINGCNTR:
        if(DEM_AGING_DOWNCTR_ENABLED == STD_ON)
        {
          #if (STD_ON == DEM_CFG_EXTRECDATA_COUNTER_2BYTES)
          DestBuffer[DataLength] = (uint8)(MemoryPointer->AgingCounter >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(MemoryPointer->AgingCounter) & DEM_0xFF;
          DataLength += DEM_TWO;
          #else
          for (flIndex = 0; flIndex < Dem_Cfg_Num_Of_Event; flIndex++)
          {
            if (Dem_Cfg_EventParameter[flIndex].Id == Event)
            {
              flDtcAttributeTableRef = Dem_Cfg_DTC[Dem_Cfg_EventParameter[flIndex].DTCTableRef].AttrbsRef;
              flIndex = Dem_Cfg_Num_Of_Event;
            }
          }

          flAgeCount = Dem_Cfg_DTCAttributes[flDtcAttributeTableRef].AgingThershold;
          if (flAgeCount >= (MemoryPointer->AgingCounter))
          {
            DestBuffer[DataLength] = (flAgeCount - (uint8)(MemoryPointer->AgingCounter));
          }
          else
          {
            DestBuffer[DataLength] = ((uint8)(MemoryPointer->AgingCounter) - flAgeCount);
          }
          DataLength += DEM_ONE;
          #endif
        }
        else
        {
          #if (STD_ON == DEM_CFG_EXTRECDATA_COUNTER_2BYTES)
          DestBuffer[DataLength] = (uint8)(MemoryPointer->AgingCounter >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(MemoryPointer->AgingCounter) & DEM_0xFF;
          DataLength += DEM_TWO;
          #else
          DestBuffer[DataLength] = (uint8)(MemoryPointer->AgingCounter);
          DataLength += DEM_ONE;
          #endif
        }
          break;
        case DEM_EXTENDED_DATA_CYCLES_SINCE_LAST_FAILED:
#if (STD_ON == DEM_CFG_EXTRECDATA_COUNTER_2BYTES)
          DestBuffer[DataLength] = (uint8)(MemoryPointer->LastFailedCount >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(MemoryPointer->LastFailedCount) & DEM_0xFF;
          DataLength += DEM_TWO;
#else
          DestBuffer[DataLength] = (uint8)(MemoryPointer->LastFailedCount);
          DataLength += DEM_ONE;
#endif
          break;
        case DEM_EXTENDED_DATA_CYCLES_SINCE_FIRST_FAILED:
#if (STD_ON == DEM_CFG_EXTRECDATA_COUNTER_2BYTES)
          DestBuffer[DataLength] = (uint8)(MemoryPointer->FirstFailedCount >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(MemoryPointer->FirstFailedCount) & DEM_0xFF;
          DataLength += DEM_TWO;
#else
          DestBuffer[DataLength] = (uint8)(MemoryPointer->FirstFailedCount);
          DataLength += DEM_ONE;
#endif
          break;
        case DEM_EXTENDED_DATA_CYCLES_SINCE_FIRST_FAILED_EVENT:
#if (STD_ON == DEM_CFG_EXTRECDATA_EVENT_2BYTES)
          DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.FirstFailedEvent >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(Dem_Cfg_StatusData.FirstFailedEvent) & DEM_0xFF;
          DataLength += DEM_TWO;
#else
          DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.FirstFailedEvent);
          DataLength += DEM_ONE;
#endif
          break;
        case DEM_EXTENDED_DATA_CYCLES_SINCE_FIRST_CONFIRMED_EVENT:
#if (STD_ON == DEM_CFG_EXTRECDATA_EVENT_2BYTES)
          DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.FirstConfirmedEvent >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(Dem_Cfg_StatusData.FirstConfirmedEvent) & DEM_0xFF;
          DataLength += DEM_TWO;
#else
          DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.FirstConfirmedEvent);
          DataLength += DEM_ONE;
#endif
          break;
        case DEM_EXTENDED_DATA_RECENT_FAILED_EVENT:
#if (STD_ON == DEM_CFG_EXTRECDATA_EVENT_2BYTES)
          DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.RecentFailedEvent >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(Dem_Cfg_StatusData.RecentFailedEvent) & DEM_0xFF;
          DataLength += DEM_TWO;
#else
          DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.RecentFailedEvent);
          DataLength += DEM_ONE;
#endif
          break;
        case RECENT_CONFIRMED_EVENT:
#if (STD_ON == DEM_CFG_EXTRECDATA_EVENT_2BYTES)
          DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.RecentConfirmedEvent >> 8) & DEM_0xFF;
          DestBuffer[DataLength + DEM_ONE] = (uint8)(Dem_Cfg_StatusData.RecentConfirmedEvent) & DEM_0xFF;
          DataLength += DEM_TWO;
#else
          DestBuffer[DataLength] = (uint8)(Dem_Cfg_StatusData.RecentConfirmedEvent);
          DataLength += DEM_ONE;
#endif
          break;
        case DEM_EXTENDED_DATA_OPERATION_CYCLES_COUNTER:
#if (STD_ON == DEM_CFG_EXTRECDATA_COUNTER_2BYTES)
          for (index = 0; index < Dem_Cfg_Num_Of_OpCycle; index++)
          {
#if(DemDevAdditionalCoverityChecks == TRUE)
            if(DataLength < DataSize)
#endif
            {
              DestBuffer[DataLength] = (uint8)(Dem_Cfg_OpCycle.Counter[index] >> 8) & DEM_0xFF;
              DestBuffer[DataLength + DEM_ONE] = (uint8)(Dem_Cfg_OpCycle.Counter[index]) & DEM_0xFF;
            }
            DataLength += DEM_TWO;
          }
#else
          for (index = 0; index < Dem_Cfg_Num_Of_OpCycle; index++)
          {
#if(DemDevAdditionalCoverityChecks == TRUE)
            if(DataLength < DataSize)
#endif
            {
              DestBuffer[DataLength] = (uint8)(Dem_Cfg_OpCycle.Counter[index]);
            }
            DataLength += DEM_ONE;
          }
#endif
          break;
        case DEM_EXTENDED_DATA_FDC:
          (void)Dem_GetFaultDetectionCounter(Event, (sint8 *)&DestBuffer[DataLength]);
          DataLength += DEM_ONE;
          break;
        default:
          flcounter++;
          break;
      } //end of switch
    } //end of if(FALSE != flElement)
  } // end of for (elementid= 0; DataLength < DataSize; elementid++)
}

/**************************************************************************
 Function name   : Dem_InternalGetExtDataRecMemoryIndex
 Arguments       :
 Return type     :
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :
 **************************************************************************/
static Std_ReturnType Dem_InternalGetExtDataRecMemoryIndex(Dem_EventIdType EventId, uint8 ExtendedDataNumber, uint16* indexOfExtendedDataRecord)
{
  Std_ReturnType fl_RetVal = DEM_E_WRONG_RECORDNUMBER;
  uint8 ExtDataRecContainerindex = 0u;
  uint8 NoofRec = 0u;
  uint8 index = 0u;
  uint8 DataTableindex = 0u;
  uint8 indexfound = 0u;

#if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if((EventId > Dem_Cfg_Num_Of_DTC) || (indexOfExtendedDataRecord == NULL_PTR))
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
#endif
  {
    uint8 ref = Dem_Cfg_DTC[EventId].AttrbsRef;
    *indexOfExtendedDataRecord = 0u;
#if(DemDevAdditionalCoverityChecks == TRUE)
    if(ref <= Dem_Cfg_Num_Of_DTC)
#endif
    {
      if (FALSE != Dem_Cfg_DTCAttributes[ref].ExtDataRecordSupported)
      {
        ExtDataRecContainerindex = Dem_Cfg_DTCAttributes[ref].ExtDataRecordContainerRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
        if(ExtDataRecContainerindex < DEM_NUM_OF_EXTENDEDRECORD_COMBINATION)
#endif
        {
          NoofRec = Dem_Cfg_ExtDataRecordContainer[ExtDataRecContainerindex].NoOfExtdataRecord;

          for (index =0; ((index< NoofRec) && (indexfound != DEM_ONE)); index++ )
          {
            DataTableindex = Dem_Cfg_ExtDataRecordContainer[ExtDataRecContainerindex].DemExtendedDataRecordClassTypeRef[index];
#if(DemDevAdditionalCoverityChecks == TRUE)
            if(DataTableindex < DEM_NUM_OF_EXTENDEDRECORD)
#endif
            {
              if (ExtendedDataNumber != Dem_Cfg_ExtRecordParameter[DataTableindex].DemExtendedDataRecordNumber)
              {
                *indexOfExtendedDataRecord += DEM_ONE;
              }
              else
              {
                indexfound = DEM_ONE;
                fl_RetVal = E_OK;
              }
            }
          }
        }
      }
    }
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DcmGetExtendedDataRecordByDTC
 Arguments       : uint8 ClientId, uint8* DestBuffer, uint16* BufSize
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     :  Gets extended data by DTC. The function stores the data in
 the provided DestBuffer.
 **************************************************************************/
Std_ReturnType Dem_GetNextExtendedDataRecord(uint8 ClientId, uint8* DestBuffer, uint16* BufSize)
{
  Dem_EventIdType Event;
  Std_ReturnType fl_RetVal = DEM_RECORD_OK;
  Std_ReturnType flRecEx_RetVal = E_OK;
  Event = Dem_InternalGetEventIdByDTCValue(Dem_DTCSelector[ClientId].DTC);
  if(Event != DEM_EVENT_INVALID)
  {
    flRecEx_RetVal = Dem_GetEventExtendedDataRecordEx(Event,Dem_DTCSelector[ClientId].ExtendedDataNumber, DestBuffer, BufSize);
    if (DEM_E_WRONG_RECORDNUMBER == flRecEx_RetVal)
    {
      fl_RetVal = DEM_RECORD_WRONG_NUMBER;
    }
    else if (DEM_E_NODATAAVAILABLE == flRecEx_RetVal)
    {
      /*DEM_RECORD_PENDING*/
      flRecEx_RetVal = E_OK;
      fl_RetVal = DEM_RECORD_OK;
    }
    else if (E_NOT_OK == flRecEx_RetVal)
    {
      fl_RetVal = DEM_RECORD_WRONG_DTC;
    }
    else
    {
      /* Dp nothing */
    }
  }
  else
  {
    fl_RetVal = DEM_RECORD_WRONG_DTC;      
  }

  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetSizeOfExtendedDataRecordSelection
 Arguments       : uint8 ClientId, uint16* SizeOfExtendedDataRecord
 Return type     : Std_ReturnType
 Sync/Async      : Asynchronous
 Reentrancy      : Non Reentrant
 Description     : Gets the size of extended data by DTC.
 **************************************************************************/
Std_ReturnType Dem_GetSizeOfExtendedDataRecordSelection(uint8 ClientId, uint16* SizeOfExtendedDataRecord)
{

  Std_ReturnType fl_RetVal = DEM_GETSIZEBYDTC_WRONG_RECNUM;
  Dem_EventIdType Event;
  uint8 ExtDataRecContainerindex = 0U;
  uint8 NoofRec = 0U;
  uint8 index = 0U;
  uint8 DataTableindex = 0U;
  uint8 DataRecTypeIndex = 0U;

  Event = Dem_InternalGetEventIdByDTCValue(Dem_DTCSelector[ClientId].DTC);
  if((ClientId < Dem_Cfg_Num_Of_Clients) && (Event <= Dem_Cfg_Num_Of_DTC) && (DEM_GET_FFDATABYDTC_OK == Event))
  {
    uint8 ref = Dem_Cfg_DTC[Event].AttrbsRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
    if((ref <= Dem_Cfg_Num_Of_DTC) && (FALSE != Dem_Cfg_DTCAttributes[ref].ExtDataRecordSupported))
#else
    if(FALSE != Dem_Cfg_DTCAttributes[ref].ExtDataRecordSupported)
#endif
    {
      ExtDataRecContainerindex = Dem_Cfg_DTCAttributes[ref].ExtDataRecordContainerRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
      if(ExtDataRecContainerindex < DEM_NUM_OF_EXTENDEDRECORD_COMBINATION)
#endif
      {
        NoofRec = Dem_Cfg_ExtDataRecordContainer[ExtDataRecContainerindex].NoOfExtdataRecord;
        for (index = 0; index < NoofRec; index++ )
        {
          DataTableindex = Dem_Cfg_ExtDataRecordContainer[ExtDataRecContainerindex].DemExtendedDataRecordClassTypeRef[index];
#if(DemDevAdditionalCoverityChecks == TRUE)
          if((DataTableindex < DEM_NUM_OF_EXTENDEDRECORD) && (Dem_DTCSelector[ClientId].ExtendedDataNumber == Dem_Cfg_ExtRecordParameter[DataTableindex].DemExtendedDataRecordNumber))
#else
          if(Dem_DTCSelector[ClientId].ExtendedDataNumber == Dem_Cfg_ExtRecordParameter[DataTableindex].DemExtendedDataRecordNumber)
#endif
          {
            fl_RetVal = DEM_GETSIZEBYDTC_OK;
            DataRecTypeIndex = Dem_Cfg_ExtRecordParameter[DataTableindex].DemExtendedDataClassRef;
#if(DemDevAdditionalCoverityChecks == TRUE)
            if(DataRecTypeIndex < DEM_NUM_OF_EXTENDEDRECORD)
#endif
            {
              uint8 reftype = Dem_Cfg_ExtDataClass[DataRecTypeIndex].DemDataElementRef;
              if (InternalDataElementClass == Dem_Cfg_ExtDataClass[DataRecTypeIndex].DemDataElementType)
              {
#if(DemDevAdditionalCoverityChecks == TRUE)
                if(reftype < DEM_NUM_OF_INTERNALRECORDDATA)
#endif
                {
                  *SizeOfExtendedDataRecord = Dem_Cfg_InternalExtDataElement[reftype].DemIntDataElementDataSize;
                }
              }
              else
              {
#if(DemDevAdditionalCoverityChecks == TRUE)
                if(reftype < DEM_NUM_OF_EXTERNALRECORDDATA)
#endif
                {
                  *SizeOfExtendedDataRecord = Dem_Cfg_ExternalExtDataElement[reftype].DemDataElementDataSize;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      fl_RetVal = DEM_GETSIZEBYDTC_WRONG_DTC;
    }
  }
  else
  {
    fl_RetVal = DEM_GETSIZEBYDTC_WRONG_DTC;
  }
  return fl_RetVal;
}
#endif  // end of #if (DEM_NUM_OF_EXTENDEDRECORD > 0)

/**************************************************************************
 Function name   : Dem_InternalClearDTC
 Arguments       :
 Return type     :
 Sync/Async      : Asynchronous
 Reentrancy      : Reentrant
 Description     :
 **************************************************************************/
static Std_ReturnType Dem_InternalClearDTC(uint8 Client)
{
  Std_ReturnType fl_RetVal;

  fl_RetVal = DEM_CLEAR_FAILED;
  Dem_EnterCriticalSection();
  if (Dem_ClearDtc[Client].Req_Status == DEM_DCM_CLEAR_DTC_IDLE)
  {
    fl_RetVal = DEM_CLEAR_WRONG_DTC;
    if ((DEM_DTC_GROUP_ALL_DTCS == Dem_DTCSelector[Client].DTC) || (DEM_EVENT_INVALID != Dem_DTCSelector[Client].EventId))
    {
      Dem_ClearDtc[Client].Req_Status = DEM_DCM_CLEAR_DTC_REQUESTED;
      Dem_ClearDtc[Client].DTC = Dem_DTCSelector[Client].DTC;
      Dem_ClearDtc[Client].Format = Dem_DTCSelector[Client].Format;
      Dem_ClearDtc[Client].Origin = Dem_DTCSelector[Client].Origin;
      Dem_ClearDtc[Client].EventId = Dem_DTCSelector[Client].EventId;
      Dem_ClearDtc[Client].QueueState = DEM_DCM_CLEAR_DTC_QUEUE_PENDING;
      fl_RetVal = DEM_CLEAR_PENDING;
    }
  }
  else
  {
    /* is it a same request again ? */
    if ((Dem_ClearDtc[Client].DTC == Dem_DTCSelector[Client].DTC) && (Dem_ClearDtc[Client].Format == Dem_DTCSelector[Client].Format)
        && (Dem_ClearDtc[Client].Origin == Dem_DTCSelector[Client].Origin))
    {
      switch (Dem_ClearDtc[Client].QueueState)
      {
        case DEM_DCM_CLEAR_DTC_QUEUE_PENDING:
          fl_RetVal = DEM_CLEAR_PENDING;
          break;
        case DEM_DCM_CLEAR_DTC_QUEUE_DONE:
          Dem_DTCSelector[Client].ActiveOps = 0;
          Dem_ClearDtc[Client].Req_Status = DEM_DCM_CLEAR_DTC_IDLE;
          fl_RetVal = DEM_CLEAR_OK;
          break;
        case DEM_DCM_CLEAR_DTC_QUEUE_FAILED:
        case DEM_DCM_CLEAR_DTC_QUEUE_CANCEL:
          Dem_DTCSelector[Client].ActiveOps = 0;
          Dem_ClearDtc[Client].Req_Status = DEM_DCM_CLEAR_DTC_IDLE;
          fl_RetVal = DEM_CLEAR_FAILED;
          break;
        default:
          /*DoNothing*/
          break;
      }
    }
    else
    {
      fl_RetVal = DEM_CLEAR_BUSY;
    }
  }
  Dem_ExitCriticalSection();
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_SelectDTC
 Arguments       : uint8 ClientId, uint32 DTC, Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     :
 **************************************************************************/
Std_ReturnType Dem_SelectDTC(uint8 ClientId, uint32 DTC, Dem_DTCFormatType DTCFormat,
 Dem_DTCOriginType DTCOrigin)
{
  Std_ReturnType fl_RetVal = E_NOT_OK;
  uint16 flEventId;

  #if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = E_NOT_OK;
  }
  else if ((ClientId >= Dem_Cfg_Num_Of_Clients) || (DTCFormat >= DEM_DTC_FORMAT_INVALID))
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_WRONG_DTC;
  }
  else
  {
    /*Do Nothing*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
  #endif
  {
    if((Dem_DTCSelector[ClientId].ActiveOps == DEM_INITIAL) ||(Dem_ClearDtc[ClientId].QueueState != DEM_DCM_CLEAR_DTC_IDLE))
    {
      flEventId = Dem_InternalGetEventIdByDTCValue(DTC);
      if(DTC == DEM_DTC_GROUP_ALL_DTCS)
      {
        Dem_EnterCriticalSection();
        Dem_DTCSelector[ClientId].DTC = DTC;
        Dem_DTCSelector[ClientId].Format = DTCFormat;
        Dem_DTCSelector[ClientId].Origin = DEM_DTC_ORIGIN_INVALID;
        Dem_DTCSelector[ClientId].EventId = DEM_EVENT_INVALID;
        Dem_DTCSelector[ClientId].ClientId = ClientId;
        Dem_DTCSelector[ClientId].DTCKind = DEM_DTC_KIND_ALL_DTCS;
        Dem_DTCSelector[ClientId].ActiveOps = DEM_DTC_SELECTED;
        Dem_ExitCriticalSection();
        fl_RetVal = E_OK;
      }
      else if(flEventId != DEM_EVENT_INVALID)
      {
        if(DTCOrigin == Dem_Cfg_EventParameter[flEventId].DemOrigin)
        {
          Dem_EnterCriticalSection();
          Dem_DTCSelector[ClientId].DTC = DTC;
          Dem_DTCSelector[ClientId].Format = DTCFormat;
          Dem_DTCSelector[ClientId].Origin = DTCOrigin;
          Dem_DTCSelector[ClientId].EventId = flEventId;
          Dem_DTCSelector[ClientId].ClientId = ClientId;
          Dem_DTCSelector[ClientId].DTCKind = DEM_DTC_KIND_ALL_DTCS;
          Dem_DTCSelector[ClientId].ActiveOps = DEM_DTC_SELECTED;
          Dem_ExitCriticalSection();
          fl_RetVal = E_OK;
        }
	  }
      else
      {
        fl_RetVal = DEM_WRONG_DTC;
      }
    }
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_GetDTCSelectionResult
 Arguments       : uint8 ClientId
 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     :
 **************************************************************************/
Std_ReturnType Dem_GetDTCSelectionResult(uint8 ClientId)
{
   Std_ReturnType fl_RetVal = E_NOT_OK;

  #if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = E_NOT_OK;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_WRONG_DTC;
  }
  #if(DEM_USERDEFINED_MEMORY_SUPPORT != STD_ON)
  else if((DEM_DTC_ORIGIN_PRIMARY_MEMORY != Dem_DTCSelector[ClientId].Origin) && (Dem_DTCSelector[ClientId].DTC != DEM_DTC_INVALID))
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal= DEM_WRONG_DTCORIGIN;
  }
  #endif
  else
  {
    /*Do Nothing*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
  #endif
  {
    if ((DEM_DTC_GROUP_ALL_DTCS == Dem_DTCSelector[ClientId].DTC) || (DEM_EVENT_INVALID != Dem_DTCSelector[ClientId].EventId))
    {
      fl_RetVal = E_OK;
    }
 }
 return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_InternalGetDTCOrigin
 Arguments       : uint32 DTC
 Return type     : Dem_DTCOriginType
 Sync/Async      : Synchronous
 Reentrancy      : Reentrant
 Description     : 
 **************************************************************************/
Dem_DTCOriginType Dem_InternalGetDTCOrigin(uint32 DTC)
{
  Dem_DTCOriginType fl_RetVal = DEM_DTC_ORIGIN_INVALID;
  uint16 flEventId;

  flEventId = Dem_InternalGetEventIdByDTCValue(DTC);
  if(flEventId != DEM_EVENT_INVALID)
  {
    fl_RetVal = Dem_Cfg_EventParameter[flEventId].DemOrigin;
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_ClearDTC(uint8 ClientId)
{
  Dem_ReturnClearDTCType fl_RetVal;
  fl_RetVal = DEM_CLEAR_FAILED;

  #if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
    fl_RetVal = DEM_CLEAR_FAILED;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
    fl_RetVal = DEM_CLEAR_WRONG_DTCORIGIN;
  }
  else
  {
    /*Do Nothing*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
  #endif
  {
    if(Dem_Cfg_Client[ClientId].DemClientFunctionality == DEM_CLIENT_USES_FULL_FUNCTIONALITY)
    {
      Dem_ProcessInitMForEventAll(DEM_INIT_MONITOR_CLEAR);
      fl_RetVal = Dem_InternalClearDTC(ClientId);
    }
    else
    {
      Dem_DTCSelector[ClientId].ActiveOps = 0;
    }
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_DisableDTCSetting
 Arguments       : uint8 ClientId

 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : Disables the DTC setting for a DTC group.
 **************************************************************************/
Std_ReturnType Dem_DisableDTCSetting(uint8 ClientId)
{
  Std_ReturnType fl_RetVal = DEM_CONTROL_DTC_SETTING_N_OK;
  uint8 OpStatus= 0;
  /* Fix for MISRA */
  DEM_IGNORE_UNREF_PARAM(OpStatus);

  #if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
  #endif
  {
    Dem_Internal.DtcSettingConditionRequestedFlag = TRUE;
    Dem_Internal.DtcSettingEnConditionQueue = DEM_DTC_STORAGE_SETTING_DISABLED;
    fl_RetVal = DEM_CONTROL_DTC_SETTING_OK;
	  Dem_DTCSelector[ClientId].ActiveOps = 0;
  }
  return fl_RetVal;
}

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
Std_ReturnType Dem_EnableDTCSetting(uint8 ClientId)
{
  Std_ReturnType fl_RetVal;
  uint8 OpStatus= 0;
  fl_RetVal = DEM_CONTROL_DTC_SETTING_N_OK;
  /* Fix for MISRA */
  DEM_IGNORE_UNREF_PARAM(OpStatus);

  #if(DemDevErrorDetect == TRUE)
  uint8 flError;
  flError = DEM_DET_NO_ERROR;
  if (Dem_Internal.InitState != DEM_INITIALIZED)
  {
    flError = DEM_DET_UNINITIALIZED;
  }
  else if (ClientId >= Dem_Cfg_Num_Of_Clients)
  {
    flError = DEM_DET_INVALID_PARAMETER;
  }
  else
  {
    /*DO NOTHING - MISRA FIX*/
  }
  if (flError != DEM_DET_NO_ERROR)
  {
    Dem_Det_Error_register(0,flError);
  }
  else
  #endif
  {
    Dem_Internal.DtcSettingConditionRequestedFlag = TRUE;
    Dem_Internal.DtcSettingEnConditionQueue = DEM_DTC_STORAGE_SETTING_ENABLED;
    fl_RetVal = DEM_CONTROL_DTC_SETTING_OK;
	  Dem_DTCSelector[ClientId].ActiveOps = 0;
  }
  return fl_RetVal;
}

/**************************************************************************
 Function name   : Dem_NvM_JobFinished
 Arguments       : uint8 ServiceId, NvM_RequestResultType JobResult

 Return type     : Std_ReturnType
 Sync/Async      : Synchronous
 Reentrancy      : Non Reentrant
 Description     : NVM CallBack .
 **************************************************************************/
Std_ReturnType Dem_NvM_JobFinished(uint8 ServiceId, NvM_RequestResultType JobResult)
{
  Std_ReturnType fl_RetVal = E_OK;

  DEM_IGNORE_UNREF_PARAM(ServiceId);

  if (Dem_NvmWriteData.WriteStatus == DEM_NVM_WRITING)
  {
    if (JobResult == NVM_REQ_OK)
    { 
      /* Write request aborted or otherwise failed. */
      Dem_NvmWriteData.WriteStatus = DEM_NVM_FINISHED;
    }
    else if(JobResult == NVM_REQ_PENDING)
    {
      /*Do nothing*/
    }
    else
    {
      /* Continue with next block */
      Dem_NvmWriteData.WriteStatus = DEM_NVM_FAILED;
    }
  }
  return fl_RetVal;
}


/*** OBD-specific Dcm <=> Dem Interfaces *** Not Supported ***/
/*** Interface J1939Dcm <=> Dem *** Not Supported ***/
/*** OBD-specific Interfaces *** Not Supported ***/
/*** Interface Dlt <=> Dem *** Not Supported ***/
#define DIAGMGR_CODE_SEC_END
#include "MemMap.h"

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
/*Date              : 05-Feb-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Rtc#735134                                            */
/*Change Description: 0x19-0x14 service issue fix and design changes        */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 29-Aug-2020                                           */
/*Version           :                                                       */
/*By                : bbaskara                                              */
/*Traceability      : Rtc#1029668                                           */
/*Change Description: 0x19 0x06 service design changes                      */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 19-Sep-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : Rtc#1046434                                           */
/*Change Description: 0x19 0x04 service design changes and defect fixes     */
/*--------------------------------------------------------------------------*/
/**-------------------------------------------------------------------------*/
/*Date              : 16-Nov-2020                                           */
/*Version           :                                                       */
/*By                : msavariy                                              */
/*Traceability      : 1126337: [vAutosar] Dem - Quality                     */
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
