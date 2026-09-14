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
 *          File:  TSC_DemApp.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_DemApp.h"
#include "TSC_DemApp.h"















     /* Client Server Interfaces: */
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_ClearDTC_DemExt_ClearDTC(UInt8 ClientId)
{
  return Rte_Call_rp_CS_DemExt_ClearDTC_DemExt_ClearDTC(ClientId);
}
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
  return Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus(EventId, EventStatus);
}
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_SetOperationCycleState_DemExt_SetOperationCycleState(UInt8 OperationCycleId, Dem_OperationCycleStateType CycleState)
{
  return Rte_Call_rp_CS_DemExt_SetOperationCycleState_DemExt_SetOperationCycleState(OperationCycleId, CycleState);
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







     /* DemApp */
      /* DemApp */



