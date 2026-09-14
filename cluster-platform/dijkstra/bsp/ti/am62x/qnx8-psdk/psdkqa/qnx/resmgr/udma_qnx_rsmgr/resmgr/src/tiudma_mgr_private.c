/*
 * $QNXLicenseC:
 * Copyright 2019, QNX Software Systems.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

/*
 * Modfications copyright (c) 2019-2022, Texas Instruments Incorporated
 *
 */

#include "tiudma_mgr_private.h"
#include <ti/drv/sciclient/sciclient.h>
#include "ti/drv/udma/include/udma_ch.h"
#include "ti/drv/udma/src/udma_priv.h"

uint64_t Resmgr_Udma_qnxVirtToPhyFxn(const void *virtAddr,
                             uint32_t chNum,
                             void *appData)
{
    int ret;
    off64_t    phyAddr = 0;
    uint32_t   length;

    if(appData != NULL_PTR) {
        length = (uint32_t) *((uint32_t *) appData);
    }
    else {
        printf("%s:%d Must specify memory size to map\n", __FUNCTION__, __LINE__);
        return -1;
    }

    /* Get destination physical address */
    ret = mem_offset64(virtAddr, NOFD, length, &phyAddr, NULL);
    if (ret) {
        if (errno != EAGAIN) {
            printf("%s:Error from mem_offset - errno=%d\n", __func__, errno);
        }
        else if (phyAddr == 0) {
            printf("%s:Error from mem_offset - errno=%d and phyAddr is NULL \n", __func__, errno);
        }
    }
    return (uint64_t ) phyAddr;
}

void *Resmgr_Udma_qnxPhyToVirtFxn(uint64_t phyAddr,
                           uint32_t chNum,
                           void *appData)
{
    uint64_t *temp = 0;
    uint32_t length = 0;


    if(appData != NULL_PTR) {
        length = (uint32_t) *((uint32_t *) appData);
    }
    else {
        printf("%s:%d Must specify memory size to map\n", __FUNCTION__, __LINE__);
        return NULL;
    }

    temp  = mmap_device_memory(0, length, PROT_READ|PROT_WRITE, 0, phyAddr);
    if((temp == MAP_FAILED))
    {
        printf("%s: mmmap_device_memory failed\n",__FUNCTION__);
    }

    return ((void *) temp);
}

