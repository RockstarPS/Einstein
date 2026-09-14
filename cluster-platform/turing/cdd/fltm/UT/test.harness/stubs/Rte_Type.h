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
 *   ECU-Project:  IC
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
 * Type definitions for transformer error handling
 *********************************************************************************************************************/

typedef uint8 Rte_TransformerClass;
typedef Std_ReturnType Rte_TransformerErrorCode;

# define RTE_TRANSFORMER_UNSPECIFIED 0x00U
# define RTE_TRANSFORMER_SERIALIZER  0x01U
# define RTE_TRANSFORMER_SAFETY      0x02U

typedef struct
{
  Rte_TransformerErrorCode errorCode;
  Rte_TransformerClass transformerClass;
} Rte_TransformerError;


/**********************************************************************************************************************
 * Data type definitions
 *********************************************************************************************************************/

# define Rte_TypeDef_Alive_101
typedef uint8 Alive_101;

# define Rte_TypeDef_Alive_200
typedef uint8 Alive_200;

# define Rte_TypeDef_Ambient_Light_level
typedef uint8 Ambient_Light_level;

# define Rte_TypeDef_Battery_Voltage
typedef uint8 Battery_Voltage;

# define Rte_TypeDef_Boolean
typedef boolean Boolean;

# define Rte_TypeDef_CRC_101
typedef uint8 CRC_101;

# define Rte_TypeDef_CRC_200
typedef uint8 CRC_200;

# define Rte_TypeDef_CurrentStateIC
typedef boolean CurrentStateIC;

# define Rte_TypeDef_DayNightMode
typedef boolean DayNightMode;

# define Rte_TypeDef_Dcm_DspDidIdentifierTableType
typedef uint16 Dcm_DspDidIdentifierTableType;

# define Rte_TypeDef_Dcm_DspRidIdentifierTableType
typedef uint16 Dcm_DspRidIdentifierTableType;

# define Rte_TypeDef_Dcm_MsgLenType
typedef uint32 Dcm_MsgLenType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Debug1_Byte0
typedef uint8 Debug1_Byte0;

# define Rte_TypeDef_Debug1_Byte1
typedef uint8 Debug1_Byte1;

# define Rte_TypeDef_Debug1_Byte2
typedef uint8 Debug1_Byte2;

# define Rte_TypeDef_Debug1_Byte3
typedef uint8 Debug1_Byte3;

# define Rte_TypeDef_Debug1_Byte4
typedef uint8 Debug1_Byte4;

# define Rte_TypeDef_Debug1_Byte5
typedef uint8 Debug1_Byte5;

# define Rte_TypeDef_Debug1_Byte6
typedef uint8 Debug1_Byte6;

# define Rte_TypeDef_Debug1_Byte7
typedef uint8 Debug1_Byte7;

# define Rte_TypeDef_Debug2_Byte0
typedef uint8 Debug2_Byte0;

# define Rte_TypeDef_Debug2_Byte1
typedef uint8 Debug2_Byte1;

# define Rte_TypeDef_Debug2_Byte2
typedef uint8 Debug2_Byte2;

# define Rte_TypeDef_Debug2_Byte3
typedef uint8 Debug2_Byte3;

# define Rte_TypeDef_Debug2_Byte4
typedef uint8 Debug2_Byte4;

# define Rte_TypeDef_Debug2_Byte5
typedef uint8 Debug2_Byte5;

# define Rte_TypeDef_Debug2_Byte6
typedef uint8 Debug2_Byte6;

# define Rte_TypeDef_Debug2_Byte7
typedef uint8 Debug2_Byte7;

# define Rte_TypeDef_Debug3_Byte0
typedef uint8 Debug3_Byte0;

# define Rte_TypeDef_Debug3_Byte1
typedef uint8 Debug3_Byte1;

# define Rte_TypeDef_Debug3_Byte2
typedef uint8 Debug3_Byte2;

# define Rte_TypeDef_Debug3_Byte3
typedef uint8 Debug3_Byte3;

# define Rte_TypeDef_Debug3_Byte4
typedef uint8 Debug3_Byte4;

# define Rte_TypeDef_Debug3_Byte5
typedef uint8 Debug3_Byte5;

# define Rte_TypeDef_Debug3_Byte6
typedef uint8 Debug3_Byte6;

# define Rte_TypeDef_Debug3_Byte7
typedef uint8 Debug3_Byte7;

# define Rte_TypeDef_Debug4_Byte0
typedef uint8 Debug4_Byte0;

# define Rte_TypeDef_Debug4_Byte1
typedef uint8 Debug4_Byte1;

# define Rte_TypeDef_Debug4_Byte2
typedef uint8 Debug4_Byte2;

# define Rte_TypeDef_Debug4_Byte3
typedef uint8 Debug4_Byte3;

# define Rte_TypeDef_Debug4_Byte4
typedef uint8 Debug4_Byte4;

# define Rte_TypeDef_Debug4_Byte5
typedef uint8 Debug4_Byte5;

# define Rte_TypeDef_Debug4_Byte6
typedef uint8 Debug4_Byte6;

# define Rte_TypeDef_Debug4_Byte7
typedef uint8 Debug4_Byte7;

# define Rte_TypeDef_Debug5_Byte0
typedef uint8 Debug5_Byte0;

# define Rte_TypeDef_Debug5_Byte1
typedef uint8 Debug5_Byte1;

# define Rte_TypeDef_Debug5_Byte2
typedef uint8 Debug5_Byte2;

# define Rte_TypeDef_Debug5_Byte3
typedef uint8 Debug5_Byte3;

# define Rte_TypeDef_Debug5_Byte4
typedef uint8 Debug5_Byte4;

# define Rte_TypeDef_Debug5_Byte5
typedef uint8 Debug5_Byte5;

# define Rte_TypeDef_Debug5_Byte6
typedef uint8 Debug5_Byte6;

# define Rte_TypeDef_Debug5_Byte7
typedef uint8 Debug5_Byte7;

# define Rte_TypeDef_Dem_DTCFormatType
typedef uint8 Dem_DTCFormatType;

# define Rte_TypeDef_Dem_DTCOriginType
typedef uint8 Dem_DTCOriginType;

# define Rte_TypeDef_Dem_DebouncingStateType
typedef uint8 Dem_DebouncingStateType;

# define Rte_TypeDef_Dem_EventIdType
typedef uint16 Dem_EventIdType;

# define Rte_TypeDef_Dem_EventStatusType
typedef uint8 Dem_EventStatusType;

# define Rte_TypeDef_Dem_OperationCycleStateType
typedef uint8 Dem_OperationCycleStateType;

# define Rte_TypeDef_Dem_UdsStatusByteType
typedef uint8 Dem_UdsStatusByteType;

# define Rte_TypeDef_Dlt_MessageArgumentCount
typedef uint16 Dlt_MessageArgumentCount;

# define Rte_TypeDef_Dlt_MessageOptionsType
typedef uint8 Dlt_MessageOptionsType;

# define Rte_TypeDef_Dlt_SessionIDType
typedef uint32 Dlt_SessionIDType;

# define Rte_TypeDef_EChimeStatus
typedef uint16 EChimeStatus;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_EngineSpeed
typedef uint16 EngineSpeed;

# define Rte_TypeDef_FV_Tx
typedef uint8 FV_Tx;

# define Rte_TypeDef_Gear
typedef uint8 Gear;

# define Rte_TypeDef_GearMode
typedef boolean GearMode;

# define Rte_TypeDef_Illumination_PWM
typedef uint8 Illumination_PWM;

# define Rte_TypeDef_Illumination_level
typedef uint8 Illumination_level;

# define Rte_TypeDef_MAC_Tx
typedef uint32 MAC_Tx;

# define Rte_TypeDef_NvM_BlockIdType
typedef uint16 NvM_BlockIdType;

# define Rte_TypeDef_NvM_RequestResultType
typedef uint8 NvM_RequestResultType;

# define Rte_TypeDef_Odometer
typedef uint32 Odometer;

# define Rte_TypeDef_PreviousStateIC
typedef sint8 PreviousStateIC;

