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
 *          File:  TSC_FastGaugeAdapter.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_FastGaugeAdapter.h"
#include "TSC_FastGaugeAdapter.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_Analog_Tacho_Analog_Tacho(UInt16 *data)
{
  return Rte_Read_rp_Analog_Tacho_Analog_Tacho(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data)
{
  return Rte_Read_rp_Dcm_appStop_AppId(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(UInt16 *data)
{
  return Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_Digital_Tacho_Digital_Tacho(UInt16 *data)
{
  return Rte_Read_rp_Digital_Tacho_Digital_Tacho(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_DispDistanceUnit_DisplayUnit(UInt8 *data)
{
  return Rte_Read_rp_DispDistanceUnit_DisplayUnit(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_DispSpeedA_DispSpeedVal(UInt16 *data)
{
  return Rte_Read_rp_DispSpeedA_DispSpeedVal(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_Display_speed_Value_Digital_Speed_Value(UInt16 *data)
{
  return Rte_Read_rp_Display_speed_Value_Digital_Speed_Value(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(HMIReadySts_Type *data)
{
  return Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_Needle_Transparent_Needle_TR(UInt8 *data)
{
  return Rte_Read_rp_Needle_Transparent_Needle_TR(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(UInt8 *data)
{
  return Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_SubDisplaySpeed_Value_SubDispSpeedVal(UInt16 *data)
{
  return Rte_Read_rp_SubDisplaySpeed_Value_SubDispSpeedVal(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_TC_Unit_Digital_TachoUnit(Boolean *data)
{
  return Rte_Read_rp_TC_Unit_Digital_TachoUnit(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_Tacho_RED_Start_RPM_RED_Start_RPM(UInt8 *data)
{
  return Rte_Read_rp_Tacho_RED_Start_RPM_RED_Start_RPM(data);
}

Std_ReturnType TSC_FastGaugeAdapter_Rte_Read_rp_Tacho_RPM_MAX_REVP_RPM_MAX(UInt8 *data)
{
  return Rte_Read_rp_Tacho_RPM_MAX_REVP_RPM_MAX(data);
}




Std_ReturnType TSC_FastGaugeAdapter_Rte_Write_pp_FastGaugeInfo_FastGaugeInfoData(const SFastGaugeInfo *data)
{
  return Rte_Write_pp_FastGaugeInfo_FastGaugeInfoData(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* FastGaugeAdapter */
      /* FastGaugeAdapter */



