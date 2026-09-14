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
 *          File:  Rte_Type.h
 *        Config:  BMW.dpa
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header file containing user defined AUTOSAR types and RTE structures
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_TYPE_H
# define _RTE_TYPE_H

# include "Rte.h"


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Dlt_ApplicationIDType
typedef uint8 Dlt_ApplicationIDType;

# define Rte_TypeDef_Dlt_ContextIDType
typedef uint8 Dlt_ContextIDType;

# define Rte_TypeDef_Dlt_LogChannelNameType
typedef uint8 Dlt_LogChannelNameType;

# define Rte_TypeDef_Dlt_MessageArgumentCount
typedef uint16 Dlt_MessageArgumentCount;

# define Rte_TypeDef_Dlt_MessageOptionsType
typedef uint8 Dlt_MessageOptionsType;

# define Rte_TypeDef_Dlt_SessionIDType
typedef uint32 Dlt_SessionIDType;

# define Rte_TypeDef_EcuMExt_ResetType
typedef uint8 EcuMExt_ResetType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_Rte_DT_Arr_u8_100_0
typedef uint8 Rte_DT_Arr_u8_100_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_1024_0
typedef uint8 Rte_DT_Arr_u8_1024_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_128_0
typedef uint8 Rte_DT_Arr_u8_128_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_16_0
typedef uint8 Rte_DT_Arr_u8_16_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_2048_0
typedef uint8 Rte_DT_Arr_u8_2048_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_256_0
typedef uint8 Rte_DT_Arr_u8_256_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_32_0
typedef uint8 Rte_DT_Arr_u8_32_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_48_0
typedef uint8 Rte_DT_Arr_u8_48_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_64_0
typedef uint8 Rte_DT_Arr_u8_64_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_8_0
typedef uint8 Rte_DT_Arr_u8_8_0;

# define Rte_TypeDef_Rte_DT_data_u8_256_0
typedef uint8 Rte_DT_data_u8_256_0;

# define Rte_TypeDef_Rte_DT_data_u8_32_0
typedef uint8 Rte_DT_data_u8_32_0;

# define Rte_TypeDef_Rte_DT_data_u8_8_0
typedef uint8 Rte_DT_data_u8_8_0;

# define Rte_TypeDef_Rte_DT_data_uint8_8_0
typedef uint8 Rte_DT_data_uint8_8_0;

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;

# define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

# define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

# define Rte_TypeDef_uint8_Ref
typedef uint8 uint8_Ref;

# define Rte_TypeDef_Dlt_AssignmentOperation
typedef uint8 Dlt_AssignmentOperation;

# define Rte_TypeDef_Dlt_MessageLogLevelType
typedef uint8 Dlt_MessageLogLevelType;

# define Rte_TypeDef_Dlt_MessageTraceType
typedef uint8 Dlt_MessageTraceType;

# define Rte_TypeDef_ECmpCmd
typedef uint8 ECmpCmd;

# define Rte_TypeDef_EDeviceStatus
typedef uint8 EDeviceStatus;

# define Rte_TypeDef_EDidType
typedef uint8 EDidType;

# define Rte_TypeDef_EDisplayCddStatus
typedef uint8 EDisplayCddStatus;

# define Rte_TypeDef_EDisplayPowerState
typedef uint8 EDisplayPowerState;

# define Rte_TypeDef_EDisplayType
typedef uint8 EDisplayType;

# define Rte_TypeDef_EDmnChangeReqStatus_t
typedef uint8 EDmnChangeReqStatus_t;

# define Rte_TypeDef_EDmnHealthState_t
typedef uint8 EDmnHealthState_t;

# define Rte_TypeDef_EDmnOverallState_t
typedef uint8 EDmnOverallState_t;

# define Rte_TypeDef_EDomainId
typedef uint8 EDomainId;

# define Rte_TypeDef_EGammaCorrectionStatus
typedef uint8 EGammaCorrectionStatus;

# define Rte_TypeDef_EIOCtrlOptType
typedef uint8 EIOCtrlOptType;

# define Rte_TypeDef_EIgnitionStatus
typedef uint8 EIgnitionStatus;

# define Rte_TypeDef_ERoutineType
typedef uint8 ERoutineType;

# define Rte_TypeDef_ESystemState
typedef uint8 ESystemState;

# define Rte_TypeDef_EUclLinkState_t
typedef uint8 EUclLinkState_t;

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

# define Rte_TypeDef_Arr_u8_100
typedef Rte_DT_Arr_u8_100_0 Arr_u8_100[100];

# define Rte_TypeDef_Arr_u8_1024
typedef Rte_DT_Arr_u8_1024_0 Arr_u8_1024[1024];

# define Rte_TypeDef_Arr_u8_128
typedef Rte_DT_Arr_u8_128_0 Arr_u8_128[128];

# define Rte_TypeDef_Arr_u8_16
typedef Rte_DT_Arr_u8_16_0 Arr_u8_16[16];

# define Rte_TypeDef_Arr_u8_2048
typedef Rte_DT_Arr_u8_2048_0 Arr_u8_2048[2048];

# define Rte_TypeDef_Arr_u8_256
typedef Rte_DT_Arr_u8_256_0 Arr_u8_256[256];

# define Rte_TypeDef_Arr_u8_32
typedef Rte_DT_Arr_u8_32_0 Arr_u8_32[32];

# define Rte_TypeDef_Arr_u8_48
typedef Rte_DT_Arr_u8_48_0 Arr_u8_48[48];

# define Rte_TypeDef_Arr_u8_64
typedef Rte_DT_Arr_u8_64_0 Arr_u8_64[64];

# define Rte_TypeDef_Arr_u8_8
typedef Rte_DT_Arr_u8_8_0 Arr_u8_8[8];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[1];

# define Rte_TypeDef_data_u8_256
typedef Rte_DT_data_u8_256_0 data_u8_256[256];

# define Rte_TypeDef_data_u8_32
typedef Rte_DT_data_u8_32_0 data_u8_32[32];

