/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2006-2015 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_Type.h
 *        Config:  Turing.dpa
 *   ECU-Project:  TuringECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.8.0
 *                 RTE Core Version 1.8.0
 *       License:  Unlimited license CBD1400814 for Visteon Corporation
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

# define Rte_TypeDef_ArrayHandle
typedef uint16 ArrayHandle;

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_Boolean_01
typedef boolean Boolean_01;

# define Rte_TypeDef_E2E_RxFilteredSpeedSft
typedef uint16 E2E_RxFilteredSpeedSft;

# define Rte_TypeDef_E2E_Rx_CRC
typedef uint8 E2E_Rx_CRC;

# define Rte_TypeDef_E2E_Rx_SeqNumber
typedef uint8 E2E_Rx_SeqNumber;

# define Rte_TypeDef_E2E_TxFilteredSpeedSft
typedef uint16 E2E_TxFilteredSpeedSft;

# define Rte_TypeDef_E2E_Tx_CRC
typedef uint8 E2E_Tx_CRC;

# define Rte_TypeDef_E2E_Tx_SeqNumber
typedef uint8 E2E_Tx_SeqNumber;

# define Rte_TypeDef_ECmpCmd
typedef uint8 ECmpCmd;

# define Rte_TypeDef_FUEL_LEVEL_CAN
typedef sint16 FUEL_LEVEL_CAN;

# define Rte_TypeDef_Rte_DT_Gauge_Correction_Table_X_0
typedef uint16 Rte_DT_Gauge_Correction_Table_X_0;

# define Rte_TypeDef_Rte_DT_Gauge_Correction_Table_Y_0
typedef uint16 Rte_DT_Gauge_Correction_Table_Y_0;

# define Rte_TypeDef_Rte_DT_Gauge_Mapping_Table_X_0
typedef uint16 Rte_DT_Gauge_Mapping_Table_X_0;

# define Rte_TypeDef_Rte_DT_Gauge_Mapping_Table_Y_0
typedef uint16 Rte_DT_Gauge_Mapping_Table_Y_0;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_0
typedef uint8 Rte_DT_NV_Data_ClusterSettings_0;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_1
typedef boolean Rte_DT_NV_Data_ClusterSettings_1;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_10
typedef uint8 Rte_DT_NV_Data_ClusterSettings_10;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_11
typedef uint16 Rte_DT_NV_Data_ClusterSettings_11;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_12
typedef uint16 Rte_DT_NV_Data_ClusterSettings_12;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_13
typedef uint8 Rte_DT_NV_Data_ClusterSettings_13;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_14
typedef uint8 Rte_DT_NV_Data_ClusterSettings_14;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_15
typedef uint8 Rte_DT_NV_Data_ClusterSettings_15;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_16
typedef uint8 Rte_DT_NV_Data_ClusterSettings_16;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_2
typedef uint16 Rte_DT_NV_Data_ClusterSettings_2;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_3
typedef uint16 Rte_DT_NV_Data_ClusterSettings_3;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_4
typedef uint8 Rte_DT_NV_Data_ClusterSettings_4;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_5
typedef uint16 Rte_DT_NV_Data_ClusterSettings_5;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_6
typedef uint16 Rte_DT_NV_Data_ClusterSettings_6;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_7
typedef uint8 Rte_DT_NV_Data_ClusterSettings_7;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_8
typedef uint16 Rte_DT_NV_Data_ClusterSettings_8;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_9
typedef uint16 Rte_DT_NV_Data_ClusterSettings_9;

# define Rte_TypeDef_Rte_DT_NvM_ECU24BytesNumberType_0
typedef uint8 Rte_DT_NvM_ECU24BytesNumberType_0;

# define Rte_TypeDef_Rte_DT_NvM_ECUSerialNumberType_0
typedef uint8 Rte_DT_NvM_ECUSerialNumberType_0;

# define Rte_TypeDef_Rte_DT_NvM_ProductInfo_0
typedef uint8 Rte_DT_NvM_ProductInfo_0;

