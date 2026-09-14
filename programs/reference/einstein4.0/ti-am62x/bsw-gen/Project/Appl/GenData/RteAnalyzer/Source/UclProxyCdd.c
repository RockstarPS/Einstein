/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  UclProxyCdd.c
 *        Config:  BMW.dpa
 *     SW-C Type:  UclProxyCdd
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <UclProxyCdd>
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

#include "Rte_UclProxyCdd.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_UclProxyCdd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void UclProxyCdd_TestDefines(void);


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
 * Rte_DT_data_u32_5_0: Integer in interval [0...4294967295]
 * Rte_DT_data_u8_10_0: Integer in interval [0...255]
 * Rte_DT_data_u8_15_0: Integer in interval [0...255]
 * Rte_DT_data_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_data_u8_256_0: Integer in interval [0...255]
 * Rte_DT_data_u8_2_0: Integer in interval [0...255]
 * Rte_DT_data_u8_32_0: Integer in interval [0...255]
 * Rte_DT_data_u8_64_0: Integer in interval [0...255]
 * Rte_DT_data_u8_8_0: Integer in interval [0...255]
 * SInt32: Integer in interval [-2147483648...2147483647]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * EDidType: Enumeration of integer in interval [0...2] with enumerators
 *   EDidType_Read (0U)
 *   EDidType_Write (1U)
 *   EDidType_Last (2U)
 * EDisplayPower: Enumeration of integer in interval [0...2] with enumerators
 *   EDisplayPower_Off (0U)
 *   EDisplayPower_On (1U)
 *   EDisplayPower_Last (2U)
 * EDisplayStatus: Enumeration of integer in interval [0...4] with enumerators
 *   EDisplayState_Off (0U)
 *   EDisplayState_On (1U)
 *   EDisplayState_Error (2U)
 *   EDisplayState_Disconnected (3U)
 *   EDisplayState_Last (4U)
 * EDomainId: Enumeration of integer in interval [0...3] with enumerators
 *   EDomainId_VP (0U)
 *   EDomainId_Cluster (1U)
 *   EDomainId_IVI (2U)
 *   EDomainId_Last (3U)
 * EGaugeUnit: Enumeration of integer in interval [0...13] with enumerators
 *   EGaugeUnit_Mph (0U)
 *   EGaugeUnit_Kmph (1U)
 *   EGaugeUnit_Centigrade (2U)
 *   EGaugeUnit_Farenheit (3U)
 *   EGaugeUnit_Psi (4U)
 *   EGaugeUnit_Pa (5U)
 *   EGaugeUnit_Bar (6U)
 *   EGaugeUnit_Kmpl (7U)
 *   EGaugeUnit_Mpg (8U)
 *   EGaugeUnit_Ltr (9U)
 *   EGaugeUnit_Gal (10U)
 *   EGaugeUnit_Km (11U)
 *   EGaugeUnit_Mile (12U)
 *   EGaugeUnit_Last (13U)
 * EIOCtrlOptType: Enumeration of integer in interval [0...4] with enumerators
 *   EIOCtrlOptType_returnControlToECU (0U)
 *   EIOCtrlOptType_resetToDefault (1U)
 *   EIOCtrlOptType_freezeCurrentState (2U)
 *   EIOCtrlOptType_shortTermAdjustment (3U)
 *   EIOCtrlOptType_Last (4U)
 * EIgnitionStatus: Enumeration of integer in interval [0...4] with enumerators
 *   EIgnitionStatus_Off (0U)
 *   EIgnitionStatus_Acc (1U)
 *   EIgnitionStatus_Start (2U)
 *   EIgnitionStatus_Run (3U)
 *   EIgnitionStatus_Last (4U)
 * ERoutineType: Enumeration of integer in interval [0...3] with enumerators
 *   ERoutineType_Start (0U)
 *   ERoutineType_Stop (1U)
 *   ERoutineType_QueryResults (2U)
 *   ERoutineType_Last (3U)
 * ESystemState: Enumeration of integer in interval [0...8] with enumerators
 *   ESystemState_Off (0U)
 *   ESystemState_Startup (1U)
 *   ESystemState_Up (2U)
 *   ESystemState_FullRun (3U)
 *   ESystemState_PrepareShutdown (4U)
 *   ESystemState_Minimal (5U)
 *   ESystemState_Meet (6U)
 *   ESystemState_Shutdown (7U)
 *   ESystemState_Last (8U)
 *
 * Array Types:
 * ============
 * SGaugeInfo_u32dyn_2: Array with 2 element(s) of type SGaugeInfo_u32dyn
 * data_u32_5: Array with 5 element(s) of type Rte_DT_data_u32_5_0
 * data_u8_10: Array with 10 element(s) of type Rte_DT_data_u8_10_0
 * data_u8_15: Array with 15 element(s) of type Rte_DT_data_u8_15_0
 * data_u8_2: Array with 2 element(s) of type Rte_DT_data_u8_2_0
 * data_u8_2048: Array with 2048 element(s) of type Rte_DT_data_u8_2048_0
 * data_u8_256: Array with 256 element(s) of type Rte_DT_data_u8_256_0
 * data_u8_32: Array with 32 element(s) of type Rte_DT_data_u8_32_0
 * data_u8_64: Array with 64 element(s) of type Rte_DT_data_u8_64_0
 * data_u8_8: Array with 8 element(s) of type Rte_DT_data_u8_8_0
 *
 * Record Types:
 * =============
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
 *   displayId of type UInt32
 *   state of type EDisplayStatus
 * SDisplaySetPower: Record with elements
 *   displayId of type UInt32
 *   state of type EDisplayPower
 * SEmmcErrorNotifier: Record with elements
 *   errorCode of type UInt32
 * SFRTT_Status: Record with elements
 *   mask of type data_u8_2
 * SFastGaugeInfo: Record with elements
 *   gaugeInfo of type SGaugeInfo_u32dyn_2
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
 * SPowerSystemStateReqChange: Record with elements
 *   state of type ESystemState
 *   domainId of type EDomainId
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
 *
 *********************************************************************************************************************/


