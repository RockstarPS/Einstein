/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2024. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/
/*****************************************************************************
*  File Name         :  SciDrv_Udma .c                                       *
*  Module Short Name :  SciDrv_Udma                                          *
*  Description       :  This file contains implementations of the SCI Driver *
*                       for AM62PX series microcontrollers.               *
*                                                                            *
* Organization     :  Driver Information Software Section,                   *
*                     Visteon Software Operation                             *
*                     Visteon Corporation                                    *
*                                                                            *
* ---------------------------------------------------------------------------*
* Compiler Name    :  Clang Compiler                                          *
* Target Hardware  :  AM62PX micro based Hardware Platform                *
*                                                                            *
******************************************************************************/



/*****************************************************************************
*                            Include files                                   *
******************************************************************************/
#include "SciDrv.h"
#include "SciDrv_Cfg.h"

#if(DMA_PROVEOUT_ENABLED == STD_ON)
#include "SciDrv_Udma.h"
#include <drivers/udma.h>
#include <drivers/udma/v0/include/udma_ch.h>
#include <drivers/udma/v0/include/udma_ring.h>
#include <drivers/udma/v0/include/udma_event.h>
#include <drivers/udma/v0/include/udma_utils.h>
#include <drivers/udma/v0/include/csl_udmap_cppi5.h>
#include <kernel/dpl/CacheP.h>
#include <string.h>
#include <stdint.h>

/* ===== Constants / sizes (yours) ===== */
#ifndef UDMA_CACHELINE_ALIGNMENT
#define UDMA_CACHELINE_ALIGNMENT   (64U)   /* note: your build seems to use 128U; both are fine */
#endif

#define SCIDRV_UDMA_RING_ELEM_CNT   (1U)          /* UART: single outstanding desc is fine */
#define SCIDRV_UDMA_RING_ENTRY_SIZE (sizeof(uint64))
#define SCIDRV_UDMA_RING_MEM_SIZE   (SCIDRV_UDMA_RING_ELEM_CNT * SCIDRV_UDMA_RING_ENTRY_SIZE)

#define SCIDRV_UDMA_HPD_SIZE        (64U)
_Static_assert((SCIDRV_UDMA_HPD_SIZE % 64U) == 0U, "HPD must be 64B aligned");
_Static_assert(sizeof(CSL_UdmapCppi5HMPD) <= SCIDRV_UDMA_HPD_SIZE, "HPD struct larger than 64B");

#ifndef SCIDRV_MAX_TX_BOUNCE
#define SCIDRV_MAX_TX_BOUNCE        (512U)
#endif

/* ===== Helpers ===== */
#define ALIGN_UP(x,a)    ( ((x) + ((a) - 1U)) & ~((a) - 1U) )

/* Round small ring to full cacheline to simplify DMA cache maintenance */
#define SCIDRV_RING_BLOCK_SIZE  ALIGN_UP(SCIDRV_UDMA_RING_MEM_SIZE, UDMA_CACHELINE_ALIGNMENT)

/* (Optional) sanity checks now pass regardless of 64B or 128B cachelines */
_Static_assert((SCIDRV_RING_BLOCK_SIZE % UDMA_CACHELINE_ALIGNMENT) == 0U, "Ring block not cacheline-multiple");
_Static_assert((SCIDRV_MAX_TX_BOUNCE % UDMA_CACHELINE_ALIGNMENT) == 0U,
               "Bounce block size not cacheline-multiple; consider ALIGN_UP if needed");

/* ===== Per-channel objects (yours) ===== */
static Udma_ChObject     gSciUdmaTxObj[SCIDRV_MAX_CHANNELS];
static Udma_ChObject     gSciUdmaRxObj[SCIDRV_MAX_CHANNELS];
static Udma_EventObject  gSciUdmaCqTxEventObj[SCIDRV_MAX_CHANNELS];
static Udma_EventObject  gSciUdmaCqRxEventObj[SCIDRV_MAX_CHANNELS];

/* ===== Per-channel aligned block types =====
   Each array element is aligned and sized to a full cacheline.
*/
typedef uint8  SciRingBlock   [SCIDRV_RING_BLOCK_SIZE]      __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
typedef uint8  SciHpdBlock    [SCIDRV_UDMA_HPD_SIZE]        __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
typedef uint8  SciBounceBlock [SCIDRV_MAX_TX_BOUNCE]        __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));

