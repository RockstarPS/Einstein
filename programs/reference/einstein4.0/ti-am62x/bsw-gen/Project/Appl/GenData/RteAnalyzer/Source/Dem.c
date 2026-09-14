/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Dem.c
 *        Config:  BMW.dpa
 *    BSW Module:  Dem
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for BSW Module <Dem>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SchM_Dem.h"
#include "TSC_SchM_Dem.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Alive_101: Integer in interval [0...15]
 * Alive_200: Integer in interval [0...255]
 * Ambient_Light_level: Integer in interval [0...100]
 * Battery_Voltage: Integer in interval [0...255]
 * Boolean: Boolean
 * CRC_101: Integer in interval [0...255]
 * CRC_200: Integer in interval [0...255]
 * CounterType: Integer in interval [0...255]
 * CurrentStateIC: Boolean
 * DayNightMode: Boolean
 * Dcm_DspDidIdentifierTableType: Integer in interval [0...65535]
 * Dcm_DspRidIdentifierTableType: Integer in interval [0...65535]
 * Dcm_MsgLenType: Integer in interval [0...4294967295]
 * Dcm_NegativeResponseCodeType: Integer in interval [0...255]
 * Dcm_OpStatusType: Integer in interval [0...255]
 * Debug1_Byte0: Integer in interval [0...255]
 * Debug1_Byte1: Integer in interval [0...255]
 * Debug1_Byte2: Integer in interval [0...255]
 * Debug1_Byte3: Integer in interval [0...255]
 * Debug1_Byte4: Integer in interval [0...255]
 * Debug1_Byte5: Integer in interval [0...255]
 * Debug1_Byte6: Integer in interval [0...255]
 * Debug1_Byte7: Integer in interval [0...255]
 * Debug2_Byte0: Integer in interval [0...255]
 * Debug2_Byte1: Integer in interval [0...255]
 * Debug2_Byte2: Integer in interval [0...255]
 * Debug2_Byte3: Integer in interval [0...255]
 * Debug2_Byte4: Integer in interval [0...255]
 * Debug2_Byte5: Integer in interval [0...255]
 * Debug2_Byte6: Integer in interval [0...255]
 * Debug2_Byte7: Integer in interval [0...255]
 * Debug3_Byte0: Integer in interval [0...255]
 * Debug3_Byte1: Integer in interval [0...255]
 * Debug3_Byte2: Integer in interval [0...255]
 * Debug3_Byte3: Integer in interval [0...255]
 * Debug3_Byte4: Integer in interval [0...255]
 * Debug3_Byte5: Integer in interval [0...255]
 * Debug3_Byte6: Integer in interval [0...255]
 * Debug3_Byte7: Integer in interval [0...255]
 * Debug4_Byte0: Integer in interval [0...255]
 * Debug4_Byte1: Integer in interval [0...255]
 * Debug4_Byte2: Integer in interval [0...255]
 * Debug4_Byte3: Integer in interval [0...255]
 * Debug4_Byte4: Integer in interval [0...255]
 * Debug4_Byte5: Integer in interval [0...255]
 * Debug4_Byte6: Integer in interval [0...255]
 * Debug4_Byte7: Integer in interval [0...255]
 * Debug5_Byte0: Integer in interval [0...255]
 * Debug5_Byte1: Integer in interval [0...255]
 * Debug5_Byte2: Integer in interval [0...255]
 * Debug5_Byte3: Integer in interval [0...255]
 * Debug5_Byte4: Integer in interval [0...255]
 * Debug5_Byte5: Integer in interval [0...255]
 * Debug5_Byte6: Integer in interval [0...255]
 * Debug5_Byte7: Integer in interval [0...255]
 * Dem_DTCFormatType: Integer in interval [0...255]
 * Dem_DTCGroupType: Integer in interval [0...16777215]
 * Dem_DTCOriginType: Integer in interval [0...255]
 * Dem_DTCStatusMaskType: Integer in interval [0...255]
 * Dem_DebouncingStateType: Integer in interval [0...255]
 * Dem_EventIdType: Integer in interval [1...65535]
 * Dem_EventIdType: Integer in interval [0...65535]
 * Dem_EventStatusType: Integer in interval [0...255]
 * Dem_OperationCycleIdType: Integer in interval [0...255]
 * Dem_OperationCycleStateType: Integer in interval [0...255]
 * Dem_RatioIdType: Integer in interval [1...65535]
 * Dem_UdsStatusByteType: Integer in interval [0...255]
 * Dlt_MessageArgumentCount: Integer in interval [0...65535]
 * Dlt_MessageOptionsType: Integer in interval [0...255]
 * Dlt_SessionIDType: Integer in interval [0...4294967295]
 * EChimeStatus: Integer in interval [0...65535]
 * EcuM_TimeType: Integer in interval [0...4294967295]
 * EcuM_UserType: Integer in interval [0...255]
 * EngineSpeed: Integer in interval [0...65535]
 * FV_Tx: Integer in interval [0...15]
 * Gear: Integer in interval [0...15]
 * GearMode: Boolean
 * Illumination_PWM: Integer in interval [0...100]
 * Illumination_level: Integer in interval [0...255]
 * MAC_Tx: Integer in interval [0...268435455]
 * NvM_BlockIdType: Integer in interval [1...32767]
 * NvM_BlockIdType: Integer in interval [0...65535]
 * NvM_RequestResultType: Integer in interval [0...255]
 * Odometer: Integer in interval [0...1609343]
 * PreviousStateIC: Integer in interval [-4...3]
 * Rte_DT_Arr_u16_7_0: Integer in interval [0...65535]
 * Rte_DT_Arr_u8_100_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_1024_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_10_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_128_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_16_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_17_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_256_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_28_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_32_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_3_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_46_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_48_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_61_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_64_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_8_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_9_0: Integer in interval [0...255]
 * Rte_DT_Dlt_ApplicationIDType_0: Integer in interval [0...255]
 * Rte_DT_Dlt_ContextIDType_0: Integer in interval [0...255]
 * Rte_DT_Dlt_LogChannelNameType_0: Integer in interval [0...255]
 * Rte_DT_PayloadArr_u8_8_0: Integer in interval [0...255]
 * Rte_DT_TTBlinkArray_0: Integer in interval [0...255]
 * Rte_DT_TT_OP_Type_0: Integer in interval [0...255]
 * Rte_DT_T_NV_Temperature_Conversion_0: Integer in interval [0...4294967295]
 * Rte_DT_Tpms_Arr_u8_5_0: Integer in interval [0...255]
 * Rte_DT_data_u32_5_0: Integer in interval [0...4294967295]
 * Rte_DT_data_u8_10_0: Integer in interval [0...255]
 * Rte_DT_data_u8_15_0: Integer in interval [0...255]
 * Rte_DT_data_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_data_u8_256_0: Integer in interval [0...255]
 * Rte_DT_data_u8_2_0: Integer in interval [0...255]
 * Rte_DT_data_u8_32_0: Integer in interval [0...255]
 * Rte_DT_data_u8_64_0: Integer in interval [0...255]
 * Rte_DT_data_u8_8_0: Integer in interval [0...255]
 * SInt16: Integer in interval [-32768...32767]
 * SInt32: Integer in interval [-2147483648...2147483647]
 * SInt8: Integer in interval [-128...127]
 * SecureTxByte0: Integer in interval [0...255]
 * SecureTxByte1: Integer in interval [0...255]
 * SecureTxByte2: Integer in interval [0...255]
 * SecureTxByte3: Integer in interval [0...255]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * TransportMode: Boolean
 * Turn_Indicator_Control: Integer in interval [0...3]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 * UserData1_IC: Integer in interval [0...255]
 * UserData2_IC: Integer in interval [0...255]
 * UserData3_IC: Integer in interval [0...255]
 * UserData4_IC: Integer in interval [0...255]
 * UserData5_IC: Integer in interval [0...255]
 * VehicleSpeedABS: Integer in interval [0...65535]
 * VehicleSpeedIC: Integer in interval [0...65535]
 * Warning: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * sint32: Integer in interval [-2147483648...2147483647] (standard type)
 * sint8: Integer in interval [-128...127] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Airbag: Enumeration of integer in interval [0...3] with enumerators
 * BOOL_TYPE: Enumeration of integer in interval [0...1] with enumerators
 * BulbTestStatus: Enumeration of integer in interval [0...45020] with enumerators
 * ClusterInitModes: Enumeration of integer in interval [0...2] with enumerators
 * ClusterModes: Enumeration of integer in interval [0...1] with enumerators
 * CountryCode_FuncType: Enumeration of integer in interval [0...14] with enumerators
 * CustResetType: Enumeration of integer in interval [0...4] with enumerators
 * Dem_DTCFormatType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DTCKindType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DTCSeverityType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DTRControlType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DebounceResetStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_DebouncingStateType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_IndicatorStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_InitMonitorReasonType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_IumprDenomCondIdType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_IumprDenomCondStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_IumprReadinessGroupType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_MonitorStatusType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_OperationCycleStateType: Enumeration of integer in interval [0...255] with enumerators
 * Dem_UdsStatusByteType: Enumeration of integer in interval [0...255] with enumerators
 * DisplayStatus: Enumeration of integer in interval [0...1] with enumerators
 * Dlt_AssignmentOperation: Enumeration of integer in interval [1...2] with enumerators
 * Dlt_MessageLogLevelType: Enumeration of integer in interval [0...6] with enumerators
 * Dlt_MessageTraceType: Enumeration of integer in interval [1...5] with enumerators
 * EButtonId: Enumeration of integer in interval [0...8] with enumerators
 * EButtonSts: Enumeration of integer in interval [0...5] with enumerators
 * EChimeID: Enumeration of integer in interval [0...1] with enumerators
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 * EDcmExtAction: Enumeration of integer in interval [0...8] with enumerators
 * EDeviceStatus: Enumeration of integer in interval [0...5] with enumerators
 * EDidType: Enumeration of integer in interval [0...2] with enumerators
 * EDisplayCddStatus: Enumeration of integer in interval [0...4] with enumerators
 * EDisplayPower: Enumeration of integer in interval [0...2] with enumerators
 * EDisplayPowerState: Enumeration of integer in interval [0...5] with enumerators
 * EDisplayStatus: Enumeration of integer in interval [0...255] with enumerators
 * EDisplayStatus: Enumeration of integer in interval [0...4] with enumerators
 * EDisplayType: Enumeration of integer in interval [0...1] with enumerators
 * EDmnChangeReqStatus_t: Enumeration of integer in interval [0...7] with enumerators
 * EDmnHealthState_t: Enumeration of integer in interval [0...8] with enumerators
 * EDmnOverallState_t: Enumeration of integer in interval [0...1] with enumerators
 * EDomainId: Enumeration of integer in interval [0...3] with enumerators
 * EDomainId: Enumeration of integer in interval [0...255] with enumerators
 * EGammaCorrectionStatus: Enumeration of integer in interval [0...3] with enumerators
 * EGaugeUnit: Enumeration of integer in interval [0...13] with enumerators
 * EIOCtrlOptType: Enumeration of integer in interval [0...4] with enumerators
 * EIgnitionStatus: Enumeration of integer in interval [0...4] with enumerators
 * EMeetModeStatus: Enumeration of integer in interval [0...1] with enumerators
 * ERoutineType: Enumeration of integer in interval [0...3] with enumerators
 * ESystemState: Enumeration of integer in interval [0...8] with enumerators
 * ESystemState: Enumeration of integer in interval [0...255] with enumerators
 * EUclLinkState_t: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_BootTargetType: Enumeration of integer in interval [0...2] with enumerators
 * EcuM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_ShutdownCauseType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_StateType: Enumeration of integer in interval [0...144] with enumerators
 * EcuM_UserType: Enumeration of integer in interval [0...255] with enumerators
 * EnetReqCmd_t: Enumeration of integer in interval [0...255] with enumerators
 * EnetReqMode_t: Enumeration of integer in interval [0...255] with enumerators
 * GearRecommendation: Enumeration of integer in interval [0...7] with enumerators
 * GearStatus: Enumeration of integer in interval [0...255] with enumerators
 * HMIReadySts_Type: Enumeration of integer in interval [0...1] with enumerators
 * HMI_Odo_Type: Enumeration of integer in interval [0...10] with enumerators
 * HMI_Screen_Mode: Enumeration of integer in interval [0...9] with enumerators
 * HTimer: Enumeration of integer in interval [0...80] with enumerators
 * Hud_Wake_Type: Enumeration of integer in interval [0...1] with enumerators
 * IOCtrl_Type: Enumeration of integer in interval [1...64] with enumerators
 * IgntionSubstateType: Enumeration of integer in interval [0...1] with enumerators
 * IoHwAb_AdcSignalIdType: Enumeration of integer in interval [0...17] with enumerators
 * IoHwAb_DInGroupIdType: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 * IoHwAb_DInSignalIdType: Enumeration of integer in interval [0...29] with enumerators
 * IoHwAb_DOutGroupIdType: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 * IoHwAb_DOutSignalIdType: Enumeration of integer in interval [0...60] with enumerators
 * IoHwAb_ErrorType: Enumeration of integer in interval [2...13] with enumerators
 * IoHwAb_PwmSignalIdType: Enumeration of integer in interval [0...9] with enumerators
 * ModeStatus: Enumeration of integer in interval [0...1] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 * NvM_ServiceIdType: Enumeration of integer in interval [6...12] with enumerators
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 * PowerMode: Enumeration of integer in interval [0...15] with enumerators
 * SettingResetResult_Type: Enumeration of integer in interval [0...2] with enumerators
 * ShiftPosition: Enumeration of integer in interval [16...96] with enumerators
 * ShiftPositionInd: Enumeration of integer in interval [1...3] with enumerators
 * SleepType: Enumeration of integer in interval [0...1] with enumerators
 * TFTIgnBlankSts_T: Enumeration of integer in interval [0...1] with enumerators
 * TTFlashMask: Enumeration of integer in interval [0...4] with enumerators
 * TT_ENUM_TYPE: Enumeration of integer in interval [0...92] with enumerators
 * TT_OP_STATES: Enumeration of integer in interval [0...255] with enumerators
 * Target_SW_Status: Enumeration of integer in interval [0...7] with enumerators
 * TurnStates: Enumeration of integer in interval [0...2] with enumerators
 * UserIdType: Enumeration of integer in interval [1...4] with enumerators
 * VehicleActiveModes: Enumeration of integer in interval [0...2] with enumerators
 * WarningDisplayedStatus: Enumeration of integer in interval [0...32] with enumerators
 * WarningEvent: Enumeration of integer in interval [0...2] with enumerators
 * WarningId: Enumeration of integer in interval [0...630] with enumerators
 * WarningStatus: Enumeration of integer in interval [0...2] with enumerators
 * eAppMdl: Enumeration of integer in interval [0...11] with enumerators
 * eFltM_FaultIdType: Enumeration of integer in interval [62977...65535] with enumerators
 * eFltM_FaultStatusType: Enumeration of integer in interval [0...3] with enumerators
 * eFltM_FlsIntegrityStatusType: Enumeration of integer in interval [0...3] with enumerators
 * eIOPulseInputId: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 * eSleepSt: Enumeration of integer in interval [0...1] with enumerators
 * tRxSafeSignalId: Enumeration of integer in interval [0...37] with enumerators
 * tRxSafeSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 * tRxSignalId: Enumeration of integer in interval [0...12] with enumerators
 * tRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 * tRxSignalStatus: Enumeration of integer in interval [0...4] with enumerators
 * tSafeRxSignalId: Enumeration of integer in interval [0...4] with enumerators
 * tSafeRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 * tSafeRxSignalStatus: Enumeration of integer in interval [0...6] with enumerators
 * tSafeTxSignalId: Enumeration of integer in interval [0...3] with enumerators
 * tTxSigConfirmStatus: Enumeration of integer in interval [0...2] with enumerators
 * tTxSignalId: Enumeration of integer in interval [0...49] with enumerators
 * teDIDOperation: Enumeration of integer in interval [0...7] with enumerators
 * teDiagOpStatus: Enumeration of integer in interval [0...64] with enumerators
 * teRoutineOperation: Enumeration of integer in interval [0...2] with enumerators
 *
 * Array Types:
 * ============
 * Arr_u16_7: Array with 7 element(s) of type Rte_DT_Arr_u16_7_0
 * Arr_u8_10: Array with 10 element(s) of type Rte_DT_Arr_u8_10_0
 * Arr_u8_100: Array with 100 element(s) of type Rte_DT_Arr_u8_100_0
 * Arr_u8_1024: Array with 1024 element(s) of type Rte_DT_Arr_u8_1024_0
 * Arr_u8_128: Array with 128 element(s) of type Rte_DT_Arr_u8_128_0
 * Arr_u8_16: Array with 16 element(s) of type Rte_DT_Arr_u8_16_0
 * Arr_u8_17: Array with 17 element(s) of type Rte_DT_Arr_u8_17_0
 * Arr_u8_2048: Array with 2048 element(s) of type Rte_DT_Arr_u8_2048_0
 * Arr_u8_256: Array with 256 element(s) of type Rte_DT_Arr_u8_256_0
 * Arr_u8_28: Array with 28 element(s) of type Rte_DT_Arr_u8_28_0
 * Arr_u8_3: Array with 3 element(s) of type Rte_DT_Arr_u8_3_0
 * Arr_u8_32: Array with 32 element(s) of type Rte_DT_Arr_u8_32_0
 * Arr_u8_46: Array with 46 element(s) of type Rte_DT_Arr_u8_46_0
 * Arr_u8_48: Array with 48 element(s) of type Rte_DT_Arr_u8_48_0
 * Arr_u8_61: Array with 61 element(s) of type Rte_DT_Arr_u8_61_0
 * Arr_u8_64: Array with 64 element(s) of type Rte_DT_Arr_u8_64_0
 * Arr_u8_8: Array with 8 element(s) of type Rte_DT_Arr_u8_8_0
 * Arr_u8_9: Array with 9 element(s) of type Rte_DT_Arr_u8_9_0
 * Dem_MaxDataValueType: Array with 1 element(s) of type uint8
 * Diag_Buffer_Tx_USDT: Array with 8 element(s) of type UInt8
 * Diag_Buffer_Tx_UUDT: Array with 8 element(s) of type UInt8
 * Dlt_ApplicationIDType: Array with 4 element(s) of type Rte_DT_Dlt_ApplicationIDType_0
 * Dlt_ContextIDType: Array with 4 element(s) of type Rte_DT_Dlt_ContextIDType_0
 * Dlt_LogChannelNameType: Array with 4 element(s) of type Rte_DT_Dlt_LogChannelNameType_0
 * PayloadArr_u8_8: Array with 8 element(s) of type Rte_DT_PayloadArr_u8_8_0
 * SGaugeInfo_u32dyn_2: Array with 2 element(s) of type SGaugeInfo_u32dyn
 * TTBlinkArray: Array with 16 element(s) of type Rte_DT_TTBlinkArray_0
 * TT_OP_Type: Array with 92 element(s) of type Rte_DT_TT_OP_Type_0
 * T_NV_Temperature_Conversion: Array with 2 element(s) of type Rte_DT_T_NV_Temperature_Conversion_0
 * Tpms_Arr_u8_5: Array with 5 element(s) of type Rte_DT_Tpms_Arr_u8_5_0
 * data_u32_5: Array with 5 element(s) of type Rte_DT_data_u32_5_0
 * data_u8_10: Array with 10 element(s) of type Rte_DT_data_u8_10_0
 * data_u8_15: Array with 15 element(s) of type Rte_DT_data_u8_15_0
 * data_u8_2: Array with 2 element(s) of type Rte_DT_data_u8_2_0
 * data_u8_2048: Array with 2048 element(s) of type Rte_DT_data_u8_2048_0
 * data_u8_256: Array with 256 element(s) of type Rte_DT_data_u8_256_0
 * data_u8_32: Array with 32 element(s) of type Rte_DT_data_u8_32_0
 * data_u8_32: Array with 32 element(s) of type uint8
 * data_u8_64: Array with 64 element(s) of type Rte_DT_data_u8_64_0
 * data_u8_8: Array with 8 element(s) of type uint8
 * data_u8_8: Array with 8 element(s) of type Rte_DT_data_u8_8_0
 *
 * Record Types:
 * =============
 * Dlt_ApplicationIdInfoType: Record with elements
 *   appId of type Dlt_ApplicationIDType
 *   contextIdCount of type UInt16
 *   contextInfoList of type Dlt_ContextIdInfoType
 *   appDescLen of type UInt16
 *   appDesc of type UInt8
 * Dlt_ContextIdInfoType: Record with elements
 *   contextId of type Dlt_ContextIDType
 *   logLevel of type Dlt_MessageLogLevelType
 *   traceStatus of type UInt8
 *   lenContextDescription of type UInt16
 *   contextDesc of type UInt8
 * Dlt_LogInfoType: Record with elements
 *   appIdCount of type UInt16
 *   appIdInfo of type Dlt_ApplicationIdInfoType
 * Dlt_MessageLogInfoType: Record with elements
 *   argCount of type Dlt_MessageArgumentCount
 *   logLevel of type Dlt_MessageLogLevelType
 *   options of type Dlt_MessageOptionsType
 *   contextId of type Dlt_ContextIDType
 *   appId of type Dlt_ApplicationIDType
 * Dlt_MessageTraceInfoType: Record with elements
 *   traceInfo of type Dlt_MessageTraceType
 *   options of type Dlt_MessageOptionsType
 *   context of type Dlt_ContextIDType
 *   appId of type Dlt_ApplicationIDType
 * ExtWarningData: Record with elements
 *   ExtWarningCurrentStatus of type WarningStatus
 *   ExtWarningCurrentEvent of type WarningEvent
 *   ExtWarningCurrentPayload of type PayloadArr_u8_8
 * IllumCtrl_Ip: Record with elements
 *   Illumination_Mode of type UInt8
 *   battery_status of type UInt8
 *   Illumination_Sts of type UInt8
 *   power_mode of type UInt8
 *   step_value of type UInt8
 *   step_direction of type UInt8
 *   switch_type of type UInt8
 *   Derating_Value of type UInt16
 * IllumCtrl_Op: Record with elements
 *   Brightness_Out of type UInt16
 *   Bulb_PWM_Out of type UInt16
 *   Illumination_Duty_Out of type UInt16
 *   RGB_Dimming_Out of type UInt16
 *   LED_PWM_Out of type UInt16
 *   Dial_Out of type UInt16
 *   Display_Out of type UInt16
 *   Telltale_Out of type UInt16
 * NV_Data_BsConst_Audio: Record with elements
 *   BsConst_Audio_Element of type Arr_u8_128
 * NV_Data_BsConst_Communication: Record with elements
 *   BsConst_Communication_Element of type Arr_u8_64
 * NV_Data_BsConst_EngOffTimer: Record with elements
 *   BsConst_EngOffTimer_Element of type Arr_u8_32
 * NV_Data_BsConst_FuelGauge: Record with elements
 *   BsConst_FuelGauge_Element of type Arr_u8_128
 * NV_Data_BsConst_Illumination: Record with elements
 *   BsConst_Compensation_Line_Slope_m of type uint32
 *   BsConst_Compensation_Line_Shift_b of type uint32
 *   BsConst_Lookup_Curve_HotSpot_Coef_X of type Arr_u16_7
 *   BsConst_Lookup_Curve_HotSpot_Coef_Y of type Arr_u16_7
 *   BsConst_Temp_Threshold_Hysteresis_Derating of type uint8
 *   BsConst_Derating_Backlight_Disable of type uint8
 *   BsConst_Temperature_Sensor_Conv of type T_NV_Temperature_Conversion
 *   BsConst_PCB_Temperature_Sensor_Conv of type T_NV_Temperature_Conversion
 *   BsConst_Display_Illum_Max_Level of type uint16
 *   BsConst_PWM_boost_bypass_duty of type uint8
 *   BsConst_BsConst_Illumination_ReservedByte of type Arr_u8_28
 * NV_Data_BsConst_Illumination_Copy1: Record with elements
 *   BsConst_Compensation_Line_Slope_m_SafeCopy1 of type uint32
 *   BsConst_Compensation_Line_Shift_b_SafeCopy1 of type uint32
 *   BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1 of type Arr_u16_7
 *   BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1 of type Arr_u16_7
 *   BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1 of type uint8
 *   BsConst_Derating_Backlight_Disable_SafeCopy1 of type uint8
 *   BsConst_Temperature_Sensor_Conv_SafeCopy1 of type T_NV_Temperature_Conversion
 *   BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1 of type T_NV_Temperature_Conversion
 *   BsConst_Display_Illum_Max_Level_SafeCopy1 of type uint16
 *   BsConst_PWM_boost_bypass_duty_SafeCopy1 of type uint8
 *   BsConst_BsConst_Illumination_ReservedByte_SafeCopy1 of type Arr_u8_28
 * NV_Data_BsConst_Illumination_Copy2: Record with elements
 *   BsConst_Compensation_Line_Slope_m_SafeCopy2 of type uint32
 *   BsConst_Compensation_Line_Shift_b_SafeCopy2 of type uint32
 *   BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2 of type Arr_u16_7
 *   BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2 of type Arr_u16_7
 *   BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2 of type uint8
 *   BsConst_Derating_Backlight_Disable_SafeCopy2 of type uint8
 *   BsConst_Temperature_Sensor_Conv_SafeCopy2 of type T_NV_Temperature_Conversion
 *   BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2 of type T_NV_Temperature_Conversion
 *   BsConst_Display_Illum_Max_Level_SafeCopy2 of type uint16
 *   BsConst_PWM_boost_bypass_duty_SafeCopy2 of type uint8
 *   BsConst_BsConst_Illumination_ReservedByte_SafeCopy2 of type Arr_u8_28
 * NV_Data_BsConst_OilGauge: Record with elements
 *   BsConst_OilGauge_Element of type Arr_u8_64
 * NV_Data_BsConst_Power: Record with elements
 *   BsConst_Power_Element of type Arr_u8_32
 * NV_Data_BsConst_PowerGauge: Record with elements
 *   BsConst_PowerGauge_Element of type Arr_u8_64
 * NV_Data_BsConst_RealTimeClock: Record with elements
 *   BsConst_RealTimeClock_Element of type Arr_u8_48
 * NV_Data_BsConst_ServiceReminder: Record with elements
 *   BsConst_ServiceReminder_Element of type Arr_u8_48
 * NV_Data_BsConst_SpeedoGauge: Record with elements
 *   BsConst_SpeedoGauge_Element of type Arr_u8_64
 * NV_Data_BsConst_TachoGauge: Record with elements
 *   BsConst_TachoGauge_Element of type Arr_u8_64
 * NV_Data_BsConst_TempGauge: Record with elements
 *   BsConst_TempGauge_Element of type Arr_u8_64
 * NV_Data_BsConst_TripComputer: Record with elements
 *   BsConst_TripComputer_Element of type Arr_u8_64
 * NV_Data_BsConst_Warning: Record with elements
 *   BsConst_Warning_Element of type Arr_u8_64
 * NV_Data_BsCys_Certicificate: Record with elements
 *   BsCys_Certicificate_Element of type Arr_u8_64
 * NV_Data_BsDiag_Dtc: Record with elements
 *   BsDiag_Dtc_Element of type Arr_u8_2048
 * NV_Data_BsDiag_ErrorRecord: Record with elements
 *   BsDiag_ErrorRecord_Element of type Arr_u8_1024
 * NV_Data_BsReten_Audio: Record with elements
 *   BsReten_Audio_Element of type Arr_u8_100
 * NV_Data_BsReten_Communication: Record with elements
 *   BsReten_Communication_Element of type Arr_u8_100
 * NV_Data_BsReten_Display: Record with elements
 *   BsReten_Display_Element of type Arr_u8_100
 * NV_Data_BsReten_Gauges: Record with elements
 *   BsReten_Gauges_Element of type Arr_u8_100
 * NV_Data_BsReten_Illumination: Record with elements
 *   BsReten_Illumination_Element of type Arr_u8_100
 * NV_Data_BsReten_Odometer: Record with elements
 *   BsReten_Odometer_Element of type Arr_u8_100
 * NV_Data_BsReten_Personalization: Record with elements
 *   BsReten_Personalization_Element of type Arr_u8_100
 * NV_Data_BsReten_Power: Record with elements
 *   BsReten_Power_Element of type Arr_u8_100
 * NV_Data_BsReten_RealTimeClock: Record with elements
 *   BsReten_RealTimeClock_Element of type Arr_u8_100
 * NV_Data_BsReten_Tripcomputer: Record with elements
 *   BsReten_Tripcomputer_Element of type Arr_u8_100
 * NV_Data_BsReten_Warning: Record with elements
 *   BsReten_Warning_Element of type Arr_u8_100
 * NV_Data_BsRt_CusDlt: Record with elements
 *   BsRt_CusDlt_Element of type Arr_u8_128
 * NV_Data_BsRt_FuelGauge: Record with elements
 *   BsRt_FuelGauge_Element of type Arr_u8_32
 * NV_Data_BsRt_Illumination: Record with elements
 *   BsRt_Illumination_Element of type Arr_u8_100
 * NV_Data_BsRt_Odometer: Record with elements
 *   BsRt_Odometer_Element of type Arr_u8_128
 * NV_Data_BsRt_OilGauge: Record with elements
 *   BsRt_OilGauge_Element of type Arr_u8_8
 * NV_Data_BsRt_Personalization: Record with elements
 *   BsRt_Personalization_Element of type Arr_u8_128
 * NV_Data_BsRt_PowerGauge: Record with elements
 *   BsRt_PowerGauge_Element of type Arr_u8_32
 * NV_Data_BsRt_RealTimeClock: Record with elements
 *   BsRt_RealTimeClock_Element of type Arr_u8_48
 * NV_Data_BsRt_SpeedoGauge: Record with elements
 *   BsRt_SpeedoGauge_Element of type Arr_u8_8
 * NV_Data_BsRt_TachoGauge: Record with elements
 *   BsRt_TachoGauge_Element of type Arr_u8_16
 * NV_Data_BsRt_TempGauge: Record with elements
 *   BsRt_TempGauge_Element of type Arr_u8_32
 * NV_Data_BsRt_TripComputer: Record with elements
 *   BsRt_TripComputer_Element of type Arr_u8_64
 * NV_Data_BsRt_Warning: Record with elements
 *   BsRt_Warning_Element of type Arr_u8_32
 * NV_Data_BsShare_EcuPartNumber: Record with elements
 *   BsShare_EcuPartNumber_Element of type Arr_u8_61
 *   BsShare_VisteonPartNumber of type Arr_u8_17
 *   BsShare_VisteonPCBPartNumber of type Arr_u8_17
 *   BsShare_ProductSerialNumber of type Arr_u8_10
 *   BsShare_PCBSerialNumber of type Arr_u8_9
 *   BsShare_SMTManufacturingDate of type Arr_u8_3
 *   BsShare_AssemblyManufacturingDate of type Arr_u8_3
 *   BsShare_SMTPlantNumber of type Arr_u8_3
 *   BsShare_AssemblyPlantNumber of type Arr_u8_3
 *   BsShare_HWModification of type uint16
 * NV_Data_BsShare_SwUpdFotaFinPrint: Record with elements
 *   BsShare_SwUpdFotaFinPrint_Element of type Arr_u8_32
 * NV_Data_BsShare_SwUpdFotaMode: Record with elements
 *   BsShare_SwUpdFotaMode_Element of type Arr_u8_16
 * NV_Data_BsShare_SwUpdFotaStatus: Record with elements
 *   BsShare_SwUpdFotaStatus_Element of type Arr_u8_48
 * NV_Data_BsShare_SwUpdFotadecrypt: Record with elements
 *   BsShare_SwUpdFotadecrypt_Element of type Arr_u8_64
 * NV_Data_BsShare_SwUpdReflash: Record with elements
 *   BsShare_SwUpdReflash_Element of type Arr_u8_8
 * NV_Data_BsShare_VehicleConfig: Record with elements
 *   BsShare_VehicleConfig_Element of type Arr_u8_256
 * NV_Data_BsShare_VisMeet: Record with elements
 *   BsShare_VisMeet_Element of type Arr_u8_46
 *   BsShare_VisMeet_EOLEntry_Element of type uint16
 * NV_Data_RefCys_Certicificate: Record with elements
 *   RefCys_Certicificate_Element of type Arr_u8_64
 * NV_Data_RefCys_Certicificate1: Record with elements
 *   RefCys_Certicificate1_Element of type Arr_u8_64
 * Rtc_AlarmType: Record with elements
 *   day of type UInt8
 *   minute of type UInt8
 *   hour of type UInt8
 * Rtc_TimeType: Record with elements
 *   year of type UInt16
 *   month of type UInt8
 *   week of type UInt8
 *   day of type UInt8
 *   hour of type UInt8
 *   minute of type UInt8
 *   second of type UInt8
 * SDLTControlMessageReponse: Record with elements
 *   status of type UInt8
 * SDLTControlMessageRequest: Record with elements
 *   status of type UInt8
 * SDLTMessageReadAck: Record with elements
 *   status of type UInt8
 * SDLTMessageReadRequest: Record with elements
 *   status of type UInt8
 * SDiagDIDRequest: Record with elements
 *   did of type UInt16
 *   didType of type EDidType
 *   dataLen of type UInt16
 *   data of type data_u8_256
 * SDiagIOCtrlRequest: Record with elements
 *   did of type UInt16
 *   optionCtrl of type EIOCtrlOptType
 *   dataLen of type UInt16
 *   data of type data_u8_256
 * SDiagResponse: Record with elements
 *   responseCode of type UInt8
 *   dataLen of type UInt16
 *   data of type data_u8_256
 * SDiagRoutineRequest: Record with elements
 *   routineId of type UInt16
 *   routineType of type ERoutineType
 *   dataLen of type UInt16
 *   data of type data_u8_256
 * SDisplayCurrentState: Record with elements
 *   displayId of type uint32
 *   state of type EDisplayStatus
 * SDisplayCurrentState: Record with elements
 *   displayId of type UInt32
 *   state of type EDisplayStatus
 * SDisplaySetPower: Record with elements
 *   displayId of type UInt32
 *   state of type EDisplayPower
 * SDmnStatus: Record with elements
 *   dmnId of type EDomainId
 *   linkStatus of type EUclLinkState_t
 *   uclErrCode of type SInt32
 *   dmnHealthState of type EDmnHealthState_t
 *   state of type ESystemState
 *   dmnStatus of type EDmnOverallState_t
 * SEmmcErrorNotifier: Record with elements
 *   errorCode of type UInt32
 * SEnetRegReq: Record with elements
 *   cmd of type EnetReqCmd_t
 *   mode of type EnetReqMode_t
 *   dataLen of type uint8
 *   data of type data_u8_8
 * SEnetRegResp: Record with elements
 *   cmd of type EnetReqCmd_t
 *   respLen of type uint8
 *   response of type data_u8_32
 * SFRTT_Status: Record with elements
 *   mask of type data_u8_2
 * SFastGaugeInfo: Record with elements
 *   gaugeInfo of type SGaugeInfo_u32dyn_2
 * SG_ABS: Record with elements
 *   Airbag of type Airbag
 *   Alive_101 of type Alive_101
 *   CRC_101 of type CRC_101
 *   VehicleSpeedABS of type VehicleSpeedABS
 * SG_COM_HS: Record with elements
 *   Alive_200 of type Alive_200
 *   Battery_Voltage of type Battery_Voltage
 *   CRC_200 of type CRC_200
 * SGaugeInfo: Record with elements
 *   id of type UInt8
 *   position of type UInt16
 *   digitalData of type SInt32
 *   unit of type EGaugeUnit
 *   dynData of type UInt16
 * SGaugeInfo_u32dyn: Record with elements
 *   id of type UInt8
 *   position of type UInt16
 *   digitalData of type UInt32
 *   unit of type EGaugeUnit
 *   dynData of type UInt16
 * SHealthDomainFatalError: Record with elements
 *   domainId of type EDomainId
 *   compIdx of type UInt32
 * SHealthDomainHeartbeat: Record with elements
 *   domainId of type EDomainId
 *   seqCnt of type UInt32
 * SHealthDumpData: Record with elements
 *   chunkSize of type UInt32
 *   data of type data_u8_32
 * SHealthDumpGetData: Record with elements
 *   reserved of type UInt8
 * SHealthDumpGetHdr: Record with elements
 *   encrypt of type UInt8
 * SHealthDumpHdrInfo: Record with elements
 *   fileSize of type UInt32
 * SHealthEventRecord: Record with elements
 *   recordType of type UInt8
 *   recordLen of type UInt8
 *   recordData of type data_u8_8
 * SHudWarningDisplay: Record with elements
 *   show of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_8
 * SHudWarningStatus: Record with elements
 *   visible of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_10
 * SIG_WIN_CRC_RGB_T: Record with elements
 *   crc of type UInt32
 * SIG_WIN_INFO_T: Record with elements
 *   sig_unit of type UInt8
 *   window of type UInt8
 * SIG_WIN_SETUP_T: Record with elements
 *   control of type UInt32
 *   winsx of type UInt16
 *   winsy of type UInt16
 *   winex of type UInt16
 *   winey of type UInt16
 *   ref_crc of type UInt32
 * SIgnState: Record with elements
 *   state of type EIgnitionStatus
 * SIlluminationData: Record with elements
 *   data of type UInt8
 *   dayStep of type UInt8
 *   nightStep of type UInt8
 *   daynightStatus of type UInt8
 * SMainHMIReadyStatus: Record with elements
 *   status of type UInt8
 * SPowerExtendShutdownTime: Record with elements
 *   domainId of type EDomainId
 *   timeoutMs of type UInt32
 * SPowerKeepSystemAwake: Record with elements
 *   domainId of type EDomainId
 *   timeoutMs of type UInt32
 * SPowerSystemState: Record with elements
 *   domainId of type EDomainId
 *   state of type ESystemState
 * SPowerSystemState: Record with elements
 *   domainId of type EDomainId
 *   state of type ESystemState
 * SPowerSystemStateReqChange: Record with elements
 *   state of type ESystemState
 *   domainId of type EDomainId
 * SPulseInputConfigParam: Record with elements
 *   MissingRecoveryTimeoutInMicroSec of type UInt32
 *   ValidPeriodMinInMicroSec of type UInt32
 *   ValidPeriodMaxInMicroSec of type UInt32
 *   HystLimitForPeriodMinInMicroSec of type UInt32
 *   HystRcvryForPeriodMinInMicroSec of type UInt32
 *   HystLimitForPeriodMaxInMicroSec of type UInt32
 *   HystRcvryForPeriodMaxInMicroSec of type UInt32
 *   ValidDutyMinInPercentage of type UInt16
 *   ValidDutyMaxInPercentage of type UInt16
 *   HystLimitForDutyMinInPercentage of type UInt16
 *   HystRcvryForDutyMinInPercentage of type UInt16
 *   HystLimitForDutyMaxInPercentage of type UInt16
 *   HystRcvryForDutyMaxInPercentage of type UInt16
 *   InValidTimeoutInMilliSec of type UInt16
 *   InValidRecoveryTimeoutInMilliSec of type UInt16
 *   MissingTimeoutInMilliSec of type UInt16
 * SRTT_Icon: Record with elements
 *   icon of type data_u8_2
 * SRTT_Status: Record with elements
 *   mask of type data_u8_2
 * SRTT_Toggle: Record with elements
 *   positions of type UInt8
 *   display of type UInt8
 * SSafeHMIReadyStatus: Record with elements
 *   status of type UInt8
 * SShiftInd: Record with elements
 *   Shift_Ind_Pos of type UInt8
 *   Shift_Ind_BlinkReq of type UInt8
 *   Shift_Ind_DisplayDecState of type UInt8
 *   Shift_Ind_Down of type UInt8
 *   Shift_Ind_Screen_ShiftType of type UInt8
 *   Shift_Ind_Up of type UInt8
 * SShiftPosIndStatus: Record with elements
 *   status of type SShiftInd
 * SSlowGuageInfo: Record with elements
 *   gaugeInfo of type SGaugeInfo
 * SSpeedCalcParam: Record with elements
 *   Pulses_Per_Revolution of type UInt32
 *   Revolutions_Per_Unit of type UInt32
 *   Tuning_Factor of type UInt32
 * STT_Status: Record with elements
 *   mask of type data_u8_15
 * STpmsWarningData: Record with elements
 *   tpmsWarndata of type data_u32_5
 * SUpdateLongServiceReq: Record with elements
 *   msgId of type UInt16
 *   msgSize of type UInt16
 *   memoryType of type UInt8
 *   memoryCmd of type UInt8
 *   sid of type UInt8
 *   length of type UInt32
 *   data of type data_u8_2048
 * SUpdateShortServiceReq: Record with elements
 *   msgId of type UInt16
 *   msgSize of type UInt16
 *   memoryType of type UInt8
 *   memoryCmd of type UInt8
 *   sid of type UInt8
 *   length of type UInt32
 *   data of type data_u8_64
 * SUpdateShortServiceResp: Record with elements
 *   msgId of type UInt16
 *   msgSize of type UInt16
 *   sid of type UInt8
 *   length of type UInt16
 *   responseCode of type UInt8
 *   NRC of type UInt8
 *   data of type data_u8_64
 * SWarningDisplay: Record with elements
 *   show of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_8
 * SWarningDisplayAvailable: Record with elements
 *   status of type UInt8
 * SWarningExtDisplay: Record with elements
 *   show of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_8
 * SWarningStatus: Record with elements
 *   visible of type UInt8
 *   warningId of type UInt16
 *   dynData of type data_u8_10
 * ShiftposData_Type: Record with elements
 *   Shift_Up_Ind of type UInt8
 *   DisplayDecState of type UInt8
 *   Shift_Ind_Pos of type UInt16
 *   Shift_Down_Ind of type UInt8
 *   Screen_ShiftType of type UInt8
 * WarningDataS: Record with elements
 *   WarningCurrentStatus of type WarningStatus
 *   WarningCurrentEvent of type WarningEvent
 *   WarningCurrentPayload of type UInt32
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
