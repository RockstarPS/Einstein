///---------------------------------------------------------------------------------------------------------------------
///
/// VISTEON CORPORATION CONFIDENTIAL
/// ________________________________
///
/// [2024] Visteon Corporation
/// All Rights Reserved.
///
/// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
/// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
/// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
/// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
/// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
/// under all copyright laws to protect this work as a published work, when appropriate.
/// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
/// without the written authorization of Visteon Corporation.
///
/// Generated on 2022/03/18 05:57:23 by IRAJENDR
///---------------------------------------------------------------------------------------------------------------------

///---------------------------------------------------------------------------------------------------------------------
/// Include files
///---------------------------------------------------------------------------------------------------------------------
#ifdef UCL_DEBUG_ON
  #include <stdarg.h>
  #include <stdio.h>
#endif
#include "Ucl.h"
#include "UclALDebugDLT_Impl.h"
#include "UclALOsPOSIX_Impl.h"
#include "UclDL_Impl.h"
#include "UclALPhyMailboxLinux_Impl.h"
#include "UclILRouter_Impl.h"
#include "UclSys_Impl.h"
#include "UclILSched_Impl.h"

///---------------------------------------------------------------------------------------------------------------------
/// Definitions
///---------------------------------------------------------------------------------------------------------------------
#define UCLALDEBUG_NUM_INSTANCES     (1u)
#define UCLALOS_NUM_INSTANCES     (1u)
#define UCLALPHY_NUM_INSTANCES     (1u)
#define UCLALPHYCBK_NUM_INSTANCES     (1u)
#define UCLDL_NUM_INSTANCES     (1u)
#define UCLDLCBK_NUM_INSTANCES     (2u)
#define UCLILROUTER_NUM_INSTANCES     (1u)
#define UCLILSCHED_NUM_INSTANCES     (1u)
#define UCLSYS_NUM_INSTANCES     (1u)

///---------------------------------------------------------------------------------------------------------------------
/// Instance Configuration
///---------------------------------------------------------------------------------------------------------------------
extern SUclALDebugDLTCfg UclALDebugCfg_0;
extern SUclALOsPOSIXCfg UclALOsCfg_0;
extern SUclALPhyMailboxCfg UclALPhyCfg_0;
extern SUclDLCfg UclDLCfg_0;
extern SUclILRouterCfg UclILRouterCfg_0;
extern SUclILSchedCfg UclILSchedCfg_0;
extern SUclSysCfg UclSysCfg_0;

///---------------------------------------------------------------------------------------------------------------------
/// Interface VTBL definitions
///---------------------------------------------------------------------------------------------------------------------
typedef struct IUclDL_t {
	Ucl_ReturnType (*Initialize)(void);
	Ucl_ReturnType (*Send)(SUclDLMsg *pMsg);
	Ucl_ReturnType (*Shutdown)(void);
	Ucl_ReturnType (*GetStats)(SUclDLStats *pDLStats);
} IUclDL;

typedef struct IUclALPhy_t {
	Ucl_ReturnType (*Initialize)(void);
	Ucl_ReturnType (*Read)(uint8 *pData, uint16 *pSize);
	Ucl_ReturnType (*Shutdown)(void);
	Ucl_ReturnType (*Write)(uint8 *pData, uint16 size);
} IUclALPhy;

typedef struct IUclALOs_t {
	Ucl_ReturnType (*DisableAllInterrupts)(void);
	Ucl_ReturnType (*EnableAllInterrupts)(void);
	uint64 (*GetSystemTimeMs)(void);
	uint32 (*GetSystemTimeResolutionMs)(void);
	Ucl_ReturnType (*Initialize)(void);
	Ucl_ReturnType (*Memcpy)(void *pDest, void *pSrc, uint32 size);
	Ucl_ReturnType (*Memset)(void *pBuffer, uint8 val, uint32 size);
	Ucl_ReturnType (*MutexCreate)(uint32 *pMutexId);
	Ucl_ReturnType (*MutexDestroy)(uint32 mutexId);
	Ucl_ReturnType (*MutexLock)(uint32 mutexId);
	Ucl_ReturnType (*MutexUnlock)(uint32 mutexId);
	Ucl_ReturnType (*SemCreate)(uint32 *pSemId, uint8 value);
	Ucl_ReturnType (*SemDestroy)(uint32 semId);
	Ucl_ReturnType (*SemPost)(uint32 semId);
	Ucl_ReturnType (*SemWait)(uint32 semId);
	Ucl_ReturnType (*Shutdown)(void);
	Ucl_ReturnType (*TaskCreate)(uint32 *pThreadId, TUclOsTaskEntryFunc pFunc, void *pInst);
	Ucl_ReturnType (*TaskDestroy)(uint32 threadId);
	void (*Tick)(void);
	Ucl_ReturnType (*TimerCreate)(uint32 *pTimerId, TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType timerType);
	Ucl_ReturnType (*TimerDestroy)(uint32 timerId);
	Ucl_ReturnType (*TimerStart)(uint32 timerId, uint32 timeout);
	Ucl_ReturnType (*TimerStop)(uint32 timerId);
	Ucl_ReturnType (*Memcmp)(void *pDest, void *pSrc, uint32 size);
	Ucl_ReturnType (*MutexTryLock)(uint32 mutexId);
} IUclALOs;

typedef struct IUclALDebug_t {
	void (*Initialize)(void);
	void (*Log)(EUclALDebugLevel level, char8 *pTag, char8 *pMsg);
	void (*SetLevel)(EUclALDebugLevel level);
	void (*Shutdown)(void);
} IUclALDebug;

