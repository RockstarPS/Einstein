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
 *        Config:  Turing.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.18.0
 *                 RTE Core Version 1.18.0
 *       License:  Unlimited license CBD1700714 for Visteon Corporation
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
# define Rte_TypeDef_SInt32
typedef sint32 SInt32;

# define Rte_TypeDef_IoHwAb_DOutGroupIdType
typedef sint32 IoHwAb_DOutGroupIdType;

# define Rte_TypeDef_IoHwAb_DInGroupIdType
typedef sint32 IoHwAb_DInGroupIdType;

# define Rte_TypeDef_AUDIO_To_METER_Frames
typedef sint8 AUDIO_To_METER_Frames;

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_E2E_LanguageInfo_CRC
typedef uint8 E2E_LanguageInfo_CRC;

# define Rte_TypeDef_E2E_LanguageInfo_SeqNumber
typedef uint8 E2E_LanguageInfo_SeqNumber;

# define Rte_TypeDef_E2E_LanguageInfo_Value
typedef uint8 E2E_LanguageInfo_Value;

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

# define Rte_TypeDef_IoHwAb_PulseOutDataType
typedef uint32 IoHwAb_PulseOutDataType;

# define Rte_TypeDef_METER_To_AUDIO_Frames
typedef sint8 METER_To_AUDIO_Frames;

# define Rte_TypeDef_Rte_DT_NV_Data_Batt_0
typedef uint16 Rte_DT_NV_Data_Batt_0;

# define Rte_TypeDef_Rte_DT_NV_Data_Batt_1
typedef uint16 Rte_DT_NV_Data_Batt_1;

# define Rte_TypeDef_Rte_DT_NV_Data_Batt_2
typedef uint16 Rte_DT_NV_Data_Batt_2;

# define Rte_TypeDef_Rte_DT_NV_Data_Batt_3
typedef uint16 Rte_DT_NV_Data_Batt_3;

# define Rte_TypeDef_Rte_DT_NV_Data_Batt_4
typedef uint16 Rte_DT_NV_Data_Batt_4;

# define Rte_TypeDef_Rte_DT_NV_Data_Batt_5
typedef uint16 Rte_DT_NV_Data_Batt_5;

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

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_17
typedef uint16 Rte_DT_NV_Data_ClusterSettings_17;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_18
typedef uint16 Rte_DT_NV_Data_ClusterSettings_18;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_19
typedef uint16 Rte_DT_NV_Data_ClusterSettings_19;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_2
typedef uint16 Rte_DT_NV_Data_ClusterSettings_2;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_20
typedef uint16 Rte_DT_NV_Data_ClusterSettings_20;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_21
typedef boolean Rte_DT_NV_Data_ClusterSettings_21;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_22
typedef boolean Rte_DT_NV_Data_ClusterSettings_22;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_23
typedef boolean Rte_DT_NV_Data_ClusterSettings_23;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_24
typedef boolean Rte_DT_NV_Data_ClusterSettings_24;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_25
typedef uint16 Rte_DT_NV_Data_ClusterSettings_25;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_26
typedef uint16 Rte_DT_NV_Data_ClusterSettings_26;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_27
typedef uint16 Rte_DT_NV_Data_ClusterSettings_27;

# define Rte_TypeDef_Rte_DT_NV_Data_ClusterSettings_28
typedef uint16 Rte_DT_NV_Data_ClusterSettings_28;

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

# define Rte_TypeDef_Rte_DT_PwmCalibrationType_0_0
typedef sint16 Rte_DT_PwmCalibrationType_0_0;

# define Rte_TypeDef_Rte_DT_PwmCalibrationType_1_0
typedef sint8 Rte_DT_PwmCalibrationType_1_0;

# define Rte_TypeDef_Rte_DT_RtcCalibration_Type_0
typedef uint16 Rte_DT_RtcCalibration_Type_0;

# define Rte_TypeDef_Rte_DT_RtcCalibration_Type_1
typedef sint16 Rte_DT_RtcCalibration_Type_1;

# define Rte_TypeDef_Rte_DT_SOdoDataSet_0
typedef uint16 Rte_DT_SOdoDataSet_0;

# define Rte_TypeDef_Rte_DT_SOdoDataSet_1
typedef uint8 Rte_DT_SOdoDataSet_1;

# define Rte_TypeDef_Rte_DT_SOdoDataSet_2
typedef uint8 Rte_DT_SOdoDataSet_2;

# define Rte_TypeDef_TPulseChannelId
typedef uint8 TPulseChannelId;

# define Rte_TypeDef_TPulseClientId
typedef uint8 TPulseClientId;

# define Rte_TypeDef_TYP_DISTANCE_UNIT
typedef sint32 TYP_DISTANCE_UNIT;

# define Rte_TypeDef_TYP_FAILURE
typedef sint32 TYP_FAILURE;

# define Rte_TypeDef_TYP_LAST_FUEL_UPDATE_CAUSE
typedef sint32 TYP_LAST_FUEL_UPDATE_CAUSE;

# define Rte_TypeDef_UFIX16_S10
typedef uint16 UFIX16_S10;

# define Rte_TypeDef_UFIX16_S100
typedef uint16 UFIX16_S100;

# define Rte_TypeDef_UFIX16_SP1
typedef uint16 UFIX16_SP1;

# define Rte_TypeDef_UFIX32_SP01
typedef uint32 UFIX32_SP01;

# define Rte_TypeDef_UFIX8_SP01
typedef uint8 UFIX8_SP01;

# define Rte_TypeDef_UFIX8_SP1
typedef uint8 UFIX8_SP1;

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

# define Rte_TypeDef_EChimeStatus
typedef uint8 EChimeStatus;

# define Rte_TypeDef_EKeyPos
typedef uint8 EKeyPos;

# define Rte_TypeDef_EPulsePhase
typedef uint8 EPulsePhase;

# define Rte_TypeDef_ESnd_InterruptType
typedef uint8 ESnd_InterruptType;

# define Rte_TypeDef_HTimer
typedef uint8 HTimer;

# define Rte_TypeDef_IoHwAb_AdcSignalIdType
typedef uint8 IoHwAb_AdcSignalIdType;

# define Rte_TypeDef_IoHwAb_DInSignalIdType
typedef uint8 IoHwAb_DInSignalIdType;

# define Rte_TypeDef_IoHwAb_DOutSignalIdType
typedef uint8 IoHwAb_DOutSignalIdType;

# define Rte_TypeDef_IoHwAb_ErrorType
typedef uint8 IoHwAb_ErrorType;

# define Rte_TypeDef_IoHwAb_PulseInputSignalIdType
typedef uint8 IoHwAb_PulseInputSignalIdType;

# define Rte_TypeDef_IoHwAb_PwmSignalIdType
typedef uint8 IoHwAb_PwmSignalIdType;

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[4];

# define Rte_TypeDef_NvM_ECU24BytesNumberType
typedef Rte_DT_NvM_ECU24BytesNumberType_0 NvM_ECU24BytesNumberType[24];

# define Rte_TypeDef_NvM_ECUSerialNumberType
typedef Rte_DT_NvM_ECUSerialNumberType_0 NvM_ECUSerialNumberType[16];

# define Rte_TypeDef_NvM_ProductInfo
typedef Rte_DT_NvM_ProductInfo_0 NvM_ProductInfo[126];

# define Rte_TypeDef_Rte_DT_PwmCalibrationType_0
typedef Rte_DT_PwmCalibrationType_0_0 Rte_DT_PwmCalibrationType_0[5];

# define Rte_TypeDef_Rte_DT_PwmCalibrationType_1
typedef Rte_DT_PwmCalibrationType_1_0 Rte_DT_PwmCalibrationType_1[5];

# define Rte_TypeDef_rt_Array_Boolean_16
typedef boolean rt_Array_Boolean_16[16];

