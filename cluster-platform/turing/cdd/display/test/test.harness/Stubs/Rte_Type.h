/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Type.h
 *           Config:  Audi_Etron_TV2.dpa
 *      ECU-Project:  Audi_Etron_TV2
 *
 *        Generator:  MICROSAR RTE Generator Version 4.39.00
 *                    RTE Core Version 4.39.00
 *          License:  CBD2500735
 *
 *      Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/* double include prevention */
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

# include "Rte.h"
# include "Rte_Cfg.h"
# ifdef RTE_CORE
/**********************************************************************************************************************
 * Type definitions for mode management
 *********************************************************************************************************************/
typedef EventMaskType Rte_EventMaskType;
# endif /* defined(RTE_CORE) */

/* PRQA S 1039 EOF */ /* MD_Rte_1039 */

/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Dcm_MessageType
typedef uint8 Dcm_MessageType;

# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;

# define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;

# define Rte_TypeDef_Dem_DTCOriginType
typedef uint8 Dem_DTCOriginType;

# define Rte_TypeDef_Dem_DTCSeverityType
typedef uint8 Dem_DTCSeverityType;

# define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

# define Rte_TypeDef_Dlt_LogChannelNameType
typedef uint8 Dlt_LogChannelNameType;

# define Rte_TypeDef_Dlt_MessageArgumentCount
typedef uint16 Dlt_MessageArgumentCount;

# define Rte_TypeDef_Dlt_MessageOptionsType
typedef uint8 Dlt_MessageOptionsType;

# define Rte_TypeDef_Dlt_SessionIDType
typedef uint32 Dlt_SessionIDType;

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_Rte_DT_Dlt_ApplicationIDType_0
typedef uint8 Rte_DT_Dlt_ApplicationIDType_0;

# define Rte_TypeDef_Rte_DT_Dlt_ContextIDType_0
typedef uint8 Rte_DT_Dlt_ContextIDType_0;

# define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_160_0
typedef uint8 Rte_DT_Nvm_U8ArrType_160_0;

# define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_20_0
typedef uint8 Rte_DT_Nvm_U8ArrType_20_0;

# define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_3_0
typedef uint8 Rte_DT_Nvm_U8ArrType_3_0;

# define Rte_TypeDef_Rte_DT_tComSignal64_0
typedef uint8 Rte_DT_tComSignal64_0;

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Dlt_AssignmentOperation
typedef uint8 Dlt_AssignmentOperation;

# define Rte_TypeDef_Dlt_MessageLogLevelType
typedef uint8 Dlt_MessageLogLevelType;

# define Rte_TypeDef_Dlt_MessageTraceType
typedef uint8 Dlt_MessageTraceType;

# define Rte_TypeDef_ECmpCmd
typedef uint8 ECmpCmd;

# define Rte_TypeDef_EDcmExtAction
typedef uint8 EDcmExtAction;

# define Rte_TypeDef_EDeviceStatus
typedef uint8 EDeviceStatus;

# define Rte_TypeDef_EDisplayCddStatus
typedef uint8 EDisplayCddStatus;

# define Rte_TypeDef_EDisplayPowerState
typedef uint8 EDisplayPowerState;

# define Rte_TypeDef_EDisplayType
typedef uint8 EDisplayType;

# define Rte_TypeDef_EDisplayStatus
typedef uint8 EDisplayStatus;

# define Rte_TypeDef_EBistPatternType
typedef uint8 EBistPatternType;

# define Rte_TypeDef_EPowerState
typedef uint8 EPowerState;



# define Rte_TypeDef_EGammaCorrectionStatus
typedef uint8 EGammaCorrectionStatus;

# define Rte_TypeDef_EMeetModeStatus
typedef uint8 EMeetModeStatus;

# define Rte_TypeDef_HTimer
typedef uint8 HTimer;

# define Rte_TypeDef_IoHwAb_AdcSignalIdType
typedef uint8 IoHwAb_AdcSignalIdType;

# define Rte_TypeDef_IoHwAb_DInGroupIdType
typedef sint32 IoHwAb_DInGroupIdType;

# define Rte_TypeDef_IoHwAb_DInSignalIdType
typedef uint8 IoHwAb_DInSignalIdType;

# define Rte_TypeDef_IoHwAb_DOutGroupIdType
typedef sint32 IoHwAb_DOutGroupIdType;

# define Rte_TypeDef_IoHwAb_DOutSignalIdType
typedef uint8 IoHwAb_DOutSignalIdType;

