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
 *          File:  TSC_Test_Comp.h
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
Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_DisplayCurrentState_DisplayCurrentStateData(SDisplayCurrentState *data);
Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_EnetRegResp_EnetRegRespData(SEnetRegResp *data);
Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_HealthDomainFatalError_HealthDomainFatalErrorData(SHealthDomainFatalError *data);
Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(SHealthDomainHeartbeat *data);
Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(SHealthDumpHdrInfo *data);
Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_HealthEventRecord_HealthEventRecordData(SHealthEventRecord *data);
Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(SPowerExtendShutdownTime *data);
Std_ReturnType TSC_Test_Comp_Rte_Read_pSR_PowerSystemState_PowerSystemStateData(SPowerSystemState *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_EnetRegReq_EnetRegReqData(const SEnetRegReq *data);
Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_HealthDumpGetData_HealthDumpGetDataData(const SHealthDumpGetData *data);
Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_HealthDumpGetHdr_HealthDumpGetHdrData(const SHealthDumpGetHdr *data);
Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_IgnState_IgnStateData(const SIgnState *data);
Std_ReturnType TSC_Test_Comp_Rte_Write_rSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(const SPowerSystemStateReqChange *data);

/** Client server interfaces */
Std_ReturnType TSC_Test_Comp_Rte_Call_ppCS_UclCmplibCmd_OnCommand(uint8 Cmd);
Std_ReturnType TSC_Test_Comp_Rte_Call_ppCS_UclInitShutdown_Initialize(void);
Std_ReturnType TSC_Test_Comp_Rte_Call_ppCS_UclInitShutdown_Shutdown(void);




