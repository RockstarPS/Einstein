#include "Std_Types.h"
#include "Rte_DmnMgr_stubs.h"
#if 0
/*from Mode Management*/
Std_ReturnType Rte_Call_rpCSDmnResetReq_ResetRequest(tResetReq uResetReq, tResetReason uResetReason)
{
    return E_OK;
}

/*from Health Logger*/
Std_ReturnType Rte_Call_ppCSHLService_GetLogData(tHL_LogId eLogId, void *pBuffer, uint16 uBufferSize, uint16 *pDataSize)
{
    return E_OK;
}

Std_ReturnType Rte_Call_ppCSHLService_ManageDataLog(tHL_LogOpId eLogOp)
{
    return E_OK;
}

Std_ReturnType Rte_Call_ppCSHLService_StopStartHL(boolean bIsStopHL)
{
    return E_OK;
}

Std_ReturnType Rte_Call_ppCSHLReport_Report(tHL_SwcId eSwcId, tHL_ErrorCode eErrorCode, void *pBuffer, uint16 uBufferSize, uint16 *pDataSize)
{
    return E_OK;
}

Std_ReturnType Rte_Read_rSR_PowerSystemState_PowerSystemStateData(SDkMsgPowerSystemState * pMsg)
{
    return E_OK;
}

Std_ReturnType Rte_Receive_rSR_PowerExtendShutdownTime_PowerExtendShutdownTimeData(SDkMsgPowerExtendShutdownTime *pMsg)
{
    return E_OK;
}
Std_ReturnType Rte_Receive_rSR_PowerKeepSystemAwake_PowerKeepSystemAwakeData(SDkMsgPowerKeepSystemAwake *pMsg)
{
    return E_OK;    
}
Std_ReturnType Rte_Receive_rSR_HealthDomainHeartbeat_HealthDomainHeartbeatData(SDkMsgHealthHeartBeat *pMsg)
{
    return E_OK;    
}
Std_ReturnType Rte_Receive_rSR_HealthDomainFatalError_HealthDomainFatalErrorData(SDkMsgHealthFatalError *pMsg)
{
    return E_OK;    
}
Std_ReturnType Rte_Write_pSR_RTTStatus_RTTStatusData(SDmnCtrlRTCInfo *pMsg)
{
    return E_OK;    
}
Std_ReturnType Rte_Write_pSR_PowerSystemStateReqChange_PowerSystemStateReqChangeData(SDkMsgPowerSystemState *pMsg)
{
    return E_OK;    
}
#endif


#if 0
Std_ReturnType Rte_Call_CanRxSignalValue_CS_GetCanSignal(tRxSignal const RxSignalId,
                                                         uint32          *pDestination1P,
                                                         tRxSignalStatus *pDestination2P)
{
    return E_OK;
}

Std_ReturnType Rte_Call_ppCS_UclInitShutdown_CUclProxyCdd_Impl_Shutdown(void)
{
    return E_OK;
}

Std_ReturnType Rte_Call_ppCS_UclInitShutdown_CUclProxyCdd_Impl_Initialize(void)
{
    return E_OK;
}

Std_ReturnType Rte_Read_pSR_UclTxStatuses_PowerSystemStateReqChange_TxStatus(sint32 *pStatus)
{
    return E_OK;
}

Std_ReturnType Rte_Read_AppModeRequest_SR_RequestedMode(tAppMode *pRequestMode)
{
	return E_OK;
}

void  Rte_Read_AppModeStatus_SR_ActualMode(tAppMode *pActualMode)
{
	;
}

void Rte_Write_AppModeStatus_SR_InhibitLocalSleep(tInhibitLocalSleep uInhibitLocalSleep)
{
	;
}

void Rte_Write_AppModeStatus_SR_ActualMode(tAppMode uActualMode)
{
	;
}

Std_ReturnType AppModeLib_Main(tAppModeManagementContext * const pContext, tAppModeActionsList const * const pAction)
{
    return E_OK;
}
#endif