# define Rte_TypeDef_rt_Array_Boolean_48
typedef boolean rt_Array_Boolean_48[48];

# define Rte_TypeDef_NV_Data_Batt
typedef struct
{
  Rte_DT_NV_Data_Batt_0 UnderVoltageThreshold;
  Rte_DT_NV_Data_Batt_1 OverVoltagePh2Hysteresis;
  Rte_DT_NV_Data_Batt_2 OverVoltagePh2Threshold;
  Rte_DT_NV_Data_Batt_3 OverVoltagePh1Hysteresis;
  Rte_DT_NV_Data_Batt_4 OverVoltagePh1Threshold;
  Rte_DT_NV_Data_Batt_5 UnderVoltageHysteresis;
} NV_Data_Batt;

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
  Rte_DT_NV_Data_ClusterSettings_17 RPM_Hysteresis_Angle_Value;
  Rte_DT_NV_Data_ClusterSettings_18 Speedo_Hysteresis_Angle_Value;
  Rte_DT_NV_Data_ClusterSettings_19 Ect_Hysteresis_Angle_Value;
  Rte_DT_NV_Data_ClusterSettings_20 Fuel_Hysteresis_Angle_Value;
  Rte_DT_NV_Data_ClusterSettings_21 RPM_Hysteresis_Direction_Value;
  Rte_DT_NV_Data_ClusterSettings_22 Speedo_Hysteresis_Direction_Value;
  Rte_DT_NV_Data_ClusterSettings_23 Ect_Hysteresis_Direction_Value;
  Rte_DT_NV_Data_ClusterSettings_24 Fuel_Hysteresis_Direction_Value;
  Rte_DT_NV_Data_ClusterSettings_25 Ect_OverDrive_Offset_Value;
  Rte_DT_NV_Data_ClusterSettings_26 Fuel_OverDrive_Offset_Value;
  Rte_DT_NV_Data_ClusterSettings_27 RPM_OverDrive_Offset_Value;
  Rte_DT_NV_Data_ClusterSettings_28 Speedo_OverDrive_Offset_Value;
} NV_Data_ClusterSettings;

# define Rte_TypeDef_NV_Data_DataBlock
typedef struct
{
  TYP_DISTANCE_UNIT NV_DisplayedSpeedUnit_S;
  TYP_FAILURE NV_FuelConsumptionFailure_S;
  TYP_LAST_FUEL_UPDATE_CAUSE NV_FuelReadjustmentCauseVal_S;
  TYP_FAILURE NV_GaugeOCFailure_S;
  TYP_FAILURE NV_GaugeSCFailure_S;
  TYP_FAILURE NV_VehicleSpeedFailure_S;
  UFIX32_SP01 NV_ClusterCurrentDistance_S;
  UFIX32_SP01 NV_ClusterDistBeforeReadjust_S;
  UInt32 NV_DistanceAtBackUpReadjust_S;
  UFIX32_SP01 NV_DistanceTotalizerRAZ_S;
  UFIX32_SP01 NV_ExtECUDistBeforeReadjust_S;
  UInt32 NV_MSCAbsoluteTimeOilChangeTarget_S;
  UInt32 NV_MSCAbsoluteTimeServiceTarget_S;
  UInt32 NV_MSCGeneralOdoOilChgTarget_S;
  UInt32 NV_MSCGeneralOdoServiceTarget_S;
  UInt32 NV_MSCTimeOrigin_S;
  UInt16 NV_CauseService_S;
  UInt16 NV_CauseStop_S;
  UInt8 NV_CauseOfLastTripComputerGasReset_S;
  UInt8 NV_CauseOfLastTripComputerGlobalReset_S;
  UInt8 NV_CauseOfLastTripComputerReset_S;
  UInt8 NV_DistUpdateByDiagCounter_S;
  UInt8 NV_DistUpdateByExtECUCounter_S;
  UInt8 NV_L0onDuringFuelReadjust_S;
  UInt8 NV_L2offDuringFuelReadjust_S;
  UInt8 NV_L3DuringFuelReadjust_S;
  UInt8 DataBlock_SpareByte0;
  Boolean NV_AbsTimeValidOil_S;
  Boolean NV_AbsTimeValidServ_S;
  Boolean DataBlock_SpareBit5;
  Boolean DataBlock_SpareBit4;
  Boolean DataBlock_SpareBit3;
  Boolean DataBlock_SpareBit2;
  Boolean DataBlock_SpareBit1;
  Boolean DataBlock_SpareBit0;
} NV_Data_DataBlock;

# define Rte_TypeDef_RtcCalibration_Type
typedef struct
{
  Rte_DT_RtcCalibration_Type_0 K;
  Rte_DT_RtcCalibration_Type_1 E_R_FC;
} RtcCalibration_Type;

# define Rte_TypeDef_Rtc_TimeType
typedef struct
{
  uint16 Date;
  uint8 Hour;
  uint8 Minute;
  uint8 Second;
} Rtc_TimeType;

# define Rte_TypeDef_SG_LanguageInfoSG
typedef struct
{
  E2E_LanguageInfo_CRC E2E_LanguageInfo_CRC;
  E2E_LanguageInfo_SeqNumber E2E_LanguageInfo_SeqNumber;
  E2E_LanguageInfo_Value E2E_LanguageInfo_Value;
} SG_LanguageInfoSG;

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

# define Rte_TypeDef_SPulseInputConfigParam
typedef struct
{
  uint32 MissingRecoveryTimeoutInMicroSec;
  uint32 ValidPeriodMinInMicroSec;
  uint32 ValidPeriodMaxInMicroSec;
  uint32 HystLimitForPeriodMinInMicroSec;
  uint32 HystRcvryForPeriodMinInMicroSec;
  uint32 HystLimitForPeriodMaxInMicroSec;
  uint32 HystRcvryForPeriodMaxInMicroSec;
  uint16 ValidDutyMinInPercentage;
  uint16 ValidDutyMaxInPercentage;
  uint16 HystLimitForDutyMinInPercentage;
  uint16 HystRcvryForDutyMinInPercentage;
  uint16 HystLimitForDutyMaxInPercentage;
  uint16 HystRcvryForDutyMaxInPercentage;
  uint16 InValidTimeoutInMilliSec;
  uint16 InValidRecoveryTimeoutInMilliSec;
  uint16 MissingTimeoutInMilliSec;
} SPulseInputConfigParam;

# define Rte_TypeDef_SPulseNotification
typedef struct
{
  TPulseChannelId Channel;
  EPulsePhase Phase;
} SPulseNotification;

# define Rte_TypeDef_SSpeedCalcParam
typedef struct
{
  uint32 Pulses_Per_Revolution;
  uint32 Revolutions_Per_Unit;
  uint32 Tuning_Factor;
} SSpeedCalcParam;

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

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

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
typedef uint16 Dem_DTCOriginType;

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

