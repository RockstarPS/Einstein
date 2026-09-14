/*
 *  Copyright (c) Texas Instruments Incorporated 2026
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

/*!
 * \file  ic_queue.c
 *
 * \brief This file contains the implementation of a circular queue.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <string.h>
#include "Eth_Cfg.h"
#if ((STD_ON == ETH_VIRTUALMAC_SUPPORT) && (STD_ON == ETH_VIRTUALMAC_INTERCORE_ENABLE))
#include "ic_queue.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*! \brief Magic vlaue used to indicate when a queue has been initialized. */
#define IC_QUEUE_INIT_DONE               (0xABCDABCDU)

/*! \brief Assert wrapper */
#define IcQueue_assert(cond, ...)

/* ========================================================================== */
/*                         Structures Declarations                            */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Private Functions                                 */
/* ========================================================================== */

/* Used when an element is enqueued */
static void IcQueue_moveHead(IcQ_Handle hIcQueue)
{
    IcQueue_assert(hIcQueue != NULL_PTR);
    IcQueue_assert(hIcQueue->magic == IC_QUEUE_INIT_DONE);

    if (++(hIcQueue->head) == hIcQueue->maxSize)
    {
        hIcQueue->head = 0;
    }
}

/* Used when an element is dequeued */
static void icQueue_moveTail(IcQ_Handle hIcQueue)
{
    IcQueue_assert(hIcQueue != NULL_PTR);
    IcQueue_assert(hIcQueue->magic == IC_QUEUE_INIT_DONE);

    if (++(hIcQueue->tail) == hIcQueue->maxSize)
    {
        hIcQueue->tail = 0;
    }
}

/* ========================================================================== */
/*                          API/Public Functions                              */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/*!
 * \brief Creates a circular queue and returns a handle to it
 *
 * \detail Creates a circular queue of \ref IcQ_Node objects.
 *  - The number of nodes on the circular queue is passed as a parameter.
 *
 *  @param[in]  hIcQueue        Handle to a pre-allocated icQueue object
 *  @param[in]  queueId         Unique queue identifier
 *  @param[in]  maxSize         Number of nodes on the circular queue
 *
 *  @return IcQueue Handle upon success. Error code otherwise.
 */
sint32 IcQueue_initQ(IcQ_Handle hIcQueue,
                      uint32 queueId,
                      uint32 maxSize)
{
    sint32 retVal = ICQ_RETURN_SUCCESS;

    IcQueue_assert(hIcQueue && maxSize);

    hIcQueue->queueId       = queueId;
    hIcQueue->head          = 0;
    hIcQueue->tail          = 0;
    hIcQueue->maxSize       = maxSize;
    hIcQueue->magic         = IC_QUEUE_INIT_DONE;

    /* Clear all the nodes */
    (void)memset(hIcQueue->nodeArray, 0x00, maxSize * sizeof(IcQ_Node));

    return retVal;
}


/*!
 * \brief Enqueues an \ref IcQ_Node object on the given queue
 *
 * @param[in] hIcQueue      Handle to IcQ object
 * @param[in] pNode         Handle to IcQ_Node object
 *
 * @return None
 */
sint32 IcQueue_enq(IcQ_Handle hIcQueue,
                    IcQ_Node *pNode)
{
    sint32 retVal = ICQ_RETURN_FAILURE;

    IcQueue_assert(hIcQueue && pNode);
    IcQueue_assert(hIcQueue->magic == IC_QUEUE_INIT_DONE);

    if (FALSE == IcQueue_isQFull(hIcQueue))
    {
        hIcQueue->nodeArray[hIcQueue->head].pDataBuffer   = pNode->pDataBuffer;
        hIcQueue->nodeArray[hIcQueue->head].dataBufferLen = pNode->dataBufferLen;
        hIcQueue->nodeArray[hIcQueue->head].packetId      = pNode->packetId;
        IcQueue_moveHead(hIcQueue);
        retVal = ICQ_RETURN_SUCCESS;
    }
    else
    {
        retVal = ICQ_ERR_QFULL;
    }

    return retVal;
}

/*!
 * \brief Dequeues a node from the given queue
 *
 * @param[in] hIcQueue      Handle to IcQ object
 *
 * @return The next \ref IcQ_Node object on the queue
 * @return NULL_PTR if the queue is empty
 */
IcQ_Node* IcQueue_deq(IcQ_Handle hIcQueue)
{
    IcQ_Node* pNode = NULL_PTR;

    IcQueue_assert(hIcQueue != NULL_PTR);
    IcQueue_assert(hIcQueue->magic == IC_QUEUE_INIT_DONE);

    if (FALSE == IcQueue_isQEmpty(hIcQueue))
    {
        pNode = &hIcQueue->nodeArray[hIcQueue->tail];
        icQueue_moveTail(hIcQueue);
    }

    return pNode;
}

/*!
 * \brief Returns BTRUE if the given queue is empty
 *
 * @param[in] hIcQueue      Handle to IcQ object
 *
 * @return True if a queue is empty.
 */
boolean IcQueue_isQEmpty(IcQ_Handle hIcQueue)
{
    IcQueue_assert(hIcQueue != NULL_PTR);
    IcQueue_assert(hIcQueue->magic == IC_QUEUE_INIT_DONE);
    boolean ret = FALSE;

    if ((FALSE == IcQueue_isQFull(hIcQueue)) && (hIcQueue->head == hIcQueue->tail))
    {
        ret = TRUE;
    }

    return ret;
}

/*!
 * \brief Returns BTURE if the given queue is full
 *
 * @param[in] hIcQueue      Handle to IcQ object
 *
 * @return True if a queue is full.
 */
boolean IcQueue_isQFull(IcQ_Handle hIcQueue)
{
    uint32 head;
    boolean ret = FALSE;

    IcQueue_assert(hIcQueue != NULL_PTR);
    IcQueue_assert(hIcQueue->magic == IC_QUEUE_INIT_DONE);

    /* Check for wrap-around. This approach wastes one slot in the
     * queue but does not require producer-consumer synchronization
     */ 
    head = hIcQueue->head + 1;

    if (head == hIcQueue->maxSize)
    {
        head = 0;
    }

    if (head == hIcQueue->tail)
    {
        ret = TRUE;
    }

    return ret;
}

#endif