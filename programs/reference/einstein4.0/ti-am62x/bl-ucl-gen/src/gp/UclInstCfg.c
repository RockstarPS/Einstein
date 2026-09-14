#include "Ucl_Types.h"
#include "UclALDebugDLT_Impl.h"
#include "UclALOsPOSIX_Impl.h"
#include "UclALPhyMailboxLinux_Impl.h"
#include "UclDL_Impl.h"
#include "UclILRouter_Impl.h"
#include "UclILSched_Impl.h"
#include "UclSys_Impl.h"
#include "UclGen_VmfAdapter.h"
#include  "stddef.h"


uint8 UCLILSCHEDCFG_0_TxWorkgBuffer[1300];
uint8 UCLDLCFG_0_TxWorkgBuffer[1400]; // ~ Approximate offsets to support Ucl Protocol // Added 100 bytes as offset
uint8 UCLDLCFG_0_RxWorkgBuffer[1400 ];  // ~ Approximate offsets to support Ucl Protocol // Added 100 bytes as offset
uint8 UCLALPHYCFG_0_RxRingBuffer[4096];
uint8 UCLALPHYCFG_0_TxRingBuffer[4096];


extern const SUclILMsgDbRx UclILMsgDbRx[];
extern const SUclILMsgDbTx UclILMsgDbTx[];

SUclALOsPOSIXTimerList UCLALOSCFG_0_SUclALOsPOSIXTimerList[20];
SUclALOsPOSIXTaskList UCLALOSCFG_0_SUclALOsPOSIXTaskList[20];
SUclALOsPOSIXMutexList UCLALOSCFG_0_SUclALOsPOSIXMutexList[20];
SUclALOsPOSIXSemList UCLALOSCFG_0_SUclALOsPOSIXSemList[20];

uint8 UCLILSCHEDCFG_0_DL0_PrioQueueLowBuffer[80];
uint8 UCLILSCHEDCFG_0_DL0_PrioQueueMedimumBuffer[80];
uint8 UCLILSCHEDCFG_0_DL0_PrioQueueHighBuffer[10];
uint8 UCLILSCHEDCFG_0_DL0_PrioQueueCriticalBuffer[10];
#define UCLILSCHEDCFG_0_MSG_RETRY_BUFFER_SIZE	180	// Size of this buffer should be greatest of 
													//the sum of all priority queue sizes of all DL instances
uint8 UCLILSCHEDCFG_0_MSG_RETRY_BUFFER[UCLILSCHEDCFG_0_MSG_RETRY_BUFFER_SIZE]; 
uint8 UCLILSCHEDCFG_0_DL0_SUclILSchedDLCfg_DestNodeIds[1] = {0x00};
SUclILSchedDLData UCLILSCHEDCFG_0_DL0_SUclILSchedDLData;
SUclDLAckQueueType UclDL_0_CFG_AckQueue[50];


SUclILSchedDLCfg UCLILSCHEDCFG_0_SUclILSchedDLCfg[1] = {
	{
		.numDestNodes = 1,
		.pDestNodeIds = UCLILSCHEDCFG_0_DL0_SUclILSchedDLCfg_DestNodeIds,
		.prioQueueCfg = {
            {
                .pData = UCLILSCHEDCFG_0_DL0_PrioQueueCriticalBuffer,
                .size = sizeof(UCLILSCHEDCFG_0_DL0_PrioQueueCriticalBuffer),
            },
            {
                .pData = UCLILSCHEDCFG_0_DL0_PrioQueueHighBuffer,
                .size = sizeof(UCLILSCHEDCFG_0_DL0_PrioQueueHighBuffer),
            },
            {
                .pData = UCLILSCHEDCFG_0_DL0_PrioQueueMedimumBuffer,
                .size = sizeof(UCLILSCHEDCFG_0_DL0_PrioQueueMedimumBuffer),
            },
            {
                .pData = UCLILSCHEDCFG_0_DL0_PrioQueueLowBuffer,
                .size = sizeof(UCLILSCHEDCFG_0_DL0_PrioQueueLowBuffer),
            },
		},
        .txWorkBufferSize = sizeof(UCLILSCHEDCFG_0_TxWorkgBuffer),
		.pTxWorkBuffer = UCLILSCHEDCFG_0_TxWorkgBuffer,
		.pData = &UCLILSCHEDCFG_0_DL0_SUclILSchedDLData,
	}
};

SUclALDebugDLTCfg UclALDebugCfg_0 = {
	.logLevel= eUclALDebugLevel_Debug,
};

SUclALOsPOSIXCfg UclALOsCfg_0 = {
	.MaxSem = 20,
	.pSemList = UCLALOSCFG_0_SUclALOsPOSIXSemList,
	.MaxTimers = 20,
	.pTimerList = UCLALOSCFG_0_SUclALOsPOSIXTimerList,
	.MaxTask = 20,
	.pTaskList = UCLALOSCFG_0_SUclALOsPOSIXTaskList,
	.MaxMutex = 20,
	.pMutexList = UCLALOSCFG_0_SUclALOsPOSIXMutexList
};


SUclALPhyMailboxCfg UclALPhyCfg_0 = {
	.mailboxBaseAddress = 0x29040000,
	.periodicityMs = 4,
	.txShmMemPhyAddr = 0x82380000,
	.txShmMemPhySize = 8192,
	.rxShmMemPhyAddr = 0x82382000,
	.rxShmMemPhySize = 8192,
    .pTxRingBuffer = UCLALPHYCFG_0_TxRingBuffer,
    .txRingBufferSize = sizeof(UCLALPHYCFG_0_TxRingBuffer),
    .pRxRingBuffer = UCLALPHYCFG_0_RxRingBuffer,
    .rxRingBufferSize = sizeof(UCLALPHYCFG_0_RxRingBuffer),
};

SUclDLCfg UclDLCfg_0 = {
	.nodeId = 0x01,
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

SUclILRouterCfg UclILRouterCfg_0 = {
	.nodeId = 0x01,
	.numMsgDbRxMsgs = UclILMsgDbRx_Size,
	.pMsgDbRx = UclILMsgDbRx,
	.periodicMsgCheckPeriodicityMs = 8,
	.timerTaskPeriodicityMs = 4
};

SUclILSchedCfg UclILSchedCfg_0 = {
	.nodeId = 0x01,
	.numMsgDbTxMsgs = UclILMsgDbTx_Size,
	.pMsgDbTx = UclILMsgDbTx,
	.timerTaskPeriodicityMs = 4,
	.schedulerPeriodicityMs = 4,
	.periodicMsgPeriodicityMs = 8,
	.pDLCfg = (SUclILSchedDLCfg*)UCLILSCHEDCFG_0_SUclILSchedDLCfg,
	.schedMsgRetryScratchBufferSize = UCLILSCHEDCFG_0_MSG_RETRY_BUFFER_SIZE,
	.pSchedMsgRetryScratchBuffer = UCLILSCHEDCFG_0_MSG_RETRY_BUFFER
};

SUclSysCfg UclSysCfg_0 = {
	0
};