# define Rte_TypeDef_NV_Data_ConfigBlock
typedef struct
{
  UInt32 NV_M_ClusterUserSetMenu_p1_CF;
  UInt32 NV_M_ClusterUserSetMenu_p2_CF;
  UInt32 NV_M_ECUPresent_Part1_CF;
  UInt32 NV_M_ECUPresent_Part2_CF;
  UInt32 ConfigBlock_SpareDword2;
  UInt32 ConfigBlock_SpareDword1;
  UInt32 ConfigBlock_SpareDword0;
  UInt16 NV_M_ADACWorldPresence_CF;
  UFIX16_S10 NV_M_BackupTau_CF;
  UInt16 NV_M_DisplayableLanguage_P1_CF;
  UInt16 NV_M_DisplayableLanguage_P2_CF;
  UInt16 NV_M_DisplayableLanguage_P3_CF;
  UFIX16_SP1 NV_M_L2Displayed10_CF;
  UFIX16_SP1 NV_M_L2Displayed11_CF;
  UFIX16_SP1 NV_M_L2Displayed12_CF;
  UFIX16_SP1 NV_M_L2Displayed1_CF;
  UFIX16_SP1 NV_M_L2Displayed2_CF;
  UFIX16_SP1 NV_M_L2Displayed3_CF;
  UFIX16_SP1 NV_M_L2Displayed4_CF;
  UFIX16_SP1 NV_M_L2Displayed5_CF;
  UFIX16_SP1 NV_M_L2Displayed6_CF;
  UFIX16_SP1 NV_M_L2Displayed7_CF;
  UFIX16_SP1 NV_M_L2Displayed8_CF;
  UFIX16_SP1 NV_M_L2Displayed9_CF;
  UInt16 NV_M_MSCOilChgInitialDistanceInKM_CF;
  UInt16 NV_M_MSCOilChgInitialPeriodInDay_CF;
  UFIX16_S100 NV_M_MSCOilChgWarningThresholdKM_CF;
  UInt16 NV_M_MSCServiceInitialDistanceInKM_CF;
  UInt16 NV_M_MSCServiceInitialPeriodInDay_CF;
  UFIX16_S100 NV_M_MSCServiceWarningThresholdKM_CF;
  UInt16 NV_M_PersoPageType_CF;
  UInt16 NV_M_RST_Cmax_DefaultOrNeutral_CF;
  UInt16 NV_M_RST_Pmax_DefaultOrNeutral_CF;
  UInt16 NV_M_RoundPerMinuteMaxDisplayed_CF;
  UInt16 NV_M_V0FuncR0Resistance_CF;
  UInt16 NV_M_V10FuncR10Resistance_CF;
  UInt16 NV_M_V1FuncR1Resistance_CF;
  UInt16 NV_M_V2FuncR2Resistance_CF;
  UInt16 NV_M_V3FuncR3Resistance_CF;
  UInt16 NV_M_V4FuncR4Resistance_CF;
  UInt16 NV_M_V5FuncR5Resistance_CF;
  UInt16 NV_M_V6FuncR6Resistance_CF;
  UInt16 NV_M_V7FuncR7Resistance_CF;
  UInt16 NV_M_V8FuncR8Resistance_CF;
  UInt16 NV_M_V9FuncR9Resistance_CF;
  UInt8 NV_M_AEBMMI_CF;
  UInt8 NV_M_AmbientLightMMI_CF;
  UFIX8_SP1 NV_M_BackupVolumeFuelWarning_CF;
  UInt8 NV_M_BodyTypeHMIVariant_CF;
  UInt8 NV_M_CarburationType_CF;
  UInt8 NV_M_ChronotachographPresence_CF;
  UInt8 NV_M_ClockDisplayMode_CF;
  UInt8 NV_M_Clock_CF;
  UInt8 NV_M_CountryHMISpecificity_CF;
  UInt8 NV_M_DW_CF;
  UInt8 NV_M_DimmingStrategy_CF;
  UInt8 NV_M_DistanceUnit_CF;
  UInt8 NV_M_DriverInteractionMode_CF;
  UInt8 NV_M_ECOMODEBYMEX_CF;
  UInt8 NV_M_EXTENDEDGRIPMMI_CF;
  UInt8 NV_M_ExternalTemperaturePresent_CF;
  UInt8 NV_M_FreeShiftManagement_CF;
  UInt8 NV_M_FrontSBRInhibition_CF;
  UInt8 NV_M_FuelRangeCorrectKmAutonom_CF;
  UFIX8_SP1 NV_M_FuelRangeCorrectL2Alert_CF;
  UInt8 NV_M_FuelReadjustL0L3_CF;
  UInt8 NV_M_FuelReadjustL2ZeroSpeed_CF;
  UInt8 NV_M_FuelReadjustL2offL0_CF;
  UInt8 NV_M_FuelReadjustNearFullL0L3_CF;
  UInt8 NV_M_FuelReadjustNearFullL0_CF;
  UInt8 NV_M_FuelReadjustNearFullL2_CF;
  UInt8 NV_M_GaugingThresholdHigh_CF;
  UInt8 NV_M_GaugingThresholdLow_CF;
  UInt8 NV_M_GearBoxType_CMF1_CF;
  UInt8 NV_M_LDWMMI_CF;
  UInt8 NV_M_Language_CF;
  UInt8 NV_M_MSCOilDistanceCounterPresent_CF;
  UInt8 NV_M_NivocodSensorType_CF;
  UInt8 NV_M_ParkingBrakeType_CF;
  UFIX8_SP01 NV_M_S1Kmaj_CF;
  UFIX8_SP01 NV_M_S1Kmin_CF;
  UFIX8_SP01 NV_M_S2Kmaj_CF;
  UFIX8_SP01 NV_M_S2Kmin_CF;
  UFIX8_SP01 NV_M_S3Kmaj_CF;
  UFIX8_SP01 NV_M_S3Kmin_CF;
  UInt8 NV_M_SpeedScaleType_CF;
  UInt8 NV_M_TACStrategy_CF;
  UInt8 NV_M_TCI_OptimisticFactor_CF;
  UFIX8_SP1 NV_M_TCI_RemainingDistanceDisappearanceThreshold_CF;
  UInt8 NV_M_TCI_RemainingDistanceIncreaseInhibitionThreshold_CF;
  UInt8 NV_M_TCI_RemainingDistanceWarningThreshold_CF;
  UInt8 NV_M_TPMSMMI_CF;
  UInt8 NV_M_TemperatureUnit_CF;
  UInt8 NV_M_TripComputerType_CF;
  UInt8 NV_M_TyrePressureUnit_CF;
  UInt8 NV_M_UPA_CF;
  UInt8 NV_M_V0FuncR0Volume_CF;
  UInt8 NV_M_V10FuncR10Volume_CF;
  UInt8 NV_M_V1FuncR1Volume_CF;
  UInt8 NV_M_V2FuncR2Volume_CF;
  UInt8 NV_M_V3FuncR3Volume_CF;
  UInt8 NV_M_V4FuncR4Volume_CF;
  UInt8 NV_M_V5FuncR5Volume_CF;
  UInt8 NV_M_V6FuncR6Volume_CF;
  UInt8 NV_M_V7FuncR7Volume_CF;
  UInt8 NV_M_V8FuncR8Volume_CF;
  UInt8 NV_M_V9FuncR9Volume_CF;
  UFIX8_SP1 NV_M_VolumeFuelWarning_CF;
  UInt8 NV_M_VolumeUnit_CF;
  UInt8 NV_M_WelcomeSequenceInhibition_CF;
  rt_Array_Boolean_48 NV_M_TelltaleAutotest_CF;
  rt_Array_Boolean_16 NV_M_DayBacklightsPresent_CF;
  UInt8 ConfigBlock_SpareByte2;
  UInt8 ConfigBlock_SpareByte1;
  UInt8 ConfigBlock_SpareByte0;
  Boolean NV_M_ADAS_LCAHMIVariant_CF;
  Boolean NV_M_BatteryWarnWireInhibition_CF;
  Boolean NV_M_ClusterUserSetPresent_CF;
  Boolean NV_M_DrivingStyleIndicatorMMI_CF;
  Boolean NV_M_DynamicTacho_CF;
  Boolean NV_M_MSCOilTimeCounterPresent_CF;
  Boolean NV_M_MSCServDistanceCounterPresent_CF;
  Boolean NV_M_MSCServTimeCounterPresent_CF;
  Boolean NV_M_OilLevelPresent_CF;
  Boolean NV_M_OverspeedWarningPresent_CF;
  Boolean NV_M_SEDMMI_CF;
  Boolean NV_M_UTAMMI_CF;
  Boolean NV_M_WaterTempPageMMI_CF;
  Boolean NV_M_WithESC_CF;
  Boolean ConfigBlock_SpareBit1;
  Boolean ConfigBlock_SpareBit0;
} NV_Data_ConfigBlock;

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

