/*
 *  Copyright (C) 2021 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Auto generated file 
 */

#include "ti_drivers_open_close.h"
#include <kernel/dpl/DebugP.h>

void Drivers_open(void)
{

    Drivers_mcaspOpen();
    Drivers_udmaOpen();
}

void Drivers_close(void)
{
    Drivers_mcaspClose();
    Drivers_udmaClose();
}


/*
 * MCASP
 */

/* MCASP transmit callback */
void mcasp_txcb(MCASP_Handle handle, MCASP_Transaction *transaction);
extern unsigned int audio_sample[];

/* Arrays containing indices of MCASP Tx/Rx serializers used */
uint8_t gMcasp0TxSersUsed[1] = {0};
uint8_t gMcasp0RxSersUsed[0] = {};

Udma_EventObject gBcdmaTxCqEventObj;
Udma_EventObject gBcdmaRxCqEventObj;

/* Number of ring entries */
#define UDMA_RING_ENTRIES_TX             (MCASP_TX_DMA_RING_ELEM_CNT)
#define UDMA_RING_ENTRIES_RX             (MCASP_RX_DMA_RING_ELEM_CNT)
/* Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define MCASP_UDMA_RING_ENTRY_SIZE       (sizeof(uint64_t))

#define MCASP_RING_MEM_SIZE_TX           (MCASP_UDMA_RING_ENTRY_SIZE*UDMA_RING_ENTRIES_TX)
#define MCASP_RING_MEM_SIZE_RX           (MCASP_UDMA_RING_ENTRY_SIZE*UDMA_RING_ENTRIES_RX)

#if defined (MCASP_TX_EVENT_TYPE_L2G)
#define MCASP_UDMA_TR15_TRPD_SIZE_TX        (UDMA_GET_TRPD_TR15_SIZE(MCASP_TX_DMA_TR_COUNT))
#else
#define MCASP_UDMA_TR3_TRPD_SIZE_TX         (UDMA_GET_TRPD_TR3_SIZE(MCASP_TX_DMA_TR_COUNT))
#endif

#define MCASP_UDMA_TR3_TRPD_SIZE_RX         (UDMA_GET_TRPD_TR3_SIZE(MCASP_RX_DMA_TR_COUNT))

Udma_ChObject       gMcasp0UdmaTxChObj;
Udma_EventObject    gMcasp0_UdmaCqEventObjTx;

Udma_ChObject       gMcasp0UdmaRxChObj;
Udma_EventObject    gMcasp0_UdmaCqEventObjRx;

#if defined (MCASP_TX_EVENT_TYPE_L2G)
uint8_t gMcasp0UdmaTxTrpdMem[MCASP_UDMA_TR15_TRPD_SIZE_TX*MCASP_TX_DMA_RING_ELEM_CNT] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
#else
uint8_t gMcasp0UdmaTxTrpdMem[MCASP_UDMA_TR3_TRPD_SIZE_TX*MCASP_TX_DMA_RING_ELEM_CNT] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
#endif

uint8_t gMcasp0UdmaRxTrpdMem[MCASP_UDMA_TR3_TRPD_SIZE_RX*MCASP_RX_DMA_RING_ELEM_CNT] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));

static uint8_t gMcasp0TxFqRingMem[UDMA_ALIGN_SIZE(MCASP_RING_MEM_SIZE_TX)] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
static uint8_t gMcasp0RxFqRingMem[UDMA_ALIGN_SIZE(MCASP_RING_MEM_SIZE_RX)] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));

static MCASP_Transaction *gMcasp0TxCbParam[MCASP_TX_DMA_TR_COUNT];
static MCASP_Transaction *gMcasp0RxCbParam[MCASP_RX_DMA_TR_COUNT];

MCASP_DmaChConfig gMcasp0_DmaChCfg[] =
{
    {
        .txChHandle         = &gMcasp0UdmaTxChObj,
        .rxChHandle         = &gMcasp0UdmaRxChObj,
        .cqTxEvtHandle      = &gMcasp0_UdmaCqEventObjTx,
        .cqRxEvtHandle      = &gMcasp0_UdmaCqEventObjRx,
        .txTrpdMem          = gMcasp0UdmaTxTrpdMem,
        .rxTrpdMem          = gMcasp0UdmaRxTrpdMem,
        .txRingMem          = gMcasp0TxFqRingMem,
        .rxRingMem          = gMcasp0RxFqRingMem,
        .txCbParams         = gMcasp0TxCbParam,
        .rxCbParams         = gMcasp0RxCbParam,
        .rxEvtNum           = UDMA_PDMA_CH_MAIN0_MCASP1_RX,
        .txEvtNum           = UDMA_PDMA_CH_MAIN0_MCASP1_TX,
    }
};

/* MCASP Driver handles */
MCASP_Handle gMcaspHandle[CONFIG_MCASP_NUM_INSTANCES];
/* MCASP Driver Open Parameters */
MCASP_OpenParams gMcaspOpenParams[CONFIG_MCASP_NUM_INSTANCES] =
{
    {
        .transferMode = MCASP_TRANSFER_MODE_DMA,
        .txBufferFormat = MCASP_AUDBUFF_FORMAT_1SER_MULTISLOT_INTERLEAVED,
        .rxBufferFormat = MCASP_AUDBUFF_FORMAT_1SER_MULTISLOT_INTERLEAVED,
        .txSerUsedCount = 1,
        .rxSerUsedCount = 0,
        .txSerUsedArray = (uint8_t *) gMcasp0TxSersUsed,
        .rxSerUsedArray = (uint8_t *) gMcasp0RxSersUsed,
        .txSlotCount = 2,
        .rxSlotCount = 2,
        .txCallbackFxn = mcasp_txcb,
        .txLoopjobEnable = true,
        .txLoopjobBuf = (uint8_t *) audio_sample,
        .txLoopjobBufLength = 96000,
        .rxLoopjobEnable = true,
        .dmaChCfg = &gMcasp0_DmaChCfg[0],
        .mcaspDmaDrvObj = &gUdmaDrvObj[CONFIG_UDMA0],

        .skipDriverOpen = 0,
    },
};


