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
 *  \file ipc_api.c
 *
 *  \brief File containing the IPC driver APIs.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <CddIpc/ipc_baremetal_hw/ipc.h>
#include <string.h>
#include "ipc_priv.h"
#include "ipc_virtioPrivate.h"
#include "ipc_utils.h"
#include "ipc_mailbox.h"
#include "Cdd_Ipc.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define MAXCALLBACKS           IPC_MAX_PROCS

#define MSGBUFFERSIZE          (IPC_MAX_DATA_PAYLOAD)
#define SERVICENAMELEN         32U
#define HEAPALIGNMENT          8U

struct RPMessage_Object_s;
typedef struct RPMessage_Object_s*            RPMessage_EndptPool[MAXENDPOINTS];

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

#define CNTRLMSG_ANNOUNCE (0x00000000U)

#define SemaphoreP_NO_WAIT       ((uint32)0U)

/* Message Header: Must match mp_msg_hdr in virtio_rp_msg.h on Linux side. */
typedef struct RPMessage_MsgHeader_s
{
    uint32  srcAddr;             /* source endpoint addr       */
    uint32  dstAddr;             /* destination endpoint addr  */
    uint32  srcProcId;           /* reserved                   */
    uint16  dataLen;             /* data length                */
    uint16  flags;               /* bitmask of different flags */
    uint8   payload[];           /* Data payload               */
}RPMessage_MsgHeader;


/* common fields of a control message */
typedef struct RPMessage_CntrlMsg_s
{
    uint32  type;
}RPMessage_CntrlMsg;

/* announcement message */
typedef struct RPMessage_Announcement_s
{
    UCHAR                 name[SERVICENAMELEN];
    uint32             endPt;
    RPMessage_CntrlMsg   ctrl;
} RPMessage_Announcement;


/* list element for the announcedEndpts list */
typedef struct RPMessage_NameEntry_s
{
    IpcUtils_QElem   elem;
    uint32         procId;
    uint32         endPt;
    UCHAR             name[SERVICENAMELEN];
} RPMessage_NameEntry;


/* list element for the waitingTasks list */
typedef struct RPMessage_Waiter_s
{
    IpcUtils_QElem     elem;
    void               *semHandle;
    uint32           procId;
    uint32           endPt;
    UCHAR               name[SERVICENAMELEN];
    uint32           token;
} RPMessage_Waiter;
/**
 *  \brief Element to hold payload copied onto receiver's queue.
 */
typedef struct RPMessage_MsgElem_s
{
    IpcUtils_QElem    elem;          /**< Allow list linking.          */
    uint32          len;           /**< Length of data               */
    uint32          src;           /**< Src address/endPt of the msg */
    uint32          procId;        /**< Processor sending the msg    */
} RPMessage_MsgElem;

/* The RPMessage Object */
typedef struct RPMessage_Object_s
{
    uint32             endPt;        /**< Unique id (procId | queueIndex) */
    void                 *semHandle;   /**< I/O Completion                 */
    RPMessage_Callback   cb;           /**< RPMessage Callback */
    void*                arg;          /**< Callback argument */
    IpcUtils_QHandle     queue;        /**< Queue of pending messages             */
    uint8              unblocked;    /**< Use with signal to unblock _receive() */
    IpcUtils_HeapParams  heapParams;   /* Save the heapBuf params to delete Heap   */
    IpcUtils_HeapHandle  heap;         /* Heap from which to allocate free messages */
    RPMessage_EndptPool  *pool;        /**< track associated pool for cleanup */
    void*                recv_buffer;  /**< Application buffer from RPMessage_recv() */
    RPMessage_MsgElem    payload;      /**< Message info for RPMessage_recv() */
} RPMessage_Object;

/**
 *  \brief This struct is used as private data supplied to the VQ
 *         callback function.  It is also passed to the SWI
 *         functions through arg0. */
