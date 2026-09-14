/*
 *  Copyright (c) Texas Instruments Incorporated 2024
 *  All rights reserved.
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

/**
 *  \file ipc_virtio.c
 *
 *  \brief Implementation of ipc rtos virtio.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <CddIpc/ipc_baremetal_hw/ipc.h>
#include <string.h>

#include "ipc_virtioPrivate.h"
#include "ipc_vring.h"
#include "ipc_mailbox.h"
#include "ipc_utils.h"
#include "ipc_priv.h"

#include <hw_include/arch/r5/lld_cache.h>

/* Vring alignment */
#if defined(SOC_AM275X) || defined(SOC_AM62AX) || defined(SOC_AM62PX) || defined(SOC_AM62DX) || defined(SOC_AM62X)
#if (CDD_IPC_REMOTE_CORE_QNX == STD_ON)
#define IPC_VRING_ALIGNMENT    (0x1000U)
#else
#define IPC_VRING_ALIGNMENT    (0x4U)
  #endif
#else 
  #define IPC_VRING_ALIGNMENT    (0x1000U)
#endif


#define IPC_VRING_BUF_CNT      (CDD_IPC_NUM_VRING_BUFF)

typedef struct Ipc_VirtioInfo_s
{
    uint32  daTx;       /* Buffer for TX to remote core */
    uint32  daRx;       /* Buffer for RX from remote core */
    uint32  primeBuf;   /* Address for prime buffer */
    uint32  align;      /* Data alignment */
    uint32  num;        /* Number of buffer */
    uint32  selfId;     /* Self procId */
    uint32  remoteId;   /* Remote procId */
    uint32  txNotifyId; /* Notify Id for TX */
    uint32  rxNotifyId; /* Notify Id for RX */
} Ipc_VirtioInfo;


/* TranslationEntry */
typedef struct Ipc_TranslationEntry_s
{
    uint32  pa;  /* physical address */
    uint32 va;  /* virtual address  */
    uint32  len; /* Length of buffer */
}Ipc_TranslationEntry;

#define   IPC_TABLE_MAX_CNT   64

/* IPC PhyAddr to VirtAddr translation table */
typedef struct Ipc_TranslationTable_s
{
    uint32              count;
    /**< Number of entryies in the translation table */

    Ipc_TranslationEntry  entry[IPC_TABLE_MAX_CNT];
    /**< Entries in the table, there should be 3-entries for
     * each remote cores */

}Ipc_TranslationTable;

typedef struct Ipc_NotifyIdEntry_s
{
    sint32    txNotifyId;
    sint32    rxNotifyId;
} Ipc_NotifyIdEntry;

#define CDD_IPC_START_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

sint32  virtio_cnt = 0;

#define CDD_IPC_STOP_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

/* VRING mapping index array from src core to dst, '-1' means NO VRING, */
#if defined (SOC_AM275X)
#define CDD_IPC_START_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"
#define CDD_IPC_STOP_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"
#endif

#if defined (SOC_AM62X) || defined (SOC_AM62AX) || defined (SOC_AM62PX) || defined (SOC_AM62DX) || defined (SOC_AM275X) || defined (SOC_J722S)
static uint32 Cdd_Ipc_vringId[IPC_MAX_PROCS][IPC_MAX_PROCS];
#endif

/**
 *  \brief Used for defining the size of the virtqueue registry
 */
#define MAX_VIRTQUEUES          (IPC_MAX_PROCS * 2U)
#define MAX_VQ_PAIRS            ((MAX_VIRTQUEUES+1U)/2U)


#define DIV_ROUND_UP(n,d)   (((n) + (d) - 1) / (d))
#define RP_MSG_BUF_SIZE     (512U)

/* The vring will occupy 3 pages
 *
 * RP_MSG_RING_SIZE = ((DIV_ROUND_UP(vring_size(RP_MSG_NUM_BUFS,
 *                    RP_MSG_VRING_ALIGN), PAGE_SIZE)) * PAGE_SIZE)
 *
 * The total IPC space needed to communicate with a remote processor
 *
 * RPMSG_IPC_MEM = (RP_MSG_BUFS_SPACE + 2 * RP_MSG_RING_SIZE)
 */

