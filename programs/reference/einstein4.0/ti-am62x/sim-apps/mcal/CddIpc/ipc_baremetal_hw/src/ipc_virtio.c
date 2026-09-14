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

/* 512k for each vring */
#define IPC_VRING_ALIGNMENT    (0x1000)
#define IPC_VRING_BUF_CNT      (256)

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
typedef struct Ipc_TranslationEntry
{
    uint32  pa;  /* physical address */
    uintptr_t va;  /* virtual address  */
    uint32  len; /* Length of buffer */
}Ipc_TranslationEntry;

#define   IPC_TABLE_MAX_CNT   64

/* IPC PhyAddr to VirtAddr translation table */
typedef struct Ipc_TranslationTable
{
    uint32              count;
    /**< Number of entryies in the translation table */

    Ipc_TranslationEntry  entry[IPC_TABLE_MAX_CNT];
    /**< Entries in the table, there should be 3-entries for
     * each remote cores */

}Ipc_TranslationTable;

typedef struct Ipc_NotifyIdEntry_s
{
    int32_t    txNotifyId;
    int32_t    rxNotifyId;
} Ipc_NotifyIdEntry;

#define CDD_IPC_START_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

int32_t  virtio_cnt = 0;

#define CDD_IPC_STOP_SEC_VAR_INIT_32
#include "Cdd_Ipc_MemMap.h"

/**
 *  \brief Used for defining the size of the virtqueue registry
 */
#define MAX_VIRTQUEUES          (IPC_MAX_PROCS * 2U)
#define MAX_VQ_PAIRS            ((MAX_VIRTQUEUES+1U)/2U)


#define DIV_ROUND_UP(n,d)   (((n) + (d) - 1) / (d))
#define RP_MSG_BUF_SIZE     (512)

/**
 *  \brief The alignment to use between consumer and producer parts of vring.
 *         Note: this is part of the "wire" protocol. If you change this,
 *         you need to update your BIOS image as well
 */
#define RP_MSG_VRING_ALIGN  (4096)

/* With 256 buffers, the vring will occupy 3 pages
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

    void*             rscTable;
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
    uintptr_t addr;
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

static void*    rscTable   = NULL;

#define CDD_IPC_STOP_SEC_VAR_INIT_PTR
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

static Ipc_TranslationTable  vrTranslationTable;

#define CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

Virtio_Handle Virtio_create(uint32 vqId, uint32 procId, Virtio_callback callback, Vring_Params *params,
   VIRTIO_DIR direction, uint8 status, uint32 timeoutCnt);
void Virtio_prime(Virtio_Object *vq, uintptr_t addr, uint32 num);
int32_t VirtioIPC_createVirtioCorePair(Ipc_VirtioInfo* vqInfo, uint32 timeoutCnt);
void Ipc_updateVirtioInfo(uint32 numProc, void *baseAddr, uint32 vrBufSize, Ipc_VirtioInfo* info);

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

void* Ipc_allocVirtio(void)
{
    void  *ptr = NULL;
    return ptr;
}

/**
 * \brief    Add entry to the translation able
 **/

/**
 * \brief Get virual address for given physical address
 **/
/* CDD_IPC_CoverageGap_22: The function Ipc_physToVirt() is not called in the CDD driver code.*/
int32_t Ipc_physToVirt(uint32 pa, uintptr_t *va)
{
    Std_ReturnType status = IPC_EFAIL;
    return (status);
}

/**
 * \brief Get physical address from given virual address
 **/
/* CDD_IPC_CoverageGap_23: The function Ipc_virtToPhys() is not called in the CDD driver code.*/
int8_t Ipc_virtToPhys(uintptr_t va, uint32 *pa)
{
    Std_ReturnType status = IPC_EFAIL;
    return (status);
}
/*CDD_IPC_CoverageGap_37: Ipc_getVqObjMemoryRequiredPerCore - This API is used in ETH driver, so it will be covered in ETH LDRA - MCAL-9188(JIRA task)*/
uint32 Ipc_getVqObjMemoryRequiredPerCore(void)
{
    return 0U;
}

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
    uint8  retVal = 0U;
    return retVal;
}

/**
 * \brief  Checks if remote is ready
 *
 * \return  1 if remote proc is is not A72 or resource table is null
 *            or linux vdev status is 0x7
 *          0 if linux vdev status is not 0x7
 *
 */