# define Rte_TypeDef_PwmCalibrationType
typedef struct
{
  Rte_DT_PwmCalibrationType_0 Offset;
  Rte_DT_PwmCalibrationType_1 Multiplier;
} PwmCalibrationType;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;

# define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;

# define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;

# define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_ArrayHandle
typedef uint16 ArrayHandle;

#  define Rte_TypeDef_DownTranOfEngCoolantTempCAN
typedef boolean DownTranOfEngCoolantTempCAN;

#  define Rte_TypeDef_DownTranOfEngCoolantTempCAN_1
typedef boolean DownTranOfEngCoolantTempCAN_1;

#  define Rte_TypeDef_E2E_AirbagMalfunction_CRC
typedef uint8 E2E_AirbagMalfunction_CRC;

#  define Rte_TypeDef_E2E_AirbagMalfunction_SeqNumber
typedef uint8 E2E_AirbagMalfunction_SeqNumber;

#  define Rte_TypeDef_E2E_AirbagMalfunction_Value
typedef boolean E2E_AirbagMalfunction_Value;

#  define Rte_TypeDef_EngineCoolantTempCAN
typedef sint8 EngineCoolantTempCAN;

#  define Rte_TypeDef_FUEL_LEVEL_CAN
typedef sint16 FUEL_LEVEL_CAN;

#  define Rte_TypeDef_InterpTblHandle
typedef uint16 InterpTblHandle;

#  define Rte_TypeDef_IoHwAb_DO_TT_Type
typedef uint16 IoHwAb_DO_TT_Type;

#  define Rte_TypeDef_PtrUint16
typedef uint16 * PtrUint16;

#  define Rte_TypeDef_Rte_DT_Gauge_Correction_Table_X_0
typedef uint16 Rte_DT_Gauge_Correction_Table_X_0;

#  define Rte_TypeDef_Rte_DT_Gauge_Correction_Table_Y_0
typedef uint16 Rte_DT_Gauge_Correction_Table_Y_0;

#  define Rte_TypeDef_Rte_DT_Gauge_Mapping_Table_X_0
typedef uint16 Rte_DT_Gauge_Mapping_Table_X_0;

#  define Rte_TypeDef_Rte_DT_Gauge_Mapping_Table_Y_0
typedef uint16 Rte_DT_Gauge_Mapping_Table_Y_0;

#  define Rte_TypeDef_Rte_DT_IoHwAbCalibration_Type_0
typedef uint8 Rte_DT_IoHwAbCalibration_Type_0;

#  define Rte_TypeDef_Rte_DT_IoHwAbCalibration_Type_1
typedef uint8 Rte_DT_IoHwAbCalibration_Type_1;

#  define Rte_TypeDef_Rte_DT_IoHwAbCalibration_Type_2
typedef uint8 Rte_DT_IoHwAbCalibration_Type_2;

#  define Rte_TypeDef_THwData
typedef uint32 THwData;

#  define Rte_TypeDef_TIOAppData
typedef sint32 TIOAppData;

#  define Rte_TypeDef_TWrnId
typedef uint16 TWrnId;

#  define Rte_TypeDef_TWrnListMask
typedef uint8 TWrnListMask;

#  define Rte_TypeDef_UFIX16_SP001
typedef uint16 UFIX16_SP001;

#  define Rte_TypeDef_UFIX16_SP01
typedef uint16 UFIX16_SP01;

#  define Rte_TypeDef_WarningWaterTempCAN
typedef sint8 WarningWaterTempCAN;

#  define Rte_TypeDef_WarningWaterTempCAN_1
typedef sint8 WarningWaterTempCAN_1;

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

#  define Rte_TypeDef_EAnalogButton
typedef uint8 EAnalogButton;

#  define Rte_TypeDef_EBatteryState
typedef uint8 EBatteryState;

#  define Rte_TypeDef_EBtnState
typedef uint8 EBtnState;

#  define Rte_TypeDef_EDcmExtAction
typedef uint8 EDcmExtAction;

#  define Rte_TypeDef_EHmiSubId
typedef uint8 EHmiSubId;

#  define Rte_TypeDef_EIOCurrentInId
typedef sint32 EIOCurrentInId;

#  define Rte_TypeDef_EIODutyInId
typedef sint32 EIODutyInId;

#  define Rte_TypeDef_EIOGroupInId
typedef sint32 EIOGroupInId;

#  define Rte_TypeDef_EIOGroupOutId
typedef sint32 EIOGroupOutId;

#  define Rte_TypeDef_EIOMapStat
typedef uint8 EIOMapStat;

#  define Rte_TypeDef_EIOMapStatInId
typedef sint32 EIOMapStatInId;

#  define Rte_TypeDef_EIOPeriodInId
typedef sint32 EIOPeriodInId;

#  define Rte_TypeDef_EIOPeriodOutId
typedef sint32 EIOPeriodOutId;

#  define Rte_TypeDef_EIOPinInId
typedef uint8 EIOPinInId;

#  define Rte_TypeDef_EIOPinOutId
typedef uint8 EIOPinOutId;

#  define Rte_TypeDef_EIOResistanceInId
typedef sint32 EIOResistanceInId;

#  define Rte_TypeDef_EIOVoltageInId
typedef sint32 EIOVoltageInId;

#  define Rte_TypeDef_EIOVoltageOutId
typedef sint32 EIOVoltageOutId;

#  define Rte_TypeDef_EStpCalibKind
typedef uint8 EStpCalibKind;

#  define Rte_TypeDef_EStpStat
typedef uint8 EStpStat;

#  define Rte_TypeDef_ETtMdlMask
typedef uint8 ETtMdlMask;

#  define Rte_TypeDef_EWrnId
typedef uint8 EWrnId;

#  define Rte_TypeDef_EWrnReason
typedef uint8 EWrnReason;

#  define Rte_TypeDef_TYP_CAN_SIGNAL_STATUS
typedef sint32 TYP_CAN_SIGNAL_STATUS;

#  define Rte_TypeDef_eSystemEventType
typedef uint8 eSystemEventType;

#  define Rte_TypeDef_DiagReqBufferType
typedef uint8 DiagReqBufferType[16];

#  define Rte_TypeDef_DiagRespBufferType
typedef uint8 DiagRespBufferType[8];

#  define Rte_TypeDef_Gauge_Correction_Table_X
typedef Rte_DT_Gauge_Correction_Table_X_0 Gauge_Correction_Table_X[2];

#  define Rte_TypeDef_Gauge_Correction_Table_Y
typedef Rte_DT_Gauge_Correction_Table_Y_0 Gauge_Correction_Table_Y[2];

#  define Rte_TypeDef_Gauge_Mapping_Table_X
typedef Rte_DT_Gauge_Mapping_Table_X_0 Gauge_Mapping_Table_X[2];

#  define Rte_TypeDef_Gauge_Mapping_Table_Y
typedef Rte_DT_Gauge_Mapping_Table_Y_0 Gauge_Mapping_Table_Y[2];

#  define Rte_TypeDef_U8Array128
typedef uint8 U8Array128[128];

#  define Rte_TypeDef_U8Array5
typedef uint8 U8Array5[5];

#  define Rte_TypeDef_IoHwAbCalibration_Type
typedef struct
{
  Rte_DT_IoHwAbCalibration_Type_0 KMONTIME;
  Rte_DT_IoHwAbCalibration_Type_1 KMONTIMEB;
  Rte_DT_IoHwAbCalibration_Type_2 KMONTIMEC;
} IoHwAbCalibration_Type;

#  define Rte_TypeDef_SDimming_t
typedef struct
{
  uint8 TftDimmingCmd;
} SDimming_t;

#  define Rte_TypeDef_SG_AirbagMalfunctionSG
typedef struct
{
  E2E_AirbagMalfunction_SeqNumber E2E_AirbagMalfunction_SeqNumber;
  E2E_AirbagMalfunction_Value E2E_AirbagMalfunction_Value;
  E2E_AirbagMalfunction_CRC E2E_AirbagMalfunction_CRC;
} SG_AirbagMalfunctionSG;