# define Rte_TypeDef_data_u8_8
typedef Rte_DT_data_u8_8_0 data_u8_8[8];

# define Rte_TypeDef_data_uint8_8
typedef Rte_DT_data_uint8_8_0 data_uint8_8[8];

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
  Dlt_MessageArgumentCount arg_count;
  Dlt_MessageLogLevelType log_level;
  Dlt_MessageOptionsType options;
  Dlt_ContextIDType context_id;
  Dlt_ApplicationIDType app_id;
} Dlt_MessageLogInfoType;

# define Rte_TypeDef_Dlt_MessageTraceInfoType
typedef struct
{
  Dlt_MessageTraceType traceInfo;
  Dlt_MessageOptionsType option;
  Dlt_ContextIDType context;
  Dlt_ApplicationIDType appId;
} Dlt_MessageTraceInfoType;

# define Rte_TypeDef_Rtc_AlarmType
typedef struct
{
  UInt8 day;
  UInt8 minute;
  UInt8 hour;
} Rtc_AlarmType;

# define Rte_TypeDef_Rtc_TimeType
typedef struct
{
  UInt16 year;
  uint8_Ref month;
  UInt8 week;
  UInt8 day;
  UInt8 hour;
  UInt8 minute;
  UInt8 second;
} Rtc_TimeType;

# define Rte_TypeDef_SDmnStatus
typedef struct
{
  EDomainId dmnId;
  EUclLinkState_t linkStatus;
  SInt32 uclErrCode;
  EDmnHealthState_t dmnHealthState;
  ESystemState state;
  EDmnOverallState_t dmnStatus;
} SDmnStatus;

# define Rte_TypeDef_SHealthDomainFatalError
typedef struct
{
  EDomainId domainId;
  UInt32 compIdx;
} SHealthDomainFatalError;

# define Rte_TypeDef_SHealthDomainHeartbeat
typedef struct
{
  EDomainId domainId;
  UInt32 seqCnt;
} SHealthDomainHeartbeat;

# define Rte_TypeDef_SHealthDumpGetData
typedef struct
{
  UInt8 reserved;
} SHealthDumpGetData;

# define Rte_TypeDef_SHealthDumpGetHdr
typedef struct
{
  UInt8 encrypt;
} SHealthDumpGetHdr;

# define Rte_TypeDef_SHealthDumpHdrInfo
typedef struct
{
  UInt32 fileSize;
} SHealthDumpHdrInfo;

# define Rte_TypeDef_SIgnState
typedef struct
{
  EIgnitionStatus state;
} SIgnState;

# define Rte_TypeDef_SPowerExtendShutdownTime
typedef struct
{
  EDomainId domainId;
  UInt32 timeoutMs;
} SPowerExtendShutdownTime;

# define Rte_TypeDef_SPowerKeepSystemAwake
typedef struct
{
  EDomainId domainId;
  UInt32 timeoutMs;
} SPowerKeepSystemAwake;

# define Rte_TypeDef_SPowerSystemState
typedef struct
{
  EDomainId domainId;
  ESystemState state;
} SPowerSystemState;

# define Rte_TypeDef_SPowerSystemStateReqChange
typedef struct
{
  ESystemState state;
  EDomainId domainId;
} SPowerSystemStateReqChange;

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

# define Rte_TypeDef_tDlt_BH_MessageFormat
typedef struct
{
  UInt32 HeaderType;
  UInt8 MessageCount;
  UInt16 MessageLen;
  UInt8 MessageInfo;
  UInt8 no_of_arguments;
  UInt32 LogMessage_Timestamp;
} tDlt_BH_MessageFormat;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint8 ComM_UserHandleType;

# define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;

# define Rte_TypeDef_Dem_DTCGroupType
typedef uint32 Dem_DTCGroupType;

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;

# define Rte_TypeDef_Dem_DTCSeverityType
typedef uint8 Dem_DTCSeverityType;

# define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;

# define Rte_TypeDef_Dem_DTRControlType
typedef uint8 Dem_DTRControlType;

# define Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;

# define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;

# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;

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

# define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;

# define Rte_TypeDef_Dem_RatioIdType
typedef uint16 Dem_RatioIdType;

# define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

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

# define Rte_TypeDef_EDisplayStatus
typedef uint8 EDisplayStatus;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;

# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;

# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;

# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_EnetReqCmd_t
typedef uint8 EnetReqCmd_t;

# define Rte_TypeDef_EnetReqMode_t
typedef uint8 EnetReqMode_t;

# define Rte_TypeDef_NV_Data_BsConst_Audio
typedef struct
{
  Arr_u8_128 BsConst_Audio_Element;
} NV_Data_BsConst_Audio;

# define Rte_TypeDef_NV_Data_BsConst_Communication
typedef struct
{
  Arr_u8_64 BsConst_Communication_Element;
} NV_Data_BsConst_Communication;

# define Rte_TypeDef_NV_Data_BsConst_EngOffTimer
typedef struct
{
  Arr_u8_32 BsConst_EngOffTimer_Element;
} NV_Data_BsConst_EngOffTimer;

# define Rte_TypeDef_NV_Data_BsConst_FuelGauge
typedef struct
{
  Arr_u8_128 BsConst_FuelGauge_Element;
} NV_Data_BsConst_FuelGauge;

# define Rte_TypeDef_NV_Data_BsConst_Illumination
typedef struct
{
  Arr_u8_128 BsConst_Illumination_Element;
} NV_Data_BsConst_Illumination;

# define Rte_TypeDef_NV_Data_BsConst_OilGauge
typedef struct
{
  Arr_u8_64 BsConst_OilGauge_Element;
} NV_Data_BsConst_OilGauge;

# define Rte_TypeDef_NV_Data_BsConst_Power
typedef struct
{
  Arr_u8_32 BsConst_Power_Element;
} NV_Data_BsConst_Power;

# define Rte_TypeDef_NV_Data_BsConst_PowerGauge
typedef struct
{
  Arr_u8_64 BsConst_PowerGauge_Element;
} NV_Data_BsConst_PowerGauge;

