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
 *        Config:  Traveo2.dpa
 *   ECU-Project:  CLU
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
typedef uint8 Dlt_LogChannelNameType[4];

# define Rte_TypeDef_Dlt_MessageArgumentCount
typedef uint16 Dlt_MessageArgumentCount;

# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;

# define Rte_TypeDef_Dlt_MessageOptionsType
typedef uint8 Dlt_MessageOptionsType;

# define Rte_TypeDef_Dlt_SessionIDType
typedef uint32 Dlt_SessionIDType;

# define Rte_TypeDef_EChimeStatus
typedef uint16 EChimeStatus;

# define Rte_TypeDef_ELastToneStatus
typedef boolean ELastToneStatus;

# define Rte_TypeDef_EOL_History_Type
typedef uint8 EOL_History_Type;

# define Rte_TypeDef_ERtcAmPm
typedef uint8 ERtcAmPm;

# define Rte_TypeDef_ERtcDayOfWeek
typedef uint8 ERtcDayOfWeek;

# define Rte_TypeDef_ERtcHourMode
typedef uint8 ERtcHourMode;

# define Rte_TypeDef_ERtcMonth
typedef uint8 ERtcMonth;

# define Rte_TypeDef_ESetMenuId
typedef uint16 ESetMenuId;

# define Rte_TypeDef_IoHwAbExt_ErrorType
typedef uint8 IoHwAbExt_ErrorType;

# define Rte_TypeDef_IoHwAbExt_Lcd_Buffer
typedef uint8 IoHwAbExt_Lcd_Buffer;

# define Rte_TypeDef_Lcd_Buffer
typedef uint8 Lcd_Buffer;

# define Rte_TypeDef_NV_Magic_Flag_Table
typedef uint32 NV_Magic_Flag_Table;

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_Rte_DT_Data_TTSts_10_0
typedef uint8 Rte_DT_Data_TTSts_10_0;

# define Rte_TypeDef_Rte_DT_Dlt_ApplicationIDType_0
typedef uint8 Rte_DT_Dlt_ApplicationIDType_0;

# define Rte_TypeDef_Rte_DT_Dlt_ContextIDType_0
typedef uint8 Rte_DT_Dlt_ContextIDType_0;

# define Rte_TypeDef_Rte_DT_EOL_Mfg_Mode_Entry_Table_0
typedef uint8 Rte_DT_EOL_Mfg_Mode_Entry_Table_0;

# define Rte_TypeDef_Rte_DT_NV_CANDataBaseVersion_Table_0
typedef uint8 Rte_DT_NV_CANDataBaseVersion_Table_0;

# define Rte_TypeDef_Rte_DT_NV_ECUHardwareNumber_Table_0
typedef uint8 Rte_DT_NV_ECUHardwareNumber_Table_0;

# define Rte_TypeDef_Rte_DT_NV_FE11_Reserved_Data_Table_0
typedef uint8 Rte_DT_NV_FE11_Reserved_Data_Table_0;

# define Rte_TypeDef_Rte_DT_NV_HKMC_SW_Unit_Ver_Table_0
typedef uint8 Rte_DT_NV_HKMC_SW_Unit_Ver_Table_0;

# define Rte_TypeDef_Rte_DT_NV_HKMC_SW_Ver_Table_0
typedef uint8 Rte_DT_NV_HKMC_SW_Ver_Table_0;

# define Rte_TypeDef_Rte_DT_NV_MEETData_Reserved_Table_0
typedef uint8 Rte_DT_NV_MEETData_Reserved_Table_0;

# define Rte_TypeDef_Rte_DT_NV_ManufacturingDate_Table_0
typedef uint8 Rte_DT_NV_ManufacturingDate_Table_0;

# define Rte_TypeDef_Rte_DT_NV_Mfg_SerNo_Mfg_Date_Table_0
typedef uint8 Rte_DT_NV_Mfg_SerNo_Mfg_Date_Table_0;

# define Rte_TypeDef_Rte_DT_NV_Odo_Date_Table_0
typedef uint8 Rte_DT_NV_Odo_Date_Table_0;

# define Rte_TypeDef_Rte_DT_NV_Odo_Dealer_Id_Table_0
typedef uint8 Rte_DT_NV_Odo_Dealer_Id_Table_0;

# define Rte_TypeDef_Rte_DT_NV_PartNumber_Table_0
typedef uint8 Rte_DT_NV_PartNumber_Table_0;

# define Rte_TypeDef_Rte_DT_NV_Reset_Reason_Table_0
typedef uint8 Rte_DT_NV_Reset_Reason_Table_0;

# define Rte_TypeDef_Rte_DT_NV_SWVersion_Table_0
typedef uint8 Rte_DT_NV_SWVersion_Table_0;

# define Rte_TypeDef_Rte_DT_NV_Vehicle_Identi_No_Table_0
typedef uint8 Rte_DT_NV_Vehicle_Identi_No_Table_0;

# define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_160_0
typedef uint8 Rte_DT_Nvm_U8ArrType_160_0;

# define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_20_0
typedef uint8 Rte_DT_Nvm_U8ArrType_20_0;

# define Rte_TypeDef_Rte_DT_SegmentCtrlType_0
typedef uint8 Rte_DT_SegmentCtrlType_0;

# define Rte_TypeDef_Rte_DT_ServiceInterval_Reserved_Table_0
typedef uint8 Rte_DT_ServiceInterval_Reserved_Table_0;

# define Rte_TypeDef_Rte_DT_ServiceInterval_config_Reserved_Table_0
typedef uint8 Rte_DT_ServiceInterval_config_Reserved_Table_0;

# define Rte_TypeDef_Rte_DT_Settings_Fuel_Economy_Unit_Table_0
typedef uint8 Rte_DT_Settings_Fuel_Economy_Unit_Table_0;

# define Rte_TypeDef_Rte_DT_TFTRegStatusType_0
typedef uint8 Rte_DT_TFTRegStatusType_0;

# define Rte_TypeDef_Rte_DT_TripBase_Reserved_Table_0
typedef uint8 Rte_DT_TripBase_Reserved_Table_0;

# define Rte_TypeDef_Rte_DT_TripComputer_Reserved_Table_0
typedef uint8 Rte_DT_TripComputer_Reserved_Table_0;

# define Rte_TypeDef_Rte_DT_USM_Illumination_Table_0
typedef uint8 Rte_DT_USM_Illumination_Table_0;

# define Rte_TypeDef_Rte_DT_USM_UserSettings_Table_0
typedef uint8 Rte_DT_USM_UserSettings_Table_0;

# define Rte_TypeDef_Rte_DT_USM_Warning_Volume_Table_0
typedef uint8 Rte_DT_USM_Warning_Volume_Table_0;

# define Rte_TypeDef_Rte_DT_UserSettings_Reserved_Table_0
typedef uint8 Rte_DT_UserSettings_Reserved_Table_0;

# define Rte_TypeDef_Rte_DT_data_bool_25_0
typedef boolean Rte_DT_data_bool_25_0;

# define Rte_TypeDef_Rte_DT_data_u16_3_0
typedef uint16 Rte_DT_data_u16_3_0;

# define Rte_TypeDef_Rte_DT_data_u32_2_0
typedef uint32 Rte_DT_data_u32_2_0;

# define Rte_TypeDef_Rte_DT_data_u8_102_0
typedef uint8 Rte_DT_data_u8_102_0;

# define Rte_TypeDef_Rte_DT_data_u8_12_0
typedef uint8 Rte_DT_data_u8_12_0;

# define Rte_TypeDef_Rte_DT_data_u8_19_0
typedef uint8 Rte_DT_data_u8_19_0;

# define Rte_TypeDef_Rte_DT_data_u8_2_0
typedef uint8 Rte_DT_data_u8_2_0;

# define Rte_TypeDef_Rte_DT_data_u8_3_0
typedef uint8 Rte_DT_data_u8_3_0;

# define Rte_TypeDef_Rte_DT_data_u8_4_0
typedef uint8 Rte_DT_data_u8_4_0;

# define Rte_TypeDef_Rte_DT_data_u8_6_0
typedef uint8 Rte_DT_data_u8_6_0;

# define Rte_TypeDef_Rte_DT_data_u8_72_0
typedef uint8 Rte_DT_data_u8_72_0;

# define Rte_TypeDef_Rte_DT_data_u8_8_0
typedef uint8 Rte_DT_data_u8_8_0;

# define Rte_TypeDef_Rte_DT_data_uint8_120_0
typedef uint8 Rte_DT_data_uint8_120_0;

# define Rte_TypeDef_Rte_DT_data_uint8_129_0
typedef uint8 Rte_DT_data_uint8_129_0;

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;

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

# define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

# define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

# define Rte_TypeDef_tComSignal64
typedef uint64 tComSignal64;

# define Rte_TypeDef_uint32_Ref
typedef uint32 uint32_Ref;

# define Rte_TypeDef_uint8_Ref
typedef uint8 uint8_Ref;

# define Rte_TypeDef_AppSleepType
typedef uint8 AppSleepType;

# define Rte_TypeDef_BulbTest
typedef uint8 BulbTest;

# define Rte_TypeDef_DAW_MENU_CONFIG
typedef uint8 DAW_MENU_CONFIG;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_DemSID
typedef sint32 DemSID;

# define Rte_TypeDef_DisplayStatus
typedef uint8 DisplayStatus;

# define Rte_TypeDef_Dlt_AssignmentOperation
typedef uint8 Dlt_AssignmentOperation;

# define Rte_TypeDef_Dlt_MessageLogLevelType
typedef uint8 Dlt_MessageLogLevelType;

# define Rte_TypeDef_Dlt_MessageTraceType
typedef uint8 Dlt_MessageTraceType;

# define Rte_TypeDef_EAccStatus_t
typedef uint8 EAccStatus_t;

# define Rte_TypeDef_EAvMode_t
typedef uint8 EAvMode_t;

# define Rte_TypeDef_EButtonIDs
typedef uint8 EButtonIDs;

# define Rte_TypeDef_EButtonSts
typedef uint8 EButtonSts;

# define Rte_TypeDef_EChannel_ID
typedef uint8 EChannel_ID;

# define Rte_TypeDef_EChimeID
typedef uint8 EChimeID;

# define Rte_TypeDef_EChimeType
typedef uint8 EChimeType;

# define Rte_TypeDef_ECmpCmd
typedef uint8 ECmpCmd;

# define Rte_TypeDef_EDMSTT_t
typedef uint8 EDMSTT_t;

# define Rte_TypeDef_EDawDisplay_t
typedef uint8 EDawDisplay_t;

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

# define Rte_TypeDef_EGammaCorrectionStatus
typedef uint8 EGammaCorrectionStatus;

# define Rte_TypeDef_EGaugeUnit_t
typedef uint8 EGaugeUnit_t;

# define Rte_TypeDef_EGearATCurDctpos_t
typedef uint8 EGearATCurDctpos_t;

# define Rte_TypeDef_EGearATpos_t
typedef uint8 EGearATpos_t;

# define Rte_TypeDef_EGearBlink_t
typedef uint8 EGearBlink_t;

# define Rte_TypeDef_EGearMTEclutch_t
typedef uint8 EGearMTEclutch_t;

# define Rte_TypeDef_EGearMTpos_t
typedef uint8 EGearMTpos_t;

# define Rte_TypeDef_EGearMTtar_t
typedef uint8 EGearMTtar_t;

# define Rte_TypeDef_EGearMode_t
typedef uint8 EGearMode_t;

# define Rte_TypeDef_EIODutyInIdSafe
typedef uint8 EIODutyInIdSafe;

# define Rte_TypeDef_EIOPeriodInIdSafe
typedef uint8 EIOPeriodInIdSafe;

# define Rte_TypeDef_EIgnitionStatus_t
typedef uint8 EIgnitionStatus_t;

# define Rte_TypeDef_EIsgDisplay_t
typedef uint8 EIsgDisplay_t;

# define Rte_TypeDef_ELED_DeviceID
typedef uint8 ELED_DeviceID;

# define Rte_TypeDef_ELanguageList
typedef uint8 ELanguageList;

# define Rte_TypeDef_ELedFaultStatus
typedef uint8 ELedFaultStatus;

# define Rte_TypeDef_EMeetModeStatus
typedef uint8 EMeetModeStatus;

# define Rte_TypeDef_EMenuDisplay_t
typedef uint8 EMenuDisplay_t;

# define Rte_TypeDef_EOLConfig
typedef uint8 EOLConfig;

# define Rte_TypeDef_EOatStatus_t
typedef uint8 EOatStatus_t;

# define Rte_TypeDef_EOdoStatus_t
typedef uint8 EOdoStatus_t;

# define Rte_TypeDef_ERegionInfo_t
typedef uint8 ERegionInfo_t;

# define Rte_TypeDef_ERsbrSeat_t
typedef uint8 ERsbrSeat_t;

# define Rte_TypeDef_ESetMenuSts
typedef uint8 ESetMenuSts;

# define Rte_TypeDef_ESndChnStat
typedef uint8 ESndChnStat;

# define Rte_TypeDef_ESndInterruptType
typedef uint8 ESndInterruptType;

# define Rte_TypeDef_ESnd_InterruptType
typedef uint8 ESnd_InterruptType;

# define Rte_TypeDef_ETbtCombinedStreet
typedef uint8 ETbtCombinedStreet;

# define Rte_TypeDef_ETbtDestinationFlag
typedef uint8 ETbtDestinationFlag;

# define Rte_TypeDef_ETbtDistanceUnit
typedef uint8 ETbtDistanceUnit;

# define Rte_TypeDef_ETbtETAformat
typedef uint8 ETbtETAformat;

# define Rte_TypeDef_ETbtEstimationTimeType
typedef uint8 ETbtEstimationTimeType;

# define Rte_TypeDef_ETbtLaneType
typedef uint8 ETbtLaneType;

# define Rte_TypeDef_ETbtPathDirection
typedef uint8 ETbtPathDirection;

# define Rte_TypeDef_EThemeSel_t
typedef uint8 EThemeSel_t;

# define Rte_TypeDef_ETripCmd
typedef uint8 ETripCmd;

# define Rte_TypeDef_ETtIndex
typedef uint8 ETtIndex;

# define Rte_TypeDef_ETtStatus
typedef uint8 ETtStatus;

# define Rte_TypeDef_EVariantConfig_t
typedef uint8 EVariantConfig_t;

# define Rte_TypeDef_EWarningMessage_t
typedef uint8 EWarningMessage_t;

# define Rte_TypeDef_FuelEcoDisplay
typedef uint8 FuelEcoDisplay;

# define Rte_TypeDef_FuelEcoUnit
typedef uint8 FuelEcoUnit;

# define Rte_TypeDef_Fuel_type
typedef uint8 Fuel_type;

# define Rte_TypeDef_GaugeSweep
typedef uint8 GaugeSweep;

# define Rte_TypeDef_HMI_Current_Status
typedef uint8 HMI_Current_Status;

# define Rte_TypeDef_HTimer
typedef uint8 HTimer;

# define Rte_TypeDef_Init_status
typedef uint8 Init_status;

# define Rte_TypeDef_IoHwAbExt_LEDChannelType
typedef uint8 IoHwAbExt_LEDChannelType;

# define Rte_TypeDef_IoHwAbExt_LEDGroupType
typedef uint8 IoHwAbExt_LEDGroupType;

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

# define Rte_TypeDef_NTDriveModes
typedef uint8 NTDriveModes;

# define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# define Rte_TypeDef_PwmChannel
typedef uint8 PwmChannel;

# define Rte_TypeDef_SleepSource
typedef uint8 SleepSource;

# define Rte_TypeDef_SmSafeStateIndex
typedef uint8 SmSafeStateIndex;

# define Rte_TypeDef_SpeedInputType
typedef uint8 SpeedInputType;

# define Rte_TypeDef_Speedo_type
typedef uint8 Speedo_type;

# define Rte_TypeDef_SpeedometerUnit
typedef uint8 SpeedometerUnit;

# define Rte_TypeDef_SystemStatusType
typedef uint8 SystemStatusType;

# define Rte_TypeDef_SystemType
typedef uint8 SystemType;

# define Rte_TypeDef_USMConfig
typedef uint8 USMConfig;

# define Rte_TypeDef_VehicleStateType
typedef uint8 VehicleStateType;

# define Rte_TypeDef_WARN_MSG_EVENT_T
typedef uint8 WARN_MSG_EVENT_T;

# define Rte_TypeDef_WARN_MSG_STATE_T
typedef uint8 WARN_MSG_STATE_T;

# define Rte_TypeDef_WARN_MSG_STATUS_T
typedef uint8 WARN_MSG_STATUS_T;

# define Rte_TypeDef_eAfeID
typedef uint8 eAfeID;

# define Rte_TypeDef_eAvsID
typedef uint8 eAvsID;

# define Rte_TypeDef_eBatteryState
typedef uint8 eBatteryState;

# define Rte_TypeDef_eBtnType
typedef uint8 eBtnType;

# define Rte_TypeDef_eDriveTimeID
typedef uint8 eDriveTimeID;

# define Rte_TypeDef_eEtmTTState
typedef uint8 eEtmTTState;

# define Rte_TypeDef_eExecutionState
typedef uint8 eExecutionState;

# define Rte_TypeDef_eIOPulseInputId
typedef sint32 eIOPulseInputId;

# define Rte_TypeDef_eIceWarnStsType
typedef uint8 eIceWarnStsType;

# define Rte_TypeDef_eIgnState
typedef uint8 eIgnState;

# define Rte_TypeDef_eOatUnit
typedef uint8 eOatUnit;

# define Rte_TypeDef_eOdoUnit
typedef uint8 eOdoUnit;

# define Rte_TypeDef_eSafeTellTalelist
typedef uint8 eSafeTellTalelist;

# define Rte_TypeDef_eTellTaleSts
typedef uint8 eTellTaleSts;

