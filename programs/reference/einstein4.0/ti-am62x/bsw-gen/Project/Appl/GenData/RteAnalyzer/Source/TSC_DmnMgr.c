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
 *          File:  TSC_DmnMgr.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_DmnMgr.h"
#include "TSC_DmnMgr.h"







Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(SHealthDomainFatalError *data)
{
  return Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(data);
}

Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(SHealthDomainHeartbeat *data)
{
  return Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(data);
}

Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_HealthDumpData_HealthDumpDataData(SHealthDumpData *data)
{
  return Rte_Receive_rSR_HealthDumpData_HealthDumpDataData(data);
}

Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(SHealthDumpHdrInfo *data)
{
  return Rte_Receive_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(data);
}

Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(SPowerExtendShutdownTime *data)
{
  return Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(data);
}

Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(SPowerKeepSystemAwake *data)
{
  return Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(data);
}


Std_ReturnType TSC_DmnMgr_Rte_Read_rSR_PowerSystemState_PowerSystemStateData(SPowerSystemState *data)
{
  return Rte_Read_rSR_PowerSystemState_PowerSystemStateData(data);
}

Std_ReturnType TSC_DmnMgr_Rte_Read_rpSR_DmnInfo_SDmnStatus(SDmnStatus *data)
{
  return Rte_Read_rpSR_DmnInfo_SDmnStatus(data);
}


Std_ReturnType TSC_DmnMgr_Rte_Send_pSR_HealthDumpGetData_HealthDumpGetDataData(const SHealthDumpGetData *data)
{
  return Rte_Send_pSR_HealthDumpGetData_HealthDumpGetDataData(data);
}
Std_ReturnType TSC_DmnMgr_Rte_Send_pSR_HealthDumpGetHdr_HealthDumpGetHdrData(const SHealthDumpGetHdr *data)
{
  return Rte_Send_pSR_HealthDumpGetHdr_HealthDumpGetHdrData(data);
}


Std_ReturnType TSC_DmnMgr_Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(const SPowerSystemStateReqChange *data)
{
  return Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(data);
}

Std_ReturnType TSC_DmnMgr_Rte_Write_ppSR_DmnInfo_SDmnStatus(const SDmnStatus *data)
{
  return Rte_Write_ppSR_DmnInfo_SDmnStatus(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_DmnMgr_Rte_Call_rpCS_UclInitShutdown_Impl_Initialize(void)
{
  return Rte_Call_rpCS_UclInitShutdown_Impl_Initialize();
}
Std_ReturnType TSC_DmnMgr_Rte_Call_rpCS_UclInitShutdown_Impl_Shutdown(void)
{
  return Rte_Call_rpCS_UclInitShutdown_Impl_Shutdown();
}
Std_ReturnType TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep(void)
{
  return Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep();
}
Std_ReturnType TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep(void)
{
  return Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep();
}
Std_ReturnType TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep(void)
{
  return Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep();
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







     /* DmnMgr */
      /* DmnMgr */



