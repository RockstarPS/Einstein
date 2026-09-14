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
 *          File:  TSC_WarnMsg_Core_TmrSupport.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_WarnMsg_Core_TmrSupport.h"
#include "TSC_WarnMsg_Core_TmrSupport.h"















     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */
Std_ReturnType TSC_WarnMsg_Core_TmrSupport_Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, Boolean *IsElapsed)
{
  return Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(hTimer, Timeout, IsElapsed);
}
Std_ReturnType TSC_WarnMsg_Core_TmrSupport_Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(HTimer hTimer)
{
  return Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(hTimer);
}
Std_ReturnType TSC_WarnMsg_Core_TmrSupport_Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(HTimer hTimer, Boolean *IsStarted)
{
  return Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(hTimer, IsStarted);
}
Std_ReturnType TSC_WarnMsg_Core_TmrSupport_Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(HTimer hTimer)
{
  return Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(hTimer);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* WarnMsg_Core_TmrSupport */
      /* WarnMsg_Core_TmrSupport */