typedef struct IUclALCrypto_t {
	Ucl_ReturnType (*CBC_Decrypt)(uint8 *pCipherText, uint8 *pClearText, uint16 size);
	Ucl_ReturnType (*CBC_Done)(void);
	Ucl_ReturnType (*CBC_Encrypt)(uint8 *pClearText, uint8 *pCipherText, uint16 size);
	Ucl_ReturnType (*CBC_Start)(EUclALCryptoKeyType KeyId, uint8 *pIV, uint16 Size);
	Ucl_ReturnType (*CMAC_Done)(uint8 *pResult, uint16 *pSize);
	Ucl_ReturnType (*CMAC_Process)(uint8 *pData, uint16 size);
	Ucl_ReturnType (*CMAC_Start)(EUclALCryptoKeyType keyId);
	Ucl_ReturnType (*Initialize)(void);
	Ucl_ReturnType (*Random)(uint8 *pResult, uint16 size);
	Ucl_ReturnType (*SetSessionKey)(uint8 *pKey, uint16 size);
	Ucl_ReturnType (*Shutdown)(void);
} IUclALCrypto;

typedef struct IUclSys_t {
	Ucl_ReturnType (*Initialize)(void);
	Ucl_ReturnType (*Send)(uint8 dlInst, SUclDLMsg *pMsg);
	Ucl_ReturnType (*Shutdown)(void);
	void (*Task)(void);
} IUclSys;

typedef struct IUclILSched_t {
	Ucl_ReturnType (*Initialize)(void);
	Ucl_ReturnType (*Shutdown)(void);
	void (*NotifyMessageUpdate)(uint16 msgIdx, uint16 duIdx, uint8 *pBuffer, uint16 size);
} IUclILSched;

typedef struct IUclILRouter_t {
	Ucl_ReturnType (*Initialize)(void);
	Ucl_ReturnType (*Shutdown)(void);
} IUclILRouter;

typedef struct IUclTest_t {
	void (*Initialize)(void);
	void (*Shutdown)(void);
	void (*Start)(void);
	void (*Stop)(void);
} IUclTest;

typedef struct IUclDLCbk_t {
	void (*FatalError)(EUclDLError status);
	void (*LinkStatusChanged)(EUclDLLinkStatus status);
	void (*MsgReceived)(EUclDLRxStatus status, SUclDLMsg *pMsg);
	void (*MsgTransmitStatus)(uint16 msgId, EUclDLAckStatus status);
} IUclDLCbk;

typedef struct IUclALPhyCbk_t {
	void (*FatalError)(sint32 status);
	void (*PeerReadyStatusChanged)(EUclALPhyPeerReadyStatus status);
	void (*ReceiveDataAvailable)(void);
} IUclALPhyCbk;

typedef struct IUclALHwCbk_t {
	void (*TransmitComplete)(void);
	void (*ReceiveComplete)(void);
	void (*GpioChanged)(uint32 gpioNum);
} IUclALHwCbk;

typedef struct IUclILStream_t {
	Ucl_ReturnType (*Initialize)(void);
	Ucl_ReturnType (*Shutdown)(void);
	sint32 (*Open)(uint8 chId, uint16 flags);
	sint32 (*Close)(sint32 fd);
	sint32 (*Read)(sint32 fd, uint8 *pBuffer, uint32 size);
	sint32 (*Write)(sint32 fd, uint8 *pBuffer, uint32 size);
	sint32 (*Poll)(sint32 fd, uint32 timeout);
	sint32 (*PollEx)(sint32 fd, uint8 reqId, uint32 *pStatus, uint32 timeout);
	sint32 (*WriteEx)(sint32 fd, uint8 reqId, uint8 *pBuffer, uint32 size);
	sint32 (*Ioctl)(sint32 fd, uint16 request, void *pData, uint16 size);
} IUclILStream;


///---------------------------------------------------------------------------------------------------------------------
/// Instance Definitions
///---------------------------------------------------------------------------------------------------------------------
static uint8 UclSysInst_0_IUclALDebug[1] = {0};
static uint8 UclSysInst_0_IUclALOs[1] = {0};
static uint8 UclSysInst_0_IUclILRouter[1] = {0};
static uint8 UclSysInst_0_IUclILSched[1] = {0};
static SUclSysInst UclSysInst_0 = {
	.pCfg = &UclSysCfg_0,
	.numIUclALDebug = 1,
	.pIUclALDebug = &UclSysInst_0_IUclALDebug[0],
	.numIUclALOs = 1,
	.pIUclALOs = &UclSysInst_0_IUclALOs[0],
	.numIUclILRouter = 1,
	.pIUclILRouter = &UclSysInst_0_IUclILRouter[0],
	.numIUclILSched = 1,
	.pIUclILSched = &UclSysInst_0_IUclILSched[0],
};

static SUclALOsPOSIXInst UclALOsInst_0 = {
	.pCfg = &UclALOsCfg_0,
};

static SUclALDebugDLTInst UclALDebugInst_0 = {
	.pCfg = &UclALDebugCfg_0,
};

static uint8 UclDLInst_0_IUclALPhy[1] = {0};
static uint8 UclDLInst_0_IUclDLCbk[2] = {0,1};
static SUclDLInst UclDLInst_0 = {
	.pCfg = &UclDLCfg_0,
	.numIUclALPhy = 1,
	.pIUclALPhy = &UclDLInst_0_IUclALPhy[0],
	.numIUclDLCbk = 2,
	.pIUclDLCbk = &UclDLInst_0_IUclDLCbk[0],
};

static uint8 UclALPhyInst_0_IUclALPhyCbk[1] = {0};
static SUclALPhyMailboxLinuxInst UclALPhyInst_0 = {
	.pCfg = &UclALPhyCfg_0,
	.numIUclALPhyCbk = 1,
	.pIUclALPhyCbk = &UclALPhyInst_0_IUclALPhyCbk[0],
};

