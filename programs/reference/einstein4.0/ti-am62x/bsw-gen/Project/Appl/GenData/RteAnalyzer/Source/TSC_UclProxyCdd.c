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
 *          File:  TSC_UclProxyCdd.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_UclProxyCdd.h"
#include "TSC_UclProxyCdd.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */





Std_ReturnType TSC_UclProxyCdd_Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(SDiagDIDRequest *data)
{
  return Rte_Receive_rSR_DiagDIDRequest_DiagDIDRequestData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(SDiagIOCtrlRequest *data)
{
  return Rte_Receive_rSR_DiagIOCtrlRequest_DiagIOCtrlRequestData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(SDiagRoutineRequest *data)
{
  return Rte_Receive_rSR_DiagRoutineRequest_DiagRoutineRequestData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data)
{
  return Rte_Receive_rSR_HealthDumpGetData_HealthDumpGetDataData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data)
{
  return Rte_Receive_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Receive_rSR_IgnState_IgnStateData(SIgnState *data)
{
  return Rte_Receive_rSR_IgnState_IgnStateData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(SUpdateLongServiceReq *data)
{
  return Rte_Receive_rSR_UpdateLongServiceReq_UpdateLongServiceReqData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(SUpdateShortServiceReq *data)
{
  return Rte_Receive_rSR_UpdateShortServiceReq_UpdateShortServiceReqData(data);
}


Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(SDLTControlMessageReponse *data)
{
  return Rte_Read_rSR_DLTControlMessageReponse_DLTControlMessageReponseData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(SDLTMessageReadRequest *data)
{
  return Rte_Read_rSR_DLTMessageReadRequest_DLTMessageReadRequestData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(SDisplaySetPower *data)
{
  return Rte_Read_rSR_DisplaySetPower_DisplaySetPowerData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_FRTT_Status_FRTT_StatusData(SFRTT_Status *data)
{
  return Rte_Read_rSR_FRTT_Status_FRTT_StatusData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(SFastGaugeInfo *data)
{
  return Rte_Read_rSR_FastGaugeInfo_FastGaugeInfoData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(SHudWarningDisplay *data)
{
  return Rte_Read_rSR_HudWarningDisplay_HudWarningDisplayData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_IlluminationData_IlluminationDataData(SIlluminationData *data)
{
  return Rte_Read_rSR_IlluminationData_IlluminationDataData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data)
{
  return Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_RTT_Icon_RTT_IconData(SRTT_Icon *data)
{
  return Rte_Read_rSR_RTT_Icon_RTT_IconData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_RTT_Status_RTT_StatusData(SRTT_Status *data)
{
  return Rte_Read_rSR_RTT_Status_RTT_StatusData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(SRTT_Toggle *data)
{
  return Rte_Read_rSR_RTT_Toggle_RTT_ToggleData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(SShiftPosIndStatus *data)
{
  return Rte_Read_rSR_ShiftPosIndStatus_ShiftPosIndStatusData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(SSlowGuageInfo *data)
{
  return Rte_Read_rSR_SlowGaugeInfo_SlowGaugeInfoData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_TT_Status_TT_StatusData(STT_Status *data)
{
  return Rte_Read_rSR_TT_Status_TT_StatusData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(STpmsWarningData *data)
{
  return Rte_Read_rSR_TpmsWarningData_TpmsWarningDataData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_WarningDisplay_WarningDisplayData(SWarningDisplay *data)
{
  return Rte_Read_rSR_WarningDisplay_WarningDisplayData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(SWarningExtDisplay *data)
{
  return Rte_Read_rSR_WarningExtDisplay_WarningExtDisplayData(data);
}


Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_DiagResponse_DiagResponseData(const SDiagResponse *data)
{
  return Rte_Send_pSR_DiagResponse_DiagResponseData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data)
{
  return Rte_Send_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data)
{
  return Rte_Send_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpData_HealthDumpDataData(const SHealthDumpData *data)
{
  return Rte_Send_pSR_HealthDumpData_HealthDumpDataData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data)
{
  return Rte_Send_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data)
{
  return Rte_Send_pSR_HealthEventRecord_HealthEventRecordData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(const SMainHMIReadyStatus *data)
{
  return Rte_Send_pSR_MainHMIReadyStatus_MainHMIReadyStatusData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data)
{
  return Rte_Send_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(const SPowerKeepSystemAwake *data)
{
  return Rte_Send_pSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(const SSafeHMIReadyStatus *data)
{
  return Rte_Send_pSR_SafeHMIReadyStatus_SafeHMIReadyStatusData(data);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(const SUpdateShortServiceResp *data)
{
  return Rte_Send_pSR_UpdateShortServiceResp_UpdateShortServiceRespData(data);
}


Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(const SDLTControlMessageRequest *data)
{
  return Rte_Write_pSR_DLTControlMessageRequest_DLTControlMessageRequestData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(const SDLTMessageReadAck *data)
{
  return Rte_Write_pSR_DLTMessageReadAck_DLTMessageReadAckData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data)
{
  return Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(const SEmmcErrorNotifier *data)
{
  return Rte_Write_pSR_EmmcErrorNotifier_EmmcErrorNotifierData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(const SHudWarningStatus *data)
{
  return Rte_Write_pSR_HudWarningStatus_HudWarningStatusData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data)
{
  return Rte_Write_pSR_PowerSystemState_PowerSystemStateData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(const SWarningDisplayAvailable *data)
{
  return Rte_Write_pSR_WarningDisplayAvailable_WarningDisplayAvailableData(data);
}

Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_WarningStatus_WarningStatusData(const SWarningStatus *data)
{
  return Rte_Write_pSR_WarningStatus_WarningStatusData(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(UInt8 DLInst, SInt32 ErrorCode)
{
  return Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(DLInst, ErrorCode);
}
Std_ReturnType TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(UInt8 DLInst, SInt32 Status)
{
  return Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(DLInst, Status);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* UclProxyCdd */
      /* UclProxyCdd */