# define Rte_TypeDef_IoHwAb_ErrorType
typedef uint8 IoHwAb_ErrorType;

# define Rte_TypeDef_IoHwAb_PwmSignalIdType
typedef uint8 IoHwAb_PwmSignalIdType;

# define Rte_TypeDef_eIOPulseInputId
typedef sint32 eIOPulseInputId;

# define Rte_TypeDef_tDiagSessionSt
typedef uint8 tDiagSessionSt;

# define Rte_TypeDef_tRxSignalId
typedef uint8 tRxSignalId;

# define Rte_TypeDef_tRxSignalJustRcvdStatus
typedef uint8 tRxSignalJustRcvdStatus;

# define Rte_TypeDef_tRxSignalStatus
typedef uint8 tRxSignalStatus;

# define Rte_TypeDef_tTxSigConfirmStatus
typedef uint8 tTxSigConfirmStatus;

# define Rte_TypeDef_tTxSignalId
typedef uint8 tTxSignalId;

# define Rte_TypeDef_teDIDOperation
typedef uint8 teDIDOperation;

# define Rte_TypeDef_teDTCOperation
typedef uint8 teDTCOperation;

# define Rte_TypeDef_teDiagFilterBypassMode
typedef uint8 teDiagFilterBypassMode;

# define Rte_TypeDef_teRoutineOperation
typedef uint8 teRoutineOperation;

# define Rte_TypeDef_teSetAllTelltalesDiagCtrl
typedef uint8 teSetAllTelltalesDiagCtrl;

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[1];

# define Rte_TypeDef_Dlt_ApplicationIDType
typedef Rte_DT_Dlt_ApplicationIDType_0 Dlt_ApplicationIDType[4];

# define Rte_TypeDef_Dlt_ContextIDType
typedef Rte_DT_Dlt_ContextIDType_0 Dlt_ContextIDType[4];

# define Rte_TypeDef_Nvm_U8ArrType_160
typedef Rte_DT_Nvm_U8ArrType_160_0 Nvm_U8ArrType_160[160];

# define Rte_TypeDef_Nvm_U8ArrType_20
typedef Rte_DT_Nvm_U8ArrType_20_0 Nvm_U8ArrType_20[20];

# define Rte_TypeDef_Nvm_U8ArrType_3
typedef Rte_DT_Nvm_U8ArrType_3_0 Nvm_U8ArrType_3[3];

# define Rte_TypeDef_tComSignal64
typedef Rte_DT_tComSignal64_0 tComSignal64[8];

/*! Type distinguishes the different modes that were configured for the WdgM */
# ifndef Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;
# endif

/*! The local supervision status represents status of each Supervised Entity individually */
# ifndef Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;
# endif

/*! The global supervision status summarizes the local supervision status of all supervised entities */
# ifndef Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;
# endif


# define Rte_TypeDef_SPulseInputConfigParam
typedef struct
{
  UInt32 MissingRecoveryTimeoutInMicroSec;
  UInt32 ValidPeriodMinInMicroSec;
  UInt32 ValidPeriodMaxInMicroSec;
  UInt32 HystLimitForPeriodMinInMicroSec;
  UInt32 HystRcvryForPeriodMinInMicroSec;
  UInt32 HystLimitForPeriodMaxInMicroSec;
  UInt32 HystRcvryForPeriodMaxInMicroSec;
  UInt16 ValidDutyMinInPercentage;
  UInt16 ValidDutyMaxInPercentage;
  UInt16 HystLimitForDutyMinInPercentage;
  UInt16 HystRcvryForDutyMinInPercentage;
  UInt16 HystLimitForDutyMaxInPercentage;
  UInt16 HystRcvryForDutyMaxInPercentage;
  UInt16 InValidTimeoutInMilliSec;
  UInt16 InValidRecoveryTimeoutInMilliSec;
  UInt16 MissingTimeoutInMilliSec;
} SPulseInputConfigParam;

# define Rte_TypeDef_SSpeedCalcParam
typedef struct
{
  UInt32 Pulses_Per_Revolution;
  UInt32 Revolutions_Per_Unit;
  UInt32 Tuning_Factor;
} SSpeedCalcParam;

# define Rte_TypeDef_ComMMode_ReferenceType
typedef uint8 ComMMode_ReferenceType;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint16 ComM_UserHandleType;