# define Rte_TypeDef_NV_Data_BsConst_RealTimeClock
typedef struct
{
  Arr_u8_48 BsConst_RealTimeClock_Element;
} NV_Data_BsConst_RealTimeClock;

# define Rte_TypeDef_NV_Data_BsConst_ServiceReminder
typedef struct
{
  Arr_u8_48 BsConst_ServiceReminder_Element;
} NV_Data_BsConst_ServiceReminder;

# define Rte_TypeDef_NV_Data_BsConst_SpeedoGauge
typedef struct
{
  Arr_u8_64 BsConst_SpeedoGauge_Element;
} NV_Data_BsConst_SpeedoGauge;

# define Rte_TypeDef_NV_Data_BsConst_TachoGauge
typedef struct
{
  Arr_u8_64 BsConst_TachoGauge_Element;
} NV_Data_BsConst_TachoGauge;

# define Rte_TypeDef_NV_Data_BsConst_TempGauge
typedef struct
{
  Arr_u8_64 BsConst_TempGauge_Element;
} NV_Data_BsConst_TempGauge;

# define Rte_TypeDef_NV_Data_BsConst_TripComputer
typedef struct
{
  Arr_u8_64 BsConst_TripComputer_Element;
} NV_Data_BsConst_TripComputer;

# define Rte_TypeDef_NV_Data_BsConst_Warning
typedef struct
{
  Arr_u8_64 BsConst_Warning_Element;
} NV_Data_BsConst_Warning;

# define Rte_TypeDef_NV_Data_BsCys_Certicificate
typedef struct
{
  Arr_u8_64 BsCys_Certicificate_Element;
} NV_Data_BsCys_Certicificate;

# define Rte_TypeDef_NV_Data_BsDiag_Dtc
typedef struct
{
  Arr_u8_2048 BsDiag_Dtc_Element;
} NV_Data_BsDiag_Dtc;

# define Rte_TypeDef_NV_Data_BsDiag_ErrorRecord
typedef struct
{
  Arr_u8_1024 BsDiag_ErrorRecord_Element;
} NV_Data_BsDiag_ErrorRecord;

# define Rte_TypeDef_NV_Data_BsFuSa_Audio
typedef struct
{
  Arr_u8_32 BsFuSa_Audio_Element;
} NV_Data_BsFuSa_Audio;

# define Rte_TypeDef_NV_Data_BsFuSa_Communication
typedef struct
{
  Arr_u8_16 BsFuSa_Communication_Element;
} NV_Data_BsFuSa_Communication;

# define Rte_TypeDef_NV_Data_BsFuSa_Config
typedef struct
{
  Arr_u8_16 BsFuSa_Config_Element;
} NV_Data_BsFuSa_Config;

# define Rte_TypeDef_NV_Data_BsFuSa_Display
typedef struct
{
  Arr_u8_64 BsFuSa_Display_Element;
} NV_Data_BsFuSa_Display;

# define Rte_TypeDef_NV_Data_BsFuSa_Power
typedef struct
{
  Arr_u8_48 BsFuSa_Power_Element;
} NV_Data_BsFuSa_Power;

# define Rte_TypeDef_NV_Data_BsFuSa_Warning
typedef struct
{
  Arr_u8_32 BsFuSa_Warning_Element;
} NV_Data_BsFuSa_Warning;

# define Rte_TypeDef_NV_Data_BsFusa_Fota
typedef struct
{
  Arr_u8_32 BsFusa_Fota_Element;
} NV_Data_BsFusa_Fota;

# define Rte_TypeDef_NV_Data_BsReten_Audio
typedef struct
{
  Arr_u8_100 BsReten_Audio_Element;
} NV_Data_BsReten_Audio;

# define Rte_TypeDef_NV_Data_BsReten_Communication
typedef struct
{
  Arr_u8_100 BsReten_Communication_Element;
} NV_Data_BsReten_Communication;

# define Rte_TypeDef_NV_Data_BsReten_Display
typedef struct
{
  Arr_u8_100 BsReten_Display_Element;
} NV_Data_BsReten_Display;

# define Rte_TypeDef_NV_Data_BsReten_Gauges
typedef struct
{
  Arr_u8_100 BsReten_Gauges_Element;
} NV_Data_BsReten_Gauges;

# define Rte_TypeDef_NV_Data_BsReten_Illumination
typedef struct
{
  Arr_u8_100 BsReten_Illumination_Element;
} NV_Data_BsReten_Illumination;

# define Rte_TypeDef_NV_Data_BsReten_Odometer
typedef struct
{
  Arr_u8_100 BsReten_Odometer_Element;
} NV_Data_BsReten_Odometer;

# define Rte_TypeDef_NV_Data_BsReten_Personalization
typedef struct
{
  Arr_u8_100 BsReten_Personalization_Element;
} NV_Data_BsReten_Personalization;

# define Rte_TypeDef_NV_Data_BsReten_Power
typedef struct
{
  Arr_u8_100 BsReten_Power_Element;
} NV_Data_BsReten_Power;

# define Rte_TypeDef_NV_Data_BsReten_RealTimeClock
typedef struct
{
  Arr_u8_100 BsReten_RealTimeClock_Element;
} NV_Data_BsReten_RealTimeClock;

# define Rte_TypeDef_NV_Data_BsReten_Tripcomputer
typedef struct
{
  Arr_u8_100 BsReten_Tripcomputer_Element;
} NV_Data_BsReten_Tripcomputer;

# define Rte_TypeDef_NV_Data_BsReten_VisDlt
typedef struct
{
  Arr_u8_256 BsReten_VisDlt_Element;
} NV_Data_BsReten_VisDlt;

# define Rte_TypeDef_NV_Data_BsReten_Warning
typedef struct
{
  Arr_u8_100 BsReten_Warning_Element;
} NV_Data_BsReten_Warning;

# define Rte_TypeDef_NV_Data_BsRt_CusDlt
typedef struct
{
  Arr_u8_128 BsRt_CusDlt_Element;
} NV_Data_BsRt_CusDlt;

