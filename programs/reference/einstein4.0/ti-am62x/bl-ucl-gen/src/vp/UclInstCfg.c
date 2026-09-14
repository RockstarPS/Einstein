#include "Ucl_Types.h"
#include "UclALDebugNull_Impl.h"
#include "UclALOsASR_Impl.h"
#include "UclALPhyMailboxASR_Impl.h"
#include "UclDL_Impl.h"
#include "UclSysDL_Impl.h"
#include "UclSys_Impl.h"

uint8 UCLDLCFG_0_TxWorkgBuffer[5000]; // Assuming chunk size of 2k
uint8 UCLDLCFG_0_RxWorkgBuffer[1024];
uint8 UCLALPHYCFG_0_RxRingBuffer[2048];
uint8 UCLALPHYCFG_0_TxRingBuffer[5000];

SUclALOsASRTimerList UCLALOSCFG_0_SUclALOsASRTimerList[10];

SUclDLAckQueueType UclDL_0_CFG_AckQueue[10];

SUclALDebugNullCfg UclALDebugCfg_0 = {
    0
};

SUclALOsASRCfg UclALOsCfg_0 = {
    .tickResolutionMs = 4,
    .maxTimers = 10,
    .pTimerList = UCLALOSCFG_0_SUclALOsASRTimerList,
};

SUclALPhyMailboxASRCfg UclALPhyCfg_0 = {
    .mailboxBaseAddress =  0x29040000,
	.periodicityMs = 4,
    .pTxRingBuffer = UCLALPHYCFG_0_TxRingBuffer,
    .txRingBufferSize = sizeof(UCLALPHYCFG_0_TxRingBuffer),
    .pRxRingBuffer = UCLALPHYCFG_0_RxRingBuffer,
    .rxRingBufferSize = sizeof(UCLALPHYCFG_0_RxRingBuffer)
};

SUclDLCfg UclDLCfg_0 = {
	.nodeId = 0x00,
    .timerTaskPeriodicityMs = 4,
    .receiveProcessingMode = 0,
    .heartBeatTimerPeriodicityMs = 250,
    .linkDownTimerPeriodicityMs = 1000,
	.pAckQueue = UclDL_0_CFG_AckQueue,///< UCL DL TX  Queue size  is configured as 10
	.maxTxAckQueueSize = sizeof(UclDL_0_CFG_AckQueue)/sizeof(SUclDLAckQueueType),
	.maxAckTimeoutMs = 250,
    .phyRetryTimeIntervalMs = 500,
    .maxPhyRecoveryAttempts = 255,
    .pTxWorkBuffer = UCLDLCFG_0_TxWorkgBuffer,
    .maxTxMsgLength = 1300,
    .txWorkBufferSize = 1400,
    .pRxWorkBuffer = UCLDLCFG_0_RxWorkgBuffer,
    .maxRxMsgLength = 1300,
    .rxWorkBufferSize = 1400,
    .enableSecurity = 0,
    .enableTSC = 0,
    .tscToleranceMs = 0,
    .keyNegotiationDelayMs = 0,
    .securityStateTimeoutMs = 0,
    .encBufferSize = 0,
    .decBufferSize = 0,
    .pEncBuffer = NULL,
    .pDecBuffer = NULL,
    .pCryMsgScratchBuffer = NULL,
    .pTransmitIVBuffer = NULL,
    .pReceiveIVBuffer = NULL,
    .pRS1Buffer = NULL,
    .pRS2Buffer = NULL,
    .pSKBuffer = NULL,
    .pKVVReqBuffer = NULL,
    .pKVVRespBuffer = NULL
};

extern void App_UclFatalError(uint8 DLInst, uint8 Status);
extern void App_UclMsgTransmitStatusFunc(uint8 DLInst, uint16 MsgId,EUclDLAckStatus Status);
extern void App_UclMsgReceivedFunc(uint8 DLInst, EUclDLRxStatus Status,SUclDLMsg *pMsg);
extern void App_UclLinkStatusChangedFunc(uint8 DLInst, EUclDLLinkStatus Status);


SUclSysDLCfg UclSysCfg_0 = 
{
	.pFatalErrorFunc =&App_UclFatalError,
    .pMsgReceivedFunc =&App_UclMsgReceivedFunc,
    .pMsgTransmitStatusFunc =&App_UclMsgTransmitStatusFunc,
	.pLinkStatusChangedFunc =&App_UclLinkStatusChangedFunc,
};