# define Rte_TypeDef_Rte_DT_SOdoDataSet_0
typedef uint16 Rte_DT_SOdoDataSet_0;

# define Rte_TypeDef_Rte_DT_SOdoDataSet_1
typedef uint8 Rte_DT_SOdoDataSet_1;

# define Rte_TypeDef_Rte_DT_SOdoDataSet_2
typedef uint8 Rte_DT_SOdoDataSet_2;

# define Rte_TypeDef_TIOAppData
typedef sint32 TIOAppData;

# define Rte_TypeDef_TPulseChannelId
typedef uint8 TPulseChannelId;

# define Rte_TypeDef_TPulseClientId
typedef uint8 TPulseClientId;

# define Rte_TypeDef_TWrnId
typedef uint16 TWrnId;

# define Rte_TypeDef_TWrnListMask
typedef uint8 TWrnListMask;

# define Rte_TypeDef_UFIX16_SP001
typedef uint16 UFIX16_SP001;

# define Rte_TypeDef_UFIX16_SP01
typedef uint16 UFIX16_SP01;

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;

# define Rte_TypeDef_UInt16_01
typedef uint16 UInt16_01;

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;

# define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

# define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

# define Rte_TypeDef_EBtnState
typedef uint8 EBtnState;

# define Rte_TypeDef_EChimeStatus
typedef uint8 EChimeStatus;

# define Rte_TypeDef_EDcmExtAction
typedef uint8 EDcmExtAction;

# define Rte_TypeDef_EHmiSubId
typedef uint8 EHmiSubId;

# define Rte_TypeDef_EIOCurrentInId
typedef sint32 EIOCurrentInId;

# define Rte_TypeDef_EIODutyInId
typedef sint32 EIODutyInId;

# define Rte_TypeDef_EIODutyOutId
typedef uint8 EIODutyOutId;

# define Rte_TypeDef_EIOGroupInId
typedef sint32 EIOGroupInId;

# define Rte_TypeDef_EIOGroupOutId
typedef sint32 EIOGroupOutId;

# define Rte_TypeDef_EIOMapStat
typedef uint8 EIOMapStat;

# define Rte_TypeDef_EIOMapStatInId
typedef sint32 EIOMapStatInId;

# define Rte_TypeDef_EIOPeriodInId
typedef sint32 EIOPeriodInId;

# define Rte_TypeDef_EIOPeriodOutId
typedef sint32 EIOPeriodOutId;

# define Rte_TypeDef_EIOPinInId
typedef uint8 EIOPinInId;

# define Rte_TypeDef_EIOPinOutId
typedef uint8 EIOPinOutId;

# define Rte_TypeDef_EIOResistanceInId
typedef sint32 EIOResistanceInId;

# define Rte_TypeDef_EIOVoltageInId
typedef sint32 EIOVoltageInId;

# define Rte_TypeDef_EIOVoltageOutId
typedef sint32 EIOVoltageOutId;

# define Rte_TypeDef_EKeyPos
typedef uint8 EKeyPos;

# define Rte_TypeDef_EPulsePhase
typedef uint8 EPulsePhase;

# define Rte_TypeDef_EStpCalibKind
typedef uint8 EStpCalibKind;

# define Rte_TypeDef_EStpStat
typedef uint8 EStpStat;

# define Rte_TypeDef_ETtMdlMask
typedef uint8 ETtMdlMask;

# define Rte_TypeDef_EWrnReason
typedef uint8 EWrnReason;

# define Rte_TypeDef_TYP_CAN_SIGNAL_STATUS
typedef sint32 TYP_CAN_SIGNAL_STATUS;

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[4];

# define Rte_TypeDef_Dlt_VerboseBufferType
typedef uint8 Dlt_VerboseBufferType[128];

# define Rte_TypeDef_Gauge_Correction_Table_X
typedef Rte_DT_Gauge_Correction_Table_X_0 Gauge_Correction_Table_X[2];

