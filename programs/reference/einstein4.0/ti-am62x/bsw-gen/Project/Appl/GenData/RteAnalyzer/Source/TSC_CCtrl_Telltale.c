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
 *          File:  TSC_CCtrl_Telltale.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CCtrl_Telltale.h"
#include "TSC_CCtrl_Telltale.h"








Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpETMBulbTest_CurrentBulbTestStatus(BulbTestStatus *data)
{
  return Rte_Read_rpETMBulbTest_CurrentBulbTestStatus(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpHmiReadyState_HMI_ReadyStatus(HMIReadySts_Type *data)
{
  return Rte_Read_rpHmiReadyState_HMI_ReadyStatus(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck(TFTIgnBlankSts_T *data)
{
  return Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data)
{
  return Rte_Read_rpIgnSubstate_IgnitionSubstate(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTIndex(TT_ENUM_TYPE *data)
{
  return Rte_Read_rpTelltaleIndexStatus_TTIndex(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTStatus(TT_OP_STATES *data)
{
  return Rte_Read_rpTelltaleIndexStatus_TTStatus(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(TT_OP_STATES *data)
{
  return Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data)
{
  return Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data)
{
  return Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data)
{
  return Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rp_EtmSts_CurrentBulbTestStatus(BulbTestStatus *data)
{
  return Rte_Read_rp_EtmSts_CurrentBulbTestStatus(data);
}




Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray(const Rte_DT_TTBlinkArray_0 *data)
{
  return Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes(TTFlashMask data)
{
  return Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(const Rte_DT_TT_OP_Type_0 *data)
{
  return Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(data);
}

Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppTelltaleStatusOP_TelltaleOpArray(const Rte_DT_TT_OP_Type_0 *data)
{
  return Rte_Write_ppTelltaleStatusOP_TelltaleOpArray(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(UInt8 Channel, UInt8 *Status)
{
  return Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(Channel, Status);
}
Std_ReturnType TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(UInt8 InputId, UInt8 *Status)
{
  return Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(InputId, Status);
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







     /* CCtrl_Telltale */
      /* CCtrl_Telltale */