uint16_t Resmgr_Udma_rmAllocProxy(uint16_t preferredProxyNum, Udma_DrvHandle drvHandle)
{
    uint16_t            i, offset, proxyNum = UDMA_PROXY_INVALID, temp;
    uint32_t            bitPos, bitMask;
    Udma_RmInitPrms    *rmInitPrms = &drvHandle->initPrms.rmInitPrms;

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.lockMutex != (Udma_OsalMutexLockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.lockMutex(drvHandle->rmLock);

    if(UDMA_PROXY_ANY == preferredProxyNum)
    {
        for(i = 0U; i < rmInitPrms->numProxy; i++)
        {
            offset = i >> 5U;
            Udma_assert(drvHandle, offset < UDMA_RM_PROXY_ARR_SIZE);
            temp = i - (offset << 5U);
            bitPos = (uint32_t) temp;
            bitMask = (uint32_t) 1U << bitPos;
            if((drvHandle->proxyFlag[offset] & bitMask) == bitMask)
            {
                drvHandle->proxyFlag[offset] &= ~bitMask;
                proxyNum = (uint16_t)rmInitPrms->startProxy;  /* Add start offset */
                proxyNum += i;
                break;
            }
        }
    }
    else
    {
        /* Array bound check */
        if((preferredProxyNum >= rmInitPrms->startProxy) &&
           (preferredProxyNum < (rmInitPrms->startProxy + rmInitPrms->numProxy)))
        {
            i = preferredProxyNum - rmInitPrms->startProxy;
            offset = i >> 5U;
            Udma_assert(drvHandle, offset < UDMA_RM_PROXY_ARR_SIZE);
            bitPos = i - (offset << 5U);
            bitMask = (uint32_t) 1U << bitPos;
            if((drvHandle->proxyFlag[offset] & bitMask) == bitMask)
            {
                drvHandle->proxyFlag[offset] &= ~bitMask;
                proxyNum = preferredProxyNum;
            }
        }
    }

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.unlockMutex != (Udma_OsalMutexUnlockFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.unlockMutex(drvHandle->rmLock);

    return (proxyNum);
}

int32_t Resmgr_Udma_eventCheckParams(Udma_DrvHandle drvHandle,
                                     const Udma_EventPrms *eventPrms)
{
    int32_t             retVal = UDMA_SOK;
    Udma_EventHandle    masterEventHandle;

    Udma_assert(drvHandle, eventPrms != NULL_PTR);

    /* Exclusive event checks */
    if(UDMA_EVENT_MODE_EXCLUSIVE == eventPrms->eventMode)
    {
        if(NULL_PTR != eventPrms->masterEventHandle)
        {
            retVal = UDMA_EINVALID_PARAMS;
            Udma_printf(drvHandle,
                "[Error] Master event handle should be NULL_PTR for exclusive event!!!\n");
        }
    }

    /* Shared event checks */
    if(UDMA_EVENT_MODE_SHARED == eventPrms->eventMode)
    {
        /* Shared event slave checks */
        if(NULL_PTR != eventPrms->masterEventHandle)
        {
            /* Check if callback is non-null for slave shared events when
             * master has callback set - This is becasuse once the master has
             * interrupt registered, all slaves should have a callback as IA
             * is same and there is no individual control to disable
             * interrupt */
            if(FALSE == eventPrms->osalRegisterDisable)
            {
                masterEventHandle = eventPrms->masterEventHandle;
                if(((Udma_EventCallback) NULL_PTR != masterEventHandle->eventPrms.eventCb) &&
                   ((Udma_EventCallback) NULL_PTR == eventPrms->eventCb))
                {
                    retVal = UDMA_EINVALID_PARAMS;
                    Udma_printf(drvHandle,
                        "[Error] No callback set for slave shared events!!!\n");
                }
                /* Check if master has not registered a callback, the slave should not
                 * expect a callback either!! */
                if(((Udma_EventCallback) NULL_PTR == masterEventHandle->eventPrms.eventCb) &&
                   ((Udma_EventCallback) NULL_PTR != eventPrms->eventCb) &&
                   (UDMA_EVENT_TYPE_MASTER != masterEventHandle->eventPrms.eventType))
                {
                    retVal = UDMA_EINVALID_PARAMS;
                    Udma_printf(drvHandle,
                        "[Error] Callback set for slave shared events when master event didnot set a callback!!!\n");
                }
            }
        }
    }

    /* Channel handle should be provided to reconfigure channel related event */
    if((UDMA_EVENT_TYPE_DMA_COMPLETION == eventPrms->eventType) ||
       (UDMA_EVENT_TYPE_TEARDOWN_PACKET == eventPrms->eventType) ||
       (UDMA_EVENT_TYPE_TR == eventPrms->eventType))
    {
        if(NULL_PTR == eventPrms->chHandle)
        {
            retVal = UDMA_EINVALID_PARAMS;
            Udma_printf(drvHandle,
                "[Error] Channel handle should be provided for ring/ch OES programming!!!\n");
        }
    }

    /* Ring handle should be provided to configure ring event */
    if(UDMA_EVENT_TYPE_RING == eventPrms->eventType)
    {
        if(NULL_PTR == eventPrms->ringHandle)
        {
            retVal = UDMA_EINVALID_PARAMS;
            Udma_printf(drvHandle,
                "[Error] Ring handle should be provided for ring OES programming!!!\n");
        }
    }

    /* Ring monitor handle should be provided to configure monitor event */
    if(UDMA_EVENT_TYPE_RING_MON == eventPrms->eventType)
    {
        if(NULL_PTR == eventPrms->monHandle)
        {
            retVal = UDMA_EINVALID_PARAMS;
            Udma_printf(drvHandle,
                "[Error] Monitor handle should be provided for ring monitor OES programming!!!\n");
        }
    }

    if(UDMA_EVENT_TYPE_MASTER == eventPrms->eventType)
    {
        if(UDMA_EVENT_MODE_SHARED != eventPrms->eventMode)
        {
            retVal = UDMA_EINVALID_PARAMS;
            Udma_printf(drvHandle,
                "[Error] Event should be shareable for global master event type!!!\n");
        }

        if(NULL_PTR != eventPrms->masterEventHandle)
        {
            retVal = UDMA_EINVALID_PARAMS;
            Udma_printf(drvHandle,
                "[Error] Master handle should be NULL_PTR for master event type!!!\n");
        }
    }

    return (retVal);
}

void Resmgr_Udma_eventFreeResource(Udma_DrvHandle drvHandle,
                                   Udma_EventHandle eventHandle)
{
    uintptr_t   cookie;

    /* Do atomic link list update as the same is used in ISR */
    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.disableAllIntr != (Udma_OsalDisableAllIntrFxn) NULL_PTR);
    cookie = drvHandle->initPrms.osalPrms.disableAllIntr();

    /*
     * Remove this event node - link previous to next
     * Note: This is applicable only for shared mode. But the pointers will
     * be NULL_PTR for exclusive mode. Hence the logic is same.
     */
    /* Link previous's next to current's next */
    if(NULL_PTR != eventHandle->prevEvent)
    {
        eventHandle->prevEvent->nextEvent = eventHandle->nextEvent;
    }
    /* Link next's previous to current's previous */
    if(NULL_PTR != eventHandle->nextEvent)
    {
        eventHandle->nextEvent->prevEvent = eventHandle->prevEvent;
    }

    Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.restoreAllIntr != (Udma_OsalRestoreAllIntrFxn) NULL_PTR);
    drvHandle->initPrms.osalPrms.restoreAllIntr(cookie);

    if(NULL_PTR != eventHandle->hwiHandle)
    {
        Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.unRegisterIntr != (Udma_OsalUnRegisterIntrFxn) NULL_PTR);
        drvHandle->initPrms.osalPrms.unRegisterIntr(eventHandle->hwiHandle);
        eventHandle->hwiHandle = NULL_PTR;
    }
    if(UDMA_INTR_INVALID != eventHandle->coreIntrNum)
    {
        Udma_rmFreeIrIntr(eventHandle->irIntrNum, drvHandle);
        eventHandle->irIntrNum = UDMA_INTR_INVALID;
        eventHandle->coreIntrNum = UDMA_INTR_INVALID;
    }

    if(UDMA_EVENT_INVALID != eventHandle->globalEvent)
    {
        /* Reset steering */
        Udma_rmFreeEvent(eventHandle->globalEvent, drvHandle);
        eventHandle->globalEvent = UDMA_EVENT_INVALID;
    }
    if(UDMA_EVENT_INVALID != eventHandle->vintrBitNum)
    {
        Udma_rmFreeVintrBit(eventHandle->vintrBitNum, drvHandle, eventHandle);
        eventHandle->vintrBitNum = UDMA_EVENT_INVALID;
    }
    if(UDMA_EVENT_INVALID != eventHandle->vintrNum)
    {
        Udma_rmFreeVintr(eventHandle->vintrNum, drvHandle);
        eventHandle->vintrNum = UDMA_EVENT_INVALID;
    }

    return;
}