/* ===== Per-channel buffers ===== */
static SciRingBlock    gSciUdmaTxFqRingMem[SCIDRV_MAX_CHANNELS];
static SciRingBlock    gSciUdmaTxCqRingMem[SCIDRV_MAX_CHANNELS];
static SciRingBlock    gSciUdmaRxFqRingMem[SCIDRV_MAX_CHANNELS];
static SciRingBlock    gSciUdmaRxCqRingMem[SCIDRV_MAX_CHANNELS];

static SciHpdBlock     gSciUdmaTxHpdMem[SCIDRV_MAX_CHANNELS];
static SciHpdBlock     gSciUdmaRxHpdMem[SCIDRV_MAX_CHANNELS];

static SciBounceBlock  gSciUdmaTxBounce[SCIDRV_MAX_CHANNELS];


/* ===== (Optional) quick address check you can call once at init =====
   Verifies every per-channel block is cacheline-aligned.
*/



typedef struct
{
  Udma_ChHandle txCh;
  Udma_ChHandle rxCh;
  Udma_ChObject *txChObj;
  Udma_ChObject *rxChObj;

  Udma_EventHandle cqTxEvt;
  Udma_EventHandle cqRxEvt;

  uint8 *txFqRingMem;
    uint8            *txCqRingMem;
  uint8 *rxFqRingMem;
  uint8 *rxCqRingMem;

  uint8 *txHpdMem;
  uint8 *rxHpdMem;

  volatile boolean txDone;
  volatile boolean rxDone;

  /* RX bookkeeping */
  uint8 *rxBuf;
  uint32 rxLenLatched;

  boolean isAttached;
} SciUdmaCtxType;

static SciUdmaCtxType gSciUdmaCtx[SCIDRV_MAX_CHANNELS];

/* ==== helpers ==== */
static inline uint32 SciDrv_GetUartBase(uint8 channelId)
{
  return pSciDrvCfg->pSciDrvChnCfg[channelId].SciDrvBaseAddr;
}

static void SciDrv_Write_Reg32(uint32 regAddr, uint32 value)
{
  *(volatile uint32 *)regAddr = value;
}

/* Bind all static memories to the context (rings/HPDs/evt objs) */
static void SciDrv_UdmaBindMem(uint8 channelId)
{
  SciUdmaCtxType *udmaContext = &gSciUdmaCtx[channelId];

  udmaContext->txChObj = &gSciUdmaTxObj[channelId];
  udmaContext->rxChObj = &gSciUdmaRxObj[channelId];

  udmaContext->cqTxEvt = &gSciUdmaCqTxEventObj[channelId];
  udmaContext->cqRxEvt = &gSciUdmaCqRxEventObj[channelId];

  udmaContext->txFqRingMem = &gSciUdmaTxFqRingMem[channelId][0];
    udmaContext->txCqRingMem = &gSciUdmaTxCqRingMem[channelId][0];
  udmaContext->rxFqRingMem = &gSciUdmaRxFqRingMem[channelId][0];
  udmaContext->rxCqRingMem = &gSciUdmaRxCqRingMem[channelId][0];

  udmaContext->txHpdMem = &gSciUdmaTxHpdMem[channelId][0];
  udmaContext->rxHpdMem = &gSciUdmaRxHpdMem[channelId][0];
}

/* ---- TX DMA completion ISR (PKTDMA/HPD) ---- */
static void SciDrv_UdmaTxIsr(Udma_EventHandle eventHandle, uint32 eventType, void *appData)
{
    uint8 swChannel = (uint8)(uintptr_t)appData;
    SciUdmaCtxType *ctx = &gSciUdmaCtx[swChannel];
    (void)eventHandle;

    if (eventType == UDMA_EVENT_TYPE_DMA_COMPLETION)
    {
        uint64 pDesc;
        boolean gotOne = FALSE;

        /* Drain ALL completions posted for this transfer */
        while (Udma_ringDequeueRaw(Udma_chGetCqRingHandle(ctx->txCh), &pDesc) == UDMA_SOK && pDesc != 0U)
        {
            gotOne = TRUE;
        }

        if (gotOne)
        {
            CacheP_inv(ctx->txHpdMem, sizeof(CSL_UdmapCppi5HMPD), CacheP_TYPE_ALLD);
            ctx->txDone = TRUE;
            SciDrv_DmaTxComplete(swChannel);
        }
    }
}