typedef struct RPMessage_CallbackData_s
{
    Virtio_Handle        vq;
    RPMessage_EndptPool  *pool;
    Ipc_OsalHIsrHandle   swi;
} RPMessage_CallbackData;

/**
 *  \brief Module_State
 */
typedef struct RPMessage_Module_s
{
    /* Instance gate: */
    Ipc_OsalHIsrGateHandle gateSwi;

    /* Lookup VQ handle from procId for sending messages. */
    /* Array indexed by procId.                           */
    Virtio_Handle tx_VQs[IPC_MAX_PROCS];

    /* Array of callback structs. Used only for RX VirtQueues */
    RPMessage_CallbackData VQ_callbacks[MAXCALLBACKS];

    uint32 numCallbacks;

    /* Global endpoint pool */
    RPMessage_EndptPool globalPool;

    /* Lookup endpoint pool from procId.  Array indexed by procId. */
    /* RPMessage_EndptPool pools[MAXREMOTEPROCS];            */

    /* Queue to track announcements from other processors */
    IpcUtils_QHandle announcedEndpts;

    /* Queue to hold the semaphores of waiting tasks */
    IpcUtils_QHandle waitingTasks;

    /* Array of RPMessage Object, memory supplied by application */
    RPMessage_Object*   objArry;

    /* Current object Count */
    uint16 objCnt;

    /* NameEntry count */
    uint16  nameEntryCnt;

    RPMessage_NameEntry  nameEntry[IPC_MAX_NAME_ENTRY];

} RPMessage_Module;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define CDD_IPC_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

/**< IPC Object */

#define CDD_IPC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Cdd_Ipc_MemMap.h"

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t RPMessageParams_init(RPMessage_Params *params)
{
    int32_t    retVal = IPC_SOK;
    return (retVal);
}

uint32 RPMessage_getObjMemRequired(void)
{
    uint32 objSize = 0U;
    return objSize;
}


/*
 *  ======== RPMessage_enqueMsg ========
 */
/* Always assumed to be called in SWI context */

/**
 *  \brief RPMessage_init : Initializing the framework
 */
/* CDD_IPC_CoverageGap_19: Already check is provided which makes this part of code inaccessible*/
int32_t RPMessage_init(RPMessage_Params *params)
{
    int32_t          retVal = IPC_SOK;
    return retVal;
}


/*
 *  ======== RPMessage_create ========
 */
RPMessage_Handle RPMessage_create(RPMessage_Params *params, uint32 *endPt)
{
    RPMessage_Object *obj = NULL;
    return (RPMessage_Handle)obj;
}

/**
 *  \brief RPMessage_deinit : Tear down the module
 */

/*
 *  ======== RPMessage_delete ========
 */

/*
 *  ======== RPMessage_recv ========
 */

/*
 *  ======== RPMessage_recvNb ========
 */
int32_t RPMessage_recvNb(RPMessage_Handle handle, void* data, uint16 *len,
                   uint32 *rplyEndPt, uint32 *rplyProcId,boolean isCtrlMsg)
{
    int32_t             status = IPC_EBADARGS;
    return (status);
}

/*
 *  ======== RPMessage_send ========
 */
/* CDD_IPC_CoverageGap_20: Already check is provided which makes this part of code inaccessible. */
int32_t RPMessage_send(RPMessage_Handle handle, uint32 procId, uint32 dstEndPt,
     uint32 srcEndPt, void* data, uint16 len)
{
    int32_t             status = IPC_SOK;
    return status;
}


/*
 *  ======== RPMessage_unblock ========
 */

void IpcInitPrms_init(uint32 instId, Ipc_InitPrms *initPrms)
{
    
}

Ipc_Object *getIpcObjInst(uint32 instId)
{
    return NULL;
}

int32_t Ipc_init(Ipc_InitPrms *cfg)
{
    int32_t retVal = IPC_EINVALID_PARAMS;
    return (retVal);
}

void Ipc_newMessageIsr(uint32 srcProcId)
{

}