# define Rte_TypeDef_Gauge_Correction_Table_Y
typedef Rte_DT_Gauge_Correction_Table_Y_0 Gauge_Correction_Table_Y[2];

# define Rte_TypeDef_Gauge_Mapping_Table_X
typedef Rte_DT_Gauge_Mapping_Table_X_0 Gauge_Mapping_Table_X[2];

# define Rte_TypeDef_Gauge_Mapping_Table_Y
typedef Rte_DT_Gauge_Mapping_Table_Y_0 Gauge_Mapping_Table_Y[2];

# define Rte_TypeDef_NvM_ECU24BytesNumberType
typedef Rte_DT_NvM_ECU24BytesNumberType_0 NvM_ECU24BytesNumberType[24];

# define Rte_TypeDef_NvM_ECUSerialNumberType
typedef Rte_DT_NvM_ECUSerialNumberType_0 NvM_ECUSerialNumberType[16];

# define Rte_TypeDef_NvM_ProductInfo
typedef Rte_DT_NvM_ProductInfo_0 NvM_ProductInfo[126];

# define Rte_TypeDef_NV_Data_ClusterSettings
typedef struct
{
  Rte_DT_NV_Data_ClusterSettings_0 Language;
  Rte_DT_NV_Data_ClusterSettings_1 Immobilizer;
  Rte_DT_NV_Data_ClusterSettings_2 Speedo_Gauge_Sleep_Offset;
  Rte_DT_NV_Data_ClusterSettings_3 Speedo_Gauge_Zero_Software;
  Rte_DT_NV_Data_ClusterSettings_4 Speedo_Gauge_Magnetic_Offset;
  Rte_DT_NV_Data_ClusterSettings_5 RPM_Gauge_Sleep_Offset;
  Rte_DT_NV_Data_ClusterSettings_6 RPM_Gauge_Zero_Software;
  Rte_DT_NV_Data_ClusterSettings_7 RPM_Gauge_Magnetic_Offset;
  Rte_DT_NV_Data_ClusterSettings_8 Ect_Gauge_Sleep_Offset;
  Rte_DT_NV_Data_ClusterSettings_9 Ect_Gauge_Zero_Software;
  Rte_DT_NV_Data_ClusterSettings_10 Ect_Gauge_Magnetic_Offset;
  Rte_DT_NV_Data_ClusterSettings_11 Fuel_Gauge_Sleep_Offset;
  Rte_DT_NV_Data_ClusterSettings_12 Fuel_Gauge_Zero_Software;
  Rte_DT_NV_Data_ClusterSettings_13 Fuel_Gauge_Magnetic_Offset;
  Rte_DT_NV_Data_ClusterSettings_14 ETM_Entry;
  Rte_DT_NV_Data_ClusterSettings_15 ETM_Enter;
  Rte_DT_NV_Data_ClusterSettings_16 ETM_Exit;
} NV_Data_ClusterSettings;

# define Rte_TypeDef_SG_RxFilteredSpeed
typedef struct
{
  E2E_RxFilteredSpeedSft E2E_RxFilteredSpeedSft;
  E2E_Rx_CRC E2E_Rx_CRC;
  E2E_Rx_SeqNumber E2E_Rx_SeqNumber;
} SG_RxFilteredSpeed;

# define Rte_TypeDef_SG_TxFilteredSpeed
typedef struct
{
  E2E_Tx_CRC E2E_Tx_CRC;
  E2E_Tx_SeqNumber E2E_Tx_SeqNumber;
  E2E_TxFilteredSpeedSft E2E_TxFilteredSpeedSft;
} SG_TxFilteredSpeed;

# define Rte_TypeDef_SOdoDataSet
typedef struct
{
  Rte_DT_SOdoDataSet_0 count;
  Rte_DT_SOdoDataSet_1 extra_count;
  Rte_DT_SOdoDataSet_2 increments;
} SOdoDataSet;

# define Rte_TypeDef_SPulseNotification
typedef struct
{
  TPulseChannelId Channel;
  EPulsePhase Phase;
} SPulseNotification;