# define Rte_TypeDef_Rte_DT_Arr_u16_7_0
typedef uint16 Rte_DT_Arr_u16_7_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_100_0
typedef uint8 Rte_DT_Arr_u8_100_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_1024_0
typedef uint8 Rte_DT_Arr_u8_1024_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_10_0
typedef uint8 Rte_DT_Arr_u8_10_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_128_0
typedef uint8 Rte_DT_Arr_u8_128_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_16_0
typedef uint8 Rte_DT_Arr_u8_16_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_17_0
typedef uint8 Rte_DT_Arr_u8_17_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_2048_0
typedef uint8 Rte_DT_Arr_u8_2048_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_256_0
typedef uint8 Rte_DT_Arr_u8_256_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_28_0
typedef uint8 Rte_DT_Arr_u8_28_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_32_0
typedef uint8 Rte_DT_Arr_u8_32_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_3_0
typedef uint8 Rte_DT_Arr_u8_3_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_46_0
typedef uint8 Rte_DT_Arr_u8_46_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_48_0
typedef uint8 Rte_DT_Arr_u8_48_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_61_0
typedef uint8 Rte_DT_Arr_u8_61_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_64_0
typedef uint8 Rte_DT_Arr_u8_64_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_8_0
typedef uint8 Rte_DT_Arr_u8_8_0;

# define Rte_TypeDef_Rte_DT_Arr_u8_9_0
typedef uint8 Rte_DT_Arr_u8_9_0;

# define Rte_TypeDef_Rte_DT_Dlt_ApplicationIDType_0
typedef uint8 Rte_DT_Dlt_ApplicationIDType_0;

# define Rte_TypeDef_Rte_DT_Dlt_ContextIDType_0
typedef uint8 Rte_DT_Dlt_ContextIDType_0;

# define Rte_TypeDef_Rte_DT_Dlt_LogChannelNameType_0
typedef uint8 Rte_DT_Dlt_LogChannelNameType_0;

# define Rte_TypeDef_Rte_DT_PayloadArr_u8_8_0
typedef uint8 Rte_DT_PayloadArr_u8_8_0;

# define Rte_TypeDef_Rte_DT_TTBlinkArray_0
typedef uint8 Rte_DT_TTBlinkArray_0;

# define Rte_TypeDef_Rte_DT_TT_OP_Type_0
typedef uint8 Rte_DT_TT_OP_Type_0;

# define Rte_TypeDef_Rte_DT_T_NV_Temperature_Conversion_0
typedef uint32 Rte_DT_T_NV_Temperature_Conversion_0;

# define Rte_TypeDef_Rte_DT_Tpms_Arr_u8_5_0
typedef uint8 Rte_DT_Tpms_Arr_u8_5_0;

# define Rte_TypeDef_Rte_DT_data_u32_5_0
typedef uint32 Rte_DT_data_u32_5_0;

# define Rte_TypeDef_Rte_DT_data_u8_10_0
typedef uint8 Rte_DT_data_u8_10_0;

# define Rte_TypeDef_Rte_DT_data_u8_15_0
typedef uint8 Rte_DT_data_u8_15_0;

# define Rte_TypeDef_Rte_DT_data_u8_256_0
typedef uint8 Rte_DT_data_u8_256_0;

# define Rte_TypeDef_Rte_DT_data_u8_2_0
typedef uint8 Rte_DT_data_u8_2_0;

# define Rte_TypeDef_Rte_DT_data_u8_32_0
typedef uint8 Rte_DT_data_u8_32_0;

# define Rte_TypeDef_Rte_DT_data_u8_512_0
typedef uint8 Rte_DT_data_u8_512_0;

# define Rte_TypeDef_Rte_DT_data_u8_64_0
typedef uint8 Rte_DT_data_u8_64_0;

# define Rte_TypeDef_Rte_DT_data_u8_8_0
typedef uint8 Rte_DT_data_u8_8_0;

# define Rte_TypeDef_SInt16
typedef sint16 SInt16;

# define Rte_TypeDef_SInt32
typedef sint32 SInt32;

# define Rte_TypeDef_SInt8
typedef sint8 SInt8;

# define Rte_TypeDef_SecureTxByte0
typedef uint8 SecureTxByte0;

# define Rte_TypeDef_SecureTxByte1
typedef uint8 SecureTxByte1;

# define Rte_TypeDef_SecureTxByte2
typedef uint8 SecureTxByte2;

# define Rte_TypeDef_SecureTxByte3
typedef uint8 SecureTxByte3;

# define Rte_TypeDef_TransportMode
typedef boolean TransportMode;

# define Rte_TypeDef_Turn_Indicator_Control
typedef uint8 Turn_Indicator_Control;

# define Rte_TypeDef_UInt16
typedef uint16 UInt16;

# define Rte_TypeDef_UInt32
typedef uint32 UInt32;

# define Rte_TypeDef_UInt8
typedef uint8 UInt8;

# define Rte_TypeDef_UserData1_IC
typedef uint8 UserData1_IC;

# define Rte_TypeDef_UserData2_IC
typedef uint8 UserData2_IC;

# define Rte_TypeDef_UserData3_IC
typedef uint8 UserData3_IC;

# define Rte_TypeDef_UserData4_IC
typedef uint8 UserData4_IC;

# define Rte_TypeDef_UserData5_IC
typedef uint8 UserData5_IC;

# define Rte_TypeDef_VehicleSpeedABS
typedef uint16 VehicleSpeedABS;

# define Rte_TypeDef_VehicleSpeedIC
typedef uint16 VehicleSpeedIC;

# define Rte_TypeDef_Warning
typedef uint8 Warning;

# define Rte_TypeDef_dtRef_VOID
typedef void * dtRef_VOID;

# define Rte_TypeDef_dtRef_const_VOID
typedef const void * dtRef_const_VOID;

# define Rte_TypeDef_Airbag
typedef uint8 Airbag;

# define Rte_TypeDef_BOOL_TYPE
typedef uint8 BOOL_TYPE;

# define Rte_TypeDef_BulbTestStatus
typedef uint16 BulbTestStatus;

# define Rte_TypeDef_ClusterInitModes
typedef uint8 ClusterInitModes;

# define Rte_TypeDef_ClusterModes
typedef uint8 ClusterModes;

# define Rte_TypeDef_CountryCode_FuncType
typedef uint8 CountryCode_FuncType;

# define Rte_TypeDef_CustResetType
typedef uint8 CustResetType;

# define Rte_TypeDef_DisplayStatus
typedef uint8 DisplayStatus;

# define Rte_TypeDef_Dlt_AssignmentOperation
typedef uint8 Dlt_AssignmentOperation;

# define Rte_TypeDef_Dlt_MessageLogLevelType
typedef uint8 Dlt_MessageLogLevelType;

# define Rte_TypeDef_Dlt_MessageTraceType
typedef uint8 Dlt_MessageTraceType;

# define Rte_TypeDef_EButtonId
typedef uint8 EButtonId;

# define Rte_TypeDef_EButtonSts
typedef uint8 EButtonSts;

# define Rte_TypeDef_EChimeID
typedef uint8 EChimeID;

# define Rte_TypeDef_ECmpCmd
typedef uint8 ECmpCmd;

# define Rte_TypeDef_EDcmExtAction
typedef uint8 EDcmExtAction;

# define Rte_TypeDef_EDeviceStatus
typedef uint8 EDeviceStatus;

# define Rte_TypeDef_EDidType
typedef uint8 EDidType;

# define Rte_TypeDef_EDisplayCddStatus
typedef uint8 EDisplayCddStatus;

# define Rte_TypeDef_EDisplayPower
typedef uint8 EDisplayPower;

# define Rte_TypeDef_EDisplayPowerState
typedef uint8 EDisplayPowerState;

# define Rte_TypeDef_EDisplayStatus
typedef uint8 EDisplayStatus;

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

# define Rte_TypeDef_EGaugeUnit
typedef uint8 EGaugeUnit;

# define Rte_TypeDef_EIOCtrlOptType
typedef uint8 EIOCtrlOptType;

# define Rte_TypeDef_EIgnitionStatus
typedef uint8 EIgnitionStatus;

# define Rte_TypeDef_EMeetModeStatus
typedef uint8 EMeetModeStatus;

# define Rte_TypeDef_ERoutineType
typedef uint8 ERoutineType;

# define Rte_TypeDef_ESystemState
typedef uint8 ESystemState;

# define Rte_TypeDef_EUclLinkState_t
typedef uint8 EUclLinkState_t;