#  define Rte_TypeDef_SNotifyMACPacketsCount_t
typedef struct
{
  uint32 u32PacketsCountP;
} SNotifyMACPacketsCount_t;

#  define Rte_TypeDef_SSALT_t
typedef struct
{
  uint16 NewAlertToDisplay_VIF;
  uint16 HMI_iMessageToDisplay_VIF;
  uint16 PictureToDisplay_VIF;
  uint8 AlertRecColor_VIF;
  uint8 HMI_iALTColor_VIF;
  uint8 HMI_iALTMessageType_VIF;
} SSALT_t;

#  define Rte_TypeDef_SSANIM_t
typedef struct
{
  uint8 DisplayAnimType_VIF;
} SSANIM_t;

#  define Rte_TypeDef_SSBATTERY_t
typedef struct
{
  sint32 GaugeHVBatteryStatus_VIF;
  uint8 GaugeHVBatteryEnergyLevel_VIF;
  uint8 NumericHVBatteryEnergyLevel_VIF;
} SSBATTERY_t;

#  define Rte_TypeDef_SSCCSL_ACC_t
typedef struct
{
  sint32 HMI_iCCSLACCState;
  uint16 HMI_sRegulationStateDesc;
  uint8 HMI_sACCReqSpeedDisplay_VIF;
} SSCCSL_ACC_t;

#  define Rte_TypeDef_SSFUEL_t
typedef struct
{
  uint16 FuelGaugeLevelToDisplayPercent_VIF;
  uint8 FuelGaugeLevelToDisplayExtBar_VIF;
} SSFUEL_t;

#  define Rte_TypeDef_SSISC_t
typedef struct
{
  uint8 AdvisorEconometer_VIF;
} SSISC_t;

#  define Rte_TypeDef_SSMisc_t
typedef struct
{
  uint16 ChargeInterruptionDelay_VIF;
  uint16 SCR_DistanceAutonomyDisplay_VIF;
  uint8 LevellingDisplayValue_VIF;
  uint8 CurrentDriveMode_VIF;
  uint8 EgocarColor_VIF;
} SSMisc_t;

#  define Rte_TypeDef_SSPOWER_METER_t
typedef struct
{
  sint32 PHEV_PwrMeter_Gauge_background_VIF;
  sint32 PHEV_PwrMeter_Gauge_style_VIF;
  sint32 PHEV_MaxPwrIndicator_status_VIF;
  sint8 PowermeterValue_VIF;
  uint8 PHEV_MaxPwrIndicator_value_VIF;
} SSPOWER_METER_t;

#  define Rte_TypeDef_SSTACH_t
typedef struct
{
  uint16 HMI_iDisplayedEngineRpm_VIF;
  uint8 RPMScale_VIF;
} SSTACH_t;

#  define Rte_TypeDef_SSWATER_TEMP_t
typedef struct
{
  uint8 DispEngineCoolantTemp_VIF;
} SSWATER_TEMP_t;

#  define Rte_TypeDef_SStpIfCfg
typedef struct
{
  boolean bRotationDirection;
  uint8 MagneticOffset;
} SStpIfCfg;

#  define Rte_TypeDef_STRUCT_DISP_ENGINE_COOLANT_TEMP
typedef struct
{
  UInt8 Data;
  UInt8 Status;
} STRUCT_DISP_ENGINE_COOLANT_TEMP;

#  define Rte_TypeDef_STRUCT_DYNAMIC_ENGINE
typedef struct
{
  UInt16 Data;
  UInt8 Status;
} STRUCT_DYNAMIC_ENGINE;

#  define Rte_TypeDef_STRUCT_ENGINE_COOLANT_TEMP
typedef struct
{
  UInt8 Data;
  TYP_CAN_SIGNAL_STATUS Status;
} STRUCT_ENGINE_COOLANT_TEMP;

#  define Rte_TypeDef_STRUCT_FUEL_LEVEL_CAN
typedef struct
{
  UFIX16_SP001 Data;
  TYP_CAN_SIGNAL_STATUS Status;
} STRUCT_FUEL_LEVEL_CAN;

#  define Rte_TypeDef_STRUCT_WARNING_WATER_TEMP
typedef struct
{
  UInt8 Data;
  TYP_CAN_SIGNAL_STATUS Status;
} STRUCT_WARNING_WATER_TEMP;

#  define Rte_TypeDef_sTrcOut
typedef struct
{
  uint32 TripTime;
  uint32 TripDistance;
  uint32 TripDTE;
  uint32 TripAFE;
  uint32 DTE;
  uint32 AFE;
} sTrcOut;

#  define Rte_TypeDef_sTrcOut_01
typedef struct
{
  uint32 TripTime;
  uint32 TripDistance;
  uint32 TripDTE;
  uint32 TripAFE;
  uint32 DTE;
  uint32 AFE;
} sTrcOut_01;

#  define Rte_TypeDef_CommStatusType
typedef uint8 CommStatusType;

#  define Rte_TypeDef_DiagActionType
typedef uint8 DiagActionType;

#  define Rte_TypeDef_DiagResultType
typedef uint8 DiagResultType;

#  define Rte_TypeDef_ErrorCauseType
typedef uint8 ErrorCauseType;

#  define Rte_TypeDef_ErrorOriginType
typedef uint8 ErrorOriginType;

#  define Rte_TypeDef_EthernetMmiType
typedef uint8 EthernetMmiType;

#  define Rte_TypeDef_FaultStatusType
typedef uint8 FaultStatusType;

#  define Rte_TypeDef_FaultType
typedef uint8 FaultType;

#  define Rte_TypeDef_HealthStatusType
typedef uint8 HealthStatusType;

#  define Rte_TypeDef_ModeType
typedef uint8 ModeType;

#  define Rte_TypeDef_MpdtChannelType
typedef uint8 MpdtChannelType;

#  define Rte_TypeDef_NV_Data_Interpolations
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

#  define Rte_TypeDef_PicFileStatusType
typedef uint8 PicFileStatusType;

#  define Rte_TypeDef_ResetReasonType
typedef uint8 ResetReasonType;

#  define Rte_TypeDef_SDiagRequest_t
typedef struct
{
  DiagReqBufferType DataP;
  sint32 ServiceId;
  DiagActionType ActionP;
  uint8 LengthP;
} SDiagRequest_t;

#  define Rte_TypeDef_SDiagResponse_t
typedef struct
{
  DiagResultType DiagResult;
  DiagRespBufferType DiagRespBuffer;
  uint8 Length;
} SDiagResponse_t;

#  define Rte_TypeDef_SEthernetActivationReq_t
typedef struct
{
  Boolean EthernetActivationReq;
} SEthernetActivationReq_t;

#  define Rte_TypeDef_SEthernetMmi_t
typedef struct
{
  EthernetMmiType EthernetMmi;
} SEthernetMmi_t;

#  define Rte_TypeDef_SModeType_t
typedef struct
{
  ModeType Mode;
} SModeType_t;

#  define Rte_TypeDef_SNotifyEthernetCommStatus_t
typedef struct
{
  CommStatusType StatusP;
} SNotifyEthernetCommStatus_t;

#  define Rte_TypeDef_SNotifyGIPDtc_t
typedef struct
{
  FaultType Fault;
  FaultStatusType FaultStatus;
} SNotifyGIPDtc_t;

#  define Rte_TypeDef_SNotifyGIPStatus_t
typedef struct
{
  ModeType NotifyGIPStatus;
} SNotifyGIPStatus_t;

#  define Rte_TypeDef_SNotifyHeartBeat_t
typedef struct
{
  HealthStatusType HealtStatus;
  ErrorCauseType ErrorCause;
  ErrorOriginType ErrorOrigin;
} SNotifyHeartBeat_t;