static SUclILRouterInst UclILRouterInst_0 = {
	.pCfg = &UclILRouterCfg_0,
};

static uint8 UclILSchedInst_0_IUclDL[1] = {0};
static SUclILSchedInst UclILSchedInst_0 = {
	.pCfg = &UclILSchedCfg_0,
	.numIUclDL = 1,
	.pIUclDL = &UclILSchedInst_0_IUclDL[0],
};


///---------------------------------------------------------------------------------------------------------------------
/// Instance Links
///---------------------------------------------------------------------------------------------------------------------
static Ucl_ReturnType UclSysInst_0_DummyMain_IUclSys_Initialize(void) {return UclSys_Impl_IUclSys_Initialize(&UclSysInst_0, (0)); }
static Ucl_ReturnType UclSysInst_0_DummyMain_IUclSys_Send(uint8 dlInst, SUclDLMsg *pMsg) { return UclSys_Impl_IUclSys_Send(&UclSysInst_0, (0), dlInst, pMsg); }
static Ucl_ReturnType UclSysInst_0_DummyMain_IUclSys_Shutdown(void) {return UclSys_Impl_IUclSys_Shutdown(&UclSysInst_0, (0)); }
static void UclSysInst_0_DummyMain_IUclSys_Task(void) {UclSys_Impl_IUclSys_Task(&UclSysInst_0, (0)); }

static const IUclSys UclSysInst_0_DummyMain_IUclSys = {
	&UclSysInst_0_DummyMain_IUclSys_Initialize,
	&UclSysInst_0_DummyMain_IUclSys_Send,
	&UclSysInst_0_DummyMain_IUclSys_Shutdown,
	&UclSysInst_0_DummyMain_IUclSys_Task,
};