# define Rte_TypeDef_Dem_BufferLengthType
typedef uint16 Dem_BufferLengthType;

# define Rte_TypeDef_Dem_DTCGroupType
typedef uint32 Dem_DTCGroupType;

# define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;

# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;

# define Rte_TypeDef_Dem_RatioIdType
typedef uint16 Dem_RatioIdType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

# define Rte_TypeDef_Dem_DTRControlType
typedef uint8 Dem_DTRControlType;

# define Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;

# define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;

# define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;

# define Rte_TypeDef_Dem_IndicatorStatusType
typedef uint8 Dem_IndicatorStatusType;

# define Rte_TypeDef_Dem_InitMonitorReasonType
typedef uint8 Dem_InitMonitorReasonType;

# define Rte_TypeDef_Dem_IumprDenomCondIdType
typedef uint8 Dem_IumprDenomCondIdType;

# define Rte_TypeDef_Dem_IumprDenomCondStatusType
typedef uint8 Dem_IumprDenomCondStatusType;

# define Rte_TypeDef_Dem_IumprReadinessGroupType
typedef uint8 Dem_IumprReadinessGroupType;

# define Rte_TypeDef_Dem_MonitorStatusType
typedef uint8 Dem_MonitorStatusType;

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;

# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;

# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_Dlt_ContextIdInfoType
typedef struct
{
  Dlt_ContextIDType contextId;
  Dlt_MessageLogLevelType logLevel;
  UInt8 traceStatus;
  UInt16 lenContextDescription;
  UInt8 contextDesc;
} Dlt_ContextIdInfoType;

# define Rte_TypeDef_Dlt_MessageLogInfoType
typedef struct
{
  Dlt_MessageArgumentCount argCount;
  Dlt_MessageLogLevelType logLevel;
  Dlt_MessageOptionsType options;
  Dlt_ContextIDType contextId;
  Dlt_ApplicationIDType appId;
} Dlt_MessageLogInfoType;

# define Rte_TypeDef_Dlt_MessageTraceInfoType
typedef struct
{
  Dlt_MessageTraceType traceInfo;
  Dlt_MessageOptionsType options;
  Dlt_ContextIDType context;
  Dlt_ApplicationIDType appId;
} Dlt_MessageTraceInfoType;

# define Rte_TypeDef_Dlt_ApplicationIdInfoType
typedef struct
{
  Dlt_ApplicationIDType appId;
  UInt16 contextIdCount;
  Dlt_ContextIdInfoType contextInfoList;
  UInt16 appDescLen;
  UInt8 appDesc;
} Dlt_ApplicationIdInfoType;

# define Rte_TypeDef_Dlt_LogInfoType
typedef struct
{
  UInt16 appIdCount;
  Dlt_ApplicationIdInfoType appIdInfo;
} Dlt_LogInfoType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

#  define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

#  define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;

#  define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# endif
# include "Rte_DataHandleType.h"

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned int Rte_BitType;
/**********************************************************************************************************************
 * type and extern declarations of RTE internal variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

# define RTE_STATE_UNINIT     (0U)
# define RTE_STATE_SCHM_START (1U)
# define RTE_STATE_SCHM_INIT  (2U)
# define RTE_STATE_INIT       (3U)

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_EcucPartition_ASIL_B_START_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(UInt8, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_DiagSession_DiagSessionData; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_DisplayIlluminationDiagCtrl_DisplayIllumCtrlData; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(teDiagFilterBypassMode, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_FilterBypassModeCtrl_DiagFilterBypassModeCtrl; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(teSetAllTelltalesDiagCtrl, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_SetAllTelltalesDiagCtrl_TelltalesDiagCtrlData; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_SleepReq_SleepReqData; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CSleepManager_ppSR_SleepStatus_SleepManager_SleepStatus; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DG_16_vehicle_type_U8; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Diag_config_var_16_padding_U8A; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Diag_config_var_5_padding_U8A; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Dlt_Fetal_Storage; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Dlt_Main_Storage; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_EOL_Mfg_Mode_Entry; /* PRQA S 3408, 1504 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */

#  define RTE_EcucPartition_ASIL_B_STOP_SEC_VAR_INIT_ASIL_B_LOCAL_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




# endif /* defined(RTE_CORE) */

#endif /* RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_1039:  MISRA rule: Rule1.2
     Reason:     Same macro and function names are required to meet AUTOSAR spec.
     Risk:       No functional risk. Macro will be undefined before function definition.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

*/
