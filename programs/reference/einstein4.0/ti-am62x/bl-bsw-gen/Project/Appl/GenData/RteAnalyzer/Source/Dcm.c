/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Dcm.c
 *        Config:  BMW.dpa"
 *    BSW Module:  Dcm
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for BSW Module <Dcm>
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

#include "SchM_Dcm.h"
#include "TSC_SchM_Dcm.h"


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
 * Boolean: Boolean
 * ComM_InhibitionStatusType: Integer in interval [0...255]
 * ComM_UserHandleType: Integer in interval [0...255]
 * CounterType: Integer in interval [0...255]
 * Dem_DTCGroupType: Integer in interval [0...16777215]
 * Dem_DTCStatusMaskType: Integer in interval [0...255]
 * Dem_EventIdType: Integer in interval [1...65535]
 * Dem_OperationCycleIdType: Integer in interval [0...255]
 * Dem_RatioIdType: Integer in interval [1...65535]
 * EcuM_TimeType: Integer in interval [0...4294967295]
 * NetworkHandleType: Integer in interval [0...255]
 * NvM_BlockIdType: Integer in interval [0...65535]
 * NvM_BlockIdType: Integer in interval [1...32767]
 * NvM_RequestResultType: Integer in interval [0...255]
 * Rte_DT_Arr_u8_100_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_1024_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_128_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_16_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_256_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_32_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_48_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_64_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_8_0: Integer in interval [0...255]
 * SInt32: Integer in interval [-2147483648...2147483647]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
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
 * ComM_ModeType: Enumeration of integer in interval [0...3] with enumerators
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
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 * EDisplayStatus: Enumeration of integer in interval [0...255] with enumerators
 * EDisplayType: Enumeration of integer in interval [0...1] with enumerators
 * EDomainId: Enumeration of integer in interval [0...255] with enumerators
 * EIgnitionStatus: Enumeration of integer in interval [0...255] with enumerators
 * ESystemState: Enumeration of integer in interval [0...255] with enumerators
 * EcuM_BootTargetType: Enumeration of integer in interval [0...2] with enumerators
 * EcuM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_ShutdownCauseType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_StateType: Enumeration of integer in interval [0...144] with enumerators
 * EcuM_UserType: Enumeration of integer in interval [0...255] with enumerators
 * EnetReqCmd_t: Enumeration of integer in interval [0...255] with enumerators
 * EnetReqMode_t: Enumeration of integer in interval [0...255] with enumerators
 * HTimer: Enumeration of integer in interval [0...79] with enumerators
 * IoHwAb_AdcSignalIdType: Enumeration of integer in interval [0...17] with enumerators
 * IoHwAb_DInGroupIdType: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 * IoHwAb_DInSignalIdType: Enumeration of integer in interval [0...13] with enumerators
 * IoHwAb_DOutGroupIdType: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 * IoHwAb_DOutSignalIdType: Enumeration of integer in interval [0...26] with enumerators
 * IoHwAb_ErrorType: Enumeration of integer in interval [2...13] with enumerators
 * IoHwAb_PwmSignalIdType: Enumeration of integer in interval [0...9] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 * NvM_RequestResultType: Enumeration of integer in interval [0...8] with enumerators
 * NvM_ServiceIdType: Enumeration of integer in interval [0...255] with enumerators
 * NvM_ServiceIdType: Enumeration of integer in interval [6...12] with enumerators
 * eIOPulseInputId: Enumeration of integer in interval [-2147483647...2147483647] with enumerators
 *
 * Array Types:
 * ============
 * Arr_u8_100: Array with 100 element(s) of type Rte_DT_Arr_u8_100_0
 * Arr_u8_1024: Array with 1024 element(s) of type Rte_DT_Arr_u8_1024_0
 * Arr_u8_128: Array with 128 element(s) of type Rte_DT_Arr_u8_128_0
 * Arr_u8_16: Array with 16 element(s) of type Rte_DT_Arr_u8_16_0
 * Arr_u8_2048: Array with 2048 element(s) of type Rte_DT_Arr_u8_2048_0
 * Arr_u8_256: Array with 256 element(s) of type Rte_DT_Arr_u8_256_0
 * Arr_u8_32: Array with 32 element(s) of type Rte_DT_Arr_u8_32_0
 * Arr_u8_48: Array with 48 element(s) of type Rte_DT_Arr_u8_48_0
 * Arr_u8_64: Array with 64 element(s) of type Rte_DT_Arr_u8_64_0
 * Arr_u8_8: Array with 8 element(s) of type Rte_DT_Arr_u8_8_0
 * Dem_MaxDataValueType: Array with 1 element(s) of type uint8
 * data_u8_32: Array with 32 element(s) of type uint8
 * data_u8_8: Array with 8 element(s) of type uint8
 *
 * Record Types:
 * =============
 * NV_Data_BsConst_Audio: Record with elements
 *   BsConst_Audio_Element of type Arr_u8_128
 * NV_Data_BsConst_Communication: Record with elements
 *   BsConst_Communication_Element of type Arr_u8_64
 * NV_Data_BsConst_EngOffTimer: Record with elements
 *   BsConst_EngOffTimer_Element of type Arr_u8_32
 * NV_Data_BsConst_FuelGauge: Record with elements
 *   BsConst_FuelGauge_Element of type Arr_u8_128
 * NV_Data_BsConst_Illumination: Record with elements
 *   BsConst_Illumination_Element of type Arr_u8_128
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
 * NV_Data_BsFuSa_Audio: Record with elements
 *   BsFuSa_Audio_Element of type Arr_u8_32
 * NV_Data_BsFuSa_Communication: Record with elements
 *   BsFuSa_Communication_Element of type Arr_u8_16
 * NV_Data_BsFuSa_Config: Record with elements
 *   BsFuSa_Config_Element of type Arr_u8_16
 * NV_Data_BsFuSa_Display: Record with elements
 *   BsFuSa_Display_Element of type Arr_u8_64
 * NV_Data_BsFuSa_Power: Record with elements
 *   BsFuSa_Power_Element of type Arr_u8_48
 * NV_Data_BsFuSa_Warning: Record with elements
 *   BsFuSa_Warning_Element of type Arr_u8_32
 * NV_Data_BsFusa_Fota: Record with elements
 *   BsFusa_Fota_Element of type Arr_u8_32
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
 * NV_Data_BsReten_VisDlt: Record with elements
 *   BsReten_VisDlt_Element of type Arr_u8_256
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
 *   BsShare_EcuPartNumber_Element of type Arr_u8_128
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
 *   BsShare_VisMeet_Element of type Arr_u8_48
 * NV_Data_RefCys_Certicificate: Record with elements
 *   RefCys_Certicificate_Element of type Arr_u8_64
 * NV_Data_RefCys_Certicificate1: Record with elements
 *   RefCys_Certicificate1_Element of type Arr_u8_64
 * SDisplayCurrentState: Record with elements
 *   displayId of type uint32
 *   state of type EDisplayStatus
 * SEnetRegReq: Record with elements
 *   cmd of type EnetReqCmd_t
 *   mode of type EnetReqMode_t
 *   dataLen of type uint8
 *   data of type data_u8_8
 * SEnetRegResp: Record with elements
 *   cmd of type EnetReqCmd_t
 *   respLen of type uint8
 *   response of type data_u8_32
 * SHealthDomainFatalError: Record with elements
 *   domainId of type uint8
 *   compldx of type uint32
 * SHealthDomainHeartbeat: Record with elements
 *   domainId of type uint8
 *   seqCnt of type uint32
 * SHealthDumpGetData: Record with elements
 *   reserved of type uint8
 * SHealthDumpGetHdr: Record with elements
 *   encrypt of type uint8
 * SHealthDumpHdrInfo: Record with elements
 *   fileSize of type uint32
 * SHealthEventRecord: Record with elements
 *   recordType of type uint8
 *   recordLen of type uint8
 *   recordData of type data_u8_8
 * SIgnState: Record with elements
 *   state of type EIgnitionStatus
 * SPowerExtendShutdownTime: Record with elements
 *   domainId of type EDomainId
 *   timeoutMs of type uint32
 * SPowerSystemState: Record with elements
 *   domainId of type EDomainId
 *   state of type ESystemState
 * SPowerSystemStateReqChange: Record with elements
 *   domainId of type EDomainId
 *   state of type ESystemState
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
 * SSpeedCalcParam: Record with elements
 *   Pulses_Per_Revolution of type UInt32
 *   Revolutions_Per_Unit of type UInt32
 *   Tuning_Factor of type UInt32
 *
 *********************************************************************************************************************/


#define DCM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Schedulable Entity Name: Dcm_MainFunction
 *
 *********************************************************************************************************************/

FUNC(void, DCM_CODE) Dcm_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_MainFunction
 *********************************************************************************************************************/

  TSC_Dcm_SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0();
  TSC_Dcm_SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define DCM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