/* ---- RX DMA completion ISR: dequeue exactly one CQ entry ---- */
static void SciDrv_UdmaRxIsr(Udma_EventHandle eventHandle, uint32 eventType, void *appData)
{
  uint8 channelId = (uint8)(uintptr_t)appData;
  SciUdmaCtxType *udmaContext = &gSciUdmaCtx[channelId];
  (void)eventHandle;
  (void)eventType;

  uint64 cqWord;
  if (Udma_ringDequeueRaw(Udma_chGetCqRingHandle(udmaContext->rxCh), &cqWord) == UDMA_SOK)
  {
    CacheP_inv(udmaContext->rxBuf, udmaContext->rxLenLatched, CacheP_TYPE_ALLD);
    udmaContext->rxDone = TRUE;
    SciDrv_DmaRxComplete(channelId, udmaContext->rxLenLatched);
  }
}

/* ========= Attach / Channel open ========= */
Std_ReturnType SciDrv_UdmaAttach(uint8 swChannel, uint32 udmaInstId,
                                 uint32 peerTxThread, uint32 peerRxThread)
{
  SciUdmaCtxType *udmaContext = &gSciUdmaCtx[swChannel];

  if (udmaContext->isAttached == TRUE)
  {
    return E_OK;
  }

  SciDrv_UdmaBindMem(swChannel); /* rings/HPDs/event objects bind */

  extern Udma_DrvObject gUdmaDrvObj[];
  Udma_DrvHandle driverHandle = &gUdmaDrvObj[udmaInstId];


  /* ---------------- TX channel (PDMA) ---------------- */
  Udma_ChPrms txPrms;
  UdmaChPrms_init(&txPrms, UDMA_CH_TYPE_PDMA_TX);
  txPrms.peerChNum = peerTxThread;

  /* SDK pattern: only FQ ring for TX (submit HPDs here). No TX CQ ring. */
  txPrms.fqRingPrms.ringMem = udmaContext->txFqRingMem;
  txPrms.fqRingPrms.ringMemSize = SCIDRV_UDMA_RING_MEM_SIZE;
  txPrms.fqRingPrms.elemCnt = SCIDRV_UDMA_RING_ELEM_CNT;

  DebugP_assert(Udma_chOpen(driverHandle, udmaContext->txChObj,
                            UDMA_CH_TYPE_PDMA_TX, &txPrms) == UDMA_SOK);
  udmaContext->txCh = udmaContext->txChObj;

  {
    Udma_ChTxPrms txCommon;
    UdmaChTxPrms_init(&txCommon, UDMA_CH_TYPE_PDMA_TX);
    DebugP_assert(Udma_chConfigTx(udmaContext->txCh, &txCommon) == UDMA_SOK);
  }

  /* ---------------- RX channel (PDMA) ---------------- */
  Udma_ChPrms rxPrms;
  UdmaChPrms_init(&rxPrms, UDMA_CH_TYPE_PDMA_RX);
  rxPrms.peerChNum = peerRxThread;

  /* FQ ring (submit RX HPDs) + CQ ring (RX completion) */
  rxPrms.fqRingPrms.ringMem = udmaContext->rxFqRingMem;
  rxPrms.fqRingPrms.ringMemSize = SCIDRV_UDMA_RING_MEM_SIZE;
  rxPrms.fqRingPrms.elemCnt = SCIDRV_UDMA_RING_ELEM_CNT;

  rxPrms.cqRingPrms.ringMem = udmaContext->rxCqRingMem;
  rxPrms.cqRingPrms.ringMemSize = SCIDRV_UDMA_RING_MEM_SIZE;
  rxPrms.cqRingPrms.elemCnt = SCIDRV_UDMA_RING_ELEM_CNT;

  DebugP_assert(Udma_chOpen(driverHandle, udmaContext->rxChObj,
                            UDMA_CH_TYPE_PDMA_RX, &rxPrms) == UDMA_SOK);
  udmaContext->rxCh = udmaContext->rxChObj;

  {
    Udma_ChRxPrms rxCommon;
    UdmaChRxPrms_init(&rxCommon, UDMA_CH_TYPE_PDMA_RX);
    rxCommon.configDefaultFlow = FALSE;
    DebugP_assert(Udma_chConfigRx(udmaContext->rxCh, &rxCommon) == UDMA_SOK);
  }

  /* PDMA engine width default: 8-bit, 1 element (both) */
  {
    Udma_ChPdmaPrms pdma;
    UdmaChPdmaPrms_init(&pdma);
    pdma.elemSize = UDMA_PDMA_ES_8BITS;
    pdma.elemCnt = 1U;
    pdma.fifoCnt = 0U;
    DebugP_assert(Udma_chConfigPdma(udmaContext->txCh, &pdma) == UDMA_SOK);

    UdmaChPdmaPrms_init(&pdma);
    pdma.elemSize = UDMA_PDMA_ES_8BITS;
    pdma.elemCnt = 1U;
    pdma.fifoCnt = 0U;
    DebugP_assert(Udma_chConfigPdma(udmaContext->rxCh, &pdma) == UDMA_SOK);
  }

  /* -------- Register completion events BEFORE enable -------- */
  Udma_EventPrms evt;
  UdmaEventPrms_init(&evt);
  evt.eventType = UDMA_EVENT_TYPE_DMA_COMPLETION;
  evt.eventMode = UDMA_EVENT_MODE_SHARED;
  evt.intrPriority = 8U;
  evt.masterEventHandle = Udma_eventGetGlobalHandle(driverHandle);

  /* TX completion (no CQ dequeue here) */
  evt.chHandle = udmaContext->txCh;
  evt.appData = (void *)(uintptr_t)swChannel;
  evt.eventCb = SciDrv_UdmaTxIsr;
  DebugP_assert(Udma_eventRegister(driverHandle, udmaContext->cqTxEvt, &evt) == UDMA_SOK);
  DebugP_assert(Udma_eventEnable(udmaContext->cqTxEvt) == UDMA_SOK);

  /* RX completion (we will dequeue from RX CQ) */
  evt.chHandle = udmaContext->rxCh;
  evt.appData = (void *)(uintptr_t)swChannel;
  evt.eventCb = SciDrv_UdmaRxIsr;
  DebugP_assert(Udma_eventRegister(driverHandle, udmaContext->cqRxEvt, &evt) == UDMA_SOK);
  DebugP_assert(Udma_eventEnable(udmaContext->cqRxEvt) == UDMA_SOK);

  /* Enable channels */
  DebugP_assert(Udma_chEnable(udmaContext->txCh) == UDMA_SOK);
  DebugP_assert(Udma_chEnable(udmaContext->rxCh) == UDMA_SOK);

  udmaContext->txDone = FALSE;
  udmaContext->rxDone = FALSE;
  udmaContext->isAttached = TRUE;


  return E_OK;
}