typedef struct Virtio_Object_s
{
    uint16          id;
    /**< Id for this VirtQueue_Object */

    Virtio_callback   callback;
    /**< The function to call when buffers are consumed (can be NULL) */

    uint32*         callback_priv;
    /**< The private data to pass to the callback (can be NULL) */

    struct VRing      vring;
    /**< Shared state */

    uint16          last_avail_idx;
    /**< Last available index; updated by VirtQueue_getAvailBuf */

    uint16          last_used_idx;
    /**< Last available index; updated by VirtQueue_addUsedBuf */

    uint16          procId;
    /** Will eventually be used to kick remote processor */

    uint8          status;
    /**< Address of the vring status variable in shared memory.
     For TX vq, the address is for this proc's variable.
     For RX vq, the address is for the peer proc's variable.*/

    VIRTIO_DIR        direction;
    /**< Indicates TX or RX direction */

    void*             resourceTable;
    /**< Address of resource table. This address is provided by
    application. If the remote core is not A72 or Linux is not
    running, it should be NULL */

    uint32        timeoutCnt;
    /**< Timeout count used for mailbox send. If the mailbox FIFO
     * is full, then how long it should try.
     * 0xFFFFFFFF  --> ForEver
     * */

} Virtio_Object;

/**
 *  \brief Vring parameter
 */
typedef struct Vring_Params_s
{
    uint32  num;
    uint32 addr;
    uint32  align;
} Vring_Params;

#define CDD_IPC_START_SEC_VAR_NO_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

static Virtio_Object *queueRegistry[MAX_VIRTQUEUES];

#define CDD_IPC_STOP_SEC_VAR_NO_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

/* Application provides the memory for storing local Virtio */
#define CDD_IPC_START_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

static void*    vqBaseAddr = NULL;


#define CDD_IPC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

static uint32 vqSizeLeft = 0U;

#define CDD_IPC_STOP_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

#if !defined (SOC_AM275X)
static void*    rscTable   = NULL;
#endif

#define CDD_IPC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

static Ipc_TranslationTable  vrTranslationTable;

#define CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

Virtio_Handle Virtio_create(uint32 vqId, uint32 procId, Virtio_callback callback, Vring_Params *params,
   VIRTIO_DIR direction, uint8 status, uint32 timeoutCnt);
void Virtio_prime(Virtio_Object *vq, uint32 addr, uint32 num);
sint32 VirtioIPC_createVirtioCorePair(Ipc_VirtioInfo* vqInfo, uint32 timeoutCnt);
void Ipc_updateVirtioInfo(uint32 numProc, void *baseAddr, uint32 vrBufSize, Ipc_VirtioInfo* info, uint32 index);

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

void* Ipc_allocVirtio(void)
{
    void  *ptr = NULL;
    if(vqSizeLeft >= sizeof(Virtio_Object))
    {
        ptr = (void*)((uint32)vqBaseAddr + (((uint32)virtio_cnt) * sizeof(Virtio_Object)));
        virtio_cnt++;
        vqSizeLeft -= sizeof(Virtio_Object);
    }
    /**
* TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage for the  'if' statement present in the function Adc_ReadGroup
Is not achievable since number of sample is always greater than 1.

* TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
*/
    else
    {
      /* Nothing to do */
    }
    /* TI_COVERAGE_GAP_STOP */

    return ptr;
}

/**
 * \brief    Add entry to the translation able
 **/

/**
 * \brief Get virual address for given physical address
 **/


sint32 Ipc_physToVirt(uint32 pa, uint32 *va)
{
    uint32                n;
    uint32                offset;
    Ipc_TranslationEntry   *e;
    Std_ReturnType status =  (Std_ReturnType) IPC_EFAIL;
    *va = 0U;
    /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as the function Ipc_physToVirt() is not called in the CDD driver code.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    if(vrTranslationTable.count == 0U)
    {
        *va = pa;
    }

    for (n = 0; n < vrTranslationTable.count; n++)
    {
        e = &vrTranslationTable.entry[n];
        if ((pa >= e->pa) && (pa < (e->pa + e->len)))
        {
            offset = pa - e->pa;
            *va = e->va + offset;
            status = IPC_SOK;
        }
        /* TI_COVERAGE_GAP_STOP */
        else
        {
          /* Do nothing */
        }
    }

    return ((sint32)(status));
}

/**
 * \brief Get physical address from given virual address
 **/


sint8 Ipc_virtToPhys(uint32 va, uint32 *pa)
{
    uint32              n;
    uint32              offset;
    Ipc_TranslationEntry *e;
    Std_ReturnType status = (Std_ReturnType)IPC_EFAIL;
    *pa = 0U;
    /**
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as the function Ipc_virtToPhys() is not called in the CDD driver code.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    if(vrTranslationTable.count == 0U)
    {
        *pa = va;
    }

    for (n = 0; n < vrTranslationTable.count; n++)
    {
        e = &vrTranslationTable.entry[n];
        if ((va >= e->va) && (va < (e->va + e->len)))
        {
            offset = va - e->va;
            *pa = e->pa + offset;
            status = IPC_SOK;
        }
        else
        {
          /* Do Nothing */
        }
    /* TI_COVERAGE_GAP_STOP */
    }

    return ((sint8)(status));
}

