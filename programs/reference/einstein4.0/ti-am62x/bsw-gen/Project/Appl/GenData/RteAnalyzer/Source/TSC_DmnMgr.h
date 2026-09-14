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
 *          File:  TSC_DmnMgr.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_DmnMgr_Rte_Read_rSR_PowerSystemState_PowerSystemStateData(SPowerSystemState *data);
Std_ReturnType TSC_DmnMgr_Rte_Read_rpSR_DmnInfo_SDmnStatus(SDmnStatus *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_DmnMgr_Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(const SPowerSystemStateReqChange *data);
Std_ReturnType TSC_DmnMgr_Rte_Write_ppSR_DmnInfo_SDmnStatus(const SDmnStatus *data);

/** Sender receiver - Queued - Explicit read */
Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(SHealthDomainFatalError *data);
Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(SHealthDomainHeartbeat *data);
Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_HealthDumpData_HealthDumpDataData(SHealthDumpData *data);
Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_HealthDumpHdrInfo_HealthDumpHdrInfoData(SHealthDumpHdrInfo *data);
Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(SPowerExtendShutdownTime *data);
Std_ReturnType TSC_DmnMgr_Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(SPowerKeepSystemAwake *data);

/** Sender receiver - Queued - Explicit send */
Std_ReturnType TSC_DmnMgr_Rte_Send_pSR_HealthDumpGetData_HealthDumpGetDataData(const SHealthDumpGetData *data);
Std_ReturnType TSC_DmnMgr_Rte_Send_pSR_HealthDumpGetHdr_HealthDumpGetHdrData(const SHealthDumpGetHdr *data);

/** Client server interfaces */
Std_ReturnType TSC_DmnMgr_Rte_Call_rpCS_UclInitShutdown_Impl_Initialize(void);
Std_ReturnType TSC_DmnMgr_Rte_Call_rpCS_UclInitShutdown_Impl_Shutdown(void);
Std_ReturnType TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_CancelSleep(void);
Std_ReturnType TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_ReadytoSleep(void);
Std_ReturnType TSC_DmnMgr_Rte_Call_rp_CS_SleepOperation_CtrlWSS_RequestSleep(void);