Std_ReturnType SciDrv_UdmaSubmitTx(uint8 swChannel, uint8 *payloadPtr, uint32 payloadLen)
{
    SciUdmaCtxType *ctx = &gSciUdmaCtx[swChannel];
    if ((ctx->txCh == NULL) || (payloadPtr == NULL) || (payloadLen == 0U)) { return E_NOT_OK; }
    if (payloadLen > SCIDRV_MAX_TX_BOUNCE) { return E_NOT_OK; }

    /* Bounce copy into cache-coherent buffer (contiguous, DMA-visible) */
    uint8 *bounce = &gSciUdmaTxBounce[swChannel][0];
    (void)memcpy(bounce, payloadPtr, payloadLen);
    CacheP_wb(bounce, payloadLen, CacheP_TYPE_ALLD);

    /* --- SDK style: (re)configure PDMA + enable channel on EVERY transfer --- */
    {
        Udma_ChPdmaPrms pdma;
        UdmaChPdmaPrms_init(&pdma);
        pdma.elemSize = UDMA_PDMA_ES_8BITS;
        pdma.elemCnt  = 1U;
        pdma.fifoCnt  = 0U; /* TX: don't care, SDK uses 0 */
        DebugP_assert(Udma_chConfigPdma(ctx->txCh, &pdma) == UDMA_SOK);
        DebugP_assert(Udma_chEnable(ctx->txCh) == UDMA_SOK);
    }

    /* Build 64B Host Packet Descriptor (HPD), SDK layout */
    CSL_UdmapCppi5HMPD *h = (CSL_UdmapCppi5HMPD *)ctx->txHpdMem;
    (void)memset(h, 0, sizeof(*h));
    const uint32 descType = (uint32)CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST;

    CSL_udmapCppi5SetDescType(h, descType);
    CSL_udmapCppi5SetEpiDataPresent(h, 0U);
    CSL_udmapCppi5SetPsDataLoc(h, 0U);
    CSL_udmapCppi5SetPsDataLen(h, 0U);
    CSL_udmapCppi5SetPsFlags(h, 0U);
    CSL_udmapCppi5SetPktLen(h, descType, (uint32)payloadLen);

    /* IDs + default flow (SDK uses any pktId, default flow) */
    CSL_udmapCppi5SetIds(h, descType, 0x321U, UDMA_DEFAULT_FLOW_ID);
    CSL_udmapCppi5SetSrcTag(h, 0U);
    CSL_udmapCppi5SetDstTag(h, 0U);

    /* Return policy = 0 (no TX CQ), just like SDK UART */
    CSL_udmapCppi5SetReturnPolicy(h, descType, 0U, 0U, 0U, 0U);

    /* Map buffer */
    uint64 phys = (uint64)Udma_defaultVirtToPhyFxn((const void*)bounce, 0U, NULL);
    CSL_udmapCppi5SetBufferAddr(h, phys);
    CSL_udmapCppi5SetBufferLen(h, (uint32)payloadLen);
    CSL_udmapCppi5SetOrgBufferAddr(h, phys);
    CSL_udmapCppi5SetOrgBufferLen(h, (uint32)payloadLen);
    CSL_udmapCppi5LinkDesc(h, 0U);

    /* Writeback HPD to memory */
    CacheP_wb(h, sizeof(*h), CacheP_TYPE_ALLD);

    /* Queue the HPD pointer to TX FQ (NO manual doorbell; same as SDK) */
    Udma_RingHandle fq = Udma_chGetFqRingHandle(ctx->txCh);
    uint64 physHpd = (uint64)Udma_defaultVirtToPhyFxn((const void*)ctx->txHpdMem, 0U, NULL);
    DebugP_assert(Udma_ringQueueRaw(fq, physHpd) == UDMA_SOK);

    ctx->txDone = FALSE;
    return E_OK;
}