# define Rte_TypeDef_eTimerSafeID
typedef uint8 eTimerSafeID;

# define Rte_TypeDef_eTripID
typedef uint8 eTripID;

# define Rte_TypeDef_eUclEndToEnd_type
typedef uint8 eUclEndToEnd_type;

# define Rte_TypeDef_tDiagSessionSt
typedef uint8 tDiagSessionSt;

# define Rte_TypeDef_tRxSafeSignalId
typedef uint8 tRxSafeSignalId;

# define Rte_TypeDef_tRxSafeSignalJustRcvdStatus
typedef uint8 tRxSafeSignalJustRcvdStatus;

# define Rte_TypeDef_tRxSafeSignalStatus
typedef uint8 tRxSafeSignalStatus;

# define Rte_TypeDef_tRxSignalId
typedef uint16 tRxSignalId;

# define Rte_TypeDef_tRxSignalJustRcvdStatus
typedef uint8 tRxSignalJustRcvdStatus;

# define Rte_TypeDef_tRxSignalStatus
typedef uint8 tRxSignalStatus;

# define Rte_TypeDef_tTxSafeSignalId
typedef uint8 tTxSafeSignalId;

# define Rte_TypeDef_tTxSigConfirmStatus
typedef uint8 tTxSigConfirmStatus;

# define Rte_TypeDef_tTxSigSafeConfirmStatus
typedef uint8 tTxSigSafeConfirmStatus;

# define Rte_TypeDef_tTxSignalId
typedef uint16 tTxSignalId;

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

# define Rte_TypeDef_Data_TTSts_10
typedef Rte_DT_Data_TTSts_10_0 Data_TTSts_10[10];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[1];

# define Rte_TypeDef_Dlt_ApplicationIDType
typedef Rte_DT_Dlt_ApplicationIDType_0 Dlt_ApplicationIDType[4];

# define Rte_TypeDef_Dlt_ContextIDType
typedef Rte_DT_Dlt_ContextIDType_0 Dlt_ContextIDType[4];

# define Rte_TypeDef_EOL_Mfg_Mode_Entry_Table
typedef Rte_DT_EOL_Mfg_Mode_Entry_Table_0 EOL_Mfg_Mode_Entry_Table[2];

# define Rte_TypeDef_ETbtDistanceUnit_2
typedef ETbtDistanceUnit ETbtDistanceUnit_2[2];

# define Rte_TypeDef_NV_CANDataBaseVersion_Table
typedef Rte_DT_NV_CANDataBaseVersion_Table_0 NV_CANDataBaseVersion_Table[3];

# define Rte_TypeDef_NV_ECUHardwareNumber_Table
typedef Rte_DT_NV_ECUHardwareNumber_Table_0 NV_ECUHardwareNumber_Table[3];

# define Rte_TypeDef_NV_FE11_Reserved_Data_Table
typedef Rte_DT_NV_FE11_Reserved_Data_Table_0 NV_FE11_Reserved_Data_Table[32];

# define Rte_TypeDef_NV_HKMC_SW_Unit_Ver_Table
typedef Rte_DT_NV_HKMC_SW_Unit_Ver_Table_0 NV_HKMC_SW_Unit_Ver_Table[33];

# define Rte_TypeDef_NV_HKMC_SW_Ver_Table
typedef Rte_DT_NV_HKMC_SW_Ver_Table_0 NV_HKMC_SW_Ver_Table[33];

# define Rte_TypeDef_NV_MEETData_Reserved_Table
typedef Rte_DT_NV_MEETData_Reserved_Table_0 NV_MEETData_Reserved_Table[40];

# define Rte_TypeDef_NV_ManufacturingDate_Table
typedef Rte_DT_NV_ManufacturingDate_Table_0 NV_ManufacturingDate_Table[4];

# define Rte_TypeDef_NV_Mfg_SerNo_Mfg_Date_Table
typedef Rte_DT_NV_Mfg_SerNo_Mfg_Date_Table_0 NV_Mfg_SerNo_Mfg_Date_Table[19];

# define Rte_TypeDef_NV_Odo_Date_Table
typedef Rte_DT_NV_Odo_Date_Table_0 NV_Odo_Date_Table[4];

# define Rte_TypeDef_NV_Odo_Dealer_Id_Table
typedef Rte_DT_NV_Odo_Dealer_Id_Table_0 NV_Odo_Dealer_Id_Table[5];

# define Rte_TypeDef_NV_PartNumber_Table
typedef Rte_DT_NV_PartNumber_Table_0 NV_PartNumber_Table[10];

# define Rte_TypeDef_NV_Reset_Reason_Table
typedef Rte_DT_NV_Reset_Reason_Table_0 NV_Reset_Reason_Table[128];

# define Rte_TypeDef_NV_SWVersion_Table
typedef Rte_DT_NV_SWVersion_Table_0 NV_SWVersion_Table[3];

# define Rte_TypeDef_NV_Vehicle_Identi_No_Table
typedef Rte_DT_NV_Vehicle_Identi_No_Table_0 NV_Vehicle_Identi_No_Table[17];

# define Rte_TypeDef_Nvm_U8ArrType_160
typedef Rte_DT_Nvm_U8ArrType_160_0 Nvm_U8ArrType_160[160];

# define Rte_TypeDef_Nvm_U8ArrType_20
typedef Rte_DT_Nvm_U8ArrType_20_0 Nvm_U8ArrType_20[20];

# define Rte_TypeDef_SegmentCtrlType
typedef Rte_DT_SegmentCtrlType_0 SegmentCtrlType[15];

# define Rte_TypeDef_ServiceInterval_Reserved_Table
typedef Rte_DT_ServiceInterval_Reserved_Table_0 ServiceInterval_Reserved_Table[4];

# define Rte_TypeDef_ServiceInterval_config_Reserved_Table
typedef Rte_DT_ServiceInterval_config_Reserved_Table_0 ServiceInterval_config_Reserved_Table[6];

# define Rte_TypeDef_Settings_Fuel_Economy_Unit_Table
typedef Rte_DT_Settings_Fuel_Economy_Unit_Table_0 Settings_Fuel_Economy_Unit_Table[4];

# define Rte_TypeDef_TFTRegStatusType
typedef Rte_DT_TFTRegStatusType_0 TFTRegStatusType[2];

# define Rte_TypeDef_TripBase_Reserved_Table
typedef Rte_DT_TripBase_Reserved_Table_0 TripBase_Reserved_Table[8];

# define Rte_TypeDef_TripComputer_Reserved_Table
typedef Rte_DT_TripComputer_Reserved_Table_0 TripComputer_Reserved_Table[14];

# define Rte_TypeDef_USM_Illumination_Table
typedef Rte_DT_USM_Illumination_Table_0 USM_Illumination_Table[4];

# define Rte_TypeDef_USM_UserSettings_Table
typedef Rte_DT_USM_UserSettings_Table_0 USM_UserSettings_Table[4];

# define Rte_TypeDef_USM_Warning_Volume_Table
typedef Rte_DT_USM_Warning_Volume_Table_0 USM_Warning_Volume_Table[4];

# define Rte_TypeDef_UserSettings_Reserved_Table
typedef Rte_DT_UserSettings_Reserved_Table_0 UserSettings_Reserved_Table[22];

# define Rte_TypeDef_data_bool_25
typedef Rte_DT_data_bool_25_0 data_bool_25[25];

# define Rte_TypeDef_data_u16_3
typedef Rte_DT_data_u16_3_0 data_u16_3[3];

# define Rte_TypeDef_data_u32_2
typedef Rte_DT_data_u32_2_0 data_u32_2[2];

# define Rte_TypeDef_data_u8_102
typedef Rte_DT_data_u8_102_0 data_u8_102[102];

# define Rte_TypeDef_data_u8_12
typedef Rte_DT_data_u8_12_0 data_u8_12[12];

# define Rte_TypeDef_data_u8_19
typedef Rte_DT_data_u8_19_0 data_u8_19[19];

# define Rte_TypeDef_data_u8_2
typedef Rte_DT_data_u8_2_0 data_u8_2[2];

# define Rte_TypeDef_data_u8_3
typedef Rte_DT_data_u8_3_0 data_u8_3[3];

# define Rte_TypeDef_data_u8_4
typedef Rte_DT_data_u8_4_0 data_u8_4[4];

# define Rte_TypeDef_data_u8_6
typedef Rte_DT_data_u8_6_0 data_u8_6[6];

# define Rte_TypeDef_data_u8_72
typedef Rte_DT_data_u8_72_0 data_u8_72[72];

# define Rte_TypeDef_data_u8_8
typedef Rte_DT_data_u8_8_0 data_u8_8[8];

# define Rte_TypeDef_data_uint8_120
typedef Rte_DT_data_uint8_120_0 data_uint8_120[120];

# define Rte_TypeDef_data_uint8_129
typedef Rte_DT_data_uint8_129_0 data_uint8_129[129];

# define Rte_TypeDef_CLAG_AFE1_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Distance1;
  UInt32 Accum_Fuel1;
} CLAG_AFE1_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_AFE1_INSTANT_DATA
typedef struct
{
  UInt32 Instant_Fuel1;
  UInt32 Instant_Distance1;
} CLAG_AFE1_INSTANT_DATA;

# define Rte_TypeDef_CLAG_AFE1_OUTPUT
typedef struct
{
  UInt32 AFE1_Value;
  Boolean AFE1_Error;
} CLAG_AFE1_OUTPUT;

# define Rte_TypeDef_CLAG_AFE2_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Distance2;
  UInt32 Accum_Fuel2;
} CLAG_AFE2_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_AFE2_INSTANT_DATA
typedef struct
{
  UInt32 Instant_Fuel2;
  UInt32 Instant_Distance2;
} CLAG_AFE2_INSTANT_DATA;

# define Rte_TypeDef_CLAG_AFE2_OUTPUT
typedef struct
{
  UInt32 AFE2_Value;
  Boolean AFE2_Error;
} CLAG_AFE2_OUTPUT;

# define Rte_TypeDef_CLAG_AFE3_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Distance3;
  UInt32 Accum_Fuel3;
} CLAG_AFE3_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_AFE3_INSTANT_DATA
typedef struct
{
  UInt32 Instant_Fuel3;
  UInt32 Instant_Distance3;
} CLAG_AFE3_INSTANT_DATA;

# define Rte_TypeDef_CLAG_AFE3_OUTPUT
typedef struct
{
  UInt32 AFE3_Value;
  Boolean AFE3_Error;
} CLAG_AFE3_OUTPUT;

# define Rte_TypeDef_CLAG_AFE4_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Distance4;
  UInt32 Accum_Fuel4;
} CLAG_AFE4_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_AFE4_INSTANT_DATA
typedef struct
{
  UInt32 Instant_Fuel4;
  UInt32 Instant_Distance4;
} CLAG_AFE4_INSTANT_DATA;

# define Rte_TypeDef_CLAG_AFE4_OUTPUT
typedef struct
{
  UInt32 AFE4_Value;
  Boolean AFE4_Error;
} CLAG_AFE4_OUTPUT;

# define Rte_TypeDef_CLAG_AFE_RESET_INFO
typedef struct
{
  Boolean Reset_AFE1;
  Boolean Reset_AFE2;
  Boolean Reset_AFE3;
  Boolean Reset_AFE4;
} CLAG_AFE_RESET_INFO;

# define Rte_TypeDef_CLAG_AVS1_ACCUMULATED_DATA
typedef struct
{
  UInt32 Instant_Distance1;
  UInt32 Instant_Time1;
} CLAG_AVS1_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_AVS1_INSTANT_DATA
typedef struct
{
  UInt32 Instant_AVS1_Speed;
  UInt32 Instant_AVS1_Time;
} CLAG_AVS1_INSTANT_DATA;

# define Rte_TypeDef_CLAG_AVS1_OUTPUT
typedef struct
{
  UInt32 AVS1_Value;
  Boolean AVS1_Error;
} CLAG_AVS1_OUTPUT;

# define Rte_TypeDef_CLAG_AVS2_ACCUMULATED_DATA
typedef struct
{
  UInt32 Instant_Distance2;
  UInt32 Instant_Time2;
} CLAG_AVS2_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_AVS2_INSTANT_DATA
typedef struct
{
  UInt32 Instant_AVS2_Speed;
  UInt32 Instant_AVS2_Time;
} CLAG_AVS2_INSTANT_DATA;

# define Rte_TypeDef_CLAG_AVS2_OUTPUT
typedef struct
{
  UInt32 AVS2_Value;
  Boolean AVS2_Error;
} CLAG_AVS2_OUTPUT;

# define Rte_TypeDef_CLAG_AVS3_ACCUMULATED_DATA
typedef struct
{
  UInt32 Instant_Distance3;
  UInt32 Instant_Time3;
} CLAG_AVS3_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_AVS3_INSTANT_DATA
typedef struct
{
  UInt32 Instant_AVS3_Speed;
  UInt32 Instant_AVS3_Time;
} CLAG_AVS3_INSTANT_DATA;

# define Rte_TypeDef_CLAG_AVS3_OUTPUT
typedef struct
{
  UInt32 AVS3_Value;
  Boolean AVS3_Error;
} CLAG_AVS3_OUTPUT;

# define Rte_TypeDef_CLAG_AVS_RESET_INFO
typedef struct
{
  Boolean Reset_AVS1;
  Boolean Reset_AVS3;
  Boolean Reset_AVS2;
} CLAG_AVS_RESET_INFO;

# define Rte_TypeDef_CLAG_DT1_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Hour1;
  UInt8 Accum_Min1;
  UInt8 Accum_Sec1;
} CLAG_DT1_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_DT1_INIT_DATA
typedef struct
{
  UInt32 Accum_Hour1;
  UInt8 Accum_Min1;
  UInt8 Accum_Sec1;
} CLAG_DT1_INIT_DATA;

# define Rte_TypeDef_CLAG_DT2_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Hour2;
  UInt8 Accum_Min2;
  UInt8 Accum_Sec2;
} CLAG_DT2_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_DT2_INIT_DATA
typedef struct
{
  UInt32 Accum_Hour2;
  UInt8 Accum_Min2;
  UInt8 Accum_Sec2;
} CLAG_DT2_INIT_DATA;

# define Rte_TypeDef_CLAG_DT3_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Hour3;
  UInt8 Accum_Min3;
  UInt8 Accum_Sec3;
} CLAG_DT3_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_DT3_INIT_DATA
typedef struct
{
  UInt32 Accum_Hour3;
  UInt8 Accum_Min3;
  UInt8 Accum_Sec3;
} CLAG_DT3_INIT_DATA;

# define Rte_TypeDef_CLAG_DT4_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Hour4;
  UInt8 Accum_Min4;
  UInt8 Accum_Sec4;
} CLAG_DT4_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_DT4_INIT_DATA
typedef struct
{
  UInt32 Accum_Hour4;
  UInt8 Accum_Min4;
  UInt8 Accum_Sec4;
} CLAG_DT4_INIT_DATA;

# define Rte_TypeDef_CLAG_DT5_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Hour5;
  UInt8 Accum_Min5;
  UInt8 Accum_Sec5;
} CLAG_DT5_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_DT5_INIT_DATA
typedef struct
{
  UInt32 Accum_Hour5;
  UInt8 Accum_Min5;
  UInt8 Accum_Sec5;
} CLAG_DT5_INIT_DATA;

# define Rte_TypeDef_CLAG_DT6_ACCUMULATED_DATA
typedef struct
{
  UInt32 Accum_Hour6;
  UInt8 Accum_Min6;
  UInt8 Accum_Sec6;
} CLAG_DT6_ACCUMULATED_DATA;

# define Rte_TypeDef_CLAG_DT6_INIT_DATA
typedef struct
{
  UInt32 Accum_Hour6;
  UInt8 Accum_Min6;
  UInt8 Accum_Sec6;
} CLAG_DT6_INIT_DATA;

# define Rte_TypeDef_CLAG_DTE_INSTANT_DATA
typedef struct
{
  UInt32 Instant_Fuel;
  UInt32 Instant_Distance;
  UInt16 Tank_Fuel_Level;
  UInt16 Raw_Vehicle_Speed;
  Boolean Fuel_Sensor_Status;
  Boolean Fuel_Refill_Status;
  Boolean Fuel_Inline_Status;
} CLAG_DTE_INSTANT_DATA;

# define Rte_TypeDef_CLAG_DT_INSTANT_DATA
typedef struct
{
  UInt32 Instant_Time1;
  UInt32 Instant_Time2;
  UInt32 Instant_Time3;
  UInt32 Instant_Time4;
  UInt32 Instant_Time5;
  UInt32 Instant_Time6;
} CLAG_DT_INSTANT_DATA;

# define Rte_TypeDef_CLAG_DT_RESET_INFO
typedef struct
{
  Boolean Reset_DT1;
  Boolean Reset_DT4;
  Boolean Reset_DT3;
  Boolean Reset_DT2;
  Boolean Reset_DT5;
  Boolean Reset_DT6;
} CLAG_DT_RESET_INFO;

# define Rte_TypeDef_CLAG_IFE_CALCULATED_DATA
typedef struct
{
  UInt32 IFE_Data;
  Boolean IFE_Error;
} CLAG_IFE_CALCULATED_DATA;

# define Rte_TypeDef_CLAG_IFE_INSTANT_DATA
typedef struct
{
  UInt32 Instant_IFE_Distance;
  UInt32 Instant_IFE_Fuel;
} CLAG_IFE_INSTANT_DATA;

# define Rte_TypeDef_NV_Data_Customer_EOLConfig
typedef struct
{
  UInt8 NVM_Customer_EOL_Byte1;
  UInt8 NVM_Customer_EOL_Byte2;
  UInt8 NVM_Customer_EOL_Byte3;
  UInt8 NVM_Customer_EOL_Byte4;
  UInt8 NVM_Customer_EOL_Byte5_reserved;
  UInt8 NVM_Customer_EOL_Byte6_reserved;
  UInt8 NVM_Customer_EOL_Byte7_reserved;
  UInt8 NVM_Customer_EOL_Byte8_reserved;
} NV_Data_Customer_EOLConfig;