#  define Rte_TypeDef_SNotifyResetReason_t
typedef struct
{
  ResetReasonType ResetReason;
} SNotifyResetReason_t;

#  define Rte_TypeDef_SPictureData_t
typedef struct
{
  PicFileStatusType u8AudioFileStatus;
  PicFileStatusType u8PhoneFileStatus;
  Boolean bNewAudioFileAvailable_E;
  Boolean bNewPhoneFileAvailable_E;
} SPictureData_t;

#  define Rte_TypeDef_SSADAC_t
typedef struct
{
  sint32 VehicleGUIStyle_VIF;
  sint32 HMI_iConsDispUnit_VIF;
  sint32 InstConsoEVSign_VIF;
  sint32 Amperemeter_sign_VIF;
  uint32 HMI_sPartialDistanceValue_VIF;
  uint32 HMI_sTotalDistanceValue_VIF;
  uint32 HMI_iTripDispDistance_VIF;
  uint16 HMI_sAvConsValue_VIF;
  uint16 HMI_sInstConsValue_VIF;
  uint16 HMI_iTripDispAvgSpeed_VIF;
  uint16 HMI_iDispDistanceAutonomy_VIF;
  uint16 MSCAlertRemainingDays_VIF;
  uint16 MSCAlertRemainingDistance_VIF;
  uint16 MSCOilRemainingDistance_VIF;
  uint16 MSCOilRemainingMonthes_VIF;
  uint16 MSCServiceRemainingDistance_VIF;
  uint16 MSCServiceRemainingMonthes_VIF;
  uint16 TitleAutonomy_VIF;
  uint16 TitleConso_VIF;
  uint16 TitleTrajet_VIF;
  uint16 Amperemeter_value_VIF;
  uint16 AutonomyZEV_VIF;
  uint16 AvgConsoZEV_VIF;
  uint16 Voltmeter_value_VIF;
  uint16 EV_Tachometer_value_VIF;
  uint16 InstConsoEVForBaregraph_VIF;
  uint16 InstConsoZEV_VIF;
  uint16 TitleAmperemeter_VIF;
  uint16 TitleTachymeter_VIF;
  uint16 TitleVoltmeter_VIF;
  uint16 AutonomyHEV_VIF;
  uint8 HMI_iADACPage_VIF;
  uint8 HMI_iALTADACColor_VIF;
  uint8 HMI_iALTADACMessageType_VIF;
  uint8 HMI_iDistanceUnit_VIF;
  uint8 AM_PM_VIF;
  uint8 HMI_iConsDispUnitEV_VIF;
  uint8 EngineMotorEnergyFlowDisp_VIF;
  uint8 EngineWheelEnergyFlowDisp_VIF;
  uint8 MotorWheelEnergyFlowDisp_VIF;
  uint8 TireRotatingDirectionDisp_VIF;
  Boolean ODOTotalVisible_VIF;
} SSADAC_t;

#  define Rte_TypeDef_SSADAS_t
typedef struct
{
  sint32 ACC_distance_level_VIF;
  sint32 HMI_iADASLongi_TakeOverDisplayState_VIF;
  sint32 HMI_iDWgraphism_VIF;
  sint32 LCA_LeftSideState_VIF;
  sint32 LCA_PictoState_VIF;
  sint32 LCA_RightSideState_VIF;
  sint32 LDW_PictoState_VIF;
  sint32 LKAActionLeftSide_VIF;
  sint32 LKAActionRightSide_VIF;
  sint32 LKA_PictoState_VIF;
  sint32 LeftLaneState_VIF;
  sint32 RightLaneState_VIF;
  uint8 ACC_distance_graphism_VIF;
  Boolean CCSLACC_SpeedDisplay_VIF;
  Boolean DWBlinker_VIF;
  uint8 HMI_iACC_target_graphism_VIF;
  uint8 HMI_iDWText_VIF;
} SSADAS_t;

#  define Rte_TypeDef_SSCHARGE_HMI_t
typedef struct
{
  uint16 RemainingChargeTime_Hours_VIF;
  uint16 TitleChargeTimeRemaning_VIF;
  uint8 RemainingChargeTime_Minutes_VIF;
  Boolean RemainingChargeTimeDisplayState_VIF;
  Boolean Presoak_pictogram_display_VIF;
  Boolean Programmed_charge_pictogram_display_VIF;
} SSCHARGE_HMI_t;

#  define Rte_TypeDef_SSCLOCK_t
typedef struct
{
  uint8 Display_Hours_VIF;
  uint8 Display_Minutes_VIF;
  uint8 DisplayedHoursVisible_VIF;
  Boolean DisplayedMinutesVisible_VIF;
  Boolean CLKVisible_VIF;
} SSCLOCK_t;

#  define Rte_TypeDef_SSEXT_TEMP_t
typedef struct
{
  Boolean BlinkOnExternalTemp_VIF;
  uint8 DisplayedExternalTemp_VIF;
  uint8 ExternalTempDisplayedUnit_VIF;
  uint8 ExternalTempVisibility_VIF;
} SSEXT_TEMP_t;

#  define Rte_TypeDef_SSGearbox_t
typedef struct
{
  sint32 HMI_GearLayout_VIF;
  sint32 HMI_P_State_VIF;
  sint32 HMI_R_State_VIF;
  sint32 HMI_N_State_VIF;
  sint32 HMI_D_State_VIF;
  sint32 HMI_B_State_VIF;
  sint32 HMI_M_State_VIF;
  sint32 HMI_L_State_VIF;
  sint32 HMI_Plus_State_VIF;
  sint32 HMI_Minus_State_VIF;
  sint32 IShifter_EngagedGear_VIF;
  sint32 HMI_ReverseAvailability_VIF;
  sint32 HMI_NeutralAvailability_VIF;
  sint32 HMI_DriveAvailability_VIF;
  sint32 HMI_ManualAvailability_VIF;
  uint8 AGB_GearEngaged_VIF;
  uint8 GearBoxType_VIF;
  Boolean FreeshiftUp_VIF;
  Boolean FreeshiftDown_VIF;
} SSGearbox_t;

#  define Rte_TypeDef_SSIDM_t
typedef struct
{
  uint8 idm_fangle_VIF;
  uint8 idm_rangle_VIF;
  Boolean idm_fl_VIF;
  Boolean idm_fr_VIF;
  Boolean idm_rl_VIF;
  Boolean idm_rr_VIF;
} SSIDM_t;

#  define Rte_TypeDef_SSLAYOUT_t
typedef struct
{
  uint8 HMI_Color_VIF;
  uint8 HMI_iClusterSkinStatus_VIF;
  uint8 HMI_iDisplayStatus_VIF;
  uint8 HMI_iMexModeState_VIF;
  uint8 Language_VIF;
  uint8 Reserved1_VIF;
  uint8 Reserved2_VIF;
  uint8 Reserved3_VIF;
  uint8 Reserved4_VIF;
  uint8 EgocarType_VIF;
  uint8 GNCCarburationInProgress_VIF;
  uint8 GPLCarburationInProgress_VIF;
  Boolean TyrePressureUnit_VIF;
  Boolean BicarburationForAutonomy_VIF;
} SSLAYOUT_t;

#  define Rte_TypeDef_SSMENU_t
typedef struct
{
  uint16 MPULine1_VIF;
  uint16 MPULine2_VIF;
  uint16 MPULine3_VIF;
  uint16 MPULine4_VIF;
  uint16 MPUTitle_VIF;
  uint8 MPUArrow_VIF;
  uint8 MPUItem1Attribute_VIF;
  uint8 MPUItem1Type_VIF;
  uint8 MPUItem2Attribute_VIF;
  uint8 MPUItem2Type_VIF;
  uint8 MPUItem3Attribute_VIF;
  uint8 MPUItem3Type_VIF;
  uint8 MPUItem4Attribute_VIF;
  uint8 MPUItem4Type_VIF;
  uint8 MPUItemSelection_VIF;
  uint8 MPU_NbItemOnPage_VIF;
  Boolean MenuRequest_VIF;
} SSMENU_t;

