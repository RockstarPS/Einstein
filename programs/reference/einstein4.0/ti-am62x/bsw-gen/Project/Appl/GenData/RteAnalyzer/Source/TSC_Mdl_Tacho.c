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
 *          File:  TSC_Mdl_Tacho.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Mdl_Tacho.h"
#include "TSC_Mdl_Tacho.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_Country_Code_Func_CountryCode_Func(CountryCode_FuncType *data)
{
  return Rte_Read_rp_Country_Code_Func_CountryCode_Func(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data)
{
  return Rte_Read_rp_Dcm_appStop_AppId(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(UInt8 *data)
{
  return Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_SPD_SP1_In_Status_SP1_In_Status(UInt16 *data)
{
  return Rte_Read_rp_SPD_SP1_In_Status_SP1_In_Status(data);
}




Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Analog_Tacho_Analog_Tacho(UInt16 data)
{
  return Rte_Write_pp_Analog_Tacho_Analog_Tacho(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Digital_Tacho_Digital_Tacho(UInt16 data)
{
  return Rte_Write_pp_Digital_Tacho_Digital_Tacho(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_NE_Out_CalTachoValue(UInt16 data)
{
  return Rte_Write_pp_NE_Out_CalTachoValue(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Needle_Transparent_Needle_TR(UInt8 data)
{
  return Rte_Write_pp_Needle_Transparent_Needle_TR(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Revp_Disp_REVP_DISP(Boolean data)
{
  return Rte_Write_pp_Revp_Disp_REVP_DISP(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_TC_Unit_Digital_TachoUnit(Boolean data)
{
  return Rte_Write_pp_TC_Unit_Digital_TachoUnit(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Tacho_RED_Start_RPM_RED_Start_RPM(UInt8 data)
{
  return Rte_Write_pp_Tacho_RED_Start_RPM_RED_Start_RPM(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Tacho_RPM_MAX_REVP_RPM_MAX(UInt8 data)
{
  return Rte_Write_pp_Tacho_RPM_MAX_REVP_RPM_MAX(data);
}

Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Tacho_Revp_RPM_REVP_RPM(UInt16 data)
{
  return Rte_Write_pp_Tacho_Revp_RPM_REVP_RPM(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(SignalId, pSignalValue, pSignalStatus);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(SignalId, pSignalValue, pSignalStatus, pSignalLength);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(SignalId, pSignalValue);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(SignalId, pSignaValue, pSignalLength);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(SignalId);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(SignalId, pJustRcvdStatus);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
{
  return Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(SignalId, Status);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(UInt8 VariantID, UInt8 *VariantActiveSt)
{
  return Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(VariantID, VariantActiveSt);
}
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_NE1_Notify_NE1_Recieve_Notify_Value(UInt16 NE1_SignalVal)
{
  return Rte_Call_rp_NE1_Notify_NE1_Recieve_Notify_Value(NE1_SignalVal);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* Mdl_Tacho */
      /* Mdl_Tacho */