# define Rte_TypeDef_NV_Data_FBLGip_Checker
typedef struct
{
  UInt8 ECUCompatibilityDTCStateAddress;
} NV_Data_FBLGip_Checker;

# define Rte_TypeDef_NV_Data_FBLVip_Checker
typedef struct
{
  UInt8 FBLValidDTCStateAddress;
} NV_Data_FBLVip_Checker;

# define Rte_TypeDef_NV_Data_FblSecurityDelay
typedef struct
{
  UInt8 SecurityDelayTime;
} NV_Data_FblSecurityDelay;

# define Rte_TypeDef_NV_Data_FblSecurityFail
typedef struct
{
  UInt8 SecurityFailCount;
} NV_Data_FblSecurityFail;

# define Rte_TypeDef_NV_Data_MagicFlag
typedef struct
{
  NV_Magic_Flag_Table BootMagicFlag_0;
} NV_Data_MagicFlag;

# define Rte_TypeDef_NV_Data_OdometerBLK1
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value1;
} NV_Data_OdometerBLK1;

# define Rte_TypeDef_NV_Data_OdometerBLK2
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value2;
} NV_Data_OdometerBLK2;

# define Rte_TypeDef_NV_Data_OdometerBLK3
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value3;
} NV_Data_OdometerBLK3;

# define Rte_TypeDef_NV_Data_OdometerBLK4
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value4;
} NV_Data_OdometerBLK4;

# define Rte_TypeDef_NV_Data_OdometerBLK5
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value5;
} NV_Data_OdometerBLK5;

# define Rte_TypeDef_NV_Data_Visteon_EOLConfig
typedef struct
{
  UInt8 NVM_Visteon_EOL_Byte1;
  UInt8 NVM_Visteon_EOL_Byte2;
  UInt8 NVM_Visteon_EOL_Byte3;
  UInt8 NVM_Visteon_EOL_Byte4;
  UInt8 NVM_Visteon_EOL_Byte5;
  UInt8 NVM_Visteon_EOL_Byte6;
  UInt8 NVM_Visteon_EOL_Byte7_reserved;
  UInt8 NVM_Visteon_EOL_Byte8_reserved;
} NV_Data_Visteon_EOLConfig;

# define Rte_TypeDef_Rtc_AlarmType
typedef struct
{
  uint8_Ref Date;
  ERtcMonth Month;
  UInt8 hours;
  UInt8 Second;
  UInt8 Second_En;
  UInt8 Minute_En;
  UInt8 Hour;
  UInt8 Hour_En;
  ERtcDayOfWeek DayOfWeek;
  UInt8 DayOfWeek_En;
  UInt8 Date_En;
  UInt8 Month_En;
  UInt8 Alarm_En;
  UInt8 Minute;
} Rtc_AlarmType;

# define Rte_TypeDef_Rtc_DateType
typedef struct
{
  UInt8 Date;
  ERtcMonth Month;
  UInt8 Year;
} Rtc_DateType;

# define Rte_TypeDef_Rtc_PeriodicAlarmType
typedef struct
{
  UInt8 PeriodicAlaram;
} Rtc_PeriodicAlarmType;

# define Rte_TypeDef_Rtc_TimeType
typedef struct
{
  UInt8 Hour;
  UInt8 Minute;
  UInt8 Second;
  ERtcAmPm AmPm;
  ERtcHourMode HourMode;
  ERtcDayOfWeek DayOfWeek;
} Rtc_TimeType;

# define Rte_TypeDef_SBcaMenu
typedef struct
{
  UInt8 BcaMenuAvailable;
  UInt8 BcaDisplayType;
} SBcaMenu;

# define Rte_TypeDef_SCruiseSpeedLimiter
typedef struct
{
  UInt8 DisplayType;
  UInt8 SpeedValue;
  UInt8 SpeedUnit;
  UInt8 BlinkStatus;
} SCruiseSpeedLimiter;

# define Rte_TypeDef_SDIS
typedef struct
{
  UInt8 DisEnabled;
  UInt8 DisArea;
  UInt8 DisIconType;
  UInt8 DisIconSel;
  UInt8 DisSpeedVal;
} SDIS;

# define Rte_TypeDef_SDTE
typedef struct
{
  UInt16 value;
  UInt8 unit;
  Boolean status;
} SDTE;

# define Rte_TypeDef_SDawInfo
typedef struct
{
  EDawDisplay_t DawDisplayType;
} SDawInfo;

# define Rte_TypeDef_SFcaBcaWarn
typedef struct
{
  UInt8 FcaWarnAvailable;
  UInt8 FcaWarnPayload;
  UInt8 BcaWarnAvailable_P10070;
  UInt8 BcaWarnPayload_P10070;
  UInt8 BcaWarnAvailable_P10080;
  UInt8 BcaWarnPayload_P10080;
} SFcaBcaWarn;

# define Rte_TypeDef_SGaugeBarLvl
typedef struct
{
  UInt8 input_count;
  UInt8 previous_input;
  UInt8 previous_segment;
  UInt8 table_type;
} SGaugeBarLvl;

# define Rte_TypeDef_SGaugeInfo
typedef struct
{
  UInt8 id;
  UInt16 position;
  SInt32 digitalData;
  EGaugeUnit_t unit;
  UInt16 dynData;
} SGaugeInfo;

# define Rte_TypeDef_SGearInfo
typedef struct
{
  EGearMode_t gearMode;
  EGearATpos_t ATGgearPosition;
  EGearATCurDctpos_t ATCurDctGearPosition;
  EGearMTpos_t MTGearPosition;
  EGearMTtar_t MTTargetGearStatus;
  EGearMTEclutch_t MTEclutchGearPosition;
  EGearBlink_t gearBlinkStatus;
} SGearInfo;

# define Rte_TypeDef_SHeaderScc
typedef struct
{
  UInt8 HdrSccTargetVehicle;
  UInt8 HdrSccDisplayType;
  UInt8 HdrSccSpeedUnit;
  UInt8 HdrSccSpeedValue;
  UInt8 HdrSccTargetDistance;
  UInt8 HdrSccHdaDisplayType;
} SHeaderScc;

# define Rte_TypeDef_SHelpPopupSts
typedef struct
{
  Boolean HelpPopupSts;
  UInt16 HelpPopupId;
} SHelpPopupSts;

# define Rte_TypeDef_SIG_WIN_CRC_RGB_T
typedef struct
{
  UInt32 crc_r;
  UInt32 crc_g;
  UInt32 crc_b;
} SIG_WIN_CRC_RGB_T;

# define Rte_TypeDef_SIG_WIN_INFO_T
typedef struct
{
  UInt8 sig_unit;
  UInt8 window;
} SIG_WIN_INFO_T;

# define Rte_TypeDef_SIG_WIN_SETUP_T
typedef struct
{
  UInt32 control;
  UInt16 winsx;
  UInt16 winsy;
  UInt16 winex;
  UInt16 winey;
  UInt32 crc_ref_r;
  UInt32 crc_ref_g;
  UInt32 crc_ref_b;
} SIG_WIN_SETUP_T;

# define Rte_TypeDef_SIgnState
typedef struct
{
  EIgnitionStatus_t state;
} SIgnState;

# define Rte_TypeDef_SInfoWarningList
typedef struct
{
  EWarningMessage_t WarningID;
  UInt8 WarningPayload;
} SInfoWarningList;

# define Rte_TypeDef_SIsgInfo
typedef struct
{
  EIsgDisplay_t IsgDisplayType;
  UInt8 IsgHour;
  UInt8 IsgMin;
  UInt8 IsgSec;
  Boolean IsgMenuSts;
} SIsgInfo;

# define Rte_TypeDef_SLanguageInfo
typedef struct
{
  UInt8 LanguageInfo;
} SLanguageInfo;

# define Rte_TypeDef_SLfaMenu
typedef struct
{
  UInt8 LfaMenuAvailable;
  UInt8 LfaDisplayType;
} SLfaMenu;

# define Rte_TypeDef_SLkaMenu
typedef struct
{
  UInt8 LkaMenuAvailable;
  UInt8 LkaDisplayType;
  UInt8 LkaMenuLeftLane;
  UInt8 LkaMenuRightLane;
} SLkaMenu;

# define Rte_TypeDef_SMenuCmd
typedef struct
{
  ESetMenuId MenuId_e;
  EButtonIDs ButtonType_e;
  EButtonSts ButtonStatus_e;
  UInt32 MenuValue_u32;
} SMenuCmd;

# define Rte_TypeDef_SMenuGipInfo
typedef struct
{
  ESetMenuId MenuId_e;
  EButtonIDs ButtonType_e;
  EButtonSts ButtonStatus_e;
  UInt32 MenuValue_u32;
  UInt8 MenuValueId_u8;
} SMenuGipInfo;

# define Rte_TypeDef_SMenuStatus
typedef struct
{
  EMenuDisplay_t MenuStatus;
} SMenuStatus;

# define Rte_TypeDef_SMenuSts
typedef struct
{
  ESetMenuId MenuId_e;
  ESetMenuSts MenuStatus_e;
} SMenuSts;

# define Rte_TypeDef_SMenuStsU16Val
typedef struct
{
  ESetMenuId MenuId_e;
  ESetMenuSts MenuStatus_e;
  UInt16 MenuValue_u16;
} SMenuStsU16Val;

# define Rte_TypeDef_SMenuStsU32Val
typedef struct
{
  ESetMenuId MenuId_e;
  ESetMenuSts MenuStatus_e;
  UInt32 MenuValue_u32;
} SMenuStsU32Val;

# define Rte_TypeDef_SMenuStsU8Val
typedef struct
{
  ESetMenuId MenuId_e;
  ESetMenuSts MenuStatus_e;
  UInt8 MenuValue_u8;
} SMenuStsU8Val;

# define Rte_TypeDef_SMenuVipInfo
typedef struct
{
  UInt8 MenuStatusID;
  UInt8 MenuValueID;
  uint8_Ref MenuStatus;
  uint32_Ref MenuValue;
} SMenuVipInfo;

# define Rte_TypeDef_SMiniPopupDisplay
typedef struct
{
  UInt8 show;
  EWarningMessage_t popupId;
  UInt8 dynData;
} SMiniPopupDisplay;

# define Rte_TypeDef_SOAT
typedef struct
{
  UInt16 value;
  UInt8 icon;
  EGaugeUnit_t unit;
  EOatStatus_t status;
} SOAT;

# define Rte_TypeDef_SOdometer
typedef struct
{
  EOdoStatus_t status;
  UInt32 value;
  UInt8 unit;
} SOdometer;

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

# define Rte_TypeDef_SSWC
typedef struct
{
  EButtonIDs buttonId;
  EButtonSts buttonStatus;
  UInt8 holdTime;
} SSWC;

# define Rte_TypeDef_SSccMenu
typedef struct
{
  UInt8 SccMenuAvailable;
  UInt8 SccDisplayType;
  UInt16 SccTargetVehPos;
  UInt8 SccTargetVehType;
  UInt8 SccTargetDisType;
  UInt16 SccTargetDist;
} SSccMenu;

# define Rte_TypeDef_SSndCddChimeData
typedef struct
{
  UInt8 ChannelId;
  EChimeType ChimeType;
  UInt16 DynamicDeadTime;
} SSndCddChimeData;

# define Rte_TypeDef_SSpeedCalcParam
typedef struct
{
  UInt32 Pulses_Per_Revolution;
  UInt32 Revolutions_Per_Unit;
  UInt32 Tuning_Factor;
} SSpeedCalcParam;

# define Rte_TypeDef_STbtDestInfo
typedef struct
{
  UInt32 DestinationDistance;
  ETbtDistanceUnit DistanceUnit;
  ETbtDestinationFlag DestinationFlag;
  ETbtEstimationTimeType EstimationTimeType;
  ETbtETAformat ETA_format;
  UInt8 ETA_hours;
  UInt8 ETA_minutes;
  UInt8 RemTimeHours;
  UInt8 RemTimeMinutes;
} STbtDestInfo;

# define Rte_TypeDef_STbtLaneInfo
typedef struct
{
  ETbtLaneType LaneType;
  Boolean BottomIconAvailable;
  UInt8 BottomIcon;
  Boolean MidIconAvailable;
  UInt8 MidIcon;
  Boolean TopIconAvailable;
  UInt8 TopIcon;
  Boolean OverpassEnable;
  Boolean UnderpassEnable;
  UInt8 HiPassLaneNumber;
  UInt8 HiPassNonHiPassDisplayType;
} STbtLaneInfo;

# define Rte_TypeDef_SThemeInfo
typedef struct
{
  EThemeSel_t ThemeInfo;
} SThemeInfo;

# define Rte_TypeDef_SThemeStatus
typedef struct
{
  EThemeSel_t ThemeStatus;
} SThemeStatus;

# define Rte_TypeDef_STripFuelEcoInfo
typedef struct
{
  UInt32 accumulatedDistance;
  UInt32 accumulatedHours;
  UInt8 accumulatedMinutes;
  UInt16 accumulatedAfe;
  UInt16 accumulatedAvs;
  UInt32 driveDistance;
  UInt32 driveHours;
  UInt8 driveMinutes;
  UInt16 driveAfe;
  UInt16 driveAvs;
  UInt32 afterRefuelDistance;
  UInt32 afterRefuelHours;
  UInt8 afterRefuelMinutes;
  UInt16 afterRefuelAfe;
  UInt16 afterRefuelAvs;
  UInt16 AfeFooter;
  UInt8 IfeScale;
  UInt16 IfeFooter;
  UInt8 distanceUnit;
  UInt8 IfeUnit;
  UInt8 iconsVisible;
  UInt8 AvsEnableSts;
  UInt8 FuelType;
  UInt8 Page_display_Sts;
} STripFuelEcoInfo;

# define Rte_TypeDef_STripResetCmd
typedef struct
{
  UInt16 tripCmdId;
} STripResetCmd;

# define Rte_TypeDef_SUreaLvlInfo
typedef struct
{
  UInt8 UreaLevelSteps;
  UInt8 UreaLevelType;
  Boolean UreaMenuSts;
} SUreaLvlInfo;

# define Rte_TypeDef_SUsmMenuInfo
typedef struct
{
  Boolean UsmMenuStatus;
  Boolean HelpCueStatus;
  UInt8 SmartTrunk_Tail;
  UInt8 WelMirLig;
  UInt8 OnkeyVehicleoff;
} SUsmMenuInfo;

# define Rte_TypeDef_WARN_MSG_DATA_TS
typedef struct
{
  WARN_MSG_STATUS_T status;
  WARN_MSG_EVENT_T event;
  UInt16 payload;
} WARN_MSG_DATA_TS;

# define Rte_TypeDef_WARN_MSG_INFO_DATA_TS
typedef struct
{
  WARN_MSG_STATUS_T p_warning_id;
  UInt8 payload;
} WARN_MSG_INFO_DATA_TS;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint8 ComM_UserHandleType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef UInt8 Dcm_RequestKindType;

# define Rte_TypeDef_Dcm_SecLevelType
typedef UInt8 Dcm_SecLevelType;

# define Rte_TypeDef_Dem_DTCGroupType
typedef uint32 Dem_DTCGroupType;

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

# define Rte_TypeDef_NV_Data_DiagDIDFE11
typedef struct
{
  NV_Reset_Reason_Table NV_DIAG_DID_FE11_Data;
  NV_FE11_Reserved_Data_Table NV_FE11_Reserved_Data;
} NV_Data_DiagDIDFE11;

# define Rte_TypeDef_NV_Data_Dlt_Fetal_Storage
typedef struct
{
  Nvm_U8ArrType_20 NVM_Dlt_Fetal_Storage;
} NV_Data_Dlt_Fetal_Storage;

# define Rte_TypeDef_NV_Data_Dlt_Main_Storage
typedef struct
{
  Nvm_U8ArrType_160 NVM_Dlt_Main_Storage;
} NV_Data_Dlt_Main_Storage;

# define Rte_TypeDef_NV_Data_HKMCData
typedef struct
{
  NV_Vehicle_Identi_No_Table NV_DIAG_DID_F190_Veh_Identi_No;
  NV_HKMC_SW_Ver_Table NV_DIAG_DID_F1A0_Data;
  NV_HKMC_SW_Unit_Ver_Table NV_DIAG_DID_F1B1_Data;
} NV_Data_HKMCData;

# define Rte_TypeDef_NV_Data_MEETData
typedef struct
{
  EOL_History_Type NV_Customer_EOL_write_history;
  NV_SWVersion_Table NV_Customer_Software_Version;
  NV_PartNumber_Table NV_HMC_Part_Number;
  NV_ManufacturingDate_Table NV_Assembly_Mfg_Date;
  NV_ECUHardwareNumber_Table NV_ECU_Hardware_Number;
  NV_CANDataBaseVersion_Table NV_MMCAN_DataBase_Version;
  NV_Mfg_SerNo_Mfg_Date_Table NV_Mfg_SerNo_Mfg_Date;
  NV_Odo_Dealer_Id_Table NVM_Odo_Dealer_Id;
  NV_Odo_Date_Table NVM_Odo_Date_Update;
  UInt8 NVM_Odo_Checksum;
  UInt8 NVM_Odo_Reset_Count;
  NV_MEETData_Reserved_Table NV_MEETData_Reserved_Data;
} NV_Data_MEETData;

# define Rte_TypeDef_NV_Data_MEETData_config
typedef struct
{
  EOL_Mfg_Mode_Entry_Table NV_Mfg_Mode_Requested;
} NV_Data_MEETData_config;