static void Resmgr_Udma_eventIsrFxn(uintptr_t arg)
{
    uint32_t            vintrBitNum;
    uint32_t            vintrNum;
    Udma_EventHandle    eventHandle = (Udma_EventHandle) arg;
    Udma_DrvHandle      drvHandle;
    Udma_EventPrms     *eventPrms;

    drvHandle = eventHandle->drvHandle;
    vintrNum = eventHandle->vintrNum;
    Udma_assert(drvHandle, vintrNum != UDMA_EVENT_INVALID);
    /* Loop through all the shared events. In case of exclusive events,
     * the next event is NULL_PTR and the logic remains same and the while breaks */
    while(eventHandle != NULL_PTR)
    {
        /* There is no valid VINT bit for global master event */
        if(UDMA_EVENT_TYPE_MASTER != eventHandle->eventPrms.eventType)
        {
            Udma_assert(drvHandle,
                eventHandle->vintrBitNum <= UDMA_MAX_EVENTS_PER_VINTR);
            vintrBitNum = vintrNum * UDMA_MAX_EVENTS_PER_VINTR;
            vintrBitNum += eventHandle->vintrBitNum;

            /* Check IA status */
            if((bool)true == CSL_intaggrIsIntrPending(&drvHandle->iaRegs, vintrBitNum, (bool)true))
            {
                /* Clear the interrupt */
                (void) CSL_intaggrClrIntr(&drvHandle->iaRegs, vintrBitNum);

                /* Notify through callback if registered */
                eventPrms = &eventHandle->eventPrms;
                if((Udma_EventCallback) NULL_PTR != eventPrms->eventCb)
                {
                    eventPrms->eventCb(
                        eventHandle, eventPrms->eventType, eventPrms->appData);
                }
            }
        }

        /* Move to next shared event */
        eventHandle = eventHandle->nextEvent;
    }

    return;
}

int32_t Resmgr_Udma_eventProgramSteering(Udma_DrvHandle drvHandle,
                                         Udma_EventHandle eventHandle)
{
    int32_t                 retVal = UDMA_SOK;
    Udma_ChHandle           chHandle;
    Udma_EventPrms         *eventPrms;

    Udma_assert(drvHandle, eventHandle != NULL_PTR);
    eventPrms = &eventHandle->eventPrms;

    if(UDMA_EVENT_TYPE_TR == eventPrms->eventType)
    {
        Udma_assert(drvHandle, eventPrms->chHandle != NULL_PTR);
        chHandle = eventPrms->chHandle;

        if(((chHandle->chType & UDMA_CH_FLAG_BLK_COPY) == UDMA_CH_FLAG_BLK_COPY) ||
            ((chHandle->chType & UDMA_CH_FLAG_RX) == UDMA_CH_FLAG_RX))
        {
            /* Done by DMSC RM */
        }
        else if((chHandle->chType & UDMA_CH_FLAG_TX) == UDMA_CH_FLAG_TX)
        {
            /* Done by DMSC RM */
        }
        else
        {
#if (UDMA_NUM_UTC_INSTANCE > 0)
            uint32_t                evtNum;
            uint32_t                utcChNum;
            const Udma_UtcInstInfo *utcInfo;

            evtNum = Udma_eventGetId(eventHandle);
            utcInfo = chHandle->utcInfo;
            Udma_assert(drvHandle, utcInfo != NULL_PTR);
            if(UDMA_UTC_TYPE_DRU == utcInfo->utcType)
            {
                Udma_assert(drvHandle, utcInfo->druRegs != NULL_PTR);
                Udma_assert(drvHandle, chHandle->extChNum >= utcInfo->startCh);
                utcChNum = chHandle->extChNum - utcInfo->startCh;

                retVal = CSL_druChSetEvent(utcInfo->druRegs, utcChNum, evtNum);
                if(CSL_PASS != retVal)
                {
                    Udma_printf(drvHandle,
                        "[Error] DRU channel set event failed!!\n");
                }
            }
            else
            {
                retVal = UDMA_EFAIL;
                Udma_printf(drvHandle,
                    "[Error] TR events not possible in other external channels!!\n");
            }
#endif
        }

        if(UDMA_SOK == retVal)
        {
            /* Mark OES alloc flag */
            chHandle->chOesAllocDone = TRUE;
        }
    }

    return (retVal);
}

