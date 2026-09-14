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
 *          File:  TSC_SlowGaugeAdapter.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_SlowGaugeAdapter.h"
#include "TSC_SlowGaugeAdapter.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */






Std_ReturnType TSC_SlowGaugeAdapter_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_SlowGaugeAdapter_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_SlowGaugeAdapter_Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data)
{
  return Rte_Read_rp_Dcm_appStop_AppId(data);
}

Std_ReturnType TSC_SlowGaugeAdapter_Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(UInt16 *data)
{
  return Rte_Read_rp_Diag_Digitalspeed_Diag_Digital_Speed_Value(data);
}

Std_ReturnType TSC_SlowGaugeAdapter_Rte_Read_rp_DispDistanceUnit_DisplayUnit(UInt8 *data)
{
  return Rte_Read_rp_DispDistanceUnit_DisplayUnit(data);
}

Std_ReturnType TSC_SlowGaugeAdapter_Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(HMIReadySts_Type *data)
{
  return Rte_Read_rp_HMIReadyState_HMI_ReadyStatus(data);
}




Std_ReturnType TSC_SlowGaugeAdapter_Rte_Write_pp_SlowGaugeInfo_SlowGaugeInfoData(const SSlowGuageInfo *data)
{
  return Rte_Write_pp_SlowGaugeInfo_SlowGaugeInfoData(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* SlowGaugeAdapter */
      /* SlowGaugeAdapter */