# define Rte_TypeDef_NV_Data_ServiceInterval
typedef struct
{
  UInt32 NVM_SIA_ODO;
  UInt16 NVM_SIA_DAYS;
  UInt16 NVM_RunningTime;
  ServiceInterval_Reserved_Table NVM_ServiceInterval_Reserved_Data;
} NV_Data_ServiceInterval;

# define Rte_TypeDef_NV_Data_ServiceInterval_config
typedef struct
{
  UInt32 NVM_Disable_Service_Distance;
  UInt32 NVM_Settings_Service_Distance;
  UInt16 NVM_Disable_Service_Days;
  UInt16 NVM_Settings_Service_Months;
  UInt8 NVM_Settings_Service_Enable;
  UInt8 NVM_Settings_Service_Mode;
  ServiceInterval_config_Reserved_Table NVM_ServiceInterval_config_Reserved_Data;
} NV_Data_ServiceInterval_config;

# define Rte_TypeDef_NV_Data_TripBase
typedef struct
{
  UInt32 NV_Odo_TripBase_Accuinfo;
  UInt32 NV_Odo_TripBase_Refuelinfo;
  TripBase_Reserved_Table NV_Odo_TripBase_Reserved_Data;
} NV_Data_TripBase;

# define Rte_TypeDef_NV_Data_TripComputer
typedef struct
{
  UInt32 NVM_TC_AFE_1_ACCUM_DISTANCE_Accuinfo;
  UInt32 NVM_TC_AFE_1_ACCUM_FUEL_Accuinfo;
  UInt32 NVM_TC_AFE_2_ACCUM_DISTANCE_Refuelinfo;
  UInt32 NVM_TC_AFE_2_ACCUM_FUEL_Refuelinfo;
  UInt32 NVM_TC_AVS_1_ACCUM_DISTANCE_Accuinfo;
  UInt32 NVM_TC_AVS_1_ACCUM_TIME_Accuinfo;
  UInt32 NVM_TC_AVS_2_ACCUM_DISTANCE_Refuelinfo;
  UInt32 NVM_TC_AVS_2_ACCUM_TIME_Refuelinfo;
  UInt32 NVM_DRIVINGTIME_HOUR_Accuinfo;
  UInt8 NVM_DRIVINGTIME_MIN_Accuinfo;
  UInt8 NVM_DRIVINGTIME_SEC_Accuinfo;
  UInt32 NVM_DRIVINGTIME_HOUR_Refuelinfo;
  UInt8 NVM_DRIVINGTIME_MIN_Refuelinfo;
  UInt8 NVM_DRIVINGTIME_SEC_Refuelinfo;
  UInt8 NVM_DRIVINGTIME_HOUR_AutoStop;
  UInt8 NVM_DRIVINGTIME_MIN_AutoStop;
  UInt8 NVM_DRIVINGTIME_SEC_AutoStop;
  UInt8 NVM_DRIVINGTIME_HOUR_AutoStop1;
  UInt8 NVM_DRIVINGTIME_MIN_AutoStop1;
  UInt8 NVM_DRIVINGTIME_SEC_AutoStop1;
  TripComputer_Reserved_Table NVM_TripComputer_Reserved_Data;
} NV_Data_TripComputer;

# define Rte_TypeDef_NV_Data_UserSettings
typedef struct
{
  UInt16 NVM_AVN_BRIGHTLEVEL;
  UInt8 NVM_Settings_Fuel_Economy_Reset;
  UInt8 NVM_AVN_USM_Settings_Language;
  UInt8 NVM_USM_KMMILES;
  UInt8 NVM_Current_UserSettingProfile;
  Settings_Fuel_Economy_Unit_Table NVM_Settings_Fuel_Economy_Unit;
  USM_UserSettings_Table NVM_USM_WiperLight;
  USM_UserSettings_Table NVM_USM_Welcomesound;
  USM_UserSettings_Table NVM_USM_IceWarning;
  USM_UserSettings_Table NVM_USM_TrafficSign;
  USM_UserSettings_Table NVM_USM_KMMILESUSM;
  USM_Warning_Volume_Table NVM_USM_Warning_Volume;
  USM_Illumination_Table NVM_USM_Illumination;
  USM_UserSettings_Table NVM_USM_Fuel_Economy_Display;
  USM_UserSettings_Table NVM_USM_Theme_Selection;
  USM_UserSettings_Table NVM_USM_Theme_Interlocking_Selection;
  USM_UserSettings_Table NVM_CLU_USM_Settings_Language;
  UserSettings_Reserved_Table NVM_UserSettings_Reserved_Data;
} NV_Data_UserSettings;

# define Rte_TypeDef_SAvPopupInfo_t
typedef struct
{
  EAvMode_t AvMode;
  UInt8 ChannelNumber;
  UInt8 FrequencyUnit;
  UInt16 FrequencyValue;
  UInt8 HuDecimalPoint;
  UInt8 HuType;
  data_u8_102 TpData;
  UInt16 TrackNumber;
} SAvPopupInfo_t;

# define Rte_TypeDef_SCruiseSpeedLimiter_2
typedef SCruiseSpeedLimiter SCruiseSpeedLimiter_2[2];

# define Rte_TypeDef_SDriverAssistMenuInfo
typedef struct
{
  SBcaMenu BcaMenuInfo;
  SLkaMenu LkaMenuInfo;
  SSccMenu SccMenuInfo;
  SLfaMenu LfaMenuInfo;
  SFcaBcaWarn FcaBcaWarnInfo;
  Boolean DriverAssistHoldOkSts;
} SDriverAssistMenuInfo;

# define Rte_TypeDef_SEtmInfo_t
typedef struct
{
  UInt16 RomLevel;
  UInt16 NvmLevel;
  UInt16 DteFuelRate;
  UInt16 FuelRatioAD;
  UInt16 FuelVolume;
  UInt8 DteFuelEfficiency;
  data_u16_3 TotalFuelConsumption;
  UInt8 FuelEconomyUnit;
  UInt8 BatteryVoltage;
  data_u8_19 ManufSerNumDate;
  data_bool_25 DtcFlags;
  data_u8_4 CustomerEol;
  data_u8_4 VisteonEol;
} SEtmInfo_t;

# define Rte_TypeDef_SGaugeInfo_2
typedef SGaugeInfo SGaugeInfo_2[2];

# define Rte_TypeDef_SGaugeInfo_3
typedef SGaugeInfo SGaugeInfo_3[3];

# define Rte_TypeDef_SInfoWarningList_50
typedef SInfoWarningList SInfoWarningList_50[50];

# define Rte_TypeDef_SMenuStsU16Val_10
typedef SMenuStsU16Val SMenuStsU16Val_10[10];

# define Rte_TypeDef_SMenuStsU32Val_10
typedef SMenuStsU32Val SMenuStsU32Val_10[10];

# define Rte_TypeDef_SMenuStsU8Val_60
typedef SMenuStsU8Val SMenuStsU8Val_60[60];

# define Rte_TypeDef_SMenuSts_250
typedef SMenuSts SMenuSts_250[250];

# define Rte_TypeDef_SMiniPopupStatus
typedef struct
{
  UInt8 visible;
  EWarningMessage_t popupId;
  data_u8_8 dynData;
} SMiniPopupStatus;

# define Rte_TypeDef_SSetMenuCmd
typedef struct
{
  SMenuCmd data;
} SSetMenuCmd;

# define Rte_TypeDef_SSetMenuSts
typedef struct
{
  SMenuSts_250 data;
} SSetMenuSts;

# define Rte_TypeDef_SSetMenuStsU16Val
typedef struct
{
  SMenuStsU16Val_10 data;
} SSetMenuStsU16Val;

# define Rte_TypeDef_SSetMenuStsU32Val
typedef struct
{
  SMenuStsU32Val_10 data;
} SSetMenuStsU32Val;

# define Rte_TypeDef_SSetMenuStsU8Val
typedef struct
{
  SMenuStsU8Val_60 data;
} SSetMenuStsU8Val;

# define Rte_TypeDef_SSlowGaugeInfo
typedef struct
{
  SGaugeInfo_3 gaugeInfo_3;
} SSlowGaugeInfo;

# define Rte_TypeDef_SStoreMenuConfig
typedef struct
{
  UInt8 InfoWarningCount;
  SInfoWarningList_50 InfoWarningList_50;
  data_u8_6 TPMSDynData_6;
} SStoreMenuConfig;

# define Rte_TypeDef_STTChecksumSts
typedef struct
{
  data_u8_2 TTChecksumSts;
} STTChecksumSts;

# define Rte_TypeDef_STT_Status
typedef struct
{
  data_u8_12 mask;
} STT_Status;

# define Rte_TypeDef_STbtRouteGuideInfo
typedef struct
{
  UInt8 DispType;
  UInt8 DirectionSeperation;
  UInt16 RoadDisplay;
  ETbtCombinedStreet CombinedStreet;
  ETbtPathDirection PathDirection;
  ETbtDistanceUnit DistanceUnit;
  UInt32 DestinationDistance;
  UInt8 BarGraphPercent;
  ETbtDestinationFlag DestinationFlag;
  data_u8_2 PrelimInfoIcon;
  data_u32_2 PrelimInfoDistance;
  ETbtDistanceUnit_2 PrelimInfoDistanceUnit;
  UInt8 LaneQty;
  UInt8 LanePacketInfo;
  UInt16 LaneDistance;
  ETbtDistanceUnit LaneUnit;
  STbtLaneInfo LaneInfo;
} STbtRouteGuideInfo;

# define Rte_TypeDef_STpmsMenuInfo
typedef struct
{
  Boolean TpmsMenuSts;
  data_u8_4 TireData_4;
  UInt8 TireStatus;
  UInt8 TirePressureUnit;
  UInt8 DisplayType;
} STpmsMenuInfo;

# define Rte_TypeDef_SWarningDisplay
typedef struct
{
  UInt8 show;
  EWarningMessage_t warningId;
  data_u8_6 dynData;
} SWarningDisplay;

# define Rte_TypeDef_SWarningStatus
typedef struct
{
  UInt8 visible;
  EWarningMessage_t warningId;
  data_u8_8 dynData;
} SWarningStatus;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

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

# define Rte_TypeDef_SCCSL
typedef struct
{
  SCruiseSpeedLimiter_2 ccsldata_2;
} SCCSL;

# define Rte_TypeDef_SEtmInfo
typedef struct
{
  UInt8 EtmEnabled;
  UInt8 EtmScreenIndex;
  SEtmInfo_t EtmScreenInfo;
} SEtmInfo;

# define Rte_TypeDef_SFastGaugeInfo
typedef struct
{
  SGaugeInfo_2 gaugeInfo_2;
} SFastGaugeInfo;

# define Rte_TypeDef_STBTMenuInfo
typedef struct
{
  STbtRouteGuideInfo routeGuidePageInfo;
  STbtDestInfo destinationPageInfo;
  UInt8 pageSwitchRequired;
  data_u8_102 tpDataGuide;
  data_u8_102 tpDataPrelimInfo;
  data_u8_102 tpDataDest;
  Boolean TbtHdrstatus;
  Boolean TbtGuideMenuStatus;
  Boolean TbtDestMenuStatus;
} STBTMenuInfo;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_Dcm_MsgType
typedef uint8 Dcm_MsgType1;

#  define Rte_TypeDef_Integer
typedef uint8 Integer;

#  define Rte_TypeDef_Rte_DT_NV_ChimeVolData2_Reserved_Table_0
typedef uint8 Rte_DT_NV_ChimeVolData2_Reserved_Table_0;

#  define Rte_TypeDef_Rte_DT_NV_ChimeVolData3_Reserved_Table_0
typedef uint8 Rte_DT_NV_ChimeVolData3_Reserved_Table_0;

#  define Rte_TypeDef_Rte_DT_NV_ChimeVolData4_Reserved_Table_0
typedef uint8 Rte_DT_NV_ChimeVolData4_Reserved_Table_0;

#  define Rte_TypeDef_Rte_DT_NV_HealthManagement_Type_0
typedef uint8 Rte_DT_NV_HealthManagement_Type_0;

#  define Rte_TypeDef_Rte_DT_NV_SoundSpeedTable_0
typedef uint8 Rte_DT_NV_SoundSpeedTable_0;

#  define Rte_TypeDef_Rte_DT_NV_SoundUSMTable_0
typedef uint8 Rte_DT_NV_SoundUSMTable_0;

#  define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_2_0
typedef uint8 Rte_DT_Nvm_U8ArrType_2_0;

#  define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_3_0
typedef uint8 Rte_DT_Nvm_U8ArrType_3_0;

#  define Rte_TypeDef_Rte_DT_USM_AutoBrightIllumination_Table_0
typedef uint16 Rte_DT_USM_AutoBrightIllumination_Table_0;

#  define Rte_TypeDef_Rte_DT_data_u8_25_0
typedef uint8 Rte_DT_data_u8_25_0;

#  define Rte_TypeDef_Rte_DT_data_u8_7_0
typedef uint8 Rte_DT_data_u8_7_0;

#  define Rte_TypeDef_Rte_DT_data_uint8_8_0
typedef uint8 Rte_DT_data_uint8_8_0;

#  define Rte_TypeDef_Rte_DT_t_uint8_x_160_0
typedef uint8 Rte_DT_t_uint8_x_160_0;

#  define Rte_TypeDef_teDiagOpStatus
typedef uint8 teDiagOpStatus;

#  define Rte_TypeDef_Dcm_NegativeResponseCode
typedef uint8 Dcm_NegativeResponseCode;

#  define Rte_TypeDef_EAccStatus
typedef uint8 EAccStatus;

#  define Rte_TypeDef_EMenuSettingId
typedef uint8 EMenuSettingId;

#  define Rte_TypeDef_EMenuSettingSts
typedef uint8 EMenuSettingSts;

#  define Rte_TypeDef_EMiniPopup_t
typedef uint8 EMiniPopup_t;

#  define Rte_TypeDef_I2c_StatusType
typedef uint8 I2c_StatusType;

#  define Rte_TypeDef_Region_type
typedef uint8 Region_type;

#  define Rte_TypeDef_VariantConfig
typedef uint8 VariantConfig;

#  define Rte_TypeDef_NV_ChimeVolData2_Reserved_Table
typedef Rte_DT_NV_ChimeVolData2_Reserved_Table_0 NV_ChimeVolData2_Reserved_Table[4];

#  define Rte_TypeDef_NV_ChimeVolData3_Reserved_Table
typedef Rte_DT_NV_ChimeVolData3_Reserved_Table_0 NV_ChimeVolData3_Reserved_Table[16];

#  define Rte_TypeDef_NV_ChimeVolData4_Reserved_Table
typedef Rte_DT_NV_ChimeVolData4_Reserved_Table_0 NV_ChimeVolData4_Reserved_Table[160];

#  define Rte_TypeDef_NV_HealthManagement_Type
typedef Rte_DT_NV_HealthManagement_Type_0 NV_HealthManagement_Type[150];

#  define Rte_TypeDef_NV_SoundSpeedTable
typedef Rte_DT_NV_SoundSpeedTable_0 NV_SoundSpeedTable[8];

#  define Rte_TypeDef_NV_SoundUSMTable
typedef Rte_DT_NV_SoundUSMTable_0 NV_SoundUSMTable[4];

#  define Rte_TypeDef_Nvm_U8ArrType_2
typedef Rte_DT_Nvm_U8ArrType_2_0 Nvm_U8ArrType_2[2];

#  define Rte_TypeDef_Nvm_U8ArrType_3
typedef Rte_DT_Nvm_U8ArrType_3_0 Nvm_U8ArrType_3[3];

#  define Rte_TypeDef_USM_AutoBrightIllumination_Table
typedef Rte_DT_USM_AutoBrightIllumination_Table_0 USM_AutoBrightIllumination_Table[4];

#  define Rte_TypeDef_data_u8_25
typedef Rte_DT_data_u8_25_0 data_u8_25[25];

#  define Rte_TypeDef_data_u8_7
typedef Rte_DT_data_u8_7_0 data_u8_7[7];

#  define Rte_TypeDef_data_uint8_8
typedef Rte_DT_data_uint8_8_0 data_uint8_8[8];

#  define Rte_TypeDef_t_uint8_x_160
typedef Rte_DT_t_uint8_x_160_0 t_uint8_x_160[160];

#  define Rte_TypeDef_NV_Data_EOL_IDENTIFIERS
typedef struct
{
  UInt16 NVM_EOL_Mfg_Mode_Entry;
} NV_Data_EOL_IDENTIFIERS;

#  define Rte_TypeDef_SDMS_TT
typedef struct
{
  EDMSTT_t DMSTT;
} SDMS_TT;

#  define Rte_TypeDef_SRSBR_TT
typedef struct
{
  UInt16 RSBRTT;
} SRSBR_TT;

#  define Rte_TypeDef_tDlt_BH_MessageFormat
typedef struct
{
  UInt32 HeaderType;
  UInt8 MessageCount;
  UInt16 MessageLen;
  UInt8 MessageInfo;
  UInt8 no_of_arguments;
  UInt32 LogMessage_Timestamp;
} tDlt_BH_MessageFormat;

#  define Rte_TypeDef_NV_Data_ChimeVolData
typedef struct
{
  NV_SoundSpeedTable NV_SoundTickTockWithAdasVehSpd;
  NV_SoundSpeedTable NV_SoundTickTockWithNonAdasVehSpd;
  NV_SoundSpeedTable NV_SoundScctakeOverWithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundScctakeOverWithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundScctakeOverWithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundScctakeOverWithAdasUsmSpdOff;
  NV_SoundSpeedTable NV_SoundScctakeOverWithNonAdasSpd;
  NV_SoundSpeedTable NV_SoundSeatbeltWithAdasVehSpdNotEEC;
  NV_SoundSpeedTable NV_SoundSeatbeltWithNonAdasVehSpdNotEEC;
  NV_SoundSpeedTable NV_SoundSeatbeltWithAdasVehSpdEEC;
  NV_SoundSpeedTable NV_SoundSeatbeltWithNonAdasVehSpdEEC;
  NV_SoundSpeedTable NV_SoundPopupAlarm3WithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundPopupAlarm3WithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundPopupAlarm3WithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundPopupAlarm3WithAdasUsmSpdOff;
  NV_SoundSpeedTable NV_SoundPopupAlarm3WithNonAdasSpd;
} NV_Data_ChimeVolData;