/* ========= RX prime: HPD + fifoCnt=bytes to fetch ========= */
Std_ReturnType SciDrv_UdmaPrimeRx(uint8 channelId, uint8 *rxBuf, uint32 rxLen)
{
  SciUdmaCtxType *udmaContext = &gSciUdmaCtx[channelId];

  if ((udmaContext->rxCh == NULL) || (rxBuf == NULL) || (rxLen == 0U))
  {
    return E_NOT_OK;
  }

  udmaContext->rxBuf = rxBuf;
  udmaContext->rxLenLatched = rxLen;

  /* RX PDMA config: fifoCnt = bytes to fetch; enable channel */
  Udma_ChPdmaPrms pd;
  UdmaChPdmaPrms_init(&pd);
  pd.elemSize = UDMA_PDMA_ES_8BITS;
  pd.elemCnt = 1U;
  pd.fifoCnt = rxLen;
  DebugP_assert(Udma_chConfigPdma(udmaContext->rxCh, &pd) == UDMA_SOK);
  DebugP_assert(Udma_chEnable(udmaContext->rxCh) == UDMA_SOK);

  CSL_UdmapCppi5HMPD *hpd = (CSL_UdmapCppi5HMPD *)udmaContext->rxHpdMem;
  const uint32 dtype = (uint32)CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST;
  (void)memset(hpd, 0, sizeof(*hpd));

  CSL_udmapCppi5SetDescType(hpd, dtype);
  CSL_udmapCppi5SetEpiDataPresent(hpd, 0U);
  CSL_udmapCppi5SetPsDataLoc(hpd, 0U);
  CSL_udmapCppi5SetPsDataLen(hpd, 0U);
  CSL_udmapCppi5SetPsFlags(hpd, 0U);
  CSL_udmapCppi5SetPktLen(hpd, dtype, (uint32)rxLen);

  /* Use default RX flow */
  Udma_FlowHandle rxFlow = Udma_chGetDefaultFlowHandle(udmaContext->rxCh);
  uint32 flowId = (uint32)Udma_flowGetNum(rxFlow);
  CSL_udmapCppi5SetIds(hpd, dtype, 0U, flowId);

  uint64 physBuf = (uint64)Udma_defaultVirtToPhyFxn((const void *)rxBuf, 0U, NULL);
  CSL_udmapCppi5SetBufferAddr(hpd, physBuf);
  CSL_udmapCppi5SetBufferLen(hpd, (uint32)rxLen);
  CSL_udmapCppi5SetOrgBufferAddr(hpd, physBuf);
  CSL_udmapCppi5SetOrgBufferLen(hpd, (uint32)rxLen);

  /* Return RX completion to RX CQ */
  {
    Udma_RingHandle rxCq = Udma_chGetCqRingHandle(udmaContext->rxCh);
    uint32 rxCqNum = (uint32)Udma_ringGetNum(rxCq);
    CSL_udmapCppi5SetReturnPolicy(hpd, dtype, 0U, 0U, 0U, rxCqNum);
  }

  CSL_udmapCppi5LinkDesc(hpd, 0U);

  CacheP_inv(rxBuf, rxLen, CacheP_TYPE_ALLD);
  CacheP_wb(hpd, sizeof(*hpd), CacheP_TYPE_ALLD);

  /* Enqueue to RX FQ (no manual doorbell) */
  Udma_RingHandle rxFq = Udma_chGetFqRingHandle(udmaContext->rxCh);
  uint64 hpdPhys = (uint64)Udma_defaultVirtToPhyFxn((const void *)udmaContext->rxHpdMem, 0U, NULL);
  DebugP_assert(Udma_ringQueueRaw(rxFq, hpdPhys) == UDMA_SOK);

  udmaContext->rxDone = FALSE;
  return E_OK;
}