# define Rte_TypeDef_GearRecommendation
typedef uint8 GearRecommendation;

# define Rte_TypeDef_GearStatus
typedef uint8 GearStatus;

# define Rte_TypeDef_HMIReadySts_Type
typedef uint8 HMIReadySts_Type;

# define Rte_TypeDef_HMI_Odo_Type
typedef uint8 HMI_Odo_Type;

# define Rte_TypeDef_HMI_Screen_Mode
typedef uint8 HMI_Screen_Mode;

# define Rte_TypeDef_HTimer
typedef uint8 HTimer;

# define Rte_TypeDef_Hud_Wake_Type
typedef uint8 Hud_Wake_Type;

# define Rte_TypeDef_IOCtrl_Type
typedef uint8 IOCtrl_Type;

# define Rte_TypeDef_IgntionSubstateType
typedef uint8 IgntionSubstateType;

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

# define Rte_TypeDef_ModeStatus
typedef uint8 ModeStatus;

# define Rte_TypeDef_PowerMode
typedef uint8 PowerMode;

# define Rte_TypeDef_SettingResetResult_Type
typedef uint8 SettingResetResult_Type;

# define Rte_TypeDef_ShiftPosition
typedef uint8 ShiftPosition;

# define Rte_TypeDef_ShiftPositionInd
typedef uint8 ShiftPositionInd;

# define Rte_TypeDef_SleepType
typedef uint8 SleepType;

# define Rte_TypeDef_TFTIgnBlankSts_T
typedef uint8 TFTIgnBlankSts_T;

# define Rte_TypeDef_TTFlashMask
typedef uint8 TTFlashMask;

# define Rte_TypeDef_TT_ENUM_TYPE
typedef uint8 TT_ENUM_TYPE;

# define Rte_TypeDef_TT_OP_STATES
typedef uint8 TT_OP_STATES;

# define Rte_TypeDef_Target_SW_Status
typedef uint8 Target_SW_Status;

# define Rte_TypeDef_TurnStates
typedef uint8 TurnStates;

# define Rte_TypeDef_UserIdType
typedef uint8 UserIdType;

# define Rte_TypeDef_VehicleActiveModes
typedef uint8 VehicleActiveModes;

# define Rte_TypeDef_WarningDisplayedStatus
typedef uint8 WarningDisplayedStatus;

# define Rte_TypeDef_WarningEvent
typedef uint8 WarningEvent;

# define Rte_TypeDef_WarningId
typedef uint16 WarningId;

# define Rte_TypeDef_WarningStatus
typedef uint8 WarningStatus;

# define Rte_TypeDef_eAppMdl
typedef uint8 eAppMdl;

# define Rte_TypeDef_eFltM_FaultIdType
typedef uint16 eFltM_FaultIdType;

# define Rte_TypeDef_eFltM_FaultStatusType
typedef uint8 eFltM_FaultStatusType;

# define Rte_TypeDef_eFltM_FlsIntegrityStatusType
typedef uint8 eFltM_FlsIntegrityStatusType;

# define Rte_TypeDef_eIOPulseInputId
typedef sint32 eIOPulseInputId;

# define Rte_TypeDef_eSleepSt
typedef uint8 eSleepSt;

# define Rte_TypeDef_tRxSafeSignalId
typedef uint8 tRxSafeSignalId;

# define Rte_TypeDef_tRxSafeSignalJustRcvdStatus
typedef uint8 tRxSafeSignalJustRcvdStatus;

# define Rte_TypeDef_tRxSignalId
typedef uint8 tRxSignalId;

# define Rte_TypeDef_tRxSignalJustRcvdStatus
typedef uint8 tRxSignalJustRcvdStatus;

# define Rte_TypeDef_tRxSignalStatus
typedef uint8 tRxSignalStatus;

# define Rte_TypeDef_tSafeRxSignalId
typedef uint8 tSafeRxSignalId;

# define Rte_TypeDef_tSafeRxSignalJustRcvdStatus
typedef uint8 tSafeRxSignalJustRcvdStatus;

# define Rte_TypeDef_tSafeRxSignalStatus
typedef uint8 tSafeRxSignalStatus;

# define Rte_TypeDef_tSafeTxSignalId
typedef uint8 tSafeTxSignalId;

# define Rte_TypeDef_tTxSigConfirmStatus
typedef uint8 tTxSigConfirmStatus;

# define Rte_TypeDef_tTxSignalId
typedef uint8 tTxSignalId;

# define Rte_TypeDef_teDIDOperation
typedef uint8 teDIDOperation;

# define Rte_TypeDef_teDiagOpStatus
typedef uint8 teDiagOpStatus;

# define Rte_TypeDef_teRoutineOperation
typedef uint8 teRoutineOperation;

# define Rte_TypeDef_Arr_u16_7
typedef Rte_DT_Arr_u16_7_0 Arr_u16_7[7];

# define Rte_TypeDef_Arr_u8_10
typedef Rte_DT_Arr_u8_10_0 Arr_u8_10[10];

# define Rte_TypeDef_Arr_u8_100
typedef Rte_DT_Arr_u8_100_0 Arr_u8_100[100];

# define Rte_TypeDef_Arr_u8_1024
typedef Rte_DT_Arr_u8_1024_0 Arr_u8_1024[1024];

# define Rte_TypeDef_Arr_u8_128
typedef Rte_DT_Arr_u8_128_0 Arr_u8_128[128];

# define Rte_TypeDef_Arr_u8_16
typedef Rte_DT_Arr_u8_16_0 Arr_u8_16[16];

# define Rte_TypeDef_Arr_u8_17
typedef Rte_DT_Arr_u8_17_0 Arr_u8_17[17];

# define Rte_TypeDef_Arr_u8_2048
typedef Rte_DT_Arr_u8_2048_0 Arr_u8_2048[2048];

# define Rte_TypeDef_Arr_u8_256
typedef Rte_DT_Arr_u8_256_0 Arr_u8_256[256];

# define Rte_TypeDef_Arr_u8_28
typedef Rte_DT_Arr_u8_28_0 Arr_u8_28[28];

# define Rte_TypeDef_Arr_u8_3
typedef Rte_DT_Arr_u8_3_0 Arr_u8_3[3];

# define Rte_TypeDef_Arr_u8_32
typedef Rte_DT_Arr_u8_32_0 Arr_u8_32[32];

# define Rte_TypeDef_Arr_u8_46
typedef Rte_DT_Arr_u8_46_0 Arr_u8_46[46];

# define Rte_TypeDef_Arr_u8_48
typedef Rte_DT_Arr_u8_48_0 Arr_u8_48[48];

# define Rte_TypeDef_Arr_u8_61
typedef Rte_DT_Arr_u8_61_0 Arr_u8_61[61];

# define Rte_TypeDef_Arr_u8_64
typedef Rte_DT_Arr_u8_64_0 Arr_u8_64[64];

# define Rte_TypeDef_Arr_u8_8
typedef Rte_DT_Arr_u8_8_0 Arr_u8_8[8];

# define Rte_TypeDef_Arr_u8_9
typedef Rte_DT_Arr_u8_9_0 Arr_u8_9[9];

# define Rte_TypeDef_Dem_MaxDataValueType
typedef uint8 Dem_MaxDataValueType[1];

# define Rte_TypeDef_Diag_Buffer_Tx_USDT
typedef UInt8 Diag_Buffer_Tx_USDT[8];

# define Rte_TypeDef_Diag_Buffer_Tx_UUDT
typedef UInt8 Diag_Buffer_Tx_UUDT[8];

# define Rte_TypeDef_Dlt_ApplicationIDType
typedef Rte_DT_Dlt_ApplicationIDType_0 Dlt_ApplicationIDType[4];

# define Rte_TypeDef_Dlt_ContextIDType
typedef Rte_DT_Dlt_ContextIDType_0 Dlt_ContextIDType[4];

# define Rte_TypeDef_Dlt_LogChannelNameType
typedef Rte_DT_Dlt_LogChannelNameType_0 Dlt_LogChannelNameType[4];

# define Rte_TypeDef_PayloadArr_u8_8
typedef Rte_DT_PayloadArr_u8_8_0 PayloadArr_u8_8[8];

# define Rte_TypeDef_TTBlinkArray
typedef Rte_DT_TTBlinkArray_0 TTBlinkArray[16];