int32_t Resmgr_Udma_eventConfig(Udma_DrvHandle drvHandle,
                                Udma_EventHandle eventHandle)
{
    int32_t             retVal = UDMA_SOK;
    uint32_t            vintrNum, coreIntrNum;
    Udma_ChHandle       chHandle;
    Udma_RingHandle     ringHandle;
#if (UDMA_SOC_CFG_RING_MON_PRESENT == 1)
    Udma_RingMonHandle  monHandle;
#endif
    Udma_EventPrms     *eventPrms;
    struct tisci_msg_rm_irq_set_req     rmIrqReq;
    struct tisci_msg_rm_irq_set_resp    rmIrqResp;

    Udma_assert(drvHandle, eventHandle != NULL_PTR);
    eventPrms = &eventHandle->eventPrms;

    rmIrqReq.valid_params           = 0U;
    rmIrqReq.global_event           = 0U;
    rmIrqReq.src_id                 = 0U;
    rmIrqReq.src_index              = 0U;
    rmIrqReq.dst_id                 = 0U;
    rmIrqReq.dst_host_irq           = 0U;
    rmIrqReq.ia_id                  = 0U;
    rmIrqReq.vint                   = 0U;
    rmIrqReq.vint_status_bit_index  = 0U;
    rmIrqReq.secondary_host         = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;

    /* Event is always allocated except global master event */
    if(UDMA_EVENT_TYPE_MASTER != eventPrms->eventType)
    {
        rmIrqReq.valid_params  |= TISCI_MSG_VALUE_RM_GLOBAL_EVENT_VALID;
        rmIrqReq.global_event   = (uint16_t)Udma_eventGetId(eventHandle);
    }

    /* IR setup */
    if(UDMA_INTR_INVALID != eventHandle->coreIntrNum)
    {
        /* Route Virtual interrupt (VINT) to core interrupt */
        Udma_assert(drvHandle, eventHandle->vintrNum != UDMA_EVENT_INVALID);

        rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
        rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;
        rmIrqReq.dst_id        = drvHandle->devIdCore;
        rmIrqReq.dst_host_irq  = (uint16_t)eventHandle->coreIntrNum;
    }

    /* Get master IA register number for slaves */
    if(NULL_PTR != eventHandle->eventPrms.masterEventHandle)
    {
        vintrNum = eventHandle->eventPrms.masterEventHandle->vintrNum;
    }
    else
    {
        /* For master use the own register number */
        vintrNum = eventHandle->vintrNum;
    }
    Udma_assert(drvHandle, vintrNum != UDMA_EVENT_INVALID);
    rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_IA_ID_VALID;
    rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_VINT_VALID;
    rmIrqReq.ia_id         = drvHandle->devIdIa;
    rmIrqReq.vint          = (uint16_t)vintrNum;

    if(UDMA_EVENT_INVALID != eventHandle->vintrBitNum)
    {
        Udma_assert(drvHandle,
            eventHandle->vintrBitNum <= UDMA_MAX_EVENTS_PER_VINTR);
        rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_VINT_STATUS_BIT_INDEX_VALID;
        rmIrqReq.vint_status_bit_index  = (uint8_t)eventHandle->vintrBitNum;
    }

    if((UDMA_EVENT_TYPE_DMA_COMPLETION == eventPrms->eventType) ||
       (UDMA_EVENT_TYPE_TEARDOWN_PACKET == eventPrms->eventType))
    {
        Udma_assert(drvHandle, eventPrms->chHandle != NULL_PTR);
        chHandle = eventPrms->chHandle;

        rmIrqReq.src_id = drvHandle->srcIdRingIrq;
        if(UDMA_EVENT_TYPE_DMA_COMPLETION == eventPrms->eventType)
        {
            Udma_assert(drvHandle, chHandle->cqRing != NULL_PTR);
            Udma_assert(drvHandle,
                chHandle->cqRing->ringNum != UDMA_RING_INVALID);
            rmIrqReq.src_index = chHandle->cqRing->ringNum;
            if((chHandle->chType & UDMA_CH_FLAG_BLK_COPY) == UDMA_CH_FLAG_BLK_COPY)
            {
                rmIrqReq.src_index += drvHandle->blkCopyRingIrqOffset;
            }
            else if((chHandle->chType & UDMA_CH_FLAG_TX) == UDMA_CH_FLAG_TX)
            {
                rmIrqReq.src_index += drvHandle->txRingIrqOffset;
            }
            else
            {
                rmIrqReq.src_index += drvHandle->rxRingIrqOffset;
            }
        }
        else
        {
            /* For devices like AM64x in which Teardown event is not supported,
             * it dosen't reach here since it is bypassed in eventRegister */
            Udma_assert(drvHandle, chHandle->tdCqRing != NULL_PTR);
            Udma_assert(drvHandle,
                chHandle->tdCqRing->ringNum != UDMA_RING_INVALID);
            rmIrqReq.src_index = chHandle->tdCqRing->ringNum;
            rmIrqReq.src_index += TISCI_RINGACC0_OES_IRQ_SRC_IDX_START;
        }
    }

    if(UDMA_EVENT_TYPE_TR == eventPrms->eventType)
    {
        if(UDMA_INST_TYPE_LCDMA_PKTDMA == drvHandle->instType)
        {
            /* TR Event is not supported for PKTMDA */
            retVal = UDMA_EFAIL;
            Udma_printf(drvHandle, "[Error] TR event not supported for PKTDMA instance; Event config failed!!!\n");
        }
        else
        {
            Udma_assert(drvHandle, eventPrms->chHandle != NULL_PTR);
            chHandle = eventPrms->chHandle;
            rmIrqReq.src_id = drvHandle->srcIdTrIrq;
            if((chHandle->chType & UDMA_CH_FLAG_BLK_COPY) == UDMA_CH_FLAG_BLK_COPY)
            {
                Udma_assert(drvHandle, chHandle->txChNum != UDMA_DMA_CH_INVALID);
                rmIrqReq.src_index = (uint16_t)chHandle->txChNum;
                rmIrqReq.src_index += drvHandle->blkCopyTrIrqOffset;
            }
            else if((chHandle->chType & UDMA_CH_FLAG_RX) == UDMA_CH_FLAG_RX)
            {
                Udma_assert(drvHandle, chHandle->rxChNum != UDMA_DMA_CH_INVALID);
                rmIrqReq.src_index = (uint16_t)chHandle->rxChNum;
                rmIrqReq.src_index += drvHandle->rxTrIrqOffset;
            }
            else if((chHandle->chType & UDMA_CH_FLAG_TX) == UDMA_CH_FLAG_TX)
            {
                Udma_assert(drvHandle, chHandle->txChNum != UDMA_DMA_CH_INVALID);
                rmIrqReq.src_index = (uint16_t)chHandle->txChNum;
                rmIrqReq.src_index += drvHandle->txTrIrqOffset;
            }
            else
            {
                /* DMSC RM doesn't program the DRU OES - program locally for now
                * in Resmgr_Udma_eventProgramSteering() */
                /* Use a SRC which doesn't need a OES programming so that DMSC will skip */
                rmIrqReq.src_id = drvHandle->devIdIa;
                rmIrqReq.src_index = 0U;                /* Not used by DMSC RM */
            }
        }
    }

    if(UDMA_EVENT_TYPE_RING == eventPrms->eventType)
    {
        Udma_assert(drvHandle, eventPrms->ringHandle != NULL_PTR);
        ringHandle = eventPrms->ringHandle;
        Udma_assert(drvHandle, ringHandle->ringNum != UDMA_RING_INVALID);

        rmIrqReq.src_id     = drvHandle->srcIdRingIrq;
        rmIrqReq.src_index  = ringHandle->ringNum;
        rmIrqReq.src_index += drvHandle->txRingIrqOffset;

#if ((UDMA_NUM_MAPPED_TX_GROUP + UDMA_NUM_MAPPED_RX_GROUP) > 0)
        /* For mapped RX rings, subtract the already added TX offset and add RX offset */
        if((ringHandle->mappedRingGrp >= UDMA_NUM_MAPPED_TX_GROUP) &&
           (ringHandle->mappedRingGrp < (UDMA_NUM_MAPPED_TX_GROUP + UDMA_NUM_MAPPED_RX_GROUP)))
        {
            rmIrqReq.src_index -= drvHandle->txRingIrqOffset;
            rmIrqReq.src_index += drvHandle->rxRingIrqOffset;
        }
#endif 
    }

    if(UDMA_EVENT_TYPE_RING_MON == eventPrms->eventType)
    {
#if (UDMA_SOC_CFG_RING_MON_PRESENT == 1)
        Udma_assert(drvHandle, eventPrms->monHandle != NULL_PTR);
        monHandle = eventPrms->monHandle;
        Udma_assert(drvHandle, monHandle->ringMonNum != UDMA_RING_MON_INVALID);

        rmIrqReq.src_id     = drvHandle->devIdRing;
        rmIrqReq.src_index  = monHandle->ringMonNum;
        rmIrqReq.src_index += TISCI_RINGACC0_MON_IRQ_SRC_IDX_START; 
#else
        retVal = UDMA_EFAIL;
        Udma_printf(drvHandle, "[Error] Ring Monitor not supported; Event Config failed!!!\n");
#endif
    }

    if(UDMA_EVENT_TYPE_ERR_OUT_OF_RANGE_FLOW == eventPrms->eventType)
    {
#if (UDMA_SOC_CFG_UDMAP_PRESENT == 1)
        rmIrqReq.src_id     = drvHandle->devIdUdma;
        rmIrqReq.src_index  = TISCI_UDMAP0_RX_FLOW_EOES_IRQ_SRC_IDX_START;  
#else
        retVal = UDMA_EFAIL;
        Udma_printf(drvHandle, "[Error] Event for trapping out of range flow ID received on a packet, not supported!!!\n");
#endif
    }

    if(UDMA_SOK == retVal)
    {
        /* Program Output event steering based on event type */
        retVal = Resmgr_Udma_eventProgramSteering(drvHandle, eventHandle);
        if(UDMA_SOK != retVal)
        {
            Udma_printf(drvHandle, "[Error] OES program failed!!!\n");
        }
    }

    if(UDMA_SOK == retVal)
    {
        if((drvHandle->instType    != UDMA_INST_TYPE_NORMAL) &&
           (UDMA_EVENT_TYPE_MASTER == eventPrms->eventType))
        {
            /* In case of devices like AM64x, where there are no IRs to configure 
               no need to config the Global Master event using DMSC RM */
        }
        else
        {
            /* Config event */
            retVal = Sciclient_rmIrqSet(
                         &rmIrqReq, &rmIrqResp, UDMA_SCICLIENT_TIMEOUT);
            if(CSL_PASS != retVal)
            {
                Udma_printf(drvHandle, "[Error] Sciclient event config failed!!!\n");
            }
        }
    }

    if(UDMA_SOK == retVal)
    {
        /* Register after programming IA, so that when spurious interrupts
         * occur, we have a sane state/variables to handle it */
        if((UDMA_INTR_INVALID != eventHandle->coreIntrNum) &&
           (FALSE == eventHandle->eventPrms.osalRegisterDisable))
        {
            coreIntrNum = eventHandle->coreIntrNum;
#if defined (__C7100__)
            CSL_ClecEventConfig evtCfg;
            uint32_t            clecEvtNum;
            Udma_RmInitPrms    *rmInitPrms = &drvHandle->initPrms.rmInitPrms;

            /* CLEC programming required for C7x */
            coreIntrNum = eventHandle->irIntrNum - rmInitPrms->startIrIntr;
            coreIntrNum += rmInitPrms->startC7xCoreIntr;
            evtCfg.secureClaimEnable = FALSE;
            evtCfg.evtSendEnable     = TRUE;
            evtCfg.rtMap             = drvHandle->clecRtMap;
            evtCfg.extEvtNum         = 0x00U;   /* Not used */
            evtCfg.c7xEvtNum         = coreIntrNum;
            clecEvtNum = eventHandle->coreIntrNum + drvHandle->clecOffset;
            CSL_clecConfigEvent(drvHandle->clecRegs, clecEvtNum, &evtCfg);
#endif

            /* Register interrupt only when asked for */
            Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.registerIntr != (Udma_OsalRegisterIntrFxn) NULL_PTR);
            eventHandle->hwiHandle =
                drvHandle->initPrms.osalPrms.registerIntr(
                    &Resmgr_Udma_eventIsrFxn,
                    coreIntrNum,
                    eventHandle->eventPrms.intrPriority,
                    eventHandle);
            if(NULL_PTR == eventHandle->hwiHandle)
            {
                retVal = UDMA_EFAIL;
                Udma_printf(drvHandle,
                            "[Error] OSAL intr registration failed!!!\n");
            }
        }
    }

    return (retVal);
}