/**
 * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as Ipc_getVqObjMemoryRequiredPerCore - This API is used in ETH driver, so it will be covered in ETH LDRA - MCAL-9188(JIRA task)

* TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
*/
uint32 Ipc_getVqObjMemoryRequiredPerCore(void)
{
    /* Two VRing (TX/RX) for each core combination */
    return (sizeof(Virtio_Object) * 2U);
}
/* TI_COVERAGE_GAP_STOP */

#if !defined (SOC_AM275X)
/**
 * \brief    Checks if remote is A72 with Linux
 *
 * \param  procId  [IN] Remote proc Id
 *
 * \return  1 if remote core is A72 & valid resource table
 *          0 otherwise
 *
 */

uint8 Virtio_isRemoteLinux(uint16 procId)
{
    uint8  retVal;

    /*Conditional check added 
     *as different SOC's have 
     *different Linux core nomenclature's*/
    #if defined(SOC_J7200) || defined(SOC_J721E) ||defined (SOC_J721S2) || defined (SOC_J784S4) || defined (SOC_J742S2)
    if((procId == IPC_MPU1_0) && (rscTable != NULL))
    #elif defined(SOC_AM62X)
    if((procId == IPC_A53SS_1) && (rscTable != NULL))
    #elif defined(SOC_AM62AX) || defined(SOC_AM62DX) || defined(SOC_AM62PX) || defined(SOC_J722S)
    if((procId == CDD_IPC_CORE_A53SS0_0) && (rscTable != NULL))
    #endif
    {
        retVal = 1;
    }
    else
    {
        retVal = 0;
    }
    return retVal;
}
#endif

/**
 * \brief  Checks if remote is ready
 *
 * \return  1 if remote proc is is not A72 or resource table is null
 *            or linux vdev status is 0x7
 *          0 if linux vdev status is not 0x7
 *
 */

/**
* TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as this function Ipc_isRemoteReady() checks for RemoteLinux which is never true. Hence, this part cannot be covered.

* TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
*/
uint8 Ipc_isRemoteReady(uint16 procId)
{
    uint8            retVal = TRUE;
#if !defined (SOC_AM275X)
    Ipc_ResourceTable *rsc    = (Ipc_ResourceTable*) NULL;

    if(TRUE == Virtio_isRemoteLinux(procId))
/* TI_COVERAGE_GAP_STOP */
    {
        rsc = (Ipc_ResourceTable*)rscTable;
        //CacheP_Inv(rsc, sizeof(Ipc_ResourceTable));
        MCAL_CSL_armR5CacheInv(rsc, sizeof(Ipc_ResourceTable));
        if(rsc->rpmsg_vdev.status != 0x7U)
        {
            retVal = FALSE;
        }
        else
        {
          /* Do Nothing */
        }
    }
    else
#endif
    {
      /* Do Nothing */
    }

    return retVal;
}

/**
 *  \brief Initializes the registry
 */
sint32 Ipc_initVirtIO(Ipc_VirtIoParams *vqParam)
{
    sint32   retVal = IPC_SOK;

    if( (vqParam == NULL) ||
        (vqParam->vringBufSize < IPC_VRING_BUFFER_SIZE) ||
		(vqParam->vqBufSize == 0U))
    {
        retVal = IPC_EFAIL;
    }

    if(retVal == IPC_SOK)
    {
        /* Initialize the global queue registry */
        memset(queueRegistry, 0, sizeof(queueRegistry));

        vqBaseAddr = (void*)vqParam->vqObjBaseAddr;
        vqSizeLeft = vqParam->vqBufSize;

        /* Initialize the shared page table and VRing */
        retVal = VirtioIPC_init(vqParam);
    }

    return retVal;
}

/**
 *  \brief Saves the resourcetable to be used CDD_IPC_CORE_A53SS0_0
 *  vring for remotecore A72 running Linux
 */
 /**
 *  \brief Placeholder for MMU Address translation
 */
/**
* TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as the MACRO – IPC_EXCLUDE_CTRL_TASKS
 *should not be defined for this part of code to be covered. It is already defined in driver makefile.

* TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
*/
static inline void *mapPAtoVA(uint32 pa)
{
    uint32 va = 0U;

    Ipc_physToVirt(pa, &va);

    return (void*)va;
}
/* TI_COVERAGE_GAP_STOP */


/**
 *  \brief Placeholder for MMU Address translation
 */
static inline uint32 mapVAtoPA(void * va)
{
    uint32 pa;

    Ipc_virtToPhys((uint32)va, &pa);

    return pa;
}