# define Rte_TypeDef_TT_OP_Type
typedef Rte_DT_TT_OP_Type_0 TT_OP_Type[92];

# define Rte_TypeDef_T_NV_Temperature_Conversion
typedef Rte_DT_T_NV_Temperature_Conversion_0 T_NV_Temperature_Conversion[2];

# define Rte_TypeDef_Tpms_Arr_u8_5
typedef Rte_DT_Tpms_Arr_u8_5_0 Tpms_Arr_u8_5[5];

# define Rte_TypeDef_data_u32_5
typedef Rte_DT_data_u32_5_0 data_u32_5[5];

# define Rte_TypeDef_data_u8_10
typedef Rte_DT_data_u8_10_0 data_u8_10[10];

# define Rte_TypeDef_data_u8_15
typedef Rte_DT_data_u8_15_0 data_u8_15[15];

# define Rte_TypeDef_data_u8_2
typedef Rte_DT_data_u8_2_0 data_u8_2[2];

# define Rte_TypeDef_data_u8_256
typedef Rte_DT_data_u8_256_0 data_u8_256[256];

# define Rte_TypeDef_data_u8_32
typedef Rte_DT_data_u8_32_0 data_u8_32[32];

# define Rte_TypeDef_data_u8_512
typedef Rte_DT_data_u8_512_0 data_u8_512[512];

# define Rte_TypeDef_data_u8_64
typedef Rte_DT_data_u8_64_0 data_u8_64[64];

# define Rte_TypeDef_data_u8_8
typedef uint8 data_u8_8[8];

# define Rte_TypeDef_IllumCtrl_Ip
typedef struct
{
  UInt8 Illumination_Mode;
  UInt8 battery_status;
  UInt8 Illumination_Sts;
  UInt8 power_mode;
  UInt8 step_value;
  UInt8 step_direction;
  UInt8 switch_type;
  UInt16 Derating_Value;
} IllumCtrl_Ip;

# define Rte_TypeDef_IllumCtrl_Op
typedef struct
{
  UInt16 Brightness_Out;
  UInt16 Bulb_PWM_Out;
  UInt16 Illumination_Duty_Out;
  UInt16 RGB_Dimming_Out;
  UInt16 LED_PWM_Out;
  UInt16 Dial_Out;
  UInt16 Display_Out;
  UInt16 Telltale_Out;
} IllumCtrl_Op;

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
  UInt8 month;
  UInt8 week;
  UInt8 day;
  UInt8 hour;
  UInt8 minute;
  UInt8 second;
} Rtc_TimeType;

# define Rte_TypeDef_SDLTControlMessageReponse
typedef struct
{
  UInt8 status;
} SDLTControlMessageReponse;

# define Rte_TypeDef_SDLTControlMessageRequest
typedef struct
{
  UInt8 status;
} SDLTControlMessageRequest;

# define Rte_TypeDef_SDLTMessageReadAck
typedef struct
{
  UInt8 status;
} SDLTMessageReadAck;

# define Rte_TypeDef_SDLTMessageReadRequest
typedef struct
{
  UInt8 status;
} SDLTMessageReadRequest;

# define Rte_TypeDef_SDisplayCurrentState
typedef struct
{
  UInt32 displayId;
  EDisplayStatus state;
} SDisplayCurrentState;

# define Rte_TypeDef_SDisplaySetPower
typedef struct
{
  UInt32 displayId;
  EDisplayPower state;
} SDisplaySetPower;

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

# define Rte_TypeDef_SEmmcErrorNotifier
typedef struct
{
  UInt32 errorCode;
} SEmmcErrorNotifier;

# define Rte_TypeDef_SG_ABS
typedef struct
{
  Airbag Airbag;
  Alive_101 Alive_101;
  CRC_101 CRC_101;
  VehicleSpeedABS VehicleSpeedABS;
} SG_ABS;

# define Rte_TypeDef_SG_COM_HS
typedef struct
{
  Alive_200 Alive_200;
  Battery_Voltage Battery_Voltage;
  CRC_200 CRC_200;
} SG_COM_HS;

# define Rte_TypeDef_SGaugeInfo
typedef struct
{
  UInt8 id;
  UInt16 position;
  SInt32 digitalData;
  EGaugeUnit unit;
  UInt16 dynData;
} SGaugeInfo;

# define Rte_TypeDef_SGaugeInfo_u32dyn
typedef struct
{
  UInt8 id;
  UInt16 position;
  UInt32 digitalData;
  EGaugeUnit unit;
  UInt16 dynData;
} SGaugeInfo_u32dyn;

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

# define Rte_TypeDef_SIlluminationData
typedef struct
{
  UInt8 data;
  UInt8 dayStep;
  UInt8 nightStep;
  UInt8 daynightStatus;
} SIlluminationData;

# define Rte_TypeDef_SMainHMIReadyStatus
typedef struct
{
  UInt8 status;
} SMainHMIReadyStatus;

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

# define Rte_TypeDef_SRTT_Toggle
typedef struct
{
  UInt8 positions;
  UInt8 display;
} SRTT_Toggle;

# define Rte_TypeDef_SSafeHMIReadyStatus
typedef struct
{
  UInt8 status;
} SSafeHMIReadyStatus;

# define Rte_TypeDef_SShiftInd
typedef struct
{
  UInt8 Shift_Ind_Pos;
  UInt8 Shift_Ind_BlinkReq;
  UInt8 Shift_Ind_DisplayDecState;
  UInt8 Shift_Ind_Down;
  UInt8 Shift_Ind_Screen_ShiftType;
  UInt8 Shift_Ind_Up;
} SShiftInd;

# define Rte_TypeDef_SSpeedCalcParam
typedef struct
{
  UInt32 Pulses_Per_Revolution;
  UInt32 Revolutions_Per_Unit;
  UInt32 Tuning_Factor;
} SSpeedCalcParam;

# define Rte_TypeDef_SWarningDisplayAvailable
typedef struct
{
  UInt8 status;
} SWarningDisplayAvailable;

# define Rte_TypeDef_ShiftposData_Type
typedef struct
{
  UInt8 Shift_Up_Ind;
  UInt8 DisplayDecState;
  UInt16 Shift_Ind_Pos;
  UInt8 Shift_Down_Ind;
  UInt8 Screen_ShiftType;
} ShiftposData_Type;

# define Rte_TypeDef_WarningDataS
typedef struct
{
  WarningStatus WarningCurrentStatus;
  WarningEvent WarningCurrentEvent;
  UInt32 WarningCurrentPayload;
} WarningDataS;

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
typedef UInt8 EcuM_BootTargetType;

# define Rte_TypeDef_EcuM_ModeType
typedef UInt8 EcuM_ModeType;

# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef UInt8 EcuM_ShutdownCauseType;

# define Rte_TypeDef_EcuM_StateType
typedef UInt8 EcuM_StateType;

# define Rte_TypeDef_EcuM_TimeType
typedef UInt32 EcuM_TimeType;

# define Rte_TypeDef_EnetReqCmd_t
typedef uint8 EnetReqCmd_t;

# define Rte_TypeDef_EnetReqMode_t
typedef uint8 EnetReqMode_t;

# define Rte_TypeDef_ExtWarningData
typedef struct
{
  WarningStatus ExtWarningCurrentStatus;
  WarningEvent ExtWarningCurrentEvent;
  PayloadArr_u8_8 ExtWarningCurrentPayload;
} ExtWarningData;

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
  uint32 BsConst_Compensation_Line_Slope_m;
  uint32 BsConst_Compensation_Line_Shift_b;
  Arr_u16_7 BsConst_Lookup_Curve_HotSpot_Coef_X;
  Arr_u16_7 BsConst_Lookup_Curve_HotSpot_Coef_Y;
  uint8 BsConst_Temp_Threshold_Hysteresis_Derating;
  uint8 BsConst_Derating_Backlight_Disable;
  T_NV_Temperature_Conversion BsConst_Temperature_Sensor_Conv;
  T_NV_Temperature_Conversion BsConst_PCB_Temperature_Sensor_Conv;
  uint16 BsConst_Display_Illum_Max_Level;
  uint8 BsConst_PWM_boost_bypass_duty;
  Arr_u8_28 BsConst_BsConst_Illumination_ReservedByte;
} NV_Data_BsConst_Illumination;