# define Rte_TypeDef_STRUCT_ECT_CONFIGURATION
typedef struct
{
  UInt8 ECT_TP0;
  UInt8 ECT_TP1;
  UInt8 ECT_TP2;
  UInt8 ECT_TP3;
  UInt8 ECT_Mini;
  UInt8 ECT_Plateau;
  UInt8 ECT_Maxi;
  UInt8 Padding;
} STRUCT_ECT_CONFIGURATION;

# define Rte_TypeDef_STRUCT_FUEL_LEVEL_CAN
typedef struct
{
  UFIX16_SP001 Data;
  TYP_CAN_SIGNAL_STATUS Status;
} STRUCT_FUEL_LEVEL_CAN;

# define Rte_TypeDef_sTrcOut
typedef struct
{
  uint32 TripTime;
  uint32 TripDistance;
  uint32 TripDTE;
  uint32 TripAFE;
  uint32 DTE;
  uint32 AFE;
} sTrcOut;

# define Rte_TypeDef_sTrcOut_01
typedef struct
{
  uint32 TripTime;
  uint32 TripDistance;
  uint32 TripDTE;
  uint32 TripAFE;
  uint32 DTE;
  uint32 AFE;
} sTrcOut_01;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint8 ComM_UserHandleType;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_SecLevelType
typedef uint8 Dcm_SecLevelType;

# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;

# define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;

# define Rte_TypeDef_Dem_DTCGroupType
typedef uint32 Dem_DTCGroupType;

# define Rte_TypeDef_Dem_DTCKindType
typedef uint8 Dem_DTCKindType;

# define Rte_TypeDef_Dem_DTCOriginType
typedef uint8 Dem_DTCOriginType;

# define Rte_TypeDef_Dem_DTCStatusMaskType
typedef uint8 Dem_DTCStatusMaskType;

# define Rte_TypeDef_Dem_DebounceResetStatusType
typedef uint8 Dem_DebounceResetStatusType;

# define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;

# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;

# define Rte_TypeDef_Dem_EventStatusExtendedType
typedef uint8 Dem_EventStatusExtendedType;

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

# define Rte_TypeDef_Dem_OperationCycleIdType
typedef uint8 Dem_OperationCycleIdType;

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;

# define Rte_TypeDef_Dem_RatioIdType
typedef uint16 Dem_RatioIdType;

# define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

# define Rte_TypeDef_Dlt_SessionIDType
typedef uint32 Dlt_SessionIDType;

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

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_NV_Data_Interpolations
typedef struct
{
  Gauge_Mapping_Table_X Speedo_Gauge_Mapping_Table_X;
  Gauge_Mapping_Table_Y Speedo_Gauge_Mapping_Table_Y;
  Gauge_Correction_Table_X Speedo_Gauge_Correction_Table_X;
  Gauge_Correction_Table_Y Speedo_Gauge_Correction_Table_Y;
  Gauge_Mapping_Table_X RPM_Gauge_Mapping_Table_X;
  Gauge_Mapping_Table_Y RPM_Gauge_Mapping_Table_Y;
  Gauge_Correction_Table_X RPM_Gauge_Correction_Table_X;
  Gauge_Correction_Table_Y RPM_Gauge_Correction_Table_Y;
  Gauge_Mapping_Table_X Ect_Gauge_Mapping_Table_X;
  Gauge_Mapping_Table_Y Ect_Gauge_Mapping_Table_Y;
  Gauge_Correction_Table_X Ect_Gauge_Correction_Table_X;
  Gauge_Correction_Table_Y Ect_Gauge_Correction_Table_Y;
  Gauge_Mapping_Table_X Fuel_Gauge_Mapping_Table_X;
  Gauge_Mapping_Table_Y Fuel_Gauge_Mapping_Table_Y;
  Gauge_Correction_Table_X Fuel_Gauge_Correction_Table_X;
  Gauge_Mapping_Table_Y Fuel_Gauge_Correction_Table_Y;
} NV_Data_Interpolations;

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