#  define Rte_TypeDef_SSMEX_t
typedef struct
{
  uint16 TitleAWD_VIF;
  uint16 TitleIDM_VIF;
  uint16 TitleDSI_VIF;
  uint16 TitleTorquePower_VIF;
  uint16 TitleAccelerometer_VIF;
  uint16 TitleMexConso_VIF;
  uint8 AcceleratorIndicator_VIF;
  Boolean EcoAdviceAccelOff_VIF;
  Boolean MexAuxMode_AUTO_VIF;
  Boolean MexAuxMode_ENAV_VIF;
  Boolean MexAuxMode_ESAVE_VIF;
} SSMEX_t;

#  define Rte_TypeDef_SSMpdt_t
typedef struct
{
  U8Array128 DataBuf;
  MpdtChannelType ChannelId;
  Boolean ClearChannel;
} SSMpdt_t;

#  define Rte_TypeDef_SSOSP_t
typedef struct
{
  sint32 DangerousAeraUnitDistanceToView_VIF;
  sint32 DangerousZoneMod_VIF;
  sint32 DispDistanceToDangerousZone_VIF;
  sint32 DisplayCloud_VIF;
  sint32 DisplaySpdInClusterUnit_VIF;
  sint32 DisplaySubsign1_VIF;
  sint32 DisplaySubsign2_VIF;
  sint32 DisplaySubsign3_VIF;
  sint32 DisplayTrafficSign_VIF;
  sint32 SortSpeedLimitSign_VIF;
  sint32 SpeedLimitSign2_VIF;
  U8Array5 DangerousAreaDistanceToView_VIF;
  uint8 DangerousAeraSpeedLimitToView_VIF;
  Boolean Is_TSRConfidence2_VIF;
  Boolean Is_TSRConfidence_VIF;
  Boolean OSPOverspeedBlinkerOff_VIF;
  Boolean OverspeedWarning_VIF;
  uint8 SPDLimitValue2_VIF;
  uint8 SpeedInClusterUnit_VIF;
  uint8 SpeedOnLimitSign_VIF;
} SSOSP_t;

#  define Rte_TypeDef_SSPICTURE_t
typedef struct
{
  sint32 AudioFileStatus_VIF;
  sint32 PhoneFileStatus_VIF;
  Boolean NewAudioFileAvailable_E_VIF;
  Boolean NewPhoneFileAvailable_E_VIF;
} SSPICTURE_t;

#  define Rte_TypeDef_SSPerso_page_t
typedef struct
{
  uint32 CurrentAudioTrackNumber_VIF;
  sint32 CurrentPhoneStatus_VIF;
  sint32 UnitDistanceBeforeNextAction_VIF;
  uint16 CompassIndicator_VIF;
  uint16 IconNumberForNav_VIF;
  uint16 PersoPage_InstCons_VIF;
  uint16 PersoPage_AvCons_VIF;
  uint8 CurrentAudioSource_VIF;
  uint8 CurrentAudioStatus_VIF;
  uint8 CurrentRadioBand_VIF;
  uint8 CurrentRadioMode_VIF;
  uint8 CurrentRadioPreset_VIF;
  uint8 DefaultIconNumberForNav_VIF;
  U8Array5 DistanceBeforeNextAction_VIF;
  uint8 FrontDistribRatio_VIF;
  uint8 RearDistribRatio_VIF;
  uint8 RelativeEnginePower_VIF;
  uint8 RelativeEngineTorque_VIF;
  uint8 IconNumberForMotorWayRoadDisp_VIF;
  uint8 IconNumberForMotorWayGuidanceDisp_VIF;
  Boolean CurrentRadioFavorite_VIF;
} SSPerso_page_t;

#  define Rte_TypeDef_SSSBR_t
typedef struct
{
  sint32 SecondRowCenterSafetyBeltState_VIF;
  sint32 SecondRowLeftSafetyBeltState_VIF;
  sint32 SecondRowRightSafetyBeltState_VIF;
  sint32 ThirdRowCenterSafetyBeltState_VIF;
  sint32 ThirdRowLeftSafetyBeltState_VIF;
  sint32 ThirdRowRightSafetyBeltState_VIF;
  Boolean RearSBRVisible_VIF;
  Boolean RearSBRVisibleByAlert_VIF;
  Boolean TLTSeatBelt_VIF;
} SSSBR_t;

#  define Rte_TypeDef_SSSBW_t
typedef struct
{
  sint32 PGear_Color_VIF;
  sint32 RGear_Color_VIF;
  sint32 NGear_Color_VIF;
  sint32 MDGear_Color_VIF;
  sint32 PlusGear_Color_VIF;
  sint32 MinusGear_Color_VIF;
  sint32 ArrowR_VIF;
  sint32 ArrowN_VIF;
  sint32 ArrowPlus_VIF;
  sint32 ArrowMinus_VIF;
  sint32 ArrowMD_VIF;
  Boolean PressBrakePedal_VIF;
} SSSBW_t;

#  define Rte_TypeDef_SSSPD_t
typedef struct
{
  uint16 HMI_fAnalogSpeedValuekmh_VIF;
  uint16 HMI_fAnalogSpeedValuemph_VIF;
  uint16 HMI_sDigitalSpeedValue_VIF;
  uint8 HMI_iSpeedUnit_VIF;
  uint8 SpeedScaleType_VIF;
  uint8 TargetGearToDisplay_VIF;
  Boolean TargetVisible_VIF;
} SSSPD_t;

#  define Rte_TypeDef_SSTT_t
typedef struct
{
  Boolean LevellingDisplayRequest_VIF;
  uint8 TLT4WDCurrentMode_VIF;
  Boolean TLTABS_VIF;
  Boolean TLTAEBSOff2_VIF;
  Boolean TLTAEBSOff_VIF;
  Boolean TLTAirbag_VIF;
  Boolean TLTAutoHold_VIF;
  Boolean TLTBattery_VIF;
  Boolean TLTChargeFailure_VIF;
  Boolean TLTChronotachy_VIF;
  Boolean TLTDAE_VIF;
  Boolean TLTDAEMinorFailure_VIF;
  Boolean TLTElectricalPlug_VIF;
  Boolean TLTElectroTech_VIF;
  Boolean TLTEngineCold_VIF;
  Boolean TLTESC_VIF;
  Boolean TLTESPOff_VIF;
  Boolean TLTEVLimitedPerfo_VIF;
  Boolean TLTFCW_VIF;
  Boolean TLTFrontFog_VIF;
  Boolean TLTFuel_VIF;
  Boolean TLTFuelCap_VIF;
  Boolean TLTGPL_VIF;
  Boolean TLTGroundHeight_VIF;
  Boolean TLTHDC_VIF;
  Boolean TLTHFP_VIF;
  Boolean TLTHighBeam_VIF;
  Boolean TLTLEDPAHL_VIF;
  Boolean TLTLowBeam_VIF;
  Boolean TLTMiniFlex_VIF;
  Boolean TLTMiniTractionBattery_VIF;
  Boolean TLTMinorBrakingFailure_VIF;
  Boolean TLTNivocod_VIF;
  Boolean TLTODB_VIF;
  Boolean TLTOilPressure_VIF;
  Boolean TLTOpenDoor_VIF;
  Boolean TLTOverspeed_VIF;
  Boolean TLTParkBrake_VIF;
  Boolean TLTParticulFilter_VIF;
  Boolean TLTPreglo_VIF;
  Boolean TLTReady_VIF;
  Boolean TLTRearFog_VIF;
  Boolean TLTSailingEnable_VIF;
  Boolean TLTSailingInProgress_VIF;
  Boolean TLTService_VIF;
  Boolean TLTSideLight_VIF;
  Boolean TLTStop_VIF;
  Boolean TLTStopAndStart_VIF;
  Boolean TLTStopStartNa_VIF;
  Boolean TLTTractionBatteryHot_VIF;
  Boolean TLTTyrePressure_VIF;
  Boolean TLTUREA_VIF;
  Boolean TLTWaterTemp_VIF;
  Boolean TTECO_VIF;
  Boolean TLTAFSFailure_VIF;
  Boolean TLTEcomode_VIF;
  Boolean TLTEVmode_VIF;
  Boolean TLTElectroTechMajor_VIF;
  Boolean AltBattEmptyPresent_VIF;
  Boolean TLTTractionBatteryCold_VIF;
  Boolean TLTXEVSystemFailure_VIF;
} SSTT_t;

