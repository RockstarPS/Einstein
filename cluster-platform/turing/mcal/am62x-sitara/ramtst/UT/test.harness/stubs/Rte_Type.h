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
 *        Config:  iMX8.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700905 for Visteon Electronics Germany GmbH
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

# define Rte_TypeDef_ComMExt_IpduGroupId
typedef uint8 ComMExt_IpduGroupId;

# define Rte_TypeDef_Dcm_MsgType
typedef uint8 *Dcm_MsgType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

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

# define Rte_TypeDef_Guest_Login_Data_AlertSetting_ref
typedef uint32 Guest_Login_Data_AlertSetting_ref;

# define Rte_TypeDef_Guest_Login_Data_Top_ref
typedef uint32 Guest_Login_Data_Top_ref;

# define Rte_TypeDef_Guest_Login_Data_ref
typedef uint8 Guest_Login_Data_ref;

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_Rte_DT_AVAILABLE_TIME_ZONE_TYPE_0
typedef uint8 Rte_DT_AVAILABLE_TIME_ZONE_TYPE_0;

# define Rte_TypeDef_Rte_DT_Ad2SurrVehInfo_0
typedef uint8 Rte_DT_Ad2SurrVehInfo_0;

# define Rte_TypeDef_Rte_DT_Ad2SurrVehSts_0
typedef uint8 Rte_DT_Ad2SurrVehSts_0;

# define Rte_TypeDef_Rte_DT_BaseVoltageT_0
typedef uint8 Rte_DT_BaseVoltageT_0;

# define Rte_TypeDef_Rte_DT_ComMsgPoint_0
typedef uint16 Rte_DT_ComMsgPoint_0;

# define Rte_TypeDef_Rte_DT_Crc_IN_Type_0
typedef uint8 Rte_DT_Crc_IN_Type_0;

# define Rte_TypeDef_Rte_DT_CutOffMaskT_0
typedef uint8 Rte_DT_CutOffMaskT_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_100_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_100_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_200_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_200_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_300_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_300_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_400_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_400_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F011_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F011_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F012_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F012_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F013_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F013_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F187_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F187_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F18A_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F18A_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F18C_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F18C_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F190_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F190_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F191_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F191_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F194_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F194_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F195_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F195_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F1A1_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F1A1_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_F1A2_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_F1A2_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DIAG_DID_FE11_Data_ref_0
typedef uint8 Rte_DT_DIAG_DID_FE11_Data_ref_0;

# define Rte_TypeDef_Rte_DT_DTCStatusArrayT_0
typedef uint8 Rte_DT_DTCStatusArrayT_0;

# define Rte_TypeDef_Rte_DT_DistanceUnitT_0
typedef uint8 Rte_DT_DistanceUnitT_0;

# define Rte_TypeDef_Rte_DT_ECUHwCodeT_0
typedef uint8 Rte_DT_ECUHwCodeT_0;

# define Rte_TypeDef_Rte_DT_ECUSwNumberT_0
typedef uint8 Rte_DT_ECUSwNumberT_0;

# define Rte_TypeDef_Rte_DT_ECUSwVersionDateT_0
typedef uint8 Rte_DT_ECUSwVersionDateT_0;

# define Rte_TypeDef_Rte_DT_ECUSwVersionPCBCodeT_0
typedef uint8 Rte_DT_ECUSwVersionPCBCodeT_0;

# define Rte_TypeDef_Rte_DT_ECUVoltageT_0
typedef uint16 Rte_DT_ECUVoltageT_0;

# define Rte_TypeDef_Rte_DT_EFotaVinResponseType_0
typedef uint8 Rte_DT_EFotaVinResponseType_0;

# define Rte_TypeDef_Rte_DT_ETMStringT_0
typedef uint16 Rte_DT_ETMStringT_0;

# define Rte_TypeDef_Rte_DT_ExtTempT_0
typedef uint16 Rte_DT_ExtTempT_0;

# define Rte_TypeDef_Rte_DT_FuelVolTablConfigSize_0
typedef uint16 Rte_DT_FuelVolTablConfigSize_0;

# define Rte_TypeDef_Rte_DT_GIP_ResetReason_Type_0
typedef uint8 Rte_DT_GIP_ResetReason_Type_0;

# define Rte_TypeDef_Rte_DT_GadeT_0
typedef uint8 Rte_DT_GadeT_0;

# define Rte_TypeDef_Rte_DT_Gauge_Correction_Table_X_0
typedef uint16 Rte_DT_Gauge_Correction_Table_X_0;

# define Rte_TypeDef_Rte_DT_Gauge_Correction_Table_Y_0
typedef uint16 Rte_DT_Gauge_Correction_Table_Y_0;

# define Rte_TypeDef_Rte_DT_Gauge_Mapping_Table_X_0
typedef uint16 Rte_DT_Gauge_Mapping_Table_X_0;

# define Rte_TypeDef_Rte_DT_Gauge_Mapping_Table_Y_0
typedef uint16 Rte_DT_Gauge_Mapping_Table_Y_0;

# define Rte_TypeDef_Rte_DT_HFE2MinsValueType_0
typedef uint16 Rte_DT_HFE2MinsValueType_0;

# define Rte_TypeDef_Rte_DT_HFEValueType_0
typedef uint16 Rte_DT_HFEValueType_0;

# define Rte_TypeDef_Rte_DT_HandBrakeT_0
typedef uint8 Rte_DT_HandBrakeT_0;

# define Rte_TypeDef_Rte_DT_IGNStatusT_0
typedef uint8 Rte_DT_IGNStatusT_0;

# define Rte_TypeDef_Rte_DT_Ikey_Link_Data_AlertSetting_ref_0
typedef uint32 Rte_DT_Ikey_Link_Data_AlertSetting_ref_0;

# define Rte_TypeDef_Rte_DT_Ikey_Link_Data_Top_ref_0
typedef uint32 Rte_DT_Ikey_Link_Data_Top_ref_0;

# define Rte_TypeDef_Rte_DT_Ikey_Link_Data_ref_0
typedef uint8 Rte_DT_Ikey_Link_Data_ref_0;

# define Rte_TypeDef_Rte_DT_IndicatorOutputType_0
typedef uint8 Rte_DT_IndicatorOutputType_0;

# define Rte_TypeDef_Rte_DT_LaneMarker_0
typedef uint8 Rte_DT_LaneMarker_0;

# define Rte_TypeDef_Rte_DT_Language_Cfg_Type_0
typedef uint8 Rte_DT_Language_Cfg_Type_0;

# define Rte_TypeDef_Rte_DT_MainMenuArrayT_0
typedef uint8 Rte_DT_MainMenuArrayT_0;

# define Rte_TypeDef_Rte_DT_MasterWakeupCommandT_0
typedef uint8 Rte_DT_MasterWakeupCommandT_0;

# define Rte_TypeDef_Rte_DT_NV_FuelTable_ref_0
typedef uint16 Rte_DT_NV_FuelTable_ref_0;

# define Rte_TypeDef_Rte_DT_NV_IllumDutyTable_ref_0
typedef uint16 Rte_DT_NV_IllumDutyTable_ref_0;

# define Rte_TypeDef_Rte_DT_NV_SigmaDataIndexArray_T_0
typedef uint8 Rte_DT_NV_SigmaDataIndexArray_T_0;

# define Rte_TypeDef_Rte_DT_NV_SigmaSSD_T_0
typedef uint8 Rte_DT_NV_SigmaSSD_T_0;

# define Rte_TypeDef_Rte_DT_NV_SigmaTimeData_T_0
typedef uint8 Rte_DT_NV_SigmaTimeData_T_0;

# define Rte_TypeDef_Rte_DT_NV_SigmaVTD_T_0
typedef uint8 Rte_DT_NV_SigmaVTD_T_0;

# define Rte_TypeDef_Rte_DT_OAT_ADC_Count_ref_0
typedef uint16 Rte_DT_OAT_ADC_Count_ref_0;

# define Rte_TypeDef_Rte_DT_OAT_TempDeg_ref_0
typedef sint8 Rte_DT_OAT_TempDeg_ref_0;

# define Rte_TypeDef_Rte_DT_ReprogBufferType_0
typedef uint8 Rte_DT_ReprogBufferType_0;

# define Rte_TypeDef_Rte_DT_SafeTTResponseBufferType_0
typedef uint8 Rte_DT_SafeTTResponseBufferType_0;

# define Rte_TypeDef_Rte_DT_SafeTTStatusBufferType_0
typedef uint8 Rte_DT_SafeTTStatusBufferType_0;

# define Rte_TypeDef_Rte_DT_SigmaFrameT_0
typedef uint8 Rte_DT_SigmaFrameT_0;

# define Rte_TypeDef_Rte_DT_SlaveRefuseToSleepT_0
typedef uint8 Rte_DT_SlaveRefuseToSleepT_0;

# define Rte_TypeDef_Rte_DT_TFotaVersion_0
typedef uint8 Rte_DT_TFotaVersion_0;

# define Rte_TypeDef_Rte_DT_TTBlinkArray_0
typedef uint8 Rte_DT_TTBlinkArray_0;

# define Rte_TypeDef_Rte_DT_TT_OP_Type_0
typedef uint8 Rte_DT_TT_OP_Type_0;

# define Rte_TypeDef_Rte_DT_UI_AUDIO_SOURCE_AVAILABLE_T_0
typedef uint8 Rte_DT_UI_AUDIO_SOURCE_AVAILABLE_T_0;

# define Rte_TypeDef_Rte_DT_UI_FREQ_ARRAY_0
typedef uint32 Rte_DT_UI_FREQ_ARRAY_0;

# define Rte_TypeDef_Rte_DT_UI_LANE_ARROW_TYPE_T_0
typedef uint16 Rte_DT_UI_LANE_ARROW_TYPE_T_0;

# define Rte_TypeDef_Rte_DT_UI_NAVI_DISTANCE_ARRAY_T_0
typedef uint32 Rte_DT_UI_NAVI_DISTANCE_ARRAY_T_0;

# define Rte_TypeDef_Rte_DT_UI_RA_EXIT_NUMBER_T_0
typedef uint8 Rte_DT_UI_RA_EXIT_NUMBER_T_0;

# define Rte_TypeDef_Rte_DT_UI_TEXT_BUFFER_T_0
typedef uint32 Rte_DT_UI_TEXT_BUFFER_T_0;

# define Rte_TypeDef_Rte_DT_UI_TV_CHANNEL_T_0
typedef uint32 Rte_DT_UI_TV_CHANNEL_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_10_ref_T_0
typedef uint8 Rte_DT_Uint8Array_10_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_16_ref_T_0
typedef uint8 Rte_DT_Uint8Array_16_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_17_ref_T_0
typedef uint8 Rte_DT_Uint8Array_17_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_18_ref_T_0
typedef uint8 Rte_DT_Uint8Array_18_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_20_ref_T_0
typedef uint8 Rte_DT_Uint8Array_20_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_3_ref_T_0
typedef uint8 Rte_DT_Uint8Array_3_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_4_ref_T_0
typedef uint8 Rte_DT_Uint8Array_4_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_5_ref_T_0
typedef uint8 Rte_DT_Uint8Array_5_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8Array_8_ref_T_0
typedef uint8 Rte_DT_Uint8Array_8_ref_T_0;

# define Rte_TypeDef_Rte_DT_Uint8FotaArray_6_ref_T_0
typedef uint8 Rte_DT_Uint8FotaArray_6_ref_T_0;

# define Rte_TypeDef_Rte_DT_Ul_LANE_ARROW_GUIDE_INFO_T_0
typedef uint8 Rte_DT_Ul_LANE_ARROW_GUIDE_INFO_T_0;

# define Rte_TypeDef_Rte_DT_Ul_VR_DIGITS_0
typedef uint32 Rte_DT_Ul_VR_DIGITS_0;

# define Rte_TypeDef_Rte_DT_User_Login_Data_AlertSetting_ref_0
typedef uint32 Rte_DT_User_Login_Data_AlertSetting_ref_0;

# define Rte_TypeDef_Rte_DT_User_Login_Data_Top_ref_0
typedef uint32 Rte_DT_User_Login_Data_Top_ref_0;

# define Rte_TypeDef_Rte_DT_User_Login_Data_ref_0
typedef uint8 Rte_DT_User_Login_Data_ref_0;

# define Rte_TypeDef_Rte_DT_VehiclePosType_0
typedef uint8 Rte_DT_VehiclePosType_0;

# define Rte_TypeDef_Rte_DT_VehicleSpeedT_0
typedef uint16 Rte_DT_VehicleSpeedT_0;

# define Rte_TypeDef_Rte_DT_VehicleStsType_0
typedef uint8 Rte_DT_VehicleStsType_0;

# define Rte_TypeDef_Rte_DT_Visteon_Product_Config_Data_ref_0
typedef uint8 Rte_DT_Visteon_Product_Config_Data_ref_0;

# define Rte_TypeDef_Rte_DT_WICodeT_0
typedef uint16 Rte_DT_WICodeT_0;

# define Rte_TypeDef_Rte_DT_data_u16_10_0
typedef uint16 Rte_DT_data_u16_10_0;

# define Rte_TypeDef_Rte_DT_data_u16_15_0
typedef uint16 Rte_DT_data_u16_15_0;

# define Rte_TypeDef_Rte_DT_data_u16_16_0
typedef uint16 Rte_DT_data_u16_16_0;

# define Rte_TypeDef_Rte_DT_data_u16_3_0
typedef uint16 Rte_DT_data_u16_3_0;

# define Rte_TypeDef_Rte_DT_data_u16_50_0
typedef uint16 Rte_DT_data_u16_50_0;

# define Rte_TypeDef_Rte_DT_data_u16_6_0
typedef uint16 Rte_DT_data_u16_6_0;

# define Rte_TypeDef_Rte_DT_data_u32_3_0
typedef uint32 Rte_DT_data_u32_3_0;

# define Rte_TypeDef_Rte_DT_data_u32_50_0
typedef uint32 Rte_DT_data_u32_50_0;

# define Rte_TypeDef_Rte_DT_data_u32_6_0
typedef uint32 Rte_DT_data_u32_6_0;

# define Rte_TypeDef_Rte_DT_data_u8_10_0
typedef uint8 Rte_DT_data_u8_10_0;

# define Rte_TypeDef_Rte_DT_data_u8_12_0
typedef uint8 Rte_DT_data_u8_12_0;

# define Rte_TypeDef_Rte_DT_data_u8_130_0
typedef uint8 Rte_DT_data_u8_130_0;

# define Rte_TypeDef_Rte_DT_data_u8_15_0
typedef uint8 Rte_DT_data_u8_15_0;

# define Rte_TypeDef_Rte_DT_data_u8_17_0
typedef uint8 Rte_DT_data_u8_17_0;

# define Rte_TypeDef_Rte_DT_data_u8_256_0
typedef uint8 Rte_DT_data_u8_256_0;

# define Rte_TypeDef_Rte_DT_data_u8_25_0
typedef uint8 Rte_DT_data_u8_25_0;

# define Rte_TypeDef_Rte_DT_data_u8_280_0
typedef uint8 Rte_DT_data_u8_280_0;

# define Rte_TypeDef_Rte_DT_data_u8_300_0
typedef uint8 Rte_DT_data_u8_300_0;

# define Rte_TypeDef_Rte_DT_data_u8_320_0
typedef uint8 Rte_DT_data_u8_320_0;

# define Rte_TypeDef_Rte_DT_data_u8_32_0
typedef uint8 Rte_DT_data_u8_32_0;

# define Rte_TypeDef_Rte_DT_data_u8_35_0
typedef uint8 Rte_DT_data_u8_35_0;

# define Rte_TypeDef_Rte_DT_data_u8_3_0
typedef uint8 Rte_DT_data_u8_3_0;

# define Rte_TypeDef_Rte_DT_data_u8_40_0
typedef uint8 Rte_DT_data_u8_40_0;

# define Rte_TypeDef_Rte_DT_data_u8_4_0
typedef uint8 Rte_DT_data_u8_4_0;

# define Rte_TypeDef_Rte_DT_data_u8_50_0
typedef uint8 Rte_DT_data_u8_50_0;

# define Rte_TypeDef_Rte_DT_data_u8_5_0
typedef uint8 Rte_DT_data_u8_5_0;

# define Rte_TypeDef_Rte_DT_data_u8_60_0
typedef uint8 Rte_DT_data_u8_60_0;

# define Rte_TypeDef_Rte_DT_data_u8_65_0
typedef uint8 Rte_DT_data_u8_65_0;

# define Rte_TypeDef_Rte_DT_data_u8_75_0
typedef uint8 Rte_DT_data_u8_75_0;

# define Rte_TypeDef_Rte_DT_data_u8_8_0
typedef uint8 Rte_DT_data_u8_8_0;

# define Rte_TypeDef_Rte_DT_received_data_0
typedef uint8 Rte_DT_received_data_0;

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;

# define Rte_TypeDef_SInt8
typedef sint8 SInt8;

# define Rte_TypeDef_SettingsID
typedef uint32 SettingsID;

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

# define Rte_TypeDef_AD1StatusType
typedef uint8 AD1StatusType;

# define Rte_TypeDef_ADBPopUpT
typedef uint8 ADBPopUpT;

# define Rte_TypeDef_ADBPopUpTrigger
typedef uint8 ADBPopUpTrigger;

# define Rte_TypeDef_AFSwarningT
typedef uint8 AFSwarningT;

# define Rte_TypeDef_AccStatusType
typedef uint8 AccStatusType;

# define Rte_TypeDef_AccelMenuAvailability
typedef uint8 AccelMenuAvailability;

# define Rte_TypeDef_AccentLightingT
typedef uint8 AccentLightingT;

# define Rte_TypeDef_Ad1l3BackColor
typedef uint8 Ad1l3BackColor;

# define Rte_TypeDef_Ad1l3LaneCurveSts
typedef uint8 Ad1l3LaneCurveSts;

# define Rte_TypeDef_Ad1l3LaneGap
typedef uint8 Ad1l3LaneGap;

# define Rte_TypeDef_Ad1l3LaneHov
typedef uint8 Ad1l3LaneHov;

# define Rte_TypeDef_Ad1l3LaneLeftSts
typedef uint8 Ad1l3LaneLeftSts;

# define Rte_TypeDef_Ad1l3LaneRightSts
typedef uint8 Ad1l3LaneRightSts;

# define Rte_TypeDef_Ad1l3LaneSts
typedef uint8 Ad1l3LaneSts;

# define Rte_TypeDef_Ad1l3StatusDisplay
typedef sint32 Ad1l3StatusDisplay;

# define Rte_TypeDef_Ad1l3ViewMode
typedef uint8 Ad1l3ViewMode;

# define Rte_TypeDef_Ad1lv3TJPPayloadS
typedef uint8 Ad1lv3TJPPayloadS;

# define Rte_TypeDef_Ad2AlcNumber
typedef uint8 Ad2AlcNumber;

# define Rte_TypeDef_AlcIconStatus
typedef uint8 AlcIconStatus;

# define Rte_TypeDef_AnimSoundStsT
typedef uint8 AnimSoundStsT;

# define Rte_TypeDef_AutoUnlock
typedef uint8 AutoUnlock;

# define Rte_TypeDef_Awd4wdAvlTypeT
typedef uint8 Awd4wdAvlTypeT;

# define Rte_TypeDef_BCIStatusType
typedef uint8 BCIStatusType;

# define Rte_TypeDef_BFEUpdate
typedef uint8 BFEUpdate;

# define Rte_TypeDef_BLDriveStateT
typedef uint8 BLDriveStateT;

# define Rte_TypeDef_BSIBSWType
typedef uint8 BSIBSWType;

# define Rte_TypeDef_BSIStatusType
typedef uint8 BSIStatusType;

# define Rte_TypeDef_BSWBSIMainMenuType
typedef uint8 BSWBSIMainMenuType;

# define Rte_TypeDef_BSWStatusType
typedef uint8 BSWStatusType;

# define Rte_TypeDef_BatModeCursorStateT
typedef uint8 BatModeCursorStateT;

# define Rte_TypeDef_BatteryModeDisplayT
typedef uint8 BatteryModeDisplayT;

# define Rte_TypeDef_BatteryModeInterruptPayload
typedef uint8 BatteryModeInterruptPayload;

# define Rte_TypeDef_BatteryNotPermitPayload
typedef uint8 BatteryNotPermitPayload;

# define Rte_TypeDef_BatteryWheelT
typedef uint8 BatteryWheelT;

# define Rte_TypeDef_BatteryZEVCancelPayload
typedef uint8 BatteryZEVCancelPayload;

# define Rte_TypeDef_BlinkStatusType
typedef uint8 BlinkStatusType;

# define Rte_TypeDef_BrakeLampStateT
typedef uint8 BrakeLampStateT;

# define Rte_TypeDef_BulbTestStatus
typedef uint16 BulbTestStatus;

# define Rte_TypeDef_ButtonEtmStatus
typedef uint8 ButtonEtmStatus;

# define Rte_TypeDef_ButtonEvents
typedef uint8 ButtonEvents;

# define Rte_TypeDef_ButtonID
typedef uint8 ButtonID;

# define Rte_TypeDef_CANFaultConfigID
typedef uint8 CANFaultConfigID;

# define Rte_TypeDef_CANIpWakeUpState
typedef uint8 CANIpWakeUpState;

# define Rte_TypeDef_CANNMState
typedef uint8 CANNMState;

# define Rte_TypeDef_CLOCK_AVAILABLE_STATE_TYPE
typedef uint8 CLOCK_AVAILABLE_STATE_TYPE;

# define Rte_TypeDef_CLOCK_CLOCK_TYPE
typedef uint8 CLOCK_CLOCK_TYPE;

# define Rte_TypeDef_CLOCK_MODE_INFO_STATES_TYPE
typedef uint8 CLOCK_MODE_INFO_STATES_TYPE;

# define Rte_TypeDef_CLOCK_MODE_TYPE
typedef uint8 CLOCK_MODE_TYPE;

# define Rte_TypeDef_CLOCK_Msg_Type
typedef uint8 CLOCK_Msg_Type;

# define Rte_TypeDef_CLOCK_PARAMETER_TYPE
typedef uint8 CLOCK_PARAMETER_TYPE;

# define Rte_TypeDef_CTAStatusType
typedef uint8 CTAStatusType;

# define Rte_TypeDef_CaptionStatus
typedef uint8 CaptionStatus;

# define Rte_TypeDef_ChangeLanguage
typedef uint8 ChangeLanguage;

# define Rte_TypeDef_CheckSumMemoryId
typedef uint8 CheckSumMemoryId;

# define Rte_TypeDef_ChecksumStatusT
typedef uint8 ChecksumStatusT;

# define Rte_TypeDef_ChimeID
typedef uint8 ChimeID;

# define Rte_TypeDef_ChimeRequestT
typedef uint8 ChimeRequestT;

# define Rte_TypeDef_ChimeStatusT
typedef uint8 ChimeStatusT;

# define Rte_TypeDef_ClkStateT
typedef uint8 ClkStateT;

# define Rte_TypeDef_ClockConfigType
typedef uint8 ClockConfigType;

# define Rte_TypeDef_ClockDisplaySts
typedef uint8 ClockDisplaySts;

# define Rte_TypeDef_ClockMenuEnterExit
typedef uint8 ClockMenuEnterExit;

# define Rte_TypeDef_ClusterModeStatus
typedef uint8 ClusterModeStatus;

# define Rte_TypeDef_CombLightSWType_CF_Type
typedef uint8 CombLightSWType_CF_Type;

# define Rte_TypeDef_CombWiperSWType_CF_Type
typedef uint8 CombWiperSWType_CF_Type;

# define Rte_TypeDef_CombiRearWiperSwStatus
typedef uint8 CombiRearWiperSwStatus;

# define Rte_TypeDef_CombiSWLightOPType
typedef uint8 CombiSWLightOPType;

# define Rte_TypeDef_CombiSWWiperLevelType
typedef uint8 CombiSWWiperLevelType;

# define Rte_TypeDef_CombiSWWiperSwStatus
typedef uint8 CombiSWWiperSwStatus;

# define Rte_TypeDef_CombiSWWiperSwType
typedef uint8 CombiSWWiperSwType;

# define Rte_TypeDef_CombiSwLightStatus
typedef uint8 CombiSwLightStatus;

# define Rte_TypeDef_CommStatusType
typedef uint8 CommStatusType;

# define Rte_TypeDef_Communication_T
typedef uint8 Communication_T;

# define Rte_TypeDef_CrankStatusType
typedef uint8 CrankStatusType;

# define Rte_TypeDef_CrcCdd_Index
typedef uint8 CrcCdd_Index;

# define Rte_TypeDef_CrcStateT
typedef uint8 CrcStateT;

# define Rte_TypeDef_CriticalSleepComponentIdx
typedef uint8 CriticalSleepComponentIdx;

# define Rte_TypeDef_CruisPopUpTrigger
typedef uint8 CruisPopUpTrigger;

# define Rte_TypeDef_CruiseCancelPopUpEnum
typedef uint8 CruiseCancelPopUpEnum;

# define Rte_TypeDef_CruisePayload
typedef uint8 CruisePayload;

# define Rte_TypeDef_CruiseSlPopUpEnum
typedef uint8 CruiseSlPopUpEnum;

# define Rte_TypeDef_CruiseSpeedUnitColorT
typedef uint8 CruiseSpeedUnitColorT;

# define Rte_TypeDef_CruiseStatusType
typedef uint8 CruiseStatusType;

# define Rte_TypeDef_Cruisiccguidance
typedef uint8 Cruisiccguidance;

# define Rte_TypeDef_CurrentLaneActionUnitT
typedef uint8 CurrentLaneActionUnitT;

# define Rte_TypeDef_CurrentUIModeType
typedef uint8 CurrentUIModeType;

# define Rte_TypeDef_CurveRoadStatusType
typedef uint8 CurveRoadStatusType;

# define Rte_TypeDef_DASEvtT
typedef uint8 DASEvtT;

# define Rte_TypeDef_DAYLIGHT_SAVING_TYPE
typedef uint8 DAYLIGHT_SAVING_TYPE;

# define Rte_TypeDef_DCAStatusType
typedef uint8 DCAStatusType;

# define Rte_TypeDef_DTCClearT
typedef uint8 DTCClearT;

# define Rte_TypeDef_DTCCurrentStatusT
typedef uint8 DTCCurrentStatusT;

# define Rte_TypeDef_DTCIdT
typedef uint8 DTCIdT;

# define Rte_TypeDef_DTEWarningType
typedef uint8 DTEWarningType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_DefaultUnit_T
typedef uint8 DefaultUnit_T;

# define Rte_TypeDef_DeratingCFT
typedef uint8 DeratingCFT;

# define Rte_TypeDef_DeratingEndPointPWMT
typedef uint8 DeratingEndPointPWMT;

# define Rte_TypeDef_DeratingEndPointTempT
typedef uint8 DeratingEndPointTempT;

# define Rte_TypeDef_DeratingFaultPointTempT
typedef uint8 DeratingFaultPointTempT;

# define Rte_TypeDef_DeratingStartPointTempT
typedef uint8 DeratingStartPointTempT;

# define Rte_TypeDef_DiagConfiguration_T
typedef uint8 DiagConfiguration_T;

# define Rte_TypeDef_DiagFaultStatesType
typedef uint8 DiagFaultStatesType;

# define Rte_TypeDef_DiagGearNumber
typedef uint8 DiagGearNumber;

# define Rte_TypeDef_DiagRespEvt
typedef uint8 DiagRespEvt;

# define Rte_TypeDef_DiagWriteDIDT
typedef uint32 DiagWriteDIDT;

# define Rte_TypeDef_DialDesignStdT
typedef uint8 DialDesignStdT;

# define Rte_TypeDef_DialDesignTypeT
typedef uint8 DialDesignTypeT;

# define Rte_TypeDef_DimmingModeType
typedef uint8 DimmingModeType;

# define Rte_TypeDef_DisplayModeT
typedef uint8 DisplayModeT;

# define Rte_TypeDef_DisplayStatus
typedef uint8 DisplayStatus;

# define Rte_TypeDef_Display_ModeT
typedef uint8 Display_ModeT;

# define Rte_TypeDef_DistanceUnit
typedef uint8 DistanceUnit;

# define Rte_TypeDef_DoorStatus
typedef uint8 DoorStatus;

# define Rte_TypeDef_DriveModePayloadS
typedef uint8 DriveModePayloadS;

# define Rte_TypeDef_DriveModeS
typedef uint8 DriveModeS;

# define Rte_TypeDef_DriveModeTypeS
typedef uint8 DriveModeTypeS;

# define Rte_TypeDef_EAudioIndCbEnum_t
typedef uint8 EAudioIndCbEnum_t;

# define Rte_TypeDef_EAudioSourceList_t
typedef uint8 EAudioSourceList_t;

# define Rte_TypeDef_ECOIndicator
typedef uint8 ECOIndicator;

# define Rte_TypeDef_ECOModeReport
typedef uint8 ECOModeReport;

# define Rte_TypeDef_EChimeStatus
typedef uint16 EChimeStatus;

# define Rte_TypeDef_ECmpCmd
typedef uint8 ECmpCmd;

# define Rte_TypeDef_ECompState_t
typedef uint8 ECompState_t;

# define Rte_TypeDef_EDcmExtAction
typedef uint8 EDcmExtAction;

# define Rte_TypeDef_EDeviceStatus
typedef uint8 EDeviceStatus;

# define Rte_TypeDef_EDidType_t
typedef uint8 EDidType_t;

# define Rte_TypeDef_EDisplayPowerState
typedef uint8 EDisplayPowerState;

# define Rte_TypeDef_EDisplayPower_t
typedef uint8 EDisplayPower_t;

# define Rte_TypeDef_EDisplayStatus_t
typedef uint8 EDisplayStatus_t;

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

# define Rte_TypeDef_EDomainId_t
typedef uint8 EDomainId_t;

# define Rte_TypeDef_EFotaActiveCond
typedef uint8 EFotaActiveCond;

# define Rte_TypeDef_EFotaSlaveResponse_t
typedef uint8 EFotaSlaveResponse_t;

# define Rte_TypeDef_EFotaState
typedef uint8 EFotaState;

# define Rte_TypeDef_EFuSaCddSelfTst_t
typedef uint8 EFuSaCddSelfTst_t;

# define Rte_TypeDef_EIOCtrlOptType_t
typedef uint8 EIOCtrlOptType_t;

# define Rte_TypeDef_EITSOpngMovieOnDisplay_t
typedef uint8 EITSOpngMovieOnDisplay_t;

# define Rte_TypeDef_EIgnitionStatus_t
typedef uint8 EIgnitionStatus_t;

# define Rte_TypeDef_EInstallerFotaState_t
typedef uint8 EInstallerFotaState_t;

# define Rte_TypeDef_EInstallerNotif_t
typedef uint8 EInstallerNotif_t;

# define Rte_TypeDef_EInstallerReq_t
typedef uint8 EInstallerReq_t;

# define Rte_TypeDef_ELKAStatusType
typedef uint8 ELKAStatusType;

# define Rte_TypeDef_EMSStatusT
typedef uint8 EMSStatusT;

# define Rte_TypeDef_EMcanChannelState_t
typedef uint8 EMcanChannelState_t;

# define Rte_TypeDef_EMeetModeStatus
typedef uint8 EMeetModeStatus;

# define Rte_TypeDef_EMemCtrlCmd_t
typedef uint8 EMemCtrlCmd_t;

# define Rte_TypeDef_EMemCtrlShMem_t
typedef uint8 EMemCtrlShMem_t;

# define Rte_TypeDef_EMemDiagRequestCmd_t
typedef uint8 EMemDiagRequestCmd_t;

# define Rte_TypeDef_EMemTypeCmd_t
typedef uint8 EMemTypeCmd_t;

# define Rte_TypeDef_ENaviIndCbEnum_t
typedef uint8 ENaviIndCbEnum_t;

# define Rte_TypeDef_EOpeningMovieAnimStatus_t
typedef uint8 EOpeningMovieAnimStatus_t;

# define Rte_TypeDef_EPButtonId_t
typedef uint8 EPButtonId_t;

# define Rte_TypeDef_EPButtonState_t
typedef uint8 EPButtonState_t;

# define Rte_TypeDef_EPITSOpngMovieStatus_t
typedef uint8 EPITSOpngMovieStatus_t;

# define Rte_TypeDef_EPIllumButtonEvent_t
typedef uint8 EPIllumButtonEvent_t;

# define Rte_TypeDef_EPOpeningMovieStatus_t
typedef uint8 EPOpeningMovieStatus_t;

# define Rte_TypeDef_EPWUSCurrentVehicleState_t
typedef uint8 EPWUSCurrentVehicleState_t;

# define Rte_TypeDef_EPhoneIndCbEnum_t
typedef uint8 EPhoneIndCbEnum_t;

# define Rte_TypeDef_EPowerState
typedef uint8 EPowerState;

# define Rte_TypeDef_EPowerSubState
typedef uint8 EPowerSubState;

# define Rte_TypeDef_EPowerSubStateStatus
typedef uint8 EPowerSubStateStatus;

# define Rte_TypeDef_EReflashStatus_t
typedef uint8 EReflashStatus_t;

# define Rte_TypeDef_ERoutineType_t
typedef uint8 ERoutineType_t;

# define Rte_TypeDef_ESecBootSts
typedef uint8 ESecBootSts;

# define Rte_TypeDef_ESecurityKey
typedef uint8 ESecurityKey;

# define Rte_TypeDef_ESndChnStat
typedef uint8 ESndChnStat;

# define Rte_TypeDef_ESndInterruptType
typedef uint8 ESndInterruptType;

# define Rte_TypeDef_ESystemState
typedef uint8 ESystemState;

# define Rte_TypeDef_ESystemState_t
typedef uint8 ESystemState_t;

# define Rte_TypeDef_ETMEvents
typedef uint8 ETMEvents;

# define Rte_TypeDef_ETMState
typedef uint16 ETMState;

# define Rte_TypeDef_ETelMenuItem_t
typedef uint8 ETelMenuItem_t;

# define Rte_TypeDef_EUIMcanFeatureAvailability_t
typedef uint8 EUIMcanFeatureAvailability_t;

# define Rte_TypeDef_EUclLinkState_t
typedef uint8 EUclLinkState_t;

# define Rte_TypeDef_EUiSmsMenuItem_t
typedef uint8 EUiSmsMenuItem_t;

# define Rte_TypeDef_EWUSCurrentAccState_t
typedef uint8 EWUSCurrentAccState_t;

# define Rte_TypeDef_EcoIndicatorPayload
typedef uint8 EcoIndicatorPayload;

# define Rte_TypeDef_EcuMExt_BootModeType
typedef uint8 EcuMExt_BootModeType;

# define Rte_TypeDef_EcuMExt_ResetType
typedef uint8 EcuMExt_ResetType;

# define Rte_TypeDef_EcuMExt_WakeupReasonType
typedef sint32 EcuMExt_WakeupReasonType;

# define Rte_TypeDef_EcuMExt_WakeupType
typedef sint32 EcuMExt_WakeupType;

# define Rte_TypeDef_EffectModeType
typedef uint8 EffectModeType;

# define Rte_TypeDef_EnerFlowSOCBarColorT
typedef uint8 EnerFlowSOCBarColorT;

# define Rte_TypeDef_EnergyFlowStateT
typedef uint8 EnergyFlowStateT;

# define Rte_TypeDef_EnergyMetertypeT
typedef uint8 EnergyMetertypeT;

# define Rte_TypeDef_EnergyRunningStateT
typedef uint8 EnergyRunningStateT;

# define Rte_TypeDef_EngineBatteryT
typedef uint8 EngineBatteryT;

# define Rte_TypeDef_EngineStateTypes
typedef uint8 EngineStateTypes;

# define Rte_TypeDef_ErrorCauseType
typedef uint8 ErrorCauseType;

# define Rte_TypeDef_ErrorOriginType
typedef uint8 ErrorOriginType;

# define Rte_TypeDef_FCWMainMenuType
typedef uint8 FCWMainMenuType;

# define Rte_TypeDef_FEBIndicatorStatusT
typedef uint8 FEBIndicatorStatusT;

# define Rte_TypeDef_FEBStatusType
typedef uint8 FEBStatusType;

# define Rte_TypeDef_FaultLogType
typedef uint8 FaultLogType;

# define Rte_TypeDef_FeatureID
typedef uint8 FeatureID;

# define Rte_TypeDef_FeatureInputSts
typedef uint8 FeatureInputSts;

# define Rte_TypeDef_FeatureStatus
typedef uint8 FeatureStatus;

# define Rte_TypeDef_FrCameraType
typedef uint8 FrCameraType;

# define Rte_TypeDef_FrRadarType
typedef uint8 FrRadarType;

# define Rte_TypeDef_FrVehicleType
typedef uint8 FrVehicleType;

# define Rte_TypeDef_FrontVehReminderT
typedef uint8 FrontVehReminderT;

# define Rte_TypeDef_FuelCapPositionT
typedef uint8 FuelCapPositionT;

# define Rte_TypeDef_FuelFillModeType
typedef uint8 FuelFillModeType;

# define Rte_TypeDef_FuelInitStatus
typedef uint8 FuelInitStatus;

# define Rte_TypeDef_FuelSensorRawStatusT
typedef uint8 FuelSensorRawStatusT;

# define Rte_TypeDef_FuelSensorStatusT
typedef uint8 FuelSensorStatusT;

# define Rte_TypeDef_FuelTankTypeT
typedef uint8 FuelTankTypeT;

# define Rte_TypeDef_FutureStatusT
typedef uint8 FutureStatusT;

# define Rte_TypeDef_GSFutrinfo
typedef uint8 GSFutrinfo;

# define Rte_TypeDef_GSIStatus
typedef uint8 GSIStatus;

# define Rte_TypeDef_GaugeClient
typedef uint8 GaugeClient;

# define Rte_TypeDef_GaugeScreenState
typedef uint8 GaugeScreenState;

# define Rte_TypeDef_GaugeSweepStsT
typedef uint8 GaugeSweepStsT;

# define Rte_TypeDef_GaugeTestStatus
typedef uint8 GaugeTestStatus;

# define Rte_TypeDef_GcarEffectModeType
typedef uint8 GcarEffectModeType;

# define Rte_TypeDef_GearNumber
typedef uint8 GearNumber;

# define Rte_TypeDef_GreenFrameType
typedef uint8 GreenFrameType;

# define Rte_TypeDef_GuageEffectModeStatus
typedef uint8 GuageEffectModeStatus;

# define Rte_TypeDef_GuidanceSwType
typedef uint8 GuidanceSwType;

# define Rte_TypeDef_HMIContentStatus
typedef uint8 HMIContentStatus;

# define Rte_TypeDef_HTimer
typedef uint8 HTimer;

# define Rte_TypeDef_HandColorType
typedef uint8 HandColorType;

# define Rte_TypeDef_HandlePositionT
typedef uint8 HandlePositionT;

# define Rte_TypeDef_HeaderFooterClient
typedef uint8 HeaderFooterClient;

# define Rte_TypeDef_HeaderFooterState
typedef uint8 HeaderFooterState;

# define Rte_TypeDef_HealthStatusType
typedef uint8 HealthStatusType;

# define Rte_TypeDef_HiBeamPopUpT
typedef uint8 HiBeamPopUpT;

# define Rte_TypeDef_HiBeamPopUpTrigger
typedef uint8 HiBeamPopUpTrigger;

# define Rte_TypeDef_HmiInitStatus
typedef uint8 HmiInitStatus;

# define Rte_TypeDef_HomeScreenStatusT
typedef uint8 HomeScreenStatusT;

# define Rte_TypeDef_HwIgnStatus
typedef uint8 HwIgnStatus;

# define Rte_TypeDef_HwPinStatus
typedef uint8 HwPinStatus;

# define Rte_TypeDef_ICCPopupPayloadT
typedef uint8 ICCPopupPayloadT;

# define Rte_TypeDef_ICCSwipeStatusT
typedef uint8 ICCSwipeStatusT;

# define Rte_TypeDef_ICSControlInstructionT
typedef uint8 ICSControlInstructionT;

# define Rte_TypeDef_ICSFrontCarImageDistanceT
typedef uint8 ICSFrontCarImageDistanceT;

# define Rte_TypeDef_ICSFrontCarImageSizeT
typedef uint8 ICSFrontCarImageSizeT;

# define Rte_TypeDef_ICSFrontCarImageT
typedef uint8 ICSFrontCarImageT;

# define Rte_TypeDef_ICSLaneColorT
typedef uint8 ICSLaneColorT;

# define Rte_TypeDef_ICSStatusInstructionT
typedef uint8 ICSStatusInstructionT;

# define Rte_TypeDef_ICSSteeringIconDisplayT
typedef uint8 ICSSteeringIconDisplayT;

# define Rte_TypeDef_ICSVehicleDisplayDistanceIndT
typedef uint8 ICSVehicleDisplayDistanceIndT;

# define Rte_TypeDef_IDMArcEffectStatesS
typedef uint8 IDMArcEffectStatesS;

# define Rte_TypeDef_IDMDisplayStatesS
typedef uint8 IDMDisplayStatesS;

# define Rte_TypeDef_IDMHsaEffectStStatesS
typedef uint8 IDMHsaEffectStStatesS;

# define Rte_TypeDef_IDMTireEffectStatesS
typedef uint8 IDMTireEffectStatesS;

# define Rte_TypeDef_IDMTurnEffectLeftStatesS
typedef uint8 IDMTurnEffectLeftStatesS;

# define Rte_TypeDef_IDMTurnEffectRightStatesS
typedef uint8 IDMTurnEffectRightStatesS;

# define Rte_TypeDef_IFETypeT
typedef uint8 IFETypeT;

# define Rte_TypeDef_ITSICONCF
typedef uint8 ITSICONCF;

# define Rte_TypeDef_ITSMainMenuIconType
typedef uint8 ITSMainMenuIconType;

# define Rte_TypeDef_ITSOpngMovieOnDisplay
typedef uint8 ITSOpngMovieOnDisplay;

# define Rte_TypeDef_ITSOpngMovieStatus
typedef uint8 ITSOpngMovieStatus;

# define Rte_TypeDef_IconStatusType
typedef uint8 IconStatusType;

# define Rte_TypeDef_IdleStopState
typedef uint8 IdleStopState;

# define Rte_TypeDef_IdleStpIndType
typedef uint8 IdleStpIndType;

# define Rte_TypeDef_IdlingState
typedef uint8 IdlingState;

# define Rte_TypeDef_IgnOffDimmingProcessStsT
typedef uint8 IgnOffDimmingProcessStsT;

# define Rte_TypeDef_IgntionSubstateType
typedef uint8 IgntionSubstateType;

# define Rte_TypeDef_IkeyTypeT
typedef uint8 IkeyTypeT;

# define Rte_TypeDef_IllumEvent
typedef uint8 IllumEvent;

# define Rte_TypeDef_IllumOpStatus
typedef uint8 IllumOpStatus;

# define Rte_TypeDef_IllumPopUpTrigger
typedef uint8 IllumPopUpTrigger;

# define Rte_TypeDef_IlluminationControlTypeT
typedef uint8 IlluminationControlTypeT;

# define Rte_TypeDef_IndicatorStatusT
typedef uint8 IndicatorStatusT;

# define Rte_TypeDef_IndicatorType
typedef uint8 IndicatorType;

# define Rte_TypeDef_InitType
typedef uint8 InitType;

# define Rte_TypeDef_InterruptionMessageType
typedef uint8 InterruptionMessageType;

# define Rte_TypeDef_IoHwAbExt_ErrorType
typedef uint8 IoHwAbExt_ErrorType;

# define Rte_TypeDef_IoHwAbExt_LEDChannelType
typedef uint8 IoHwAbExt_LEDChannelType;

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

# define Rte_TypeDef_KeyOffProcessStatus
typedef uint8 KeyOffProcessStatus;

# define Rte_TypeDef_LDPLDWType
typedef uint8 LDPLDWType;

# define Rte_TypeDef_LDPSSiconCfgT
typedef uint8 LDPSSiconCfgT;

# define Rte_TypeDef_LDPStatusType
typedef uint8 LDPStatusType;

# define Rte_TypeDef_LDWLDPMainMenuType
typedef uint8 LDWLDPMainMenuType;

# define Rte_TypeDef_LDWStatusType
typedef uint8 LDWStatusType;

# define Rte_TypeDef_LKAStatusType
typedef uint8 LKAStatusType;

# define Rte_TypeDef_LangaugeMaskPos
typedef uint8 LangaugeMaskPos;

# define Rte_TypeDef_Language
typedef uint8 Language;

# define Rte_TypeDef_LanguageUnitStatusT
typedef uint8 LanguageUnitStatusT;

# define Rte_TypeDef_LayoutErrorStateT
typedef uint8 LayoutErrorStateT;

# define Rte_TypeDef_LightOffDelay
typedef uint8 LightOffDelay;

# define Rte_TypeDef_LightSensitivity
typedef uint8 LightSensitivity;

# define Rte_TypeDef_LookUpSignSpdValueType
typedef uint8 LookUpSignSpdValueType;

# define Rte_TypeDef_LookUpSignType
typedef uint8 LookUpSignType;

# define Rte_TypeDef_LowFuelStatusT
typedef uint8 LowFuelStatusT;

# define Rte_TypeDef_MCANChannelT
typedef uint8 MCANChannelT;

# define Rte_TypeDef_MCANTransmitDataSigId
typedef uint8 MCANTransmitDataSigId;

# define Rte_TypeDef_MainMenuListT
typedef uint8 MainMenuListT;

# define Rte_TypeDef_McanFaultState
typedef uint8 McanFaultState;

# define Rte_TypeDef_MenuOpenCloseT
typedef uint8 MenuOpenCloseT;

# define Rte_TypeDef_MilageUnits
typedef uint8 MilageUnits;

# define Rte_TypeDef_MirrorsSetting
typedef uint8 MirrorsSetting;

# define Rte_TypeDef_MsgRcvdT
typedef uint8 MsgRcvdT;

# define Rte_TypeDef_NaviLinkStatusType
typedef uint8 NaviLinkStatusType;

# define Rte_TypeDef_NonCriticalSleepComponentIdx
typedef uint8 NonCriticalSleepComponentIdx;

# define Rte_TypeDef_NvMJobResultRI
typedef uint8 NvMJobResultRI;

# define Rte_TypeDef_NvMServiceIdRI
typedef uint8 NvMServiceIdRI;

# define Rte_TypeDef_NvMfgMode
typedef uint16 NvMfgMode;

# define Rte_TypeDef_Nvm_BlockId
typedef uint8 Nvm_BlockId;

# define Rte_TypeDef_OATAlert
typedef uint8 OATAlert;

# define Rte_TypeDef_OATSensorStatusT
typedef uint8 OATSensorStatusT;

# define Rte_TypeDef_OilLevelSensorMeasureT
typedef uint8 OilLevelSensorMeasureT;

# define Rte_TypeDef_OilSensorStatusT
typedef uint8 OilSensorStatusT;

# define Rte_TypeDef_OpeningMovieAnimationStatus
typedef uint8 OpeningMovieAnimationStatus;

# define Rte_TypeDef_OpeningMovieStatus
typedef uint8 OpeningMovieStatus;

# define Rte_TypeDef_OwnVehicleBrake
typedef uint8 OwnVehicleBrake;

# define Rte_TypeDef_OwnVehicleEffect
typedef uint8 OwnVehicleEffect;

# define Rte_TypeDef_OwnVehicleTurn
typedef uint8 OwnVehicleTurn;

# define Rte_TypeDef_PWMSwChannelT
typedef uint8 PWMSwChannelT;

# define Rte_TypeDef_PersonalMenuClient
typedef uint8 PersonalMenuClient;

# define Rte_TypeDef_PersonalMenuState
typedef uint8 PersonalMenuState;

# define Rte_TypeDef_PersonalizedListT
typedef uint8 PersonalizedListT;

# define Rte_TypeDef_PersonalizedSubListT
typedef uint8 PersonalizedSubListT;

# define Rte_TypeDef_PersonnalMenuStsT
typedef uint16 PersonnalMenuStsT;

# define Rte_TypeDef_PilotDrivePayloadS
typedef uint8 PilotDrivePayloadS;

# define Rte_TypeDef_PopUpAckStatus
typedef uint8 PopUpAckStatus;

# define Rte_TypeDef_PopUpStatus
typedef uint8 PopUpStatus;

# define Rte_TypeDef_PopUpTriggerSts
typedef uint8 PopUpTriggerSts;

# define Rte_TypeDef_PowerStateT
typedef uint8 PowerStateT;

# define Rte_TypeDef_REBIndicatorPayload
typedef uint8 REBIndicatorPayload;

# define Rte_TypeDef_RESPayload
typedef uint8 RESPayload;

# define Rte_TypeDef_RSB3rdRowAvailableT
typedef uint8 RSB3rdRowAvailableT;

# define Rte_TypeDef_RSBDuringWarn
typedef uint8 RSBDuringWarn;

# define Rte_TypeDef_RSBFastenedStatus
typedef uint8 RSBFastenedStatus;

# define Rte_TypeDef_RSBHandlePositionT
typedef uint8 RSBHandlePositionT;

# define Rte_TypeDef_RSBPopupAvailableT
typedef uint8 RSBPopupAvailableT;

# define Rte_TypeDef_RSBwithODSstsT
typedef uint8 RSBwithODSstsT;

# define Rte_TypeDef_RearDoorAlert
typedef uint8 RearDoorAlert;

# define Rte_TypeDef_RearDoorAlertEvt
typedef uint8 RearDoorAlertEvt;

# define Rte_TypeDef_RegionInfoT
typedef uint8 RegionInfoT;

# define Rte_TypeDef_ReprogCmdType
typedef uint8 ReprogCmdType;

# define Rte_TypeDef_ResetReasonType
typedef uint8 ResetReasonType;

# define Rte_TypeDef_ResetReason_T
typedef uint8 ResetReason_T;

# define Rte_TypeDef_SET_CLOCK_TYPE
typedef uint8 SET_CLOCK_TYPE;

# define Rte_TypeDef_SOCBarColorT
typedef uint8 SOCBarColorT;

# define Rte_TypeDef_SSAPayloadS
typedef uint8 SSAPayloadS;

# define Rte_TypeDef_STATE_TYPE
typedef uint8 STATE_TYPE;

# define Rte_TypeDef_SafetyMsgRcvT
typedef uint16 SafetyMsgRcvT;

# define Rte_TypeDef_SensitivityType
typedef uint8 SensitivityType;

# define Rte_TypeDef_SettingRestTypeT
typedef uint8 SettingRestTypeT;

# define Rte_TypeDef_SettingsActionType
typedef uint8 SettingsActionType;

# define Rte_TypeDef_SettingsMenuConfigID
typedef uint8 SettingsMenuConfigID;

# define Rte_TypeDef_SettingsMenuStatus
typedef uint8 SettingsMenuStatus;

# define Rte_TypeDef_SigmaTaskTriggerT
typedef uint8 SigmaTaskTriggerT;

# define Rte_TypeDef_SleepControlType
typedef uint8 SleepControlType;

# define Rte_TypeDef_SleepDiagRequest
typedef uint8 SleepDiagRequest;

# define Rte_TypeDef_SoftwareModeS
typedef uint8 SoftwareModeS;

# define Rte_TypeDef_SonarIndPayloadS
typedef uint8 SonarIndPayloadS;

# define Rte_TypeDef_SonarRange
typedef uint8 SonarRange;

# define Rte_TypeDef_SonarSensorAvailability
typedef uint8 SonarSensorAvailability;

# define Rte_TypeDef_SonarVol
typedef uint8 SonarVol;

# define Rte_TypeDef_SonarWarningLevel
typedef uint8 SonarWarningLevel;

# define Rte_TypeDef_SpdLmtAssist
typedef uint8 SpdLmtAssist;

# define Rte_TypeDef_SpdLmtAssistOffset
typedef uint8 SpdLmtAssistOffset;

# define Rte_TypeDef_StartUpInitProcessStateT
typedef uint8 StartUpInitProcessStateT;

# define Rte_TypeDef_SteeringColorType
typedef uint8 SteeringColorType;

# define Rte_TypeDef_SteeringEffortSetting
typedef uint8 SteeringEffortSetting;

# define Rte_TypeDef_StreamStatusType
typedef uint8 StreamStatusType;

# define Rte_TypeDef_Strg1BtnType
typedef uint8 Strg1BtnType;

# define Rte_TypeDef_Strg2BtnType
typedef uint8 Strg2BtnType;

# define Rte_TypeDef_StrgSwT
typedef uint8 StrgSwT;

# define Rte_TypeDef_SubSpeedUnitT
typedef uint8 SubSpeedUnitT;

# define Rte_TypeDef_SubcriptionErrorStatusT
typedef uint8 SubcriptionErrorStatusT;

# define Rte_TypeDef_TELActiveStatus
typedef uint8 TELActiveStatus;

# define Rte_TypeDef_TEPowerVariantInfo
typedef uint8 TEPowerVariantInfo;

# define Rte_TypeDef_TFTIgnBlankSts_T
typedef uint8 TFTIgnBlankSts_T;

# define Rte_TypeDef_TFTTempSensorStatusT
typedef uint16 TFTTempSensorStatusT;

# define Rte_TypeDef_TIME_CLOCK_TYPE
typedef uint8 TIME_CLOCK_TYPE;

# define Rte_TypeDef_TIME_FORMAT_TYPE
typedef uint8 TIME_FORMAT_TYPE;

# define Rte_TypeDef_TIME_ZONE_TYPE
typedef uint8 TIME_ZONE_TYPE;

# define Rte_TypeDef_TJPPayloadS
typedef uint8 TJPPayloadS;

# define Rte_TypeDef_TPMSAxleStatus
typedef uint8 TPMSAxleStatus;

# define Rte_TypeDef_TPMSColdTireStatus
typedef uint8 TPMSColdTireStatus;

# define Rte_TypeDef_TPMSEcoAdviceT
typedef uint8 TPMSEcoAdviceT;

# define Rte_TypeDef_TPMSFeatureStatus
typedef uint8 TPMSFeatureStatus;

# define Rte_TypeDef_TPMSTirePressureStatus
typedef uint8 TPMSTirePressureStatus;

# define Rte_TypeDef_TPMSTireWarningStatus
typedef uint8 TPMSTireWarningStatus;

# define Rte_TypeDef_TSRNoOverTakeSign
typedef uint8 TSRNoOverTakeSign;

# define Rte_TypeDef_TSRRegionT
typedef uint8 TSRRegionT;

# define Rte_TypeDef_TSRSpeedSignalZone
typedef uint8 TSRSpeedSignalZone;

# define Rte_TypeDef_TSRSubSignZone
typedef uint8 TSRSubSignZone;

# define Rte_TypeDef_TTFlashMask
typedef uint8 TTFlashMask;

# define Rte_TypeDef_TT_ENUM_TYPE
typedef uint8 TT_ENUM_TYPE;

# define Rte_TypeDef_TT_OP_STATES
typedef uint8 TT_OP_STATES;

# define Rte_TypeDef_TVariantSwapTT
typedef uint8 TVariantSwapTT;

# define Rte_TypeDef_TachoDesignUnitT
typedef uint8 TachoDesignUnitT;

# define Rte_TypeDef_TachoRedZoneT
typedef uint8 TachoRedZoneT;

# define Rte_TypeDef_TachoStateT
typedef uint8 TachoStateT;

# define Rte_TypeDef_TachoUnitT
typedef uint8 TachoUnitT;

# define Rte_TypeDef_TellTaleState_T
typedef uint8 TellTaleState_T;

# define Rte_TypeDef_TempUnit
typedef uint8 TempUnit;

# define Rte_TypeDef_TextShrinkApplicableStsT
typedef uint8 TextShrinkApplicableStsT;

# define Rte_TypeDef_TextStatusType
typedef uint8 TextStatusType;

# define Rte_TypeDef_ThatchamAlertEvt
typedef uint8 ThatchamAlertEvt;

# define Rte_TypeDef_TpmsUnit
typedef uint8 TpmsUnit;

# define Rte_TypeDef_TrafficSignType
typedef uint8 TrafficSignType;

# define Rte_TypeDef_TransmissionTypeT
typedef uint8 TransmissionTypeT;

# define Rte_TypeDef_TripDist3RstTypT
typedef uint8 TripDist3RstTypT;

# define Rte_TypeDef_TripResetTypT
typedef uint8 TripResetTypT;

# define Rte_TypeDef_TripType
typedef uint8 TripType;

# define Rte_TypeDef_TsrIccPopUpType
typedef uint8 TsrIccPopUpType;

# define Rte_TypeDef_TsrSpeedGuide_T
typedef uint8 TsrSpeedGuide_T;

# define Rte_TypeDef_UI_ARTIST_LABEL_T
typedef uint8 UI_ARTIST_LABEL_T;

# define Rte_TypeDef_UI_AUDIO_ICON_T
typedef uint8 UI_AUDIO_ICON_T;

# define Rte_TypeDef_UI_AUDIO_MODE_T
typedef uint8 UI_AUDIO_MODE_T;

# define Rte_TypeDef_UI_AUDIO_SOURCE_LIST_T
typedef uint8 UI_AUDIO_SOURCE_LIST_T;

# define Rte_TypeDef_UI_AUDIO_SRC_LIST_OPEN_CLOSE
typedef uint8 UI_AUDIO_SRC_LIST_OPEN_CLOSE;

# define Rte_TypeDef_UI_AUDIO_WARNING_T
typedef uint8 UI_AUDIO_WARNING_T;

# define Rte_TypeDef_UI_AUX_SOURCE_T
typedef uint8 UI_AUX_SOURCE_T;

# define Rte_TypeDef_UI_BROADCAST_LABEL_T
typedef uint8 UI_BROADCAST_LABEL_T;

# define Rte_TypeDef_UI_CATEGORY_LABEL_T
typedef uint8 UI_CATEGORY_LABEL_T;

# define Rte_TypeDef_UI_DISC_SOURCE_T
typedef uint8 UI_DISC_SOURCE_T;

# define Rte_TypeDef_UI_DISP_CASE
typedef uint8 UI_DISP_CASE;

# define Rte_TypeDef_UI_GROUP_LABEL_T
typedef uint8 UI_GROUP_LABEL_T;

# define Rte_TypeDef_UI_HD_RADIO_SRC_T
typedef uint8 UI_HD_RADIO_SRC_T;

# define Rte_TypeDef_UI_MCAN_FEATURE_AVAILABILITY
typedef uint8 UI_MCAN_FEATURE_AVAILABILITY;

# define Rte_TypeDef_UI_MCAN_POPUP_STAUTS_T
typedef uint8 UI_MCAN_POPUP_STAUTS_T;

# define Rte_TypeDef_UI_MCAN_POPUP_T
typedef uint8 UI_MCAN_POPUP_T;

# define Rte_TypeDef_UI_MCAN_TRIG_EVENT_T
typedef uint8 UI_MCAN_TRIG_EVENT_T;

# define Rte_TypeDef_UI_MCAN_TRIG_STATUS_T
typedef uint8 UI_MCAN_TRIG_STATUS_T;

# define Rte_TypeDef_UI_NAVI_ARRIVAL_CLOCK_INFO_T
typedef uint8 UI_NAVI_ARRIVAL_CLOCK_INFO_T;

# define Rte_TypeDef_UI_NAVI_ARRIVAL_POINT_INFO_T
typedef uint8 UI_NAVI_ARRIVAL_POINT_INFO_T;

# define Rte_TypeDef_UI_NAVI_ARRIVAL_TIME_TYPE_INFO_T
typedef uint8 UI_NAVI_ARRIVAL_TIME_TYPE_INFO_T;

# define Rte_TypeDef_UI_NAVI_BAR_SCALE_DIV_T
typedef uint8 UI_NAVI_BAR_SCALE_DIV_T;

# define Rte_TypeDef_UI_NAVI_BAR_SCALE_INFO_T
typedef uint8 UI_NAVI_BAR_SCALE_INFO_T;

# define Rte_TypeDef_UI_NAVI_BAR_SCALE_UNIT_T
typedef uint8 UI_NAVI_BAR_SCALE_UNIT_T;

# define Rte_TypeDef_UI_NAVI_BAR_STATE
typedef uint8 UI_NAVI_BAR_STATE;

# define Rte_TypeDef_UI_NAVI_COMPASS_T
typedef uint8 UI_NAVI_COMPASS_T;

# define Rte_TypeDef_UI_NAVI_COMPASS_T_DIR
typedef uint8 UI_NAVI_COMPASS_T_DIR;

# define Rte_TypeDef_UI_NAVI_DEFORM_ARROW_INFO_T
typedef uint8 UI_NAVI_DEFORM_ARROW_INFO_T;

# define Rte_TypeDef_UI_NAVI_DEFORM_ROAD_INFO_T
typedef uint8 UI_NAVI_DEFORM_ROAD_INFO_T;

# define Rte_TypeDef_UI_NAVI_DEST_WEATHER_INFO_T
typedef uint8 UI_NAVI_DEST_WEATHER_INFO_T;

# define Rte_TypeDef_UI_NAVI_DISPLAY_MODE_T
typedef uint8 UI_NAVI_DISPLAY_MODE_T;

# define Rte_TypeDef_UI_NAVI_DIST_UNIT_T
typedef uint8 UI_NAVI_DIST_UNIT_T;

# define Rte_TypeDef_UI_NAVI_LANE_CATEGORY_T
typedef uint8 UI_NAVI_LANE_CATEGORY_T;

# define Rte_TypeDef_UI_NAVI_SPEED_LIMIT_STATE_T
typedef uint8 UI_NAVI_SPEED_LIMIT_STATE_T;

# define Rte_TypeDef_UI_NAVI_SPEED_LIMIT_TYPE_T
typedef uint8 UI_NAVI_SPEED_LIMIT_TYPE_T;

# define Rte_TypeDef_UI_NAVI_SPEED_LIMIT_UNIT_T
typedef uint8 UI_NAVI_SPEED_LIMIT_UNIT_T;

# define Rte_TypeDef_UI_NAVI_STATE_T
typedef uint8 UI_NAVI_STATE_T;

# define Rte_TypeDef_UI_NAVI_SWIPE_STATE_T
typedef uint8 UI_NAVI_SWIPE_STATE_T;

# define Rte_TypeDef_UI_NAVI_TBT_INFO_T
typedef uint8 UI_NAVI_TBT_INFO_T;

# define Rte_TypeDef_UI_RADIO_SOURCE_T
typedef uint8 UI_RADIO_SOURCE_T;

# define Rte_TypeDef_UI_RADIO_UNIT_T
typedef uint8 UI_RADIO_UNIT_T;

# define Rte_TypeDef_UI_SETTING_STATUS_T
typedef uint8 UI_SETTING_STATUS_T;

# define Rte_TypeDef_UI_SMS_MENU_ITEM_T
typedef uint8 UI_SMS_MENU_ITEM_T;

# define Rte_TypeDef_UI_SMS_STATE_T
typedef uint8 UI_SMS_STATE_T;

# define Rte_TypeDef_UI_TEL_DISPLAY_MENU_TYPE_T
typedef uint8 UI_TEL_DISPLAY_MENU_TYPE_T;

# define Rte_TypeDef_UI_TEL_MENU_ITEM_T
typedef uint8 UI_TEL_MENU_ITEM_T;

# define Rte_TypeDef_UI_TEL_MUTE_T
typedef uint8 UI_TEL_MUTE_T;

# define Rte_TypeDef_UI_TEL_WARNING_STATE_T
typedef uint8 UI_TEL_WARNING_STATE_T;

# define Rte_TypeDef_UI_TRACK_LABEL_T
typedef uint8 UI_TRACK_LABEL_T;

# define Rte_TypeDef_UI_TV_LABEL_T
typedef uint8 UI_TV_LABEL_T;

# define Rte_TypeDef_UI_TV_SOURCE_T
typedef uint8 UI_TV_SOURCE_T;

# define Rte_TypeDef_UI_VR_INFO_ON_OFF_T
typedef uint8 UI_VR_INFO_ON_OFF_T;

# define Rte_TypeDef_UI_VR_INSTRUCTION_T
typedef uint8 UI_VR_INSTRUCTION_T;

# define Rte_TypeDef_UI_VR_STATE_T
typedef uint8 UI_VR_STATE_T;

# define Rte_TypeDef_UiSettingsToggleTypeMenu
typedef uint8 UiSettingsToggleTypeMenu;

# define Rte_TypeDef_VIPGIPElementType
typedef uint8 VIPGIPElementType;

# define Rte_TypeDef_VariantCfgT
typedef uint8 VariantCfgT;

# define Rte_TypeDef_VehSpdIndType
typedef uint8 VehSpdIndType;

# define Rte_TypeDef_VehiclDASsettingStsT
typedef uint8 VehiclDASsettingStsT;

# define Rte_TypeDef_VehicleActiveModes
typedef uint8 VehicleActiveModes;

# define Rte_TypeDef_VehicleCondition_T
typedef uint8 VehicleCondition_T;

# define Rte_TypeDef_VehicleTypeCfgT
typedef uint8 VehicleTypeCfgT;

# define Rte_TypeDef_VideoLayoutType
typedef uint8 VideoLayoutType;

# define Rte_TypeDef_WUSStates
typedef uint8 WUSStates;

# define Rte_TypeDef_WakeupEventType
typedef uint8 WakeupEventType;

# define Rte_TypeDef_WarningAckSts
typedef uint8 WarningAckSts;

# define Rte_TypeDef_WarningAnimStatusT
typedef uint8 WarningAnimStatusT;

# define Rte_TypeDef_WarningDisplayedStatus
typedef uint8 WarningDisplayedStatus;

# define Rte_TypeDef_WarningEvent
typedef uint8 WarningEvent;

# define Rte_TypeDef_WarningId
typedef uint8 WarningId;

# define Rte_TypeDef_WarningPresentStatusT
typedef uint8 WarningPresentStatusT;

# define Rte_TypeDef_WarningStatus
typedef uint8 WarningStatus;

# define Rte_TypeDef_WatchDogAction
typedef uint8 WatchDogAction;

# define Rte_TypeDef_WaterHTempT
typedef uint8 WaterHTempT;

# define Rte_TypeDef_WaterHighTempThT
typedef uint8 WaterHighTempThT;

# define Rte_TypeDef_WgdChkPtID
typedef uint8 WgdChkPtID;

# define Rte_TypeDef_ZoneCfT
typedef uint8 ZoneCfT;

# define Rte_TypeDef_ZoneP2Status
typedef uint8 ZoneP2Status;

# define Rte_TypeDef_eBatteryState
typedef uint8 eBatteryState;

# define Rte_TypeDef_eEcuMExt_PwrModeType
typedef uint8 eEcuMExt_PwrModeType;

# define Rte_TypeDef_eIOPulseInputId
typedef sint32 eIOPulseInputId;

# define Rte_TypeDef_ePedalModeStatus
typedef uint8 ePedalModeStatus;

# define Rte_TypeDef_eShutdownState
typedef uint8 eShutdownState;

# define Rte_TypeDef_tDiagSessionSt
typedef uint8 tDiagSessionSt;

# define Rte_TypeDef_tHL_ErrorCode
typedef uint8 tHL_ErrorCode;

# define Rte_TypeDef_tHL_LogId
typedef uint8 tHL_LogId;

# define Rte_TypeDef_tHL_LogOpId
typedef uint8 tHL_LogOpId;

# define Rte_TypeDef_tHL_SwcId
typedef uint8 tHL_SwcId;

# define Rte_TypeDef_tInhibitLocalSleep
typedef uint8 tInhibitLocalSleep;

# define Rte_TypeDef_tModeMgrMeetMode
typedef uint8 tModeMgrMeetMode;

# define Rte_TypeDef_tResetReason
typedef uint8 tResetReason;

# define Rte_TypeDef_tSWCFeature
typedef uint8 tSWCFeature;

# define Rte_TypeDef_tSWCMode
typedef uint8 tSWCMode;

# define Rte_TypeDef_teDIDOperation
typedef uint8 teDIDOperation;

# define Rte_TypeDef_teDTCOperation
typedef uint8 teDTCOperation;

# define Rte_TypeDef_teDiagFilterBypassMode
typedef uint8 teDiagFilterBypassMode;

# define Rte_TypeDef_teDiagOpStatus
typedef uint8 teDiagOpStatus;

# define Rte_TypeDef_teRoutineOperation
typedef uint8 teRoutineOperation;

# define Rte_TypeDef_teSetAllTelltalesDiagCtrl
typedef uint8 teSetAllTelltalesDiagCtrl;

# define Rte_TypeDef_AVAILABLE_TIME_ZONE_TYPE
typedef Rte_DT_AVAILABLE_TIME_ZONE_TYPE_0 AVAILABLE_TIME_ZONE_TYPE[89];

# define Rte_TypeDef_Ad2SurrVehInfo
typedef Rte_DT_Ad2SurrVehInfo_0 Ad2SurrVehInfo[8];

# define Rte_TypeDef_Ad2SurrVehSts
typedef Rte_DT_Ad2SurrVehSts_0 Ad2SurrVehSts[48];

# define Rte_TypeDef_BaseVoltageT
typedef Rte_DT_BaseVoltageT_0 BaseVoltageT[19];

# define Rte_TypeDef_ComMsgPoint
typedef Rte_DT_ComMsgPoint_0 ComMsgPoint[16];

# define Rte_TypeDef_Crc_IN_Type
typedef Rte_DT_Crc_IN_Type_0 Crc_IN_Type[2];

# define Rte_TypeDef_CutOffMaskT
typedef Rte_DT_CutOffMaskT_0 CutOffMaskT[19];

# define Rte_TypeDef_DIAG_DID_100_Data_ref
typedef Rte_DT_DIAG_DID_100_Data_ref_0 DIAG_DID_100_Data_ref[16];

# define Rte_TypeDef_DIAG_DID_200_Data_ref
typedef Rte_DT_DIAG_DID_200_Data_ref_0 DIAG_DID_200_Data_ref[16];

# define Rte_TypeDef_DIAG_DID_300_Data_ref
typedef Rte_DT_DIAG_DID_300_Data_ref_0 DIAG_DID_300_Data_ref[4];

# define Rte_TypeDef_DIAG_DID_400_Data_ref
typedef Rte_DT_DIAG_DID_400_Data_ref_0 DIAG_DID_400_Data_ref[2];

# define Rte_TypeDef_DIAG_DID_F011_Data_ref
typedef Rte_DT_DIAG_DID_F011_Data_ref_0 DIAG_DID_F011_Data_ref[10];

# define Rte_TypeDef_DIAG_DID_F012_Data_ref
typedef Rte_DT_DIAG_DID_F012_Data_ref_0 DIAG_DID_F012_Data_ref[10];

# define Rte_TypeDef_DIAG_DID_F013_Data_ref
typedef Rte_DT_DIAG_DID_F013_Data_ref_0 DIAG_DID_F013_Data_ref[10];

# define Rte_TypeDef_DIAG_DID_F187_Data_ref
typedef Rte_DT_DIAG_DID_F187_Data_ref_0 DIAG_DID_F187_Data_ref[10];

# define Rte_TypeDef_DIAG_DID_F18A_Data_ref
typedef Rte_DT_DIAG_DID_F18A_Data_ref_0 DIAG_DID_F18A_Data_ref[4];

# define Rte_TypeDef_DIAG_DID_F18C_Data_ref
typedef Rte_DT_DIAG_DID_F18C_Data_ref_0 DIAG_DID_F18C_Data_ref[20];

# define Rte_TypeDef_DIAG_DID_F190_Data_ref
typedef Rte_DT_DIAG_DID_F190_Data_ref_0 DIAG_DID_F190_Data_ref[17];

# define Rte_TypeDef_DIAG_DID_F191_Data_ref
typedef Rte_DT_DIAG_DID_F191_Data_ref_0 DIAG_DID_F191_Data_ref[10];

# define Rte_TypeDef_DIAG_DID_F194_Data_ref
typedef Rte_DT_DIAG_DID_F194_Data_ref_0 DIAG_DID_F194_Data_ref[32];

# define Rte_TypeDef_DIAG_DID_F195_Data_ref
typedef Rte_DT_DIAG_DID_F195_Data_ref_0 DIAG_DID_F195_Data_ref[32];

# define Rte_TypeDef_DIAG_DID_F1A1_Data_ref
typedef Rte_DT_DIAG_DID_F1A1_Data_ref_0 DIAG_DID_F1A1_Data_ref[10];

# define Rte_TypeDef_DIAG_DID_F1A2_Data_ref
typedef Rte_DT_DIAG_DID_F1A2_Data_ref_0 DIAG_DID_F1A2_Data_ref[10];

# define Rte_TypeDef_DIAG_DID_FE11_Data_ref
typedef Rte_DT_DIAG_DID_FE11_Data_ref_0 DIAG_DID_FE11_Data_ref[64];

# define Rte_TypeDef_DTCStatusArrayT
typedef Rte_DT_DTCStatusArrayT_0 DTCStatusArrayT[64];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[1];

# define Rte_TypeDef_DistanceUnitT
typedef Rte_DT_DistanceUnitT_0 DistanceUnitT[19];

# define Rte_TypeDef_ECUHwCodeT
typedef Rte_DT_ECUHwCodeT_0 ECUHwCodeT[2];

# define Rte_TypeDef_ECUSwNumberT
typedef Rte_DT_ECUSwNumberT_0 ECUSwNumberT[6];

# define Rte_TypeDef_ECUSwVersionDateT
typedef Rte_DT_ECUSwVersionDateT_0 ECUSwVersionDateT[9];

# define Rte_TypeDef_ECUSwVersionPCBCodeT
typedef Rte_DT_ECUSwVersionPCBCodeT_0 ECUSwVersionPCBCodeT[5];

# define Rte_TypeDef_ECUVoltageT
typedef Rte_DT_ECUVoltageT_0 ECUVoltageT[19];

# define Rte_TypeDef_EFotaVinResponseType
typedef Rte_DT_EFotaVinResponseType_0 EFotaVinResponseType[24];

# define Rte_TypeDef_ETMStringT
typedef Rte_DT_ETMStringT_0 ETMStringT[16];

# define Rte_TypeDef_ExtTempT
typedef Rte_DT_ExtTempT_0 ExtTempT[19];

# define Rte_TypeDef_FuelVolTablConfigSize
typedef Rte_DT_FuelVolTablConfigSize_0 FuelVolTablConfigSize[28];

# define Rte_TypeDef_GIP_ResetReason_Type
typedef Rte_DT_GIP_ResetReason_Type_0 GIP_ResetReason_Type[40];

# define Rte_TypeDef_GadeT
typedef Rte_DT_GadeT_0 GadeT[19];

# define Rte_TypeDef_Gauge_Correction_Table_X
typedef Rte_DT_Gauge_Correction_Table_X_0 Gauge_Correction_Table_X[15];

# define Rte_TypeDef_Gauge_Correction_Table_Y
typedef Rte_DT_Gauge_Correction_Table_Y_0 Gauge_Correction_Table_Y[15];

# define Rte_TypeDef_Gauge_Mapping_Table_X
typedef Rte_DT_Gauge_Mapping_Table_X_0 Gauge_Mapping_Table_X[15];

# define Rte_TypeDef_Gauge_Mapping_Table_Y
typedef Rte_DT_Gauge_Mapping_Table_Y_0 Gauge_Mapping_Table_Y[15];

# define Rte_TypeDef_HFE2MinsValueType
typedef Rte_DT_HFE2MinsValueType_0 HFE2MinsValueType[15];

# define Rte_TypeDef_HFEValueType
typedef Rte_DT_HFEValueType_0 HFEValueType[6];

# define Rte_TypeDef_HandBrakeT
typedef Rte_DT_HandBrakeT_0 HandBrakeT[19];

# define Rte_TypeDef_IGNStatusT
typedef Rte_DT_IGNStatusT_0 IGNStatusT[19];

# define Rte_TypeDef_Ikey_Link_Data_AlertSetting_ref
typedef Rte_DT_Ikey_Link_Data_AlertSetting_ref_0 Ikey_Link_Data_AlertSetting_ref[4];

# define Rte_TypeDef_Ikey_Link_Data_Top_ref
typedef Rte_DT_Ikey_Link_Data_Top_ref_0 Ikey_Link_Data_Top_ref[4];

# define Rte_TypeDef_Ikey_Link_Data_ref
typedef Rte_DT_Ikey_Link_Data_ref_0 Ikey_Link_Data_ref[4];

# define Rte_TypeDef_IndicatorOutputType
typedef Rte_DT_IndicatorOutputType_0 IndicatorOutputType[58];

# define Rte_TypeDef_LaneMarker
typedef Rte_DT_LaneMarker_0 LaneMarker[8];

# define Rte_TypeDef_Language_Cfg_Type
typedef Rte_DT_Language_Cfg_Type_0 Language_Cfg_Type[36];

# define Rte_TypeDef_MainMenuArrayT
typedef Rte_DT_MainMenuArrayT_0 MainMenuArrayT[34];

# define Rte_TypeDef_MasterWakeupCommandT
typedef Rte_DT_MasterWakeupCommandT_0 MasterWakeupCommandT[19];

# define Rte_TypeDef_NV_FuelTable_ref
typedef Rte_DT_NV_FuelTable_ref_0 NV_FuelTable_ref[12];

# define Rte_TypeDef_NV_IllumDutyTable_ref
typedef Rte_DT_NV_IllumDutyTable_ref_0 NV_IllumDutyTable_ref[22];

# define Rte_TypeDef_NV_SigmaDataIndexArray_T
typedef Rte_DT_NV_SigmaDataIndexArray_T_0 NV_SigmaDataIndexArray_T[16];

# define Rte_TypeDef_NV_SigmaSSD_T
typedef Rte_DT_NV_SigmaSSD_T_0 NV_SigmaSSD_T[63];

# define Rte_TypeDef_NV_SigmaTimeData_T
typedef Rte_DT_NV_SigmaTimeData_T_0 NV_SigmaTimeData_T[3];

# define Rte_TypeDef_NV_SigmaVTD_T
typedef Rte_DT_NV_SigmaVTD_T_0 NV_SigmaVTD_T[128];

# define Rte_TypeDef_OAT_ADC_Count_ref
typedef Rte_DT_OAT_ADC_Count_ref_0 OAT_ADC_Count_ref[17];

# define Rte_TypeDef_OAT_TempDeg_ref
typedef Rte_DT_OAT_TempDeg_ref_0 OAT_TempDeg_ref[17];

# define Rte_TypeDef_ReprogBufferType
typedef Rte_DT_ReprogBufferType_0 ReprogBufferType[176];

# define Rte_TypeDef_SafeTTResponseBufferType
typedef Rte_DT_SafeTTResponseBufferType_0 SafeTTResponseBufferType[87];

# define Rte_TypeDef_SafeTTStatusBufferType
typedef Rte_DT_SafeTTStatusBufferType_0 SafeTTStatusBufferType[21];

# define Rte_TypeDef_SigmaFrameT
typedef Rte_DT_SigmaFrameT_0 SigmaFrameT[7];

# define Rte_TypeDef_SlaveRefuseToSleepT
typedef Rte_DT_SlaveRefuseToSleepT_0 SlaveRefuseToSleepT[19];

# define Rte_TypeDef_TFotaVersion
typedef Rte_DT_TFotaVersion_0 TFotaVersion[6];

# define Rte_TypeDef_TTBlinkArray
typedef Rte_DT_TTBlinkArray_0 TTBlinkArray[8];

# define Rte_TypeDef_TT_OP_Type
typedef Rte_DT_TT_OP_Type_0 TT_OP_Type[54];

# define Rte_TypeDef_UI_AUDIO_SOURCE_AVAILABLE_T
typedef Rte_DT_UI_AUDIO_SOURCE_AVAILABLE_T_0 UI_AUDIO_SOURCE_AVAILABLE_T[40];

# define Rte_TypeDef_UI_FREQ_ARRAY
typedef Rte_DT_UI_FREQ_ARRAY_0 UI_FREQ_ARRAY[8];

# define Rte_TypeDef_UI_LANE_ARROW_TYPE_T
typedef Rte_DT_UI_LANE_ARROW_TYPE_T_0 UI_LANE_ARROW_TYPE_T[11];

# define Rte_TypeDef_UI_NAVI_DISTANCE_ARRAY_T
typedef Rte_DT_UI_NAVI_DISTANCE_ARRAY_T_0 UI_NAVI_DISTANCE_ARRAY_T[9];

# define Rte_TypeDef_UI_RA_EXIT_NUMBER_T
typedef Rte_DT_UI_RA_EXIT_NUMBER_T_0 UI_RA_EXIT_NUMBER_T[4];

# define Rte_TypeDef_UI_TEXT_BUFFER_T
typedef Rte_DT_UI_TEXT_BUFFER_T_0 UI_TEXT_BUFFER_T[65];

# define Rte_TypeDef_UI_TV_CHANNEL_T
typedef Rte_DT_UI_TV_CHANNEL_T_0 UI_TV_CHANNEL_T[6];

# define Rte_TypeDef_Uint8Array_10_ref_T
typedef Rte_DT_Uint8Array_10_ref_T_0 Uint8Array_10_ref_T[10];

# define Rte_TypeDef_Uint8Array_16_ref_T
typedef Rte_DT_Uint8Array_16_ref_T_0 Uint8Array_16_ref_T[16];

# define Rte_TypeDef_Uint8Array_17_ref_T
typedef Rte_DT_Uint8Array_17_ref_T_0 Uint8Array_17_ref_T[17];

# define Rte_TypeDef_Uint8Array_18_ref_T
typedef Rte_DT_Uint8Array_18_ref_T_0 Uint8Array_18_ref_T[18];

# define Rte_TypeDef_Uint8Array_20_ref_T
typedef Rte_DT_Uint8Array_20_ref_T_0 Uint8Array_20_ref_T[20];

# define Rte_TypeDef_Uint8Array_3_ref_T
typedef Rte_DT_Uint8Array_3_ref_T_0 Uint8Array_3_ref_T[3];

# define Rte_TypeDef_Uint8Array_4_ref_T
typedef Rte_DT_Uint8Array_4_ref_T_0 Uint8Array_4_ref_T[4];

# define Rte_TypeDef_Uint8Array_5_ref_T
typedef Rte_DT_Uint8Array_5_ref_T_0 Uint8Array_5_ref_T[5];

# define Rte_TypeDef_Uint8Array_8_ref_T
typedef Rte_DT_Uint8Array_8_ref_T_0 Uint8Array_8_ref_T[8];

# define Rte_TypeDef_Uint8FotaArray_6_ref_T
typedef Rte_DT_Uint8FotaArray_6_ref_T_0 Uint8FotaArray_6_ref_T[6];

# define Rte_TypeDef_Ul_LANE_ARROW_GUIDE_INFO_T
typedef Rte_DT_Ul_LANE_ARROW_GUIDE_INFO_T_0 Ul_LANE_ARROW_GUIDE_INFO_T[11];

# define Rte_TypeDef_Ul_VR_DIGITS
typedef Rte_DT_Ul_VR_DIGITS_0 Ul_VR_DIGITS[25];

# define Rte_TypeDef_User_Login_Data_AlertSetting_ref
typedef Rte_DT_User_Login_Data_AlertSetting_ref_0 User_Login_Data_AlertSetting_ref[5];

# define Rte_TypeDef_User_Login_Data_Top_ref
typedef Rte_DT_User_Login_Data_Top_ref_0 User_Login_Data_Top_ref[5];

# define Rte_TypeDef_User_Login_Data_ref
typedef Rte_DT_User_Login_Data_ref_0 User_Login_Data_ref[5];

# define Rte_TypeDef_VehiclePosType
typedef Rte_DT_VehiclePosType_0 VehiclePosType[8];

# define Rte_TypeDef_VehicleSpeedT
typedef Rte_DT_VehicleSpeedT_0 VehicleSpeedT[19];

# define Rte_TypeDef_VehicleStsType
typedef Rte_DT_VehicleStsType_0 VehicleStsType[8];

# define Rte_TypeDef_Visteon_Product_Config_Data_ref
typedef Rte_DT_Visteon_Product_Config_Data_ref_0 Visteon_Product_Config_Data_ref[30];

# define Rte_TypeDef_WICodeT
typedef Rte_DT_WICodeT_0 WICodeT[4];

# define Rte_TypeDef_data_u16_10
typedef Rte_DT_data_u16_10_0 data_u16_10[10];

# define Rte_TypeDef_data_u16_15
typedef Rte_DT_data_u16_15_0 data_u16_15[15];

# define Rte_TypeDef_data_u16_16
typedef Rte_DT_data_u16_16_0 data_u16_16[16];

# define Rte_TypeDef_data_u16_3
typedef Rte_DT_data_u16_3_0 data_u16_3[3];

# define Rte_TypeDef_data_u16_50
typedef Rte_DT_data_u16_50_0 data_u16_50[50];

# define Rte_TypeDef_data_u16_6
typedef Rte_DT_data_u16_6_0 data_u16_6[6];

# define Rte_TypeDef_data_u32_3
typedef Rte_DT_data_u32_3_0 data_u32_3[3];

# define Rte_TypeDef_data_u32_50
typedef Rte_DT_data_u32_50_0 data_u32_50[50];

# define Rte_TypeDef_data_u32_6
typedef Rte_DT_data_u32_6_0 data_u32_6[6];

# define Rte_TypeDef_data_u8_10
typedef Rte_DT_data_u8_10_0 data_u8_10[10];

# define Rte_TypeDef_data_u8_12
typedef Rte_DT_data_u8_12_0 data_u8_12[12];

# define Rte_TypeDef_data_u8_130
typedef Rte_DT_data_u8_130_0 data_u8_130[130];

# define Rte_TypeDef_data_u8_15
typedef Rte_DT_data_u8_15_0 data_u8_15[15];

# define Rte_TypeDef_data_u8_17
typedef Rte_DT_data_u8_17_0 data_u8_17[17];

# define Rte_TypeDef_data_u8_25
typedef Rte_DT_data_u8_25_0 data_u8_25[25];

# define Rte_TypeDef_data_u8_256
typedef Rte_DT_data_u8_256_0 data_u8_256[256];

# define Rte_TypeDef_data_u8_280
typedef Rte_DT_data_u8_280_0 data_u8_280[280];

# define Rte_TypeDef_data_u8_3
typedef Rte_DT_data_u8_3_0 data_u8_3[3];

# define Rte_TypeDef_data_u8_300
typedef Rte_DT_data_u8_300_0 data_u8_300[300];

# define Rte_TypeDef_data_u8_32
typedef Rte_DT_data_u8_32_0 data_u8_32[32];

# define Rte_TypeDef_data_u8_320
typedef Rte_DT_data_u8_320_0 data_u8_320[320];

# define Rte_TypeDef_data_u8_35
typedef Rte_DT_data_u8_35_0 data_u8_35[35];

# define Rte_TypeDef_data_u8_4
typedef Rte_DT_data_u8_4_0 data_u8_4[4];

# define Rte_TypeDef_data_u8_40
typedef Rte_DT_data_u8_40_0 data_u8_40[40];

# define Rte_TypeDef_data_u8_5
typedef Rte_DT_data_u8_5_0 data_u8_5[5];

# define Rte_TypeDef_data_u8_50
typedef Rte_DT_data_u8_50_0 data_u8_50[50];

# define Rte_TypeDef_data_u8_60
typedef Rte_DT_data_u8_60_0 data_u8_60[60];

# define Rte_TypeDef_data_u8_65
typedef Rte_DT_data_u8_65_0 data_u8_65[65];

# define Rte_TypeDef_data_u8_75
typedef Rte_DT_data_u8_75_0 data_u8_75[75];

# define Rte_TypeDef_data_u8_8
typedef Rte_DT_data_u8_8_0 data_u8_8[8];

# define Rte_TypeDef_received_data
typedef Rte_DT_received_data_0 received_data[1024];

# define Rte_TypeDef_t_uint16_x_12
typedef uint16 t_uint16_x_12[12];

# define Rte_TypeDef_t_uint16_x_15
typedef uint16 t_uint16_x_15[15];

# define Rte_TypeDef_t_uint16_x_22
typedef uint16 t_uint16_x_22[22];

# define Rte_TypeDef_t_uint16_x_3
typedef uint16 t_uint16_x_3[3];

# define Rte_TypeDef_t_uint32_x_4
typedef uint16 t_uint32_x_4[4];

# define Rte_TypeDef_t_uint32_x_5
typedef UInt32 t_uint32_x_5[5];

# define Rte_TypeDef_t_uint8_x_10
typedef uint8 t_uint8_x_10[10];

# define Rte_TypeDef_t_uint8_x_100
typedef uint8 t_uint8_x_100[100];

# define Rte_TypeDef_t_uint8_x_128
typedef uint8 t_uint8_x_128[128];

# define Rte_TypeDef_t_uint8_x_16
typedef uint8 t_uint8_x_16[16];

# define Rte_TypeDef_t_uint8_x_160
typedef uint8 t_uint8_x_160[160];

# define Rte_TypeDef_t_uint8_x_17
typedef uint8 t_uint8_x_17[17];

# define Rte_TypeDef_t_uint8_x_18
typedef uint8 t_uint8_x_18[18];

# define Rte_TypeDef_t_uint8_x_2
typedef uint8 t_uint8_x_2[2];

# define Rte_TypeDef_t_uint8_x_20
typedef uint8 t_uint8_x_20[20];

# define Rte_TypeDef_t_uint8_x_256
typedef uint8 t_uint8_x_256[256];

# define Rte_TypeDef_t_uint8_x_3
typedef uint8 t_uint8_x_3[3];

# define Rte_TypeDef_t_uint8_x_30
typedef uint8 t_uint8_x_30[30];

# define Rte_TypeDef_t_uint8_x_32
typedef uint8 t_uint8_x_32[32];

# define Rte_TypeDef_t_uint8_x_4
typedef uint8 t_uint8_x_4[4];

# define Rte_TypeDef_t_uint8_x_5
typedef uint8 t_uint8_x_5[5];

# define Rte_TypeDef_t_uint8_x_6
typedef uint8 t_uint8_x_6[6];

# define Rte_TypeDef_t_uint8_x_63
typedef uint8 t_uint8_x_63[63];

# define Rte_TypeDef_t_uint8_x_64
typedef uint8 t_uint8_x_64[64];

# define Rte_TypeDef_t_uint8_x_8
typedef uint8 t_uint8_x_8[8];

# define Rte_TypeDef_AD1L3StrgIconS
typedef struct
{
  SteeringColorType SteeringColor;
  HandColorType HandsColor;
  BlinkStatusType BlinkStatus;
} AD1L3StrgIconS;

# define Rte_TypeDef_AccelGuideValueS
typedef struct
{
  UInt8 EcoNonEcoThershold;
  UInt8 EcoSuperEcoThershold;
  UInt8 AccelGuideRatio;
  UInt16 HysteresisVehicleSpeed;
} AccelGuideValueS;

# define Rte_TypeDef_BatterModeS
typedef struct
{
  UInt8 ChargeModeIndicatorDisplay;
  BatteryModeDisplayT CurrentBatteryMode;
  BatModeCursorStateT BatModeNormalState;
  BatModeCursorStateT BatModeEVState;
  BatModeCursorStateT BatModeSaveState;
  BatModeCursorStateT BatModeChargeState;
} BatterModeS;

# define Rte_TypeDef_BatterySOCS
typedef struct
{
  UInt8 BatterySOCLevel;
  SOCBarColorT BatteryScaleDisplay;
} BatterySOCS;

# define Rte_TypeDef_ButtonAndEvents
typedef struct
{
  ButtonID CurrentButton;
  ButtonEvents CurrentEvent;
} ButtonAndEvents;

# define Rte_TypeDef_ChanStatusStruc
typedef struct
{
  UInt16 C1_count;
  STATE_TYPE state;
  UInt8 conn_flag;
} ChanStatusStruc;

# define Rte_TypeDef_ChargeGaugeDataS
typedef struct
{
  UInt8 ChargeGaugeAvailability;
  UInt8 ChargeGaugeValue;
} ChargeGaugeDataS;

# define Rte_TypeDef_ClockType
typedef struct
{
  UInt8 CurrHour;
  UInt8 CurrMinute;
  TIME_FORMAT_TYPE CurrentMode;
} ClockType;

# define Rte_TypeDef_CombiSWConfigS
typedef struct
{
  CombLightSWType_CF_Type CombLightSWType_CF;
  CombWiperSWType_CF_Type CombWiperSWType_CF;
} CombiSWConfigS;

# define Rte_TypeDef_CombiSWOutputS
typedef struct
{
  CombiSWLightOPType LightSwType;
  CombiSWWiperSwType WiperSwType;
  CombiSWWiperLevelType WiperLevel;
  CombiSWWiperSwStatus WiperSwStatus;
  CombiSwLightStatus LightSwStatus;
  CombiRearWiperSwStatus RearWiperSwStatus;
  GuidanceSwType GuidanceSwStatus;
} CombiSWOutputS;

# define Rte_TypeDef_CurrentHMIDetailsType
typedef struct
{
  Language CurrrentLanguage;
  CurrentUIModeType CurrentMode;
} CurrentHMIDetailsType;

# define Rte_TypeDef_DiagGSIPayloadS
typedef struct
{
  GSIStatus GSICurStatus;
  DiagGearNumber DiagGSICurGearNumber;
} DiagGSIPayloadS;

# define Rte_TypeDef_DialConfigT
typedef struct
{
  TachoDesignUnitT TachoDialDesign_CF;
  TachoUnitT TachoDialUnit_CF;
  UInt16 TachoRedZoneMax_CF;
  UInt16 TachoRedZoneStart_CF;
  TachoStateT Tacho_CF;
  PowerStateT PowerGauge_CF;
  EnergyMetertypeT EnergyMeter_CF;
  UInt16 SpeedoMainMaxSpeed_CF;
  SubSpeedUnitT SpeedoMainUnit_CF;
  FeatureStatus SpeedoSubAvailable_CF;
  UInt16 SpeedoSubMaxSpeed_CF;
  SubSpeedUnitT SpeedoSubUnit_CF;
  UInt8 WaterTempMeter_CF;
  UInt8 AssistChargeMeter_CF;
  DialDesignTypeT WaterTempMeterType_CF_DialDesign;
  DialDesignStdT WaterTempMeter_CF_Std;
} DialConfigT;

# define Rte_TypeDef_DoorAjarPayloadS
typedef struct
{
  DoorStatus FronRightDoor;
  DoorStatus FrontLeftDoor;
  DoorStatus RearRightDoor;
  DoorStatus RearLeftDoor;
  DoorStatus Boot;
  DoorStatus DriveDoor;
  DoorStatus GlasshatchDoor;
} DoorAjarPayloadS;

# define Rte_TypeDef_EnergyFlowStatusS
typedef struct
{
  BatteryWheelT EnergyFlowBatFrontMot;
  BatteryWheelT EnergyFlowBatRearMot;
  EngineBatteryT EnergyFlowEngBattery;
  EnergyFlowStateT EnergyFlowStatus;
  EnergyRunningStateT EnergyRunningStatus;
} EnergyFlowStatusS;

# define Rte_TypeDef_GSIPayloadS
typedef struct
{
  GSIStatus GSICurStatus;
  GearNumber GSICurGearNumber;
} GSIPayloadS;

# define Rte_TypeDef_IFEConfigT
typedef struct
{
  UInt16 IFERange_CF;
  MilageUnits IFEFuelConsumption_CF;
  IFETypeT IFEType_CF;
} IFEConfigT;

# define Rte_TypeDef_ITSAccelPedalHighS
typedef struct
{
  DCAStatusType DCAAccelPedalStatus;
  BSIStatusType BSIAccelPedalStatus;
  FEBStatusType FEBAccelPedalStatus;
} ITSAccelPedalHighS;

# define Rte_TypeDef_ITSBadWeatherS
typedef struct
{
  LKAStatusType LKABWStatus;
  CruiseStatusType CruiseAD1BWStatus;
  FEBStatusType FEBBWStatus;
} ITSBadWeatherS;

# define Rte_TypeDef_ITSCameraFaultS
typedef struct
{
  LDWStatusType LDWCameraFaultStatus;
  LDPStatusType LDPCameraFaultStatus;
  BSIStatusType BSICameraFaultStatus;
  LKAStatusType LKACameraFaultStatus;
  FEBStatusType FEBCameraFaultStatus;
} ITSCameraFaultS;

# define Rte_TypeDef_ITSCleanUpFrontCameraS
typedef struct
{
  LKAStatusType LKACleanFrontCameraStatus;
  FEBStatusType FEBCleanFrontCameraStatus;
  ELKAStatusType ELKACleanFrontCameraStatus;
} ITSCleanUpFrontCameraS;

# define Rte_TypeDef_ITSFEBSensorBlockedS
typedef struct
{
  FrVehicleType FrVehicleStatus;
  FrCameraType FrCamersStatus;
  FrRadarType FrRadarStatus;
} ITSFEBSensorBlockedS;

# define Rte_TypeDef_ITSFrontRadarBlockedS
typedef struct
{
  FEBStatusType FEBFrontRadarBlockedStatus;
  CruiseStatusType CruiseFrontRadarBlockedStatus;
  DCAStatusType DCAFrontRadarBlockedStatus;
  ELKAStatusType ELKAFrontRadarBlockedStatus;
} ITSFrontRadarBlockedS;

# define Rte_TypeDef_ITSHandleReleaseS
typedef struct
{
  IconStatusType IconHandleReleaseStatus;
  TextStatusType TextHandleReleaseStatus;
} ITSHandleReleaseS;

# define Rte_TypeDef_ITSNotOperateS
typedef struct
{
  LKAStatusType LKANotOpStatus;
  CruiseStatusType CruiseAD1NotOpStatus;
} ITSNotOperateS;

# define Rte_TypeDef_ITSSideRadarBlockedS
typedef struct
{
  BSIStatusType BSISideRadarBlockedStatus;
  BSWStatusType BSWSideRadarBlockedStatus;
  BCIStatusType BCISideRadarBlockedStatus;
  CTAStatusType CTASideRadarBlockedStatus;
  ELKAStatusType ELKASideRadarBlockedStatus;
} ITSSideRadarBlockedS;

# define Rte_TypeDef_ITSSlipperyRoadS
typedef struct
{
  LDPStatusType LDPSlipperyStatus;
  BSIStatusType BSISlipperyStatus;
  DCAStatusType DCASlipperyStatus;
  AD1StatusType AD1SlipperyStatus;
} ITSSlipperyRoadS;

# define Rte_TypeDef_ITSSystemFaultS
typedef struct
{
  LDWStatusType LDWSystemFaultStatus;
  LDPStatusType LDPSystemFaultStatus;
  BSIStatusType BSISystemFaultStatus;
  BSWStatusType BSWSystemFaultStatus;
  CruiseStatusType CruiseSystemFaultStatus;
  LKAStatusType LKASystemFaultStatus;
  DCAStatusType DCASystemFaultStatus;
  ELKAStatusType ELKASystemFaultStatus;
} ITSSystemFaultS;

# define Rte_TypeDef_ITSVDCOffS
typedef struct
{
  LDPStatusType LDPVdcOffStatus;
  BSIStatusType BSIVdcOffStatus;
  AD1StatusType AD1VdcOffStatus;
  DCAStatusType DCAVdcOffStatus;
  ELKAStatusType ELKAVdcOffStatus;
} ITSVDCOffS;

# define Rte_TypeDef_IdleStopCLTTimeS
typedef struct
{
  UInt8 IdleStopCltHours;
  UInt8 IdleStopCltMins;
  UInt8 IdleStopCltSecs;
} IdleStopCLTTimeS;

# define Rte_TypeDef_IdleStopTimeS
typedef struct
{
  UInt8 IdleStopHours;
  UInt8 IdleStopMins;
  UInt8 IdleStopSecs;
} IdleStopTimeS;

# define Rte_TypeDef_IdleStopVLTTimeS
typedef struct
{
  UInt16 IdleStopVltHours;
  UInt16 IdleStopVltMins;
  UInt16 IdleStopVltSecs;
} IdleStopVLTTimeS;

# define Rte_TypeDef_IllumCurSteps
typedef struct
{
  UInt8 CurDaySteps;
  UInt8 CurNighSteps;
} IllumCurSteps;

# define Rte_TypeDef_MCANFaultT
typedef struct
{
  MCANChannelT McanChannelId;
  McanFaultState McanFaultState;
} MCANFaultT;

# define Rte_TypeDef_MCAN_CLOCK_SETTING
typedef struct
{
  TIME_FORMAT_TYPE Time_Format;
  CLOCK_MODE_TYPE Clock_Mode;
  SET_CLOCK_TYPE Set_Clock;
  UInt8 hour_changed;
  UInt8 Clock_Setting_hour;
  UInt8 minute_changed;
  UInt8 Clock_Setting_minute;
  DAYLIGHT_SAVING_TYPE Daylight_Saving;
  TIME_ZONE_TYPE Time_Zone;
} MCAN_CLOCK_SETTING;

# define Rte_TypeDef_MCAN_TIME_INFO
typedef struct
{
  TIME_CLOCK_TYPE clock_type;
  UInt8 time_info_hour;
  UInt8 time_info_minute;
} MCAN_TIME_INFO;

# define Rte_TypeDef_NV_AccelGuideParameters
typedef struct
{
  UInt8 AccelGuideSpeed_V1_Min;
  UInt8 AccelGuideSpeed_V1_Max;
  UInt8 AccelGuideSpeed_V2_Max;
  UInt8 AccelGuideSpeed_V2_Min;
  UInt8 AccelGuideSpeed_V3_Max;
  UInt8 AccelGuideSpeed_V3_Min;
  UInt8 EcoRate_E1_Value;
  UInt8 EcoRate_E2_Value;
  UInt8 EcoRate_E3_Value;
  UInt8 EcoRate_E4_Value;
  UInt8 EcoRank_T1_Min_Time;
} NV_AccelGuideParameters;

# define Rte_TypeDef_NV_Data_ApplicationRandomNumber
typedef struct
{
  UInt32 BootApplicationRandomNumber_0;
} NV_Data_ApplicationRandomNumber;

# define Rte_TypeDef_NV_Data_DiagDID310
typedef struct
{
  UInt8 NV_DIAG_DID_310_Data;
} NV_Data_DiagDID310;

# define Rte_TypeDef_NV_Data_DiagDID420
typedef struct
{
  UInt8 NV_DIAG_DID_420_Data;
} NV_Data_DiagDID420;

# define Rte_TypeDef_NV_Data_DiagDID430
typedef struct
{
  UInt8 NV_DIAG_DID_430_Data;
} NV_Data_DiagDID430;

# define Rte_TypeDef_NV_Data_DiagDID440
typedef struct
{
  UInt8 NV_DIAG_DID_440_Data;
} NV_Data_DiagDID440;

# define Rte_TypeDef_NV_Data_DiagDID450
typedef struct
{
  UInt8 NV_DIAG_DID_450_Data;
} NV_Data_DiagDID450;

# define Rte_TypeDef_NV_Data_DiagDID500
typedef struct
{
  UInt8 NV_DIAG_DID_500_Data;
} NV_Data_DiagDID500;

# define Rte_TypeDef_NV_Data_DiagDID900
typedef struct
{
  UInt8 NV_DIAG_DID_900_Data;
} NV_Data_DiagDID900;

# define Rte_TypeDef_NV_Data_FBLValidDTCState
typedef struct
{
  UInt8 ValidDTCState;
} NV_Data_FBLValidDTCState;

# define Rte_TypeDef_NV_Data_FBL_NVM
typedef struct
{
  UInt8 ECUCompatibilityDTCState;
  UInt8 ECUGeneralMemoryFailureDTCState;
  UInt16 ProgLimitCntr;
  UInt8 CoherencyDTCState;
  UInt8 GeneralMemoryFailureDTCState;
  UInt8 SecurebootCount;
  UInt8 CmacAppCount;
  UInt8 CmacFotaCount;
  UInt8 CmacRollbackCount;
} NV_Data_FBL_NVM;

# define Rte_TypeDef_NV_Data_FuelCalcCalib
typedef struct
{
  UInt16 NV_XFuelValue;
  UInt16 NV_YFuelValue;
} NV_Data_FuelCalcCalib;

# define Rte_TypeDef_NV_Data_GUST_USER_LOGIN
typedef struct
{
  UInt8 Gust_NVM_Main_menu_Select_byte1_User;
  UInt8 Gust_NVM_Main_menu_Select_byte2_User;
  UInt8 Gust_NVM_Car_color_Eco_Welcome_User;
  UInt8 Gust_NVM_TPMS_Temp_unit_setting_User;
  UInt32 Gust_NVM_Top_layer_contents_User;
  UInt8 Gust_NVM_Lang_Navi_User;
  UInt8 Gust_NVM_illum_mode_step_User;
  UInt8 Gust_NVM_illum_night_step_User;
  UInt32 Gust_NVM_AlertSetting_User;
  UInt8 Gust_NVM_Key_Link_UserLogin;
  UInt8 Gust_NVM_PersonalDisplay_User;
  UInt8 Gust_NVM_OperationGuidance_User;
} NV_Data_GUST_USER_LOGIN;

# define Rte_TypeDef_NV_Data_IllumPWMCalib
typedef struct
{
  UInt16 IllumReferenceMaxIntensity;
  UInt16 IllumMeasuredMaxIntensity;
  UInt16 NV_PWMTFTBLCalibrationGain;
  UInt16 NV_PWMLeftDialCalibrationGain;
  UInt16 NV_PWMRightDialCalibrationGain;
  UInt16 NV_PWMBigLeftPointerCalibrationGain;
  UInt16 NV_PWMBigRightPointerCalibrationGain;
  UInt16 NV_PWMSmallLeftPointerCalibrationGain;
  UInt16 NV_PWMSmallRightPointerCalibrationGain;
} NV_Data_IllumPWMCalib;

# define Rte_TypeDef_NV_Data_LoaderModeDetected
typedef struct
{
  UInt32 BootForcedLoaderModeDetected_0;
} NV_Data_LoaderModeDetected;

# define Rte_TypeDef_NV_Data_NvM_Revision_Value
typedef struct
{
  UInt8 NV_NvM_Revision_Value;
} NV_Data_NvM_Revision_Value;

# define Rte_TypeDef_NV_Data_NvM_Version_Value
typedef struct
{
  UInt8 NV_NvM_Version_Value;
} NV_Data_NvM_Version_Value;

# define Rte_TypeDef_NV_Data_Odometer_BLK1
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value1;
} NV_Data_Odometer_BLK1;

# define Rte_TypeDef_NV_Data_Odometer_BLK2
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value2;
} NV_Data_Odometer_BLK2;

# define Rte_TypeDef_NV_Data_Odometer_BLK3
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value3;
} NV_Data_Odometer_BLK3;

# define Rte_TypeDef_NV_Data_Odometer_BLK4
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value4;
} NV_Data_Odometer_BLK4;

# define Rte_TypeDef_NV_Data_Odometer_BLK5
typedef struct
{
  UInt32 NV_Odo_Running_Count_Value5;
} NV_Data_Odometer_BLK5;

# define Rte_TypeDef_NV_Data_VehicleStateDetected
typedef struct
{
  UInt32 BootVehicleStateDetected_0;
} NV_Data_VehicleStateDetected;

# define Rte_TypeDef_Nv_IllumCalibParam_T
typedef struct
{
  UInt16 IllumReferenceMaxIntensity;
  UInt16 IllumMeasuredMaxIntensity;
} Nv_IllumCalibParam_T;

# define Rte_TypeDef_PWM_APP_DATA
typedef struct
{
  PWMSwChannelT ChannelNo_U8;
  UInt16 target_Duty_U16;
  UInt16 target_time_U16;
  UInt16 duty_rate_U16;
} PWM_APP_DATA;

# define Rte_TypeDef_PowerGaugeDataS
typedef struct
{
  UInt8 PowerGaugeAvailability;
  UInt8 PowerGaugeValue;
} PowerGaugeDataS;

# define Rte_TypeDef_PowerGaugeTypeBDataS
typedef struct
{
  UInt8 PowerGaugeBAvailability;
  UInt8 PowerGaugeBValue;
  UInt8 TachoGaugeAvailability;
  UInt16 TachoGaugeValue;
  UInt8 ReadyOffStatus;
} PowerGaugeTypeBDataS;

# define Rte_TypeDef_RSBWarningPayloadS
typedef struct
{
  PopUpStatus RSBWarningState;
  RSBFastenedStatus RSBLeftStatus;
  RSBFastenedStatus RSBCenterStatus;
  RSBFastenedStatus RSBRightStatus;
  RSBFastenedStatus RSB3rdCenterStatus;
  RSBFastenedStatus RSB3rdLeftStatus;
  RSBFastenedStatus RSB3rdRightStatus;
  RSBFastenedStatus RSBDriverStatus;
  RSBFastenedStatus RSBPassengerStatus;
  RSB3rdRowAvailableT RSB3rdRowAvailableState;
  RSBHandlePositionT RSBHandlePosition;
} RSBWarningPayloadS;

# define Rte_TypeDef_Rtc_TimeType
typedef struct
{
  UInt16 Date;
  UInt8 Hour;
  UInt8 Minute;
  UInt8 Second;
} Rtc_TimeType;

# define Rte_TypeDef_SAFEResetCmd
typedef struct
{
  UInt8 resetAFE;
} SAFEResetCmd;

# define Rte_TypeDef_SAVSResetCmd
typedef struct
{
  UInt8 resetAVS;
} SAVSResetCmd;

# define Rte_TypeDef_SAccelGuideValue
typedef struct
{
  UInt8 currentAccelMenuAvailability;
  UInt8 currentEcoRankMenuAvailability;
  UInt8 ecoNonEcoThershold;
  UInt8 ecoSuperEcoThershold;
  UInt8 accelGuideRatio;
  UInt16 hysteresisVehicleSpeed;
  UInt8 ecoRankNumberOfStars;
  UInt8 ecoIndicatorCurrentValue;
  UInt8 TPMSEcoAdviceStatus;
  UInt8 ecoIndicatorSettingsVal;
  UInt8 accelEcoAvailability;
} SAccelGuideValue;

# define Rte_TypeDef_SAudioChannelData
typedef struct
{
  EMcanChannelState_t audioChannelStatus;
} SAudioChannelData;

# define Rte_TypeDef_SAudioInitData
typedef struct
{
  UInt8 audioInitStatus;
} SAudioInitData;

# define Rte_TypeDef_SAudioSourceSelData
typedef struct
{
  EAudioSourceList_t audioSourceSelect;
} SAudioSourceSelData;

# define Rte_TypeDef_SBackUpRamDataRxAck
typedef struct
{
  UInt8 backUpDataRxAck;
} SBackUpRamDataRxAck;

# define Rte_TypeDef_SButtonStatusETM
typedef struct
{
  EPButtonId_t buttonId;
  EPButtonState_t buttonStatus;
  EPButtonState_t switchStatus;
} SButtonStatusETM;

# define Rte_TypeDef_SClockMenuEnterExitEvent
typedef struct
{
  UInt8 enterOrExitClockMenu;
} SClockMenuEnterExitEvent;

# define Rte_TypeDef_SCurrentBulbCheckStatus
typedef struct
{
  UInt16 currentBulbTestStatus;
} SCurrentBulbCheckStatus;

# define Rte_TypeDef_SCurrentETMStatus
typedef struct
{
  UInt16 currentETMState;
} SCurrentETMStatus;

# define Rte_TypeDef_SCurrentSettingsData
typedef struct
{
  UInt16 currSettingsId;
  UInt32 currSettingsVal;
  UInt8 curSettingsAction;
} SCurrentSettingsData;

# define Rte_TypeDef_SCurrentTimeDisplay
typedef struct
{
  UInt8 hour;
  UInt8 minute;
  UInt8 mode;
  UInt8 currentClockMenuType;
  UInt8 clockDisplaySts;
} SCurrentTimeDisplay;

# define Rte_TypeDef_SDimmingData
typedef struct
{
  UInt32 dimmingLevel;
} SDimmingData;

# define Rte_TypeDef_SDisplayCurrentState
typedef struct
{
  UInt32 displayId;
  EDisplayStatus_t state;
} SDisplayCurrentState;

# define Rte_TypeDef_SDisplayGetState
typedef struct
{
  UInt32 displayId;
} SDisplayGetState;

# define Rte_TypeDef_SDisplaySetPower
typedef struct
{
  UInt32 displayId;
  EDisplayPower_t state;
} SDisplaySetPower;

# define Rte_TypeDef_SDistanceToEmptyStatus
typedef struct
{
  UInt16 DTEValue;
  UInt8 DTEWarningStatus;
} SDistanceToEmptyStatus;

# define Rte_TypeDef_SDmnStatus
typedef struct
{
  EDomainId_t dmnId;
  EUclLinkState_t linkStatus;
  SInt32 uclErrCode;
  EDmnHealthState_t dmnHealthState;
  ESystemState_t state;
  EDmnOverallState_t dmnStatus;
} SDmnStatus;

# define Rte_TypeDef_SEMSStatus
typedef struct
{
  UInt8 currentEMSStatus;
} SEMSStatus;

# define Rte_TypeDef_SEctData
typedef struct
{
  UInt8 engineTempValue;
} SEctData;

# define Rte_TypeDef_SEnterorExitClockMenu
typedef struct
{
  UInt8 enterClockSettingsMenu;
} SEnterorExitClockMenu;

# define Rte_TypeDef_SEthlinkDownStatus
typedef struct
{
  UInt8 ethernetLinkStatus;
} SEthlinkDownStatus;

# define Rte_TypeDef_SFotaChangeRequest
typedef struct
{
  EInstallerFotaState_t state;
} SFotaChangeRequest;

# define Rte_TypeDef_SFotaChangeResponse
typedef struct
{
  EFotaSlaveResponse_t fotaSlaveResponse;
  EInstallerFotaState_t installerState;
} SFotaChangeResponse;

# define Rte_TypeDef_SFotaCommandRequest
typedef struct
{
  EInstallerReq_t reqType;
} SFotaCommandRequest;

# define Rte_TypeDef_SFotaCommandResponse
typedef struct
{
  EFotaSlaveResponse_t fotaSlaveResponse;
  EInstallerReq_t requestType;
} SFotaCommandResponse;

# define Rte_TypeDef_SFotaMemCtrlReqData
typedef struct
{
  EMemCtrlShMem_t bankId;
  UInt32 offset;
  UInt32 size;
  EMemCtrlCmd_t cmd;
} SFotaMemCtrlReqData;

# define Rte_TypeDef_SFotaMemCtrlRespData
typedef struct
{
  EMemCtrlShMem_t bankId;
  UInt32 size;
  EMemCtrlCmd_t resp;
} SFotaMemCtrlRespData;

# define Rte_TypeDef_SFotaStateNotify
typedef struct
{
  EInstallerNotif_t notifType;
} SFotaStateNotify;

# define Rte_TypeDef_SFotaStateRequest
typedef struct
{
  UInt8 statereq;
} SFotaStateRequest;

# define Rte_TypeDef_SFotaStateResponse
typedef struct
{
  EInstallerFotaState_t state;
} SFotaStateResponse;

# define Rte_TypeDef_SFotaVersionNotify
typedef struct
{
  UInt8 gipDowngradeCheckSts;
  UInt8 majVer;
  UInt8 minVer;
  UInt8 nvmVer;
} SFotaVersionNotify;

# define Rte_TypeDef_SFotaVinRequest
typedef struct
{
  UInt8 vinreq;
} SFotaVinRequest;

# define Rte_TypeDef_SFuelData
typedef struct
{
  UInt16 fuelFLPSValue;
  UInt8 currentFuelSensorStatus;
} SFuelData;

# define Rte_TypeDef_SGFXScreenID
typedef struct
{
  UInt8 currentScreenID;
  UInt32 currentMainMenu;
} SGFXScreenID;

# define Rte_TypeDef_SHMIPowerONStatus
typedef struct
{
  UInt8 powerONStatus;
} SHMIPowerONStatus;

# define Rte_TypeDef_SHMIProcessStatus
typedef struct
{
  UInt8 processStatus;
} SHMIProcessStatus;

# define Rte_TypeDef_SHMISleepStatus
typedef struct
{
  UInt8 sleepStatus;
  UInt8 HMIReady;
} SHMISleepStatus;

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

# define Rte_TypeDef_SICCDynamicMenuStatus
typedef struct
{
  UInt8 ICCSwipeEvent;
} SICCDynamicMenuStatus;

# define Rte_TypeDef_SIGNOffMenuTimeoutStatus
typedef struct
{
  UInt8 HMIDoorAjarMenuStatus;
} SIGNOffMenuTimeoutStatus;

# define Rte_TypeDef_SIdleStopResetCmd
typedef struct
{
  UInt8 resetIdleStop;
} SIdleStopResetCmd;

# define Rte_TypeDef_SIgnOffPersonalMenuAnimEvent
typedef struct
{
  UInt8 ignOffPersonalMenuEvent;
} SIgnOffPersonalMenuAnimEvent;

# define Rte_TypeDef_SIgnOnPersonalMenuAnimEvent
typedef struct
{
  UInt8 ignOnPersonalMenuEvent;
} SIgnOnPersonalMenuAnimEvent;

# define Rte_TypeDef_SIgnState
typedef struct
{
  EIgnitionStatus_t status;
} SIgnState;

# define Rte_TypeDef_SIgnStateStatus
typedef struct
{
  EIgnitionStatus_t ignStatus;
  EPWUSCurrentVehicleState_t vehicleStatus;
  EWUSCurrentAccState_t ACCStatus;
} SIgnStateStatus;

# define Rte_TypeDef_SIllumButtonEvents
typedef struct
{
  EPButtonId_t buttonId;
  EPIllumButtonEvent_t buttonStatus;
} SIllumButtonEvents;

# define Rte_TypeDef_SKeyVal
typedef struct
{
  UInt32 key;
  UInt32 value;
  UInt32 id;
} SKeyVal;

# define Rte_TypeDef_SMcanFeatureInfo
typedef struct
{
  EUIMcanFeatureAvailability_t MCANClockAvailability;
  EUIMcanFeatureAvailability_t AudioFeatureAvailability;
  EUIMcanFeatureAvailability_t HFFeatureAvailability;
  EUIMcanFeatureAvailability_t SMSFeatureAvailability;
  EUIMcanFeatureAvailability_t VRFeatureAvailability;
  EUIMcanFeatureAvailability_t NaviSourceAvailability;
} SMcanFeatureInfo;

# define Rte_TypeDef_SMemDiagReqData
typedef struct
{
  EMemTypeCmd_t memoryType;
  UInt32 address;
  UInt32 size;
  EMemDiagRequestCmd_t reqCmd;
} SMemDiagReqData;

# define Rte_TypeDef_SMenuBackUpData_t
typedef struct
{
  UInt32 storedMainMenuItem;
  UInt8 currrentLanguage;
  UInt8 currentMode;
  UInt8 batteryConnectChk;
  UInt8 homeScreenSts;
} SMenuBackUpData_t;

# define Rte_TypeDef_SModeChangeAnimEvent
typedef struct
{
  UInt8 modeChangeEvent;
} SModeChangeAnimEvent;

# define Rte_TypeDef_SNaviChannelData
typedef struct
{
  EMcanChannelState_t naviChannelStatus;
} SNaviChannelData;

# define Rte_TypeDef_SNaviInitData
typedef struct
{
  UInt8 naviInitStatus;
} SNaviInitData;

# define Rte_TypeDef_SNvmData
typedef struct
{
  UInt16 nvmEEPROMVersion;
  UInt16 mfgModeReq;
} SNvmData;

# define Rte_TypeDef_SOpeningMovieData
typedef struct
{
  EPOpeningMovieStatus_t openingMovieStatus;
  EPITSOpngMovieStatus_t ITSstatus;
} SOpeningMovieData;

# define Rte_TypeDef_SOpeningMovieResponse
typedef struct
{
  EOpeningMovieAnimStatus_t openingMovieRunningStatus;
  EITSOpngMovieOnDisplay_t ITS_ScreenDisplayStatus;
  UInt8 keyPressEventDuringOpngMoive;
} SOpeningMovieResponse;

# define Rte_TypeDef_SOpngMovieAnimEvent
typedef struct
{
  UInt8 opngMovieEvent;
} SOpngMovieAnimEvent;

# define Rte_TypeDef_SOutsideAirTemperature
typedef struct
{
  SInt8 OATvalue;
} SOutsideAirTemperature;

# define Rte_TypeDef_SPersRecordMsgResp
typedef struct
{
  UInt8 rcvdSettingIdx;
} SPersRecordMsgResp;

# define Rte_TypeDef_SPersonalizedAverageSpeedStatus
typedef struct
{
  UInt8 personalizedAvgSpeedStatus;
  UInt8 personalizedFuelEconomyStatus;
  UInt8 personalizedListSettingStatus;
  UInt8 personalizedTripStatus;
  UInt8 currentIkeyS;
  UInt16 TPMSResetTimeoutEvt;
} SPersonalizedAverageSpeedStatus;

# define Rte_TypeDef_SPhoneDataResponse
typedef struct
{
  UInt8 smsAckevent;
  EUiSmsMenuItem_t smsSelEvent;
  ETelMenuItem_t telSelEvent;
  UInt8 phoneRspData;
} SPhoneDataResponse;

# define Rte_TypeDef_SPhoneIndEvt
typedef struct
{
  UInt8 telTriggerEvent;
} SPhoneIndEvt;

# define Rte_TypeDef_SPopupAckResponse
typedef struct
{
  UInt8 clearIllumPopupRetrigger;
  UInt8 cruiseSlPopupEvt;
  UInt8 cancelReasonPopUpEvt;
  UInt8 rearSeatbeltDisplayStatus;
  UInt8 rearSeatBeltAckEvent;
  UInt16 buttonEventsToMCAN;
  UInt8 BFEUpdateEvent;
  UInt8 ZoneP2ActiveStatus;
} SPopupAckResponse;

# define Rte_TypeDef_SPowerData
typedef struct
{
  UInt16 powerGaugeValue;
} SPowerData;

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

# define Rte_TypeDef_SPowerReportCompState
typedef struct
{
  ECompState_t state;
} SPowerReportCompState;

# define Rte_TypeDef_SPowerSystemState
typedef struct
{
  EDomainId domainId;
  ESystemState state;
} SPowerSystemState;

# define Rte_TypeDef_SPowerSystemStateReqChange
typedef struct
{
  EDomainId domainId;
  ESystemState state;
} SPowerSystemStateReqChange;

# define Rte_TypeDef_SPowerSystemStateReqWakeLock
typedef struct
{
  UInt8 enable;
  UInt32 requiredTimeMs;
} SPowerSystemStateReqWakeLock;

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

# define Rte_TypeDef_SRearSeatBeltStatus
typedef struct
{
  UInt8 rearSeatBeltStatus;
} SRearSeatBeltStatus;

# define Rte_TypeDef_SSelfDiagBackUpData_t
typedef struct
{
  UInt8 errorCodeInit;
  UInt8 illumButtonSts;
  UInt8 tripButtonSts;
  UInt8 illumButtonStuckSts;
  UInt8 tripButtonStuckSts;
} SSelfDiagBackUpData_t;

# define Rte_TypeDef_SSettingsResetData
typedef struct
{
  UInt8 odoDisplayChangeFactoryResetEvt;
} SSettingsResetData;

# define Rte_TypeDef_SSndCddChimeDB
typedef struct
{
  UInt8 ChimeID;
  UInt8 ChannelId;
  UInt8 ChimeType;
  UInt8 ToneRepeat;
  UInt8 ChimeRepeat;
} SSndCddChimeDB;

# define Rte_TypeDef_SSndCddChimeData
typedef struct
{
  UInt8 ChannelId;
  UInt8 ChimeType;
  UInt16 DynamicDeadTime;
} SSndCddChimeData;

# define Rte_TypeDef_SSpeedCalcParam
typedef struct
{
  UInt32 Pulses_Per_Revolution;
  UInt32 Revolutions_Per_Unit;
  UInt32 Tuning_Factor;
} SSpeedCalcParam;

# define Rte_TypeDef_SSpeedData
typedef struct
{
  UInt8 defaultSpeedUnit;
  UInt16 digiSpeedValueInKMPH;
  UInt16 digiSpeedValueInMPH;
  UInt16 speedValueInKMPH;
  UInt16 speedValueInMPH;
  UInt16 vehicleSpeedDisplayedinkmh_Value;
  UInt8 vehicleSpeedDisplayedinkmh_Status;
  UInt16 vehicleSpeedDisplayedinmph_Value;
  UInt8 vehicleSpeedDisplayedinmph_Status;
} SSpeedData;

# define Rte_TypeDef_SStrButtonEvents
typedef struct
{
  EPButtonId_t buttonId;
  EPButtonState_t buttonStatus;
} SStrButtonEvents;

# define Rte_TypeDef_SStrButtonStatus
typedef struct
{
  EPButtonId_t buttonId;
  EPButtonState_t buttonStatus;
} SStrButtonStatus;

# define Rte_TypeDef_SSwUpdateDataTransferReq
typedef struct
{
  UInt32 bufferId;
  UInt32 startAddress;
  UInt32 dataLen;
  UInt8 serviceId;
} SSwUpdateDataTransferReq;

# define Rte_TypeDef_SSwUpdateDownloadSwPartReq
typedef struct
{
  UInt8 swPartId;
  UInt32 startAddress;
  UInt32 length;
  UInt8 serviceId;
} SSwUpdateDownloadSwPartReq;

# define Rte_TypeDef_SSwUpdateEraseSwPartReq
typedef struct
{
  UInt8 swPartId;
  UInt8 serviceId;
} SSwUpdateEraseSwPartReq;

# define Rte_TypeDef_SSwUpdateResponse
typedef struct
{
  UInt8 serviceId;
  UInt32 Data;
  UInt8 status;
} SSwUpdateResponse;

# define Rte_TypeDef_SSwUpdateUploadSwPartReq
typedef struct
{
  UInt8 swPartId;
  UInt32 startAddress;
  UInt32 bufferId;
  UInt32 dataLen;
  UInt32 length;
  UInt8 serviceId;
} SSwUpdateUploadSwPartReq;

# define Rte_TypeDef_STachoData
typedef struct
{
  UInt16 engineRPMValue;
} STachoData;

# define Rte_TypeDef_STelButtonEvents
typedef struct
{
  EPButtonId_t buttonId;
  EPButtonState_t buttonStatus;
} STelButtonEvents;

# define Rte_TypeDef_STpmsSettingsResetSuccessEvt
typedef struct
{
  UInt8 TPMSResetSuccessEvt;
} STpmsSettingsResetSuccessEvt;

# define Rte_TypeDef_STripButtonEvents
typedef struct
{
  EPButtonId_t buttonId;
  EPButtonState_t buttonStatus;
} STripButtonEvents;

# define Rte_TypeDef_STripDistResetCmd
typedef struct
{
  UInt8 resetTripDistance;
} STripDistResetCmd;

# define Rte_TypeDef_STripOdoResetEvent
typedef struct
{
  UInt8 odoResetEvt;
} STripOdoResetEvent;

# define Rte_TypeDef_STripTimeResetCmd
typedef struct
{
  UInt8 resetTripTime;
} STripTimeResetCmd;

# define Rte_TypeDef_SUclErrorNotify
typedef struct
{
  SInt32 errorCode;
} SUclErrorNotify;

# define Rte_TypeDef_SUclLinkStatus
typedef struct
{
  SInt32 linkState;
} SUclLinkStatus;

# define Rte_TypeDef_SUclMessageStatus
typedef struct
{
  SInt32 Status;
} SUclMessageStatus;

# define Rte_TypeDef_SUnitLanguageSettings
typedef struct
{
  UInt8 currentTempUnit;
  UInt8 currentDistanceUnit;
  UInt8 currentFuelUnit;
  UInt8 currentTPMSUnit;
  UInt8 currentLanguage;
} SUnitLanguageSettings;

# define Rte_TypeDef_SVCRStatus
typedef struct
{
  UInt8 boostPressure;
  UInt8 VCRCompressionRatio;
} SVCRStatus;

# define Rte_TypeDef_SVariantConfigData
typedef struct
{
  UInt8 vehicleTypeCF;
  UInt8 variantTypeCF;
} SVariantConfigData;

# define Rte_TypeDef_SettingsUpdateS
typedef struct
{
  SettingsID CurrSettingsId;
  UInt32 CurrSettingsVal;
  SettingsActionType CurSettingsAction;
} SettingsUpdateS;

# define Rte_TypeDef_SigmaVSS_T
typedef struct
{
  UInt8 SIGMA_NO_V_LOCAL;
  UInt8 SIGMATrigger;
  UInt8 SIGMAIGN;
  UInt8 SIGMATriCount_GLOBAL;
  UInt32 SIGMAMileage;
  UInt8 SIGMA_Infor_V_GLOBAL;
  UInt8 SIGMA_NO_V_GLOBAL;
  UInt8 SIGMA_Infor_V_LOCAL;
  UInt8 SIGMATriCount_LOCAL;
} SigmaVSS_T;

# define Rte_TypeDef_SonarPayloadS
typedef struct
{
  SonarSensorAvailability RearCenterSensorAvailability;
  SonarWarningLevel RearCenterLevel;
  SonarSensorAvailability RearLeftSensorAvailability;
  SonarWarningLevel RearLeftLevel;
  SonarSensorAvailability RearRightSensorAvailability;
  SonarWarningLevel RearRightLevel;
  SonarSensorAvailability FrontCenterSensorAvailability;
  SonarWarningLevel FrontCenterLevel;
  SonarSensorAvailability FrontLeftSensorAvailability;
  SonarWarningLevel FrontLeftLevel;
  SonarSensorAvailability FrontRightSensorAvailability;
  SonarWarningLevel FrontRightLevel;
  UInt8 ObstacleDistanceInCM;
  UInt8 ObstacleDistanceInInch;
  SonarWarningLevel SideSonarLfLevel;
  SonarSensorAvailability SideSonarLfAvailability;
  SonarWarningLevel SideSonarLfcLevel;
  SonarSensorAvailability SideSonarLfcAvailability;
  SonarWarningLevel SideSonarLrcLevel;
  SonarSensorAvailability SideSonarLrcAvailability;
  SonarWarningLevel SideSonarRlLevel;
  SonarSensorAvailability SideSonarRlAvailability;
  SonarWarningLevel SideSonarRfLevel;
  SonarSensorAvailability SideSonarRfAvailability;
  SonarWarningLevel SideSonarRfcLevel;
  SonarSensorAvailability SideSonarRfcAvailability;
  SonarWarningLevel SideSonarRrcLevel;
  SonarSensorAvailability SideSonarRrcAvailability;
  SonarWarningLevel SideSonarRrLevel;
  SonarSensorAvailability SideSonarRrAvailability;
} SonarPayloadS;

# define Rte_TypeDef_StartUpInitT
typedef struct
{
  StartUpInitProcessStateT StartUpInitWarnings_CF;
  StartUpInitProcessStateT StartUpInitGauges_CF;
  StartUpInitProcessStateT StartUpInitMainMenu_CF;
} StartUpInitT;

# define Rte_TypeDef_TPMSPayloadS
typedef struct
{
  TPMSTireWarningStatus FRLeftTireStatus;
  TPMSTireWarningStatus FRRightTireStatus;
  TPMSTireWarningStatus RearLeftTireStatus;
  TPMSTireWarningStatus RearRightTireStatus;
  TPMSFeatureStatus TPMSFeatureCurStatus;
  TPMSColdTireStatus TPMSCurrentColdPressureStatus;
  TPMSTirePressureStatus TPMSIndTirePressureStatus;
  TPMSAxleStatus TPMSFrontAxleStatus;
  TPMSAxleStatus TPMSRearAxleStatus;
  UInt32 FrontLeftTirePressureVal;
  UInt32 FrontRightTirePressureVal;
  UInt32 RearRightTirePressureVal;
  UInt32 RearLeftTirePressureVal;
  UInt16 FrontAxleThersholdPressureVal;
  UInt16 RearAxleThersholdPressureVal;
} TPMSPayloadS;

# define Rte_TypeDef_TSRPayloadS
typedef struct
{
  TSRNoOverTakeSign NoOverTakeSignPayload;
  UInt8 TsrSpeedLimitValueZone1;
  UInt8 TsrSpeedLimitValueZone2;
  TSRSpeedSignalZone TsrSpeedLimitZone1;
  TSRSpeedSignalZone TsrSpeedLimitZone2;
  TSRSubSignZone TsrSupplementZone1;
  TSRSubSignZone TsrSupplementZone2;
  TSRSubSignZone TsrSupplementZone3;
} TSRPayloadS;

# define Rte_TypeDef_TelltaleResetDataS
typedef struct
{
  UInt8 TelltaleID;
  UInt8 TelltaleResetCause;
} TelltaleResetDataS;

# define Rte_TypeDef_TripTimeS
typedef struct
{
  UInt8 TripTimeSecsOrMins;
  UInt8 TripTimeMinsOrHours;
} TripTimeS;

# define Rte_TypeDef_UIIdmPriorityDisplayS
typedef struct
{
  IDMDisplayStatesS IDMDisplayStates;
  IDMArcEffectStatesS IDMSsaEffectStates;
  IDMTireEffectStatesS IDMTireEffectRRStates;
  IDMHsaEffectStStatesS IDMHsaEffectStates;
  IDMArcEffectStatesS IDMArcEffectStates;
  IDMTurnEffectLeftStatesS IDMTurnEffectLeftStates;
  IDMTurnEffectRightStatesS IDMTurnEffectRightStates;
  IDMTireEffectStatesS IDMTireEffectFLStates;
  IDMTireEffectStatesS IDMTireEffectFRStates;
  IDMTireEffectStatesS IDMTireEffectRLStates;
  IDMArcEffectStatesS IDMHdcEffectStates;
} UIIdmPriorityDisplayS;

# define Rte_TypeDef_UI_AUDIOWARNING_UPDATE_T
typedef struct
{
  Boolean interrupt_state;
  UI_AUDIO_WARNING_T warning_id;
  UI_AUDIO_ICON_T audio_icon;
} UI_AUDIOWARNING_UPDATE_T;

# define Rte_TypeDef_UI_AUDIO_UPDATE_T
typedef struct
{
  UI_AUDIO_MODE_T audio_mode;
  Boolean warning;
} UI_AUDIO_UPDATE_T;

# define Rte_TypeDef_UI_AUX_INFO_T
typedef struct
{
  Boolean aux_src_update;
  UI_AUX_SOURCE_T aux_mode;
  UInt8 reserved;
} UI_AUX_INFO_T;

# define Rte_TypeDef_UI_DISC_INFO_T
typedef struct
{
  Boolean disc_src_update;
  UI_DISC_SOURCE_T disc_mode;
  Boolean content_type;
  Boolean track_update;
  UI_TRACK_LABEL_T track_type;
  UInt32 track_num;
  Boolean group_update;
  UInt8 group_type;
  UInt16 group_num;
  Boolean artist_update;
  UI_ARTIST_LABEL_T artist_type;
  UI_DISP_CASE disp_case;
} UI_DISC_INFO_T;

# define Rte_TypeDef_UI_INTERNET_AUDIO_INFO_T
typedef struct
{
  UInt8 int_aud_src_update;
  Boolean track_update;
  UI_TRACK_LABEL_T track_type;
  UInt32 track_num;
  Boolean group_update;
  UI_GROUP_LABEL_T group_type;
  UInt16 group_num;
  Boolean artist_update;
  UI_ARTIST_LABEL_T artist_type;
} UI_INTERNET_AUDIO_INFO_T;

# define Rte_TypeDef_UI_NAVI_LANE_CATEGORY_INFO_T
typedef struct
{
  UI_NAVI_LANE_CATEGORY_T l_lane_category;
  UInt8 l_no_of_lanes_U8;
} UI_NAVI_LANE_CATEGORY_INFO_T;

# define Rte_TypeDef_UI_NAVI_SPEED_LIMIT_INFO_T
typedef struct
{
  UI_NAVI_SPEED_LIMIT_STATE_T l_navi_spd_lmt_state;
  UI_NAVI_SPEED_LIMIT_TYPE_T l_navi_spd_lmt_type;
  UInt8 l_speed_U8;
  UI_NAVI_SPEED_LIMIT_UNIT_T l_speed_Unit;
} UI_NAVI_SPEED_LIMIT_INFO_T;

# define Rte_TypeDef_UI_TEL_INFO_T
typedef struct
{
  UI_TEL_DISPLAY_MENU_TYPE_T menu_type;
  UI_TEL_MUTE_T mute;
} UI_TEL_INFO_T;

# define Rte_TypeDef_UiSettingsAllTypesS
typedef struct
{
  UiSettingsToggleTypeMenu ToggleMenu;
  SonarRange SonarRangeVar;
  SonarVol SonarVolVar;
  TpmsUnit TpmsUnit;
  ECOIndicator ECOIndicatorVar;
  ECOModeReport ECOModeReportVar;
  OATAlert OATAlertVar;
  LightSensitivity LightSensitivityVar;
  AutoUnlock AutoUnlockVar;
  MilageUnits FuelUnitsVar;
  Language LanguageVar;
  DistanceUnit DistanceUnitVar;
  TempUnit TempUnitVar;
  RearDoorAlert RearDoorAlertVar;
  LightOffDelay LightOffDelayVar;
  AutoUnlock AutoDoorlockVar;
  SpdLmtAssist SpdLmtAssistVar;
  SpdLmtAssistOffset SpdLmtAssistOffsetVar;
  MirrorsSetting MirrorsSettingVar;
  SteeringEffortSetting SteeringEffortSettingVar;
  SensitivityType SensitivityTypeVar;
} UiSettingsAllTypesS;

# define Rte_TypeDef_WarningDataS
typedef struct
{
  WarningStatus WarningCurrentStatus;
  WarningEvent WarningCurrentEvent;
  UInt32 WarningCurrentPayload;
} WarningDataS;

# define Rte_TypeDef_WaterHighTempThValueS
typedef struct
{
  WaterHighTempThT WaterHighTempThOnValue;
  WaterHighTempThT WaterHighTempThOffValue;
} WaterHighTempThValueS;

# define Rte_TypeDef_AliveCntCrcT
typedef struct
{
  Crc_IN_Type AliveCntArray;
  CrcCdd_Index Index;
  Crc_IN_Type CrcArray;
} AliveCntCrcT;

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint8 ComM_UserHandleType;

# define Rte_TypeDef_CrcUpdateType
typedef struct
{
  UInt8 ComPduId;
  ComMsgPoint ComSduDataPtr;
  UInt16 ComSduLength;
} CrcUpdateType;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

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

# define Rte_TypeDef_ECUVersionDetatilS
typedef struct
{
  ECUSwNumberT SwNumber;
  ECUSwVersionDateT SwVersionDate;
  ECUSwVersionPCBCodeT SwVersionPCBCode;
  ECUHwCodeT HwCode;
} ECUVersionDetatilS;

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

# define Rte_TypeDef_MCAN_CLOCK_SETTING_INFO
typedef struct
{
  CLOCK_PARAMETER_TYPE Invalid_Parameter;
  CLOCK_AVAILABLE_STATE_TYPE Time_Format_Info_Avbl;
  TIME_FORMAT_TYPE Time_Format_Info;
  CLOCK_AVAILABLE_STATE_TYPE Clock_Mode_Info_Avbl;
  CLOCK_MODE_INFO_STATES_TYPE Clock_Mode_Info_Audo;
  CLOCK_MODE_INFO_STATES_TYPE Clock_Mode_Info_Manual;
  CLOCK_MODE_INFO_STATES_TYPE Clock_Mode_Info_Time_zone;
  CLOCK_AVAILABLE_STATE_TYPE Clock_Info_avbl;
  CLOCK_CLOCK_TYPE Clock_Info_Clock;
  UInt8 Clock_Info_hour;
  UInt8 Clock_Info_minute;
  CLOCK_AVAILABLE_STATE_TYPE Daylight_Saving_Info_avbl;
  CLOCK_MODE_INFO_STATES_TYPE Daylight_Saving_Info;
  CLOCK_AVAILABLE_STATE_TYPE Time_Zone_Info_avbl;
  TIME_ZONE_TYPE Time_Zone_info;
  AVAILABLE_TIME_ZONE_TYPE Available_Time_Zone_info;
  CLOCK_Msg_Type ClockIndOrStatus;
} MCAN_CLOCK_SETTING_INFO;

# define Rte_TypeDef_NV_Data_CustomerHWReference
typedef struct
{
  t_uint8_x_10 CustomerHWReference_number;
} NV_Data_CustomerHWReference;

# define Rte_TypeDef_NV_Data_CustomerReference
typedef struct
{
  t_uint8_x_10 CustomerReference_number;
} NV_Data_CustomerReference;

# define Rte_TypeDef_NV_Data_CustomerReference2
typedef struct
{
  t_uint8_x_10 CustomerReference2_number;
} NV_Data_CustomerReference2;

# define Rte_TypeDef_NV_Data_DiagDID100
typedef struct
{
  t_uint8_x_16 NV_DIAG_DID_100_Data;
} NV_Data_DiagDID100;

# define Rte_TypeDef_NV_Data_DiagDID200
typedef struct
{
  t_uint8_x_16 NV_DIAG_DID_200_Data;
} NV_Data_DiagDID200;

# define Rte_TypeDef_NV_Data_DiagDID300
typedef struct
{
  t_uint8_x_4 NV_DIAG_DID_300_Data;
} NV_Data_DiagDID300;

# define Rte_TypeDef_NV_Data_DiagDID400
typedef struct
{
  t_uint8_x_2 NV_DIAG_DID_400_Data;
} NV_Data_DiagDID400;

# define Rte_TypeDef_NV_Data_DiagDID410
typedef struct
{
  t_uint8_x_2 NV_DIAG_DID_410_Data;
} NV_Data_DiagDID410;

# define Rte_TypeDef_NV_Data_DiagDIDF190
typedef struct
{
  t_uint8_x_17 NV_DIAG_DID_F190_Data;
} NV_Data_DiagDIDF190;

# define Rte_TypeDef_NV_Data_DiagDIDF1A2
typedef struct
{
  t_uint8_x_10 NV_DIAG_DID_F1A2_Data;
} NV_Data_DiagDIDF1A2;

# define Rte_TypeDef_NV_Data_DiagDIDFE11
typedef struct
{
  t_uint8_x_64 NV_DIAG_DID_FE11_Data;
} NV_Data_DiagDIDFE11;

# define Rte_TypeDef_NV_Data_FBLValidDTCState_1
typedef struct
{
  t_uint8_x_16 ValidDTCState_1;
} NV_Data_FBLValidDTCState_1;

# define Rte_TypeDef_NV_Data_FOTA_NVM
typedef struct
{
  UInt32 Fota_FlashCompletedAddress;
  UInt32 Fota_RemainingDataSize;
  UInt8 Fota_ActivePartition;
  UInt8 Fota_State;
  UInt8 Fota_CancelCounter;
  UInt32 Fota_VipDtcUpdate;
  UInt32 Fota_GipDtcUpdate;
  t_uint8_x_32 Fota_HashValueUpdate;
  t_uint8_x_16 Fota_IVectorData;
  UInt8 Fota_VlanOpenStatus;
  UInt8 Fota_RollbackCompleteFlag;
  UInt8 Fota_RollbackInprogress;
  UInt8 Fota_RebootCompleteFlag;
  UInt8 Fota_VIPDownloadSkipFlag;
  UInt8 Fota_PreviousState;
  t_uint8_x_256 Fota_DecryptionResult;
  UInt8 Fota_GlobalDtcUpdate;
} NV_Data_FOTA_NVM;

# define Rte_TypeDef_NV_Data_FOTA_NVM_DIGHRNIG
typedef struct
{
  UInt8 Fota_Virgin_Flag;
  t_uint8_x_6 Fota_ConfigurationSignatureError;
  UInt8 Fota_Att_Cnt;
  UInt8 Fota_Mileage_Flag;
  t_uint8_x_32 Fota_IncrementalCounter;
  UInt8 Fota_F_virgin;
  t_uint8_x_32 Fota_Correlator_Id;
} NV_Data_FOTA_NVM_DIGHRNIG;

# define Rte_TypeDef_NV_Data_FeatureConfigCalib
typedef struct
{
  t_uint8_x_30 NV_Visteon_Product_Config_Data;
} NV_Data_FeatureConfigCalib;

# define Rte_TypeDef_NV_Data_FeaturesConst
typedef struct
{
  UInt8 Nv_AccelGuideSpeed_V3Min;
  UInt8 Nv_AccelGuideSpeed_V3max;
  UInt8 Nv_AccelGuideSpeed_V2Min;
  UInt8 Nv_AccelGuideSpeed_V2Max;
  UInt8 Nv_AccelGuideSpeed_V1Min;
  UInt8 Nv_AccelGuideSpeed_V1Max;
  UInt8 Nv_EcoRank_T1Min_Time;
  UInt8 Nv_EcoRate_E1_Value;
  UInt8 Nv_EcoRate_E2_Value;
  UInt8 Nv_EcoRate_E3_Value;
  UInt8 Nv_EcoRate_E4_Value;
  UInt16 Nv_RearDoorAlert_T1_Time;
  t_uint16_x_12 Fuel_Table_A_FLPS;
  t_uint16_x_12 Fuel_Table_B_RADS;
  t_uint16_x_12 Fuel_Table_A_RADS;
  t_uint16_x_12 Fuel_Table_B_FLPS;
  t_uint16_x_12 Fuel_Table_C_FLPS;
  t_uint16_x_12 Fuel_Table_D_RADS;
  t_uint16_x_12 Fuel_Table_D_FLPS;
  t_uint16_x_12 Fuel_Table_E_RADS;
  t_uint16_x_12 Fuel_Table_E_FLPS;
  t_uint16_x_12 Fuel_Table_C_RADS;
} NV_Data_FeaturesConst;

# define Rte_TypeDef_NV_Data_FeaturesConst1
typedef struct
{
  t_uint16_x_22 Nv_Dial_DayMode_Type_A_duty;
  t_uint16_x_22 Nv_Dial_DayMode_Type_B_duty;
  t_uint16_x_22 Nv_Dial_NightMode_Type_A_duty;
  t_uint16_x_22 Nv_Dial_NightMode_Type_B_duty;
} NV_Data_FeaturesConst1;

# define Rte_TypeDef_NV_Data_FeaturesConst2
typedef struct
{
  t_uint16_x_22 Nv_Pointer_DayMode_Type_A_duty;
  t_uint16_x_22 Nv_Pointer_DayMode_Type_B_duty;
  t_uint16_x_22 Nv_Pointer_NightMode_Type_A_duty;
  t_uint16_x_22 Nv_Pointer_NightMode_Type_B_duty;
} NV_Data_FeaturesConst2;

# define Rte_TypeDef_NV_Data_FeaturesConst3
typedef struct
{
  t_uint16_x_22 Nv_TFT_DayMode_Type_A_duty;
  t_uint16_x_22 Nv_TFT_DayMode_Type_B_duty;
  t_uint16_x_22 Nv_TFT_NightMode_Type_A_duty;
  t_uint16_x_22 Nv_TFT_NightMode_Type_B_duty;
} NV_Data_FeaturesConst3;

# define Rte_TypeDef_NV_Data_FeaturesConst4
typedef struct
{
  t_uint16_x_22 Nv_Extern_CANOut_Type_A_duty;
  t_uint16_x_22 Nv_Extern_CANOut_Type_B_duty;
  t_uint16_x_22 Nv_Extern_Illum_Type_A_duty;
  t_uint16_x_22 Nv_Extern_Illum_Type_B_duty;
} NV_Data_FeaturesConst4;

# define Rte_TypeDef_NV_Data_FeaturesConst5
typedef struct
{
  t_uint16_x_22 Nv_SideSw_DayMode_Type_A_duty;
  t_uint16_x_22 Nv_SideSw_DayMode_Type_B_duty;
  t_uint16_x_22 Nv_SideSw_NightMode_Type_A_duty;
  t_uint16_x_22 Nv_SideSw_NightMode_Type_B_duty;
} NV_Data_FeaturesConst5;

# define Rte_TypeDef_NV_Data_FeaturesConst6
typedef struct
{
  t_uint16_x_12 Fuel_Table_H_RADS;
  t_uint16_x_12 Fuel_Table_H_FLPS;
  t_uint16_x_12 Fuel_Table_I_RADS;
  t_uint16_x_12 Fuel_Table_I_FLPS;
  t_uint16_x_12 Fuel_Table_J_RADS;
  t_uint16_x_12 Fuel_Table_J_FLPS;
  t_uint16_x_12 Fuel_Table_K_RADS;
  t_uint16_x_12 Fuel_Table_K_FLPS;
  t_uint16_x_12 Fuel_Table_L_RADS;
  t_uint16_x_12 Fuel_Table_L_FLPS;
} NV_Data_FeaturesConst6;

# define Rte_TypeDef_NV_Data_Fingerprint
typedef struct
{
  t_uint8_x_20 Fingerprint;
} NV_Data_Fingerprint;

# define Rte_TypeDef_NV_Data_FotaUpdateStatus
typedef struct
{
  t_uint8_x_16 FotaUpdateStatus_0;
} NV_Data_FotaUpdateStatus;

# define Rte_TypeDef_NV_Data_FotaUpdateStatus_1
typedef struct
{
  t_uint8_x_16 FotaUpdateStatus_1;
} NV_Data_FotaUpdateStatus_1;

# define Rte_TypeDef_NV_Data_GaugeEctCalib
typedef struct
{
  t_uint16_x_15 NV_Ect_Gauge_Mapping_Table_X;
  t_uint16_x_15 NV_Ect_Gauge_Mapping_Table_Y;
  t_uint16_x_15 NV_Ect_Gauge_Correction_Table_X;
  t_uint16_x_15 NV_Ect_Gauge_Correction_Table_Y;
} NV_Data_GaugeEctCalib;

# define Rte_TypeDef_NV_Data_GaugeFuelCalib
typedef struct
{
  t_uint16_x_15 NV_Fuel_Gauge_Mapping_Table_X;
  t_uint16_x_15 NV_Fuel_Gauge_Mapping_Table_Y;
  t_uint16_x_15 NV_Fuel_Gauge_Correction_Table_X;
  t_uint16_x_15 NV_Fuel_Gauge_Correction_Table_Y;
} NV_Data_GaugeFuelCalib;

# define Rte_TypeDef_NV_Data_GaugeRPMCalib
typedef struct
{
  t_uint16_x_15 NV_RPM_Gauge_Mapping_Table_X;
  t_uint16_x_15 NV_RPM_Gauge_Mapping_Table_Y;
  t_uint16_x_15 NV_RPM_Gauge_Correction_Table_X;
  t_uint16_x_15 NV_RPM_Gauge_Correction_Table_Y;
} NV_Data_GaugeRPMCalib;

# define Rte_TypeDef_NV_Data_GaugeSpdCalib
typedef struct
{
  t_uint16_x_15 NV_Spd_Gauge_Mapping_Table_X;
  t_uint16_x_15 NV_Spd_Gauge_Mapping_Table_Y;
  t_uint16_x_15 NV_Spd_Gauge_Correction_Table_X;
  t_uint16_x_15 NV_Spd_Gauge_Correction_Table_Y;
} NV_Data_GaugeSpdCalib;

# define Rte_TypeDef_NV_Data_IDLE_STOP
typedef struct
{
  t_uint16_x_3 NV_Idle_StopSetting_VltData;
  t_uint8_x_3 NV_Idle_StopSetting_CltData;
  UInt16 NV_Idle_StopSetting_VltCount;
  UInt8 NV_Idle_StopSetting_CltCount;
} NV_Data_IDLE_STOP;

# define Rte_TypeDef_NV_Data_IKEY_BLK
typedef struct
{
  t_uint8_x_4 NVM_Main_menu_Select_byte1_key;
  t_uint8_x_4 NVM_Main_menu_Select_byte2_key;
  t_uint8_x_4 NVM_Car_color_Eco_Welcome_key;
  t_uint8_x_4 NVM_Milage_TPMS_Temp_unit_setting_key;
  t_uint8_x_4 NVM_Lang_Navi_Ikey_link_key;
  t_uint8_x_4 NVM_illum_mode_step_key;
  t_uint8_x_4 NVM_illum_night_step_key;
  t_uint32_x_4 NVM_Top_layer_contents_key;
  t_uint8_x_4 NVM_Key_Link_status;
  t_uint8_x_4 NVM_Personal_Display_Key;
  t_uint8_x_4 NVM_Operation_Guidance_Key;
  UInt8 NVM_KeyId;
  t_uint32_x_4 NVM_AlertSettingSave_Key;
} NV_Data_IKEY_BLK;

# define Rte_TypeDef_NV_Data_MFG_DID_PRODUCT
typedef struct
{
  t_uint8_x_16 NV_ProductVisteonPartNum;
  t_uint8_x_17 NV_EquippedPCBVisteonPartNum;
  t_uint8_x_5 NV_PCBSerialNum;
  t_uint8_x_3 NV_SMDPlantNum;
  t_uint8_x_4 NV_AssemblyPlantNum;
  t_uint8_x_20 NV_Assembly_Manufacturing_date;
  t_uint8_x_10 NV_Customer_reference;
  t_uint8_x_10 NV_vehicleManufacturerECUHardwareNumber;
  UInt8 NV_Traceability_Bytes_ICT;
  UInt8 NV_Traceability_Bytes_FCT;
  UInt8 NV_Traceability_Bytes_FC;
  UInt8 NV_Traceability_Bytes_AC;
  UInt8 NV_Traceability_Bytes_WS2;
  t_uint8_x_4 NV_PWMTFTBLCalibration;
  t_uint8_x_18 NV_Analog_Measurements_Calibration;
  t_uint8_x_8 NV_Reset_Counters_Reading;
  UInt16 ManufacturingModeRequested;
  t_uint8_x_4 NVM_Sound_Channel_Vol;
  UInt8 NVM_Sound_Mixer_Op_Vol;
  t_uint8_x_10 NV_VehicleManufacturerSparePartNumberVIP;
  t_uint8_x_10 NV_VehicleManufacturerSparePartNumberGIP;
} NV_Data_MFG_DID_PRODUCT;

# define Rte_TypeDef_NV_Data_MagicFlag
typedef struct
{
  t_uint8_x_16 BootMagicFlag_0;
} NV_Data_MagicFlag;

# define Rte_TypeDef_NV_Data_NVM_HM_FaultCounters
typedef struct
{
  t_uint8_x_100 NVM_HM_FaultCounters_Data;
} NV_Data_NVM_HM_FaultCounters;

# define Rte_TypeDef_NV_Data_PCBSerialNumber
typedef struct
{
  t_uint8_x_20 PCB_serial_number_AssemblymanufDate;
} NV_Data_PCBSerialNumber;

# define Rte_TypeDef_NV_Data_Reserved_Health_Management
typedef struct
{
  t_uint8_x_160 Reserved_Health_Management_Data;
} NV_Data_Reserved_Health_Management;

# define Rte_TypeDef_NV_Data_SIGMA_DTC_INDEX_BLK
typedef struct
{
  UInt8 NV_SigmaStoreNoTriggerDTCIndex;
  UInt8 NV_SigmaStoreTriggerDTCIndex;
  UInt8 NV_SigmaNumberValueNoTrigger;
  UInt8 NV_SigmaTriggerNumberValue;
  t_uint8_x_16 NV_SigmaDataIndexArray;
} NV_Data_SIGMA_DTC_INDEX_BLK;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK0
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_0;
  t_uint8_x_3 NV_SigmaSSD_TimeData_0;
} NV_Data_SIGMA_SSD_BLK0;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK1
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_1;
  t_uint8_x_3 NV_SigmaSSD_TimeData_1;
} NV_Data_SIGMA_SSD_BLK1;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK10
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_10;
  t_uint8_x_3 NV_SigmaSSD_TimeData_10;
} NV_Data_SIGMA_SSD_BLK10;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK11
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_11;
  t_uint8_x_3 NV_SigmaSSD_TimeData_11;
} NV_Data_SIGMA_SSD_BLK11;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK12
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_12;
  t_uint8_x_3 NV_SigmaSSD_TimeData_12;
} NV_Data_SIGMA_SSD_BLK12;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK13
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_13;
  t_uint8_x_3 NV_SigmaSSD_TimeData_13;
} NV_Data_SIGMA_SSD_BLK13;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK14
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_14;
  t_uint8_x_3 NV_SigmaSSD_TimeData_14;
} NV_Data_SIGMA_SSD_BLK14;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK15
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_15;
  t_uint8_x_3 NV_SigmaSSD_TimeData_15;
} NV_Data_SIGMA_SSD_BLK15;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK2
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_2;
  t_uint8_x_3 NV_SigmaSSD_TimeData_2;
} NV_Data_SIGMA_SSD_BLK2;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK3
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_3;
  t_uint8_x_3 NV_SigmaSSD_TimeData_3;
} NV_Data_SIGMA_SSD_BLK3;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK4
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_4;
  t_uint8_x_3 NV_SigmaSSD_TimeData_4;
} NV_Data_SIGMA_SSD_BLK4;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK5
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_5;
  t_uint8_x_3 NV_SigmaSSD_TimeData_5;
} NV_Data_SIGMA_SSD_BLK5;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK6
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_6;
  t_uint8_x_3 NV_SigmaSSD_TimeData_6;
} NV_Data_SIGMA_SSD_BLK6;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK7
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_7;
  t_uint8_x_3 NV_SigmaSSD_TimeData_7;
} NV_Data_SIGMA_SSD_BLK7;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK8
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_8;
  t_uint8_x_3 NV_SigmaSSD_TimeData_8;
} NV_Data_SIGMA_SSD_BLK8;

# define Rte_TypeDef_NV_Data_SIGMA_SSD_BLK9
typedef struct
{
  t_uint8_x_63 NV_SigmaSSD_Data_9;
  t_uint8_x_3 NV_SigmaSSD_TimeData_9;
} NV_Data_SIGMA_SSD_BLK9;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK0
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_0;
} NV_Data_SIGMA_VTD_BLK0;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK1
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_1;
} NV_Data_SIGMA_VTD_BLK1;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK10
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_10;
} NV_Data_SIGMA_VTD_BLK10;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK11
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_11;
} NV_Data_SIGMA_VTD_BLK11;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK12
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_12;
} NV_Data_SIGMA_VTD_BLK12;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK13
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_13;
} NV_Data_SIGMA_VTD_BLK13;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK14
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_14;
} NV_Data_SIGMA_VTD_BLK14;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK15
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_15;
} NV_Data_SIGMA_VTD_BLK15;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK2
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_2;
} NV_Data_SIGMA_VTD_BLK2;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK3
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_3;
} NV_Data_SIGMA_VTD_BLK3;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK4
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_4;
} NV_Data_SIGMA_VTD_BLK4;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK5
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_5;
} NV_Data_SIGMA_VTD_BLK5;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK6
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_6;
} NV_Data_SIGMA_VTD_BLK6;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK7
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_7;
} NV_Data_SIGMA_VTD_BLK7;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK8
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_8;
} NV_Data_SIGMA_VTD_BLK8;

# define Rte_TypeDef_NV_Data_SIGMA_VTD_BLK9
typedef struct
{
  t_uint8_x_128 NV_SigmaVTD_Data_9;
} NV_Data_SIGMA_VTD_BLK9;

# define Rte_TypeDef_NV_Data_Signature
typedef struct
{
  t_uint8_x_256 Signature;
} NV_Data_Signature;

# define Rte_TypeDef_NV_Data_Signature_1
typedef struct
{
  t_uint8_x_256 Signature_1;
} NV_Data_Signature_1;

# define Rte_TypeDef_NV_Data_USER_LOGIN
typedef struct
{
  t_uint8_x_5 NVM_Main_menu_Select_byte1_User;
  t_uint8_x_5 NVM_Main_menu_Select_byte2_User;
  t_uint8_x_5 NVM_Car_color_Eco_Welcome_User;
  t_uint8_x_5 NVM_Milage_TPMS_Temp_unit_setting_User;
  t_uint32_x_5 NVM_Top_layer_contents_User;
  t_uint8_x_5 NVM_Lang_Navi_User;
  t_uint8_x_5 NVM_illum_mode_step_User;
  t_uint8_x_5 NVM_illum_night_step_User;
  t_uint32_x_5 NVM_AlertSetting_User;
  t_uint8_x_5 NVM_Key_Link_UserLogin;
  t_uint8_x_5 NVM_PersonalDisplay_User;
  t_uint8_x_5 NVM_OperationGuidance_User;
} NV_Data_USER_LOGIN;

# define Rte_TypeDef_NvM_ServiceIdType
typedef uint8 NvM_ServiceIdType;

# define Rte_TypeDef_ReprogDataType
typedef struct
{
  UInt8 u8Counter;
  ReprogCmdType ReprogCmd;
  UInt16 u16Length;
  ReprogBufferType DataBuffer;
} ReprogDataType;

# define Rte_TypeDef_SAD2MenuPayloadData
typedef struct
{
  data_u8_40 AD2menuPayload;
} SAD2MenuPayloadData;

# define Rte_TypeDef_SAD2VehSts
typedef struct
{
  data_u8_12 PeripheralVehSts;
} SAD2VehSts;

# define Rte_TypeDef_SAudioIndData
typedef struct
{
  UInt16 rcvdDataLength;
  data_u8_280 rcvdData;
  EAudioIndCbEnum_t audioIndCbEnum;
} SAudioIndData;

# define Rte_TypeDef_SCustSettingsMsg
typedef struct
{
  data_u8_50 customSettingsData;
} SCustSettingsMsg;

# define Rte_TypeDef_SDiagDIDRequest
typedef struct
{
  UInt16 did;
  EDidType_t didType;
  UInt16 dataLen;
  data_u8_256 data;
} SDiagDIDRequest;

# define Rte_TypeDef_SDiagIOCtrlRequest
typedef struct
{
  UInt16 did;
  EIOCtrlOptType_t optionCtrl;
  UInt16 dataLen;
  data_u8_256 data;
} SDiagIOCtrlRequest;

# define Rte_TypeDef_SDiagResponse
typedef struct
{
  UInt8 responseCode;
  UInt16 dataLen;
  data_u8_256 data;
} SDiagResponse;

# define Rte_TypeDef_SDiagRoutineRequest
typedef struct
{
  UInt16 routineId;
  ERoutineType_t routineType;
  UInt16 dataLen;
  data_u8_320 data;
} SDiagRoutineRequest;

# define Rte_TypeDef_SEtmConfigData
typedef struct
{
  data_u16_16 etmConfig;
  UInt8 etmConfigIndex;
} SEtmConfigData;

# define Rte_TypeDef_SFotaCorrelationID
typedef struct
{
  data_u8_32 correlationData;
} SFotaCorrelationID;

# define Rte_TypeDef_SFotaVinResponse
typedef struct
{
  data_u8_17 vin;
} SFotaVinResponse;

# define Rte_TypeDef_SFuelEconomyData
typedef struct
{
  UInt16 IFEValue;
  UInt16 BFEValue;
  UInt16 rechargeMileValue;
  data_u16_3 AFEValue;
  data_u16_6 HFEValue;
  data_u16_15 HFE2MinValue;
} SFuelEconomyData;

# define Rte_TypeDef_SGipDiagDIDRequest
typedef struct
{
  UInt16 did;
  EDidType_t didType;
  UInt16 dataLen;
  data_u8_300 data;
} SGipDiagDIDRequest;

# define Rte_TypeDef_SGipDiagIOCtrlRequest
typedef struct
{
  UInt16 did;
  EIOCtrlOptType_t optionCtrl;
  UInt16 dataLen;
  data_u8_256 data;
} SGipDiagIOCtrlRequest;

# define Rte_TypeDef_SGipDiagResponse
typedef struct
{
  UInt8 responseCode;
  UInt16 dataLen;
  data_u8_300 data;
} SGipDiagResponse;

# define Rte_TypeDef_SGipDiagRoutineRequest
typedef struct
{
  UInt16 routineId;
  ERoutineType_t routineType;
  UInt16 dataLen;
  data_u8_256 data;
} SGipDiagRoutineRequest;

# define Rte_TypeDef_SHealthDumpData
typedef struct
{
  UInt32 chunkSize;
  data_u8_32 data;
} SHealthDumpData;

# define Rte_TypeDef_SIdleStopData
typedef struct
{
  data_u8_3 cumulativeIdleStopTime;
  data_u8_3 tripIdleStopTime;
  data_u16_3 vehicleLifeTime;
  UInt32 idleStopCo2CLTSavedVolume;
  UInt32 idleStopCo2VLTSavedVolume;
  UInt32 idleStopFuelConsumption;
  UInt8 idleStopActivationStatus;
} SIdleStopData;

# define Rte_TypeDef_SMcanAvailabilityInfo
typedef struct
{
  SMcanFeatureInfo mcanAvailability;
} SMcanAvailabilityInfo;

# define Rte_TypeDef_SMemDiagRespData
typedef struct
{
  EMemDiagRequestCmd_t respCmd;
  EReflashStatus_t resResult;
  data_u8_4 data;
} SMemDiagRespData;

# define Rte_TypeDef_SMenuPayloadData
typedef struct
{
  data_u8_50 menuPayload;
} SMenuPayloadData;

# define Rte_TypeDef_SModuleConfigStatus
typedef struct
{
  data_u8_25 featureConfigSts;
} SModuleConfigStatus;

# define Rte_TypeDef_SNaviIndData
typedef struct
{
  UInt16 rcvdDataLength;
  data_u8_75 rcvdData;
  ENaviIndCbEnum_t naviIndCbEnum;
} SNaviIndData;

# define Rte_TypeDef_SOdometerStatus
typedef struct
{
  UInt32 value;
  UInt32 tripAvalue;
  UInt32 tripBvalue;
  data_u32_3 tripDistance;
} SOdometerStatus;

# define Rte_TypeDef_SPersRecordCmd
typedef struct
{
  SKeyVal data;
} SPersRecordCmd;

# define Rte_TypeDef_SPersRecordMsg
typedef struct
{
  data_u8_50 settingAvailabilityStatus;
  data_u32_50 currentSettingValue;
  UInt8 currentSettingIdx;
  data_u16_50 currMdlSettingsId;
} SPersRecordMsg;

# define Rte_TypeDef_SPhoneIndData
typedef struct
{
  UInt16 rcvdDataLength;
  data_u8_75 rcvdData;
  EPhoneIndCbEnum_t phoneIndCbEnum;
} SPhoneIndData;

# define Rte_TypeDef_SPopupStatusData
typedef struct
{
  data_u8_5 popupStatus;
  data_u8_5 popupRetriggerStatus;
  data_u8_5 popupPayload;
} SPopupStatusData;

# define Rte_TypeDef_SRestoreBackUpRamData
typedef struct
{
  UInt8 currOdoTripRes;
  UInt8 hmiCtrlInitRes;
  SMenuBackUpData_t menuBackupDataRes;
  data_u32_6 recordMainMenuItem;
  data_u8_8 errorData;
  UInt8 personalSubWidgetRes;
  SSelfDiagBackUpData_t selfDiagBackupDataRes;
} SRestoreBackUpRamData;

# define Rte_TypeDef_SSaveBackUpRamData
typedef struct
{
  UInt8 currOdoTripReq;
  UInt8 hmiCtrlInitReq;
  SMenuBackUpData_t menuBackupDataReq;
  data_u32_6 recordMainMenuItem;
  data_u8_8 errorData;
  UInt8 personalSubWidgetReq;
  SSelfDiagBackUpData_t selfDiagBackupDataReq;
} SSaveBackUpRamData;

# define Rte_TypeDef_STTChecksumSts
typedef struct
{
  data_u8_35 TTChecksumSts;
} STTChecksumSts;

# define Rte_TypeDef_STTIndicatorStatus
typedef struct
{
  data_u8_60 telltaleStatus;
  data_u8_60 indicatorStatus;
  data_u8_25 indicatorPayload;
} STTIndicatorStatus;

# define Rte_TypeDef_STT_statusVIP
typedef struct
{
  data_u8_15 VIPTTStsMsg;
} STT_statusVIP;

# define Rte_TypeDef_STripComputerData
typedef struct
{
  data_u8_3 tripTimeMinsOrHours;
  data_u8_3 tripTimeSecsOrMins;
  data_u16_3 averageSpeed;
  data_u8_3 vehicleMovedStatus;
  UInt8 isVehicleIdling;
} STripComputerData;

# define Rte_TypeDef_SWarningAckStatus
typedef struct
{
  data_u16_10 warnAckStatus;
} SWarningAckStatus;

# define Rte_TypeDef_SWarningDisplayAvailable
typedef struct
{
  data_u8_10 warnAckStatus;
} SWarningDisplayAvailable;

# define Rte_TypeDef_SWarningDisplayStatus
typedef struct
{
  data_u8_65 warnStatus;
  data_u8_60 warnPayload;
} SWarningDisplayStatus;

# define Rte_TypeDef_SWarningNotifyStatus
typedef struct
{
  data_u8_130 warnNotifyStatus;
} SWarningNotifyStatus;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_UI_HD_RADIO_INFO_T
typedef struct
{
  UInt8 hd_radio_src_update;
  UI_HD_RADIO_SRC_T hd_radio_mode;
  UI_BROADCAST_LABEL_T hd_brdcast_update;
  UInt8 hd_brdcast_type;
  UInt8 hd_prst_number;
  Boolean hd_catgy_update;
  UI_CATEGORY_LABEL_T hd_catgy_type;
  UI_FREQ_ARRAY hd_frequency;
  UI_RADIO_UNIT_T hd_unit;
  UInt8 hd_multicast_ch;
} UI_HD_RADIO_INFO_T;

# define Rte_TypeDef_UI_NAVI_ARRIVAL_WEATHER_INFO_T
typedef struct
{
  UI_NAVI_ARRIVAL_POINT_INFO_T l_arrvl_point_type;
  UI_NAVI_ARRIVAL_CLOCK_INFO_T l_clock_type;
  UInt8 l_clock_hour;
  UInt8 l_clock_min;
  UI_NAVI_DIST_UNIT_T l_dist_units_U8;
  UI_NAVI_ARRIVAL_TIME_TYPE_INFO_T l_time_type;
  UI_NAVI_DEST_WEATHER_INFO_T l_dest_weather_info;
  UI_NAVI_DEST_WEATHER_INFO_T l_cru_weather_info;
  UI_NAVI_DISTANCE_ARRAY_T l_navi_distance;
} UI_NAVI_ARRIVAL_WEATHER_INFO_T;

# define Rte_TypeDef_UI_NAVI_GUIDE_INFO_T
typedef struct
{
  UI_NAVI_STATE_T navi_state;
  UI_NAVI_TBT_INFO_T tbt_info;
  UI_NAVI_BAR_STATE bar_state;
  UInt8 bar_progress;
  UI_NAVI_BAR_SCALE_INFO_T bar_scale_num;
  UI_NAVI_COMPASS_T Compass_data;
  UI_NAVI_COMPASS_T_DIR compass_dir;
  UI_NAVI_DEFORM_ROAD_INFO_T navi_deform_road;
  UI_NAVI_DEFORM_ARROW_INFO_T navi_deform_arrow;
  UI_NAVI_DIST_UNIT_T l_distance_units_U8;
  UI_NAVI_BAR_SCALE_UNIT_T bar_scale_unit;
  UI_NAVI_BAR_SCALE_DIV_T bar_scale_div;
  UI_RA_EXIT_NUMBER_T l_ra_exit_number;
  UI_NAVI_DISTANCE_ARRAY_T l_navi_info_distance;
  UI_NAVI_COMPASS_T Compass_Map_data;
} UI_NAVI_GUIDE_INFO_T;

# define Rte_TypeDef_UI_RADIO_INFO_T
typedef struct
{
  UInt8 radio_src_update;
  UI_RADIO_SOURCE_T radio_mode;
  UI_BROADCAST_LABEL_T broadcast_update;
  UInt8 broadcast_type;
  UInt8 preset_number;
  Boolean category_update;
  UI_CATEGORY_LABEL_T category_type;
  UI_FREQ_ARRAY frequency;
  UI_RADIO_UNIT_T unit;
  UI_DISP_CASE disp_case_type;
} UI_RADIO_INFO_T;

# define Rte_TypeDef_UI_TV_INFO_T
typedef struct
{
  Boolean tv_src_update;
  UI_TV_SOURCE_T tv_mode;
  Boolean tvbrdcst_update;
  UI_TV_LABEL_T tv_label_type;
  UInt8 preset_channel;
  UI_TV_CHANNEL_T tv_channel_num;
} UI_TV_INFO_T;

# define Rte_TypeDef_UI_VR_INFO_T
typedef struct
{
  UI_VR_STATE_T state;
  UI_VR_INFO_ON_OFF_T on_off_status;
  UI_VR_INSTRUCTION_T vr_instruction;
  UInt8 no_of_digits;
  Ul_VR_DIGITS vr_digits;
  UInt8 null_termed_len_of_digits;
} UI_VR_INFO_T;

# define Rte_TypeDef_tt_feedback
typedef struct
{
  data_u8_15 tt_index;
  data_u16_15 tt_status;
} tt_feedback;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_DemExt_EventStatusType
typedef uint8 DemExt_EventStatusType;

#  define Rte_TypeDef_DemExt_OperationCycleStateType
typedef uint8 DemExt_OperationCycleStateType;

#  define Rte_TypeDef_Rte_DT_FuelTablConfigSize_0
typedef sint32 Rte_DT_FuelTablConfigSize_0;

#  define Rte_TypeDef_Rte_DT_data_u8_100_0
typedef uint8 Rte_DT_data_u8_100_0;

#  define Rte_TypeDef_Rte_DT_data_u8_1024_0
typedef uint8 Rte_DT_data_u8_1024_0;

#  define Rte_TypeDef_Rte_DT_data_u8_120_0
typedef uint8 Rte_DT_data_u8_120_0;

#  define Rte_TypeDef_Rte_DT_data_u8_20_0
typedef uint8 Rte_DT_data_u8_20_0;

#  define Rte_TypeDef_Rte_DT_data_u8_22_0
typedef uint8 Rte_DT_data_u8_22_0;

#  define Rte_TypeDef_Rte_DT_data_u8_2_0
typedef uint8 Rte_DT_data_u8_2_0;

#  define Rte_TypeDef_Rte_DT_data_u8_30_0
typedef uint8 Rte_DT_data_u8_30_0;

#  define Rte_TypeDef_Rte_DT_data_u8_3584_0
typedef uint8 Rte_DT_data_u8_3584_0;

#  define Rte_TypeDef_Rte_DT_data_u8_36_0
typedef uint8 Rte_DT_data_u8_36_0;

#  define Rte_TypeDef_Rte_DT_data_u8_42_0
typedef uint8 Rte_DT_data_u8_42_0;

#  define Rte_TypeDef_Rte_DT_data_u8_47_0
typedef uint8 Rte_DT_data_u8_47_0;

#  define Rte_TypeDef_Rte_DT_data_u8_52_0
typedef uint8 Rte_DT_data_u8_52_0;

#  define Rte_TypeDef_Rte_DT_data_u8_53_0
typedef uint8 Rte_DT_data_u8_53_0;

#  define Rte_TypeDef_Rte_DT_data_u8_54_0
typedef uint8 Rte_DT_data_u8_54_0;

#  define Rte_TypeDef_Rte_DT_data_u8_6_0
typedef uint8 Rte_DT_data_u8_6_0;

#  define Rte_TypeDef_Rte_DT_data_u8_70_0
typedef uint8 Rte_DT_data_u8_70_0;

#  define Rte_TypeDef_Rte_DT_data_u8_7168_0
typedef uint8 Rte_DT_data_u8_7168_0;

#  define Rte_TypeDef_Rte_DT_data_u8_80_0
typedef uint8 Rte_DT_data_u8_80_0;

#  define Rte_TypeDef_Rte_DT_data_u8_9_0
typedef uint8 Rte_DT_data_u8_9_0;

#  define Rte_TypeDef_Rte_DT_tComSignal64_0
typedef uint8 Rte_DT_tComSignal64_0;

#  define Rte_TypeDef_tConfigAutoParkWarnConfig
typedef boolean tConfigAutoParkWarnConfig;

#  define Rte_TypeDef_tConfigCTASensorBlockedWarnConfig
typedef boolean tConfigCTASensorBlockedWarnConfig;

#  define Rte_TypeDef_tConfigCTASystemFaultWarnConfig
typedef boolean tConfigCTASystemFaultWarnConfig;

#  define Rte_TypeDef_tConfigChargePortDoorAjarWarningConfig
typedef boolean tConfigChargePortDoorAjarWarningConfig;

#  define Rte_TypeDef_tConfigChargeStationFaultWarningsConfig
typedef boolean tConfigChargeStationFaultWarningsConfig;

#  define Rte_TypeDef_tConfigChimeVolumeSetDRConfig
typedef boolean tConfigChimeVolumeSetDRConfig;

#  define Rte_TypeDef_tConfigCrossTrafficAlertBrakeWarnConfig
typedef boolean tConfigCrossTrafficAlertBrakeWarnConfig;

#  define Rte_TypeDef_tConfigCrossTrafficAlertWarnConfig
typedef boolean tConfigCrossTrafficAlertWarnConfig;

#  define Rte_TypeDef_tConfigDR
typedef uint8 tConfigDR;

#  define Rte_TypeDef_tConfigDTEValue
typedef uint8 tConfigDTEValue;

#  define Rte_TypeDef_tConfigDeltaLimitTable
typedef uint8 tConfigDeltaLimitTable;

#  define Rte_TypeDef_tConfigDistanceAlertConfig
typedef boolean tConfigDistanceAlertConfig;

#  define Rte_TypeDef_tConfigDistanceIndicatorConfig
typedef boolean tConfigDistanceIndicatorConfig;

#  define Rte_TypeDef_tConfigESCConfig
typedef boolean tConfigESCConfig;

#  define Rte_TypeDef_tConfigESCOffConfig
typedef boolean tConfigESCOffConfig;

#  define Rte_TypeDef_tConfigEngineCoolantTempGauge
typedef boolean tConfigEngineCoolantTempGauge;

#  define Rte_TypeDef_tConfigFuelCapacity
typedef uint32 tConfigFuelCapacity;

#  define Rte_TypeDef_tConfigHighwayAssistConfig
typedef boolean tConfigHighwayAssistConfig;

#  define Rte_TypeDef_tConfigISAConfig
typedef boolean tConfigISAConfig;

#  define Rte_TypeDef_tConfigInitialDateDay
typedef uint16 tConfigInitialDateDay;

#  define Rte_TypeDef_tConfigInitialDateYr
typedef uint16 tConfigInitialDateYr;

#  define Rte_TypeDef_tConfigKR
typedef uint32 tConfigKR;

#  define Rte_TypeDef_tConfigLanguageBundles
typedef uint16 tConfigLanguageBundles;

#  define Rte_TypeDef_tConfigLfrFuelDteHybrid
typedef uint8 tConfigLfrFuelDteHybrid;

#  define Rte_TypeDef_tConfigMyViewTimeout
typedef uint8 tConfigMyViewTimeout;

#  define Rte_TypeDef_tConfigPDSFaultConfig
typedef boolean tConfigPDSFaultConfig;

#  define Rte_TypeDef_tConfigParkLockControlConfig
typedef boolean tConfigParkLockControlConfig;

#  define Rte_TypeDef_tConfigRAFE
typedef uint8 tConfigRAFE;

#  define Rte_TypeDef_tConfigSD
typedef uint8 tConfigSD;

#  define Rte_TypeDef_tConfigSK
typedef uint16 tConfigSK;

#  define Rte_TypeDef_tConfigSWSConfig
typedef boolean tConfigSWSConfig;

#  define Rte_TypeDef_tConfigServiceAdvanceTracConfig
typedef boolean tConfigServiceAdvanceTracConfig;

#  define Rte_TypeDef_tConfigShiftOutOfNeutralConfig
typedef boolean tConfigShiftOutOfNeutralConfig;

#  define Rte_TypeDef_tConfigTD
typedef uint8 tConfigTD;

#  define Rte_TypeDef_tConfigTK
typedef uint16 tConfigTK;

#  define Rte_TypeDef_tConfigTSRConfig
typedef boolean tConfigTSRConfig;

#  define Rte_TypeDef_tConfigTransManualConfig
typedef boolean tConfigTransManualConfig;

#  define Rte_TypeDef_teDiagBypassMode
typedef uint8 teDiagBypassMode;

#  define Rte_TypeDef_voidptr
typedef void * voidptr;

#  define Rte_TypeDef_EButtonId
typedef uint8 EButtonId;

#  define Rte_TypeDef_EButtonState
typedef uint8 EButtonState;

#  define Rte_TypeDef_ECompassValue
typedef uint8 ECompassValue;

#  define Rte_TypeDef_EDidType
typedef uint8 EDidType;

#  define Rte_TypeDef_EDisplayHMIStatus
typedef uint8 EDisplayHMIStatus;

#  define Rte_TypeDef_EDisplayPower
typedef uint8 EDisplayPower;

#  define Rte_TypeDef_EDisplayStatus
typedef uint8 EDisplayStatus;

#  define Rte_TypeDef_EDmnSystemState_t
typedef uint8 EDmnSystemState_t;

#  define Rte_TypeDef_EFuelEconomy
typedef uint8 EFuelEconomy;

#  define Rte_TypeDef_EGaugeUnit
typedef uint8 EGaugeUnit;

#  define Rte_TypeDef_EIOCtrlOptType
typedef uint8 EIOCtrlOptType;

#  define Rte_TypeDef_EIgnitionStatus
typedef uint8 EIgnitionStatus;

#  define Rte_TypeDef_EMediaText
typedef uint8 EMediaText;

#  define Rte_TypeDef_EOatStatus
typedef uint8 EOatStatus;

#  define Rte_TypeDef_EOdoStatus
typedef uint8 EOdoStatus;

#  define Rte_TypeDef_EPUIMcanPopupStatus_t
typedef uint8 EPUIMcanPopupStatus_t;

#  define Rte_TypeDef_EPhoneCmd
typedef uint8 EPhoneCmd;

#  define Rte_TypeDef_EPhoneStatus
typedef uint8 EPhoneStatus;

#  define Rte_TypeDef_EPictureCopyStatusType_t
typedef uint8 EPictureCopyStatusType_t;

#  define Rte_TypeDef_ERoutineType
typedef uint8 ERoutineType;

#  define Rte_TypeDef_ESndCdd_InterruptType
typedef uint8 ESndCdd_InterruptType;

#  define Rte_TypeDef_ESnd_InterruptType
typedef uint8 ESnd_InterruptType;

#  define Rte_TypeDef_EStringEncoding
typedef uint8 EStringEncoding;

#  define Rte_TypeDef_ETrip
typedef uint8 ETrip;

#  define Rte_TypeDef_ETripCmd
typedef uint8 ETripCmd;

#  define Rte_TypeDef_EUdsTimeout_t
typedef uint8 EUdsTimeout_t;

#  define Rte_TypeDef_EVidioPlayerStatusType_t
typedef uint8 EVidioPlayerStatusType_t;

#  define Rte_TypeDef_EcuM_WakeupSourceType
typedef uint32 EcuM_WakeupSourceType;

#  define Rte_TypeDef_WarningAckStatus
typedef uint8 WarningAckStatus;

#  define Rte_TypeDef_WdgM_GlobalStatusType
typedef uint8 WdgM_GlobalStatusType;

#  define Rte_TypeDef_WdgM_LocalStatusType
typedef uint8 WdgM_LocalStatusType;

#  define Rte_TypeDef_tACCEnableOutValue
typedef uint8 tACCEnableOutValue;

#  define Rte_TypeDef_tACC_Mode
typedef uint8 tACC_Mode;

#  define Rte_TypeDef_tAppStatus
typedef uint8 tAppStatus;

#  define Rte_TypeDef_tBMAudioMuteStatus
typedef uint8 tBMAudioMuteStatus;

#  define Rte_TypeDef_tBMMyKey
typedef uint8 tBMMyKey;

#  define Rte_TypeDef_tBeltminderTTState
typedef uint8 tBeltminderTTState;

#  define Rte_TypeDef_tChimeId
typedef uint8 tChimeId;

#  define Rte_TypeDef_tChimeSource
typedef uint8 tChimeSource;

#  define Rte_TypeDef_tChimesQueueStatus
typedef uint8 tChimesQueueStatus;

#  define Rte_TypeDef_tConfig4x4AWDSource
typedef uint8 tConfig4x4AWDSource;

#  define Rte_TypeDef_tConfigAFEReset
typedef uint8 tConfigAFEReset;

#  define Rte_TypeDef_tConfigAltFuelInjector
typedef uint8 tConfigAltFuelInjector;

#  define Rte_TypeDef_tConfigAltFuelLPG
typedef uint8 tConfigAltFuelLPG;

#  define Rte_TypeDef_tConfigAutoHBMenu
typedef uint8 tConfigAutoHBMenu;

#  define Rte_TypeDef_tConfigAutoHighbeam
typedef uint8 tConfigAutoHighbeam;

#  define Rte_TypeDef_tConfigAutoPark
typedef uint8 tConfigAutoPark;

#  define Rte_TypeDef_tConfigBench
typedef uint8 tConfigBench;

#  define Rte_TypeDef_tConfigBoostVacuum
typedef uint8 tConfigBoostVacuum;

#  define Rte_TypeDef_tConfigBoostVacuumRange
typedef uint8 tConfigBoostVacuumRange;

#  define Rte_TypeDef_tConfigBrakeTltSymbol
typedef uint8 tConfigBrakeTltSymbol;

#  define Rte_TypeDef_tConfigBrakeType
typedef uint8 tConfigBrakeType;

#  define Rte_TypeDef_tConfigBrand
typedef uint8 tConfigBrand;

#  define Rte_TypeDef_tConfigCenterStack
typedef uint8 tConfigCenterStack;

#  define Rte_TypeDef_tConfigChimeSource
typedef uint8 tConfigChimeSource;

#  define Rte_TypeDef_tConfigChinaBEV
typedef uint8 tConfigChinaBEV;

#  define Rte_TypeDef_tConfigCompassSyncGen
typedef uint8 tConfigCompassSyncGen;

#  define Rte_TypeDef_tConfigCountdownStart
typedef uint8 tConfigCountdownStart;

#  define Rte_TypeDef_tConfigCustomerConnectivitySettings
typedef uint8 tConfigCustomerConnectivitySettings;

#  define Rte_TypeDef_tConfigD544SpdmtrStyle
typedef uint8 tConfigD544SpdmtrStyle;

#  define Rte_TypeDef_tConfigDEFWarnings
typedef uint8 tConfigDEFWarnings;

#  define Rte_TypeDef_tConfigDateTime
typedef uint8 tConfigDateTime;

#  define Rte_TypeDef_tConfigDefaultLanguage
typedef uint8 tConfigDefaultLanguage;

#  define Rte_TypeDef_tConfigDig
typedef uint8 tConfigDig;

#  define Rte_TypeDef_tConfigDispTempUnit
typedef uint8 tConfigDispTempUnit;

#  define Rte_TypeDef_tConfigDispUnit
typedef uint8 tConfigDispUnit;

#  define Rte_TypeDef_tConfigDoorContent
typedef uint8 tConfigDoorContent;

#  define Rte_TypeDef_tConfigDriverSide
typedef uint8 tConfigDriverSide;

#  define Rte_TypeDef_tConfigECUArchitecture
typedef uint8 tConfigECUArchitecture;

#  define Rte_TypeDef_tConfigEIChime
typedef uint8 tConfigEIChime;

#  define Rte_TypeDef_tConfigEPRNDL
typedef uint8 tConfigEPRNDL;

#  define Rte_TypeDef_tConfigEngineFuelType
typedef uint8 tConfigEngineFuelType;

#  define Rte_TypeDef_tConfigFCW
typedef uint8 tConfigFCW;

#  define Rte_TypeDef_tConfigFEGallon
typedef uint8 tConfigFEGallon;

#  define Rte_TypeDef_tConfigFEMethod
typedef uint8 tConfigFEMethod;

#  define Rte_TypeDef_tConfigFEMetric
typedef uint8 tConfigFEMetric;

#  define Rte_TypeDef_tConfigFeatureGlobalActive
typedef uint8 tConfigFeatureGlobalActive;

#  define Rte_TypeDef_tConfigFuelGDelta
typedef uint8 tConfigFuelGDelta;

#  define Rte_TypeDef_tConfigFuelInitStep
typedef uint8 tConfigFuelInitStep;

#  define Rte_TypeDef_tConfigFuelLvlPCM
typedef uint8 tConfigFuelLvlPCM;

#  define Rte_TypeDef_tConfigFuelTankArrowDirection
typedef uint8 tConfigFuelTankArrowDirection;

#  define Rte_TypeDef_tConfigGearRange
typedef uint8 tConfigGearRange;

#  define Rte_TypeDef_tConfigGearSelect
typedef uint8 tConfigGearSelect;

#  define Rte_TypeDef_tConfigGlobalClock
typedef uint8 tConfigGlobalClock;

#  define Rte_TypeDef_tConfigHMIOilMinderMenu
typedef uint8 tConfigHMIOilMinderMenu;

#  define Rte_TypeDef_tConfigHUDCfg
typedef uint8 tConfigHUDCfg;

#  define Rte_TypeDef_tConfigHardWiredCan
typedef uint8 tConfigHardWiredCan;

#  define Rte_TypeDef_tConfigHighbeam
typedef uint8 tConfigHighbeam;

#  define Rte_TypeDef_tConfigHighbeam2
typedef uint8 tConfigHighbeam2;

#  define Rte_TypeDef_tConfigICPlantConfigStatus
typedef uint8 tConfigICPlantConfigStatus;

#  define Rte_TypeDef_tConfigICPlantConfigUnits
typedef uint8 tConfigICPlantConfigUnits;

#  define Rte_TypeDef_tConfigICPlantConfigWrnByLoc
typedef uint8 tConfigICPlantConfigWrnByLoc;

#  define Rte_TypeDef_tConfigIntelAccKeyFree
typedef uint8 tConfigIntelAccKeyFree;

#  define Rte_TypeDef_tConfigInterface_DExxBlocks
typedef uint8 tConfigInterface_DExxBlocks;

#  define Rte_TypeDef_tConfigLaneAssist
typedef uint8 tConfigLaneAssist;

#  define Rte_TypeDef_tConfigLaneAssistMenu
typedef uint8 tConfigLaneAssistMenu;

#  define Rte_TypeDef_tConfigLangSyncVersion
typedef uint8 tConfigLangSyncVersion;

#  define Rte_TypeDef_tConfigLanguageSignal
typedef uint8 tConfigLanguageSignal;

#  define Rte_TypeDef_tConfigLfrDteLvl
typedef uint8 tConfigLfrDteLvl;

#  define Rte_TypeDef_tConfigLfrDteValue
typedef uint8 tConfigLfrDteValue;

#  define Rte_TypeDef_tConfigMaintenanceMode
typedef uint8 tConfigMaintenanceMode;

#  define Rte_TypeDef_tConfigMexico
typedef uint8 tConfigMexico;

#  define Rte_TypeDef_tConfigMinorGaugeUnits
typedef uint8 tConfigMinorGaugeUnits;

#  define Rte_TypeDef_tConfigMsgCenterDispInterface
typedef uint8 tConfigMsgCenterDispInterface;

#  define Rte_TypeDef_tConfigMultipleChime
typedef uint8 tConfigMultipleChime;

#  define Rte_TypeDef_tConfigMyKey911
typedef uint8 tConfigMyKey911;

#  define Rte_TypeDef_tConfigMyKeySpdMkt
typedef uint8 tConfigMyKeySpdMkt;

#  define Rte_TypeDef_tConfigNavSpdSign
typedef uint8 tConfigNavSpdSign;

#  define Rte_TypeDef_tConfigNoFuelSensors
typedef uint8 tConfigNoFuelSensors;

#  define Rte_TypeDef_tConfigOATSource
typedef uint8 tConfigOATSource;

#  define Rte_TypeDef_tConfigOffRoadScreen
typedef uint8 tConfigOffRoadScreen;

#  define Rte_TypeDef_tConfigOilPressureGaugeType
typedef uint8 tConfigOilPressureGaugeType;

#  define Rte_TypeDef_tConfigPADITelltale
typedef uint8 tConfigPADITelltale;

#  define Rte_TypeDef_tConfigPTHybrid
typedef uint8 tConfigPTHybrid;

#  define Rte_TypeDef_tConfigPTHybrid2
typedef uint8 tConfigPTHybrid2;

#  define Rte_TypeDef_tConfigParameterList
typedef uint16 tConfigParameterList;

#  define Rte_TypeDef_tConfigParkAidW350
typedef uint8 tConfigParkAidW350;

#  define Rte_TypeDef_tConfigPassengerCommercial
typedef uint8 tConfigPassengerCommercial;

#  define Rte_TypeDef_tConfigPerimeterAlarmText
typedef uint8 tConfigPerimeterAlarmText;

#  define Rte_TypeDef_tConfigPoliceMxSpdSelction
typedef uint8 tConfigPoliceMxSpdSelction;

#  define Rte_TypeDef_tConfigPowerSlidingDoor
typedef uint8 tConfigPowerSlidingDoor;

#  define Rte_TypeDef_tConfigPrkLckAllw
typedef uint8 tConfigPrkLckAllw;

#  define Rte_TypeDef_tConfigPtyStyle
typedef uint8 tConfigPtyStyle;

#  define Rte_TypeDef_tConfigPwrDoorChime
typedef uint8 tConfigPwrDoorChime;

#  define Rte_TypeDef_tConfigRBMSeatLayout
typedef uint8 tConfigRBMSeatLayout;

#  define Rte_TypeDef_tConfigRemovableDoors
typedef uint8 tConfigRemovableDoors;

#  define Rte_TypeDef_tConfigSBWeShifter
typedef uint8 tConfigSBWeShifter;

#  define Rte_TypeDef_tConfigSST
typedef uint8 tConfigSST;

#  define Rte_TypeDef_tConfigSaddleTankWght
typedef uint8 tConfigSaddleTankWght;

#  define Rte_TypeDef_tConfigSeatBeltWarning
typedef uint8 tConfigSeatBeltWarning;

#  define Rte_TypeDef_tConfigSeatbelt
typedef uint8 tConfigSeatbelt;

#  define Rte_TypeDef_tConfigSettingsMenu
typedef uint8 tConfigSettingsMenu;

#  define Rte_TypeDef_tConfigSpeedoBias
typedef uint8 tConfigSpeedoBias;

#  define Rte_TypeDef_tConfigStatus
typedef uint8 tConfigStatus;

#  define Rte_TypeDef_tConfigSteeringGear
typedef uint8 tConfigSteeringGear;

#  define Rte_TypeDef_tConfigSteeringWheelSwtchKA
typedef uint8 tConfigSteeringWheelSwtchKA;

#  define Rte_TypeDef_tConfigTCI_IVD_RSC
typedef uint8 tConfigTCI_IVD_RSC;

#  define Rte_TypeDef_tConfigTCType
typedef uint8 tConfigTCType;

#  define Rte_TypeDef_tConfigTJAMetaphor
typedef uint8 tConfigTJAMetaphor;

#  define Rte_TypeDef_tConfigTPMSFedReg
typedef uint8 tConfigTPMSFedReg;

#  define Rte_TypeDef_tConfigTPMSLocation
typedef uint8 tConfigTPMSLocation;

#  define Rte_TypeDef_tConfigTPMSUnits
typedef uint8 tConfigTPMSUnits;

#  define Rte_TypeDef_tConfigTachRedline
typedef uint8 tConfigTachRedline;

#  define Rte_TypeDef_tConfigTachSignal
typedef uint8 tConfigTachSignal;

#  define Rte_TypeDef_tConfigTankSelection
typedef uint8 tConfigTankSelection;

#  define Rte_TypeDef_tConfigTanks
typedef uint8 tConfigTanks;

#  define Rte_TypeDef_tConfigTccmNt
typedef uint8 tConfigTccmNt;

#  define Rte_TypeDef_tConfigTempCurve
typedef uint8 tConfigTempCurve;

#  define Rte_TypeDef_tConfigTempCurve2
typedef uint8 tConfigTempCurve2;

#  define Rte_TypeDef_tConfigTerrainManWithType
typedef uint8 tConfigTerrainManWithType;

#  define Rte_TypeDef_tConfigTrailerMeasure
typedef uint8 tConfigTrailerMeasure;

#  define Rte_TypeDef_tConfigTransType
typedef uint8 tConfigTransType;

#  define Rte_TypeDef_tConfigTransferCaseType
typedef uint8 tConfigTransferCaseType;

#  define Rte_TypeDef_tConfigTransmissionTempCurve
typedef uint8 tConfigTransmissionTempCurve;

#  define Rte_TypeDef_tConfigTurboBoost
typedef uint8 tConfigTurboBoost;

#  define Rte_TypeDef_tConfigVirtualSpeedometerStyle
typedef uint8 tConfigVirtualSpeedometerStyle;

#  define Rte_TypeDef_tConfigWarningDisplayLocation
typedef uint8 tConfigWarningDisplayLocation;

#  define Rte_TypeDef_tConfigWelcomeIgn
typedef uint8 tConfigWelcomeIgn;

#  define Rte_TypeDef_tConfigXWD
typedef uint8 tConfigXWD;

#  define Rte_TypeDef_tDiagSelfTestSt
typedef uint8 tDiagSelfTestSt;

#  define Rte_TypeDef_tDiagVehicleMode
typedef uint8 tDiagVehicleMode;

#  define Rte_TypeDef_tEPRNDLMode
typedef uint8 tEPRNDLMode;

#  define Rte_TypeDef_tEPRNDLSSTIndicatorSelection
typedef uint8 tEPRNDLSSTIndicatorSelection;

#  define Rte_TypeDef_tEPRNDLSSTRangeDiagCtrl
typedef uint8 tEPRNDLSSTRangeDiagCtrl;

#  define Rte_TypeDef_tETMFlagStatus
typedef uint8 tETMFlagStatus;

#  define Rte_TypeDef_tFaultCounterReset
typedef uint8 tFaultCounterReset;

#  define Rte_TypeDef_tGaugesDiagSelfTestStatus
typedef uint8 tGaugesDiagSelfTestStatus;

#  define Rte_TypeDef_tGaugesODSelfTest
typedef uint8 tGaugesODSelfTest;

#  define Rte_TypeDef_tGearSelectInd
typedef uint8 tGearSelectInd;

#  define Rte_TypeDef_tGenMdlDiagResp
typedef uint8 tGenMdlDiagResp;

#  define Rte_TypeDef_tGenMdlKeyOffcounterSts
typedef uint8 tGenMdlKeyOffcounterSts;

#  define Rte_TypeDef_tHoodAjarChimeState
typedef uint8 tHoodAjarChimeState;

#  define Rte_TypeDef_tIODPwrDistConstantIDs
typedef uint8 tIODPwrDistConstantIDs;

#  define Rte_TypeDef_tIPCACCDenyOutValue
typedef uint8 tIPCACCDenyOutValue;

#  define Rte_TypeDef_tMCRqstWarningChime
typedef sint32 tMCRqstWarningChime;

#  define Rte_TypeDef_tManualGearIndication
typedef uint8 tManualGearIndication;

#  define Rte_TypeDef_tNCC_Mode
typedef uint8 tNCC_Mode;

#  define Rte_TypeDef_tOdoStatus
typedef uint8 tOdoStatus;

#  define Rte_TypeDef_tPDSFault
typedef uint8 tPDSFault;

#  define Rte_TypeDef_tPDSStatus
typedef uint8 tPDSStatus;

#  define Rte_TypeDef_tPaddleGraphicsAnimation
typedef uint8 tPaddleGraphicsAnimation;

#  define Rte_TypeDef_tParkSwitchStatusDiagCtrl
typedef uint8 tParkSwitchStatusDiagCtrl;

#  define Rte_TypeDef_tPersACCMode
typedef uint8 tPersACCMode;

#  define Rte_TypeDef_tPersAFEUnits
typedef uint8 tPersAFEUnits;

#  define Rte_TypeDef_tPersAutoLampDelay
typedef uint8 tPersAutoLampDelay;

#  define Rte_TypeDef_tPersAutoRegenCtrlStatus
typedef uint8 tPersAutoRegenCtrlStatus;

#  define Rte_TypeDef_tPersBoolean
typedef uint8 tPersBoolean;

#  define Rte_TypeDef_tPersDispUnitDist
typedef uint8 tPersDispUnitDist;

#  define Rte_TypeDef_tPersDispUnitTemp
typedef uint8 tPersDispUnitTemp;

#  define Rte_TypeDef_tPersHSAStatus
typedef uint8 tPersHSAStatus;

#  define Rte_TypeDef_tPersHUDAdasState
typedef uint8 tPersHUDAdasState;

#  define Rte_TypeDef_tPersIKDType
typedef uint8 tPersIKDType;

#  define Rte_TypeDef_tPersISASetup
typedef uint8 tPersISASetup;

#  define Rte_TypeDef_tPersLaneAssistAid
typedef uint8 tPersLaneAssistAid;

#  define Rte_TypeDef_tPersLaneAssistAlert
typedef uint8 tPersLaneAssistAlert;

#  define Rte_TypeDef_tPersLaneAssistMode
typedef uint8 tPersLaneAssistMode;

#  define Rte_TypeDef_tPersLaneAssistSensitivity
typedef uint8 tPersLaneAssistSensitivity;

#  define Rte_TypeDef_tPersLaneAssistWHI
typedef uint8 tPersLaneAssistWHI;

#  define Rte_TypeDef_tPersLanguage
typedef uint8 tPersLanguage;

#  define Rte_TypeDef_tPersMyKeySpeed
typedef uint8 tPersMyKeySpeed;

#  define Rte_TypeDef_tPersOilPercentStatus
typedef uint8 tPersOilPercentStatus;

#  define Rte_TypeDef_tPersOneTwoStageUnlock
typedef uint8 tPersOneTwoStageUnlock;

#  define Rte_TypeDef_tPersPRBStatus
typedef uint8 tPersPRBStatus;

#  define Rte_TypeDef_tPersPSChime
typedef uint8 tPersPSChime;

#  define Rte_TypeDef_tPersPerimeterAlarmguard
typedef uint8 tPersPerimeterAlarmguard;

#  define Rte_TypeDef_tPersRSClimateCtrl
typedef uint8 tPersRSClimateCtrl;

#  define Rte_TypeDef_tPersRSDefrost
typedef uint8 tPersRSDefrost;

#  define Rte_TypeDef_tPersRSDuration
typedef uint8 tPersRSDuration;

#  define Rte_TypeDef_tPersRSSeatAndWheel
typedef uint8 tPersRSSeatAndWheel;

#  define Rte_TypeDef_tPersSensitivity
typedef uint8 tPersSensitivity;

#  define Rte_TypeDef_tPersSpeedThreshold
typedef uint8 tPersSpeedThreshold;

#  define Rte_TypeDef_tPersStatus
typedef uint8 tPersStatus;

#  define Rte_TypeDef_tPersTSRThreshold
typedef uint8 tPersTSRThreshold;

#  define Rte_TypeDef_tPersTSRUnits
typedef uint8 tPersTSRUnits;

#  define Rte_TypeDef_tPersTpmsUnits
typedef uint8 tPersTpmsUnits;

#  define Rte_TypeDef_tProveOutBulbSt
typedef uint8 tProveOutBulbSt;

#  define Rte_TypeDef_tPwrGroupTrans
typedef uint8 tPwrGroupTrans;

#  define Rte_TypeDef_tPwrModeState
typedef uint8 tPwrModeState;

#  define Rte_TypeDef_tRTT_Master_List
typedef uint8 tRTT_Master_List;

#  define Rte_TypeDef_tRxSignalId
typedef uint8 tRxSignalId;

#  define Rte_TypeDef_tRxSignalJustRcvdStatus
typedef uint8 tRxSignalJustRcvdStatus;

#  define Rte_TypeDef_tRxSignalStatus
typedef uint8 tRxSignalStatus;

#  define Rte_TypeDef_tSSTGearIndication
typedef uint8 tSSTGearIndication;

#  define Rte_TypeDef_tSSTRangeSelectIndication
typedef uint8 tSSTRangeSelectIndication;

#  define Rte_TypeDef_tSWC_ButtonSt
typedef uint8 tSWC_ButtonSt;

#  define Rte_TypeDef_tSWC_ESCOffSwitchPress
typedef uint8 tSWC_ESCOffSwitchPress;

#  define Rte_TypeDef_tSWC_FastScrollSt
typedef uint8 tSWC_FastScrollSt;

#  define Rte_TypeDef_tSWC_HillDescentSw
typedef uint8 tSWC_HillDescentSw;

#  define Rte_TypeDef_tSWC_TrailControlSw
typedef uint8 tSWC_TrailControlSw;

#  define Rte_TypeDef_tSWSKeepAliveCtrlAllowSleep
typedef uint8 tSWSKeepAliveCtrlAllowSleep;

#  define Rte_TypeDef_tSdmDriveMode
typedef uint8 tSdmDriveMode;

#  define Rte_TypeDef_tSeatBeltChimeState
typedef uint8 tSeatBeltChimeState;

#  define Rte_TypeDef_tSeatBeltMinderChimeState
typedef uint8 tSeatBeltMinderChimeState;

#  define Rte_TypeDef_tSndCDDChimeSourceConfig
typedef uint8 tSndCDDChimeSourceConfig;

#  define Rte_TypeDef_tSndCDDEngSpeedThreshold
typedef uint8 tSndCDDEngSpeedThreshold;

#  define Rte_TypeDef_tSndCDDLifeCycleMode
typedef uint8 tSndCDDLifeCycleMode;

#  define Rte_TypeDef_tSndCDDMultipleChimeConfig
typedef uint8 tSndCDDMultipleChimeConfig;

#  define Rte_TypeDef_tSndCtrlChimeCurrentStatus
typedef uint8 tSndCtrlChimeCurrentStatus;

#  define Rte_TypeDef_tSndCtrlChimeQueueParams
typedef uint8 tSndCtrlChimeQueueParams;

#  define Rte_TypeDef_tSndCtrlDiagResp
typedef uint8 tSndCtrlDiagResp;

#  define Rte_TypeDef_tTJA_DA_Status
typedef uint8 tTJA_DA_Status;

#  define Rte_TypeDef_tTTDiagCtrl
typedef uint8 tTTDiagCtrl;

#  define Rte_TypeDef_tTTFuncOutputStatus
typedef uint8 tTTFuncOutputStatus;

#  define Rte_TypeDef_tTTList
typedef uint8 tTTList;

#  define Rte_TypeDef_tTTPTIDIDStatus
typedef uint8 tTTPTIDIDStatus;

#  define Rte_TypeDef_tTTSyncDIDStatus
typedef uint8 tTTSyncDIDStatus;

#  define Rte_TypeDef_tTxSigConfirmStatus
typedef uint8 tTxSigConfirmStatus;

#  define Rte_TypeDef_tTxSignalId
typedef uint8 tTxSignalId;

#  define Rte_TypeDef_tUnexpectedIgnState
typedef uint8 tUnexpectedIgnState;

#  define Rte_TypeDef_tWarnCP_Display
typedef uint8 tWarnCP_Display;

#  define Rte_TypeDef_tWarnCP_Location
typedef uint8 tWarnCP_Location;

#  define Rte_TypeDef_tWarn_CP
typedef uint8 tWarn_CP;

#  define Rte_TypeDef_tWarn_RBM_RTT_Icon
typedef uint8 tWarn_RBM_RTT_Icon;

#  define Rte_TypeDef_tWarning_DispState
typedef uint8 tWarning_DispState;

#  define Rte_TypeDef_tWarnings_DebounceBSMSensorSts
typedef uint8 tWarnings_DebounceBSMSensorSts;

#  define Rte_TypeDef_tWarnings_DebounceSts
typedef uint8 tWarnings_DebounceSts;

#  define Rte_TypeDef_tWarnings_DebouncedCTSensorSts
typedef uint8 tWarnings_DebouncedCTSensorSts;

#  define Rte_TypeDef_tWarnings_GenericMaskCounterSts
typedef uint8 tWarnings_GenericMaskCounterSts;

#  define Rte_TypeDef_tWarnings_Master_List
typedef uint16 tWarnings_Master_List;

#  define Rte_TypeDef_teOdoParam
typedef uint8 teOdoParam;

#  define Rte_TypeDef_teRomChecksumResult
typedef uint8 teRomChecksumResult;

#  define Rte_TypeDef_Csm_KeyDataType_CsmKey_MacVerify_FordCry
typedef UInt8 Csm_KeyDataType_CsmKey_MacVerify_FordCry[12];

#  define Rte_TypeDef_Csm_KeyDataType_CsmKey_RNG
typedef UInt8 Csm_KeyDataType_CsmKey_RNG[20];

#  define Rte_TypeDef_Csm_MacVerifyCompareType_CsmMacVerifyConfig
typedef UInt8 Csm_MacVerifyCompareType_CsmMacVerifyConfig[16];

#  define Rte_TypeDef_Csm_MacVerifyDataType_CsmMacVerifyConfig
typedef UInt8 Csm_MacVerifyDataType_CsmMacVerifyConfig[1024];

#  define Rte_TypeDef_Csm_RandomGenerateResultType_CsmRandomGenerateConfig
typedef UInt8 Csm_RandomGenerateResultType_CsmRandomGenerateConfig[16];

#  define Rte_TypeDef_Csm_SeedDataType
typedef UInt8 Csm_SeedDataType[20];

#  define Rte_TypeDef_Dcm_Data12ByteType
typedef UInt8 Dcm_Data12ByteType[12];

#  define Rte_TypeDef_Dcm_Data16ByteType
typedef UInt8 Dcm_Data16ByteType[16];

#  define Rte_TypeDef_FuelTablConfigSize
typedef Rte_DT_FuelTablConfigSize_0 FuelTablConfigSize[28];

#  define Rte_TypeDef_RandomSeedDataBuffer
typedef UInt8 RandomSeedDataBuffer[128];

#  define Rte_TypeDef_data_u8_100
typedef Rte_DT_data_u8_100_0 data_u8_100[100];

#  define Rte_TypeDef_data_u8_1024
typedef Rte_DT_data_u8_1024_0 data_u8_1024[1024];

#  define Rte_TypeDef_data_u8_120
typedef Rte_DT_data_u8_120_0 data_u8_120[120];

#  define Rte_TypeDef_data_u8_2
typedef uint8 data_u8_2[2];

#  define Rte_TypeDef_data_u8_20
typedef Rte_DT_data_u8_20_0 data_u8_20[20];

#  define Rte_TypeDef_data_u8_22
typedef Rte_DT_data_u8_22_0 data_u8_22[22];

#  define Rte_TypeDef_data_u8_30
typedef Rte_DT_data_u8_30_0 data_u8_30[30];

#  define Rte_TypeDef_data_u8_3584
typedef Rte_DT_data_u8_3584_0 data_u8_3584[3584];

#  define Rte_TypeDef_data_u8_36
typedef Rte_DT_data_u8_36_0 data_u8_36[36];

#  define Rte_TypeDef_data_u8_42
typedef Rte_DT_data_u8_42_0 data_u8_42[42];

#  define Rte_TypeDef_data_u8_47
typedef Rte_DT_data_u8_47_0 data_u8_47[47];

#  define Rte_TypeDef_data_u8_52
typedef Rte_DT_data_u8_52_0 data_u8_52[52];

#  define Rte_TypeDef_data_u8_53
typedef Rte_DT_data_u8_53_0 data_u8_53[53];

#  define Rte_TypeDef_data_u8_54
typedef Rte_DT_data_u8_54_0 data_u8_54[54];

#  define Rte_TypeDef_data_u8_6
typedef uint8 data_u8_6[6];

#  define Rte_TypeDef_data_u8_70
typedef uint8 data_u8_70[70];

#  define Rte_TypeDef_data_u8_7168
typedef Rte_DT_data_u8_7168_0 data_u8_7168[7168];

#  define Rte_TypeDef_data_u8_80
typedef Rte_DT_data_u8_80_0 data_u8_80[80];

#  define Rte_TypeDef_data_u8_9
typedef Rte_DT_data_u8_9_0 data_u8_9[9];

#  define Rte_TypeDef_tComSignal64
typedef Rte_DT_tComSignal64_0 tComSignal64[8];

#  define Rte_TypeDef_tConfigInterface_uint8_x_10
typedef uint8 tConfigInterface_uint8_x_10[10];

#  define Rte_TypeDef_tConfigInterface_uint8_x_3
typedef uint8 tConfigInterface_uint8_x_3[3];

#  define Rte_TypeDef_t_uint16_x_2
typedef uint16 t_uint16_x_2[2];

#  define Rte_TypeDef_t_uint16_x_24
typedef uint16 t_uint16_x_24[24];

#  define Rte_TypeDef_t_uint16_x_6
typedef uint16 t_uint16_x_6[6];

#  define Rte_TypeDef_t_uint32_x_2
typedef UInt32 t_uint32_x_2[2];

#  define Rte_TypeDef_t_uint32_x_20
typedef UInt32 t_uint32_x_20[20];

#  define Rte_TypeDef_t_uint8_x_12
typedef uint8 t_uint8_x_12[12];

#  define Rte_TypeDef_t_uint8_x_120
typedef uint8 t_uint8_x_120[120];

#  define Rte_TypeDef_t_uint8_x_122
typedef uint8 t_uint8_x_122[122];

#  define Rte_TypeDef_t_uint8_x_124
typedef uint8 t_uint8_x_124[124];

#  define Rte_TypeDef_t_uint8_x_163
typedef uint8 t_uint8_x_163[163];

#  define Rte_TypeDef_t_uint8_x_24
typedef uint8 t_uint8_x_24[24];

#  define Rte_TypeDef_t_uint8_x_25
typedef uint8 t_uint8_x_25[25];

#  define Rte_TypeDef_t_uint8_x_40
typedef uint8 t_uint8_x_40[40];

#  define Rte_TypeDef_t_uint8_x_55
typedef uint8 t_uint8_x_55[55];

#  define Rte_TypeDef_t_uint8_x_7
typedef uint8 t_uint8_x_7[7];

#  define Rte_TypeDef_NV_Data_FeaturesMCANBK
typedef struct
{
  UInt8 VRFeatureAvailability;
  UInt8 SMSFeatureAvailability;
  UInt8 HFFeatureAvailability;
  UInt8 AudioFeatureAvailability;
  UInt8 NaviSourceAvailability;
  UInt8 Steeringwheel_SourceAvailability;
} NV_Data_FeaturesMCANBK;

#  define Rte_TypeDef_SAWDGaugeData
typedef struct
{
  UInt8 AWDGauge_FrontLeftPixelFill;
  UInt8 AWDGauge_FrontRightPixelFill;
  UInt8 AWDGauge_RearLeftPixelFill;
  UInt8 AWDGauge_RearRightPixelFill;
} SAWDGaugeData;

#  define Rte_TypeDef_SAirFuelRatioState
typedef struct
{
  UInt16 value;
} SAirFuelRatioState;

#  define Rte_TypeDef_SAutoStartStopState
typedef struct
{
  UInt8 activeStartStopDisplay;
} SAutoStartStopState;

#  define Rte_TypeDef_SCompassInfo
typedef struct
{
  ECompassValue value;
} SCompassInfo;

#  define Rte_TypeDef_SControlPopup
typedef struct
{
  UInt8 type;
  UInt8 level;
  UInt8 status;
} SControlPopup;

#  define Rte_TypeDef_SControlPopupStatus
typedef struct
{
  UInt8 status;
} SControlPopupStatus;

#  define Rte_TypeDef_SDASGenData
typedef struct
{
  UInt8 id;
  UInt8 RTTStatus;
  UInt8 dynData;
} SDASGenData;

#  define Rte_TypeDef_SDTEHistory
typedef struct
{
  UInt8 dtehistoryused;
} SDTEHistory;

#  define Rte_TypeDef_SDateTime
typedef struct
{
  UInt16 year;
  UInt8 month;
  UInt8 day;
  UInt8 hour;
  UInt8 min;
  UInt8 sec;
} SDateTime;

#  define Rte_TypeDef_SDieselAdBlueState
typedef struct
{
  UInt8 text1;
  UInt8 text2;
  UInt16 value1;
  UInt16 value2;
  UInt16 value3;
} SDieselAdBlueState;

#  define Rte_TypeDef_SDieselExhaustState
typedef struct
{
  UInt8 defActive;
  UInt16 defRange;
  UInt8 defMask;
  UInt8 defSpeedLimit;
} SDieselExhaustState;

#  define Rte_TypeDef_SDieselPRTCFilterState
typedef struct
{
  UInt8 active;
  UInt8 PFS;
} SDieselPRTCFilterState;

#  define Rte_TypeDef_SDoIPSetNetworkInformation
typedef struct
{
  UInt8 ipAddressNetwork1;
  UInt8 ipAddressNetwork2;
  UInt8 ipAddressHost1;
  UInt8 ipAddressHost2;
  UInt16 portNum;
} SDoIPSetNetworkInformation;

#  define Rte_TypeDef_SDoIPSetNetworkInformation_t
typedef struct
{
  UInt8 ipAddressNetwork1;
  UInt8 ipAddressNetwork2;
  UInt8 ipAddressHost1;
  UInt8 ipAddressHost2;
  UInt16 portNum;
} SDoIPSetNetworkInformation_t;

#  define Rte_TypeDef_SDoipDiagDataConfirmation
typedef struct
{
  UInt16 sourceAddress;
  UInt16 targetAddress;
  UInt8 targetAddressType;
  UInt8 result;
} SDoipDiagDataConfirmation;

#  define Rte_TypeDef_SDoipDiagPowerModeStatus
typedef struct
{
  UInt8 powerMode;
} SDoipDiagPowerModeStatus;

#  define Rte_TypeDef_SDriverAssistDisplay
typedef struct
{
  UInt8 display;
  UInt8 counter;
} SDriverAssistDisplay;

#  define Rte_TypeDef_SEHMIStatus
typedef struct
{
  UInt8 status;
} SEHMIStatus;

#  define Rte_TypeDef_SEVCoachState
typedef struct
{
  UInt8 activeDispayMask;
  UInt8 reqPowerPercent;
  UInt8 evModeThesholdPowerPercent;
  UInt8 regenModeThesholdPowerPercent;
} SEVCoachState;

#  define Rte_TypeDef_SEVCoachTripState
typedef struct
{
  UInt8 accelScore;
  UInt8 decelScore;
  UInt8 cruiseScore;
  UInt8 shiftScore;
  UInt16 currentTrip;
  UInt8 currentTripUnits;
  UInt16 lastTrip;
  UInt8 lastTripUnits;
  UInt8 msgTextId;
  UInt8 validMask;
} SEVCoachTripState;

#  define Rte_TypeDef_SEcoAdvice
typedef struct
{
  UInt8 reasonIcon;
  UInt8 adviceIcon;
  UInt8 adviceIconColor;
  UInt8 speedLimit;
} SEcoAdvice;

#  define Rte_TypeDef_SEcoCoachDisplay
typedef struct
{
  SInt16 value;
  UInt8 status;
  UInt8 visible;
} SEcoCoachDisplay;

#  define Rte_TypeDef_SEcoCoachTripState
typedef struct
{
  UInt8 accelScore;
  UInt8 decelScore;
  UInt8 cruiseScore;
  UInt8 shiftScore;
  UInt8 ComplianceScore;
  UInt16 currentTrip;
  UInt8 currentTripUnits;
  UInt16 lastTrip;
  UInt8 lastTripUnits;
  UInt8 msgTextId;
  UInt8 validMask;
} SEcoCoachTripState;

#  define Rte_TypeDef_SElectricEfficiencyFunction
typedef struct
{
  UInt16 efficiency;
  UInt8 efficiencyStatus;
  UInt8 range;
  UInt8 rangeStatus;
} SElectricEfficiencyFunction;

#  define Rte_TypeDef_SEngineAirFilterState
typedef struct
{
  UInt8 value;
} SEngineAirFilterState;

#  define Rte_TypeDef_SEngineInfo
typedef struct
{
  UInt16 hours;
  UInt16 idleHours;
  UInt8 value;
} SEngineInfo;

#  define Rte_TypeDef_SExtETMStatus
typedef struct
{
  UInt8 value;
} SExtETMStatus;

#  define Rte_TypeDef_SGaugeInfo
typedef struct
{
  UInt8 id;
  UInt16 position;
  SInt32 digitalData;
  EGaugeUnit unit;
  UInt16 dynData;
} SGaugeInfo;

#  define Rte_TypeDef_SGaugeSceneStatus
typedef struct
{
  UInt8 gaugeSceneRendered;
} SGaugeSceneStatus;

#  define Rte_TypeDef_SGearAnimStatus
typedef struct
{
  UInt8 status;
} SGearAnimStatus;

#  define Rte_TypeDef_SHMIStatus
typedef struct
{
  UInt8 status;
} SHMIStatus;

#  define Rte_TypeDef_SHealthGetStatus
typedef struct
{
  UInt8 compIdx;
} SHealthGetStatus;

#  define Rte_TypeDef_SHighVoltageBatteryDisplay
typedef struct
{
  UInt8 batterySOC;
  UInt16 batteryPercMC;
  UInt8 electricRangeKm;
  UInt8 electricRangeMi;
} SHighVoltageBatteryDisplay;

#  define Rte_TypeDef_SHmiGfxCmdQueueRcvd
typedef struct
{
  UInt8 gfxCmdStatus;
} SHmiGfxCmdQueueRcvd;

#  define Rte_TypeDef_SHmiRendrerStatus
typedef struct
{
  UInt32 rendrerStatus;
} SHmiRendrerStatus;

#  define Rte_TypeDef_SIODGaugeData
typedef struct
{
  UInt8 id;
  UInt8 status;
  UInt8 unit;
  UInt16 value;
} SIODGaugeData;

#  define Rte_TypeDef_SKeyVal1
typedef struct
{
  UInt8 key;
  UInt8 value;
} SKeyVal1;

#  define Rte_TypeDef_SLHIStatus
typedef struct
{
  UInt8 active;
} SLHIStatus;

#  define Rte_TypeDef_SLaneKeepAssist
typedef struct
{
  UInt8 assistStatus;
  UInt8 RTTStatus;
  UInt8 markerStatus;
} SLaneKeepAssist;

#  define Rte_TypeDef_SListCmd
typedef struct
{
  UInt8 listCmd;
} SListCmd;

#  define Rte_TypeDef_SListTimeout
typedef struct
{
  UInt8 timeout;
} SListTimeout;

#  define Rte_TypeDef_SLocalHazardInformation
typedef struct
{
  UInt16 LHIDistance;
  UInt8 LHIUnits;
  UInt8 LHIDisplayStatus;
} SLocalHazardInformation;

#  define Rte_TypeDef_SMaintStatus
typedef struct
{
  UInt8 status;
  UInt8 value;
  UInt8 state;
} SMaintStatus;

#  define Rte_TypeDef_SMcanFeatureInfo_t
typedef struct
{
  EUIMcanFeatureAvailability_t MCANClockAvailability;
  EUIMcanFeatureAvailability_t AudioFeatureAvailability;
  EUIMcanFeatureAvailability_t HFFeatureAvailability;
  EUIMcanFeatureAvailability_t SMSFeatureAvailability;
  EUIMcanFeatureAvailability_t VRFeatureAvailability;
  EUIMcanFeatureAvailability_t NaviSourceAvailability;
} SMcanFeatureInfo_t;

#  define Rte_TypeDef_SNaviCmd
typedef struct
{
  UInt8 naviCmd;
} SNaviCmd;

#  define Rte_TypeDef_SOAT
typedef struct
{
  UInt16 value;
  EGaugeUnit unit;
  EOatStatus status;
} SOAT;

#  define Rte_TypeDef_SOdometer
typedef struct
{
  EOdoStatus status;
  UInt32 value;
  UInt8 unit;
} SOdometer;

#  define Rte_TypeDef_SOffRoadState
typedef struct
{
  UInt8 steeringWheelAngle;
  UInt8 pitchAngle;
  UInt8 rollAngle;
} SOffRoadState;

#  define Rte_TypeDef_SPhoneCmd
typedef struct
{
  EPhoneCmd callCmd;
} SPhoneCmd;

#  define Rte_TypeDef_SPictureCopyStatus
typedef struct
{
  EPictureCopyStatusType_t pictureCopyStatus;
} SPictureCopyStatus;

#  define Rte_TypeDef_SPowerDisState
typedef struct
{
  UInt8 frontPercentFill;
  UInt8 backPercentFill;
  UInt8 displayAnimation;
} SPowerDisState;

#  define Rte_TypeDef_SRTT_Toggle
typedef struct
{
  UInt8 positions;
  UInt8 display;
} SRTT_Toggle;

#  define Rte_TypeDef_SRadioData
typedef struct
{
  UInt16 AMFreq;
  UInt16 FMFreq;
  UInt8 valid;
} SRadioData;

#  define Rte_TypeDef_SRangeDisplay
typedef struct
{
  UInt8 mode;
  UInt8 unit;
  EDisplayHMIStatus status;
  UInt8 value;
} SRangeDisplay;

#  define Rte_TypeDef_SRearBeltMonitor
typedef struct
{
  UInt8 count;
  UInt8 seatselection;
  UInt8 seatselectionvalue;
} SRearBeltMonitor;

#  define Rte_TypeDef_SSDM
typedef struct
{
  UInt8 id;
  UInt8 mode;
  UInt16 mask;
} SSDM;

#  define Rte_TypeDef_SSPRStatus
typedef struct
{
  UInt8 steeringWheelAngle;
  UInt8 pitchAngle;
  UInt8 rollAngle;
} SSPRStatus;

#  define Rte_TypeDef_SSSM
typedef struct
{
  UInt8 id;
  UInt8 position;
  UInt8 mask;
} SSSM;

#  define Rte_TypeDef_SSSTM
typedef struct
{
  UInt8 id;
  UInt8 position;
  UInt8 mask;
} SSSTM;

#  define Rte_TypeDef_SSWC
typedef struct
{
  EButtonId buttonId;
  EButtonState buttonStatus;
  UInt8 holdTime;
} SSWC;

#  define Rte_TypeDef_SSdmArray
typedef struct
{
  UInt8 id;
  UInt8 mode;
  UInt16 mask;
} SSdmArray;

#  define Rte_TypeDef_SSetupSpeed
typedef struct
{
  UInt8 speedstatus;
} SSetupSpeed;

#  define Rte_TypeDef_SSpeedLockStatus
typedef struct
{
  UInt8 speedlockstatus;
} SSpeedLockStatus;

#  define Rte_TypeDef_SSystemMemoryTotal
typedef struct
{
  UInt32 SystemMemoryFreeStatus;
} SSystemMemoryTotal;

#  define Rte_TypeDef_STireTempState
typedef struct
{
  UInt8 tireTempUnit;
  UInt8 tireTempStat;
  UInt16 lfTireTemp;
  UInt16 rfTireTemp;
  UInt16 lrTireTemp;
  UInt16 rrTireTemp;
} STireTempState;

#  define Rte_TypeDef_STotalSystemMemoryStatus
typedef struct
{
  UInt32 totalSystemMemory;
} STotalSystemMemoryStatus;

#  define Rte_TypeDef_STrafficJamAssist
typedef struct
{
  UInt8 tjaStatus;
  UInt8 DAStatus;
  UInt8 laneBias;
} STrafficJamAssist;

#  define Rte_TypeDef_STrailerLighting
typedef struct
{
  UInt16 mask;
} STrailerLighting;

#  define Rte_TypeDef_STrailerTPMSState
typedef struct
{
  UInt8 status;
  UInt8 thresholdStatus;
  UInt8 tireCntStatus;
  UInt8 tirePressureNumColor;
  UInt8 tireTemperatureNumColor;
  UInt8 warningStatus;
  UInt8 tireTempPressColor;
} STrailerTPMSState;

#  define Rte_TypeDef_STripComputer
typedef struct
{
  ETrip tripId;
  UInt8 hour;
  UInt8 minute;
  UInt8 second;
  UInt32 distance;
  UInt32 distanceEV;
  UInt8 distanceUnit;
  UInt16 avgFuel;
  UInt16 avgFuelEV;
  UInt8 valid;
} STripComputer;

#  define Rte_TypeDef_STripResetCmd
typedef struct
{
  ETripCmd tripCmdId;
} STripResetCmd;

#  define Rte_TypeDef_SUdsServiceResponseTransmitConfirmation
typedef struct
{
  UInt8 serviceId;
  UInt8 responseType;
  UInt16 clientAddress;
} SUdsServiceResponseTransmitConfirmation;

#  define Rte_TypeDef_SUdsServiceSetTimings
typedef struct
{
  UInt32 p2TimeMs;
  UInt32 p2StarTimeMs;
  UInt32 p4TimeMs;
} SUdsServiceSetTimings;

#  define Rte_TypeDef_SUdsTimeout
typedef struct
{
  EUdsTimeout_t timeoutType;
  UInt16 clientAddress;
} SUdsTimeout;

#  define Rte_TypeDef_SVideoPlayerStatus
typedef struct
{
  EVidioPlayerStatusType_t videoPlayerStatus;
} SVideoPlayerStatus;

#  define Rte_TypeDef_SWarningStatus
typedef struct
{
  UInt8 visible;
  UInt16 warningId;
} SWarningStatus;

#  define Rte_TypeDef_SWelcomeFarewallData
typedef struct
{
  UInt8 SUSDState;
  UInt8 WelcomeScreenState;
  UInt8 FarewellScreenState;
} SWelcomeFarewallData;

#  define Rte_TypeDef_SWelcomeResponse
typedef struct
{
  UInt8 status;
} SWelcomeResponse;

#  define Rte_TypeDef_TC06_NVM_VARIABLE
typedef struct
{
  UInt32 AFE_A_Dist;
  UInt32 AFE_A_Fuel;
  UInt32 TripStatsA_Dist;
  UInt32 TripStatsB_Dist;
  UInt32 TripStatsA_Fuel;
  UInt32 TripStatsB_Fuel;
  UInt32 TripStatsA_TimeCnt;
  UInt32 TripStatsB_TimeCnt;
  UInt32 eAFE_A_Fuel_Pos_Accum;
  UInt32 eAFE_A_Fuel_Neg_Accum;
  UInt32 eTS_Dist_A_Accum;
  UInt32 eTS_Fuel_Pos_A_Accum;
  UInt32 eTS_Fuel_Neg_A_Accum;
  UInt32 eTS_Dist_B_Accum;
  UInt32 eTS_Fuel_Pos_B_Accum;
  UInt32 eTS_Fuel_Neg_B_Accum;
  UInt32 LTFE_Dist_Accum;
  UInt32 LTFE_Fuel_Accum;
  UInt32 eLTFE_Dist_Accum;
  UInt32 eLTFE_Fuel_Neg_Accum;
  UInt32 eLTFE_Fuel_Pos_Accum;
  UInt32 eLTFE_Distance_km;
  UInt32 eLTFE_Distance_mi;
} TC06_NVM_VARIABLE;

#  define Rte_TypeDef_tGenMdlDiagToneCtrlData
typedef struct
{
  UInt16 ChimeFreq;
  UInt8 VolumePercent;
  UInt8 Channel;
} tGenMdlDiagToneCtrlData;

#  define Rte_TypeDef_tPwrModeTrans
typedef struct
{
  tPwrModeState EntryMode;
  tPwrGroupTrans GroupTrans;
  tPwrModeState ExitMode;
} tPwrModeTrans;

#  define Rte_TypeDef_tSndCDDDiagRoutineCtrlData
typedef struct
{
  UInt8 AttenuationLevel;
  UInt8 ChimeId;
  UInt8 Repetition;
} tSndCDDDiagRoutineCtrlData;

#  define Rte_TypeDef_tSndCtrlDiagRoutineData
typedef struct
{
  UInt8 AttenuationLevel;
  UInt8 ChimeId;
  UInt8 Repetition;
} tSndCtrlDiagRoutineData;

#  define Rte_TypeDef_tSndCtrlToneParam
typedef struct
{
  UInt16 AmplitudeDutyCycle;
  UInt16 AmplitudeFrequency;
  UInt16 ToneAttackConstant;
  UInt16 ToneAttackTime;
  UInt8 ToneAttackType;
  UInt16 ToneDecayConstant;
  UInt16 ToneDecayTime;
  UInt8 ToneDecayType;
  UInt16 ToneDuration;
  UInt16 ToneDutyCycle;
  UInt16 ToneFrequency;
  UInt16 ToneSustainTime;
} tSndCtrlToneParam;

#  define Rte_TypeDef_Crypto_VerifyResultType
typedef UInt8 Crypto_VerifyResultType;

#  define Rte_TypeDef_Csm_ResultType
typedef UInt8 Csm_ResultType;

#  define Rte_TypeDef_Dcm_SecLevelType
typedef UInt8 Dcm_SecLevelType;

#  define Rte_TypeDef_HM_Failure_Code_Type
typedef struct
{
  UInt8 Info_byte;
  UInt8 Component_ID;
  t_uint8_x_4 TimeStamp;
  UInt32 TimeIGNOn;
} HM_Failure_Code_Type;

#  define Rte_TypeDef_SChecksumValue
typedef struct
{
  data_u32_3 dispCtrlChecksumValue;
  UInt8 regionid;
  UInt8 assetid;
  UInt16 safetyfooter;
} SChecksumValue;

#  define Rte_TypeDef_SDistanceToEmpty
typedef struct
{
  EFuelEconomy feType;
  UInt16 value;
  UInt8 unit;
  UInt8 valid;
  data_u8_5 dynData;
} SDistanceToEmpty;

#  define Rte_TypeDef_SDoipDiagDataIndication
typedef struct
{
  UInt16 sourceAddress;
  UInt16 targetAddress;
  UInt8 targetAddressType;
  UInt16 dataLen;
  data_u8_7168 data;
  UInt8 result;
} SDoipDiagDataIndication;

#  define Rte_TypeDef_SDoipDiagDataTransferRequest
typedef struct
{
  UInt16 sourceAddress;
  UInt16 targetAddress;
  UInt8 targetAddressType;
  UInt16 dataLen;
  data_u8_7168 data;
  UInt8 result;
} SDoipDiagDataTransferRequest;

#  define Rte_TypeDef_SDoipSetParams
typedef struct
{
  data_u8_17 vinNumber;
  data_u8_6 eidNumber;
  data_u8_6 gidNumber;
  UInt8 isVinNumValid;
  UInt8 isGidNumValid;
  UInt8 isEidNumValid;
  SDoIPSetNetworkInformation ipConfig;
  UInt8 isNetWorkConfigValid;
  UInt8 gidSyncStatus;
  UInt8 isGidSyncStatusValid;
} SDoipSetParams;

#  define Rte_TypeDef_SDriverAssistData
typedef struct
{
  UInt8 id;
  UInt8 mode;
  data_u8_9 dynData;
} SDriverAssistData;

#  define Rte_TypeDef_SETMData
typedef struct
{
  UInt8 id;
  data_u8_50 data;
} SETMData;

#  define Rte_TypeDef_SETMStatus
typedef struct
{
  data_u8_5 data;
} SETMStatus;

#  define Rte_TypeDef_SFRTT_Status
typedef struct
{
  data_u8_32 mask;
} SFRTT_Status;

#  define Rte_TypeDef_SFastGuageInfo
typedef struct
{
  SGaugeInfo gaugeInfo_4;
} SFastGuageInfo;

#  define Rte_TypeDef_SFuelEconomy
typedef struct
{
  EFuelEconomy feType;
  UInt16 value;
  UInt8 valid;
  data_u8_8 dynData;
} SFuelEconomy;

#  define Rte_TypeDef_SGALCarPlayData
typedef struct
{
  data_u8_3 dynData;
} SGALCarPlayData;

#  define Rte_TypeDef_SGaugeInfo_4
typedef SGaugeInfo SGaugeInfo_4[4];

#  define Rte_TypeDef_SGearStatus
typedef struct
{
  UInt8 eprndl;
  UInt8 manual;
  UInt8 sst;
  data_u8_10 sstRange;
  UInt8 dynData;
} SGearStatus;

#  define Rte_TypeDef_SHealthStatusReport
typedef struct
{
  UInt32 timestamp;
  UInt16 dataLen;
  data_u8_256 data;
} SHealthStatusReport;

#  define Rte_TypeDef_SHmiAnimationStatus
typedef struct
{
  data_u8_1024 animationStatus;
} SHmiAnimationStatus;

#  define Rte_TypeDef_SHmiCmdData
typedef struct
{
  data_u8_3584 cmdData;
} SHmiCmdData;

#  define Rte_TypeDef_SIODSettings
typedef struct
{
  data_u8_2 dynData;
} SIODSettings;

#  define Rte_TypeDef_SKeyVal1_10
typedef SKeyVal1 SKeyVal1_10[10];

#  define Rte_TypeDef_SKeyVal2
typedef struct
{
  UInt8 key;
  data_u8_2 value;
} SKeyVal2;

#  define Rte_TypeDef_SKeyVal2_50
typedef SKeyVal2 SKeyVal2_50[50];

#  define Rte_TypeDef_SKeyVal4
typedef struct
{
  UInt8 key;
  data_u8_4 value;
} SKeyVal4;

#  define Rte_TypeDef_SKeyVal4_5
typedef SKeyVal4 SKeyVal4_5[5];

#  define Rte_TypeDef_SKeyVal8
typedef struct
{
  UInt8 key;
  data_u8_8 value;
} SKeyVal8;

#  define Rte_TypeDef_SKeyVal8_2
typedef SKeyVal8 SKeyVal8_2[2];

#  define Rte_TypeDef_SMediaText
typedef struct
{
  EMediaText id;
  data_u8_40 text;
  EStringEncoding type;
} SMediaText;

#  define Rte_TypeDef_SMediaTextExt
typedef struct
{
  EMediaText id;
  data_u8_130 text;
  EStringEncoding type;
} SMediaTextExt;

#  define Rte_TypeDef_SNaviData
typedef struct
{
  data_u8_42 streetName;
  EStringEncoding streetNameType;
  UInt8 active;
  UInt8 turnIconId;
  UInt8 speedLimitValue;
  UInt8 navBarGraphSteps;
  UInt16 naviDistanceWhole;
  UInt16 naviDistanceTenth;
  UInt8 naviDistanceUnit;
} SNaviData;

#  define Rte_TypeDef_SPersRecord
typedef struct
{
  SKeyVal8 data;
} SPersRecord;

#  define Rte_TypeDef_SPersRecord1byte
typedef struct
{
  SKeyVal1_10 data_10;
} SPersRecord1byte;

#  define Rte_TypeDef_SPersRecord4byte
typedef struct
{
  SKeyVal4 data_5;
} SPersRecord4byte;

#  define Rte_TypeDef_SPersRecord8byte
typedef struct
{
  SKeyVal8 data_2;
} SPersRecord8byte;

#  define Rte_TypeDef_SPhoneData
typedef struct
{
  UInt8 muteStatus;
  EPhoneStatus phoneStatus;
  data_u8_36 callerName;
  EStringEncoding callerNameEncodingType;
  data_u8_25 callerNumber;
  UInt16 callDuration;
  EPhoneCmd callCmd;
} SPhoneData;

#  define Rte_TypeDef_SRTC
typedef struct
{
  SDateTime dateTime;
} SRTC;

#  define Rte_TypeDef_SRTT_Icon
typedef struct
{
  data_u8_6 icon;
} SRTT_Icon;

#  define Rte_TypeDef_SRTT_Status
typedef struct
{
  data_u8_32 mask;
} SRTT_Status;

#  define Rte_TypeDef_SSDARSData
typedef struct
{
  UInt16 channelNumber;
  data_u8_130 title;
  EStringEncoding titleType;
  UInt8 valid;
} SSDARSData;

#  define Rte_TypeDef_SSDMExt
typedef struct
{
  SSdmArray data_15;
} SSDMExt;

#  define Rte_TypeDef_SSlowGuageInfo
typedef struct
{
  SGaugeInfo gaugeInfo;
} SSlowGuageInfo;

#  define Rte_TypeDef_STT_Status
typedef struct
{
  data_u8_12 mask;
} STT_Status;

#  define Rte_TypeDef_STT_status
typedef struct
{
  data_u8_15 TTStsMsg;
} STT_status;

#  define Rte_TypeDef_STrafficSignRecognition
typedef struct
{
  UInt8 id;
  UInt8 speedLimitValue;
  UInt8 type;
  UInt8 annex;
  UInt8 region;
  UInt8 color;
  data_u8_2 dynData;
} STrafficSignRecognition;

#  define Rte_TypeDef_STrailerInfo
typedef struct
{
  UInt8 status;
  UInt8 backupAssist;
  UInt8 reverseGuidance;
  UInt8 blindSpot;
  data_u8_8 accumulatedDistanceStr;
  data_u8_6 fuleEconomyStr;
  data_u8_32 trailerName;
} STrailerInfo;

#  define Rte_TypeDef_SUdsServiceReqIndication
typedef struct
{
  UInt8 serviceId;
  UInt8 requestType;
  UInt16 clientAddress;
  UInt16 dataLen;
  data_u8_7168 data;
} SUdsServiceReqIndication;

#  define Rte_TypeDef_SUdsServiceResponseTransmitRequest
typedef struct
{
  UInt8 serviceId;
  UInt8 responseType;
  UInt16 clientAddress;
  UInt16 dataLen;
  data_u8_7168 data;
} SUdsServiceResponseTransmitRequest;

#  define Rte_TypeDef_SWarningDisplay
typedef struct
{
  UInt8 show;
  UInt16 warningId;
  data_u8_4 dynData;
} SWarningDisplay;

#  define Rte_TypeDef_SWarningExtDisplay
typedef struct
{
  UInt8 show;
  UInt16 warningId;
  data_u8_70 dynData;
} SWarningExtDisplay;

#  define Rte_TypeDef_SWarningsTPMSData
typedef struct
{
  data_u8_22 warningsTPMSData;
} SWarningsTPMSData;

#  define Rte_TypeDef_SWelcomeScreens
typedef struct
{
  data_u8_2 DynData;
} SWelcomeScreens;

#  define Rte_TypeDef_T_NVM_MANUFACT
typedef struct
{
  t_uint8_x_16 serial_number;
  UInt32 part_number_prefix;
  UInt32 part_number_base;
  UInt16 part_number_suffix;
  UInt16 nvm_unused7;
  UInt8 eol_tester_number;
  UInt8 eol_test_counts;
  UInt8 pwb_tester_number;
  UInt8 pwb_test_counts;
  UInt16 board_level_date_code;
  UInt16 pre_burnin_date_code;
  UInt16 module_date_code;
  UInt16 trouble_shooter_date_code;
  UInt16 nvm_unused1;
  UInt8 nvm_unused2;
  UInt8 nvm_unused3;
  UInt8 nvm_unused4;
  UInt8 nvm_unused5;
  UInt8 pwb_start_code;
  UInt8 start_code;
} T_NVM_MANUFACT;

#  define Rte_TypeDef_T_NVM_PEO
typedef struct
{
  UInt8 nvm_checksum_end_address;
  UInt16 flash_btl_hw_compat_level;
  UInt16 flash_btl_nvm_compat_level;
  UInt16 nvm_checksum;
  UInt8 rom_major;
  UInt8 rom_minor;
  UInt8 nvm_revision_level;
  UInt8 nvm_month;
  UInt8 nvm_day;
  UInt8 nvm_year;
  t_uint32_x_2 nvm_unused_32;
  t_uint16_x_2 nvm_unused_16;
  t_uint8_x_4 nvm_unused_8;
} T_NVM_PEO;

#  define Rte_TypeDef_WdgM_ModeType
typedef UInt8 WdgM_ModeType;

#  define Rte_TypeDef_t_uint16_x_18x6
typedef t_uint16_x_6 t_uint16_x_18x6[18];

#  define Rte_TypeDef_t_uint8_x_18x5
typedef t_uint8_x_5 t_uint8_x_18x5[18];

#  define Rte_TypeDef_teChecksumStatus
typedef uint8 teChecksumStatus;

#  define Rte_TypeDef_teDTC_Master_List
typedef uint8 teDTC_Master_List;

#  define Rte_TypeDef_teMonitorList
typedef uint8 teMonitorList;

#  define Rte_TypeDef_SConfigRecord
typedef struct
{
  SKeyVal2 data;
} SConfigRecord;

#  define Rte_TypeDef_SConfigRecordExt
typedef struct
{
  SKeyVal2_50 data_50;
} SConfigRecordExt;

# endif


/**********************************************************************************************************************
 * Constant value definitions
 *********************************************************************************************************************/

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Hmi_AdapterAD2_Surr_Veh_AlphaValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Hmi_AdapterAD2_Surr_Veh_ColorValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Hmi_AdapterAD2_Surr_Veh_RNDR_StsValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Hmi_AdapterAD2_Surr_Veh_X_PosValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Hmi_AdapterAD2_Surr_Veh_Y_PosValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Mdl_AD2_3DAD2_Surr_Veh_AlphaValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Mdl_AD2_3DAD2_Surr_Veh_ColorValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Mdl_AD2_3DAD2_Surr_Veh_RNDR_StsValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Mdl_AD2_3DAD2_Surr_Veh_X_PosValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehInfo, RTE_CONST) Rte_Mdl_AD2_3DAD2_Surr_Veh_Y_PosValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehSts, RTE_CONST) Rte_Hmi_AdapterAD2_Surr_Veh_StatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ad2SurrVehSts, RTE_CONST) Rte_Mdl_AD2_3DAD2_Surr_Veh_StatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(BaseVoltageT, RTE_CONST) Rte_Mdl_SigmaAdapterBaseVoltageDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(BaseVoltageT, RTE_CONST) Rte_Mdl_SigmaBaseVoltageDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CutOffMaskT, RTE_CONST) Rte_Mdl_SigmaAdapterCutOffMaskDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CutOffMaskT, RTE_CONST) Rte_Mdl_SigmaCutOffMaskDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DIAG_DID_100_Data_ref, RTE_CONST) Rte_Mdl_SafetyAdapterDiagDID_100DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DTCStatusArrayT, RTE_CONST) Rte_CFotaCddAllDTCStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DTCStatusArrayT, RTE_CONST) Rte_Dem_AppAllDTCStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DTCStatusArrayT, RTE_CONST) Rte_Hmi_AdapterAllDTCStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DTCStatusArrayT, RTE_CONST) Rte_Mdl_DTCAllDTCStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DistanceUnitT, RTE_CONST) Rte_Mdl_SigmaAdapterDistanceUnitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DistanceUnitT, RTE_CONST) Rte_Mdl_SigmaDistanceUnitDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ECUVoltageT, RTE_CONST) Rte_Mdl_SigmaAdapterECUVoltageDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ECUVoltageT, RTE_CONST) Rte_Mdl_SigmaECUVoltageDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ETMStringT, RTE_CONST) Rte_Hmi_AdapterHardWareCodeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ETMStringT, RTE_CONST) Rte_Hmi_AdapterPCBCodeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ETMStringT, RTE_CONST) Rte_Hmi_AdapterSoftwareVersionValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ETMStringT, RTE_CONST) Rte_Hmi_AdapterSparePartNoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ETMStringT, RTE_CONST) Rte_MDL_ConfigHardWareCodeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ETMStringT, RTE_CONST) Rte_MDL_ConfigPCBCodeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ETMStringT, RTE_CONST) Rte_MDL_ConfigSoftwareVersionValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ETMStringT, RTE_CONST) Rte_MDL_ConfigSparePartNoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ExtTempT, RTE_CONST) Rte_Mdl_SigmaAdapterExtTempDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ExtTempT, RTE_CONST) Rte_Mdl_SigmaExtTempDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(GadeT, RTE_CONST) Rte_Mdl_SigmaAdapterGadeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(GadeT, RTE_CONST) Rte_Mdl_SigmaGadeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(HFE2MinsValueType, RTE_CONST) Rte_Hmi_AdapterHFE2MinsValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(HFE2MinsValueType, RTE_CONST) Rte_Mdl_TripCompEVHFE2MinsValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(HFEValueType, RTE_CONST) Rte_Hmi_AdapterHFEValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(HFEValueType, RTE_CONST) Rte_Mdl_TripCompHFEValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(HandBrakeT, RTE_CONST) Rte_Mdl_SigmaAdapterHandBrakeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(HandBrakeT, RTE_CONST) Rte_Mdl_SigmaHandBrakeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IGNStatusT, RTE_CONST) Rte_Mdl_SigmaAdapterIGNStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IGNStatusT, RTE_CONST) Rte_Mdl_SigmaIGNStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IndicatorOutputType, RTE_CONST) Rte_Ctrl_indicatorIndicatorStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IndicatorOutputType, RTE_CONST) Rte_Hmi_AdapterIndicatorStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(LaneMarker, RTE_CONST) Rte_Hmi_AdapterLaneMarkerStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(LaneMarker, RTE_CONST) Rte_Mdl_AD2_3DLaneMarkerStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MainMenuArrayT, RTE_CONST) Rte_CBswc_EthernetCurrentMainMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MainMenuArrayT, RTE_CONST) Rte_Hmi_AdapterCurrentMainMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MainMenuArrayT, RTE_CONST) Rte_Mdl_CustMenuSettingsCurrentMainMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MainMenuArrayT, RTE_CONST) Rte_Mdl_ICCCurrentMainMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MainMenuArrayT, RTE_CONST) Rte_Mdl_NaviMcanCurrentMainMenuStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MasterWakeupCommandT, RTE_CONST) Rte_Mdl_SigmaAdapterMasterWakeupCommandDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MasterWakeupCommandT, RTE_CONST) Rte_Mdl_SigmaMasterWakeupCommandDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SigmaFrameT, RTE_CONST) Rte_Mdl_SigmaAdapterSigmaFrameDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SigmaFrameT, RTE_CONST) Rte_Mdl_SigmaSigmaFrameDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SlaveRefuseToSleepT, RTE_CONST) Rte_Mdl_SigmaAdapterSlaveRefuseToSleepDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SlaveRefuseToSleepT, RTE_CONST) Rte_Mdl_SigmaSlaveRefuseToSleepDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TTBlinkArray, RTE_CONST) Rte_Ctrl_indicatorTTBlinkStatusArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TTBlinkArray, RTE_CONST) Rte_Ctrl_telltaleTTBlinkStatusArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_Ctrl_telltaleTelltaleFunctionalOpStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_Ctrl_telltaleTelltaleOpArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_Dcm_AppTelltaleFunctionalOpStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_Hmi_AdapterTelltaleFunctionalOpStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_Hmi_AdapterTelltaleOpArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_Mdl_IpclSafeCommunicationTelltaleOpArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_Mdl_SafetyAdapterTelltaleOpArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_View_telltaleTelltaleOpArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_AUDIO_SOURCE_AVAILABLE_T, RTE_CONST) Rte_Hmi_AdapterCurrentAudioSrcAvailValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_AUDIO_SOURCE_AVAILABLE_T, RTE_CONST) Rte_Mdl_AudioMcanCurrentAudioSrcAvailValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_LANE_ARROW_TYPE_T, RTE_CONST) Rte_Hmi_AdapterNaviIntsecFourLaneArrowValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_LANE_ARROW_TYPE_T, RTE_CONST) Rte_Hmi_AdapterNaviIntsecOneLaneArrowValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_LANE_ARROW_TYPE_T, RTE_CONST) Rte_Hmi_AdapterNaviIntsecThreeLaneArrowValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_LANE_ARROW_TYPE_T, RTE_CONST) Rte_Hmi_AdapterNaviIntsecTwoLaneArrowValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_LANE_ARROW_TYPE_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntsecFourLaneArrowValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_LANE_ARROW_TYPE_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntsecOneLaneArrowValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_LANE_ARROW_TYPE_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntsecThreeLaneArrowValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_LANE_ARROW_TYPE_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntsecTwoLaneArrowValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextAudioWarningValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextDiscArtistValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextDiscGroupValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextDiscTrackValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextHDRadioArtistValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextHDRadioBroadCastValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextHDRadioCategoryValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextHDRadioSongTitleValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextInternetAudioArtistValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextInternetAudioGroupValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextInternetAudioSourceValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextInternetAudioTrackValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextRadioBroadCastValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextRadioCategoryValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterAudioTextTVBroadCastValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterCurrentStreetNameValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterSMSRxdTextValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterStreetNameIntersection_1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterStreetNameIntersection_2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterStreetNameIntersection_3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterStreetNameIntersection_4Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Hmi_AdapterTelRxdTextValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_MDL_PhoneMcanSMSRxdTextValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_MDL_PhoneMcanTelRxdTextValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextAudioWarningValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextDiscArtistValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextDiscGroupValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextDiscTrackValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextHDRadioArtistValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextHDRadioBroadCastValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextHDRadioCategoryValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextHDRadioSongTitleValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextInternetAudioArtistValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextInternetAudioGroupValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextInternetAudioSourceValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextInternetAudioTrackValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextRadioBroadCastValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextRadioCategoryValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_AudioMcanAudioTextTVBroadCastValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_NaviMcanCurrentStreetNameValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_NaviMcanStreetNameIntersection_1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_NaviMcanStreetNameIntersection_2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_NaviMcanStreetNameIntersection_3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEXT_BUFFER_T, RTE_CONST) Rte_Mdl_NaviMcanStreetNameIntersection_4Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviIntSecFourArrowGuideInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviIntSecOneArrowGuideInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviIntSecThreeArrowGuideInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviIntSecTwoArrowGuideInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntSecFourArrowGuideInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntSecOneArrowGuideInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntSecThreeArrowGuideInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntSecTwoArrowGuideInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehiclePosType, RTE_CONST) Rte_Hmi_AdapterAd1l3VehiclePos_XValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehiclePosType, RTE_CONST) Rte_Hmi_AdapterAd1l3VehiclePos_YValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehiclePosType, RTE_CONST) Rte_Mdl_AD2SafetyAd1l3VehiclePos_XValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehiclePosType, RTE_CONST) Rte_Mdl_AD2SafetyAd1l3VehiclePos_YValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehiclePosType, RTE_CONST) Rte_Mdl_IpclSafeCommunicationAd1l3VehiclePos_XValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehiclePosType, RTE_CONST) Rte_Mdl_IpclSafeCommunicationAd1l3VehiclePos_YValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehicleSpeedT, RTE_CONST) Rte_Mdl_SigmaAdapterVehicleSpeedDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehicleSpeedT, RTE_CONST) Rte_Mdl_SigmaVehicleSpeedDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehicleStsType, RTE_CONST) Rte_Hmi_AdapterAd1l3VehicleStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehicleStsType, RTE_CONST) Rte_Mdl_AD2SafetyAd1l3VehicleStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(VehicleStsType, RTE_CONST) Rte_Mdl_IpclSafeCommunicationAd1l3VehicleStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Visteon_Product_Config_Data_ref, RTE_CONST) Rte_Mdl_SafetyAdapterVisteon_Product_Config_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(WICodeT, RTE_CONST) Rte_Hmi_AdapterWICodeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(WICodeT, RTE_CONST) Rte_MDL_ConfigWICodeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_10; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_11; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_12; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_13; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_14; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_15; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_16; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_17; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_18; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_19; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_3; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_4; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_5; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_6; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_7; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_8; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_12, RTE_CONST) Rte_C_t_uint16_x_12_9; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_3; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_4; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_5; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_6; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_7; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_15, RTE_CONST) Rte_C_t_uint16_x_15_8; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_3; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_4; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_5; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_6; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_7; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_8; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_22, RTE_CONST) Rte_C_t_uint16_x_22_9; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint16_x_3, RTE_CONST) Rte_C_t_uint16_x_3_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint32_x_4, RTE_CONST) Rte_C_t_uint32_x_4_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint32_x_5, RTE_CONST) Rte_C_t_uint32_x_5_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_10, RTE_CONST) Rte_C_t_uint8_x_10_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_10, RTE_CONST) Rte_C_t_uint8_x_10_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_10, RTE_CONST) Rte_C_t_uint8_x_10_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_100, RTE_CONST) Rte_C_t_uint8_x_100_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_128, RTE_CONST) Rte_C_t_uint8_x_128_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_16, RTE_CONST) Rte_C_t_uint8_x_16_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_16, RTE_CONST) Rte_C_t_uint8_x_16_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_16, RTE_CONST) Rte_C_t_uint8_x_16_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_16, RTE_CONST) Rte_C_t_uint8_x_16_3; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_160, RTE_CONST) Rte_C_t_uint8_x_160_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_17, RTE_CONST) Rte_C_t_uint8_x_17_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_17, RTE_CONST) Rte_C_t_uint8_x_17_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_18, RTE_CONST) Rte_C_t_uint8_x_18_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_2, RTE_CONST) Rte_C_t_uint8_x_2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_2, RTE_CONST) Rte_C_t_uint8_x_2_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_20, RTE_CONST) Rte_C_t_uint8_x_20_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_20, RTE_CONST) Rte_C_t_uint8_x_20_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_20, RTE_CONST) Rte_C_t_uint8_x_20_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_256, RTE_CONST) Rte_C_t_uint8_x_256_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_3, RTE_CONST) Rte_C_t_uint8_x_3_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_3, RTE_CONST) Rte_C_t_uint8_x_3_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_30, RTE_CONST) Rte_C_t_uint8_x_30_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_32, RTE_CONST) Rte_C_t_uint8_x_32_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_4, RTE_CONST) Rte_C_t_uint8_x_4_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_4, RTE_CONST) Rte_C_t_uint8_x_4_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_4, RTE_CONST) Rte_C_t_uint8_x_4_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_5, RTE_CONST) Rte_C_t_uint8_x_5_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_5, RTE_CONST) Rte_C_t_uint8_x_5_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_5, RTE_CONST) Rte_C_t_uint8_x_5_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_5, RTE_CONST) Rte_C_t_uint8_x_5_3; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_6, RTE_CONST) Rte_C_t_uint8_x_6_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_6, RTE_CONST) Rte_C_t_uint8_x_6_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_63, RTE_CONST) Rte_C_t_uint8_x_63_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_64, RTE_CONST) Rte_C_t_uint8_x_64_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(t_uint8_x_8, RTE_CONST) Rte_C_t_uint8_x_8_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(AD1L3StrgIconS, RTE_CONST) Rte_Hmi_AdapterAD1L3StrgIconValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(AD1L3StrgIconS, RTE_CONST) Rte_Mdl_AD2SafetyAD1L3StrgIconValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(AD1L3StrgIconS, RTE_CONST) Rte_Mdl_IpclSafeCommunicationAD1L3StrgIconValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(AccelGuideValueS, RTE_CONST) Rte_Hmi_AdapterCurrentAccelGuideValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(AccelGuideValueS, RTE_CONST) Rte_Mdl_AccelEcoCurrentAccelGuideValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(AliveCntCrcT, RTE_CONST) Rte_Mdl_CrcCddAliveCntCrcValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(AliveCntCrcT, RTE_CONST) Rte_Mdl_DTCAliveCntCrcValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(BatterModeS, RTE_CONST) Rte_Hmi_AdapterBatteryModeAvailAndStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(BatterModeS, RTE_CONST) Rte_Mdl_BatModeBatteryModeAvailAndStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(BatterySOCS, RTE_CONST) Rte_Hmi_AdapterBatterySOCDisplayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(BatterySOCS, RTE_CONST) Rte_Mdl_SOCBatterySOCDisplayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ButtonAndEvents, RTE_CONST) Rte_Hmi_AdapterSettingDummyPortValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ButtonAndEvents, RTE_CONST) Rte_Mdl_ButtonSettingDummyPortValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ChargeGaugeDataS, RTE_CONST) Rte_Hmi_AdapterTotalChargeDisplayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ChargeGaugeDataS, RTE_CONST) Rte_Mdl_PowerGaugeTotalChargeDisplayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ClockType, RTE_CONST) Rte_Hmi_AdapterCurrentTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ClockType, RTE_CONST) Rte_Mdl_ClockSettingsCurrentTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ClockType, RTE_CONST) Rte_Mdl_SigmaAdapterSigmaTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ClockType, RTE_CONST) Rte_Mdl_SigmaCurrentTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ClockType, RTE_CONST) Rte_Mdl_SigmaSigmaTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CombiSWConfigS, RTE_CONST) Rte_MDL_ConfigCombiSWConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CombiSWConfigS, RTE_CONST) Rte_Mdl_CombiSwitchCombiSWConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CombiSWOutputS, RTE_CONST) Rte_Hmi_AdapterCombiSwPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(CombiSWOutputS, RTE_CONST) Rte_Mdl_CombiSwitchCombiSwPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DiagGSIPayloadS, RTE_CONST) Rte_Dcm_AppDiagMdlGsiGearNumberValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DiagGSIPayloadS, RTE_CONST) Rte_Mdl_gearshiftDiagMdlGsiGearNumberValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DialConfigT, RTE_CONST) Rte_Hmi_AdapterDialCurrentConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DialConfigT, RTE_CONST) Rte_MDL_ConfigDialCurrentConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DialConfigT, RTE_CONST) Rte_Mdl_PowerGaugeDialCurrentConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DialConfigT, RTE_CONST) Rte_Mdl_SOCDialCurrentConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DoorAjarPayloadS, RTE_CONST) Rte_Dcm_AppDoorAjarWarningPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DoorAjarPayloadS, RTE_CONST) Rte_Hmi_AdapterDoorAjarWarningPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(DoorAjarPayloadS, RTE_CONST) Rte_Mdl_DoorAjarDoorAjarWarningPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ECUVersionDetatilS, RTE_CONST) Rte_CMeetCddECUVersionDetatilValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ECUVersionDetatilS, RTE_CONST) Rte_Dcm_AppECUVersionDetatilValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ECUVersionDetatilS, RTE_CONST) Rte_MDL_ConfigECUVersionDetatilValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ECUVersionDetatilS, RTE_CONST) Rte_Mdl_AudioMcanECUVersionDetatilValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ECUVersionDetatilS, RTE_CONST) Rte_Mdl_NaviMcanECUVersionDetatilValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ECUVersionDetatilS, RTE_CONST) Rte_Mdl_StgWheelMcanECUVersionDetatilValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(EnergyFlowStatusS, RTE_CONST) Rte_Hmi_AdapterCurrentEnergyFlowDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(EnergyFlowStatusS, RTE_CONST) Rte_Mdl_EnergyFlowCurrentEnergyFlowDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(GSIPayloadS, RTE_CONST) Rte_Dcm_AppGSICurrentPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(GSIPayloadS, RTE_CONST) Rte_Hmi_AdapterGSICurrentPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(GSIPayloadS, RTE_CONST) Rte_Mdl_IpclSafeCommunicationGSICurrentPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(GSIPayloadS, RTE_CONST) Rte_Mdl_gearshiftGSICurrentPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(GSIPayloadS, RTE_CONST) Rte_Mdl_opng_movieGSICurrentPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IFEConfigT, RTE_CONST) Rte_Hmi_AdapterIFECurrentConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IFEConfigT, RTE_CONST) Rte_MDL_ConfigIFECurrentConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IFEConfigT, RTE_CONST) Rte_Mdl_PowerGaugeIFECurrentConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IFEConfigT, RTE_CONST) Rte_Mdl_SOCIFECurrentConfigValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSAccelPedalHighS, RTE_CONST) Rte_Dcm_AppAccelPedalHighPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSAccelPedalHighS, RTE_CONST) Rte_Hmi_AdapterAccelPedalHighPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSAccelPedalHighS, RTE_CONST) Rte_Mdl_ITSAccelPedalHighPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSBadWeatherS, RTE_CONST) Rte_Dcm_AppBadWeatherPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSBadWeatherS, RTE_CONST) Rte_Hmi_AdapterBadWeatherPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSBadWeatherS, RTE_CONST) Rte_Mdl_ITSBadWeatherPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSCameraFaultS, RTE_CONST) Rte_Dcm_AppCameraFaultPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSCameraFaultS, RTE_CONST) Rte_Hmi_AdapterCameraFaultPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSCameraFaultS, RTE_CONST) Rte_Mdl_ITSCameraFaultPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSCleanUpFrontCameraS, RTE_CONST) Rte_Dcm_AppCleanFrontViewCameraPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSCleanUpFrontCameraS, RTE_CONST) Rte_Hmi_AdapterCleanFrontViewCameraPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSCleanUpFrontCameraS, RTE_CONST) Rte_Mdl_ITSCleanFrontViewCameraPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSFEBSensorBlockedS, RTE_CONST) Rte_Dcm_AppFEBSensorBlockedValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSFEBSensorBlockedS, RTE_CONST) Rte_Hmi_AdapterFEBSensorBlockedValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSFEBSensorBlockedS, RTE_CONST) Rte_Mdl_ITSFEBSensorBlockedValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSFrontRadarBlockedS, RTE_CONST) Rte_Dcm_AppFrontRadarBlockedPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSFrontRadarBlockedS, RTE_CONST) Rte_Hmi_AdapterFrontRadarBlockedPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSFrontRadarBlockedS, RTE_CONST) Rte_Mdl_ITSFrontRadarBlockedPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSHandleReleaseS, RTE_CONST) Rte_Dcm_AppHandleReleaseValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSHandleReleaseS, RTE_CONST) Rte_Hmi_AdapterHandleReleaseValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSHandleReleaseS, RTE_CONST) Rte_Mdl_ITSHandleReleaseValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSNotOperateS, RTE_CONST) Rte_Dcm_AppNotOperatePayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSNotOperateS, RTE_CONST) Rte_Hmi_AdapterNotOperatePayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSNotOperateS, RTE_CONST) Rte_Mdl_ITSNotOperatePayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSideRadarBlockedS, RTE_CONST) Rte_Dcm_AppSideRadarBlockedPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSideRadarBlockedS, RTE_CONST) Rte_Hmi_AdapterSideRadarBlockedPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSideRadarBlockedS, RTE_CONST) Rte_Mdl_ITSSideRadarBlockedPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSlipperyRoadS, RTE_CONST) Rte_Dcm_AppSlipperyRoadPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSlipperyRoadS, RTE_CONST) Rte_Hmi_AdapterSlipperyRoadPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSlipperyRoadS, RTE_CONST) Rte_Mdl_ITSSlipperyRoadPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSystemFaultS, RTE_CONST) Rte_Dcm_AppSystemFaultWarningPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSystemFaultS, RTE_CONST) Rte_Hmi_AdapterSystemFaultWarningPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSSystemFaultS, RTE_CONST) Rte_Mdl_ITSSystemFaultWarningPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSVDCOffS, RTE_CONST) Rte_Dcm_AppVdcOffPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSVDCOffS, RTE_CONST) Rte_Hmi_AdapterVdcOffPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ITSVDCOffS, RTE_CONST) Rte_Mdl_ITSVdcOffPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IdleStopCLTTimeS, RTE_CONST) Rte_Hmi_AdapterCumulativeIdleStopTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IdleStopCLTTimeS, RTE_CONST) Rte_Mdl_IdleStopSettingCumulativeIdleStopTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IdleStopTimeS, RTE_CONST) Rte_Hmi_AdapterTripIdleStopTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IdleStopTimeS, RTE_CONST) Rte_Mdl_IdleStopSettingTripIdleStopTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IdleStopVLTTimeS, RTE_CONST) Rte_Hmi_AdapterVehicleLifeTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IdleStopVLTTimeS, RTE_CONST) Rte_Mdl_IdleStopSettingVehicleLifeTimeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IllumCurSteps, RTE_CONST) Rte_Mdl_DimmingCurrentIllumStepValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IllumCurSteps, RTE_CONST) Rte_Mdl_Ikey_LinkCurrentIllumStepValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IllumCurSteps, RTE_CONST) Rte_Mdl_UsrLoginCurrentIllumStepValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MCANFaultT, RTE_CONST) Rte_CMcan_cddCommunicationManagementReceptionValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MCANFaultT, RTE_CONST) Rte_CMcan_cddCommunicationManagementTransmissionValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MCANFaultT, RTE_CONST) Rte_Mdl_DTCCommunicationManagementReceptionValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MCANFaultT, RTE_CONST) Rte_Mdl_DTCCommunicationManagementTransmissionValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MCAN_TIME_INFO, RTE_CONST) Rte_Mdl_ClockSettingsCurrentMcanTimeValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(MCAN_TIME_INFO, RTE_CONST) Rte_Mdl_StgWheelMcanCurrentMcanTimeValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_ApplicationRandomNumber, RTE_CONST) Rte_C_NV_Data_ApplicationRandomNumber_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_CustomerHWReference, RTE_CONST) Rte_C_NV_Data_CustomerHWReference_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_CustomerReference, RTE_CONST) Rte_C_NV_Data_CustomerReference_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_CustomerReference2, RTE_CONST) Rte_C_NV_Data_CustomerReference2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID100, RTE_CONST) Rte_C_NV_Data_DiagDID100_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID200, RTE_CONST) Rte_C_NV_Data_DiagDID200_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID300, RTE_CONST) Rte_C_NV_Data_DiagDID300_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID310, RTE_CONST) Rte_C_NV_Data_DiagDID310_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID400, RTE_CONST) Rte_C_NV_Data_DiagDID400_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID410, RTE_CONST) Rte_C_NV_Data_DiagDID410_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID420, RTE_CONST) Rte_C_NV_Data_DiagDID420_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID430, RTE_CONST) Rte_C_NV_Data_DiagDID430_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID440, RTE_CONST) Rte_C_NV_Data_DiagDID440_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID450, RTE_CONST) Rte_C_NV_Data_DiagDID450_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID500, RTE_CONST) Rte_C_NV_Data_DiagDID500_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDID900, RTE_CONST) Rte_C_NV_Data_DiagDID900_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDIDF190, RTE_CONST) Rte_C_NV_Data_DiagDIDF190_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDIDF1A2, RTE_CONST) Rte_C_NV_Data_DiagDIDF1A2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_DiagDIDFE11, RTE_CONST) Rte_C_NV_Data_DiagDIDFE11_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FBLValidDTCState, RTE_CONST) Rte_C_NV_Data_FBLValidDTCState_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FBLValidDTCState_1, RTE_CONST) Rte_C_NV_Data_FBLValidDTCState_1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FBL_NVM, RTE_CONST) Rte_C_NV_Data_FBL_NVM_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FOTA_NVM, RTE_CONST) Rte_C_NV_Data_FOTA_NVM_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FOTA_NVM_DIGHRNIG, RTE_CONST) Rte_C_NV_Data_FOTA_NVM_DIGHRNIG_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FeatureConfigCalib, RTE_CONST) Rte_C_NV_Data_FeatureConfigCalib_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FeaturesConst, RTE_CONST) Rte_C_NV_Data_FeaturesConst_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FeaturesConst1, RTE_CONST) Rte_C_NV_Data_FeaturesConst1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FeaturesConst2, RTE_CONST) Rte_C_NV_Data_FeaturesConst2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FeaturesConst3, RTE_CONST) Rte_C_NV_Data_FeaturesConst3_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FeaturesConst4, RTE_CONST) Rte_C_NV_Data_FeaturesConst4_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FeaturesConst5, RTE_CONST) Rte_C_NV_Data_FeaturesConst5_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FeaturesConst6, RTE_CONST) Rte_C_NV_Data_FeaturesConst6_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Fingerprint, RTE_CONST) Rte_C_NV_Data_Fingerprint_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FotaUpdateStatus, RTE_CONST) Rte_C_NV_Data_FotaUpdateStatus_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FotaUpdateStatus_1, RTE_CONST) Rte_C_NV_Data_FotaUpdateStatus_1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_FuelCalcCalib, RTE_CONST) Rte_C_NV_Data_FuelCalcCalib_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_GUST_USER_LOGIN, RTE_CONST) Rte_C_NV_Data_GUST_USER_LOGIN_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_GaugeEctCalib, RTE_CONST) Rte_C_NV_Data_GaugeEctCalib_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_GaugeFuelCalib, RTE_CONST) Rte_C_NV_Data_GaugeFuelCalib_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_GaugeRPMCalib, RTE_CONST) Rte_C_NV_Data_GaugeRPMCalib_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_GaugeSpdCalib, RTE_CONST) Rte_C_NV_Data_GaugeSpdCalib_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_IDLE_STOP, RTE_CONST) Rte_C_NV_Data_IDLE_STOP_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_IKEY_BLK, RTE_CONST) Rte_C_NV_Data_IKEY_BLK_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_IllumPWMCalib, RTE_CONST) Rte_C_NV_Data_IllumPWMCalib_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_LoaderModeDetected, RTE_CONST) Rte_C_NV_Data_LoaderModeDetected_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_MFG_DID_PRODUCT, RTE_CONST) Rte_C_NV_Data_MFG_DID_PRODUCT_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_MagicFlag, RTE_CONST) Rte_C_NV_Data_MagicFlag_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_NVM_HM_FaultCounters, RTE_CONST) Rte_C_NV_Data_NVM_HM_FaultCounters_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_NvM_Revision_Value, RTE_CONST) Rte_C_NV_Data_NvM_Revision_Value_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_NvM_Version_Value, RTE_CONST) Rte_C_NV_Data_NvM_Version_Value_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Odometer_BLK1, RTE_CONST) Rte_C_NV_Data_Odometer_BLK1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Odometer_BLK2, RTE_CONST) Rte_C_NV_Data_Odometer_BLK2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Odometer_BLK3, RTE_CONST) Rte_C_NV_Data_Odometer_BLK3_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Odometer_BLK4, RTE_CONST) Rte_C_NV_Data_Odometer_BLK4_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Odometer_BLK5, RTE_CONST) Rte_C_NV_Data_Odometer_BLK5_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_PCBSerialNumber, RTE_CONST) Rte_C_NV_Data_PCBSerialNumber_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Reserved_Health_Management, RTE_CONST) Rte_C_NV_Data_Reserved_Health_Management_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_DTC_INDEX_BLK, RTE_CONST) Rte_C_NV_Data_SIGMA_DTC_INDEX_BLK_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK0, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK0_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK1, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK10, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK10_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK11, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK11_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK12, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK12_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK13, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK13_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK14, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK14_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK15, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK15_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK2, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK3, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK3_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK4, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK4_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK5, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK5_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK6, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK6_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK7, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK7_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK8, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK8_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_SSD_BLK9, RTE_CONST) Rte_C_NV_Data_SIGMA_SSD_BLK9_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK0, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK0_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK1, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK10, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK10_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK11, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK11_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK12, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK12_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK13, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK13_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK14, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK14_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK15, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK15_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK2, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK3, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK3_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK4, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK4_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK5, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK5_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK6, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK6_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK7, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK7_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK8, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK8_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_SIGMA_VTD_BLK9, RTE_CONST) Rte_C_NV_Data_SIGMA_VTD_BLK9_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Signature, RTE_CONST) Rte_C_NV_Data_Signature_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_Signature_1, RTE_CONST) Rte_C_NV_Data_Signature_1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_USER_LOGIN, RTE_CONST) Rte_C_NV_Data_USER_LOGIN_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_VehicleStateDetected, RTE_CONST) Rte_C_NV_Data_VehicleStateDetected_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(PowerGaugeDataS, RTE_CONST) Rte_Hmi_AdapterTotalPowerDisplayTypeAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(PowerGaugeDataS, RTE_CONST) Rte_Mdl_PowerGaugeTotalPowerDisplayTypeAValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(PowerGaugeTypeBDataS, RTE_CONST) Rte_Hmi_AdapterTotalPowerDisplayTypeBValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(PowerGaugeTypeBDataS, RTE_CONST) Rte_Mdl_PowerGaugeTotalPowerDisplayTypeBValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(RSBWarningPayloadS, RTE_CONST) Rte_Hmi_AdapterRSBWarningPayloadStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(RSBWarningPayloadS, RTE_CONST) Rte_Mdl_DoorAjarRSBWarningPayloadStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(RSBWarningPayloadS, RTE_CONST) Rte_Mdl_RearSeatBeltRSBWarningPayloadStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SAD2MenuPayloadData, RTE_CONST) Rte_Hmi_AdapterAD2MenuPayloadDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SAD2MenuPayloadData, RTE_CONST) Rte_UclProxyCddAD2MenuPayloadDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SAccelGuideValue, RTE_CONST) Rte_Hmi_AdapterAccelGuideValueDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SAccelGuideValue, RTE_CONST) Rte_UclProxyCddAccelGuideValueDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SCurrentTimeDisplay, RTE_CONST) Rte_Hmi_AdapterCurrentTimeDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SCurrentTimeDisplay, RTE_CONST) Rte_UclProxyCddCurrentTimeDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDimmingData, RTE_CONST) Rte_UclProxyCddDimmingDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDimmingData, RTE_CONST) Rte_View_DimmingDimmingDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplayCurrentState, RTE_CONST) Rte_ModeMgrDisplayCurrentStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplayCurrentState, RTE_CONST) Rte_UclProxyCddDisplayCurrentStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplayGetState, RTE_CONST) Rte_UclProxyCddDisplayGetStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplaySetPower, RTE_CONST) Rte_ModeMgrDisplaySetPowerDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplaySetPower, RTE_CONST) Rte_UclProxyCddDisplaySetPowerDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDistanceToEmptyStatus, RTE_CONST) Rte_Hmi_AdapterDistanceToEmptyStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDistanceToEmptyStatus, RTE_CONST) Rte_UclProxyCddDistanceToEmptyStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDmnStatus, RTE_CONST) Rte_DmnMgrSDmnStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDmnStatus, RTE_CONST) Rte_ModeMgrSDmnStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEMSStatus, RTE_CONST) Rte_Hmi_AdapterEMSStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEMSStatus, RTE_CONST) Rte_UclProxyCddEMSStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEctData, RTE_CONST) Rte_Hmi_AdapterEctDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEctData, RTE_CONST) Rte_UclProxyCddEctDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaChangeRequest, RTE_CONST) Rte_CFotaCddFotaChangeRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaChangeRequest, RTE_CONST) Rte_UclProxyCddFotaChangeRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaCommandRequest, RTE_CONST) Rte_CFotaCddFotaCommandRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaCommandRequest, RTE_CONST) Rte_UclProxyCddFotaCommandRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaStateResponse, RTE_CONST) Rte_CFotaCddFotaStateResponseDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaStateResponse, RTE_CONST) Rte_UclProxyCddFotaStateResponseDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaVinRequest, RTE_CONST) Rte_CFotaCddFotaVinRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaVinRequest, RTE_CONST) Rte_UclProxyCddFotaVinRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaVinResponse, RTE_CONST) Rte_CFotaCddFotaVinResponseDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFotaVinResponse, RTE_CONST) Rte_UclProxyCddFotaVinResponseDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFuelData, RTE_CONST) Rte_Hmi_AdapterFuelDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFuelData, RTE_CONST) Rte_UclProxyCddFuelDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFuelEconomyData, RTE_CONST) Rte_Hmi_AdapterFuelEconomyDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFuelEconomyData, RTE_CONST) Rte_UclProxyCddFuelEconomyDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SGFXScreenID, RTE_CONST) Rte_Hmi_AdapterGFXScreenIDDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SGFXScreenID, RTE_CONST) Rte_UclProxyCddGFXScreenIDDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHMISleepStatus, RTE_CONST) Rte_Hmi_AdapterHMISleepStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHMISleepStatus, RTE_CONST) Rte_UclProxyCddHMISleepStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIdleStopData, RTE_CONST) Rte_Hmi_AdapterIdleStopDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIdleStopData, RTE_CONST) Rte_UclProxyCddIdleStopDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnStateStatus, RTE_CONST) Rte_Hmi_AdapterIgnStateStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIgnStateStatus, RTE_CONST) Rte_UclProxyCddIgnStateStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMenuPayloadData, RTE_CONST) Rte_Hmi_AdapterMenuPayloadDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SMenuPayloadData, RTE_CONST) Rte_UclProxyCddMenuPayloadDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SModuleConfigStatus, RTE_CONST) Rte_Hmi_AdapterModuleConfigStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SModuleConfigStatus, RTE_CONST) Rte_UclProxyCddModuleConfigStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOdometerStatus, RTE_CONST) Rte_Hmi_AdapterOdometerStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOdometerStatus, RTE_CONST) Rte_UclProxyCddOdometerStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOutsideAirTemperature, RTE_CONST) Rte_Hmi_AdapterOutsideAirTemperatureDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SOutsideAirTemperature, RTE_CONST) Rte_UclProxyCddOutsideAirTemperatureDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPopupStatusData, RTE_CONST) Rte_Hmi_AdapterPopupStatusDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPopupStatusData, RTE_CONST) Rte_UclProxyCddPopupStatusDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerData, RTE_CONST) Rte_Hmi_AdapterPowerDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerData, RTE_CONST) Rte_UclProxyCddPowerDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemState, RTE_CONST) Rte_DmnMgrPowerSystemStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemState, RTE_CONST) Rte_UclProxyCddPowerSystemStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemStateReqChange, RTE_CONST) Rte_DmnMgrPowerSystemStateReqChangeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemStateReqChange, RTE_CONST) Rte_UclProxyCddPowerSystemStateReqChangeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSpeedData, RTE_CONST) Rte_Hmi_AdapterSpeedDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSpeedData, RTE_CONST) Rte_UclProxyCddSpeedDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSwUpdateDataTransferReq, RTE_CONST) Rte_CFotaCddSwUpdateDataTransferReqDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSwUpdateDataTransferReq, RTE_CONST) Rte_UclProxyCddSwUpdateDataTransferReqDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSwUpdateDownloadSwPartReq, RTE_CONST) Rte_CFotaCddSwUpdateDownloadSwPartReqDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSwUpdateDownloadSwPartReq, RTE_CONST) Rte_UclProxyCddSwUpdateDownloadSwPartReqDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSwUpdateEraseSwPartReq, RTE_CONST) Rte_CFotaCddSwUpdateEraseSwPartReqDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSwUpdateEraseSwPartReq, RTE_CONST) Rte_UclProxyCddSwUpdateEraseSwPartReqDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSwUpdateUploadSwPartReq, RTE_CONST) Rte_CFotaCddSwUpdateUploadSwPartReqDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSwUpdateUploadSwPartReq, RTE_CONST) Rte_UclProxyCddSwUpdateUploadSwPartReqDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STTIndicatorStatus, RTE_CONST) Rte_Hmi_AdapterTTIndicatorStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STTIndicatorStatus, RTE_CONST) Rte_UclProxyCddTTIndicatorStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_statusVIP, RTE_CONST) Rte_Mdl_IpclSafeCommunicationTT_statusVIPDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_statusVIP, RTE_CONST) Rte_UclProxyCddTT_statusVIPDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STachoData, RTE_CONST) Rte_Hmi_AdapterTachoDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STachoData, RTE_CONST) Rte_UclProxyCddTachoDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripComputerData, RTE_CONST) Rte_Hmi_AdapterTripComputerDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STripComputerData, RTE_CONST) Rte_UclProxyCddTripComputerDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SVCRStatus, RTE_CONST) Rte_Hmi_AdapterVCRStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SVCRStatus, RTE_CONST) Rte_UclProxyCddVCRStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SVariantConfigData, RTE_CONST) Rte_Hmi_AdapterVariantConfigDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SVariantConfigData, RTE_CONST) Rte_UclProxyCddVariantConfigDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplayStatus, RTE_CONST) Rte_Hmi_AdapterWarningDisplayStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplayStatus, RTE_CONST) Rte_UclProxyCddWarningDisplayStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SigmaVSS_T, RTE_CONST) Rte_Mdl_SigmaAdapterSigmaVSSDDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SigmaVSS_T, RTE_CONST) Rte_Mdl_SigmaSigmaVSSDDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SonarPayloadS, RTE_CONST) Rte_Hmi_AdapterSonarWarningPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SonarPayloadS, RTE_CONST) Rte_Mdl_SonarSonarWarningPayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(StartUpInitT, RTE_CONST) Rte_Hmi_AdapterStartUpInitValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TPMSPayloadS, RTE_CONST) Rte_Dcm_AppTPMSPayloadValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TPMSPayloadS, RTE_CONST) Rte_Hmi_AdapterTPMSPayloadValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TPMSPayloadS, RTE_CONST) Rte_Mdl_TPMSTPMSPayloadValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TSRPayloadS, RTE_CONST) Rte_Hmi_AdapterTSRPayloadCurValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TSRPayloadS, RTE_CONST) Rte_Mdl_CustMenuSettingsTSRPayloadCurValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TSRPayloadS, RTE_CONST) Rte_Mdl_TSRTSRPayloadCurValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TelltaleResetDataS, RTE_CONST) Rte_Mdl_IpclSafeCommunicationTelltaleResetStsValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TelltaleResetDataS, RTE_CONST) Rte_Mdl_ResetReasonTelltaleResetStsValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TripTimeS, RTE_CONST) Rte_Hmi_AdapterTripTimeValue1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TripTimeS, RTE_CONST) Rte_Hmi_AdapterTripTimeValue2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TripTimeS, RTE_CONST) Rte_Hmi_AdapterTripTimeValue3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TripTimeS, RTE_CONST) Rte_Mdl_TripCompTripTimeValue1Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TripTimeS, RTE_CONST) Rte_Mdl_TripCompTripTimeValue2Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TripTimeS, RTE_CONST) Rte_Mdl_TripCompTripTimeValue3Value0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UIIdmPriorityDisplayS, RTE_CONST) Rte_Hmi_AdapterIDMMainDisplayStatesValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UIIdmPriorityDisplayS, RTE_CONST) Rte_Mdl_IDMMainDisplayIDMMainDisplayStatesValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_AUDIOWARNING_UPDATE_T, RTE_CONST) Rte_Hmi_AdapterUiAudioWarningValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_AUDIOWARNING_UPDATE_T, RTE_CONST) Rte_Mdl_AudioMcanUiAudioWarningValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_AUDIO_UPDATE_T, RTE_CONST) Rte_Hmi_AdapterCurrentAudioSourceValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_AUDIO_UPDATE_T, RTE_CONST) Rte_Mdl_AudioMcanCurrentAudioSourceValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_AUX_INFO_T, RTE_CONST) Rte_Hmi_AdapterUiAuxDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_AUX_INFO_T, RTE_CONST) Rte_Mdl_AudioMcanUiAuxDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_DISC_INFO_T, RTE_CONST) Rte_Hmi_AdapterUiDiscDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_DISC_INFO_T, RTE_CONST) Rte_Mdl_AudioMcanUiDiscDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_HD_RADIO_INFO_T, RTE_CONST) Rte_Hmi_AdapterUiHDRadioDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_HD_RADIO_INFO_T, RTE_CONST) Rte_Mdl_AudioMcanUiHDRadioDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_INTERNET_AUDIO_INFO_T, RTE_CONST) Rte_Hmi_AdapterUiInternetAudioDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_INTERNET_AUDIO_INFO_T, RTE_CONST) Rte_Mdl_AudioMcanUiInternetAudioDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_ARRIVAL_WEATHER_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviArrivalWeatherInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_ARRIVAL_WEATHER_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviArrivalWeatherInfoValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_GUIDE_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviGuideDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_GUIDE_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviGuideDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviIntSecFourLaneDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviIntSecOneLaneDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviIntSecTwoLaneDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_CONST) Rte_Hmi_AdapterNaviInterSecThreeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntSecFourLaneDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntSecOneLaneDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviIntSecTwoLaneDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanNaviInterSecThreeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_SPEED_LIMIT_INFO_T, RTE_CONST) Rte_Hmi_AdapterCurrentSpeedLimitStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_NAVI_SPEED_LIMIT_INFO_T, RTE_CONST) Rte_Mdl_NaviMcanCurrentSpeedLimitStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_RADIO_INFO_T, RTE_CONST) Rte_Hmi_AdapterUiRadioDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_RADIO_INFO_T, RTE_CONST) Rte_Mdl_AudioMcanUiRadioDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEL_INFO_T, RTE_CONST) Rte_Hmi_AdapterTelInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TEL_INFO_T, RTE_CONST) Rte_MDL_PhoneMcanTelInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TV_INFO_T, RTE_CONST) Rte_Hmi_AdapterUiTvDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_TV_INFO_T, RTE_CONST) Rte_Mdl_AudioMcanUiTvDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_VR_INFO_T, RTE_CONST) Rte_Hmi_AdapterVRInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UI_VR_INFO_T, RTE_CONST) Rte_MDL_PhoneMcanVRInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Ctrl_SettingsAdapterSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Hmi_AdapterSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_AccelEcoSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_ClockSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_CustMenuSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_DASSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_HUDSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_IdleStopSettingSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_MtncSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_SpeedSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_TPMSSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_UnitLangSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_VDCSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(UiSettingsAllTypesS, RTE_CONST) Rte_Mdl_VehicleSettingsSettingsAlltypeValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(WaterHighTempThValueS, RTE_CONST) Rte_MDL_ConfigWaterHighTempThValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(WaterHighTempThValueS, RTE_CONST) Rte_Mdl_EctWaterHighTempThValueValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(tt_feedback, RTE_CONST) Rte_Mdl_SafetyAdaptertt_diag_feedbackValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(tt_feedback, RTE_CONST) Rte_SENS_Adapttt_diag_feedbackValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# include "Rte_DataHandleType.h"

# ifdef RTE_MICROSAR_PIM_EXPORT


/**********************************************************************************************************************
 * Calibration component and SW-C local calibration parameters
 *********************************************************************************************************************/

#  define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(NV_Data_ApplicationRandomNumber, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ApplicationRandomNumber_ROM_NVBlockDescriptor_ApplicationRandomNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_CustomerHWReference, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerHWReference_ROM_NVBlockDescriptor_CustomerHWReference; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_CustomerReference2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerReference2_ROM_NVBlockDescriptor_CustomerReference2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_CustomerReference, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerReference_ROM_NVBlockDescriptor_CustomerReference; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID100, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID100_ROM_NVBlockDescriptor_DiagDID100; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID200, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID200_ROM_NVBlockDescriptor_DiagDID200; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID300, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID300_ROM_NVBlockDescriptor_DiagDID300; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID310, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID310_ROM_NVBlockDescriptor_DiagDID310; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID400, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID400_ROM_NVBlockDescriptor_DiagDID400; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID410, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID410_ROM_NVBlockDescriptor_DiagDID410; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID420, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID420_ROM_NVBlockDescriptor_DiagDID420; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID430, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID430_ROM_NVBlockDescriptor_DiagDID430; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID440, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID440_ROM_NVBlockDescriptor_DiagDID440; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID450, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID450_ROM_NVBlockDescriptor_DiagDID450; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID500, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID500_ROM_NVBlockDescriptor_DiagDID500; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDID900, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID900_ROM_NVBlockDescriptor_DiagDID900; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDIDF190, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDF190_ROM_NVBlockDescriptor_DiagDIDF190; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDIDF1A2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDF1A2_ROM_NVBlockDescriptor_DiagDIDF1A2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_DiagDIDFE11, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDFE11_ROM_NVBlockDescriptor_DiagDIDFE11; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FBLValidDTCState, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLValidDTCState_ROM_NVBlockDescriptor_FBLValidDTCState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FBLValidDTCState_1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLValidDTCState_1_ROM_NVBlockDescriptor_FBLValidDTCState_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FBL_NVM, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_NVM_ROM_NVBlockDescriptor_FBL_NVM; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FOTA_NVM, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_NVM_ROM_NVBlockDescriptor_FOTA_NVM; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FOTA_NVM_DIGHRNIG, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_NVM_DIGHRNIG_ROM_NVBlockDescriptor_FOTA_NVM_DIGHRNIG; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FeatureConfigCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeatureConfigCalib_ROM_NVBlockDescriptor_FeatureConfigCalib; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FeaturesConst1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst1_ROM_NVBlockDescriptor_FeaturesConst1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FeaturesConst2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst2_ROM_NVBlockDescriptor_FeaturesConst2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FeaturesConst3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst3_ROM_NVBlockDescriptor_FeaturesConst3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FeaturesConst4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst4_ROM_NVBlockDescriptor_FeaturesConst4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FeaturesConst5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst5_ROM_NVBlockDescriptor_FeaturesConst5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FeaturesConst6, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst6_ROM_NVBlockDescriptor_FeaturesConst6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FeaturesConst, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst_ROM_NVBlockDescriptor_FeaturesConst; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Fingerprint, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Fingerprint_ROM_NVBlockDescriptor_Fingerprint; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FotaUpdateStatus, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FotaUpdateStatus_ROM_NVBlockDescriptor_FotaUpdateStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FotaUpdateStatus_1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FotaUpdateStatus_1_ROM_NVBlockDescriptor_FotaUpdateStatus_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_FuelCalcCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FuelCalcCalib_ROM_NVBlockDescriptor_FuelCalcCalib; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_GUST_USER_LOGIN, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GUST_USER_LOGIN_ROM_NVBlockDescriptor_GUST_USER_LOGIN; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_GaugeEctCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeEctCalib_ROM_NVBlockDescriptor_GaugeEctCalib; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_GaugeFuelCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuelCalib_ROM_NVBlockDescriptor_GaugeFuelCalib; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_GaugeRPMCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeRPMCalib_ROM_NVBlockDescriptor_GaugeRPMCalib; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_GaugeSpdCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeSpdCalib_ROM_NVBlockDescriptor_GaugeSpdCalib; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_IDLE_STOP, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_IDLE_STOP_ROM_NVBlockDescriptor_IDLE_STOP; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_IKEY_BLK, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_IKEY_BLK_ROM_NVBlockDescriptor_IKEY_BLK; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_IllumPWMCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_IllumPWMCalib_ROM_NVBlockDescriptor_IllumPWMCalib; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_LoaderModeDetected, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_LoaderModeDetected_ROM_NVBlockDescriptor_LoaderModeDetected; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_MFG_DID_PRODUCT, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MFG_DID_PRODUCT_ROM_NVBlockDescriptor_MFG_DID_PRODUCT; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_MagicFlag, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MagicFlag_ROM_NVBlockDescriptor_MagicFlag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_NVM_HM_FaultCounters, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_NVM_HM_FaultCounters_ROM_NVBlockDescriptor_NVM_HM_FaultCounters; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_NvM_Revision_Value, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_NvM_Revision_Value_ROM_NVBlockDescriptor_NvM_Revision_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_NvM_Version_Value, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_NvM_Version_Value_ROM_NVBlockDescriptor_NvM_Version_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Odometer_BLK1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK1_ROM_NVBlockDescriptor_Odometer_BLK1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Odometer_BLK2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK2_ROM_NVBlockDescriptor_Odometer_BLK2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Odometer_BLK3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK3_ROM_NVBlockDescriptor_Odometer_BLK3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Odometer_BLK4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK4_ROM_NVBlockDescriptor_Odometer_BLK4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Odometer_BLK5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK5_ROM_NVBlockDescriptor_Odometer_BLK5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_PCBSerialNumber, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_PCBSerialNumber_ROM_NVBlockDescriptor_PCBSerialNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Reserved_Health_Management, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Reserved_Health_Management_ROM_NVBlockDescriptor_Reserved_Health_Management; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_DTC_INDEX_BLK, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_DTC_INDEX_BLK_ROM_NVBlockDescriptor_SIGMA_DTC_INDEX_BLK; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK0, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK0_ROM_NVBlockDescriptor_SIGMA_SSD_BLK0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK10, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK10_ROM_NVBlockDescriptor_SIGMA_SSD_BLK10; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK11, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK11_ROM_NVBlockDescriptor_SIGMA_SSD_BLK11; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK12, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK12_ROM_NVBlockDescriptor_SIGMA_SSD_BLK12; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK13, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK13_ROM_NVBlockDescriptor_SIGMA_SSD_BLK13; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK14, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK14_ROM_NVBlockDescriptor_SIGMA_SSD_BLK14; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK15, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK15_ROM_NVBlockDescriptor_SIGMA_SSD_BLK15; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK1_ROM_NVBlockDescriptor_SIGMA_SSD_BLK1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK2_ROM_NVBlockDescriptor_SIGMA_SSD_BLK2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK3_ROM_NVBlockDescriptor_SIGMA_SSD_BLK3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK4_ROM_NVBlockDescriptor_SIGMA_SSD_BLK4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK5_ROM_NVBlockDescriptor_SIGMA_SSD_BLK5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK6, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK6_ROM_NVBlockDescriptor_SIGMA_SSD_BLK6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK7, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK7_ROM_NVBlockDescriptor_SIGMA_SSD_BLK7; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK8_ROM_NVBlockDescriptor_SIGMA_SSD_BLK8; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_SSD_BLK9, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK9_ROM_NVBlockDescriptor_SIGMA_SSD_BLK9; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK0, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK0_ROM_NVBlockDescriptor_SIGMA_VTD_BLK0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK10, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK10_ROM_NVBlockDescriptor_SIGMA_VTD_BLK10; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK11, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK11_ROM_NVBlockDescriptor_SIGMA_VTD_BLK11; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK12, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK12_ROM_NVBlockDescriptor_SIGMA_VTD_BLK12; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK13, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK13_ROM_NVBlockDescriptor_SIGMA_VTD_BLK13; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK14, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK14_ROM_NVBlockDescriptor_SIGMA_VTD_BLK14; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK15, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK15_ROM_NVBlockDescriptor_SIGMA_VTD_BLK15; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK1_ROM_NVBlockDescriptor_SIGMA_VTD_BLK1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK2_ROM_NVBlockDescriptor_SIGMA_VTD_BLK2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK3_ROM_NVBlockDescriptor_SIGMA_VTD_BLK3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK4_ROM_NVBlockDescriptor_SIGMA_VTD_BLK4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK5_ROM_NVBlockDescriptor_SIGMA_VTD_BLK5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK6, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK6_ROM_NVBlockDescriptor_SIGMA_VTD_BLK6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK7, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK7_ROM_NVBlockDescriptor_SIGMA_VTD_BLK7; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK8_ROM_NVBlockDescriptor_SIGMA_VTD_BLK8; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_SIGMA_VTD_BLK9, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK9_ROM_NVBlockDescriptor_SIGMA_VTD_BLK9; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Signature, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Signature_ROM_NVBlockDescriptor_Signature; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_Signature_1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Signature_1_ROM_NVBlockDescriptor_Signature_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_USER_LOGIN, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_LOGIN_ROM_NVBlockDescriptor_USER_LOGIN; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_VehicleStateDetected, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_VehicleStateDetected_ROM_NVBlockDescriptor_VehicleStateDetected; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

extern CONST(NV_Data_ApplicationRandomNumber, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_ApplicationRandomNumber_ROM_NVBlockDescriptor_ApplicationRandomNumber; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_CustomerHWReference, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerHWReference_ROM_NVBlockDescriptor_CustomerHWReference; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_CustomerReference2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerReference2_ROM_NVBlockDescriptor_CustomerReference2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_CustomerReference, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerReference_ROM_NVBlockDescriptor_CustomerReference; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID100, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID100_ROM_NVBlockDescriptor_DiagDID100; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID200, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID200_ROM_NVBlockDescriptor_DiagDID200; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID300, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID300_ROM_NVBlockDescriptor_DiagDID300; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID310, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID310_ROM_NVBlockDescriptor_DiagDID310; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID400, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID400_ROM_NVBlockDescriptor_DiagDID400; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID410, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID410_ROM_NVBlockDescriptor_DiagDID410; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID420, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID420_ROM_NVBlockDescriptor_DiagDID420; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID430, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID430_ROM_NVBlockDescriptor_DiagDID430; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID440, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID440_ROM_NVBlockDescriptor_DiagDID440; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID450, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID450_ROM_NVBlockDescriptor_DiagDID450; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID500, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID500_ROM_NVBlockDescriptor_DiagDID500; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDID900, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID900_ROM_NVBlockDescriptor_DiagDID900; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDIDF190, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDF190_ROM_NVBlockDescriptor_DiagDIDF190; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDIDF1A2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDF1A2_ROM_NVBlockDescriptor_DiagDIDF1A2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_DiagDIDFE11, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDFE11_ROM_NVBlockDescriptor_DiagDIDFE11; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FBLValidDTCState, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLValidDTCState_ROM_NVBlockDescriptor_FBLValidDTCState; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FBLValidDTCState_1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLValidDTCState_1_ROM_NVBlockDescriptor_FBLValidDTCState_1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FBL_NVM, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_NVM_ROM_NVBlockDescriptor_FBL_NVM; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FOTA_NVM, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_NVM_ROM_NVBlockDescriptor_FOTA_NVM; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FOTA_NVM_DIGHRNIG, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_NVM_DIGHRNIG_ROM_NVBlockDescriptor_FOTA_NVM_DIGHRNIG; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FeatureConfigCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeatureConfigCalib_ROM_NVBlockDescriptor_FeatureConfigCalib; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FeaturesConst1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst1_ROM_NVBlockDescriptor_FeaturesConst1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FeaturesConst2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst2_ROM_NVBlockDescriptor_FeaturesConst2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FeaturesConst3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst3_ROM_NVBlockDescriptor_FeaturesConst3; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FeaturesConst4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst4_ROM_NVBlockDescriptor_FeaturesConst4; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FeaturesConst5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst5_ROM_NVBlockDescriptor_FeaturesConst5; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FeaturesConst6, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst6_ROM_NVBlockDescriptor_FeaturesConst6; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FeaturesConst, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst_ROM_NVBlockDescriptor_FeaturesConst; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Fingerprint, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Fingerprint_ROM_NVBlockDescriptor_Fingerprint; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FotaUpdateStatus, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FotaUpdateStatus_ROM_NVBlockDescriptor_FotaUpdateStatus; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FotaUpdateStatus_1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FotaUpdateStatus_1_ROM_NVBlockDescriptor_FotaUpdateStatus_1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_FuelCalcCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_FuelCalcCalib_ROM_NVBlockDescriptor_FuelCalcCalib; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_GUST_USER_LOGIN, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GUST_USER_LOGIN_ROM_NVBlockDescriptor_GUST_USER_LOGIN; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_GaugeEctCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeEctCalib_ROM_NVBlockDescriptor_GaugeEctCalib; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_GaugeFuelCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuelCalib_ROM_NVBlockDescriptor_GaugeFuelCalib; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_GaugeRPMCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeRPMCalib_ROM_NVBlockDescriptor_GaugeRPMCalib; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_GaugeSpdCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeSpdCalib_ROM_NVBlockDescriptor_GaugeSpdCalib; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_IDLE_STOP, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_IDLE_STOP_ROM_NVBlockDescriptor_IDLE_STOP; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_IKEY_BLK, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_IKEY_BLK_ROM_NVBlockDescriptor_IKEY_BLK; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_IllumPWMCalib, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_IllumPWMCalib_ROM_NVBlockDescriptor_IllumPWMCalib; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_LoaderModeDetected, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_LoaderModeDetected_ROM_NVBlockDescriptor_LoaderModeDetected; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_MFG_DID_PRODUCT, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MFG_DID_PRODUCT_ROM_NVBlockDescriptor_MFG_DID_PRODUCT; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_MagicFlag, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_MagicFlag_ROM_NVBlockDescriptor_MagicFlag; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_NVM_HM_FaultCounters, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_NVM_HM_FaultCounters_ROM_NVBlockDescriptor_NVM_HM_FaultCounters; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_NvM_Revision_Value, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_NvM_Revision_Value_ROM_NVBlockDescriptor_NvM_Revision_Value; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_NvM_Version_Value, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_NvM_Version_Value_ROM_NVBlockDescriptor_NvM_Version_Value; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Odometer_BLK1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK1_ROM_NVBlockDescriptor_Odometer_BLK1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Odometer_BLK2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK2_ROM_NVBlockDescriptor_Odometer_BLK2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Odometer_BLK3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK3_ROM_NVBlockDescriptor_Odometer_BLK3; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Odometer_BLK4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK4_ROM_NVBlockDescriptor_Odometer_BLK4; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Odometer_BLK5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK5_ROM_NVBlockDescriptor_Odometer_BLK5; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_PCBSerialNumber, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_PCBSerialNumber_ROM_NVBlockDescriptor_PCBSerialNumber; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Reserved_Health_Management, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Reserved_Health_Management_ROM_NVBlockDescriptor_Reserved_Health_Management; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_DTC_INDEX_BLK, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_DTC_INDEX_BLK_ROM_NVBlockDescriptor_SIGMA_DTC_INDEX_BLK; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK0, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK0_ROM_NVBlockDescriptor_SIGMA_SSD_BLK0; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK10, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK10_ROM_NVBlockDescriptor_SIGMA_SSD_BLK10; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK11, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK11_ROM_NVBlockDescriptor_SIGMA_SSD_BLK11; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK12, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK12_ROM_NVBlockDescriptor_SIGMA_SSD_BLK12; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK13, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK13_ROM_NVBlockDescriptor_SIGMA_SSD_BLK13; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK14, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK14_ROM_NVBlockDescriptor_SIGMA_SSD_BLK14; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK15, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK15_ROM_NVBlockDescriptor_SIGMA_SSD_BLK15; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK1_ROM_NVBlockDescriptor_SIGMA_SSD_BLK1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK2_ROM_NVBlockDescriptor_SIGMA_SSD_BLK2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK3_ROM_NVBlockDescriptor_SIGMA_SSD_BLK3; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK4_ROM_NVBlockDescriptor_SIGMA_SSD_BLK4; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK5_ROM_NVBlockDescriptor_SIGMA_SSD_BLK5; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK6, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK6_ROM_NVBlockDescriptor_SIGMA_SSD_BLK6; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK7, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK7_ROM_NVBlockDescriptor_SIGMA_SSD_BLK7; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK8_ROM_NVBlockDescriptor_SIGMA_SSD_BLK8; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_SSD_BLK9, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK9_ROM_NVBlockDescriptor_SIGMA_SSD_BLK9; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK0, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK0_ROM_NVBlockDescriptor_SIGMA_VTD_BLK0; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK10, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK10_ROM_NVBlockDescriptor_SIGMA_VTD_BLK10; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK11, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK11_ROM_NVBlockDescriptor_SIGMA_VTD_BLK11; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK12, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK12_ROM_NVBlockDescriptor_SIGMA_VTD_BLK12; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK13, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK13_ROM_NVBlockDescriptor_SIGMA_VTD_BLK13; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK14, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK14_ROM_NVBlockDescriptor_SIGMA_VTD_BLK14; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK15, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK15_ROM_NVBlockDescriptor_SIGMA_VTD_BLK15; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK1_ROM_NVBlockDescriptor_SIGMA_VTD_BLK1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK2_ROM_NVBlockDescriptor_SIGMA_VTD_BLK2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK3, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK3_ROM_NVBlockDescriptor_SIGMA_VTD_BLK3; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK4, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK4_ROM_NVBlockDescriptor_SIGMA_VTD_BLK4; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK5, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK5_ROM_NVBlockDescriptor_SIGMA_VTD_BLK5; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK6, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK6_ROM_NVBlockDescriptor_SIGMA_VTD_BLK6; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK7, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK7_ROM_NVBlockDescriptor_SIGMA_VTD_BLK7; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK8, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK8_ROM_NVBlockDescriptor_SIGMA_VTD_BLK8; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_SIGMA_VTD_BLK9, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK9_ROM_NVBlockDescriptor_SIGMA_VTD_BLK9; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Signature, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Signature_ROM_NVBlockDescriptor_Signature; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_Signature_1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_Signature_1_ROM_NVBlockDescriptor_Signature_1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_USER_LOGIN, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_LOGIN_ROM_NVBlockDescriptor_USER_LOGIN; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_VehicleStateDetected, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_VehicleStateDetected_ROM_NVBlockDescriptor_VehicleStateDetected; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */

#  define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ClusterModeStatus, RTE_VAR_INIT) Rte_AppCtrl_ppEnterAppMode_EnterApplicationMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SoftwareModeS, RTE_VAR_INIT) Rte_AppCtrl_ppSoftwareMode_SoftwareMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SigmaTaskTriggerT, RTE_VAR_INIT) Rte_BswcVcanSigma_ppSigmaTaskTrigger_SigmaCallTriggerType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_AppIntrpt_pp100msCount_HundredmsCount; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Bswc_AppIntrpt_ppGetTripDistanceCounts_TripDistanceCounts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANControllerDTC_CANControllerDTC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ACU_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A103; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A110; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A116; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A117; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A119; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A120; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A124; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A125; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A139; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A147; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A148; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A149; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A150; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A151; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A152; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A153; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A154; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A157; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A162; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_A6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADAS_N101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADB_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ADP_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ALC_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ATCU_A106; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ATCU_A109; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ATCU_A110; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ATCU_A113; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ATCU_A114; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_AVM_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_AVM_A120; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_AVM_A121; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_AVM_A128; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A105; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A106; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A107; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A108; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A109; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A110; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A111; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A112; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A113; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A114; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A115; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A116; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_BCM_A2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_CDM_A112; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_CDM_A116; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_CDM_A119; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_DSMU_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_DSMU_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_EBA_A2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A105; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A107; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A108; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A109; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A110; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A112; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A114; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A116; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_A14; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_ECM_R101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_EPKB_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_EPKB_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_EPS_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_EPS_A103; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_FRCAMERA_A110; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_FRCAMERA_A111; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_FRCAMERA_A2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_FWD_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_A105; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_A106; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_A108; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_A109; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_A112; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_A137; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_A37; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_A6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_N102; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HEVC_R101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HFM_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HFM_A102; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HFM_A104; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HUD_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HUD_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_HVAC_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_IVI_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_IVI_A3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_IVI_R104; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_MBL_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_PBD_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_PSCU_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_PSCU_R1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_PSDL_A103; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_SONAR_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_SONAR_A3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_SONAR_A4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_SRRR_A106; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_SRRR_A107; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_SRRR_A134; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_USM_A101; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_USM_A103; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_VDC_A113; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_VDC_A114; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_VDC_A9; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Bswc_VCAN_ppCANNvrRcvd_VSP_A1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MsgRcvdT, RTE_VAR_INIT) Rte_Bswc_VCAN_ppMsgRcvdInIgnOn_MsgRcvdInIgnOn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SubcriptionErrorStatusT, RTE_VAR_INIT) Rte_CBswc_Ethernet_ppAudioVideoLayoutSubscribeStsUpdate_VIPAudioSubscribeStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LayoutErrorStateT, RTE_VAR_INIT) Rte_CBswc_Ethernet_ppAudioVideoLayoutSubscribeStsUpdate_VIPVideoLayoutStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SubcriptionErrorStatusT, RTE_VAR_INIT) Rte_CBswc_Ethernet_ppAudioVideoLayoutSubscribeStsUpdate_VIPVideoSubscribeStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VideoLayoutType, RTE_VAR_INIT) Rte_CBswc_Ethernet_ppSR_ppClusterVideo_TIClusterVideoIf_VideoLayoutRequest; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBswc_Ethernet_ppSR_ppEthernet_TIEthernetIf_EthernetActivationReq; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(StreamStatusType, RTE_VAR_INIT) Rte_CBswc_Ethernet_ppVideoStreamStsUpdate_VideoStreamStsUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFotaChangeRequest, RTE_VAR_INIT) Rte_CFotaCdd_pSR_FotaChangeRequest_FotaChangeRequestData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFotaCommandRequest, RTE_VAR_INIT) Rte_CFotaCdd_pSR_FotaCommandRequest_FotaCommandRequestData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFotaStateResponse, RTE_VAR_INIT) Rte_CFotaCdd_pSR_FotaStateResponse_FotaStateResponseData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFotaVinResponse, RTE_VAR_INIT) Rte_CFotaCdd_pSR_FotaVinResponse_FotaVinResponseData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSwUpdateDataTransferReq, RTE_VAR_INIT) Rte_CFotaCdd_pSR_SwUpdateDataTransferReq_SwUpdateDataTransferReqData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSwUpdateDownloadSwPartReq, RTE_VAR_INIT) Rte_CFotaCdd_pSR_SwUpdateDownloadSwPartReq_SwUpdateDownloadSwPartReqData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSwUpdateEraseSwPartReq, RTE_VAR_INIT) Rte_CFotaCdd_pSR_SwUpdateEraseSwPartReq_SwUpdateEraseSwPartReqData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSwUpdateUploadSwPartReq, RTE_VAR_INIT) Rte_CFotaCdd_pSR_SwUpdateUploadSwPartReq_SwUpdateUploadSwPartReqData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EFotaState, RTE_VAR_INIT) Rte_CFotaCdd_pp_FotaState_FotaState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(tDiagSessionSt, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_DiagSession_DiagSessionData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_DisplayIlluminationDiagCtrl_DisplayIllumCtrlData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(teDiagFilterBypassMode, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_FilterBypassModeCtrl_DiagFilterBypassModeCtrl; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(teSetAllTelltalesDiagCtrl, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_SetAllTelltalesDiagCtrl_TelltalesDiagCtrlData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CMeetCdd_pp_SR_SleepReq_SleepReqData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UiSettingsAllTypesS, RTE_VAR_INIT) Rte_Ctrl_SettingsAdapter_ppMenuAlltypes_SettingsAlltype; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WUS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WUSStates, RTE_VAR_INIT) Rte_Ctrl_WUS_pp_TI_WUS_CurrentState_WusState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehicleActiveModes, RTE_VAR_INIT) Rte_Ctrl_WUS_pp_WUSVehActiveMode_WUSCurrentVehicleState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IndicatorOutputType, RTE_VAR_INIT) Rte_Ctrl_indicator_ppSetIndicatorStatus_IndicatorStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DTCClearT, RTE_VAR_INIT) Rte_Dcm_App_ppClearDTCOccurCounter_ClearDTCCounter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Communication_T, RTE_VAR_INIT) Rte_Dcm_App_ppDiagCommState_DiagCommState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SPowerSystemStateReqChange, RTE_VAR_INIT) Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDmnStatus, RTE_VAR_INIT) Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EFotaActiveCond, RTE_VAR_INIT) Rte_FotaMdl_pp_FotaActivationStatus_FotaCondChkDuringActivation; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EFotaActiveCond, RTE_VAR_INIT) Rte_FotaMdl_pp_FotaActivationStatus_FotaCondDuringReadyForActivation; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EFotaActiveCond, RTE_VAR_INIT) Rte_FotaMdl_pp_FotaActivationStatus_FotaCondDuringVehCondCheck; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_FotaMdl_pp_FotaChangeReq_FotaChangeRequest; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Fuel_Cdd_ppFuelFlps_FuelFLPSValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Fuel_Cdd_ppFuelInterface_FuelBatteryConnectStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FuelFillModeType, RTE_VAR_INIT) Rte_Fuel_Cdd_ppFuelInterface_FuelFillMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(InitType, RTE_VAR_INIT) Rte_Fuel_Cdd_ppFuelInterface_FuelInitType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FuelSensorStatusT, RTE_VAR_INIT) Rte_Fuel_Cdd_ppFuelInterface_FuelSensorCurrentStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Fuel_Cdd_ppFuelInterface_FuelVolInCentiLitres; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LowFuelStatusT, RTE_VAR_INIT) Rte_Fuel_Cdd_ppFuelInterface_LowFuelStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Fuel_Cdd_ppFuelRAD_FuelRADValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Fuel_Cdd_ppLowFuelTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SAD2MenuPayloadData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_AD2MenuPayloadData_AD2MenuPayloadDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SAccelGuideValue, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_AccelGuideValue_AccelGuideValueData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SCurrentTimeDisplay, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_CurrentTimeDisplay_CurrentTimeDisplayData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDistanceToEmptyStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_DistanceToEmptyStatus_DistanceToEmptyStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SEMSStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_EMSStatus_EMSStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SEctData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_EctData_EctDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFuelData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_FuelData_FuelDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFuelEconomyData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_FuelEconomyData_FuelEconomyDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIdleStopData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_IdleStopData_IdleStopDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIgnStateStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_IgnStateStatus_IgnStateStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SMenuPayloadData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_MenuPayloadData_MenuPayloadDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SModuleConfigStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_ModuleConfigStatus_ModuleConfigStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SOdometerStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_OdometerStatus_OdometerStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SOutsideAirTemperature, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_OutsideAirTemperature_OutsideAirTemperatureData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SPopupStatusData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_PopupStatusData_PopupStatusDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SPowerData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_PowerData_PowerDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSpeedData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_SpeedData_SpeedDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STTIndicatorStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_TTIndicatorStatus_TTIndicatorStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STachoData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_TachoData_TachoDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STripComputerData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_TripComputerData_TripComputerDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SVCRStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_VCRStatus_VCRStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SVariantConfigData, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_VariantConfigData_VariantConfigDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SWarningDisplayStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_pSR_WarningDisplayStatus_WarningDisplayStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WarningPresentStatusT, RTE_VAR_INIT) Rte_Hmi_Adapter_ppAnyWarningActive_AnyWarningActive; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WarningAnimStatusT, RTE_VAR_INIT) Rte_Hmi_Adapter_ppAnyWarningActiveRawStatus_ActiveWarningAnimStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WarningPresentStatusT, RTE_VAR_INIT) Rte_Hmi_Adapter_ppAnyWarningActiveRawStatus_AnyWarningActiveRawStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Hmi_Adapter_ppAudioSourceDispSts_AudioSourceSelectn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETMState, RTE_VAR_INIT) Rte_Hmi_Adapter_ppCurrentETMState_CurrentETMState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Hmi_Adapter_ppCurrentMainMenu_CurrentMainMenu; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Hmi_Adapter_ppCurrentMainMenuSceen_CurrentMainMenuScreen; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PopUpStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_ppEMSPopupDisplaySts_EMSPopupDisplaySts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BulbTestStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_ppETMBulbTest_CurrentBulbTestStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HMIContentStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_ppHMIContentStatus_HMIContentCurrentStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HmiInitStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_ppHmiInitStatus_HmiInitedAndActive; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IgnOffDimmingProcessStsT, RTE_VAR_INIT) Rte_Hmi_Adapter_ppIgnOffDimmingProcessSts_IgnOffDimmingProcessSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Hmi_Adapter_ppInEMSMenu_InEMSMenu; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PersonnalMenuStsT, RTE_VAR_INIT) Rte_Hmi_Adapter_ppInPersonnalMenu_InPersonnalMenu; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OpeningMovieAnimationStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_ppOpeningMovieAnimStatus_OpeningMovieAnimStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(StartUpInitT, RTE_VAR_INIT) Rte_Hmi_Adapter_ppStartUpInitProcess_StartUpInit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TELActiveStatus, RTE_VAR_INIT) Rte_Hmi_Adapter_ppTELActiveStatus_IsTELActive; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WarningPresentStatusT, RTE_VAR_INIT) Rte_Hmi_Adapter_ppWCatMoreThanOneStatus_WCatWarnMoreThanOne; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WarningPresentStatusT, RTE_VAR_INIT) Rte_Hmi_Adapter_ppWCatWarnStatus_WCategoryWarning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ZoneP2Status, RTE_VAR_INIT) Rte_Hmi_Adapter_ppZoneP2ActiveStatus_AnyZoneP2Active; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppADColorConfigSts_ADColorConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppADTypeConfigSts_ADTypeConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AFSwarningT, RTE_VAR_INIT) Rte_MDL_Config_ppAFSwarningCfg_AFSwarningCfg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TransmissionTypeT, RTE_VAR_INIT) Rte_MDL_Config_ppATCVTTransmisnType_TransmissionType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Awd4wdAvlTypeT, RTE_VAR_INIT) Rte_MDL_Config_ppAWD4WDConfiginfo_WdConfigStates; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AccentLightingT, RTE_VAR_INIT) Rte_MDL_Config_ppAccentLightingStates_AccentLightingConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CombiSWConfigS, RTE_VAR_INIT) Rte_MDL_Config_ppCombiSWConfig_CombiSWConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DialConfigT, RTE_VAR_INIT) Rte_MDL_Config_ppConfigVariationInfo_DialCurrentConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IFEConfigT, RTE_VAR_INIT) Rte_MDL_Config_ppConfigVariationInfo_IFECurrentConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ZoneCfT, RTE_VAR_INIT) Rte_MDL_Config_ppConfig_Destination_DestinationCurrentConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DisplayModeT, RTE_VAR_INIT) Rte_MDL_Config_ppDefaultDisplayMode_DefaultDisplayMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DeratingEndPointPWMT, RTE_VAR_INIT) Rte_MDL_Config_ppDeratingEndPointPWM_DeratingEndPointPWM; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DeratingEndPointTempT, RTE_VAR_INIT) Rte_MDL_Config_ppDeratingEndPointTemp_DeratingEndPointTemp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DeratingFaultPointTempT, RTE_VAR_INIT) Rte_MDL_Config_ppDeratingFaulltPointTemp_DeratingFaulltPointTemp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DeratingStartPointTempT, RTE_VAR_INIT) Rte_MDL_Config_ppDeratingStartPointTemp_DeratingStartPointTemp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DeratingCFT, RTE_VAR_INIT) Rte_MDL_Config_ppDerating_CF_sts_Derating_CF_sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ECUVersionDetatilS, RTE_VAR_INIT) Rte_MDL_Config_ppECUVersionDetatilInfo_ECUVersionDetatil; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETMStringT, RTE_VAR_INIT) Rte_MDL_Config_ppETMdisplaydata_HardWareCode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETMStringT, RTE_VAR_INIT) Rte_MDL_Config_ppETMdisplaydata_PCBCode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETMStringT, RTE_VAR_INIT) Rte_MDL_Config_ppETMdisplaydata_SoftwareVersion; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ETMStringT, RTE_VAR_INIT) Rte_MDL_Config_ppETMdisplaydata_SparePartNo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WICodeT, RTE_VAR_INIT) Rte_MDL_Config_ppETMdisplaydata_WICode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppEnglishDefaultType_EnglishDefaultTypeConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FuelTankTypeT, RTE_VAR_INIT) Rte_MDL_Config_ppFuelTankType_FuelTankType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FuelCapPositionT, RTE_VAR_INIT) Rte_MDL_Config_ppFuelcapPosition_FuelCapPostn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppGSIConfigSts_GSIStsConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_MDL_Config_ppGetDTESecWarnValue_DTE_SecondWarn_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_MDL_Config_ppGetFuelParameter_FuelConsumptionLong_B; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_MDL_Config_ppGetFuelParameter_FuelConsumptionShort_A; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppGetFuelParameter_FuelDeadremain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppGetFuelParameter_FuelEconomyRAFC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_MDL_Config_ppGetFuelParameter_FuelIdleStop; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_MDL_Config_ppGetFuelParameter_FuelRemainingAverage_C; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_MDL_Config_ppGetFuelParameter_FuelRemainingMeasureable_A; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppGetFuelParameter_FuelSafetymargin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_MDL_Config_ppGetLFWValue_LFWOFFValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_MDL_Config_ppGetLFWValue_LFWONValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LangaugeMaskPos, RTE_VAR_INIT) Rte_MDL_Config_ppGetLangMaskPos_LangMaskPos; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppGetPartNumber_PartNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TachoRedZoneT, RTE_VAR_INIT) Rte_MDL_Config_ppGetTachoRedZoneInfo_TachoRedZoneInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TextShrinkApplicableStsT, RTE_VAR_INIT) Rte_MDL_Config_ppGetTextShrinkApplicableSts_TextShrinkApplicableSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HandlePositionT, RTE_VAR_INIT) Rte_MDL_Config_ppHandlePosition_HandlePositionConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppITSTJPConfigSts_ITSTJPConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppITSTSRConfigSts_ITSTSRConfigSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FeatureStatus, RTE_VAR_INIT) Rte_MDL_Config_ppITSfeatureCfg_ITSfeaturetConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IlluminationControlTypeT, RTE_VAR_INIT) Rte_MDL_Config_ppIlluminationControlType_ILiCtrlType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LDPSSiconCfgT, RTE_VAR_INIT) Rte_MDL_Config_ppLDWiconSelection_LDPSSiconSelection; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppMPGDefaultType_MPGDefaultTypeConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppOpnMveAnimTWaitDuration_OpnMveAnimConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppOpnMveAnimTsDuration_OpnMveAnimConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(RSBPopupAvailableT, RTE_VAR_INIT) Rte_MDL_Config_ppRSBPopupApplicableSts_RSBPopupApplicable; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FutureStatusT, RTE_VAR_INIT) Rte_MDL_Config_ppSpeedFutureApcble_SpeedApplicable; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SubSpeedUnitT, RTE_VAR_INIT) Rte_MDL_Config_ppSpeedUnitType_SpeedUnitType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppSwipeAnimationDelay_SwipeAnimationDelay; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppSwipeAnimationDuration_SwipeAnimationDuration; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_Config_ppSwipeConfigSts_EthernetSwipeConfigSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TSRRegionT, RTE_VAR_INIT) Rte_MDL_Config_ppTSRDisplayRegionSts_TSR_DisplayRegionSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FeatureStatus, RTE_VAR_INIT) Rte_MDL_Config_ppTSRfeatureCfg_TSRfeaturetConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SettingRestTypeT, RTE_VAR_INIT) Rte_MDL_Config_ppTripConfigRestStates_ConfigRestStates; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VariantCfgT, RTE_VAR_INIT) Rte_MDL_Config_ppVariantCfg_VariantConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehiclDASsettingStsT, RTE_VAR_INIT) Rte_MDL_Config_ppVehiDASsettingSts_VehicleDASsettingSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehicleTypeCfgT, RTE_VAR_INIT) Rte_MDL_Config_ppVehicleTypeCfg_VehicleTypeConfig; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WaterHTempT, RTE_VAR_INIT) Rte_MDL_Config_ppWaterHTempCfg_WaterHTempCfg; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(WaterHighTempThValueS, RTE_VAR_INIT) Rte_MDL_Config_ppWaterHighTemValue_WaterHighTempThValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MDL_DriveMode_ppDriveModePayload_DriveModeTwoWDSwtchSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DriveModeS, RTE_VAR_INIT) Rte_MDL_DriveMode_ppDriveModePayload_DriveModeWarningPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DriveModeTypeS, RTE_VAR_INIT) Rte_MDL_DriveMode_ppDriveModePayload_DriveModeWarningTypePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_4WD_pp4WDAutoTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_4WD_pp4WDLockTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_4WD_ppFourWDState_FrontTorqueRatio; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_4WD_ppFourWDState_RearTorqueRatio; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad2AlcNumber, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInAD1L3AlcLane_AD1L3LaneAlcNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneHov, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInAD1L3AlcLane_AD1L3LaneHovCenter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneHov, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInAD1L3AlcLane_AD1L3LaneHovLeft; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneHov, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInAD1L3AlcLane_AD1L3LaneHovRight; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInAD1L3ControlInstruction_AD1L3ControlInstruction; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3StatusDisplay, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInAD1L3StatusDisplay_ADL3_StatusDisplay; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInAutoLaneChangeSts_ADL3_AlcLaneStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3BackColor, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInBackColorViewMode_AD1L3BackColor; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3ViewMode, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInBackColorViewMode_AD1L3ViewMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneCurveSts, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInTrafficLaneSts_AD1L3TrafficLaneCurve; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneGap, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInTrafficLaneSts_AD1L3TrafficLaneLeftGap; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneLeftSts, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInTrafficLaneSts_AD1L3TrafficLaneLeftSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneGap, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInTrafficLaneSts_AD1L3TrafficLaneRightGap; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneRightSts, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInTrafficLaneSts_AD1L3TrafficLaneRightSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1l3LaneSts, RTE_VAR_INIT) Rte_Mdl_AD2_ppHmiInTrafficLaneSts_AD1L3TrafficLaneSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_ppWRN_400Popup_Wrn_400Payload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_ppWRN_400Popup_Wrn_400PopUpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_ppWRN_401Popup_Wrn_401Payload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_ppWRN_401Popup_Wrn_401PopUpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_ppWRN_402Popup_Wrn_402Payload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_ppWRN_402Popup_Wrn_402PopUpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NaviLinkStatusType, RTE_VAR_INIT) Rte_Mdl_AD2_pp_HmiInAD1L3NaviLinkIcon_ADL3_NaviLinkIconStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AlcIconStatus, RTE_VAR_INIT) Rte_Mdl_AD2_pp_HmiInAD1L3_AlcIcon_ADL3_AlcIconStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_pp_HmiInAD1L3_AlcMarkerStatus_ADL3_AlcMarkerStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_pp_HmiInAD1L3_NaviRoutGuide_ADL3_NaviRoutGuide; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2Chimes_ppSndCddUpdateGroupPriority_SndCddGroup; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LaneMarker, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_HmiLaneMarkerStatus_LaneMarkerStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OwnVehicleBrake, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_HmiOwnVehicleStatus_OwnVehicleBrake; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OwnVehicleEffect, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_HmiOwnVehicleStatus_OwnVehicleEffect; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OwnVehicleTurn, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_HmiOwnVehicleStatus_OwnVehicleTurn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_Hmi_AD2SurrVehicleSts_AD2_Frame_No; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad2SurrVehInfo, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_Hmi_AD2SurrVehicleSts_AD2_Surr_Veh_Alpha; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad2SurrVehInfo, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_Hmi_AD2SurrVehicleSts_AD2_Surr_Veh_Color; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad2SurrVehInfo, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_Hmi_AD2SurrVehicleSts_AD2_Surr_Veh_RNDR_Sts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad2SurrVehSts, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_Hmi_AD2SurrVehicleSts_AD2_Surr_Veh_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad2SurrVehInfo, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_Hmi_AD2SurrVehicleSts_AD2_Surr_Veh_X_Pos; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad2SurrVehInfo, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_Hmi_AD2SurrVehicleSts_AD2_Surr_Veh_Y_Pos; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PilotDrivePayloadS, RTE_VAR_INIT) Rte_Mdl_AD2_3D_pp_PilotDrive_Payload_PilotPayloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Common_SwrgSw_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Cruise_Distance_Front_Car; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Cruise_Front_Car_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Cruise_Lane_Left_Lower_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Cruise_Lane_Left_Upper_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Cruise_Lane_Right_Lower_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Cruise_Lane_Right_Upper_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Cruise_Strg_Icon; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AD3_ppHmiZ2CruiseStatus_Cruise_Text; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_ADAS_ppAD1L3LockUpFramePayload_AD1L3LockUpFramePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_ADAS_ppAD1L3VehicleSpdIndPayload_AD1L3VehicleSpdIndPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CurveRoadStatusType, RTE_VAR_INIT) Rte_Mdl_ADAS_ppCurveRoadPayload_CurveRoadPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_ADAS_ppCurveRoadPayloadAD2_CurveRoadPayloadAD2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TrafficSignType, RTE_VAR_INIT) Rte_Mdl_ADAS_ppTSDPayload_TSDPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(GreenFrameType, RTE_VAR_INIT) Rte_Mdl_ADAS_ppTSR_ICCPayload_GreenFramePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LookUpSignType, RTE_VAR_INIT) Rte_Mdl_ADAS_ppTSR_ICCPayload_LookUpSignPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LookUpSignSpdValueType, RTE_VAR_INIT) Rte_Mdl_ADAS_ppTSR_ICCPayload_LookUpSignSpdPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehSpdIndType, RTE_VAR_INIT) Rte_Mdl_ADAS_ppTSR_ICCPayload_VehSpdIndPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TsrIccPopUpType, RTE_VAR_INIT) Rte_Mdl_ADAS_ppTSR_ICCPopup_TsrIccPopUpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PopUpTriggerSts, RTE_VAR_INIT) Rte_Mdl_ADAS_ppTSR_ICCPopup_TsrIccPopupNewTrigger; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AWC_ppAWCState_AWCYawMomentValuePattern; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AWC_ppAWCState_TorqueRatioPosition; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AccStatusType, RTE_VAR_INIT) Rte_Mdl_Acc_Crank_ppACCStatus_AccStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FeatureInputSts, RTE_VAR_INIT) Rte_Mdl_Acc_Crank_ppCrankRdyIpSts_CrankReadyIpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrankStatusType, RTE_VAR_INIT) Rte_Mdl_Acc_Crank_ppCrankStatus_CrankStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EngineStateTypes, RTE_VAR_INIT) Rte_Mdl_Acc_Crank_ppEngineState_EngineState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FeatureInputSts, RTE_VAR_INIT) Rte_Mdl_Acc_Crank_ppOpeningEntryChek_OpeningEntryCheck; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FeatureInputSts, RTE_VAR_INIT) Rte_Mdl_Acc_Crank_ppOpeningOffStatus_OpeningOffIpSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AccelMenuAvailability, RTE_VAR_INIT) Rte_Mdl_AccelEco_ppAccelMenuAvailability_CurrentAccelMenuAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AccelMenuAvailability, RTE_VAR_INIT) Rte_Mdl_AccelEco_ppAccelMenuAvailability_CurrentEcoRankMenuAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AccelGuideValueS, RTE_VAR_INIT) Rte_Mdl_AccelEco_ppCurrentAccelValue_CurrentAccelGuideValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EcoIndicatorPayload, RTE_VAR_INIT) Rte_Mdl_AccelEco_ppCurrentAccelValue_EcoIndicatorCurrentValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_AccelEco_ppCurrentAccelValue_EcoRankNumberOfStars; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_AccelEco_ppCurrentAccelValue_EcoTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TPMSEcoAdviceT, RTE_VAR_INIT) Rte_Mdl_AccelEco_ppTPMSEcoAdvice_TPMSEcoAdviceStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AccelMenuAvailability, RTE_VAR_INIT) Rte_Mdl_AccelEco_ppTPMSEcoAdviceOnoffStatus_AcceecolAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ECOIndicator, RTE_VAR_INIT) Rte_Mdl_AccelEcoSettings_ppEcoIndicatorSettings_CurrentEcoIndicatorSettingsVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ECOModeReport, RTE_VAR_INIT) Rte_Mdl_AccelEcoSettings_ppEcoModeReportSettings_CurrentEcoModeReportSettingsVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ADBPopUpT, RTE_VAR_INIT) Rte_Mdl_Adb_ppADBPopUpStatus_ADBPopUpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ADBPopUpTrigger, RTE_VAR_INIT) Rte_Mdl_Adb_ppADBPopUpStatus_ADBPopupNewTrigger; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Adb_ppADBTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BatterModeS, RTE_VAR_INIT) Rte_Mdl_BatMode_ppCurrentBatMode_BatteryModeAvailAndStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BatteryModeInterruptPayload, RTE_VAR_INIT) Rte_Mdl_BatMode_ppCurrentBatMode_BatteryModeInterrupt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BatteryNotPermitPayload, RTE_VAR_INIT) Rte_Mdl_BatMode_ppCurrentBatMode_BatteryNotPermitWarning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BatteryZEVCancelPayload, RTE_VAR_INIT) Rte_Mdl_BatMode_ppCurrentBatMode_BatteryZEVCancelWarning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ButtonEtmStatus, RTE_VAR_INIT) Rte_Mdl_Button_ppETMEnterButtonPressedStatus_ButtonStatusEtmPort; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ButtonAndEvents, RTE_VAR_INIT) Rte_Mdl_Button_ppSettingDummyPort_SettingDummyPort; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Ceng_ppCengTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Ceng2_ppCeng2TTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ClockDisplaySts, RTE_VAR_INIT) Rte_Mdl_ClockSettings_ppClockDisplayStatus_ClockDisplaysts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ClockConfigType, RTE_VAR_INIT) Rte_Mdl_ClockSettings_ppClockMenuType_CurrentClockMenuType; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ClockType, RTE_VAR_INIT) Rte_Mdl_ClockSettings_ppCurrentTime_CurrentTime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CombiSWOutputS, RTE_VAR_INIT) Rte_Mdl_CombiSwitch_ppCombiSWPayload_CombiSwPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppADBSettingStatus_ADBSettingsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppCombiSWSettingsStatus_CombiSWLightSettingStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppCombiSWSettingsStatus_CombiSWRearWiperSettingStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppCombiSWSettingsStatus_CombiSWWiperSettingStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppCruiseControlGuidanceSetting_CruiseControlGuidanceSettingsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppCruiseScreenSettingsStatus_CruiseScreenSettingsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MainMenuArrayT, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppCurMainMenuStatus_CurrentMainMenuStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MainMenuListT, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppCurMainMenuStatus_CurrentMenuList; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Display_ModeT, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppDisplayMode_HmiDisplayMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppHighBeamAssistSettingStatus_HighBeamAssistSettingsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppNaviIntSettingStatus_NavigationInterruptSettingsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppOpngMovieSettingsStatus_OpeningMovieSettingsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PersonalizedSubListT, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppPersonalizedSettingStatus_PersonalizedAverageSpeedStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PersonalizedSubListT, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppPersonalizedSettingStatus_PersonalizedFuelEconomyStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PersonalizedListT, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppPersonalizedSettingStatus_PersonalizedListSettingStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PersonalizedSubListT, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppPersonalizedSettingStatus_PersonalizedTripStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AnimSoundStsT, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppSR_ppWelcEffectAnimAndSoundSetting_TI_WelcEffectAnimAndSoundSetting_AnimAndSoundSetting; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppSR_ppWelcomeSndSettingsSts_TI_HMI_WelcomeSoundSettingsStatus_WelcomeSndSettingsSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppSeatMemoryGuidanceSettingStatus_SeatMemoryGuidanceSettingsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SETTING_STATUS_T, RTE_VAR_INIT) Rte_Mdl_CustMenuSettings_ppSpeedLimitterSettingStatus_SpeedLimitterSettingsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OATAlert, RTE_VAR_INIT) Rte_Mdl_DASSettings_ppOATAlertSettings_CurrentOATAlertSettingsVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DTCStatusArrayT, RTE_VAR_INIT) Rte_Mdl_DTC_ppAllDTCStatus_AllDTCStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DTCIdT, RTE_VAR_INIT) Rte_Mdl_DTC_ppAllDTCStatus_DummyCurrentDTCId; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DTCCurrentStatusT, RTE_VAR_INIT) Rte_Mdl_DTC_ppAllDTCStatus_DummyCurrentDTCStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DiagFaultStatesType, RTE_VAR_INIT) Rte_Mdl_DTC_ppEthernetLinkFaultSts_EthernetLinkFaultSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DiagFaultStatesType, RTE_VAR_INIT) Rte_Mdl_DTC_ppSR_ppEatherportstate_TIEatherFaultState_Eathernetfaultst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_DTE_ppCurrentDTE_CurrentDTEValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DTEWarningType, RTE_VAR_INIT) Rte_Mdl_DTE_ppCurrentDTE_DTESecondaryWarningStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DTEWarningType, RTE_VAR_INIT) Rte_Mdl_DTE_ppCurrentDTE_DTEWarningStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DiagWriteDIDT, RTE_VAR_INIT) Rte_Mdl_DataAdapter_ppDIDconfigDummy_DaigDIDNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NvMJobResultRI, RTE_VAR_INIT) Rte_Mdl_DataAdapter_ppMfgDIDComplition_MfgDIDComplition; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IllumCurSteps, RTE_VAR_INIT) Rte_Mdl_Dimming_ppCurrentDimStep_CurrentIllumStep; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dimming_ppDimmingBlankOutSignalSts_DimmingBlankOutSignalSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DimmingModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppDimmingMode_CanOutDimmngMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DimmingModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppDimmingMode_DialPointerDimmngMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DimmingModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppDimmingMode_ExtIllumDimmngMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DimmingModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppDimmingMode_NightRheostatedLightMaxPercent; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DimmingModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppDimmingMode_TftDimmngMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(GcarEffectModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppGcarEffectMode_GcarEffectState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Dimming_ppGcarReloadValue_RetriggerReloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dimming_ppIllumCurrStepsCanout_IllumCurNightRheoCanOutPer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dimming_ppIllumPopUpStatus_IllumCurSteps; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IllumPopUpTrigger, RTE_VAR_INIT) Rte_Mdl_Dimming_ppIllumPopUpStatus_IllumPopupNewTrigger; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PopUpStatus, RTE_VAR_INIT) Rte_Mdl_Dimming_ppIllumPopUpStatus_IlluminationPopUpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EffectModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppWelcomeEffectMode_DialEffectState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EffectModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppWelcomeEffectMode_PointerEffectState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EffectModeType, RTE_VAR_INIT) Rte_Mdl_Dimming_ppWelcomeEffectMode_TftEffectState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(GuageEffectModeStatus, RTE_VAR_INIT) Rte_Mdl_Dimming_ppWelcomeModeStatus_GaugeEffectModeStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_DippedBeam_ppDippedBeamTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DoorAjarPayloadS, RTE_VAR_INIT) Rte_Mdl_DoorAjar_ppDoorAjarPayload_DoorAjarWarningPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_EPKBWARNING_ppParkingBrakeStatustoSigma_Dat_PKBStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DriveModePayloadS, RTE_VAR_INIT) Rte_Mdl_EcoMode_ppDrivingModePayload_DriveModePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_EcoMode_ppEcoTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Ect_ppDispEngineTempValue_EngineTempDispValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Ect_ppEngineTempValue_EngineTempValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EnergyFlowStatusS, RTE_VAR_INIT) Rte_Mdl_EnergyFlow_pp_EnergyFlowData_CurrentEnergyFlowData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FEBIndicatorStatusT, RTE_VAR_INIT) Rte_Mdl_FEB_ppFEBIndicatorStatus_FEBIndicatorCurrentStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FrontVehReminderT, RTE_VAR_INIT) Rte_Mdl_FrontVehReminder_ppFrontVehReminderPayload_FrontVehRem; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FuelFillModeType, RTE_VAR_INIT) Rte_Mdl_FuelCore_ppFuelCoreOutput_CurrentFuelFillMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FuelInitStatus, RTE_VAR_INIT) Rte_Mdl_FuelCore_ppFuelCoreOutput_CurrentFuelInitStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FuelSensorStatusT, RTE_VAR_INIT) Rte_Mdl_FuelCore_ppFuelCoreOutput_CurrentFuelSensorStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_FuelCore_ppFuelCoreOutput_CurrentFuelSloshFLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(KeyOffProcessStatus, RTE_VAR_INIT) Rte_Mdl_FuelCore_ppFuelCoreOutput_CurrentKeyOfProcessingStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FuelSensorRawStatusT, RTE_VAR_INIT) Rte_Mdl_FuelCore_ppFuelCoreOutput_FuelSensorTransFaultStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Grow_ppGrowTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_HDCInd_ppHDCIndTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_HSA_ppHSATTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_ICC_ppHmiInAD1L3_CCDistance_AD1L3_CCDistance; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PopUpStatus, RTE_VAR_INIT) Rte_Mdl_ICC_ppICCPopup_ICCVehicleDisplayDistancePopup; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICCPopupPayloadT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICCPopupPLStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSControlInstructionT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSControlInstruction; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSFrontCarImageDistanceT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSFrontCarImageDistance; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSFrontCarImageT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSFrontCarImagePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSFrontCarImageSizeT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSFrontCarImageSize; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSLaneColorT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSLeftLanePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSLaneColorT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSRightLanePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSStatusInstructionT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSStatusInstruction; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSSteeringIconDisplayT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSSteeringIconDisplay; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ICSVehicleDisplayDistanceIndT, RTE_VAR_INIT) Rte_Mdl_ICC_ppICSStatus_ICSVehicleDisplayDistancePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UIIdmPriorityDisplayS, RTE_VAR_INIT) Rte_Mdl_IDMMainDisplay_ppIdmMainDisplayStates_IDMMainDisplayStates; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BSIStatusType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSDiagUpdate_BSIStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LDPStatusType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSDiagUpdate_LDPStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSICONCF, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSIconCfUpdate_ITS_Icon_Cf; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BSWBSIMainMenuType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_BSIBSWMainMenuRightPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BSWBSIMainMenuType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_BSIBSWPMainMenuLeftPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSMainMenuIconType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_BSIMainMenuIconStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CaptionStatus, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_BSWBSIMainMenuCaptionStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSMainMenuIconType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_BSWMainMenuIconStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSMainMenuIconType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_DCAMainMenuIconStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CaptionStatus, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_FCWMainMenuCaptionStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSMainMenuIconType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_FCWMainMenuIconStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(FCWMainMenuType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_FCWMainMenuPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSMainMenuIconType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_LDPMainMenuIconStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CaptionStatus, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_LDWLDPMainMenuCaptionStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LDWLDPMainMenuType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_LDWLDPMainMenuLeftPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LDWLDPMainMenuType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_LDWLDPMainMenuRightPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSMainMenuIconType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSMainMenuPayload_LDWMainMenuIconStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSOpngMovieStatus, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSOpngMovie_ITSDisplayAfterOpngMovieStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BSIBSWType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSPayload_BSIBSWPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(LDPLDWType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSPayload_LDPLDWPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSAccelPedalHighS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_AccelPedalHighPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSBadWeatherS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_BadWeatherPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSCameraFaultS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_CameraFaultPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSCleanUpFrontCameraS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_CleanFrontViewCameraPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSFEBSensorBlockedS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_FEBSensorBlocked; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSFrontRadarBlockedS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_FrontRadarBlockedPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSHandleReleaseS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_HandleRelease; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(InterruptionMessageType, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_ItsStatusCheckNormalPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSNotOperateS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_NotOperatePayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSSideRadarBlockedS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_SideRadarBlockedPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSSlipperyRoadS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_SlipperyRoadPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSSystemFaultS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_SystemFaultWarningPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ITSVDCOffS, RTE_VAR_INIT) Rte_Mdl_ITS_ppITSWarningPayload_VdcOffPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_IdlStpInd_ppIdleStpDiagPayload_IdlStpDiagPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdleStpIndType, RTE_VAR_INIT) Rte_Mdl_IdlStpInd_ppIdleStpIndPayload_IdleStpIndicatorPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_IdlStpInd_ppSailingStopTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdleStopState, RTE_VAR_INIT) Rte_Mdl_IdleStopSetting_ppIdleStopActivationStatus_IdleStopActivationStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdleStopState, RTE_VAR_INIT) Rte_Mdl_IdleStopSetting_ppIdleStopGuidanceWarning_GuidanceWarning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_IdleStopSetting_pp_IdleStopFuelCons_IdleStopCo2CLTSavedVolume; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_IdleStopSetting_pp_IdleStopFuelCons_IdleStopCo2VLTSavedVolume; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_IdleStopSetting_pp_IdleStopFuelCons_IdleStopFuelConsumption; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdleStopCLTTimeS, RTE_VAR_INIT) Rte_Mdl_IdleStopSetting_pp_IdleStopTime_CumulativeIdleStopTime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdleStopTimeS, RTE_VAR_INIT) Rte_Mdl_IdleStopSetting_pp_IdleStopTime_TripIdleStopTime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdleStopVLTTimeS, RTE_VAR_INIT) Rte_Mdl_IdleStopSetting_pp_IdleStopTime_VehicleLifeTime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Hmi_Adapter_rpCurrentIKeyMainMenuScn_CurrentMainMenu; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IkeyTypeT, RTE_VAR_INIT) Rte_Mdl_Ikey_Link_ppIkeyStates_CurrentIkeyS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_LowWaterTemp_ppLowWaterTempTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_MstrWrn_ppMstWrnRedTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_MstrWrn_ppMstWrnYellowTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SInt8, RTE_VAR_INIT) Rte_Mdl_OAT_ppOATVal_CurrentOATValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_OAT_ppOAT_DEM_Val_CurrentOATDEMValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_OAT_ppOAT_SIGMA_Val_CurrentOATSIGMAValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_OCS_ppOCSPayload_OCSRemDistance; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_OCS_ppOCSPayload_OCSServNoWarn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_ODOff_ppODOffTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_ODOff_ppSportTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentCalculatedOdoValue_CalculatedOdoValueInDeciMeter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentCalculatedOdoValue_CurrentCalculatedOdoValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripMaintenance_CurrentTripFilter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripMaintenance_CurrentTripOilAndFilter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripMaintenance_CurrentTripOthers; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripMaintenance_CurrentTripTyre; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripValues_CurrentTripAValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripValues_CurrentTripBValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripValues_CurrentTripDistanceValue1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripValues_CurrentTripDistanceValue2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppCurrentTripValues_CurrentTripDistanceValue3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppOdoKMMilesValue_OdoKMMilesValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Odo_ppOdotoTripComp_CurrentCalculatedOdoValueTripComp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OilSensorStatusT, RTE_VAR_INIT) Rte_Mdl_OilLevelSensor_ppOilLevelSensorSts_MdlOilSensorCurrentStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_OilPre_ppOilPreTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PilotDrivePayloadS, RTE_VAR_INIT) Rte_Mdl_PilotDrive_Indicator_ppPilotDriveAD1L3_Payload_PilotDriveAd1l3PayloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PilotDrivePayloadS, RTE_VAR_INIT) Rte_Mdl_PilotDrive_Indicator_ppPilotDrive_Payload_PilotDrivePayloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Poslmp_ppPOSTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ChargeGaugeDataS, RTE_VAR_INIT) Rte_Mdl_PowerGauge_ppChargeGaugeData_TotalChargeDisplay; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_PowerGauge_ppDiagPwrGaugeData_PowerGaugeData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PowerGaugeDataS, RTE_VAR_INIT) Rte_Mdl_PowerGauge_ppPowerGaugeData_TotalPowerDisplayTypeA; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PowerGaugeTypeBDataS, RTE_VAR_INIT) Rte_Mdl_PowerGauge_ppPowerGaugeTypeBData_TotalPowerDisplayTypeB; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_PowerGauge_ppPowerScaleData_Powerscale; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(REBIndicatorPayload, RTE_VAR_INIT) Rte_Mdl_REB_ppREBIndPayload_CurrentREBIndicatorPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_REB_ppREBTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(RESPayload, RTE_VAR_INIT) Rte_Mdl_RES_ppRESPayload_RESWarningPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Ready_ppReadyTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ChimeRequestT, RTE_VAR_INIT) Rte_Mdl_RearSeatBelt_ppRSBChimeStatus_RSBChimeStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(RSBDuringWarn, RTE_VAR_INIT) Rte_Mdl_RearSeatBelt_ppRSBDuringWarningSts_RSBduringStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_RearSeatBelt_ppRSBTelltaleStatus_RSBTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(RSBWarningPayloadS, RTE_VAR_INIT) Rte_Mdl_RearSeatBelt_ppRSBWarningStatus_RSBWarningPayloadStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_RearSeatBelt_ppRSBWarningTriggerStatus_RSBWarningStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(RSBwithODSstsT, RTE_VAR_INIT) Rte_Mdl_RearSeatBelt_ppRSBwithODSstatus_RSBODSstatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BatterySOCS, RTE_VAR_INIT) Rte_Mdl_SOC_ppBatSOCStatus_BatterySOCDisplay; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EnerFlowSOCBarColorT, RTE_VAR_INIT) Rte_Mdl_SOC_ppEnergyFlowBatSOCSts_EnergyFlowBattSOCDisp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_ABSstateDisplayRequest_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_FunctionalLimit_3695d174; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_StatusDisplay_3695d174; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_SteeringWheelTakeOverAlert_3695d174; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleEffect1_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleEffect2_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleEffect3_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleEffect4_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleEffect5_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleEffect6_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleEffect7_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleEffect8_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionX_1_c3159694; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionX_2_c3159694; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionX_3_c3159694; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionX_4_c3159694; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionX_5_f2fd8c09; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionX_6_f2fd8c09; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionX_7_f2fd8c09; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionX_8_f2fd8c09; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionY_1_c3159694; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionY_2_c3159694; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionY_3_c3159694; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionY_4_c3159694; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionY_5_f2fd8c09; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionY_6_f2fd8c09; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionY_7_f2fd8c09; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehiclePositionY_8_f2fd8c09; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleStatus1_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleStatus2_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleStatus3_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleStatus4_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleStatus5_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleStatus6_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleStatus7_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AD_VehicleStatus8_65629d20; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AEB_FCWactivationState2_248fad54; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AEB_FailureDisplay2_248fad54; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AEB_StatusDisplay2_v2_248fad54; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AIRBAGMalfunction_39bc2e85; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_ALC_HandsRequest_3695d174; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_ATCVT_RangeIndicationExtended_51c9fa50; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_ATCVT_RangeIndicationForDisplay_3913a580; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AT_GearShiftRefused_51c9fa50; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AT_Parkfailure_08fbbf1d; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_AirbagWarningLampCheck_39bc2e85; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_BattWarnReq_Level_Hi_ECM_v2_bf9c7f4f; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_BattWarnReq_Level_Hi_USM_v2_f8b1a02a; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRBSfailureDisplayAlert_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_ACU_A101_39bc2e85; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_ADAS_A110_e12893da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_ADAS_A139_3695d174; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_ATCU_A110_08fbbf1d; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_ATCU_A113_3913a580; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_BCM_A107_2c19a566; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_BCM_A110_25149b76; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_EBA_A2_bc0cc2ad; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_ECM_A108_bf9c7f4f; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_EPKB_A101_d3758951; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_EPS_A101_c6e0ce6a; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_USM_A101_f8b1a02a; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_CRC_VDC_A113_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_ACU_A101_39bc2e85; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_ADAS_A110_e12893da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_ADAS_A139_3695d174; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_ATCU_A110_08fbbf1d; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_ATCU_A113_3913a580; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_BCM_A107_2c19a566; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_BCM_A110_25149b76; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_EBA_A2_bc0cc2ad; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_ECM_A108_bf9c7f4f; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_EPKB_A101_d3758951; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_EPS_A101_c6e0ce6a; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_USM_A101_f8b1a02a; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Clock_VDC_A113_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DoorLockRefuseToLockAlertDisplay_7c26de3b; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_DynamicBrakingDisplay_d3758951; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EBA_MajorFailure_bc0cc2ad; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EBA_MinorFailure_bc0cc2ad; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EBAfailureDisplayAlert_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EBDstateDisplayRequest_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EPB_BindingStatusDisplay_d3758951; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EPB_MalfunctionDisplay_d3758951; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EPB_TightenRequestUnavailable_d3758951; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_EPSWarning_c6e0ce6a; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_FlashingIndicatorStatusDisplay_2c19a566; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_FrontFogLightsDisplay_836390c2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_GSITargettedGearDisplayRequest_b49615a5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_HEV_SystemFailureDisplay_v2_65076287; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_HighBeamDisplay_da51d58f; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_KeyReminderAlert_7c26de3b; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_LCA_StatusDisplay_v2_1c6a89d9; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_LCA_SteeringWheelDisplay_74b0d609; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_LCA_SteeringWheelTakeOverAlert_e12893da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_LowVacPWT_RestartImpossibleAlert_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MeterRing_Illumination_Request_7c26de3b; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_NeutralHoldModeMessage_51c9fa50; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_ParkingBrakeBindingStatus_eda5fb4c; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_PositionLightsDisplay_7c26de3b; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_PositionLightsOmissionWarning_b28b8a5f; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_RESstatus_25149b76; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_RearFogLightStateDisplay_25149b76; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_RegenBrakingLevelDisplay_60431d19; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_SSA_StateLamp_a6b84962; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_ShiftIndicator_b49615a5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_SmartKeylessInformationDisplay_836390c2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_StopStartInformationDisplay_2309048c; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_VDCdeactivationDisplayRequest_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_VDCstateDisplayRequest_ffa0e7da; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SigmaFrameT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVSSData_SigmaFrameData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SigmaVSS_T, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVSSData_SigmaVSSDData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BaseVoltageT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_BaseVoltageData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CutOffMaskT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_CutOffMaskData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DistanceUnitT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_DistanceUnitData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ECUVoltageT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_ECUVoltageData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ExtTempT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_ExtTempData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(GadeT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_GadeData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HandBrakeT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_HandBrakeData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IGNStatusT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_IGNStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MasterWakeupCommandT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_MasterWakeupCommandData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ClockType, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_SigmaTime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SlaveRefuseToSleepT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_SlaveRefuseToSleepData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_VTDDelayTime; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_VTDSigmaNOV; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehicleSpeedT, RTE_VAR_INIT) Rte_Mdl_Sigma_ppSigmaVTDData_VehicleSpeedData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Slow_ppSlowIndicatorTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SonarIndPayloadS, RTE_VAR_INIT) Rte_Mdl_Sonar_ppSonarInd_Payload_SonarIndPayloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PopUpStatus, RTE_VAR_INIT) Rte_Mdl_Sonar_ppSonarStatusChkDsp_SonarStatusChkDsp; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SonarPayloadS, RTE_VAR_INIT) Rte_Mdl_Sonar_ppSonarWarningPayload_SonarWarningPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_ppDigiSpeedValueInKMPH_DigiSpeedValueInKMPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_ppDigiSpeedValueInMPH_DigiSpeedValueInMPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_ppMPHSpeedVal_SpeedValueInMPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Speed_ppOvSpdTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DefaultUnit_T, RTE_VAR_INIT) Rte_Mdl_Speed_ppSpeedDefaultUnit_DefaultSpeedUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_Mdl_Speed_ppSpeedPeriodValue_SpeedPeriodValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_ppSpeedValue_SpeedValueInKMPH; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehicleCondition_T, RTE_VAR_INIT) Rte_Mdl_Speed_ppVehicleCondition_VehicleConditionvalue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(BrakeLampStateT, RTE_VAR_INIT) Rte_Mdl_StopLamp_ppBrakeLampDisplayStatus_BrakeLampDisplayStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ad1lv3TJPPayloadS, RTE_VAR_INIT) Rte_Mdl_TJPIND_ppAd1lv3TJP_Payload_Ad1lv3TJPPayloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TJPPayloadS, RTE_VAR_INIT) Rte_Mdl_TJPIND_ppTJP_Payload_TJPPayloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TPMS_ppTPMSTelltaleStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TellTaleState_T, RTE_VAR_INIT) Rte_Mdl_TPMS_pp_TPMS_TT_StatusDiag_TellTaleState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TPMSPayloadS, RTE_VAR_INIT) Rte_Mdl_TPMS_pp_TPMS_paylod_TPMSPayloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ECOModeReport, RTE_VAR_INIT) Rte_Mdl_TPMSSettings_ppTPMSEcoSetStatus_TPMSECOAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_TSR_ppTSRSpeedGuidanceSpeedValue_TSRSpeedGuidanceSpeedValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TsrSpeedGuide_T, RTE_VAR_INIT) Rte_Mdl_TSR_ppTSRSpeedGuidanceSts_TSRSpeedGuidanceSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TSRPayloadS, RTE_VAR_INIT) Rte_Mdl_TSR_ppTsrPayload_TSRPayloadCurValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_ppEngineRPMValue_EngineRPMValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAFEValue_AFEValue1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAFEValue_AFEValue2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAFEValue_AFEValue3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdlingState, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAFEVehicleMovedSt_VehicleMovedSt1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdlingState, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAFEVehicleMovedSt_VehicleMovedSt2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdlingState, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAFEVehicleMovedSt_VehicleMovedSt3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAVSValue_AverageVehicleSpeed1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAVSValue_AverageVehicleSpeed2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripComp_ppAVSValue_AverageVehicleSpeed3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(PopUpStatus, RTE_VAR_INIT) Rte_Mdl_TripComp_ppBFEPopupstatus_BFEPopupStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripComp_ppBFEValue_BFEValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(EMSStatusT, RTE_VAR_INIT) Rte_Mdl_TripComp_ppEMSStatus_EMSStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HFEValueType, RTE_VAR_INIT) Rte_Mdl_TripComp_ppHFEValue_HFEValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripComp_ppIFEValue_IFEValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TripTimeS, RTE_VAR_INIT) Rte_Mdl_TripComp_ppTripTimeValue_TripTimeValue1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TripTimeS, RTE_VAR_INIT) Rte_Mdl_TripComp_ppTripTimeValue_TripTimeValue2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TripTimeS, RTE_VAR_INIT) Rte_Mdl_TripComp_ppTripTimeValue_TripTimeValue3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IdlingState, RTE_VAR_INIT) Rte_Mdl_TripComp_ppVehicleIdling_VehicleIdling; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HFE2MinsValueType, RTE_VAR_INIT) Rte_Mdl_TripCompEV_ppHFE2MinsValue_HFE2MinsValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_TripCompEV_ppRechargeFreeMile_RechargeFreeMileVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DistanceUnit, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDefaultUnitsAndLang_DefaultDistanceUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Language, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDefaultUnitsAndLang_DefaultLanguage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MilageUnits, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDefaultUnitsAndLang_DefaultMilageUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TpmsUnit, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDefaultUnitsAndLang_DefaultTPMSUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TempUnit, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDefaultUnitsAndLang_DefaultTempUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DistanceUnit, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDispayUnitsAndLanguage_CurrentDistanceUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MilageUnits, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDispayUnitsAndLanguage_CurrentFuelUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Language, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDispayUnitsAndLanguage_CurrentLanguage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TpmsUnit, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDispayUnitsAndLanguage_CurrentTPMSUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TempUnit, RTE_VAR_INIT) Rte_Mdl_UnitLangSettings_ppDispayUnitsAndLanguage_CurrentTempUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_VCR_ppVCRDisplayValue_BoostPressure; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_VCR_ppVCRDisplayValue_VCRCompressionRatio; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_VSPOff_ppVSPOffTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorAd2Payload_CruiseIndicatorPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorAd2Payload_CurrentCruiseSpeedUnitColor; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorAd2Payload_CurrentLaneAction; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorAd2Payload_SpeedIccGuidance_Color; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CruisePayload, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorPayload_CruiseIndicatorPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorPayload_CruiseSpeedValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Cruisiccguidance, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorPayload_CruisiccguidanceState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CruiseSpeedUnitColorT, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorPayload_CurrentCruiseSpeedUnitColor; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CurrentLaneActionUnitT, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruiseIndicatorPayload_CurrentLaneAction; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CruiseCancelPopUpEnum, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruisePopup_CancelReasonPopup; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CruisPopUpTrigger, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruisePopup_CancelReasonPopupPopupNewTrigger; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CruiseSlPopUpEnum, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruisePopup_CruisSlPopup; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CruisPopUpTrigger, RTE_VAR_INIT) Rte_Mdl_cruise_ppCruisePopup_CruisSlPopupPopupPopupNewTrigger; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ePedalModeStatus, RTE_VAR_INIT) Rte_Mdl_ePedal_ppePedalModeDisplayStatus_ePedalModeDisplay; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_hibeam_ppAutoHiLoTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_hibeam_ppHbeamTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HiBeamPopUpT, RTE_VAR_INIT) Rte_Mdl_hibeam_ppHiBeamPopUpStatus_HiBeamPopUpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HiBeamPopUpTrigger, RTE_VAR_INIT) Rte_Mdl_hibeam_ppHiBeamPopUpStatus_HiBeamPopupNewTrigger; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OpeningMovieStatus, RTE_VAR_INIT) Rte_Mdl_opng_movie_ppOpngMovieStatus_OpngMovieStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_seatbelt_ppSeatBeltTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_tcan_Adapter_pp_METER_CAN_CorruptionDetection_ComData_METER_CAN_CorruptionDetection; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_tcan_Adapter_pp_METER_Status_ComData_METER_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_OilChangeCounterReset_5e4b4c19; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootApplicationRandomNumber_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootForcedLoaderModeDetected_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootMagicFlag_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootVehicleStateDetected_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacAppCount; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacFotaCount; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacRollbackCount; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CoherencyDTCState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerHWReference_number; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerReference2_number; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerReference_number; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ECUCompatibilityDTCState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ECUGeneralMemoryFailureDTCState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fingerprint; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_FotaUpdateStatus_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_FotaUpdateStatus_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_ActivePartition; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Att_Cnt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_CancelCounter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_ConfigurationSignatureError; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Correlator_Id; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_DecryptionResult; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_F_virgin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_FlashCompletedAddress; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_GipDtcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_GlobalDtcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_HashValueUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_IVectorData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_IncrementalCounter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Mileage_Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_PreviousState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RebootCompleteFlag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RemainingDataSize; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RollbackCompleteFlag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RollbackInprogress; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_State; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VIPDownloadSkipFlag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VipDtcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Virgin_Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VlanOpenStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_A_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_A_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_B_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_B_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_C_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_C_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_D_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_D_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_E_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_E_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_H_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_H_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_I_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_I_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_J_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_J_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_K_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_K_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_L_FLPS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_L_RADS; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_GeneralMemoryFailureDTCState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_AlertSetting_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Car_color_Eco_Welcome_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Key_Link_UserLogin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Lang_Navi_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte1_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte2_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_OperationGuidance_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_PersonalDisplay_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_TPMS_Temp_unit_setting_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Top_layer_contents_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_illum_mode_step_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_illum_night_step_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_IllumMeasuredMaxIntensity; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_IllumReferenceMaxIntensity; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ManufacturingModeRequested; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_AlertSettingSave_Key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_AlertSetting_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_FaultCounters_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_KeyId; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Key_Link_UserLogin; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Key_Link_status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Lang_Navi_Ikey_link_key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Lang_Navi_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_OperationGuidance_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Operation_Guidance_Key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_PersonalDisplay_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Personal_Display_Key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Sound_Channel_Vol; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Sound_Mixer_Op_Vol; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_mode_step_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_mode_step_key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_night_step_User; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_night_step_key; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Analog_Measurements_Calibration; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_AssemblyPlantNum; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Assembly_Manufacturing_date; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Customer_reference; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_100_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_200_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_300_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_310_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_400_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_410_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_420_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_430_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_440_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_450_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_500_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_900_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F190_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1A2_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_FE11_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_EquippedPCBVisteonPartNum; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltCount; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltCount; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_NvM_Revision_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_NvM_Version_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PCBSerialNum; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMBigLeftPointerCalibrationGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMBigRightPointerCalibrationGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMLeftDialCalibrationGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMRightDialCalibrationGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMSmallLeftPointerCalibrationGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMSmallRightPointerCalibrationGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibration; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibrationGain; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_ProductVisteonPartNum; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Reset_Counters_Reading; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SMDPlantNum; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaDataIndexArray; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaNumberValueNoTrigger; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_10; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_11; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_12; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_13; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_14; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_15; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_7; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_8; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_9; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_10; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_11; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_12; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_13; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_14; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_15; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_7; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_8; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_9; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaStoreNoTriggerDTCIndex; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaStoreTriggerDTCIndex; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaTriggerNumberValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_10; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_11; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_12; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_13; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_14; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_15; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_7; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_8; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_9; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_AC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FC; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FCT; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_ICT; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_WS2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_VehicleManufacturerSparePartNumberGIP; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_VehicleManufacturerSparePartNumberVIP; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Visteon_Product_Config_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_XFuelValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_YFuelValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_vehicleManufacturerECUHardwareNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Max; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Min; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Max; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Min; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3Min; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3max; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRank_T1Min_Time; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E1_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E2_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E3_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E4_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_RearDoorAlert_T1_Time; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_A_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_B_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_PCB_serial_number_AssemblymanufDate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ProgLimitCntr; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Reserved_Health_Management_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_SecurebootCount; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Signature; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Signature_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ValidDTCState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ValidDTCState_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractStub_AudioFeatureAvailability_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_ApplicationRandomNumber, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_ApplicationRandomNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_LoaderModeDetected, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_LoaderModeDetected; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_MagicFlag, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_MagicFlag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_VehicleStateDetected, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_VehicleStateDetected; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FBL_NVM, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBL_NVM; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_CustomerHWReference, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerHWReference; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_CustomerReference2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerReference2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_CustomerReference, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_CustomerReference; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Fingerprint, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Fingerprint; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FotaUpdateStatus, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FotaUpdateStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FotaUpdateStatus_1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FotaUpdateStatus_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FOTA_NVM, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_NVM; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FOTA_NVM_DIGHRNIG, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FOTA_NVM_DIGHRNIG; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FeaturesConst, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FeaturesConst6, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_GUST_USER_LOGIN, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_GUST_USER_LOGIN; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractStub_HFFeatureAvailability_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_IllumPWMCalib, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_IllumPWMCalib; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_MFG_DID_PRODUCT, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_MFG_DID_PRODUCT; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_IKEY_BLK, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_IKEY_BLK; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_USER_LOGIN, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_USER_LOGIN; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_NVM_HM_FaultCounters, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_NVM_HM_FaultCounters; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID100, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID100; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID200, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID200; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID300, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID300; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID310, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID310; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID400, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID400; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID410, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID410; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID420, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID420; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID430, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID430; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID440, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID440; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID450, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID450; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID500, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID500; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDID900, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDID900; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDIDF190, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDF190; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDIDF1A2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDF1A2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_DiagDIDFE11, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDFE11; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_GaugeEctCalib, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeEctCalib; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_GaugeFuelCalib, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuelCalib; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_IDLE_STOP, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_IDLE_STOP; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_NvM_Revision_Value, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_NvM_Revision_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_NvM_Version_Value, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_NvM_Version_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Odometer_BLK1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Odometer_BLK2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Odometer_BLK3, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Odometer_BLK4, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Odometer_BLK5, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_GaugeRPMCalib, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeRPMCalib; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_DTC_INDEX_BLK, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_DTC_INDEX_BLK; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK0, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK10, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK10; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK11, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK11; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK12, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK12; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK13, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK13; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK14, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK14; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK15, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK15; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK3, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK4, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK5, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK6, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK7, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK7; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK8, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK8; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_SSD_BLK9, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK9; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK0, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK0; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK10, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK10; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK11, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK11; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK12, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK12; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK13, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK13; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK14, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK14; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK15, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK15; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK3, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK4, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK5, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK6, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK6; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK7, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK7; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK8, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK8; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_SIGMA_VTD_BLK9, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK9; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_GaugeSpdCalib, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_GaugeSpdCalib; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FeatureConfigCalib, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeatureConfigCalib; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FuelCalcCalib, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FuelCalcCalib; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractStub_NaviSourceAvailability_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FeaturesConst1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FeaturesConst4, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FeaturesConst2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FeaturesConst5, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst5; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FeaturesConst3, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_PCBSerialNumber, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_PCBSerialNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Reserved_Health_Management, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Reserved_Health_Management; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractStub_SMSFeatureAvailability_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Signature, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Signature; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_Signature_1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_Signature_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractStub_Steeringwheel_SourceAvailability_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractStub_VRFeatureAvailability_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FBLValidDTCState, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLValidDTCState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_FBLValidDTCState_1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_FBLValidDTCState_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDisplaySetPower, RTE_VAR_INIT) Rte_ModeMgr_ppSRDisplaySetPower_DisplaySetPowerData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(tModeMgrMeetMode, RTE_VAR_INIT) Rte_ModeMgr_ppSRMeetMode_MeetModeStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(tResetReason, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeResetReason_ResetReason; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(tSWCMode, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeSWCRequestGroup0_RequestedMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(tSWCMode, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeSWCRequestGroup1_RequestedMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(tSWCMode, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeSWCRequestGroup2_RequestedMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(tSWCMode, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeSWCRequestGroup3_RequestedMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_ModeMgr_ppSRModeSleepStatus_PreSleep; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_ModeMgr_ppSRPhasedRead_Status_phase1readcompleted; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_ModeMgr_ppSRPhasedRead_Status_phase2readcompleted; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_ModeMgr_ppSRPhasedRead_Status_phase3readcompleted; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_ModeMgr_ppSRPhasedRead_Status_phase4readcompleted; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_pp_SR_NvMExt_WakeupStatus_WakeupFlag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_OdoCtrl_ppCurrentOdoValueInNVM_CurrentOdoMeterValueInNVM; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_HVP0Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_HVSD0Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_HVSD1Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_LVP0Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_LVP1Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD0Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD1Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD2Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD3Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_LVSD4Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_PowerCdd_ppSR_PowerCdd_AVP_SVPFlag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDisplayCurrentState, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFotaVinRequest, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_FotaVinRequest_FotaVinRequestData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SGFXScreenID, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_GFXScreenID_GFXScreenIDData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SHMISleepStatus, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_HMISleepStatus_HMISleepStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SPowerSystemState, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDimmingData, RTE_VAR_INIT) Rte_View_Dimming_pSR_DimmingData_DimmingDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TFTIgnBlankSts_T, RTE_VAR_INIT) Rte_View_Dimming_ppIgnBlankOutCheck_IgnBlankOutCheck; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt32, RTE_VAR_INIT) Rte_View_Dimming_ppSR_ppDimming_TIDimmingIf_TftDimmingCmd; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(MCANFaultT, RTE_VAR_INIT) Rte_CMcan_cdd_ppCommunicationMcanFault_CommunicationManagementReception; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MCANFaultT, RTE_VAR_INIT) Rte_CMcan_cdd_ppCommunicationMcanFault_CommunicationManagementTransmission; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_MCAN_POPUP_T, RTE_VAR_INIT) Rte_Ctrl_McanPopup_ppCurrntPopupStatus_CurrentActiveMcanPopup; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_MDL_PhoneMcan_ppMcanPhoneGetTextData_SMSRxdText; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_MDL_PhoneMcan_ppMcanPhoneGetTextData_TelRxdText; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_SMS_STATE_T, RTE_VAR_INIT) Rte_MDL_PhoneMcan_ppSmsState_SmsStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEL_INFO_T, RTE_VAR_INIT) Rte_MDL_PhoneMcan_ppTelData_TelInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEL_WARNING_STATE_T, RTE_VAR_INIT) Rte_MDL_PhoneMcan_ppTelWarningStatus_TelWarnRetSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_VR_INFO_T, RTE_VAR_INIT) Rte_MDL_PhoneMcan_ppVRData_VRInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_AUDIO_SRC_LIST_OPEN_CLOSE, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppAudioSrcListAvail_AudioSrcListOpenClose; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_AUDIO_SOURCE_AVAILABLE_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppAudioSrcListAvail_CurrentAudioSrcAvail; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_AUDIO_UPDATE_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioMode_CurrentAudioSource; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextAudioWarning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextDiscArtist; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextDiscGroup; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextDiscTrack; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextHDRadioArtist; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextHDRadioBroadCast; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextHDRadioCategory; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextHDRadioSongTitle; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextInternetAudioArtist; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextInternetAudioGroup; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextInternetAudioSource; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextInternetAudioTrack; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextRadioBroadCast; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextRadioCategory; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioTextInfo_AudioTextTVBroadCast; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_AUDIOWARNING_UPDATE_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAudioWarningInfo_UiAudioWarning; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_AUX_INFO_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetAuxInfo_UiAuxData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_DISC_INFO_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetDiscInfo_UiDiscData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_HD_RADIO_INFO_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetHDRadioInfo_UiHDRadioData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_INTERNET_AUDIO_INFO_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetIAInfo_UiInternetAudioData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_RADIO_INFO_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetRadioInfo_UiRadioData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TV_INFO_T, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppMcanGetTVInfo_UiTvData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_MCAN_FEATURE_AVAILABILITY, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppSourceAvail_HMIAudioFeatureAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_MCAN_FEATURE_AVAILABILITY, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppSourceAvail_HMIHFFeatureAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_MCAN_FEATURE_AVAILABILITY, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppSourceAvail_HMISMSFeatureAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_MCAN_FEATURE_AVAILABILITY, RTE_VAR_INIT) Rte_Mdl_AudioMcan_ppSourceAvail_HMIVRFeatureAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_NAVI_ARRIVAL_WEATHER_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviArrWeatherInfo_NaviArrivalWeatherInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_NAVI_DISPLAY_MODE_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviDisplayMode_NaviDisplayMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviGuideInfo_NaviGuideCurIntersectionNum; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_NAVI_GUIDE_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviGuideInfo_NaviGuideData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec1_NaviIntSecOneArrowGuideInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec1_NaviIntSecOneLaneData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_LANE_ARROW_TYPE_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec1_NaviIntsecOneLaneArrow; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec2_NaviIntSecTwoArrowGuideInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec2_NaviIntSecTwoLaneData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_LANE_ARROW_TYPE_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec2_NaviIntsecTwoLaneArrow; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec3_NaviIntSecThreeArrowGuideInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec3_NaviInterSecThreeData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_LANE_ARROW_TYPE_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec3_NaviIntsecThreeLaneArrow; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Ul_LANE_ARROW_GUIDE_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec4_NaviIntSecFourArrowGuideInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_NAVI_LANE_CATEGORY_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec4_NaviIntSecFourLaneData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_LANE_ARROW_TYPE_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviLaneInfoIntSec4_NaviIntsecFourLaneArrow; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_MCAN_FEATURE_AVAILABILITY, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviSourceAvailable_HMINaviSourceAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_NAVI_SPEED_LIMIT_INFO_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviSpdLmt_CurrentSpeedLimitStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviStreetName_CurrentStreetName; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviStreetName_StreetNameIntersection_1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviStreetName_StreetNameIntersection_2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviStreetName_StreetNameIntersection_3; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_TEXT_BUFFER_T, RTE_VAR_INIT) Rte_Mdl_NaviMcan_ppNaviStreetName_StreetNameIntersection_4; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(MCAN_TIME_INFO, RTE_VAR_INIT) Rte_Mdl_StgWheelMcan_ppCurrentMcanTime_CurrentMcanTimeValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UI_MCAN_FEATURE_AVAILABILITY, RTE_VAR_INIT) Rte_Mdl_StgWheelMcan_ppMCANClockAvailable_MCANClockAvailability; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(StrgSwT, RTE_VAR_INIT) Rte_Mdl_StgWheelMcan_ppStrgSwStates_StrgSwSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(eBatteryState, RTE_VAR_INIT) Rte_BattMdl_pState_BatteryState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ChecksumStatusT, RTE_VAR_INIT) Rte_CChecksumCdd_ppChecksumStatus_HFlash_Checksum_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ChecksumStatusT, RTE_VAR_INIT) Rte_CChecksumCdd_ppChecksumStatus_ROM_Checksum_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TTBlinkArray, RTE_VAR_INIT) Rte_Ctrl_telltale_ppBlinkStatusArray_TTBlinkStatusArray; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TTFlashMask, RTE_VAR_INIT) Rte_Ctrl_telltale_ppBlinkStatusArray_TTdummyDataForTypes; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_Type, RTE_VAR_INIT) Rte_Ctrl_telltale_ppGetTelltaleStatus_TelltaleFunctionalOpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_Type, RTE_VAR_INIT) Rte_Ctrl_telltale_ppTelltaleStatusOP_TelltaleOpArray; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_ABS_ppABSTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AD1L3StrgIconS, RTE_VAR_INIT) Rte_Mdl_AD2Safety_pp_AD1L3StrgIcon_AD1L3StrgIcon; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehiclePosType, RTE_VAR_INIT) Rte_Mdl_AD2Safety_pp_Ad1l3VehicleStatus_Ad1l3VehiclePos_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehiclePosType, RTE_VAR_INIT) Rte_Mdl_AD2Safety_pp_Ad1l3VehicleStatus_Ad1l3VehiclePos_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehicleStsType, RTE_VAR_INIT) Rte_Mdl_AD2Safety_pp_Ad1l3VehicleStatus_Ad1l3VehicleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Airbag_ppAirbagTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CANNMState, RTE_VAR_INIT) Rte_Mdl_CANNm_ppCANNMState_CurrentCANNmState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_CANNm_ppClusterRefuseToSleepToSigma_ClusterRefuseToSleep; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CANIpWakeUpState, RTE_VAR_INIT) Rte_Mdl_CANWakeUpIp_pp_CanWakeUpIpSt_CANWakeUpIpSt; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Charge_ppChargeTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(AliveCntCrcT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppClkAliveCntStatus_AliveCntCrc; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ClkStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppClkAliveCntStatus_Dummy_AliveCntStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppClkAliveCntStatus_Dummy_CrcStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStatesSpecific_SpecificMdlCrcUpdateDummy; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ACU_A101_ACU_A101CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ADAS_A139_ADAS_A139CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ADAS_A157_ADAS_A157CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ATCU_A110_ATCU_A110CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ATCU_A113_ATCU_A113CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_AVM_A128_AVM_A128CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_BCM_A107_BCM_A107CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_BCM_A110_BCM_A110CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A103_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A110_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A116_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A117_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A119_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A120_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A124_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A125_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A139_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A147_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A148_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A149_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A150_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A151_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A152_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A153_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A154_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A157_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A6_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_N101_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ATCU_A113_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_AVM_A120_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_AVM_A121_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_AVM_A128_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_AVM_A1_CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A103_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A110_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A116_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A117_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A119_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A120_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A124_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A125_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A139_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A147_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A148_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A149_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A150_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A151_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A152_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A153_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A154_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A157_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_A6_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ADAS_N101_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_ATCU_A113_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_AVM_A120_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_AVM_A121_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_AVM_A128_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ComStatus_CrcStates_AVM_A1_ComStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_EBA_A2_EBA_A2CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_ECM_A108_ECM_A108CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_EPKB_A101_EPKB_A101CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_EPS_A101_EPS_A101CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_USM_A101_USM_A101CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(CrcStateT, RTE_VAR_INIT) Rte_Mdl_CrcCdd_ppCrcStates_VDC_A113_VDC_A113CrcUpdate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_EPKB_ppEPBIndicatorTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_EPKB_ppEPBWarningLampTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_EPS_ppEPSTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_EPS_ppEPSredTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_FogInd_ppFFogTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_FogInd_ppRFogTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_IbaAeb_ppIBATTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STT_statusVIP, RTE_VAR_INIT) Rte_Mdl_IpclSafeCommunication_pSR_TT_statusVIP_TT_statusVIPData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_IpclSafeCommunication_ppMonitorFailureStatus_DCIC_CheckSumFailureStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_IpclSafeCommunication_ppMonitorFailureStatus_UART_DataFailureStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_IpclSafeCommunication_ppMonitorFailureStatus_WidgetMonitorFailureStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TelltaleResetDataS, RTE_VAR_INIT) Rte_Mdl_IpclSafeCommunication_ppTTReset_Status_TelltaleResetSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_RbrakeSystemHba_ppRbrakeSystemHbaTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSAPayloadS, RTE_VAR_INIT) Rte_Mdl_SSA_Indicator_ppSSA_Payload_SSAPayloadValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_SSA_Indicator_ppSSTelltaleStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TEPowerVariantInfo, RTE_VAR_INIT) Rte_Mdl_SafetyAdapter_ppEpowerVarientInfo_EpowerVariantInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(RegionInfoT, RTE_VAR_INIT) Rte_Mdl_SafetyAdapter_ppPresentRegionInfo_PresentRegionInfo; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TVariantSwapTT, RTE_VAR_INIT) Rte_Mdl_SafetyAdapter_ppVariantSpecificTTsts_VariantSpecificTTsts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_SailStopInd_ppSailingStopWarnLmpTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_ShiftByWire_TT_ppShiftByWireTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_SystemFail_TT_ppSystemFailTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TJP_ppTJPTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnInd_ppLTurnTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnInd_ppRTurnTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_VDC_ppVDCTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_brake_ppBrakeTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_brakeSystemHba_ppHbaTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_gearshift_ppATShiftIndicatorSts_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DiagGSIPayloadS, RTE_VAR_INIT) Rte_Mdl_gearshift_ppDiagGearPayload_DiagMdlGsiGearNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(GSFutrinfo, RTE_VAR_INIT) Rte_Mdl_gearshift_ppGSConfigurerS_GSIConfiureState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(GSIPayloadS, RTE_VAR_INIT) Rte_Mdl_gearshift_ppGearPayload_GSICurrentPayload; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_gearshift_ppGearShiftIndicatorSts_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_slip_ppSlipTTStatus_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SENS_Adapt_ppBatteryVoltage_BatteryVoltage; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HwPinStatus, RTE_VAR_INIT) Rte_SENS_Adapt_ppBrakeOilStatus_BrakeOilStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SENS_Adapt_ppFuelA2DCounts_lFuelA2DCounts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HwPinStatus, RTE_VAR_INIT) Rte_SENS_Adapt_ppHwDimmingSwStatus_DimmingSwDownStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HwPinStatus, RTE_VAR_INIT) Rte_SENS_Adapt_ppHwDimmingSwStatus_DimmingSwUpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HwIgnStatus, RTE_VAR_INIT) Rte_SENS_Adapt_ppHwIgnStatus_HwIgnitionCurrentStaus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HwPinStatus, RTE_VAR_INIT) Rte_SENS_Adapt_ppHwParkBrakeStatus_ParkBrakeInputStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Strg1BtnType, RTE_VAR_INIT) Rte_SENS_Adapt_ppHwSteeringSWStatus_Strg1Btn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Strg2BtnType, RTE_VAR_INIT) Rte_SENS_Adapt_ppHwSteeringSWStatus_Strg2Btn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HwPinStatus, RTE_VAR_INIT) Rte_SENS_Adapt_ppHwTripResetStatus_TripResetStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HwPinStatus, RTE_VAR_INIT) Rte_SENS_Adapt_ppHwWasherStatus_WasherInputStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IllumOpStatus, RTE_VAR_INIT) Rte_SENS_Adapt_ppIllumOpStatus_CurrentIllumOpStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(OATSensorStatusT, RTE_VAR_INIT) Rte_SENS_Adapt_ppOatTempVal_OATSensorCurrentStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SInt16, RTE_VAR_INIT) Rte_SENS_Adapt_ppOatTempVal_RawOATValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SENS_Adapt_ppSbattA2DCounts_lSbattA2DCounts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SENS_Adapt_ppTFTTempStatus_TFTTempStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TFTTempSensorStatusT, RTE_VAR_INIT) Rte_SENS_Adapt_ppTFTTempVal_TFTTempFailValueShare; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_SENS_Adapt_ppTFTTempVal_TFTTempValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(tt_feedback, RTE_VAR_INIT) Rte_SENS_Adapt_ppTTDiagFeedback_tt_diag_feedback; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_SENS_Adapt_ppTftMonitoringStatus_tft_monitoring_status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_ENUM_TYPE, RTE_VAR_INIT) Rte_View_telltale_ppTelltaleIndexStatus_TTIndex; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_View_telltale_ppTelltaleIndexStatus_TTStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

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

extern VAR(Rte_QRamInfoType, RTE_VAR_NOINIT) Rte_QRamInfo[163]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Rte_QRomInfoType, RTE_CONST) Rte_QRomInfo[163];

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
  Rte_BitType Rte_b8 : 1;
  Rte_BitType Rte_b9 : 1;
  Rte_BitType Rte_b10 : 1;
  Rte_BitType Rte_b11 : 1;
  Rte_BitType Rte_b12 : 1;
  Rte_BitType Rte_b13 : 1;
  Rte_BitType Rte_b14 : 1;
  Rte_BitType Rte_b15 : 1;
  Rte_BitType Rte_b16 : 1;
  Rte_BitType Rte_b17 : 1;
  Rte_BitType Rte_b18 : 1;
  Rte_BitType Rte_b19 : 1;
  Rte_BitType Rte_b20 : 1;
  Rte_BitType Rte_b21 : 1;
  Rte_BitType Rte_b22 : 1;
  Rte_BitType Rte_b23 : 1;
  Rte_BitType Rte_b24 : 1;
  Rte_BitType Rte_b25 : 1;
  Rte_BitType Rte_b26 : 1;
  Rte_BitType Rte_b27 : 1;
  Rte_BitType Rte_b28 : 1;
  Rte_BitType Rte_b29 : 1;
  Rte_BitType Rte_b30 : 1;
  Rte_BitType Rte_b31 : 1;
  Rte_BitType Rte_b32 : 1;
  Rte_BitType Rte_b33 : 1;
  Rte_BitType Rte_b34 : 1;
  Rte_BitType Rte_b35 : 1;
  Rte_BitType Rte_b36 : 1;
  Rte_BitType Rte_b37 : 1;
  Rte_BitType Rte_b38 : 1;
  Rte_BitType Rte_b39 : 1;
  Rte_BitType Rte_b40 : 1;
  Rte_BitType Rte_b41 : 1;
  Rte_BitType Rte_b42 : 1;
  Rte_BitType Rte_b43 : 1;
  Rte_BitType Rte_b44 : 1;
  Rte_BitType Rte_b45 : 1;
  Rte_BitType Rte_b46 : 1;
  Rte_BitType Rte_b47 : 1;
  Rte_BitType Rte_b48 : 1;
  Rte_BitType Rte_b49 : 1;
  Rte_BitType Rte_b50 : 1;
  Rte_BitType Rte_b51 : 1;
  Rte_BitType Rte_b52 : 1;
  Rte_BitType Rte_b53 : 1;
  Rte_BitType Rte_b54 : 1;
  Rte_BitType Rte_b55 : 1;
  Rte_BitType Rte_b56 : 1;
  Rte_BitType Rte_b57 : 1;
  Rte_BitType Rte_b58 : 1;
  Rte_BitType Rte_b59 : 1;
  Rte_BitType Rte_b60 : 1;
  Rte_BitType Rte_b61 : 1;
  Rte_BitType Rte_b62 : 1;
  Rte_BitType Rte_b63 : 1;
  Rte_BitType Rte_b64 : 1;
  Rte_BitType Rte_b65 : 1;
  Rte_BitType Rte_b66 : 1;
  Rte_BitType Rte_b67 : 1;
  Rte_BitType Rte_b68 : 1;
  Rte_BitType Rte_b69 : 1;
  Rte_BitType Rte_b70 : 1;
  Rte_BitType Rte_b71 : 1;
  Rte_BitType Rte_b72 : 1;
  Rte_BitType Rte_b73 : 1;
  Rte_BitType Rte_b74 : 1;
  Rte_BitType Rte_b75 : 1;
  Rte_BitType Rte_b76 : 1;
  Rte_BitType Rte_b77 : 1;
  Rte_BitType Rte_b78 : 1;
  Rte_BitType Rte_b79 : 1;
  Rte_BitType Rte_b80 : 1;
  Rte_BitType Rte_b81 : 1;
  Rte_BitType Rte_b82 : 1;
  Rte_BitType Rte_b83 : 1;
  Rte_BitType Rte_b84 : 1;
  Rte_BitType Rte_b85 : 1;
  Rte_BitType Rte_b86 : 1;
  Rte_BitType Rte_b87 : 1;
  Rte_BitType Rte_b88 : 1;
  Rte_BitType Rte_b89 : 1;
  Rte_BitType Rte_b90 : 1;
  Rte_BitType Rte_b91 : 1;
  Rte_BitType Rte_b92 : 1;
  Rte_BitType Rte_b93 : 1;
  Rte_BitType Rte_b94 : 1;
  Rte_BitType Rte_b95 : 1;
  Rte_BitType Rte_b96 : 1;
  Rte_BitType Rte_b97 : 1;
  Rte_BitType Rte_b98 : 1;
  Rte_BitType Rte_b99 : 1;
  Rte_BitType Rte_b100 : 1;
  Rte_BitType Rte_b101 : 1;
  Rte_BitType Rte_b102 : 1;
  Rte_BitType Rte_b103 : 1;
  Rte_BitType Rte_b104 : 1;
  Rte_BitType Rte_b105 : 1;
  Rte_BitType Rte_b106 : 1;
  Rte_BitType Rte_b107 : 1;
  Rte_BitType Rte_b108 : 1;
  Rte_BitType Rte_b109 : 1;
  Rte_BitType Rte_b110 : 1;
  Rte_BitType Rte_b111 : 1;
  Rte_BitType Rte_b112 : 1;
  Rte_BitType Rte_b113 : 1;
  Rte_BitType Rte_b114 : 1;
  Rte_BitType Rte_b115 : 1;
  Rte_BitType Rte_b116 : 1;
  Rte_BitType Rte_b117 : 1;
  Rte_BitType Rte_b118 : 1;
  Rte_BitType Rte_b119 : 1;
  Rte_BitType Rte_b120 : 1;
  Rte_BitType Rte_b121 : 1;
  Rte_BitType Rte_b122 : 1;
  Rte_BitType Rte_b123 : 1;
  Rte_BitType Rte_b124 : 1;
  Rte_BitType Rte_b125 : 1;
  Rte_BitType Rte_b126 : 1;
  Rte_BitType Rte_b127 : 1;
  Rte_BitType Rte_b128 : 1;
  Rte_BitType Rte_b129 : 1;
  Rte_BitType Rte_b130 : 1;
  Rte_BitType Rte_b131 : 1;
  Rte_BitType Rte_b132 : 1;
  Rte_BitType Rte_b133 : 1;
  Rte_BitType Rte_b134 : 1;
  Rte_BitType Rte_b135 : 1;
  Rte_BitType Rte_b136 : 1;
  Rte_BitType Rte_b137 : 1;
  Rte_BitType Rte_b138 : 1;
  Rte_BitType Rte_b139 : 1;
  Rte_BitType Rte_b140 : 1;
  Rte_BitType Rte_b141 : 1;
  Rte_BitType Rte_b142 : 1;
  Rte_BitType Rte_b143 : 1;
  Rte_BitType Rte_b144 : 1;
  Rte_BitType Rte_b145 : 1;
  Rte_BitType Rte_b146 : 1;
  Rte_BitType Rte_b147 : 1;
  Rte_BitType Rte_b148 : 1;
  Rte_BitType Rte_b149 : 1;
  Rte_BitType Rte_b150 : 1;
  Rte_BitType Rte_b151 : 1;
  Rte_BitType Rte_b152 : 1;
  Rte_BitType Rte_b153 : 1;
  Rte_BitType Rte_b154 : 1;
  Rte_BitType Rte_b155 : 1;
  Rte_BitType Rte_b156 : 1;
  Rte_BitType Rte_b157 : 1;
  Rte_BitType Rte_b158 : 1;
  Rte_BitType Rte_b159 : 1;
  Rte_BitType Rte_b160 : 1;
  Rte_BitType Rte_b161 : 1;
  Rte_BitType Rte_b162 : 1;
} Rte_OsApplication_NonTrusted_QOverflowType;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_QOverflowType, RTE_VAR_NOINIT) Rte_OsApplication_NonTrusted_QOverflow; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_RxTimeout_ABSstateDisplayRequest_ffa0e7da : 1;
  Rte_BitType Rte_RxTimeout_ACC_CancelReason_v2_9be8b02a : 1;
  Rte_BitType Rte_RxTimeout_ACC_CruiseEcoActivationState_cd66cb85 : 1;
  Rte_BitType Rte_RxTimeout_ACC_DistanceSettingDisplay_74b0d609 : 1;
  Rte_BitType Rte_RxTimeout_ACC_StatusDisplay_v2_e12893da : 1;
  Rte_BitType Rte_RxTimeout_ADA1ActivationState_a6b84962 : 1;
  Rte_BitType Rte_RxTimeout_ADAS_Cut_in_Alert_7afec37d : 1;
  Rte_BitType Rte_RxTimeout_ADBCautionDisplay_bb86b44f : 1;
  Rte_BitType Rte_RxTimeout_ADB_ActivationStatusDisplay_8a6eaed2 : 1;
  Rte_BitType Rte_RxTimeout_ADB_FailureDisplay_8d60920f : 1;
  Rte_BitType Rte_RxTimeout_AD_CancelReason_912db933 : 1;
  Rte_BitType Rte_RxTimeout_AD_CurveStatus_548a87bd : 1;
  Rte_BitType Rte_RxTimeout_AD_DriverInformation_a0c5a3ae : 1;
  Rte_BitType Rte_RxTimeout_AD_FunctionalLimit_3695d174 : 1;
  Rte_BitType Rte_RxTimeout_AD_LeftsideLane_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_OwnVehicle_ALCPosition_9a27d3d9 : 1;
  Rte_BitType Rte_RxTimeout_AD_StatusDisplay_3695d174 : 1;
  Rte_BitType Rte_RxTimeout_AD_SteeringWheelTakeOverAlert_3695d174 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleEffect1_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleEffect2_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleEffect3_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleEffect4_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleEffect5_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleEffect6_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleEffect7_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleEffect8_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionX_1_c3159694 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionX_2_c3159694 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionX_3_c3159694 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionX_4_c3159694 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionX_5_f2fd8c09 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionX_6_f2fd8c09 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionX_7_f2fd8c09 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionX_8_f2fd8c09 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionY_1_c3159694 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionY_2_c3159694 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionY_3_c3159694 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionY_4_c3159694 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionY_5_f2fd8c09 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionY_6_f2fd8c09 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionY_7_f2fd8c09 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehiclePositionY_8_f2fd8c09 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleStatus1_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleStatus2_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleStatus3_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleStatus4_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleStatus5_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleStatus6_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleStatus7_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AD_VehicleStatus8_65629d20 : 1;
  Rte_BitType Rte_RxTimeout_AEB_CancelReason_v2_9be8b02a : 1;
  Rte_BitType Rte_RxTimeout_AEB_CyclistAlertRequest2_248fad54 : 1;
  Rte_BitType Rte_RxTimeout_AEB_RadarCancelReason_82f8a6e0 : 1;
  Rte_BitType Rte_RxTimeout_AEB_SoundAlert_v2_6fa79439 : 1;
  Rte_BitType Rte_RxTimeout_AHL_ActivationDisplay_7c26de3b : 1;
  Rte_BitType Rte_RxTimeout_AIRBAGMalfunction_39bc2e85 : 1;
  Rte_BitType Rte_RxTimeout_ALC_HandsRequest_3695d174 : 1;
  Rte_BitType Rte_RxTimeout_APB_BrakePedalRequestDisplay_d3758951 : 1;
  Rte_BitType Rte_RxTimeout_APPRUN_ActivationState_80d1f9d4 : 1;
  Rte_BitType Rte_RxTimeout_ATCVT_RangeIndicationForDisplay_3913a580 : 1;
  Rte_BitType Rte_RxTimeout_ATCVT_WarningMessage1_a7818ab9 : 1;
  Rte_BitType Rte_RxTimeout_ATCVT_WarningMessage6_ASIL_fcb49b0e : 1;
  Rte_BitType Rte_RxTimeout_AT_GearShiftRefused_51c9fa50 : 1;
  Rte_BitType Rte_RxTimeout_AT_Level2FailureDisplayRequest_08fbbf1d : 1;
  Rte_BitType Rte_RxTimeout_AirCondEcoActivationState_48d90d68 : 1;
  Rte_BitType Rte_RxTimeout_AmbientLightingArea1Status_e315765e : 1;
  Rte_BitType Rte_RxTimeout_AssistanceFunctionStatusDisplay_1c6a89d9 : 1;
  Rte_BitType Rte_RxTimeout_AutoACC2Status_MM_b28b8a5f : 1;
  Rte_BitType Rte_RxTimeout_AutoFMHactivationState_da51d58f : 1;
  Rte_BitType Rte_RxTimeout_BSWRad_CancelReason_v2_b7be6fcb : 1;
  Rte_BitType Rte_RxTimeout_BSWrad_ActivationState_aeae7901 : 1;
  Rte_BitType Rte_RxTimeout_BadgeBatteryLow_d2e9d673 : 1;
  Rte_BitType Rte_RxTimeout_BattWarnReq_Level_Hi_ECM_v2_bf9c7f4f : 1;
  Rte_BitType Rte_RxTimeout_BattWarnReq_Level_Lo_USM_6f2eb103 : 1;
  Rte_BitType Rte_RxTimeout_BatteryVoltage_f8b1a02a : 1;
  Rte_BitType Rte_RxTimeout_BoostPressureDisplay_de4b1e8f : 1;
  Rte_BitType Rte_RxTimeout_BrakeInfoStatus_14fc81eb : 1;
  Rte_BitType Rte_RxTimeout_BrakeLampStatus_836390c2 : 1;
  Rte_BitType Rte_RxTimeout_CRC_AVM_A120_7ed2ac87 : 1;
  Rte_BitType Rte_RxTimeout_CTA_ActivationState_08d972b5 : 1;
  Rte_BitType Rte_RxTimeout_Clock_ADAS_A147_6c6fa330 : 1;
  Rte_BitType Rte_RxTimeout_Clock_BCM_A107_2c19a566 : 1;
  Rte_BitType Rte_RxTimeout_Clock_BCM_A110_25149b76 : 1;
  Rte_BitType Rte_RxTimeout_Clock_EBA_A2_bc0cc2ad : 1;
  Rte_BitType Rte_RxTimeout_Clock_EPS_A101_c6e0ce6a : 1;
  Rte_BitType Rte_RxTimeout_ComputedOilDrainingRange_36ac238f : 1;
  Rte_BitType Rte_RxTimeout_Contextual_ModeStatus_3d9fbb9e : 1;
  Rte_BitType Rte_RxTimeout_CruiseControlStatus_b49615a5 : 1;
  Rte_BitType Rte_RxTimeout_CruiseEcoActivationState_2309048c : 1;
  Rte_BitType Rte_RxTimeout_CurrentUserState_v2_aadf8507 : 1;
  Rte_BitType Rte_RxTimeout_DCA_CancelReason_9be8b02a : 1;
  Rte_BitType Rte_RxTimeout_DistanceTotalizer_3a07d954 : 1;
  Rte_BitType Rte_RxTimeout_DriveModeState_52f76d71 : 1;
  Rte_BitType Rte_RxTimeout_DriverEasyAccessState_6a6aa0eb : 1;
  Rte_BitType Rte_RxTimeout_ELKA_CancelReason_v2_9be8b02a : 1;
  Rte_BitType Rte_RxTimeout_ETS_WARN_MMD1_bf72e99a : 1;
  Rte_BitType Rte_RxTimeout_EcoAdviceTirePressureFL_1326146c : 1;
  Rte_BitType Rte_RxTimeout_ElecPowerDisplay_697d197c : 1;
  Rte_BitType Rte_RxTimeout_EngineControlFailureLevel1_49d40fa6 : 1;
  Rte_BitType Rte_RxTimeout_EngineCoolantTemp_bf9c7f4f : 1;
  Rte_BitType Rte_RxTimeout_EngineRPMDisplay_19eb74fb : 1;
  Rte_BitType Rte_RxTimeout_FAP_OperationSound_d8a5a733 : 1;
  Rte_BitType Rte_RxTimeout_FKP_ActivationStatus_0a8d297a : 1;
  Rte_BitType Rte_RxTimeout_FreeDistanceZEVSinceECOreset_c0e6cab3 : 1;
  Rte_BitType Rte_RxTimeout_FrontParkAssistState_9d123853 : 1;
  Rte_BitType Rte_RxTimeout_FrontWiperIntAutoSpeedStatus_772cb4d1 : 1;
  Rte_BitType Rte_RxTimeout_HEV_SystemFailureDisplay_v2_65076287 : 1;
  Rte_BitType Rte_RxTimeout_HUD_ActivationState_72afc3d2 : 1;
  Rte_BitType Rte_RxTimeout_HUD_RotationPositionState_14b50951 : 1;
  Rte_BitType Rte_RxTimeout_HybridTractionSaveModeAvail_307c6644 : 1;
  Rte_BitType Rte_RxTimeout_LCA_CancelReason_9be8b02a : 1;
  Rte_BitType Rte_RxTimeout_LCDN_AlertRequest_7c728bea : 1;
  Rte_BitType Rte_RxTimeout_LDW_CancelReason_9be8b02a : 1;
  Rte_BitType Rte_RxTimeout_LDW_VibrationIntensityState_517fdf43 : 1;
  Rte_BitType Rte_RxTimeout_MOD_ActivationState_8af1b488 : 1;
  Rte_BitType Rte_RxTimeout_MemoryGuidanceDisplayRequest_ce8aaccc : 1;
  Rte_BitType Rte_RxTimeout_OSPOverSpeedDisplayRequest_3793bbe2 : 1;
  Rte_BitType Rte_RxTimeout_OSPSpeedLimit_Display_c67db47f : 1;
  Rte_BitType Rte_RxTimeout_PBDMainSwitchActivationState_882a8b89 : 1;
  Rte_BitType Rte_RxTimeout_PSD_Left_BuzzerActivationStatus_812f9a4c : 1;
  Rte_BitType Rte_RxTimeout_ParkAssistVolumeState_cf2a17f4 : 1;
  Rte_BitType Rte_RxTimeout_ParkingBrakeBindingStatus_eda5fb4c : 1;
  Rte_BitType Rte_RxTimeout_PassengerEasyAccessState_be967169 : 1;
  Rte_BitType Rte_RxTimeout_PassengerSeatMemoAlertRequest_fa725a50 : 1;
  Rte_BitType Rte_RxTimeout_PowerTrainStatus_d746209f : 1;
  Rte_BitType Rte_RxTimeout_ReadyLampStatus_60431d19 : 1;
  Rte_BitType Rte_RxTimeout_SET_ALCActivationByTSIG_State_3c50d86d : 1;
  Rte_BitType Rte_RxTimeout_SSA_SteepSlopeWarning_Request_50f0398b : 1;
  Rte_BitType Rte_RxTimeout_SeatMemoAlertRequest_ae3bc3da : 1;
  Rte_BitType Rte_RxTimeout_SubAD_ADL3_Warning_4d3de2e0 : 1;
  Rte_BitType Rte_RxTimeout_TotalDrivePowerDisplay_51ab0784 : 1;
  Rte_BitType Rte_RxTimeout_TripComputer_ResetRequest_12897325 : 1;
  Rte_BitType Rte_RxTimeout_UserIdentification_IKeyLink_b139e349 : 1;
  Rte_BitType Rte_RxTimeout_VSPstatusDisplay_517616e1 : 1;
  Rte_BitType Rte_RxTimeout_VehicleSpeed_29cdb325 : 1;
  Rte_BitType Rte_RxTimeout_VolumAlarmActivatedDisplay_d15bbf65 : 1;
  Rte_BitType Rte_RxTimeout_VolumAlarmActivationState_d15bbf65 : 1;
  Rte_BitType Rte_RxTimeout_VolumAlarmDisplayRequest_d15bbf65 : 1;
  Rte_BitType Rte_RxTimeout_WelcomeFunctionAvailability_347e904b : 1;
  Rte_BitType Rte_RxTimeout_ZEVModeCancelMessage_7135dda2 : 1;
  Rte_BitType Rte_RxTimeout_ePedalMemorySettingStatus_58a63994 : 1;
  Rte_BitType Rte_RxTimeout_ePedalModeDisplayRequest_48bb114e : 1;
} Rte_OsApplication_NonTrusted_RxTimeoutFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_RxTimeoutFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrusted_RxTimeoutFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


typedef struct
{
  Rte_BitType Rte_RxNeverReceived_ABSstateDisplayRequest_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_ACC_CancelReason_v2_9be8b02a : 1;
  Rte_BitType Rte_RxNeverReceived_ACC_CruiseEcoActivationState_cd66cb85 : 1;
  Rte_BitType Rte_RxNeverReceived_ACC_DistanceSettingDisplay_74b0d609 : 1;
  Rte_BitType Rte_RxNeverReceived_ACC_StatusDisplay_v2_e12893da : 1;
  Rte_BitType Rte_RxNeverReceived_ADA1ActivationState_a6b84962 : 1;
  Rte_BitType Rte_RxNeverReceived_ADAS_Cut_in_Alert_7afec37d : 1;
  Rte_BitType Rte_RxNeverReceived_ADBCautionDisplay_bb86b44f : 1;
  Rte_BitType Rte_RxNeverReceived_ADB_ActivationStatusDisplay_8a6eaed2 : 1;
  Rte_BitType Rte_RxNeverReceived_ADB_FailureDisplay_8d60920f : 1;
  Rte_BitType Rte_RxNeverReceived_AD_CancelReason_912db933 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_CurveStatus_548a87bd : 1;
  Rte_BitType Rte_RxNeverReceived_AD_DriverInformation_a0c5a3ae : 1;
  Rte_BitType Rte_RxNeverReceived_AD_FunctionalLimit_3695d174 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_LeftsideLane_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_OwnVehicle_ALCPosition_9a27d3d9 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_StatusDisplay_3695d174 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_SteeringWheelTakeOverAlert_3695d174 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleEffect1_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleEffect2_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleEffect3_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleEffect4_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleEffect5_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleEffect6_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleEffect7_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleEffect8_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionX_1_c3159694 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionX_2_c3159694 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionX_3_c3159694 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionX_4_c3159694 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionX_5_f2fd8c09 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionX_6_f2fd8c09 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionX_7_f2fd8c09 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionX_8_f2fd8c09 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionY_1_c3159694 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionY_2_c3159694 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionY_3_c3159694 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionY_4_c3159694 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionY_5_f2fd8c09 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionY_6_f2fd8c09 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionY_7_f2fd8c09 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehiclePositionY_8_f2fd8c09 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleStatus1_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleStatus2_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleStatus3_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleStatus4_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleStatus5_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleStatus6_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleStatus7_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AD_VehicleStatus8_65629d20 : 1;
  Rte_BitType Rte_RxNeverReceived_AEB_CancelReason_v2_9be8b02a : 1;
  Rte_BitType Rte_RxNeverReceived_AEB_CyclistAlertRequest2_248fad54 : 1;
  Rte_BitType Rte_RxNeverReceived_AEB_FCWactivationState2_248fad54 : 1;
  Rte_BitType Rte_RxNeverReceived_AEB_FailureDisplay2_248fad54 : 1;
  Rte_BitType Rte_RxNeverReceived_AEB_RadarCancelReason_82f8a6e0 : 1;
  Rte_BitType Rte_RxNeverReceived_AEB_SoundAlert_v2_6fa79439 : 1;
  Rte_BitType Rte_RxNeverReceived_AEB_StatusDisplay2_v2_248fad54 : 1;
  Rte_BitType Rte_RxNeverReceived_AHL_ActivationDisplay_7c26de3b : 1;
  Rte_BitType Rte_RxNeverReceived_AIRBAGMalfunction_39bc2e85 : 1;
  Rte_BitType Rte_RxNeverReceived_ALC_HandsRequest_3695d174 : 1;
  Rte_BitType Rte_RxNeverReceived_APB_BrakePedalRequestDisplay_d3758951 : 1;
  Rte_BitType Rte_RxNeverReceived_APPRUN_ActivationState_80d1f9d4 : 1;
  Rte_BitType Rte_RxNeverReceived_ATCVT_RangeIndicationExtended_51c9fa50 : 1;
  Rte_BitType Rte_RxNeverReceived_ATCVT_RangeIndicationForDisplay_3913a580 : 1;
  Rte_BitType Rte_RxNeverReceived_ATCVT_WarningMessage1_a7818ab9 : 1;
  Rte_BitType Rte_RxNeverReceived_ATCVT_WarningMessage6_ASIL_fcb49b0e : 1;
  Rte_BitType Rte_RxNeverReceived_AT_GearShiftRefused_51c9fa50 : 1;
  Rte_BitType Rte_RxNeverReceived_AT_Level2FailureDisplayRequest_08fbbf1d : 1;
  Rte_BitType Rte_RxNeverReceived_AT_Parkfailure_08fbbf1d : 1;
  Rte_BitType Rte_RxNeverReceived_AirCondEcoActivationState_48d90d68 : 1;
  Rte_BitType Rte_RxNeverReceived_AirbagWarningLampCheck_39bc2e85 : 1;
  Rte_BitType Rte_RxNeverReceived_AssistanceFunctionStatusDisplay_1c6a89d9 : 1;
  Rte_BitType Rte_RxNeverReceived_AutoACC2Status_MM_b28b8a5f : 1;
  Rte_BitType Rte_RxNeverReceived_AutoFMHactivationState_da51d58f : 1;
  Rte_BitType Rte_RxNeverReceived_BSWRad_CancelReason_v2_b7be6fcb : 1;
  Rte_BitType Rte_RxNeverReceived_BSWrad_ActivationState_aeae7901 : 1;
  Rte_BitType Rte_RxNeverReceived_BadgeBatteryLow_d2e9d673 : 1;
  Rte_BitType Rte_RxNeverReceived_BattWarnReq_Level_Hi_ECM_v2_bf9c7f4f : 1;
  Rte_BitType Rte_RxNeverReceived_BattWarnReq_Level_Hi_USM_v2_f8b1a02a : 1;
  Rte_BitType Rte_RxNeverReceived_BattWarnReq_Level_Lo_USM_6f2eb103 : 1;
  Rte_BitType Rte_RxNeverReceived_BatteryVoltage_f8b1a02a : 1;
  Rte_BitType Rte_RxNeverReceived_BoostPressureDisplay_de4b1e8f : 1;
  Rte_BitType Rte_RxNeverReceived_BrakeInfoStatus_14fc81eb : 1;
  Rte_BitType Rte_RxNeverReceived_BrakeLampStatus_836390c2 : 1;
  Rte_BitType Rte_RxNeverReceived_Bswc_VCAN_ppCANNvrRcvd_ACU_A101 : 1;
  Rte_BitType Rte_RxNeverReceived_CRBSfailureDisplayAlert_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_ACU_A101_39bc2e85 : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_ADAS_A110_e12893da : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_ADAS_A139_3695d174 : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_ATCU_A110_08fbbf1d : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_ATCU_A113_3913a580 : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_AVM_A120_7ed2ac87 : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_BCM_A107_2c19a566 : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_BCM_A110_25149b76 : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_EBA_A2_bc0cc2ad : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_ECM_A108_bf9c7f4f : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_EPKB_A101_d3758951 : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_EPS_A101_c6e0ce6a : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_USM_A101_f8b1a02a : 1;
  Rte_BitType Rte_RxNeverReceived_CRC_VDC_A113_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_CTA_ActivationState_08d972b5 : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_ACU_A101_39bc2e85 : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_ADAS_A110_e12893da : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_ADAS_A139_3695d174 : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_ADAS_A147_6c6fa330 : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_ATCU_A110_08fbbf1d : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_ATCU_A113_3913a580 : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_BCM_A107_2c19a566 : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_BCM_A110_25149b76 : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_EBA_A2_bc0cc2ad : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_ECM_A108_bf9c7f4f : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_EPKB_A101_d3758951 : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_EPS_A101_c6e0ce6a : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_USM_A101_f8b1a02a : 1;
  Rte_BitType Rte_RxNeverReceived_Clock_VDC_A113_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_ComputedOilDrainingRange_36ac238f : 1;
  Rte_BitType Rte_RxNeverReceived_Contextual_ModeStatus_3d9fbb9e : 1;
  Rte_BitType Rte_RxNeverReceived_CruiseControlStatus_b49615a5 : 1;
  Rte_BitType Rte_RxNeverReceived_CruiseEcoActivationState_2309048c : 1;
  Rte_BitType Rte_RxNeverReceived_Ctrl_WUS_ppIgnSubstate_IgnitionSubstate : 1;
  Rte_BitType Rte_RxNeverReceived_Ctrl_WUS_pp_WUSVehActiveMode_WUSCurrentVehicleState : 1;
  Rte_BitType Rte_RxNeverReceived_CurrentUserState_v2_aadf8507 : 1;
  Rte_BitType Rte_RxNeverReceived_DCA_CancelReason_9be8b02a : 1;
  Rte_BitType Rte_RxNeverReceived_DistanceTotalizer_3a07d954 : 1;
  Rte_BitType Rte_RxNeverReceived_DoorLockRefuseToLockAlertDisplay_7c26de3b : 1;
  Rte_BitType Rte_RxNeverReceived_DriveModeState_52f76d71 : 1;
  Rte_BitType Rte_RxNeverReceived_DriverEasyAccessState_6a6aa0eb : 1;
  Rte_BitType Rte_RxNeverReceived_DynamicBrakingDisplay_d3758951 : 1;
  Rte_BitType Rte_RxNeverReceived_EBA_MajorFailure_bc0cc2ad : 1;
  Rte_BitType Rte_RxNeverReceived_EBA_MinorFailure_bc0cc2ad : 1;
  Rte_BitType Rte_RxNeverReceived_EBAfailureDisplayAlert_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_EBDstateDisplayRequest_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_ELKA_CancelReason_v2_9be8b02a : 1;
  Rte_BitType Rte_RxNeverReceived_EPB_BindingStatusDisplay_d3758951 : 1;
  Rte_BitType Rte_RxNeverReceived_EPB_MalfunctionDisplay_d3758951 : 1;
  Rte_BitType Rte_RxNeverReceived_EPB_TightenRequestUnavailable_d3758951 : 1;
  Rte_BitType Rte_RxNeverReceived_EPSWarning_c6e0ce6a : 1;
  Rte_BitType Rte_RxNeverReceived_ETS_WARN_MMD1_bf72e99a : 1;
  Rte_BitType Rte_RxNeverReceived_EcoAdviceTirePressureFL_1326146c : 1;
  Rte_BitType Rte_RxNeverReceived_ElecPowerDisplay_697d197c : 1;
  Rte_BitType Rte_RxNeverReceived_EngineControlFailureLevel1_49d40fa6 : 1;
  Rte_BitType Rte_RxNeverReceived_EngineCoolantTemp_bf9c7f4f : 1;
  Rte_BitType Rte_RxNeverReceived_EngineRPMDisplay_19eb74fb : 1;
  Rte_BitType Rte_RxNeverReceived_FAP_OperationSound_d8a5a733 : 1;
  Rte_BitType Rte_RxNeverReceived_FKP_ActivationStatus_0a8d297a : 1;
  Rte_BitType Rte_RxNeverReceived_FlashingIndicatorStatusDisplay_2c19a566 : 1;
  Rte_BitType Rte_RxNeverReceived_FreeDistanceZEVSinceECOreset_c0e6cab3 : 1;
  Rte_BitType Rte_RxNeverReceived_FrontFogLightsDisplay_836390c2 : 1;
  Rte_BitType Rte_RxNeverReceived_FrontParkAssistState_9d123853 : 1;
  Rte_BitType Rte_RxNeverReceived_FrontWiperIntAutoSpeedStatus_772cb4d1 : 1;
  Rte_BitType Rte_RxNeverReceived_GSITargettedGearDisplayRequest_b49615a5 : 1;
  Rte_BitType Rte_RxNeverReceived_HEV_SystemFailureDisplay_v2_65076287 : 1;
  Rte_BitType Rte_RxNeverReceived_HUD_ActivationState_72afc3d2 : 1;
  Rte_BitType Rte_RxNeverReceived_HUD_RotationPositionState_14b50951 : 1;
  Rte_BitType Rte_RxNeverReceived_HighBeamDisplay_da51d58f : 1;
  Rte_BitType Rte_RxNeverReceived_HybridTractionSaveModeAvail_307c6644 : 1;
  Rte_BitType Rte_RxNeverReceived_KeyReminderAlert_7c26de3b : 1;
  Rte_BitType Rte_RxNeverReceived_LCA_CancelReason_9be8b02a : 1;
  Rte_BitType Rte_RxNeverReceived_LCA_StatusDisplay_v2_1c6a89d9 : 1;
  Rte_BitType Rte_RxNeverReceived_LCA_SteeringWheelDisplay_74b0d609 : 1;
  Rte_BitType Rte_RxNeverReceived_LCA_SteeringWheelTakeOverAlert_e12893da : 1;
  Rte_BitType Rte_RxNeverReceived_LCDN_AlertRequest_7c728bea : 1;
  Rte_BitType Rte_RxNeverReceived_LDW_CancelReason_9be8b02a : 1;
  Rte_BitType Rte_RxNeverReceived_LDW_VibrationIntensityState_517fdf43 : 1;
  Rte_BitType Rte_RxNeverReceived_LowVacPWT_RestartImpossibleAlert_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_MOD_ActivationState_8af1b488 : 1;
  Rte_BitType Rte_RxNeverReceived_MemoryGuidanceDisplayRequest_ce8aaccc : 1;
  Rte_BitType Rte_RxNeverReceived_MeterRing_Illumination_Request_7c26de3b : 1;
  Rte_BitType Rte_RxNeverReceived_NeutralHoldModeMessage_51c9fa50 : 1;
  Rte_BitType Rte_RxNeverReceived_OSPOverSpeedDisplayRequest_3793bbe2 : 1;
  Rte_BitType Rte_RxNeverReceived_OSPSpeedLimit_Display_c67db47f : 1;
  Rte_BitType Rte_RxNeverReceived_PBDMainSwitchActivationState_882a8b89 : 1;
  Rte_BitType Rte_RxNeverReceived_PSD_Left_BuzzerActivationStatus_812f9a4c : 1;
  Rte_BitType Rte_RxNeverReceived_ParkAssistVolumeState_cf2a17f4 : 1;
  Rte_BitType Rte_RxNeverReceived_ParkingBrakeBindingStatus_eda5fb4c : 1;
  Rte_BitType Rte_RxNeverReceived_PassengerEasyAccessState_be967169 : 1;
  Rte_BitType Rte_RxNeverReceived_PassengerSeatMemoAlertRequest_fa725a50 : 1;
  Rte_BitType Rte_RxNeverReceived_PositionLightsDisplay_7c26de3b : 1;
  Rte_BitType Rte_RxNeverReceived_PositionLightsOmissionWarning_b28b8a5f : 1;
  Rte_BitType Rte_RxNeverReceived_PowerTrainStatus_d746209f : 1;
  Rte_BitType Rte_RxNeverReceived_RESstatus_25149b76 : 1;
  Rte_BitType Rte_RxNeverReceived_ReadyLampStatus_60431d19 : 1;
  Rte_BitType Rte_RxNeverReceived_RearFogLightStateDisplay_25149b76 : 1;
  Rte_BitType Rte_RxNeverReceived_RegenBrakingLevelDisplay_60431d19 : 1;
  Rte_BitType Rte_RxNeverReceived_SET_ALCActivationByTSIG_State_3c50d86d : 1;
  Rte_BitType Rte_RxNeverReceived_SSA_StateLamp_a6b84962 : 1;
  Rte_BitType Rte_RxNeverReceived_SSA_SteepSlopeWarning_Request_50f0398b : 1;
  Rte_BitType Rte_RxNeverReceived_SeatMemoAlertRequest_ae3bc3da : 1;
  Rte_BitType Rte_RxNeverReceived_ShiftIndicator_b49615a5 : 1;
  Rte_BitType Rte_RxNeverReceived_SmartKeylessInformationDisplay_836390c2 : 1;
  Rte_BitType Rte_RxNeverReceived_StopStartInformationDisplay_2309048c : 1;
  Rte_BitType Rte_RxNeverReceived_SubAD_ADL3_Warning_4d3de2e0 : 1;
  Rte_BitType Rte_RxNeverReceived_TotalDrivePowerDisplay_51ab0784 : 1;
  Rte_BitType Rte_RxNeverReceived_TripComputer_ResetRequest_12897325 : 1;
  Rte_BitType Rte_RxNeverReceived_UserIdentification_IKeyLink_b139e349 : 1;
  Rte_BitType Rte_RxNeverReceived_VDCdeactivationDisplayRequest_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_VDCstateDisplayRequest_ffa0e7da : 1;
  Rte_BitType Rte_RxNeverReceived_VSPstatusDisplay_517616e1 : 1;
  Rte_BitType Rte_RxNeverReceived_VehicleSpeed_29cdb325 : 1;
  Rte_BitType Rte_RxNeverReceived_VolumAlarmActivatedDisplay_d15bbf65 : 1;
  Rte_BitType Rte_RxNeverReceived_VolumAlarmActivationState_d15bbf65 : 1;
  Rte_BitType Rte_RxNeverReceived_VolumAlarmDisplayRequest_d15bbf65 : 1;
  Rte_BitType Rte_RxNeverReceived_WelcomeFunctionAvailability_347e904b : 1;
  Rte_BitType Rte_RxNeverReceived_ZEVModeCancelMessage_7135dda2 : 1;
  Rte_BitType Rte_RxNeverReceived_ePedalMemorySettingStatus_58a63994 : 1;
  Rte_BitType Rte_RxNeverReceived_ePedalModeDisplayRequest_48bb114e : 1;
} Rte_OsApplication_NonTrusted_RxNeverReceivedFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_RxNeverReceivedFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrusted_RxNeverReceivedFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_RxNeverReceived_Ctrl_telltale_ppTelltaleStatusOP_TelltaleOpArray : 1;
  Rte_BitType Rte_RxNeverReceived_Mdl_CANNm_ppCANNMState_CurrentCANNmState : 1;
  Rte_BitType Rte_RxNeverReceived_Mdl_CrcCdd_ppCrcStates_CanUpdate_CrcStates_ADAS_A103_CrcUpdate : 1;
  Rte_BitType Rte_RxNeverReceived_SENS_Adapt_ppTTDiagFeedback_tt_diag_feedback : 1;
  Rte_BitType Rte_RxNeverReceived_SENS_Adapt_ppTftMonitoringStatus_tft_monitoring_status : 1;
  Rte_BitType Rte_RxNeverReceived_View_telltale_ppTelltaleIndexStatus_TTIndex : 1;
} Rte_OsApplication_Trusted_RxNeverReceivedFlagsType;

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_Trusted_RxNeverReceivedFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Trusted_RxNeverReceivedFlags;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


typedef struct
{
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_ApplicationRandomNumber : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_CustomerHWReference : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_CustomerReference : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_CustomerReference2 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID100 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID200 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID300 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID310 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID400 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID410 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID420 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID430 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID440 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID450 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID500 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDID900 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDF190 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDF1A2 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_DiagDIDFE11 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FBLValidDTCState : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FBLValidDTCState_1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FBL_NVM : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FOTA_NVM : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FOTA_NVM_DIGHRNIG : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FeatureConfigCalib : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst2 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst3 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst4 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst5 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FeaturesConst6 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Fingerprint : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FotaUpdateStatus : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FotaUpdateStatus_1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_FuelCalcCalib : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_GUST_USER_LOGIN : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_GaugeEctCalib : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_GaugeFuelCalib : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_GaugeRPMCalib : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_GaugeSpdCalib : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_IDLE_STOP : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_IKEY_BLK : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_IllumPWMCalib : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_LoaderModeDetected : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_MFG_DID_PRODUCT : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_MagicFlag : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_NVM_HM_FaultCounters : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_NvM_Revision_Value : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_NvM_Version_Value : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK2 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK3 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK4 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Odometer_BLK5 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_PCBSerialNumber : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Reserved_Health_Management : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_DTC_INDEX_BLK : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK0 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK10 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK11 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK12 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK13 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK14 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK15 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK2 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK3 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK4 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK5 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK6 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK7 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK8 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_SSD_BLK9 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK0 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK10 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK11 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK12 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK13 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK14 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK15 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK2 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK3 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK4 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK5 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK6 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK7 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK8 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_SIGMA_VTD_BLK9 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Signature : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_Signature_1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_USER_LOGIN : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_VehicleStateDetected : 1;
} Rte_DirtyFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_DirtyFlagsType, RTE_VAR_ZERO_INIT) Rte_DirtyFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * RTE internal IOC replacement
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UI_AUDIO_SRC_LIST_OPEN_CLOSE, RTE_VAR_NOINIT) Rte_ioc_Rte_Hmi_Adapter_rpAudioSrcListEvent_AudioSourceOpenPreCndn_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Hmi_Adapter_rpAudioSrcListEvent_AudioSourceOpenPreCndn_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Hmi_Adapter_rpAudioSrcListEvent_AudioSourceOpenPreCndn_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UI_NAVI_SWIPE_STATE_T, RTE_VAR_NOINIT) Rte_ioc_Rte_Hmi_Adapter_rpNaviDisplayMode_NaviSwipeMode_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Hmi_Adapter_rpNaviDisplayMode_NaviSwipeMode_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Hmi_Adapter_rpNaviDisplayMode_NaviSwipeMode_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SPhoneDataResponse, RTE_VAR_NOINIT) Rte_ioc_Rte_MDL_PhoneMcan_rSR_PhoneDataResponse_PhoneDataResponseData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rSR_PhoneDataResponse_PhoneDataResponseData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rSR_PhoneDataResponse_PhoneDataResponseData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UI_SMS_STATE_T, RTE_VAR_NOINIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_EnterButtonPressed_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_EnterButtonPressed_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_EnterButtonPressed_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_SMSAckEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_SMSAckEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_SMSAckEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UI_SMS_MENU_ITEM_T, RTE_VAR_NOINIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_SMSListSelectionEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_SMSListSelectionEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSEvents_SMSListSelectionEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSWarningAckEvent_SMSWarningAckEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSWarningAckEvent_SMSWarningAckEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpSMSWarningAckEvent_SMSWarningAckEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UI_TEL_MENU_ITEM_T, RTE_VAR_NOINIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TELListSelectionEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TELListSelectionEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TELListSelectionEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(WarningAckSts, RTE_VAR_NOINIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TelAckStatus_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TelAckStatus_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TelAckStatus_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ButtonAndEvents, RTE_VAR_NOINIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelSwitchPressEvent_TelSwitchPressEvent_Queue[15U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelSwitchPressEvent_TelSwitchPressEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_MDL_PhoneMcan_rpTelSwitchPressEvent_TelSwitchPressEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt32, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_AD2Safety_rpGipHeartbeatFailureStatus_GIPFailureStatus_Queue[5U];

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AD2Safety_rpGipHeartbeatFailureStatus_GIPFailureStatus_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AD2Safety_rpGipHeartbeatFailureStatus_GIPFailureStatus_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SAudioSourceSelData, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_AudioMcan_rSR_AudioSourceSelData_AudioSourceSelDataData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AudioMcan_rSR_AudioSourceSelData_AudioSourceSelDataData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AudioMcan_rSR_AudioSourceSelData_AudioSourceSelDataData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListAckEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListAckEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListAckEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UI_AUDIO_SOURCE_LIST_T, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListTransmitEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListTransmitEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListTransmitEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ChangeLanguage, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_AudioMcan_rpLangChangeEvt_ChangeLangEvt_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AudioMcan_rpLangChangeEvt_ChangeLangEvt_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_AudioMcan_rpLangChangeEvt_ChangeLangEvt_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(MCAN_CLOCK_SETTING_INFO, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_ClockSettings_rpClockSettingEvent_CurrentClockSettingsAvailableEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_ClockSettings_rpClockSettingEvent_CurrentClockSettingsAvailableEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_ClockSettings_rpClockSettingEvent_CurrentClockSettingsAvailableEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ACU_A101ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ACU_A101ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ACU_A101ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A103ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A103ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A103ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A110_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A110_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A110_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A116ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A116ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A116ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A117ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A117ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A117ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A119ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A119ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A119ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A120ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A120ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A120ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A124ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A124ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A124ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A125ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A125ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A125ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A139ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A139ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A139ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A147_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A147_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A147_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A148_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A148_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A148_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A149_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A149_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A149_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A150ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A150ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A150ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A151ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A151ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A151ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A152ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A152ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A152ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A153ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A153ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A153ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A154_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A154_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A154_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A157_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A157_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A157_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A6ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A6ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A6ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_N101ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_N101ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_N101ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A110ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A110ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A110ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A113ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A113ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A113ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A120_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A120_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A120_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A121ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A121ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A121ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A128_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A128_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A128_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A1ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A1ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A1ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A107ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A107ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A107ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A110ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A110ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A110ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EBA_A2ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EBA_A2ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EBA_A2ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ECM_A108ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ECM_A108ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_ECM_A108ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EPKB_A101ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EPKB_A101ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EPKB_A101ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EPS_A101ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EPS_A101ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_EPS_A101ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_HEVC_N102ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_HEVC_N102ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_HEVC_N102ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_USM_A101ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_USM_A101ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_USM_A101ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(CrcUpdateType, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_VDC_A113ComCrcUpdate_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_VDC_A113ComCrcUpdate_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_CrcCdd_rpCANClockCRC_VDC_A113ComCrcUpdate_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SAD2VehSts, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rSR_AD2VehSts_AD2VehStsData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rSR_AD2VehSts_AD2VehStsData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rSR_AD2VehSts_AD2VehStsData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(STTChecksumSts, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rSR_TTChecksumSts_TTChecksumStsData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rSR_TTChecksumSts_TTChecksumStsData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rSR_TTChecksumSts_TTChecksumStsData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpIgnOffPersonalMenuAnimEvent_IgnOffPersonalMenuAnimEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpIgnOffPersonalMenuAnimEvent_IgnOffPersonalMenuAnimEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpIgnOffPersonalMenuAnimEvent_IgnOffPersonalMenuAnimEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpIgnOnPersonalMenuAnimEvent_IgnOnPersonalMenuAnimEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpIgnOnPersonalMenuAnimEvent_IgnOnPersonalMenuAnimEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpIgnOnPersonalMenuAnimEvent_IgnOnPersonalMenuAnimEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpModeChangeAnimEvent_ModeChangeAnimEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpModeChangeAnimEvent_ModeChangeAnimEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpModeChangeAnimEvent_ModeChangeAnimEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpOpngMovieAnimEvent_OpngMovieAnimEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpOpngMovieAnimEvent_OpngMovieAnimEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpOpngMovieAnimEvent_OpngMovieAnimEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpPersMenuAnimEvent_PersMenuAnimEvent_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpPersMenuAnimEvent_PersMenuAnimEvent_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_IpclSafeCommunication_rpPersMenuAnimEvent_PersMenuAnimEvent_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SafetyMsgRcvT, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_ShiftByWire_TT_rpATCU_A110_MsgRcv_ATCU_A110_Rcvd_Queue[1U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_ShiftByWire_TT_rpATCU_A110_MsgRcv_ATCU_A110_Rcvd_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_ShiftByWire_TT_rpATCU_A110_MsgRcv_ATCU_A110_Rcvd_head;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ButtonAndEvents, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Hmi_Adapter_ButtonEventsToMCAN_Queue[15U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Hmi_Adapter_ButtonEventsToMCAN_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Hmi_Adapter_ButtonEventsToMCAN_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ButtonAndEvents, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Mdl_Button_ButtonEventsToMCAN_Queue[15U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Mdl_Button_ButtonEventsToMCAN_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Mdl_Button_ButtonEventsToMCAN_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ButtonAndEvents, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpSwMcanEvt_ButtonEventsToMCAN_Queue[15U];

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpSwMcanEvt_ButtonEventsToMCAN_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpSwMcanEvt_ButtonEventsToMCAN_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ButtonAndEvents, RTE_VAR_NOINIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpTelSwMcanEvt_ButtonEventsToMCAN_Queue[15U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpTelSwMcanEvt_ButtonEventsToMCAN_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpTelSwMcanEvt_ButtonEventsToMCAN_head;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SAudioChannelData, RTE_VAR_NOINIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioChannelData_AudioChannelDataData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioChannelData_AudioChannelDataData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioChannelData_AudioChannelDataData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SAudioIndData, RTE_VAR_NOINIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioIndData_AudioIndDataData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioIndData_AudioIndDataData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioIndData_AudioIndDataData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SAudioInitData, RTE_VAR_NOINIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioInitData_AudioInitDataData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioInitData_AudioInitDataData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_AudioInitData_AudioInitDataData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SNaviChannelData, RTE_VAR_NOINIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviChannelData_NaviChannelDataData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviChannelData_NaviChannelDataData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviChannelData_NaviChannelDataData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SNaviIndData, RTE_VAR_NOINIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviIndData_NaviIndDataData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviIndData_NaviIndDataData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviIndData_NaviIndDataData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SNaviInitData, RTE_VAR_NOINIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviInitData_NaviInitDataData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviInitData_NaviInitDataData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_NaviInitData_NaviInitDataData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(SPhoneIndData, RTE_VAR_NOINIT) Rte_ioc_Rte_UclProxyCdd_rSR_PhoneIndData_PhoneIndDataData_Queue[2U];

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_PhoneIndData_PhoneIndDataData_tail;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_UclProxyCdd_rSR_PhoneIndData_PhoneIndDataData_head;

#  define RTE_STOP_SEC_VAR_OsApplication_NonTrusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_Hmi_Adapter_rpAudioSrcListEvent_AudioSourceOpenPreCndn_overflow0 : 1;
  Rte_BitType Rte_Hmi_Adapter_rpNaviDisplayMode_NaviSwipeMode_overflow0 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rSR_PhoneDataResponse_PhoneDataResponseData_overflow1 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpSMSEvents_EnterButtonPressed_overflow1 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpSMSEvents_SMSAckEvent_overflow1 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpSMSEvents_SMSListSelectionEvent_overflow1 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpSMSWarningAckEvent_SMSWarningAckEvent_overflow1 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TELListSelectionEvent_overflow1 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TelAckStatus_overflow1 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpTelSwitchPressEvent_TelSwitchPressEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_AudioMcan_rSR_AudioSourceSelData_AudioSourceSelDataData_overflow1 : 1;
  Rte_BitType Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListAckEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListTransmitEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_AudioMcan_rpLangChangeEvt_ChangeLangEvt_overflow1 : 1;
  Rte_BitType Rte_Mdl_ClockSettings_rpClockSettingEvent_CurrentClockSettingsAvailableEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Hmi_Adapter_ButtonEventsToMCAN_overflow1 : 1;
  Rte_BitType Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Mdl_Button_ButtonEventsToMCAN_overflow1 : 1;
  Rte_BitType Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpSwMcanEvt_ButtonEventsToMCAN_overflow1 : 1;
  Rte_BitType Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpTelSwMcanEvt_ButtonEventsToMCAN_overflow0 : 1;
  Rte_BitType Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpTelSwMcanEvt_ButtonEventsToMCAN_overflow1 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_AudioChannelData_AudioChannelDataData_overflow0 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_AudioIndData_AudioIndDataData_overflow0 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_AudioInitData_AudioInitDataData_overflow0 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_NaviChannelData_NaviChannelDataData_overflow0 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_NaviIndData_NaviIndDataData_overflow0 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_NaviInitData_NaviInitDataData_overflow0 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_PhoneIndData_PhoneIndDataData_overflow0 : 1;
} Rte_OsApplication_CyberSecurity_IocOverflowFlagsType;

#  define RTE_START_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_CyberSecurity_IocOverflowFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_CyberSecurity_IocOverflowFlags;

#  define RTE_STOP_SEC_VAR_OsApplication_CyberSecurity_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_Hmi_Adapter_rpAudioSrcListEvent_AudioSourceOpenPreCndn_overflow1 : 1;
  Rte_BitType Rte_Hmi_Adapter_rpNaviDisplayMode_NaviSwipeMode_overflow1 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rSR_PhoneDataResponse_PhoneDataResponseData_overflow0 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpSMSEvents_EnterButtonPressed_overflow0 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpSMSEvents_SMSAckEvent_overflow0 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpSMSEvents_SMSListSelectionEvent_overflow0 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpSMSWarningAckEvent_SMSWarningAckEvent_overflow0 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TELListSelectionEvent_overflow0 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpTelEvent_rpTelEvent_Hmi_Adapter_TelAckStatus_overflow0 : 1;
  Rte_BitType Rte_MDL_PhoneMcan_rpTelSwitchPressEvent_TelSwitchPressEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_AudioMcan_rSR_AudioSourceSelData_AudioSourceSelDataData_overflow0 : 1;
  Rte_BitType Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListAckEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_AudioMcan_rpAudioSourceListEvent_AudioSourceListTransmitEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_AudioMcan_rpLangChangeEvt_ChangeLangEvt_overflow0 : 1;
  Rte_BitType Rte_Mdl_ClockSettings_rpClockSettingEvent_CurrentClockSettingsAvailableEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ACU_A101ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A103ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A110_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A116ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A117ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A119ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A120ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A124ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A125ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A139ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A147_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A148_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A149_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A150ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A151ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A152ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A153ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A154_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A157_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A6ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_N101ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A110ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A113ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A120_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A121ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A128_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A1ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A107ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A110ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_EBA_A2ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ECM_A108ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_EPKB_A101ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_EPS_A101ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_HEVC_N102ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_USM_A101ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_VDC_A113ComCrcUpdate_overflow0 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rSR_AD2VehSts_AD2VehStsData_overflow0 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rSR_TTChecksumSts_TTChecksumStsData_overflow0 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpIgnOffPersonalMenuAnimEvent_IgnOffPersonalMenuAnimEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpIgnOnPersonalMenuAnimEvent_IgnOnPersonalMenuAnimEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpModeChangeAnimEvent_ModeChangeAnimEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpOpngMovieAnimEvent_OpngMovieAnimEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpPersMenuAnimEvent_PersMenuAnimEvent_overflow0 : 1;
  Rte_BitType Rte_Mdl_ShiftByWire_TT_rpATCU_A110_MsgRcv_ATCU_A110_Rcvd_overflow0 : 1;
  Rte_BitType Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Hmi_Adapter_ButtonEventsToMCAN_overflow0 : 1;
  Rte_BitType Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpMcanButtonEvents_Mdl_Button_ButtonEventsToMCAN_overflow0 : 1;
  Rte_BitType Rte_Mdl_StgWheelMcan_rpMcanButtonEvents_rpSwMcanEvt_ButtonEventsToMCAN_overflow0 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_AudioChannelData_AudioChannelDataData_overflow1 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_AudioIndData_AudioIndDataData_overflow1 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_AudioInitData_AudioInitDataData_overflow1 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_NaviChannelData_NaviChannelDataData_overflow1 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_NaviIndData_NaviIndDataData_overflow1 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_NaviInitData_NaviInitDataData_overflow1 : 1;
  Rte_BitType Rte_UclProxyCdd_rSR_PhoneIndData_PhoneIndDataData_overflow1 : 1;
} Rte_OsApplication_NonTrusted_IocOverflowFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_IocOverflowFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrusted_IocOverflowFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_Mdl_AD2Safety_rpGipHeartbeatFailureStatus_GIPFailureStatus_overflow0 : 1;
  Rte_BitType Rte_Mdl_AD2Safety_rpGipHeartbeatFailureStatus_GIPFailureStatus_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ACU_A101ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A103ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A110_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A116ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A117ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A119ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A120ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A124ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A125ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A139ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A147_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A148_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A149_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A150ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A151ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A152ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A153ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A154_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A157_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_A6ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ADAS_N101ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A110ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ATCU_A113ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A120_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A121ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A128_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_AVM_A1ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A107ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_BCM_A110ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_EBA_A2ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_ECM_A108ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_EPKB_A101ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_EPS_A101ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_HEVC_N102ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_USM_A101ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_CrcCdd_rpCANClockCRC_VDC_A113ComCrcUpdate_overflow1 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rSR_AD2VehSts_AD2VehStsData_overflow1 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rSR_TTChecksumSts_TTChecksumStsData_overflow1 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpIgnOffPersonalMenuAnimEvent_IgnOffPersonalMenuAnimEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpIgnOnPersonalMenuAnimEvent_IgnOnPersonalMenuAnimEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpModeChangeAnimEvent_ModeChangeAnimEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpOpngMovieAnimEvent_OpngMovieAnimEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_IpclSafeCommunication_rpPersMenuAnimEvent_PersMenuAnimEvent_overflow1 : 1;
  Rte_BitType Rte_Mdl_ShiftByWire_TT_rpATCU_A110_MsgRcv_ATCU_A110_Rcvd_overflow1 : 1;
} Rte_OsApplication_Trusted_IocOverflowFlagsType;

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_Trusted_IocOverflowFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Trusted_IocOverflowFlags;

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
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