# define Rte_TypeDef_NvM_EOLDataType
typedef struct
{
  NvM_ECU24BytesNumberType ECUDeliveryAssemblyNumber;
  NvM_ECU24BytesNumberType VehicleManufacturerECUSoftwareNumber;
  NvM_ECUSerialNumberType ECUSerialNumber;
  NvM_ProductInfo ProductInfo;
} NvM_EOLDataType;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# define Rte_TypeDef_OdoDataSetType
typedef SOdoDataSet OdoDataSetType[2];

# define Rte_TypeDef_Rte_DT_Dlt_MessageLogInfoType_0
typedef uint8 Rte_DT_Dlt_MessageLogInfoType_0;

# define Rte_TypeDef_Dlt_MessageLogInfoType
typedef struct
{
  Rte_DT_Dlt_MessageLogInfoType_0 log_level;
  uint8 options;
  uint32 context_id;
  uint32 app_id;
} Dlt_MessageLogInfoType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_BrkLamp_B_Rq
typedef boolean BrkLamp_B_Rq;

#  define Rte_TypeDef_DownTranOfEngCoolantTempCAN
typedef boolean DownTranOfEngCoolantTempCAN;

#  define Rte_TypeDef_DownTranOfEngCoolantTempCAN_1
typedef boolean DownTranOfEngCoolantTempCAN_1;

#  define Rte_TypeDef_DrStatDrv_B_Actl
typedef boolean DrStatDrv_B_Actl;

#  define Rte_TypeDef_DrStatPsngr_B_Actl
typedef boolean DrStatPsngr_B_Actl;

#  define Rte_TypeDef_EngineCoolantTempCAN
typedef sint8 EngineCoolantTempCAN;

#  define Rte_TypeDef_InterpTblHandle
typedef uint16 InterpTblHandle;

#  define Rte_TypeDef_IoHwAb_DO_TT_Type
typedef uint16 IoHwAb_DO_TT_Type;

#  define Rte_TypeDef_PtrUint16
typedef uint16 * PtrUint16;

#  define Rte_TypeDef_Tire_Press_System_Stat
typedef uint8 Tire_Press_System_Stat;

#  define Rte_TypeDef_WarningWaterTempCAN
typedef sint8 WarningWaterTempCAN;

#  define Rte_TypeDef_WarningWaterTempCAN_1
typedef sint8 WarningWaterTempCAN_1;

#  define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;

#  define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;

#  define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint8 WdgM_SupervisedEntityIdType;

#  define Rte_TypeDef_dtLeftTurnOn
typedef boolean dtLeftTurnOn;

#  define Rte_TypeDef_dtRightTurnOn
typedef boolean dtRightTurnOn;

#  define Rte_TypeDef_dtSpdRef
typedef uint16 dtSpdRef;

#  define Rte_TypeDef_dtSpeedFTx
typedef uint16 dtSpeedFTx;

#  define Rte_TypeDef_dtTachoFTx
typedef uint16 dtTachoFTx;

#  define Rte_TypeDef_dtTachoRef
typedef uint16 dtTachoRef;

#  define Rte_TypeDef_EWrnId
typedef uint8 EWrnId;

#  define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;

#  define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;

#  define Rte_TypeDef_eSystemEventType
typedef uint8 eSystemEventType;

#  define Rte_TypeDef_Rte_DT_Dlt_VerboseMsgType_2
typedef uint8 Rte_DT_Dlt_VerboseMsgType_2[128];

#  define Rte_TypeDef_Rte_DT_Dlt_NonVerboseMsgType_0
typedef struct
{
  uint8 HeaderType;
  uint8 MessageCounter;
  uint16 Length;
} Rte_DT_Dlt_NonVerboseMsgType_0;

#  define Rte_TypeDef_Rte_DT_Dlt_VerboseMsgType_0
typedef struct
{
  uint8 HeaderType;
  uint8 MessageCounter;
  uint16 Length;
} Rte_DT_Dlt_VerboseMsgType_0;

