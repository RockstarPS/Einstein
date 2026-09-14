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
 *          File:  Rte_UclProxyCdd.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <UclProxyCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_UCLPROXYCDD_H
# define _RTE_UCLPROXYCDD_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_UclProxyCdd_Type.h"
# include "Rte_DataHandleType.h"


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData(P2VAR(SDiagDIDRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(P2VAR(SDiagIOCtrlRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData(P2VAR(SDiagRoutineRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData(P2VAR(SHealthDumpGetData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(P2VAR(SHealthDumpGetHdr, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_IgnState_IgnStateData(P2VAR(SIgnState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(P2VAR(SUpdateLongServiceReq, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(P2VAR(SUpdateShortServiceReq, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(P2VAR(SDLTControlMessageReponse, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(P2VAR(SDLTMessageReadRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_DisplaySetPower_DisplaySetPowerData(P2VAR(SDisplaySetPower, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_FastGaugeInfo_FastGaugeInfoData(P2VAR(SFastGaugeInfo, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_HudWarningDisplay_HudWarningDisplayData(P2VAR(SHudWarningDisplay, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_IlluminationData_IlluminationDataData(P2VAR(SIlluminationData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(P2VAR(SPowerSystemStateReqChange, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(P2VAR(SShiftPosIndStatus, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_SlowGaugeInfo_SlowGaugeInfoData(P2VAR(SSlowGuageInfo, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_TT_Status_TT_StatusData(P2VAR(STT_Status, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_TpmsWarningData_TpmsWarningDataData(P2VAR(STpmsWarningData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UclProxyCdd_rSR_WarningDisplay_WarningDisplayData(P2VAR(SWarningDisplay, AUTOMATIC, RTE_UCLPROXYCDD_APPL_VAR) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_DiagResponse_DiagResponseData(P2CONST(SDiagResponse, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(P2CONST(SHealthDomainFatalError, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(P2CONST(SHealthDomainHeartbeat, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDumpData_HealthDumpDataData(P2CONST(SHealthDumpData, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(P2CONST(SHealthDumpHdrInfo, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(P2CONST(SMainHMIReadyStatus, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(P2CONST(SPowerExtendShutdownTime, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(P2CONST(SPowerKeepSystemAwake, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Send_UclProxyCdd_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(P2CONST(SUpdateShortServiceResp, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(P2CONST(SDLTControlMessageRequest, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_DLTMessageReadAck_DLTMessageReadAckData(P2CONST(SDLTMessageReadAck, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData(P2CONST(SDisplayCurrentState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_HudWarningStatus_HudWarningStatusData(P2CONST(SHudWarningStatus, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData(P2CONST(SPowerSystemState, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UclProxyCdd_pSR_WarningStatus_WarningStatusData(P2CONST(SWarningStatus, AUTOMATIC, RTE_UCLPROXYCDD_APPL_DATA) data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData Rte_Receive_UclProxyCdd_rSR_DiagDIDRequest_DiagDIDRequestData
#  define Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData Rte_Receive_UclProxyCdd_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData
#  define Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData Rte_Receive_UclProxyCdd_rSR_DiagRoutineRequest_DiagRoutineRequestData
#  define Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData Rte_Receive_UclProxyCdd_rSR_HealthDumpGetData_HealthDumpGetDataData
#  define Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData Rte_Receive_UclProxyCdd_rSR_HealthDumpGetHdr_HealthDumpGetHdrData
#  define Rte_Receive_rSR_IgnState_IgnStateData Rte_Receive_UclProxyCdd_rSR_IgnState_IgnStateData
#  define Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData Rte_Receive_UclProxyCdd_rSR_UpdateLongServiceReq_UpdateLongServiceReqData
#  define Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData Rte_Receive_UclProxyCdd_rSR_UpdateShortServiceReq_UpdateShortServiceReqData


/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData Rte_Read_UclProxyCdd_rSR_DLTControlMessageReponse_DLTControlMessageReponseData
#  define Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData Rte_Read_UclProxyCdd_rSR_DLTMessageReadRequest_DLTMessageReadRequestData
#  define Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData Rte_Read_UclProxyCdd_rSR_DisplaySetPower_DisplaySetPowerData
#  define Rte_Read_rSR_FRTT_Status_FRTT_StatusData Rte_Read_UclProxyCdd_rSR_FRTT_Status_FRTT_StatusData
#  define Rte_Read_UclProxyCdd_rSR_FRTT_Status_FRTT_StatusData(data) (*(data) = Rte_UclProxyCddFRTT_StatusDataValue0, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData Rte_Read_UclProxyCdd_rSR_FastGaugeInfo_FastGaugeInfoData
#  define Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData Rte_Read_UclProxyCdd_rSR_HudWarningDisplay_HudWarningDisplayData
#  define Rte_Read_rSR_IlluminationData_IlluminationDataData Rte_Read_UclProxyCdd_rSR_IlluminationData_IlluminationDataData
#  define Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData Rte_Read_UclProxyCdd_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData
#  define Rte_Read_rSR_RTT_Icon_RTT_IconData Rte_Read_UclProxyCdd_rSR_RTT_Icon_RTT_IconData
#  define Rte_Read_UclProxyCdd_rSR_RTT_Icon_RTT_IconData(data) (*(data) = Rte_UclProxyCddRTT_IconDataValue0, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rSR_RTT_Status_RTT_StatusData Rte_Read_UclProxyCdd_rSR_RTT_Status_RTT_StatusData
#  define Rte_Read_UclProxyCdd_rSR_RTT_Status_RTT_StatusData(data) (*(data) = Rte_UclProxyCddRTT_StatusDataValue0, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rSR_RTT_Toggle_RTT_ToggleData Rte_Read_UclProxyCdd_rSR_RTT_Toggle_RTT_ToggleData
#  define Rte_Read_UclProxyCdd_rSR_RTT_Toggle_RTT_ToggleData(data) (*(data) = Rte_UclProxyCddRTT_ToggleDataValue0, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData Rte_Read_UclProxyCdd_rSR_ShiftPosIndStatus_ShiftPosIndStatusData
#  define Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData Rte_Read_UclProxyCdd_rSR_SlowGaugeInfo_SlowGaugeInfoData
#  define Rte_Read_rSR_TT_Status_TT_StatusData Rte_Read_UclProxyCdd_rSR_TT_Status_TT_StatusData
#  define Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData Rte_Read_UclProxyCdd_rSR_TpmsWarningData_TpmsWarningDataData
#  define Rte_Read_rSR_WarningDisplay_WarningDisplayData Rte_Read_UclProxyCdd_rSR_WarningDisplay_WarningDisplayData
#  define Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData Rte_Read_UclProxyCdd_rSR_WarningExtDisplay_WarningExtDisplayData
#  define Rte_Read_UclProxyCdd_rSR_WarningExtDisplay_WarningExtDisplayData(data) (*(data) = Rte_UclProxyCddWarningExtDisplayDataValue0, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
 *********************************************************************************************************************/
#  define Rte_Send_pSR_DiagResponse_DiagResponseData Rte_Send_UclProxyCdd_pSR_DiagResponse_DiagResponseData
#  define Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData Rte_Send_UclProxyCdd_pSR_HealthDomainFatalError_HealthDomainFatalErrorData
#  define Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData Rte_Send_UclProxyCdd_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData
#  define Rte_Send_pSR_HealthDumpData_HealthDumpDataData Rte_Send_UclProxyCdd_pSR_HealthDumpData_HealthDumpDataData
#  define Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData Rte_Send_UclProxyCdd_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData
#  define Rte_Send_pSR_HealthEventRecord_HealthEventRecordData Rte_Send_UclProxyCdd_pSR_HealthEventRecord_HealthEventRecordData
#  define Rte_Send_UclProxyCdd_pSR_HealthEventRecord_HealthEventRecordData(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData Rte_Send_UclProxyCdd_pSR_MainHMIReadyStatus_MainHMIReadyStatusData
#  define Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData Rte_Send_UclProxyCdd_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData
#  define Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData Rte_Send_UclProxyCdd_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData
#  define Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData Rte_Send_UclProxyCdd_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData
#  define Rte_Send_UclProxyCdd_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData Rte_Send_UclProxyCdd_pSR_UpdateShortServiceResp_UpdateShortServiceRespData


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData Rte_Write_UclProxyCdd_pSR_DLTControlMessageRequest_DLTControlMessageRequestData
#  define Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData Rte_Write_UclProxyCdd_pSR_DLTMessageReadAck_DLTMessageReadAckData
#  define Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData Rte_Write_UclProxyCdd_pSR_DisplayCurrentState_DisplayCurrentStateData
#  define Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData Rte_Write_UclProxyCdd_pSR_EmmcErrorNotifier_EmmcErrorNotifierData
#  define Rte_Write_UclProxyCdd_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pSR_HudWarningStatus_HudWarningStatusData Rte_Write_UclProxyCdd_pSR_HudWarningStatus_HudWarningStatusData
#  define Rte_Write_pSR_PowerSystemState_PowerSystemStateData Rte_Write_UclProxyCdd_pSR_PowerSystemState_PowerSystemStateData
#  define Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData Rte_Write_UclProxyCdd_pSR_WarningDisplayAvailable_WarningDisplayAvailableData
#  define Rte_Write_UclProxyCdd_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pSR_WarningStatus_WarningStatusData Rte_Write_UclProxyCdd_pSR_WarningStatus_WarningStatusData


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DMNMGR_APPL_CODE) DmnMgr_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(arg1, arg2) (DmnMgr_ErrorNotification(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DMNMGR_APPL_CODE) DmnMgr_LinkStatusChanged(UInt8 DLInst, SInt32 Status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DMNMGR_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(arg1, arg2) (DmnMgr_LinkStatusChanged(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


# endif /* !defined(RTE_CORE) */


# define UclProxyCdd_START_SEC_CODE
# include "UclProxyCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CUclProxyCdd_Impl_Initialize CUclProxyCdd_Impl_Initialize
#  define RTE_RUNNABLE_CUclProxyCdd_Impl_MainFunction CUclProxyCdd_Impl_MainFunction
#  define RTE_RUNNABLE_CUclProxyCdd_Impl_OnCommand CUclProxyCdd_Impl_OnCommand
#  define RTE_RUNNABLE_CUclProxyCdd_Impl_Shutdown CUclProxyCdd_Impl_Shutdown
#  define RTE_RUNNABLE_OnDre_DLTControlMessageReponse OnDre_DLTControlMessageReponse
#  define RTE_RUNNABLE_OnDre_DLTMessageReadRequest OnDre_DLTMessageReadRequest
#  define RTE_RUNNABLE_OnDre_DiagDIDRequest OnDre_DiagDIDRequest
#  define RTE_RUNNABLE_OnDre_DiagIOCtrlRequest OnDre_DiagIOCtrlRequest
#  define RTE_RUNNABLE_OnDre_DiagRoutineRequest OnDre_DiagRoutineRequest
#  define RTE_RUNNABLE_OnDre_DisplaySetPower OnDre_DisplaySetPower
#  define RTE_RUNNABLE_OnDre_FRTT_Status OnDre_FRTT_Status
#  define RTE_RUNNABLE_OnDre_FastGaugeInfo OnDre_FastGaugeInfo
#  define RTE_RUNNABLE_OnDre_HealthDumpGetData OnDre_HealthDumpGetData
#  define RTE_RUNNABLE_OnDre_HealthDumpGetHdr OnDre_HealthDumpGetHdr
#  define RTE_RUNNABLE_OnDre_IlluminationData OnDre_IlluminationData
#  define RTE_RUNNABLE_OnDre_PowerSystemStateReqChange OnDre_PowerSystemStateReqChange
#  define RTE_RUNNABLE_OnDre_RTT_Icon OnDre_RTT_Icon
#  define RTE_RUNNABLE_OnDre_RTT_Status OnDre_RTT_Status
#  define RTE_RUNNABLE_OnDre_RTT_Toggle OnDre_RTT_Toggle
#  define RTE_RUNNABLE_OnDre_ShiftPosIndStatus OnDre_ShiftPosIndStatus
#  define RTE_RUNNABLE_OnDre_SlowGaugeInfo OnDre_SlowGaugeInfo
#  define RTE_RUNNABLE_OnDre_TT_Status OnDre_TT_Status
#  define RTE_RUNNABLE_OnDre_UpdateLongServiceReq OnDre_UpdateLongServiceReq
#  define RTE_RUNNABLE_OnDre_UpdateShortServiceReq OnDre_UpdateShortServiceReq
#  define RTE_RUNNABLE_OnDre_WarningDisplay OnDre_WarningDisplay
#  define RTE_RUNNABLE_OnDre_WarningExtDisplay OnDre_WarningExtDisplay
# endif

FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Initialize(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, UclProxyCdd_CODE) CUclProxyCdd_Impl_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_OnCommand(ECmpCmd cmdP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, UclProxyCdd_CODE) CUclProxyCdd_Impl_Shutdown(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, UclProxyCdd_CODE) OnDre_DLTControlMessageReponse(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_DLTMessageReadRequest(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_DiagDIDRequest(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_DiagIOCtrlRequest(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_DiagRoutineRequest(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_DisplaySetPower(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_FRTT_Status(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_FastGaugeInfo(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_HealthDumpGetData(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_HealthDumpGetHdr(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_IlluminationData(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_PowerSystemStateReqChange(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_RTT_Icon(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_RTT_Status(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_RTT_Toggle(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_ShiftPosIndStatus(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_SlowGaugeInfo(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_TT_Status(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_UpdateLongServiceReq(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_UpdateShortServiceReq(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_WarningDisplay(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, UclProxyCdd_CODE) OnDre_WarningExtDisplay(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define UclProxyCdd_STOP_SEC_CODE
# include "UclProxyCdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_UclInitShutdown_E_NOT_OK (1U)

#  define RTE_E_if_CS_ModeOnCommand_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_UCLPROXYCDD_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