# define Rte_TypeDef_NV_Data_BsConst_Illumination_Copy1
typedef struct
{
  uint32 BsConst_Compensation_Line_Slope_m_SafeCopy1;
  uint32 BsConst_Compensation_Line_Shift_b_SafeCopy1;
  Arr_u16_7 BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1;
  Arr_u16_7 BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1;
  uint8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1;
  uint8 BsConst_Derating_Backlight_Disable_SafeCopy1;
  T_NV_Temperature_Conversion BsConst_Temperature_Sensor_Conv_SafeCopy1;
  T_NV_Temperature_Conversion BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1;
  uint16 BsConst_Display_Illum_Max_Level_SafeCopy1;
  uint8 BsConst_PWM_boost_bypass_duty_SafeCopy1;
  Arr_u8_28 BsConst_BsConst_Illumination_ReservedByte_SafeCopy1;
} NV_Data_BsConst_Illumination_Copy1;

# define Rte_TypeDef_NV_Data_BsConst_Illumination_Copy2
typedef struct
{
  uint32 BsConst_Compensation_Line_Slope_m_SafeCopy2;
  uint32 BsConst_Compensation_Line_Shift_b_SafeCopy2;
  Arr_u16_7 BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2;
  Arr_u16_7 BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2;
  uint8 BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2;
  uint8 BsConst_Derating_Backlight_Disable_SafeCopy2;
  T_NV_Temperature_Conversion BsConst_Temperature_Sensor_Conv_SafeCopy2;
  T_NV_Temperature_Conversion BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2;
  uint16 BsConst_Display_Illum_Max_Level_SafeCopy2;
  uint8 BsConst_PWM_boost_bypass_duty_SafeCopy2;
  Arr_u8_28 BsConst_BsConst_Illumination_ReservedByte_SafeCopy2;
} NV_Data_BsConst_Illumination_Copy2;

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
  Arr_u8_61 BsShare_EcuPartNumber_Element;
  Arr_u8_17 BsShare_VisteonPartNumber;
  Arr_u8_17 BsShare_VisteonPCBPartNumber;
  Arr_u8_10 BsShare_ProductSerialNumber;
  Arr_u8_9 BsShare_PCBSerialNumber;
  Arr_u8_3 BsShare_SMTManufacturingDate;
  Arr_u8_3 BsShare_AssemblyManufacturingDate;
  Arr_u8_3 BsShare_SMTPlantNumber;
  Arr_u8_3 BsShare_AssemblyPlantNumber;
  uint16 BsShare_HWModification;
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
  Arr_u8_46 BsShare_VisMeet_Element;
  uint16 BsShare_VisMeet_EOLEntry_Element;
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
  ERoutineType routineType;
  UInt16 dataLen;
  data_u8_256 data;
} SDiagRoutineRequest;

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

# define Rte_TypeDef_SFRTT_Status
typedef struct
{
  data_u8_2 mask;
} SFRTT_Status;

# define Rte_TypeDef_SGaugeInfo_u32dyn_2
typedef SGaugeInfo_u32dyn SGaugeInfo_u32dyn_2[2];

# define Rte_TypeDef_SHealthDumpData
typedef struct
{
  UInt32 chunkSize;
  data_u8_32 data;
} SHealthDumpData;

# define Rte_TypeDef_SHealthEventRecord
typedef struct
{
  UInt8 recordType;
  UInt8 recordLen;
  data_u8_8 recordData;
} SHealthEventRecord;

# define Rte_TypeDef_SHudWarningDisplay
typedef struct
{
  UInt8 show;
  UInt16 warningId;
  data_u8_8 dynData;
} SHudWarningDisplay;

# define Rte_TypeDef_SHudWarningStatus
typedef struct
{
  UInt8 visible;
  UInt16 warningId;
  data_u8_10 dynData;
} SHudWarningStatus;

# define Rte_TypeDef_SRTT_Icon
typedef struct
{
  data_u8_2 icon;
} SRTT_Icon;

# define Rte_TypeDef_SRTT_Status
typedef struct
{
  data_u8_2 mask;
} SRTT_Status;

# define Rte_TypeDef_SShiftPosIndStatus
typedef struct
{
  SShiftInd status;
} SShiftPosIndStatus;

# define Rte_TypeDef_SSlowGuageInfo
typedef struct
{
  SGaugeInfo gaugeInfo;
} SSlowGuageInfo;

# define Rte_TypeDef_STT_Status
typedef struct
{
  data_u8_15 mask;
} STT_Status;

# define Rte_TypeDef_STpmsWarningData
typedef struct
{
  data_u32_5 tpmsWarndata;
} STpmsWarningData;

# define Rte_TypeDef_SUpdateLongServiceReq
typedef struct
{
  UInt16 msgId;
  UInt16 msgSize;
  UInt8 memoryType;
  UInt8 memoryCmd;
  UInt8 sid;
  UInt32 length;
  data_u8_512 data;
} SUpdateLongServiceReq;

# define Rte_TypeDef_SUpdateShortServiceReq
typedef struct
{
  UInt16 msgId;
  UInt16 msgSize;
  UInt8 memoryType;
  UInt8 memoryCmd;
  UInt8 sid;
  UInt32 length;
  data_u8_64 data;
} SUpdateShortServiceReq;

# define Rte_TypeDef_SUpdateShortServiceResp
typedef struct
{
  UInt16 msgId;
  UInt16 msgSize;
  UInt8 sid;
  UInt16 length;
  UInt8 responseCode;
  UInt8 NRC;
  data_u8_64 data;
} SUpdateShortServiceResp;

# define Rte_TypeDef_SWarningDisplay
typedef struct
{
  UInt8 show;
  UInt16 warningId;
  data_u8_8 dynData;
} SWarningDisplay;

# define Rte_TypeDef_SWarningExtDisplay
typedef struct
{
  UInt8 show;
  UInt16 warningId;
  data_u8_8 dynData;
} SWarningExtDisplay;