#define UclProxyCdd_START_SEC_CODE
#include "UclProxyCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CUclProxyCdd_Impl_Initialize
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_Initialize> of PortPrototype <ppCS_UclInitShutdown>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CUclProxyCdd_Impl_Initialize(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_UclInitShutdown_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_Initialize_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Initialize(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_Initialize (returns application error)
 *********************************************************************************************************************/

  UclProxyCdd_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CUclProxyCdd_Impl_MainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_MainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) CUclProxyCdd_Impl_MainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_MainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CUclProxyCdd_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_CUclProxyCdd>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CUclProxyCdd_Impl_OnCommand(ECmpCmd cmdP)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CUclProxyCdd_Impl_Shutdown
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_Shutdown> of PortPrototype <ppCS_UclInitShutdown>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CUclProxyCdd_Impl_Shutdown(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_UclInitShutdown_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_Shutdown_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Shutdown(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CUclProxyCdd_Impl_Shutdown (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_DLTControlMessageReponse
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DLTControlMessageReponseData> of PortPrototype <rSR_DLTControlMessageReponse>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DLTControlMessageReponse_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_DLTControlMessageReponse(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DLTControlMessageReponse
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_DLTMessageReadRequest
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DLTMessageReadRequestData> of PortPrototype <rSR_DLTMessageReadRequest>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DLTMessageReadRequest_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_DLTMessageReadRequest(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DLTMessageReadRequest
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_DiagDIDRequest
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DiagDIDRequestData> of PortPrototype <rSR_DiagDIDRequest>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DiagDIDRequest_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_DiagDIDRequest(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DiagDIDRequest
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_DiagIOCtrlRequest
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DiagIOCtrlRequestData> of PortPrototype <rSR_DiagIOCtrlRequest>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DiagIOCtrlRequest_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_DiagIOCtrlRequest(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DiagIOCtrlRequest
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_DiagRoutineRequest
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DiagRoutineRequestData> of PortPrototype <rSR_DiagRoutineRequest>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DiagRoutineRequest_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_DiagRoutineRequest(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DiagRoutineRequest
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_DisplaySetPower
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DisplaySetPowerData> of PortPrototype <rSR_DisplaySetPower>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DisplaySetPower_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_DisplaySetPower(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_DisplaySetPower
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_FRTT_Status
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <FRTT_StatusData> of PortPrototype <rSR_FRTT_Status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_FRTT_Status_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_FRTT_Status(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_FRTT_Status
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_FastGaugeInfo
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <FastGaugeInfoData> of PortPrototype <rSR_FastGaugeInfo>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_FastGaugeInfo_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_FastGaugeInfo(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_FastGaugeInfo
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_HealthDumpGetData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HealthDumpGetDataData> of PortPrototype <rSR_HealthDumpGetData>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_HealthDumpGetData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_HealthDumpGetData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_HealthDumpGetData
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_HealthDumpGetHdr
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <HealthDumpGetHdrData> of PortPrototype <rSR_HealthDumpGetHdr>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_HealthDumpGetHdr_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_HealthDumpGetHdr(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_HealthDumpGetHdr
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_IlluminationData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <IlluminationDataData> of PortPrototype <rSR_IlluminationData>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_IlluminationData_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_IlluminationData(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_IlluminationData
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_PowerSystemStateReqChange
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <PowerSystemStateReqChangeData> of PortPrototype <rSR_PowerSystemStateReqChange>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_PowerSystemStateReqChange_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_PowerSystemStateReqChange(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_PowerSystemStateReqChange
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_RTT_Icon
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <RTT_IconData> of PortPrototype <rSR_RTT_Icon>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_RTT_Icon_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_RTT_Icon(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_RTT_Icon
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_RTT_Status
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <RTT_StatusData> of PortPrototype <rSR_RTT_Status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_RTT_Status_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_RTT_Status(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_RTT_Status
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_RTT_Toggle
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <RTT_ToggleData> of PortPrototype <rSR_RTT_Toggle>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_RTT_Toggle_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_RTT_Toggle(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_RTT_Toggle
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_ShiftPosIndStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ShiftPosIndStatusData> of PortPrototype <rSR_ShiftPosIndStatus>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_ShiftPosIndStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_ShiftPosIndStatus(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_ShiftPosIndStatus
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_SlowGaugeInfo
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <SlowGaugeInfoData> of PortPrototype <rSR_SlowGaugeInfo>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_SlowGaugeInfo_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_SlowGaugeInfo(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_SlowGaugeInfo
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_TT_Status
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <TT_StatusData> of PortPrototype <rSR_TT_Status>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_TT_Status_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_TT_Status(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_TT_Status
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_UpdateLongServiceReq
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <UpdateLongServiceReqData> of PortPrototype <rSR_UpdateLongServiceReq>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_UpdateLongServiceReq_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_UpdateLongServiceReq(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_UpdateLongServiceReq
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_UpdateShortServiceReq
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <UpdateShortServiceReqData> of PortPrototype <rSR_UpdateShortServiceReq>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_UpdateShortServiceReq_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_UpdateShortServiceReq(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_UpdateShortServiceReq
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_WarningDisplay
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <WarningDisplayData> of PortPrototype <rSR_WarningDisplay>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_WarningDisplay_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_WarningDisplay(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_WarningDisplay
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: OnDre_WarningExtDisplay
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <WarningExtDisplayData> of PortPrototype <rSR_WarningExtDisplay>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
 *   Std_ReturnType Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
 *   Std_ReturnType Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
 *   Std_ReturnType Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
 *   Std_ReturnType Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
 *   Std_ReturnType Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
 *   Std_ReturnType Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
 *   Std_ReturnType Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
 *   Std_ReturnType Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
 *   Std_ReturnType Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
 *   Std_ReturnType Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
 *   Std_ReturnType Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
 *   Std_ReturnType Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
 *   Std_ReturnType Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
 *   Std_ReturnType Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
 *   Std_ReturnType Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
 *   Std_ReturnType Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
 *   Std_ReturnType Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
 *   Std_ReturnType Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
 *   Std_ReturnType Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
 *   Std_ReturnType Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
 *   Std_ReturnType Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
 *   Std_ReturnType Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
 *   Std_ReturnType Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
 *   Std_ReturnType Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
 *   Std_ReturnType Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
 *   Std_ReturnType Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
 *   Std_ReturnType Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
 *   Std_ReturnType Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
 *   Std_ReturnType Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_WarningExtDisplay_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, UclProxyCdd_CODE) OnDre_WarningExtDisplay(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: OnDre_WarningExtDisplay
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  SDiagDIDRequest Receive_rSR_DiagDIDRequest_DiagDIDRequestData;
  SDiagIOCtrlRequest Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData;
  SDiagRoutineRequest Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData;
  SHealthDumpGetData Receive_rSR_HealthDumpGetData_HealthDumpGetDataData;
  SHealthDumpGetHdr Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData;
  SIgnState Receive_rSR_IgnState_IgnStateData;
  SUpdateLongServiceReq Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData;
  SUpdateShortServiceReq Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData;
  SDLTControlMessageReponse Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData;
  SDLTMessageReadRequest Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData;
  SDisplaySetPower Read_rSR_DisplaySetPower_DisplaySetPowerData;
  SFRTT_Status Read_rSR_FRTT_Status_FRTT_StatusData;
  SFastGaugeInfo Read_rSR_FastGaugeInfo_FastGaugeInfoData;
  SHudWarningDisplay Read_rSR_HudWarningDisplay_HudWarningDisplayData;
  SIlluminationData Read_rSR_IlluminationData_IlluminationDataData;
  SPowerSystemStateReqChange Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData;
  SRTT_Icon Read_rSR_RTT_Icon_RTT_IconData;
  SRTT_Status Read_rSR_RTT_Status_RTT_StatusData;
  SRTT_Toggle Read_rSR_RTT_Toggle_RTT_ToggleData;
  SShiftPosIndStatus Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData;
  SSlowGuageInfo Read_rSR_SlowGaugeInfo_SlowGaugeInfoData;
  STT_Status Read_rSR_TT_Status_TT_StatusData;
  STpmsWarningData Read_rSR_TpmsWarningData_TpmsWarningDataData;
  SWarningDisplay Read_rSR_WarningDisplay_WarningDisplayData;
  SWarningExtDisplay Read_rSR_WarningExtDisplay_WarningExtDisplayData;

  SDiagResponse Send_pSR_DiagResponse_DiagResponseData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SHealthDomainFatalError Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData = {
  0U, 0U
};
  SHealthDomainHeartbeat Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData = {
  0U, 0U
};
  SHealthDumpData Send_pSR_HealthDumpData_HealthDumpDataData = {
  0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U}
};
  SHealthDumpHdrInfo Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData = {
  0U
};
  SHealthEventRecord Send_pSR_HealthEventRecord_HealthEventRecordData = {
  0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};
  SMainHMIReadyStatus Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData = {
  0U
};
  SPowerExtendShutdownTime Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData = {
  0U, 0U
};
  SPowerKeepSystemAwake Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData = {
  0U, 0U
};
  SSafeHMIReadyStatus Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData = {
  0U
};
  SUpdateShortServiceResp Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData = {
  0U, 0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}
};

  SDLTControlMessageRequest Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData;
  SDLTMessageReadAck Write_pSR_DLTMessageReadAck_DLTMessageReadAckData;
  SDisplayCurrentState Write_pSR_DisplayCurrentState_DisplayCurrentStateData;
  SEmmcErrorNotifier Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData;
  SHudWarningStatus Write_pSR_HudWarningStatus_HudWarningStatusData;
  SPowerSystemState Write_pSR_PowerSystemState_PowerSystemStateData;
  SWarningDisplayAvailable Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData;
  SWarningStatus Write_pSR_WarningStatus_WarningStatusData;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(&Receive_rSR_DiagDIDRequest_DiagDIDRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(&Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(&Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(&Receive_rSR_HealthDumpGetData_HealthDumpGetDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(&Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(&Receive_rSR_IgnState_IgnStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(&Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(&Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NO_DATA:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_LOST_DATA:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(&Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(&Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(&Read_rSR_DisplaySetPower_DisplaySetPowerData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(&Read_rSR_FRTT_Status_FRTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(&Read_rSR_FastGaugeInfo_FastGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(&Read_rSR_HudWarningDisplay_HudWarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(&Read_rSR_IlluminationData_IlluminationDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(&Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(&Read_rSR_RTT_Icon_RTT_IconData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(&Read_rSR_RTT_Status_RTT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(&Read_rSR_RTT_Toggle_RTT_ToggleData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(&Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(&Read_rSR_SlowGaugeInfo_SlowGaugeInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(&Read_rSR_TT_Status_TT_StatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(&Read_rSR_TpmsWarningData_TpmsWarningDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(&Read_rSR_WarningDisplay_WarningDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(&Read_rSR_WarningExtDisplay_WarningExtDisplayData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(&Send_pSR_DiagResponse_DiagResponseData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(&Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(&Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(&Send_pSR_HealthDumpData_HealthDumpDataData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(&Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(&Send_pSR_HealthEventRecord_HealthEventRecordData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(&Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(&Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(&Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(&Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(&Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_LIMIT:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData, 0, sizeof(Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(&Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData, 0, sizeof(Write_pSR_DLTMessageReadAck_DLTMessageReadAckData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(&Write_pSR_DLTMessageReadAck_DLTMessageReadAckData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData, 0, sizeof(Write_pSR_DisplayCurrentState_DisplayCurrentStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(&Write_pSR_DisplayCurrentState_DisplayCurrentStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData, 0, sizeof(Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(&Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_HudWarningStatus_HudWarningStatusData, 0, sizeof(Write_pSR_HudWarningStatus_HudWarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(&Write_pSR_HudWarningStatus_HudWarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_PowerSystemState_PowerSystemStateData, 0, sizeof(Write_pSR_PowerSystemState_PowerSystemStateData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(&Write_pSR_PowerSystemState_PowerSystemStateData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData, 0, sizeof(Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(&Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_pSR_WarningStatus_WarningStatusData, 0, sizeof(Write_pSR_WarningStatus_WarningStatusData));
  fct_status = TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(&Write_pSR_WarningStatus_WarningStatusData);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(0U, 0);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define UclProxyCdd_STOP_SEC_CODE
#include "UclProxyCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void UclProxyCdd_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  EDidType Test_EDidType_V_1 = EDidType_Read;
  EDidType Test_EDidType_V_2 = EDidType_Write;
  EDidType Test_EDidType_V_3 = EDidType_Last;

  EDisplayPower Test_EDisplayPower_V_1 = EDisplayPower_Off;
  EDisplayPower Test_EDisplayPower_V_2 = EDisplayPower_On;
  EDisplayPower Test_EDisplayPower_V_3 = EDisplayPower_Last;

  EDisplayStatus Test_EDisplayStatus_V_1 = EDisplayState_Off;
  EDisplayStatus Test_EDisplayStatus_V_2 = EDisplayState_On;
  EDisplayStatus Test_EDisplayStatus_V_3 = EDisplayState_Error;
  EDisplayStatus Test_EDisplayStatus_V_4 = EDisplayState_Disconnected;
  EDisplayStatus Test_EDisplayStatus_V_5 = EDisplayState_Last;

  EDomainId Test_EDomainId_V_1 = EDomainId_VP;
  EDomainId Test_EDomainId_V_2 = EDomainId_Cluster;
  EDomainId Test_EDomainId_V_3 = EDomainId_IVI;
  EDomainId Test_EDomainId_V_4 = EDomainId_Last;

  EGaugeUnit Test_EGaugeUnit_V_1 = EGaugeUnit_Mph;
  EGaugeUnit Test_EGaugeUnit_V_2 = EGaugeUnit_Kmph;
  EGaugeUnit Test_EGaugeUnit_V_3 = EGaugeUnit_Centigrade;
  EGaugeUnit Test_EGaugeUnit_V_4 = EGaugeUnit_Farenheit;
  EGaugeUnit Test_EGaugeUnit_V_5 = EGaugeUnit_Psi;
  EGaugeUnit Test_EGaugeUnit_V_6 = EGaugeUnit_Pa;
  EGaugeUnit Test_EGaugeUnit_V_7 = EGaugeUnit_Bar;
  EGaugeUnit Test_EGaugeUnit_V_8 = EGaugeUnit_Kmpl;
  EGaugeUnit Test_EGaugeUnit_V_9 = EGaugeUnit_Mpg;
  EGaugeUnit Test_EGaugeUnit_V_10 = EGaugeUnit_Ltr;
  EGaugeUnit Test_EGaugeUnit_V_11 = EGaugeUnit_Gal;
  EGaugeUnit Test_EGaugeUnit_V_12 = EGaugeUnit_Km;
  EGaugeUnit Test_EGaugeUnit_V_13 = EGaugeUnit_Mile;
  EGaugeUnit Test_EGaugeUnit_V_14 = EGaugeUnit_Last;

  EIOCtrlOptType Test_EIOCtrlOptType_V_1 = EIOCtrlOptType_returnControlToECU;
  EIOCtrlOptType Test_EIOCtrlOptType_V_2 = EIOCtrlOptType_resetToDefault;
  EIOCtrlOptType Test_EIOCtrlOptType_V_3 = EIOCtrlOptType_freezeCurrentState;
  EIOCtrlOptType Test_EIOCtrlOptType_V_4 = EIOCtrlOptType_shortTermAdjustment;
  EIOCtrlOptType Test_EIOCtrlOptType_V_5 = EIOCtrlOptType_Last;

  EIgnitionStatus Test_EIgnitionStatus_V_1 = EIgnitionStatus_Off;
  EIgnitionStatus Test_EIgnitionStatus_V_2 = EIgnitionStatus_Acc;
  EIgnitionStatus Test_EIgnitionStatus_V_3 = EIgnitionStatus_Start;
  EIgnitionStatus Test_EIgnitionStatus_V_4 = EIgnitionStatus_Run;
  EIgnitionStatus Test_EIgnitionStatus_V_5 = EIgnitionStatus_Last;

  ERoutineType Test_ERoutineType_V_1 = ERoutineType_Start;
  ERoutineType Test_ERoutineType_V_2 = ERoutineType_Stop;
  ERoutineType Test_ERoutineType_V_3 = ERoutineType_QueryResults;
  ERoutineType Test_ERoutineType_V_4 = ERoutineType_Last;

  ESystemState Test_ESystemState_V_1 = ESystemState_Off;
  ESystemState Test_ESystemState_V_2 = ESystemState_Startup;
  ESystemState Test_ESystemState_V_3 = ESystemState_Up;
  ESystemState Test_ESystemState_V_4 = ESystemState_FullRun;
  ESystemState Test_ESystemState_V_5 = ESystemState_PrepareShutdown;
  ESystemState Test_ESystemState_V_6 = ESystemState_Minimal;
  ESystemState Test_ESystemState_V_7 = ESystemState_Meet;
  ESystemState Test_ESystemState_V_8 = ESystemState_Shutdown;
  ESystemState Test_ESystemState_V_9 = ESystemState_Last;
}

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