/**
 *  \brief Check the vq status
 */

uint8 Virtio_isReady(Virtio_Handle vq)
{
    return (uint8)(vq->status);
}

/**
 *  \brief Get the processor Id
 */
uint32 Virtio_getProcId(Virtio_Handle vq)
{
    return vq->procId;
}

/**
 *  \brief Virtio kick
 */
sint32 Virtio_kick(Virtio_Handle vq)
{
    uint32 selfId = Ipc_mpGetSelfId();
    sint32 status = IPC_SOK;

#ifdef QNX_OS
    asm("   DSB ST");
#endif

    /* For now, simply interrupt remote processor */
    if (0U == (vq->vring.avail->flags & VRING_AVAIL_F_NO_INTERRUPT))
    {
        status = Ipc_mailboxSend(selfId, vq->procId, vq->id, vq->timeoutCnt);
        if (IPC_SOK != status)
        {
            #if DEBUG_PRINT
            SystemP_printf((sint8 *)"Virtio_kick: Ipc_mailboxSend failed\n");
            #endif
        }
        else
        {
          /* Do Nothing */
        }
    }
    else
    {
      /* Do Nothing */
    }
    return status;
}

/**
 *  \brief Virtio_addUsedBuf
 */
sint32 Virtio_addUsedBuf(Virtio_Handle vq, sint16 head, sint32 len)
{
    struct vring_used_elem *used;

    /*
    * The virtqueue contains a ring of used buffers.  Get a pointer to the
    * next entry in that used ring.
    */
    used = &vq->vring.used->ring[vq->vring.used->idx % vq->vring.num];
    used->id = (uint32)head;
    used->len = (uint32)len;

#ifdef QNX_OS
    asm("   DMB ST");
#endif

    vq->vring.used->idx++;

    return (0);
}

/**
 *  \brief Virtio_addAvailBuf
 */
void Virtio_addAvailBuf(Virtio_Handle vq, void *buf, uint16 head)
{
    uint16 avail;

    avail = (uint16)(vq->vring.avail->idx % vq->vring.num);

    vq->vring.desc[head].addr   = mapVAtoPA(buf);
    vq->vring.desc[head].len    = RP_MSG_BUF_SIZE;
    vq->vring.desc[head].flags  = 2;
    vq->vring.avail->ring[avail] = head;

    /*
     * Descriptors and available array need to be set before we expose the
     * new available array entries.
     */
#ifdef QNX_OS
    asm("   DMB ST");
#endif

    vq->vring.avail->idx++;
}

/**
 *  \brief Virtio_getUsedBuf ========
 */
void *Virtio_getUsedBuf(Virtio_Handle vq, uint16 *token)
{
    uint16 head;
    void     *buf = NULL;

    /* There's nothing available? */
    if (vq->last_used_idx != vq->vring.used->idx)
    {
#ifdef QNX_OS
        asm("   DMB SY");
#endif

        head = (uint16)(vq->vring.used->ring[vq->last_used_idx % vq->vring.num].id);
        vq->last_used_idx++;

        buf = mapPAtoVA(vq->vring.desc[head].addr);
        *token = head;
    }

    return (buf);
}

/**
 *  \brief VirtQueue_getAvailBuf
 */
sint16 Virtio_getAvailBuf(Virtio_Handle vq, void **buf, sint32 *len)
{
    uint16 head;
    sint16  retVal;

    /* There's nothing available? */
    if (vq->last_avail_idx == vq->vring.avail->idx)
    {
        /* We need to know about added buffers */
        vq->vring.used->flags &= (uint16)~VRING_USED_F_NO_NOTIFY;
        retVal = -1;
    }
    else
    {
        /*
         * Grab the next descriptor number they're advertising, and increment
         * the index we've seen.
         */

#ifdef QNX_OS
        /* Only get avail array entries after they have been exposed. */
        asm("   DMB SY");
#endif

        head = vq->vring.avail->ring[vq->last_avail_idx % vq->vring.num];
        vq->last_avail_idx++;

        *buf = mapPAtoVA(vq->vring.desc[head].addr);
        *len = (sint32)vq->vring.desc[head].len;
        retVal = (sint16)head;
    }

    return (retVal);
}



/**
 *  \brief Virtio_enableCallback
 */

/**
 *  \brief Virtio_isr
 */
void Virtio_isr(uint32* msg, uint32 priv)
{
    Virtio_Object *vq;

    vq = queueRegistry[(2U*priv)+1U];
    if ((vq != NULL) && (vq->callback != NULL))
    {
      if((vq && vq->procId) == (priv && vq->callback))
      {
          vq->callback(vq->callback_priv);
      }
    }
}