/* CDD_IPC_CoverageGap_24: This function Ipc_isRemoteReady() checks for RemoteLinux which is never true. Hence, this part cannot be covered.*/
uint8 Ipc_isRemoteReady(uint16 procId)
{
    uint8            retVal = TRUE;
    return retVal;
}

/**
 *  \brief Initializes the registry
 */
int32_t Ipc_initVirtIO(Ipc_VirtIoParams *vqParam)
{
    int32_t   retVal = IPC_SOK;
    return retVal;
}

/**
 *  \brief Check the vq status
 */

uint8 Virtio_isReady(Virtio_Handle vq)
{
    return 0U;
}

/**
 *  \brief Get the processor Id
 */
uint32 Virtio_getProcId(Virtio_Handle vq)
{
    return 0U;
}

/**
 *  \brief Virtio kick
 */
void Virtio_kick(Virtio_Handle vq)
{
    
}

/**
 *  \brief Virtio_addUsedBuf
 */
int32_t Virtio_addUsedBuf(Virtio_Handle vq, int16_t head, int32_t len)
{
    return (0);
}

/**
 *  \brief Virtio_addAvailBuf
 */
void Virtio_addAvailBuf(Virtio_Handle vq, void *buf, uint16 head)
{
    
}

/**
 *  \brief Virtio_getUsedBuf ========
 */
void *Virtio_getUsedBuf(Virtio_Handle vq, uint16 *token)
{
    void     *buf = NULL;
    return (buf);
}

/**
 *  \brief VirtQueue_getAvailBuf
 */
int16_t Virtio_getAvailBuf(Virtio_Handle vq, void **buf, int32_t *len)
{
    int16_t  retVal = 0;
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
    
}

/**
 *  \brief Virtio_create
 */
 Virtio_Handle Virtio_create(uint32 vqId, uint32 procId,
    Virtio_callback callback, Vring_Params *params,
    VIRTIO_DIR direction, uint8 status, uint32 timeoutCnt)
{
    Virtio_Object *vq = NULL;
    return (vq);
}


/**
 *  \brief Virtio_getHandle
 */

Virtio_Handle Virtio_getHandle(uint32 procId, VIRTIO_DIR dir)
{
    return NULL;
}

/**
 *  \brief Virtio_setCallback
 */
int32_t Virtio_setCallback(uint32 procId, Virtio_callback callback, uint32* priv)
{
    int32_t status = 1;
    return status;
}


/**
 *  \brief Setups vring buffers.  The buffers are "allocated" from
 *  a single block of memory beginning at addr.  It is assumed that
 *  addr has the appropriate alignment.
 */
void Virtio_prime(Virtio_Object *vq, uintptr_t addr, uint32 num)
{
    
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

#define CDD_IPC_START_SEC_CODE
#include "Cdd_Ipc_MemMap.h"

uint8 VirtioIPC_getVirtQueues(uint32 type, uint32 procId, uint32 rank,
                             uint32 *tx_vqId, uint32 *rx_vqId)
{
    uint8 retVal = 0;
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
int32_t VirtioIPC_createVirtioCorePair(Ipc_VirtioInfo* vqInfo, uint32 timeoutCnt)
{
    int32_t        retVal = IPC_SOK;
    return retVal;
}

uint8 Ipc_isRemoteVirtioCreated(uint32 remoteId)
{
    uint8      vqCreated = 0;
    return vqCreated;
}

/* CDD_IPC_CoverageGap_29: The condition will always be false as the array is not filled before this condition. So this is not covered.*/
void Ipc_updateVirtioInfo(uint32 numProc, void *baseAddr, uint32 vrBufSize,
                      Ipc_VirtioInfo* info)
{
    
}

int32_t VirtioIPC_init(Ipc_VirtIoParams *vqParams)
{
    int32_t          retVal = IPC_SOK;
    return retVal;
}

/**
 *  \brief Saves the resourcetable to be used for
 *  vring for remotecore A72/A53 running Linux
 */

int32_t Ipc_loadResourceTable(void *rsctable){
	return 0;
}

#define CDD_IPC_STOP_SEC_CODE
#include "Cdd_Ipc_MemMap.h"