/* ========= Detach ========= */
void SciDrv_UdmaDetach(uint8 channelId)
{
  SciUdmaCtxType *udmaContext = &gSciUdmaCtx[channelId];
  if (udmaContext->isAttached != TRUE)
  {
    return;
  }

  /* Drain rings defensively */
  uint64 deq;
  while (Udma_ringDequeueRaw(Udma_chGetFqRingHandle(udmaContext->txCh), &deq) == UDMA_SOK)
  {
  }
  while (Udma_ringDequeueRaw(Udma_chGetFqRingHandle(udmaContext->rxCh), &deq) == UDMA_SOK)
  {
  }
  while (Udma_ringDequeueRaw(Udma_chGetCqRingHandle(udmaContext->rxCh), &deq) == UDMA_SOK)
  {
  }

  (void)Udma_chDisable(udmaContext->txCh, UDMA_DEFAULT_CH_DISABLE_TIMEOUT);
  (void)Udma_chDisable(udmaContext->rxCh, UDMA_DEFAULT_CH_DISABLE_TIMEOUT);

  if (udmaContext->cqTxEvt)
  {
    (void)Udma_eventDisable(udmaContext->cqTxEvt);
    (void)Udma_eventUnRegister(udmaContext->cqTxEvt);
  }
  if (udmaContext->cqRxEvt)
  {
    (void)Udma_eventDisable(udmaContext->cqRxEvt);
    (void)Udma_eventUnRegister(udmaContext->cqRxEvt);
  }

  (void)Udma_chClose(udmaContext->txCh);
  (void)Udma_chClose(udmaContext->rxCh);

  udmaContext->txCh = NULL;
  udmaContext->rxCh = NULL;
  udmaContext->isAttached = FALSE;
}

/* ===== Done flags + acks ===== */
boolean SciDrv_UdmaTxDone(uint8 channelId) { return gSciUdmaCtx[channelId].txDone; }
boolean SciDrv_UdmaRxDone(uint8 channelId) { return gSciUdmaCtx[channelId].rxDone; }
void SciDrv_UdmaAckTx(uint8 channelId) { gSciUdmaCtx[channelId].txDone = FALSE; }
void SciDrv_UdmaAckRx(uint8 channelId) { gSciUdmaCtx[channelId].rxDone = FALSE; }
#endif /* DMA_PROVEOUT_ENABLED */
