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
 *          File:  TSC_UclProxyCdd.h
 *        Config:  BMW.dpa"
 *   ECU-Project:  EcuInstance
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_EnetRegReq_EnetRegReqData(SEnetRegReq *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_HealthDumpGetData_HealthDumpGetDataData(SHealthDumpGetData *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(SHealthDumpGetHdr *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_IgnState_IgnStateData(SIgnState *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Read_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SPowerSystemStateReqChange *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_DisplayCurrentState_DisplayCurrentStateData(const SDisplayCurrentState *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_EnetRegResp_EnetRegRespData(const SEnetRegResp *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(const SHealthDomainFatalError *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(const SHealthDomainHeartbeat *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(const SHealthDumpHdrInfo *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_HealthEventRecord_HealthEventRecordData(const SHealthEventRecord *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(const SPowerExtendShutdownTime *data);
Std_ReturnType TSC_UclProxyCdd_Rte_Write_pSR_PowerSystemState_PowerSystemStateData(const SPowerSystemState *data);

/** Client server interfaces */
Std_ReturnType TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_ErrorNotification(uint8 DLInst, sint32 ErrorCode);
Std_ReturnType TSC_UclProxyCdd_Rte_Call_rCS_UclSystemCallbacks_LinkStatusChanged(uint8 DLInst, sint32 Status);