# define Rte_TypeDef_SWarningStatus
typedef struct
{
  UInt8 visible;
  UInt16 warningId;
  data_u8_10 dynData;
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

# define Rte_TypeDef_SFastGaugeInfo
typedef struct
{
  SGaugeInfo_u32dyn_2 gaugeInfo;
} SFastGaugeInfo;


# ifndef RTE_SUPPRESS_UNUSED_DATATYPES
/**********************************************************************************************************************
 * Unused Data type definitions
 *********************************************************************************************************************/

#  define Rte_TypeDef_ELastToneStatus
typedef boolean ELastToneStatus;

#  define Rte_TypeDef_EcuMExt_ResetType
typedef uint8 EcuMExt_ResetType;

#  define Rte_TypeDef_FltM_FaultIdType
typedef uint16 FltM_FaultIdType;

#  define Rte_TypeDef_Rte_DT_Nvm_U8ArrType_3_0
typedef uint8 Rte_DT_Nvm_U8ArrType_3_0;

#  define Rte_TypeDef_Rte_DT_data_u8_12_0
typedef uint8 Rte_DT_data_u8_12_0;

#  define Rte_TypeDef_Rte_DT_data_u8_4_0
typedef uint8 Rte_DT_data_u8_4_0;

#  define Rte_TypeDef_Rte_DT_data_uint8_8_0
typedef uint8 Rte_DT_data_uint8_8_0;

#  define Rte_TypeDef_uint8_Ref
typedef uint8 uint8_Ref;

#  define Rte_TypeDef_EChimeType
typedef uint8 EChimeType;

#  define Rte_TypeDef_ESndInterruptType
typedef uint8 ESndInterruptType;

#  define Rte_TypeDef_ESndToneInterruptableType
typedef uint8 ESndToneInterruptableType;

#  define Rte_TypeDef_RstM_FaultIdType
typedef uint8 RstM_FaultIdType;

#  define Rte_TypeDef_RstM_ResetType
typedef uint8 RstM_ResetType;

#  define Rte_TypeDef_tRxSafeSignalStatus
typedef uint8 tRxSafeSignalStatus;

#  define Rte_TypeDef_Nvm_U8ArrType_3
typedef Rte_DT_Nvm_U8ArrType_3_0 Nvm_U8ArrType_3[3];

#  define Rte_TypeDef_data_u8_12
typedef Rte_DT_data_u8_12_0 data_u8_12[12];

#  define Rte_TypeDef_data_u8_4
typedef Rte_DT_data_u8_4_0 data_u8_4[4];

#  define Rte_TypeDef_data_uint8_8
typedef Rte_DT_data_uint8_8_0 data_uint8_8[8];

#  define Rte_TypeDef_RstM_ResetHistoryType
typedef struct
{
  UInt32 ResetTime;
  RstM_FaultIdType FaultId;
  RstM_ResetType ResetType;
} RstM_ResetHistoryType;

#  define Rte_TypeDef_RstM_ResetLogType
typedef struct
{
  UInt16 ModuleId;
  UInt8 InstanceId;
  UInt8 ApiId;
  RstM_FaultIdType FaultId;
  UInt8 ErrorId;
} RstM_ResetLogType;

#  define Rte_TypeDef_SKeyVal1
typedef struct
{
  UInt8 key;
  UInt8 value;
} SKeyVal1;

#  define Rte_TypeDef_SSndCddChimeData
typedef struct
{
  UInt8 ChannelId;
  EChimeType ChimeType;
  UInt16 DynamicDeadTime;
} SSndCddChimeData;

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

#  define Rte_TypeDef_BswM_MDG_Sfd_NvmBlockStatus
typedef UInt8 BswM_MDG_Sfd_NvmBlockStatus;

#  define Rte_TypeDef_ComM_InhibitionStatusType
typedef UInt8 ComM_InhibitionStatusType;

#  define Rte_TypeDef_ComM_ModeType
typedef UInt8 ComM_ModeType;

#  define Rte_TypeDef_ComM_UserHandleType
typedef UInt8 ComM_UserHandleType;

#  define Rte_TypeDef_Ivd_RequestPostRun
typedef UInt8 Ivd_RequestPostRun;

#  define Rte_TypeDef_NV_Data_BsFuSa_Audio
typedef struct
{
  Arr_u8_32 BsFuSa_Audio_Element;
} NV_Data_BsFuSa_Audio;

#  define Rte_TypeDef_NV_Data_BsFuSa_Communication
typedef struct
{
  Arr_u8_16 BsFuSa_Communication_Element;
} NV_Data_BsFuSa_Communication;

#  define Rte_TypeDef_NV_Data_BsFuSa_Config
typedef struct
{
  Arr_u8_16 BsFuSa_Config_Element;
} NV_Data_BsFuSa_Config;

#  define Rte_TypeDef_NV_Data_BsFuSa_Display
typedef struct
{
  Arr_u8_64 BsFuSa_Display_Element;
} NV_Data_BsFuSa_Display;

#  define Rte_TypeDef_NV_Data_BsFuSa_FeatureData
typedef struct
{
  Arr_u8_3 BsFuSa_FeatureData_Warning_Element;
  Arr_u8_10 BsFuSa_FeatureData_Power_Element;
  UInt16 BsFuSa_FeatureData_Display_Element;
  Arr_u8_8 BsFuSa_FeatureData_Audio_Element;
  Arr_u8_9 BsFuSa_FeatureData_Communication_Element;
  UInt16 BsFuSa_FeatureData_Fota_Element;
} NV_Data_BsFuSa_FeatureData;

#  define Rte_TypeDef_NV_Data_BsFuSa_Power
typedef struct
{
  Arr_u8_48 BsFuSa_Power_Element;
} NV_Data_BsFuSa_Power;

#  define Rte_TypeDef_NV_Data_BsFuSa_Warning
typedef struct
{
  Arr_u8_32 BsFuSa_Warning_Element;
} NV_Data_BsFuSa_Warning;

#  define Rte_TypeDef_NV_Data_BsFusa_Fota
typedef struct
{
  Arr_u8_32 BsFusa_Fota_Element;
} NV_Data_BsFusa_Fota;

#  define Rte_TypeDef_NV_Data_BsReten_VisDlt
typedef struct
{
  Arr_u8_256 BsReten_VisDlt_Element;
} NV_Data_BsReten_VisDlt;

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

#  define Rte_TypeDef_SFastGuageInfo
typedef struct
{
  SGaugeInfo gaugeInfo_4;
} SFastGuageInfo;

#  define Rte_TypeDef_SGaugeInfo_2
typedef SGaugeInfo SGaugeInfo_2[2];

#  define Rte_TypeDef_SGaugeInfo_u32dyn_3
typedef SGaugeInfo_u32dyn SGaugeInfo_u32dyn_3[3];

#  define Rte_TypeDef_SSlowGaugeInfo
typedef struct
{
  SGaugeInfo_2 gaugeInfo;
} SSlowGaugeInfo;

#  define Rte_TypeDef_SfdA_RequestRoleType
typedef UInt8 SfdA_RequestRoleType;

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

extern CONST(Arr_u16_7, RTE_CONST) Rte_C_Arr_u16_7_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u16_7, RTE_CONST) Rte_C_Arr_u16_7_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_10, RTE_CONST) Rte_C_Arr_u8_10_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_100, RTE_CONST) Rte_C_Arr_u8_100_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_1024, RTE_CONST) Rte_C_Arr_u8_1024_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_128, RTE_CONST) Rte_C_Arr_u8_128_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_16, RTE_CONST) Rte_C_Arr_u8_16_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_17, RTE_CONST) Rte_C_Arr_u8_17_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_2048, RTE_CONST) Rte_C_Arr_u8_2048_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_256, RTE_CONST) Rte_C_Arr_u8_256_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_28, RTE_CONST) Rte_C_Arr_u8_28_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_3, RTE_CONST) Rte_C_Arr_u8_3_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_3, RTE_CONST) Rte_C_Arr_u8_3_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_32, RTE_CONST) Rte_C_Arr_u8_32_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_46, RTE_CONST) Rte_C_Arr_u8_46_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_48, RTE_CONST) Rte_C_Arr_u8_48_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_61, RTE_CONST) Rte_C_Arr_u8_61_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_64, RTE_CONST) Rte_C_Arr_u8_64_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_8, RTE_CONST) Rte_C_Arr_u8_8_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Arr_u8_9, RTE_CONST) Rte_C_Arr_u8_9_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Diag_Buffer_Tx_USDT, RTE_CONST) Rte_C_Diag_Buffer_Tx_USDT_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Diag_Buffer_Tx_UUDT, RTE_CONST) Rte_C_Diag_Buffer_Tx_UUDT_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TTBlinkArray, RTE_CONST) Rte_CCtrl_TelltaleTTBlinkStatusArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TTBlinkArray, RTE_CONST) Rte_CView_TelltaleTTBlinkStatusArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TTBlinkArray, RTE_CONST) Rte_Ctrl_WSSTTBlinkStatusArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_CCtrl_TelltaleTelltaleFunctionalOpStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_CCtrl_TelltaleTelltaleOpArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_CView_TelltaleTelltaleOpArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(TT_OP_Type, RTE_CONST) Rte_Ctrl_WSSTelltaleOpArrayValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(T_NV_Temperature_Conversion, RTE_CONST) Rte_C_T_NV_Temperature_Conversion_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(Tpms_Arr_u8_5, RTE_CONST) Rte_CWarnMsg_Core_ObserverTpms_PayloadValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IllumCtrl_Ip, RTE_CONST) Rte_Ctrl_IlluminationIllumCtrl_Ip_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IllumCtrl_Ip, RTE_CONST) Rte_Mdl_DimIllumCtrl_Ip_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IllumCtrl_Op, RTE_CONST) Rte_Ctrl_IlluminationIllumCtrl_Op_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(IllumCtrl_Op, RTE_CONST) Rte_View_IlluminationIllumCtrl_Op_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Audio, RTE_CONST) Rte_C_NV_Data_BsConst_Audio_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Communication, RTE_CONST) Rte_C_NV_Data_BsConst_Communication_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_EngOffTimer, RTE_CONST) Rte_C_NV_Data_BsConst_EngOffTimer_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_FuelGauge, RTE_CONST) Rte_C_NV_Data_BsConst_FuelGauge_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Illumination, RTE_CONST) Rte_C_NV_Data_BsConst_Illumination_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Illumination_Copy1, RTE_CONST) Rte_C_NV_Data_BsConst_Illumination_Copy1_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(NV_Data_BsConst_Illumination_Copy2, RTE_CONST) Rte_C_NV_Data_BsConst_Illumination_Copy2_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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