#  define Rte_TypeDef_NV_Data_ChimeVolData1
typedef struct
{
  NV_SoundSpeedTable NV_SoundPopupAlarm2WithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundPopupAlarm2WithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundPopupAlarm2WithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundPopupAlarm2WithAdasUsmSpdOff;
  NV_SoundSpeedTable NV_SoundPopupAlarm2WithNonAdasSpd;
  NV_SoundSpeedTable NV_SoundPopupAlarm1WithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundPopupAlarm1WithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundPopupAlarm1WithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundPopupAlarm1WithAdasUsmSpdOff;
  NV_SoundSpeedTable NV_SoundPopupAlarm1WithNonAdasSpd;
  NV_SoundUSMTable NV_SoundPASRear3WithUsm;
  NV_SoundUSMTable NV_SoundPASFront3WithUsm;
  NV_SoundUSMTable NV_SoundPASRear2WithUsm;
  NV_SoundUSMTable NV_SoundPASFront2WithUsm;
  NV_SoundUSMTable NV_SoundPASRear1WithUsm;
  NV_SoundUSMTable NV_SoundPASFront1WithUsm;
  NV_SoundUSMTable NV_SoundWarningVolumeFeedBackUsm;
  NV_SoundUSMTable NV_SoundMSLAWithUsm;
  NV_SoundSpeedTable NV_SoundFCA_3rdWithNonAdasSpd;
  NV_SoundSpeedTable NV_SoundFCA_1st2ndWithNonAdasSpd;
  NV_SoundSpeedTable NV_SoundFCA_1st2ndWithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundFCA_1st2ndWithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundFCA_1st2ndWithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundFCA_1st2ndWithAdasUsmSpdOff;
} NV_Data_ChimeVolData1;

#  define Rte_TypeDef_NV_Data_ChimeVolData2
typedef struct
{
  NV_SoundSpeedTable NV_SoundBCW_WithNonAdasSpd;
  NV_SoundSpeedTable NV_SoundBCW_WithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundBCW_WithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundBCW_WithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundBCW_WithAdasUsmSpdOff;
  NV_SoundUSMTable NV_SoundBCW_Sea_WithUsm;
  NV_SoundUSMTable NV_SoundBCW_Rccw_WithUsm;
  NV_SoundSpeedTable NV_SoundLka_WithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundLka_WithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundLka_WithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundLka_WithAdasUsmSpdOff;
  NV_SoundSpeedTable NV_SoundLka_WithNonAdasSpd;
  NV_SoundSpeedTable NV_SoundLkaHandsOff_WithNonAdasSpd;
  NV_ChimeVolData2_Reserved_Table NV_ChimeVolData2_Reserved_Data;
} NV_Data_ChimeVolData2;

#  define Rte_TypeDef_NV_Data_ChimeVolData3
typedef struct
{
  NV_SoundSpeedTable NV_SoundLkaHandsOff_WithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundLkaHandsOff_WithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundLkaHandsOff_WithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundLkaHandsOff_WithAdasUsmSpdOff;
  NV_SoundSpeedTable NV_SoundFCA_3rdWithAdasUsmSpdHigh;
  NV_SoundSpeedTable NV_SoundFCA_3rdWithAdasUsmSpdMid;
  NV_SoundSpeedTable NV_SoundFCA_3rdWithAdasUsmSpdLow;
  NV_SoundSpeedTable NV_SoundFCA_3rdWithAdasUsmSpdOff;
  NV_ChimeVolData3_Reserved_Table NV_ChimeVolData3_Reserved_Data;
} NV_Data_ChimeVolData3;

#  define Rte_TypeDef_NV_Data_ChimeVolData4
typedef struct
{
  NV_ChimeVolData4_Reserved_Table NV_ChimeVolData4_Reserved_Data;
} NV_Data_ChimeVolData4;

#  define Rte_TypeDef_NV_Data_DIAG_CONFIG_VAR_5
typedef struct
{
  Boolean NVM_DG_13_Airbag_Fdbk_IC_sts_BOOL;
  Nvm_U8ArrType_3 NVM_Diag_config_var_5_padding_U8A;
} NV_Data_DIAG_CONFIG_VAR_5;

#  define Rte_TypeDef_NV_Data_DIAG_CONFIG_VAR_8
typedef struct
{
  UInt8 NVM_DG_16_vehicle_type_U8;
  Nvm_U8ArrType_3 NVM_Diag_config_var_16_padding_U8A;
} NV_Data_DIAG_CONFIG_VAR_8;

#  define Rte_TypeDef_NV_Data_Health_Management
typedef struct
{
  NV_HealthManagement_Type Health_Management_Data;
} NV_Data_Health_Management;

#  define Rte_TypeDef_SSetMenuStsU16Val_10
typedef SSetMenuStsU16Val SSetMenuStsU16Val_10[10];

#  define Rte_TypeDef_SSetMenuStsU32Val_10
typedef SSetMenuStsU32Val SSetMenuStsU32Val_10[10];

#  define Rte_TypeDef_SSetMenuStsU8Val_60
typedef SSetMenuStsU8Val SSetMenuStsU8Val_60[60];

#  define Rte_TypeDef_SSetMenuSts_250
typedef SSetMenuSts SSetMenuSts_250[250];

#  define Rte_TypeDef_SStoreMenuConfig_50
typedef SStoreMenuConfig SStoreMenuConfig_50[50];

#  define Rte_TypeDef_STbtRouteGuideInfo_2
typedef STbtRouteGuideInfo STbtRouteGuideInfo_2[2];