int32_t Resmgr_Udma_eventAllocResource(Udma_DrvHandle drvHandle,
                                       Udma_EventHandle eventHandle)
{
    int32_t                 retVal = UDMA_SOK;
    uint32_t                vintrNum;
    uint32_t                preferredIrIntrNum;
    const Udma_EventPrms   *eventPrms;
    Udma_EventHandle        lastEvent;
    uintptr_t               cookie;

    Udma_assert(drvHandle, eventHandle != NULL_PTR);
    eventPrms = &eventHandle->eventPrms;

    /* Allocate event irrespective of all modes except global master event */
    if(UDMA_EVENT_TYPE_MASTER != eventPrms->eventType)
    {
        eventHandle->globalEvent = Udma_rmAllocEvent(drvHandle);
        if(UDMA_EVENT_INVALID == eventHandle->globalEvent)
        {
            retVal = UDMA_EALLOC;
            Udma_printf(drvHandle, "[Error] Global event alloc failed!!!\n");
        }
        else
        {
            Udma_assert(drvHandle, drvHandle->iaRegs.pImapRegs != NULL_PTR);
            eventHandle->pIaGeviRegs =
                &drvHandle->iaRegs.pImapRegs->GEVI[eventHandle->globalEvent];
        }
    }

    if(UDMA_SOK == retVal)
    {
        /* Allocate IA register for master and exclusive events */
        if((UDMA_EVENT_MODE_EXCLUSIVE == eventPrms->eventMode) ||
            ((UDMA_EVENT_MODE_SHARED == eventPrms->eventMode) &&
                (NULL_PTR == eventPrms->masterEventHandle)))
        {
            eventHandle->vintrNum = Udma_rmAllocVintr(drvHandle);
            if(UDMA_EVENT_INVALID == eventHandle->vintrNum)
            {
                retVal = UDMA_EALLOC;
                Udma_printf(drvHandle, "[Error] VINTR alloc failed!!!\n");
            }
        }
    }

    if(UDMA_SOK == retVal)
    {
        /* Allocate IA bit for all event modes except global master event */
        if(UDMA_EVENT_TYPE_MASTER != eventPrms->eventType)
        {
            eventHandle->vintrBitNum = Udma_rmAllocVintrBit(eventHandle);
            if(UDMA_EVENT_INVALID == eventHandle->vintrBitNum)
            {
                retVal = UDMA_EALLOC;
                Udma_printf(drvHandle, "[Error] VINTR bit alloc failed!!!\n");
            }
        }
    }

    if(UDMA_SOK == retVal)
    {
        /* Allocate interrupt when callback is requested and only for
         * exclusive and master shared events (master handle is NULL_PTR) */
        if(((((Udma_EventCallback) NULL_PTR != eventPrms->eventCb) ||
                    (TRUE == eventPrms->osalRegisterDisable)) &&
                (NULL_PTR == eventPrms->masterEventHandle)) ||
            (UDMA_EVENT_TYPE_MASTER == eventPrms->eventType))
        {
            if(UDMA_CORE_INTR_ANY != eventPrms->preferredCoreIntrNum)
            {
                preferredIrIntrNum = Udma_rmTranslateCoreIntrInput(drvHandle, eventPrms->preferredCoreIntrNum);
            }
            else
            {
                preferredIrIntrNum = eventPrms->preferredCoreIntrNum;
            }
            if(UDMA_INTR_INVALID != preferredIrIntrNum)
            {
                eventHandle->irIntrNum =
                    Udma_rmAllocIrIntr(preferredIrIntrNum, drvHandle);
                if(UDMA_INTR_INVALID != eventHandle->irIntrNum)
                {
                    eventHandle->coreIntrNum = Udma_rmTranslateIrOutput(drvHandle, eventHandle->irIntrNum);
                }
            }
            Udma_printf(drvHandle, "eventHandle->coreIntrNum = %d!!!\n", eventHandle->coreIntrNum);
            if(UDMA_INTR_INVALID == eventHandle->coreIntrNum)
            {
                retVal = UDMA_EALLOC;
                Udma_printf(drvHandle, "[Error] Core intr alloc failed!!!\n");
            }
        }
    }

    if(UDMA_SOK == retVal)
    {
        /* Do atomic link list update as the same is used in ISR */
        Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.disableAllIntr != (Udma_OsalDisableAllIntrFxn) NULL_PTR);
        cookie = drvHandle->initPrms.osalPrms.disableAllIntr();

        /* Link shared events to master event */
        eventHandle->prevEvent = (Udma_EventHandle) NULL_PTR;
        eventHandle->nextEvent = (Udma_EventHandle) NULL_PTR;
        if(NULL_PTR != eventPrms->masterEventHandle)
        {
            /* Go to the last node - insert node at the end */
            lastEvent = eventPrms->masterEventHandle;
            while(NULL_PTR != lastEvent->nextEvent)
            {
                /* Move to next node */
                lastEvent = lastEvent->nextEvent;
            }
            /* Cross link between last and current node */
            eventHandle->prevEvent = lastEvent;
            lastEvent->nextEvent   = eventHandle;
        }
        Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.restoreAllIntr != (Udma_OsalRestoreAllIntrFxn) NULL_PTR);
        drvHandle->initPrms.osalPrms.restoreAllIntr(cookie);
    }

    if(UDMA_SOK == retVal)
    {
        if(UDMA_EVENT_TYPE_TR == eventPrms->eventType)
        {
            Udma_ChHandle chHandle;
            Udma_assert(drvHandle, eventPrms->chHandle != NULL_PTR);
            chHandle = eventPrms->chHandle;

            if(TRUE == chHandle->chOesAllocDone)
            {
                retVal = UDMA_EALLOC;
                Udma_printf(drvHandle, "[Error] Channel OES not de-allocated!!!\n");
            }
        }
    }

    if(UDMA_SOK != retVal)
    {
        Resmgr_Udma_eventFreeResource(drvHandle, eventHandle);
    }
    else
    {
        if(NULL_PTR == eventPrms->masterEventHandle)
        {
            vintrNum = eventHandle->vintrNum;
        }
        else
        {
            /* Use master event's info */
            vintrNum = eventPrms->masterEventHandle->vintrNum;
        }
        Udma_assert(drvHandle, drvHandle->iaRegs.pIntrRegs != NULL_PTR);
        eventHandle->pIaVintrRegs = &drvHandle->iaRegs.pIntrRegs->VINT[vintrNum];
    }

    return (retVal);
}