#  define Rte_TypeDef_SSUPA_t
typedef struct
{
  sint32 FrontCenterDetection_VIF;
  sint32 FrontLeftDetection_VIF;
  sint32 FrontRightDetection_VIF;
  sint32 RearCenterDetection_VIF;
  sint32 RearLeftDetection_VIF;
  sint32 RearRightDetection_VIF;
  Boolean IsFrontActive_VIF;
  Boolean IsRearActive_VIF;
  Boolean UPA_Requested_VIF;
} SSUPA_t;

#  define Rte_TypeDef_SSVIGNETTE_t
typedef struct
{
  uint16 HMI_sFLWheelPressure_VIF;
  uint16 HMI_sFRWheelPressure_VIF;
  uint16 HMI_sRLWheelPressure_VIF;
  uint16 HMI_sRRWheelPressure_VIF;
  Boolean FLWheelPressureVisible_VIF;
  Boolean FRWheelPressureVisible_VIF;
  Boolean HMI_iFLDoorStatus_VIF;
  uint8 HMI_iFLWheelStatus_VIF;
  Boolean HMI_iFRDoorStatus_VIF;
  uint8 HMI_iFRWheelStatus_VIF;
  Boolean HMI_iRLDoorStatus_VIF;
  uint8 HMI_iRLWheelStatus_VIF;
  Boolean HMI_iRRDoorStatus_VIF;
  uint8 HMI_iRRWheelStatus_VIF;
  Boolean HMI_iTrunkStatus_VIF;
  Boolean RLWheelPressureVisible_VIF;
  Boolean RRWheelPressureVisible_VIF;
  uint8 TPMS_VignetteDisplayState;
} SSVIGNETTE_t;

#  define Rte_TypeDef_SSWORLD_List_t
typedef struct
{
  sint32 CurrentSelectedMexID_VIF;
  Boolean AnimationDown_VIF;
  Boolean AnimationUp_VIF;
  uint8 World1SelectedIndex_VIF;
  uint8 World2SelectedIndex_VIF;
  uint8 World3SelectedIndex_VIF;
  Boolean WorldChange_VIF;
  uint8 CurrentSelectedNumberItems_VIF;
  uint8 CurrentSelectedID_VIF;
  Boolean CurrentTreeHasChanged_VIF;
  uint8 CurrentSelectedIndex_VIF;
  uint8 CurrentSelectedNumberMexItems_VIF;
} SSWORLD_List_t;

#  define Rte_TypeDef_SSWORLD_t
typedef struct
{
  sint32 ADAC_Category_VIF;
  Boolean HighlightWorld_VIF;
  uint8 SelectedWorld_VIF;
  Boolean ADAC_CAR_present_VIF;
  Boolean ADAC_AUDIO_present_VIF;
  Boolean ADAC_NAV_present_VIF;
  Boolean ADAC_MEX_present_VIF;
  Boolean ADAC_MPU_present_VIF;
  Boolean ADAC_ALT_present_VIF;
  Boolean ADAC_ADAS_present_VIF;
} SSWORLD_t;

#  define Rte_TypeDef_StreamStatusType
typedef uint8 StreamStatusType;

#  define Rte_TypeDef_TBtnId
typedef uint8 TBtnId;

#  define Rte_TypeDef_VideoLayoutType
typedef uint8 VideoLayoutType;

#  define Rte_TypeDef_SNotifyVideoStream_t
typedef struct
{
  StreamStatusType StatusP;
} SNotifyVideoStream_t;

#  define Rte_TypeDef_SVideoLayout_t
typedef struct
{
  VideoLayoutType VideoLayout;
} SVideoLayout_t;

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(NvM_ECU24BytesNumberType, RTE_CONST) Rte_C_NvM_ECU24BytesNumberType_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NvM_ECUSerialNumberType, RTE_CONST) Rte_C_NvM_ECUSerialNumberType_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NvM_ProductInfo, RTE_CONST) Rte_C_NvM_ProductInfo_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(OdoDataSetType, RTE_CONST) Rte_ZeroElem_OdoDataSet; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(rt_Array_Boolean_16, RTE_CONST) Rte_C_rt_Array_Boolean_16_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(rt_Array_Boolean_48, RTE_CONST) Rte_C_rt_Array_Boolean_48_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Batt, RTE_CONST) Rte_NV_BatteryData_Const; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_ClusterSettings, RTE_CONST) Rte_NV_ZeroDataClusterSettings; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_ConfigBlock, RTE_CONST) Rte_C_NV_Data_ConfigBlock_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DataBlock, RTE_CONST) Rte_C_NV_Data_DataBlock_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NvM_EOLDataType, RTE_CONST) Rte_NVM_EOLDataConstant; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(PwmCalibrationType, RTE_CONST) Rte_PwmCalibrationConstant; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(RtcCalibration_Type, RTE_CONST) Rte_C_RtcCalibration_Type_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SG_LanguageInfoSG, RTE_CONST) Rte_C_SG_LanguageInfoSG_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SG_RxFilteredSpeed, RTE_CONST) Rte_C_SG_RxFilteredSpeed_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST) Rte_C_STRUCT_ECT_CONFIGURATION_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST) Rte_NV_ZeroEctConfiguration; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# include "Rte_DataHandleType.h"

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Calibration component and SW-C local calibration parameters
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(NV_Data_ClusterSettings, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings_ROM_NVBlockDescriptor_ClusterSettings; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_ConfigBlock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ConfigBlock_ROM_NVBlockDescriptor_ConfigBlock; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DataBlock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DataBlock_ROM_NVBlockDescriptor_DataBlock; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NvM_EOLDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_EOLData_ROM_NVBlockDescriptor_EOLData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_EctConfiguration_ROM_NVBlockDescriptor_EctConfiguration; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(PwmCalibrationType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_PwmCalibration_ROM_NVBlockDescriptor; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(RtcCalibration_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RtcCalibration_ROM_NVBlockDescriptor_RtcCalibration; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

extern CONST(NV_Data_ClusterSettings, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings_ROM_NVBlockDescriptor_ClusterSettings; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_ConfigBlock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ConfigBlock_ROM_NVBlockDescriptor_ConfigBlock; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DataBlock, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DataBlock_ROM_NVBlockDescriptor_DataBlock; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NvM_EOLDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_EOLData_ROM_NVBlockDescriptor_EOLData; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(STRUCT_ECT_CONFIGURATION, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_EctConfiguration_ROM_NVBlockDescriptor_EctConfiguration; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(PwmCalibrationType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_PwmCalibration_ROM_NVBlockDescriptor; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(RtcCalibration_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_RtcCalibration_ROM_NVBlockDescriptor_RtcCalibration; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(EKeyPos, RTE_VAR_INIT) Rte_EcumExt_rpSR_rKeyPos_TIModMdl_KeyPos_KeyPos; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DataBlock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DataBlock; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_ConfigBlock, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_ConfigBlock; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_ClusterSettings, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_ClusterSettings; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(RtcCalibration_Type, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_RtcCalibration; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
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