#  define Rte_TypeDef_tDlt_MessageFormat
typedef struct
{
  tDlt_BH_MessageFormat BaseHeader;
  data_uint8_8 PayLoad;
} tDlt_MessageFormat;

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(EOL_Mfg_Mode_Entry_Table, RTE_CONST) Rte_C_EOL_Mfg_Mode_Entry_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_CANDataBaseVersion_Table, RTE_CONST) Rte_C_NV_CANDataBaseVersion_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_ECUHardwareNumber_Table, RTE_CONST) Rte_C_NV_ECUHardwareNumber_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_FE11_Reserved_Data_Table, RTE_CONST) Rte_C_NV_FE11_Reserved_Data_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_HKMC_SW_Unit_Ver_Table, RTE_CONST) Rte_C_NV_HKMC_SW_Unit_Ver_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_HKMC_SW_Ver_Table, RTE_CONST) Rte_C_NV_HKMC_SW_Ver_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_MEETData_Reserved_Table, RTE_CONST) Rte_C_NV_MEETData_Reserved_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_ManufacturingDate_Table, RTE_CONST) Rte_C_NV_ManufacturingDate_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Mfg_SerNo_Mfg_Date_Table, RTE_CONST) Rte_C_NV_Mfg_SerNo_Mfg_Date_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Odo_Date_Table, RTE_CONST) Rte_C_NV_Odo_Date_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Odo_Dealer_Id_Table, RTE_CONST) Rte_C_NV_Odo_Dealer_Id_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_PartNumber_Table, RTE_CONST) Rte_C_NV_PartNumber_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Reset_Reason_Table, RTE_CONST) Rte_C_NV_Reset_Reason_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_SWVersion_Table, RTE_CONST) Rte_C_NV_SWVersion_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Vehicle_Identi_No_Table, RTE_CONST) Rte_C_NV_Vehicle_Identi_No_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Nvm_U8ArrType_160, RTE_CONST) Rte_C_Nvm_U8ArrType_160_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Nvm_U8ArrType_20, RTE_CONST) Rte_C_Nvm_U8ArrType_20_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SegmentCtrlType, RTE_CONST) Rte_CMeetCddSegmentCtrlDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SegmentCtrlType, RTE_CONST) Rte_UiCtrl_ETMSegmentCtrlDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ServiceInterval_Reserved_Table, RTE_CONST) Rte_C_ServiceInterval_Reserved_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ServiceInterval_config_Reserved_Table, RTE_CONST) Rte_C_ServiceInterval_config_Reserved_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Settings_Fuel_Economy_Unit_Table, RTE_CONST) Rte_C_Settings_Fuel_Economy_Unit_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TFTRegStatusType, RTE_CONST) Rte_CDisplayCddTFTRegStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TFTRegStatusType, RTE_CONST) Rte_DimSafeMdlTFTRegStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TripBase_Reserved_Table, RTE_CONST) Rte_C_TripBase_Reserved_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TripComputer_Reserved_Table, RTE_CONST) Rte_C_TripComputer_Reserved_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(USM_Illumination_Table, RTE_CONST) Rte_C_USM_Illumination_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(USM_UserSettings_Table, RTE_CONST) Rte_C_USM_UserSettings_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(USM_UserSettings_Table, RTE_CONST) Rte_C_USM_UserSettings_Table_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(USM_UserSettings_Table, RTE_CONST) Rte_C_USM_UserSettings_Table_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(USM_Warning_Volume_Table, RTE_CONST) Rte_C_USM_Warning_Volume_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UserSettings_Reserved_Table, RTE_CONST) Rte_C_UserSettings_Reserved_Table_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(data_u8_72, RTE_CONST) Rte_Ctrl_TelltaleTelltaleStatusOPArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(data_u8_72, RTE_CONST) Rte_View_TelltaleTelltaleStatusOPArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE1_ACCUMULATED_DATA, RTE_CONST) Rte_AfeMdlAFE1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE1_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_AFEAFE1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE1_INSTANT_DATA, RTE_CONST) Rte_AfeMdlAFE1_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE1_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_AFEAFE1_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE1_OUTPUT, RTE_CONST) Rte_AfeCtrlAFE1_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE1_OUTPUT, RTE_CONST) Rte_Core_clag_tc_AFEAFE1_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE2_ACCUMULATED_DATA, RTE_CONST) Rte_AfeMdlAFE2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE2_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_AFEAFE2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE2_INSTANT_DATA, RTE_CONST) Rte_AfeMdlAFE2_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE2_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_AFEAFE2_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE2_OUTPUT, RTE_CONST) Rte_AfeCtrlAFE2_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE2_OUTPUT, RTE_CONST) Rte_Core_clag_tc_AFEAFE2_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE3_ACCUMULATED_DATA, RTE_CONST) Rte_AfeMdlAFE3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE3_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_AFEAFE3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE3_INSTANT_DATA, RTE_CONST) Rte_AfeMdlAFE3_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE3_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_AFEAFE3_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE3_OUTPUT, RTE_CONST) Rte_AfeCtrlAFE3_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE3_OUTPUT, RTE_CONST) Rte_Core_clag_tc_AFEAFE3_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE4_ACCUMULATED_DATA, RTE_CONST) Rte_AfeMdlAFE4Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE4_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_AFEAFE4Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE4_INSTANT_DATA, RTE_CONST) Rte_AfeMdlAFE4_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE4_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_AFEAFE4_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE4_OUTPUT, RTE_CONST) Rte_AfeCtrlAFE4_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE4_OUTPUT, RTE_CONST) Rte_Core_clag_tc_AFEAFE4_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE_RESET_INFO, RTE_CONST) Rte_AfeCtrlReset_InfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE_RESET_INFO, RTE_CONST) Rte_AfeMdlReset_InfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AFE_RESET_INFO, RTE_CONST) Rte_Core_clag_tc_AFEReset_InfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS1_ACCUMULATED_DATA, RTE_CONST) Rte_AvsMdlAVS1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS1_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_AVSAVS1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS1_INSTANT_DATA, RTE_CONST) Rte_AvsMdlAVS1_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS1_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_AVSAVS1_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS1_OUTPUT, RTE_CONST) Rte_AvsCtrlAVS1_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS1_OUTPUT, RTE_CONST) Rte_Core_clag_tc_AVSAVS1_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS2_ACCUMULATED_DATA, RTE_CONST) Rte_AvsMdlAVS2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS2_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_AVSAVS2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS2_INSTANT_DATA, RTE_CONST) Rte_AvsMdlAVS2_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS2_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_AVSAVS2_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS2_OUTPUT, RTE_CONST) Rte_AvsCtrlAVS2_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS2_OUTPUT, RTE_CONST) Rte_Core_clag_tc_AVSAVS2_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS3_ACCUMULATED_DATA, RTE_CONST) Rte_AvsMdlAVS3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS3_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_AVSAVS3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS3_INSTANT_DATA, RTE_CONST) Rte_AvsMdlAVS3_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS3_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_AVSAVS3_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS3_OUTPUT, RTE_CONST) Rte_AvsCtrlAVS3_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS3_OUTPUT, RTE_CONST) Rte_Core_clag_tc_AVSAVS3_CALC_DATAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS_RESET_INFO, RTE_CONST) Rte_AvsCtrlReset_InfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS_RESET_INFO, RTE_CONST) Rte_AvsMdlReset_InfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_AVS_RESET_INFO, RTE_CONST) Rte_Core_clag_tc_AVSReset_InfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT1_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT1_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT1_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeCtrlDT1_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT1_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeMdlDT1_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT1_INIT_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT1_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT1_INIT_DATA, RTE_CONST) Rte_DriveTimeMdlDT1_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT2_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT2_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT2_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeCtrlDT2_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT2_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeMdlDT2_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT2_INIT_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT2_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT2_INIT_DATA, RTE_CONST) Rte_DriveTimeMdlDT2_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT3_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT3_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT3_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeCtrlDT3_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT3_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeMdlDT3_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT3_INIT_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT3_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT3_INIT_DATA, RTE_CONST) Rte_DriveTimeMdlDT3_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT4_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT4_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT4_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeCtrlDT4_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT4_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeMdlDT4_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT4_INIT_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT4_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT4_INIT_DATA, RTE_CONST) Rte_DriveTimeMdlDT4_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT5_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT5_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT5_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeCtrlDT5_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT5_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeMdlDT5_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT5_INIT_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT5_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT5_INIT_DATA, RTE_CONST) Rte_DriveTimeMdlDT5_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT6_ACCUMULATED_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT6_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT6_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeCtrlDT6_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT6_ACCUMULATED_DATA, RTE_CONST) Rte_DriveTimeMdlDT6_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT6_INIT_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEDT6_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT6_INIT_DATA, RTE_CONST) Rte_DriveTimeMdlDT6_InitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DTE_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_DTEDTE_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DTE_INSTANT_DATA, RTE_CONST) Rte_DteMdlDTE_Instant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEInstant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT_INSTANT_DATA, RTE_CONST) Rte_DriveTimeMdlInstant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT_RESET_INFO, RTE_CONST) Rte_Core_clag_tc_DRIVETIMEReset_InfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_DT_RESET_INFO, RTE_CONST) Rte_DriveTimeMdlReset_InfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_IFE_CALCULATED_DATA, RTE_CONST) Rte_Core_clag_tc_IFEOutput_IFEValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_IFE_CALCULATED_DATA, RTE_CONST) Rte_IfeCtrlOutput_IFEValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_IFE_INSTANT_DATA, RTE_CONST) Rte_Core_clag_tc_IFEInstant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CLAG_IFE_INSTANT_DATA, RTE_CONST) Rte_IfeMdlInstant_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Customer_EOLConfig, RTE_CONST) Rte_C_NV_Data_Customer_EOLConfig_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDIDFE11, RTE_CONST) Rte_C_NV_Data_DiagDIDFE11_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Dlt_Fetal_Storage, RTE_CONST) Rte_C_NV_Data_Dlt_Fetal_Storage_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Dlt_Main_Storage, RTE_CONST) Rte_C_NV_Data_Dlt_Main_Storage_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FBLGip_Checker, RTE_CONST) Rte_C_NV_Data_FBLGip_Checker_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FBLVip_Checker, RTE_CONST) Rte_C_NV_Data_FBLVip_Checker_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FblSecurityDelay, RTE_CONST) Rte_C_NV_Data_FblSecurityDelay_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FblSecurityFail, RTE_CONST) Rte_C_NV_Data_FblSecurityFail_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_HKMCData, RTE_CONST) Rte_C_NV_Data_HKMCData_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_MEETData, RTE_CONST) Rte_C_NV_Data_MEETData_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_MEETData_config, RTE_CONST) Rte_C_NV_Data_MEETData_config_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_MagicFlag, RTE_CONST) Rte_C_NV_Data_MagicFlag_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_OdometerBLK1, RTE_CONST) Rte_C_NV_Data_OdometerBLK1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_OdometerBLK2, RTE_CONST) Rte_C_NV_Data_OdometerBLK2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_OdometerBLK3, RTE_CONST) Rte_C_NV_Data_OdometerBLK3_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_OdometerBLK4, RTE_CONST) Rte_C_NV_Data_OdometerBLK4_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_OdometerBLK5, RTE_CONST) Rte_C_NV_Data_OdometerBLK5_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_ServiceInterval, RTE_CONST) Rte_C_NV_Data_ServiceInterval_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_ServiceInterval_config, RTE_CONST) Rte_C_NV_Data_ServiceInterval_config_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_TripBase, RTE_CONST) Rte_C_NV_Data_TripBase_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_TripComputer, RTE_CONST) Rte_C_NV_Data_TripComputer_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_UserSettings, RTE_CONST) Rte_C_NV_Data_UserSettings_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Visteon_EOLConfig, RTE_CONST) Rte_C_NV_Data_Visteon_EOLConfig_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SAvPopupInfo_t, RTE_CONST) Rte_AvMdlAvPopupInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SAvPopupInfo_t, RTE_CONST) Rte_UiCtrl_PopupAvPopupInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SCCSL, RTE_CONST) Rte_SCCSL_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDIS, RTE_CONST) Rte_DisMdlDISDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDIS, RTE_CONST) Rte_UiCtrl_IndicatorDISDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDTE, RTE_CONST) Rte_TripAdapterMdlDTEDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDTE, RTE_CONST) Rte_UiCtrl_HdrFtrDTEDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDawInfo, RTE_CONST) Rte_DawMdlDawInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDawInfo, RTE_CONST) Rte_UiCtrl_MenuDawInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDriverAssistMenuInfo, RTE_CONST) Rte_DriveAssistAdapterMdlDriverAssistMenuInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDriverAssistMenuInfo, RTE_CONST) Rte_UiCtrl_MenuDriverAssistMenuInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEtmInfo, RTE_CONST) Rte_EtmMdlEtmInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEtmInfo, RTE_CONST) Rte_UiCtrl_ETMEtmInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFastGaugeInfo, RTE_CONST) Rte_SFastGaugeInfo_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SGearInfo, RTE_CONST) Rte_FuelMdlGearInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SGearInfo, RTE_CONST) Rte_FuelMdl_CbGearInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SGearInfo, RTE_CONST) Rte_GearSafeMdlGearInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SGearInfo, RTE_CONST) Rte_ParkUsmMdlGearInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SGearInfo, RTE_CONST) Rte_SettingsMdlGearInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SGearInfo, RTE_CONST) Rte_UiCtrl_IndicatorGearInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHeaderScc, RTE_CONST) Rte_SccLfaMdlHeaderSccDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHeaderScc, RTE_CONST) Rte_UiCtrl_HdrFtrHeaderSccDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHelpPopupSts, RTE_CONST) Rte_ParkUsmMdlHelpPopupStsValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHelpPopupSts, RTE_CONST) Rte_UiCtrl_MenuHelpPopupStsValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_CSigCddsig0_port0Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_CSigCddsig0_port1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_CSigCddsig0_port2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_CSigCddsig0_port3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_SigUnitCtrlsig0_port0Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_SigUnitCtrlsig0_port1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_SigUnitCtrlsig0_port2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIG_WIN_SETUP_T, RTE_CONST) Rte_SigUnitCtrlsig0_port3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_ModMdlIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_SigUnitCtrlIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_ButtonIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_ETMIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_HMIIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_HdrFtrIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_IndicatorIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_MenuIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_PopupIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_SegmentedDisplayIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_SettingsAdapterIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_TelltaleIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnState, RTE_CONST) Rte_UiCtrl_WarningIgnStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIsgInfo, RTE_CONST) Rte_IsgMdlIsgInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIsgInfo, RTE_CONST) Rte_UiCtrl_MenuIsgInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_DriveTimeCtrlLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_LanguageMdlLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_ButtonLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_ETMLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_HMILanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_HdrFtrLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_IndicatorLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_MenuLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_PopupLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_SegmentedDisplayLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_SettingsAdapterLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_TelltaleLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SLanguageInfo, RTE_CONST) Rte_UiCtrl_WarningLanguageInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMenuStatus, RTE_CONST) Rte_BcwBcaMdlMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMenuStatus, RTE_CONST) Rte_CluInfoMdlMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMenuStatus, RTE_CONST) Rte_FcaMdlMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMenuStatus, RTE_CONST) Rte_TbtMdlMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMenuStatus, RTE_CONST) Rte_UiCtrl_MenuMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMiniPopupDisplay, RTE_CONST) Rte_UiCtrl_PopupMiniPopupDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMiniPopupDisplay, RTE_CONST) Rte_Warn_msg_cbMiniPopupDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMiniPopupStatus, RTE_CONST) Rte_PopupChmMdlMiniPopupStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMiniPopupStatus, RTE_CONST) Rte_UiCtrl_PopupMiniPopupStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMiniPopupStatus, RTE_CONST) Rte_Warn_msg_cbMiniPopupStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMiniPopupStatus, RTE_CONST) Rte_Warn_msg_ifMiniPopupStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOAT, RTE_CONST) Rte_OatMdlOATDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOAT, RTE_CONST) Rte_UiCtrl_HdrFtrOATDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOAT, RTE_CONST) Rte_UiCtrl_TelltaleOATDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOdometer, RTE_CONST) Rte_OdoMdlOdometerDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOdometer, RTE_CONST) Rte_UiCtrl_HdrFtrOdometerDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSetMenuSts, RTE_CONST) Rte_SSetMenuSts_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSetMenuStsU16Val, RTE_CONST) Rte_SSetMenuStsU16Val_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSetMenuStsU32Val, RTE_CONST) Rte_SSetMenuStsU32Val_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSetMenuStsU8Val, RTE_CONST) Rte_SSetMenuStsU8Val_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSlowGaugeInfo, RTE_CONST) Rte_SSlowGaugeInfo_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SStoreMenuConfig, RTE_CONST) Rte_SStoreMenuConfig_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STBTMenuInfo, RTE_CONST) Rte_STBTMenuInfo_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_AppSafeCtrlTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_DcmAdapterMdlTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_DimMdlTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_DimSafeMdlTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_STT_Status_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_SigUnitCtrlTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_UclSafeAdapterMdlTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_UiCtrl_HMITT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_UiCtrl_HdrFtrTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_UiCtrl_SegmentedDisplayTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_UiCtrl_TelltaleTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_View_TelltaleTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_DimMdlThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_ThemeSelMdlThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_ButtonThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_ETMThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_HMIThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_HdrFtrThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_IndicatorThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_MenuThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_PopupThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_SegmentedDisplayThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_SettingsAdapterThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_TelltaleThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeInfo, RTE_CONST) Rte_UiCtrl_WarningThemeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeStatus, RTE_CONST) Rte_CluInfoMdlThemeStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeStatus, RTE_CONST) Rte_TachCtrlThemeStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeStatus, RTE_CONST) Rte_ThemeSelMdlThemeStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SThemeStatus, RTE_CONST) Rte_UiCtrl_MenuThemeStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STpmsMenuInfo, RTE_CONST) Rte_TpmsMdlTpmsMenuInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STpmsMenuInfo, RTE_CONST) Rte_UiCtrl_MenuTpmsMenuInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripFuelEcoInfo, RTE_CONST) Rte_TripAdapterMdlTripFuelEcoInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripFuelEcoInfo, RTE_CONST) Rte_UiCtrl_HdrFtrTripFuelEcoInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripFuelEcoInfo, RTE_CONST) Rte_UiCtrl_MenuTripFuelEcoInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripFuelEcoInfo, RTE_CONST) Rte_UiCtrl_WarningTripFuelEcoInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripResetCmd, RTE_CONST) Rte_TripAdapterMdlTripResetCmdDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripResetCmd, RTE_CONST) Rte_TripResetMdlTripResetCmdDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripResetCmd, RTE_CONST) Rte_UiCtrl_MenuTripResetCmdDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SUreaLvlInfo, RTE_CONST) Rte_UiCtrl_MenuUreaLvlInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SUreaLvlInfo, RTE_CONST) Rte_UreaMdlUreaLvlInfoDataValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SUsmMenuInfo, RTE_CONST) Rte_SettingsMdlUsmMenuInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SUsmMenuInfo, RTE_CONST) Rte_UiCtrl_MenuUsmMenuInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplay, RTE_CONST) Rte_DimMdlWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplay, RTE_CONST) Rte_DimSafeMdlWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplay, RTE_CONST) Rte_UiCtrl_HMIWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplay, RTE_CONST) Rte_UiCtrl_HdrFtrWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplay, RTE_CONST) Rte_UiCtrl_WarningWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplay, RTE_CONST) Rte_Warn_msg_cbWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningStatus, RTE_CONST) Rte_PopupChmMdlWarningStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningStatus, RTE_CONST) Rte_UiCtrl_WarningWarningStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningStatus, RTE_CONST) Rte_Warn_msg_cbWarningStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningStatus, RTE_CONST) Rte_Warn_msg_ifWarningStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# include "Rte_DataHandleType.h"

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Calibration component and SW-C local calibration parameters
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(NV_Data_Customer_EOLConfig, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Customer_EOLConfig_ROM_NVBlockDescriptor_Customer_EOLConfig; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDIDFE11, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDFE11_ROM_NVBlockDescriptor_DiagDIDFE11; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Dlt_Fetal_Storage, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Dlt_Fetal_Storage_ROM_NVBlockDescriptor_Dlt_Fetal_Storage; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Dlt_Main_Storage, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Dlt_Main_Storage_ROM_NVBlockDescriptor_Dlt_Main_Storage; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FBLGip_Checker, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLGip_Checker_ROM_NVBlockDescriptor_FBLGip_Checker; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FBLVip_Checker, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLVip_Checker_ROM_NVBlockDescriptor_FBLVip_Checker; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FblSecurityDelay, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FblSecurityDelay_ROM_NVBlockDescriptor_FblSecurityDelay; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FblSecurityFail, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FblSecurityFail_ROM_NVBlockDescriptor_FblSecurityFail; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_HKMCData, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_HKMCData_ROM_NVBlockDescriptor_HKMCData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_MEETData, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MEETData_ROM_NVBlockDescriptor_MEETData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_MEETData_config, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MEETData_config_ROM_NVBlockDescriptor_MEETData_config; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_MagicFlag, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MagicFlag_ROM_NVBlockDescriptor_MagicFlag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_OdometerBLK1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK1_ROM_NVBlockDescriptor_OdometerBLK1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_OdometerBLK2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK2_ROM_NVBlockDescriptor_OdometerBLK2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_OdometerBLK3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK3_ROM_NVBlockDescriptor_OdometerBLK3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_OdometerBLK4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK4_ROM_NVBlockDescriptor_OdometerBLK4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_OdometerBLK5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK5_ROM_NVBlockDescriptor_OdometerBLK5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_ServiceInterval, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ServiceInterval_ROM_NVBlockDescriptor_ServiceInterval; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_ServiceInterval_config, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ServiceInterval_config_ROM_NVBlockDescriptor_ServiceInterval_config; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_TripBase, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_TripBase_ROM_NVBlockDescriptor_TripBase; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer_ROM_NVBlockDescriptor_TripComputer; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_UserSettings, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_UserSettings_ROM_NVBlockDescriptor_UserSettings; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Visteon_EOLConfig, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Visteon_EOLConfig_ROM_NVBlockDescriptor_Visteon_EOLConfig; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

extern CONST(NV_Data_Customer_EOLConfig, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Customer_EOLConfig_ROM_NVBlockDescriptor_Customer_EOLConfig; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDIDFE11, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDFE11_ROM_NVBlockDescriptor_DiagDIDFE11; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Dlt_Fetal_Storage, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Dlt_Fetal_Storage_ROM_NVBlockDescriptor_Dlt_Fetal_Storage; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Dlt_Main_Storage, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Dlt_Main_Storage_ROM_NVBlockDescriptor_Dlt_Main_Storage; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FBLGip_Checker, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLGip_Checker_ROM_NVBlockDescriptor_FBLGip_Checker; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FBLVip_Checker, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLVip_Checker_ROM_NVBlockDescriptor_FBLVip_Checker; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FblSecurityDelay, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FblSecurityDelay_ROM_NVBlockDescriptor_FblSecurityDelay; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FblSecurityFail, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FblSecurityFail_ROM_NVBlockDescriptor_FblSecurityFail; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_HKMCData, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_HKMCData_ROM_NVBlockDescriptor_HKMCData; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_MEETData, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MEETData_ROM_NVBlockDescriptor_MEETData; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_MEETData_config, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MEETData_config_ROM_NVBlockDescriptor_MEETData_config; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_MagicFlag, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MagicFlag_ROM_NVBlockDescriptor_MagicFlag; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_OdometerBLK1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK1_ROM_NVBlockDescriptor_OdometerBLK1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_OdometerBLK2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK2_ROM_NVBlockDescriptor_OdometerBLK2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_OdometerBLK3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK3_ROM_NVBlockDescriptor_OdometerBLK3; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_OdometerBLK4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK4_ROM_NVBlockDescriptor_OdometerBLK4; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_OdometerBLK5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK5_ROM_NVBlockDescriptor_OdometerBLK5; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_ServiceInterval, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ServiceInterval_ROM_NVBlockDescriptor_ServiceInterval; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_ServiceInterval_config, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ServiceInterval_config_ROM_NVBlockDescriptor_ServiceInterval_config; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_TripBase, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_TripBase_ROM_NVBlockDescriptor_TripBase; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_TripComputer, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer_ROM_NVBlockDescriptor_TripComputer; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_UserSettings, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_UserSettings_ROM_NVBlockDescriptor_UserSettings; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Visteon_EOLConfig, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Visteon_EOLConfig_ROM_NVBlockDescriptor_Visteon_EOLConfig; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(EAccStatus_t, RTE_VAR_INIT) Rte_AccMdl_ppAccStatus_AccStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AdasMenuStsMdl_ppAdasMenuStatus_AdasMenusts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_AdasMenuStsMdl_ppHoldOkCueSts_HoldOkCueSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE1_INSTANT_DATA, RTE_VAR_INIT) Rte_AfeMdl_pp_AFE1_Instant_data_AFE1_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE2_INSTANT_DATA, RTE_VAR_INIT) Rte_AfeMdl_pp_AFE2_Instant_data_AFE2_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE3_INSTANT_DATA, RTE_VAR_INIT) Rte_AfeMdl_pp_AFE3_Instant_data_AFE3_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE4_INSTANT_DATA, RTE_VAR_INIT) Rte_AfeMdl_pp_AFE4_Instant_data_AFE4_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE_RESET_INFO, RTE_VAR_INIT) Rte_AfeMdl_pp_Afe_Reset_Info_Reset_Info; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eExecutionState, RTE_VAR_INIT) Rte_AfeMdl_pp_Afe_Run_Status_Run_sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AppSleepType, RTE_VAR_INIT) Rte_AppSleepCtrl_ppAppSleepStatus_AppSleepStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EcuAppM_rpSR_SleepStatus_SleepManager_SleepStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SAvPopupInfo_t, RTE_VAR_INIT) Rte_AvMdl_ppAvPayload_AvPopupInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS1_INSTANT_DATA, RTE_VAR_INIT) Rte_AvsMdl_pp_AVS1_Instant_data_AVS1_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS2_INSTANT_DATA, RTE_VAR_INIT) Rte_AvsMdl_pp_AVS2_Instant_data_AVS2_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS3_INSTANT_DATA, RTE_VAR_INIT) Rte_AvsMdl_pp_AVS3_Instant_data_AVS3_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS_RESET_INFO, RTE_VAR_INIT) Rte_AvsMdl_pp_AVS_Reset_Info_Reset_Info; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eExecutionState, RTE_VAR_INIT) Rte_AvsMdl_pp_AVS_Run_Status_Run_sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AvsMdl_pp_AVS_Status_AVS_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_BattChargeMdl_ppSR_ppTelltaleStatusBattCharge_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_BcwBcaMdl_ppBcwBcaMenuPayload_BCA_10070_WarnPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_BcwBcaMdl_ppBcwBcaMenuPayload_BCA_10080_WarnPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_BtnMdl_ppCruiseSw_Clu_CruiseSwState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_BtnMdl_ppCruiseSw_Clu_SldMainSW; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_BtnMdl_ppCruiseSw_CruiseSwMain_Stat; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FUN_DIAG_RQST_oFUN_DIAG_RQST_oVCAN_b2f0643e_Rx; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TFTRegStatusType, RTE_VAR_INIT) Rte_CDisplayCdd_pp_SR_DisplayCdd_TFTStatus_TFTRegStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_DiagSession_DiagSessionData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_DisplayIlluminationDiagCtrl_DisplayIllumCtrlData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(teDiagFilterBypassMode, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_FilterBypassModeCtrl_DiagFilterBypassModeCtrl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SegmentCtrlType, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_SegmentCtrl_SegmentCtrlData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(teSetAllTelltalesDiagCtrl, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_SetAllTelltalesDiagCtrl_TelltalesDiagCtrlData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_SleepReq_SleepReqData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_ChkEngMdl_ppSR_ppTelltaleStatusChkEng_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_CngFailMdl_ppSR_ppTelltaleStatusCngFail_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CngMdl_ppCngMdl_CNG_Dynamic_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CngMdl_ppCngMdl_CNG_Level; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE1_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_AFE_pp_AFE1_Acc_data_AFE1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE1_OUTPUT, RTE_VAR_INIT) Rte_Core_clag_tc_AFE_pp_AFE1_Calculated_data_AFE1_CALC_DATA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE2_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_AFE_pp_AFE2_Acc_data_AFE2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE2_OUTPUT, RTE_VAR_INIT) Rte_Core_clag_tc_AFE_pp_AFE2_Calculated_data_AFE2_CALC_DATA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE3_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_AFE_pp_AFE3_Acc_data_AFE3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE3_OUTPUT, RTE_VAR_INIT) Rte_Core_clag_tc_AFE_pp_AFE3_Calculated_data_AFE3_CALC_DATA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE4_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_AFE_pp_AFE4_Acc_data_AFE4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AFE4_OUTPUT, RTE_VAR_INIT) Rte_Core_clag_tc_AFE_pp_AFE4_Calculated_data_AFE4_CALC_DATA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS1_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_AVS_pp_AVS1_Accumulated_data_AVS1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS1_OUTPUT, RTE_VAR_INIT) Rte_Core_clag_tc_AVS_pp_AVS1_Calculated_data_AVS1_CALC_DATA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS2_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_AVS_pp_AVS2_Accumulated_data_AVS2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS2_OUTPUT, RTE_VAR_INIT) Rte_Core_clag_tc_AVS_pp_AVS2_Calculated_data_AVS2_CALC_DATA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS3_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_AVS_pp_AVS3_Accumulated_data_AVS3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_AVS3_OUTPUT, RTE_VAR_INIT) Rte_Core_clag_tc_AVS_pp_AVS3_Calculated_data_AVS3_CALC_DATA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT1_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_DRIVETIME_pp_DT1_Accumulated_data_DT1_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT2_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_DRIVETIME_pp_DT2_Accumulated_data_DT2_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT3_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_DRIVETIME_pp_DT3_Accumulated_data_DT3_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT4_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_DRIVETIME_pp_DT4_Accumulated_data_DT4_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT5_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_DRIVETIME_pp_DT5_Accumulated_data_DT5_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT6_ACCUMULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_DRIVETIME_pp_DT6_Accumulated_data_DT6_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Core_clag_tc_DTE_pp_Calculated_data_DTE_CALC_DATA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Core_clag_tc_DTE_pp_DTE_Fuel_level_DTE_Fuel_Level; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_IFE_CALCULATED_DATA, RTE_VAR_INIT) Rte_Core_clag_tc_IFE_pp_IFE_Calculated_Data_Output_IFE; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SCCSL, RTE_VAR_INIT) Rte_CruiseMdl_ppCCSL_HMI_CCSLData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSetMenuSts, RTE_VAR_INIT) Rte_Ctrl_Settings_pp_SetMenuSts_SMenuSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSetMenuStsU16Val, RTE_VAR_INIT) Rte_Ctrl_Settings_pp_SetMenuStsU16Val_SMenuStsU16Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSetMenuStsU32Val, RTE_VAR_INIT) Rte_Ctrl_Settings_pp_SetMenuStsU32Val_SMenuStsU32Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSetMenuStsU8Val, RTE_VAR_INIT) Rte_Ctrl_Settings_pp_SetMenuStsU8Val_SMenuStsU8Val; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDawInfo, RTE_VAR_INIT) Rte_DawMdl_ppDawHMI_DawInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_DawMdl_ppSR_ppTelltaleStatusDaw_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BulbTest, RTE_VAR_INIT) Rte_DcmAdapterMdl_pp_Diag_Status_BulbTestStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(GaugeSweep, RTE_VAR_INIT) Rte_DcmAdapterMdl_pp_Diag_Status_GaugeSweepStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_DimDerateMdl_ppSR_ppTftDeratedDuty_TIRecommendedDuty_RecommendedDuty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimMdl_ppDimMdl_DetentStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimMdl_ppDimMdl_DimmingLevel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimMdl_ppDimMdl_DimmingMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimMdl_ppDimMdl_IlluMenuSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AppSleepType, RTE_VAR_INIT) Rte_DimMdl_ppDimSleepSts_DimSleepStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimMdl_ppHMIGauges_Sts_EnableSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimMdl_ppLedBinIndexSts_LedBinIndexSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDIS, RTE_VAR_INIT) Rte_DisMdl_ppDISInfoHMI_DISData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_DoorMdl_ppDoorPayloadHmi_DoorPayloadData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_DpfMdl_ppSR_ppTelltaleStatusDpf_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDriverAssistMenuInfo, RTE_VAR_INIT) Rte_DriveAssistAdapterMdl_ppDriverAssistMenuInfo_DriverAssistMenuInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_DriveTimeMdl_ppEngRunStatus_EngRunstatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT1_INIT_DATA, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT1_Init_data_DT1_InitData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT2_INIT_DATA, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT2_Init_data_DT2_InitData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT3_INIT_DATA, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT3_Init_data_DT3_InitData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT4_INIT_DATA, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT4_Init_data_DT4_InitData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT5_INIT_DATA, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT5_Init_data_DT5_InitData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT6_INIT_DATA, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT6_Init_data_DT6_InitData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT_INSTANT_DATA, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT_Instant_data_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DT_RESET_INFO, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT_Reset_Info_Reset_Info; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eExecutionState, RTE_VAR_INIT) Rte_DriveTimeMdl_pp_DT_Run_Status_Run_sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DrvModeMdl_ppDrvModeSts_DriveModeLevel; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DrvModeMdl_ppDrvModeSts_DriveModeMood; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EDMSTT_t, RTE_VAR_INIT) Rte_DrvModeMdl_ppDrvModeSts_DriveModeStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_DrvModeMdl_ppSR_ppTelltaleStatusDash_TICurrentTelltaleStatus4_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_DrvModeMdl_ppSR_ppTelltaleStatusEcoGrey_TICurrentTelltaleStatus3_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_DrvModeMdl_ppSR_ppTelltaleStatusEco_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_DrvModeMdl_ppSR_ppTelltaleStatusSport_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_DteCtrl_ppDteReady_Sts_Dte_Ready_Bool; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_DteCtrl_ppDteValue_DteValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_DTE_INSTANT_DATA, RTE_VAR_INIT) Rte_DteMdl_ppDte_Instant_DTE_DTE_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_DteMdl_ppDte_Reset_Sts_Reset_Info; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eExecutionState, RTE_VAR_INIT) Rte_DteMdl_ppDte_Run_Sts_Run_sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_EcallMdl_ppSR_ppTelltaleStatusEcall_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EctMdl_ppEctMdl_EctRedzone; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EctMdl_ppEctMdl_EctTemp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_EcuMExt_pp_SR_EcumExt_RomIntegritycheck_ChecksumStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_EngRunMdl_pp_EngineStatus_EngineStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SEtmInfo, RTE_VAR_INIT) Rte_EtmMdl_ppEtmInfoHMI_EtmInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_EtmMdl_ppEtmsts_EtmStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EtmMdl_ppEtmsts_GaugeSweepSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_EtmMdl_ppEtmsts_HoodChimeSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eEtmTTState, RTE_VAR_INIT) Rte_EtmMdl_ppEtmsts_TTOnOffSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFastGaugeInfo, RTE_VAR_INIT) Rte_FastGaugeCtrl_ppFastGaugesHMI_FastGaugeInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FastGaugeCtrl_ppSR_ppTelltaleStatusSPD_KM_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FastGaugeCtrl_ppSR_ppTelltaleStatusSPD_MI_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FastGaugeCtrl_ppSR_ppTelltaleStatusTACH_KM_TICurrentTelltaleStatus3_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FastGaugeCtrl_ppSR_ppTelltaleStatusTACH_MI_TICurrentTelltaleStatus4_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_FcaMdl_ppFcaMenuPayload_Fca_10032_WarnPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FcaMdl_ppSR_ppTelltaleStatusFcaR_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FcaMdl_ppSR_ppTelltaleStatusFcaY_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FrontFogMdl_ppSR_ppTelltaleStatusFrontFog_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelCtrl_ppFuelValue_FuelValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelCtrl_ppFuelValue_FuelValueUCLDynData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_CAN_FLPS_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_FastFill_Active_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_Fill_Or_Loss_Detected_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_Fuel_Level_Hys_SloshFilterHysValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_Fuel_Level_SloshFilterValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_Init_Completed_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_InlineMode_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_KeyOff_Completed_ReadyForSleepStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_KeyOff_Counter_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_LFW_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_Open_Or_Short_Detected_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_PFH_SloshFilterHysValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_PF_SloshFilterValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_Sender_RAD_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_Unfiltered_FLPS_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_FuelMdl_ppFuelData_ZSS_Counter_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_FuelMdl_Cb_ppFlatSts_FlatStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_FuelMdl_Cb_ppFlatSts_RefuelStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_FuelMdl_Cb_ppFuelValue_RefuelDeltaVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_FuelMdl_Cb_ppFuelValue_RefuelType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FuelModeMdl_ppSR_ppTelltaleStatusCng_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FuelModeMdl_ppSR_ppTelltaleStatusPetrol_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FuelWarnMdl_ppSR_ppTelltaleStatusLF_W_TICurrentTelltaleStatusLF_W_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_FuelWarnMdl_ppSR_ppTelltaleStatusLF_Y_TICurrentTelltaleStatusLF_Y_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_GlowPlugMdl_ppSR_ppTelltaleStatusGlowPlug_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_GngSymblMdl_ppSR_ppTelltaleStatusCngW_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_GngSymblMdl_ppSR_ppTelltaleStatusCngY_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_GngSymblMdl_ppSR_ppTelltaleStatusLF_W_TICurrentTelltaleStatus3_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_GngSymblMdl_ppSR_ppTelltaleStatusLF_Y_TICurrentTelltaleStatus4_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_HbaMdl_ppSR_ppTelltaleStatusHbaG_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_HbaMdl_ppSR_ppTelltaleStatusHbaW_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_HdaLfaMdl_ppSR_ppTelltaleStatusLfaG_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_HdaLfaMdl_ppSR_ppTelltaleStatusLfaGrey_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_HdaLfaMdl_ppSR_ppTelltaleStatusLfaW_TICurrentTelltaleStatus3_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_HiTempMdl_ppSR_ppTelltaleStatusHotTemp_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_HighBeamMdl_ppSR_ppTelltaleStatusHighBeam_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_IfeCtrl_ppIfeUpdateSts_IfeUpdateStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_IfeMdl_ppIfeUpdateSts_IfeUpdateStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CLAG_IFE_INSTANT_DATA, RTE_VAR_INIT) Rte_IfeMdl_pp_IFE_Instant_Data_Instant_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eExecutionState, RTE_VAR_INIT) Rte_IfeMdl_pp_IFE_RunStatus_Run_sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_IllumMdl_ppAutoBrightStepVal_AutoBrightStepVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_IllumMdl_ppAutoBrightStepVal_ProcessedAutoBrightStepVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_ImmoMdl_ppSR_ppTelltaleStatusImmo_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIsgInfo, RTE_VAR_INIT) Rte_IsgMdl_ppIsgHMI_IsgInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_IsgMdl_ppIsgStatus_Menu_sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_IsgMdl_ppIsgStatus_Timer_sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_IsgMdl_ppSR_ppTelltaleStatusIsgG_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_IsgMdl_ppSR_ppTelltaleStatusIsgW_TICurrentTelltaleStatus3_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_IsgMdl_ppSR_ppTelltaleStatusIsgY_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_LampFailMdl_ppSR_ppTelltaleStatusLF_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ELanguageList, RTE_VAR_INIT) Rte_LanguageMdl_ppDefault_lang_Region_Default_Language; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SLanguageInfo, RTE_VAR_INIT) Rte_LanguageMdl_ppLanguageInfoHMI_LanguageInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_LkaMdl_ppSR_ppTelltaleStatusLkaG_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_LkaMdl_ppSR_ppTelltaleStatusLkaGrey_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_LkaMdl_ppSR_ppTelltaleStatusLkaY_TICurrentTelltaleStatus3_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_LowBeamMdl_ppSR_ppTelltaleStatusLowBeam_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_LowCngMdl_ppSR_ppTelltaleStatusCngW_TICurrentTelltaleStatusCngW_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_LowCngMdl_ppSR_ppTelltaleStatusCngY_TICurrentTelltaleStatusCngY_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_MasterSymMdl_ppSR_ppTelltaleStatusMasterSym_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootMagicFlag_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ECUCompatibilityDTCStateAddress; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_FBLValidDTCStateAddress; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_AVN_BRIGHTLEVEL; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_AVN_USM_Settings_Language; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_CLU_USM_Settings_Language; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Current_UserSettingProfile; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Customer_EOL_Byte1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Customer_EOL_Byte2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Customer_EOL_Byte3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Customer_EOL_Byte4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Customer_EOL_Byte5_reserved; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Customer_EOL_Byte6_reserved; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Customer_EOL_Byte7_reserved; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Customer_EOL_Byte8_reserved; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_HOUR_Accuinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_HOUR_AutoStop; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_HOUR_AutoStop1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_HOUR_Refuelinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_MIN_Accuinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_MIN_AutoStop; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_MIN_AutoStop1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_MIN_Refuelinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_SEC_Accuinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_SEC_AutoStop; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_SEC_AutoStop1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_DRIVINGTIME_SEC_Refuelinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Disable_Service_Days; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Disable_Service_Distance; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Dlt_Fetal_Storage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Dlt_Main_Storage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Odo_Checksum; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Odo_Date_Update; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Odo_Dealer_Id; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Odo_Reset_Count; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_RunningTime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_SIA_DAYS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_SIA_ODO; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_ServiceInterval_Reserved_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_ServiceInterval_config_Reserved_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Settings_Fuel_Economy_Reset; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Settings_Fuel_Economy_Unit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Settings_Service_Distance; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Settings_Service_Enable; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Settings_Service_Mode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Settings_Service_Months; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TC_AFE_1_ACCUM_DISTANCE_Accuinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TC_AFE_1_ACCUM_FUEL_Accuinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TC_AFE_2_ACCUM_DISTANCE_Refuelinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TC_AFE_2_ACCUM_FUEL_Refuelinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TC_AVS_1_ACCUM_DISTANCE_Accuinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TC_AVS_1_ACCUM_TIME_Accuinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TC_AVS_2_ACCUM_DISTANCE_Refuelinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TC_AVS_2_ACCUM_TIME_Refuelinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_TripComputer_Reserved_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_Fuel_Economy_Display; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_IceWarning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_Illumination; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_KMMILES; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_KMMILESUSM; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_Theme_Interlocking_Selection; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_Theme_Selection; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_TrafficSign; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_Warning_Volume; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_Welcomesound; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_USM_WiperLight; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_UserSettings_Reserved_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Visteon_EOL_Byte1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Visteon_EOL_Byte2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Visteon_EOL_Byte3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Visteon_EOL_Byte4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Visteon_EOL_Byte5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Visteon_EOL_Byte6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Visteon_EOL_Byte7_reserved; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Visteon_EOL_Byte8_reserved; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Assembly_Mfg_Date; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Customer_EOL_write_history; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Customer_Software_Version; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F190_Veh_Identi_No; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1A0_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1B1_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_FE11_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_ECU_Hardware_Number; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_FE11_Reserved_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_HMC_Part_Number; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_MEETData_Reserved_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_MMCAN_DataBase_Version; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Mfg_Mode_Requested; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Mfg_SerNo_Mfg_Date; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_TripBase_Accuinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_TripBase_Refuelinfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_TripBase_Reserved_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_SecurityDelayTime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_SecurityFailCount; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_MagicFlag, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_MagicFlag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FBLGip_Checker, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLGip_Checker; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FBLVip_Checker, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLVip_Checker; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_UserSettings, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_UserSettings; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Customer_EOLConfig, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Customer_EOLConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_TripComputer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_TripComputer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_ServiceInterval_config, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_ServiceInterval_config; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Dlt_Fetal_Storage, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Dlt_Fetal_Storage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Dlt_Main_Storage, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Dlt_Main_Storage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_MEETData, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_MEETData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_ServiceInterval, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_ServiceInterval; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Visteon_EOLConfig, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Visteon_EOLConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_HKMCData, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_HKMCData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDIDFE11, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDFE11; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_MEETData_config, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_MEETData_config; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_OdometerBLK1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_OdometerBLK2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_OdometerBLK3, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_OdometerBLK4, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_OdometerBLK5, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_TripBase, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_TripBase; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FblSecurityDelay, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FblSecurityDelay; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FblSecurityFail, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FblSecurityFail; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvmAdapterMdl_ppNvmCngInfoHMI_CNGInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ERegionInfo_t, RTE_VAR_INIT) Rte_NvmAdapterMdl_ppNvmRegionInfo_RegionInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EVariantConfig_t, RTE_VAR_INIT) Rte_NvmAdapterMdl_ppNvmVariantInfo_VariantInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SOAT, RTE_VAR_INIT) Rte_OatMdl_ppOatHMI_OATData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_OatMdl_ppSR_ppOatSts_TIOatSts_OatSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eIceWarnStsType, RTE_VAR_INIT) Rte_OatMdl_ppSR_ppOatValue_TIOatMdl_IceWarning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eOatUnit, RTE_VAR_INIT) Rte_OatMdl_ppSR_ppOatValue_TIOatMdl_OatUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SInt16, RTE_VAR_INIT) Rte_OatMdl_ppSR_ppOatValue_TIOatMdl_OatValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_OdoCtrl_ppStoredOdoValue_StoredOdoValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_OdoMdl_ppCalOdoValue_CalculatedOdoValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SOdometer, RTE_VAR_INIT) Rte_OdoMdl_ppOdoValue_OdometerData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_OdoMdl_ppTcOdoData_AvsDistInMeters; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_OdoMdl_ppTcOdoData_OdoTuningFactor; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_OdoMdl_ppTcOdoData_TcDistInMeters; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_OilPresMdl_ppSR_ppTelltaleStatusOil_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_OverSpeedMdl_ppSR_ppTelltaleStatusOverSpd_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_ParkUsmMdl_ppHelpCueSts_HelpCueSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_PocRateMdl_ppPocRatePwmIllOutput_IllOutCurrentValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_PocRateMdl_ppPocRatePwmIllOutput_PwmOutCurrentValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RearFogMdl_ppSR_ppTelltaleStatusRearFog_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ERsbrSeat_t, RTE_VAR_INIT) Rte_RsbrMdl_ppRsbrSeatType_RsbrSeatType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusCB_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusCET_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusCUB_TICurrentTelltaleStatus3_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusLB_TICurrentTelltaleStatus4_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusLET_TICurrentTelltaleStatus5_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusLUB_TICurrentTelltaleStatus6_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusRB_TICurrentTelltaleStatus7_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusRET_TICurrentTelltaleStatus8_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_RsbrMdl_ppSR_ppTelltaleStatusRUB_TICurrentTelltaleStatus9_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SHeaderScc, RTE_VAR_INIT) Rte_SccLfaMdl_ppHeaderSccHMI_HeaderSccData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_SeatBeltMdl_ppSR_ppTelltaleStatusSeatBelt_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SUsmMenuInfo, RTE_VAR_INIT) Rte_SettingsMdl_ppUsmMenuInfo_UsmMenuInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSlowGaugeInfo, RTE_VAR_INIT) Rte_SlowGaugeCtrl_ppSlowGauges_SlowGaugeInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_TachCtrl_ppRpmClip_RPMClipValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_TachCtrl_ppRpmClip_RPMRedzone; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_TachCtrl_ppRpmClip_RPMVariant; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_TachMdl_ppEngRpm_EngineRPM; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_TailLampMdl_ppSR_ppTelltaleStatusTailLamp_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_TailLampMdl_ppTailLamp_TailLampStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STBTMenuInfo, RTE_VAR_INIT) Rte_TbtMdl_ppTBTMenuInfo_TBTMenuInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SThemeInfo, RTE_VAR_INIT) Rte_ThemeSelMdl_ppThemeInfo_ThemeInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_TpmsMdl_ppSR_ppTelltaleStatusTpms_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STpmsMenuInfo, RTE_VAR_INIT) Rte_TpmsMdl_ppTpmsMenuInfoHMI_TpmsMenuInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDTE, RTE_VAR_INIT) Rte_TripAdapterMdl_ppDteHMI_DTEData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STripFuelEcoInfo, RTE_VAR_INIT) Rte_TripAdapterMdl_ppTripFuelEcoInfoHMI_TripFuelEcoInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_TripDistMdl_ppTcAfeDistVal_AfeDistValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_TripDistMdl_ppTcAvsDistVal_AvsDistValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_TripDistMdl_ppTcDteDistVal_DteDistValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_TripDistMdl_ppTcIfeDistVal_IfeDistValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_TripDistMdl_ppTcProcCntr_AVsProcessCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_TripDistMdl_ppTcProcCntr_AfeProcessCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_TripDistMdl_ppTcProcCntr_DteProcessCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_TripDistMdl_ppTcProcCntr_IfeProcessCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_TripFuelMdl_ppTcAfeFuelVal_AfeFuelValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_TripFuelMdl_ppTcDteFuelVal_DteFuelValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_TripFuelMdl_ppTcIfeFuelVal_IfeFuelValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TripResetMdl_pp_AFE_Display_Update_Status_AFE1_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TripResetMdl_pp_AFE_Display_Update_Status_AFE2_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TripResetMdl_pp_AFE_Display_Update_Status_AFE3_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TripResetMdl_pp_AFE_Display_Update_Status_AFE4_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TripResetMdl_pp_AVS_Display_Update_Status_AVS1_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TripResetMdl_pp_AVS_Display_Update_Status_AVS2_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TripResetMdl_pp_AVS_Display_Update_Status_AVS3_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_TurnSigMdl_ppSR_ppTelltaleStatusLeft_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_TurnSigMdl_ppSR_ppTelltaleStatusRight_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TurnSigMdl_ppTTActiveSts_TurnLeft; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_TurnSigMdl_ppTTActiveSts_TurnRight; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DisplayStatus, RTE_VAR_INIT) Rte_UiCtrl_HMI_ppTFTDisplayOnStatus_TFTDisplayOn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_UiCtrl_HMI_pp_HmiSleepSts_HmiSleepSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HMI_Current_Status, RTE_VAR_INIT) Rte_UiCtrl_HMI_pp_Hmi_Current_State_HMIReadyState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Init_status, RTE_VAR_INIT) Rte_UiCtrl_HMI_pp_Hmi_Init_Status_HMIInitStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_UiCtrl_HdrFtr_ppHmiHdrStatus_HmiHdrData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SHelpPopupSts, RTE_VAR_INIT) Rte_UiCtrl_Menu_pp_HelpPopupSts_HelpPopupSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SMenuStatus, RTE_VAR_INIT) Rte_UiCtrl_Menu_pp_MenuStatus_MenuStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_UiCtrl_Menu_pp_SrvIntEntrySts_SrvIntEntrySts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SThemeStatus, RTE_VAR_INIT) Rte_UiCtrl_Menu_pp_ThemeStatus_ThemeStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STripResetCmd, RTE_VAR_INIT) Rte_UiCtrl_Menu_pp_TripResetCmd_TripResetCmdData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SMiniPopupStatus, RTE_VAR_INIT) Rte_UiCtrl_Popup_pp_MiniPopupStatus_MiniPopupStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_UiCtrl_SegmentedDisplay_pp_SLCD_AdasStyLineLeftSts_AdasStyLineLeftStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_UiCtrl_SegmentedDisplay_pp_SLCD_AdasStyLineRghtSts_AdasStyLineRghtStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_UiCtrl_SegmentedDisplay_pp_SLCD_AdasStyLineSts_AdasStyLineStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_UiCtrl_SegmentedDisplay_pp_SLCD_GaugeStatus_GaugeStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_UiCtrl_SegmentedDisplay_pp_SLCD_SpeedSegDig_SpeedSegDigStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_UiCtrl_SegmentedDisplay_pp_SLCD_StyLineSts_StyLineStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STT_Status, RTE_VAR_INIT) Rte_UiCtrl_SegmentedDisplay_pp_TT_HMIStatus_TT_HmiStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SWarningStatus, RTE_VAR_INIT) Rte_UiCtrl_Warning_pp_WarningStatus_WarningStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SUreaLvlInfo, RTE_VAR_INIT) Rte_UreaMdl_ppUreaHMI_UreaLvlInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SMiniPopupDisplay, RTE_VAR_INIT) Rte_Warn_msg_cb_ppMiniPopupData_MiniPopupDisplayData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SStoreMenuConfig, RTE_VAR_INIT) Rte_Warn_msg_cb_ppStoredWrnStsHMI_StoreMenuConfigData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SWarningDisplay, RTE_VAR_INIT) Rte_Warn_msg_cb_ppWrnData_WarningDisplayData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_WatSepMdl_ppSR_ppTelltaleStatusWaterSep_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ETtStatus, RTE_VAR_INIT) Rte_AbsMdl_ppSR_ppTelltaleStatusAbs_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_AirbagMdl_ppSR_ppTelltaleStatusAirBag_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_AutoHoldMdl_ppSR_ppTelltaleStatusAH_G_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_AutoHoldMdl_ppSR_ppTelltaleStatusAH_W_TICurrentTelltaleStatus3_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_AutoHoldMdl_ppSR_ppTelltaleStatusAH_Y_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eBatteryState, RTE_VAR_INIT) Rte_BattMdl_ppBattState_BatteryState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_BattMdl_ppBattState_BatteryVoltage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_BattMdl_ppBattState_IsHighVoltage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_BattMdl_ppBattState_IsLowVoltage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CSigCdd_pp_SigCddSts_win_violation_output; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(data_u8_72, RTE_VAR_INIT) Rte_Ctrl_Telltale_ppSR_ppTelltaleStatusOP_TI_TelltaleStatusOPArray_TelltaleStatusOPArray; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ctrl_Telltale_cb_pp_TT_BlinkStatus_TT_BlinkStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimSafeMdl_ppDimSafeAutoBright_AutoBrightMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_DimSafeMdl_ppDimSafeAutoBright_AutoBrightVariantSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimSafeMdl_ppDimmingMode_DimmingMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DimSafeMdl_ppSlcdErrSts_SLCDErrStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_EpbSafeMdl_ppSR_ppTelltaleStatusEpb_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_EscSafeMdl_ppSR_ppTelltaleStatus_EscOff_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_EscSafeMdl_ppSR_ppTelltaleStatus_Esc_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_GearSafeMdl_ppAmtVarStatus_AmtVariantSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SGearInfo, RTE_VAR_INIT) Rte_GearSafeMdl_ppGearDispHMI_GearInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_GearSafeMdl_ppeClutchStatus_eClutch2PedalVariantSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_GearSafeMdl_ppeClutchStatus_eClutch3PedalVariantSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_MdpsSafeMdl_ppSR_ppTelltaleStatusMdps_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(eIgnState, RTE_VAR_INIT) Rte_ModMdl_ppIgnState_IGNState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIgnState, RTE_VAR_INIT) Rte_ModMdl_ppIgnStateHMI_IgnStateData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_ParkBrakeSafeMdl_ppSR_ppTelltaleStatusParkDom_TICurrentTelltaleStatus2_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETtStatus, RTE_VAR_INIT) Rte_ParkBrakeSafeMdl_ppSR_ppTelltaleStatusPark_TICurrentTelltaleStatus1_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIG_WIN_SETUP_T, RTE_VAR_INIT) Rte_SigUnitCtrl_pp_SigData_sig0_port0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIG_WIN_SETUP_T, RTE_VAR_INIT) Rte_SigUnitCtrl_pp_SigData_sig0_port1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIG_WIN_SETUP_T, RTE_VAR_INIT) Rte_SigUnitCtrl_pp_SigData_sig0_port2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIG_WIN_SETUP_T, RTE_VAR_INIT) Rte_SigUnitCtrl_pp_SigData_sig0_port3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_SpdCtrl_ppSpeedInfo_DigitialSegment_Pos; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdCtrl_ppSpeedInfo_DigitialSpeedometerKPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdCtrl_ppSpeedInfo_DigitialSpeedometerMPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_BiasedSpeed_KPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_BiasedSpeed_MPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_DisplaySpeed_KPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_DisplaySpeed_MPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_DisplaySpeed_Unit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_HWRawSpeed; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_MaxSpeedStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_RawSpeed; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SpeedometerUnit, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_SPEEDOTYPE_Unit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SpeedInputType, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_SpeedInputType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_SpeedStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_Unit_Change_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehicleStateType, RTE_VAR_INIT) Rte_SpdMdl_ppSpeedData_VehicleState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_View_Telltale_ppTT_Sleep_Status_Sleep_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STT_Status, RTE_VAR_INIT) Rte_View_Telltale_ppTftTtStatus_TT_StatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
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