/**
 *  \brief Virtio_create
 */
 Virtio_Handle Virtio_create(uint32 vqId, uint32 procId,
    Virtio_callback callback, Vring_Params *params,
    VIRTIO_DIR direction, uint8 status, uint32 timeoutCnt)
{
    sint32 retVal;
    Virtio_Object *vq = (Virtio_Object*) NULL;

    if (procId < IPC_MAX_PROCS)
    {
        vq = (Virtio_Object *)Ipc_allocVirtio();
    }

    if (NULL != vq)
    {
        vq->callback       = callback;
        vq->id             = (uint16)vqId;
        vq->procId         = (uint16)procId;
        vq->status         = status;
        vq->last_avail_idx = 0;
        vq->last_used_idx  = 0;
        vq->direction      = direction;
        vq->timeoutCnt     = timeoutCnt;

        vring_init(&(vq->vring), params->num, (void*)params->addr, params->align);

        /* Each processor clears only its TX vq memory. */
        if (direction == VIRTIO_TX)
        {
            memset((void*)params->addr, 0, vring_size(params->num, params->align));
            /* Don't trigger a mailbox message every time remote rpoc */
            /* makes another buffer available.                        */
            vq->vring.used->flags |= VRING_USED_F_NO_NOTIFY;
            queueRegistry[(2U)*procId] = vq;
        }

        if (direction == VIRTIO_RX)
        {
            uint32 selfId = Ipc_mpGetSelfId();
            queueRegistry[(2U*procId)+1U] = vq;
            retVal = Ipc_mailboxRegister((uint16)selfId, (uint16)procId, Virtio_isr, procId, timeoutCnt);
            if (retVal != IPC_SOK)
            {
                #if DEBUG_PRINT
                 SystemP_printf((sint8 *)"Virtio_create : Failed to register mailbox\n");
                 #endif
            }
        }
    }

    return (vq);
}


/**
 *  \brief Virtio_getHandle
 */

Virtio_Handle Virtio_getHandle(uint32 procId, VIRTIO_DIR dir)
{
    uint32 vqIndex = (2U*procId) + (uint32)dir;
    return queueRegistry[vqIndex];
}

/**
 *  \brief Virtio_setCallback
 */
sint32 Virtio_setCallback(uint32 procId, Virtio_callback callback, uint32* priv)
{
    sint32 status = 1;
    Virtio_Object *vq = Virtio_getHandle(procId, VIRTIO_RX);

    if (NULL != vq)
    {
        vq->callback = callback;
        vq->callback_priv = priv;
        status = 0;
    }

    return status;
}


/**
 *  \brief Setups vring buffers.  The buffers are "allocated" from
 *  a single block of memory beginning at addr.  It is assumed that
 *  addr has the appropriate alignment.
 */