int32_t Resmgr_Udma_eventRegister(Udma_DrvHandle drvHandle,
                           Udma_EventHandle eventHandle,
                           Udma_EventPrms *eventPrms)
{
    int32_t         retVal = UDMA_SOK;
    uint32_t        allocDone = (uint32_t) FALSE;

    /* Error check */
    if((NULL_PTR == drvHandle) || (NULL_PTR == eventHandle) || (NULL_PTR == eventPrms))
    {
        retVal = UDMA_EBADARGS;
    }
    if(UDMA_SOK == retVal)
    {
        if(drvHandle->drvInitDone != UDMA_INIT_DONE)
        {
            retVal = UDMA_EFAIL;
        }
    }

    if(UDMA_SOK == retVal)
    {
        retVal = Resmgr_Udma_eventCheckParams(drvHandle, eventPrms);
    }

    if(UDMA_SOK == retVal)
    {
        /* Copy and init parameters */
        (void) memcpy(
            &eventHandle->eventPrms, eventPrms, sizeof(eventHandle->eventPrms));
        eventHandle->drvHandle      = drvHandle;
        eventHandle->globalEvent    = UDMA_EVENT_INVALID;
        eventHandle->vintrNum       = UDMA_EVENT_INVALID;
        eventHandle->vintrBitNum    = UDMA_EVENT_INVALID;
        eventHandle->irIntrNum      = UDMA_INTR_INVALID;
        eventHandle->coreIntrNum    = UDMA_INTR_INVALID;
        eventHandle->nextEvent      = (Udma_EventHandle) NULL_PTR;
        eventHandle->prevEvent      = (Udma_EventHandle) NULL_PTR;
        eventHandle->hwiHandle      = NULL_PTR;
        eventHandle->vintrBitAllocFlag = 0U;
        eventHandle->pIaGeviRegs    = (volatile CSL_intaggr_imapRegs_gevi *) NULL_PTR;
        eventHandle->pIaVintrRegs   = (volatile CSL_intaggr_intrRegs_vint *) NULL_PTR;
    }

    if(UDMA_SOK == retVal)
    {
        if ((UDMA_INST_TYPE_NORMAL           != drvHandle->instType) && 
            (UDMA_EVENT_TYPE_TEARDOWN_PACKET == eventPrms->eventType))
        {
            /* In case of devices like AM64x, Teardown is not supported.
            Therefore no need to allocate resource and configure teardown event.
            
            eventHandle is already populated with drvHandle and eventPrms, 
            becase during Unregistering this event, 
            the instType in DrvHandle and evenType in eventPrms
            are required to bypass the eventReset 
            (Since only evenHandle is passed to eventUnRegister) */
        }
        else
        {   
            /* Alloc event resources */
            retVal = Resmgr_Udma_eventAllocResource(drvHandle, eventHandle);
            if(UDMA_SOK == retVal)
            {
                allocDone = (uint32_t) TRUE;
            }
            else
            {
                Udma_printf(drvHandle, "[Error] Event resource allocation failed!!\n");
            }

            if(UDMA_SOK == retVal)
            {
                /* Set init flag as events are allocated and event config expects
                * this flag to be set */
                eventHandle->eventInitDone = UDMA_INIT_DONE;

                /* Configure Event */
                retVal = Resmgr_Udma_eventConfig(drvHandle, eventHandle);
                if(UDMA_SOK == retVal)
                {
                    allocDone = (uint32_t) TRUE;
                }
                else
                {
                    Udma_printf(drvHandle, "[Error] Event config failed!!\n");
                }
            }

            if(UDMA_SOK != retVal)
            {
                /* Error. Free-up resource if allocated */
                if(((uint32_t) TRUE) == allocDone)
                {
                    Resmgr_Udma_eventFreeResource(drvHandle, eventHandle);
                    eventHandle->eventInitDone = UDMA_DEINIT_DONE;
                }
            }
            else
            {
                /* Copy the allocated resource info */
                Udma_assert(drvHandle, eventHandle->pIaVintrRegs != NULL_PTR);
                eventPrms->intrStatusReg    = &eventHandle->pIaVintrRegs->STATUSM;
                eventPrms->intrClearReg     = &eventHandle->pIaVintrRegs->STATUS_CLEAR;
                if(eventHandle->vintrBitNum != UDMA_EVENT_INVALID)
                {
                    eventPrms->intrMask     = ((uint64_t)1U << eventHandle->vintrBitNum);
                }
                else
                {
                    /* No VINT bit for global master event */
                    eventPrms->intrMask     = 0U;
                }
                if(NULL_PTR == eventHandle->eventPrms.masterEventHandle)
                {
                    /* This is master handle - copy directly from here itself */
                    eventPrms->coreIntrNum  = eventHandle->coreIntrNum;
                }
                else
                {
                    /* Copy core number from master handle */
                    eventPrms->coreIntrNum    =
                        eventHandle->eventPrms.masterEventHandle->coreIntrNum;
                }
            }
        }
    }
    return (retVal);
}

