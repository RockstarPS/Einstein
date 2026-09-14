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
 *          File:  TSC_Test_Comp.c
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_Test_Comp.h"
#include "TSC_Test_Comp.h"















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






Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_DisplayCurrentState_DisplayCurrentStateData(SDisplayCurrentState *data)
{
  return Rte_Read_pSR_DisplayCurrentState_DisplayCurrentStateData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_EnetRegResp_EnetRegRespData(SEnetRegResp *data)
{
  return Rte_Read_pSR_EnetRegResp_EnetRegRespData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(SHealthDomainFatalError *data)
{
  return Rte_Read_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(SHealthDomainHeartbeat *data)
{
  return Rte_Read_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(SHealthDumpHdrInfo *data)
{
  return Rte_Read_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_HealthEventRecord_HealthEventRecordData(SHealthEventRecord *data)
{
  return Rte_Read_pSR_HealthEventRecord_HealthEventRecordData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(SPowerExtendShutdownTime *data)
{
  return Rte_Read_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_PowerSystemState_PowerSystemStateData(SPowerSystemState *data)
{
  return Rte_Read_pSR_PowerSystemState_PowerSystemStateData(data);
}




Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_EnetRegReq_EnetRegReqData(const SEnetRegReq *data)
{
  return Rte_Write_rSR_EnetRegReq_EnetRegReqData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_HealthDumpGetData_HealthDumpGetDataData(const SHealthDumpGetData *data)
{
  return Rte_Write_rSR_HealthDumpGetData_HealthDumpGetDataData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(const SHealthDumpGetHdr *data)
{
  return Rte_Write_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_IgnState_IgnStateData(const SIgnState *data)
{
  return Rte_Write_rSR_IgnState_IgnStateData(data);
}

Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(const SPowerSystemStateReqChange *data)
{
  return Rte_Write_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_Test_Comp_Rte_Call_ppCS_UclCmplibCmd_OnCommand(uint8 Cmd)
{
  return Rte_Call_ppCS_UclCmplibCmd_OnCommand(Cmd);
}
Std_ReturnType TSC_Test_Comp_Rte_Call_ppCS_UclInitShutdown_Initialize(void)
{
  return Rte_Call_ppCS_UclInitShutdown_Initialize();
}
Std_ReturnType TSC_Test_Comp_Rte_Call_ppCS_UclInitShutdown_Shutdown(void)
{
  return Rte_Call_ppCS_UclInitShutdown_Shutdown();
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







     /* Test_Comp */
      /* Test_Comp */