extern VAR(Rte_QRamInfoType, RTE_VAR_NOINIT) Rte_QRamInfo[4]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Rte_QRomInfoType, RTE_CONST) Rte_QRomInfo[4];

#  define RTE_STOP_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_b0 : 1;
  Rte_BitType Rte_b1 : 1;
  Rte_BitType Rte_b2 : 1;
  Rte_BitType Rte_b3 : 1;
} Rte_OsApplication_NonTrusted_QOverflowType;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_QOverflowType, RTE_VAR_NOINIT) Rte_OsApplication_NonTrusted_QOverflow; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_AVN_FCANValueSet_CF_AVN_FCANValueSet : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_CLU_ADASMenu_Shortcut_CF_CLU_ADASMenu_Shortcut : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_CLU_DrvngLampChgnSta_NEW_CF_CLU_DrvngLampChgnSta_NEW : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_CLU_SelfRgnNValueSet_CF_CLU_SelfRgnNValueSet : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_ADrUNValueSet_CF_Clu_ADrUNValueSet : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_AliveCnt1_CF_Clu_AliveCnt1 : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_AliveCnt2_CF_Clu_AliveCnt2 : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_AvgFCU_CF_Clu_AvgFCU : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_CluInfo_CF_Clu_CluInfo : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_ClusterSound_CF_Clu_ClusterSound : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_ClusterUSM_CF_Clu_ClusterUSM : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_CruiseSwState_CF_Clu_CruiseSwState : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_CurrentThemeSta_VCRM_CF_Clu_CurrentThemeSta_VCRM : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_CurrentUtilitySta_VCRM_CF_Clu_CurrentUtilitySta_VCRM : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_LanguageInfo_CF_Clu_LanguageInfo : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_LanguageInfo_NEW_CF_Clu_LanguageInfo_NEW : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_LowfuelWarn_CF_Clu_LowfuelWarn : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_Odometer_CF_Clu_Odometer : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_PaddUpSwState_CF_Clu_PaddUpSwState : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_ParityBit1_CF_Clu_ParityBit1 : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_RrSeatRemindNValueSet_CF_Clu_RrSeatRemindNValueSet : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_TirePressUnitNValueSet_CF_Clu_TirePressUnitNValueSet : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCF_Clu_TripUnit_CF_Clu_TripUnit : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCLU_SCCDispColor_CLU_SCCDispColor : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCLU_SWVerMajor_CLU_SWVerMajor : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCLU_SWVerMinor_CLU_SWVerMinor : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxCLU_Usm_ThemeOpt_CLU_Usm_ThemeOpt : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxClu_OutTempC_Clu_OutTempC : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxClu_Usm_ServiceReminderMode_Clu_Usm_ServiceReminderMode : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxClu_Usm_VoiceVolume_Clu_Usm_VoiceVolume : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxUSM_AdasFCAJnctnSetReq_USM_AdasFCAJnctnSetReq : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxWarn_Sound_LKA_HndsoffSnd_Warn_Sound_LKA_HndsoffSnd : 2;
  Rte_BitType Rte_TxAck_CComAbsMdl_pp_SR_TxWarn_Sound_SeatBelt_Warn_Sound_SeatBelt : 2;
  Rte_BitType Rte_TxAck_CComAbsSafe_pp_SR_TxCF_Clu_SWL_Stat_CF_Clu_SWL_Stat : 2;
  Rte_BitType Rte_TxAck_CComAbsSafe_pp_SR_TxCF_Clu_VanzDecimal_CF_Clu_VanzDecimal : 2;
  Rte_BitType Rte_TxAck_CComAbsSafe_pp_SR_TxCF_Clu_VehicleSpeed_CF_Clu_VehicleSpeed : 2;
} Rte_OsApplication_NonTrusted_AckFlagsType;

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_AckFlagsType, RTE_VAR_INIT) Rte_OsApplication_NonTrusted_AckFlags; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Customer_EOLConfig : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDFE11 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Dlt_Fetal_Storage : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Dlt_Main_Storage : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FBLGip_Checker : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FBLVip_Checker : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FblSecurityDelay : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FblSecurityFail : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_HKMCData : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_MEETData : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_MEETData_config : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_MagicFlag : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK2 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK3 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK4 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_OdometerBLK5 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_ServiceInterval : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_ServiceInterval_config : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_TripBase : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_TripComputer : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_UserSettings : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Visteon_EOLConfig : 1;
} Rte_DirtyFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_DirtyFlagsType, RTE_VAR_ZERO_INIT) Rte_DirtyFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * RTE internal IOC replacement
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(STTChecksumSts, RTE_VAR_NOINIT) Rte_ioc_Rte_AppSafeCtrl_rSRTTChecksumSts_TTChecksumStsData_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_AppSafeCtrl_rSRTTChecksumSts_TTChecksumStsData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_AppSafeCtrl_rSRTTChecksumSts_TTChecksumStsData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(STTChecksumSts, RTE_VAR_NOINIT) Rte_ioc_Rte_UclSafeAdapterMdl_rSR_TTChecksumSts_TTChecksumStsData_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_UclSafeAdapterMdl_rSR_TTChecksumSts_TTChecksumStsData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclSafeAdapterMdl_rSR_TTChecksumSts_TTChecksumStsData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_AppSafeCtrl_rSRTTChecksumSts_TTChecksumStsData_overflow0 : 1;
  Rte_BitType Rte_AppSafeCtrl_rSRTTChecksumSts_TTChecksumStsData_overflow1 : 1;
  Rte_BitType Rte_UclSafeAdapterMdl_rSR_TTChecksumSts_TTChecksumStsData_overflow0 : 1;
  Rte_BitType Rte_UclSafeAdapterMdl_rSR_TTChecksumSts_TTChecksumStsData_overflow1 : 1;
} Rte_OsApplication_Trusted_IocOverflowFlagsType;

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_Trusted_IocOverflowFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Trusted_IocOverflowFlags;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