extern CONST(SDLTControlMessageReponse, RTE_CONST) Rte_DltExtDLTControlMessageReponseDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDLTControlMessageReponse, RTE_CONST) Rte_UclProxyCddDLTControlMessageReponseDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDLTControlMessageRequest, RTE_CONST) Rte_DltExtDLTControlMessageRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDLTControlMessageRequest, RTE_CONST) Rte_UclProxyCddDLTControlMessageRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDLTMessageReadAck, RTE_CONST) Rte_DltExtDLTMessageReadAckDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDLTMessageReadAck, RTE_CONST) Rte_UclProxyCddDLTMessageReadAckDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDLTMessageReadRequest, RTE_CONST) Rte_DltExtDLTMessageReadRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDLTMessageReadRequest, RTE_CONST) Rte_UclProxyCddDLTMessageReadRequestDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplayCurrentState, RTE_CONST) Rte_CDisplayCddDisplayCurrentStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplayCurrentState, RTE_CONST) Rte_C_SDisplayCurrentState_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplayCurrentState, RTE_CONST) Rte_UclProxyCddDisplayCurrentStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplaySetPower, RTE_CONST) Rte_CDisplayCddDisplaySetPowerDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDisplaySetPower, RTE_CONST) Rte_UclProxyCddDisplaySetPowerDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SDmnStatus, RTE_CONST) Rte_DmnMgrSDmnStatusValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEmmcErrorNotifier, RTE_CONST) Rte_UclProxyCddEmmcErrorNotifierDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEnetRegReq, RTE_CONST) Rte_C_SEnetRegReq_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SEnetRegResp, RTE_CONST) Rte_C_SEnetRegResp_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFRTT_Status, RTE_CONST) Rte_UclProxyCddFRTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SFastGaugeInfo, RTE_CONST) Rte_SFastGaugeInfo_InitValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SG_ABS, RTE_CONST) Rte_C_SG_ABS_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SG_COM_HS, RTE_CONST) Rte_C_SG_COM_HS_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHudWarningDisplay, RTE_CONST) Rte_CWarnMsg_Core_ObserverHudWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHudWarningDisplay, RTE_CONST) Rte_UclProxyCddHudWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHudWarningStatus, RTE_CONST) Rte_CWarnMsg_Core_ObserverHudWarningStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SHudWarningStatus, RTE_CONST) Rte_UclProxyCddHudWarningStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIlluminationData, RTE_CONST) Rte_Ctrl_DimIlluminationDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIlluminationData, RTE_CONST) Rte_UclProxyCddIlluminationDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SIlluminationData, RTE_CONST) Rte_View_IlluminationIlluminationDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemState, RTE_CONST) Rte_C_SPowerSystemState_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemState, RTE_CONST) Rte_DmnMgrPowerSystemStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemState, RTE_CONST) Rte_UclProxyCddPowerSystemStateDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemStateReqChange, RTE_CONST) Rte_DmnMgrPowerSystemStateReqChangeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SPowerSystemStateReqChange, RTE_CONST) Rte_UclProxyCddPowerSystemStateReqChangeDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SRTT_Icon, RTE_CONST) Rte_UclProxyCddRTT_IconDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SRTT_Status, RTE_CONST) Rte_UclProxyCddRTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SRTT_Toggle, RTE_CONST) Rte_UclProxyCddRTT_ToggleDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SShiftPosIndStatus, RTE_CONST) Rte_Mdl_GearShiftPosIndStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SShiftPosIndStatus, RTE_CONST) Rte_UclProxyCddShiftPosIndStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSlowGuageInfo, RTE_CONST) Rte_SlowGaugeAdapterSlowGaugeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SSlowGuageInfo, RTE_CONST) Rte_UclProxyCddSlowGaugeInfoDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_CView_TelltaleTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STT_Status, RTE_CONST) Rte_UclProxyCddTT_StatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STpmsWarningData, RTE_CONST) Rte_CWarnMsg_Core_ObserverTpmsWarningDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(STpmsWarningData, RTE_CONST) Rte_UclProxyCddTpmsWarningDataDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplay, RTE_CONST) Rte_CWarnMsg_Core_ObserverWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplay, RTE_CONST) Rte_UclProxyCddWarningDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningDisplayAvailable, RTE_CONST) Rte_UclProxyCddWarningDisplayAvailableDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningExtDisplay, RTE_CONST) Rte_UclProxyCddWarningExtDisplayDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningStatus, RTE_CONST) Rte_CWarnMsg_Core_ObserverWarningStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(SWarningStatus, RTE_CONST) Rte_UclProxyCddWarningStatusDataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