#  define Rte_TypeDef_SStpIfCfg
typedef struct
{
  boolean bRotationDirection;
  uint8 MagneticOffset;
} SStpIfCfg;

#  define Rte_TypeDef_STRUCT_DOWN_TRANSITION_OF_ENG_COOLANT_TEMP
typedef struct
{
  Boolean Data;
  TYP_CAN_SIGNAL_STATUS Status;
} STRUCT_DOWN_TRANSITION_OF_ENG_COOLANT_TEMP;

#  define Rte_TypeDef_STRUCT_ENGINE_COOLANT_TEMP
typedef struct
{
  UInt8 Data;
  TYP_CAN_SIGNAL_STATUS Status;
} STRUCT_ENGINE_COOLANT_TEMP;

#  define Rte_TypeDef_STRUCT_WARNING_WATER_TEMP
typedef struct
{
  UInt8 Data;
  TYP_CAN_SIGNAL_STATUS Status;
} STRUCT_WARNING_WATER_TEMP;

#  define Rte_TypeDef_Dlt_ApplicationIDType
typedef uint32 Dlt_ApplicationIDType;

#  define Rte_TypeDef_Dlt_ContextIDType
typedef uint32 Dlt_ContextIDType;

#  define Rte_TypeDef_Dlt_MessageArgumentCount
typedef uint8 Dlt_MessageArgumentCount;

#  define Rte_TypeDef_Dlt_MessageLogLevelType
typedef uint8 Dlt_MessageLogLevelType;

#  define Rte_TypeDef_Dlt_MessageOptionsType
typedef uint8 Dlt_MessageOptionsType;

#  define Rte_TypeDef_Dlt_MessageTraceType
typedef uint8 Dlt_MessageTraceType;

#  define Rte_TypeDef_Dlt_NonVerboseMsgType
typedef struct
{
  Rte_DT_Dlt_NonVerboseMsgType_0 StdHeader;
  uint32 MessageId;
} Dlt_NonVerboseMsgType;

#  define Rte_TypeDef_Dlt_VerboseMsgType
typedef struct
{
  Rte_DT_Dlt_VerboseMsgType_0 StdHeader;
  uint32 MessageId;
  Rte_DT_Dlt_VerboseMsgType_2 Payload;
} Dlt_VerboseMsgType;

#  define Rte_TypeDef_Rte_DT_Dlt_MessageTraceInfoType_0
typedef uint8 Rte_DT_Dlt_MessageTraceInfoType_0;

#  define Rte_TypeDef_TBtnId
typedef uint8 TBtnId;