void Drivers_mcaspOpen(void)
{
    uint32_t instCnt;
    int32_t  status = SystemP_SUCCESS;

    for(instCnt = 0U; instCnt < CONFIG_MCASP_NUM_INSTANCES; instCnt++)
    {
        gMcaspHandle[instCnt] = NULL;   /* Init to NULL so that we can exit gracefully */
    }

    /* Open all instances */
    for(instCnt = 0U; instCnt < CONFIG_MCASP_NUM_INSTANCES; instCnt++)
    {
        if(!gMcaspOpenParams[instCnt].skipDriverOpen)
        {
            gMcaspHandle[instCnt] = MCASP_open(instCnt, &gMcaspOpenParams[instCnt]);
            if(NULL == gMcaspHandle[instCnt])
            {
                DebugP_logError("MCASP open failed for instance %d !!!\r\n", instCnt);
                status = SystemP_FAILURE;
                break;
            }
        }
    }

    if(SystemP_FAILURE == status)
    {
        Drivers_mcaspClose();   /* Exit gracefully */
    }

    return;
}

void Drivers_mcaspClose(void)
{
    uint32_t instCnt;

    /* Close all instances that are open */
    for(instCnt = 0U; instCnt < CONFIG_MCASP_NUM_INSTANCES; instCnt++)
    {
        if(gMcaspHandle[instCnt] != NULL)
        {
            MCASP_close(gMcaspHandle[instCnt]);
        }
    }

    for(instCnt = 0U; instCnt < CONFIG_MCASP_NUM_INSTANCES; instCnt++)
    {
        if(gMcaspHandle[instCnt] != NULL)
        {
            gMcaspHandle[instCnt] = NULL;
        }
    }

    return;
}

/*
 * UDMA
 */

void Drivers_udmaOpen(void)
{
}

void Drivers_udmaClose(void)
{
}