void Virtio_prime(Virtio_Object *vq, uint32 addr, uint32 num)
{
    uint32 i;
    uint8 *buf;

    /* Add buffers to the vring's available ring. */
    buf = (uint8 *)addr;
    for (i = 0; i < num; i++)
    {
        Virtio_addAvailBuf(vq, (void *)(uint32)buf, (uint16)i);
        buf += RP_MSG_BUF_SIZE;
    }
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

/* This array serves as a way to look up virtQueues when creating higher
 * level transports, such as RPMessage.  So far, the convention is
 * that the first pair of vrings defined for a remote proc will be
 * used for the primary RPMessage transport.
 *
 * Since none of this info is derived, it's all in the shared page, the
 * search could operate directly on the shared page instead of using
 * this array.
 */
static struct VirtioIPC_Vqdev
{
    uint32 virtioId;
    uint32 rank;    /* zero for primary... */
    uint32 tx_vqId;
    uint32 rx_vqId;
    uint32 procId;
} g_vqTable[MAX_VQ_PAIRS];

#define CDD_IPC_START_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

static uint32 g_vqItemCnt = 0U;

#define CDD_IPC_STOP_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

/**
 *  \brief VirtioIPC_getVirtQueues :
 *           Look up the VirtQueues by procId.
 *           Rank is 0 for primary VQs.
 */

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

uint8 VirtioIPC_getVirtQueues(uint32 type, uint32 procId, uint32 rank,
                             uint32 *tx_vqId, uint32 *rx_vqId)
{
    uint32 i;
    uint8 retVal = FALSE;

    for (i = 0U; i < g_vqItemCnt; i++)
    {
        if ((type   == g_vqTable[i].virtioId) &&
            (rank   == g_vqTable[i].rank)     &&
            (procId == g_vqTable[i].procId))
        {
            *tx_vqId = g_vqTable[i].tx_vqId;
            *rx_vqId = g_vqTable[i].rx_vqId;
            retVal   = TRUE;
            break;
        }
    }

    return retVal;
}

/**
 * \brief Creates Virtio for TX and RX for given given core pair.
 * Must be called multiple times with for each remote core.
 * It will result in a TX/RX pair of Virtio being created.
 * One assumption made is that all vrings will be accessed as Virtio.
 * The Virtio callback to the higher level transport is set to
 * Null.  It must be changed when higher level transport is initialized.
 */
sint32 VirtioIPC_createVirtioCorePair(Ipc_VirtioInfo* vqInfo, uint32 timeoutCnt)
{
    Vring_Params   params;
    Virtio_Handle  tx_vq, rx_vq;
    uint8        status = 0;
    sint32        retVal = IPC_SOK;

    /* TX VQ */
    params.num   = vqInfo->num;
    params.addr  = (uint32)mapPAtoVA(vqInfo->daTx);
    params.align = vqInfo->align;
    tx_vq = Virtio_create(vqInfo->txNotifyId, vqInfo->remoteId, (Virtio_callback) NULL,
                  &params, VIRTIO_TX, status, timeoutCnt);
    if (tx_vq == NULL)
    {
        retVal = IPC_EFAIL;
    }

    if(retVal == IPC_SOK)
    {
        /* Prime the transmit buffer */
        uint32 *primeBuf = (uint32 *)mapPAtoVA(vqInfo->primeBuf);
        Virtio_prime(tx_vq, (uint32)primeBuf, vqInfo->num);
   
        /* RX VQ */
        params.num   = vqInfo->num;
        params.addr  = (uint32)mapPAtoVA(vqInfo->daRx);
        params.align = vqInfo->align;
        rx_vq = Virtio_create(vqInfo->rxNotifyId, vqInfo->remoteId, (Virtio_callback) NULL,
                  &params, VIRTIO_RX, status, timeoutCnt);
        /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as SelfId and RemoteId are fixed enums which cannot be changed.
         *Also, testing is done only for cores 2_1 and 2_0. So this is not covered .

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */

        if (rx_vq == NULL)
        {
            retVal = IPC_EFAIL;
        }
        /* TI_COVERAGE_GAP_STOP */
    }
 
    if(retVal == IPC_SOK)
    {
        /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as the condition will always be false as the array is not filled before this condition. So this is not covered.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
        /* Add to global registry */
        g_vqTable[g_vqItemCnt].virtioId = VIRTIO_ID_RPMSG;
        g_vqTable[g_vqItemCnt].rank     = 0;
        g_vqTable[g_vqItemCnt].tx_vqId  = vqInfo->txNotifyId;
        g_vqTable[g_vqItemCnt].rx_vqId  = vqInfo->rxNotifyId;
        g_vqTable[g_vqItemCnt].procId   = vqInfo->remoteId;
        if (g_vqItemCnt <= MAX_VIRTQUEUES) 
        {
            g_vqItemCnt++;
        }
        
    }
    /* TI_COVERAGE_GAP_STOP */
    return retVal;
}

uint8 Ipc_isRemoteVirtioCreated(uint32 remoteId)
{
    uint8      vqCreated = FALSE;
    uint32  index     = 0;

    for(index = 0; index < g_vqItemCnt; index++)
    {
        /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as asSelfId and RemoteId are fixed enums which cannot be changed.
         *Also, testing is done only for cores 2_1 and 2_0. So this is not covered .

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
        if (remoteId == g_vqTable[index].procId)
        {
            vqCreated = TRUE;
            break;
        }
        /* TI_COVERAGE_GAP_STOP */
    }
    return vqCreated;
}

/**
* TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as the condition will always be false as the array is not filled before this condition. So this is not covered.

* TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
*/
void Ipc_updateVirtioInfo(uint32 numProc, void *baseAddr, uint32 vrBufSize,
                      Ipc_VirtioInfo* info, uint32 index)
{
#if defined (SOC_AM62X) || defined (SOC_AM62AX) || defined (SOC_AM62PX) || defined (SOC_AM62DX) || defined (SOC_AM275X) || defined (SOC_J722S)
    uint32 vringTxIdx = 0U, vringRxIdx = 0U;
#endif
#if !defined (SOC_AM62X) && !defined (SOC_AM62AX) && !defined (SOC_AM62PX) && !defined (SOC_AM62DX) && !defined (SOC_AM275X) && !defined (SOC_J722S)
    uint32 cnt = 0, a , b, i;
#endif
#ifdef QNX_OS
    uint32 revPrimeBuf;
#endif
/* TI_COVERAGE_GAP_STOP */

#if defined (SOC_AM62X) || defined (SOC_AM62AX) || defined (SOC_AM62PX) || defined (SOC_AM62DX) || defined (SOC_AM275X) || defined (SOC_J722S)
    vringTxIdx = Cdd_Ipc_vringId[info -> selfId][info -> remoteId];
    vringRxIdx = Cdd_Ipc_vringId[info -> remoteId][info -> selfId];

    info->daTx       = (uint32)((uint32)baseAddr + (vringTxIdx * vrBufSize));
    info->daRx       = (uint32)((uint32)baseAddr + (vringRxIdx * vrBufSize));
    info->primeBuf   = (uint32)((uint32)baseAddr + ((vringTxIdx+1U) * vrBufSize));

#ifdef QNX_OS
        revPrimeBuf      = (uint32)((uint32)baseAddr + ((vringRxIdx+1U) * vrBufSize));
#endif

    if(info->remoteId > info->selfId)
    {
        info->txNotifyId = 1;
        info->rxNotifyId = 0;
    }
    else
    {
        info->txNotifyId = 0;
        info->rxNotifyId = 1;
    }
#else
    if(info->remoteId > info->selfId)
    {
    
        a = info->selfId;
        b = info->remoteId;
    }
    else
    {
        a = info->remoteId;
        b = info->selfId;
    }

    for(i = 0; i < a; i++)
    {
        cnt += (numProc - i - 1U);
    }
    cnt += ((b - a) - 1U);
    cnt *= 4U;

    if(info->remoteId > info->selfId)
    {
        info->daTx       = (uint32)((uint32)baseAddr + (cnt * vrBufSize));
        info->daRx       = (uint32)((uint32)baseAddr + ((cnt+2U) * vrBufSize));
        info->primeBuf   = (uint32)((uint32)baseAddr + ((cnt+1U) * vrBufSize));
#ifdef QNX_OS
        revPrimeBuf      = (uint32)((uint32)baseAddr + ((cnt+3U) * vrBufSize));
#endif
        info->txNotifyId = 1;
        info->rxNotifyId = 0;
    }
    else
    {
        info->daTx       = (uint32)((uint32)baseAddr + ((cnt+2U) * vrBufSize));
        info->daRx       = (uint32)((uint32)baseAddr + (cnt * vrBufSize));
        info->primeBuf   = (uint32)((uint32)baseAddr + ((cnt+3U) * vrBufSize));
#ifdef QNX_OS
        revPrimeBuf      = (uint32)((uint32)baseAddr + ((cnt+1U) * vrBufSize));
#endif
        info->txNotifyId = 0;
        info->rxNotifyId = 1;
    }
#endif

    /* If remote core is Linux, and vdev is ready
     * update the address
     */
#if !defined (SOC_AM275X)
    /** 
    * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as this function checks for RemoteLinux which is never true. Hence, this part cannot be covered.

    * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
    */
    if(TRUE == Virtio_isRemoteLinux((uint16)(info->remoteId)))
    {
        Ipc_ResourceTable *rsc = (Ipc_ResourceTable*)rscTable;
        info->daTx      = rsc->rpmsg_vring0.da;
        info->daRx      = rsc->rpmsg_vring1.da;
        info->primeBuf  = info->daTx + (2U*vrBufSize);
        info->align     = rsc->rpmsg_vring0.align;

#if defined(SOC_AM62X)  ||  defined(SOC_AM62AX) || defined(SOC_AM62DX) || defined(SOC_AM62PX) || defined(SOC_J722S)
        info->txNotifyId = 0;
        info->rxNotifyId = 1;
#endif

    }
/* TI_COVERAGE_GAP_STOP */
#endif

#ifdef QNX_OS
    /* For QNX, mmap to local process space */
    Ipc_addTranslationEntry(info->daTx, vrBufSize);
    Ipc_addTranslationEntry(info->daRx, vrBufSize);
    Ipc_addTranslationEntry(info->primeBuf, vrBufSize);
    Ipc_addTranslationEntry(revPrimeBuf, vrBufSize);
#endif
#if DEBUG_PRINT
    SystemP_printf((sint8 *)"Virtio: remote %d, daTx 0x%x, daRx 0x%x, prime 0x%x\n",
        info->remoteId, info->daTx, info->daRx, info->primeBuf);
#endif

}
#if defined(SOC_J722S) || defined(SOC_J721E) || defined(SOC_J721S2) || defined(SOC_J742S2) || defined(SOC_J784S4) || defined(SOC_J7200)
void Ipc_resetCoreVirtIO(uint32 coreId)
{
    Virtio_Handle rxVqHandle = Virtio_getHandle(coreId, VIRTIO_RX);
    Virtio_Handle txVqHandle = Virtio_getHandle(coreId, VIRTIO_TX);

    txVqHandle->last_avail_idx = 0U;
    txVqHandle->last_used_idx = 0U;
    (txVqHandle->vring.used)->idx = 0U;
    (txVqHandle->vring.avail)->idx = 0U;
    rxVqHandle->last_avail_idx = 0U;
    rxVqHandle->last_used_idx = 0U;
    (rxVqHandle->vring.used)->idx = 0U;
    (rxVqHandle->vring.avail)->idx = 0U;
}
#endif
sint32 VirtioIPC_init(Ipc_VirtIoParams *vqParams)
{
    sint32          retVal = IPC_SOK;
    uint32         selfId;
    uint32        numProcessors = Ipc_mpGetNumProcessors();
    Ipc_VirtioInfo   vqInfo;
    uint32         procId;
    uint32         index;
#if defined (SOC_AM62X) || defined (SOC_AM62AX) || defined (SOC_AM62PX) || defined (SOC_AM62DX) || defined (SOC_AM275X) || defined (SOC_J722S)
    uint32         numProcs = numProcessors+1U;
    uint32         id=0U,enabledCores[IPC_MAX_PROCS] = {0U};
#endif

    selfId = Ipc_mpGetSelfId();

    vqInfo.align = IPC_VRING_ALIGNMENT;
    vqInfo.num   = IPC_VRING_BUF_CNT;
    vqInfo.selfId = selfId;

#if defined (SOC_AM62X) || defined (SOC_AM62AX) || defined (SOC_AM62PX) || defined (SOC_AM62DX) || defined (SOC_AM275X) || defined (SOC_J722S)
    for(uint32 i = 0U; i < numProcessors; i++){
        
        procId = Ipc_mpGetRemoteProcId(i);
        enabledCores[i] = procId;
    }
    enabledCores[numProcessors] = selfId;

    for(uint32 i = 0U; i < numProcs; i++){
        for(uint32 j = i+1U; j< numProcs; j++){
            if(enabledCores[i] > enabledCores[j]){                
                uint32 temp = enabledCores[i];
                enabledCores[i] = enabledCores[j];
                enabledCores[j] = temp;
            }
        }
    }

    for(uint32 i=0U; i< numProcs; i++){
        uint32 selfCore = enabledCores[i];
        for(uint32 j = 0U; j < numProcs; j++){
            uint32 remoteCore = enabledCores[j];
            if(selfCore == remoteCore){
                /* No vring for self core*/
                Cdd_Ipc_vringId[selfCore][remoteCore] = -1;
            }
            else{
                Cdd_Ipc_vringId[selfCore][remoteCore] = id;
                /* Tx+Prime or Rx+RevPrime*/
                id = id+2U;
            }
        }
    }
#endif

    for(index = 0; index < numProcessors; index++)
    {
        procId = Ipc_mpGetRemoteProcId(index);

        /* if virtio is already created for this core then ignore */
        /**
        * TI_COVERAGE_GAP_START [Branch Coverage] Dynamic branch coverage cannot be covered as valid memory is always shared between remote and cdd ipc driver.
         *So this condition will always be False. Check is already added for Invalid memory. So this part cannot be covered.

        * TI_COVERAGE_UNIT_EFFECT There is no side-effects on this unit as confirmed from the inspection review.
        */
        if(TRUE == Ipc_isRemoteVirtioCreated(procId))
        {
            continue;
        }
        /* TI_COVERAGE_GAP_STOP */
        if(FALSE == Ipc_isRemoteReady((uint16)procId))
        {
            /* Linux on A72 is not ready, go to next core
             * Virtio is not created at this moment, it must be
             * created on demand.
             */
            continue;
        }
        vqInfo.remoteId   = procId;
        Ipc_updateVirtioInfo(IPC_MAX_PROCS, vqParams->vringBaseAddr, IPC_VRING_SIZE, &vqInfo, index);
        retVal = VirtioIPC_createVirtioCorePair(&vqInfo, vqParams->timeoutCnt);
        if(retVal != IPC_SOK)
        {
            #if DEBUG_PRINT
            SystemP_printf((sint8 *)"VirtioIPC_init: Failed to create VirtIO for procId..\n",
                 procId);
            #endif
            break;
        }
    }
    return retVal;
}

/**
 *  \brief Saves the resourcetable to be used for
 *  vring for remotecore A72/A53 running Linux
 */

#if !defined (SOC_AM275X)
sint32 Ipc_loadResourceTable(void *rsctable){
	rscTable = rsctable;
	return IPC_SOK;
}
#endif

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"