# define Rte_TypeDef_NV_Data_BsRt_FuelGauge
typedef struct
{
  Arr_u8_32 BsRt_FuelGauge_Element;
} NV_Data_BsRt_FuelGauge;

# define Rte_TypeDef_NV_Data_BsRt_Illumination
typedef struct
{
  Arr_u8_100 BsRt_Illumination_Element;
} NV_Data_BsRt_Illumination;

# define Rte_TypeDef_NV_Data_BsRt_Odometer
typedef struct
{
  Arr_u8_128 BsRt_Odometer_Element;
} NV_Data_BsRt_Odometer;

# define Rte_TypeDef_NV_Data_BsRt_OilGauge
typedef struct
{
  Arr_u8_8 BsRt_OilGauge_Element;
} NV_Data_BsRt_OilGauge;

# define Rte_TypeDef_NV_Data_BsRt_Personalization
typedef struct
{
  Arr_u8_128 BsRt_Personalization_Element;
} NV_Data_BsRt_Personalization;

# define Rte_TypeDef_NV_Data_BsRt_PowerGauge
typedef struct
{
  Arr_u8_32 BsRt_PowerGauge_Element;
} NV_Data_BsRt_PowerGauge;

# define Rte_TypeDef_NV_Data_BsRt_RealTimeClock
typedef struct
{
  Arr_u8_48 BsRt_RealTimeClock_Element;
} NV_Data_BsRt_RealTimeClock;

# define Rte_TypeDef_NV_Data_BsRt_SpeedoGauge
typedef struct
{
  Arr_u8_8 BsRt_SpeedoGauge_Element;
} NV_Data_BsRt_SpeedoGauge;

# define Rte_TypeDef_NV_Data_BsRt_TachoGauge
typedef struct
{
  Arr_u8_16 BsRt_TachoGauge_Element;
} NV_Data_BsRt_TachoGauge;

# define Rte_TypeDef_NV_Data_BsRt_TempGauge
typedef struct
{
  Arr_u8_32 BsRt_TempGauge_Element;
} NV_Data_BsRt_TempGauge;

# define Rte_TypeDef_NV_Data_BsRt_TripComputer
typedef struct
{
  Arr_u8_64 BsRt_TripComputer_Element;
} NV_Data_BsRt_TripComputer;

# define Rte_TypeDef_NV_Data_BsRt_Warning
typedef struct
{
  Arr_u8_32 BsRt_Warning_Element;
} NV_Data_BsRt_Warning;

# define Rte_TypeDef_NV_Data_BsShare_EcuPartNumber
typedef struct
{
  Arr_u8_128 BsShare_EcuPartNumber_Element;
} NV_Data_BsShare_EcuPartNumber;

# define Rte_TypeDef_NV_Data_BsShare_SwUpdFotaFinPrint
typedef struct
{
  Arr_u8_32 BsShare_SwUpdFotaFinPrint_Element;
} NV_Data_BsShare_SwUpdFotaFinPrint;

# define Rte_TypeDef_NV_Data_BsShare_SwUpdFotaMode
typedef struct
{
  Arr_u8_16 BsShare_SwUpdFotaMode_Element;
} NV_Data_BsShare_SwUpdFotaMode;

# define Rte_TypeDef_NV_Data_BsShare_SwUpdFotaStatus
typedef struct
{
  Arr_u8_48 BsShare_SwUpdFotaStatus_Element;
} NV_Data_BsShare_SwUpdFotaStatus;

# define Rte_TypeDef_NV_Data_BsShare_SwUpdFotadecrypt
typedef struct
{
  Arr_u8_64 BsShare_SwUpdFotadecrypt_Element;
} NV_Data_BsShare_SwUpdFotadecrypt;

# define Rte_TypeDef_NV_Data_BsShare_SwUpdReflash
typedef struct
{
  Arr_u8_8 BsShare_SwUpdReflash_Element;
} NV_Data_BsShare_SwUpdReflash;

# define Rte_TypeDef_NV_Data_BsShare_VehicleConfig
typedef struct
{
  Arr_u8_256 BsShare_VehicleConfig_Element;
} NV_Data_BsShare_VehicleConfig;

# define Rte_TypeDef_NV_Data_BsShare_VisMeet
typedef struct
{
  Arr_u8_48 BsShare_VisMeet_Element;
} NV_Data_BsShare_VisMeet;

# define Rte_TypeDef_NV_Data_RefCys_Certicificate
typedef struct
{
  Arr_u8_64 RefCys_Certicificate_Element;
} NV_Data_RefCys_Certicificate;

# define Rte_TypeDef_NV_Data_RefCys_Certicificate1
typedef struct
{
  Arr_u8_64 RefCys_Certicificate1_Element;
} NV_Data_RefCys_Certicificate1;

# define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# define Rte_TypeDef_SDiagDIDRequest
typedef struct
{
  UInt16 did;
  EDidType didType;
  UInt16 dataLen;
  data_u8_256 data;
} SDiagDIDRequest;

# define Rte_TypeDef_SDiagIOCtrlRequest
typedef struct
{
  UInt16 did;
  EIOCtrlOptType optionCtrl;
  UInt16 dataLen;
  data_u8_256 data;
} SDiagIOCtrlRequest;

# define Rte_TypeDef_SDiagRoutineRequest
typedef struct
{
  UInt16 routineId;
  ERoutineType routineType;
  UInt16 dataLen;
  data_u8_256 data;
} SDiagRoutineRequest;

# define Rte_TypeDef_SDisplayCurrentState
typedef struct
{
  uint32 displayId;
  EDisplayStatus state;
} SDisplayCurrentState;

# define Rte_TypeDef_SEnetRegReq
typedef struct
{
  EnetReqCmd_t cmd;
  EnetReqMode_t mode;
  uint8 dataLen;
  data_u8_8 data;
} SEnetRegReq;

# define Rte_TypeDef_SEnetRegResp
typedef struct
{
  EnetReqCmd_t cmd;
  uint8 respLen;
  data_u8_32 response;
} SEnetRegResp;