/* Queue element type definitions for internal C/S connections */

typedef struct
{
  Rte_BitType Rte_Idle_GdtCdd_rp_TIGdtCtrl_RenderDone : 1;
} Rte_OsApplication_NonTrusted_ClientIdleFlagsType;

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_ClientIdleFlagsType, RTE_VAR_INIT) Rte_OsApplication_NonTrusted_ClientIdleFlags;

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


typedef struct
{
  boolean Rte_CallCompleted;
} Rte_CS_ClientQueueType_GdtCtrl_pp_TIGdtCtrl_RenderDone;

typedef struct
{
  P2VAR(Rte_CS_ClientQueueType_GdtCtrl_pp_TIGdtCtrl_RenderDone, TYPEDEF, RTE_VAR_NOINIT) Rte_ClientQueue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
} Rte_CS_ClientConfigType_GdtCtrl_pp_TIGdtCtrl_RenderDone;

typedef struct
{
  uint8 Rte_ClientId;
} Rte_CS_ServerQueueType_GdtCtrl_pp_TIGdtCtrl_RenderDone;

typedef struct
{
  uint8 Rte_Active;
} Rte_CS_ServerQueueInfoType_GdtCtrl_pp_TIGdtCtrl_RenderDone;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_CS_ServerQueueType_GdtCtrl_pp_TIGdtCtrl_RenderDone, RTE_VAR_NOINIT) Rte_CS_ServerQueue_GdtCtrl_pp_TIGdtCtrl_RenderDone; /* PRQA S 0850, 3229 */ /* MD_MSR_19.8, MD_Rte_Qac */
extern VAR(Rte_CS_ServerQueueInfoType_GdtCtrl_pp_TIGdtCtrl_RenderDone, RTE_VAR_NOINIT) Rte_CS_ServerQueueInfo_GdtCtrl_pp_TIGdtCtrl_RenderDone; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(Rte_CS_ClientQueueType_GdtCtrl_pp_TIGdtCtrl_RenderDone, RTE_VAR_NOINIT) Rte_CS_ClientQueue_GdtCdd_rp_TIGdtCtrl_RenderDone; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Rte_CS_ClientConfigType_GdtCtrl_pp_TIGdtCtrl_RenderDone, RTE_CONST) Rte_CS_ClientConfig_GdtCtrl_pp_TIGdtCtrl_RenderDone[1]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_CONST_UNSPECIFIED
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

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