#  define Rte_TypeDef_Dlt_MessageTraceInfoType
typedef struct
{
  Rte_DT_Dlt_MessageTraceInfoType_0 trace_info;
  uint8 options;
  uint32 context_id;
  uint32 app_id;
} Dlt_MessageTraceInfoType;

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Gauge_Correction_Table_X, RTE_CONST) Rte_C_Gauge_Correction_Table_X_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Gauge_Correction_Table_Y, RTE_CONST) Rte_C_Gauge_Correction_Table_Y_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Gauge_Mapping_Table_X, RTE_CONST) Rte_C_Gauge_Mapping_Table_X_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Gauge_Mapping_Table_Y, RTE_CONST) Rte_C_Gauge_Mapping_Table_Y_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NvM_ECU24BytesNumberType, RTE_CONST) Rte_C_NvM_ECU24BytesNumberType_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NvM_ECUSerialNumberType, RTE_CONST) Rte_C_NvM_ECUSerialNumberType_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NvM_ECUSerialNumberType, RTE_CONST) Rte_C_NvM_ECUSerialNumberType_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NvM_ProductInfo, RTE_CONST) Rte_C_NvM_ProductInfo_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(OdoDataSetType, RTE_CONST) Rte_ZeroElem_OdoDataSet; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_ClusterSettings, RTE_CONST) Rte_NV_ZeroDataClusterSettings; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Interpolations, RTE_CONST) Rte_NV_Interpolations_Const; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NvM_EOLDataType, RTE_CONST) Rte_NVM_EOLDataConstant; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SG_RxFilteredSpeed, RTE_CONST) Rte_C_SG_RxFilteredSpeed_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SG_TxFilteredSpeed, RTE_CONST) Rte_C_SG_TxFilteredSpeed_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST) Rte_C_STRUCT_ECT_CONFIGURATION_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST) Rte_DefaultInitValue_STRUCT_ECT_CONFIGURATION; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST) Rte_NV_ZeroEctConfiguration; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STRUCT_FUEL_LEVEL_CAN, RTE_CONST) Rte_DefaultInitValu_7bfb7bfae69e880b; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(sTrcOut, RTE_CONST) Rte_C_sTrcOut_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# include "Rte_DataHandleType.h"

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Calibration component and SW-C local calibration parameters
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(OdoDataSetType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_ROM_NVBlockDescriptor_Odometer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_ClusterSettings, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings_ROM_NVBlockDescriptor_ClusterSettings; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NvM_EOLDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_EOLData_ROM_NVBlockDescriptor_EOLData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_EctConfiguration_ROM_NVBlockDescriptor_EctConfiguration; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Interpolations, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Interpolations_ROM_NVBlockDescriptor_Interpolations; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif


/**********************************************************************************************************************
 * Buffer definitions for implicit access to S/R port elements
 *********************************************************************************************************************/

# define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_DES_UInt16 Rte_rpSR_rCIn_TIEngMdl_ComIn_RxRpm;
} Rte_tsRB_EngMdl_CEngMdl_Impl_MainFunction;

/* PRQA S 0750, 3629 L1 */ /* MD_MSR_18.4, MD_Rte_3629 */
typedef union
{
  Rte_tsRB_EngMdl_CEngMdl_Impl_MainFunction Rte_EngMdl_CEngMdl_Impl_MainFunction; /* PRQA S 3629 */ /* MD_Rte_3629 */
} Rte_tuRB_OsTask_20msHP;
/* PRQA L:L1 */

typedef struct
{
  Rte_tuRB_OsTask_20msHP Rte_RB; /* PRQA S 3629 */ /* MD_Rte_3629 */
} Rte_tsOsTask_20msHP;

# define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

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

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

# define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef RTE_CORE

/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(OdoDataSetType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_ROM_NVBlockDescriptor_Odometer; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_ClusterSettings, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings_ROM_NVBlockDescriptor_ClusterSettings; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NvM_EOLDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_EOLData_ROM_NVBlockDescriptor_EOLData; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_EctConfiguration_ROM_NVBlockDescriptor_EctConfiguration; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Interpolations, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Interpolations_ROM_NVBlockDescriptor_Interpolations; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NvM_EOLDataType, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_EOLData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_ClusterSettings, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_DimMdl_tiSR_TIDimMdl_FltLevel_FltLevel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STRUCT_ECT_CONFIGURATION, RTE_VAR_INIT) Rte_EctMdlWrp_EctConfiguration_EctConfiguration; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EctMdlWrp_TemperatureUnit_CF_TemperatureUnit_CF; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UFIX16_SP001, RTE_VAR_INIT) Rte_FuelMdl_FuelLevelCanS_de_FuelLevelOut; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STRUCT_FUEL_LEVEL_CAN, RTE_VAR_INIT) Rte_FuelMdlWrp_if_FuelLevelCanR_de_FuelLevelIn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UFIX16_SP01, RTE_VAR_INIT) Rte_FuelMdlWrp_if_FuelLevelCanR_de_Tau; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EKeyPos, RTE_VAR_INIT) Rte_ModMdl_ppSR_pKeyPos_TIModMdl_KeyPos_KeyPos; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STRUCT_ECT_CONFIGURATION, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_EctConfiguration; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Interpolations, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Interpolations; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OdoDataSetType, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(uint32, RTE_VAR_INIT) Rte_OdoMdl_tiSR_OdoOutMiles_Miles; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_IsOverSpeed; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EKeyPos, RTE_VAR_INIT) Rte_TripMdl_tiSR_TIModMdl_KeyPos_KeyPos; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(sTrcOut, RTE_VAR_INIT) Rte_TripMdl_tiSR_TrcOut_deTrcOut; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtMdlMask, RTE_VAR_INIT) Rte_TtMdl_ppSR_pTt_TITtMdl_TtMask_TtMask; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_RxTimeout_DimGeneral_0e65ef90 : 1;
  Rte_BitType Rte_RxTimeout_DownTranOfEngCoolantTempCAN_46dad878 : 1;
  Rte_BitType Rte_RxTimeout_EngineCoolantTempCAN_46dad878 : 1;
  Rte_BitType Rte_RxTimeout_SpeedRef_a9ab8ab7 : 1;
  Rte_BitType Rte_RxTimeout_TachoRef_3db35f78 : 1;
  Rte_BitType Rte_RxTimeout_WarningWaterTempCAN_46dad878 : 1;
} Rte_OsApplication_RxTimeoutFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_RxTimeoutFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_RxTimeoutFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