# define Rte_TypeDef_SHealthDumpData
typedef struct
{
  UInt32 chunkSize;
  data_u8_32 data;
} SHealthDumpData;

# define Rte_TypeDef_SHealthEventRecord
typedef struct
{
  uint8 recordType;
  uint8 recordLen;
  data_u8_8 recordData;
} SHealthEventRecord;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_tDlt_MessageFormat
typedef struct
{
  tDlt_BH_MessageFormat BaseHeader;
  data_uint8_8 PayLoad;
} tDlt_MessageFormat;

# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_EChimeStatus
typedef uint16 EChimeStatus;

#  define Rte_TypeDef_ELastToneStatus
typedef boolean ELastToneStatus;

#  define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_3_0
typedef uint8 Rte_DT_Nvm_U8ArrType_3_0;

#  define Rte_TypeDef_EChimeID
typedef uint8 EChimeID;

#  define Rte_TypeDef_EChimeType
typedef uint8 EChimeType;

#  define Rte_TypeDef_ESndInterruptType
typedef uint8 ESndInterruptType;

#  define Rte_TypeDef_ESndToneInterruptableType
typedef uint8 ESndToneInterruptableType;

#  define Rte_TypeDef_Nvm_U8ArrType_3
typedef Rte_DT_Nvm_U8ArrType_3_0 Nvm_U8ArrType_3[3];

#  define Rte_TypeDef_SSndCddChimeData
typedef struct
{
  UInt8 ChannelId;
  EChimeType ChimeType;
  UInt16 DynamicDeadTime;
} SSndCddChimeData;

#  define Rte_TypeDef_BswM_MDG_Sfd_NvmBlockStatus
typedef uint8 BswM_MDG_Sfd_NvmBlockStatus;

#  define Rte_TypeDef_Dem_DTCOriginType
typedef uint16 Dem_DTCOriginType;

#  define Rte_TypeDef_Ivd_RequestPostRun
typedef uint8 Ivd_RequestPostRun;

#  define Rte_TypeDef_NV_Data_NvMSampleBlock1
typedef struct
{
  Arr_u8_8 SampleElement1;
} NV_Data_NvMSampleBlock1;

#  define Rte_TypeDef_NV_Data_SampleBlock2
typedef struct
{
  Arr_u8_16 SampleElement2;
} NV_Data_SampleBlock2;