static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_DisableAllInterrupts(void) {return UclALOsPOSIX_Impl_IUclALOs_DisableAllInterrupts(&UclALOsInst_0, (0)); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_EnableAllInterrupts(void) {return UclALOsPOSIX_Impl_IUclALOs_EnableAllInterrupts(&UclALOsInst_0, (0)); }
static uint64 UclALOsInst_0_UclSysInst_0_IUclALOs_GetSystemTimeMs(void) {return UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeMs(&UclALOsInst_0, (0)); }
static uint32 UclALOsInst_0_UclSysInst_0_IUclALOs_GetSystemTimeResolutionMs(void) {return UclALOsPOSIX_Impl_IUclALOs_GetSystemTimeResolutionMs(&UclALOsInst_0, (0)); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_Initialize(void) {return UclALOsPOSIX_Impl_IUclALOs_Initialize(&UclALOsInst_0, (0)); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_Memcpy(void *pDest, void *pSrc, uint32 size) { return UclALOsPOSIX_Impl_IUclALOs_Memcpy(&UclALOsInst_0, (0), pDest, pSrc, size); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_Memset(void *pBuffer, uint8 val, uint32 size) { return UclALOsPOSIX_Impl_IUclALOs_Memset(&UclALOsInst_0, (0), pBuffer, val, size); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_MutexCreate(uint32 *pMutexId) { return UclALOsPOSIX_Impl_IUclALOs_MutexCreate(&UclALOsInst_0, (0), pMutexId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_MutexDestroy(uint32 mutexId) { return UclALOsPOSIX_Impl_IUclALOs_MutexDestroy(&UclALOsInst_0, (0), mutexId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_MutexLock(uint32 mutexId) { return UclALOsPOSIX_Impl_IUclALOs_MutexLock(&UclALOsInst_0, (0), mutexId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_MutexUnlock(uint32 mutexId) { return UclALOsPOSIX_Impl_IUclALOs_MutexUnlock(&UclALOsInst_0, (0), mutexId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_SemCreate(uint32 *pSemId, uint8 value) { return UclALOsPOSIX_Impl_IUclALOs_SemCreate(&UclALOsInst_0, (0), pSemId, value); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_SemDestroy(uint32 semId) { return UclALOsPOSIX_Impl_IUclALOs_SemDestroy(&UclALOsInst_0, (0), semId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_SemPost(uint32 semId) { return UclALOsPOSIX_Impl_IUclALOs_SemPost(&UclALOsInst_0, (0), semId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_SemWait(uint32 semId) { return UclALOsPOSIX_Impl_IUclALOs_SemWait(&UclALOsInst_0, (0), semId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_Shutdown(void) {return UclALOsPOSIX_Impl_IUclALOs_Shutdown(&UclALOsInst_0, (0)); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_TaskCreate(uint32 *pThreadId, TUclOsTaskEntryFunc pFunc, void *pInst) { return UclALOsPOSIX_Impl_IUclALOs_TaskCreate(&UclALOsInst_0, (0), pThreadId, pFunc, pInst); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_TaskDestroy(uint32 threadId) { return UclALOsPOSIX_Impl_IUclALOs_TaskDestroy(&UclALOsInst_0, (0), threadId); }
static void UclALOsInst_0_UclSysInst_0_IUclALOs_Tick(void) {UclALOsPOSIX_Impl_IUclALOs_Tick(&UclALOsInst_0, (0)); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_TimerCreate(uint32 *pTimerId, TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType timerType) { return UclALOsPOSIX_Impl_IUclALOs_TimerCreate(&UclALOsInst_0, (0), pTimerId, pFunc, pData, timerType); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_TimerDestroy(uint32 timerId) { return UclALOsPOSIX_Impl_IUclALOs_TimerDestroy(&UclALOsInst_0, (0), timerId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_TimerStart(uint32 timerId, uint32 timeout) { return UclALOsPOSIX_Impl_IUclALOs_TimerStart(&UclALOsInst_0, (0), timerId, timeout); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_TimerStop(uint32 timerId) { return UclALOsPOSIX_Impl_IUclALOs_TimerStop(&UclALOsInst_0, (0), timerId); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_Memcmp(void *pDest, void *pSrc, uint32 size) { return UclALOsPOSIX_Impl_IUclALOs_Memcmp(&UclALOsInst_0, (0), pDest, pSrc, size); }
static Ucl_ReturnType UclALOsInst_0_UclSysInst_0_IUclALOs_MutexTryLock(uint32 mutexId) { return UclALOsPOSIX_Impl_IUclALOs_MutexTryLock(&UclALOsInst_0, (0), mutexId); }

static const IUclALOs UclALOsInst_0_UclSysInst_0_IUclALOs = {
	&UclALOsInst_0_UclSysInst_0_IUclALOs_DisableAllInterrupts,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_EnableAllInterrupts,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_GetSystemTimeMs,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_GetSystemTimeResolutionMs,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_Initialize,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_Memcpy,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_Memset,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_MutexCreate,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_MutexDestroy,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_MutexLock,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_MutexUnlock,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_SemCreate,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_SemDestroy,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_SemPost,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_SemWait,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_Shutdown,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_TaskCreate,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_TaskDestroy,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_Tick,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_TimerCreate,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_TimerDestroy,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_TimerStart,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_TimerStop,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_Memcmp,
	&UclALOsInst_0_UclSysInst_0_IUclALOs_MutexTryLock,
};

static Ucl_ReturnType UclILRouterInst_0_UclSysInst_0_IUclILRouter_Initialize(void) {return UclILRouter_Impl_IUclILRouter_Initialize(&UclILRouterInst_0, (0)); }
static Ucl_ReturnType UclILRouterInst_0_UclSysInst_0_IUclILRouter_Shutdown(void) {return UclILRouter_Impl_IUclILRouter_Shutdown(&UclILRouterInst_0, (0)); }

static const IUclILRouter UclILRouterInst_0_UclSysInst_0_IUclILRouter = {
	&UclILRouterInst_0_UclSysInst_0_IUclILRouter_Initialize,
	&UclILRouterInst_0_UclSysInst_0_IUclILRouter_Shutdown,
};

static Ucl_ReturnType UclILSchedInst_0_UclSysInst_0_IUclILSched_Initialize(void) {return UclILSched_Impl_IUclILSched_Initialize(&UclILSchedInst_0, (0)); }
static Ucl_ReturnType UclILSchedInst_0_UclSysInst_0_IUclILSched_Shutdown(void) {return UclILSched_Impl_IUclILSched_Shutdown(&UclILSchedInst_0, (0)); }
static void UclILSchedInst_0_UclSysInst_0_IUclILSched_NotifyMessageUpdate(uint16 msgIdx, uint16 duIdx, uint8 *pBuffer, uint16 size) { UclILSched_Impl_IUclILSched_NotifyMessageUpdate(&UclILSchedInst_0, (0), msgIdx, duIdx, pBuffer, size); }

static const IUclILSched UclILSchedInst_0_UclSysInst_0_IUclILSched = {
	&UclILSchedInst_0_UclSysInst_0_IUclILSched_Initialize,
	&UclILSchedInst_0_UclSysInst_0_IUclILSched_Shutdown,
	&UclILSchedInst_0_UclSysInst_0_IUclILSched_NotifyMessageUpdate,
};

static Ucl_ReturnType UclDLInst_0_UclILSchedInst_0_IUclDL_Initialize(void) {return UclDL_Impl_IUclDL_Initialize(&UclDLInst_0, (0)); }
static Ucl_ReturnType UclDLInst_0_UclILSchedInst_0_IUclDL_Send(SUclDLMsg *pMsg) { return UclDL_Impl_IUclDL_Send(&UclDLInst_0, (0), pMsg); }
static Ucl_ReturnType UclDLInst_0_UclILSchedInst_0_IUclDL_Shutdown(void) {return UclDL_Impl_IUclDL_Shutdown(&UclDLInst_0, (0)); }
static Ucl_ReturnType UclDLInst_0_UclILSchedInst_0_IUclDL_GetStats(SUclDLStats *pDLStats) { return UclDL_Impl_IUclDL_GetStats(&UclDLInst_0, (0), pDLStats); }

static const IUclDL UclDLInst_0_UclILSchedInst_0_IUclDL = {
	&UclDLInst_0_UclILSchedInst_0_IUclDL_Initialize,
	&UclDLInst_0_UclILSchedInst_0_IUclDL_Send,
	&UclDLInst_0_UclILSchedInst_0_IUclDL_Shutdown,
	&UclDLInst_0_UclILSchedInst_0_IUclDL_GetStats,
};

static void UclILSchedInst_0_UclDLInst_0_IUclDLCbk_FatalError(EUclDLError status) { UclILSched_Impl_IUclDLCbk_FatalError(&UclILSchedInst_0, (0), status); }
static void UclILSchedInst_0_UclDLInst_0_IUclDLCbk_LinkStatusChanged(EUclDLLinkStatus status) { UclILSched_Impl_IUclDLCbk_LinkStatusChanged(&UclILSchedInst_0, (0), status); }
static void UclILSchedInst_0_UclDLInst_0_IUclDLCbk_MsgReceived(EUclDLRxStatus status, SUclDLMsg *pMsg) { UclILSched_Impl_IUclDLCbk_MsgReceived(&UclILSchedInst_0, (0), status, pMsg); }
static void UclILSchedInst_0_UclDLInst_0_IUclDLCbk_MsgTransmitStatus(uint16 msgId, EUclDLAckStatus status) { UclILSched_Impl_IUclDLCbk_MsgTransmitStatus(&UclILSchedInst_0, (0), msgId, status); }

static const IUclDLCbk UclILSchedInst_0_UclDLInst_0_IUclDLCbk = {
	&UclILSchedInst_0_UclDLInst_0_IUclDLCbk_FatalError,
	&UclILSchedInst_0_UclDLInst_0_IUclDLCbk_LinkStatusChanged,
	&UclILSchedInst_0_UclDLInst_0_IUclDLCbk_MsgReceived,
	&UclILSchedInst_0_UclDLInst_0_IUclDLCbk_MsgTransmitStatus,
};

static void UclILRouterInst_0_UclDLInst_0_IUclDLCbk_FatalError(EUclDLError status) { UclILRouter_Impl_IUclDLCbk_FatalError(&UclILRouterInst_0, (0), status); }
static void UclILRouterInst_0_UclDLInst_0_IUclDLCbk_LinkStatusChanged(EUclDLLinkStatus status) { UclILRouter_Impl_IUclDLCbk_LinkStatusChanged(&UclILRouterInst_0, (0), status); }
static void UclILRouterInst_0_UclDLInst_0_IUclDLCbk_MsgReceived(EUclDLRxStatus status, SUclDLMsg *pMsg) { UclILRouter_Impl_IUclDLCbk_MsgReceived(&UclILRouterInst_0, (0), status, pMsg); }
static void UclILRouterInst_0_UclDLInst_0_IUclDLCbk_MsgTransmitStatus(uint16 msgId, EUclDLAckStatus status) { UclILRouter_Impl_IUclDLCbk_MsgTransmitStatus(&UclILRouterInst_0, (0), msgId, status); }

static const IUclDLCbk UclILRouterInst_0_UclDLInst_0_IUclDLCbk = {
	&UclILRouterInst_0_UclDLInst_0_IUclDLCbk_FatalError,
	&UclILRouterInst_0_UclDLInst_0_IUclDLCbk_LinkStatusChanged,
	&UclILRouterInst_0_UclDLInst_0_IUclDLCbk_MsgReceived,
	&UclILRouterInst_0_UclDLInst_0_IUclDLCbk_MsgTransmitStatus,
};

static void UclALDebugInst_0_UclSysInst_0_IUclALDebug_Initialize(void) {UclALDebugDLT_Impl_IUclALDebug_Initialize(&UclALDebugInst_0, (0)); }
static void UclALDebugInst_0_UclSysInst_0_IUclALDebug_Log(EUclALDebugLevel level, char8 *pTag, char8 *pMsg) { UclALDebugDLT_Impl_IUclALDebug_Log(&UclALDebugInst_0, (0), level, pTag, pMsg); }
static void UclALDebugInst_0_UclSysInst_0_IUclALDebug_SetLevel(EUclALDebugLevel level) { UclALDebugDLT_Impl_IUclALDebug_SetLevel(&UclALDebugInst_0, (0), level); }
static void UclALDebugInst_0_UclSysInst_0_IUclALDebug_Shutdown(void) {UclALDebugDLT_Impl_IUclALDebug_Shutdown(&UclALDebugInst_0, (0)); }

static const IUclALDebug UclALDebugInst_0_UclSysInst_0_IUclALDebug = {
	&UclALDebugInst_0_UclSysInst_0_IUclALDebug_Initialize,
	&UclALDebugInst_0_UclSysInst_0_IUclALDebug_Log,
	&UclALDebugInst_0_UclSysInst_0_IUclALDebug_SetLevel,
	&UclALDebugInst_0_UclSysInst_0_IUclALDebug_Shutdown,
};

static void UclDLInst_0_UclALPhyInst_0_IUclALPhyCbk_FatalError(sint32 status) { UclDL_Impl_IUclALPhyCbk_FatalError(&UclDLInst_0, (0), status); }
static void UclDLInst_0_UclALPhyInst_0_IUclALPhyCbk_PeerReadyStatusChanged(EUclALPhyPeerReadyStatus status) { UclDL_Impl_IUclALPhyCbk_PeerReadyStatusChanged(&UclDLInst_0, (0), status); }
static void UclDLInst_0_UclALPhyInst_0_IUclALPhyCbk_ReceiveDataAvailable(void) {UclDL_Impl_IUclALPhyCbk_ReceiveDataAvailable(&UclDLInst_0, (0)); }

static const IUclALPhyCbk UclDLInst_0_UclALPhyInst_0_IUclALPhyCbk = {
	&UclDLInst_0_UclALPhyInst_0_IUclALPhyCbk_FatalError,
	&UclDLInst_0_UclALPhyInst_0_IUclALPhyCbk_PeerReadyStatusChanged,
	&UclDLInst_0_UclALPhyInst_0_IUclALPhyCbk_ReceiveDataAvailable,
};

static Ucl_ReturnType UclALPhyInst_0_UclDLInst_0_IUclALPhy_Initialize(void) {return UclALPhyMailboxLinux_Impl_IUclALPhy_Initialize(&UclALPhyInst_0, (0)); }
static Ucl_ReturnType UclALPhyInst_0_UclDLInst_0_IUclALPhy_Read(uint8 *pData, uint16 *pSize) { return UclALPhyMailboxLinux_Impl_IUclALPhy_Read(&UclALPhyInst_0, (0), pData, pSize); }
static Ucl_ReturnType UclALPhyInst_0_UclDLInst_0_IUclALPhy_Shutdown(void) {return UclALPhyMailboxLinux_Impl_IUclALPhy_Shutdown(&UclALPhyInst_0, (0)); }
static Ucl_ReturnType UclALPhyInst_0_UclDLInst_0_IUclALPhy_Write(uint8 *pData, uint16 size) { return UclALPhyMailboxLinux_Impl_IUclALPhy_Write(&UclALPhyInst_0, (0), pData, size); }

static const IUclALPhy UclALPhyInst_0_UclDLInst_0_IUclALPhy = {
	&UclALPhyInst_0_UclDLInst_0_IUclALPhy_Initialize,
	&UclALPhyInst_0_UclDLInst_0_IUclALPhy_Read,
	&UclALPhyInst_0_UclDLInst_0_IUclALPhy_Shutdown,
	&UclALPhyInst_0_UclDLInst_0_IUclALPhy_Write,
};


///---------------------------------------------------------------------------------------------------------------------
/// Instance Array
///---------------------------------------------------------------------------------------------------------------------
const IUclALDebug *UclALDebugObjs[1] = {
	&UclALDebugInst_0_UclSysInst_0_IUclALDebug,
};

const IUclALOs *UclALOsObjs[1] = {
	&UclALOsInst_0_UclSysInst_0_IUclALOs,
};

const IUclALPhy *UclALPhyObjs[1] = {
	&UclALPhyInst_0_UclDLInst_0_IUclALPhy,
};

const IUclALPhyCbk *UclALPhyCbkObjs[1] = {
	&UclDLInst_0_UclALPhyInst_0_IUclALPhyCbk,
};

const IUclDL *UclDLObjs[1] = {
	&UclDLInst_0_UclILSchedInst_0_IUclDL,
};

const IUclDLCbk *UclDLCbkObjs[2] = {
	&UclILSchedInst_0_UclDLInst_0_IUclDLCbk,
	&UclILRouterInst_0_UclDLInst_0_IUclDLCbk,
};

const IUclILRouter *UclILRouterObjs[1] = {
	&UclILRouterInst_0_UclSysInst_0_IUclILRouter,
};

const IUclILSched *UclILSchedObjs[1] = {
	&UclILSchedInst_0_UclSysInst_0_IUclILSched,
};

const IUclSys *UclSysObjs[1] = {
	&UclSysInst_0_DummyMain_IUclSys,
};


///---------------------------------------------------------------------------------------------------------------------
/// Wrapper Functions
///---------------------------------------------------------------------------------------------------------------------
Ucl_ReturnType UclDL_Initialize(uint8 instId) {
#ifdef UCLDL_NUM_INSTANCES
	return UclDLObjs[instId]->Initialize();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclDL_Send(uint8 instId, SUclDLMsg *pMsg) { 
#ifdef UCLDL_NUM_INSTANCES
	return UclDLObjs[instId]->Send(pMsg);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclDL_Shutdown(uint8 instId) {
#ifdef UCLDL_NUM_INSTANCES
	return UclDLObjs[instId]->Shutdown();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclDL_GetStats(uint8 instId, SUclDLStats *pDLStats) { 
#ifdef UCLDL_NUM_INSTANCES
	return UclDLObjs[instId]->GetStats(pDLStats);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALPhy_Initialize(uint8 instId) {
#ifdef UCLALPHY_NUM_INSTANCES
	return UclALPhyObjs[instId]->Initialize();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALPhy_Read(uint8 instId, uint8 *pData, uint16 *pSize) { 
#ifdef UCLALPHY_NUM_INSTANCES
	return UclALPhyObjs[instId]->Read(pData, pSize);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALPhy_Shutdown(uint8 instId) {
#ifdef UCLALPHY_NUM_INSTANCES
	return UclALPhyObjs[instId]->Shutdown();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALPhy_Write(uint8 instId, uint8 *pData, uint16 size) { 
#ifdef UCLALPHY_NUM_INSTANCES
	return UclALPhyObjs[instId]->Write(pData, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_DisableAllInterrupts(uint8 instId) {
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->DisableAllInterrupts();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_EnableAllInterrupts(uint8 instId) {
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->EnableAllInterrupts();
#else
	return UCL_E_NOK;
#endif
}
uint64 UclALOs_GetSystemTimeMs(uint8 instId) {
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->GetSystemTimeMs();
#else
	return UCL_E_NOK;
#endif
}
uint32 UclALOs_GetSystemTimeResolutionMs(uint8 instId) {
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->GetSystemTimeResolutionMs();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_Initialize(uint8 instId) {
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->Initialize();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_Memcpy(uint8 instId, void *pDest, void *pSrc, uint32 size) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->Memcpy(pDest, pSrc, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_Memset(uint8 instId, void *pBuffer, uint8 val, uint32 size) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->Memset(pBuffer, val, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_MutexCreate(uint8 instId, uint32 *pMutexId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->MutexCreate(pMutexId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_MutexDestroy(uint8 instId, uint32 mutexId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->MutexDestroy(mutexId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_MutexLock(uint8 instId, uint32 mutexId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->MutexLock(mutexId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_MutexUnlock(uint8 instId, uint32 mutexId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->MutexUnlock(mutexId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_SemCreate(uint8 instId, uint32 *pSemId, uint8 value) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->SemCreate(pSemId, value);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_SemDestroy(uint8 instId, uint32 semId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->SemDestroy(semId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_SemPost(uint8 instId, uint32 semId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->SemPost(semId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_SemWait(uint8 instId, uint32 semId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->SemWait(semId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_Shutdown(uint8 instId) {
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->Shutdown();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_TaskCreate(uint8 instId, uint32 *pThreadId, TUclOsTaskEntryFunc pFunc, void *pInst) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->TaskCreate(pThreadId, pFunc, pInst);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_TaskDestroy(uint8 instId, uint32 threadId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->TaskDestroy(threadId);
#else
	return UCL_E_NOK;
#endif
}
void UclALOs_Tick(uint8 instId) {
#ifdef UCLALOS_NUM_INSTANCES
	UclALOsObjs[instId]->Tick();
#else
	return;
#endif
}
Ucl_ReturnType UclALOs_TimerCreate(uint8 instId, uint32 *pTimerId, TUclOsTaskEntryFunc pFunc, void *pData, EUclOsTimerType timerType) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->TimerCreate(pTimerId, pFunc, pData, timerType);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_TimerDestroy(uint8 instId, uint32 timerId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->TimerDestroy(timerId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_TimerStart(uint8 instId, uint32 timerId, uint32 timeout) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->TimerStart(timerId, timeout);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_TimerStop(uint8 instId, uint32 timerId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->TimerStop(timerId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_Memcmp(uint8 instId, void *pDest, void *pSrc, uint32 size) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->Memcmp(pDest, pSrc, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALOs_MutexTryLock(uint8 instId, uint32 mutexId) { 
#ifdef UCLALOS_NUM_INSTANCES
	return UclALOsObjs[instId]->MutexTryLock(mutexId);
#else
	return UCL_E_NOK;
#endif
}
void UclALDebug_Initialize(uint8 instId) {
#ifdef UCLALDEBUG_NUM_INSTANCES
	UclALDebugObjs[instId]->Initialize();
#else
	return;
#endif
}
void UclALDebug_Log(uint8 InstId, EUclALDebugLevel Level, const char8 *tag, const char8 * fmt, ...)
{
#ifdef UCLALDEBUG_NUM_INSTANCES
#ifdef UCL_DEBUG_ON
    char8 buffer[256];
    va_list argptr;
    va_start(argptr, fmt);
    vsnprintf(buffer, 256, fmt, argptr);
    va_end(argptr);
    UclALDebugObjs[InstId]->Log(Level, (char8 *) tag, buffer);
#endif
#endif
}
void UclALDebug_SetLevel(uint8 instId, EUclALDebugLevel level) { 
#ifdef UCLALDEBUG_NUM_INSTANCES
	UclALDebugObjs[instId]->SetLevel(level);
#else
	return;
#endif
}
void UclALDebug_Shutdown(uint8 instId) {
#ifdef UCLALDEBUG_NUM_INSTANCES
	UclALDebugObjs[instId]->Shutdown();
#else
	return;
#endif
}
Ucl_ReturnType UclALCrypto_CBC_Decrypt(uint8 instId, uint8 *pCipherText, uint8 *pClearText, uint16 size) { 
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->CBC_Decrypt(pCipherText, pClearText, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_CBC_Done(uint8 instId) {
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->CBC_Done();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_CBC_Encrypt(uint8 instId, uint8 *pClearText, uint8 *pCipherText, uint16 size) { 
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->CBC_Encrypt(pClearText, pCipherText, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_CBC_Start(uint8 instId, EUclALCryptoKeyType KeyId, uint8 *pIV, uint16 Size) { 
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->CBC_Start(KeyId, pIV, Size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_CMAC_Done(uint8 instId, uint8 *pResult, uint16 *pSize) { 
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->CMAC_Done(pResult, pSize);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_CMAC_Process(uint8 instId, uint8 *pData, uint16 size) { 
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->CMAC_Process(pData, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_CMAC_Start(uint8 instId, EUclALCryptoKeyType keyId) { 
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->CMAC_Start(keyId);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_Initialize(uint8 instId) {
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->Initialize();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_Random(uint8 instId, uint8 *pResult, uint16 size) { 
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->Random(pResult, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_SetSessionKey(uint8 instId, uint8 *pKey, uint16 size) { 
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->SetSessionKey(pKey, size);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclALCrypto_Shutdown(uint8 instId) {
#ifdef UCLALCRYPTO_NUM_INSTANCES
	return UclALCryptoObjs[instId]->Shutdown();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclSys_Initialize(uint8 instId) {
#ifdef UCLSYS_NUM_INSTANCES
	return UclSysObjs[instId]->Initialize();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclSys_Send(uint8 instId, uint8 dlInst, SUclDLMsg *pMsg) { 
#ifdef UCLSYS_NUM_INSTANCES
	return UclSysObjs[instId]->Send(dlInst, pMsg);
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclSys_Shutdown(uint8 instId) {
#ifdef UCLSYS_NUM_INSTANCES
	return UclSysObjs[instId]->Shutdown();
#else
	return UCL_E_NOK;
#endif
}
void UclSys_Task(uint8 instId) {
#ifdef UCLSYS_NUM_INSTANCES
	UclSysObjs[instId]->Task();
#else
	return;
#endif
}
Ucl_ReturnType UclILSched_Initialize(uint8 instId) {
#ifdef UCLILSCHED_NUM_INSTANCES
	return UclILSchedObjs[instId]->Initialize();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclILSched_Shutdown(uint8 instId) {
#ifdef UCLILSCHED_NUM_INSTANCES
	return UclILSchedObjs[instId]->Shutdown();
#else
	return UCL_E_NOK;
#endif
}
void UclILSched_NotifyMessageUpdate(uint8 instId, uint16 msgIdx, uint16 duIdx, uint8 *pBuffer, uint16 size) { 
#ifdef UCLILSCHED_NUM_INSTANCES
	UclILSchedObjs[instId]->NotifyMessageUpdate(msgIdx, duIdx, pBuffer, size);
#else
	return;
#endif
}
Ucl_ReturnType UclILRouter_Initialize(uint8 instId) {
#ifdef UCLILROUTER_NUM_INSTANCES
	return UclILRouterObjs[instId]->Initialize();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclILRouter_Shutdown(uint8 instId) {
#ifdef UCLILROUTER_NUM_INSTANCES
	return UclILRouterObjs[instId]->Shutdown();
#else
	return UCL_E_NOK;
#endif
}
void UclTest_Initialize(uint8 instId) {
#ifdef UCLTEST_NUM_INSTANCES
	UclTestObjs[instId]->Initialize();
#else
	return;
#endif
}
void UclTest_Shutdown(uint8 instId) {
#ifdef UCLTEST_NUM_INSTANCES
	UclTestObjs[instId]->Shutdown();
#else
	return;
#endif
}
void UclTest_Start(uint8 instId) {
#ifdef UCLTEST_NUM_INSTANCES
	UclTestObjs[instId]->Start();
#else
	return;
#endif
}
void UclTest_Stop(uint8 instId) {
#ifdef UCLTEST_NUM_INSTANCES
	UclTestObjs[instId]->Stop();
#else
	return;
#endif
}
void UclDLCbk_FatalError(uint8 instId, EUclDLError status) { 
#ifdef UCLDLCBK_NUM_INSTANCES
	UclDLCbkObjs[instId]->FatalError(status);
#else
	return;
#endif
}
void UclDLCbk_LinkStatusChanged(uint8 instId, EUclDLLinkStatus status) { 
#ifdef UCLDLCBK_NUM_INSTANCES
	UclDLCbkObjs[instId]->LinkStatusChanged(status);
#else
	return;
#endif
}
void UclDLCbk_MsgReceived(uint8 instId, EUclDLRxStatus status, SUclDLMsg *pMsg) { 
#ifdef UCLDLCBK_NUM_INSTANCES
	UclDLCbkObjs[instId]->MsgReceived(status, pMsg);
#else
	return;
#endif
}
void UclDLCbk_MsgTransmitStatus(uint8 instId, uint16 msgId, EUclDLAckStatus status) { 
#ifdef UCLDLCBK_NUM_INSTANCES
	UclDLCbkObjs[instId]->MsgTransmitStatus(msgId, status);
#else
	return;
#endif
}
void UclALPhyCbk_FatalError(uint8 instId, sint32 status) { 
#ifdef UCLALPHYCBK_NUM_INSTANCES
	UclALPhyCbkObjs[instId]->FatalError(status);
#else
	return;
#endif
}
void UclALPhyCbk_PeerReadyStatusChanged(uint8 instId, EUclALPhyPeerReadyStatus status) { 
#ifdef UCLALPHYCBK_NUM_INSTANCES
	UclALPhyCbkObjs[instId]->PeerReadyStatusChanged(status);
#else
	return;
#endif
}
void UclALPhyCbk_ReceiveDataAvailable(uint8 instId) {
#ifdef UCLALPHYCBK_NUM_INSTANCES
	UclALPhyCbkObjs[instId]->ReceiveDataAvailable();
#else
	return;
#endif
}
void UclALHwCbk_TransmitComplete(uint8 instId) {
#ifdef UCLALHWCBK_NUM_INSTANCES
	UclALHwCbkObjs[instId]->TransmitComplete();
#else
	return;
#endif
}
void UclALHwCbk_ReceiveComplete(uint8 instId) {
#ifdef UCLALHWCBK_NUM_INSTANCES
	UclALHwCbkObjs[instId]->ReceiveComplete();
#else
	return;
#endif
}
void UclALHwCbk_GpioChanged(uint8 instId, uint32 gpioNum) { 
#ifdef UCLALHWCBK_NUM_INSTANCES
	UclALHwCbkObjs[instId]->GpioChanged(gpioNum);
#else
	return;
#endif
}
Ucl_ReturnType UclILStream_Initialize(uint8 instId) {
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->Initialize();
#else
	return UCL_E_NOK;
#endif
}
Ucl_ReturnType UclILStream_Shutdown(uint8 instId) {
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->Shutdown();
#else
	return UCL_E_NOK;
#endif
}
sint32 UclILStream_Open(uint8 instId, uint8 chId, uint16 flags) { 
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->Open(chId, flags);
#else
	return UCL_E_NOK;
#endif
}
sint32 UclILStream_Close(uint8 instId, sint32 fd) { 
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->Close(fd);
#else
	return UCL_E_NOK;
#endif
}
sint32 UclILStream_Read(uint8 instId, sint32 fd, uint8 *pBuffer, uint32 size) { 
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->Read(fd, pBuffer, size);
#else
	return UCL_E_NOK;
#endif
}
sint32 UclILStream_Write(uint8 instId, sint32 fd, uint8 *pBuffer, uint32 size) { 
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->Write(fd, pBuffer, size);
#else
	return UCL_E_NOK;
#endif
}
sint32 UclILStream_Poll(uint8 instId, sint32 fd, uint32 timeout) { 
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->Poll(fd, timeout);
#else
	return UCL_E_NOK;
#endif
}
sint32 UclILStream_PollEx(uint8 instId, sint32 fd, uint8 reqId, uint32 *pStatus, uint32 timeout) { 
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->PollEx(fd, reqId, pStatus, timeout);
#else
	return UCL_E_NOK;
#endif
}
sint32 UclILStream_WriteEx(uint8 instId, sint32 fd, uint8 reqId, uint8 *pBuffer, uint32 size) { 
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->WriteEx(fd, reqId, pBuffer, size);
#else
	return UCL_E_NOK;
#endif
}
sint32 UclILStream_Ioctl(uint8 instId, sint32 fd, uint16 request, void *pData, uint16 size) { 
#ifdef UCLILSTREAM_NUM_INSTANCES
	return UclILStreamObjs[instId]->Ioctl(fd, request, pData, size);
#else
	return UCL_E_NOK;
#endif
}