typedef struct
{
  Rte_BitType Rte_RxNeverReceived_SpeedRef_a9ab8ab7 : 1;
} Rte_OsApplication_RxNeverReceivedFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_RxNeverReceivedFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_RxNeverReceivedFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


typedef struct
{
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_EOLData : 1;
} Rte_DirtyFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_DirtyFlagsType, RTE_VAR_ZERO_INIT) Rte_DirtyFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

/* Queue element type definitions for internal C/S connections */

typedef struct
{
  uint8 arg; /* PRQA S 0850 */ /* MD_MSR_19.8 */
  boolean Rte_ServerCompleted;
  TaskType Rte_TaskID;
  Std_ReturnType Rte_Result;
} Rte_CS_ServerQueueType_EctMdlWrp_EctMdl_SystemIf_EctMdl_OnCommand;

typedef struct
{
  uint8 Rte_Free;
  uint8 Rte_Active;
} Rte_CS_ServerQueueInfoType_EctMdlWrp_EctMdl_SystemIf_EctMdl_OnCommand;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_CS_ServerQueueType_EctMdlWrp_EctMdl_SystemIf_EctMdl_OnCommand, RTE_VAR_NOINIT) Rte_CS_ServerQueue_EctMdlWrp_EctMdl_SystemIf_EctMdl_OnCommand; /* PRQA S 0850, 3229 */ /* MD_MSR_19.8, MD_Rte_Qac */
extern VAR(Rte_CS_ServerQueueInfoType_EctMdlWrp_EctMdl_SystemIf_EctMdl_OnCommand, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_EctMdlWrp_EctMdl_SystemIf_EctMdl_OnCommand; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



# endif /* defined(RTE_CORE) */

/**********************************************************************************************************************
 * extern declaration of RTE Update Flags for optimized macro implementation
 *********************************************************************************************************************/
typedef struct
{
  Rte_BitType Rte_RxUpdate_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed : 1;
  Rte_BitType Rte_RxUpdate_CDD_Test_SG_RxFilteredSpeed_SG_RxFilteredSpeed_Sender : 1;
  Rte_BitType Rte_RxUpdate_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo : 1;
  Rte_BitType Rte_RxUpdate_OdoMdl_pTIOdoMdl_ComIn_NewRollingOdo_Sender : 1;
} Rte_OsApplication_RxUpdateFlagsType;

# define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_RxUpdateFlags;

# define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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

   MD_Rte_3629:  MISRA rule: 12.12
     Reason:     For an efficient usage of memory the swapping of memory is essential. If data is sequential accessed
                 and not affected by other data the only solution with a type safety access is the usage of unions.
     Risk:       Wrong implementations could remain undetected.
     Prevention: Code inspection and test of different source code variants by the component test suites.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