#  define Rte_TypeDef_SfdA_RequestRoleType
typedef uint8 SfdA_RequestRoleType;

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Arr_u8_100, RTE_CONST) Rte_C_Arr_u8_100_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_1024, RTE_CONST) Rte_C_Arr_u8_1024_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_128, RTE_CONST) Rte_C_Arr_u8_128_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_16, RTE_CONST) Rte_C_Arr_u8_16_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_2048, RTE_CONST) Rte_C_Arr_u8_2048_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_256, RTE_CONST) Rte_C_Arr_u8_256_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_32, RTE_CONST) Rte_C_Arr_u8_32_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_48, RTE_CONST) Rte_C_Arr_u8_48_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_64, RTE_CONST) Rte_C_Arr_u8_64_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_8, RTE_CONST) Rte_C_Arr_u8_8_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Audio, RTE_CONST) Rte_C_NV_Data_BsConst_Audio_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Communication, RTE_CONST) Rte_C_NV_Data_BsConst_Communication_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_EngOffTimer, RTE_CONST) Rte_C_NV_Data_BsConst_EngOffTimer_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_FuelGauge, RTE_CONST) Rte_C_NV_Data_BsConst_FuelGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Illumination, RTE_CONST) Rte_C_NV_Data_BsConst_Illumination_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_OilGauge, RTE_CONST) Rte_C_NV_Data_BsConst_OilGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Power, RTE_CONST) Rte_C_NV_Data_BsConst_Power_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_PowerGauge, RTE_CONST) Rte_C_NV_Data_BsConst_PowerGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_RealTimeClock, RTE_CONST) Rte_C_NV_Data_BsConst_RealTimeClock_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_ServiceReminder, RTE_CONST) Rte_C_NV_Data_BsConst_ServiceReminder_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_SpeedoGauge, RTE_CONST) Rte_C_NV_Data_BsConst_SpeedoGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_TachoGauge, RTE_CONST) Rte_C_NV_Data_BsConst_TachoGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_TempGauge, RTE_CONST) Rte_C_NV_Data_BsConst_TempGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_TripComputer, RTE_CONST) Rte_C_NV_Data_BsConst_TripComputer_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Warning, RTE_CONST) Rte_C_NV_Data_BsConst_Warning_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsCys_Certicificate, RTE_CONST) Rte_C_NV_Data_BsCys_Certicificate_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsDiag_Dtc, RTE_CONST) Rte_C_NV_Data_BsDiag_Dtc_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsDiag_ErrorRecord, RTE_CONST) Rte_C_NV_Data_BsDiag_ErrorRecord_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsFuSa_Audio, RTE_CONST) Rte_C_NV_Data_BsFuSa_Audio_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsFuSa_Communication, RTE_CONST) Rte_C_NV_Data_BsFuSa_Communication_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsFuSa_Config, RTE_CONST) Rte_C_NV_Data_BsFuSa_Config_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsFuSa_Display, RTE_CONST) Rte_C_NV_Data_BsFuSa_Display_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsFuSa_Power, RTE_CONST) Rte_C_NV_Data_BsFuSa_Power_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsFuSa_Warning, RTE_CONST) Rte_C_NV_Data_BsFuSa_Warning_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsFusa_Fota, RTE_CONST) Rte_C_NV_Data_BsFusa_Fota_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Audio, RTE_CONST) Rte_C_NV_Data_BsReten_Audio_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Communication, RTE_CONST) Rte_C_NV_Data_BsReten_Communication_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Display, RTE_CONST) Rte_C_NV_Data_BsReten_Display_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Gauges, RTE_CONST) Rte_C_NV_Data_BsReten_Gauges_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Illumination, RTE_CONST) Rte_C_NV_Data_BsReten_Illumination_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Odometer, RTE_CONST) Rte_C_NV_Data_BsReten_Odometer_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Personalization, RTE_CONST) Rte_C_NV_Data_BsReten_Personalization_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Power, RTE_CONST) Rte_C_NV_Data_BsReten_Power_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_RealTimeClock, RTE_CONST) Rte_C_NV_Data_BsReten_RealTimeClock_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Tripcomputer, RTE_CONST) Rte_C_NV_Data_BsReten_Tripcomputer_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_VisDlt, RTE_CONST) Rte_C_NV_Data_BsReten_VisDlt_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsReten_Warning, RTE_CONST) Rte_C_NV_Data_BsReten_Warning_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_CusDlt, RTE_CONST) Rte_C_NV_Data_BsRt_CusDlt_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_FuelGauge, RTE_CONST) Rte_C_NV_Data_BsRt_FuelGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_Illumination, RTE_CONST) Rte_C_NV_Data_BsRt_Illumination_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_Odometer, RTE_CONST) Rte_C_NV_Data_BsRt_Odometer_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_OilGauge, RTE_CONST) Rte_C_NV_Data_BsRt_OilGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_Personalization, RTE_CONST) Rte_C_NV_Data_BsRt_Personalization_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_PowerGauge, RTE_CONST) Rte_C_NV_Data_BsRt_PowerGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_RealTimeClock, RTE_CONST) Rte_C_NV_Data_BsRt_RealTimeClock_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_SpeedoGauge, RTE_CONST) Rte_C_NV_Data_BsRt_SpeedoGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_TachoGauge, RTE_CONST) Rte_C_NV_Data_BsRt_TachoGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_TempGauge, RTE_CONST) Rte_C_NV_Data_BsRt_TempGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_TripComputer, RTE_CONST) Rte_C_NV_Data_BsRt_TripComputer_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsRt_Warning, RTE_CONST) Rte_C_NV_Data_BsRt_Warning_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsShare_EcuPartNumber, RTE_CONST) Rte_C_NV_Data_BsShare_EcuPartNumber_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdFotaFinPrint_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsShare_SwUpdFotaMode, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdFotaMode_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsShare_SwUpdFotaStatus, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdFotaStatus_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsShare_SwUpdFotadecrypt, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdFotadecrypt_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsShare_SwUpdReflash, RTE_CONST) Rte_C_NV_Data_BsShare_SwUpdReflash_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsShare_VehicleConfig, RTE_CONST) Rte_C_NV_Data_BsShare_VehicleConfig_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsShare_VisMeet, RTE_CONST) Rte_C_NV_Data_BsShare_VisMeet_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_RefCys_Certicificate, RTE_CONST) Rte_C_NV_Data_RefCys_Certicificate_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_RefCys_Certicificate1, RTE_CONST) Rte_C_NV_Data_RefCys_Certicificate1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplayCurrentState, RTE_CONST) Rte_C_SDisplayCurrentState_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDmnStatus, RTE_CONST) Rte_DmnMgrSDmnStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEnetRegReq, RTE_CONST) Rte_C_SEnetRegReq_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEnetRegResp, RTE_CONST) Rte_C_SEnetRegResp_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemState, RTE_CONST) Rte_C_SPowerSystemState_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemState, RTE_CONST) Rte_DmnMgrPowerSystemStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemState, RTE_CONST) Rte_UclProxyCddPowerSystemStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemStateReqChange, RTE_CONST) Rte_DmnMgrPowerSystemStateReqChangeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemStateReqChange, RTE_CONST) Rte_UclProxyCddPowerSystemStateReqChangeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# include "Rte_DataHandleType.h"

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Calibration component and SW-C local calibration parameters
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(NV_Data_BsConst_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio_ROM_NVBlockDescriptor_BsConst_Audio; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication_ROM_NVBlockDescriptor_BsConst_Communication; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_EngOffTimer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer_ROM_NVBlockDescriptor_BsConst_EngOffTimer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_FuelGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge_ROM_NVBlockDescriptor_BsConst_FuelGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_OilGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge_ROM_NVBlockDescriptor_BsConst_OilGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power_ROM_NVBlockDescriptor_BsConst_Power; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_PowerGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge_ROM_NVBlockDescriptor_BsConst_PowerGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock_ROM_NVBlockDescriptor_BsConst_RealTimeClock; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_ServiceReminder, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder_ROM_NVBlockDescriptor_BsConst_ServiceReminder; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_SpeedoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge_ROM_NVBlockDescriptor_BsConst_SpeedoGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_TachoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge_ROM_NVBlockDescriptor_BsConst_TachoGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_TempGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge_ROM_NVBlockDescriptor_BsConst_TempGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer_ROM_NVBlockDescriptor_BsConst_TripComputer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning_ROM_NVBlockDescriptor_BsConst_Warning; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsCys_Certicificate, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate_ROM_NVBlockDescriptor_BsCys_Certicificate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsDiag_Dtc, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc_ROM_NVBlockDescriptor_BsDiag_Dtc; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsDiag_ErrorRecord, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord_ROM_NVBlockDescriptor_BsDiag_ErrorRecord; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsFuSa_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio_ROM_NVBlockDescriptor_BsFuSa_Audio; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsFuSa_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication_ROM_NVBlockDescriptor_BsFuSa_Communication; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsFuSa_Config, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config_ROM_NVBlockDescriptor_BsFuSa_Config; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsFuSa_Display, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display_ROM_NVBlockDescriptor_BsFuSa_Display; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsFuSa_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power_ROM_NVBlockDescriptor_BsFuSa_Power; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsFuSa_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning_ROM_NVBlockDescriptor_BsFuSa_Warning; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsFusa_Fota, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota_ROM_NVBlockDescriptor_BsFusa_Fota; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio_ROM_NVBlockDescriptor_BsReten_Audio; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication_ROM_NVBlockDescriptor_BsReten_Communication; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Display, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display_ROM_NVBlockDescriptor_BsReten_Display; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Gauges, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges_ROM_NVBlockDescriptor_BsReten_Gauges; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination_ROM_NVBlockDescriptor_BsReten_Illumination; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Odometer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer_ROM_NVBlockDescriptor_BsReten_Odometer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Personalization, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization_ROM_NVBlockDescriptor_BsReten_Personalization; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power_ROM_NVBlockDescriptor_BsReten_Power; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock_ROM_NVBlockDescriptor_BsReten_RealTimeClock; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Tripcomputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer_ROM_NVBlockDescriptor_BsReten_Tripcomputer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_VisDlt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt_ROM_NVBlockDescriptor_BsReten_VisDlt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsReten_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning_ROM_NVBlockDescriptor_BsReten_Warning; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_CusDlt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt_ROM_NVBlockDescriptor_BsRt_CusDlt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_FuelGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge_ROM_NVBlockDescriptor_BsRt_FuelGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination_ROM_NVBlockDescriptor_BsRt_Illumination; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_Odometer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer_ROM_NVBlockDescriptor_BsRt_Odometer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_OilGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge_ROM_NVBlockDescriptor_BsRt_OilGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_Personalization, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization_ROM_NVBlockDescriptor_BsRt_Personalization; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_PowerGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge_ROM_NVBlockDescriptor_BsRt_PowerGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock_ROM_NVBlockDescriptor_BsRt_RealTimeClock; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_SpeedoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge_ROM_NVBlockDescriptor_BsRt_SpeedoGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_TachoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge_ROM_NVBlockDescriptor_BsRt_TachoGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_TempGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge_ROM_NVBlockDescriptor_BsRt_TempGauge; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer_ROM_NVBlockDescriptor_BsRt_TripComputer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsRt_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning_ROM_NVBlockDescriptor_BsRt_Warning; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsShare_EcuPartNumber, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint_ROM_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsShare_SwUpdFotaMode, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode_ROM_NVBlockDescriptor_BsShare_SwUpdFotaMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsShare_SwUpdFotaStatus, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus_ROM_NVBlockDescriptor_BsShare_SwUpdFotaStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsShare_SwUpdFotadecrypt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt_ROM_NVBlockDescriptor_BsShare_SwUpdFotadecrypt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsShare_SwUpdReflash, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash_ROM_NVBlockDescriptor_BsShare_SwUpdReflash; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsShare_VehicleConfig, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig_ROM_NVBlockDescriptor_BsShare_VehicleConfig; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsShare_VisMeet, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet_ROM_NVBlockDescriptor_BsShare_VisMeet; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_RefCys_Certicificate1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1_ROM_NVBlockDescriptor_RefCys_Certicificate1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_RefCys_Certicificate, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate_ROM_NVBlockDescriptor_RefCys_Certicificate; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif

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

# define RTE_STATE_UNINIT    (0U)
# define RTE_STATE_SCHM_INIT (1U)
# define RTE_STATE_INIT      (2U)

# define RTE_START_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(NV_Data_BsConst_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio_ROM_NVBlockDescriptor_BsConst_Audio; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication_ROM_NVBlockDescriptor_BsConst_Communication; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_EngOffTimer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer_ROM_NVBlockDescriptor_BsConst_EngOffTimer; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_FuelGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge_ROM_NVBlockDescriptor_BsConst_FuelGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_ROM_NVBlockDescriptor_BsConst_Illumination; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_OilGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge_ROM_NVBlockDescriptor_BsConst_OilGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power_ROM_NVBlockDescriptor_BsConst_Power; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_PowerGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge_ROM_NVBlockDescriptor_BsConst_PowerGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock_ROM_NVBlockDescriptor_BsConst_RealTimeClock; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_ServiceReminder, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder_ROM_NVBlockDescriptor_BsConst_ServiceReminder; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_SpeedoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge_ROM_NVBlockDescriptor_BsConst_SpeedoGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_TachoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge_ROM_NVBlockDescriptor_BsConst_TachoGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_TempGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge_ROM_NVBlockDescriptor_BsConst_TempGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer_ROM_NVBlockDescriptor_BsConst_TripComputer; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning_ROM_NVBlockDescriptor_BsConst_Warning; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsCys_Certicificate, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate_ROM_NVBlockDescriptor_BsCys_Certicificate; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsDiag_Dtc, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc_ROM_NVBlockDescriptor_BsDiag_Dtc; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsDiag_ErrorRecord, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord_ROM_NVBlockDescriptor_BsDiag_ErrorRecord; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsFuSa_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio_ROM_NVBlockDescriptor_BsFuSa_Audio; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsFuSa_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication_ROM_NVBlockDescriptor_BsFuSa_Communication; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsFuSa_Config, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config_ROM_NVBlockDescriptor_BsFuSa_Config; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsFuSa_Display, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display_ROM_NVBlockDescriptor_BsFuSa_Display; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsFuSa_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power_ROM_NVBlockDescriptor_BsFuSa_Power; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsFuSa_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning_ROM_NVBlockDescriptor_BsFuSa_Warning; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsFusa_Fota, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota_ROM_NVBlockDescriptor_BsFusa_Fota; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Audio, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio_ROM_NVBlockDescriptor_BsReten_Audio; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Communication, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication_ROM_NVBlockDescriptor_BsReten_Communication; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Display, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display_ROM_NVBlockDescriptor_BsReten_Display; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Gauges, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges_ROM_NVBlockDescriptor_BsReten_Gauges; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination_ROM_NVBlockDescriptor_BsReten_Illumination; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Odometer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer_ROM_NVBlockDescriptor_BsReten_Odometer; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Personalization, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization_ROM_NVBlockDescriptor_BsReten_Personalization; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Power, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power_ROM_NVBlockDescriptor_BsReten_Power; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock_ROM_NVBlockDescriptor_BsReten_RealTimeClock; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Tripcomputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer_ROM_NVBlockDescriptor_BsReten_Tripcomputer; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_VisDlt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt_ROM_NVBlockDescriptor_BsReten_VisDlt; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsReten_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning_ROM_NVBlockDescriptor_BsReten_Warning; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_CusDlt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt_ROM_NVBlockDescriptor_BsRt_CusDlt; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_FuelGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge_ROM_NVBlockDescriptor_BsRt_FuelGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_Illumination, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination_ROM_NVBlockDescriptor_BsRt_Illumination; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_Odometer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer_ROM_NVBlockDescriptor_BsRt_Odometer; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_OilGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge_ROM_NVBlockDescriptor_BsRt_OilGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_Personalization, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization_ROM_NVBlockDescriptor_BsRt_Personalization; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_PowerGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge_ROM_NVBlockDescriptor_BsRt_PowerGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_RealTimeClock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock_ROM_NVBlockDescriptor_BsRt_RealTimeClock; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_SpeedoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge_ROM_NVBlockDescriptor_BsRt_SpeedoGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_TachoGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge_ROM_NVBlockDescriptor_BsRt_TachoGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_TempGauge, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge_ROM_NVBlockDescriptor_BsRt_TempGauge; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer_ROM_NVBlockDescriptor_BsRt_TripComputer; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsRt_Warning, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning_ROM_NVBlockDescriptor_BsRt_Warning; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsShare_EcuPartNumber, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber_ROM_NVBlockDescriptor_BsShare_EcuPartNumber; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint_ROM_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsShare_SwUpdFotaMode, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode_ROM_NVBlockDescriptor_BsShare_SwUpdFotaMode; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsShare_SwUpdFotaStatus, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus_ROM_NVBlockDescriptor_BsShare_SwUpdFotaStatus; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsShare_SwUpdFotadecrypt, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt_ROM_NVBlockDescriptor_BsShare_SwUpdFotadecrypt; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsShare_SwUpdReflash, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash_ROM_NVBlockDescriptor_BsShare_SwUpdReflash; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsShare_VehicleConfig, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig_ROM_NVBlockDescriptor_BsShare_VehicleConfig; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsShare_VisMeet, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet_ROM_NVBlockDescriptor_BsShare_VisMeet; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_RefCys_Certicificate1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1_ROM_NVBlockDescriptor_RefCys_Certicificate1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_RefCys_Certicificate, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate_ROM_NVBlockDescriptor_RefCys_Certicificate; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_INIT) Rte_CSleepManager_ppSR_SleepStatus_SleepManager_SleepStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SPowerSystemStateReqChange, RTE_VAR_INIT) Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDmnStatus, RTE_VAR_INIT) Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_EngOffTimer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_FuelGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_OilGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_PowerGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Power, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_ServiceReminder, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_SpeedoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_TachoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_TempGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_TripComputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsCys_Certicificate, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsDiag_Dtc, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsDiag_ErrorRecord, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsFuSa_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsFuSa_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsFuSa_Config, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsFuSa_Display, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsFuSa_Power, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsFuSa_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsFusa_Fota, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Display, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Gauges, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Odometer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Personalization, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Power, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Tripcomputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_VisDlt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsReten_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_CusDlt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_FuelGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_Odometer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_OilGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_Personalization, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_PowerGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_RealTimeClock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_SpeedoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_TachoGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_TempGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_TripComputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsRt_Warning, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsShare_EcuPartNumber, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsShare_SwUpdFotaFinPrint, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsShare_SwUpdFotaMode, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsShare_SwUpdFotaStatus, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsShare_SwUpdFotadecrypt, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsShare_SwUpdReflash, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsShare_VehicleConfig, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsShare_VisMeet, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_RefCys_Certicificate1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_RefCys_Certicificate, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SPowerSystemState, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* queue ROM informations type */
typedef struct
{
  P2VAR(void, TYPEDEF, RTE_VAR_NOINIT) Rte_BasePtr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  uint16 Rte_BytesPerElement;
  uint8 Rte_MaxElements;
} Rte_QRomInfoType;

/* queue RAM informations type */
typedef struct
{
  uint8 Rte_ReadCtr;
  uint8 Rte_WriteCtr;
  uint8 Rte_ElementCtr;
} Rte_QRamInfoType;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_QRamInfoType, RTE_VAR_NOINIT) Rte_QRamInfo[8]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Rte_QRomInfoType, RTE_CONST) Rte_QRomInfo[8];