extern CONST(ShiftposData_Type, RTE_CONST) Rte_Mdl_GearShiftPos_DataValue0; /* PRQA S 0850 */ /* MD_MSR_19.8 */

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
extern CONST(NV_Data_BsConst_Illumination_Copy1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern CONST(NV_Data_BsConst_Illumination_Copy2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
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
extern CONST(NV_Data_BsConst_Illumination_Copy1, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1_ROM_NVBlockDescriptor_BsConst_Illumination_Copy1; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
extern CONST(NV_Data_BsConst_Illumination_Copy2, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2_ROM_NVBlockDescriptor_BsConst_Illumination_Copy2; /* PRQA S 0850, 3408 */ /* MD_MSR_19.8, MD_Rte_3408 */
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

extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_HVP0Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_HVSD0Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_HVSD1Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_HVSD2Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_HVSD3Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_HVSD4Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_LVP0Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_LVP1Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_LVSD0Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_LVSD1Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_LVSD2Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_LVSD3Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_LVSD4Flag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_CBattMdl_ppSR_BattMdl_AVP_SVPFlag; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SHudWarningDisplay, RTE_VAR_INIT) Rte_CWarnMsg_Core_Observer_pp_HUDWarningDisplay_HudWarningDisplayData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STpmsWarningData, RTE_VAR_INIT) Rte_CWarnMsg_Core_Observer_pp_TPMSWarnPayload_TpmsWarningDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SWarningDisplay, RTE_VAR_INIT) Rte_CWarnMsg_Core_Observer_pp_WarningDisplay_WarningDisplayData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SIlluminationData, RTE_VAR_INIT) Rte_Ctrl_Dim_pSR_IlluminationData_IlluminationDataData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Ctrl_Dim_pp_Ctrl_Ready_to_Sleep_Ready_to_Sleep; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ctrl_Dim_pp_IlumDayNightRequired_IlumDayNightRequired; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ctrl_Dim_pp_IlumDayNightStatus_Day_Night_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Ctrl_Dim_pp_StopPwmUpdate_channel_id; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IllumCtrl_Op, RTE_VAR_INIT) Rte_Ctrl_Illumination_pp_IllumCtrl_Op_IllumCtrl_Op_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IgntionSubstateType, RTE_VAR_INIT) Rte_Ctrl_WSS_ppIgnSubstate_IgnitionSubstate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(HMIReadySts_Type, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_HMIReady_HMI_ReadyStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(DisplayStatus, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_TFTDisplayOn_TFTDisplayOn; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(VehicleActiveModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_VehicleAppMode_WSSCurrentVehicleState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDLTControlMessageReponse, RTE_VAR_INIT) Rte_DltExt_pSR_DLTControlMessageReponse_DLTControlMessageReponseData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDLTMessageReadRequest, RTE_VAR_INIT) Rte_DltExt_pSR_DLTMessageReadRequest_DLTMessageReadRequestData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SPowerSystemStateReqChange, RTE_VAR_INIT) Rte_DmnMgr_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDmnStatus, RTE_VAR_INIT) Rte_DmnMgr_ppSR_DmnInfo_SDmnStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SFastGaugeInfo, RTE_VAR_INIT) Rte_FastGaugeAdapter_pp_FastGaugeInfo_FastGaugeInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(IllumCtrl_Ip, RTE_VAR_INIT) Rte_Mdl_Dim_pp_IllumCtrl_Ip_IllumCtrl_Ip_Data; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_IlumDayNightStatus_illumDNStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_IlumStep_IllumStepValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_RheostatDayStep_RheostatDayStep; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_RheostatNightStep_RheostatNightStep; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_illumStarterstatus_StarterStatus_Out; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Dim_pp_illum_rheostat_change_RheoUpdateVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Gear_pp_ShiftPositionDisplay_ShiftPositionDisplay; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SShiftPosIndStatus, RTE_VAR_INIT) Rte_Mdl_Gear_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_SP1_In_Status_SP1_In_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Selection_Table_Speed_Selection_Table; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Target2_Status_Spd_Target2_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Target_Status_Spd_Target_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Trim2_Status_Spd_Trim2_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Speed_pp_SPD_Trim_Status_Spd_Trim_Status; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Analog_Tacho_Analog_Tacho; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Digital_Tacho_Digital_Tacho; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Needle_Transparent_Needle_TR; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_TC_Unit_Digital_TachoUnit; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Tacho_RED_Start_RPM_RED_Start_RPM; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_Mdl_Tacho_pp_Tacho_RPM_MAX_REVP_RPM_MAX; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TurnStates, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TurnStates, RTE_VAR_INIT) Rte_Mdl_TurnHazard_pp_TurnHazard_TurnR_Sts_RightIndicatorSts; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Audio_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Communication_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Shift_b_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Compensation_Line_Slope_m_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Derating_Backlight_Disable_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Display_Illum_Max_Level_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_EngOffTimer_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_FuelGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_OilGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PWM_boost_bypass_duty_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_PowerGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Power_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_RealTimeClock_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_ServiceReminder_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_SpeedoGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TachoGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TempGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Temperature_Sensor_Conv_SafeCopy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_TripComputer_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsConst_Warning_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsCys_Certicificate_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_Dtc_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsDiag_ErrorRecord_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Audio_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Communication_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Display_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Gauges_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Illumination_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Odometer_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Personalization_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Power_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_RealTimeClock_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Tripcomputer_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsReten_Warning_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_CusDlt_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_FuelGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Illumination_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Odometer_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_OilGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Personalization_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_PowerGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_RealTimeClock_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_SpeedoGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TachoGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TempGauge_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_TripComputer_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsRt_Warning_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyManufacturingDate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_AssemblyPlantNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_EcuPartNumber_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_HWModification; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_PCBSerialNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_ProductSerialNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTManufacturingDate; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SMTPlantNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaFinPrint_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaMode_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotaStatus_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdFotadecrypt_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_SwUpdReflash_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VehicleConfig_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_EOLEntry_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisMeet_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPCBPartNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BsShare_VisteonPartNumber; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate1_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_RefCys_Certicificate_Element; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Audio, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Illumination, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Illumination_Copy1, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Illumination_Copy2, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_Communication, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_EngOffTimer, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(NV_Data_BsConst_FuelGauge, RTE_VAR_INIT) Rte_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase1readcompleted_PhasedRead_Status_phase1readcompleted; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase2readcompleted_PhasedRead_Status_phase2readcompleted; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Boolean, RTE_VAR_INIT) Rte_NvMExt_ppSRPhasedRead_Status_phase3readcompleted_PhasedRead_Status_phase3readcompleted; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SSlowGuageInfo, RTE_VAR_INIT) Rte_SlowGaugeAdapter_pp_SlowGaugeInfo_SlowGaugeInfoData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDLTControlMessageRequest, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_DLTControlMessageRequest_DLTControlMessageRequestData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDLTMessageReadAck, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_DLTMessageReadAck_DLTMessageReadAckData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDisplayCurrentState, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SHudWarningStatus, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_HudWarningStatus_HudWarningStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SPowerSystemState, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SWarningStatus, RTE_VAR_INIT) Rte_UclProxyCdd_pSR_WarningStatus_WarningStatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_View_Speed_pp_Display_speed_Value_Digital_Speed_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(UInt16, RTE_VAR_INIT) Rte_View_Speed_pp_SubDisplaySpeed_Value_SubDispSpeedVal; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(TTBlinkArray, RTE_VAR_INIT) Rte_CCtrl_Telltale_ppBlinkStatusArray_TTBlinkStatusArray; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TTFlashMask, RTE_VAR_INIT) Rte_CCtrl_Telltale_ppBlinkStatusArray_TTdummyDataForTypes; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_Type, RTE_VAR_INIT) Rte_CCtrl_Telltale_ppTelltaleStatusOP_TelltaleOpArray; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(SDisplaySetPower, RTE_VAR_INIT) Rte_CDisplayCdd_ppSRDisplaySetPower_DisplaySetPowerData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(STT_Status, RTE_VAR_INIT) Rte_CView_Telltale_ppTelltaleSts_TT_StatusData; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(TT_OP_STATES, RTE_VAR_INIT) Rte_Mdl_Airbag_pp_Airbag_TT_Status_CurrentTelltaleStatus; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Arr_u8_28, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_BsConst_Illumination_ReservedByte_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(uint32, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Shift_b_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(uint32, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Compensation_Line_Slope_m_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Derating_Backlight_Disable_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(uint16, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Display_Illum_Max_Level_Safe_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Arr_u16_7, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_X_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(Arr_u16_7, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Lookup_Curve_HotSpot_Coef_Y_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(T_NV_Temperature_Conversion, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_PCB_Temperature_Sensor_Conv_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_PWM_boost_bypass_duty_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(uint8, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Temp_Threshold_Hysteresis_Derating_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
extern VAR(T_NV_Temperature_Conversion, RTE_VAR_INIT) Rte_MemAbstract_Stub_Safe_BsConst_Temperature_Sensor_Conv_Value; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/* TxUpdateFlags for ComSendSignalProxy without IOCs */

typedef struct
{
  Rte_BitType Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS : 1;
} Rte_OsApplication_NonTrusted_TxUpdateFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_TxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrusted_TxUpdateFlags; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* TxUpdateFlags for ComSendSignalProxy without IOCs */

typedef struct
{
  Rte_BitType Rte_TxUpdate_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS : 2;
  Rte_BitType Rte_TxUpdateProxy_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS : 1;
} Rte_OsApplication_Trusted_TxUpdateFlagsType;

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_Trusted_TxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_Trusted_TxUpdateFlags; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
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

extern VAR(Rte_QRamInfoType, RTE_VAR_NOINIT) Rte_QRamInfo[16]; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_CONST_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONST(Rte_QRomInfoType, RTE_CONST) Rte_QRomInfo[16];

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
} Rte_OsApplication_NonTrusted_QOverflowType;

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_QOverflowType, RTE_VAR_NOINIT) Rte_OsApplication_NonTrusted_QOverflow; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_TxAck_TrustecSWC_PP_TX_SG_COM_HS_SG_COM_HS : 2;
} Rte_OsApplication_NonTrusted_AckFlagsType;

#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_AckFlagsType, RTE_VAR_INIT) Rte_OsApplication_NonTrusted_AckFlags; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef struct
{
  Rte_BitType Rte_RxNeverReceived_SG_ABS_oABS_oCAN00_6681ad27_Rx : 1;
} Rte_OsApplication_NonTrusted_RxNeverReceivedFlagsType;

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(Rte_OsApplication_NonTrusted_RxNeverReceivedFlagsType, RTE_VAR_ZERO_INIT) Rte_OsApplication_NonTrusted_RxNeverReceivedFlags;

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


typedef struct
{
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Audio : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Communication : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_EngOffTimer : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_FuelGauge : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy1 : 1;
  Rte_BitType Rte_DirtyFlag_NvBlockSwComponentType_NVBlockDescriptor_BsConst_Illumination_Copy2 : 1;
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


/**********************************************************************************************************************
 * Buffers for data transformation / LdComSignals
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_NOINIT) Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx[6]; /* PRQA S 0850, 0759 */ /* MD_MSR_19.8, MD_MSR_18.4 */

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint8, RTE_VAR_NOINIT) Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx[3]; /* PRQA S 0850, 0759 */ /* MD_MSR_19.8, MD_MSR_18.4 */

#  define RTE_STOP_SEC_VAR_OsApplication_Trusted_NOINIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_INIT) Rte_Com_SG_ABS_oABS_oCAN00_6681ad27_Rx_Length; /* PRQA S 0850, 0759 */ /* MD_MSR_19.8, MD_MSR_18.4 */

#  define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define RTE_START_SEC_VAR_OsApplication_Trusted_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(uint32, RTE_VAR_INIT) Rte_Com_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx_Length; /* PRQA S 0850, 0759 */ /* MD_MSR_19.8, MD_MSR_18.4 */

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
