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
 *          File:  TSC_CWarnMsg_Core_Observer.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CWarnMsg_Core_Observer.h"
#include "TSC_CWarnMsg_Core_Observer.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_ChimeRequest_Chime_Request(EChimeID *data)
{
  return Rte_Read_rpCS_ChimeRequest_Chime_Request(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rpCS_GetChimeStatus_Chime_Status(EChimeStatus *data)
{
  return Rte_Read_rpCS_GetChimeStatus_Chime_Status(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryMode_FactoryMode(UInt8 *data)
{
  return Rte_Read_rp_FactoryMode_FactoryMode(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_FactoryModeSts_FactoryModeStatus(UInt8 *data)
{
  return Rte_Read_rp_FactoryModeSts_FactoryModeStatus(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(HMIReadySts_Type *data)
{
  return Rte_Read_rp_HMIReadySts_HMI_ReadyStatus(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(HMI_Screen_Mode *data)
{
  return Rte_Read_rp_HMIScreenMode_HMIScreenMode_Status(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(Hud_Wake_Type *data)
{
  return Rte_Read_rp_HUDWakeupHwSts_WakeType_Hw(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(Hud_Wake_Type *data)
{
  return Rte_Read_rp_HUDWakeupSwSts_WakeType_Int(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(SHudWarningStatus *data)
{
  return Rte_Read_rp_HUDWarningStatus_HudWarningStatusData(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_IllumStartSts_StarterStatus_Out(UInt8 *data)
{
  return Rte_Read_rp_IllumStartSts_StarterStatus_Out(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(UInt8 *data)
{
  return Rte_Read_rp_NVM_HUD_CoordinateFlag_NvmData(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TPMSPayload_Tpms_Payload(Rte_DT_Tpms_Arr_u8_5_0 *data)
{
  return Rte_Read_rp_TPMSPayload_Tpms_Payload(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_TargetSWStatus_TargetSw(Target_SW_Status *data)
{
  return Rte_Read_rp_TargetSWStatus_TargetSw(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Read_rp_WarningStatus_WarningStatusData(SWarningStatus *data)
{
  return Rte_Read_rp_WarningStatus_WarningStatusData(data);
}




Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(const SHudWarningDisplay *data)
{
  return Rte_Write_pp_HUDWarningDisplay_HudWarningDisplayData(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(const STpmsWarningData *data)
{
  return Rte_Write_pp_TPMSWarnPayload_TpmsWarningDataData(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(UInt8 data)
{
  return Rte_Write_pp_WarnHighInt_WarningHighInterrupt_State(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarnInt_WarningInterrupt_State(UInt8 data)
{
  return Rte_Write_pp_WarnInt_WarningInterrupt_State(data);
}

Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Write_pp_WarningDisplay_WarningDisplayData(const SWarningDisplay *data)
{
  return Rte_Write_pp_WarningDisplay_WarningDisplayData(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(WarningId CurrentWarning, ExtWarningData *CurrentWarningStatus)
{
  return Rte_Call_rpActiveWarningStatus_GetActiveWarningStatus(CurrentWarning, CurrentWarningStatus);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(WarningId CurrentWarning, WarningDataS *CurrentWarningStatus)
{
  return Rte_Call_rp_ActiveWarningSts_GetWarningActiveStatus(CurrentWarning, CurrentWarningStatus);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
{
  return Rte_Call_rp_CS_TxCanMdl_TxCan_ClearCanSignalTxConfirmation(SignalId);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
{
  return Rte_Call_rp_CS_TxCanMdl_TxCan_GetCanSignalTxConfirmation(SignalId, pStatus);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
{
  return Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalFromRetentionBuffer(SignalId);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(tTxSignalId SignalId, UInt8 *pTxSignalData)
{
  return Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValue(SignalId, pTxSignalData);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
{
  return Rte_Call_rp_CS_TxCanMdl_TxCan_SetSignalValueU8Arr(SignalId, pTxSignalData, SignalLength);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(WarningId CurWarningId, const Rte_DT_PayloadArr_u8_8_0 *CurWarningDispPayload)
{
  return Rte_Call_rp_UpdateDisplayPayload_SetWarningDisplayedPayload(CurWarningId, CurWarningDispPayload);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(WarningId CurWarningId, WarningDisplayedStatus CurWarningDispStatus)
{
  return Rte_Call_rp_UpdateDisplayStatus_SetWarningDisplayedStatus(CurWarningId, CurWarningDispStatus);
}
Std_ReturnType TSC_CWarnMsg_Core_Observer_Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(WarningId Warning, UInt16 ButtonEvent, UInt8 CursorSt)
{
  return Rte_Call_rp_VoiceOpButtonSts_GetButtonStatus(Warning, ButtonEvent, CursorSt);
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







     /* CWarnMsg_Core_Observer */
      /* CWarnMsg_Core_Observer */