#  define RTE_STOP_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_b0 : 1;
  Rte_BitType Rte_b1 : 1;
  Rte_BitType Rte_b2 : 1;
  Rte_BitType Rte_b3 : 1;
  Rte_BitType Rte_b4 : 1;
  Rte_BitType Rte_b5 : 1;
  Rte_BitType Rte_b6 : 1;
  Rte_BitType Rte_b7 : 1;
} Rte_SystemApplication_OsCore0_QOverflowType;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_SystemApplication_OsCore0_QOverflowType, RTE_VAR_NOINIT) Rte_SystemApplication_OsCore0_QOverflow; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_OilGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Power : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_PowerGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_RealTimeClock : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_ServiceReminder : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_SpeedoGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TachoGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TempGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_TripComputer : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Warning : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsCys_Certicificate : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_Dtc : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsDiag_ErrorRecord : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Audio : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Communication : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Config : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Display : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Power : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFuSa_Warning : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsFusa_Fota : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Audio : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Communication : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Display : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Gauges : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Illumination : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Odometer : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Personalization : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Power : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_RealTimeClock : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Tripcomputer : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_VisDlt : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsReten_Warning : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_CusDlt : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_FuelGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Illumination : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Odometer : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_OilGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Personalization : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_PowerGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_RealTimeClock : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_SpeedoGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TachoGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TempGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_TripComputer : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsRt_Warning : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_EcuPartNumber : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaFinPrint : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaMode : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotaStatus : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdFotadecrypt : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_SwUpdReflash : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VehicleConfig : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsShare_VisMeet : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_RefCys_Certicificate1 : 1;
} Rte_DirtyFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_DirtyFlagsType, RTE_VAR_ZERO_INIT) Rte_DirtyFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



# endif /* defined(RTE_CORE) */

#endif /* _RTE_TYPE_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

*/