int32_t Resmgr_Udma_eventInit(Udma_DrvHandle drvHandle)
{
    int32_t  retVal = UDMA_SOK;
    Udma_EventPrms  eventPrms;

    UdmaEventPrms_init(&eventPrms);
    eventPrms.eventType = UDMA_EVENT_TYPE_MASTER;
    eventPrms.eventMode = UDMA_EVENT_MODE_SHARED;
    retVal = Resmgr_Udma_eventRegister(
                 drvHandle, &drvHandle->globalEventObj, &eventPrms);
    if(UDMA_SOK != retVal)
    {
        Udma_printf(drvHandle,
            "[Error] Global master event register failed!!!\n");
    }
    else
    {
        drvHandle->globalEventHandle = &drvHandle->globalEventObj;
    }

    return retVal;
}

void Resmgr_Udma_setup(void)
{
    int32_t                             retVal = UDMA_SOK;
#if defined (SOC_AM62X)
    uint32_t        instId = UDMA_INST_ID_START;
    uint32_t        noUdmaBlocks = 2;
#elif defined (SOC_AM62A) || defined (SOC_AM62PX)
    uint32_t        instId = UDMA_INST_ID_START;
    uint32_t        noUdmaBlocks = 3;
#else
    uint32_t        instId = UDMA_INST_ID_MAIN_0;
    uint32_t        noUdmaBlocks = 1;
#endif
    struct tisci_msg_rm_proxy_cfg_req   req;
    Udma_DrvHandle  drvHandle;
    Udma_InitPrms   initPrms;

    for (int i = 0; i < noUdmaBlocks; i++ ) 
    {
        /* UDMA driver init */
        drvHandle = &gUdmaDrvObj[instId];
        UdmaInitPrms_init(instId, &initPrms);

        /* Set virtToPhy and PhytoVirt to support QNX */
        initPrms.virtToPhyFxn = &Resmgr_Udma_qnxVirtToPhyFxn;
        initPrms.phyToVirtFxn = &Resmgr_Udma_qnxPhyToVirtFxn;
        initPrms.skipGlobalEventReg = TRUE;
        
        Udma_init(drvHandle, &initPrms);

        req.valid_params = 0U;
#if defined (SOC_AM62X) || defined (SOC_AM62A) || defined (SOC_AM62PX)
        req.nav_id       = drvHandle->devIdPsil;
#else
        req.nav_id       = drvHandle->devIdProxy;
#endif
        req.index        = drvHandle->initPrms.rmInitPrms.proxyThreadNum;
        retVal = Sciclient_rmSetProxyCfg(&req, UDMA_SCICLIENT_TIMEOUT);
        if(UDMA_SOK != retVal)
        {
            Udma_printf(drvHandle, "[Error] SciClient Set proxy config failed!!!\n");
            Udma_assert(drvHandle, retVal==UDMA_SOK);
        }

        Udma_assert(drvHandle, drvHandle->initPrms.osalPrms.createMutex != (Udma_OsalMutexCreateFxn) NULL_PTR);
        drvHandle->rmLock = drvHandle->initPrms.osalPrms.createMutex();
        Udma_assert(drvHandle, drvHandle->rmLock != (Udma_OsalMutexCreateFxn) NULL_PTR);

        drvHandle->printLock = drvHandle->initPrms.osalPrms.createMutex();
        Udma_assert(drvHandle, drvHandle->printLock != (Udma_OsalMutexCreateFxn) NULL_PTR);

        retVal = Resmgr_Udma_eventInit(drvHandle);
        if(UDMA_SOK != retVal)
        {
            Udma_printf(drvHandle, "[Error] Resmgr_Udma_eventInit failed!!!\n");
            Udma_assert(drvHandle, retVal==UDMA_SOK);
        }
        instId++;
    }
}
